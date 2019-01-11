/****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products [NXP Microcontrollers such as JN5168, JN5179].
 * You, and any third parties must reproduce the copyright and warranty notice
 * and any other legend of ownership on each copy or partial copy of the
 * software.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Copyright NXP B.V. 2016. All rights reserved
 ****************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
/* Standard includes */
#include <string.h>
/* SDK includes */
#include <jendefs.h>
/* Hardware includes */
#include <AppHardwareApi.h>
#include <PeripheralRegs.h>
/* Device includes */
#include "DriverBulb.h"
/* RTOS include */
#ifdef RTOS
#include "os.h"
#endif

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/* DIO for the NXP SSL/LED driver boards */

#define LAMP_PWM_PIN            10              /* Timer 0 output pin      */

/* Lamp On/Off control pins (13/14/15) REF: ticket lpap87                  */

#define LAMP_ON_OFF_MASK        0xe000UL
#define LAMP_LEVEL_MAX          255             /* Max value for level     */
#define TIMER0_T_LO_REG		    0x02005004
#define VBUS_MAXIMUM            480


#if (JENNIC_CHIP == JN5148) || (JENNIC_CHIP == JN5148J01)
#define ADC_USED		E_AHI_ADC_SRC_ADC_4 /* ADC to be read */
#else
#define ADC_USED		E_AHI_ADC_SRC_ADC_1 /* ADC to be read */
#endif

#if (JENNIC_CHIP == JN5148) || (JENNIC_CHIP == JN5148J01)
#define ADC_BITS 12
#elif (JENNIC_CHIP == JN5142J01)
#define ADC_BITS  8
#else
#define ADC_BITS 10
#endif


/* define the DIO to be reclaimed off timer dio */
#define TIMER_DIO_INHIBIT     (REG_SYS_TIM_IO_T0GDIS_MASK | \
                               REG_SYS_TIM_IO_T0CDIS_MASK | \
                               REG_SYS_TIM_IO_T2PDIS_MASK | \
                               REG_SYS_TIM_IO_T3PDIS_MASK)

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/

PRIVATE uint32 u32ApplyParabolicCorrectionCurve(uint32 u32Level);

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Global Variables                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/


PUBLIC void DriverBulb_vInit(void)
{
	static bool_t bFirstCalled = TRUE;

	if (bFirstCalled)
	{
		/* Configure DIO pins */
		vAHI_DioSetDirection(0, (LAMP_ON_OFF_MASK | (1<< LAMP_PWM_PIN)) );
		vAHI_DioSetOutput(0,(1<< LAMP_PWM_PIN));

		vAHI_DioSetPullup(0,(LAMP_ON_OFF_MASK | (1<< LAMP_PWM_PIN) ));

		/* Configure timer 0 to generate a PWM output on its output pin */
		vAHI_TimerEnable(E_AHI_TIMER_0, 0, FALSE, FALSE, TRUE);
		vAHI_TimerConfigureOutputs(E_AHI_TIMER_0, TRUE, TRUE); /* Invert PWM and disable gating */
		vAHI_TimerClockSelect(E_AHI_TIMER_0, FALSE, TRUE);

		uint16 u16Max = u32ApplyParabolicCorrectionCurve(LAMP_LEVEL_MAX);
		/* start the timer running 100% duty cycle */
		vAHI_TimerStartRepeat(E_AHI_TIMER_0,u16Max,u16Max);
		bFirstCalled = FALSE;
	}
}

PUBLIC bool_t DriverBulb_bReady(void)
{
	return (TRUE);
}

PUBLIC void DriverBulb_vSetLevel(uint32 u32Level)
{
    *(volatile uint32 *)TIMER0_T_LO_REG	= u32ApplyParabolicCorrectionCurve(u32Level);
}

PUBLIC void DriverBulb_vOn(void)
{
	vAHI_DioSetOutput(LAMP_ON_OFF_MASK,0);
	/* Put the timer back on the DIO (permanently running) */
	vREG_SysExtWrite(REG_SYS_TIM_IO_CTRL ,TIMER_DIO_INHIBIT );
}

PUBLIC void DriverBulb_vOff(void)
{
	vAHI_DioSetOutput(0,LAMP_ON_OFF_MASK);
	/* take the timer 0ff DIO10 */
	vREG_SysExtWrite(REG_SYS_TIM_IO_CTRL ,(TIMER_DIO_INHIBIT|REG_SYS_TIM_IO_T0PDIS_MASK));
}

PUBLIC void DriverBulb_vSetOnOff(bool_t bOn)
{
	(bOn) ? DriverBulb_vOn() : DriverBulb_vOff();
}
/****************************************************************************
 *
 * NAMES:           DriverBulb_bOn, u16ReadBusVoltage, u16ReadChipTemperature
 *
 * DESCRIPTION:		Acess functions for Monitored Lamp Parmeters
 *
 *
 * PARAMETERS:      Name     RW  Usage
 *
 * RETURNS:
 * Lamp state, Bus Voltage (Volts), Chip Temperature (Degrees C)
 *
 ****************************************************************************/
PUBLIC bool_t DriverBulb_bOn(void)
{
	if ((u32AHI_DioReadInput() & LAMP_ON_OFF_MASK) == LAMP_ON_OFF_MASK)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/****************************************************************************
 *
 * NAMES:           DriverBulb_vTick
 *
 * DESCRIPTION:		10 ms Ticks from higher layer for timing
 *
 *
 ****************************************************************************/

PUBLIC void DriverBulb_vTick(void)
{

}
/****************************************************************************
 *
 * NAME:			vMonitorVoltage
 *
 * DESCRIPTION:
 *                  Reads ADC and updates voltage variable used by forground
 *                  0xFFF is 2.4V (=228V)
 *                  Also turns off lamp if Vbus to low.
 *
 *
 *
 *
 * PARAMETERS:      Name	     RW  Usage
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC int16 DriverBulb_i16Analogue(uint8 u8Adc, uint16 u16AdcRead)
{
	uint32 u32AdcSample = 0;

	/* ADC4/1 - bus voltage  */
	if (u8Adc == ADC_USED)
	{
 		u32AdcSample = ((uint32)u16AdcRead*VBUS_MAXIMUM) >> ADC_BITS;
	}

	return (int16) u32AdcSample;
}

/****************************************************************************
 *
 * NAME:			DriverBulb_bFailed
 *
 * DESCRIPTION:     Access function for Failed bulb state
 *
 *
 * RETURNS:         bulb state
 *
 ****************************************************************************/

PUBLIC bool_t DriverBulb_bFailed(void)
{
	return (FALSE);
}

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

#define X_OFFSET 0UL
#define MIN_PERCENT 5
#define PWM_PERIOD 53333 /* 16E6/53333 = 300Hz PWM */
/*Normalisation constants */
#define MAX_VALUE ((255+X_OFFSET)*(255+X_OFFSET))
#define MIN_OFFSET ((MAX_VALUE*MIN_PERCENT)/100)

PRIVATE uint32 u32ApplyParabolicCorrectionCurve(uint32 u32RawLevel)
{
    uint32 u32PwmValue = u32RawLevel + X_OFFSET;  /* F(X) = (X+a) */
	u32PwmValue *= u32PwmValue;                   /* F(X) = (X+a)^2 */
	u32PwmValue += MIN_OFFSET;                    /* F(X) = (X+a)^2 + b */
	u32PwmValue *= PWM_PERIOD;                    /* F(X) = ((X+a)^2 + b) * PWM_PERIOD */
	u32PwmValue /= (MAX_VALUE+MIN_OFFSET);        /* Normalise so F(255) = PWM_PERIOD  */
	return u32PwmValue;
}


/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

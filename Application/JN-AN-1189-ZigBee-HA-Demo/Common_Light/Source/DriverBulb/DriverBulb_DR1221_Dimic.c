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
#include "AppHardwareApi.h"
#include <PeripheralRegs.h>
#include <MicroSpecific.h>

#include "dbg.h"
#include "dbg_uart.h"

/* Device includes */
#include "DriverBulb.h"

#ifdef RTOS
#include "os.h"
#endif

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#ifndef DEBUG_DRIVER
#define TRACE_DRIVER FALSE
#else
#define TRACE_DRIVER TRUE
#endif

#define LAMP_ON_OFF_MASK       (1 << 13)

#define TIMER_START_REPEAT     (1 + 8 +      512       )  /* EN + OE +        + GDIS         */
#define TIMER_START_SINGLE     (1 + 8 + 16 + 512 + 1024)  /* EN + OE + SINGLE + GDIS + INVOUT*/

/* Flip the PWM polarity if we're the SW255 as this needs an external transistor to start up */
#ifdef VAUX
#define PWM_START_TIMER_PWM_POLARITY  TIMER_START_REPEAT
#else
#define  PWM_START_TIMER_PWM_POLARITY (TIMER_START_REPEAT | REG_TMR_CTRL_INVOUT_MASK )
#endif

#ifdef SWAP_PWM
#define LEVEL_TIMER_BASE   REG_TMR1_BASE
#define TEMP_TIMER_BASE   REG_TMR0_BASE
#else
#define LEVEL_TIMER_BASE   REG_TMR0_BASE
#define TEMP_TIMER_BASE   REG_TMR1_BASE
#endif

#define PWM_CHANNELS              2UL
//#define PWM_PERIOD                40000UL
//#define PWM_PERIOD                38000UL   //420Hz
#define PWM_PERIOD                26667UL   //600Hz
#define PWM_MIN					  4854UL    // 18.2% of PWM_PERIOD @ 600Hz

#define INITIAL_COLOUR_TEMP       0


/* define the DIO to be reclaimed off timer dio */
#define TIMER_DIO_INHIBIT     (REG_SYS_TIM_IO_T0GDIS_MASK | \
                               REG_SYS_TIM_IO_T0CDIS_MASK | \
                               REG_SYS_TIM_IO_T2PDIS_MASK | \
                               REG_SYS_TIM_IO_T3PDIS_MASK)

/* DIO scope Tracing.  Set to 2 to enable DIO 1 tracing*/

#define TRACE_DIO 2

#if (TRACE_DIO)
/* Toggle a DIO each time comparator falls below Vref */
#define TRACE_COMP_FE_ON	vAHI_DioSetOutput(2,0)
#define TRACE_COMP_FE_OFF	vAHI_DioSetOutput(0,2)
#else
#define TRACE_COMP_FE_ON
#define TRACE_COMP_FE_OFF
#endif

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

enum {E_CCT_COOL_WHITE   = 2700L,
	  E_CCT_WARM_WHITE   = 6500L,
	  E_LUMENS_COLD_WHITE = 763L,
	  E_LUMENS_WARM_WHITE = 828L};

typedef struct
{
	volatile uint32 u32Count;
	uint32 u32Rise;
	uint32 u32Fall;
	uint32 u32Control;
	uint32 u32Prescale;
	uint32 u32IntStatus;
	uint32 u32IntEnable;
	uint32 u32MaskedIntStatus;
}tsTimer; /* Timer HAL Interface */

typedef struct
{
	uint32 u32Direction;
	uint32 u32Output;
	const volatile uint32 u32Input;
}tsDio; /* DIO HAL Interface */

typedef enum
{
	START_REPEAT,
	SINGLE_SHOT
}teTimerMode;

typedef enum
{
	E_MODE_CCT,
	E_MODE_BALANCE
}teDualPwmMode;



/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/

/* Only need prototypes if used in Jennet-IP otherwise OS_ISR() macro used  */


PRIVATE void vSetPwm(tsTimer * const psPwmTimer, uint32 u32Rise, uint32 u32Fall, uint32 u32Control);
PRIVATE void vSetDualPwm(uint32 u32ResetMask);
#ifndef LINEAR_MODE
PRIVATE uint32 u32ApplyCorrectionCurve(uint32 u32Level);
#endif
#ifdef DUAL_PWM
PRIVATE int32 i32CalculateCCTPulseWidth(int32 i32ColourTemperature, int32 i32PrimaryPwmPulseWidth);
#endif
//PRIVATE inline unsigned divu3(unsigned n);


/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Global Variables                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

PRIVATE struct
{
	volatile uint32 u32SyncLockLossCount;
	volatile uint32 u32PwmPeriod;
	uint32 u32PwmLastValue[PWM_CHANNELS];
	         uint32 u32Level;
	         uint32 u32Balance;
	         int32  i32ColourTemperature;
	         teDualPwmMode eDualPwmMode;
	         bool_t bIsOn;
} sBulb = {0,PWM_PERIOD,{PWM_PERIOD,PWM_PERIOD},255,127,INITIAL_COLOUR_TEMP,E_MODE_BALANCE,TRUE};

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

/****************************************************************************
 *
 * NAME:       		LAMP_vInit
 *
 * DESCRIPTION:		Initialises the lamp drive system
 *
 ****************************************************************************/
PUBLIC void DriverBulb_vInit(void)
{
	static bool_t bFirstCall = TRUE;

	if (bFirstCall == TRUE)
	{
		bFirstCall = FALSE;

         vAHI_DioSetDirection(0,TRACE_DIO | (1<<10) | (1<<11));
         vAHI_DioSetDirection(0,LAMP_ON_OFF_MASK);
         vAHI_DioSetOutput(0, (1<<10) | (1<<11));  //  switch pins off

	    /* Release DIO 8 & 9 off timer 0 (before timer enabled to avoid glitches */
        /* DIO12 off timer 2 for bleed and Timer 3 (internal pulse counter)      */
	    vAHI_TimerFineGrainDIOControl(0x33);

		/* Configure White PWM */
		vAHI_TimerEnable(E_AHI_TIMER_0, 0, FALSE, FALSE, TRUE);
        vAHI_TimerClockSelect(E_AHI_TIMER_0, FALSE, TRUE);

         /* Provide a second PWM drive for amber led string in a tunable White SSL */
    	vAHI_TimerEnable(E_AHI_TIMER_1, 0, FALSE, FALSE, TRUE);
        vAHI_TimerClockSelect(E_AHI_TIMER_1, FALSE, TRUE);

        /* Turn on the PWM channels and ON-OFF DIO */
        vSetDualPwm(REG_TMR_CTRL_CTRRST_MASK);
        vAHI_DioSetOutput(LAMP_ON_OFF_MASK,0);

		/* Enable the Analogue Peripheral block  */
		/* If running under Jennet-IP the MIB Module will check the */
		/* bAHI_APRegulatorEnabled before initialising the Analogue MIB Block */
		vAHI_ApConfigure(E_AHI_AP_REGULATOR_ENABLE,
						 E_AHI_AP_INT_DISABLE,
						 E_AHI_AP_SAMPLE_2,
						 E_AHI_AP_CLOCKDIV_500KHZ,
						 E_AHI_AP_INTREF);

		while (!bAHI_APRegulatorEnabled());   /* spin on reg not enabled */
	}

}

/****************************************************************************
 *
 * NAME:       		LAMP_bReady
 *
 * DESCRIPTION:		Returns if lamp is ready to be operated
 *
 * RETURNS:         TRUE
 *
 ****************************************************************************/
PUBLIC bool_t DriverBulb_bReady(void)
{
	return (TRUE);
}

/****************************************************************************
 *
 * NAME:       		DriverBulb_vSetLevel
 *
 * DESCRIPTION:		Updates the lamp level
 *
 * PARAMETERS:      Name     RW  Usage
 *         	        u8Level  R   Light level 0-255
 *
 ****************************************************************************/

PUBLIC void DriverBulb_vSetLevel(uint32 u32Level)
{

	sBulb.u32Level = (uint32)u32Level;
   /* Optionally bypass the correction curves with linear 0-100% dimming mode */
#ifdef LINEAR_MODE
	sBulb.u32PwmLastValue[0] = ((u32Level * (sBulb.u32PwmPeriod-PWM_MIN)/255)) + PWM_MIN;
#else
    sBulb.u32PwmLastValue[0] = u32ApplyCorrectionCurve(sBulb.u32Level);
#endif

    vSetDualPwm(0);
	DBG_vPrintf(TRACE_DRIVER, "\nL%d",u32Level);
}

/****************************************************************************
 *
 * NAME:       		DriverBulb_vSetBalance (For TEST Application AN1166)
 *
 * DESCRIPTION:		Updates Balance (% of current in each led string)
 *
 ****************************************************************************/
#ifdef AN1166
PUBLIC void DriverBulb_vSetBalance(uint8 u8Balance)
{
	sBulb.eDualPwmMode = E_MODE_BALANCE;
	sBulb.u32Balance = (uint32)u8Balance;
	sBulb.u32PwmLastValue[1] = (sBulb.u32Balance) * sBulb.u32PwmPeriod;
	sBulb.u32PwmLastValue[1] = sBulb.u32PwmLastValue[1]/255;
	vSetDualPwm(0);
}
#endif

#ifdef DUAL_PWM
/****************************************************************************
 *
 * NAME:       		DriverBulb_vSetTunableWhiteColourTemperature
 *
 * DESCRIPTION:		Controls the perceived colour temperature of
 *                  Dual LED string Hardware
 *
 ****************************************************************************/
PUBLIC void DriverBulb_vSetTunableWhiteColourTemperature(int32 i32ColourTemperature)
{
	sBulb.eDualPwmMode = E_MODE_CCT;
	sBulb.i32ColourTemperature = i32ColourTemperature;
	sBulb.u32PwmLastValue[1] = i32CalculateCCTPulseWidth(i32ColourTemperature,sBulb.u32PwmPeriod );
	vSetDualPwm(0);
}

PRIVATE int32 i32CalculateCCTPulseWidth(int32 i32ColourTemperature, int32 i32PrimaryPwmPulseWidth)
{
	/* Limit Range to what the calibration constants allow         */
	/* ZCL should also check this if called/configured correctly   */
	if (i32ColourTemperature > E_CCT_WARM_WHITE)
	{
		i32ColourTemperature = E_CCT_WARM_WHITE;
	}

	if (i32ColourTemperature < E_CCT_COOL_WHITE)
	{
		i32ColourTemperature = E_CCT_COOL_WHITE;
	}

	// for 600Hz
	int32 i32result = (i32ColourTemperature-E_CCT_COOL_WHITE)*PWM_PERIOD;
	i32result /= 3800;
	return i32result;
	// for 420Hz
	//return (i32ColourTemperature -E_CCT_COOL_WHITE)*10;
}
#endif

PUBLIC void DriverBulb_vSetOnOff(bool_t bOn)
{
	(bOn == TRUE) ? DriverBulb_vOn() : DriverBulb_vOff();
}
/****************************************************************************
 *
 * NAME:            LAMP_vOn
 *
 * DESCRIPTION:     Turns the lamp on
 *
 ****************************************************************************/
PUBLIC void DriverBulb_vOn(void)
{
	sBulb.bIsOn = TRUE;
	vAHI_DioSetOutput(LAMP_ON_OFF_MASK,0);
    vAHI_TimerFineGrainDIOControl(0x33);
	DBG_vPrintf(TRACE_DRIVER, "\nS:ON");
}

/****************************************************************************
 *
 * NAME:            DriverBulb_vOff
 *
 * DESCRIPTION:     Turns the lamp off
 *
 ****************************************************************************/
PUBLIC void DriverBulb_vOff(void)
{
	//uint32 u32Ints;

    /* Critical Section Cannot be interrupted as it changes parameters */
    /* that main ISR uses.  Ensures a clean stop without restart risk  */
	//MICRO_DISABLE_AND_SAVE_INTERRUPTS(u32Ints);
	sBulb.bIsOn = FALSE;

    //MICRO_RESTORE_INTERRUPTS(u32Ints);
    vAHI_DioSetOutput(0,LAMP_ON_OFF_MASK);
    vAHI_TimerFineGrainDIOControl(0x3f);

    DBG_vPrintf(TRACE_DRIVER, "\nS:OFF");
}

/****************************************************************************
 *
 * NAMES:           DriverBulb_bOn
 *
 * DESCRIPTION:		Access functions for Monitored Lamp Parmeters
 *
 * RETURNS:
 * Lamp state, Bus Voltage (Volts), Chip Temperature (Degrees C)
 *
 ****************************************************************************/
PUBLIC bool_t DriverBulb_bOn(void)
{
	return (sBulb.bIsOn);
}

/****************************************************************************
 *
 * NAMES:           DriverBulb_vTick
 *
 * DESCRIPTION:		Accepts 10 ms Ticks from higher layer for timing
 *                  Implements a sync-loss detector by incrementing
 *                  a counter that is reset by the sync pulses so under
 *                  sync conditions this counter will remain below a threshold
 *                  If we lose sync the counter exceeds this and we reset
 *                  the PWM to either last value (On) or GND (off)
 *
 ****************************************************************************/

PUBLIC void DriverBulb_vTick(void)
{

}
/****************************************************************************
 *
 * NAME:			DriverBulb_i16Analogue
 *
 * DESCRIPTION:     Retained for upper layer compatibility
 *
 *
 * PARAMETERS:      Name	     RW  Usage
 *                  u8Adc        R   Identity of the ADC suppling the data
 *                  u16AdcRead   R   Value of last conversion
 *
 * RETURNS:         0
 *
 ****************************************************************************/
PUBLIC int16 DriverBulb_i16Analogue(uint8 u8Adc, uint16 u16AdcRead)
{
	return (0);
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

PUBLIC void DriverBulb_vGetColourTempPhyMinMax(uint16 *pu16PhyMin, uint16 *pu16PhyMax)
{
	*pu16PhyMax = (uint16)(1000000L/E_CCT_COOL_WHITE);
	*pu16PhyMin = (uint16)(1000000L/E_CCT_WARM_WHITE);
}


/****************************************************************************
 * NAME:			vSetDualPwm
 *
 * DESCRIPTION:     Helper function to configure white and Amber PWM timers
 ****************************************************************************/
PRIVATE void vSetDualPwm(uint32 u32ResetMask)
{
	vSetPwm((tsTimer *)LEVEL_TIMER_BASE, sBulb.u32PwmLastValue[0], sBulb.u32PwmPeriod, PWM_START_TIMER_PWM_POLARITY | u32ResetMask);
#ifdef DUAL_PWM
	vSetPwm((tsTimer *)TEMP_TIMER_BASE, sBulb.u32PwmLastValue[1], sBulb.u32PwmPeriod, (TIMER_START_REPEAT | REG_TMR_CTRL_INVOUT_MASK | u32ResetMask));
#endif
}

/****************************************************************************
 * NAME:			vSetPwm
 *
 * DESCRIPTION:     Helper function to configure a single PWM timer
 ****************************************************************************/
PRIVATE void vSetPwm(tsTimer * const psPwmTimer, uint32 u32Rise, uint32 u32Fall, uint32 u32Control)
{
	psPwmTimer->u32Rise    = sBulb.bIsOn ? u32Rise : 0UL;
	psPwmTimer->u32Fall    = u32Fall;
	psPwmTimer->u32Control = u32Control;
}

#ifndef LINEAR_MODE

#if 0
/****************************************************************************
 * NAME:			u32ApplyCorrectionCurve
 *
 * DESCRIPTION:     Helper function to calculate the Parabolic locus
 *                  F(X)=(X+a)(X+a) scaling between min % level for F(0)
 *                  and 100% for F(255)
 *                  100% -> mapped to PWMPeriod from Sync process
 ****************************************************************************/
/* shift parabola directrix to left to avoid small dy/dx about zero point */
#define X_OFFSET 17UL
/* min values is a function of target hardware SLN36/SLN38 = 6% CCT = 4%*/
#ifdef DUAL_PWM
#define MIN_PERCENT 4
#else
#define MIN_PERCENT 6
#endif

/*Normalisation constants */
#define MAX_VALUE ((255+X_OFFSET)*(255+X_OFFSET))
#define MIN_OFFSET ((MAX_VALUE*MIN_PERCENT)/100)

PRIVATE uint32 u32ApplyCorrectionCurve(uint32 u32Level)
{
    uint32 u32PwmValue = u32Level + X_OFFSET;  /* F(X) = (X+a) */
	u32PwmValue *= u32PwmValue;                /* F(X) = (X+a)^2 */
	u32PwmValue += MIN_OFFSET;                 /* F(X) = (X+a)^2 + b */
	u32PwmValue *= sBulb.u32PwmPeriod;         /* F(X) = ((X+a)^2 + b) * PWM_PERIOD */
	u32PwmValue /= (MAX_VALUE+MIN_OFFSET);     /* Normalise so F(255) = PWM_PERIOD  */
	return u32PwmValue;
}
#endif


/****************************************************************************
 * NAME:			u32ApplyCorrectionCurve
 *
 * DESCRIPTION:     Helper function to calculate the Parabolic locus
 *
 * Apply correction curve of y = 0.0013x2 - 0.0028x + 18.207 based on
 * Jaaps measurements.
 *
 * 10000*y = 10000 *(0.0013x2 - 0.0028x + 18.207)
 *
 *         = 13x2 - 28x + 182070
 *
 ****************************************************************************/
#define PARAM1  13
#define PARAM2  28
#define PARAM3  182070

PRIVATE uint32 u32ApplyCorrectionCurve(uint32 u32Level)
{
    uint32 u32PwmValue = u32Level * u32Level*PARAM1;  /* F(X) = (X^2)*0.0013 */
	u32PwmValue -= (u32Level * PARAM2);               /* F(X) = ((X^2)*0.0013 - 0.0028x */
	u32PwmValue += PARAM3;                            /* F(X) = ((X^2)*0.0013 - 0.0028x + 182070 */
	u32PwmValue /= 100;                               /* divide by 100 to get % */
	u32PwmValue *= sBulb.u32PwmPeriod;                /* x PWM_PERIOD  to get new value*/
	u32PwmValue /= 10000;                             /* correction for integer maths  */
	/* trend line goes slightly over 100% at top value */
	if (u32PwmValue>sBulb.u32PwmPeriod) u32PwmValue=sBulb.u32PwmPeriod;
	return u32PwmValue;
}
#endif


#if 0

/****************************************************************************
 * NAME:		   div3u
 *
 * DESCRIPTION:    Fast divide by 3 routine
 *
 ****************************************************************************/
PRIVATE inline unsigned divu3(unsigned n)
{
	unsigned r;
	r = (0x55555555*n + (n >> 1) - (n >> 3)) >> 30;
	return (n - r)*0xAAAAAAAB;
}
#endif

#ifdef RTOS
OS_ISR(vISR_Timer4)
#else
PRIVATE void vISR_Timer4(void)
#endif
{
}

#ifdef RTOS
OS_ISR(vISR_Timer3)
#else
PRIVATE void vISR_Timer3(void)
#endif
{
}

#ifdef RTOS
OS_ISR(vISR_SystemController)
#else
PRIVATE void vISR_SystemController(void)
#endif
{
}

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

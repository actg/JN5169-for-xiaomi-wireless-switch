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
#include <MicroSpecific.h>
/* Device includes */
#include "DriverBulb.h"

#include "Printf.h"

#ifdef RTOS
#include "os.h"
#endif


/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#define LAMP_ON_OFF_MASK       (1 << 13)

#define TIMER_START_REPEAT     (1 + 8 +      32 + 512       )  /* EN + OE +        + RST + GDIS         */
#define TIMER_START_SINGLE     (1 + 8 + 16 + 32 + 512 + 1024)  /* EN + OE + SINGLE + RST + GDIS + INVOUT*/


/* Flip the PWM plarity if we're the SW255 as this needs an external transistor to start up */
#ifdef SW555
#define PWM_START_TIMER_PWM_POLARITY  TIMER_START_REPEAT
#else
#define  PWM_START_TIMER_PWM_POLARITY (TIMER_START_REPEAT | REG_TMR_CTRL_INVOUT_MASK )
#endif

#define PWM_CHANNELS              2UL
#define PWM_PERIOD                40000UL
#define PWM_SYNC_TIMER_MAX        60000UL

#ifdef DUAL_PWM
#define PWM1_DELAY                (26E-6/625E-10)
#define PWM2_DELAY                (10E-6/625E-10)
#define PWM2_MIN                  (0)
#define INITIAL_COLOUR_TEMP       4700
#else
#define PWM1_DELAY                0
#define PWM2_DELAY                0
#define INITIAL_COLOUR_TEMP       0
#endif


/* define the DIO to be reclaimed off timer dio */
#define TIMER_DIO_INHIBIT     (REG_SYS_TIM_IO_T0GDIS_MASK | \
                               REG_SYS_TIM_IO_T0CDIS_MASK | \
                               REG_SYS_TIM_IO_T2PDIS_MASK | \
                               REG_SYS_TIM_IO_T3PDIS_MASK)

#define COMP_DIO_MASK           ( (1 << 16) | (1 <<17) )
#define SYNC_LOSS_10MS_TICKS    20 /* 200ms to detect sync loss */

#define ADDR_AP_COMPCTRL  0x02001F20
#define ADDR_AP_CTRL      0x02001F00

/* SW555 and DUAL_PWM are for later versions of SSB that only need one   */
/* output for the anti-rebroadcast flicker drive                         */
#if defined(SW555) || defined(DUAL_PWM)
#define CURRENT_BLEED_DIO_MASK  0x00001000UL      /* DIO12 on DR1221     */
#else
#define CURRENT_BLEED_DIO_MASK  0x00001b00UL      /* DIO12+11+8+9 DR1190 */
#endif

#define RX_ACTIVE_DIO           2
#define TX_ACTIVE_DIO           3
#define TX_RX_DIO_MASK          ((1<<TX_ACTIVE_DIO) | (1<<RX_ACTIVE_DIO) )

#define GPIO_DOUT_REG           0x02002004UL
#define GPIO_DIN_REG			0x02002008UL
#define SYSCON_WK_ET            0x02000008UL
#define SYSCON_SYS_IM           0x0200000CUL
#define SYSCON_SYS_IS           0x02000010UL

#define REG_SYS_PWR_CTRL        0x02000000
#define RFRXEN_MASK             (1 << 24)
#define RFTXEN_MASK             (1 << 25)

/* The DIO we want the 60us pulse demand to appear on */
#define VAUX_SENSE_DIO (1 << 9)

/* The Pulse timer runs at 16MHz so each clock is 62.5s   */
/* So we need a 60us fraction of this to get T_rise value */
#define PULSE_60US_CLKS          (16E6 * 60E-6)

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

#ifndef RTOS
PRIVATE void vISR_SystemController(void);
PRIVATE void vISR_Timer3(void);
PRIVATE void vISR_Timer4(void);
#endif

PRIVATE void vInitComparator(void);
PRIVATE void vSetPwm(tsTimer * const psPwmTimer, uint32 u32Rise, uint32 u32Fall, uint32 u32Control);
PRIVATE void vSetDualPwm();
PRIVATE void vForceTimerUpdateIfNeeded(void);
PRIVATE uint32 u32ApplyCorrectionCurve(uint32 u32Level);
PRIVATE int32 i32CalculateCCTPulseWidth(int32 i32ColourTemperature, int32 i32PrimaryPwmPulseWidth);
PRIVATE void vAdjustBalance(void);
PRIVATE inline unsigned divu3(unsigned n);

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

PRIVATE uint32 u32Toggle = 0;

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

        /* override defaults to compensate for CCT LSB hardware delays */
#ifdef DUAL_PWM
		sBulb.u32PwmLastValue[0] -= PWM1_DELAY;

		sBulb.u32PwmLastValue[1] = sBulb.u32PwmLastValue[0] >> 1;

		vAdjustBalance();
#endif

		/* Configure DIO pins */
		vAHI_DioSetDirection(COMP_DIO_MASK, LAMP_ON_OFF_MASK );
	    vAHI_DioSetPullup(0,COMP_DIO_MASK);
	    vAHI_DioSetDirection(TX_RX_DIO_MASK ,CURRENT_BLEED_DIO_MASK);
	    vAHI_DioWakeEdge((1<<TX_ACTIVE_DIO),(1<<RX_ACTIVE_DIO));

         vAHI_DioSetDirection(0,TRACE_DIO);

	    /* Release DIO 8 & 9 off timer 0 (before timer enabled to avoid glitches */
        /* DIO12 off timer 2 for bleed and Timer 3 (internal pulse counter)      */
	    vAHI_TimerFineGrainDIOControl(0x33);

		/* Configure White PWM */
		vAHI_TimerEnable(E_AHI_TIMER_0, 0, FALSE, FALSE, TRUE);
        vAHI_TimerClockSelect(E_AHI_TIMER_0, FALSE, TRUE);

         /* Optionally Provide a second PWM drive for amber led string in a tunable White SSL */
#ifdef DUAL_PWM
    	vAHI_TimerEnable(E_AHI_TIMER_1, 0, FALSE, FALSE, TRUE);
        vAHI_TimerClockSelect(E_AHI_TIMER_1, FALSE, TRUE);
#endif

        /* Set up a timer to work out number of cycles between comparator IRQs */
		vAHI_TimerEnable(E_AHI_TIMER_2,3,FALSE, FALSE, FALSE);
		vAHI_TimerConfigure(E_AHI_TIMER_2, TRUE, TRUE);
		vAHI_TimerClockSelect(E_AHI_TIMER_2, FALSE, TRUE);

		/*setup a timer for (optional) pulse generation */
		 vAHI_TimerEnable(E_AHI_TIMER_3, 0, FALSE, TRUE, FALSE);
		 vAHI_TimerClockSelect(E_AHI_TIMER_3, FALSE, TRUE);

        /*Set up a timer to provide phase delay compensation between comparator IRQ and zero crossing */
		 vAHI_TimerEnable(E_AHI_TIMER_4,3,FALSE, TRUE, FALSE);
		 vAHI_TimerConfigure(E_AHI_TIMER_4, TRUE, TRUE);
		 vAHI_TimerClockSelect(E_AHI_TIMER_4, FALSE, TRUE);


        /* Turn on the PWM channels and ON-OFF DIO */
        vSetDualPwm();
        vAHI_DioSetOutput(LAMP_ON_OFF_MASK,0);

        /* Optionally configure a DIO as a trigger input to generate 60us pulses  */
		/* in response to a rising edge event on the input pin and a dedicated    */
        /* hardware timer to accurately schedule the end of the pulse             */
#ifdef SW555
		 vAHI_DioSetDirection( VAUX_SENSE_DIO,0);        /* make sure VAUX SENSE is input  */
	     vAHI_DioSetPullup(0, VAUX_SENSE_DIO);           /* ... and pullup off             */
	     vAHI_DioWakeEdge(VAUX_SENSE_DIO,0);             /* Rising edge interrupts         */
		 vAHI_DioWakeEnable(VAUX_SENSE_DIO,0);           /* Enable Interrupts              */

		 /* If the White timer is taken off the DIO we want to be driving out a zero */

		 vAHI_DioSetDirection(0,E_AHI_DIO10_INT);
		 vAHI_DioSetPullup(0,E_AHI_DIO10_INT);
		 vAHI_DioSetOutput(0,E_AHI_DIO10_INT);
#endif

		/* Enable the Analogue Peripheral block if running under RTOS (ZLL/ZHA) */
		/* If running under Jennet-IP the MIB Modules take care of this         */
#ifdef RTOS
		vAHI_ApConfigure(E_AHI_AP_REGULATOR_ENABLE,
						 E_AHI_AP_INT_DISABLE,
						 E_AHI_AP_SAMPLE_2,
						 E_AHI_AP_CLOCKDIV_500KHZ,
						 E_AHI_AP_INTREF);

		while (!bAHI_APRegulatorEnabled());   /* spin on reg not enabled */

		vInitComparator();

#else   /* If no RTOS present mimic the ZLL/ZHA setup from the OSCONFIG diagram     */
		/* patch in syscon event handlers bypassing the standard AHI ones for speed */

		MICRO_SET_INT_HANDLER(MICRO_ISR_NUM_SYSCTRL, vISR_SystemController);
        MICRO_SET_INT_HANDLER(MICRO_ISR_NUM_TMR3   , vISR_Timer3);
        MICRO_SET_INT_HANDLER(MICRO_ISR_NUM_TMR4   , vISR_Timer4);

		/* Raise the system controller and timer3/4 priority levels above the stack */

		vAHI_InterruptSetPriority( MICRO_ISR_MASK_SYSCTRL , 15);
		vAHI_InterruptSetPriority( MICRO_ISR_MASK_TMR3    , 14);
		vAHI_InterruptSetPriority( MICRO_ISR_MASK_TMR4    , 13);

#endif
		*(uint32 *)REG_SYS_PWR_CTRL |= (RFRXEN_MASK | RFTXEN_MASK);
		 vAHI_DioInterruptEnable(((1<<TX_ACTIVE_DIO) | (1<<RX_ACTIVE_DIO)),0);


	}
	else /* 2nd call to function is after stack starts so safe to enable high power */
	{
		*(uint32 *)REG_SYS_PWR_CTRL |= (RFRXEN_MASK | RFTXEN_MASK);
		 vAHI_DioInterruptEnable(((1<<TX_ACTIVE_DIO) | (1<<RX_ACTIVE_DIO)),0);
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
	sBulb.u32PwmLastValue[0] = ((u32Level+1) * sBulb.u32PwmPeriod) >> 8;
#else
    sBulb.u32PwmLastValue[0] = u32ApplyCorrectionCurve(sBulb.u32Level);
#endif


	/* Recalculate other PWM channel PWM to maintain colour temperature */
	if (sBulb.eDualPwmMode == E_MODE_BALANCE)
	{
		#ifdef AN1166
		DriverBulb_vSetBalance(sBulb.u32Balance);
		#endif
	}
	else
	{
		DriverBulb_vSetTunableWhiteColourTemperature(sBulb.i32ColourTemperature);
	}
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
	sBulb.u32PwmLastValue[1] = (sBulb.u32Balance+1) * sBulb.u32PwmLastValue[0];
	sBulb.u32PwmLastValue[1] >>=8;
	vAdjustBalance();
    vForceTimerUpdateIfNeeded();
}
#endif

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
	sBulb.u32PwmLastValue[1] = i32CalculateCCTPulseWidth(i32ColourTemperature,sBulb.u32PwmLastValue[0]);
	vAdjustBalance();
	vForceTimerUpdateIfNeeded();
}

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
	vForceTimerUpdateIfNeeded();
	vAHI_DioSetOutput(LAMP_ON_OFF_MASK,0);
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
	uint32 u32Ints;

    /* Critical Section Cannot be interrupted as it changes parameters */
    /* that main ISR uses.  Ensures a clean stop without restart risk  */
	MICRO_DISABLE_AND_SAVE_INTERRUPTS(u32Ints);
	sBulb.bIsOn = FALSE;

	vForceTimerUpdateIfNeeded();
    MICRO_RESTORE_INTERRUPTS(u32Ints);
    vAHI_DioSetOutput(0,LAMP_ON_OFF_MASK);
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
	static uint32 u32RestartFlag;

	if (sBulb.u32SyncLockLossCount <SYNC_LOSS_10MS_TICKS)
	{
		sBulb.u32SyncLockLossCount++;
		u32RestartFlag = 0;
	}
	else
	{
		if (u32RestartFlag==0)
		{
			tsTimer * const psTimer2 = (tsTimer *)REG_TMR2_BASE;

			sBulb.u32PwmPeriod = PWM_PERIOD;
			vSetDualPwm();

			/* stop the sync timer and then reset */
			psTimer2->u32Control &= ~REG_TMR_CTRL_EN_MASK;
			psTimer2->u32Control |= REG_TMR_CTRL_CTRRST_MASK;

			/* make sure comparator interrupt is enabled so we can re-acquire lock */
			*(uint32 *)SYSCON_SYS_IM |= E_AHI_SYSCTRL_COMP0_MASK;

			u32RestartFlag = -1;
		}
	}
}
/****************************************************************************
 *
 * NAME:			DriverBulb_i16Analogue
 *
 * DESCRIPTION:     Retained for upper layer compatibility
 *                  The Synchronous driver doesn't use bus voltage
 *                  so always returns zero. However once called it indicates
 *                  the analogue peripheral are up & running so it's safe
 *                  to enable the comparator for synch pulse detection
 *                  (JenNet-IP only)  If using RTOS the local Driver_BulbInit
 *                   function is responsible for configuring the analogue peripheral
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
	static bool_t bFirstCall = TRUE;

	if (bFirstCall == TRUE)
	{
		bFirstCall = FALSE;
		vInitComparator();
	}
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
 *
 * NAME:			vISR_SystemController
 *
 * DESCRIPTION:     Call-back Interrupt service routine.
 *                  Times the duration between successive interrupts
 *                  for use as the frequency multiplier for the
 *                  phase-locked loop
 *
 ****************************************************************************/
#ifdef RTOS
OS_ISR(vISR_SystemController)
#else
PRIVATE void vISR_SystemController(void)
#endif
{
	uint32 * const pu32DioOutputRegister   = (uint32 *) GPIO_DOUT_REG;
	uint32 * const pu32SysConWakeEventType = (uint32 *) SYSCON_WK_ET;
	uint32 * const pu32SysConEventStatus   = (uint32 *) SYSCON_SYS_IS;

	uint32 u32IntStatus = *pu32SysConEventStatus;

    /*****************************************************************************/
    /* Generate a 60us pulse on PWM if VAUX sense dio rising edge                */
    /*****************************************************************************/

    if ((u32IntStatus & VAUX_SENSE_DIO) !=0)
    {
 #ifdef SW555
        /* Take Timer 0 off the DIO10 (DIO10 is set output-low) */
        vREG_SysExtWrite(REG_SYS_TIM_IO_CTRL ,(TIMER_DIO_INHIBIT|REG_SYS_TIM_IO_T0PDIS_MASK));

        /* Launch the 60us pulse timer  */
        vSetPwm((tsTimer *)REG_TMR3_BASE,PULSE_60US_CLKS,PULSE_60US_CLKS, TIMER_START_SINGLE);

#endif
        /* clear down vaux interrupt (since it got us here) */
		*pu32SysConEventStatus = u32IntStatus & VAUX_SENSE_DIO;
	}

    /*****************************************************************************/
    /* Start of rebroadcast anti-flicker logic to activate bleed resistor on DIO */
    /* when switching form RX to TX (Done by soft 'NOR' of DIO2/3 in HP Mode     */
    /*****************************************************************************/

	if (  (u32IntStatus & TX_RX_DIO_MASK) !=0 ) /*check if any DIO2/3 events occurred */
	{

		/* loop back the DIO onto edge type (to track rising /falling edges) and set bit 28 */
		/* to give a falling edge on the comparator                                         */

		*pu32SysConWakeEventType = ((*(uint32 *) GPIO_DIN_REG) | 0x10000000 ) & 0x1000000c;

		if ((*pu32SysConWakeEventType & TX_RX_DIO_MASK)  ==0)
		{
			*pu32DioOutputRegister |= CURRENT_BLEED_DIO_MASK;
		}
		else
		{
			*pu32DioOutputRegister &= ~CURRENT_BLEED_DIO_MASK;
		}

		/* clear down the dio2/3 interrupts */
		*pu32SysConEventStatus = u32IntStatus & TX_RX_DIO_MASK;
	}

	/*****************************************************************************/
	/* Start of Mains sync logic implementing a frequency multiplier using phase */
	/* locked loop coupled to mains 50-50 Hz zero crossings. Half wave rectified */
	/* sine is fed into comparator input to generate periodic interrupts which   */
	/* are timed between successive ones.  The value is fed into the PWM timer   */
	/* running at x8 the speed of the zero-crossing timer therefore syncing the  */
	/* PWM to x8 the mains frequency.                                            */
	/*****************************************************************************/

	if ( (u32IntStatus & E_AHI_SYSCTRL_COMP0_MASK) !=0)  /* check if the comparator has fired */
	{
		if ((u8AHI_ComparatorStatus() & E_AHI_AP_COMPARATOR_MASK_1) != E_AHI_AP_COMPARATOR_MASK_1) /* and it a true falling edge */
		{
			sBulb.u32SyncLockLossCount = 0;
			sBulb.u32PwmPeriod = *(uint32 *)REG_TMR2_BASE; /* direct read of counter */

			/* Start the timing between successive comparator interrupts */
			vSetPwm((tsTimer * )REG_TMR2_BASE,(PWM_SYNC_TIMER_MAX/2),PWM_SYNC_TIMER_MAX,TIMER_START_SINGLE);


			/* normally resstart the PWM timers here but moved approx 1.5ms into future to align */
			/* synchronisation with zero crossing event when unit is powered from AC          */
			if (sBulb.u32PwmPeriod > 0)
			{
				if (u32Toggle ^= 0x01UL) TRACE_COMP_FE_ON; else TRACE_COMP_FE_OFF ;

				/* approx 1/12 of the period added to the current time    */
				/* re-times the sync operation to align with zero crossing */
				uint32 u32PhaseDelay = divu3(sBulb.u32PwmPeriod >>2);

				/* launch the phase delay timer */
				vSetPwm((tsTimer * )REG_TMR4_BASE,u32PhaseDelay,u32PhaseDelay, TIMER_START_SINGLE);
			}

			  /* Period may have changed so recalculate the pwm */
		     sBulb.u32PwmLastValue[0] = u32ApplyCorrectionCurve(sBulb.u32Level);

			/* pipeline the balance recalculations */
			if (sBulb.eDualPwmMode == E_MODE_CCT)
			{
				sBulb.u32PwmLastValue[1] = i32CalculateCCTPulseWidth(sBulb.i32ColourTemperature,sBulb.u32PwmLastValue[0]);
			}
			else
			{
				sBulb.u32PwmLastValue[1] = (sBulb.u32Balance+1) * sBulb.u32PwmLastValue[0];
				sBulb.u32PwmLastValue[1] >>= 8;
			}
			vAdjustBalance();

		}
		/* Clear Down The comparator interrupt */
		*pu32SysConEventStatus = E_AHI_SYSCTRL_COMP0_MASK;
	}
}

/****************************************************************************
 *
 * NAME:			vISR_Timer3
 *
 * DESCRIPTION:     Handles the expiring of the low pulse timer
 *
 ****************************************************************************/
#ifdef RTOS
OS_ISR(vISR_Timer3)
#else
PRIVATE void vISR_Timer3(void)
#endif
{
	tsTimer * const psTimer3 = (tsTimer *) REG_TMR3_BASE;

    psTimer3->u32MaskedIntStatus = REG_TMR_INT_P_EN_MASK;       /* Clear Down pulse timer FALL Interrupt  */

	vREG_SysExtWrite(REG_SYS_TIM_IO_CTRL ,TIMER_DIO_INHIBIT );  /* put the timer back on the dio          */
}

/****************************************************************************
 *
 * NAME:			vISR_Timer4
 *
 * DESCRIPTION:     Handles moving the synchronisation event into the future
 *                  to coincide with the mains zero crossing when system
 *                  is powered from an AC source
 *
 ****************************************************************************/
#ifdef RTOS
OS_ISR(vISR_Timer4)
#else
PRIVATE void vISR_Timer4(void)
#endif
{
	 tsTimer * const psTimer4 = (tsTimer *) REG_TMR4_BASE;

	 psTimer4->u32MaskedIntStatus = REG_TMR_INT_P_EN_MASK;         /* Clear Down pulse timer Period Interrupt      */

    vSetDualPwm();
}

/****************************************************************************
 * NAME:			vInitComparator
 *
 * DESCRIPTION:     Helper function called to set the comparator up
 *                  correctly.  If running under RTOS (ZLL/ZHA) its called
 *                  from the Driver_BulbInit otherwise from DriverBulb_i16Analogue
 *                  function as this is called from the JenNet-Ip MIB layer
 *                  when it has configured the Analogue peripharals
 *
 ****************************************************************************/
PRIVATE void vInitComparator(void)
{
	vAHI_ComparatorEnable(E_AHI_AP_COMPARATOR_1, E_AHI_COMP_HYSTERESIS_40MV, E_AHI_COMP_SEL_BANDGAP);
	vAHI_ComparatorLowPowerMode(TRUE);
	*(uint32 *)ADDR_AP_CTRL |= (1 <<28); /* ensure low-power really set Fix from SMB/IL [lpsw3902] */
	vAHI_ComparatorIntEnable(E_AHI_AP_COMPARATOR_1,TRUE,FALSE);
	*(uint32 *)ADDR_AP_COMPCTRL  &= 0xfffffffb;	/* clear bit 2 Ref Ticket [lpsw3219] */
}

/****************************************************************************
 * NAME:			vSetDualPwm
 *
 * DESCRIPTION:     Helper function to configure white and Amber PWM timers
 ****************************************************************************/
PRIVATE void vSetDualPwm(void)
{
	vSetPwm((tsTimer *)REG_TMR0_BASE,(sBulb.u32PwmLastValue[0] - PWM1_DELAY),sBulb.u32PwmPeriod, PWM_START_TIMER_PWM_POLARITY);
#ifdef DUAL_PWM
	vSetPwm((tsTimer *)REG_TMR1_BASE,sBulb.u32PwmLastValue[1] ,sBulb.u32PwmPeriod, (TIMER_START_REPEAT | REG_TMR_CTRL_INVOUT_MASK ));
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

PRIVATE int32 i32CalculateCCTPulseWidth(int32 i32ColourTemperature, int32 i32PrimaryPwmPulseWidth)
{
	int32 i32Numerator, i32Denominator;

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

	i32Numerator = E_LUMENS_COLD_WHITE * (E_CCT_COOL_WHITE - i32ColourTemperature);
	i32Denominator = (i32ColourTemperature * (E_LUMENS_WARM_WHITE - E_LUMENS_COLD_WHITE) + (E_CCT_COOL_WHITE*E_LUMENS_COLD_WHITE) - (E_CCT_WARM_WHITE*E_LUMENS_WARM_WHITE));

	i32Numerator   >>= 6;
	i32Denominator >>= 6;

	return (i32PrimaryPwmPulseWidth * i32Numerator)/i32Denominator;
}

/****************************************************************************
 * NAME:			vForceUpdateIfNeeded
 *
 * DESCRIPTION:     Helper function to check if sync driver has lost the lock
 *                  and force the update to the timers if needed
 ****************************************************************************/
PRIVATE void vForceTimerUpdateIfNeeded(void)
{
    /* If synchronisation is lost and the bulb is on then we force the update */
	/* to the timer As the ISR (which normally does this) won't be running    */
    if (sBulb.u32SyncLockLossCount >= SYNC_LOSS_10MS_TICKS)
    {
    	vSetDualPwm();
    }
}

/****************************************************************************
 * NAME:			vAdjustBalance
 *
 * DESCRIPTION:     Helper function to advance/retard falling edges on
 *                  balance PWM channel to cope with hardware non-linearities
 *                  Only used in AN1166 (Balance Test Mode)
 ****************************************************************************/

PRIVATE void vAdjustBalance(void)
{
#ifdef DUAL_PWM
	if (sBulb.u32PwmLastValue[1] >=PWM2_DELAY)
	{
		sBulb.u32PwmLastValue[1] -= PWM2_DELAY;
	}
	else
	{
		sBulb.u32PwmLastValue[1] = 0;
	}
#endif
}


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

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

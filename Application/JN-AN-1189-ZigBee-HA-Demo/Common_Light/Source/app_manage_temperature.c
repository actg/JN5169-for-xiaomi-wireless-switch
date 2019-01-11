/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          Temperature Management Implementation
 *
 * DESCRIPTION:        Set of functions/task for temperature related behaviour
 *
 ****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products [NXP Microcontrollers such as JN5168, JN5164,
 * JN5161, JN5148, JN5142, JN5139].
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
 * Copyright NXP B.V. 2012. All rights reserved
 *
 ***************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include <jendefs.h>
#include "os.h"
#include "os_gen.h"
#include "AppHardwareApi.h"
#include "app_timer_driver.h"
#include "app_manage_temperature.h"
#include "DriverBulb.h"
#include "DBG.h"
#include "recal.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#define TEMP_XTAL_HALF_PULL             95  /*  95C */
#define TEMP_XTAL_HALF_PUSH             93  /*  93C */
#define TEMP_XTAL_FULL_PULL            110  /* 110C */
#define TEMP_XTAL_FULL_PUSH            108  /* 108C */

#define ADC_REG                        0x02001f04

#define TEMPERATURE_DECIMATION_FACTOR  10

#ifdef DEBUG_TEMPERATURE
#define TRACE_APP_TEMPERATURE           	TRUE
#else
#define TRACE_APP_TEMPERATURE				FALSE
#endif

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
typedef enum
{
	E_STATE_XTAL_UNPULLED = 0,
	E_STATE_XTAL_SEMIPULLED = 1,
	E_STATE_XTAL_PULLED = 3
} teXtalPullingStates;


/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/

PRIVATE void vPullXtal(int32 i32Temperature);
PRIVATE int16 i16GetChipTemp(uint16 u16AdcValue);

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC void APP_vManageTemperatureInit(void)
{
	/* set up the ADCS on platforms that dont already use them */
#if (defined DR1175) || (defined DR1173) || (defined DR1190)
	/* Set up the analogue peripherals ready to handle the conversions */
	vAHI_ApConfigure(E_AHI_AP_REGULATOR_ENABLE,
					 E_AHI_AP_INT_DISABLE,
                     E_AHI_AP_SAMPLE_2,
                     E_AHI_AP_CLOCKDIV_500KHZ,
                     E_AHI_AP_INTREF);

    while (!bAHI_APRegulatorEnabled());   /* spin on reg not enabled */
#endif
    DBG_vPrintf(TRACE_APP_TEMPERATURE, "\nAPP: InitManageTemperature");
}

/****************************************************************************
*
* NAME: APP_RadioRecal
*
* DESCRIPTION:
* Calibrates the radio every minute or defer for 10 seconds if MAC busy
*
****************************************************************************/
OS_TASK(APP_RadioRecal)
{
    DBG_vPrintf(TRACE_APP_TEMPERATURE,"\nAPP: Recal Radio ");

	if (eAHI_AttemptCalibration() == E_CAL_SUCCESS)
	{
		OS_eStopSWTimer(APP_RadioRecalTimer);
		OS_eStartSWTimer(APP_RadioRecalTimer, APP_TIME_SEC(60), NULL);
		DBG_vPrintf(TRACE_APP_TEMPERATURE,"OK");
	}
	else
	{
		OS_eStopSWTimer(APP_RadioRecalTimer);
		OS_eStartSWTimer(APP_RadioRecalTimer, APP_TIME_SEC(10), NULL);
		DBG_vPrintf(TRACE_APP_TEMPERATURE,"deferred (MAC busy)");
	}
}

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

/****************************************************************************/
/* NAME: vPullXtal                                                          */
/*                                                                          */
/* DESCRIPTION:                                                             */
/* Oscillator pulling State machine                                         */
/****************************************************************************/
PRIVATE void vPullXtal(int32 i32Temperature)
{
	static teXtalPullingStates eXtalPullingState = E_STATE_XTAL_UNPULLED;

    DBG_vPrintf(TRACE_APP_TEMPERATURE, "\nAPP: T =%d C",i32Temperature);

	switch (eXtalPullingState)
	{
		case  E_STATE_XTAL_UNPULLED :
			if (i32Temperature >= TEMP_XTAL_HALF_PULL)
			{
				DBG_vPrintf(TRACE_APP_TEMPERATURE, "\nAPP: Xtal 1/2 pulled");
				eXtalPullingState = E_STATE_XTAL_SEMIPULLED;
				vAHI_ClockXtalPull(eXtalPullingState);
			}
			break;

		case  E_STATE_XTAL_SEMIPULLED :
			if (i32Temperature >= TEMP_XTAL_FULL_PULL)
			{
				DBG_vPrintf(TRACE_APP_TEMPERATURE, "\nAPP: Xtal full pulled");
				eXtalPullingState = E_STATE_XTAL_PULLED;
				vAHI_ClockXtalPull(eXtalPullingState);
			}
			else if (i32Temperature < TEMP_XTAL_HALF_PUSH)
			{
				DBG_vPrintf(TRACE_APP_TEMPERATURE, "\nAPP: Xtal not pulled");
				eXtalPullingState = E_STATE_XTAL_UNPULLED;
				vAHI_ClockXtalPull(eXtalPullingState);
			}
			break;

		case  E_STATE_XTAL_PULLED :
			if (i32Temperature < TEMP_XTAL_FULL_PUSH)
			{
				DBG_vPrintf(TRACE_APP_TEMPERATURE, "\nAPP: Xtal 1/2 pulled");
				eXtalPullingState = E_STATE_XTAL_SEMIPULLED;
				vAHI_ClockXtalPull(eXtalPullingState);
			}
			break;

		default :
		break;
	}
}
/****************************************************************************/
/* NAME: APP_vManageTemperatureTick                                         */
/*                                                                          */
/* DESCRIPTION:                                                             */
/* uses the tick count to schedule the adc conversions                      */
/****************************************************************************/

PUBLIC void APP_vManageTemperatureTick(uint32 u32Ticks)
{
	static uint32 u32DecimationCounter = TEMPERATURE_DECIMATION_FACTOR;

    uint16 u16AdcTempSensor;
    int32 i32ChipTemperature;



	/* every second interleave a temperature adc conversion start */
	if (u32Ticks == 90)
	{
        if (!bAHI_APRegulatorEnabled())
        {
	        vAHI_ApConfigure(E_AHI_AP_REGULATOR_ENABLE,
						 E_AHI_AP_INT_DISABLE,
						 E_AHI_AP_SAMPLE_2,
						 E_AHI_AP_CLOCKDIV_500KHZ,
						 E_AHI_AP_INTREF);

	        while (!bAHI_APRegulatorEnabled());   /* spin on reg not enabled */
        }

		vAHI_AdcEnable(E_AHI_ADC_SINGLE_SHOT,E_AHI_AP_INPUT_RANGE_1,E_AHI_ADC_SRC_TEMP);
		vAHI_AdcStartSample();
	}

	/*...and read it 5 ms later */
	if (u32Ticks == 95)
	{
		/* only take every reading every 10 seconds */
		if (--u32DecimationCounter == 0)
		{
			u32DecimationCounter = TEMPERATURE_DECIMATION_FACTOR;
			if (DriverBulb_u16GetAdcValue)
			{
				u16AdcTempSensor = DriverBulb_u16GetAdcValue(4);
			}
			else
			{
				u16AdcTempSensor = u16AHI_AdcRead();
			}

		    i32ChipTemperature = i16GetChipTemp(u16AdcTempSensor);
            vPullXtal(i32ChipTemperature);

		}
	}
}

/****************************************************************************/
/* NAME: i16GetChipTemp                                                     */
/*                                                                          */
/* DESCRIPTION:                                                             */
/* Helper Function to convert 10bit ADC reading to degrees C                */
/* Formula: DegC = Typical DegC - ((Reading12 - Typ12) * ScaleFactor)       */
/* Where C = 25 and temps sensor output 730mv at 25C (from datasheet)       */
/* As we use 2Vref and 10bit adc this gives (730/2400)*4096  [=Typ12 =1210] */
/*                                                                          */
/* RETURNS: Chip Temperature in DegC                                        */
/****************************************************************************/
PRIVATE int16 i16GetChipTemp(uint16 u16AdcValue)
{
	int16 i16Centigrade;

	i16Centigrade = 25-(((u16AdcValue-605)*723) >> 10);

	return (i16Centigrade);
}
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

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

/* SDK includes */
#include <jendefs.h>
#include "AppHardwareApi.h"

/* DK4 includes */
#include "PCA9634.h"
#include "LightingBoard.h"

/* Device includes */
#include "DriverBulb.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#define ADC_FULL_SCALE   1023
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Global Variables                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
PRIVATE bool_t bBulbOn = FALSE;
/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC void DriverBulb_vInit(void)
{
	static bool_t bFirstCalled = TRUE;

	if (bFirstCalled)
	{
		bRGB_LED_Enable();
		bPCA9634_WriteRegister(PCA9634_MODE2, 0x14);
		bRGB_LED_On();
		bRGB_LED_SetLevel(255,255,255);
        bRGB_LED_SetGroupLevel( 255);
		bBulbOn = TRUE;
		bFirstCalled = FALSE;
	}
}

PUBLIC void DriverBulb_vOn(void)
{
	DriverBulb_vSetOnOff(TRUE);
}

PUBLIC void DriverBulb_vOff(void)
{
	DriverBulb_vSetOnOff(FALSE);
}

PUBLIC void DriverBulb_vSetOnOff(bool_t bOn)
{
	 (bOn) ? bRGB_LED_On(): bRGB_LED_Off();
     bBulbOn =  bOn;
}

PUBLIC void DriverBulb_vSetLevel(uint32 u32Level)
{
	bRGB_LED_SetGroupLevel(MAX(1, u32Level));
}

PUBLIC void DriverBulb_vSetColour(uint32 u32Red, uint32 u32Green, uint32 u32Blue)
{
	bRGB_LED_SetLevel(u32Red,u32Green,u32Blue);
}

PUBLIC bool_t DriverBulb_bOn(void)
{
	return (bBulbOn);
}

PUBLIC bool_t DriverBulb_bReady(void)
{
	return (TRUE);
}

PUBLIC bool_t DriverBulb_bFailed(void)
{
	return (FALSE);
}

PUBLIC void DriverBulb_vTick(void)
{
/* No timing behaviour needed in DR1173 */
}

PUBLIC int16 DriverBulb_i16Analogue(uint8 u8Adc, uint16 u16AdcRead)
{
	if (u8Adc == E_AHI_ADC_SRC_VOLT)
	{
		return ((u16AdcRead * 3600)/ADC_FULL_SCALE);
	}
	else
	{
		return(ADC_FULL_SCALE);
	}
}

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

/*
 * MODULE:             JN-AN-1171
 *
 * COMPONENT:          low_bat_indicator.h
 *
 * DESCRIPTION:        Generic Low battery Indication - Interface
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
#ifndef  LOWBAT_H_INCLUDED
#define  LOWBAT_H_INCLUDED

#if defined __cplusplus
extern "C" {
#endif

/****************************************************************************/
/***        Include Files                                                 ***/
/****************************************************************************/
/* Jennic include files */
#include <jendefs.h>

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#ifdef MK_DK2
#define LHS_LED_DIO (1 << 16)
#define RHS_LED_DIO (1 << 17)
#else
#define LHS_LED_DIO (1 << 0)
#define RHS_LED_DIO (1 << 1)
#endif
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

typedef enum
{
	E_BO_TRIP_1V95 = 0,
	E_BO_TRIP_2V0  = 2,
	E_BO_TRIP_2V1  = 4,
	E_BO_TRIP_2V2  = 6,
	E_BO_TRIP_2V3  = 8,
	E_BO_TRIP_2V4  = 10,
	E_BO_TRIP_2V7  = 12,
	E_BO_TRIP_3V0  = 14
} teBrownOutTripVoltage;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC void vLowBatIndicationInit(uint32 u32LedMask,teBrownOutTripVoltage eBOTripValue);
PUBLIC void vCbSystemController(uint32 u32DeviceId, uint32 u32ItemBitmap);

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/


#if defined __cplusplus
}
#endif

#endif  /* LOWBAT_H_INCLUDED */

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/



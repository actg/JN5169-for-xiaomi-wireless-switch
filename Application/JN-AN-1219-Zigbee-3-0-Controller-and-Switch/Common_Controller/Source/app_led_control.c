/*****************************************************************************
 *
 * MODULE:             JN-AN-1219
 *
 * COMPONENT:          app_led_control.c
 *
 * DESCRIPTION:        ZLO Demo - Led Control Implementation
 *
 ****************************************************************************
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
 *
 ***************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include <jendefs.h>
#include "dbg.h"
#include "app_led_control.h"
#include "AppHardwareApi.h"
#include "ZTimer.h"
#include "app_main.h"
#ifdef DR1199
#include "GenericBoard.h"
#include "app_serial_interface.h"
#endif

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#define DIO_BASE_ADDR 0x02002000UL
#define DIO_LED_MASK  0x03UL
#define LED_BLINK_TIME ZTIMER_TIME_MSEC(50)    /*  0.05sec blink time */

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

typedef struct
{
    uint32 u32DioDirection;
    uint32 u32DioOutput;
    const volatile uint32 u32DioInput;
} tsDio;

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
PRIVATE void vAppSetLedState(uint32 u32LedMask, bool_t bOn );

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

tsDio * const psDio = (tsDio *)DIO_BASE_ADDR;

PRIVATE teShiftLevel eAppShiftLevel;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC void APP_vInitLeds(void)
{
#ifdef DR1159
    vAHI_DioSetPullup( DIO_LED_MASK,0);        /* pull up on */
    psDio->u32DioDirection &= ~DIO_LED_MASK;   /* input */
#elif (defined DR1199)
    vAHI_DioSetDirection(0, BOARD_LED_CTRL_MASK);
#endif
}


PUBLIC void APP_vBlinkLeds(teShiftLevel eShiftLevel)
{
    eAppShiftLevel = eShiftLevel;
    APP_vSetLeds((~eShiftLevel) & DIO_LED_MASK);
    ZTIMER_eStop(u8TimerLedBlink);
    ZTIMER_eStart(u8TimerLedBlink, LED_BLINK_TIME);

}

PUBLIC void APP_vSetLeds(teShiftLevel eShiftLevel)
{
    (eShiftLevel & 0x01) ? vAppSetLedState(1<<0, 1): vAppSetLedState(1<<0, 0);
    (eShiftLevel & 0x02) ? vAppSetLedState(1<<1, 1): vAppSetLedState(1<<1, 0);
#ifdef DR1199
    uint8 u8Leds = (uint8)eShiftLevel;
    /* this serial protocol message will cause what looks like garbage debug output on a terminal */
    vSL_WriteMessage(SERIAL_MSG_TYPE_LEDS, SERIAL_MSG_LENGTH_LEDS, &u8Leds);
#endif
}

PRIVATE void vAppSetLedState(uint32 u32LedMask, bool_t bOn )
{
#ifdef DR1159
     if (bOn)
     {
           vAHI_DioSetPullup(0,u32LedMask);        /* pull up off */
           psDio->u32DioDirection |= u32LedMask;   /* pin an output */
           psDio->u32DioOutput &= ~u32LedMask;     /* output low */
     }
     else
     {
           vAHI_DioSetPullup(u32LedMask,0);        /* pull up on */
           psDio->u32DioDirection &= ~u32LedMask;  /* pin an input */
     }
#elif (defined DR1199)
     if (u32LedMask & 0x01)
     {
         if (bOn)
         {
             /* leds on dr1199 driven high for on */
             vAHI_DioSetOutput(BOARD_LED_D1_PIN , 0);
         }
         else
         {
             vAHI_DioSetOutput(0, BOARD_LED_D1_PIN);
         }
     }
     if (u32LedMask & 0x02)
     {
         if (bOn)
         {
             /* leds on dr1199 driven high for on */
             vAHI_DioSetOutput(BOARD_LED_D2_PIN , 0);
         }
         else
         {
             vAHI_DioSetOutput(0, BOARD_LED_D2_PIN);
         }
     }
#endif
}


PUBLIC void APP_cbTimerLedBlink(void *pvParam)
{
    APP_vSetLeds(eAppShiftLevel);
}

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

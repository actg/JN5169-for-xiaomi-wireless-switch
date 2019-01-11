/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          app_led_control.c
 *
 * DESCRIPTION:        ZHA demo - Led Control Implementation
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
#include "app_led_control.h"
#include "AppHardwareApi.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#define DIO_BASE_ADDR 0x02002000UL
#define DIO_LED_MASK  0x03UL
#define LED_BLINK_TIME 8E5                /*  16E6/8E5 = 0.05sec blink time */

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

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
/****************************************************************************
 *
 * NAME: APP_vInitLeds
 *
 * DESCRIPTION:
 *
 * Initialises the LEDs
 *
 * PARAMETERS:      Name            RW  Usage
 *
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_vInitLeds(void)
{
    vAHI_DioSetPullup( DIO_LED_MASK,0);        /* pull up on */
    psDio->u32DioDirection &= ~DIO_LED_MASK;  /* input */
}
/****************************************************************************
 *
 * NAME: APP_vBlinkLeds
 *
 * DESCRIPTION:
 *
 * Initiates a blink for the LEDs
 *
 * PARAMETERS:      Name            RW  Usage
 * teShiftLevel eShiftLevel            The shift level the remote is in
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_vBlinkLeds(teShiftLevel eShiftLevel)
{
    APP_vSetLeds((~eShiftLevel) & DIO_LED_MASK);
    OS_eStartSWTimer(APP_LedBlinkTimer,LED_BLINK_TIME,(void*)eShiftLevel);
}
/****************************************************************************
 *
 * NAME: APP_vSetLeds
 *
 * DESCRIPTION:
 *
 * Sets the correct state of the LEDs depending on the shift level
 *
 * PARAMETERS:      Name            RW  Usage
 * teShiftLevel eShiftLevel            The shift level the remote is in
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_vSetLeds(teShiftLevel eShiftLevel)
{
    (eShiftLevel & 0x01) ? vAppSetLedState(1<<0, 1): vAppSetLedState(1<<0, 0);
    (eShiftLevel & 0x02) ? vAppSetLedState(1<<1, 1): vAppSetLedState(1<<1, 0);
}
/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/
/****************************************************************************
 *
 * NAME: vAppSetLedState
 *
 * DESCRIPTION:
 *
 * Sets the correct state of the LEDs depending on the shift level
 *
 * PARAMETERS:      Name            RW  Usage
 * uint32 u32LedMask                DIO mask for LEDs
 * bool_t bOn                        On or Off bool flag
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vAppSetLedState(uint32 u32LedMask, bool_t bOn )
{
     if (bOn)
     {
           vAHI_DioSetPullup(0,u32LedMask);        /* pull up off */
           psDio->u32DioDirection |= u32LedMask;   /* pin an output */
           psDio->u32DioOutput &= ~u32LedMask;      /* output low */
     }
     else
     {
           vAHI_DioSetPullup(u32LedMask,0);        /* pull up on */
           psDio->u32DioDirection &= ~u32LedMask;  /* pin an input */
     }
}
/****************************************************************************
 *
 * NAME: App_cbBlinkLed
 *
 * DESCRIPTION:
 *
 * OS timer call back
 *
 * PARAMETERS:      Name            RW  Usage
 * pvDummy                            Pointer to data
 * RETURNS:
 * void
 *
 ****************************************************************************/

OS_SWTIMER_CALLBACK(App_cbBlinkLed, pvDummy)
{
    APP_vSetLeds( (teShiftLevel)pvDummy );

}

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

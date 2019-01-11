/*****************************************************************************
 *
 * MODULE:          JN-AN-1189
 *
 * COMPONENT:       app_blink_led.c
 *
 * DESCRIPTION:     ZHA Demo: Blinks an LED a number of pre defined ticks
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
 * Copyright NXP B.V. 2013. All rights reserved
 *
 ***************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include "dbg.h"
#include "App_OccupancySensor.h"
#include "GenericBoard.h"
#include "AppHardwareApi.h"
#include "os.h"
#include "os_gen.h"
#include "pwrm.h"
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifdef DEBUG_BLINK_LED
    #define TRACE_BLINK_LED   TRUE
#else
    #define TRACE_BLINK_LED   FALSE
#endif
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
#define BLINK_LED    GEN_BOARD_LED_D3_VAL
/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
PRIVATE void vToggleLED(void);
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
PRIVATE bool_t bDIO1State = FALSE;
PRIVATE uint32 u32BlinkTickTime = 0;
/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

/****************************************************************************
 *
 * NAME: APP_BlinkLED
 *
 * DESCRIPTION:
 * Toggles LED 2 and restarts the timer.
 * RETURNS:
 * void
 *
 ****************************************************************************/
OS_TASK(APP_BlinkLED)
{
    DBG_vPrintf(TRACE_BLINK_LED, "\nAPP Blink LED: Task Started");
    vToggleLED();
    OS_eContinueSWTimer(APP_BlinkTimer, u32BlinkTickTime, NULL);
}

/****************************************************************************
 *
 * NAME: vStartBlinkTimer
 *
 * DESCRIPTION:
 * Starts the software timer and blinks it the desired amount of ticks. It also
 * stores the time so the Task can restart it with the defined time
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vStartBlinkTimer(uint32 u32Ticks)
{
    DBG_vPrintf(TRACE_BLINK_LED, "\nAPP Blink LED: Starting Blink Timer value = %d", u32Ticks);
    u32BlinkTickTime = u32Ticks;
    OS_eStartSWTimer(APP_BlinkTimer, u32Ticks, NULL);
}

/****************************************************************************
 *
 * NAME: vStopBlinkTimer
 *
 * DESCRIPTION:
 * Stops the blink timer and turns the LED off
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vStopBlinkTimer(void)
{
    DBG_vPrintf(TRACE_BLINK_LED, "\nAPP Blink LED: Stopping Blink Timer");
    OS_eStopSWTimer(APP_BlinkTimer);
    u32BlinkTickTime = 0;
    vGenericLEDSetOutput(BLINK_LED, FALSE);
}

/****************************************************************************/
/***        Local Function                                                   ***/
/****************************************************************************/

/****************************************************************************
 *
 * NAME: vToggleLED
 *
 * DESCRIPTION:
 * Changes the state of LED 2
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vToggleLED(void)
{
    DBG_vPrintf(TRACE_BLINK_LED, "\nAPP Blink LED: Toggle LED to %b", !bDIO1State);
    bDIO1State = !bDIO1State;
    vGenericLEDSetOutput(BLINK_LED, bDIO1State);
}
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

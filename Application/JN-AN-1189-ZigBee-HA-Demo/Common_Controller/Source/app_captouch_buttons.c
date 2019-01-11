/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          app_captouch_buttons.c
 *
 * DESCRIPTION:        Capacitance Touch Button Handler -Implementation
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
#include "DBG.h"
#include "AppHardwareApi.h"
#include "app_events.h"
#include "app_timer_driver.h"
#include "pwrm.h"
#include "app_captouch_buttons.h"
#include "DriverCapTouch.h"
#include "low_bat_indicator.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#ifdef DEBUG_APP_BUTTON
#define TRACE_APP_BUTTON    TRUE
#else
#define TRACE_APP_BUTTON    FALSE
#endif

/* Hardware Timer aspects */
#define KEY_SCAN_TIMER      E_AHI_TIMER_1
#define KEY_SCAN_PERIOD     10000

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
/***        Local Variables                                               ***/
/****************************************************************************/

PRIVATE teUserKeyCodes eGetKeyCode(uint8 u8Button);

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
/****************************************************************************
 *
 * NAME: APP_bButtonInitialise
 *
 * DESCRIPTION:
 *
 * Initialises the touch button interface.
 *
 * PARAMETERS:      Name            RW  Usage
 *
 *
 * RETURNS:
 * if any button is pressed
 *
 ****************************************************************************/
PUBLIC bool_t APP_bButtonInitialise(void)
{


    DBG_vPrintf(TRACE_APP_BUTTON,"\nStarting Touch Interface...");
    /*
     * Initialise the touch Interface
     * */
    if (eTouchInit() != TOUCH_STATUS_OK)
    {
        DBG_vPrintf(TRACE_APP_BUTTON,"Failed");
        return FALSE;
    }

    DBG_vPrintf(TRACE_APP_BUTTON, "\nGetting background capacitance...");

    /* Get background capacitance */
    while(eTouchProcess() ==  TOUCH_STATUS_DONT_SLEEP);

    DBG_vPrintf(TRACE_APP_BUTTON,"OK");

#if TRACE_APP_BUTTON
    volatile int n;
    for(n = 0; n < 1000000; n++);
#endif

    DBG_vPrintf(TRACE_APP_BUTTON, "\nStarting Scanning...");

    vConfigureScanTimer();

    return FALSE;
}

/****************************************************************************
 *
 * NAME: APP_isrSystemController
 *
 * DESCRIPTION:
 *
 * ISR called on DIO interrupt, Wake timer interrupt
 * or Brown Out - SysCon Interrupt source
 *
 ****************************************************************************/
OS_ISR(APP_isrSystemController)
{

        /*
         * clear pending DIO changed bits by reading register
         * */
        u32AHI_DioInterruptStatus();

        /*
         * disable edge detection until scan complete
         * */
        vAHI_DioInterruptEnable(0, 1);
        /*
         * Get the wake interrupt status
         * */

        if ( u8AHI_WakeTimerFiredStatus() & E_AHI_WAKE_TIMER_MASK_1)
        {
            /*
             * wake timer interrupt got us here
             * Call the call back */
            PWRM_vWakeInterruptCallback();
        }

        /* check if we had a enter brown-out interrupt below VTrip*/

        if (u32AHI_BrownOutPoll() & E_AHI_SYSCTRL_VREM_MASK)
        {
            vCbSystemController(E_AHI_DEVICE_SYSCTRL,E_AHI_SYSCTRL_VREM_MASK);
        }
}


/****************************************************************************
 *
 * NAME: vCbTouchEventButton
 *
 * DESCRIPTION:
 *
 * Callback  function for the touch driver to called when
 * a button event is detected.
 *
 * PARAMETERS:      Name            RW  Usage
 *                  eEvent          R   The event that has been detected
 *                  u8ButtonNumber  R   The button number which experienced the event
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vCbTouchEventButton(eTouchButtonEvent eEvent, uint8 u8ButtonNumber)
{

    APP_tsEvent sButtonEvent;

    switch(eEvent)
    {

    case TOUCH_BUTTON_EVENT_PRESSED:
        sButtonEvent.eType = APP_E_EVENT_BUTTON_DOWN;
        sButtonEvent.uEvent.sButton.u8Button = eGetKeyCode(u8ButtonNumber);
        DBG_vPrintf(TRACE_APP_BUTTON, "\nKey %d Down", sButtonEvent.uEvent.sButton.u8Button);
        OS_ePostMessage(APP_msgEvents, &sButtonEvent);
        break;

    case TOUCH_BUTTON_EVENT_RELEASED:
        sButtonEvent.eType = APP_E_EVENT_BUTTON_UP;
        sButtonEvent.uEvent.sButton.u8Button = eGetKeyCode(u8ButtonNumber);
        DBG_vPrintf(TRACE_APP_BUTTON, "\nKey %d Up", sButtonEvent.uEvent.sButton.u8Button);
        OS_ePostMessage(APP_msgEvents, &sButtonEvent);
        break;

    case TOUCH_BUTTON_EVENT_ALL_RELEASED:
        break;

    }

}


/****************************************************************************
 *
 * NAME: APP_isrKeyScan
 *
 * DESCRIPTION:
 *
 * ISR for the Keyscan timer
 *
 * PARAMETERS:      Name            RW  Usage
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
OS_ISR(APP_isrKeyScan)
{
    /* Clear Timer 0 Interrupt */
    u8AHI_TimerFired(KEY_SCAN_TIMER);
    /* Scan the keys  (will result in call back if press/release occurs)     */
    eTouchProcess();
}


/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/
/****************************************************************************
 *
 * NAME: eGetKeyCode
 *
 * DESCRIPTION:
 *
 * returns the keycode
 *
 * PARAMETERS:      Name            RW  Usage
 *                    u8Button        accepts the button number
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE teUserKeyCodes eGetKeyCode(uint8 u8Button)
{

    teUserKeyCodes aeCode[] = {KEY_16,
                               KEY_12,
                               KEY_4,
                               KEY_8,
                               KEY_7,
                               KEY_3,
                               KEY_11,
                               KEY_10,
                               KEY_2,
                               KEY_6,
                               KEY_5,
                               KEY_1,
                               KEY_9,
                               KEY_13,
                               KEY_14,
                               KEY_15};

    return aeCode[u8Button];
}

/****************************************************************************
 *
 * NAME: vConfigureScanTimer
 *
 * DESCRIPTION: Enables 100Hz hardware timer for keyboard scanning
 *
 ****************************************************************************/
PUBLIC void vConfigureScanTimer(void)
{

    /* configure timer 0 for 100 HZ operation */
    vAHI_TimerEnable(KEY_SCAN_TIMER,4,FALSE,TRUE,FALSE);

    /* Make sure no DIO claimed by timer */
    vAHI_TimerDIOControl(KEY_SCAN_TIMER, FALSE);

    vAHI_TimerStartRepeat(KEY_SCAN_TIMER,(KEY_SCAN_PERIOD/2),KEY_SCAN_PERIOD);

}
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

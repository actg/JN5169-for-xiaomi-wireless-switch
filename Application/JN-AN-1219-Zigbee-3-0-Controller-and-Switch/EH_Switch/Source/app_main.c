/*****************************************************************************
 *
 * MODULE:             JN-AN-1219
 *
 * COMPONENT:          app_main.c
 *
 * DESCRIPTION:        EH switch app_main
 *
 *****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products [NXP Microcontrollers such as JN5148, JN5142,
 * JN5139]. You, and any third parties must reproduce the copyright and
 * warranty notice and any other legend of ownership on each copy or partial
 * copy of the software.
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
 ****************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#include "app_main.h"
#include "app_buttons.h"
#include "ZTimer.h"



#include "AppHardwareApi.h"
#include "PeripheralRegs.h"
#include <dbg.h>
#include <dbg_uart.h>
#include "EH_IEEE_802154_Switch.h"
#include "EH_Button.h"
#include "app_events.h"
#include "EH_IEEE_Features.h"
#include "AHI_EEPROM.h"
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#ifndef DEBUG_APP
#define TRACE_APP   FALSE
#else
#define TRACE_APP   TRUE
#endif

#define ON  (1 << APP_BUTTONS_BUTTON_SW1)
#define OFF (1 << APP_BUTTONS_BUTTON_SW2 )
#define UP (1 << APP_BUTTONS_BUTTON_SW3 )
#define DOWN (1 << APP_BUTTONS_BUTTON_SW4 )
#define COMM (1 << APP_BUTTONS_BUTTON_1)
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
PUBLIC void APP_cbTimerReceive(void *pvParam);
PUBLIC void APP_cbTimerShortPress(void *pvParam);
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
/* dummy variable for compilation */
uint16 s_u16ActivityCounter;

PUBLIC uint8 u8TimerButtonScan;
PUBLIC uint8 u8TimerReceive;
PUBLIC uint8 u8TimerButtonDelay;
PUBLIC uint8 u8TimerTick;
PUBLIC uint8 u8TimerChangeMode;
PUBLIC uint8 u8TimerShortPress;
PUBLIC tszQueue APP_msgAppEvents;

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
PRIVATE ZTIMER_tsTimer asTimers[3];

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/


/****************************************************************************
 *
 * NAME: APP_ZLO_Switch_Task
 *
 * DESCRIPTION:
 * Task that handles the application related functionality
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
bool_t ZQ_bQueueSend(void *pvQueueHandle, const void *pvItemToQueue)
{
    APP_tsEvent *psAppEvent = (APP_tsEvent *)pvItemToQueue;
    te_TransitionCode eTransitionCode = NUMBER_OF_TRANSITION_CODE;

    switch(psAppEvent->eType)
    {

    case APP_E_EVENT_BUTTON_DOWN:
        DBG_vPrintf(DBG_DEVICE_SWITCH, "\nButton Down Number= %d",psAppEvent->uEvent.sButton.u8Button);
        DBG_vPrintf(DBG_DEVICE_SWITCH, "\nDIO State    = %08x\n",psAppEvent->uEvent.sButton.u32DIOState);


        eTransitionCode = psAppEvent->uEvent.sButton.u8Button;
        if(0 == (psAppEvent->uEvent.sButton.u32DIOState & (UP | ON)))
        eTransitionCode = UP_AND_ON_TOGETHER_PRESSED;


        DBG_vPrintf(DBG_DEVICE_SWITCH, "\nTransition Code = %d\n",eTransitionCode);

        vHandleButtonPress(eTransitionCode);
        break;

    case APP_E_EVENT_BUTTON_UP:
        DBG_vPrintf(DBG_DEVICE_SWITCH, "\nButton Up Number= %d",psAppEvent->uEvent.sButton.u8Button);
        DBG_vPrintf(DBG_DEVICE_SWITCH, "\nDIO State    = %08x\n",psAppEvent->uEvent.sButton.u32DIOState);

        switch (psAppEvent->uEvent.sButton.u8Button)
        {

        case APP_E_BUTTONS_BUTTON_1:
            eTransitionCode = COMM_BUTTON_RELEASED;
            break;

        case APP_E_BUTTONS_BUTTON_SW4:
            eTransitionCode = DOWN_RELEASED;
            break;

        case APP_E_BUTTONS_BUTTON_SW3:
            eTransitionCode = UP_RELEASED;
            break;

        default :
            break;

        }
        vHandleButtonPress(eTransitionCode);
        break;

    default :
        break;

    }
    ZTIMER_eStop(u8TimerShortPress);
    ZTIMER_eStart(u8TimerShortPress, ZTIMER_TIME_SEC(3));
    return 0;
}




/****************************************************************************
 *
 * NAME: APP_vInitResources
 *
 * DESCRIPTION:
 * Initialise resources (timers, queue's etc)
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_vInitResources(void)
{

    /* Initialise the Z timer module */
    ZTIMER_eInit(asTimers, (sizeof(asTimers) / sizeof(ZTIMER_tsTimer)));


    ZTIMER_eOpen(&u8TimerButtonScan,    APP_cbTimerButtonScan,  NULL, ZTIMER_FLAG_PREVENT_SLEEP);
    ZTIMER_eOpen(&u8TimerReceive,       APP_cbTimerReceive,     NULL, ZTIMER_FLAG_PREVENT_SLEEP);
    ZTIMER_eOpen(&u8TimerShortPress,    APP_cbTimerShortPress,  NULL, ZTIMER_FLAG_PREVENT_SLEEP);

}
PUBLIC void APP_cbTimerShortPress(void *pvParam)
{
    bEnableSleep = TRUE;
}

PUBLIC void APP_cbTimerReceive(void *pvParam)
{
//	bRxTimerExpired = TRUE;
}

PUBLIC void PWRM_vWakeInterruptCallback(void)
{

}
/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

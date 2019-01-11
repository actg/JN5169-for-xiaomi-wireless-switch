/*****************************************************************************
 *
 * MODULE:          JN-AN-1189
 *
 * COMPONENT:       app_event_handler.c
 *
 * DESCRIPTION:     ZHA Demo: Handles all the different type of Application events
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
#include "app_events.h"
#include "zha_sensor_node.h"
#include "haEzFindAndBind.h"
#include "app_sensor_state_machine.h"
#include "os_gen.h"
#include "App_OccupancySensor.h"
#include "app_sleep_handler.h"
#include "app_event_handler.h"
#include "app_PIR_events.h"
#include "app_reporting.h"
#include "app_blink_led.h"
#include "AppHardwareApi.h"
#include "app_nwk_event_handler.h"
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifdef DEBUG_EVENT_HANDLER
    #define TRACE_EVENT_HANDLER   TRUE
#else
    #define TRACE_EVENT_HANDLER   FALSE
#endif
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
PRIVATE void vDioEventHandler(te_TransitionCode eTransitionCode);
PRIVATE void vEventStartFindAndBind(void);
PRIVATE void vEventStopFindAndBind(void);
PRIVATE void vStartPersistantPolling(void);
PRIVATE void vStopPersistantPolling(void);
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
extern const uint8 u8MyEndpoint;
/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
/****************************************************************************
 *
 * NAME: vDioEventHandler
 *
 * DESCRIPTION:
 * Processes the Dio events like binding and occupancy. Any other events that
 * come through we immediately attempt to go to sleep as we have no process for
 * them.
 *
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vDioEventHandler(te_TransitionCode eTransitionCode )
{
    DBG_vPrintf(TRACE_EVENT_HANDLER,"\nAPP Process Buttons: In vSensorStateMachine TransitionCode = %d -> ",eTransitionCode);
    switch(eTransitionCode)
    {
        /* Fall through for the button presses as there will be a delayed action*/
        case COMM_BUTTON_PRESSED:
            vEventStartFindAndBind();
            break;

        case COMM_BUTTON_RELEASED:
            vEventStopFindAndBind();
            break;

        case SW1_PRESSED:
            vHandleFallingEdgeEvent();
            break;

        case SW1_RELEASED:
            vHandleRisingEdgeEvent();
            break;

        case SW2_PRESSED:
            vStartPersistantPolling();
            break;
        case SW3_PRESSED:
            vStopPersistantPolling();
            break;
        case SW2_RELEASED:
        case SW3_RELEASED:
        case SW4_RELEASED:
        case SW4_PRESSED:
            vAttemptToSleep();
            break;
        default:
            break;
    }
}

/****************************************************************************
 *
 * NAME: vAppHandleAppEvent
 *
 * DESCRIPTION:
 * interprets the button press and calls the state machine.
 *
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppHandleAppEvent(APP_tsEvent sButton)
{
    te_TransitionCode eTransitionCode=NUMBER_OF_TRANSITION_CODE;

    switch(sButton.eType)
    {
        case APP_E_EVENT_BUTTON_DOWN:
            DBG_vPrintf(TRACE_EVENT_HANDLER, "\nAPP Process Buttons: Button Number= %d",sButton.uEvent.sButton.u8Button);
            DBG_vPrintf(TRACE_EVENT_HANDLER, "\nAPP Process Buttons: DIO State    = %08x",sButton.uEvent.sButton.u32DIOState);
            DBG_vPrintf(TRACE_EVENT_HANDLER, "\nAPP Process Buttons: Transition Code = %d",eTransitionCode);

            eTransitionCode=sButton.uEvent.sButton.u8Button;
            vDioEventHandler(eTransitionCode);
            break;

        case APP_E_EVENT_BUTTON_UP:
            DBG_vPrintf(TRACE_EVENT_HANDLER, "\nAPP Process Buttons: Button Number= %d",sButton.uEvent.sButton.u8Button);
            DBG_vPrintf(TRACE_EVENT_HANDLER, "\nAPP Process Buttons: DIO State    = %08x",sButton.uEvent.sButton.u32DIOState);

            eTransitionCode = BUTTON_RELEASED_OFFSET | sButton.uEvent.sButton.u8Button;

            DBG_vPrintf(TRACE_EVENT_HANDLER, "\nAPP Process Buttons: Transition Code = %d",eTransitionCode);
            vDioEventHandler(eTransitionCode);
            break;

        case APP_E_EVENT_WAKE_TIMER:
            vHandleWakeTimeoutEvent();
            break;
        case APP_E_EVENT_SEND_REPORT:
            vSendImmediateReport();
            /* Let it fall into the vAttemptToSleep function with no break*/
        case APP_E_EVENT_FAILED_DEBOUNCE:
        case APP_E_EVENT_NO_BUTTON_CHANGE:
        case APP_E_EVENT_PERIODIC_REPORT:
            /* All these events are sent to tell us to sleep*/
            vAttemptToSleep();
            break;

        default :

            break;
    }
}
/****************************************************************************/
/***        Local Functions                                                  ***/
/****************************************************************************/
/****************************************************************************
 *
 * NAME: vEventStartFindAndBind
 *
 * DESCRIPTION:
 * Initiates the find and bind procedure, Starts a poll timer and the blink
 * timer.
 *
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vEventStartFindAndBind(void)
{
    DBG_vPrintf(TRACE_EVENT_HANDLER,"\nAPP Process Buttons: eEZ_FindAndBind");
    /* Exclude These Clusters */
    eEZ_ExcludeClusterFromEZBinding(GENERAL_CLUSTER_ID_BASIC,TRUE);
    eEZ_ExcludeClusterFromEZBinding(GENERAL_CLUSTER_ID_BASIC,FALSE);
    eEZ_ExcludeClusterFromEZBinding(GENERAL_CLUSTER_ID_GROUPS,FALSE);
    eEZ_ExcludeClusterFromEZBinding(GENERAL_CLUSTER_ID_IDENTIFY,TRUE);
    eEZ_ExcludeClusterFromEZBinding(GENERAL_CLUSTER_ID_IDENTIFY,FALSE);
    vAPP_ZCL_DeviceSpecific_SetIdentifyTime(0xFF);
    eEZ_FindAndBind(u8MyEndpoint,E_EZ_INITIATOR);
    vStartPollTimerTask(POLL_TIME_FAST);
    vStartBlinkTimer(APP_FIND_AND_BIND_BLINK_TIME);
}

/****************************************************************************
 *
 * NAME: vEventStopFindAndBind
 *
 * DESCRIPTION:
 * Stops the find and bind procedure and attempts to sleep.
 *
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vEventStopFindAndBind(void)
{
    DBG_vPrintf(TRACE_EVENT_HANDLER,"\nAPP Process Buttons: Exit Easy Mode");
    vAPP_ZCL_DeviceSpecific_IdentifyOff();
    vEZ_Exit(u8MyEndpoint);
    vStopBlinkTimer();
    vStopPollTimerTask();
    vHandleNewJoinEvent();
    vAttemptToSleep();
}

/****************************************************************************
 *
 * NAME: vStartPersistantPolling
 *
 * DESCRIPTION:
 * Starts the Poll timer which will in turn keep the device awake so it can
 * receive data from it's parent.
 *
 ****************************************************************************/
PRIVATE void vStartPersistantPolling(void)
{
    vStartPollTimerTask(POLL_TIME_FAST);
    vStartBlinkTimer(APP_KEEP_AWAKE_TIME);
}

/****************************************************************************
 *
 * NAME: vStopPersistantPolling
 *
 * DESCRIPTION:
 * Stops the poll timer which will allow the device to go back to sleep.
 *
 ****************************************************************************/
PRIVATE void vStopPersistantPolling(void)
{
    vStopPollTimerTask();
    vStopBlinkTimer();
    vAttemptToSleep();
}

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

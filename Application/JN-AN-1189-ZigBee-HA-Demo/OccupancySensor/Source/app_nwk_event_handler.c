/*****************************************************************************
 *
 * MODULE:          JN-AN-1189
 *
 * COMPONENT:       app_nwk_event_handler.c
 *
 * DESCRIPTION:     ZHA Demo: Handles all network events like network join/leave
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
#include "haEzFindAndBind.h"
#include "os_gen.h"
#include "App_OccupancySensor.h"
#include "app_sleep_handler.h"
#include "app_common.h"
#include "app_zbp_utilities.h"
#include "app_nwk_event_handler.h"
#include "app_PIR_events.h"
#include "app_blink_led.h"
#include "AppHardwareApi.h"
#include "pwrm.h"
#include "pdum_gen.h"
#include "pdm.h"
#include "pdum_gen.h"
#include "PDM_IDs.h"
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifdef DEBUG_NWK_EVENT_HANDLER
    #define TRACE_NWK_EVENT_HANDLER   TRUE
#else
    #define TRACE_NWK_EVENT_HANDLER  FALSE
#endif
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
extern tsDeviceDesc sDeviceDesc;
extern PDM_tsRecordDescriptor sDevicePDDesc;
/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

PRIVATE uint32 u32PollTime = 0;
/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC void vStartPollTimerTask(uint32 u32PollInterval)
{
    u32PollTime = u32PollInterval;
    OS_eStartSWTimer(APP_PollTimer, u32PollTime, NULL);
}

PUBLIC void vStopPollTimerTask()
{
    u32PollTime = 0;
    OS_eStopSWTimer(APP_PollTimer);
}
/****************************************************************************
 *
 * NAME: APP_PollTask
 *
 * DESCRIPTION:
 * Poll Task for timed polling.
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
OS_TASK(APP_PollTask)
{
    ZPS_eAplZdoPoll();
    DBG_vPrintf(TRACE_NWK_EVENT_HANDLER, "\nAPP Poll Handler: Poll Sent");
    OS_eContinueSWTimer(APP_PollTimer, u32PollTime, NULL);
}

/****************************************************************************
 *
 * NAME: vHandlePollResponse
 *
 * DESCRIPTION:
 * Processes the poll response, Poll again if we have no ACK to force the Stack
 * to handle the failed poll count or poll to get the data.
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vHandlePollResponse(ZPS_tsAfEvent sStackEvent)
{
    DBG_vPrintf(TRACE_NWK_EVENT_HANDLER, "\nAPP NWK Event Handler: Poll Response");
    switch (sStackEvent.uEvent.sNwkPollConfirmEvent.u8Status)
    {
        case MAC_ENUM_SUCCESS:
        case MAC_ENUM_NO_ACK:
            ZPS_eAplZdoPoll();
            break;

        case MAC_ENUM_NO_DATA:
        default:
            break;
    }
}

/****************************************************************************
 *
 * NAME: vHandleFailedRejoin
 *
 * DESCRIPTION:
 * If we have failed to rejoin the network, keep trying until we hit our maximum
 * rejoin count in which we start like factory new.
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vHandleFailedRejoin(void)
{
    DBG_vPrintf(TRACE_NWK_EVENT_HANDLER, "\nAPP NWK Event Handler: Failed Rejoin");
    vStartStopTimer(APP_JoinTimer, APP_TIME_MS(1000),(uint8*)&(sDeviceDesc.eNodeState),E_REJOINING );
    vStartPollTimerTask(POLL_TIME_FAST);
    vStartBlinkTimer(APP_JOINING_BLINK_TIME);
}

/****************************************************************************
 *
 * NAME: vHandleNetworkJoinEndDevice
 *
 * DESCRIPTION:
 * If we have joined a new network or rejoined, stop the timer tell the PIR
 * event handler.
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vHandleNetworkJoinEndDevice(void)
{
    DBG_vPrintf(TRACE_NWK_EVENT_HANDLER, "\nAPP NWK Event Handler: Network Join End Device");
    vStopPollTimerTask();
    vStopBlinkTimer();
    vHandleNewJoinEvent();
    vAttemptToSleep();
}

/****************************************************************************
 *
 * NAME: vHandleNetworkLeave
 *
 * DESCRIPTION:
 * We have left the network so restart as factory new (not sure why we don't
 * restart the joining rather than restarting the whole device).
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vHandleNetworkLeave(ZPS_tsAfEvent sStackEvent)
{
    DBG_vPrintf(TRACE_NWK_EVENT_HANDLER, "\nAPP NWK Event Handler: Network Leave");
    if( sStackEvent.uEvent.sNwkLeaveIndicationEvent.u64ExtAddr == 0 )
    {
        DBG_vPrintf(TRACE_NWK_EVENT_HANDLER, "\nAPP NWK Event Handler: ZDO Leave" );
        PDM_vDeleteAllDataRecords();
        vAHI_SwReset();
    }
}

/****************************************************************************
 *
 * NAME: vHandleNetworkJoinAndRejoin
 *
 * DESCRIPTION:
 * Checks to see if we have joined a network. If we have, stop all the timers,
 * save the network state into PDM and attempt to sleep.
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vHandleNetworkJoinAndRejoin( ZPS_tsAfEvent *pZPSevent, teEZ_JoinAction eJoinAction  )
{
    teEZ_State ezState;
    /*Call The EZ mode Handler passing the events*/
    vEZ_EZModeNWKJoinHandler(pZPSevent,eJoinAction);
    ezState = eEZ_GetJoinState();
    DBG_vPrintf(TRACE_NWK_EVENT_HANDLER, "\nAPP NWK Event Handler: EZ_STATE\%x", ezState);
    if(ezState == E_EZ_DEVICE_IN_NETWORK)
    {
        /*The following Patch ensures the device will set the address allocate flag will set to FALSE during rejoin in future*/
        void* pvNwk;
        pvNwk = ZPS_pvAplZdoGetNwkHandle();
        ZPS_psNwkNibGetHandle( pvNwk)->sPersist.u8CapabilityInformation &= 0x7f;
        DBG_vPrintf(TRACE_NWK_EVENT_HANDLER,"\nThe sNib.sPersist.u8CapabilityInformation = %02x",ZPS_psNwkNibGetHandle( pvNwk)->sPersist.u8CapabilityInformation);

        DBG_vPrintf(TRACE_NWK_EVENT_HANDLER, "\nAPP NWK Event Handler: HA EZMode EVT: E_EZ_DEVICE_IN_NETWORK");
        OS_eStopSWTimer(APP_JoinTimer);
        vStopPollTimerTask();
        vStopBlinkTimer();
        sDeviceDesc.eNodeState = E_RUNNING;
        vHandleNewJoinEvent();

        PDM_eSaveRecordData(PDM_ID_APP_REMOTE_CONTROL,
                                &sDeviceDesc,
                                sizeof(tsDeviceDesc));
        ZPS_vSaveAllZpsRecords();
        vAttemptToSleep();
    }
}
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

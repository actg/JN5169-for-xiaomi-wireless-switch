/*
 * MODULE:             JN-AN-1219
 *
  * COMPONENT:          zlo_controller_node.c
 *
 * DESCRIPTION:        ZLO Demo: Remote Control Functionality -Implementation
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
#include <string.h>
#include <AppApi.h>
#include "pdum_apl.h"
#include "pdum_gen.h"
#include "PDM.h"
#include "dbg.h"
#include "dbg_uart.h"
#include "pwrm.h"
#include "zps_gen.h"
#include "zps_apl_af.h"
#include "zps_apl_zdo.h"
#include "zps_apl_aib.h"
#include "zps_apl_zdp.h"
#include "rnd_pub.h"
#include "bdb_api.h"
#include "bdb_tl.h"
#include "bdb_fb_api.h"

#include "app_common.h"
#include "app_main.h"
#ifdef JN517x
#include "AHI_ModuleConfiguration.h"
#endif

#include "app_menu_handler.h"

#include "PDM_IDs.h"

#include "ZTimer.h"
#ifdef DR1159
#include "DriverCapTouch.h"
#endif
#ifdef DR1199
#include "app_buttons.h"
#endif
#include "app_led_control.h"
#include "zlo_controller_node.h"

#include "eventStrings.h"
#include "app_zcl_controller_task.h"
#include "zlo_controller_node.h"
#include "app_events.h"
#include "zcl_customcommand.h"

#include "zlo_device_id.h"

//#include "appZpsBeaconHandler.h"

#include "app_group_commands.h"
#include "app_identify_commands.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#ifdef DEBUG_APP
    #define TRACE_APP   TRUE
#else
    #define TRACE_APP   FALSE
#endif

#ifdef DEBUG_REMOTE_NODE
    #define TRACE_REMOTE_NODE   TRUE
#else
    #define TRACE_REMOTE_NODE   FALSE
#endif

#ifndef DEBUG_CLASSIC_JOIN
#define TRACE_CLASSIC FALSE
#else
#define TRACE_CLASSIC TRUE
#endif

#ifdef DEBUG_LIGHT_AGE
#define TRACE_LIGHT_AGE   TRUE
#else
#define TRACE_LIGHT_AGE   FALSE
#endif

#ifndef DEBUG_SLEEP
#define TRACE_SLEEP FALSE
#else
#define TRACE_SLEEP TRUE
#endif

#ifndef DEBUG_REJOIN
#define TRACE_REJOIN FALSE
#else
#define TRACE_REJOIN TRUE
#endif

/* ZDO endpoint for all devices is always 0 */
#define CONTROLLER_ZDO_ENDPOINT    (0)

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/


/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
PRIVATE void vWakeCallBack(void);
PRIVATE void vStopAllTimers(void);
PRIVATE void vAppHandleAfEvent( BDB_tsZpsAfEvent *psZpsAfEvent);
PRIVATE void vHandleWaitStartAppEvent(APP_tsEvent* psAppEvent);
PRIVATE void vHandleRunningAppEvent(APP_tsEvent* psAppEvent);
PRIVATE void vHandleRunningStackEvent(ZPS_tsAfEvent* psStackEvent);
PRIVATE void vHandleWaitStartStackEvent(ZPS_tsAfEvent* psStackEvent);
PRIVATE void vAppHandleTouchLink(APP_tsEvent* psAppEvent);
PRIVATE void vAppHandleEndpointInfo(APP_tsEvent* psAppEvent);
PRIVATE void vAppHandleEndpointList(APP_tsEvent* psAppEvent);
PRIVATE void vAppHandleGroupList(APP_tsEvent* psAppEvent);
PRIVATE void vResetSleepAndJoinCounters(void);
PRIVATE bool bIsDeviceController(uint16 u16DeviceId);
PRIVATE bool bIsDeviceLight(uint16 u16DeviceId);
PRIVATE uint8 u8GetFirstPrimaryChannel( void);
PRIVATE void vAppHandleZdoEvents( BDB_tsZpsAfEvent *psZpsAfEvent);

PRIVATE bool bAppCancelRejoin(void);
#ifdef DR1199
PRIVATE void vDeletePDMOnButtonPress(uint8 u8ButtonDIO);
#endif

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
PUBLIC tsZllRemoteState sZllState = {FACTORY_NEW_REMOTE, E_REMOTE_STARTUP, 11, TL_MIN_ADDR, TL_MIN_ADDR, TL_MAX_ADDR, TL_MIN_GROUP, TL_MAX_GROUP};
PUBLIC tsZllEndpointInfoTable sEndpointTable;
PUBLIC tsZllGroupInfoTable sGroupTable;
PUBLIC uint8 u8KeepAliveTime = KEEP_ALIVETIME;

extern bool_t bDeepSleep;
extern bool_t bSendFactoryResetOverAir;

bool_t bFailedToJoin = FALSE;
bool_t bBDBJoinFailed = FALSE;

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/




PRIVATE uint16 u16FastPoll;

PRIVATE uint8 u8DeepSleepTime = DEEP_SLEEPTIME;
PRIVATE    pwrm_tsWakeTimerEvent    sWake;
PRIVATE uint8 u8AddGroupToIndex;
PRIVATE bool_t bAddGroupToAll;
PRIVATE uint16 u16IdTime = 0;



PUBLIC bool_t bAddrMode = TRUE;


/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/





/****************************************************************************
 *
 * NAME: APP_vInitialiseNode
 *
 * DESCRIPTION:
 * Initialises the application related functions
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC tsZllEndpointInfoTable * psGetEndpointRecordTable(void)
{
    return &sEndpointTable;
}

/****************************************************************************
 *
 * NAME: psGetGroupRecordTable
 *
 * DESCRIPTION:
 * return the address of the group record table
 *
 * RETURNS:
 * pointer to the group record table
 *
 ****************************************************************************/
PUBLIC tsZllGroupInfoTable * psGetGroupRecordTable(void)
{
    return &sGroupTable;
}

/****************************************************************************
 *
 * NAME: APP_vInitialiseNode
 *
 * DESCRIPTION:
 * Initials the node before launching the application
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_vInitialiseNode(void)
{
    DBG_vPrintf(TRACE_APP, "\nAPP_vInitialiseNode*\n");

    APP_vInitLeds();
    sZllState.eNodeState = E_REMOTE_STARTUP;

    uint16 u16BytesRead;


    /* Initialise buttons;
     */
    APP_bButtonInitialise();

    PDM_eReadDataFromRecord(PDM_ID_APP_ZLO_CONTROLLER, &sZllState,sizeof(tsZllRemoteState), &u16BytesRead);
    PDM_eReadDataFromRecord(PDM_ID_APP_END_P_TABLE, &sEndpointTable, sizeof(tsZllEndpointInfoTable), &u16BytesRead);
    PDM_eReadDataFromRecord(PDM_ID_APP_GROUP_TABLE, &sGroupTable, sizeof(tsZllGroupInfoTable), &u16BytesRead);

#ifdef JN517x
    /* Default module configuration: change E_MODULE_DEFAULT as appropriate */
      vAHI_ModuleConfigure(E_MODULE_DEFAULT);
#endif

    /* Initialise ZBPro stack */
    ZPS_eAplAfInit();

    APP_ZCL_vInitialise();

    /* Remote control will spend low periods in deep sleep
     * so set a long time out period for the parent
     */
    ZPS_bAplAfSetEndDeviceTimeout( ZED_TIMEOUT_16384_MIN);

    /* Set channel mask to primary channels */
    ZPS_eAplAibSetApsChannelMask( BDB_PRIMARY_CHANNEL_SET | BDB_SECONDARY_CHANNEL_SET );
    DBG_vPrintf(TRACE_REMOTE_NODE, "\nSet channel mask %08x\n", (BDB_PRIMARY_CHANNEL_SET | BDB_SECONDARY_CHANNEL_SET) );

    /* If the device state has been restored from flash, re-start the stack
     * and set the application running again.
     */
    if ((sZllState.eNodeState == E_REMOTE_RUNNING) || (ZPS_psAplAibGetAib()->u64ApsUseExtendedPanid != 0))
    {
        DBG_vPrintf(TRACE_APP, "\nNon Factory New Start\n");
        sZllState.eNodeState = E_REMOTE_RUNNING; // E_REMOTE_NFN_START;
        sBDB.sAttrib.bbdbNodeIsOnANetwork = TRUE;
    }
    else
    {
        sZllState.u8MyChannel = u8GetFirstPrimaryChannel();

        ZPS_vNwkNibSetChannel( ZPS_pvAplZdoGetNwkHandle(), sZllState.u8MyChannel);
        DBG_vPrintf(TRACE_REMOTE_NODE, "\nStart out on ch %d\n", sZllState.u8MyChannel);
        /* Stay awake for joining */
        DBG_vPrintf(TRACE_APP, "\nFactory New Start\n");
        sBDB.sAttrib.bbdbNodeIsOnANetwork = FALSE;
        /* Setting random PANId for Factory New remote */

        uint16 u16PanId = (uint16) RND_u32GetRand(1, 0xfff0);
        ZPS_vNwkNibSetPanId(ZPS_pvAplZdoGetNwkHandle(), u16PanId);
    }

#ifdef DR1199
    vDeletePDMOnButtonPress(APP_BUTTONS_BUTTON_1);
#endif

    BDB_vRegisterRejoinControl( bAppCancelRejoin);

    sBDB.sAttrib.u32bdbPrimaryChannelSet = BDB_PRIMARY_CHANNEL_SET;
    sBDB.sAttrib.u32bdbSecondaryChannelSet = BDB_SECONDARY_CHANNEL_SET;
    BDB_tsInitArgs sInitArgs;
    sInitArgs.hBdbEventsMsgQ = &APP_msgBdbEvents;

    BDB_vInit(&sInitArgs);
}



/****************************************************************************
 *
 * NAME: vStartPolling
 *
 * DESCRIPTION:
 * start te remote polling, initial at a fast rate
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vStartPolling(void)
{
    uint8 u8Start;
    u16FastPoll = (uint16)(5/0.25);
    ZTIMER_eStop(u8TimerPoll);
    u8Start = ZTIMER_eStart(u8TimerPoll, POLL_TIME_FAST);
    DBG_vPrintf(TRACE_REMOTE_NODE, "\nStart Fpoll start %d", u8Start);
}

/****************************************************************************
 *
 * NAME: APP_vBdbCallback
 *
 * DESCRIPTION:
 * Callbak from the BDB
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_vBdbCallback(BDB_tsBdbEvent *psBdbEvent)
{
    static uint8 u8NoQueryCount;

    switch(psBdbEvent->eEventType)
    {
        case BDB_EVENT_NONE:
            break;
        case BDB_EVENT_ZPSAF:                // Use with BDB_tsZpsAfEvent
            vAppHandleAfEvent(&psBdbEvent->uEventData.sZpsAfEvent);
            break;

        case BDB_EVENT_INIT_SUCCESS:
            DBG_vPrintf(TRACE_REMOTE_NODE,"APP: BdbInitSuccessful\n");
            break;
        case BDB_EVENT_REJOIN_FAILURE: // only for ZED
            DBG_vPrintf(TRACE_REMOTE_NODE|TRACE_REJOIN, "BDB EVT INIT failed to join\n");
            bBDBJoinFailed = TRUE;
            break;
        case BDB_EVENT_REJOIN_SUCCESS: // only for ZED
            DBG_vPrintf(TRACE_REMOTE_NODE|TRACE_REJOIN, "BDB EVT INIT Join success\n");
            vResetSleepAndJoinCounters();
            sZllState.eNodeState = E_REMOTE_RUNNING;
            PDM_eSaveRecordData(PDM_ID_APP_ZLO_CONTROLLER, &sZllState,sizeof(tsZllRemoteState));

            vHandleIdentifyRequest(5);
            vStartPolling();
            break;


        case BDB_EVENT_NWK_STEERING_SUCCESS:
            // go to running state
            DBG_vPrintf(TRACE_REMOTE_NODE,"GoRunningState!");
            sZllState.eState = NOT_FACTORY_NEW_REMOTE;
            sZllState.eNodeState = E_REMOTE_RUNNING;
            PDM_eSaveRecordData(PDM_ID_APP_ZLO_CONTROLLER,&sZllState,sizeof(tsZllRemoteState));
            break;

        case BDB_EVENT_NO_NETWORK:
            DBG_vPrintf(TRACE_REMOTE_NODE, "STEER -> No Network\n");
            bBDBJoinFailed = TRUE;
            break;

        case BDB_EVENT_FB_CHECK_BEFORE_BINDING_CLUSTER_FOR_TARGET:
            DBG_vPrintf(TRACE_REMOTE_NODE,"Check For Binding Cluster %d \n",psBdbEvent->uEventData.psFindAndBindEvent->uEvent.u16ClusterId);
            break;

        case BDB_EVENT_FB_CLUSTER_BIND_CREATED_FOR_TARGET:
            DBG_vPrintf(TRACE_REMOTE_NODE,"Bind Created for cluster %d \n",psBdbEvent->uEventData.psFindAndBindEvent->uEvent.u16ClusterId);
            break;

        case BDB_EVENT_FB_BIND_CREATED_FOR_TARGET:
        {
            DBG_vPrintf(TRACE_REMOTE_NODE,"Bind Created for target EndPt %d \n",psBdbEvent->uEventData.psFindAndBindEvent->u8TargetEp);

                break;
        }

        case BDB_EVENT_FB_GROUP_ADDED_TO_TARGET:
        {
            DBG_vPrintf(TRACE_REMOTE_NODE,"Group Added with ID %d \n",psBdbEvent->uEventData.psFindAndBindEvent->uEvent.u16GroupId);
            u8NoQueryCount = 0;
            //Example to ask to Stop identification to that group
            uint8 u8Seq;
            tsZCL_Address sAddress;
            tsCLD_Identify_IdentifyRequestPayload sPayload;

            sPayload.u16IdentifyTime = 0;
            sAddress.eAddressMode = E_ZCL_AM_SHORT;
            sAddress.uAddress.u16GroupAddress = psBdbEvent->uEventData.psFindAndBindEvent->u16TargetAddress;
                  /*  psBdbEvent->uEventData.psFindAndBindEvent->uEvent.u16GroupId;*/

            eCLD_IdentifyCommandIdentifyRequestSend(
                                    psBdbEvent->uEventData.psFindAndBindEvent->u8InitiatorEp,
                                    psBdbEvent->uEventData.psFindAndBindEvent->u8TargetEp,
                                    &sAddress,
                                    &u8Seq,
                                    &sPayload);
            break;
        }

        case BDB_EVENT_FB_ERR_BINDING_TABLE_FULL:
            DBG_vPrintf(TRACE_REMOTE_NODE,"ERR: Bind Table Full\n");
            break;

        case BDB_EVENT_FB_ERR_BINDING_FAILED:
            DBG_vPrintf(TRACE_REMOTE_NODE,"ERR: Bind\n");
            break;

        case BDB_EVENT_FB_ERR_GROUPING_FAILED:
            DBG_vPrintf(TRACE_REMOTE_NODE,"ERR: Group\n");
            break;

        case BDB_EVENT_FB_NO_QUERY_RESPONSE:
            DBG_vPrintf(TRACE_REMOTE_NODE,"ERR: No Query response\n");
            //Example to stop further query repeating
            if(u8NoQueryCount >= 2)
            {
                u8NoQueryCount = 0;
                BDB_vFbExitAsInitiator();
                u8KeepAliveTime = KEEP_ALIVETIME;
            }
            else
            {
                u8NoQueryCount++;
            }
            break;

        case BDB_EVENT_FB_TIMEOUT:
            DBG_vPrintf(TRACE_REMOTE_NODE,"ERR: TimeOut\n");
            u8KeepAliveTime = KEEP_ALIVETIME;
            break;

        case BDB_EVENT_FB_HANDLE_SIMPLE_DESC_RESP_OF_TARGET:
            DBG_vPrintf(TRACE_REMOTE_NODE, "FB Addr %04x Profle %04x Device %04x Ep %d Version %d\n",
                    psBdbEvent->uEventData.psFindAndBindEvent->u16TargetAddress,
                    psBdbEvent->uEventData.psFindAndBindEvent->u16ProfileId,
                    psBdbEvent->uEventData.psFindAndBindEvent->u16DeviceId,
                    psBdbEvent->uEventData.psFindAndBindEvent->u8TargetEp,
                    psBdbEvent->uEventData.psFindAndBindEvent->u8DeviceVersion
            );
            if ( bIsDeviceLight(psBdbEvent->uEventData.psFindAndBindEvent->u16DeviceId  ) )
            {
                /*
                 * Controlled device attempt to add to device endpoint table
                 */
                APP_tsEventTouchLink sTarget;
                sTarget.u16NwkAddr = psBdbEvent->uEventData.psFindAndBindEvent->u16TargetAddress;
                sTarget.u16ProfileID = psBdbEvent->uEventData.psFindAndBindEvent->u16ProfileId;
                sTarget.u16DeviceID = psBdbEvent->uEventData.psFindAndBindEvent->u16DeviceId;
                sTarget.u8Endpoint = psBdbEvent->uEventData.psFindAndBindEvent->u8TargetEp;
                sTarget.u8Version = psBdbEvent->uEventData.psFindAndBindEvent->u8DeviceVersion;


                /* add target to light data base
                 * no need to add group as F%B will of done that */
                if (bAddToEndpointTable( &sTarget))
                {
                    DBG_vPrintf(TRACE_REMOTE_NODE, "Added to table\n");
                    PDM_eSaveRecordData(PDM_ID_APP_END_P_TABLE, &sEndpointTable,
                                            sizeof(tsZllEndpointInfoTable));
                }
            }
            break;

            default:
                DBG_vPrintf(TRACE_REMOTE_NODE, "BDB EVT default evt %d\n", psBdbEvent->eEventType);
            break;
    }
}

/****************************************************************************
 *
 * NAME: vAppHandleAfEvent
 *
 * DESCRIPTION:
 * Application handler for stack events
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vAppHandleAfEvent( BDB_tsZpsAfEvent *psZpsAfEvent)
{
    if (psZpsAfEvent->u8EndPoint == app_u8GetDeviceEndpoint() )
    {
        if ((psZpsAfEvent->sStackEvent.eType == ZPS_EVENT_APS_DATA_INDICATION) ||
            (psZpsAfEvent->sStackEvent.eType == ZPS_EVENT_APS_INTERPAN_DATA_INDICATION))
        {
            APP_ZCL_vEventHandler( &psZpsAfEvent->sStackEvent);
         }
    } else if (psZpsAfEvent->u8EndPoint == CONTROLLER_ZDO_ENDPOINT)
    {
        // events for ep 0
        vAppHandleZdoEvents( psZpsAfEvent);
    }

    /* Ensure Freeing of Apdus */
    if (psZpsAfEvent->sStackEvent.eType == ZPS_EVENT_APS_DATA_INDICATION)
    {
        PDUM_eAPduFreeAPduInstance(psZpsAfEvent->sStackEvent.uEvent.sApsDataIndEvent.hAPduInst);
    }
    else if ( psZpsAfEvent->sStackEvent.eType == ZPS_EVENT_APS_INTERPAN_DATA_INDICATION )
    {
        PDUM_eAPduFreeAPduInstance(psZpsAfEvent->sStackEvent.uEvent.sApsInterPanDataIndEvent.hAPduInst);
    }
}


/****************************************************************************
 *
 * NAME: APP_taskController
 *
 * DESCRIPTION:
 * Task that handles the application related functionality
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_taskController(void)
{

    APP_tsEvent sAppEvent;

    if (ZQ_bQueueReceive(&APP_msgAppEvents, &sAppEvent) == FALSE)
    {
        // no event go away
        return;
    }

    switch(sZllState.eNodeState)
    {
        case E_REMOTE_STARTUP:
            /* Wait for touchlink to form network
             * or classical join
             * if nothing happens Sleep and Join task will force deep sleep
             */

            if (sAppEvent.eType == APP_E_EVENT_BUTTON_DOWN)
            {
                vHandleWaitStartAppEvent(&sAppEvent);
            }
            break;
    case E_REMOTE_NFN_START:

        break;
    case E_REMOTE_RUNNING:
        if (sAppEvent.eType == APP_E_EVENT_TOUCH_LINK)
        {
            vAppHandleTouchLink( &sAppEvent);
        }
        else if (sAppEvent.eType == APP_E_EVENT_EP_INFO_MSG)
        {
            vAppHandleEndpointInfo( &sAppEvent);
        }
        else if (sAppEvent.eType == APP_E_EVENT_EP_LIST_MSG)
        {
            vAppHandleEndpointList( &sAppEvent);
        }
        else if (sAppEvent.eType == APP_E_EVENT_GROUP_LIST_MSG)
        {
            vAppHandleGroupList( &sAppEvent);
        }
        else if (sAppEvent.eType != APP_E_EVENT_NONE)
        {
            vHandleRunningAppEvent( &sAppEvent);
        }
        break;
    }
}


/****************************************************************************
 *
 * NAME: vAppHandleZdoEvents
 *
 * DESCRIPTION:
 * Application handler for stack events for end point 0 (ZDO)
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vAppHandleZdoEvents( BDB_tsZpsAfEvent *psZpsAfEvent)
{
    switch(sZllState.eNodeState)
    {
    case E_REMOTE_STARTUP:
        vHandleWaitStartStackEvent(&psZpsAfEvent->sStackEvent);
        break;
    case E_REMOTE_NFN_START:
        DBG_vPrintf(TRACE_REMOTE_NODE, "Stack Event in NFN Start up\n");
   // Delibrate fall through
    case E_REMOTE_RUNNING:
        vHandleRunningStackEvent(&psZpsAfEvent->sStackEvent);

    break;
    }
}

/****************************************************************************
 *
 * NAME: vHandleWaitStartAppEvent
 *
 * DESCRIPTION:
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vHandleWaitStartAppEvent(APP_tsEvent* psAppEvent)
{


    // wait button to start touch link
    DBG_vPrintf(TRACE_APP, "Handle wait start Event [%d %d]\n", sZllState.eNodeState, psAppEvent->eType);
    APP_vHandleFactoryNewKeyPress(psAppEvent->uEvent.sButton.u8Button);

}

/****************************************************************************
 *
 * NAME: vHandleRunningAppEvent
 *
 * DESCRIPTION: handle events in the application running state,
 * stack events and button presses
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vHandleRunningAppEvent(APP_tsEvent* psAppEvent)
{

    switch(psAppEvent->eType)
    {

    case APP_E_EVENT_NONE:
        break;

    case APP_E_EVENT_BUTTON_DOWN:
        {
            teUserKeyCodes eKeyCode = psAppEvent->uEvent.sButton.u8Button;

            // Hook to rejoin the network if the Light was unavailable
            if(bBDBJoinFailed  && (KEY_16 != eKeyCode)  &&
               ( !BDB_bTlTouchLinkInProgress() ))
            {
                // TODO kick BDB for rejoin
                DBG_vPrintf(TRACE_APP, "Call BDB vStart\n");
                sBDB.sAttrib.bbdbNodeIsOnANetwork = TRUE;
                BDB_vStart();
            }
            APP_vHandleKeyPress(eKeyCode);


            u8KeepAliveTime = KEEP_ALIVETIME;
            u8DeepSleepTime = DEEP_SLEEPTIME;
        }
        break;

    case APP_E_EVENT_BUTTON_UP:
        APP_vHandleKeyRelease(psAppEvent->uEvent.sButton.u8Button);
        break;

    case APP_E_EVENT_LEAVE_AND_RESET:
        DBG_vPrintf(TRACE_APP, "We are asked to leave\n");
        ZPS_eAplZdoLeaveNetwork( 0UL, FALSE, FALSE);
        break;

    default:
        break;
    }
}

/****************************************************************************
 *
 * NAME: vHandleWaitStartStackEvent
 *
 * DESCRIPTION: handle events in the wait start state - stack join related events
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vHandleWaitStartStackEvent(ZPS_tsAfEvent* psStackEvent)
{

    void * pvNwk = ZPS_pvAplZdoGetNwkHandle();
    switch (psStackEvent->eType)
    {
        case ZPS_EVENT_NWK_JOINED_AS_ENDDEVICE:
            DBG_vPrintf(TRACE_REMOTE_NODE|TRACE_REJOIN, "\nWAIT START Joined as Ed");
            if (psStackEvent->uEvent.sNwkJoinedEvent.bRejoin == FALSE)
            {
                DBG_vPrintf(TRACE_APP, "Only for Classic Association\n");
                /* generate a unique to the device, but fixed group address
                 *
                 */
                uint64 u64MacAddr = ZPS_u64NwkNibGetExtAddr(ZPS_pvAplZdoGetNwkHandle() );
                uint16 u16Group = ((uint16)u64MacAddr) ^ ((uint16)(u64MacAddr>>16));
                vSetGroupAddress(u16Group, GROUPS_REQUIRED);
                sZllState.u16FreeAddrLow = 0;
                sZllState.u16FreeAddrHigh = 0;
                sZllState.u16FreeGroupLow = 0;
                sZllState.u16FreeGroupHigh = 0;
            }
            vResetSleepAndJoinCounters();
            sZllState.eNodeState = E_REMOTE_RUNNING;
            sZllState.eState = NOT_FACTORY_NEW_REMOTE;
            sZllState.u16MyAddr = psStackEvent->uEvent.sNwkJoinedEvent.u16Addr;
            sZllState.u8MyChannel = ZPS_psNwkNibGetHandle( pvNwk)->sPersist.u8VsChannel;
            PDM_eSaveRecordData(PDM_ID_APP_ZLO_CONTROLLER, &sZllState,sizeof(tsZllRemoteState));
            DBG_vPrintf(TRACE_APP, "Joined on Ch %d\n", sZllState.u8MyChannel );

            if (sEndpointTable.asEndpointRecords[0].u16NwkAddr)
            {
                bAddrMode = FALSE;           // ensure not in group mode
                DBG_vPrintf(TRACE_REMOTE_NODE, "\nNEW3 Send group add %d to %04x\n", sGroupTable.asGroupRecords[0].u16GroupId,
                sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u16NwkAddr);
                u8AddGroupToIndex = sEndpointTable.u8CurrentLight;
                bAddGroupToAll = FALSE;
                ZTIMER_eStart(u8TimerAddGroup, ZTIMER_TIME_MSEC(500));
            }
            /* set the aps use pan id */
            ZPS_eAplAibSetApsUseExtendedPanId( ZPS_u64NwkNibGetEpid(ZPS_pvAplZdoGetNwkHandle()) );
            vHandleIdentifyRequest(5);
            vStartPolling();

            break;

        case ZPS_EVENT_NWK_FAILED_TO_JOIN:
            DBG_vPrintf(TRACE_REMOTE_NODE|TRACE_REJOIN, "Wait Start: Failed to join \n");
            bFailedToJoin = TRUE;
            if (ZPS_psAplAibGetAib()->u64ApsUseExtendedPanid != 0)
            {
                DBG_vPrintf(TRACE_REMOTE_NODE, "Restore epid %016llx\n", ZPS_psAplAibGetAib()->u64ApsUseExtendedPanid);
                ZPS_vNwkNibSetExtPanId(ZPS_pvAplZdoGetNwkHandle(), ZPS_psAplAibGetAib()->u64ApsUseExtendedPanid);
            }
            break;
        default:
            break;
    }
}

/****************************************************************************
 *
 * NAME: vHandleRunningStackEvent
 *
 * DESCRIPTION:
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vHandleRunningStackEvent(ZPS_tsAfEvent* psStackEvent)
{
   void * pvNwk = ZPS_pvAplZdoGetNwkHandle();

    switch (psStackEvent->eType)
    {
    case ZPS_EVENT_NWK_JOINED_AS_ENDDEVICE:
        vResetSleepAndJoinCounters();
        DBG_vPrintf(TRACE_REMOTE_NODE|TRACE_REJOIN, "Joined as Ed while running\n");
        vStartPolling();
        sZllState.u16MyAddr = psStackEvent->uEvent.sNwkJoinedEvent.u16Addr;
        sZllState.u8MyChannel = ZPS_psNwkNibGetHandle( pvNwk)->sPersist.u8VsChannel;
        PDM_eSaveRecordData(PDM_ID_APP_ZLO_CONTROLLER, &sZllState,sizeof(tsZllRemoteState));
        vHandleIdentifyRequest(5);
        break;

    case ZPS_EVENT_NWK_FAILED_TO_JOIN:
        DBG_vPrintf(TRACE_REMOTE_NODE|TRACE_REJOIN, "Running Failed to join\n");
        bFailedToJoin = TRUE;
        if (ZPS_psAplAibGetAib()->u64ApsUseExtendedPanid != 0)
        {
            DBG_vPrintf(TRACE_REMOTE_NODE|TRACE_REJOIN, "Restore epid %016llx\n", ZPS_psAplAibGetAib()->u64ApsUseExtendedPanid);
            ZPS_vNwkNibSetExtPanId(ZPS_pvAplZdoGetNwkHandle(), ZPS_psAplAibGetAib()->u64ApsUseExtendedPanid);
        }
        break;
    case ZPS_EVENT_NWK_LEAVE_INDICATION:
        DBG_vPrintf(TRACE_APP, "LEAVE IND Addr %016llx Rejoin %02x\n",
                psStackEvent->uEvent.sNwkLeaveIndicationEvent.u64ExtAddr,
                psStackEvent->uEvent.sNwkLeaveIndicationEvent.u8Rejoin);
        if ( (psStackEvent->uEvent.sNwkLeaveIndicationEvent.u64ExtAddr == 0UL) &&
             (psStackEvent->uEvent.sNwkLeaveIndicationEvent.u8Rejoin == 0) )
        {
            /* We sare asked to Leave without rejoin */
            DBG_vPrintf(TRACE_APP, "LEAVE IND -> For Us No Rejoin\n");
            DBG_vPrintf(TRACE_APP, "Leave -> Reset Data Structures\n");
            APP_vFactoryResetRecords();
            DBG_vPrintf(TRACE_APP, "Leave -> Soft Reset\n");
            vAHI_SwReset();
        }

        break;
    case ZPS_EVENT_NWK_LEAVE_CONFIRM:
        if (( psStackEvent->uEvent.sNwkLeaveConfirmEvent.eStatus == ZPS_E_SUCCESS) &&
            ( psStackEvent->uEvent.sNwkLeaveConfirmEvent.u64ExtAddr == 0UL))
        {
            /* It was a self leave success */
            if (sBDB.sAttrib.bLeaveRequested)
            {
                /* originated in touch link, pass it over */
                tsBDB_ZCLEvent sBdbEvent;
                tsZCL_CallBackEvent sCallBackEvent;
                sBdbEvent.psCallBackEvent = &sCallBackEvent;

                sBDB.sAttrib.bLeaveRequested = FALSE;
                sBdbEvent.eType = BDB_E_ZCL_EVENT_LEAVE_CFM;
                DBG_vPrintf(TRACE_REMOTE_NODE, "Send Leave cfm\n");
                sBdbEvent.psCallBackEvent->pZPSevent = psStackEvent;
                BDB_vZclEventHandler(&sBdbEvent);
            }
            else
            {
                DBG_vPrintf(TRACE_APP, "Leave -> Reset Data Structures\n");
                APP_vFactoryResetRecords();
                DBG_vPrintf(TRACE_APP, "Leave -> Soft Reset\n");
                vAHI_SwReset();
            }
        }
        break;
    default:
        break;
    }
}

/****************************************************************************
 *
 * NAME: vAppHandleTouchLink
 *
 * DESCRIPTION: handles touck link events, ie new lights pr remotes
 * completed a touch link process. add to light data pbase or query
 *  their data base as required.
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vAppHandleTouchLink(APP_tsEvent* psAppEvent)
{
    tsCLD_ZllUtility_EndpointInformationCommandPayload sPayload;
    tsZCL_Address               sDestinationAddress;
    tsCLD_ZllDeviceTable * psDevTab = (tsCLD_ZllDeviceTable*)psGetDeviceTable();
    uint8 u8SeqNo;

    DBG_vPrintf(TRACE_REMOTE_NODE, "\nTLink %04x Ep %d Dev %04x", psAppEvent->uEvent.sTouchLink.u16NwkAddr,
            psAppEvent->uEvent.sTouchLink.u8Endpoint,
            psAppEvent->uEvent.sTouchLink.u16DeviceID);

    if ( bIsDeviceController(psAppEvent->uEvent.sTouchLink.u16DeviceID))
    {
        /*
         * Just added a controller device, send endpoint info
         */

        sPayload.u64IEEEAddr = psDevTab->asDeviceRecords[0].u64IEEEAddr;
        sPayload.u16NwkAddr = ZPS_u16AplZdoGetNwkAddr();
        sPayload.u16DeviceID = psDevTab->asDeviceRecords[0].u16DeviceId;
        sPayload.u16ProfileID = psDevTab->asDeviceRecords[0].u16ProfileId;
        sPayload.u8Endpoint = psDevTab->asDeviceRecords[0].u8Endpoint;
        sPayload.u8Version = psDevTab->asDeviceRecords[0].u8Version;

        DBG_vPrintf(TRACE_REMOTE_NODE, "\nTell new controller about us %04x", psAppEvent->uEvent.sTouchLink.u16NwkAddr);

        sDestinationAddress.eAddressMode = E_ZCL_AM_SHORT_NO_ACK;
        sDestinationAddress.uAddress.u16DestinationAddress = psAppEvent->uEvent.sTouchLink.u16NwkAddr;
        eCLD_ZllUtilityCommandEndpointInformationCommandSend(
                            sDeviceTable.asDeviceRecords[0].u8Endpoint,                        // src ep
                            psAppEvent->uEvent.sTouchLink.u8Endpoint,            // dst ep
                            &sDestinationAddress,
                            &u8SeqNo,
                            &sPayload);
    }
    else
    {
        if ( bIsDeviceLight(psAppEvent->uEvent.sTouchLink.u16DeviceID) )
        {
            /*
             * Controlled device attempt to add to device endpoint table
             */
            if (bAddToEndpointTable( &psAppEvent->uEvent.sTouchLink))
            {
                /* Added new or updated old
                 * ensure that it has our group address
                 */
                PDM_eSaveRecordData(PDM_ID_APP_END_P_TABLE, &sEndpointTable,
                        sizeof(tsZllEndpointInfoTable));
                bAddrMode = FALSE;           // ensure not in group mode
                DBG_vPrintf(TRACE_REMOTE_NODE, "\nNEW Send group add %d to %04x\n", sGroupTable.asGroupRecords[0].u16GroupId,
                    sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u16NwkAddr);

                /* next 3 bindings are pointless, but the
                 * test spec requires it
                 */
                ZPS_eAplZdoBindGroup(GENERAL_CLUSTER_ID_ONOFF, app_u8GetDeviceEndpoint(), sGroupTable.asGroupRecords[0].u16GroupId);
                ZPS_eAplZdoBindGroup(GENERAL_CLUSTER_ID_LEVEL_CONTROL, app_u8GetDeviceEndpoint(), sGroupTable.asGroupRecords[0].u16GroupId);
                ZPS_eAplZdoBindGroup(LIGHTING_CLUSTER_ID_COLOUR_CONTROL, app_u8GetDeviceEndpoint(), sGroupTable.asGroupRecords[0].u16GroupId);


                vAppIdentifyEffect(E_CLD_IDENTIFY_EFFECT_OKAY);
                u8AddGroupToIndex = sEndpointTable.u8CurrentLight;
                bAddGroupToAll = FALSE;
                ZTIMER_eStart(u8TimerAddGroup, ZTIMER_TIME_MSEC(500));

            }
        }
    }
}


/****************************************************************************
 *
 * NAME: bIsDeviceController
 *
 * DESCRIPTION: tests if the given device id is a controller type device
 *
 * RETURNS: True if a controler type
 *
 *
 ****************************************************************************/
PRIVATE bool bIsDeviceController(uint16 u16DeviceId)
{
    switch (u16DeviceId)
    {
        case ZLO_ON_OFF_LIGHT_SWITCH_DEVICE_ID:
        case ZLO_DIMMER_SWITCH_DEVICE_ID:
        case ZLO_COLOUR_DIMMER_SWITCH_DEVICE_ID:
        case ZLO_LIGHT_SENSOR_DEVICE_ID:
        case ZLO_OCCUPANCY_SENSOR_DEVICE_ID:
        case ZLO_LIGHT_LEVEL_SENSOR_DEVICE_ID:
        case ZLO_COLOUR_CONTROLLER_DEVICE_ID:
        case ZLO_COLOUR_SCENE_CONTROLLER_DEVICE_ID:
        case ZLO_NON_COLOUR_CONTROLLER_DEVICE_ID:
        case ZLO_NON_COLOUR_SCENE_CONTROLLER_DEVICE_ID:
        case ZLO_CONTROL_BRIDGE_DEVICE_ID:
        case ZLO_ON_OFF_SENSOR_DEVICE_ID:
            return TRUE;
            break;
    }
    return FALSE;
}

/****************************************************************************
 *
 * NAME: bIsDeviceLight
 *
 * DESCRIPTION: tests if the given device id is a light bulb type device
 *
 * RETURNS: True if a bulb type
 *
 *
 ****************************************************************************/
PRIVATE bool bIsDeviceLight(uint16 u16DeviceId)
{

    switch (u16DeviceId)
    {
        case ZLO_ON_OFF_LIGHT_DEVICE_ID:
        case ZLO_DIMMABLE_LIGHT_DEVICE_ID:
        case ZLO_COLOUR_DIMMABLE_LIGHT_DEVICE_ID:
        case ZLO_ON_OFF_BALLAST_DEVICE_ID:
        case ZLO_DIMMABLE_BALLAST_DEVICE_ID:
        case ZLO_ON_OFF_PLUG_DEVICE_ID:
        case ZLO_DIMMABLE_PLUG_DEVICE_ID:
        case ZLO_COLOUR_TEMPERATURE_LIGHT_DEVICE_ID:
        case ZLO_EXTENDED_COLOUR_LIGHT_DEVICE_ID:

        /* Legacy ZLL Device IDs */
        case ON_OFF_LIGHT_DEVICE_ID:
        case ON_OFF_PLUG_DEVICE_ID:
        case DIMMABLE_PLUG_DEVICE_ID:
        case COLOUR_LIGHT_DEVICE_ID:
        case EXTENDED_COLOUR_LIGHT_DEVICE_ID:
        case COLOUR_TEMPERATURE_LIGHT_DEVICE_ID:
            return TRUE;
    }
    return FALSE;
}

/****************************************************************************
 *
 * NAME: vAppHandleEndpointInfo
 *
 * DESCRIPTION: handle end point info requests from the zll utility cluster
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vAppHandleEndpointInfo(APP_tsEvent* psAppEvent)
{
    tsZCL_Address sAddress;
    uint8 u8SeqNo = 0xaf;

    // we are end device so no point looking in NT
    ZPS_eAplZdoAddAddrMapEntry(psAppEvent->uEvent.sEpInfoMsg.sPayload.u16NwkAddr,
                               psAppEvent->uEvent.sEpInfoMsg.sPayload.u64IEEEAddr, FALSE);

    /* Respond with a request for the endpoint information
     *
     */

    sAddress.eAddressMode = E_ZCL_AM_SHORT_NO_ACK;
    sAddress.uAddress.u16DestinationAddress = psAppEvent->uEvent.sEpInfoMsg.sPayload.u16NwkAddr;

    DBG_vPrintf(TRACE_REMOTE_NODE, "Reply to %04x\n", sAddress.uAddress.u16DestinationAddress);

    eCLD_ZllUtilityCommandGetEndpointListReqCommandSend(
            sDeviceTable.asDeviceRecords[0].u8Endpoint,         // src ep
            psAppEvent->uEvent.sEpInfoMsg.sPayload.u8Endpoint,                 // dst ep
            &sAddress,
            &u8SeqNo,
            0);
}

/****************************************************************************
 *
 * NAME: vAppHandleEndpointList
 *
 * DESCRIPTION: handle the end point list response from the
 * zll utility cluster
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vAppHandleEndpointList(APP_tsEvent* psAppEvent)
{
    int i;
    tsZCL_Address sAddress;
    uint8 u8SeqNo = 0xad;

    for (i=0; i<psAppEvent->uEvent.sEpListMsg.sPayload.u8Count; i++)
    {
        /* For every endpoint in the list if it is controlled device (light etc)
         * add it to the end point table
         */

        if ( bIsDeviceLight( psAppEvent->uEvent.sEpListMsg.sPayload.asEndpointRecords[i].u16DeviceID) )
        {
            if ( !bAddToEndpointTable( &psAppEvent->uEvent.sEpListMsg.sPayload.asEndpointRecords[i]))
            {
                /* If added to table or table updated ensure the device has our group address
                 *
                 */
                DBG_vPrintf(TRACE_REMOTE_NODE, "\nFaile to add %04x to table\n",
                        sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u16NwkAddr);

            }
        }
    }
    /* Save the end point table */
    PDM_eSaveRecordData(PDM_ID_APP_END_P_TABLE, &sEndpointTable,
                                sizeof(tsZllEndpointInfoTable));
    u8AddGroupToIndex = 0;
    bAddGroupToAll = TRUE;
    ZTIMER_eStart(u8TimerAddGroup, ZTIMER_TIME_MSEC(1000));

    /* Ask for the list of group addresses
     *
     */

    sAddress.eAddressMode = E_ZCL_AM_SHORT_NO_ACK;
    sAddress.uAddress.u16DestinationAddress = psAppEvent->uEvent.sEpListMsg.u16SrcAddr;

    eCLD_ZllUtilityCommandGetGroupIdReqCommandSend( sDeviceTable.asDeviceRecords[0].u8Endpoint,                     // src ep
                                                    psAppEvent->uEvent.sEpListMsg.u8SrcEp,              // dst ep
                                                    &sAddress,
                                                    &u8SeqNo,
                                                    0);
}

/****************************************************************************
 *
 * NAME: vAppHandleGroupList
 *
 * DESCRIPTION: handle the group list response from the
 * zll utility cluster
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vAppHandleGroupList(APP_tsEvent* psAppEvent)
{
    DBG_vPrintf(TRACE_REMOTE_NODE, "\ngot gp list with %d", psAppEvent->uEvent.sGroupListMsg.sPayload.u8Count);
    int i;

    for (i=0; i<psAppEvent->uEvent.sGroupListMsg.sPayload.u8Count; i++)
    {
        DBG_vPrintf(TRACE_REMOTE_NODE, "\nGroup %04x %d",
                psAppEvent->uEvent.sGroupListMsg.sPayload.asGroupRecords[i].u16GroupID,
                psAppEvent->uEvent.sGroupListMsg.sPayload.asGroupRecords[i].u8GroupType);
    }
}

/****************************************************************************
 *
 * NAME: APP_AddGroupTask
 *
 * DESCRIPTION:
 * Task that sends a add group command to a light,
 * works through each light in the data base
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_cbTimerAddGroup(void *pvParam)
{

    DBG_vPrintf(TRACE_REMOTE_NODE, "AddGroupTimerExpired\n");

    vAppAddGroup(sGroupTable.asGroupRecords[u8GroupId].u16GroupId, u8AddGroupToIndex);
    DBG_vPrintf(TRACE_REMOTE_NODE, "Add G Task: to All %d  index %d\n", bAddGroupToAll, u8AddGroupToIndex);
    if (bAddGroupToAll)
    {
        /* adding group to all lights in the table */
        u8AddGroupToIndex++;
        if (u8AddGroupToIndex < sEndpointTable.u8NumRecords)
        {
            /* more to send, set the timer to come back */
            ZTIMER_eStart(u8TimerAddGroup, ZTIMER_TIME_MSEC(500));
            return;
        }
    }
    /* all done, stop the timer to keep sleep happy */
    ZTIMER_eStop(u8TimerAddGroup);
}

/****************************************************************************
 *
 * NAME: vStopAllTimers
 *
 * DESCRIPTION:
 * Stops all the timers
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vStopAllTimers(void)
{
    ZTIMER_eStop(u8TimerLedBlink);
    ZTIMER_eStop(u8TimerPoll);
    ZTIMER_eStop(u8TimerAddGroup);
    ZTIMER_eStop(u8TimerId);
    ZTIMER_eStop(u8TimerZCL);
}
/****************************************************************************
 *
 * NAME: APP_vStartUpHW
 *
 * DESCRIPTION:
 * Os Task activated by the wake up event to manage sleep
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_vStartUpHW(void)
{

    uint8 u8Status;


    /* Restart the keyboard scanning timer as we've come up through */
    /* warm start via the Power Manager if we get here              */

#ifdef DR1199

#elif (defined DR1159)
    vConfigureScanTimer();
#endif

    DBG_vPrintf(TRACE_SLEEP, "\nWoken: start poll timer,");
    u8Status = ZPS_eAplZdoPoll();
    DBG_vPrintf(TRACE_SLEEP, " Wake poll %02x\n", u8Status);
    ZTIMER_eStart(u8TimerPoll, ZTIMER_TIME_MSEC(200));
    ZTIMER_eStart(u8TimerZCL, ZCL_TICK_TIME);

}



/****************************************************************************
 *
 * NAME: vWakeCallBack
 *
 * DESCRIPTION:
 * Wake up call back called upon wake up by the schedule activity event.
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vWakeCallBack(void)
{
    /*Decrement the deepsleep count so that if there is no activity for
     * DEEP_SLEEPTIME then the module is put to deep sleep.
     * */
    if (0 < u8DeepSleepTime)
{
#if NEVER_DEEP_SLEEP
        u8DeepSleepTime = DEEP_SLEEPTIME;
#else
        u8DeepSleepTime--;
#endif
    }

#ifdef DR1199

#elif (defined DR1159)
    vConfigureScanTimer();
#endif

    bAddrMode = TRUE;
}

/****************************************************************************
 *
 * NAME: u8SearchEndpointTable
 *
 * DESCRIPTION: searches the light data base to see if a light is already present,
 * or finds a free location if one exists, sets the point to the location as required
 *
 * RETURNS: 0, not present free slot found pointer valid
 *          1, already present, pointer valid
 *          3, table full, pointer not valid
 * uint8
 *
 ****************************************************************************/
PRIVATE uint8 u8SearchEndpointTable(APP_tsEventTouchLink *psEndpointData, uint8* pu8Index)
{
    int i;
    bool bGotFree = FALSE;
    *pu8Index = 0xff;

    for (i=0; i<NUM_ENDPOINT_RECORDS; i++)
    {
        if ((psEndpointData->u16NwkAddr == sEndpointTable.asEndpointRecords[i].u16NwkAddr) &&
                (psEndpointData->u8Endpoint == sEndpointTable.asEndpointRecords[i].u8Endpoint))
         {
            /* same ep on same device already known about */
            *pu8Index = i;
            DBG_vPrintf(TRACE_REMOTE_NODE, "\nPresent");
            return 1;
        }
        if ((sEndpointTable.asEndpointRecords[i].u16NwkAddr == 0) && !bGotFree)
        {
            *pu8Index = i;
            bGotFree = TRUE;
            DBG_vPrintf(TRACE_REMOTE_NODE, "\nFree slot %d", *pu8Index);
        }

    }

    DBG_vPrintf(TRACE_REMOTE_NODE, "\nNot found");
    return (bGotFree)? 0: 3  ;
}

/****************************************************************************
 *
 * NAME: vRemoveLight
 *
 * DESCRIPTION: remove the light with the specified address from the light data base
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vRemoveLight(uint16 u16Addr)
{
    uint32 i,j;

    for ( i=0; i<sEndpointTable.u8NumRecords; i++ )
    {
        if (sEndpointTable.asEndpointRecords[i].u16NwkAddr == u16Addr )
        {
            if ( i < NUM_ENDPOINT_RECORDS-1 )
            {
                /* not last record */
                for (j=i; j<NUM_ENDPOINT_RECORDS-1; j++ )
                {
                    sEndpointTable.asEndpointRecords[j] = sEndpointTable.asEndpointRecords[j+1];
                    sEndpointTable.au8PingCount[j] = sEndpointTable.au8PingCount[j+1];
                }
            }

            /* clear the last record */
            sEndpointTable.u8NumRecords--;
            memset( &sEndpointTable.asEndpointRecords[sEndpointTable.u8NumRecords], 0, sizeof( tsZllEndpointInfoRecord) );
            sEndpointTable.au8PingCount[sEndpointTable.u8NumRecords] = 0;
            sEndpointTable.u8CurrentLight = 0;    // reset
            PDM_eSaveRecordData(PDM_ID_APP_END_P_TABLE, &sEndpointTable,
                                sizeof(tsZllEndpointInfoTable));

            DBG_vPrintf(TRACE_LIGHT_AGE, "Num Records %d\n", sEndpointTable.u8NumRecords);
            break;
        }
    }
}
/****************************************************************************
 *
 * NAME: vSelectLight
 *
 * DESCRIPTION: selects the next light in the data base for unicast
 * a read attribute request will be sent to it,
 * it the light responds to that then the identify command will then be sent
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vSelectLight(void)
{
    uint32 i;

    if ( sEndpointTable.au8PingCount[sEndpointTable.u8CurrentLight] >= LIGHT_DEVICE_AGE_LIMIT )
{
        DBG_vPrintf(TRACE_LIGHT_AGE, "Remove %04x at idx %d\n",
                sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u16NwkAddr,
                sEndpointTable.u8CurrentLight);
        for ( i=sEndpointTable.u8CurrentLight; i<sEndpointTable.u8NumRecords; i++ )
        {
            if ( i < NUM_ENDPOINT_RECORDS-1 )
            {
                sEndpointTable.asEndpointRecords[i] = sEndpointTable.asEndpointRecords[i+1];
                sEndpointTable.au8PingCount[i] = sEndpointTable.au8PingCount[i+1];
            }
        }
        /* clear the last recod */
        sEndpointTable.u8NumRecords--;
        memset( &sEndpointTable.asEndpointRecords[sEndpointTable.u8NumRecords], 0, sizeof( tsZllEndpointInfoRecord) );
        sEndpointTable.au8PingCount[sEndpointTable.u8NumRecords] = 0;

        PDM_eSaveRecordData(PDM_ID_APP_END_P_TABLE, &sEndpointTable,
                                    sizeof(tsZllEndpointInfoTable));

        DBG_vPrintf(TRACE_LIGHT_AGE, "Num Records %d\n", sEndpointTable.u8NumRecords);

#if TRACE_LIGHT_AGE
        for (i=0; i<NUM_ENDPOINT_RECORDS; i++)
        {
            DBG_vPrintf(TRACE_LIGHT_AGE, "Idx %d, Addr %04x Profile %04x\n", i,
                    sEndpointTable.asEndpointRecords[i].u16NwkAddr,
                    sEndpointTable.asEndpointRecords[i].u16ProfileId);
        }
#endif
    }

    if (sEndpointTable.u8NumRecords == 0)
    {
        /* table is empty, nothing to identify */
        return;
    }


    i = sEndpointTable.u8CurrentLight;

    do {
        /*
         * loop through the table till new device found
         * or full table has been searched
         */
        sEndpointTable.u8CurrentLight++;
        if (sEndpointTable.u8CurrentLight >= sEndpointTable.u8NumRecords)
        {
            sEndpointTable.u8CurrentLight = 0;
        }
    } while( (sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u16NwkAddr == 0) &&
             ( i == sEndpointTable.u8CurrentLight ) );

    sEndpointTable.au8PingCount[sEndpointTable.u8CurrentLight]++;
    DBG_vPrintf(TRACE_LIGHT_AGE, "Ping Count for %04x is now %d\n", sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u16NwkAddr,
            sEndpointTable.au8PingCount[sEndpointTable.u8CurrentLight]);


    if (sEndpointTable.au8PingCount[sEndpointTable.u8CurrentLight] == LIGHT_DEVICE_NO_ROUTE)
    {
        /* send network status of no route
         * will trigger route disovery next time
         */

        ZPS_vNwkSendNwkStatusCommand( ZPS_pvAplZdoGetNwkHandle(),
                                      sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u16NwkAddr,
                                      ZPS_NWK_BCAST_ADDR_ZCZR,
                                      0,
                                      2);

#if LIGHT_DEVICE_AGING==FALSE
        sEndpointTable.au8PingCount[sEndpointTable.u8CurrentLight] = 0;
#endif

    } 
    else 
    {

        DBG_vPrintf(TRACE_REMOTE_NODE|TRACE_LIGHT_AGE, "\nId %04x", sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u16NwkAddr);

        uint8 u8Seq;
        tsZCL_Address sAddress;
        uint16 au16AttribList[] = {0x0000};             /* ZCL version attribute */


        /* ensure we are polling */
        vStartPolling();

        sAddress.eAddressMode = E_ZCL_AM_SHORT_NO_ACK;
        sAddress.uAddress.u16DestinationAddress = sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u16NwkAddr;

        eZCL_SendReadAttributesRequest(
                                sDeviceTable.asDeviceRecords[0].u8Endpoint,
                                sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint,
                                GENERAL_CLUSTER_ID_BASIC,                     // basic
                                FALSE,                     /* bDirectionIsServerToClient,*/
                                &sAddress,
                                &u8Seq,
                                1,                       /*u8NumberOfAttributesInRequest,*/
                                FALSE,                     /* bIsManufacturerSpecific,*/
                                0,                      /*u16ManufacturerCode,*/
                                au16AttribList);
    }


}


/****************************************************************************
 *
 * NAME: bAddToEndpointTable
 *
 * DESCRIPTION: following completion of touch link with a light
 * the lights details are added to the light data base
 *
 * RETURNS:
 * bool
 *
 ****************************************************************************/
PUBLIC bool bAddToEndpointTable(APP_tsEventTouchLink *psEndpointData)
{
    uint8 u8Index = 0xff;
    bool_t bPresent;

    bPresent = u8SearchEndpointTable(psEndpointData, &u8Index);
    if (u8Index < 0xff)
    {
        /* There is space for a new entry
         * or it is already there
         */
        if (!bPresent)
    {
            /* new entry, increment device count
             *
             */
            sEndpointTable.u8NumRecords++;
        }
        /* Add or update details at the slot indicated
         *
         */
        sEndpointTable.asEndpointRecords[u8Index].u16NwkAddr = psEndpointData->u16NwkAddr;
        sEndpointTable.asEndpointRecords[u8Index].u16ProfileId = psEndpointData->u16ProfileID;
        sEndpointTable.asEndpointRecords[u8Index].u16DeviceId = psEndpointData->u16DeviceID;
        sEndpointTable.asEndpointRecords[u8Index].u8Endpoint = psEndpointData->u8Endpoint;
        sEndpointTable.asEndpointRecords[u8Index].u8Version = psEndpointData->u8Version;
        sEndpointTable.au8PingCount[u8Index] = 0;
        DBG_vPrintf(TRACE_REMOTE_NODE, "\nAdd idx %d Addr %04x Ep %d Dev %04x", u8Index,
                sEndpointTable.asEndpointRecords[u8Index].u16NwkAddr,
                sEndpointTable.asEndpointRecords[u8Index].u8Endpoint,
                sEndpointTable.asEndpointRecords[u8Index].u16DeviceId);

        sEndpointTable.u8CurrentLight = u8Index;
#if TRACE_LIGHT_AGE
        DBG_vPrintf(TRACE_LIGHT_AGE, "Num Records %d\n", sEndpointTable.u8NumRecords);
        for (u8Index=0; u8Index<NUM_ENDPOINT_RECORDS; u8Index++)
        {
            DBG_vPrintf(TRACE_LIGHT_AGE, "Idx %d, Addr %04x Profile %04x\n", u8Index,
                    sEndpointTable.asEndpointRecords[u8Index].u16NwkAddr,
                    sEndpointTable.asEndpointRecords[u8Index].u16ProfileId);
        }
#endif
        return TRUE;
    }

    /* no room in the table */
    return FALSE;
}


/****************************************************************************
 *
 * NAME: vSetGroupAddress
 *
 * DESCRIPTION: set and save the group addresses for use by the remote control
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vSetGroupAddress(uint16 u16GroupStart, uint8 u8NumGroups)
{
    int i;

    /* This passes all the required group addresses for the device
     * if the are morethan one sub devices (endpoints) they need
     * sharing amoung the endpoints
     * In this case there is one the 1 Rc endpoint, so all group addresses
     * are for it
     */
    for (i=0; i<NUM_GROUP_RECORDS && i<u8NumGroups; i++)
    {
        sGroupTable.asGroupRecords[i].u16GroupId = u16GroupStart++;
        sGroupTable.asGroupRecords[i].u8GroupType = 0;
        DBG_vPrintf(TRACE_REMOTE_NODE, "Idx %d Grp %04x\n", i, sGroupTable.asGroupRecords[i].u16GroupId);
    }
    sGroupTable.u8NumRecords = u8NumGroups;

    PDM_eSaveRecordData(PDM_ID_APP_GROUP_TABLE, &sGroupTable, sizeof(tsZllGroupInfoTable));

}

/****************************************************************************
 *
 * NAME: APP_vFactoryResetRecords
 *
 * DESCRIPTION: reset application and stack to factory new state
 *              preserving the outgoing nwk frame counter
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_vFactoryResetRecords( void)
{

    /* clear out the stack */
    ZPS_vDefaultStack();
    ZPS_vSetKeys();
    ZPS_eAplAibSetApsUseExtendedPanId (0);

    /* clear out the application */
    sZllState.eNodeState = E_REMOTE_STARTUP;
    sZllState.eState = FACTORY_NEW_REMOTE;
    sZllState.u8MyChannel = u8GetFirstPrimaryChannel();
    sZllState.u16MyAddr= TL_MIN_ADDR;
    sZllState.u16FreeAddrLow = TL_MIN_ADDR;
    sZllState.u16FreeAddrHigh = TL_MAX_ADDR;
    sZllState.u16FreeGroupLow = TL_MIN_GROUP;
    sZllState.u16FreeGroupHigh = TL_MAX_GROUP;

    memset(&sEndpointTable, 0 , sizeof(tsZllEndpointInfoTable));
    memset(&sGroupTable, 0, sizeof(tsZllGroupInfoTable));

    /* save everything */
    PDM_eSaveRecordData(PDM_ID_APP_ZLO_CONTROLLER, &sZllState,sizeof(tsZllRemoteState));
    PDM_eSaveRecordData(PDM_ID_APP_END_P_TABLE, &sEndpointTable, sizeof(tsZllEndpointInfoTable));
    PDM_eSaveRecordData(PDM_ID_APP_GROUP_TABLE, &sGroupTable, sizeof(tsZllGroupInfoTable));
    ZPS_vSaveAllZpsRecords();
}

/****************************************************************************
 *
 * NAME: APP_SleepAndPollTask
 *
 * DESCRIPTION: Manages polling, sleeping and rejoin retries
 *              Acctivated by timer
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_cbTimerPoll(void *pvParam)
{
    uint32 u32Time = ZTIMER_TIME_MSEC(1000);

    if ( !BDB_bTlTouchLinkInProgress())
    {
        DBG_vPrintf(TRACE_REMOTE_NODE|TRACE_REJOIN, "KeepAlive - %d, Deep Sleep - %d fast Poll - %d FailedTojoin %d \n",
                        u8KeepAliveTime,
                        u8DeepSleepTime,
                        u16FastPoll,
                        bFailedToJoin);
        switch (sZllState.eNodeState)
        {
        case E_REMOTE_STARTUP:
            u32Time = ZTIMER_TIME_MSEC(1000);
            DBG_vPrintf(TRACE_REMOTE_NODE|TRACE_REJOIN, "Poll and Sleep: Start up \n");
            break;

        case E_REMOTE_RUNNING:
            //DBG_vPrintf(TRACE_REMOTE_NODE|TRACE_REJOIN, "Poll and Sleep: Running\n");
            if (bBDBJoinFailed)
            {
                /* Manage rejoin attempts,then short wait, then deep sleep */
                u32Time = ZTIMER_TIME_MSEC(1000);

                if (u8DeepSleepTime)
                {
                    u8DeepSleepTime--;
                }
                else
                {
                    vStopAllTimers();
                    DBG_vPrintf(TRACE_REJOIN, "join failed: go deep... %d\n", PWRM_u16GetActivityCount());
                    PWRM_vInit(E_AHI_SLEEP_DEEP);
                    bDeepSleep = TRUE;
                    return;
                }

            }
            else
            {
                /* Manage polling, then warm sleep, then deep sleep */
                if(u8KeepAliveTime == 0)
                {
                    vStopAllTimers();
                    if (u8DeepSleepTime)
                    {
                       uint8 u8Status;
                        u8Status = PWRM_eScheduleActivity(&sWake, (SLEEP_DURATION_MS * SLEEP_TIMER_TICKS_PER_MS) , vWakeCallBack);
                       DBG_vPrintf(TRACE_SLEEP, "poll task: schedule sleep %02x\n", u8Status );
                    }
                    else 
                    {
                        PWRM_vInit(E_AHI_SLEEP_DEEP);
                        bDeepSleep = TRUE;
                        DBG_vPrintf(TRACE_SLEEP, "poll task: go deep\n");
                    }
                    DBG_vPrintf(TRACE_SLEEP,"Activity %d\n",PWRM_u16GetActivityCount());
                    while (0 != PWRM_u16GetActivityCount())
                    {
                        /* force sleep if required */
                        PWRM_eFinishActivity();
                        DBG_vPrintf(TRACE_SLEEP, "Activity Now %d\n", PWRM_u16GetActivityCount() );
                    }
                    return;
                }
                else
                {
                   uint8 u8PStatus;
                   u8PStatus = ZPS_eAplZdoPoll();
                   if ( u8PStatus)
                   {
                       DBG_vPrintf(TRACE_REMOTE_NODE|TRACE_REJOIN, "\nPOLL status %d\n", u8PStatus);
                   }

                   if (u16FastPoll)
                   {
                       u16FastPoll--;
                       u32Time = POLL_TIME_FAST;
                       if (u16FastPoll == 0)
                       {
                           DBG_vPrintf(TRACE_REMOTE_NODE, "\nStop fast poll");
                       }
                   }
                   else
                   {
                       /* Decrement the keep alive in the normal operation mode
                        * Not in active scan mode or while fast polling
                        */

                       if(0 < u8KeepAliveTime)
                       {
#ifdef SLEEP_ENABLE
                           u8KeepAliveTime--;
#endif
                       }
                       /*Start Poll Timer to continue normal polling */
                       u32Time = ZTIMER_TIME_MSEC(1000);
                   }
                }
            }
            break;

        default:
            /* shouldn't happen, but... */
            u32Time = ZTIMER_TIME_MSEC(1000);
            break;

        }
    }
    else
    {
        DBG_vPrintf(TRACE_REMOTE_NODE|TRACE_REJOIN, "Sleep and Poll: Touch link in progress\n");
    }

    ZTIMER_eStop(u8TimerPoll);
    ZTIMER_eStart(u8TimerPoll, u32Time);
}

/****************************************************************************
 *
 * NAME:
 *
 * DESCRIPTION: handle identify request command received by the remote
 * causes the identify blink for the required time
 *
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vHandleIdentifyRequest(uint16 u16Duration)
{
    u16IdTime = u16Duration << 1;
    ZTIMER_eStop(u8TimerId);
    if (u16IdTime == 0)
    {
        APP_vSetLeds(eShiftLevel);
    }
    else
    {
        if (u16Duration == 0xffff)
        {
            u16Duration = 10;
        }
        ZTIMER_eStart(u8TimerId, ZTIMER_TIME_MSEC(500));
        APP_vSetLeds(E_SHIFT_3);
    }
}

/****************************************************************************
 *
 * NAME: APP_cbTimerId
 *
 * DESCRIPTION: Tasks that handles the flashing leds during identfy operation
 *
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_cbTimerId(void *pvParam)
{
    if (u16IdTime == 0)
    {
        /* interpan id time out, shut down */
        ZTIMER_eStop(u8TimerId);
        APP_vSetLeds(eShiftLevel);
    }
    else 
    {
        u16IdTime--;
        if (u16IdTime & 0x01)
        {
            APP_vSetLeds(E_SHIFT_0);
        }
        else
        {
            APP_vSetLeds(E_SHIFT_3);
        }
        ZTIMER_eStop(u8TimerId);
        ZTIMER_eStart(u8TimerId, ZTIMER_TIME_MSEC(500));
    }
}

/****************************************************************************
 *
 * NAME: vResetSleepAndJoinCounters
 *
 * DESCRIPTION: helper function to reset counters and flags associated
 * with sleep and join
 *
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/

PRIVATE void vResetSleepAndJoinCounters(void)
{
    u8KeepAliveTime = KEEP_ALIVETIME;
    u8DeepSleepTime = DEEP_SLEEPTIME;
    bFailedToJoin = FALSE;
    bBDBJoinFailed = FALSE;
}

/****************************************************************************
 *
 * NAME: u8GetFirstPrimaryChannel
 *
 * DESCRIPTION:
 *
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE uint8 u8GetFirstPrimaryChannel( void)
{
    uint32 u32Channel = 0;
    uint32 u32ChannelMask = BDB_PRIMARY_CHANNEL_SET;

    while( (u32ChannelMask & 0x01) == 0)
    {
        u32Channel++;
        u32ChannelMask >>= 1;
    };

    return (uint8)u32Channel;


}

/****************************************************************************
 *
 * NAME: bAppCancelRejoin
 *
 * DESCRIPTION: registered callback function for BDB to cancel rejoin attempts
 * if something else is taking precedence eg touchlink or out of band
 * commissioning
 *
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE bool bAppCancelRejoin(void)
{
    /* cancel rejoin attempts if touch link is started */
    /* any other reasons for cancelling can be added here */
    return bIsTlStarted();
}


#ifdef DR1199
/****************************************************************************
 *
 * NAME: vDeletePDMOnButtonPress
 *
 * DESCRIPTION:
 * PDM context clearing on button press
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vDeletePDMOnButtonPress(uint8 u8ButtonDIO)
{
    bool_t bDeleteRecords = FALSE;
    uint32 u32Buttons = u32AHI_DioReadInput() & (1 << u8ButtonDIO);
    if (u32Buttons == 0)
    {
        bDeleteRecords = TRUE;
    }
    else
    {
        bDeleteRecords = FALSE;
    }
    /* If required, at this point delete the network context from flash, perhaps upon some condition
     * For example, check if a button is being held down at reset, and if so request the Persistent
     * Data Manager to delete all its records:
     * e.g. bDeleteRecords = vCheckButtons();
     * Alternatively, always call PDM_vDeleteAllDataRecords() if context saving is not required.
     */
    if(bDeleteRecords)
    {
        if (ZPS_E_SUCCESS !=  ZPS_eAplZdoLeaveNetwork(0, FALSE,FALSE)) {
            /* Leave failed,so just reset everything */
            DBG_vPrintf(TRACE_APP,"Deleting the PDM Leave Fail\n");
            APP_vFactoryResetRecords();
            while (u32Buttons == 0)
            {
                u32Buttons = u32AHI_DioReadInput() & (1 << u8ButtonDIO);
            }
            vAHI_SwReset();
        }
    }
}
#endif

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

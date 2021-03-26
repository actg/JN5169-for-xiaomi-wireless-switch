/*****************************************************************************
 *
 * MODULE:             JN-AN-1219
 *
 * COMPONENT:          app_zlo_switch_node.c
 *
 * DESCRIPTION:        ZLO Controller & Switch Demo : Stack <-> Remote Control App Interaction
 *                     (Implementation)
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
 * Copyright NXP B.V. 2017. All rights reserved
 *
 ***************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#include <jendefs.h>
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
#include "Identify.h"
#include "app_common.h"
#include "app_main.h"
#include "Groups.h"
#ifdef JN517x
#include "AHI_ModuleConfiguration.h"
#endif

#include "PDM_IDs.h"
#include "app_events.h"

#include "ZTimer.h"
#include "app_zlo_switch_node.h"

#include "app_zcl_switch_task.h"
#include "app_zbp_utilities.h"

#include "app_events.h"
#include "zcl_customcommand.h"
#include "app_buttons.h"
#include "GenericBoard.h"
#include "app_switch_state_machine.h"
#include "zcl_common.h"
#ifdef CLD_OTA
#include "OTA.h"
#include "app_ota_client.h"
#endif

#ifdef APP_NTAG_ICODE
#include "app_ntag_icode.h"
#include "nfc_nwk.h"
#endif
#ifdef APP_NTAG_AES
#include "app_ntag_aes.h"
#include "nfc_nwk.h"
#endif

#include "appZdpExtraction.h"
#include "app_main.h"
#include "app_pdm_convert.h"
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifdef DEBUG_SWITCH_NODE
#define TRACE_SWITCH_NODE   TRUE
#else
#define TRACE_SWITCH_NODE   FALSE
#endif

#define bWakeUpFromSleep() bWaitingToSleep()  /* For readability purpose */

#define APP_LONG_SLEEP_DURATION_IN_SEC (60*60)          //60 minutes

/* ZDO endpoint for all devices is always 0 */
#define SWITCH_ZDO_ENDPOINT    (0)

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/


/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
PUBLIC void vStopTimer(uint8 u8Timer);
#ifdef SLEEP_ENABLE
PRIVATE void vStopAllTimers(void);
PRIVATE void vLoadKeepAliveTime(uint8 u8TimeInSec);
#ifdef DEEP_SLEEP_ENABLE
PRIVATE void vActionOnButtonActivationAfterDeepSleep(void);
#endif
#endif

PRIVATE void vSetAddress(tsZCL_Address * psAddress, bool_t bBroadcast, uint16 u16ClusterId);
PRIVATE void vHandleJoinAndRejoin(void);
PRIVATE void app_vRestartNode(void);
PRIVATE void app_vStartNodeFactoryNew(void);
PRIVATE void vAppHandleAfEvent(BDB_tsZpsAfEvent *psZpsAfEvent);
PRIVATE void vHandleRunningStackEvent(ZPS_tsAfEvent* psStackEvent);
PRIVATE bool bAddressInTable(uint16 u16AddressToCheck);
PRIVATE void vAppHandleZdoEvents(BDB_tsZpsAfEvent *psZpsAfEvent);
PRIVATE void vDeletePDMOnButtonPress(uint8 u8ButtonDIO);
PRIVATE void vAppEnterDeepSleepMode(void);

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

PUBLIC PDM_tsRecordDescriptor   sDevicePDDesc;
PUBLIC tsDeviceDesc             sDeviceDesc;
PUBLIC uint16                   u16GroupId;
PUBLIC uint16 u16GlobalGroupId = 1;
extern PUBLIC uint8 u8TimerLedBlinks;
PUBLIC ledVset_t ledVsetParam;

tsConvertR21toR22 sConvertR21toR22 = { FALSE };

extern const uint8 u8MyEndpoint;
/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
PRIVATE tsDeviceInfo sDeviceInfo;

PRIVATE uint16 u16FastPoll;

#ifdef SLEEP_ENABLE
PRIVATE bool bDataPending = FALSE;
#ifdef DEEP_SLEEP_ENABLE
PRIVATE uint8 u8DeepSleepTime = DEEP_SLEEP_TIME;
#endif
PRIVATE uint8 u8KeepAliveTime = KEEP_ALIVETIME;
PRIVATE pwrm_tsWakeTimerEvent    sWake;
#endif
PRIVATE bool bWaitingForLeave = FALSE;
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
PUBLIC void APP_vInitialiseNode(void)
{
    DBG_vPrintf(TRACE_SWITCH_NODE, "APP: Entering %s()\n", __func__);

    APP_vInitLeds();

#ifdef DEEP_SLEEP_ENABLE
    vReloadSleepTimers();
#endif
    /*Initialise the application buttons*/
    APP_bButtonInitialise();

#ifdef CLD_OTA
    vLoadOTAPersistedData();
#endif

    /* Restore any application data previously saved to flash */
    uint16 u16ByteRead;
    PDM_eReadDataFromRecord(PDM_ID_APP_ZLO_SWITCH,
                            &sDeviceDesc,
                            sizeof(tsDeviceDesc),
                            &u16ByteRead);

    PDM_eReadDataFromRecord(PDM_ID_APP_CONVERT,
                            &sConvertR21toR22,
                            sizeof(tsConvertR21toR22),
                            &u16ByteRead);

#ifdef JN517x
    /* Default module configuration: change E_MODULE_DEFAULT as appropriate */
    vAHI_ModuleConfigure(E_MODULE_DEFAULT);
#endif


    /* Check if the device is running but not converted Structures */
    if((sDeviceDesc.eNodeState == E_RUNNING) && (sConvertR21toR22.bConvertRequired != TRUE))
    {
        /* Device has been OTA'ed so convert records */
        APP_vConvertR21_PdmToR22_Records();
    }

    /* Device just started up, or conversion complete */
    sConvertR21toR22.bConvertRequired = TRUE;

    PDM_eSaveRecordData(PDM_ID_APP_CONVERT, &sConvertR21toR22, sizeof(tsConvertR21toR22));


    /* Initialise ZBPro stack */
    ZPS_eAplAfInit();

    APP_ZCL_vInitialise();

    ZPS_bAplAfSetEndDeviceTimeout(ZED_TIMEOUT_16384_MIN);
    /* If the device state has been restored from flash, re-start the stack
     * and set the application running again.
     */
    if(sDeviceDesc.eNodeState == E_RUNNING)
    {
        DBG_vPrintf(TRACE_SWITCH_NODE, "\nNon Factory New Start\n");
        app_vRestartNode();
        sBDB.sAttrib.bbdbNodeIsOnANetwork = TRUE;
        //read u16GlobalGroupId
        PDM_eReadDataFromRecord(PDM_ID_DEVICE_SWITCH_GROUPID, &u16GlobalGroupId, sizeof(u16GlobalGroupId), &u16ByteRead);
    }
    else
    {
        DBG_vPrintf(TRACE_SWITCH_NODE, "\nFactory New Start\n");
        app_vStartNodeFactoryNew();
        sBDB.sAttrib.bbdbNodeIsOnANetwork = FALSE;
    }

    sBDB.sAttrib.u32bdbPrimaryChannelSet = BDB_PRIMARY_CHANNEL_SET;
    sBDB.sAttrib.u32bdbSecondaryChannelSet = BDB_SECONDARY_CHANNEL_SET;
    BDB_tsInitArgs sInitArgs;
    sInitArgs.hBdbEventsMsgQ = &APP_msgBdbEvents;

    BDB_vInit(&sInitArgs);

    //comment it to prevent delete PDM
#if 0
    /*In case of a deep sleep device any button wake up would cause a PDM delete , only check for DIO8
     * pressed for deleting the context */
#ifdef DEEP_SLEEP_ENABLE
    if(FALSE == (u16AHI_PowerStatus() & WAKE_FROM_DEEP_SLEEP))
    {
        DBG_vPrintf(TRACE_SWITCH_NODE, "wake from deep sleep\n");
        vDeletePDMOnButtonPress(APP_BUTTONS_BUTTON_1);
    }
    else if(sDeviceDesc.eNodeState == E_STARTUP)
    {
        DBG_vPrintf(TRACE_SWITCH_NODE, "wake from non-deep sleep\n");
        /* As in startup state re trigger the network steering */
        vActionOnButtonActivationAfterDeepSleep();
    }
#else
    vDeletePDMOnButtonPress(APP_BUTTONS_BUTTON_1);
#endif
#endif
#ifdef PDM_EEPROM
    vDisplayPDMUsage();
#endif
}


/****************************************************************************
 *
 * NAME: bLightsDiscovered
 *
 * DESCRIPTION:
 * Initializes LED's
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC bool bLightsDiscovered(void)
{
    if(sDeviceInfo.u8Discovered > 0)
    {
        return TRUE;
    }
    return FALSE;
}


/****************************************************************************
 *
 * NAME: vStartFastPolling
 *
 * DESCRIPTION:
 * Set fast poll time
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vStartFastPolling(uint8 u8Seconds)
{
    /* Fast poll is every 100ms, so times by 10 */
    u16FastPoll = 10 * u8Seconds;
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

    // DBG_vPrintf(1,"BdbCb type %d\n", psBdbEvent->eEventType);

    switch(psBdbEvent->eEventType)
    {
        case BDB_EVENT_NONE:
            break;
        case BDB_EVENT_ZPSAF:                // Use with BDB_tsZpsAfEvent
            vAppHandleAfEvent(&psBdbEvent->uEventData.sZpsAfEvent);
            break;

        case BDB_EVENT_INIT_SUCCESS:
            DBG_vPrintf(TRACE_SWITCH_NODE, "APP: BdbInitSuccessful\n");
            break;

        case BDB_EVENT_REJOIN_FAILURE: // only for ZED
            DBG_vPrintf(TRACE_SWITCH_NODE, "BDB EVT INIT failed to join\n");
            /* If waiting for leave do not try to go to sleep*/
            if(bWaitingForLeave == FALSE)
            {
                DBG_vPrintf(TRACE_SWITCH_NODE, "Init Rejoin Failure!\n");
                // Go to deep sleep
#ifdef SLEEP_ENABLE
                vLoadKeepAliveTime(0);
#ifdef DEEP_SLEEP_ENABLE
                vLoadDeepSleepTimer(0);
#endif
                ZTIMER_eStart(u8TimerTick, ZTIMER_TIME_MSEC(10));
#endif
            }
            break;

        case BDB_EVENT_REJOIN_SUCCESS: // only for ZED
            DBG_vPrintf(TRACE_SWITCH_NODE, "BDB EVT INIT Join success\n");
            vHandleJoinAndRejoin();
#ifdef DEEP_SLEEP_ENABLE
            /*If it is coming out of deep sleep take action on button press */
            vActionOnButtonActivationAfterDeepSleep();
#endif
            break;


        case BDB_EVENT_NWK_STEERING_SUCCESS:
            // go to running state
            DBG_vPrintf(TRACE_SWITCH_NODE, "GoRunningState!\n");
            vHandleJoinAndRejoin();
            //led indicate join successful
            memset(&ledVsetParam, 0, sizeof(ledVsetParam));
            ledVsetParam.duty = 50;
            ledVsetParam.period = 1000;
            ledVsetParam.times = 3;
            ZTIMER_eStart(u8TimerLedBlinks, ZTIMER_TIME_MSEC(1));
            break;

        case BDB_EVENT_NO_NETWORK:
            DBG_vPrintf(TRACE_SWITCH_NODE, "No Network\n");
            vAppEnterDeepSleepMode();
            break;

        case BDB_EVENT_APP_START_POLLING:
            DBG_vPrintf(TRACE_SWITCH_NODE, "Start Polling!\n");
            /* Start 1 seconds polling */
            DBG_vPrintf(TRACE_SWITCH_NODE, "APP_vBdbCallback: eNodeState = E_WAIT_STARTUP\n");
            sDeviceDesc.eNodeState = E_WAIT_STARTUP;
            ZTIMER_eStart(u8TimerPoll, POLL_TIME_FAST);
            vStartFastPolling(2);
            break;

        case BDB_EVENT_FB_HANDLE_SIMPLE_DESC_RESP_OF_TARGET:
            DBG_vPrintf(TRACE_SWITCH_NODE, "Simple descriptor %d %d %04x %04x %d \n", psBdbEvent->uEventData.psFindAndBindEvent->u8TargetEp,
                        psBdbEvent->uEventData.psFindAndBindEvent->u16TargetAddress,
                        psBdbEvent->uEventData.psFindAndBindEvent->u16ProfileId,
                        psBdbEvent->uEventData.psFindAndBindEvent->u16DeviceId,
                        psBdbEvent->uEventData.psFindAndBindEvent->u8DeviceVersion);
            break;

        case BDB_EVENT_FB_CHECK_BEFORE_BINDING_CLUSTER_FOR_TARGET:
            DBG_vPrintf(TRACE_SWITCH_NODE, "Check For Binding Cluster %d \n", psBdbEvent->uEventData.psFindAndBindEvent->uEvent.u16ClusterId);
            break;

        case BDB_EVENT_FB_CLUSTER_BIND_CREATED_FOR_TARGET:
            DBG_vPrintf(TRACE_SWITCH_NODE, "Bind Created for cluster %d \n", psBdbEvent->uEventData.psFindAndBindEvent->uEvent.u16ClusterId);
            vSetIndividualLightInformation();
            break;

        case BDB_EVENT_FB_BIND_CREATED_FOR_TARGET:
            {
                DBG_vPrintf(TRACE_SWITCH_NODE, "Bind Created for target EndPt %d \n", psBdbEvent->uEventData.psFindAndBindEvent->u8TargetEp);
                u8NoQueryCount = 0;
                // Example to ask to stop identification to an end point on completing discovery

                uint8 u8Seq;
                tsZCL_Address sAddress;
                tsCLD_Identify_IdentifyRequestPayload sPayload;

                sPayload.u16IdentifyTime = 0;
                sAddress.eAddressMode = E_ZCL_AM_SHORT_NO_ACK;
                sAddress.uAddress.u16DestinationAddress = psBdbEvent->uEventData.psFindAndBindEvent->u16TargetAddress;

                eCLD_IdentifyCommandIdentifyRequestSend(
                    psBdbEvent->uEventData.psFindAndBindEvent->u8InitiatorEp,
                    psBdbEvent->uEventData.psFindAndBindEvent->u8TargetEp,
                    &sAddress,
                    &u8Seq,
                    &sPayload);

                break;
            }

        case BDB_EVENT_FB_GROUP_ADDED_TO_TARGET:
            {
                DBG_vPrintf(TRACE_SWITCH_NODE, "Group Added with ID %d \n", psBdbEvent->uEventData.psFindAndBindEvent->uEvent.u16GroupId);
                u8NoQueryCount = 0;
                //Example to ask to Stop identification to that group
                uint8 u8Seq;
                tsZCL_Address sAddress;
                tsCLD_Identify_IdentifyRequestPayload sPayload;

                sPayload.u16IdentifyTime = 0;
                sAddress.eAddressMode = E_ZCL_AM_GROUP;
                sAddress.uAddress.u16GroupAddress = psBdbEvent->uEventData.psFindAndBindEvent->uEvent.u16GroupId;

                eCLD_IdentifyCommandIdentifyRequestSend(
                    psBdbEvent->uEventData.psFindAndBindEvent->u8InitiatorEp,
                    psBdbEvent->uEventData.psFindAndBindEvent->u8TargetEp,
                    &sAddress,
                    &u8Seq,
                    &sPayload);
                break;
            }

        case BDB_EVENT_FB_ERR_BINDING_TABLE_FULL:
            DBG_vPrintf(TRACE_SWITCH_NODE, "ERR: Bind Table Full\n");
            break;

        case BDB_EVENT_FB_ERR_BINDING_FAILED:
            DBG_vPrintf(TRACE_SWITCH_NODE, "ERR: Bind\n");
            break;

        case BDB_EVENT_FB_ERR_GROUPING_FAILED:
            DBG_vPrintf(TRACE_SWITCH_NODE, "ERR: Group\n");
            break;

        case BDB_EVENT_FB_NO_QUERY_RESPONSE:
            DBG_vPrintf(TRACE_SWITCH_NODE, "ERR: No Query response\n");
            //Example to stop further query repeating
            if(u8NoQueryCount >= 2)
            {
                u8NoQueryCount = 0;
                BDB_vFbExitAsInitiator();
            }
            else
            {
                u8NoQueryCount++;
            }
            break;

        case BDB_EVENT_FB_TIMEOUT:
            DBG_vPrintf(TRACE_SWITCH_NODE, "ERR: TimeOut\n");
            break;

        default:
            DBG_vPrintf(1, "BDB EVT default evt %d\n", psBdbEvent->eEventType);
            break;
    }
}

/****************************************************************************
 *
 * NAME: vAppHandleZdoEvents
 *
 * DESCRIPTION:
 * This is the main state machine which decides whether to call up the startup
 * or running function. This depends on whether we are in the network on not.
 *
 * PARAMETERS:
 * ZPS_tsAfEvent sAppStackEvent Stack event information.
 *
 ****************************************************************************/
PRIVATE void vAppHandleAfEvent(BDB_tsZpsAfEvent *psZpsAfEvent)
{
    if(psZpsAfEvent->u8EndPoint == app_u8GetDeviceEndpoint())
    {
        if((psZpsAfEvent->sStackEvent.eType == ZPS_EVENT_APS_DATA_INDICATION) ||
           (psZpsAfEvent->sStackEvent.eType == ZPS_EVENT_APS_INTERPAN_DATA_INDICATION))
        {
            DBG_vPrintf(TRACE_SWITCH_NODE, "Pass to ZCL\n");
            APP_ZCL_vEventHandler(&psZpsAfEvent->sStackEvent);
        }
    }
    else if(psZpsAfEvent->u8EndPoint == SWITCH_ZDO_ENDPOINT)
    {
        // events for ep 0
        vAppHandleZdoEvents(psZpsAfEvent);
    }

    /* Ensure Freeing of Apdus */
    if(psZpsAfEvent->sStackEvent.eType == ZPS_EVENT_APS_DATA_INDICATION)
    {
        PDUM_eAPduFreeAPduInstance(psZpsAfEvent->sStackEvent.uEvent.sApsDataIndEvent.hAPduInst);
    }
    else if(psZpsAfEvent->sStackEvent.eType == ZPS_EVENT_APS_INTERPAN_DATA_INDICATION)
    {
        PDUM_eAPduFreeAPduInstance(psZpsAfEvent->sStackEvent.uEvent.sApsInterPanDataIndEvent.hAPduInst);
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
PRIVATE void vAppHandleZdoEvents(BDB_tsZpsAfEvent *psZpsAfEvent)
{
    //DBG_vPrintf(1, "For ep 0, State %s\n", strings[sZllState.eNodeState] );
    /* Handle events depending on node state */
    switch(sDeviceDesc.eNodeState)
    {
        case E_STARTUP:
            break;

        case E_RUNNING:
            DBG_vPrintf(TRACE_SWITCH_NODE, "E_RUNNING\r\n");
            vHandleRunningStackEvent(&psZpsAfEvent->sStackEvent);
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
    switch(psStackEvent->eType)
    {
        case ZPS_EVENT_NWK_JOINED_AS_ENDDEVICE:
            vHandleJoinAndRejoin();
#ifdef APP_NTAG_ICODE
            {
                /* Not a rejoin ? */
                if(FALSE == psStackEvent->uEvent.sNwkJoinedEvent.bRejoin)
                {
                    /* Write network data to tag */
                    DBG_vPrintf(TRACE_SWITCH_NODE, "Write network data to tag\n");
                    APP_vNtagStart(DIMMERSWITCH_SWITCH_ENDPOINT);
                }
            }
#endif
            break;

        case ZPS_EVENT_NWK_FAILED_TO_JOIN:
            DBG_vPrintf(TRACE_SWITCH_NODE, "Running Failed to join\n");
            if(ZPS_psAplAibGetAib()->u64ApsUseExtendedPanid != 0)
            {
                DBG_vPrintf(TRACE_SWITCH_NODE, "Restore epid %016llx\n", ZPS_psAplAibGetAib()->u64ApsUseExtendedPanid);
                ZPS_vNwkNibSetExtPanId(ZPS_pvAplZdoGetNwkHandle(), ZPS_psAplAibGetAib()->u64ApsUseExtendedPanid);
            }
            break;

        case ZPS_EVENT_NWK_LEAVE_INDICATION:
            DBG_vPrintf(TRACE_SWITCH_NODE, "LEAVE IND Addr %016llx Rejoin %02x\n",
                        psStackEvent->uEvent.sNwkLeaveIndicationEvent.u64ExtAddr,
                        psStackEvent->uEvent.sNwkLeaveIndicationEvent.u8Rejoin);

            if((psStackEvent->uEvent.sNwkLeaveIndicationEvent.u64ExtAddr == 0UL) &&
               (psStackEvent->uEvent.sNwkLeaveIndicationEvent.u8Rejoin == 0))
            {
                /* We sare asked to Leave without rejoin */
                DBG_vPrintf(TRACE_SWITCH_NODE, "LEAVE IND -> For Us No Rejoin\n");
                DBG_vPrintf(TRACE_SWITCH_NODE, "Leave -> Reset Data Structures\n");
                APP_vFactoryResetRecords();
                DBG_vPrintf(TRACE_SWITCH_NODE, "Leave -> Soft Reset\n");
                vAHI_SwReset();
            }
            break;

        case ZPS_EVENT_NWK_LEAVE_CONFIRM:
            /* reset app data and restart */
            APP_vFactoryResetRecords();
            /* force a restart */
            vAHI_SwReset();
            break;

        case ZPS_EVENT_APS_DATA_INDICATION:
#ifdef CLD_OTA
            if((psStackEvent->uEvent.sApsDataIndEvent.eStatus == ZPS_E_SUCCESS) &&
               (psStackEvent->uEvent.sApsDataIndEvent.u8DstEndpoint == 0))
            {
                // Data Ind for ZDp Ep
                if(ZPS_ZDP_MATCH_DESC_RSP_CLUSTER_ID == psStackEvent->uEvent.sApsDataIndEvent.u16ClusterId)
                {
                    vHandleMatchDescriptor(psStackEvent);
                }
                else if(ZPS_ZDP_IEEE_ADDR_RSP_CLUSTER_ID == psStackEvent->uEvent.sApsDataIndEvent.u16ClusterId)
                {
                    vHandleIeeeAddressRsp(psStackEvent);
                }
            }
#endif
            break;

#ifdef SLEEP_ENABLE
        case ZPS_EVENT_NWK_POLL_CONFIRM:
            if(MAC_ENUM_SUCCESS == psStackEvent->uEvent.sNwkPollConfirmEvent.u8Status)
            {
                bDataPending = TRUE;
            }
            else if(MAC_ENUM_NO_DATA == psStackEvent->uEvent.sNwkPollConfirmEvent.u8Status)
            {
                bDataPending = FALSE;
            }
            break;
#endif

        default:
            //DBG_vPrintf(1, "Running unhandled %d\n", psStackEvent->eType);
            break;
    }
}
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
PUBLIC void APP_taskSwitch(void)
{
    APP_tsEvent sAppEvent;
    sAppEvent.eType = APP_E_EVENT_NONE;

    if(ZQ_bQueueReceive(&APP_msgAppEvents, &sAppEvent) == TRUE)
    {
        DBG_vPrintf(TRACE_SWITCH_NODE, "ZPR: App event %d, NodeState=%d, CommissioningStatus=%d\n", sAppEvent.eType, sDeviceDesc.eNodeState, sBDB.sAttrib.ebdbCommissioningStatus);

#if (defined APP_NTAG_ICODE) || (defined APP_NTAG_AES)
        /* Is this a button event on NTAG_FD ? */
        if((sAppEvent.eType == APP_E_EVENT_BUTTON_DOWN || sAppEvent.eType == APP_E_EVENT_BUTTON_UP)
           && (sAppEvent.uEvent.sButton.u8Button == APP_E_BUTTONS_NFC_FD))
        {
#if APP_NTAG_ICODE
            DBG_vPrintf(TRACE_SWITCH_NODE, "button down, NtagStart endpoint\n");
            APP_vNtagStart(DIMMERSWITCH_SWITCH_ENDPOINT);
#endif
#if APP_NTAG_AES
            DBG_vPrintf(TRACE_SWITCH_NODE, "button down, NtagStart router\n");
            APP_vNtagStart(NFC_NWK_NSC_DEVICE_ZIGBEE_ROUTER_DEVICE);
#endif
        }
        /* Other event (handle as normal) ? */
        else
#endif
        {
            switch(sAppEvent.eType)
            {
                case APP_E_EVENT_BUTTON_DOWN:
                    switch(sAppEvent.uEvent.sButton.u8Button)
                    {
                        case APP_E_BUTTONS_BUTTON_1:
                            {
                                if(ZTIMER_eGetState(u8TimerButtonLongPressed) != E_ZTIMER_STATE_STOPPED)
                                {
                                    ZTIMER_eStop(u8TimerButtonLongPressed);
                                }

                                DBG_vPrintf(TRACE_SWITCH_NODE, "Start Long Pressed timer\n");
                                ZTIMER_eStart(u8TimerButtonLongPressed, APP_BUTTONS_LONG_PRESSED_TIMEOUT);
                            }
                            break;

                        case APP_E_BUTTONS_BUTTON_SW1:
                            {
                                if(sDeviceDesc.eNodeState == E_RUNNING)
                                {
                                    teZCL_Status status;
                                    static bool flag = FALSE;
                                    if(!flag)
                                    {
                                        flag = TRUE;
                                    }
                                    else
                                    {
                                        flag = FALSE;
                                    }

                                    if(flag)
                                    {
                                        //scene 1
                                        uint8 u8Seq;
                                        tsZCL_Address sDestinationAddress;
                                        tsCLD_ScenesRecallSceneRequestPayload payLoad;
                                        sDestinationAddress.eAddressMode = E_ZCL_AM_GROUP;
                                        sDestinationAddress.uAddress.u16GroupAddress = u16GlobalGroupId;

                                        payLoad.u16GroupId = u16GlobalGroupId;
                                        payLoad.u8SceneId = 1;
                                        status = eCLD_ScenesCommandRecallSceneRequestSend(DIMMERSWITCH_SWITCH_ENDPOINT, DIMMERSWITCH_SWITCH_ENDPOINT, &sDestinationAddress, &u8Seq, &payLoad);
                                        DBG_vPrintf(TRACE_SWITCH_NODE, "Recall scene 1 =%d\n", status);
                                    }
                                    else
                                    {
                                        //scene 2
                                        uint8 u8Seq;
                                        tsZCL_Address sDestinationAddress;
                                        tsCLD_ScenesRecallSceneRequestPayload payLoad;
                                        sDestinationAddress.eAddressMode = E_ZCL_AM_GROUP;
                                        sDestinationAddress.uAddress.u16GroupAddress = u16GlobalGroupId;

                                        payLoad.u16GroupId = u16GlobalGroupId;
                                        payLoad.u8SceneId = 2;
                                        status = eCLD_ScenesCommandRecallSceneRequestSend(DIMMERSWITCH_SWITCH_ENDPOINT, DIMMERSWITCH_SWITCH_ENDPOINT, &sDestinationAddress, &u8Seq, &payLoad);
                                        DBG_vPrintf(TRACE_SWITCH_NODE, "Recall scene 0 =%d\n", status);
                                    }
                                }
                                else if(sDeviceDesc.eNodeState == E_STARTUP)
                                {

                                }
                            }
                            break;
                    }
#ifdef SLEEP_ENABLE
                    vReloadSleepTimers();
#endif
                    break;
                case APP_E_EVENT_BUTTON_UP:
                    switch(sAppEvent.uEvent.sButton.u8Button)
                    {
                        case APP_E_BUTTONS_BUTTON_1:
                            {
                                if(ZTIMER_eGetState(u8TimerButtonLongPressed) != E_ZTIMER_STATE_STOPPED)
                                {
                                    DBG_vPrintf(TRACE_SWITCH_NODE, "Stop Long Pressed timer\n");
                                    ZTIMER_eStop(u8TimerButtonLongPressed);
                                }
                            }
                            break;

                        case APP_E_BUTTONS_BUTTON_SW1:
                            {

                            }
                            break;
                    }
#ifdef SLEEP_ENABLE
                    vReloadSleepTimers();
#endif

                    break;

                case APP_E_EVENT_BUTTON_ALL_UP:
                    if(sDeviceDesc.eNodeState == E_STARTUP &&
                       sBDB.sAttrib.ebdbCommissioningStatus == E_BDB_COMMISSIONING_STATUS_IN_PROGRESS)
                    {
#ifdef SLEEP_ENABLE
                        vReloadSleepTimers();
#endif
                    }
                    else if(sDeviceDesc.eNodeState == E_STARTUP &&
                            sBDB.sAttrib.ebdbCommissioningStatus == E_BDB_COMMISSIONING_STATUS_SUCCESS &&
                            ZTIMER_eGetState(u8TimerLedBlinks) != E_ZTIMER_STATE_RUNNING)
                    {
                        bool_t u8StartSteering = FALSE;
                        uint16       u16PdmRead = 0;

                        PDM_eReadDataFromRecord(PDM_ID_APP_START_STEERING,
                                                &u8StartSteering,
                                                sizeof(u8StartSteering),
                                                &u16PdmRead);

                        if(u8StartSteering)
                        {
                            // case flag and start steering
                            u8StartSteering = FALSE;
                            PDM_eSaveRecordData(PDM_ID_APP_START_STEERING, &u8StartSteering, sizeof(u8StartSteering));
                            sBDB.sAttrib.u32bdbPrimaryChannelSet = BDB_PRIMARY_CHANNEL_SET;
                            sBDB.sAttrib.u32bdbSecondaryChannelSet = 0;
                            BDB_eNsStartNwkSteering();
                        }
                        else
                        {
                            //factory and not steering mode
                            vAppEnterDeepSleepMode();
                        }
                    }
                    else if(sDeviceDesc.eNodeState == E_STARTUP &&
                            sBDB.sAttrib.ebdbCommissioningStatus == E_BDB_COMMISSIONING_STATUS_NO_NETWORK &&
                            ZTIMER_eGetState(u8TimerLedBlinks) != E_ZTIMER_STATE_RUNNING)
                    {
                        // steering failure(no network)
                        vAppEnterDeepSleepMode();
                    }
                    else if(sDeviceDesc.eNodeState == E_RUNNING && sBDB.sAttrib.ebdbCommissioningStatus == E_BDB_COMMISSIONING_STATUS_NO_NETWORK)
                    {
                        sBDB.sAttrib.u32bdbPrimaryChannelSet = BDB_PRIMARY_CHANNEL_SET;
                        sBDB.sAttrib.u32bdbSecondaryChannelSet = 0;
                        BDB_eNsStartNwkSteering();
                    }
                    break;

                default:
                    break;
            }

        }
    }
}


/****************************************************************************
 *
 * NAME: vHandleJoinAndRejoin
 *
 * DESCRIPTION:
 * Handles the Join and Rejoin events
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vHandleJoinAndRejoin(void)
{
    DBG_vPrintf(TRACE_SWITCH_NODE, "DEVICE_IN_NETWORK \n");
    uint64 u64MacAddr = *((uint64*)pvAppApiGetMacAddrLocation());
    DBG_vPrintf(TRACE_SWITCH_NODE, "vHandleJoinAndRejoin: eNodeState = E_RUNNING\n");
    sDeviceDesc.eNodeState = E_RUNNING;
    u16GroupId = ((uint16)u64MacAddr) ^ ((uint16)(u64MacAddr >> 16));
    vSetIndividualLightInformation();
    PDM_eSaveRecordData(PDM_ID_APP_ZLO_SWITCH,
                        &sDeviceDesc,
                        sizeof(tsDeviceDesc));
    ZPS_vSaveAllZpsRecords();
    /* Stop Fast polling */
    vStartFastPolling(0);
    /* Start 1 seconds polling */
    ZTIMER_eStart(u8TimerPoll, POLL_TIME);
    ZTIMER_eStart(u8TimerTick, ZCL_TICK_TIME);
}

#ifdef SLEEP_ENABLE
#ifdef DEEP_SLEEP_ENABLE
/****************************************************************************
 *
 * NAME: vActionOnButtonActivationAfterDeepSleep
 *
 * DESCRIPTION:
 * Takes some action based on the button that activated the wake up from deep
 * sleep
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vActionOnButtonActivationAfterDeepSleep(void)
{

    APP_tsEvent sButton;
    uint32 u32DIOState = u32AHI_DioReadInput();
    sButton.eType = APP_E_EVENT_NONE;
    sButton.uEvent.sButton.u32DIOState = u32DIOState;

    if(0 == (u32DIOState & ON))
    {
        sButton.uEvent.sButton.u8Button = ON_PRESSED;
        sButton.eType = APP_E_EVENT_BUTTON_DOWN;
    }
    ZQ_bQueueSend(&APP_msgAppEvents, &sButton);

}

/****************************************************************************
 *
 * NAME: vLoadDeepSleepTimer
 *
 * DESCRIPTION:
 * Loads the deep sleep time
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vLoadDeepSleepTimer(uint8 u8SleepTime)
{
    u8DeepSleepTime = u8SleepTime;
}
/****************************************************************************
 *
 * NAME: bGoingDeepSleep
 *
 * DESCRIPTION:
 * Checks if the module is going to deep sleep
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC bool bGoingDeepSleep(void)
{
    if(0 == u8DeepSleepTime)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

#endif
/****************************************************************************
 *
 * NAME: vLoadKeepAliveTime
 *
 * DESCRIPTION:
 * Loads the keep alive timer based on the right conditions.
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vLoadKeepAliveTime(uint8 u8TimeInSec)
{
    //uint8 a;
    u8KeepAliveTime = u8TimeInSec;
    ZTIMER_eStop(u8TimerPoll);
    ZTIMER_eStart(u8TimerPoll, POLL_TIME);
    ZTIMER_eStop(u8TimerTick);
    ZTIMER_eStart(u8TimerTick, ZCL_TICK_TIME);
}

/****************************************************************************
 *
 * NAME: bWaitingToSleep
 *
 * DESCRIPTION:
 * Gets the status if the module is waiting for sleep.
 *
 * RETURNS:
 * bool
 *
 ****************************************************************************/
PUBLIC bool bWaitingToSleep(void)
{
    if(0 == u8KeepAliveTime)
        return TRUE;
    else
        return FALSE;
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
PUBLIC void vStopAllTimers(void)
{
    vStopTimer(u8TimerPoll);
    vStopTimer(u8TimerButtonScan);
    vStopTimer(u8TimerTick);
    vStopTimer(u8TimerButtonDelay);
    vStopTimer(u8TimerChangeMode);
}

/****************************************************************************
 *
 * NAME: vUpdateKeepAliveTimer
 *
 * DESCRIPTION:
 * Updates the Keep Alive time at 1 sec call from the tick timer that served ZCL as well.
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vUpdateKeepAliveTimer(void)
{
    te_SwitchState eSwitchState = eGetSwitchState();

    if((eSwitchState == LIGHT_CONTROL_MODE) || (eSwitchState == INDIVIDUAL_CONTROL_MODE))
    {
        if(u8KeepAliveTime > 0)
        {
            u8KeepAliveTime--;
            DBG_vPrintf(TRACE_SWITCH_NODE, "\n KeepAliveTime = %d \n", u8KeepAliveTime);
        }
        else
        {
            vStopAllTimers();
            DBG_vPrintf(TRACE_SWITCH_NODE, "\n Activity %d, KeepAliveTime %d, u8DeepSleepTime %d\n", PWRM_u16GetActivityCount(), u8KeepAliveTime, u8DeepSleepTime);

#ifdef DEEP_SLEEP_ENABLE
            if(u8DeepSleepTime > 0)
            {
                u8DeepSleepTime--;
                /* The activity counter seems to be still greater than 0 - Go back to be awake, Try again in the next sleep time*/
                if(PWRM_u16GetActivityCount())
                {
                    DBG_vPrintf(TRACE_SWITCH_NODE, "\n Abort Sleep - Reload timers\n");
                    vReloadSleepTimers();
                }
                else
                {
                    PWRM_teStatus eStatus = PWRM_eScheduleActivity(&sWake, APP_LONG_SLEEP_DURATION_IN_SEC * 32000, vWakeCallBack);
                    DBG_vPrintf(TRACE_SWITCH_NODE, "\nSleep Status = %d, u8DeepSleepTime = %d \n", eStatus, u8DeepSleepTime);
                }
            }
            else
            {
                /*It is OK to force a deep sleep by finishing activities when we intent to enter the deep sleep*/
                while(PWRM_u16GetActivityCount())
                    PWRM_eFinishActivity();
                PWRM_vInit(E_AHI_SLEEP_DEEP);
            }
#else
            /* The activity counter seems to be still greater than 0 - Go back to be awake, Try again in the next sleep time*/
            if(PWRM_u16GetActivityCount())
            {
                vReloadSleepTimers();
            }
            else
            {
                /* The activity counter is 0 so a sleep with ram on can be scheduled*/
                PWRM_teStatus eStatus = PWRM_eScheduleActivity(&sWake, APP_LONG_SLEEP_DURATION_IN_SEC * 32000, vWakeCallBack);
                DBG_vPrintf(TRACE_SWITCH_NODE, "\nSleep Status = %d\n", eStatus);
            }
#endif
        }
    }
    else
    {
        vReloadSleepTimers();

    }
}
#endif

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
    if(u32Buttons == 0)
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
     * Alternatively, always call PDM_vDelete() if context saving is not required.
     */
    if(bDeleteRecords)
    {
        if(ZPS_E_SUCCESS !=  ZPS_eAplZdoLeaveNetwork(0, FALSE, FALSE))
        {
            /* Leave failed, probably lost parent, so just reset everything */
            DBG_vPrintf(TRACE_SWITCH_NODE, "Deleting the PDM\n");
            PDM_vDeleteAllDataRecords();
            vAHI_SwReset();
        }
        bWaitingForLeave = TRUE;
    }
}



/****************************************************************************
 *
 * NAME: vAppOnOff
 *
 * DESCRIPTION:
 *    Send out ON or OFF command, the address mode(group/unicast/bound etc)
 *    is taken from the selected light index set by the caller
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppOnOff(teCLD_OnOff_Command eCmd)
{

    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE, GENERAL_CLUSTER_ID_ONOFF);

    if((eCmd == E_CLD_ONOFF_CMD_ON) || (eCmd == E_CLD_ONOFF_CMD_OFF) || (eCmd
            == E_CLD_ONOFF_CMD_TOGGLE))
    {
        eCLD_OnOffCommandSend(
            u8MyEndpoint,
            sDeviceInfo.sLightInfo[sDeviceInfo.u8Index].u8Ep,
            &sAddress, &u8Seq, eCmd);
    }
}


/****************************************************************************
 *
 * NAME: vAppIdentify
 *
 * DESCRIPTION:
 *    Send out Identify command, the address mode(group/unicast/bound etc)
 *    is taken from the selected light index set by the caller
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppIdentify(uint16 u16Time)
{
    uint8 u8Seq;
    tsZCL_Address sAddress;
    tsCLD_Identify_IdentifyRequestPayload sPayload;

    sPayload.u16IdentifyTime = u16Time;

    vSetAddress(&sAddress, FALSE, GENERAL_CLUSTER_ID_IDENTIFY);

    eCLD_IdentifyCommandIdentifyRequestSend(
        u8MyEndpoint,
        sDeviceInfo.sLightInfo[sDeviceInfo.u8Index].u8Ep,
        &sAddress,
        &u8Seq,
        &sPayload);
}

/****************************************************************************
 *
 * NAME: vAppLevelMove
 *
 * DESCRIPTION:
 *    Send out Level Up or Down command, the address mode(group/unicast/bound etc)
 *    is taken from the selected light index set by the caller
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppLevelMove(teCLD_LevelControl_MoveMode eMode, uint8 u8Rate, bool_t bWithOnOff)
{
    tsCLD_LevelControl_MoveCommandPayload sPayload = {0};
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE, GENERAL_CLUSTER_ID_LEVEL_CONTROL);

    sPayload.u8Rate = u8Rate;
    sPayload.u8MoveMode = eMode;

    eCLD_LevelControlCommandMoveCommandSend(
        u8MyEndpoint,
        sDeviceInfo.sLightInfo[sDeviceInfo.u8Index].u8Ep,
        &sAddress,
        &u8Seq,
        bWithOnOff, /* with on off */
        &sPayload);
}


/****************************************************************************
 *
 * NAME: vAppLevelStop
 *
 * DESCRIPTION:
 *    Send out Level Stop command, the address mode(group/unicast/bound etc)
 *    is taken from the selected light index set by the caller
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppLevelStop(void)
{
    tsCLD_LevelControl_StopCommandPayload sPayload = {0};
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE, GENERAL_CLUSTER_ID_LEVEL_CONTROL);
    eCLD_LevelControlCommandStopCommandSend(
        u8MyEndpoint,
        sDeviceInfo.sLightInfo[sDeviceInfo.u8Index].u8Ep,
        &sAddress,
        &u8Seq,
        FALSE, /* without on off */
        &sPayload);
}


/****************************************************************************
 *
 * NAME: vAppLevelStepMove
 *
 * DESCRIPTION:
 *    Send out Step Move command, the address mode(group/unicast/bound etc)
 *    is taken from the selected light index set by the caller
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppLevelStepMove(teCLD_LevelControl_MoveMode eMode)
{
    tsCLD_LevelControl_StepCommandPayload sPayload = {0};
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE, GENERAL_CLUSTER_ID_LEVEL_CONTROL);

    sPayload.u16TransitionTime = 0x000a;
    sPayload.u8StepMode = eMode;
    sPayload.u8StepSize = 0x20;
    eCLD_LevelControlCommandStepCommandSend(
        u8MyEndpoint,
        sDeviceInfo.sLightInfo[sDeviceInfo.u8Index].u8Ep,
        &sAddress,
        &u8Seq,
        FALSE,               /* with on off */
        &sPayload);
}

#ifdef CLD_SCENES
/****************************************************************************
 *
 * NAME: vAppRecallSceneById
 *
 * DESCRIPTION:
 *    Send out Recall Scene command, the address is group addressing
 *    is taken from the selected light index set by the caller
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppRecallSceneById(uint8 u8SceneId, uint16 u16GroupId)
{

    tsCLD_ScenesRecallSceneRequestPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE, GENERAL_CLUSTER_ID_SCENES);

    DBG_vPrintf(TRACE_SWITCH_NODE, "\nRecall Scene %d\n", u8SceneId);

    sPayload.u16GroupId = u16GroupId;
    sPayload.u8SceneId = u8SceneId;
    sPayload.u16TransitionTime = 0x0000;

    eCLD_ScenesCommandRecallSceneRequestSend(
        u8MyEndpoint,
        sDeviceInfo.sLightInfo[sDeviceInfo.u8Index].u8Ep,
        &sAddress,
        &u8Seq,
        &sPayload);

}
/****************************************************************************
 *
 * NAME: vAppStoreSceneById
 *
 * DESCRIPTION:
 *    Send out Store Scene command, the address mode is group addressing
 *    is taken from the selected light index set by the caller
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppStoreSceneById(uint8 u8SceneId, uint16 u16GroupId)
{
    tsCLD_ScenesStoreSceneRequestPayload sPayload;

    uint8 u8Seq;
    tsZCL_Address sAddress;

    sAddress.eAddressMode = E_ZCL_AM_GROUP;
    sAddress.uAddress.u16DestinationAddress = u16GroupId;

    sPayload.u16GroupId = u16GroupId;
    sPayload.u8SceneId = u8SceneId;


    eCLD_ScenesCommandStoreSceneRequestSend(
        u8MyEndpoint,
        sDeviceInfo.sLightInfo[sDeviceInfo.u8Index].u8Ep,   /* dst ep */
        &sAddress,
        &u8Seq,
        &sPayload);

}

#endif

/****************************************************************************
 *
 * NAME: vAppAddGroup
 *
 * DESCRIPTION:
 *    Send out Add Group command, the address mode is unicast addressing and
 *    is taken from the selected light index set by the caller
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppAddGroup(uint16 u16GroupId, bool_t bBroadcast)
{

    tsCLD_Groups_AddGroupRequestPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, bBroadcast, GENERAL_CLUSTER_ID_GROUPS);

    sPayload.sGroupName.pu8Data = (uint8*)"";
    sPayload.sGroupName.u8Length = 0;
    sPayload.sGroupName.u8MaxLength = 0;
    sPayload.u16GroupId = u16GroupId;

    eCLD_GroupsCommandAddGroupRequestSend(
        u8MyEndpoint,
        sDeviceInfo.sLightInfo[sDeviceInfo.u8Index].u8Ep,
        &sAddress,
        &u8Seq,
        &sPayload);

}

/****************************************************************************
 *
 * NAME: vAppRemoveGroup
 *
 * DESCRIPTION:
 *    Send out remove group command, the address mode (group/unicast/bound etc)
 *    is taken from the selected light index set by the caller
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppRemoveGroup(uint16 u16GroupId, bool_t bBroadcast)
{

    tsCLD_Groups_RemoveGroupRequestPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, bBroadcast, GENERAL_CLUSTER_ID_GROUPS);

    sPayload.u16GroupId = u16GroupId;

    eCLD_GroupsCommandRemoveGroupRequestSend(
        u8MyEndpoint,
        sDeviceInfo.sLightInfo[sDeviceInfo.u8Index].u8Ep,
        &sAddress,
        &u8Seq,
        &sPayload);

}

/****************************************************************************
 *
 * NAME: vAppRemoveAllGroups
 *
 * DESCRIPTION:
 *    Send out Remove All group command, the address mode(group/unicast/bound etc)
 *    is taken from the selected light index set by the caller
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppRemoveAllGroups(bool_t bBroadcast)
{

    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, bBroadcast, GENERAL_CLUSTER_ID_GROUPS);

    eCLD_GroupsCommandRemoveAllGroupsRequestSend(
        u8MyEndpoint,
        sDeviceInfo.sLightInfo[sDeviceInfo.u8Index].u8Ep,
        &sAddress,
        &u8Seq);

}

/****************************************************************************
 *
 * NAME: vStopTimer
 *
 * DESCRIPTION:
 * Stops the timer
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vStopTimer(uint8 u8Timer)
{
    ZTIMER_eStop(u8Timer);
}


/****************************************************************************
 *
 * NAME: vManageWakeUponSysControlISR
 *
 * DESCRIPTION:
 * Called from SysControl ISR to process the wake up conditions
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vManageWakeUponSysControlISR(teInterruptType eInterruptType)
{
#ifdef SLEEP_ENABLE
    /*In any case this could be a wake up from timer interrupt or from buttons
     * press
     * */
    if(TRUE == bWakeUpFromSleep())
    {
        /*Only called if the module is coming out of sleep */
#ifdef CLD_OTA
        if(eInterruptType == E_INTERRUPT_WAKE_TIMER_EXPIRY)
        {
            /* Increment time out value by sleep duration in seconds */
            vIncrementTimeOut(APP_LONG_SLEEP_DURATION_IN_SEC);
        }
#endif
        /*Only called if the module is coming out of sleep */
        DBG_vPrintf(TRACE_SWITCH_NODE, "vISR_SystemController on WakeUP\n\n");
        vLoadKeepAliveTime(KEEP_ALIVETIME);
    }
#endif
}
#ifdef SLEEP_ENABLE
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
PUBLIC void vWakeCallBack(void)
{
    DBG_vPrintf(TRACE_SWITCH_NODE, "vWakeCallBack\n");

    /*Start Polling*/
    ZTIMER_eStart(u8TimerPoll, POLL_TIME);

    /*Start the APP_TickTimer to continue the ZCL tasks */
    ZTIMER_eStart(u8TimerTick, ZCL_TICK_TIME);
}
#endif
/****************************************************************************
 *
 * NAME: APP_cbTimerPoll
 *
 * DESCRIPTION:
 * Poll Task for the polling as well it triggers the rejoin in case of pool failure
 * It also manages sleep timing.
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_cbTimerPoll(void *pvParam)
{
    uint32 u32PollPeriod = POLL_TIME;


    if(
#ifdef SLEEP_ENABLE
        !bWaitingToSleep() &&
#endif
        /* Do fast polling when the device is running */
        ((sDeviceDesc.eNodeState == E_RUNNING) || (sDeviceDesc.eNodeState == E_WAIT_STARTUP)))

    {

        if(u16FastPoll)
        {
            u16FastPoll--;
            u32PollPeriod = POLL_TIME_FAST;
            /*Reload the Sleep timer during fast poll*/
#ifdef SLEEP_ENABLE
            vReloadSleepTimers();
#endif
        }
        ZTIMER_eStop(u8TimerPoll);
        ZTIMER_eStart(u8TimerPoll, u32PollPeriod);

        ZPS_teStatus u8PStatus;
        u8PStatus = ZPS_eAplZdoPoll();
        if(u8PStatus)
        {
            DBG_vPrintf(TRACE_SWITCH_NODE, "\nPoll Failed %d\n", u8PStatus);
        }
    }
}

/****************************************************************************
 *
 * NAME: vSetAddress
 *
 * DESCRIPTION:
 *     Set Address Mode for the outgoing commands
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vSetAddress(tsZCL_Address * psAddress, bool_t bBroadcast, uint16 u16ClusterId)
{
    if(bBroadcast)
    {
        DBG_vPrintf(TRACE_SWITCH_NODE, "\r\nBcast");
        psAddress->eAddressMode = E_ZCL_AM_BROADCAST;
        psAddress->uAddress.eBroadcastMode = ZPS_E_APL_AF_BROADCAST_RX_ON;
    }
    else
    {
        /*Get The switch states to decide the address mode to be taken up.*/
        switch(eGetSwitchState())
        {
            case LIGHT_CONTROL_MODE:
                /*By Default chose Group Addressing*/
                DBG_vPrintf(TRACE_SWITCH_NODE, "\nGroup");
                psAddress->eAddressMode = E_ZCL_AM_GROUP;
                psAddress->uAddress.u16DestinationAddress = u16GroupId;
                break;

            case COMMISSIONING_MODE:
            case INDIVIDUAL_CONTROL_MODE:
                DBG_vPrintf(TRACE_SWITCH_NODE, "\nUcastMatch");
                if(sDeviceInfo.sLightInfo[sDeviceInfo.u8Index].u16Address <= 0xFFF8)
                {
                    psAddress->eAddressMode = E_ZCL_AM_SHORT_NO_ACK;
                    psAddress->uAddress.u16DestinationAddress = sDeviceInfo.sLightInfo[sDeviceInfo.u8Index].u16Address;
                    DBG_vPrintf(TRACE_SWITCH_NODE, "\nAddress %d", psAddress->uAddress.u16DestinationAddress);
                }
                else
                {
                    psAddress->eAddressMode = E_ZCL_AM_ENUM_END;
                    psAddress->uAddress.u16DestinationAddress = 0xFFFF;
                }
                break;

            default:
                break;
        }
    }
}

/****************************************************************************
 *
 * NAME: bAddressInTable
 *
 * DESCRIPTION:
 * Checks if an address is already present in the last discovery
 *
 * PARAMETERS:
 * uint16 u16AddressToCheck
 *
 * RETURNS:
 * bool
 *
 ****************************************************************************/
PRIVATE bool bAddressInTable(uint16 u16AddressToCheck)
{
    uint8 i;

    for(i = 0; i < NUMBER_DEVICE_TO_BE_DISCOVERED; i++)
    {
        /* Commented out due to excessive calls */
        if(sDeviceInfo.sLightInfo[i].u16Address == u16AddressToCheck)
        {
            DBG_vPrintf(TRACE_SWITCH_NODE, "\ndup!");
            return TRUE;
        }
    }

    return FALSE;

}

/****************************************************************************
 *
 * NAME: vSelectLight
 *
 * DESCRIPTION:
 * Set the next node to identify
 *
 * PARAMETERS:
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vSelectLight(void)
{
    if(bLightsDiscovered())
    {
        /* Select next node from the list for commissioning */
        if(sDeviceInfo.u8Index > 0)
            sDeviceInfo.u8Index--;
        else
            sDeviceInfo.u8Index = sDeviceInfo.u8Discovered - 1;
        /* Send identify to the selected node */
        vAppIdentify(APP_IDENTIFY_TIME_IN_SECS);
    }
}

/****************************************************************************
 *
 * NAME: vSetIndividualLightInformation
 *
 * DESCRIPTION:
 * Discovery Individual Lights From Find And Bind Table
 *
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vSetIndividualLightInformation(void)
{
    ZPS_tsAplAib * psAplAib;
    uint8 u8BindingTableSize;
    uint16 u16NwkAddressOfInterest = 0;
    psAplAib  = ZPS_psAplAibGetAib();

    if(psAplAib->psAplApsmeAibBindingTable == NULL)
    {
        DBG_vPrintf(TRACE_SWITCH_NODE, "\n No Binding Table");
        return;
    }
    else
    {
        u8BindingTableSize = psAplAib->psAplApsmeAibBindingTable->psAplApsmeBindingTable[0].u32SizeOfBindingTable;
        DBG_vPrintf(TRACE_SWITCH_NODE, "\nBind Size %d",  u8BindingTableSize);
        if(0 == u8BindingTableSize)
        {
            DBG_vPrintf(TRACE_SWITCH_NODE, "\n Binding Table WithOut Any Entry ");
            return;
        }
        else
        {
            uint32 j;
            for(j = 0 ; j < psAplAib->psAplApsmeAibBindingTable->psAplApsmeBindingTable[0].u32SizeOfBindingTable ; j++)
            {
                DBG_vPrintf(TRACE_SWITCH_NODE, "\n Looping Binding Table = %d ", j);
                if(((GENERAL_CLUSTER_ID_ONOFF == psAplAib->psAplApsmeAibBindingTable->psAplApsmeBindingTable[0].pvAplApsmeBindingTableEntryForSpSrcAddr[j].u16ClusterId) ||
                    (GENERAL_CLUSTER_ID_LEVEL_CONTROL == psAplAib->psAplApsmeAibBindingTable->psAplApsmeBindingTable[0].pvAplApsmeBindingTableEntryForSpSrcAddr[j].u16ClusterId)) &&
                   (psAplAib->psAplApsmeAibBindingTable->psAplApsmeBindingTable[0].pvAplApsmeBindingTableEntryForSpSrcAddr[j].u8DstAddrMode == E_ZCL_AM_IEEE))
                {
                    //DBG_vPrintf(TRACE_SWITCH_NODE,"\n Binding Table Entry for Address = %016llx ",psAplAib->psAplApsmeAibBindingTable->psAplApsmeBindingTable[0].pvAplApsmeBindingTableEntryForSpSrcAddr[j].uDstAddress.u64Addr);
                    DBG_vPrintf(TRACE_SWITCH_NODE, "\n Binding Table Entry for Address = %016llx ", ZPS_u64NwkNibGetMappedIeeeAddr(ZPS_pvAplZdoGetNwkHandle(), psAplAib->psAplApsmeAibBindingTable->psAplApsmeBindingTable[0].pvAplApsmeBindingTableEntryForSpSrcAddr[j].u16AddrOrLkUp));
                    //u16NwkAddressOfInterest = ZPS_u16AplZdoLookupAddr(psAplAib->psAplApsmeAibBindingTable->psAplApsmeBindingTable[0].pvAplApsmeBindingTableEntryForSpSrcAddr[j].uDstAddress.u64Addr);
                    u16NwkAddressOfInterest = ZPS_u16AplZdoLookupAddr(ZPS_u64NwkNibGetMappedIeeeAddr(ZPS_pvAplZdoGetNwkHandle(), psAplAib->psAplApsmeAibBindingTable->psAplApsmeBindingTable[0].pvAplApsmeBindingTableEntryForSpSrcAddr[j].u16AddrOrLkUp));
                    if(bAddressInTable(u16NwkAddressOfInterest) == FALSE)
                    {
                        sDeviceInfo.sLightInfo[sDeviceInfo.u8Discovered].u16Address = u16NwkAddressOfInterest;
                        sDeviceInfo.sLightInfo[sDeviceInfo.u8Discovered].u8Ep = psAplAib->psAplApsmeAibBindingTable->psAplApsmeBindingTable[0].pvAplApsmeBindingTableEntryForSpSrcAddr[j].u8DestinationEndPoint;
                        sDeviceInfo.u8Discovered++;
                    }
                }
            }
        }
    }
}

/****************************************************************************
*
* NAME: vAppChangeChannel
*
* DESCRIPTION: This function change the channel randomly to one of the other
* primaries
*
* RETURNS:
* void
*
****************************************************************************/
PUBLIC void vAppChangeChannel(void)
{
    /*Primary channel Set */
    uint8 au8ZHAChannelSet[] = {11, 14, 15, 19, 20, 24, 25};

    ZPS_tsAplZdpMgmtNwkUpdateReq sZdpMgmtNwkUpdateReq;
    PDUM_thAPduInstance hAPduInst;
    ZPS_tuAddress uDstAddr;
    uint8 u8Seq;
    uint8 u8Min = 0, u8Max = 6;
    uint8 u8CurrentChannel, u8RandomNum;

    hAPduInst = PDUM_hAPduAllocateAPduInstance(apduZDP);
    if(hAPduInst != NULL)
    {
        sZdpMgmtNwkUpdateReq.u8ScanDuration = 0xfe;

        u8CurrentChannel = ZPS_u8AplZdoGetRadioChannel();
        u8RandomNum = RND_u32GetRand(u8Min, u8Max);
        if(u8CurrentChannel != au8ZHAChannelSet[u8RandomNum])
        {
            sZdpMgmtNwkUpdateReq.u32ScanChannels = (1 << au8ZHAChannelSet[u8RandomNum]);
        }
        else /* Increment the channel by one rather than spending in RND_u32GetRand */
        {
            /*  For roll over situation */
            if(u8RandomNum == u8Max)
            {
                sZdpMgmtNwkUpdateReq.u32ScanChannels = (1 << au8ZHAChannelSet[u8Min]);
            }
            else
            {
                sZdpMgmtNwkUpdateReq.u32ScanChannels = (1 << au8ZHAChannelSet[u8RandomNum + 1]);
            }
        }

        sZdpMgmtNwkUpdateReq.u8NwkUpdateId = ZPS_psAplZdoGetNib()->sPersist.u8UpdateId + 1;
        uDstAddr.u16Addr = 0xfffd;

        if(0 == ZPS_eAplZdpMgmtNwkUpdateRequest(hAPduInst,
                                                uDstAddr,
                                                FALSE,
                                                &u8Seq,
                                                &sZdpMgmtNwkUpdateReq))
        {
            DBG_vPrintf(TRACE_SWITCH_NODE, "update Id\n");
            /* should really be in stack?? */
            ZPS_psAplZdoGetNib()->sPersist.u8UpdateId++;
        }
    }
}
#ifdef SLEEP_ENABLE
/****************************************************************************
*
* NAME: vReloadSleepTimers
*
* DESCRIPTION:
* reloads boththe timers on identify
*
* RETURNS:
* void
*
****************************************************************************/
PUBLIC void vReloadSleepTimers(void)
{

    vLoadKeepAliveTime(KEEP_ALIVETIME);
#ifdef DEEP_SLEEP_ENABLE
    vLoadDeepSleepTimer(DEEP_SLEEP_TIME);
#endif
}
#endif

/****************************************************************************
 *
 * NAME: app_vRestartNode
 *
 * DESCRIPTION:
 * Start the Restart the ZigBee Stack after a context restore from
 * the EEPROM/Flash
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void app_vRestartNode(void)
{
    uint64 u64MacAddr = *((uint64*)pvAppApiGetMacAddrLocation());

    ZPS_vSaveAllZpsRecords();
    u16GroupId = ((uint16)u64MacAddr) ^ ((uint16)(u64MacAddr >> 16));
    /* Start 1 seconds polling */
    ZTIMER_eStart(u8TimerPoll, POLL_TIME);
}


/****************************************************************************
 *
 * NAME: app_vStartNodeFactoryNew
 *
 * DESCRIPTION:
 * Start the ZigBee Stack for the first ever Time.
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void app_vStartNodeFactoryNew(void)
{
    /* Stay awake for joining */
    DBG_vPrintf(TRACE_SWITCH_NODE, "app_vStartNodeFactoryNew: eNodeState = E_STARTUP\n");
    sDeviceDesc.eNodeState = E_STARTUP;
}


/****************************************************************************
 *
 * NAME: APP_SleepTask
 *
 * DESCRIPTION:
 * Task activated by the wake up event to manage sleep
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_vSleepTask(void)
{
#ifdef SLEEP_ENABLE
    DBG_vPrintf(TRACE_SWITCH_NODE, "\nWoken: start poll timer,");
#endif
}

#ifdef CLD_OTA
/****************************************************************************
 *
 * NAME: eGetNodeState
 *
 * DESCRIPTION:
 * returns the device state
 *
 * RETURNS:
 * teNODE_STATES
 *
 ****************************************************************************/
PUBLIC teNODE_STATES eGetNodeState(void)
{
    return sDeviceDesc.eNodeState;
}

/****************************************************************************
 *
 * NAME: sGetOTACallBackPersistdata
 *
 * DESCRIPTION:
 * returns a copy to the OTA persistent data from the device structure.
 *
 * RETURNS:
 * tsOTA_PersistedData
 *
 ****************************************************************************/
PUBLIC tsOTA_PersistedData sGetOTACallBackPersistdata(void)
{
    return sSwitch.sCLD_OTA_CustomDataStruct.sOTACallBackMessage.sPersistedData;
}
#endif

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
PUBLIC void APP_vFactoryResetRecords(void)
{
    /* clear out the stack */
    ZPS_vDefaultStack();
    ZPS_vSetKeys();
    ZPS_eAplAibSetApsUseExtendedPanId(0);

    /* clear out the application */
    DBG_vPrintf(TRACE_SWITCH_NODE, "vFactoryResetRecords: eNodeState = E_STARTUP\n");
    sDeviceDesc.eNodeState = E_STARTUP;
    memset(&sDeviceInfo, 0, sizeof(tsDeviceInfo));

#ifdef CLD_OTA
    vOTAResetPersist();
#endif

    /* save everything */
    PDM_eSaveRecordData(PDM_ID_APP_ZLO_SWITCH,
                        &sDeviceDesc,
                        sizeof(tsDeviceDesc));
    ZPS_vSaveAllZpsRecords();
}

PUBLIC void APP_cbTimerLedBlinks(void *pvParam)
{
    ledVset_t *param = (ledVset_t *)pvParam;

    if(param->times > 0)
    {
        if(param->type == 0)
        {
            param->type = 1;
            APP_vSetLED(LED1, 1);
            if(param->duty > 100)
            {
                param->duty = 100;
            }
            ZTIMER_eStart(u8TimerLedBlinks, ((uint32)param->duty * (uint32)param->period) / 100);
        }
        else if(param->type == 1)
        {
            param->times--;
            param->type = 0;
            APP_vSetLED(LED1, 0);
            ZTIMER_eStart(u8TimerLedBlinks, ((100 - param->duty) * (uint32)param->period) / 100);
        }
    }

    if(param->times == 0)
    {
        if(param->cb)
        {
            pTimerExpireCallback cbk = (pTimerExpireCallback)param->cb;
            cbk(pvParam);
        }
    }
}

PRIVATE void vAppEnterDeepSleepMode(void)
{
    // Go to deep sleep
#ifdef SLEEP_ENABLE
    vLoadKeepAliveTime(0);
#ifdef DEEP_SLEEP_ENABLE
    vLoadDeepSleepTimer(0);
    vUpdateKeepAliveTimer();
#endif
#endif
}


/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

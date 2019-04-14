/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          zha_switch_node.c
 *
 * DESCRIPTION:        ZHA Demo : Stack <-> Switch App Interaction
 *                     (Implementation)
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

#include <jendefs.h>
#include <appapi.h>
#include "os.h"
#include "os_gen.h"
#include "pdum_apl.h"
#include "pdum_gen.h"
#include "pdm.h"
#include "dbg.h"
#include "dbg_uart.h"
#include "pwrm.h"
#include "zps_gen.h"
#include "zps_apl_af.h"
#include "zps_apl_zdo.h"
#include "zps_apl_aib.h"
#include "zps_apl_zdp.h"
#include "rnd_pub.h"

#include "app_common.h"
#include "groups.h"

#include "PDM_IDs.h"

#include "app_timer_driver.h"
#include "zha_switch_node.h"

#include "app_zcl_switch_task.h"
#include "app_zbp_utilities.h"

#include "app_events.h"
#include "zcl_customcommand.h"
#include "app_buttons.h"
#include "GenericBoard.h"
#include "ha.h"

#include "haEzJoin.h"
#include "haEzFindAndBind.h"
#include "app_switch_state_machine.h"
#include "zcl_common.h"
#ifdef CLD_OTA
    #include "OTA.h"
    #include "app_ota_client.h"
#else
    #include "haKeys.h"
#endif

#include "PingParent.h"
#include "appZdpExtraction.h"
#include "Scenes.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifdef DEBUG_SWITCH_NODE
    #define TRACE_SWITCH_NODE   TRUE
#else
    #define TRACE_SWITCH_NODE   FALSE
#endif


#ifndef DEBUG_CIRCULAR_ROUTE
    #define TRACE_CIRCULAR_ROUTE FALSE
#else
    #define TRACE_CIRCULAR_ROUTE TRUE
#endif

#define bWakeUpFromSleep() bWatingToSleep()  /* For readability purpose */

#define APP_LONG_SLEEP_DURATION_IN_SEC (60*120)			//120 minutes
#define MAX_REJOIN_TIME (60*12)  /* 12 minutes */
#define BACK_OFF_TIME   (60*15)  /* 15 minutes */
#define LONG_PRESS_TIMEOUT				(5000)

#define LED1  (1 << 1)
#define LED2  (1)


#define ZHA_MAX_REJOIN_ATTEMPTS 10

#define MAX_SERVICE_DISCOVERY   3

#define APP_MATCH_DESCRIPTOR_RESPONSE   0x8006

#define SIX_SECONDS                     6
#define SIX_SECONDS_IN_MILLISECONDS     6000
#define ONE_SECOND                      1

#define START_TO_IDENTIFY               3
#define START_TO_IDENTIFY_IN_MS         (START_TO_IDENTIFY*1000)

#define SEND_FIRST_DISCOVERY            0
#define SEND_NEXT_DISCOVERY             1
#define DISCOVERY_COMPLETE              2
#define IDENTIFY_TIME                   5

PUBLIC uint8 groupId=1;

extern const uint8 u8MyEndpoint;

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/


/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
PRIVATE void vStopAllTimers(void);
PRIVATE void vStopTimer(OS_thSWTimer hSwTimer);
#ifdef SLEEP_ENABLE
    PRIVATE void vLoadKeepAliveTime(uint8 u8TimeInSec);
    #ifdef DEEP_SLEEP_ENABLE
        PRIVATE void vActionOnButtonActivationAfterDeepSleep(void);
    #endif
#endif
PRIVATE void APP_vInitLeds(void);
PRIVATE void vSetAddress(tsZCL_Address * psAddress, bool_t bBroadcast, uint16 u16ClusterId);

PRIVATE void vSendMatchDesc( uint16);

PRIVATE bool bAddressInTable( uint16 u16AddressToCheck );
PRIVATE void vClearMatchDescriptorDiscovery( void );
PRIVATE void vHandleAppEvent( APP_tsEvent sAppEvent );
PRIVATE void vDeletePDMOnButtonPress();

PRIVATE bool bIsValidBindingExsisting(uint16 u16ClusterId);
PRIVATE void vStopStartCommissionTimer( uint32 u32Ticks );
PRIVATE void vHandleMatchResponses( ZPS_tsAfEvent sStackEvent );
PRIVATE void vHandleJoinAndRejoinNWK( ZPS_tsAfEvent *pZPSevent,teEZ_JoinAction eJoinAction  );
PRIVATE void app_vRestartNode (void);
PRIVATE void app_vStartNodeFactoryNew(void);
PRIVATE bool_t bHandleZdoLeaveRequest(uint8 u8Action, uint64 u64TargetAddr, uint8 u8Flags);
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

PUBLIC PDM_tsRecordDescriptor   sDevicePDDesc;
PUBLIC tsDeviceDesc             sDeviceDesc;
PUBLIC uint16                   u16GroupId;

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
PUBLIC tsDeviceState sDeviceState;

PRIVATE uint8 u8CommState;

PRIVATE uint16 u16FastPoll;

#ifdef SLEEP_ENABLE
    PRIVATE bool bDataPending=FALSE;
    #ifdef DEEP_SLEEP_ENABLE
        PRIVATE uint8 u8DeepSleepTime= DEEP_SLEEP_TIME;
    #endif
    PRIVATE uint8 u8KeepAliveTime = KEEP_ALIVETIME;
    PRIVATE pwrm_tsWakeTimerEvent    sWake;
#endif


//#define APP_IGNORE_LEAVE_WITHOUT_REJOIN

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC void vForceDeviceDeepSleep()
{
	vStartStopTimer( APP_JoinTimer, APP_TIME_MS(500),(uint8*)&(sDeviceDesc.eNodeState),E_STARTUP );
}

PUBLIC void vForceDeviceDeepSleepEx()
{
	DBG_vPrintf(TRACE_SWITCH_NODE, "Go to deep sleep default\n");
	/*It is OK to force a deep sleep by finishing activities when we intent to enter the deep sleep*/
	while (PWRM_u16GetActivityCount()) 
			PWRM_eFinishActivity();
	PWRM_vInit(E_AHI_SLEEP_DEEP);
}

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
    DBG_vPrintf(TRACE_SWITCH_NODE, "\nAPP_vInitialiseNode*");

    APP_vInitLeds();

#ifdef DEEP_SLEEP_ENABLE
    vReloadSleepTimers();
#endif
    /*Initialise the application buttons*/
    /* Initialise buttons; if a button is held down as the device is reset, delete the device
     * context from flash
     */
    APP_bButtonInitialise();

    /*In case of a deep sleep device any button wake up would cause a PDM delete , only check for DIO8
     * pressed for deleting the context */
    //vDeletePDMOnButtonPress();

    #ifdef CLD_OTA
        vLoadOTAPersistedData();
    #endif

    /* Restore any application data previously saved to flash */
    uint16 u16ByteRead;
    PDM_eReadDataFromRecord(PDM_ID_APP_REMOTE_CONTROL,
                            &sDeviceDesc,
                            sizeof(tsDeviceDesc),
                            &u16ByteRead);

    DBG_vPrintf(TRACE_SWITCH_NODE, "Restore Device state eNodeState=%d eNodePrevState=%d\n",sDeviceDesc.eNodeState,sDeviceDesc.eNodePrevState);

    /* Initialise ZBPro stack */
    ZPS_vAplSecSetInitialSecurityState(ZPS_ZDO_PRECONFIGURED_LINK_KEY, (uint8 *)&s_au8LnkKeyArray, 0x00, ZPS_APS_GLOBAL_LINK_KEY);
    DBG_vPrintf(TRACE_SWITCH_NODE, "Set Sec state\n");

    vEZ_RestoreDefaultAIBChMask();
    /* Initialize ZBPro stack */
    ZPS_eAplAfInit();

    DBG_vPrintf(TRACE_SWITCH_NODE, "ZPS_eAplAfInit\n");
    /*Set Save default channel mask as it is going to be manipulated */
    vEZ_SetDefaultAIBChMask();

    APP_ZCL_vInitialise();

    /* If the device state has been restored from flash, re-start the stack
     * and set the application running again.
     */
    if (sDeviceDesc.eNodeState == E_RUNNING || ZPS_psAplAibGetAib()->u64ApsUseExtendedPanid != 0)
    {
        /*The following Patch ensures the device will set the address allocate flag will set to FALSE during rejoin in future*/
        void* pvNwk;
        pvNwk = ZPS_pvAplZdoGetNwkHandle();
        ZPS_psNwkNibGetHandle( pvNwk)->sPersist.u8CapabilityInformation &= 0x7f;
        DBG_vPrintf(TRACE_SWITCH_NODE,"\nThe sNib.sPersist.u8CapabilityInformation = %02x",ZPS_psNwkNibGetHandle( pvNwk)->sPersist.u8CapabilityInformation);

        //read groupId
        PDM_eReadDataFromRecord(PDM_ID_DEVICE_SWITCH_GROUPID, &groupId, sizeof(groupId), &u16ByteRead);

        app_vRestartNode();
    }
    else
    {
        app_vStartNodeFactoryNew();
    }

    #ifdef PDM_EEPROM
        vDisplayPDMUsage();
    #endif

#ifdef CLD_OTA
    vAppInitOTA();
#endif

       /* Register callback that will handle ZDP (mgmt) leave requests */
       ZPS_vAplZdoRegisterZdoLeaveActionCallback(bHandleZdoLeaveRequest);

    OS_eActivateTask(APP_ZHA_Switch_Task);
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
    if(sDeviceState.u8Discovered > 0)
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
    u16FastPoll = 10*u8Seconds;
}

/****************************************************************************
 *
 * NAME: APP_ZHA_Switch_Task
 *
 * DESCRIPTION:
 * Task that handles the application related functionality
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
OS_TASK(APP_ZHA_Switch_Task)
{
    APP_tsEvent sAppEvent;
    ZPS_tsAfEvent sStackEvent;
    sStackEvent.eType = ZPS_EVENT_NONE;
    sAppEvent.eType = APP_E_EVENT_NONE;
    if( OS_eGetSWTimerStatus(App_KeyLongPressTimer) == OS_E_SWTIMER_EXPIRED )
    {
    	//timer callback
    	DBG_vPrintf(TRACE_SWITCH_NODE,"\n\nLeave network and restore FACTORY NEW\n\n");
		ZPS_eAplZdoLeaveNetwork(0,FALSE,FALSE);
		sDeviceDesc.eNodeState = E_LEAVE_WAIT;
		PDM_vDeleteAllDataRecords();
		vAHI_SwReset();
    }
    /*Collect the application events*/
    else if (OS_eCollectMessage(APP_msgEvents, &sAppEvent) == OS_E_OK)
    {

    }
    /*Collect stack Events */
    else if ( OS_eCollectMessage(APP_msgZpsEvents, &sStackEvent) == OS_E_OK)
    {

        if(sStackEvent.eType == ZPS_EVENT_ERROR)
        {
            DBG_vPrintf(TRACE_SWITCH_NODE,"\n\n------------ZPS_EVENT_ERROR START-----------\n");
            DBG_vPrintf(TRACE_SWITCH_NODE,"sStackEvent.uEvent.sAfErrorEvent.eError= 0x%04x\n",sStackEvent.uEvent.sAfErrorEvent.eError);
            DBG_vPrintf(TRACE_SWITCH_NODE,"sStackEvent.uEvent.sAfErrorEvent.uErrorData.sAfErrorApdu.hAPdu= 0x%08x\n",sStackEvent.uEvent.sAfErrorEvent.uErrorData.sAfErrorApdu.hAPdu);
            DBG_vPrintf(TRACE_SWITCH_NODE,"sStackEvent.uEvent.sAfErrorEvent.uErrorData.sAfErrorApdu.u16ClusterId = 0x04x\n",sStackEvent.uEvent.sAfErrorEvent.uErrorData.sAfErrorApdu.u16ClusterId);
            DBG_vPrintf(TRACE_SWITCH_NODE,"sStackEvent.uEvent.sAfErrorEvent.uErrorData.sAfErrorApdu.u16DataSize = 0x%04x\n",sStackEvent.uEvent.sAfErrorEvent.uErrorData.sAfErrorApdu.u16DataSize);
            DBG_vPrintf(TRACE_SWITCH_NODE,"sStackEvent.uEvent.sAfErrorEvent.uErrorData.sAfErrorApdu.u16ProfileId= 0x%04x\n",sStackEvent.uEvent.sAfErrorEvent.uErrorData.sAfErrorApdu.u16ProfileId);
            DBG_vPrintf(TRACE_SWITCH_NODE,"sStackEvent.uEvent.sAfErrorEvent.uErrorData.sAfErrorApdu.u8DstEndpoint = 0x%02x\n",sStackEvent.uEvent.sAfErrorEvent.uErrorData.sAfErrorApdu.u8DstEndpoint);
            DBG_vPrintf(TRACE_SWITCH_NODE,"sStackEvent.uEvent.sAfErrorEvent.uErrorData.sAfErrorApdu.u8SrcAddrMode = 0x%02x\n",sStackEvent.uEvent.sAfErrorEvent.uErrorData.sAfErrorApdu.u8SrcAddrMode);
            DBG_vPrintf(TRACE_SWITCH_NODE,"sStackEvent.uEvent.sAfErrorEvent.uErrorData.sAfErrorApdu.u8SrcEndpoint = 0x%02x\n",sStackEvent.uEvent.sAfErrorEvent.uErrorData.sAfErrorApdu.u8SrcEndpoint);

            DBG_vPrintf(TRACE_SWITCH_NODE,"sStackEvent.uEvent.sAfErrorEvent.uErrorData.sAfErrorOsMessageOverrun.hMessage= 0x%08x\n",sStackEvent.uEvent.sAfErrorEvent.uErrorData.sAfErrorOsMessageOverrun.hMessage);
            DBG_vPrintf(TRACE_SWITCH_NODE,"\n------------ZPS_EVENT_ERROR   END-----------\n\n");
        }


        #ifdef DEBUG_SWITCH_NODE
            vDisplayStackEvent(sStackEvent);
        #endif


        vPingRecv(&sStackEvent);
    }


    /* Handle events depending on node state */
    switch (sDeviceDesc.eNodeState)
    {
        case E_STARTUP:
            vHandleJoinAndRejoinNWK(&sStackEvent,E_EZ_JOIN);
            vHandleAppEvent( sAppEvent );
            break;

        case E_REJOINING:
            vHandleJoinAndRejoinNWK(&sStackEvent,E_EZ_REJOIN);
            DBG_vPrintf(TRACE_SWITCH_NODE, "In E_REJOIN - Kick off Tick Timer \n");
            OS_eStartSWTimer(APP_TickTimer, ZCL_TICK_TIME, NULL);
            vHandleAppEvent( sAppEvent );
            break;

        case E_RUNNING:
            DBG_vPrintf(TRACE_SWITCH_NODE, "E_RUNNING\r\n");
            if (sStackEvent.eType == ZPS_EVENT_NWK_FAILED_TO_JOIN)
            {
                DBG_vPrintf(TRACE_SWITCH_NODE, "Start join failed tmr 1000\n");
                vStopAllTimers();
                OS_eStartSWTimer(APP_TickTimer, ZCL_TICK_TIME, NULL);
                vStartStopTimer( APP_JoinTimer, APP_TIME_MS(1000),(uint8*)&(sDeviceDesc.eNodeState),E_REJOINING );
                DBG_vPrintf(TRACE_SWITCH_NODE, "failed join running %02x\n",sStackEvent.uEvent.sNwkJoinFailedEvent.u8Status );
            }
            else if((ZPS_EVENT_APS_DATA_INDICATION == sStackEvent.eType) &&
                    (0 == sStackEvent.uEvent.sApsDataIndEvent.u8DstEndpoint))
            {
                vHandleMatchResponses(sStackEvent);
                #ifdef CLD_OTA
                    vHandleZDPReqResForOTA(&sStackEvent);
                #endif
            }

            /* Mgmt Leave Received */
            else if(  ZPS_EVENT_NWK_LEAVE_INDICATION == sStackEvent.eType  )
            {
                DBG_vPrintf(TRACE_SWITCH_NODE, "ZDO Leave\n" );
                if( sStackEvent.uEvent.sNwkLeaveIndicationEvent.u64ExtAddr == 0 )
                {
                    DBG_vPrintf(TRACE_SWITCH_NODE, "ZDO Leave\n" );
                    PDM_vDeleteAllDataRecords();
                    vAHI_SwReset();
                }
            }

            #ifdef SLEEP_ENABLE
                else if (ZPS_EVENT_NWK_POLL_CONFIRM == sStackEvent.eType)
                {
                    if (MAC_ENUM_SUCCESS == sStackEvent.uEvent.sNwkPollConfirmEvent.u8Status)
                    {
                        bDataPending = TRUE;
                    }
                    else if (MAC_ENUM_NO_DATA == sStackEvent.uEvent.sNwkPollConfirmEvent.u8Status)
                    {
                        bDataPending = FALSE;
                    }
                }
            #endif
            vHandleAppEvent( sAppEvent );
            vEZ_EZModeNWKFindAndBindHandler(&sStackEvent);
            break;
        default:
            break;
    }

    /*
     * Global clean up to make sure any PDUs have been freed
     */
    if (sStackEvent.eType == ZPS_EVENT_APS_DATA_INDICATION)
    {
        PDUM_eAPduFreeAPduInstance(sStackEvent.uEvent.sApsDataIndEvent.hAPduInst);
    }
}
/****************************************************************************
 *
 * NAME: bHandleZdoLeaveRequest
 *
 * DESCRIPTION:
 * Callback that will handle ZDP (mgmt) leave requests
 *
 * RETURNS:
 * None
 *
 ****************************************************************************/
PRIVATE bool_t bHandleZdoLeaveRequest(uint8 u8Action, uint64 u64TargetAddr, uint8 u8Flags)
{
    DBG_vPrintf(TRACE_SWITCH_NODE, "\n%s - Addr: 0x%016llx, Action: 0x%02x Flags: 0x%02x\n", __FUNCTION__, u64TargetAddr, u8Action, u8Flags);

    /* Set function to use stack leave as default return */
    bool_t bUse_Stack_Leave=TRUE;

    /* We respond to all leave commands so Mgmt, remove and NLME leave */
    if ((ZPS_LEAVE_ORIGIN_MGMT_LEAVE == u8Action) || (ZPS_LEAVE_ORIGIN_REMOVE_DEVICE == u8Action) || (ZPS_LEAVE_ORIGIN_NLME == u8Action))
    {
        /*No Rejoin just leave, reset and go to factory new state
         *              MGMT flags                    Remove flag                  nlme flags         */
        if ((0 == u8Flags) || (2 == u8Flags) || (0x80 == u8Flags) || (0xC0 == u8Flags) || (0x40 == u8Flags))
        {
        /* Define to ignore stack do not rejoin else use stack functionality */
        #ifdef APP_IGNORE_LEAVE_WITHOUT_REJOIN
            DBG_vPrintf(TRACE_SWITCH_NODE, "Set the state to Rejoining \n\n");
            sDeviceDesc.eNodeState = E_REJOINING;
            /* Leave the network and children but rejoin */
            ZPS_eAplZdoLeaveNetwork(0,TRUE,TRUE);
            bUse_Stack_Leave=FALSE;
        #else
            /* Wait for ZPS_EVENT_NWK_LEAVE_CONFIRM event which will
               confirm the responses have gone out then erase PDM and
               reset. */
            DBG_vPrintf(TRACE_SWITCH_NODE, "Set the state to leave \n\n");
            sDeviceDesc.eNodeState = E_LEAVE_WAIT;
        #endif
        }
        else
            /* Leave with Rejoin - The stack will attempt once and
              * if it can not it would bring it back to rejoin state machine
              * to take it further.
              * */
        {
            DBG_vPrintf(TRACE_SWITCH_NODE, "Set the state to Rejoining \n\n");
            sDeviceDesc.eNodeState = E_REJOINING;

        }
    }
    return bUse_Stack_Leave;
}

/****************************************************************************
 *
 * NAME: vHandleJoinAndRejoinNWK
 *
 * DESCRIPTION:
 * Handles the Start UP events
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vHandleJoinAndRejoinNWK( ZPS_tsAfEvent *pZPSevent,teEZ_JoinAction eJoinAction  )
{
    teEZ_State ezState;
    /*Call The EZ mode Handler passing the events*/
    vEZ_EZModeNWKJoinHandler(pZPSevent,eJoinAction);
    ezState = eEZ_GetJoinState();
    DBG_vPrintf(TRACE_SWITCH_NODE, "EZ_STATE=\%d\n", ezState);
    if(ezState == E_EZ_DEVICE_IN_NETWORK)
    {
        /*The following Patch ensures the device will set the address allocate flag will set to FALSE during rejoin in future*/
        void* pvNwk;
        pvNwk = ZPS_pvAplZdoGetNwkHandle();
        ZPS_psNwkNibGetHandle( pvNwk)->sPersist.u8CapabilityInformation &= 0x7f;
        DBG_vPrintf(TRACE_SWITCH_NODE,"\nThe sNib.sPersist.u8CapabilityInformation = %02x",ZPS_psNwkNibGetHandle( pvNwk)->sPersist.u8CapabilityInformation);

        DBG_vPrintf(TRACE_SWITCH_NODE, "HA EZMode EVT: E_EZ_DEVICE_IN_NETWORK \n");
        vStartStopTimer( APP_JoinTimer, APP_TIME_MS(500),(uint8*)&(sDeviceDesc.eNodeState),E_RUNNING );
        u16GroupId=ZPS_u16AplZdoGetNwkAddr();
        PDM_eSaveRecordData(PDM_ID_APP_REMOTE_CONTROL,
                                &sDeviceDesc,
                                sizeof(tsDeviceDesc));
        ZPS_vSaveAllZpsRecords();
        /* Start 1 seconds polling */
        OS_eStartSWTimer(APP_PollTimer, POLL_TIME, NULL);
        OS_eStartSWTimer(APP_TickTimer, ZCL_TICK_TIME, NULL);
    }
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

    if ( 0 == (u32DIOState & JOIN_BUTTON) )
    {
        sButton.uEvent.sButton.u8Button=COMM_BUTTON_PRESSED;
        sButton.eType = APP_E_EVENT_BUTTON_DOWN;
    }
    else if ( 0 == (u32DIOState & FUNC_SW) )
    {
        sButton.uEvent.sButton.u8Button=ON_PRESSED;
        sButton.eType = APP_E_EVENT_BUTTON_DOWN;
    }

    vApp_ProcessKeyCombination(sButton);

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
    if (0==u8DeepSleepTime)
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
    uint8 a;
    u8KeepAliveTime=u8TimeInSec;
    vStartStopTimer(APP_PollTimer,POLL_TIME, &a,a);
    vStartStopTimer(APP_TickTimer, ZCL_TICK_TIME, &a,a);
    if(sDeviceDesc.eNodeState == E_REJOINING)
        vStartStopTimer( APP_JoinTimer, APP_TIME_MS(1000),(uint8*)&(sDeviceDesc.eNodeState),E_REJOINING );
}

/****************************************************************************
 *
 * NAME: bWatingToSleep
 *
 * DESCRIPTION:
 * Gets the status if the module is waiting for sleep.
 *
 * RETURNS:
 * bool
 *
 ****************************************************************************/
PUBLIC bool bWatingToSleep(void)
{
    if (0 == u8KeepAliveTime)
        return TRUE;
    else
        return FALSE;
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

    if( (eSwitchState == LIGHT_CONTROL_MODE ) || (eSwitchState == INDIVIDUAL_CONTROL_MODE ) )
    {
        if( u8KeepAliveTime > 0 )
        {
            u8KeepAliveTime--;
            DBG_vPrintf(TRACE_SWITCH_NODE,"\n KeepAliveTime = %d \n",u8KeepAliveTime);
        }
        else
        {
            vStopAllTimers();
            DBG_vPrintf(TRACE_SWITCH_NODE,"\n Activity %d, KeepAliveTime = %d \n",PWRM_u16GetActivityCount(),u8KeepAliveTime);

            #ifdef DEEP_SLEEP_ENABLE
                if(u8DeepSleepTime > 0 )
                {
                    u8DeepSleepTime--;
                    /* The activity counter seems to be still greater than 0 - Go back to be awake, Try again in the next sleep time*/
                    if(PWRM_u16GetActivityCount())
                    {
                        DBG_vPrintf(TRACE_SWITCH_NODE,"\n Abort Sleep - Reload timers\n");
                        vReloadSleepTimers();
                    }
                    else
                    {
                        PWRM_teStatus eStatus = PWRM_eScheduleActivity(&sWake, APP_LONG_SLEEP_DURATION_IN_SEC*32000 , vWakeCallBack);
                        DBG_vPrintf(TRACE_SWITCH_NODE,"\nSleep Status = %d, u8DeepSleepTime = %d \n",eStatus,u8DeepSleepTime);
                    }
                }
                else
                {
                    /*It is OK to force a deep sleep by finishing activities when we intent to enter the deep sleep*/
                    vForceDeviceDeepSleepEx();
                }
            #else
            		if(ZPS_psAplAibGetAib()->u64ApsUseExtendedPanid != 0)
            		{
	                /* The activity counter seems to be still greater than 0 - Go back to be awake, Try again in the next sleep time*/
	                if(PWRM_u16GetActivityCount())
	                {
	                    vReloadSleepTimers();
	                }
	                else
	                {
	                    /* The activity counter is 0 so a sleep with ram on can be scheduled*/
	                    PWRM_teStatus eStatus = PWRM_eScheduleActivity(&sWake, APP_LONG_SLEEP_DURATION_IN_SEC*32000 , vWakeCallBack);
	                    DBG_vPrintf(TRACE_SWITCH_NODE,"\nSleep Status = %d\n",eStatus);
	                }
                }else{
                	DBG_vPrintf(TRACE_SWITCH_NODE,"Not joined network\n");
									vForceDeviceDeepSleepEx();
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
PRIVATE void vDeletePDMOnButtonPress()
{
    bool_t bDeleteRecords = FALSE;
    uint32 u32Buttons = u32AHI_DioReadInput() & (JOIN_BUTTON);
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
     * Alternatively, always call PDM_vDelete() if context saving is not required.
     */
    if(bDeleteRecords)
    {
        DBG_vPrintf(TRACE_SWITCH_NODE,"Deleting the PDM\n");
        PDM_vDeleteAllDataRecords();
    }
}

/****************************************************************************
 *
 * NAME: vHandleAppEvent
 *
 * DESCRIPTION:
 * Function to handle the app event - buttons
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vHandleAppEvent( APP_tsEvent sAppEvent )
{
	static uint8 flag=FALSE;
#if 0
    switch(sAppEvent.eType)
    {
        case APP_E_EVENT_BUTTON_DOWN:
        case APP_E_EVENT_BUTTON_UP:

            vApp_ProcessKeyCombination(sAppEvent);
            #ifdef SLEEP_ENABLE
                vReloadSleepTimers();
            #endif
            /*Reset the channel mask to last used so that the
             * rejoining joining will be attempted
             * */
            if(sDeviceDesc.eNodeState == E_REJOINING )
            {
                vEZ_ReJoin();
            }
        break;
        default:
        break;
    }
#endif
		// TODO: reset factory pressed long time
		if(sAppEvent.eType == APP_E_EVENT_BUTTON_DOWN && sAppEvent.uEvent.sButton.u8Button == APP_E_BUTTONS_BUTTON_1)
		{		
			if(ZPS_psAplAibGetAib()->u64ApsUseExtendedPanid != 0)
			{
				DBG_vPrintf(TRACE_SWITCH_NODE,"We have been in network\n");
				//long pressed
				if( OS_eGetSWTimerStatus(App_KeyLongPressTimer) != OS_E_SWTIMER_STOPPED )
				{
					OS_eStopSWTimer(App_KeyLongPressTimer);
				}
				OS_eStartSWTimer(App_KeyLongPressTimer, APP_TIME_MS(LONG_PRESS_TIMEOUT), NULL );
			}else{
				DBG_vPrintf(TRACE_SWITCH_NODE,"Start Joing\n");
				vStartStopTimer( APP_JoinTimer, APP_TIME_MS(500),(uint8*)&(sDeviceDesc.eNodeState),E_STARTUP );				
			}
		}else if(sAppEvent.eType == APP_E_EVENT_BUTTON_UP && sAppEvent.uEvent.sButton.u8Button == APP_E_BUTTONS_BUTTON_1)
		{
			//released
			if(ZPS_psAplAibGetAib()->u64ApsUseExtendedPanid != 0)
			{
				OS_teStatus status=OS_eGetSWTimerStatus(App_KeyLongPressTimer);
				if(status != OS_E_SWTIMER_STOPPED || status != OS_E_SWTIMER_EXPIRED )
				{
					DBG_vPrintf(TRACE_SWITCH_NODE,"Stop Long press timer\n");
					OS_eStopSWTimer(App_KeyLongPressTimer);
				}
			}
		}else if(sDeviceDesc.eNodeState == E_RUNNING && sAppEvent.eType == APP_E_EVENT_BUTTON_DOWN && sAppEvent.uEvent.sButton.u8Button == APP_E_BUTTONS_BUTTON_SW1)
		{
			teZCL_Status status;

			if(!flag)
			{
				flag=TRUE;
			}else{
				flag=FALSE;
			}
			
			if(flag)
			{
				//scene 1
				uint8 u8Seq;
				tsZCL_Address sDestinationAddress;
				tsCLD_ScenesRecallSceneRequestPayload payLoad;
				sDestinationAddress.eAddressMode=E_ZCL_AM_GROUP;
				sDestinationAddress.uAddress.u16GroupAddress=groupId;
			
				payLoad.u16GroupId=groupId;
				payLoad.u8SceneId=1;
				status=eCLD_ScenesCommandRecallSceneRequestSend(DIMMERSWITCH_SWITCH_ENDPOINT,DIMMERSWITCH_SWITCH_ENDPOINT,&sDestinationAddress,&u8Seq,&payLoad);
				DBG_vPrintf(TRACE_SWITCH_NODE,"Recall scene 1 =%d\n",status);
			}else{
				//scene 2
				uint8 u8Seq;
				tsZCL_Address sDestinationAddress;
				tsCLD_ScenesRecallSceneRequestPayload payLoad;
				sDestinationAddress.eAddressMode=E_ZCL_AM_GROUP;
				sDestinationAddress.uAddress.u16GroupAddress=groupId;
			
				payLoad.u16GroupId=groupId;
				payLoad.u8SceneId=2;
				status=eCLD_ScenesCommandRecallSceneRequestSend(DIMMERSWITCH_SWITCH_ENDPOINT,DIMMERSWITCH_SWITCH_ENDPOINT,&sDestinationAddress,&u8Seq,&payLoad);
				DBG_vPrintf(TRACE_SWITCH_NODE,"Recall scene 0 =%d\n",status);
			}
		}
}
/****************************************************************************
 *
 * NAME: vHandleMatchResponses
 *
 * DESCRIPTION:
 * Function to handle the match descriptor responses and add to the table
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vHandleMatchResponses( ZPS_tsAfEvent sStackEvent )
{
    ZPS_tsAfZdpEvent sAfZdpEvent;
    zps_bAplZdpUnpackResponse(&sStackEvent, &sAfZdpEvent);

    if (ZPS_ZDP_MATCH_DESC_RSP_CLUSTER_ID == sAfZdpEvent.u16ClusterId)
    {
        if( (sAfZdpEvent.uZdpData.sMatchDescRsp.u8Status == ZPS_E_SUCCESS) &&
                (ZPS_u16AplZdoGetNwkAddr() != sAfZdpEvent.uZdpData.sMatchDescRsp.u16NwkAddrOfInterest ))
        {
            DBG_vPrintf(TRACE_SWITCH_NODE, "\nMatch SA %04x Ep %d\n",
                    sAfZdpEvent.uZdpData.sMatchDescRsp.u16NwkAddrOfInterest,
                    sAfZdpEvent.uLists.au8Data[0]);

            if (sAfZdpEvent.uZdpData.sMatchDescRsp.u8MatchLength > 0)
            {
                /*Collect the response in the structure */
                if ( sDeviceState.u8Index < NUMBER_DEVICE_TO_BE_DISCOVERED)
                {

                    DBG_vPrintf(TRACE_SWITCH_NODE, "\nBefore ADDCHK discoverd %04x at Index %d\n", sDeviceState.u8Discovered,sDeviceState.u8Index);


                       if( (sAfZdpEvent.uZdpData.sMatchDescRsp.u16NwkAddrOfInterest <= 0xFFF8) &&
                           (!bAddressInTable(sAfZdpEvent.uZdpData.sMatchDescRsp.u16NwkAddrOfInterest)))
                       {
                            DBG_vPrintf(TRACE_SWITCH_NODE, "\nSave %04x at Index %d\n", sAfZdpEvent.uZdpData.sMatchDescRsp.u16NwkAddrOfInterest,
                            sDeviceState.u8Index);

                            sDeviceState.sMatchDev[sDeviceState.u8Index].u16Address = sAfZdpEvent.uZdpData.sMatchDescRsp.u16NwkAddrOfInterest;
                            sDeviceState.sMatchDev[sDeviceState.u8Index].u8Ep = sAfZdpEvent.uLists.au8Data[0];
                            sDeviceState.u8Index++;
                            sDeviceState.u8Discovered++;
                       }


                } else {
                    DBG_vPrintf(TRACE_SWITCH_NODE, "\nLiight Table Full\n");
                }
            }
            else
            {
                DBG_vPrintf(TRACE_SWITCH_NODE, "Empty match list\n");
            }
        }
    }
}

/****************************************************************************
 *
 * NAME: APP_CommissionTimerTask
 *
 *
 * DESCRIPTION:
 * Handles the commissioning state machine
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
OS_TASK(APP_CommissionTimerTask)
{
    static uint8 u8NumberOfDiscoveries = 0;

    switch (u8CommState)
    {
        case SEND_FIRST_DISCOVERY:
            DBG_vPrintf(TRACE_SWITCH_NODE,"\nSEND_FIRST_DISCOVERY");

            vClearMatchDescriptorDiscovery();

            /* match descriptor for on/off/level control */
            vSendMatchDesc( HA_PROFILE_ID);
            u8NumberOfDiscoveries = 1;
            u8CommState++;

            /* Only 1 scan required for less that 8 nodes */
            if(NUMBER_DEVICE_TO_BE_DISCOVERED < 8)
            {
                 u8CommState++;
            }
            break;

        case SEND_NEXT_DISCOVERY:
            DBG_vPrintf(TRACE_SWITCH_NODE,"\nSEND_NEXT_DISCOVERY");

            vSendMatchDesc( HA_PROFILE_ID);

            u8NumberOfDiscoveries++;

            if( u8NumberOfDiscoveries >= MAX_SERVICE_DISCOVERY )
            {
                u8CommState++;
            }
            break;

        case DISCOVERY_COMPLETE:
            DBG_vPrintf(TRACE_SWITCH_NODE,"\r\nDISCOVERY_COMPLETE");
            /*Any discovered light ? */
            /*Start the first one identifying */
            vSetTheNextLightIdentify();
            break;

        default:
            break;
    }
}

/****************************************************************************
 *
 * NAME: APP_vInitLeds
 *
 * DESCRIPTION:
 * Initialises LED's
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void APP_vInitLeds(void)
{
    vAHI_DioSetDirection(0, BOARD_LED_CTRL_MASK);
    vAHI_DioSetOutput(BOARD_LED_D1_PIN,0);			//default off
}

/****************************************************************************
 *
 * NAME: vSendMatchDesc
 *
 * DESCRIPTION:
 * Send out a Match descriptor
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/

void vSendMatchDesc( uint16 u16Profile)
{
    uint16 au16InClusters[]={GENERAL_CLUSTER_ID_ONOFF, GENERAL_CLUSTER_ID_LEVEL_CONTROL};
    uint8 u8TransactionSequenceNumber;
    ZPS_tuAddress uDestinationAddress;
    ZPS_tsAplZdpMatchDescReq sMatch;

    sMatch.u16ProfileId = u16Profile;
    sMatch.u8NumInClusters=sizeof(au16InClusters)/sizeof(uint16);
    sMatch.pu16InClusterList=au16InClusters;
    sMatch.pu16OutClusterList=NULL;
    sMatch.u8NumOutClusters=0;
    sMatch.u16NwkAddrOfInterest=0xFFFD;

    uDestinationAddress.u16Addr = 0xFFFD;

    PDUM_thAPduInstance hAPduInst = PDUM_hAPduAllocateAPduInstance(apduZDP);

    if (hAPduInst == PDUM_INVALID_HANDLE)
    {
        DBG_vPrintf(TRACE_SWITCH_NODE, "Allocate PDU ERR:\n");
        return;
    }

    ZPS_teStatus eStatus = ZPS_eAplZdpMatchDescRequest(hAPduInst, uDestinationAddress, FALSE, &u8TransactionSequenceNumber, &sMatch);

    if (ZPS_E_SUCCESS == eStatus)
    {
        DBG_vPrintf(TRACE_SWITCH_NODE, "Sent Match Descriptor Req P=%04x\n", u16Profile);
    }
    else
    {
        DBG_vPrintf(TRACE_SWITCH_NODE, "Match ERR: 0x%x", eStatus);
    }

    vStopStartCommissionTimer( APP_TIME_MS(START_TO_IDENTIFY_IN_MS) );

    vStartFastPolling(SIX_SECONDS);
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
PUBLIC void vAppOnOff(teCLD_OnOff_Command eCmd) {

    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE, GENERAL_CLUSTER_ID_ONOFF);

    if ((eCmd == E_CLD_ONOFF_CMD_ON) || (eCmd == E_CLD_ONOFF_CMD_OFF) || (eCmd
            == E_CLD_ONOFF_CMD_TOGGLE)) {
        eCLD_OnOffCommandSend(
                u8MyEndpoint,
                sDeviceState.sMatchDev[sDeviceState.u8Index].u8Ep,
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
PUBLIC void vAppIdentify( uint16 u16Time) {
    uint8 u8Seq;
    tsZCL_Address sAddress;
    tsCLD_Identify_IdentifyRequestPayload sPayload;

    sPayload.u16IdentifyTime = u16Time;

    vSetAddress(&sAddress,FALSE,GENERAL_CLUSTER_ID_IDENTIFY);

    eCLD_IdentifyCommandIdentifyRequestSend(
                            u8MyEndpoint,
                            sDeviceState.sMatchDev[sDeviceState.u8Index].u8Ep,
                            &sAddress,
                            &u8Seq,
                            &sPayload);
}

/****************************************************************************
 *
 * NAME: vAppIdentifyQuery
 *
 * DESCRIPTION:
 *    Send out IdentifyQuery command, the address mode(group/unicast/bound etc)
 *    is taken from the selected light index set by the caller
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppIdentifyQuery( void) {
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress,FALSE,GENERAL_CLUSTER_ID_IDENTIFY);


    eCLD_IdentifyCommandIdentifyQueryRequestSend(
                            u8MyEndpoint,
                            sDeviceState.sMatchDev[sDeviceState.u8Index].u8Ep,
                            &sAddress,
                            &u8Seq);
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
    tsCLD_LevelControl_MoveCommandPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE,GENERAL_CLUSTER_ID_LEVEL_CONTROL);

    sPayload.u8Rate = u8Rate;
    sPayload.u8MoveMode = eMode;

    eCLD_LevelControlCommandMoveCommandSend(
                                    u8MyEndpoint,
                                    sDeviceState.sMatchDev[sDeviceState.u8Index].u8Ep,
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
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE,GENERAL_CLUSTER_ID_LEVEL_CONTROL);
    eCLD_LevelControlCommandStopCommandSend(
                        u8MyEndpoint,
                        sDeviceState.sMatchDev[sDeviceState.u8Index].u8Ep,
                        &sAddress,
                        &u8Seq);
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
    tsCLD_LevelControl_StepCommandPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE,GENERAL_CLUSTER_ID_LEVEL_CONTROL);

    sPayload.u16TransitionTime = 0x000a;
    sPayload.u8StepMode = eMode;
    sPayload.u8StepSize = 0x20;
    eCLD_LevelControlCommandStepCommandSend(
                        u8MyEndpoint,
                        sDeviceState.sMatchDev[sDeviceState.u8Index].u8Ep,
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
PUBLIC void vAppRecallSceneById( uint8 u8SceneId, uint16 u16GroupId)
{

    tsCLD_ScenesRecallSceneRequestPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE,GENERAL_CLUSTER_ID_SCENES);

    DBG_vPrintf(TRACE_SWITCH_NODE, "\nRecall Scene %d\n", u8SceneId);

    sPayload.u16GroupId = u16GroupId;
    sPayload.u8SceneId = u8SceneId;

    eCLD_ScenesCommandRecallSceneRequestSend(
                            u8MyEndpoint,
                            sDeviceState.sMatchDev[sDeviceState.u8Index].u8Ep,
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

    /* vSetAddress(&sAddress, FALSE,GENERAL_CLUSTER_ID_SCENES); */
    /*  Store scene always groupcast                            */

    sAddress.eAddressMode = E_ZCL_AM_GROUP;
    sAddress.uAddress.u16DestinationAddress = u16GroupId;

    sPayload.u16GroupId = u16GroupId;
    sPayload.u8SceneId = u8SceneId;


    eCLD_ScenesCommandStoreSceneRequestSend(
                            u8MyEndpoint,
                            sDeviceState.sMatchDev[sDeviceState.u8Index].u8Ep,   /* dst ep */
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
PUBLIC void vAppAddGroup( uint16 u16GroupId, bool_t bBroadcast)
{

    tsCLD_Groups_AddGroupRequestPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, bBroadcast,GENERAL_CLUSTER_ID_GROUPS);

    sPayload.sGroupName.pu8Data = (uint8*)"";
    sPayload.sGroupName.u8Length = 0;
    sPayload.sGroupName.u8MaxLength = 0;
    sPayload.u16GroupId = u16GroupId;

    eCLD_GroupsCommandAddGroupRequestSend(
                            u8MyEndpoint,
                            sDeviceState.sMatchDev[sDeviceState.u8Index].u8Ep,
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
PUBLIC void vAppRemoveGroup( uint16 u16GroupId, bool_t bBroadcast)
{

    tsCLD_Groups_RemoveGroupRequestPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, bBroadcast,GENERAL_CLUSTER_ID_GROUPS);

    sPayload.u16GroupId = u16GroupId;

    eCLD_GroupsCommandRemoveGroupRequestSend(
                            u8MyEndpoint,
                            sDeviceState.sMatchDev[sDeviceState.u8Index].u8Ep,
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

    vSetAddress(&sAddress, bBroadcast,GENERAL_CLUSTER_ID_GROUPS);

    eCLD_GroupsCommandRemoveAllGroupsRequestSend(
                            u8MyEndpoint,
                            sDeviceState.sMatchDev[sDeviceState.u8Index].u8Ep,
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
PUBLIC void vStopTimer(OS_thSWTimer hSwTimer)
{
    if(OS_eGetSWTimerStatus(hSwTimer) != OS_E_SWTIMER_STOPPED)
        OS_eStopSWTimer(hSwTimer);
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
    vStopTimer(APP_PollTimer);
    vStopTimer(APP_CommissionTimer);
    vStopTimer(APP_ButtonsScanTimer);
    vStopTimer(APP_TickTimer);
    vStopTimer(APP_JoinTimer);
    vStopTimer(APP_BackOffTimer);
    vStopTimer(APP_tmrButtonDelayTimer);
    vStopTimer(App_EZFindAndBindTimer);
    vStopTimer(App_ChangeModeTimer);
    vStopTimer(App_PingTimer);
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
            /*Only called if the module is comming out of sleep */
            DBG_vPrintf(TRACE_SWITCH_NODE,"vISR_SystemController on WakeUP\n\n");
            vLoadKeepAliveTime(KEEP_ALIVETIME);
            vWakeCallBack();
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
    OS_eStartSWTimer(APP_PollTimer,POLL_TIME, NULL);
    /*Start the APP_TickTimer to continue the ZCL tasks */
    OS_eStartSWTimer(APP_TickTimer, ZCL_TICK_TIME, NULL);
}
#endif
/****************************************************************************
 *
 * NAME: APP_PollTask
 *
 * DESCRIPTION:
 * Poll Task for the polling as well it triggers the rejoin in case of pool failure
 * It also manages sleep timing.
 * RETURNS:
 * void
 *
 ****************************************************************************/
OS_TASK(APP_PollTask)
{
    uint32 u32PollPeriod = POLL_TIME;


    if(
    #ifdef SLEEP_ENABLE
      !bWatingToSleep() &&
    #endif
       /* Do fast polling when the device is running */
       (sDeviceDesc.eNodeState == E_RUNNING))

    {
        if( u16FastPoll )
        {
            u16FastPoll--;
            u32PollPeriod = POLL_TIME_FAST;
            /*Reload the Sleep timer during fast poll*/
            #ifdef SLEEP_ENABLE
                vReloadSleepTimers();
            #endif
        }
        OS_eStopSWTimer(APP_PollTimer);
        OS_eStartSWTimer(APP_PollTimer, u32PollPeriod, NULL);

        ZPS_teStatus u8PStatus;
        u8PStatus = ZPS_eAplZdoPoll();
        if( u8PStatus )
        {
            DBG_vPrintf(TRACE_SWITCH_NODE, "\nPoll Failed \n", u8PStatus );
        }
    }
}

/****************************************************************************
 *
 * NAME: bIsValidBindingExsisting
 *
 * DESCRIPTION:
 * Find If any Binding Table existing.
 *
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE bool bIsValidBindingExsisting(uint16 u16ClusterId)
{
    ZPS_tsAplAib * psAplAib;
    uint8 u8BindingTableSize;

    psAplAib  = ZPS_psAplAibGetAib();

    if(psAplAib->psAplApsmeAibBindingTable == NULL)
    {
        DBG_vPrintf(TRACE_SWITCH_NODE,"\n No Binding Table");
        return FALSE;
    }
    else
    {
        u8BindingTableSize = psAplAib->psAplApsmeAibBindingTable->psAplApsmeBindingTable[0].u32SizeOfBindingTable;
        DBG_vPrintf(TRACE_SWITCH_NODE, "\nBind Size %d",  u8BindingTableSize );
        if( 0== u8BindingTableSize)
        {
            DBG_vPrintf(TRACE_SWITCH_NODE,"\n Binding Table WithOut Any Entry ");
            return FALSE;
        }
        else
        {
            uint32 j;
            for( j = 0 ; j < psAplAib->psAplApsmeAibBindingTable->psAplApsmeBindingTable[0].u32SizeOfBindingTable ; j++ )
            {
                DBG_vPrintf(TRACE_SWITCH_NODE, "\n Looping Binding Table = %d ",j );
                if ( u16ClusterId == psAplAib->psAplApsmeAibBindingTable->psAplApsmeBindingTable[0].pvAplApsmeBindingTableEntryForSpSrcAddr[j].u16ClusterId)
                {
                    DBG_vPrintf(TRACE_SWITCH_NODE,"\n Binding Table Entry for Cluster = %d ",u16ClusterId);
                    return TRUE;
                }
            }
            DBG_vPrintf(TRACE_SWITCH_NODE,"\n Binding Table WithOut Any Entry for Cluster = %d ",u16ClusterId);
            return FALSE;
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
    if (bBroadcast)
    {
        DBG_vPrintf(TRACE_SWITCH_NODE, "\r\nBcast");
        psAddress->eAddressMode = E_ZCL_AM_BROADCAST;
        psAddress->uAddress.eBroadcastMode = ZPS_E_APL_AF_BROADCAST_RX_ON;
    }
    else
    {
        /*Get The switch states to decide the address mode to be taken up.*/
        switch (eGetSwitchState())
        {
            case LIGHT_CONTROL_MODE:
                /*By Default chose Group Addressing*/
                DBG_vPrintf(TRACE_SWITCH_NODE, "\nGroup");
                psAddress->eAddressMode = E_ZCL_AM_GROUP;
                psAddress->uAddress.u16DestinationAddress = u16GroupId;
                if(TRUE == bIsValidBindingExsisting(u16ClusterId))
                {
                    DBG_vPrintf(TRACE_SWITCH_NODE, "\nBound");
                    psAddress->eAddressMode = E_ZCL_AM_BOUND_NO_ACK;
                }
                break;
            case IDENTIFY_MODE:
            case INDIVIDUAL_CONTROL_MODE:
                DBG_vPrintf(TRACE_SWITCH_NODE, "\nUcastMatch");
                if(sDeviceState.sMatchDev[sDeviceState.u8Index].u16Address <= 0xFFF8 )
                {
                    psAddress->eAddressMode = E_ZCL_AM_SHORT_NO_ACK;
                    psAddress->uAddress.u16DestinationAddress = sDeviceState.sMatchDev[sDeviceState.u8Index].u16Address;
                }
                else
                {
                    psAddress->eAddressMode = E_ZCL_AM_ENUM_END;
                    psAddress->uAddress.u16DestinationAddress = 0xFFFF;
                }
                break;
            case EZMODE_FIND_AND_BIND_MODE:
                /*Get status of EZ mode from the EP to see if there is binding or grouping in progress */
                if(  E_EZ_FIND_AND_BIND_INITIATOR_IN_PROGRESS == eEZ_GetFindAndBindState(1) )
                {
                    DBG_vPrintf(TRACE_SWITCH_NODE, "\nBound");
                    psAddress->eAddressMode = E_ZCL_AM_BOUND_NO_ACK;
                }
                else /*Group by default*/
                {
                    DBG_vPrintf(TRACE_SWITCH_NODE, "\nGroup");
                    psAddress->eAddressMode = E_ZCL_AM_GROUP;
                    psAddress->uAddress.u16DestinationAddress = u16GroupId;
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
PRIVATE bool bAddressInTable( uint16 u16AddressToCheck )
{
    uint8 i;

    for( i=0; i < NUMBER_DEVICE_TO_BE_DISCOVERED; i++ )
    {
        /* Commented out due to excessive calls */
        /* DBG_vPrintf(TRACE_SWITCH_NODE, "Table: %04x, Stack: %04x", sDeviceState.sMatchDev[i].u16Address,u16AddressToCheck ); */

        if(sDeviceState.sMatchDev[i].u16Address == u16AddressToCheck )
        {
            DBG_vPrintf(TRACE_SWITCH_NODE, "\ndup!");
            return TRUE;
        }
    }

    return FALSE;

}
/****************************************************************************
 *
 * NAME: vClearMatchDescriptorDiscovery
 *
 * DESCRIPTION:
 * Clears match descriptor discovery
 *
 * PARAMETERS:
 * void
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vClearMatchDescriptorDiscovery( void )
{
    uint8 i;

    DBG_vPrintf(TRACE_SWITCH_NODE, "\nClearing Table");
    sDeviceState.u8Index = 0;
    sDeviceState.u8Discovered = 0;

    for( i=0; i < NUMBER_DEVICE_TO_BE_DISCOVERED; i++ )
    {
        sDeviceState.sMatchDev[i].u16Address = 0xffff;
    }
}

/****************************************************************************
 *
 * NAME: vStopStartCommissionTimer
 *
 * DESCRIPTION:
 * Stops and starts the commissioning timer with required ticks
 *
 * PARAMETERS:
 * u32Ticks     Ticks for timer start
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vStopStartCommissionTimer( uint32 u32Ticks )
{
    if( OS_eGetSWTimerStatus(APP_CommissionTimer) != OS_E_SWTIMER_STOPPED )
    {
        OS_eStopSWTimer(APP_CommissionTimer);
    }
    #ifdef SLEEP_ENABLE
        if( FALSE == bWatingToSleep())
        {
            OS_eStartSWTimer(APP_CommissionTimer, u32Ticks, NULL );
        }
    #else
        OS_eStartSWTimer(APP_CommissionTimer, u32Ticks, NULL );
    #endif
}

/****************************************************************************
 *
 * NAME: vSetTheNextLightIdentify
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
PUBLIC void vSetTheNextLightIdentify(void)
{
    if(bLightsDiscovered())
    {
        /* Select next node from the list for commissioning */
        if(sDeviceState.u8Index > 0)
            sDeviceState.u8Index--;
        else
            sDeviceState.u8Index = sDeviceState.u8Discovered-1;
        /* Send identify to the selected node */
        vAppIdentify(APP_IDENTIFY_TIME_IN_SECS);
    }
}
/****************************************************************************
 *
 * NAME: vSetThePrevLightIdentify
 *
 * DESCRIPTION:
 * Set the prev node to identify
 *
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vSetThePrevLightIdentify(void)
{
    if(bLightsDiscovered())
    {
        /* Select next node from the list for commissioning */
        if(sDeviceState.u8Index < (sDeviceState.u8Discovered-1))
            sDeviceState.u8Index++;
        else
            sDeviceState.u8Index=0;
        /* Send identify to the selected node */
        vAppIdentify(APP_IDENTIFY_TIME_IN_SECS);
    }
}
/****************************************************************************
 *
 * NAME: vAppDiscover
 *
 * DESCRIPTION:
 * Start Discovery and identify.
 *
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppDiscover(void)
{
    u8CommState = 0;
    OS_eActivateTask(APP_CommissionTimerTask);
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
PUBLIC void vAppChangeChannel( void)
{
    /*Primary channel Set */
    uint8 au8ZHAChannelSet[]={11,14,15,19,20,24,25};

    ZPS_tsAplZdpMgmtNwkUpdateReq sZdpMgmtNwkUpdateReq;
    PDUM_thAPduInstance hAPduInst;
    ZPS_tuAddress uDstAddr;
    uint8 u8Seq;
    uint8 u8Min=0, u8Max=6;
    uint8 u8CurrentChannel, u8RandomNum;

    hAPduInst = PDUM_hAPduAllocateAPduInstance(apduZDP);
    if (hAPduInst != NULL)
    {
        sZdpMgmtNwkUpdateReq.u8ScanDuration = 0xfe;

        u8CurrentChannel = ZPS_u8AplZdoGetRadioChannel();
        u8RandomNum = RND_u32GetRand(u8Min,u8Max);
        if(u8CurrentChannel != au8ZHAChannelSet[u8RandomNum])
        {
            sZdpMgmtNwkUpdateReq.u32ScanChannels = (1<<au8ZHAChannelSet[u8RandomNum]);
        }
        else /* Increment the channel by one rather than spending in RND_u32GetRand */
        {
            /*  For roll over situation */
            if(u8RandomNum == u8Max)
            {
                sZdpMgmtNwkUpdateReq.u32ScanChannels = (1<<au8ZHAChannelSet[u8Min]);
            }
            else
            {
                sZdpMgmtNwkUpdateReq.u32ScanChannels = (1<<au8ZHAChannelSet[u8RandomNum+1]);
            }
        }

        sZdpMgmtNwkUpdateReq.u8NwkUpdateId = ZPS_psAplZdoGetNib()->sPersist.u8UpdateId + 1;
        uDstAddr.u16Addr = 0xfffd;

        if ( 0 == ZPS_eAplZdpMgmtNwkUpdateRequest( hAPduInst,
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
 * NAME: vEZ_EZModeCb
 *
 * DESCRIPTION:
 * EZ Mode call back
 *
 * PARAMETERS:
 * tsEZ_FindAndBindEvent * psCallBackEvent  call back event.
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vEZ_EZModeCb(tsEZ_FindAndBindEvent * psCallBackEvent)
{
    switch (psCallBackEvent->eEventType)
    {
        /*EZ Mode Events */

        case E_EZ_BIND_CREATED_FOR_TARGET:
        {
            uint8 u8Seq;
            tsZCL_Address sAddress;
            tsCLD_Identify_IdentifyRequestPayload sPayload;

            sPayload.u16IdentifyTime = 0;
            sAddress.eAddressMode = E_ZCL_AM_SHORT_NO_ACK;
            sAddress.uAddress.u16DestinationAddress = psCallBackEvent->u16TargetAddress;

            eCLD_IdentifyCommandIdentifyRequestSend(
                                    psCallBackEvent->u8InitiatorEp,
                                    psCallBackEvent->u8TargetEp,
                                    &sAddress,
                                    &u8Seq,
                                    &sPayload);
            /*Make the target stop identifying that is just bound
             * This helps in adding next target */
            DBG_vPrintf(TRACE_SWITCH_NODE, " APP : E_HA_EZ_BIND_CREATED_FOR_TARGET\n");


        }
            break;

        case E_EZ_GROUP_CREATED_FOR_TARGET:
        {
            uint8 u8Seq;
            tsZCL_Address sAddress;
            tsCLD_Identify_IdentifyRequestPayload sPayload;

            sPayload.u16IdentifyTime = 0;
            sAddress.eAddressMode = E_ZCL_AM_SHORT_NO_ACK;
            sAddress.uAddress.u16DestinationAddress = psCallBackEvent->u16TargetAddress;

            eCLD_IdentifyCommandIdentifyRequestSend(
                                    psCallBackEvent->u8InitiatorEp,
                                    psCallBackEvent->u8TargetEp,
                                    &sAddress,
                                    &u8Seq,
                                    &sPayload);
            /*Make the target stop identifying that is just grouped
             * This helps in adding next target */
            DBG_vPrintf(TRACE_SWITCH_NODE, " APP : E_EZ_GROUP_CREATED_FOR_TARGET\n");

        }
            break;

        case E_EZ_TIMEOUT:
            /**/
            break;
        default:
            DBG_vPrintf(TRACE_SWITCH_NODE, "Invalid event type\r\n");
            break;
    }
}
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
PRIVATE void app_vRestartNode (void)
{
    ZPS_tsNwkNib * thisNib;

    /* Get the NWK Handle to have the NWK address from local node and use it as GroupId*/
    thisNib = ZPS_psNwkNibGetHandle(ZPS_pvAplZdoGetNwkHandle());

    /* The node is in running state indicates that
     * the EZ Mode state is as E_EZ_DEVICE_IN_NETWORK*/
    eEZ_UpdateEZState(E_EZ_DEVICE_IN_NETWORK);

    DBG_vPrintf(TRACE_SWITCH_NODE, "None Factory New Start\n");

    ZPS_vSaveAllZpsRecords();
    u16GroupId = thisNib->sPersist.u16NwkAddr;
    /* Start 1 seconds polling */
    OS_eStartSWTimer(APP_PollTimer,POLL_TIME, NULL);
    /*If it is coming out of deep sleep take action on button press */
    #ifdef SLEEP_ENABLE
        #ifdef DEEP_SLEEP_ENABLE
            vActionOnButtonActivationAfterDeepSleep();
        #endif
    #endif

    /*Rejoin NWK when coming from reset.*/
    ZPS_eAplZdoRejoinNetwork(FALSE);
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
	uint32 u32DIOState = u32AHI_DioReadInput();
	DBG_vPrintf(TRACE_SWITCH_NODE, "Factory New Start\n");

	/*Join network whenter wakeup JOIN_BUTTON */
	if ( 0 == (u32DIOState & JOIN_BUTTON) )
	{
			DBG_vPrintf(TRACE_SWITCH_NODE, "Join network\n");
			eEZ_UpdateEZState(E_EZ_START);
	    /* Stay awake for joining */
	    vStartStopTimer( APP_JoinTimer, APP_TIME_MS(10),(uint8*)&(sDeviceDesc.eNodeState),E_STARTUP);			
	}else{
		vForceDeviceDeepSleepEx();
	}
}

/****************************************************************************
 *
 * NAME: APP_SleepTask
 *
 * DESCRIPTION:
 * Os Task activated by the wake up event to manage sleep
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/

OS_TASK(APP_SleepTask)
{
    /* A Sleep Task that is called upon coming out of sleep. 
     * This can be populated as requried , left in the code to allow user to develop on top of it 
     */
}



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

#ifdef CLD_OTA
/****************************************************************************
 *
 * NAME: psGetOTACallBackPersistdata
 *
 * DESCRIPTION:
 * returns the pointer to the OTA persistent data from the device structure.
 *
 * RETURNS:
 * pointer of type tsOTA_PersistedData
 *
 ****************************************************************************/
PUBLIC tsOTA_PersistedData * psGetOTACallBackPersistdata(void)
{
    return (&(sSwitch.sCLD_OTA_CustomDataStruct.sOTACallBackMessage.sPersistedData));
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
 * NAME: vPingUCASTTarget
 *
 * DESCRIPTION:
 * Tries to send a read attribute ZCL Version of Basic cluster of the Light
 * that is currently controlled using unicast mode.
 * The right place to call this function is when button is pressed.
 *
 * If a response is heard back , it resets the logic if not for threshold
 * amount of numbers,this sends out a NWK status to parent.
 *
 *
 ****************************************************************************/
PUBLIC void vPingUCASTTarget(void)
{
    uint8 u8Seq;
    tsZCL_Address sAddress;

    uint16   au16AttributeRequestList[]={0}; /* ZCL version attribute of Basic cluster*/

    /*Following statement is to get the current address mode from the switch, cluster id set to basic cluster */
    vSetAddress(&sAddress, FALSE, 0);

    /*
     * If the mode is unicast then start observing for the packet delivery every APP_THRESHOLD_NO_OF_UCAST_TO_SEND_READ_ATTR
     * transactions to send a read attribute req
     *
     * */

    if(E_ZCL_AM_SHORT_NO_ACK == sAddress.eAddressMode)
    {
        sDeviceState.sMatchDev[sDeviceState.u8Index].u8NumberOfUcasts++;
        if( sDeviceState.sMatchDev[sDeviceState.u8Index].u8NumberOfUcasts >= APP_THRESHOLD_TO_SEND_READ_ATTR)
        {

            if(sDeviceState.sMatchDev[sDeviceState.u8Index].u8NumberOfUcasts < APP_THRESHOLD_FORCE_ROUTE_DISCOVERY )
            {
                DBG_vPrintf(TRACE_CIRCULAR_ROUTE,"Sending eZCL_SendReadAttributesRequest for %d \n",sDeviceState.sMatchDev[sDeviceState.u8Index].u8NumberOfUcasts);
                teZCL_Status eStatus=eZCL_SendReadAttributesRequest(
                                                                u8MyEndpoint,                                        /*uint8                       u8SourceEndPointId,*/
                                                                sDeviceState.sMatchDev[sDeviceState.u8Index].u8Ep,    /*uint8                       u8DestinationEndPointId,*/
                                                                0,                                                  /*Basic//uint16               u16ClusterId,*/
                                                                FALSE,                                              /*bool_t                      bDirectionIsServerToClient,*/
                                                                &sAddress,                                          /*tsZCL_Address              *psDestinationAddress,*/
                                                                &u8Seq,                                              /*uint8                      *pu8TransactionSequenceNumber,*/
                                                                1,                                                    /*uint8                       u8NumberOfAttributesInRequest,*/
                                                                FALSE,                                                /*bool_t                      bIsManufacturerSpecific,*/
                                                                0x1037,                                             /*uint16                      u16ManufacturerCode,*/
                                                                au16AttributeRequestList                            /*uint16                     *pu16AttributeRequestList*/
                                                            );
                if(E_ZCL_SUCCESS != eStatus)
                {
                    DBG_vPrintf(TRACE_CIRCULAR_ROUTE,"eZCL_SendReadAttributesRequest Status %d \n",eStatus);
                }
            }
            else
            {
                void * thisNet = ZPS_pvAplZdoGetNwkHandle();
                ZPS_tsNwkNib * thisNib = ZPS_psNwkNibGetHandle(thisNet);

                sDeviceState.sMatchDev[sDeviceState.u8Index].u8NumberOfUcasts=0;

                DBG_vPrintf(TRACE_CIRCULAR_ROUTE,"Sending ZPS_vNwkSendNwkStatusCommand\n");
                /* If the threshold has reached ,
                 * then send a NWK status instead of read attribute
                 * */

                ZPS_vNwkSendNwkStatusCommand( thisNet,
                                              sAddress.uAddress.u16DestinationAddress,
                                              thisNib->sTbl.psNtActv[0].u16NwkAddr,
                                              0,
                                              1);
            }
        }
    }
    else
    {
        /* the switch is not doing any an UCAST currently , then reset */
        sDeviceState.sMatchDev[sDeviceState.u8Index].u8NumberOfUcasts=0;
    }
}

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

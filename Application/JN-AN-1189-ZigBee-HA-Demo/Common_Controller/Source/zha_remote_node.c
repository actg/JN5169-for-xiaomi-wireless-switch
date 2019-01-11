/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          zha_remote_node.c
 *
 * DESCRIPTION:        ZHA Demo : Stack <-> Remote Control App Interaction
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
#include <string.h>
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
#include "app_captouch_buttons.h"
#include "app_led_control.h"
#include "zha_remote_node.h"

#include "app_zcl_remote_task.h"
#include "app_zbp_utilities.h"

#include "app_events.h"
#include "zcl_customcommand.h"
#include "ha.h"

#include "haEzJoin.h"

#include "zcl_common.h"
#include "zcl.h"
#include "haKeys.h"

#include "PingParent.h"
#ifdef RemoteControl
#include "haEzFindAndBind.h"
#endif
#include "appZdpExtraction.h"
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifdef DEBUG_REMOTE_NODE
    #define TRACE_REMOTE_NODE   TRUE
#else
    #define TRACE_REMOTE_NODE   FALSE
#endif

#ifndef DEBUG_SLEEP
    #define TRACE_SLEEP     FALSE
#else
    #define TRACE_SLEEP     TRUE
#endif

#define MAX_REJOIN_TIME (60*12)  /* 12 minutes */
#define BACK_OFF_TIME   (60*15)  /* 15 minutes */

#ifdef DEEP_SLEEP_ENABLE
    #define POWER_BTN (1)
    #define DEEP_SLEEP_TIME 155 /* drop in the deep sleep after 155((DEEP_SLEEPTIME - KEEPALIVE) / SLEEP_TIME) secs = 15 minutes */
#endif

#define MAX_SERVICE_DISCOVERY   3
#define SLEEP_DURATION_MS (800)
#define SLEEP_TIMER_TICKS_PER_MS (32)
#define SCAN_DURATION_IN_MS (200)

#define APP_MATCH_DESCRIPTOR_RESPONSE   0x8006

#define SIX_SECONDS                     6

#define START_TO_IDENTIFY               3
#define START_TO_IDENTIFY_IN_MS         (START_TO_IDENTIFY*1000)

#define SEND_FIRST_DISCOVERY            0
#define SEND_NEXT_DISCOVERY             1
#define DISCOVERY_COMPLETE              2

#ifdef RemoteControl
    #define STOP_FAST_POLL                  0
    /* Keep Fast Polling and identifying for EZ mode time */
    #define EZMODE_TIME                    (EZ_MODE_TIME * 60)
    /* Keep this time 1 second more than EZ Mode time just to make sure sleep is not disturbed */
    #define EZMODE_SLEEP_TIME               EZMODE_TIME + 1
#endif

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/


/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/

#ifdef SLEEP_ENABLE
    PRIVATE void vLoadKeepAliveTime(uint8 u8TimeInSec);
#endif
PRIVATE void APP_vHandleKeyPress(teUserKeyCodes eKeyCode);
PRIVATE void APP_vHandleKeyRelease(teUserKeyCodes eKeyCode);
PRIVATE void vHandleAppEvent( APP_tsEvent sAppEvent );

PRIVATE void vSendMatchDesc( uint16);

PRIVATE bool bAddressInTable( uint16 u16AddressToCheck );
PRIVATE void vClearMatchDescriptorDiscovery( void );

PRIVATE void vStopStartCommissionTimer( uint32 u32Ticks );
PRIVATE void vHandleMatchResponses( ZPS_tsAfEvent sStackEvent );
PRIVATE void vHandleJoinAndRejoinNWK( ZPS_tsAfEvent *pZPSevent,teEZ_JoinAction eJoinAction  );
PRIVATE void app_vRestartNode (void);
PRIVATE void app_vStartNodeFactoryNew(void);
PRIVATE void vStayAliveForPingResp(uint8 u8Time);

PRIVATE void vSendPermitJoin(void);

PUBLIC void vStopAllTimers(void);
PUBLIC void vStopTimer(OS_thSWTimer hSwTimer);
PUBLIC void vStartRunningTimer(OS_thSWTimer hSwTimer,uint32 u32Ticks);
PRIVATE bool_t bHandleZdoLeaveRequest(uint8 u8Action, uint64 u64TargetAddr, uint8 u8Flags);
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
PUBLIC PDM_tsRecordDescriptor sDevicePDDesc;
PUBLIC PDM_tsRecordDescriptor sDeviceStatePDDesc;
PUBLIC  tsDeviceDesc   sDeviceDesc;
PUBLIC tsDeviceState sDeviceState;

uint16 u16GroupId;

teShiftLevel eShiftLevel = E_SHIFT_0;
PUBLIC bool_t bAddrMode = FALSE;

extern bool_t bDeepSleep;
/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
PRIVATE uint8 u8CommState;

/*Primary channel Set */
PRIVATE uint8 au8ZHAChannelSet[]={11,14,15,19,20,24,25};
PRIVATE uint16 u16FastPoll;
PRIVATE uint8 u8RunningWithJoinFailedTime = 10;

//#define APP_IGNORE_LEAVE_WITHOUT_REJOIN

#ifdef SLEEP_ENABLE
    PRIVATE bool bDataPending=FALSE;
    #ifdef DEEP_SLEEP_ENABLE
        PRIVATE uint8 u8DeepSleepTime= DEEP_SLEEP_TIME;
    #endif
    PRIVATE uint8 u8KeepAliveTime = KEEP_ALIVETIME;
    PRIVATE pwrm_tsWakeTimerEvent    sWake;
#endif

#ifdef CLD_COLOUR_CONTROL
    uint16 au16ColourTemperatures[] = {370,309,264,231,205,184,168,153};/* 2700K,3232K,3784K,4326K,4868K,5410K,5952K,6500K */
    uint8 u8ColourTempIndex = 0;
#endif

#ifdef RemoteControl
    static bool_t bInEzMode;
    bool_t bReadyToGroup;
    static uint16 u16LightSensorGroupId = 0xFFFF;
#endif
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
    PDM_teStatus eDeviceStatus;
    DBG_vPrintf(TRACE_REMOTE_NODE, "\nAPP_vInitialiseNode*");

    APP_vInitLeds();

    /* Initialise buttons;
     */
    APP_bButtonInitialise();

    /* Restore any application data previously saved to flash */
    uint16 u16ByteRead;
    PDM_eReadDataFromRecord(PDM_ID_APP_REMOTE_CONTROL, 
                           &sDeviceDesc,
            sizeof(tsDeviceDesc), 
            &u16ByteRead);

    /* Restore any application data previously related to nodes saved to flash */
    eDeviceStatus = PDM_eReadDataFromRecord(PDM_ID_APP_REMOTE_DEVICE_TABLE, &sDeviceState,
            sizeof(tsDeviceState), &u16ByteRead);

    DBG_vPrintf(TRACE_REMOTE_NODE, "Restore Device state status %d\n",eDeviceStatus);

    /* Initialise ZBPro stack */
    ZPS_vAplSecSetInitialSecurityState(ZPS_ZDO_PRECONFIGURED_LINK_KEY, (uint8 *)&s_au8LnkKeyArray, 0x00, ZPS_APS_GLOBAL_LINK_KEY);
    DBG_vPrintf(TRACE_REMOTE_NODE, "Set Sec state\n");


    vEZ_RestoreDefaultAIBChMask();
    /* Initialize ZBPro stack */
    ZPS_eAplAfInit();
    DBG_vPrintf(TRACE_REMOTE_NODE, "ZPS_eAplAfInit\n");
    /*Set Save default channel mask as it is going to be manipulated */
    vEZ_SetDefaultAIBChMask();

    APP_ZCL_vInitialise();

    /*Load the reports from the PDM or the default ones depending on the PDM load record status*/
    if(eDeviceStatus !=PDM_E_STATUS_OK )
    {
        /*Load Defaults if the data was not correct*/
        PDM_eSaveRecordData( PDM_ID_APP_REMOTE_DEVICE_TABLE,&sDeviceState,sizeof(tsDeviceState));
    }
    /* If the device state has been restored from flash, re-start the stack
     * and set the application running again.
     */
    if (sDeviceDesc.eNodeState == E_RUNNING)
    {
        /*The following Patch ensures the device will set the address allocate flag will set to FALSE during rejoin in future*/

        void* pvNwk;
        pvNwk = ZPS_pvAplZdoGetNwkHandle();
        ZPS_psNwkNibGetHandle( pvNwk)->sPersist.u8CapabilityInformation &= 0x7f;
        DBG_vPrintf(TRACE_REMOTE_NODE,"\nThe sNib.sPersist.u8CapabilityInformation = %02x",ZPS_psNwkNibGetHandle( pvNwk)->sPersist.u8CapabilityInformation);

        app_vRestartNode();
        sDeviceDesc.eNodeState = E_NFN_START;
    }
    else
    {
        app_vStartNodeFactoryNew();
    }

    #ifdef PDM_EEPROM
        vDisplayPDMUsage();
    #endif

       /* Register callback that will handle ZDP (mgmt) leave requests */
       ZPS_vAplZdoRegisterZdoLeaveActionCallback(bHandleZdoLeaveRequest);

    OS_eActivateTask(APP_ZHA_Remote_Task);
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
 * NAME: APP_ZHA_Remote_Task
 *
 * DESCRIPTION:
 * Task that handles the application related functionality
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
OS_TASK(APP_ZHA_Remote_Task)
{
    APP_tsEvent sAppEvent;
    ZPS_tsAfEvent sStackEvent;
    sStackEvent.eType = ZPS_EVENT_NONE;
    sAppEvent.eType = APP_E_EVENT_NONE;
    /*Collect the application events*/
    if (OS_eCollectMessage(APP_msgEvents, &sAppEvent) == OS_E_OK)
    {

    }
    /*Collect stack Events */
    else if ( OS_eCollectMessage(APP_msgZpsEvents, &sStackEvent) == OS_E_OK)
    {
        #ifdef DEBUG_REMOTE_NODE
            vDisplayStackEvent(sStackEvent);
        #endif

        vPingRecv(&sStackEvent);
    }

    /* Handle events depending on node state */
    switch (sDeviceDesc.eNodeState)
    {
        case E_STARTUP:
            vHandleJoinAndRejoinNWK(&sStackEvent,E_EZ_JOIN);
            break;

        case E_NFN_START:
            sDeviceDesc.eNodeState = E_RUNNING;
            break;

        case E_REJOINING:
            vHandleJoinAndRejoinNWK(&sStackEvent,E_EZ_REJOIN);
            DBG_vPrintf(TRACE_REMOTE_NODE, "In E_REJOIN - Kick off Tick Timer \n");
            OS_eStartSWTimer(APP_TickTimer, ZCL_TICK_TIME, NULL);
            vHandleAppEvent( sAppEvent );
            break;

        case E_RUNNING:
            DBG_vPrintf(TRACE_REMOTE_NODE, "E_RUNNING\n");
            if (sStackEvent.eType == ZPS_EVENT_NWK_FAILED_TO_JOIN)
            {
                DBG_vPrintf(TRACE_REMOTE_NODE, "Start join failed tmr 1000\n");
                vStopAllTimers();
                OS_eStartSWTimer(APP_TickTimer, ZCL_TICK_TIME, NULL);
                vStartStopTimer( APP_JoinTimer, APP_TIME_MS(1000),(uint8*)&(sDeviceDesc.eNodeState),E_REJOINING );
                DBG_vPrintf(TRACE_REMOTE_NODE, "failed join running %02x\n",sStackEvent.uEvent.sNwkJoinFailedEvent.u8Status );
            }
            /* Mgmt Leave Received */
            else if (  ZPS_EVENT_NWK_LEAVE_INDICATION == sStackEvent.eType  )
            {
                DBG_vPrintf(TRACE_REMOTE_NODE, "ZDO Leave\n" );
                /*Indicates the node has to leave the NWK - Delete PDM and reset */                
                if( sStackEvent.uEvent.sNwkLeaveIndicationEvent.u64ExtAddr == 0 )
                {
                    /* If no rejoin is request then make factory new */
                    if (0 == sStackEvent.uEvent.sNwkLeaveIndicationEvent.u8Rejoin)
                    {
                        PDM_vDeleteAllDataRecords();
                        vAHI_SwReset();
                    }
                }
            }
            else if((ZPS_EVENT_APS_DATA_INDICATION == sStackEvent.eType) &&
                    (0 == sStackEvent.uEvent.sApsDataIndEvent.u8DstEndpoint))
            {
                vHandleMatchResponses( sStackEvent );
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
            #ifdef RemoteControl
                vEZ_EZModeNWKFindAndBindHandler(&sStackEvent);
            #endif
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
 * NAME: vHandleJoinAndRejoinNWK
 *
 * DESCRIPTION:
 * Handles the Join and Rejoin of the NWKs
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
    DBG_vPrintf(TRACE_REMOTE_NODE, "EZ_STATE\%x r\n", ezState);
    if(ezState == E_EZ_DEVICE_IN_NETWORK)
    {

        /*The following Patch ensures the device will set the address allocate flag will set to FALSE during rejoin in future*/
        void* pvNwk;
        pvNwk = ZPS_pvAplZdoGetNwkHandle();
        ZPS_psNwkNibGetHandle( pvNwk)->sPersist.u8CapabilityInformation &= 0x7f;
        DBG_vPrintf(TRACE_REMOTE_NODE,"\nThe sNib.sPersist.u8CapabilityInformation = %02x",ZPS_psNwkNibGetHandle( pvNwk)->sPersist.u8CapabilityInformation);

        DBG_vPrintf(TRACE_REMOTE_NODE, "HA EZMode EVT: E_EZ_DEVICE_IN_NETWORK \n");
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
 * NAME: vSetUpWakeUpConditions
 *
 * DESCRIPTION:
 *
 * Set up the wake up inputs while going to deep sleep
 *
 *
 ****************************************************************************/
PUBLIC void vSetUpWakeUpConditions(void)
{
    if (bDeepSleep)
    {
        APP_vSetLeds(0);                    /* ensure leds are off */
        u32AHI_DioWakeStatus();             /* clear interrupts */

        vAHI_DioSetDirection(POWER_BTN,0); /* Set Power Button(DIO0) as Input  */
        vAHI_DioWakeEdge(0,POWER_BTN);     /* Set wake up as DIO Falling Edge  */
        vAHI_DioWakeEnable(POWER_BTN,0);   /* Enable Wake up DIO Power Button  */
    }
}
#endif
/****************************************************************************
 *
 * NAME: vStayAliveForPingResp
 *
 * DESCRIPTION:
 * Loads the deep sleep time
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vStayAliveForPingResp(uint8 u8Time)
{
    vLoadKeepAliveTime(u8Time);
}
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
    if( u8KeepAliveTime > 0 )
    {
        u8KeepAliveTime--;
        DBG_vPrintf(TRACE_REMOTE_NODE,"\n KeepAliveTime = %d \n",u8KeepAliveTime);
    }
    else
    {

        vStopAllTimers();
        DBG_vPrintf(TRACE_REMOTE_NODE,"\n Activity %d, KeepAliveTime = %d \n",PWRM_u16GetActivityCount(),u8KeepAliveTime);
        #ifdef DEEP_SLEEP_ENABLE
            if(u8DeepSleepTime > 0 )
            {
                u8DeepSleepTime--;
                PWRM_eScheduleActivity(&sWake, SLEEP_DURATION_MS*SLEEP_TIMER_TICKS_PER_MS , vWakeCallBack);
            }
            else
            {
                /*It is OK to force a deep sleep by finishing activities when we intent to enter the deep sleep*/
                while (PWRM_u16GetActivityCount()) 
                    PWRM_eFinishActivity();
                    
                PWRM_vInit(E_AHI_SLEEP_DEEP);
                bDeepSleep=TRUE;
            }
        #else
            PWRM_teStatus eStatus = PWRM_eScheduleActivity(&sWake, SLEEP_DURATION_MS*SLEEP_TIMER_TICKS_PER_MS , vWakeCallBack);
            DBG_vPrintf(TRACE_REMOTE_NODE,"\nSleep Status = %d\n",eStatus);
            APP_vSetLeds(E_SHIFT_0);
        #endif
    }
}
#endif

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
    switch(sAppEvent.eType)
    {
        case APP_E_EVENT_BUTTON_DOWN:

            #ifdef SLEEP_ENABLE
                vReloadSleepTimers();
            #endif

            APP_vHandleKeyPress(sAppEvent.uEvent.sButton.u8Button);

            /*Reset the channel mask to last used so that the
             * rejoining joining will be attempted
             * */
            if(sDeviceDesc.eNodeState == E_REJOINING )
            {
                vEZ_ReJoin();
            }
        break;

        case APP_E_EVENT_BUTTON_UP:
            APP_vHandleKeyRelease(sAppEvent.uEvent.sButton.u8Button);
        break;

        default:
        break;
    }
}
/****************************************************************************
 *
 * NAME: APP_vHandleKeyPress
 *
 * Button map is as follow, please update as changes are made:
 *
 * +--------------------+ +--------------------+ +--------------------+ +--------------------+
 * |0 Brightness Up     | |0 Move Hue Up       | |0 Move saturation up| |0 On                |
 * |1 Brightness Up     | |1 Move Temp Up      | |1 Start Color Move  | |1 On                |
 * |2 Brightness Up     | |2 Move To Temp Up   | |2 Add Group         | |2 On                |
 * |3                   | |3                   | |3                   | |3 On                |
 * |                    | |                    | |                    | |                    |
 * |        1(+)        | |       2(1)         | |       3(2)         | |       4(|)         |
 * +--------------------+ +--------------------+ +--------------------+ +--------------------+
 * +--------------------+ +--------------------+ +--------------------+ +--------------------+
 * |0 Brightness Down   | |0 Move Hue Down     | |0 Move Sat Down     | |0 Off               |
 * |1 Brightness Down   | |1 MoveColorTemp Down| |1 Stop Color Move   | |1 Off               |
 * |2 Brightness Down   | |2 Move To Temp Down | |2 Remove Group      | |2 Off               |
 * |3                   | |3                   | |3                   | |3 Off               |
 * |                    | |                    | |                    | |                    |
 * |       5(-)         | |       6(3)         | |        7(4)        | |        8(O)        |
 * +--------------------+ +--------------------+ +--------------------+ +--------------------+
 * +--------------------+ +--------------------+ +--------------------+ +--------------------+
 * |0 Recall Scene 1    | |0 Reacll Scene 2    | |0 Recal Scene 3     | |0 Recall Scene 4    |
 * |1 Store Scene 1     | |1 Store Scene 2     | |1 Store Scene 3     | |1 Store Scene 4     |
 * |2 Change Color Up   | |2 Change Color Down | |2 Permit Join       | |2  Change Channel   |
 * |3                   | |3                   | |3                   | |3                   |
 * |                    | |                    | |                    | |                    |
 * |        9(A)        | |       10(B)        | |       11(C)        | |       12(D)        |
 * +--------------------+ +--------------------+ +--------------------+ +--------------------+
 * +--------------------+ +--------------------+ +--------------------+ +--------------------+
 * |0 Shift             | |0 Unicast/Groupcast | |0 Identify/NextLight| |0 EZ Mode Comm      |
 * |1 Shift             | |1 Unicast/Groupcast | |1 Identify/NextLight| |1 EZ Mode Comm      |
 * |2 Shift             | |2 Unicast/Groupcast | |2 Identify/NextLight| |2 EZ Mode Comm      |
 * |3 Shift             | |3 Unicast/Groupcast | |3 Identify/NextLigh | |3 EZ Mode Comm      |
 * |                    | |                    | |                    | |                    |
 * |       13(*)        | |       14(?)        | |       15(>)        | |      16(#)         |
 * +--------------------+ +--------------------+ +--------------------+ +--------------------+
 * Note1: FactoryNew(erases persistent data from the self(remote control unit)) in shift 3 mode
 *        KeySequence: '-' '+' '-'
 *
 * DESCRIPTION:
 * Handles key presses
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void APP_vHandleKeyPress(teUserKeyCodes eKeyCode)
{
    static uint8 u8SelfFR=0;
    #ifdef RemoteControl
        if(bInEzMode)
        {
              DBG_vPrintf(TRACE_REMOTE_NODE," Exit Easy Mode \n");
              vAPP_ZCL_DeviceSpecific_IdentifyOff();
              vEZ_Exit(u8MyEndpoint);
              /* Exit EZ mode and stop fast polling , keep alive for 20 seconds*/
              vStartFastPolling(STOP_FAST_POLL);
              /* Update LED's to reflect shift level */
              APP_vSetLeds(eShiftLevel);
              APP_vBlinkLeds(eShiftLevel);
              bInEzMode = FALSE;
              return;
        }
    #endif
    switch (eShiftLevel)
    {
        case E_SHIFT_0:
            u8SelfFR =0;
            switch (eKeyCode)
            {
                case KEY_1: /* Brightness Up*/
                            APP_ZCL_vSendHAMoveLevel(E_CLD_LEVELCONTROL_MOVE_MODE_UP, LEVEL_CHANGE_STEPS_PER_SEC_FAST, TRUE);
                            break;
                case KEY_2: /* Move Hue Up*/
                            #ifdef CLD_COLOUR_CONTROL
                                APP_ZCL_vSendHAMoveHue(E_CLD_COLOURCONTROL_MOVE_MODE_UP, HUE_CHANGE_STEPS_PER_SEC);
                            #endif
                            break;
                case KEY_3:/* Move Saturation Up*/
                            #ifdef CLD_COLOUR_CONTROL
                                APP_ZCL_vSendHAMoveSaturation(E_CLD_COLOURCONTROL_MOVE_MODE_UP, SATURATION_CHANGE_STEPS_PER_SEC);
                            #endif
                            break;
                case KEY_4: /* On*/
                            APP_ZCL_vSendHAOnOff(E_CLD_ONOFF_CMD_ON);
                            break;
                case KEY_5: /* Brightness Down*/
                            APP_ZCL_vSendHAMoveLevel(E_CLD_LEVELCONTROL_MOVE_MODE_DOWN, LEVEL_CHANGE_STEPS_PER_SEC_FAST, FALSE);
                            break;
                case KEY_6: /* Move Hue Down*/
                            #ifdef CLD_COLOUR_CONTROL
                                APP_ZCL_vSendHAMoveHue(E_CLD_COLOURCONTROL_MOVE_MODE_DOWN, HUE_CHANGE_STEPS_PER_SEC);
                            #endif
                            break;
                case KEY_7: /* Move Saturation Down*/
                            #ifdef CLD_COLOUR_CONTROL
                                APP_ZCL_vSendHAMoveSaturation(E_CLD_COLOURCONTROL_MOVE_MODE_DOWN, SATURATION_CHANGE_STEPS_PER_SEC);
                            #endif
                            break;
                case KEY_8: /* Off*/
                            APP_ZCL_vSendHAOnOff( E_CLD_ONOFF_CMD_OFF);
                            break;
                case KEY_9: /* Recall Scene 1*/
                            #ifdef CLD_SCENES
                                vAppRecallSceneById(SCENE_1, u16GroupId);
                            #endif
                            break;
                case KEY_10: /* Reacll Scene 2*/
                             #ifdef CLD_SCENES
                                vAppRecallSceneById(SCENE_2, u16GroupId);
                             #endif
                             break;
                case KEY_11: /* Recall Scene 3*/
                            #ifdef CLD_SCENES
                                vAppRecallSceneById(SCENE_3, u16GroupId);
                            #endif
                            break;
                case KEY_12: /* Recall Scene 4*/
                            #ifdef CLD_SCENES
                                vAppRecallSceneById(SCENE_4, u16GroupId);
                            #endif
                             break;
                case KEY_13: /* Shift*/
                             eShiftLevel += 1;
                             break;
                case KEY_14: /* Unicast/Groupcast Toggle*/
                             bAddrMode = !bAddrMode;
                             break;
                case KEY_15: /* Identify / Next Light*/
                             bAddrMode = FALSE;
                             vSetTheNextLightIdentify();
                             break;
                case KEY_16: /* Start discovery*/
                             vAppDiscover();
                             break;
                default : /*Default*/
                          break;
            }
            break;

            case E_SHIFT_1:
                u8SelfFR =0;
                switch(eKeyCode)
                {
                case KEY_1: /* Brightness Up*/
                            APP_ZCL_vSendHAMoveLevel(E_CLD_LEVELCONTROL_MOVE_MODE_UP, LEVEL_CHANGE_STEPS_PER_SEC_MED, TRUE);
                            break;
                case KEY_2: /* Move Color Temp*/
                            #ifdef CLD_COLOUR_CONTROL
                                APP_ZCL_vSendHAMoveColourTemperature(E_CLD_COLOURCONTROL_MOVE_MODE_UP, COLOUR_TEMP_CHANGE_STEPS_PER_SEC, MOVE_COLOUR_TEMPERATURE_MIN, MOVE_COLOUR_TEMPERATURE_MAX);
                            #endif
                            break;
                case KEY_3: /* Move Hue Up*/
                            #ifdef CLD_COLOUR_CONTROL
                                APP_ZCL_vSendHAMoveHue(E_CLD_COLOURCONTROL_MOVE_MODE_UP, HUE_CHANGE_STEPS_PER_SEC);
                            #endif
                            break;
                case KEY_4: /* On*/
                            APP_ZCL_vSendHAOnOff(E_CLD_ONOFF_CMD_ON);
                            break;
                case KEY_5: /* Brightness Down*/
                            APP_ZCL_vSendHAMoveLevel(E_CLD_LEVELCONTROL_MOVE_MODE_DOWN, LEVEL_CHANGE_STEPS_PER_SEC_MED, FALSE);
                            break;
                case KEY_6: /* Move Color Temp Down*/
                            #ifdef CLD_COLOUR_CONTROL
                                APP_ZCL_vSendHAMoveColourTemperature(E_CLD_COLOURCONTROL_MOVE_MODE_DOWN, COLOUR_TEMP_CHANGE_STEPS_PER_SEC, MOVE_COLOUR_TEMPERATURE_MIN, MOVE_COLOUR_TEMPERATURE_MAX);
                            #endif
                            break;
                case KEY_7: /* Stop Move Hue*/
                            #ifdef CLD_COLOUR_CONTROL
                                APP_ZCL_vSendHAMoveHue(E_CLD_COLOURCONTROL_MOVE_MODE_STOP, 0);
                            #endif
                            break;
                case KEY_8: /* Off*/
                            APP_ZCL_vSendHAOnOff( E_CLD_ONOFF_CMD_OFF);
                            break;
                case KEY_9: /* Store Scene 1*/
                             #ifdef CLD_SCENES
                                 vAppStoreSceneById(SCENE_1, u16GroupId);
                             #endif
                             break;
                 case KEY_10: /* Store Scene 2*/
                              #ifdef CLD_SCENES
                                  vAppStoreSceneById(SCENE_2, u16GroupId);
                              #endif
                              break;
                 case KEY_11: /* Store Scene 3*/
                             #ifdef CLD_SCENES
                                vAppStoreSceneById(SCENE_3, u16GroupId);
                             #endif
                             break;
                 case KEY_12: /* Store Scene 4*/
                              #ifdef CLD_SCENES
                                vAppStoreSceneById(SCENE_4, u16GroupId);
                             #endif
                              break;
                case KEY_13: /* Shift*/
                             eShiftLevel += 1;
                             break;
                case KEY_14: /* Unicast/Groupcast Toggle*/
                             bAddrMode = !bAddrMode;
                             break;
                case KEY_15: /* Identify / Next Light*/
                             bAddrMode = FALSE;
                             vSetTheNextLightIdentify();
                             break;
                case KEY_16: /* Start discovery*/
                             vAppDiscover();
                             break;
                default : /*Default*/
                          break;
                }
                break;

            case E_SHIFT_2:
                u8SelfFR =0;
                switch(eKeyCode)
                {
                case KEY_1: /* Brightness Up*/
                            APP_ZCL_vSendHAMoveLevel(E_CLD_LEVELCONTROL_MOVE_MODE_UP, LEVEL_CHANGE_STEPS_PER_SEC_SLOW, TRUE);
                            break;
                case KEY_2: /* Move To Color Temp*/
                            #ifdef CLD_COLOUR_CONTROL
                            if(u8ColourTempIndex < 7)
                                u8ColourTempIndex++;
                            APP_ZCL_vSendHAMoveToColourTemperature(au16ColourTemperatures[u8ColourTempIndex],MOVE_TO_COLOUR_TEMP_IN_TRANSITION_TIME);
                            #endif
                            break;
                case KEY_3:/* Add group*/
                            APP_ZCL_vSendHAAddGroup( u16GroupId);
                            break;
                case KEY_4: /* On*/
                            APP_ZCL_vSendHAOnOff(E_CLD_ONOFF_CMD_ON);
                            break;
                case KEY_5: /* Brightness Down*/
                            APP_ZCL_vSendHAMoveLevel(E_CLD_LEVELCONTROL_MOVE_MODE_DOWN, LEVEL_CHANGE_STEPS_PER_SEC_SLOW, FALSE);
                            break;
                case KEY_6: /* Move To Color Temp*/
                            #ifdef CLD_COLOUR_CONTROL
                            if(u8ColourTempIndex > 0)
                                u8ColourTempIndex--;
                            APP_ZCL_vSendHAMoveToColourTemperature(au16ColourTemperatures[u8ColourTempIndex],MOVE_TO_COLOUR_TEMP_IN_TRANSITION_TIME);
                            #endif
                            break;
                case KEY_7: /* Remove Group*/
                            APP_ZCL_vSendHARemoveGroup( u16GroupId);
                            break;
                case KEY_8: /* Off*/
                            APP_ZCL_vSendHAOnOff( E_CLD_ONOFF_CMD_OFF);
                            break;
                case KEY_9: /* Goto to a Colour*/
                             #ifdef CLD_COLOUR_CONTROL
                                APP_ZCL_vSendHAMovetoHueAndSat(1);
                             #endif
                             break;
                 case KEY_10: /* Goto to a Colour*/
                            #ifdef CLD_COLOUR_CONTROL
                                APP_ZCL_vSendHAMovetoHueAndSat(0);
                            #endif
                              break;
                case KEY_11:/* Open Network*/
                            vSendPermitJoin();
                            break;
                case KEY_12: /*Channel change from any channel other than 15 to 15 or from 15 to 11*/
                             vAppChangeChannel();
                             break;
                case KEY_13: /* Shift*/
                             eShiftLevel += 1;
                             break;
                case KEY_14: /* Unicast/Groupcast Toggle*/
                             bAddrMode = !bAddrMode;
                             break;
                case KEY_15: /* Identify / Next Light*/
                             bAddrMode = FALSE;
                             vSetTheNextLightIdentify();
                             break;
                case KEY_16: /* Start discovery*/
                             vAppDiscover();
                             break;
                default:
                             break;
                }
                break;

            case E_SHIFT_3:
                switch(eKeyCode)
                 {
                     case KEY_1:
                         if(u8SelfFR==1)u8SelfFR=2;
                         break;
                    #ifdef RemoteControl
                         case KEY_2: /* Initiate EZ Find & group */
                                 DBG_vPrintf(TRACE_REMOTE_NODE,"eEZ_FindAndGroup \n");
                                 vAPP_ZCL_DeviceSpecific_SetIdentifyTime(EZMODE_TIME);
                                 eEZ_Group(u8MyEndpoint,E_EZ_INITIATOR);
                                 /* DO not sleep for EZ mode time and keep fast polling*/
                                 #ifdef SLEEP_ENABLE
                                     vLoadKeepAliveTime(EZMODE_SLEEP_TIME);
                                 #endif
                                 vStartFastPolling(EZMODE_TIME);
                                 bInEzMode = TRUE;
                                 bReadyToGroup = FALSE;
                             break;
                         case KEY_3: /* Initiate Add group if identifying */
                         {
                                uint8 u8Seq = 0;
                                tsZCL_Address sAddress;
                                tsCLD_Groups_AddGroupRequestPayload sPayload;
                                tsCLD_Identify_IdentifyRequestPayload sIdentifyPayload;

                                if(bReadyToGroup)
                                {
                                    sAddress.eAddressMode               = E_ZCL_AM_BROADCAST;
                                    sAddress.uAddress.eBroadcastMode    = ZPS_E_APL_AF_BROADCAST_RX_ON;

                                    sPayload.sGroupName.pu8Data     = (uint8*)"";
                                    sPayload.sGroupName.u8Length    = 0;
                                    sPayload.sGroupName.u8MaxLength = 0;
                                    /*Set the NwkId of light sensor as the group ID to make it unique.*/
                                    sPayload.u16GroupId             = u16LightSensorGroupId;

                                    /* Sending the Add group to the device those are identifying*/
                                    eCLD_GroupsCommandAddGroupIfIdentifyingRequestSend(
                                                            u8MyEndpoint,
                                                            1,
                                                            &sAddress,
                                                            &u8Seq,
                                                            &sPayload);

                                    memset(&sAddress,0,sizeof(tsZCL_Address));

                                    sIdentifyPayload.u16IdentifyTime = 0;

                                    /* GroupCast Identify query request */
                                    sAddress.eAddressMode               = E_ZCL_AM_GROUP;
                                    sAddress.uAddress.u16GroupAddress = u16LightSensorGroupId;

                                    eCLD_IdentifyCommandIdentifyRequestSend(
                                                            u8MyEndpoint,
                                                            1,
                                                            &sAddress,
                                                            &u8Seq,
                                                            &sIdentifyPayload);
                                }


                         }
                             break;
                    #endif
                     case KEY_4: /* On*/
                        APP_ZCL_vSendHAOnOff(E_CLD_ONOFF_CMD_ON);
                        break;

                     case KEY_5: /* Reset Self to Factory New*/
                         if (u8SelfFR==0)u8SelfFR=1;
                         if(u8SelfFR==2)
                         {
                             u8SelfFR=0;
                             DBG_vPrintf(TRACE_REMOTE_NODE,"Deleting the PDM\n");
                             PDM_vDeleteAllDataRecords();
                             vAHI_SwReset();
                         }
                     break;

                    case KEY_8: /* Off*/
                        APP_ZCL_vSendHAOnOff( E_CLD_ONOFF_CMD_OFF);
                        break;

                    case KEY_13: /* Shift*/
                        #ifdef RemoteControl
                            bReadyToGroup = FALSE;
                        #endif
                        eShiftLevel = E_SHIFT_0;
                    break;

                    case KEY_14: /* Unicast/Groupcast Toggle*/
                         bAddrMode = !bAddrMode;
                         break;
                    case KEY_15: /* Identify / Next Light*/
                         bAddrMode = FALSE;
                         vSetTheNextLightIdentify();
                         break;
                    case KEY_16: /* Start discovery*/
                         vAppDiscover();
                         break;
                     default:
                         u8SelfFR = 0;
                     break;
                 }
            break;

            default:
                 break;
    }

     /* Update LED's to reflect shift level */
     APP_vSetLeds(eShiftLevel);
     APP_vBlinkLeds(eShiftLevel);

     /*Test and send a ping to the ucast light if the switch/remote is in UCAST mode*/
     vPingUCASTTarget();
}

/****************************************************************************
 *
 * NAME: APP_vHandleKeyPress
 *
 * DESCRIPTION:
 * Handles key releases
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void APP_vHandleKeyRelease(teUserKeyCodes eKeyCode)
{
    switch(eShiftLevel)
    {
        case E_SHIFT_0:
            switch(eKeyCode)
            {
                case KEY_1: APP_ZCL_vSendHAStopLevel();
                            break;
                case KEY_2: /* Stop Move Hue*/
                            #ifdef CLD_COLOUR_CONTROL
                                APP_ZCL_vSendHAMoveHue(E_CLD_COLOURCONTROL_MOVE_MODE_STOP, 0);
                            #endif
                            break;
                case KEY_3:/* Stop Move Saturation*/
                            #ifdef CLD_COLOUR_CONTROL
                                APP_ZCL_vSendHAMoveSaturation(E_CLD_COLOURCONTROL_MOVE_MODE_STOP, 0);
                            #endif
                            break;
                case KEY_5: APP_ZCL_vSendHAStopLevel();
                            break;
                case KEY_6: /* Stop Move Hue*/
                            #ifdef CLD_COLOUR_CONTROL
                                APP_ZCL_vSendHAMoveHue(E_CLD_COLOURCONTROL_MOVE_MODE_STOP, 0);
                            #endif
                            break;
                case KEY_7:/* Stop Move Saturation*/
                            #ifdef CLD_COLOUR_CONTROL
                                APP_ZCL_vSendHAMoveSaturation(E_CLD_COLOURCONTROL_MOVE_MODE_STOP, 0);
                            #endif
                            break;
                case KEY_15: /* Stop Identifying*/
                case KEY_16:
                             if(bLightsDiscovered())
                             {
                                 /* Save the discovered device */
                                 PDM_eSaveRecordData( PDM_ID_APP_REMOTE_DEVICE_TABLE,&sDeviceState,sizeof(tsDeviceState));
                             }
                             break;
                default:
                    break;
            }
            break;

        case E_SHIFT_1:
            switch(eKeyCode)
            {
                case KEY_1: APP_ZCL_vSendHAStopLevel();
                            break;
                case KEY_2: /* Stop Move Color*/
                            #ifdef CLD_COLOUR_CONTROL
                                APP_ZCL_vSendHAMoveColourTemperature(E_CLD_COLOURCONTROL_MOVE_MODE_STOP, 0, MOVE_COLOUR_TEMPERATURE_MIN, MOVE_COLOUR_TEMPERATURE_MAX);
                            #endif
                            break;
                case KEY_5: APP_ZCL_vSendHAStopLevel();
                            break;
                case KEY_6: /* Stop Move Color*/
                            #ifdef CLD_COLOUR_CONTROL
                                APP_ZCL_vSendHAMoveColourTemperature(E_CLD_COLOURCONTROL_MOVE_MODE_STOP, 0, MOVE_COLOUR_TEMPERATURE_MIN, MOVE_COLOUR_TEMPERATURE_MAX);
                            #endif
                            break;
                case KEY_15: /* Stop Identifying*/
                case KEY_16:
                             if(bLightsDiscovered())
                             {
                                 /* Save the discovered device */
                                 PDM_eSaveRecordData( PDM_ID_APP_REMOTE_DEVICE_TABLE,&sDeviceState,sizeof(tsDeviceState));
                             }
                             break;
                default:
                    break;
            }
            break;
        case E_SHIFT_2:
            switch(eKeyCode)
            {
                case KEY_1: APP_ZCL_vSendHAStopLevel();
                            break;
                case KEY_5: APP_ZCL_vSendHAStopLevel();
                            break;
                case KEY_15: /* Stop Identifying*/
                case KEY_16:
                             if(bLightsDiscovered())
                             {
                                 /* Save the discovered device */
                                 PDM_eSaveRecordData( PDM_ID_APP_REMOTE_DEVICE_TABLE,&sDeviceState,sizeof(tsDeviceState));
                             }
                             break;
                default:
                    break;
            }
            break;
        case E_SHIFT_3:
            switch(eKeyCode)
            {
                case KEY_15: /* Stop Identifying*/
                case KEY_16:
                             if(bLightsDiscovered())
                             {
                                 /* Save the discovered device */
                                 PDM_eSaveRecordData( PDM_ID_APP_REMOTE_DEVICE_TABLE,&sDeviceState,sizeof(tsDeviceState));
                             }
                             break;
                default:
                    break;
            }
            break;
    }

    /* Update LED's to reflect shift level */
    APP_vSetLeds(eShiftLevel);
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
    zps_bAplZdpUnpackResponse(&sStackEvent,&sAfZdpEvent);

    if (ZPS_ZDP_MATCH_DESC_RSP_CLUSTER_ID == sAfZdpEvent.u16ClusterId)
    {
        if( (sAfZdpEvent.uZdpData.sMatchDescRsp.u8Status == ZPS_E_SUCCESS) &&
                (ZPS_u16AplZdoGetNwkAddr() != sAfZdpEvent.uZdpData.sMatchDescRsp.u16NwkAddrOfInterest ))
        {
            DBG_vPrintf(TRACE_REMOTE_NODE, "\nMatch SA %04x Ep %d\n",
                    sAfZdpEvent.uZdpData.sMatchDescRsp.u16NwkAddrOfInterest,
                    sAfZdpEvent.uLists.au8Data[0]);

            if (sAfZdpEvent.uZdpData.sMatchDescRsp.u8MatchLength > 0)
            {
                /*Collect the response in the structure */
                if ( sDeviceState.u8Index < NUMBER_DEVICE_TO_BE_DISCOVERED)
                {

                    DBG_vPrintf(TRACE_REMOTE_NODE, "\nBefore ADDCHK discoverd %04x at Index %d\n", sDeviceState.u8Discovered,sDeviceState.u8Index);


                    if( (sAfZdpEvent.uZdpData.sMatchDescRsp.u16NwkAddrOfInterest <= 0xFFF8) &&
                            (!bAddressInTable(sAfZdpEvent.uZdpData.sMatchDescRsp.u16NwkAddrOfInterest)))
                    {
                        DBG_vPrintf(TRACE_REMOTE_NODE, "\nSave %04x at Index %d\n", sAfZdpEvent.uZdpData.sMatchDescRsp.u16NwkAddrOfInterest,
                        sDeviceState.u8Index);

                        sDeviceState.sMatchDev[sDeviceState.u8Index].u16Address = sAfZdpEvent.uZdpData.sMatchDescRsp.u16NwkAddrOfInterest;
                        sDeviceState.sMatchDev[sDeviceState.u8Index].u8Ep = sAfZdpEvent.uLists.au8Data[0];
                        sDeviceState.u8Index++;
                        sDeviceState.u8Discovered++;
                    }


                } else {
                    DBG_vPrintf(TRACE_REMOTE_NODE, "\nLight Table Full\n");
                }
            }
            else
            {
                DBG_vPrintf(TRACE_REMOTE_NODE, "Empty match list\n");
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
            DBG_vPrintf(TRACE_REMOTE_NODE,"\nSEND_FIRST_DISCOVERY");

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
            DBG_vPrintf(TRACE_REMOTE_NODE,"\nSEND_NEXT_DISCOVERY");

            vSendMatchDesc( HA_PROFILE_ID);

            u8NumberOfDiscoveries++;

            if( u8NumberOfDiscoveries >= MAX_SERVICE_DISCOVERY )
            {
                u8CommState++;
            }
            break;

        case DISCOVERY_COMPLETE:
            DBG_vPrintf(TRACE_REMOTE_NODE,"\r\nDISCOVERY_COMPLETE");
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
        DBG_vPrintf(TRACE_REMOTE_NODE, "Allocate PDU ERR:\n");
        return;
    }

    ZPS_teStatus eStatus = ZPS_eAplZdpMatchDescRequest(hAPduInst, uDestinationAddress, FALSE, &u8TransactionSequenceNumber, &sMatch);

    if (ZPS_E_SUCCESS == eStatus)
    {
        DBG_vPrintf(TRACE_REMOTE_NODE, "Sent Match Descriptor Req P=%04x\n", u16Profile);
    }
    else
    {
        DBG_vPrintf(TRACE_REMOTE_NODE, "Match ERR: 0x%x", eStatus);
    }

    vStopStartCommissionTimer( APP_TIME_MS(START_TO_IDENTIFY_IN_MS) );

#ifdef SLEEP_ENABLE
     vReloadSleepTimers();
#endif
    vStartFastPolling(SIX_SECONDS);
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
    vStopTimer(APP_LedBlinkTimer);
    vStopTimer(APP_JoinFailedTimer);
    vStopTimer(APP_PollTimer);
    vStopTimer(APP_TickTimer);
    vStopTimer(APP_CommissionTimer);
    vStopTimer(APP_JoinTimer);
    vStopTimer(APP_BackOffTimer);
    vStopTimer(App_PingTimer);
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
 * NAME: vStartRunningTimer
 *
 * DESCRIPTION:
 * Stops the timer if it is running and starts it again
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vStartRunningTimer(OS_thSWTimer hSwTimer,uint32 u32Ticks)
{
    if(OS_eGetSWTimerStatus(hSwTimer) == OS_E_SWTIMER_RUNNING )
        OS_eStopSWTimer(hSwTimer);
    OS_eStartSWTimer(hSwTimer,u32Ticks, NULL);
}
/****************************************************************************
 *
 * NAME: APP_SleepJoinFailed
 *
 * DESCRIPTION:
 * OS Task for the Joined failed state while allowing the module to tick down
 * for sleep
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
OS_TASK(APP_SleepJoinFailed)
{
#ifdef SLEEP_ENABLE
    {
        OS_eStopSWTimer(APP_JoinFailedTimer);
        DBG_vPrintf(TRACE_REMOTE_NODE,"SleepJoinFailed u8RunningWithJoinFailedTime - %d \n", u8RunningWithJoinFailedTime);

        if(u8RunningWithJoinFailedTime==0)
        {
            #ifdef DEEP_SLEEP_ENABLE
            if (u8DeepSleepTime) {
                DBG_vPrintf(TRACE_REMOTE_NODE, "SleepJoinFailed u8DeepSleepTime %d \n", u8RunningWithJoinFailedTime, u8DeepSleepTime);
                OS_eStartSWTimer(APP_JoinFailedTimer, APP_TIME_MS(1030), NULL);
                u8DeepSleepTime--;
            }
            else
            {

                vStopAllTimers();
                DBG_vPrintf(TRACE_REMOTE_NODE, "join failed: go deep... %d\n", PWRM_u16GetActivityCount());
                PWRM_vInit(E_AHI_SLEEP_DEEP);
                bDeepSleep = TRUE;
            }
            #else
            vUpdateKeepAliveTimer();
            #endif

        }
        else
        {
            u8RunningWithJoinFailedTime--;
            DBG_vPrintf(TRACE_REMOTE_NODE, "join failed: try a rejoin\n");
            OS_eStartSWTimer(APP_JoinFailedTimer, APP_TIME_MS(1000), NULL);
        }
    }
#endif
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
#ifdef SLEEP_ENABLE
    /* Restart the keyboard scanning timer as we've come up through */
    /* warm start via the Power Manager if we get here              */
    vConfigureScanTimer();

    DBG_vPrintf(TRACE_SLEEP, "SleepTask: start poll timer\n");
    /*Incremented by one second that is equa to the wake up cycle - the sleep task would be called in every one second */
    vIncrementPingTime(((SLEEP_DURATION_MS+SCAN_DURATION_IN_MS)/1000));
    if(!bPingParent())
    {
        OS_eStartSWTimer(APP_TickTimer, APP_TIME_MS(SCAN_DURATION_IN_MS), NULL);
    }
    else
    {
        /* 4 Seconds fixed as the immediate parent should reply back by then - this values can be fixed*/
        /* This values can be increased to 8 (or more to be fail safe) if required */
        OS_eStartSWTimer(App_PingTimer,APP_TIME_MS(10000),NULL);
        /* Wait little more than 4 seconds or 8 ( or more to be fail safe)depending on above - this values can be fixed*/
        vStayAliveForPingResp(11);
    }
    ZPS_eAplZdoPoll();
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
    DBG_vPrintf(TRACE_REMOTE_NODE, "vWakeCallBack\n");

    vConfigureScanTimer();
}
#endif

/****************************************************************************
 *
 * NAME: APP_PollTask
 *
 * DESCRIPTION:
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
OS_TASK(APP_PollTask)
{
    uint8 a;
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
            DBG_vPrintf(TRACE_REMOTE_NODE, "\nFast Poll = %d \n", u16FastPoll );
        }
        vStartStopTimer(APP_PollTimer, u32PollPeriod, &a,a);

        ZPS_teStatus u8PStatus;

        u8PStatus = ZPS_eAplZdoPoll();
        if( u8PStatus )
        {
            DBG_vPrintf(TRACE_REMOTE_NODE, "\nPoll Failed \n", u8PStatus );
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
        /* DBG_vPrintf(TRACE_REMOTE_NODE, "Table: %04x, Stack: %04x", sDeviceState.sMatchDev[i].u16Address,u16AddressToCheck ); */

        if(sDeviceState.sMatchDev[i].u16Address == u16AddressToCheck )
        {
            DBG_vPrintf(TRACE_REMOTE_NODE, "\ndup!");
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

    DBG_vPrintf(TRACE_REMOTE_NODE, "\nClearing Table");
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
    vStopTimer(APP_CommissionTimer);
    OS_eStartSWTimer(APP_CommissionTimer, u32Ticks, NULL );
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
        APP_ZCL_vSendHAIdentify(IDENTIFY_TIME_IN_SECS);
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
            DBG_vPrintf(TRACE_REMOTE_NODE, "update Id\n");
            /* should really be in stack?? */
            ZPS_psAplZdoGetNib()->sPersist.u8UpdateId++;
        }
    }
}

/****************************************************************************
 *
 * NAME: vSendPermitJoin
 *
 * DESCRIPTION: broadcast a permit join management request, 2 minutes
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vSendPermitJoin(void) {
    PDUM_thAPduInstance hAPduInst;
    ZPS_tuAddress uDstAddr;
    ZPS_tsAplZdpMgmtPermitJoiningReq sZdpMgmtPermitJoiningReq;

    hAPduInst = PDUM_hAPduAllocateAPduInstance(apduZDP);

    if (hAPduInst == PDUM_INVALID_HANDLE)
    {
        DBG_vPrintf(TRACE_REMOTE_NODE, "IEEE Address Request - PDUM_INVALID_HANDLE\n");
    }
    else
    {
        uDstAddr.u16Addr = 0xfffc;                                  /* routers*/

        sZdpMgmtPermitJoiningReq.bTcSignificance = 0;               /* doesn't effect trust centre*/
        sZdpMgmtPermitJoiningReq.u8PermitDuration = 180;            /* 3 minutes*/

        ZPS_eAplZdpMgmtPermitJoiningRequest(
            hAPduInst,
            uDstAddr,
            FALSE,  
            NULL,   
            &sZdpMgmtPermitJoiningReq);
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
PRIVATE void app_vRestartNode (void)
{
    ZPS_tsNwkNib * thisNib;

    /* Get the NWK Handle to have the NWK address from local node and use it as GroupId*/
    thisNib = ZPS_psNwkNibGetHandle(ZPS_pvAplZdoGetNwkHandle());

    /* The node is in running state indicates that
     * the EZ Mode state is as E_EZ_DEVICE_IN_NETWORK*/
    eEZ_UpdateEZState(E_EZ_DEVICE_IN_NETWORK);

    DBG_vPrintf(TRACE_REMOTE_NODE, "\nNon Factory New Start");

    ZPS_vSaveAllZpsRecords();
    u16GroupId = thisNib->sPersist.u16NwkAddr;
    /* Start 1 seconds polling */
    OS_eStartSWTimer(APP_PollTimer,POLL_TIME, NULL);

    bAddrMode = TRUE;

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
    eEZ_UpdateEZState(E_EZ_START);

    /* Stay awake for joining */
    DBG_vPrintf(TRACE_REMOTE_NODE, "\nFactory New Start");
    vStartStopTimer( APP_JoinTimer, APP_TIME_MS(1000),(uint8*)&(sDeviceDesc.eNodeState),E_STARTUP );
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
    DBG_vPrintf(TRACE_REMOTE_NODE, "\n%s - Addr: 0x%016llx, Action: 0x%02x Flags: 0x%02x\n", __FUNCTION__, u64TargetAddr, u8Action, u8Flags);

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
            DBG_vPrintf(TRACE_REMOTE_NODE, "Set the state to Rejoining \n\n");
            sDeviceDesc.eNodeState = E_REJOINING;
            /* Leave the network and children but rejoin */
            ZPS_eAplZdoLeaveNetwork(0,TRUE,TRUE);
            bUse_Stack_Leave=FALSE;
        #else
            /* Wait for ZPS_EVENT_NWK_LEAVE_CONFIRM event which will
               confirm the responses have gone out then erase PDM and
               reset. */
            DBG_vPrintf(TRACE_REMOTE_NODE, "Set the state to leave \n\n");
            sDeviceDesc.eNodeState = E_LEAVE_WAIT;
        #endif
        }
        else
            /* Leave with Rejoin - The stack will attempt once and
              * if it can not it would bring it back to rejoin state machine
              * to take it further.
              * */
        {
            DBG_vPrintf(TRACE_REMOTE_NODE, "Set the state to Rejoining \n\n");
            sDeviceDesc.eNodeState = E_REJOINING;

        }
    }
    return bUse_Stack_Leave;
}

#ifdef RemoteControl
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
            DBG_vPrintf(TRACE_REMOTE_NODE, " APP : E_HA_EZ_BIND_CREATED_FOR_TARGET\n");


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
            DBG_vPrintf(TRACE_REMOTE_NODE, " APP : E_EZ_GROUP_CREATED_FOR_TARGET\n");

        }
            break;

        case E_EZ_CHECK_FOR_GROUP_FOR_TARGET:
        {
            DBG_vPrintf(TRACE_REMOTE_NODE, " APP : E_EZ_CHECK_FOR_GROUP_FOR_TARGET\n");
            uint8 u8Seq;
            tsZCL_Address sAddress;
            tsCLD_Identify_IdentifyRequestPayload sPayload;

            if(psCallBackEvent->psAfZdpEvent->uZdpData.sSimpleDescRsp.sSimpleDescriptor.u16DeviceId == 262)
            {
                u16LightSensorGroupId = psCallBackEvent->psAfZdpEvent->uZdpData.sSimpleDescRsp.u16NwkAddrOfInterest;
                sPayload.u16IdentifyTime = 0;
                sAddress.eAddressMode = E_ZCL_AM_SHORT_NO_ACK;
                sAddress.uAddress.u16DestinationAddress = psCallBackEvent->u16TargetAddress;

                eCLD_IdentifyCommandIdentifyRequestSend(
                                        psCallBackEvent->u8InitiatorEp,
                                        psCallBackEvent->u8TargetEp,
                                        &sAddress,
                                        &u8Seq,
                                        &sPayload);

                /* Light sensor Found , stop fast polling */
                bReadyToGroup = TRUE;
                vStartFastPolling(STOP_FAST_POLL);

            }
            psCallBackEvent->bAllowBindOrGroup = FALSE;

        }
            break;

        case E_EZ_TIMEOUT:
            DBG_vPrintf(TRACE_REMOTE_NODE, "EZ mode timed out\r\n");
            vAPP_ZCL_DeviceSpecific_IdentifyOff();
            /* EZ mode timed out so reset flags */
            bInEzMode = FALSE;
            bReadyToGroup = FALSE;
            break;

        default:
            DBG_vPrintf(TRACE_REMOTE_NODE, "Invalid event type\r\n");
            break;
    }
}
#endif
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

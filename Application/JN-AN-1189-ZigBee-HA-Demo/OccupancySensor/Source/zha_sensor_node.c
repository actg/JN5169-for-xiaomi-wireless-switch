/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          zha_sensor_node.c
 *
 * DESCRIPTION:        ZHA Demo : Stack <-> Occupancy Sensor App Interaction
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
#include "rnd_pub.h"
#include "app_common.h"
#include "groups.h"
#include "PDM_IDs.h"
#include "app_timer_driver.h"
#include "zha_sensor_node.h"
#include "app_zcl_sensor_task.h"
#include "app_zbp_utilities.h"
#include "app_events.h"
#include "zcl_customcommand.h"
#include "GenericBoard.h"
#include "ha.h"
#include "haEzJoin.h"
#include "haEzFindAndBind.h"
#include "app_sensor_state_machine.h"
#include "zcl_common.h"
#include "app_reporting.h"
#include "haKeys.h"

#include "app_occupancy_buttons.h"
#include "app_sleep_handler.h"
#include "app_event_handler.h"
#include "app_nwk_event_handler.h"
#include "app_blink_led.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifdef DEBUG_SENSOR_NODE
    #define TRACE_SENSOR_NODE   TRUE
#else
    #define TRACE_SENSOR_NODE   FALSE
#endif

#define WAKE_FROM_DEEP_SLEEP     (1<<11)




/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
PRIVATE void app_vStartNodeFactoryNew(void);
PRIVATE void app_vRestartNode (void);

PRIVATE void vAppHandleStackEvent(ZPS_tsAfEvent sStackEvent);

PRIVATE bool_t bCheckIsZCLEvent(ZPS_tsAfEvent sAppStackEvent);


PRIVATE void vDeletePDMOnButtonPress(uint8 u8ButtonDIO);
PRIVATE bool_t bHandleZdoLeaveRequest(uint8 u8Action, uint64 u64TargetAddr, uint8 u8Flags);
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

PUBLIC PDM_tsRecordDescriptor sDevicePDDesc;
PUBLIC  tsDeviceDesc           sDeviceDesc;

//#define APP_IGNORE_LEAVE_WITHOUT_REJOIN

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

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
    PDM_teStatus eStatusReportReload;
    DBG_vPrintf(TRACE_SENSOR_NODE, "\nAPP Sensor Node: APP_vInitialiseNode*");

    vGenericLEDInit();
    /*Initialise the application buttons*/
    /* Initialise buttons; if a button is held down as the device is reset, delete the device
     * context from flash
     */

    APP_bButtonInitialise();

    /* We need to get the previous state out off NVM and save it*/
    sSensor.sOccupancySensingServerCluster.u8Occupancy = bGetPreSleepOccupancyState();
    vGenericLEDSetOutput(1, sSensor.sOccupancySensingServerCluster.u8Occupancy);

    /*In case of a deep sleep device any button wake up would cause a PDM delete , only check for DIO8
     * pressed for deleting the context */
    DBG_vPrintf(TRACE_SENSOR_NODE, "\nAPP Sensor Node: u16AHI_PowerStatus() = %d", u16AHI_PowerStatus());

    if (FALSE == (u16AHI_PowerStatus() & WAKE_FROM_DEEP_SLEEP))
    {
        vDeletePDMOnButtonPress(APP_BUTTONS_BUTTON_1);
    }

    /* Restore any report data that is previously saved to flash */
    eStatusReportReload = eRestoreReports();
    uint16 u16ByteRead;
    PDM_eReadDataFromRecord(PDM_ID_APP_REMOTE_CONTROL,
                                               &sDeviceDesc,
                                               sizeof(tsDeviceDesc),
                                               &u16ByteRead);


    /* Initialise ZBPro stack */
    ZPS_vAplSecSetInitialSecurityState(ZPS_ZDO_PRECONFIGURED_LINK_KEY, (uint8 *)&s_au8LnkKeyArray, 0x00, ZPS_APS_GLOBAL_LINK_KEY);
    DBG_vPrintf(TRACE_SENSOR_NODE, "\nAPP Sensor Node: Set Sec state");

    vEZ_RestoreDefaultAIBChMask();
    /* Initialize ZBPro stack */
    ZPS_eAplAfInit();

    DBG_vPrintf(TRACE_SENSOR_NODE, "\nAPP Sensor Node: ZPS_eAplAfInit");
    /*Set Save default channel mask as it is going to be manipulated */
    vEZ_SetDefaultAIBChMask();

    APP_ZCL_vInitialise();

    /*Load the reports from the PDM or the default ones depending on the PDM load record status*/
    if(eStatusReportReload !=PDM_E_STATUS_OK )
    {
        /*Load Defaults if the data was not correct*/
        vLoadDefaultConfigForReportable();
    }
    /*Make the reportable attributes */
    vMakeSupportedAttributesReportable();

    /* If the device state has been restored from flash, re-start the stack
     * and set the application running again.
     */

    if (sDeviceDesc.eNodeState == E_RUNNING)
    {
        /*The following Patch ensures the device will set the address allocate flag will set to FALSE during rejoin in future*/
        void* pvNwk;
        pvNwk = ZPS_pvAplZdoGetNwkHandle();
        ZPS_psNwkNibGetHandle( pvNwk)->sPersist.u8CapabilityInformation &= 0x7f;
        DBG_vPrintf(TRACE_SENSOR_NODE,"\nThe sNib.sPersist.u8CapabilityInformation = %02x",ZPS_psNwkNibGetHandle( pvNwk)->sPersist.u8CapabilityInformation);

        DBG_vPrintf(TRACE_SENSOR_NODE, "\nAPP Sensor Node: Running");
        app_vRestartNode();
    }
    else
    {
        app_vStartNodeFactoryNew();
    }

       /* Register callback that will handle ZDP (mgmt) leave requests */
       ZPS_vAplZdoRegisterZdoLeaveActionCallback(bHandleZdoLeaveRequest);

    #ifdef PDM_EEPROM
        vDisplayPDMUsage();
    #endif
}


/****************************************************************************
 *
 * NAME: APP_InitialiseTasks
 *
 * DESCRIPTION:
 * This is the main OS Initialise.
 * Task that checks the power status and starts tasks based on those results
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
OS_TASK(APP_InitialiseTasks)
{
    DBG_vPrintf(TRACE_SENSOR_NODE, "APP Initialise Tasks: Power Status = %d", u16AHI_PowerStatus());

    if (sDeviceDesc.eNodeState == E_RUNNING)
    {
        vActionOnButtonActivationAfterDeepSleep();
        ZPS_eAplZdoRejoinNetwork(FALSE);
    }
    else
    {
        /* We are factory new so start the join timers*/
        vStartStopTimer( APP_JoinTimer, APP_TIME_MS(1000),(uint8*)&(sDeviceDesc.eNodeState),E_STARTUP );
        vStartBlinkTimer(APP_JOINING_BLINK_TIME);
        OS_eActivateTask(APP_ZHA_Sensor_Task);
    }
}

/****************************************************************************
 *
 * NAME: APP_ZHA_Sensor_Task
 *
 * DESCRIPTION:
 * Checks to see what event has triggered the task to start and calls the
 * appropriate function. This handles App events, Stack events, timer activations
 * and manual activations.
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
OS_TASK(APP_ZHA_Sensor_Task)
{
    APP_tsEvent sAppEvent;
    ZPS_tsAfEvent sAppStackEvent;
    sAppStackEvent.eType = ZPS_EVENT_NONE;
    sAppEvent.eType = APP_E_EVENT_NONE;
    /*Collect the application events*/

    if (OS_eCollectMessage(APP_msgEvents, &sAppEvent) == OS_E_OK)
    {
        DBG_vPrintf(TRACE_SENSOR_NODE, "\nAPP ZHA Sensor Task: App Event");
        vAppHandleAppEvent(sAppEvent);
    }

    else if(OS_eCollectMessage(APP_msgZpsEvents, &sAppStackEvent) == OS_E_OK)
    {

        if (TRUE == bCheckIsZCLEvent(sAppStackEvent))
        {
            DBG_vPrintf(TRACE_SENSOR_NODE, "\nAPP ZHA Sensor Task: ZCL Event");
            vAPP_ZCL_SendStackEventToZCL(sAppStackEvent);

        }
        else
        {
            DBG_vPrintf(TRACE_SENSOR_NODE, "\nAPP ZHA Sensor Task: Main APP Handle");
            vAppHandleStackEvent(sAppStackEvent);
        }

    }
    else
    {
        DBG_vPrintf(TRACE_SENSOR_NODE, "\nAPP ZHA Sensor Task: Timer/Manual OS Event");
        vAppHandleStackEvent(sAppStackEvent);
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
    DBG_vPrintf(TRACE_SENSOR_NODE, "\n%s - Addr: 0x%016llx, Action: 0x%02x Flags: 0x%02x\n", __FUNCTION__, u64TargetAddr, u8Action, u8Flags);

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
            DBG_vPrintf(TRACE_SENSOR_NODE, "Set the state to Rejoining \n\n");
            sDeviceDesc.eNodeState = E_REJOINING;
            /* Leave the network and children but rejoin */
            ZPS_eAplZdoLeaveNetwork(0,TRUE,TRUE);
            bUse_Stack_Leave=FALSE;
        #else
            /* Wait for ZPS_EVENT_NWK_LEAVE_CONFIRM event which will
               confirm the responses have gone out then erase PDM and
               reset. */
            DBG_vPrintf(TRACE_SENSOR_NODE, "Set the state to leave \n\n");
            sDeviceDesc.eNodeState = E_LEAVE_WAIT;
        #endif
        }
        else
            /* Leave with Rejoin - The stack will attempt once and
              * if it can not it would bring it back to rejoin state machine
              * to take it further.
              * */
        {
            DBG_vPrintf(TRACE_SENSOR_NODE, "Set the state to Rejoining \n\n");
            sDeviceDesc.eNodeState = E_REJOINING;

        }
    }
    return bUse_Stack_Leave;
}

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
    (void)u32AHI_DioInterruptStatus();
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
        DBG_vPrintf(TRACE_SENSOR_NODE,"\nAPP Sensor Node: Deleting the PDM");
        PDM_vDeleteAllDataRecords();
    }
}



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
            DBG_vPrintf(TRACE_SENSOR_NODE, "\nAPP Sensor Node: E_HA_EZ_BIND_CREATED_FOR_TARGET");


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
            DBG_vPrintf(TRACE_SENSOR_NODE, "\nAPP Sensor Node: E_EZ_GROUP_CREATED_FOR_TARGET");

        }
            break;

        case E_EZ_TIMEOUT:
            /**/
            break;
        default:
            DBG_vPrintf(TRACE_SENSOR_NODE, "\nAPP Sensor Node: Invalid event type");
            break;
    }
}


/****************************************************************************
 *
 * NAME: vAppHandleStackEvent
 *
 * DESCRIPTION:
 * This is the main state machine which decides whether to call up the startup
 * or running function. This depends on whether we are in the network on not.
 *
 * PARAMETERS:
 * ZPS_tsAfEvent sAppStackEvent Stack event information.
 *
 ****************************************************************************/
PRIVATE void vAppHandleStackEvent(ZPS_tsAfEvent sStackEvent)
{
#ifdef DEBUG_SENSOR_NODE
    vDisplayStackEvent(sStackEvent);
#endif


    /* Handle events depending on node state */
    switch (sDeviceDesc.eNodeState)
    {
        case E_STARTUP:
            vAppHandleStartup(sStackEvent, E_EZ_JOIN);
            break;
        case E_REJOINING:
            vAppHandleStartup(sStackEvent, E_EZ_REJOIN);
            break;
        case E_RUNNING:
            vAppHandleRunning(sStackEvent);
            break;
        default:
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

    /* The node is in running state indicates that
     * the EZ Mode state is as E_EZ_DEVICE_IN_NETWORK*/
    eEZ_UpdateEZState(E_EZ_DEVICE_IN_NETWORK);

    DBG_vPrintf(TRACE_SENSOR_NODE, "\nNon Factory New Start");

    ZPS_vSaveAllZpsRecords();

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
    DBG_vPrintf(TRACE_SENSOR_NODE, "\nAPP Sensor Node: Factory New Start");
}

/****************************************************************************
 *
 * NAME: bCheckIsZCLEvent
 *
 * DESCRIPTION:
 * Checks to see if the destination endpoint is 1 meaning a message needs
 * to be passed to the ZCL
 *
 * PARAMETERS:
 * ZPS_tsAfEvent sAppStackEvent Stack event information.
 *
 * RETURNS:
 * bool_t whether the event is for the ZCL (TRUE) or not (FALSE)
 *
 ****************************************************************************/
PRIVATE bool_t bCheckIsZCLEvent(ZPS_tsAfEvent sAppStackEvent)
{
    switch(sAppStackEvent.eType)
    {
        case ZPS_EVENT_APS_DATA_INDICATION:
            if (OCCUPANCYSENSOR_SENSOR_ENDPOINT == sAppStackEvent.uEvent.sApsDataIndEvent.u8DstEndpoint)
                return TRUE;
            else
                return FALSE;
            break;
        case ZPS_EVENT_APS_DATA_CONFIRM:
            if (OCCUPANCYSENSOR_SENSOR_ENDPOINT == sAppStackEvent.uEvent.sApsDataConfirmEvent.u8DstEndpoint)
                return TRUE;
            else
                return FALSE;
            break;
        default:
            return FALSE;
    }
}

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

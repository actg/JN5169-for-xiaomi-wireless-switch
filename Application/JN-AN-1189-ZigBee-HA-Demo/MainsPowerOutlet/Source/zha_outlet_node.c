/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          zha_outlet_node.c
 *
 * DESCRIPTION:        ZHA Demo : Stack <-> Outlet - App Interaction (Implementation)
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
 * Copyright NXP B.V. 2014. All rights reserved
 *
 ***************************************************************************/
/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include <jendefs.h>
#include <string.h>
#include <rnd_pub.h>
#include "dbg.h"
#include "os.h"
#include "os_gen.h"
#include "pdum_gen.h"
#include "pdm.h"
#include "pdum_gen.h"
#include "zps_gen.h"
#include "zps_apl.h"
#include "zps_apl_aib.h"
#include "zps_nwk_sap.h"
#include "app_common.h"
#include "app_buttons.h"
#include "app_events.h"
#include "app_zcl_outlet_task.h"
#include "zha_outlet_node.h"
#include "ha.h"
#include "haEzJoin.h"
#include "haEzFindAndBind.h"
#include "app_reporting.h"
#include "app_scenes.h"
#include "app_pdm.h"
#include "PDM_IDs.h"
#include "zcl_options.h"
#include "app_zbp_utilities.h"
#include "App_MainsPowerOutlet.h"
#include "AgeChildren.h"
#include "app_scenes.h"
//#include "app_management_bind.h"
#include "app_status_led.h"
#include "zcl_common.h"
#include "app_buttons.h"
#include <AppHardwareApi.h>
#include "DriverOutlet.h"
#include "app_power_on_counter.h"

#ifdef CLD_GROUPS
    #include "groups.h"
    #include "Groups_internal.h"
#endif

#ifdef CLD_OTA
    #include "OTA.h"
    #include "app_ota_client.h"
#else
    #include "haKeys.h"
#endif

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifdef DEBUG_OUTLET_NODE
    #define TRACE_OUTLET_NODE   TRUE
#else
    #define TRACE_OUTLET_NODE   FALSE
#endif

#define CONFIG_ENABLE_FACTORY_NEW_CADENCE TRUE
#if (CONFIG_ENABLE_FACTORY_NEW_CADENCE == TRUE)
    #define vIndicateJoined()        vStartEffect(E_CLD_IDENTIFY_EFFECT_STOP_EFFECT)
#else
    #if (CONFIG_BLINK_ON_JOIN == TRUE)
        #define vIndicateJoined()    vStartEffect(0)
    #else
        /* No effect */
        #define vIndicateJoined()
    #endif
#endif

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
PRIVATE void app_vRestartNode (void);
PRIVATE void app_vStartNodeFactoryNew(void);
PRIVATE void vHandleAppEvent(APP_tsEvent * psAppEvent);
PRIVATE void vHandlePorEvent(APP_tsEvent * sAppPorEvent);
PRIVATE void vHandleStartUp( ZPS_tsAfEvent *pZPSevent );
PRIVATE void vHandleRunningEvent(ZPS_tsAfEvent *sStackEvent);
PRIVATE void vHandleZdoLeaveRequest(uint8 u8Action, uint64 u64TargetAddr, uint8 u8Flags);

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
tsDeviceDesc sDeviceDesc;
bool_t bResetFactoryNew = FALSE;

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
    PDM_teStatus eStatus;
    PDM_teStatus eStatusReportReload;

    DBG_vPrintf(TRACE_OUTLET_NODE, "\nAPP_vInitialiseNode*");

    vManagePowerOnCountLoadRecord();

    /* Initialise the application buttons */
    bResetFactoryNew = DriverOutlet_bIsButtonDown();

    #ifdef CLD_OTA
        vLoadOTAPersistedData();
    #endif

    /* Restore any report data that is previously saved to flash */
    eStatusReportReload = eRestoreReports();

    /* Restore device state previously saved to flash */
    eStatus = eRestoreDeviceState();

    /* Load Scenes */
    vLoadScenesNVM();

    ZPS_vAplSecSetInitialSecurityState(ZPS_ZDO_PRECONFIGURED_LINK_KEY, (uint8 *)&s_au8LnkKeyArray, 0x00, ZPS_APS_GLOBAL_LINK_KEY);

    vEZ_RestoreDefaultAIBChMask();

    /* Initialize ZBPro stack */
    ZPS_eAplAfInit();

    /* Set Save default channel mask as it is going to be manipulated */
    vEZ_SetDefaultAIBChMask();
    APP_ZCL_vInitialise();

    /* Load the reports from the PDM or the default ones depending on the PDM load record status */
    if(eStatusReportReload !=PDM_E_STATUS_RECOVERED )
    {
        /* Load Defaults if the data was not correct */
        vLoadDefaultConfigForReportable();
    }

    /*Make the reportable attributes */
    vMakeSupportedAttributesReportable();

    if (E_RUNNING == eGetNodeState())
    {
        app_vRestartNode();
    }
    else
    {
        app_vStartNodeFactoryNew();
    }

    /* Start Child Aging Code */
    OS_eStartSWTimer(APP_AgeOutChildrenTmr, APP_TIME_MS(1600), NULL);

    #ifdef CLD_OTA
        vAppInitOTA();
    #endif

    vManagePowerOnCountInit();

    /* Register callback that will handle ZDP (mgmt) leave requests */
    ZPS_vAplZdoRegisterZdoLeaveActionCallback(vHandleZdoLeaveRequest);
}

/****************************************************************************
 *
 * NAME: APP_ZPR_OnOffOutput_Task
 *
 * DESCRIPTION:
 * Task that handles application related functions
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
OS_TASK(APP_ZPR_Outlet_Task)
{
    ZPS_tsAfEvent sStackEvent = {0};
    APP_tsEvent sAppPorEvent = {0};
    APP_tsEvent sAppEvent = {0};

    DBG_vPrintf(TRACE_OUTLET_NODE, "\n\nPOR Identify\n\n");

    /* The context clearing event for the SSL bulbs */
    if (OS_eCollectMessage(APP_msgPOREvents, &sAppPorEvent) == OS_E_OK)
    {
        DBG_vPrintf(TRACE_OUTLET_NODE, "\n\nPOR Event: %d", sAppPorEvent.eType);
        vHandlePorEvent(&sAppPorEvent);
    }
    /* Collect the application events */
    else if (OS_eCollectMessage(APP_msgEvents, &sAppEvent) == OS_E_OK)
    {
        DBG_vPrintf(TRACE_OUTLET_NODE, "\n\nAPP Event: %d", sAppEvent.eType);
        vHandleAppEvent(&sAppEvent);
    }
    /* Collect stack Events */
    else if ( OS_eCollectMessage(APP_msgZpsEvents, &sStackEvent) == OS_E_OK)
    {
        DBG_vPrintf(TRACE_OUTLET_NODE, "\n\nStack Event");

        #ifdef DEBUG_OUTLET_NODE
            vDisplayStackEvent(sStackEvent);
        #endif
    }

    /* Handle events depending on node state */
    switch (sDeviceDesc.eNodeState)
    {
        case E_STARTUP:
            DBG_vPrintf(TRACE_OUTLET_NODE, "\nE_STARTUP" );
            vHandleStartUp(&sStackEvent);
            break;

        case E_RUNNING:
            DBG_vPrintf(TRACE_OUTLET_NODE, "E_RUNNING\r\n");
            vHandleRunningEvent(&sStackEvent);
            break;

        case E_LEAVE_WAIT:
            DBG_vPrintf(TRACE_OUTLET_NODE, "E_LEAVE_WAIT\r\n");
            vStartStopTimer(APP_StartUPTimer, APP_TIME_MS(500), (uint8*)&(sDeviceDesc.eNodeState), E_LEAVE_RESET);
            break;

        case E_LEAVE_RESET:
            DBG_vPrintf(TRACE_OUTLET_NODE, "E_LEAVE_RESET\r\n");
            PDM_vDeleteAllDataRecords();
            vAHI_SwReset();
            break;

        default:
            DBG_vPrintf(TRACE_OUTLET_NODE, "ERR: Unknown State %d\n", sDeviceDesc.eNodeState );
            break;
    }

    /* Global clean up to make sure any APDUs have been freed   */
    if (sStackEvent.eType == ZPS_EVENT_APS_DATA_INDICATION)
    {
        PDUM_eAPduFreeAPduInstance(sStackEvent.uEvent.sApsDataIndEvent.hAPduInst);
    }
}

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/
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
    /* The node is in running state indicates that
     * the EZ Mode state is as E_EZ_DEVICE_IN_NETWORK*/
    eEZ_UpdateEZState(E_EZ_DEVICE_IN_NETWORK);

    sDeviceDesc.eNodeState = E_RUNNING;

    /* Store the NWK frame counter increment */
    ZPS_vSaveAllZpsRecords();

    DBG_vPrintf(TRACE_OUTLET_NODE, "Restart Running\n");
    OS_eActivateTask(APP_ZPR_Outlet_Task);
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
    /* The node is in running state indicates that
     * the EZ Mode state is as E_EZ_START*/
    eEZ_UpdateEZState(E_EZ_START);

    DBG_vPrintf(TRACE_OUTLET_NODE, "\nRun and activate\n");
    vStartStopTimer(APP_StartUPTimer, APP_TIME_MS(500), (uint8*)&(sDeviceDesc.eNodeState), E_STARTUP);
    DBG_vPrintf(TRACE_OUTLET_NODE, "Start Factory New\n");
}

/****************************************************************************
 *
 * NAME: vHandleStartUp
 *
 * DESCRIPTION:
 * Handles the Start UP events
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vHandleStartUp( ZPS_tsAfEvent *pZPSevent )
{
    teEZ_State ezState;

    /* Call The EZ mode Handler passing the events */
    vEZ_EZModeNWKJoinHandler(pZPSevent,E_EZ_JOIN);
    ezState = eEZ_GetJoinState();
    DBG_vPrintf(TRACE_OUTLET_NODE, "EZ_STATE\%x r\n", ezState);

    if(ezState == E_EZ_DEVICE_IN_NETWORK)
    {
        DBG_vPrintf(TRACE_OUTLET_NODE, "HA EZMode E_EZ_DEVICE_IN_NETWORK \n");
        vStartStopTimer(APP_StartUPTimer, APP_TIME_MS(500), (uint8*)&(sDeviceDesc.eNodeState), E_RUNNING);
        vIndicateJoined();
        vEnablePermitJoin(EZ_MODE_TIME * 60);
        PDM_eSaveRecordData(PDM_ID_APP_APP_ROUTER,
                            &sDeviceDesc,
                            sizeof(tsDeviceDesc));
        ZPS_vSaveAllZpsRecords();
    }
}

/****************************************************************************
 *
 * NAME: vHandleRunningEvent
 *
 * DESCRIPTION:
 * Handles the running events
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vHandleRunningEvent(ZPS_tsAfEvent *psStackEvent)
{

    /*Request response event, call the child age logic */
    if((ZPS_EVENT_APS_DATA_INDICATION == psStackEvent->eType) &&
        (0 == psStackEvent->uEvent.sApsDataIndEvent.u8DstEndpoint))
    {
        /* check if the this is a response from my end device child, if so remove */
        vCheckIfMyChild(psStackEvent);
        #ifdef CLD_OTA
            vHandleZDPReqResForOTA(psStackEvent);
        #endif
    }

    /* Mgmt Leave Received */
    if( ZPS_EVENT_NWK_LEAVE_INDICATION == psStackEvent->eType )
    {
        DBG_vPrintf(TRACE_OUTLET_NODE, "MgmtLeave - Rejoin: %d\n", psStackEvent->uEvent.sNwkLeaveIndicationEvent.u8Rejoin);

        /* Indicates the node has to leave the NWK */
        if (0 == psStackEvent->uEvent.sNwkLeaveIndicationEvent.u64ExtAddr)
        {
            /* If no rejoin is requested then make factory new, if rejoin
               is requested do nothing as the stack will take care of it */
            if (0 == psStackEvent->uEvent.sNwkLeaveIndicationEvent.u8Rejoin)
            {
                PDM_vDeleteAllDataRecords();
                vAHI_SwReset();
            }
        }
    }

    if(ZPS_EVENT_NWK_NEW_NODE_HAS_JOINED == psStackEvent->eType)
    {
        vAgeChildren_ChildJoined(psStackEvent);
    }
}

/****************************************************************************
 *
 * NAME: vHandlePorEvent
 *
 * DESCRIPTION:
 * Stores handles the POR events based on number of resets
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vHandlePorEvent(APP_tsEvent * sAppPorEvent)
{
    if(sAppPorEvent->eType == APP_E_EVENT_POR_IDENTIFY)
    {
        DBG_vPrintf(TRACE_OUTLET_NODE, "\n\nPOR Identify\n\n");
        eEZ_FindAndBind(1,E_EZ_TARGET);
    }
    else if (sAppPorEvent->eType == APP_E_EVENT_POR_FACTORY_RESET)
    {
        DBG_vPrintf(TRACE_OUTLET_NODE, "\n\nPOR Factory Reset\n\n");

        #ifdef CLD_GROUPS
            vRemoveAllGroupsAndScenes();
        #endif

        vEZ_FactoryReset(1);
    }
    else if (sAppPorEvent->eType == APP_E_EVENT_POR_PDM_RESET)
    {
        DBG_vPrintf(TRACE_OUTLET_NODE, "\n\nPOR PDM Reset\n\n");

        ZPS_eAplZdoLeaveNetwork(0, FALSE,FALSE);
        vStartStopTimer(APP_StartUPTimer, APP_TIME_MS(1000), (uint8*)&(sDeviceDesc.eNodeState), E_LEAVE_WAIT);
    }
}

/****************************************************************************
 *
 * NAME: vHandleAppEvent
 *
 * DESCRIPTION:
 * Stores handles the POR events based on number of resets
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vHandleAppEvent(APP_tsEvent *psAppEvent)
{
    DBG_vPrintf(TRACE_OUTLET_NODE, "\n\r%s - Type: %d Button: %d", __FUNCTION__, psAppEvent->eType, psAppEvent->uEvent.sButton.u8Button);

    if ((APP_E_BUTTONS_BUTTON_1 == psAppEvent->uEvent.sButton.u8Button) &&
        (APP_E_EVENT_BUTTON_UP == psAppEvent->eType))
    {
        bool_t bOnOffAttrib;

        if (TRUE == DriverOutlet_bIsOutputOn())
        {
            DriverOutlet_vOutputOff();
            bOnOffAttrib = FALSE;
        }
        else
        {
            DriverOutlet_vOutputOn();
            bOnOffAttrib = TRUE;
        }

        /* Update cluster attribute */
        ZPS_teStatus eStatus = eZCL_WriteLocalAttributeValue(MAINSPOWEROUTLET_OUTLET_ENDPOINT,    //  u8SourceEndPointId,
                                                             HOME_AUTOMATION_ONOFF_CLUSTER_ID,    //  u16ClusterId,
                                                             TRUE,                                //  bIsServerClusterInstance,
                                                             FALSE,                                //  bIsManufacturerSpecific,
                                                             FALSE,                             //  blsClientAttribute,
                                                             E_CLD_ONOFF_ATTR_ID_ONOFF,         //  u16AttributeId,
                                                             (void *)&bOnOffAttrib);            // *pvAttributeValue

        DBG_vPrintf(TRACE_OUTLET_NODE, "\n\reZCL_WriteLocalAttributeValue: %02x", eStatus);
    }
}

/****************************************************************************
 *
 * NAME: vHandleZdoLeaveRequest
 *
 * DESCRIPTION:
 * Callback that will handle ZDP (mgmt) leave requests
 *
 * RETURNS:
 * None
 *
 ****************************************************************************/
PRIVATE void vHandleZdoLeaveRequest(uint8 u8Action, uint64 u64TargetAddr, uint8 u8Flags)
{
    DBG_vPrintf(TRACE_OUTLET_NODE, "\n%s - Addr: 0x%016llx, Action: 0x%02x Flags: 0x%02x\n", __FUNCTION__, u64TargetAddr, u8Action, u8Flags);

    /* Check this request is for us */
    if ((u64TargetAddr == ZPS_u64AplZdoGetIeeeAddr()) || (u64TargetAddr == 0ULL))
    {
        /* We respond to NLME leave requests elsewhere.. */
        if (ZPS_LEAVE_ORIGIN_MGMT_LEAVE == u8Action)
        {
            if (0 == u8Flags)
            {
                /* Wait for ZPS_EVENT_NWK_LEAVE_CONFIRM event which will
                   confirm the responses have gone out then erase PDM and
                   reset. */
                sDeviceDesc.eNodeState = E_LEAVE_WAIT;
            }
        }
    }
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
 * NAME: sGetOTACallBackPersistdata
 *
 * DESCRIPTION:
 *
 * RETURNS:
 *
 ****************************************************************************/
PUBLIC tsOTA_PersistedData sGetOTACallBackPersistdata(void)
{
    return sOnOffOutput.sCLD_OTA_CustomDataStruct.sOTACallBackMessage.sPersistedData;
}

/****************************************************************************
 *
 * NAME: psGetOTACallBackPersistdata
 *
 * DESCRIPTION:
 *
 * RETURNS:
 *
 ****************************************************************************/
PUBLIC tsOTA_PersistedData * psGetOTACallBackPersistdata(void)
{
    return (&(sOnOffOutput.sCLD_OTA_CustomDataStruct.sOTACallBackMessage.sPersistedData));
}
#endif

#ifndef CLD_OTA
/****************************************************************************
 *
 * NAME: App_TimeReadJitterTask
 *
 * DESCRIPTION:
 *
 * RETURNS:
 *
 ****************************************************************************/
OS_TASK(App_TimeReadJitterTask)
{
}
#endif

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

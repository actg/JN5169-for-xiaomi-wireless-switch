/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          zha_light_node.c
 *
 * DESCRIPTION:        ZHA Demo : Stack <-> Light-App Interaction (Implementation)
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
#include "ledcontrol.h"
#include "app_events.h"
#include <rnd_pub.h>
#include "app_zcl_light_task.h"
#include "zha_light_node.h"
#include "ha.h"
#include "haEzJoin.h"
#include "haEzFindAndBind.h"
#include "DriverBulb.h"
#include "app_reporting.h"
#include "app_scenes.h"
#include "app_pdm.h"
#ifdef CLD_OTA
    #include "OTA.h"
    #include "app_ota_client.h"
#else
    #include "haKeys.h"
#endif

#ifdef CLD_GREENPOWER
  #include "App_GreenPower.h"
#endif

#include "PDM_IDs.h"
#include "zcl_options.h"
#include "LightingBoard.h"
#include "app_zbp_utilities.h"

#include "app_manage_temperature.h"
#include "AgeChildren.h"
#include "app_power_on_counter.h"
#include "app_scenes.h"


#include "zcl_common.h"

#ifdef CLD_GROUPS
    #include "groups.h"
    #include "Groups_internal.h"
#endif
#include "app_light_effect.h"
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#ifndef DEBUG_LIGHT_NODE
    #define TRACE_LIGHT_NODE   FALSE
#else
    #define TRACE_LIGHT_NODE   TRUE
#endif

#if (CONFIG_ENABLE_FACTORY_NEW_CADENCE == TRUE)
    #define BREATH_EFFECT
#endif

#ifdef BREATH_EFFECT
    #define vIndicateJoined()        vStartEffect(E_CLD_IDENTIFY_EFFECT_STOP_EFFECT)
#else
    #if (CONFIG_BLINK_ON_JOIN == TRUE)
        #define vIndicateJoined()    vStartEffect(0)
    #else
        /* No effect */
        #define vIndicateJoined()
    #endif
#endif

//#define APP_IGNORE_LEAVE_WITHOUT_REJOIN

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/


/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
PRIVATE void app_vRestartNode (void);
PRIVATE void app_vStartNodeFactoryNew(void);
PRIVATE void vHandlePorEvent(APP_tsEvent * sAppPorEvent);
PRIVATE void vHandleStartUp( ZPS_tsAfEvent *pZPSevent );
PRIVATE void vHandleRunningEvent(ZPS_tsAfEvent *sStackEvent);
PRIVATE bool_t bHandleZdoLeaveRequest(uint8 u8Action, uint64 u64TargetAddr, uint8 u8Flags);
PRIVATE void vHandleJoinAndRejoinNWK( ZPS_tsAfEvent *pZPSevent,teEZ_JoinAction eJoinAction  );

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/



/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
tsDeviceDesc sDeviceDesc;

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

    DBG_vPrintf(TRACE_LIGHT_NODE, "\nAPP_vInitialiseNode*");

    vManagePowerOnCountLoadRecord();
    #ifdef CLD_GREENPOWER
        vLoadGPData();
    #endif

    #ifdef CLD_OTA
        vLoadOTAPersistedData();
    #endif
    /* Restore any report data that is previously saved to flash */
    eStatusReportReload = eRestoreReports();

    /* Restore device state previously saved to flash */
    eRestoreDeviceState();

    /* LoadScenes */
    vLoadScenesNVM();

    ZPS_vAplSecSetInitialSecurityState(ZPS_ZDO_PRECONFIGURED_LINK_KEY, (uint8 *)&s_au8LnkKeyArray, 0x00, ZPS_APS_GLOBAL_LINK_KEY);

    vEZ_RestoreDefaultAIBChMask();
    /* Initialise ZBPro stack */
    ZPS_eAplAfInit();
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

    if (E_RUNNING == eGetNodeState())
    {
        app_vRestartNode();
    }
    else
    {
        app_vStartNodeFactoryNew();
    }

    /* Start Child Aging Code */
    OS_eStartSWTimer(APP_AgeOutChildrenTmr, APP_TIME_MS(APP_AGE_CHILDREN_START_TIME_IN_MS), NULL);
    #ifdef CLD_OTA
        vAppInitOTA();
    #endif
    /* Start up temperature management behaviour */
    OS_eStartSWTimer(APP_RadioRecalTimer, APP_TIME_MS(10000), NULL);
    APP_vManageTemperatureInit();

#ifndef CLD_COLOUR_CONTROL
    /* Second call to bulb initialisation.  This is required by the synchronus bulb      */
    /* Driver to enable the anti rebroadcast-flicker mechanism. Ignored by other drivers */
    DriverBulb_vInit();
#endif

    vManagePowerOnCountInit();


    /* Register callback that will handle ZDP (mgmt) leave requests */
    ZPS_vAplZdoRegisterZdoLeaveActionCallback(bHandleZdoLeaveRequest);
}

/****************************************************************************
 *
 * NAME: APP_ZPR_Light_Task
 *
 * DESCRIPTION:
 * Task that handles application related functions
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
OS_TASK(APP_ZPR_Light_Task)
{
    ZPS_tsAfEvent sStackEvent = {0};
    APP_tsEvent sAppPorEvent = {0};

    DBG_vPrintf(TRACE_LIGHT_NODE, "\n\nPOR Identify\n\n");

    /* The context clearing event for the SSL bulbs */
    if (OS_eCollectMessage(APP_msgPOREvents, &sAppPorEvent) == OS_E_OK)
    {
        DBG_vPrintf(TRACE_LIGHT_NODE, "\n\nPOR Event: %d", sAppPorEvent.eType);
        vHandlePorEvent(&sAppPorEvent);
    }


    /*Collect stack Events */
    else if ( OS_eCollectMessage(APP_msgZpsEvents, &sStackEvent) == OS_E_OK)
    {
        DBG_vPrintf(TRACE_LIGHT_NODE, "\n\nStack Event");

        #ifdef DEBUG_LIGHT_NODE
            vDisplayStackEvent( sStackEvent );
        #endif

    }


    /* Handle events depending on node state */
    switch (sDeviceDesc.eNodeState)
    {
        case E_STARTUP:
            DBG_vPrintf(TRACE_LIGHT_NODE, "\nE_STARTUP" );
            vHandleStartUp(&sStackEvent);
            break;
        case E_REJOINING:
            vHandleJoinAndRejoinNWK(&sStackEvent,E_EZ_REJOIN);
            DBG_vPrintf(TRACE_LIGHT_NODE, "In E_REJOIN - Kick off Tick Timer \n");

            break;
        case E_RUNNING:
            DBG_vPrintf(TRACE_LIGHT_NODE, "E_RUNNING\r\n");
            if (sStackEvent.eType == ZPS_EVENT_NWK_FAILED_TO_JOIN)
            {
                DBG_vPrintf(TRACE_LIGHT_NODE, "Start join failed tmr 1000\n");
                vStartStopTimer( APP_JoinTimer, APP_TIME_MS(1000),(uint8*)&(sDeviceDesc.eNodeState),E_REJOINING );
                DBG_vPrintf(TRACE_LIGHT_NODE, "failed join running %02x\n",sStackEvent.uEvent.sNwkJoinFailedEvent.u8Status );
            }
            vHandleRunningEvent(&sStackEvent);
            break;

        case E_LEAVE_WAIT:
            DBG_vPrintf(TRACE_LIGHT_NODE, "E_LEAVE_WAIT\r\n");
            vStartStopTimer( APP_StartUPTimer, APP_TIME_MS(500),(uint8*)&(sDeviceDesc.eNodeState),E_LEAVE_RESET );
            break;

        case E_LEAVE_RESET:
            DBG_vPrintf(TRACE_LIGHT_NODE, "E_LEAVE_RESET\r\n");
            PDM_vDeleteAllDataRecords();
            vAHI_SwReset();
            break;

        default:
            DBG_vPrintf(TRACE_LIGHT_NODE, "ERR: Unknown State %d\n", sDeviceDesc.eNodeState );
            break;
    }

    /* Global clean up to make sure any APDUs have been freed   */
    if (sStackEvent.eType == ZPS_EVENT_APS_DATA_INDICATION)
    {
        PDUM_eAPduFreeAPduInstance(sStackEvent.uEvent.sApsDataIndEvent.hAPduInst);
    }
}
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
#ifdef POLL_BUILD
    uint8 a;
    uint32 u32PollPeriod = POLL_TIME_ICONTROL;
       /* Do fast polling when the device is running */
    if(sDeviceDesc.eNodeState == E_RUNNING)
    {
        vStartStopTimer(APP_PollTimer, u32PollPeriod, &a,a);
        ZPS_teStatus u8PStatus;

        u8PStatus = ZPS_eAplZdoPoll();
        if( u8PStatus )
        {
            DBG_vPrintf(TRACE_LIGHT_NODE, "\nPoll Failed %x \n", u8PStatus );
        }
    }
#endif
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
PRIVATE void app_vRestartNode (void)
{
    /* The node is in running state indicates that
     * the EZ Mode state is as E_EZ_DEVICE_IN_NETWORK*/
    eEZ_UpdateEZState(E_EZ_DEVICE_IN_NETWORK);

    sDeviceDesc.eNodeState = E_RUNNING;

    /* Store the NWK frame counter increment */
    ZPS_vSaveAllZpsRecords();

    DBG_vPrintf(TRACE_LIGHT_NODE, "Restart Running\n");
    OS_eActivateTask(APP_ZPR_Light_Task);

	#ifdef POLL_BUILD
    	/* Start 60 seconds polling */
    	OS_eStartSWTimer(APP_PollTimer,POLL_TIME, NULL);
	#endif

    	#ifdef APP_LIGHTS_REJOIN_ON_START_UP
        vEZ_ReJoin();
    #endif    
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

    DBG_vPrintf(TRACE_LIGHT_NODE, "\nRun and activate\n");
    vStartStopTimer( APP_StartUPTimer, APP_TIME_MS(500),(uint8*)&(sDeviceDesc.eNodeState),E_STARTUP );
    DBG_vPrintf(TRACE_LIGHT_NODE, "Start Factory New\n");
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
    /*Call The EZ mode Handler passing the events*/
    vEZ_EZModeNWKJoinHandler(pZPSevent,E_EZ_JOIN);
    ezState = eEZ_GetJoinState();
    DBG_vPrintf(TRACE_LIGHT_NODE, "EZ_STATE\%x r\n", ezState);
    if(ezState == E_EZ_DEVICE_IN_NETWORK)
    {
        DBG_vPrintf(TRACE_LIGHT_NODE, "HA EZMode E_EZ_DEVICE_IN_NETWORK \n");
        vStartStopTimer( APP_StartUPTimer, APP_TIME_MS(500),(uint8*)&(sDeviceDesc.eNodeState),E_RUNNING );
        vIndicateJoined();
        vEnablePermitJoin(EZ_MODE_TIME * 60);
        PDM_eSaveRecordData(PDM_ID_APP_APP_ROUTER,
                            &sDeviceDesc,
                            sizeof(tsDeviceDesc));
        ZPS_vSaveAllZpsRecords();
		#ifdef POLL_BUILD
        	/* Start 60 seconds polling */
        	OS_eStartSWTimer(APP_PollTimer, POLL_TIME_ICONTROL, NULL);
		#endif
        #if (CONFIG_RESTORE_DIM_LEVEL == TRUE)
        {
            /* Save level to the PDM for restoration following a reset */
            APP_ZCL_SaveLightLevel(sLight.sLevelControlServerCluster.u8CurrentLevel);
        }
        #endif
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
        DBG_vPrintf(TRACE_LIGHT_NODE, "MgmtLeave - Rejoin: %d\n", psStackEvent->uEvent.sNwkLeaveIndicationEvent.u8Rejoin);

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

    /* remove device Received */
	if(ZPS_EVENT_NWK_LEAVE_CONFIRM == psStackEvent->eType )
	{
		DBG_vPrintf(TRACE_LIGHT_NODE, "Remove - Rejoin: %d\n", psStackEvent->uEvent.sNwkLeaveConfirmEvent.bRejoin);

		/* Indicates the node has to leave the NWK */
		if (0 == psStackEvent->uEvent.sNwkLeaveConfirmEvent.u64ExtAddr)
		{
			/* If no rejoin is requested then make factory new, if rejoin
			   is requested do nothing as the stack will take care of it */
			if (FALSE == psStackEvent->uEvent.sNwkLeaveConfirmEvent.bRejoin)
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
 * Stores handles the POR events basesd on number of resets
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vHandlePorEvent(APP_tsEvent * sAppPorEvent)
{

    if(sAppPorEvent->eType == APP_E_EVENT_POR_IDENTIFY )
    {
        DBG_vPrintf(TRACE_LIGHT_NODE, "\n\nPOR Identify\n\n");
        eEZ_FindAndBind(1,E_EZ_TARGET);
        #ifdef CLD_GREENPOWER
            vAppGPEnterCommissioningMode();
        #endif
    }
    #ifdef CLD_GREENPOWER
    else if(sAppPorEvent->eType == APP_E_EVENT_GP_DECOMMISSION )
    {
        DBG_vPrintf(TRACE_LIGHT_NODE, "\n\nGP Decommision\n\n");
        vAppGPEnterDeCommissioningMode();
    }
    #endif
    else if(sAppPorEvent->eType == APP_E_EVENT_POR_FACTORY_RESET )
    {
        DBG_vPrintf(TRACE_LIGHT_NODE, "\n\nPOR Factory Reset\n\n");
        #ifdef CLD_GROUPS
            vRemoveAllGroupsAndScenes();
        #endif
        vEZ_FactoryReset(1);
    }
    else if(sAppPorEvent->eType == APP_E_EVENT_POR_PDM_RESET )
    {
        DBG_vPrintf(TRACE_LIGHT_NODE, "\n\nPOR PDM Reset\n\n");

        ZPS_eAplZdoLeaveNetwork(0, FALSE,FALSE);
        vStartStopTimer( APP_StartUPTimer, APP_TIME_MS(1000),(uint8*)&(sDeviceDesc.eNodeState),E_LEAVE_WAIT );
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
    DBG_vPrintf(TRACE_LIGHT_NODE, "\n%s - Addr: 0x%016llx, Action: 0x%02x Flags: 0x%02x\n", __FUNCTION__, u64TargetAddr, u8Action, u8Flags);

    /* Set function to use stack leave as default return */
    bool_t bUse_Stack_Leave=TRUE;

    /* We respond to all leave commands so Mgmt, remove and NLME leave */
    if ( (ZPS_LEAVE_ORIGIN_MGMT_LEAVE == u8Action) &&
    	 ( (u64TargetAddr == 0) ||
    	 u64TargetAddr == ZPS_u64NwkNibGetExtAddr(ZPS_pvAplZdoGetNwkHandle()) )
       )
    {
    	DBG_vPrintf(TRACE_LIGHT_NODE, "ZPS_LEAVE_ORIGIN_MGMT_LEAVE \n\n");
        /* 	Received Mgmt Leave for self, Check rejoin bit   */
        if ( (u8Flags & 0x80)  == 0)
        {
        /* Define to ignore stack do not rejoin else use stack functionality */
        #ifdef APP_IGNORE_LEAVE_WITHOUT_REJOIN
            DBG_vPrintf(TRACE_LIGHT_NODE, "Set the state to Rejoining \n\n");
            sDeviceDesc.eNodeState = E_REJOINING;
            /* Leave the network and children but rejoin */
            ZPS_eAplZdoLeaveNetwork(0,TRUE,TRUE);
            bUse_Stack_Leave=FALSE;
        #else
            /* Wait for ZPS_EVENT_NWK_LEAVE_CONFIRM event which will
               confirm the responses have gone out then erase PDM and
               reset. */
            DBG_vPrintf(TRACE_LIGHT_NODE, "Set the state to leave \n\n");
            sDeviceDesc.eNodeState = E_LEAVE_WAIT;
        #endif
        }
        else
            /* Leave with Rejoin - The stack will attempt once and
              * if it can not it would bring it back to rejoin state machine
              * to take it further.
              * */
        {
            DBG_vPrintf(TRACE_LIGHT_NODE, "Leave the state, stack to Rejoining \n\n");
            //sDeviceDesc.eNodeState = E_REJOINING;
        }
    }

    if(ZPS_LEAVE_ORIGIN_NLME == u8Action )
    {
        if ((u8Flags & 0x40 ) == 0)
        {
        	/*Ignore and stay in the current state*/

        }
        else
        {
        	if( (u64TargetAddr == 0) ||
        		u64TargetAddr == ZPS_u64NwkNibGetExtAddr(ZPS_pvAplZdoGetNwkHandle()) )
        	{
        		DBG_vPrintf(TRACE_LIGHT_NODE, "ZPS_LEAVE_ORIGIN_NLME \n\n");
        		if((u8Flags & 0x20 ) == 0)
        		{
        	        /* Define to ignore stack do not rejoin else use stack functionality */
        	        #ifdef APP_IGNORE_LEAVE_WITHOUT_REJOIN
        	            DBG_vPrintf(TRACE_LIGHT_NODE, "Set the state to Rejoining \n\n");
        	            sDeviceDesc.eNodeState = E_REJOINING;
        	            /* Leave the network and children but rejoin */
        	            ZPS_eAplZdoLeaveNetwork(0,TRUE,TRUE);
        	            bUse_Stack_Leave=FALSE;
        	        #else
        	            /* Wait for ZPS_EVENT_NWK_LEAVE_CONFIRM event which will
        	               confirm the responses have gone out then erase PDM and
        	               reset. */
        	            DBG_vPrintf(TRACE_LIGHT_NODE, "Set the state to leave \n\n");
        	            sDeviceDesc.eNodeState = E_LEAVE_WAIT;
        	        #endif
        		}
                else
                    /* Leave with Rejoin - The stack will attempt once and
                      * if it can not it would bring it back to rejoin state machine
                      * to take it further.
                      * */
                {
                    DBG_vPrintf(TRACE_LIGHT_NODE, "Set the state to Rejoining \n\n");
                    sDeviceDesc.eNodeState = E_REJOINING;

                }

        	}
        }

    }

    return bUse_Stack_Leave;
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
    DBG_vPrintf(TRACE_LIGHT_NODE, "EZ_STATE\%x r\n", ezState);
    if(ezState == E_EZ_DEVICE_IN_NETWORK)
    {
        DBG_vPrintf(TRACE_LIGHT_NODE, "HA EZMode EVT: E_EZ_DEVICE_IN_NETWORK \n");
        vStartStopTimer( APP_JoinTimer, APP_TIME_MS(500),(uint8*)&(sDeviceDesc.eNodeState),E_RUNNING );

        PDM_eSaveRecordData(PDM_ID_APP_APP_ROUTER,
                            &sDeviceDesc,
                            sizeof(tsDeviceDesc));
        ZPS_vSaveAllZpsRecords();
		#ifdef POLL_BUILD
        	DBG_vPrintf(TRACE_LIGHT_NODE, "start poll time \n");
        	/* Start 60 seconds polling */
        	OS_eStartSWTimer(APP_PollTimer, POLL_TIME_ICONTROL, NULL);
		#endif
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
PUBLIC tsOTA_PersistedData sGetOTACallBackPersistdata(void)
{
    return sLight.sCLD_OTA_CustomDataStruct.sOTACallBackMessage.sPersistedData;
}
PUBLIC tsOTA_PersistedData * psGetOTACallBackPersistdata(void)
{
    return (&(sLight.sCLD_OTA_CustomDataStruct.sOTACallBackMessage.sPersistedData));
}
#endif

#ifndef CLD_OTA
OS_TASK(App_TimeReadJitterTask)
{

}
#endif
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

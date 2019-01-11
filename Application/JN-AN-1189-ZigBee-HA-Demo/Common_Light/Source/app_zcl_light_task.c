/*****************************************************************************
 *
 * MODULE:             JN-AN-1189 ZHA Demo
 *
 * COMPONENT:          app_zcl_light_task.c
 *
 * DESCRIPTION:        ZHA Light Application Behavior - Implementation
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
 * Copyright NXP B.V. 2012. All rights reserved
 *
 ***************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#include <jendefs.h>
#include <string.h>
#include "os.h"
#include "os_gen.h"
#include "pdum_gen.h"
#include "pdm.h"
#include "dbg.h"
#include "zps_gen.h"
#include "PDM_IDs.h"
#include "zcl_options.h"
#include "zps_apl_af.h"
#include "ha.h"
#include "Diagnostics.h"


#ifdef CLD_GREENPOWER
  #include "App_GreenPower.h"
#endif

#include "app_zcl_light_task.h"
#include "zha_light_node.h"
#include "app_common.h"
#include "app_events.h"
#include "app_manage_temperature.h"
#include "app_light_interpolation.h"

#include "DriverBulb.h"

#include "haEzFindAndBind.h"
#include "haEzJoin.h"
#include "app_light_effect.h"
#include "app_scenes.h"

#ifdef CLD_OTA
    #include "ota.h"
    #include "app_ota_client.h"
#endif

#ifdef CLD_GROUPS
    #include "groups.h"
    #include "Groups_internal.h"
#endif

#include "app_reporting.h"
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifdef DEBUG_ZCL
    #define TRACE_ZCL   TRUE
#else
    #define TRACE_ZCL   FALSE
#endif

#ifdef DEBUG_LIGHT_TASK
    #define TRACE_LIGHT_TASK  TRUE
#else
    #define TRACE_LIGHT_TASK FALSE
#endif

#ifdef DEBUG_PATH
    #define TRACE_PATH  TRUE
#else
    #define TRACE_PATH  FALSE
#endif

#define CLAMP(x, low, high)  (((x) > (high)) ? (high) : (((x) < (low)) ? (low) : (x)))

#if (CONFIG_ENABLE_FACTORY_NEW_CADENCE == TRUE)
    #define BREATH_EFFECT
#endif

#ifdef CLD_SIMPLE_METERING
    #define LAMP_DEMAND_WATTS_MAX        11
#endif

/* 2 second delay before saving level */
#define LEVEL_SAVE_DELAY_10MS     (200)

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/


/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
PRIVATE void APP_ZCL_cbGeneralCallback(tsZCL_CallBackEvent *psEvent);
PRIVATE void APP_ZCL_cbEndpointCallback(tsZCL_CallBackEvent *psEvent);
#ifdef CLD_BAS_CMD_RESET_TO_FACTORY_DEFAULTS
PRIVATE void APP_ZCL_vHandleBasicFactoryReset( void);
#endif
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

#ifdef CLD_SIMPLE_METERING
    PRIVATE float fCurrentSummationDelivered = 0;
#endif

#if (CONFIG_RESTORE_DIM_LEVEL == TRUE)
uint8  u16LevelChangeTick = 0;
#endif

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

/****************************************************************************
 *
 * NAME: APP_ZCL_vInitialise
 *
 * DESCRIPTION:
 * Initialises ZCL related functions
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_ZCL_vInitialise(void)
{
    teZCL_Status eZCL_Status;

    /* Initialise ZHA */
    eZCL_Status = eHA_Initialise(&APP_ZCL_cbGeneralCallback, apduZCL);
    if (eZCL_Status != E_ZCL_SUCCESS)
    {
        DBG_vPrintf(TRACE_ZCL, "\nErr: eHA_Initialise:%d", eZCL_Status);
    }

    /* Start the tick timer */
    OS_eStartSWTimer(APP_TickTimer, TEN_HZ_TICK_TIME, NULL);

    /* Register EndPoint */
    eZCL_Status = eApp_HA_RegisterEndpoint(&APP_ZCL_cbEndpointCallback);

    if (eZCL_Status != E_ZCL_SUCCESS)
    {
            DBG_vPrintf(TRACE_ZCL, "Error: eApp_HA_RegisterEndpoint:%d\r\n", eZCL_Status);
    }

    #ifdef CLD_GREENPOWER
        vApp_RegisterGPDevice(&APP_ZCL_cbEndpointCallback);
    #endif

    #ifdef CLD_LEVEL_CONTROL
    {
        #if (CONFIG_RESTORE_DIM_LEVEL == TRUE)
        {
            /* Only restore previous level if device is a member of a network */
            if (E_RUNNING == eGetNodeState())
            {
                uint16 u16BytesRead;
                PDM_teStatus eStatus = PDM_eReadDataFromRecord(PDM_ID_APP_LIGHT_LEVEL,
                                                           &sLight.sLevelControlServerCluster.u8CurrentLevel,
                                                           sizeof(uint8),
                                                           &u16BytesRead);

                DBG_vPrintf(TRACE_ZCL, "\nReading Dim Level Status: %d - Bytes Read: %d", eStatus, u16BytesRead);
                DBG_vPrintf(TRACE_ZCL, "\nDim Level: %d", sLight.sLevelControlServerCluster.u8CurrentLevel);
            }
            else /* It is factory new so start at 100% */
            {
                sLight.sLevelControlServerCluster.u8CurrentLevel = CLD_LEVELCONTROL_MAX_LEVEL;
            }
        }
        #else
        {
            sLight.sLevelControlServerCluster.u8CurrentLevel = CLD_LEVELCONTROL_MAX_LEVEL;
        }
        #endif
    }
    #endif

    sLight.sOnOffServerCluster.bOnOff = TRUE;

    vAPP_ZCL_DeviceSpecific_Init();

}
/****************************************************************************
 *
 * NAME: ZCL_Task
 *
 * DESCRIPTION:
 * ZCL Task for the Light
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
OS_TASK(ZCL_Task)
{

    ZPS_tsAfEvent sStackEvent;
    tsZCL_CallBackEvent sCallBackEvent;
    sCallBackEvent.pZPSevent = &sStackEvent;

    /* If there is a stack event to process, pass it on to ZCL */
    sStackEvent.eType = ZPS_EVENT_NONE;
    if ( OS_eCollectMessage(APP_msgZpsEvents_ZCL, &sStackEvent) == OS_E_OK)
    {
        DBG_vPrintf(TRACE_ZCL, "\nZCL_Task event:%d",sStackEvent.eType);
        sCallBackEvent.eEventType = E_ZCL_CBET_ZIGBEE_EVENT;
        vZCL_EventHandler(&sCallBackEvent);
    }

}

/****************************************************************************
 *
 * NAME: APP_ZCL_vSetHAIdentifyTime
 *
 * DESCRIPTION:
 * Sets the remaining time in the identify cluster
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_ZCL_vSetIdentifyTime(uint16 u16Time)
{
    sLight.sIdentifyServerCluster.u16IdentifyTime = u16Time;
}

/****************************************************************************
 *
 * NAME: Tick_Task
 *
 * DESCRIPTION:
 * Task kicked by the tick timer
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
OS_TASK(Tick_Task)
{
    static uint32 u32Tick10ms = 9;
    static uint32 u32Tick1Sec = 99;

    tsZCL_CallBackEvent sCallBackEvent;

    OS_eContinueSWTimer(APP_TickTimer, APP_TIME_MS(10), NULL);

    /* Provide processor cycles to any drivers that need time behaviour */
    DriverBulb_vTick();

    /* Periodically update diagnostics */
    (void)eCLD_DiagnosticsUpdate(u8AppGetEPId());

    u32Tick10ms++;
    u32Tick1Sec++;

    /* Wrap the Tick10ms counter and provide 100ms ticks to cluster */
    if (u32Tick10ms > 9)
    {
        u32Tick10ms = 0;
        eHA_Update100mS();
        vIdEffectTick(1);
    }
    #if ( defined CLD_LEVEL_CONTROL) /* add in nine 10ms interpolation points */
    else
    {
         vLI_CreatePoints();
    }
    #if (CONFIG_RESTORE_DIM_LEVEL == TRUE)
    if (u16LevelChangeTick)
    {
        u16LevelChangeTick--;
        if (u16LevelChangeTick == 0)
        {
            APP_ZCL_SaveLightLevel(sLight.sLevelControlServerCluster.u8CurrentLevel);
        }
    }
    #endif
    #endif

    /* Wrap the Tick counter and provide 1Hz ticks to cluster */
    if(u32Tick1Sec > 99)
    {
        u32Tick1Sec = 0;
        sCallBackEvent.pZPSevent = NULL;
        sCallBackEvent.eEventType = E_ZCL_CBET_TIMER;
        vZCL_EventHandler(&sCallBackEvent);
        #ifdef CLD_OTA
            vRunAppOTAStateMachine();
        #endif
        #ifdef BREATH_EFFECT
            App_vLightEffect();
        #endif

        #ifdef CLD_SIMPLE_METERING
        {
            /* Demand is simply based upon the on/off state and level of the lamp */
            if (sLight.sOnOffServerCluster.bOnOff == TRUE)
            {
                /* Light is on so base instantaneous demand on level */
                sLight.sSimpleMeteringServerCluster.i24InstantaneousDemand = (LAMP_DEMAND_WATTS_MAX * sLight.sLevelControlServerCluster.u8CurrentLevel) / 255;

                /* Accumulate... */
                fCurrentSummationDelivered += ((float)sLight.sSimpleMeteringServerCluster.i24InstantaneousDemand / 3600);
                sLight.sSimpleMeteringServerCluster.u48CurrentSummationDelivered = (zuint48)fCurrentSummationDelivered;
            }
            else /* light is off so set demand to 0 watts */
            {
                    sLight.sSimpleMeteringServerCluster.i24InstantaneousDemand = 0;
            }
        }
        #endif
    }

    /* Pass the tick count into the temperature module for scheduling */
    APP_vManageTemperatureTick(u32Tick1Sec);

    #ifdef CLD_GREENPOWER
    if((u32Tick1Sec & 1UL) ==0)
    {
        vAppGPUpdateTime();
    }
    #endif
}


/****************************************************************************
 *
 * NAME: OTA_MsTask
 *
 * DESCRIPTION:
 * Task kicked by the tick timer
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
uint32 u32OTA_Time_Ms=0;

OS_TASK(OTA_MsTask)
{
    tsZCL_CallBackEvent sCallBackEvent;
    OS_eContinueSWTimer(OTA_MsTimer, APP_TIME_MS(u32OTA_Time_Ms) , NULL);
    sCallBackEvent.pZPSevent = NULL;
    sCallBackEvent.eEventType = E_ZCL_CBET_TIMER_MS;
    vZCL_EventHandler(&sCallBackEvent);
}

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/
/****************************************************************************
 *
 * NAME: APP_ZCL_cbGeneralCallback
 *
 * DESCRIPTION:
 * General callback for ZCL events
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void APP_ZCL_cbGeneralCallback(tsZCL_CallBackEvent *psEvent)
{
    switch (psEvent->eEventType)
    {


    case E_ZCL_CBET_UNHANDLED_EVENT:
        DBG_vPrintf(TRACE_ZCL, "\nEVT: Unhandled Event\r\n");
        break;

    case E_ZCL_CBET_READ_ATTRIBUTES_RESPONSE:
        DBG_vPrintf(TRACE_ZCL, "\nEVT: Read attributes response");
        break;

    case E_ZCL_CBET_READ_REQUEST:
        DBG_vPrintf(TRACE_ZCL, "\nEVT: Read request");
        break;

    case E_ZCL_CBET_DEFAULT_RESPONSE:
        DBG_vPrintf(TRACE_ZCL, "\nEVT: Default response");
        break;

    case E_ZCL_CBET_ERROR:
        DBG_vPrintf(TRACE_ZCL, "\nEVT: Error");
        break;

    case E_ZCL_CBET_TIMER:
        DBG_vPrintf(TRACE_ZCL, "\nEVT: Timer");
        break;

    case E_ZCL_CBET_ZIGBEE_EVENT:
        DBG_vPrintf(TRACE_ZCL, "\nEVT: ZigBee");
        break;

    case E_ZCL_CBET_CLUSTER_CUSTOM:
        DBG_vPrintf(TRACE_ZCL, "\nEP EVT: Custom");
        break;

    default:
        DBG_vPrintf(TRACE_ZCL, "\nInvalid event type");
        break;
    }
}
/****************************************************************************
 *
 * NAME: APP_ZCL_cbEndpointCallback
 *
 * DESCRIPTION:
 * Endpoint specific callback for ZCL events
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void APP_ZCL_cbEndpointCallback(tsZCL_CallBackEvent *psEvent)
{
    #if (defined CLD_COLOUR_CONTROL) && !(defined ColorTempTunableWhiteLight)
        uint8 u8Red, u8Green, u8Blue;
    #endif
    DBG_vPrintf(TRACE_ZCL, "\nEntering cbZCL_EndpointCallback");

    switch (psEvent->eEventType)
    {


    case E_ZCL_CBET_UNHANDLED_EVENT:
        /* DBG_vPrintf(TRACE_ZCL, "\nEP EVT: Unhandled event");*/
        break;
    case E_ZCL_CBET_REPORT_INDIVIDUAL_ATTRIBUTE:
    {
        tsZCL_IndividualAttributesResponse    *psIndividualAttributeResponse= &psEvent->uMessage.sIndividualAttributeResponse;
        DBG_vPrintf(TRACE_ZCL,"Individual Report attribute for Cluster = %d\n",psEvent->psClusterInstance->psClusterDefinition->u16ClusterEnum);
        DBG_vPrintf(TRACE_ZCL,"eAttributeDataType = %d\n",psIndividualAttributeResponse->eAttributeDataType);
        DBG_vPrintf(TRACE_ZCL,"u16AttributeEnum = %d\n",psIndividualAttributeResponse->u16AttributeEnum );
        DBG_vPrintf(TRACE_ZCL,"eAttributeStatus = %d\n",psIndividualAttributeResponse->eAttributeStatus );
#ifdef CLD_OCCUPANCY_SENSING
        if((MEASUREMENT_AND_SENSING_CLUSTER_ID_OCCUPANCY_SENSING == psEvent->psClusterInstance->psClusterDefinition->u16ClusterEnum) &&
                (psIndividualAttributeResponse->u16AttributeEnum == E_CLD_OS_ATTR_ID_OCCUPANCY))
        {
          uint8 u8Occupancy = 0;
          memcpy(&u8Occupancy,(uint8 *)psIndividualAttributeResponse->pvAttributeData,1);
          if(u8Occupancy)
              sLight.sOnOffServerCluster.bOnOff = TRUE;
          else
              sLight.sOnOffServerCluster.bOnOff = FALSE;
          #if (defined CLD_COLOUR_CONTROL) && !(defined ColorTempTunableWhiteLight)
              vApp_eCLD_ColourControl_GetRGB(&u8Red, &u8Green, &u8Blue);

              DBG_vPrintf(TRACE_LIGHT_TASK, "\nR %d G %d B %d L %d Hue %d Sat %d X %d Y %d On %d", u8Red, u8Green, u8Blue,
                  sLight.sLevelControlServerCluster.u8CurrentLevel,
                  sLight.sColourControlServerCluster.u8CurrentHue,
                  sLight.sColourControlServerCluster.u8CurrentSaturation,
                  sLight.sColourControlServerCluster.u16CurrentX,
                  sLight.sColourControlServerCluster.u16CurrentY,
                  sLight.sOnOffServerCluster.bOnOff);

              vRGBLight_SetLevels(sLight.sOnOffServerCluster.bOnOff,
                      sLight.sLevelControlServerCluster.u8CurrentLevel,
                      u8Red,
                      u8Green,
                      u8Blue);

          #elif (defined CLD_LEVEL_CONTROL) && !(defined ColorTempTunableWhiteLight)
              /* level Control with on off */
              vWhiteLightSetLevels(sLight.sOnOffServerCluster.bOnOff, sLight.sLevelControlServerCluster.u8CurrentLevel);

          #elif (defined CLD_LEVEL_CONTROL) && (defined ColorTempTunableWhiteLight)
              /* level Control with on off and colour temperature */
              vTunableWhiteLightSetLevels(sLight.sOnOffServerCluster.bOnOff,
                                          sLight.sLevelControlServerCluster.u8CurrentLevel,
                                          sLight.sColourControlServerCluster.u16ColourTemperature);


          #else
                /* must be on off with out level */
          #endif

        }
#endif
        break;
    }
    case E_ZCL_CBET_REPORT_INDIVIDUAL_ATTRIBUTES_CONFIGURE:
        {
            tsZCL_AttributeReportingConfigurationRecord    *psAttributeReportingRecord= &psEvent->uMessage.sAttributeReportingConfigurationRecord;
            DBG_vPrintf(TRACE_ZCL,"Individual Configure attribute for Cluster = %d\n",psEvent->psClusterInstance->psClusterDefinition->u16ClusterEnum);
            DBG_vPrintf(TRACE_ZCL,"eAttributeDataType = %d\n",psAttributeReportingRecord->eAttributeDataType);
            DBG_vPrintf(TRACE_ZCL,"u16AttributeEnum = %d\n",psAttributeReportingRecord->u16AttributeEnum );
            DBG_vPrintf(TRACE_ZCL,"u16MaximumReportingInterval = %d\n",psAttributeReportingRecord->u16MaximumReportingInterval );
            DBG_vPrintf(TRACE_ZCL,"u16MinimumReportingInterval = %d\n",psAttributeReportingRecord->u16MinimumReportingInterval );
            DBG_vPrintf(TRACE_ZCL,"u16TimeoutPeriodField = %d\n",psAttributeReportingRecord->u16TimeoutPeriodField );
            DBG_vPrintf(TRACE_ZCL,"u8DirectionIsReceived = %d\n",psAttributeReportingRecord->u8DirectionIsReceived );
            DBG_vPrintf(TRACE_ZCL,"uAttributeReportableChange = %d\n",psAttributeReportingRecord->uAttributeReportableChange );
            if (E_ZCL_SUCCESS == psEvent->eZCL_Status)
            {
                if(GENERAL_CLUSTER_ID_ONOFF == psEvent->psClusterInstance->psClusterDefinition->u16ClusterEnum)
                {
                    vSaveReportableRecord(0,GENERAL_CLUSTER_ID_ONOFF,psAttributeReportingRecord);
                }
                else if(GENERAL_CLUSTER_ID_LEVEL_CONTROL == psEvent->psClusterInstance->psClusterDefinition->u16ClusterEnum)
                {
                    vSaveReportableRecord(1,GENERAL_CLUSTER_ID_LEVEL_CONTROL,psAttributeReportingRecord);
                }
			#ifdef ICONTROL_BUILD
                else if(SE_CLUSTER_ID_SIMPLE_METERING == psEvent->psClusterInstance->psClusterDefinition->u16ClusterEnum)
                {
                	vSaveReportableRecord(2,SE_CLUSTER_ID_SIMPLE_METERING,psAttributeReportingRecord);
                }
			#endif
                else
                {

                }
            }
            break;
        }
    case E_ZCL_CBET_READ_INDIVIDUAL_ATTRIBUTE_RESPONSE:
        DBG_vPrintf(TRACE_ZCL, "\nEP EVT: Cl Id %04x Rd Attr %04x AS %d\n",
                psEvent->psClusterInstance->psClusterDefinition->u16ClusterEnum,
                psEvent->uMessage.sIndividualAttributeResponse.u16AttributeEnum,
                psEvent->uMessage.sIndividualAttributeResponse.eAttributeStatus);

        break;

    case E_ZCL_CBET_READ_ATTRIBUTES_RESPONSE:
        /* DBG_vPrintf(TRACE_ZCL, "\nEP EVT: Read attributes response"); */
        break;

    case E_ZCL_CBET_READ_REQUEST:
        /* DBG_vPrintf(TRACE_ZCL, "\nEP EVT: Read request"); */
        break;

    case E_ZCL_CBET_DEFAULT_RESPONSE:
        /* DBG_vPrintf(TRACE_ZCL, "\nEP EVT: Default response"); */
        break;

    case E_ZCL_CBET_ERROR:
        /* DBG_vPrintf(TRACE_ZCL, "\nEP EVT: Error"); */
        break;

    case E_ZCL_CBET_TIMER:
        /* DBG_vPrintf(TRACE_ZCL, "\nEP EVT: Timer"); */
        break;

    case E_ZCL_CBET_ENABLE_MS_TIMER:
        {
            DBG_vPrintf(TRUE,"\n E_ZCL_CBET_ENABLE_MS_TIMER Ms = %d\n", psEvent->uMessage.u32TimerPeriodMs);
            u32OTA_Time_Ms=psEvent->uMessage.u32TimerPeriodMs;
            OS_eStartSWTimer(OTA_MsTimer,APP_TIME_MS(u32OTA_Time_Ms),NULL);
        }
        break;

    case E_ZCL_CBET_DISABLE_MS_TIMER:
        {
            DBG_vPrintf(TRUE,"\n E_ZCL_CBET_DISABLE_MS_TIMER\n");
            OS_eStopSWTimer(OTA_MsTimer);
        }
        break;

    case E_ZCL_CBET_ZIGBEE_EVENT:
        /* DBG_vPrintf(TRACE_ZCL, "\nEP EVT: ZigBee"); */
        break;

    case E_ZCL_CBET_CLUSTER_CUSTOM:
        DBG_vPrintf(TRACE_ZCL, "\nEP EVT: Custom Cl %04x\n", psEvent->uMessage.sClusterCustomMessage.u16ClusterId);

        switch(psEvent->uMessage.sClusterCustomMessage.u16ClusterId)
        {
            #ifdef CLD_OTA
                case OTA_CLUSTER_ID:
                {
                    tsOTA_CallBackMessage *psCallBackMessage = (tsOTA_CallBackMessage *)psEvent->uMessage.sClusterCustomMessage.pvCustomData;
                    vHandleAppOtaClient(psCallBackMessage);
                }
                break;
            #endif

            #ifdef CLD_BAS_CMD_RESET_TO_FACTORY_DEFAULTS
                case GENERAL_CLUSTER_ID_BASIC:
                {
                    tsCLD_BasicCallBackMessage *psCallBackMessage = (tsCLD_BasicCallBackMessage*)psEvent->uMessage.sClusterCustomMessage.pvCustomData;
                    DBG_vPrintf(TRACE_ZCL, "\nGENERAL_CLUSTER_ID_BASIC - Command ID: 0x%02x\n", psCallBackMessage->u8CommandId);

                    if (E_CLD_BASIC_CMD_RESET_TO_FACTORY_DEFAULTS == psCallBackMessage->u8CommandId)
                    {
                        APP_ZCL_vHandleBasicFactoryReset();
                    }
                }
                break;
            #endif


            case GENERAL_CLUSTER_ID_GROUPS:
                DBG_vPrintf(TRACE_PATH, "\nPath 1");
                tsCLD_GroupsCallBackMessage *psCallBackMessage = (tsCLD_GroupsCallBackMessage*)psEvent->uMessage.sClusterCustomMessage.pvCustomData;
                DBG_vPrintf(TRACE_ZCL, " CmdId=%d", psCallBackMessage->u8CommandId);
                if( ( psCallBackMessage->u8CommandId == E_CLD_GROUPS_CMD_ADD_GROUP) ||
                        (psCallBackMessage->u8CommandId == E_CLD_GROUPS_CMD_REMOVE_GROUP))
                {
                    DBG_vPrintf(TRACE_ZCL,"AddGroup or Remove Group Command recieved ");

                    #if (CONFIG_BLINK_ON_GROUP == TRUE)
                    {
                        vStartEffect(E_CLD_IDENTIFY_EFFECT_OKAY);
                    }
                    #endif
                }
                break;
            case GENERAL_CLUSTER_ID_ONOFF:
            {

                DBG_vPrintf(TRACE_PATH, "\nPath 1");
                tsCLD_OnOffCallBackMessage *psCallBackMessage = (tsCLD_OnOffCallBackMessage*)psEvent->uMessage.sClusterCustomMessage.pvCustomData;

                DBG_vPrintf(TRACE_ZCL, " CmdId=%d", psCallBackMessage->u8CommandId);

                #if (defined CLD_COLOUR_CONTROL) && !(defined ColorTempTunableWhiteLight)
                    vApp_eCLD_ColourControl_GetRGB(&u8Red, &u8Green, &u8Blue);

                    DBG_vPrintf(TRACE_LIGHT_TASK, "\nR %d G %d B %d L %d Hue %d Sat %d X %d Y %d On %d", u8Red, u8Green, u8Blue,
                        sLight.sLevelControlServerCluster.u8CurrentLevel,
                        sLight.sColourControlServerCluster.u8CurrentHue,
                        sLight.sColourControlServerCluster.u8CurrentSaturation,
                        sLight.sColourControlServerCluster.u16CurrentX,
                        sLight.sColourControlServerCluster.u16CurrentY,
                        sLight.sOnOffServerCluster.bOnOff);

                    vRGBLight_SetLevels(sLight.sOnOffServerCluster.bOnOff,
                            sLight.sLevelControlServerCluster.u8CurrentLevel,
                            u8Red,
                            u8Green,
                            u8Blue);

                #elif (defined CLD_LEVEL_CONTROL) && !(defined ColorTempTunableWhiteLight)
                    /* level Control with on off */
                    vWhiteLightSetLevels(sLight.sOnOffServerCluster.bOnOff, sLight.sLevelControlServerCluster.u8CurrentLevel);

                    /*Level Control with on-off and colour temperature */
                #elif (defined CLD_LEVEL_CONTROL) && (defined ColorTempTunableWhiteLight)
                    vTunableWhiteLightSetLevels(sLight.sOnOffServerCluster.bOnOff,
                                                sLight.sLevelControlServerCluster.u8CurrentLevel,
                                                sLight.sColourControlServerCluster.u16ColourTemperatureMired);
                #else
                        /* must be on off with out level */
                #endif
            }
            break;
            case GENERAL_CLUSTER_ID_IDENTIFY:
            {
                tsCLD_IdentifyCallBackMessage *psCallBackMessage = (tsCLD_IdentifyCallBackMessage*)psEvent->uMessage.sClusterCustomMessage.pvCustomData;
                if (psCallBackMessage->u8CommandId == E_CLD_IDENTIFY_CMD_IDENTIFY) {

                    DBG_vPrintf(TRACE_LIGHT_TASK, "Id time %d\n", sLight.sIdentifyServerCluster.u16IdentifyTime);
                    APP_vHandleIdentify(sLight.sIdentifyServerCluster.u16IdentifyTime);
              }
            }
            break;
            #ifdef CLD_GREENPOWER
            case GREENPOWER_CLUSTER_ID:
            {
                DBG_vPrintf(TRACE_LIGHT_TASK, "\n cluster green");
                vHandleGreenPowerEvent(psEvent->uMessage.sClusterCustomMessage.pvCustomData);
                break;
            }
            #endif
        }
        break;
    #ifdef CLD_GREENPOWER
    case E_ZCL_CBET_ZGP_DATA_IND_ERROR:
        DBG_vPrintf(TRACE_LIGHT_TASK, "\nGP Data Error");
        break;
    #endif
    case E_ZCL_CBET_WRITE_INDIVIDUAL_ATTRIBUTE:
        DBG_vPrintf(TRACE_ZCL, "\nEP EVT: Write Individual Attribute");
        break;

    case E_ZCL_CBET_CLUSTER_UPDATE:
        DBG_vPrintf(TRACE_LIGHT_TASK, "Update Id %04x\n", psEvent->psClusterInstance->psClusterDefinition->u16ClusterEnum);
        if (psEvent->psClusterInstance->psClusterDefinition->u16ClusterEnum == GENERAL_CLUSTER_ID_SCENES)
        {
            /*Scenes Update */
        }
        else if (psEvent->psClusterInstance->psClusterDefinition->u16ClusterEnum == GENERAL_CLUSTER_ID_IDENTIFY)
        {
            /*Handle Identify for the cluster update event */
            APP_vHandleIdentify(sLight.sIdentifyServerCluster.u16IdentifyTime);
        }
        #ifdef ColorTempTunableWhiteLight /* This is a special case of Color Temp. Tunable White Light*/
            else
            {
                DBG_vPrintf(TRACE_PATH, "\nPath 2");
                if (sLight.sIdentifyServerCluster.u16IdentifyTime == 0)
                {
                    vTunableWhiteLightSetLevels(sLight.sOnOffServerCluster.bOnOff,
                                                sLight.sLevelControlServerCluster.u8CurrentLevel,
                                                sLight.sColourControlServerCluster.u16ColourTemperatureMired);
                }
            }
        #else
            else
            {
                if (sLight.sIdentifyServerCluster.u16IdentifyTime == 0)
                {
                    /*
                     * If not identifying then do the light
                     */
                    DBG_vPrintf(TRACE_PATH, "\nPath 2");
                    #if (defined CLD_COLOUR_CONTROL)
                        vApp_eCLD_ColourControl_GetRGB(&u8Red, &u8Green, &u8Blue);

                        DBG_vPrintf(TRACE_LIGHT_TASK, "\nR %d G %d B %d L %d Hue %d Sat %d X %d Y %d On %d", u8Red, u8Green, u8Blue,
                            sLight.sLevelControlServerCluster.u8CurrentLevel,
                            sLight.sColourControlServerCluster.u8CurrentHue,
                            sLight.sColourControlServerCluster.u8CurrentSaturation,
                            sLight.sColourControlServerCluster.u16CurrentX,
                            sLight.sColourControlServerCluster.u16CurrentY,
                            sLight.sOnOffServerCluster.bOnOff);

                        vRGBLight_SetLevels(sLight.sOnOffServerCluster.bOnOff,
                            sLight.sLevelControlServerCluster.u8CurrentLevel,
                            u8Red,
                            u8Green,
                            u8Blue);
                        #if (CONFIG_RESTORE_DIM_LEVEL == TRUE)
                        {
                            /* Start the count down to level saving */
                            u16LevelChangeTick = LEVEL_SAVE_DELAY_10MS;
                        }
                        #endif

                    #elif (defined CLD_LEVEL_CONTROL)
                        /* both level and on off present */
                        vWhiteLightSetLevels(sLight.sOnOffServerCluster.bOnOff, sLight.sLevelControlServerCluster.u8CurrentLevel);

                        #if (CONFIG_RESTORE_DIM_LEVEL == TRUE)
                        {
                            /* Start the count down to level saving */
                            u16LevelChangeTick = LEVEL_SAVE_DELAY_10MS;
                        }
                        #endif

                    #else
                        /* only on off present Call on off driver here*/
                    #endif
                }
            }
        #endif
        break;

        default:
            DBG_vPrintf(TRACE_ZCL, "\nEP EVT: Invalid evt type 0x%x", (uint8)psEvent->eEventType);
            break;
    }
}


/****************************************************************************
 *
 * NAME: APP_vHandleIdentify
 *
 * DESCRIPTION:
 * Handle Identify
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_vHandleIdentify(uint16 u16Time) {

    #if (defined CLD_COLOUR_CONTROL) && !(defined ColorTempTunableWhiteLight)
        uint8 u8Red, u8Green, u8Blue;
    #endif

    DBG_vPrintf(TRACE_LIGHT_TASK, "Id %d\n", u16Time);
    if (sIdEffect.u8Effect < E_CLD_IDENTIFY_EFFECT_STOP_EFFECT) {
        /* do nothing */

    }
    else if (u16Time == 0)
    {
            /*
             * Restore to on/off/colour state
             */
        DBG_vPrintf(TRACE_PATH, "\nPath 3");

        #if (defined CLD_COLOUR_CONTROL) && !(defined ColorTempTunableWhiteLight)
                /*
                 * Restore to off/off/colour state
                 */

            vApp_eCLD_ColourControl_GetRGB(&u8Red, &u8Green, &u8Blue);

            DBG_vPrintf(TRACE_LIGHT_TASK, "R %d G %d B %d L %d Hue %d Sat %d\n", u8Red, u8Green, u8Blue,
                                sLight.sLevelControlServerCluster.u8CurrentLevel,
                                sLight.sColourControlServerCluster.u8CurrentHue,
                                sLight.sColourControlServerCluster.u8CurrentSaturation);

            vRGBLight_SetLevels(sLight.sOnOffServerCluster.bOnOff,
                                sLight.sLevelControlServerCluster.u8CurrentLevel,
                                u8Red,
                                u8Green,
                                u8Blue);
        #elif (defined CLD_LEVEL_CONTROL) && !(defined ColorTempTunableWhiteLight)
            vWhiteLightSetLevels(sLight.sOnOffServerCluster.bOnOff, sLight.sLevelControlServerCluster.u8CurrentLevel);

        #elif (defined CLD_LEVEL_CONTROL) && (defined ColorTempTunableWhiteLight)
            vTunableWhiteLightSetLevels(sLight.sOnOffServerCluster.bOnOff,
                                        sLight.sLevelControlServerCluster.u8CurrentLevel,
                                        sLight.sColourControlServerCluster.u16ColourTemperatureMired);
        #else
            /* Call on-off drivers here */
        #endif
        }
        else
        {
            /* Set the Identify levels */
            DBG_vPrintf(TRACE_PATH, "\nPath 4");
            #if (defined CLD_COLOUR_CONTROL) && !(defined ColorTempTunableWhiteLight)
                vRGBLight_SetLevels(TRUE, 159, 250, 0, 0);
            #elif (defined CLD_LEVEL_CONTROL) && !(defined ColorTempTunableWhiteLight)
                vWhiteLightSetLevels(!(u16Time & 1U), 240); /* if light is on identify by going off */
            #elif (defined CLD_LEVEL_CONTROL) && (defined ColorTempTunableWhiteLight)
                vTunableWhiteLightSetLevels(!(u16Time & 1U),240, sLight.sColourControlServerCluster.u16ColourTemperatureMired);
            #else
             /* Call on-off drivers here */
            #endif
        }
}

#if (CONFIG_RESTORE_DIM_LEVEL == TRUE)
/****************************************************************************
 *
 * NAME: vAppSaveLightLevel
 *
 * DESCRIPTION:
 *
 * RETURNS:
 *
 ****************************************************************************/
PUBLIC void APP_ZCL_SaveLightLevel(uint8 u8Level)
{
    static uint8 u8SavedLevel = 0xff;
    DBG_vPrintf(TRACE_ZCL, "\n%s(%d) to PDM....", __FUNCTION__, u8Level);

    if (u8SavedLevel != u8Level)
    {
        /* Save level to the PDM for restoration following a reset */
        PDM_teStatus eStatus = PDM_eSaveRecordData(PDM_ID_APP_LIGHT_LEVEL, &u8Level, sizeof(uint8));
        DBG_vPrintf(TRACE_ZCL, "Result: %d\n", eStatus);
        u8SavedLevel = u8Level;
    }
}
#endif

#ifdef CLD_BAS_CMD_RESET_TO_FACTORY_DEFAULTS
/****************************************************************************
 *
 * NAME: vAppSaveLightLevel
 *
 * DESCRIPTION:
 *
 * RETURNS:
 *
 ****************************************************************************/
PRIVATE void APP_ZCL_vHandleBasicFactoryReset( void)
{
    DBG_vPrintf(TRACE_ZCL, "\nE_CLD_BASIC_CMD_RESET_TO_FACTORY_DEFAULTS\n");

#ifdef CLD_GROUPS
    vRemoveAllGroupsAndScenes();
#endif

    vApp_ZCL_ResetDeviceStructure();
    /* Register Light EndPoint */
    eApp_HA_RegisterEndpoint(&APP_ZCL_cbEndpointCallback);
    vAPP_ZCL_DeviceSpecific_Init();
#ifdef CLD_OTA
    vAppInitOTA();
#endif


    /* Reset light to default values */
    sLight.sOnOffServerCluster.bOnOff = TRUE;
#ifdef CLD_LEVEL_CONTROL
    sLight.sLevelControlServerCluster.u8CurrentLevel = CLD_LEVELCONTROL_MAX_LEVEL;
    #if (CONFIG_RESTORE_DIM_LEVEL == TRUE)
    /* Start the count down to level saving */
    u16LevelChangeTick = LEVEL_SAVE_DELAY_10MS;
    #endif
#endif

#if (defined CLD_COLOUR_CONTROL) && !(defined ColorTempTunableWhiteLight)
        uint8 u8Red, u8Green, u8Blue;

    vApp_eCLD_ColourControl_GetRGB(&u8Red, &u8Green, &u8Blue);

    vRGBLight_SetLevels(sLight.sOnOffServerCluster.bOnOff,
                        sLight.sLevelControlServerCluster.u8CurrentLevel,
                        u8Red,
                        u8Green,
                        u8Blue);

#elif (defined CLD_LEVEL_CONTROL) && !(defined ColorTempTunableWhiteLight)
    /* level Control with on off */
    vWhiteLightSetLevels(sLight.sOnOffServerCluster.bOnOff, sLight.sLevelControlServerCluster.u8CurrentLevel);

    /*Level Control with on-off and colour temperature */
#elif (defined CLD_LEVEL_CONTROL) && (defined ColorTempTunableWhiteLight)
    vTunableWhiteLightSetLevels(sLight.sOnOffServerCluster.bOnOff,
                                sLight.sLevelControlServerCluster.u8CurrentLevel,
                                sLight.sColourControlServerCluster.u16ColourTemperatureMired);
#else
        /* must be on off with out level */
#endif
}
#endif

/****************************************************************************
 *
 * NAME: APP_ButtonsScanTask
 *
 * DESCRIPTION:
 * Button Task Stub for all the target with out a button
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
OS_TASK(APP_ButtonsScanTask)
{

}
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

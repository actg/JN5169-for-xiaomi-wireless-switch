/*****************************************************************************
 *
 * MODULE:             JN-AN-1189 ZHA Demo
 *
 * COMPONENT:          app_zcl_outlet_task.c
 *
 * DESCRIPTION:        ZHA Outlet Application Behavior - Implementation
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
#include "DriverOutlet.h"

#ifdef CLD_GREENPOWER
  #include "App_GreenPower.h"
#endif

#include "app_zcl_outlet_task.h"
#include "zha_outlet_node.h"
#include "app_common.h"
#include "app_events.h"
#include "haEzFindAndBind.h"
#include "haEzJoin.h"
#include "app_status_led.h"

#ifdef CLD_OTA
    #include "app_ota_client.h"
#endif

#include "app_reporting.h"

#include <AppHardwareApi.h>

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifdef DEBUG_ZCL
    #define TRACE_ZCL   TRUE
#else
    #define TRACE_ZCL   FALSE
#endif

#ifdef DEBUG_OUTLET_TASK
    #define TRACE_OUTLET_TASK  TRUE
#else
    #define TRACE_OUTLET_TASK FALSE
#endif

#ifdef DEBUG_PATH
    #define TRACE_PATH  TRUE
#else
    #define TRACE_PATH  FALSE
#endif

#define CONFIG_ENABLE_FACTORY_NEW_CADENCE TRUE
#if (CONFIG_ENABLE_FACTORY_NEW_CADENCE == TRUE)
    #define BREATH_EFFECT
#endif

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/


/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
PRIVATE void APP_ZCL_cbGeneralCallback(tsZCL_CallBackEvent *psEvent);
PRIVATE void APP_ZCL_cbEndpointCallback(tsZCL_CallBackEvent *psEvent);

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
extern bool_t bResetFactoryNew;

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

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

    /* Set the default cluster (0xFFFF) to use network security, by default it uses application security */
    eZCL_Status = eZCL_SetSupportedSecurity(E_ZCL_SECURITY_NETWORK);
    DBG_vPrintf(TRACE_ZCL, "\neZCL_SetSupportedSecurity: 0x%x\r\n", eZCL_Status);

    #ifdef CLD_GREENPOWER
        vApp_RegisterGPDevice(&APP_ZCL_cbEndpointCallback);
    #endif

    sOutletDevice.sOnOffServerCluster.bOnOff = TRUE;

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
    sOutletDevice.sIdentifyServerCluster.u16IdentifyTime = u16Time;
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

    u32Tick10ms++;
    u32Tick1Sec++;

    /* Wrap the Tick10ms counter and provide 100ms ticks to cluster */
    if (u32Tick10ms > 9)
    {
        u32Tick10ms = 0;
        eHA_Update100mS();
        vIdEffectTick(1);
    }

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
    }

    if (TRUE == bResetFactoryNew)
    {
        bResetFactoryNew = FALSE;

        APP_tsEvent sPowerOnEvent;
        sPowerOnEvent.eType = APP_E_EVENT_POR_PDM_RESET;
        OS_ePostMessage(APP_msgPOREvents, &sPowerOnEvent);
    }

    #ifdef CLD_GREENPOWER
    if((u32Tick1Sec & 1UL) ==0)
    {
        vAppGPUpdateTime();
    }
    #endif
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
    #if (TRACE_ZCL == TRUE)
    {
        if ((psEvent->eEventType != E_ZCL_CBET_LOCK_MUTEX) && (psEvent->eEventType != E_ZCL_CBET_UNLOCK_MUTEX))
        {
            DBG_vPrintf(TRACE_ZCL, "\r\n%s - ", __FUNCTION__);
        }
    }
    #endif

    switch (psEvent->eEventType)
    {
        case E_ZCL_CBET_UNHANDLED_EVENT:
        {
            DBG_vPrintf(TRACE_ZCL, "E_ZCL_CBET_UNHANDLED_EVENT");
        }
        break;

        case E_ZCL_CBET_REPORT_INDIVIDUAL_ATTRIBUTE:
        {
            DBG_vPrintf(TRACE_ZCL, "E_ZCL_CBET_REPORT_INDIVIDUAL_ATTRIBUTE");

            tsZCL_IndividualAttributesResponse    *psIndividualAttributeResponse= &psEvent->uMessage.sIndividualAttributeResponse;
            DBG_vPrintf(TRACE_ZCL,"Individual Report attribute for Cluster = %d\n",psEvent->psClusterInstance->psClusterDefinition->u16ClusterEnum);
            DBG_vPrintf(TRACE_ZCL,"eAttributeDataType = %d\n",psIndividualAttributeResponse->eAttributeDataType);
            DBG_vPrintf(TRACE_ZCL,"u16AttributeEnum = %d\n",psIndividualAttributeResponse->u16AttributeEnum );
            DBG_vPrintf(TRACE_ZCL,"eAttributeStatus = %d\n",psIndividualAttributeResponse->eAttributeStatus );
        }
        break;

        case E_ZCL_CBET_REPORT_INDIVIDUAL_ATTRIBUTES_CONFIGURE:
        {
            DBG_vPrintf(TRACE_ZCL, "E_ZCL_CBET_REPORT_INDIVIDUAL_ATTRIBUTES_CONFIGURE");

            tsZCL_AttributeReportingConfigurationRecord    *psAttributeReportingRecord= &psEvent->uMessage.sAttributeReportingConfigurationRecord;
            DBG_vPrintf(TRACE_ZCL,"Individual Configure attribute for Cluster = %d\n",psEvent->psClusterInstance->psClusterDefinition->u16ClusterEnum);
            DBG_vPrintf(TRACE_ZCL,"eAttributeDataType = %d\n",psAttributeReportingRecord->eAttributeDataType);
            DBG_vPrintf(TRACE_ZCL,"u16AttributeEnum = %d\n",psAttributeReportingRecord->u16AttributeEnum );
            DBG_vPrintf(TRACE_ZCL,"u16MaximumReportingInterval = %d\n",psAttributeReportingRecord->u16MaximumReportingInterval );
            DBG_vPrintf(TRACE_ZCL,"u16MinimumReportingInterval = %d\n",psAttributeReportingRecord->u16MinimumReportingInterval );
            DBG_vPrintf(TRACE_ZCL,"u16TimeoutPeriodField = %d\n",psAttributeReportingRecord->u16TimeoutPeriodField );
            DBG_vPrintf(TRACE_ZCL,"u8DirectionIsReceived = %d\n",psAttributeReportingRecord->u8DirectionIsReceived );
            DBG_vPrintf(TRACE_ZCL,"uAttributeReportableChange = %d\n",psAttributeReportingRecord->uAttributeReportableChange );

            if(GENERAL_CLUSTER_ID_ONOFF == psEvent->psClusterInstance->psClusterDefinition->u16ClusterEnum)
            {
                vSaveReportableRecord(0,GENERAL_CLUSTER_ID_ONOFF,psAttributeReportingRecord);
            }
        }
        break;

        case E_ZCL_CBET_READ_INDIVIDUAL_ATTRIBUTE_RESPONSE:
        {
            DBG_vPrintf(TRACE_ZCL, "E_ZCL_CBET_READ_INDIVIDUAL_ATTRIBUTE_RESPONSE");

            DBG_vPrintf(TRACE_ZCL, "\nEP EVT: Cl Id %04x Rd Attr %04x AS %d\n",
                        psEvent->psClusterInstance->psClusterDefinition->u16ClusterEnum,
                        psEvent->uMessage.sIndividualAttributeResponse.u16AttributeEnum,
                        psEvent->uMessage.sIndividualAttributeResponse.eAttributeStatus);
        }
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

        case E_ZCL_CBET_ZIGBEE_EVENT:
            /* DBG_vPrintf(TRACE_ZCL, "\nEP EVT: ZigBee"); */
            break;

        case E_ZCL_CBET_CLUSTER_CUSTOM:
        {
            DBG_vPrintf(TRACE_ZCL, "E_ZCL_CBET_CLUSTER_CUSTOM: ");

            switch(psEvent->uMessage.sClusterCustomMessage.u16ClusterId)
            {
                #ifdef CLD_OTA
                    case OTA_CLUSTER_ID:
                    {
                        DBG_vPrintf(TRACE_ZCL, "OTA_CLUSTER_ID");

                        tsOTA_CallBackMessage *psCallBackMessage = (tsOTA_CallBackMessage *)psEvent->uMessage.sClusterCustomMessage.pvCustomData;
                        vHandleAppOtaClient(psCallBackMessage);
                    }
                    break;
                #endif

                case GENERAL_CLUSTER_ID_GROUPS:
                {
                    DBG_vPrintf(TRACE_ZCL, "GENERAL_CLUSTER_ID_GROUPS");

                    DBG_vPrintf(TRACE_PATH, "\nPath 1");
                    tsCLD_GroupsCallBackMessage *psCallBackMessage = (tsCLD_GroupsCallBackMessage*)psEvent->uMessage.sClusterCustomMessage.pvCustomData;
                    DBG_vPrintf(TRACE_ZCL, " CmdId=%d", psCallBackMessage->u8CommandId);

                    if((psCallBackMessage->u8CommandId == E_CLD_GROUPS_CMD_ADD_GROUP) ||
                       (psCallBackMessage->u8CommandId == E_CLD_GROUPS_CMD_REMOVE_GROUP))
                    {
                        DBG_vPrintf(TRACE_ZCL,"AddGroup or Remove Group Command recieved ");

                        #if (CONFIG_BLINK_ON_GROUP == TRUE)
                        {
                            vStartEffect(E_CLD_IDENTIFY_EFFECT_OKAY);
                        }
                        #endif
                    }
                }
                break;

                case GENERAL_CLUSTER_ID_ONOFF:
                {
                    DBG_vPrintf(TRACE_ZCL, "GENERAL_CLUSTER_ID_ONOFF");

                    tsCLD_OnOffCallBackMessage *psCallBackMessage = (tsCLD_OnOffCallBackMessage*)psEvent->uMessage.sClusterCustomMessage.pvCustomData;

                    DBG_vPrintf(TRACE_ZCL, "\n\rGENERAL_CLUSTER_ID_ONOFF - CmdId = %d", psCallBackMessage->u8CommandId);

                    switch (psCallBackMessage->u8CommandId)
                    {
                        case E_CLD_ONOFF_CMD_OFF:
                        {
                            DriverOutlet_vOutputOff();
                        }
                        break;

                        case E_CLD_ONOFF_CMD_ON:
                        {
                            DriverOutlet_vOutputOn();
                        }
                        break;

                        case E_CLD_ONOFF_CMD_TOGGLE:
                        {
                            if (DriverOutlet_bIsOutputOn() == TRUE)
                            {
                                DriverOutlet_vOutputOff();
                            }
                            else
                            {
                                DriverOutlet_vOutputOn();
                            }
                        }
                        break;

                        default:
                        {
                            /* Unknown command - do nothing */
                        }
                        break;
                    }
                }
                break;

                case GENERAL_CLUSTER_ID_IDENTIFY:
                {
                    DBG_vPrintf(TRACE_ZCL, "GENERAL_CLUSTER_ID_IDENTIFY");

                    tsCLD_IdentifyCallBackMessage *psCallBackMessage = (tsCLD_IdentifyCallBackMessage*)psEvent->uMessage.sClusterCustomMessage.pvCustomData;

                    if (psCallBackMessage->u8CommandId == E_CLD_IDENTIFY_CMD_IDENTIFY)
                    {
                        APP_vHandleIdentify(sOutletDevice.sIdentifyServerCluster.u16IdentifyTime);
                    }
                }
                break;

                #ifdef CLD_GREENPOWER
                {
                    case GREENPOWER_CLUSTER_ID:
                    {
                        DBG_vPrintf(TRACE_ZCL, "GREENPOWER_CLUSTER_ID");
                        vHandleGreenPowerEvent(psEvent->uMessage.sClusterCustomMessage.pvCustomData);
                    }
                    break;
                }
                #endif

                default:
                {
                    DBG_vPrintf(TRACE_ZCL, "UNKNOWN (%04x)", psEvent->uMessage.sClusterCustomMessage.u16ClusterId);
                }
                break;
            }
        }
        break;

        #ifdef CLD_GREENPOWER
            case E_ZCL_CBET_ZGP_DATA_IND_ERROR:
            {
                DBG_vPrintf(TRACE_OUTLET_TASK, "\nGP Data Error");
                break;
            }
        #endif

        case E_ZCL_CBET_WRITE_INDIVIDUAL_ATTRIBUTE:
        {
            DBG_vPrintf(TRACE_ZCL, "E_ZCL_CBET_WRITE_INDIVIDUAL_ATTRIBUTE");

            DBG_vPrintf(TRACE_ZCL, "\nEP EVT: Write Individual Attribute");
            DBG_vPrintf(TRACE_ZCL, "\nCluster ID: 0x%04x", psEvent->psClusterInstance->psClusterDefinition->u16ClusterEnum);
            DBG_vPrintf(TRACE_ZCL, "\nAttrib ID: 0x%04x", psEvent->uMessage.sIndividualAttributeResponse.u16AttributeEnum);
        }
        break;

        case E_ZCL_CBET_WRITE_ATTRIBUTES:
        {
            DBG_vPrintf(TRACE_ZCL, "E_ZCL_CBET_WRITE_ATTRIBUTES");

            DBG_vPrintf(TRACE_ZCL, "\nEP EVT: Write Attributes");
            DBG_vPrintf(TRACE_ZCL, "\nCluster ID: 0x%04x", psEvent->psClusterInstance->psClusterDefinition->u16ClusterEnum);
            DBG_vPrintf(TRACE_ZCL, "\nAttrib ID: 0x%04x", psEvent->uMessage.sIndividualAttributeResponse.u16AttributeEnum);
        }
        break;

        case E_ZCL_CBET_CLUSTER_UPDATE:
        {
            DBG_vPrintf(TRACE_ZCL, "E_ZCL_CBET_CLUSTER_UPDATE");
            DBG_vPrintf(TRACE_ZCL, "\n\rCluster Id: %04x", psEvent->psClusterInstance->psClusterDefinition->u16ClusterEnum);

            if (psEvent->psClusterInstance->psClusterDefinition->u16ClusterEnum == GENERAL_CLUSTER_ID_SCENES)
            {
                /*Scenes Update */
            }
            else if (psEvent->psClusterInstance->psClusterDefinition->u16ClusterEnum == GENERAL_CLUSTER_ID_IDENTIFY)
            {
                /*Handle Identify for the cluster update event */
                APP_vHandleIdentify(sOutletDevice.sIdentifyServerCluster.u16IdentifyTime);
            }
        }
        break;

        default:
        {
            DBG_vPrintf(TRACE_ZCL, "\nEP EVT: Invalid evt type 0x%x", (uint8)psEvent->eEventType);
        }
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
PUBLIC void APP_vHandleIdentify(uint16 u16Time)
{
    DBG_vPrintf(TRACE_ZCL, "\n\r%s - Time: %d", __FUNCTION__, u16Time);

       if (u16Time > 0)
       {
           if(TRUE == DriverOutlet_bIsStatusLedOn())
              {
                  DriverOutlet_vStatusLedOff();
              }
              else
              {
                  DriverOutlet_vStatusLedOn();
              }
       }
       else /* Identify finished */
       {
           /* Restore status LED to display outlet state */
           if (TRUE == DriverOutlet_bIsOutputOn())
           {
               DriverOutlet_vStatusLedOn();
           }
           else
           {
               DriverOutlet_vStatusLedOff();
           }
       }
}

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

/*****************************************************************************
 *
 * MODULE:             JN-AN-1219
 *
 * COMPONENT:          app_zcl_remote_task.c
 *
 * DESCRIPTION:        ZLO Switch Behavior (Implementation)
 *
 *****************************************************************************
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
 ****************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#include <jendefs.h>
#include <AppApi.h>
#include "pdum_apl.h"
#include "pdum_gen.h"
#include "PDM.h"
#include "dbg.h"
#include "pwrm.h"

#include "zps_apl_af.h"
#include "zps_apl_zdo.h"
#include "zps_apl_aib.h"
#include "zps_apl_zdp.h"
#include "rnd_pub.h"
#include "mac_pib.h"

#include "ZTimer.h"

#include "zcl_options.h"
#include "zcl.h"
//#include "ha.h"
#include "app_common.h"
#include "app_events.h"
#include "app_zlo_switch_node.h"
#include "AHI_AES.h"
#include "app_events.h"
#include "app_zcl_switch_task.h"
#include "App_DimmerSwitch.h"
#ifdef CLD_OTA
    #include "app_ota_client.h"
#endif
#include "app_main.h"
#include "PDM_IDs.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifdef DEBUG_ZCL
    #define TRACE_ZCL   TRUE
#else
    #define TRACE_ZCL   FALSE
#endif

#ifdef DEBUG_SWITCH_TASK
    #define TRACE_SWITCH_TASK   TRUE
#else
    #define TRACE_SWITCH_TASK   FALSE
#endif

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/

PRIVATE void APP_ZCL_cbGeneralCallback(tsZCL_CallBackEvent *psEvent);
PRIVATE void APP_ZCL_cbEndpointCallback(tsZCL_CallBackEvent *psEvent);
PRIVATE void vDevStateIndication(void);
PRIVATE void vSetThreeLeds( bool led1, bool led2, bool led3 );
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
extern PDM_tsRecordDescriptor sDevicePDDesc;
extern uint16 u16GroupId;
extern uint16 u16GlobalGroupId;
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

    /* Initialise ZCL */
    eZCL_Status = eZCL_Initialise(&APP_ZCL_cbGeneralCallback, apduZCL);
    if (eZCL_Status != E_ZCL_SUCCESS)
    {
        DBG_vPrintf(TRACE_ZCL, "Error: eHA_Initialise returned %d\r\n", eZCL_Status);
    }

    /* Register ZLO EndPoint */
    eZCL_Status = eApp_ZCL_RegisterEndpoint(&APP_ZCL_cbEndpointCallback);
    if (eZCL_Status != E_ZCL_SUCCESS)
    {
            DBG_vPrintf(TRACE_SWITCH_TASK, "Error: eApp_ZCL_RegisterEndpoint:%d\r\n", eZCL_Status);
    }

    DBG_vPrintf(TRACE_SWITCH_TASK, "Chan Mask %08x\n", ZPS_psAplAibGetAib()->pau32ApsChannelMask[0]);

    vAPP_ZCL_DeviceSpecific_Init();

    #ifdef CLD_OTA
        vAppInitOTA();
    #endif

    /* Start the tick timer */
    ZTIMER_eStart(u8TimerTick, ZCL_TICK_TIME);

}


/****************************************************************************
 *
 * NAME: APP_cbTimerZclTick
 *
 * DESCRIPTION:
 * Timer callback for the ZCL 1 second tick timer
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_cbTimerZclTick(void *pvParam)
{
    tsZCL_CallBackEvent sCallBackEvent;

    sCallBackEvent.eEventType = E_ZCL_CBET_TIMER;
    ZTIMER_eStart(u8TimerTick, ZCL_TICK_TIME);
	DBG_vPrintf(TRACE_ZCL, "\nAPP_cbTimerZclTick...\n");
    vZCL_EventHandler(&sCallBackEvent);

    vDevStateIndication();
    #ifdef SLEEP_ENABLE
    if(sDeviceDesc.eNodeState == E_RUNNING)
            vUpdateKeepAliveTimer();
    #endif
    #ifdef CLD_OTA
        vRunAppOTAStateMachine();
    #endif

}


/****************************************************************************
 *
 * NAME: APP_ZCL_vEventHandler
 *
 * DESCRIPTION:
 * Main state machine
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_ZCL_vEventHandler(ZPS_tsAfEvent *psStackEvent)
{
    tsZCL_CallBackEvent sCallBackEvent;
    sCallBackEvent.pZPSevent = psStackEvent;

    DBG_vPrintf(TRACE_ZCL, "\nZCL_Task endpoint event:%d", psStackEvent->eType);
    sCallBackEvent.eEventType = E_ZCL_CBET_ZIGBEE_EVENT;
    vZCL_EventHandler(&sCallBackEvent);

}


/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/
/****************************************************************************
 *
 * NAME: vDevStateIndication
 *
 *
 * DESCRIPTION:
 * Indication for the EZ Mode status
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vDevStateIndication(void)
{
    static bool bStatus;
    static uint8 u8Flashes;

    bStatus = ~bStatus;

    if ( sDeviceDesc.eNodeState != E_RUNNING )
    {
        vSetThreeLeds( bStatus, ~bStatus, bStatus );
        u8Flashes = 4;
    }
    /*transitioned from start up to running hence indicate the LEDs*/
    else
    {
        if(u8Flashes>0)
        {
            u8Flashes--;
            /*Blinks until last blink, then sets the LEDs to off */
            if(u8Flashes>1)
                vSetThreeLeds( bStatus, bStatus, bStatus );
            else
                vSetThreeLeds( FALSE,FALSE,FALSE );
        }
    }
}

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
            DBG_vPrintf(TRACE_ZCL, "EVT: Unhandled Event\r\n");
            break;

        case E_ZCL_CBET_READ_ATTRIBUTES_RESPONSE:
            DBG_vPrintf(TRACE_ZCL, "EVT: Read attributes response\r\n");
            break;

        case E_ZCL_CBET_READ_REQUEST:
            DBG_vPrintf(TRACE_ZCL, "EVT: Read request\r\n");
            break;

        case E_ZCL_CBET_DEFAULT_RESPONSE:
            DBG_vPrintf(TRACE_ZCL, "EVT: Default response\r\n");
            break;

        case E_ZCL_CBET_ERROR:
            DBG_vPrintf(TRACE_ZCL, "EVT: Error\r\n");
            break;

        case E_ZCL_CBET_TIMER:
            break;

        case E_ZCL_CBET_ZIGBEE_EVENT:
            DBG_vPrintf(TRACE_ZCL, "EVT: ZigBee\r\n");
            break;

        case E_ZCL_CBET_CLUSTER_CUSTOM:
            DBG_vPrintf(TRACE_ZCL, "EP EVT: Custom\r\n");
            break;

        default:
            DBG_vPrintf(TRACE_ZCL, "Invalid event type (%d) in APP_ZCL_cbGeneralCallback\r\n", psEvent->eEventType);
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
    switch (psEvent->eEventType)
    {
        case E_ZCL_CBET_UNHANDLED_EVENT:
        
        case E_ZCL_CBET_READ_ATTRIBUTES_RESPONSE:
        
        case E_ZCL_CBET_READ_REQUEST:
        
        case E_ZCL_CBET_DEFAULT_RESPONSE:
        
        case E_ZCL_CBET_ERROR:
        
        case E_ZCL_CBET_TIMER:
        
        case E_ZCL_CBET_ZIGBEE_EVENT:
            DBG_vPrintf(TRACE_ZCL, "EP EVT:No action\r\n");
            break;

        case E_ZCL_CBET_READ_INDIVIDUAL_ATTRIBUTE_RESPONSE:
            DBG_vPrintf(TRACE_SWITCH_TASK, " Read Attrib Rsp %d %02x\n", psEvent->uMessage.sIndividualAttributeResponse.eAttributeStatus,
                *((uint8*)psEvent->uMessage.sIndividualAttributeResponse.pvAttributeData));
            break;

        case E_ZCL_CBET_CLUSTER_CUSTOM:
            DBG_vPrintf(TRACE_ZCL, "EP EVT: Custom %04x\r\n", psEvent->uMessage.sClusterCustomMessage.u16ClusterId);

            switch (psEvent->uMessage.sClusterCustomMessage.u16ClusterId)
            {
                #ifdef CLD_OTA
                    case OTA_CLUSTER_ID:
                    {
                        tsOTA_CallBackMessage *psCallBackMessage = (tsOTA_CallBackMessage *)psEvent->uMessage.sClusterCustomMessage.pvCustomData;
                        vHandleAppOtaClient(psCallBackMessage);
                    }
                    break;
                #endif

                case GENERAL_CLUSTER_ID_BASIC:
                {
                    tsCLD_BasicCallBackMessage *psCallBackMessage = (tsCLD_BasicCallBackMessage*)psEvent->uMessage.sClusterCustomMessage.pvCustomData;
                    if (psCallBackMessage->u8CommandId == E_CLD_BASIC_CMD_RESET_TO_FACTORY_DEFAULTS )
                    {
                        DBG_vPrintf(TRACE_ZCL, "Basic Factory Reset Received\n");
                        /* resetting the sensor structure back to zero*/
                        memset(&sSwitch,0,sizeof(tsZLO_DimmerSwitchDevice));
                        eApp_ZCL_RegisterEndpoint(&APP_ZCL_cbEndpointCallback);
                        vAPP_ZCL_DeviceSpecific_Init();
                        #ifdef CLD_OTA
                            vAppInitOTA();
                        #endif
                    }else if(psCallBackMessage->u8CommandId == E_CLD_BASIC_CMD_CONFIG_SCENE_OF_GROUP_ID)
                    {
						PDM_eSaveRecordData(PDM_ID_DEVICE_SWITCH_GROUPID,&psCallBackMessage->groupId,sizeof(psCallBackMessage->groupId));
						u16GlobalGroupId=psCallBackMessage->groupId;
					}
                }
                break;

                case GENERAL_CLUSTER_ID_IDENTIFY:
                    DBG_vPrintf(TRACE_ZCL, "- for identify cluster\r\n");
                    tsCLD_IdentifyCallBackMessage *psCallBackMessage = (tsCLD_IdentifyCallBackMessage*)psEvent->uMessage.sClusterCustomMessage.pvCustomData;
                    if(psEvent->psClusterInstance->bIsServer == FALSE)
                    {
                        /* provide callback to BDB handler for identify query response on initiator*/
                        if(psCallBackMessage->u8CommandId == E_CLD_IDENTIFY_CMD_IDENTIFY)
                        {
                            tsBDB_ZCLEvent  sBDBZCLEvent;
                            DBG_vPrintf(TRACE_ZCL, "\nCallBackBDB");
                            sBDBZCLEvent.eType = BDB_E_ZCL_EVENT_IDENTIFY_QUERY;
                            sBDBZCLEvent.psCallBackEvent = psEvent;
                            BDB_vZclEventHandler(&sBDBZCLEvent);
                        }
                    }
                    else
                    {
                        if(psCallBackMessage->u8CommandId == E_CLD_IDENTIFY_CMD_TRIGGER_EFFECT)
                        {
                            DBG_vPrintf(TRACE_ZCL, "Trigger Effect ID %d Vr %d\r\n",
                                    psCallBackMessage->uMessage.psTriggerEffectRequestPayload->eEffectId,
                                    psCallBackMessage->uMessage.psTriggerEffectRequestPayload->u8EffectVarient);
                        }
                    }
                    break;

                case GENERAL_CLUSTER_ID_GROUPS:
                    DBG_vPrintf(TRACE_ZCL, "- for groups cluster\r\n");
                    break;

                case 0x1000:
                    DBG_vPrintf(TRACE_ZCL, "\n    - for 0x1000");
                    break;

                default:
                    DBG_vPrintf(TRACE_ZCL, "- for unknown cluster %d\r\n", psEvent->uMessage.sClusterCustomMessage.u16ClusterId);
                    break;
            }
            break;

            case E_ZCL_CBET_CLUSTER_UPDATE:
                DBG_vPrintf(TRACE_ZCL, "Update Id %04x\n", psEvent->psClusterInstance->psClusterDefinition->u16ClusterEnum);
                if (psEvent->psClusterInstance->psClusterDefinition->u16ClusterEnum == GENERAL_CLUSTER_ID_IDENTIFY)
                {
                    vAPP_ZCL_DeviceSpecific_UpdateIdentify();
                    #ifdef SLEEP_ENABLE
                        vReloadSleepTimers();
                    #endif
                }
                break;

        default:
            DBG_vPrintf(TRACE_ZCL, "EP EVT: Invalid event type (%d) in APP_ZCL_cbEndpointCallback\r\n", psEvent->eEventType);
            break;
    }
}

/****************************************************************************
 *
 * NAME: vSetThreeLeds
 *
 * DESCRIPTION:
 * Sets the three LEDs states
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vSetThreeLeds( bool led1, bool led2, bool led3 )
{
    //APP_vSetLED(LED1, led1);
}

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

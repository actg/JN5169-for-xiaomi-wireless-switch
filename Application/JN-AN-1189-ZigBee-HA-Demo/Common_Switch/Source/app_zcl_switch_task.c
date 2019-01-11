/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          app_zcl_switch_task.c
 *
 * DESCRIPTION:        ZHA Switch Behavior (Implementation)
 *
 *****************************************************************************
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
 ****************************************************************************/

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
#include "pwrm.h"

#include "zps_apl_af.h"
#include "zps_apl_zdo.h"
#include "zps_apl_aib.h"
#include "zps_apl_zdp.h"
#include "rnd_pub.h"
#include "mac_pib.h"

#include "app_timer_driver.h"

#include "zcl_options.h"
#include "zcl.h"
#include "ha.h"
#include "app_common.h"
#include "zha_switch_node.h"
#include "ahi_aes.h"
#include "app_events.h"
#include "GenericBoard.h"
#include "ha.h"
#include "haEzFindAndBind.h"

#include "app_zcl_switch_task.h"
#include "App_DimmerSwitch.h"


#ifdef CLD_OTA
    #include "app_ota_client.h"
#endif

#ifndef DEBUG_CIRCULAR_ROUTE
    #define TRACE_CIRCULAR_ROUTE FALSE
#else
    #define TRACE_CIRCULAR_ROUTE TRUE
#endif
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifdef DEBUG_ZCL
    #define TRACE_ZCL   TRUE
#else
    #define TRACE_ZCL   FALSE
#endif

#ifdef DEBUG_REMOTE_TASK
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
PRIVATE void vSetThreeLeds( bool led1, bool led2, bool led4 );
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
extern PDM_tsRecordDescriptor sDevicePDDesc;
extern tsDeviceDesc sDeviceDesc;
extern uint16 u16GroupId;
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
        DBG_vPrintf(TRACE_ZCL, "Error: eHA_Initialise returned %d\r\n", eZCL_Status);
    }

    /* Register ZHA EndPoint */
    eZCL_Status = eApp_HA_RegisterEndpoint(&APP_ZCL_cbEndpointCallback);
    if (eZCL_Status != E_ZCL_SUCCESS)
    {
            DBG_vPrintf(TRACE_SWITCH_TASK, "Error: eApp_HA_RegisterEndpoint:%d\r\n", eZCL_Status);
    }

    DBG_vPrintf(TRACE_SWITCH_TASK, "Chan Mask %08x\n", ZPS_psAplAibGetAib()->apsChannelMask);

    OS_eStartSWTimer(APP_TickTimer, ZCL_TICK_TIME, NULL);

    //add by behold
    vAPP_ZCL_DeviceSpecific_Init();
}

/****************************************************************************
 *
 * NAME: ZCL_Task
 *
 * DESCRIPTION:
 * ZCL Task for the Switch
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

    /*
     * If the 1 second tick timer has expired, restart it and pass
     * the event on to ZCL
     */
    if (OS_eGetSWTimerStatus(APP_TickTimer) == OS_E_SWTIMER_EXPIRED)
    {
        sCallBackEvent.eEventType = E_ZCL_CBET_TIMER;
        OS_eContinueSWTimer(APP_TickTimer, ZCL_TICK_TIME, NULL);
        vZCL_EventHandler(&sCallBackEvent);
        vDevStateIndication();
        #ifdef SLEEP_ENABLE
        if( (sDeviceDesc.eNodeState == E_RUNNING) ||
                (sDeviceDesc.eNodeState == E_REJOINING))
                vUpdateKeepAliveTimer();
        #endif
        #ifdef CLD_OTA
            vRunAppOTAStateMachine();
        #endif
    }
    /* If there is a stack event to process, pass it on to ZCL */
    sStackEvent.eType = ZPS_EVENT_NONE;
    if (OS_eCollectMessage(APP_msgZpsEvents_ZCL, &sStackEvent) == OS_E_OK)
    {
        DBG_vPrintf(TRACE_ZCL, "\nZCL_Task event:%d",sStackEvent.eType);
        sCallBackEvent.eEventType = E_ZCL_CBET_ZIGBEE_EVENT;
        vZCL_EventHandler(&sCallBackEvent);
    }

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
 * Inidication for the EZ Mode status
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
    else if(sDeviceDesc.eNodeState == E_RUNNING)
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
            DBG_vPrintf(TRACE_ZCL, "Invalid event type\r\n");
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
    vEZ_EPCallBackHandler(psEvent);
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
        {
            uint32 i;
            DBG_vPrintf(TRACE_SWITCH_TASK, " Read Attrib Rsp %d %02x\n", psEvent->uMessage.sIndividualAttributeResponse.eAttributeStatus,
                *((uint8*)psEvent->uMessage.sIndividualAttributeResponse.pvAttributeData));
            for (i=0;i<sDeviceState.u8Discovered;i++)
            {
                if (sDeviceState.sMatchDev[i].u16Address == psEvent->pZPSevent->uEvent.sApsDataIndEvent.uSrcAddress.u16Addr)
                {
                    sDeviceState.sMatchDev[i].u8NumberOfUcasts=0;
                    DBG_vPrintf(TRACE_CIRCULAR_ROUTE,"Reseting the Counters \n");
                    break;
                }
            }
        }
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

                case GENERAL_CLUSTER_ID_IDENTIFY:
                    DBG_vPrintf(TRACE_ZCL, "- for identify cluster\r\n");
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
            DBG_vPrintf(TRACE_ZCL, "EP EVT: Invalid event type\r\n");
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
PRIVATE void vSetThreeLeds( bool led1, bool led2, bool led4 )
{
}

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

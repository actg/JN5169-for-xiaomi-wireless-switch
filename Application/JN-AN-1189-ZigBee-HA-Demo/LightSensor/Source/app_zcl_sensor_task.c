/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          app_zcl_sensor_task.c
 *
 * DESCRIPTION:        ZHA Light sensor Control Behavior (Implementation)
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
#include "zha_sensor_node.h"
#include "ahi_aes.h"
#include "app_events.h"
#include "LightingBoard.h"
#include "ha.h"
#include "haEzFindAndBind.h"

#include "app_zcl_tick_handler.h"
#include "app_zcl_sensor_task.h"
#include "App_LightSensor.h"

#include "app_reporting.h"
#include "app_light_sensor_buttons.h"
#include "app_blink_led.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifdef DEBUG_ZCL
    #define TRACE_ZCL   TRUE
#else
    #define TRACE_ZCL   FALSE
#endif

#ifdef DEBUG_SENSOR_TASK
    #define TRACE_SENSOR_TASK   TRUE
#else
    #define TRACE_SENSOR_TASK   FALSE
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
extern PDM_tsRecordDescriptor sDevicePDDesc;
extern tsDeviceDesc sDeviceDesc;
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
        DBG_vPrintf(TRACE_ZCL, "\nAPP_ZCL: Error eHA_Initialise returned %d", eZCL_Status);
    }

    /* Register ZHA EndPoint */
    eZCL_Status = eApp_HA_RegisterEndpoint(&APP_ZCL_cbEndpointCallback);
    if (eZCL_Status != E_ZCL_SUCCESS)
    {
            DBG_vPrintf(TRACE_SENSOR_TASK, "\nAPP_ZCL: Error: eApp_HA_RegisterEndpoint:%d", eZCL_Status);
    }

    DBG_vPrintf(TRACE_SENSOR_TASK, "\nAPP_ZCL: Chan Mask %08x", ZPS_psAplAibGetAib()->apsChannelMask);
    DBG_vPrintf(TRACE_SENSOR_TASK, "\nAPP_ZCL: RxIdle TRUE");

    OS_eStartSWTimer(APP_TickTimer, ZCL_TICK_TIME, NULL);

    vAPP_ZCL_DeviceSpecific_Init();
}

/****************************************************************************
 *
 * NAME: ZCL_Task
 *
 * DESCRIPTION:
 * ZCL Task for the sensor
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
OS_TASK(ZCL_Task)
{
    /*
     * If the 1 second tick timer has expired, restart it and pass
     * the event on to ZCL
     */
    if (OS_eGetSWTimerStatus(APP_TickTimer) == OS_E_SWTIMER_EXPIRED)
    {
        vAPP_ZCL_Tick();
        OS_eContinueSWTimer(APP_TickTimer, ZCL_TICK_TIME, NULL);
    }
}

/****************************************************************************
 *
 * NAME: vAPP_ZCL_SendStackEventToZCL
 *
 * DESCRIPTION:
 * Sends the stack event to the ZCL event handler.
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAPP_ZCL_SendStackEventToZCL(ZPS_tsAfEvent sStackEvent)
{
    tsZCL_CallBackEvent sCallBackEvent;

    sCallBackEvent.pZPSevent = &sStackEvent;
    sCallBackEvent.eEventType = E_ZCL_CBET_ZIGBEE_EVENT;
    vZCL_EventHandler(&sCallBackEvent);
}

PUBLIC void vAPP_ZCL_Tick(void)
{
    ZPS_tsAfEvent sStackEvent;
    tsZCL_CallBackEvent sCallBackEvent;
    sCallBackEvent.pZPSevent = &sStackEvent;

    vDecrementTickCount();
    sCallBackEvent.eEventType = E_ZCL_CBET_TIMER;
    vZCL_EventHandler(&sCallBackEvent);
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
            DBG_vPrintf(TRACE_ZCL, "\nAPP_ZCL: EVT Unhandled Event");
            break;

        case E_ZCL_CBET_READ_ATTRIBUTES_RESPONSE:
            DBG_vPrintf(TRACE_ZCL, "\nAPP_ZCL: EVT Read attributes response");
            break;

        case E_ZCL_CBET_READ_REQUEST:
            DBG_vPrintf(TRACE_ZCL, "\nAPP_ZCL: EVT Read request");
            break;

        case E_ZCL_CBET_DEFAULT_RESPONSE:
            DBG_vPrintf(TRACE_ZCL, "\nAPP_ZCL: EVT Default response");
            break;

        case E_ZCL_CBET_ERROR:
            DBG_vPrintf(TRACE_ZCL, "\nAPP_ZCL: EVT Error");
            break;

        case E_ZCL_CBET_TIMER:
            break;

        case E_ZCL_CBET_ZIGBEE_EVENT:
            DBG_vPrintf(TRACE_ZCL, "\nAPP_ZCL: EVT ZigBee");
            break;

        case E_ZCL_CBET_CLUSTER_CUSTOM:
            DBG_vPrintf(TRACE_ZCL, "\nAPP_ZCL: EP EVT Custom");
            break;

        default:
            DBG_vPrintf(TRACE_ZCL, "\nAPP_ZCL: Invalid event type");
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

        case E_ZCL_CBET_REPORT_INDIVIDUAL_ATTRIBUTES_CONFIGURE:
            {
                tsZCL_AttributeReportingConfigurationRecord    *psAttributeReportingRecord= &psEvent->uMessage.sAttributeReportingConfigurationRecord;
                DBG_vPrintf(TRACE_ZCL,"\nAPP_ZCL: Individual Configure attribute for Cluster = %d",psEvent->psClusterInstance->psClusterDefinition->u16ClusterEnum);
                DBG_vPrintf(TRACE_ZCL,"\nAPP_ZCL: eAttributeDataType = %d",psAttributeReportingRecord->eAttributeDataType);
                DBG_vPrintf(TRACE_ZCL,"\nAPP_ZCL: u16AttributeEnum = %d",psAttributeReportingRecord->u16AttributeEnum );
                DBG_vPrintf(TRACE_ZCL,"\nAPP_ZCL: u16MaximumReportingInterval = %d",psAttributeReportingRecord->u16MaximumReportingInterval );
                DBG_vPrintf(TRACE_ZCL,"\nAPP_ZCL: u16MinimumReportingInterval = %d",psAttributeReportingRecord->u16MinimumReportingInterval );
                DBG_vPrintf(TRACE_ZCL,"\nAPP_ZCL: u16TimeoutPeriodField = %d",psAttributeReportingRecord->u16TimeoutPeriodField );
                DBG_vPrintf(TRACE_ZCL,"\nAPP_ZCL: u8DirectionIsReceived = %d",psAttributeReportingRecord->u8DirectionIsReceived );
                DBG_vPrintf(TRACE_ZCL,"\nAPP_ZCL: uAttributeReportableChange = %d",psAttributeReportingRecord->uAttributeReportableChange );
                if (E_ZCL_SUCCESS == psEvent->eZCL_Status)
                {
                    if(MEASUREMENT_AND_SENSING_CLUSTER_ID_ILLUMINANCE_MEASUREMENT == psEvent->psClusterInstance->psClusterDefinition->u16ClusterEnum)
                    {
                        vSaveReportableRecord(0,MEASUREMENT_AND_SENSING_CLUSTER_ID_ILLUMINANCE_MEASUREMENT,psAttributeReportingRecord);
                    }
                }
                break;
            }
        case E_ZCL_CBET_UNHANDLED_EVENT:
        case E_ZCL_CBET_READ_ATTRIBUTES_RESPONSE:
        case E_ZCL_CBET_READ_REQUEST:
        case E_ZCL_CBET_DEFAULT_RESPONSE:
        case E_ZCL_CBET_ERROR:
        case E_ZCL_CBET_TIMER:
        case E_ZCL_CBET_ZIGBEE_EVENT:
            DBG_vPrintf(TRACE_ZCL, "\nAPP_ZCL: EP EVT No action");
            break;

        case E_ZCL_CBET_READ_INDIVIDUAL_ATTRIBUTE_RESPONSE:
            DBG_vPrintf(TRACE_SENSOR_TASK, "\nAPP_ZCL: Read Attrib Rsp %d %02x", psEvent->uMessage.sIndividualAttributeResponse.eAttributeStatus,
                *((uint8*)psEvent->uMessage.sIndividualAttributeResponse.pvAttributeData));
            break;

        case E_ZCL_CBET_CLUSTER_CUSTOM:
            DBG_vPrintf(TRACE_ZCL, "\nAPP_ZCL: EP EVT: Custom %04x", psEvent->uMessage.sClusterCustomMessage.u16ClusterId);

            switch (psEvent->uMessage.sClusterCustomMessage.u16ClusterId)
            {

                case GENERAL_CLUSTER_ID_IDENTIFY:
                    DBG_vPrintf(TRACE_ZCL, "\nAPP_ZCL: for identify cluster");
                    if(sSensor.sIdentifyServerCluster.u16IdentifyTime == 0)
                    {
                        vStopBlinkTimer();
                    }
                   break;

                case GENERAL_CLUSTER_ID_GROUPS:
                    DBG_vPrintf(TRACE_ZCL, "\nAPP_ZCL: for groups cluster");
                    break;

                case 0x1000:
                    DBG_vPrintf(TRACE_ZCL, "\nAPP_ZCL: - for 0x1000");
                    break;

                default:
                    DBG_vPrintf(TRACE_ZCL, "\nAPP_ZCL: for unknown cluster %d", psEvent->uMessage.sClusterCustomMessage.u16ClusterId);
                    break;
            }
            break;

            case E_ZCL_CBET_CLUSTER_UPDATE:
                DBG_vPrintf(TRACE_ZCL, "\nAPP_ZCL: Update Id %04x", psEvent->psClusterInstance->psClusterDefinition->u16ClusterEnum);
                break;

        default:
            DBG_vPrintf(TRACE_ZCL, "\nAPP_ZCL: EP EVT Invalid event type");
            break;
    }
}


/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

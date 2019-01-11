/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          app_zcl_server_node_task.c
 *
 * DESCRIPTION:        ZBP-ZHA OTAServer task (Implementation)
 *
 ****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products [NXP Microcontrollers such as JN5148, JN5142,
 * JN5139]. You, and any third parties must reproduce the copyright and
 * warranty notice and any other legend of ownership on each copy or partial
 * copy of the software.
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
#include "dbg.h"
#include "os.h"
#include "os_gen.h"
#include "pdum_apl.h"
#include "pdum_gen.h"
#include "pwrm.h"
#include "pdm.h"
#include "zps_gen.h"
#include "zps_apl.h"
#include "zps_apl_af.h"
#include "zps_apl_aib.h"
#include "zps_apl_zdo.h"
#include "zps_apl_zdp.h"
#include "app_ota_server.h"
#include "app_timer_driver.h"
#include "PDM_IDs.h"
#include "AgeChildren.h"
#include "app_common.h"

#include "haEzJoin.h"

#include "zcl_options.h"
#include "zcl.h"
#include "ha.h"
#include "ota.h"
#include "Time.h"
#include "zcl_common.h"
#include "app_scenes.h"

#include "app_zbp_utilities.h"


/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#define USB_DONGLE

#ifndef DEBUG_APP
    #define TRACE_APP FALSE
#else
    #define TRACE_APP FALSE
#endif

#ifndef DEBUG_APP_OTA
    #define TRACE_APP_OTA FALSE
#else
    #define TRACE_APP_OTA TRUE
#endif
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

typedef struct
{
    /* Add  cluster instance for the OTA cluster */
    tsZCL_ClusterInstance sOTAServerClusterInst;
    #if (defined CLD_TIME) && (defined TIME_SERVER)
        tsZCL_ClusterInstance sTimeServerClusterInst;
    #endif
} tsHA_OTAServerInstances;

typedef struct
{
    /* OTA cluster */
    tsZCL_EndPointDefinition    sEndPoint;
    tsHA_OTAServerInstances sOTAServerCluster;
    tsCLD_AS_Ota sCLD_OTA;
    tsOTA_Common sCLD_OTA_CustomDataStruct;

    #if (defined CLD_TIME) && (defined TIME_SERVER)
        tsCLD_Time sTimeCluster;
    #endif

}tsOTAServer;

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
PRIVATE void APP_ZCL_cbGeneralCallback(tsZCL_CallBackEvent *psEvent);
PRIVATE void APP_ZCL_cbEndpointCallback(tsZCL_CallBackEvent *psEvent);

PRIVATE teZCL_Status eApp_HA_RegisterEndpoint(tfpZCL_ZCLCallBackFunction fptr);
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
extern bool bToggle;

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
PRIVATE tsOTAServer sOTAServer;
PRIVATE uint8 attribData[CLD_OTA_MAX_NUMBER_OF_ATTRIBUTE];

#ifdef TEST_WAITTOUPGRADE
PRIVATE tsZCL_Address  sDestinationAddressTest;
PRIVATE uint32 u32TestTime =0xffffff00;
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
        DBG_vPrintf(TRACE_APP_OTA, "\nErr: eHA_Initialise:%d", eZCL_Status);
    }

    /* Start the tick timer */
    OS_eStartSWTimer(APP_TickTimer, TEN_HZ_TICK_TIME, NULL);

    /* Register EndPoint */
    eZCL_Status = eApp_HA_RegisterEndpoint(&APP_ZCL_cbEndpointCallback);

    if (eZCL_Status != E_ZCL_SUCCESS)
    {
            DBG_vPrintf(TRACE_APP_OTA, "Error: eApp_HA_RegisterEndpoint:%d\r\n", eZCL_Status);
    }
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
        DBG_vPrintf(TRACE_APP_OTA, "\nZCL_Task event:%d",sStackEvent.eType);
        sCallBackEvent.eEventType = E_ZCL_CBET_ZIGBEE_EVENT;
        vZCL_EventHandler(&sCallBackEvent);
    }

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
        eHA_Update100mS();
        u32Tick10ms = 0;
    }

    /* Wrap the Tick counter and provide 1Hz ticks to cluster */
    if(u32Tick1Sec > 99)
    {
        u32Tick1Sec = 0;
        sCallBackEvent.pZPSevent = NULL;
        sCallBackEvent.eEventType = E_ZCL_CBET_TIMER;
        vZCL_EventHandler(&sCallBackEvent);
    }
}

OS_TASK(APP_ServerTime)
{
    uint32 utcTime;

    if( OS_E_SWTIMER_STOPPED != OS_eGetSWTimerStatus (App_ServerTimer))
        OS_eStopSWTimer(App_ServerTimer);
    OS_eStartSWTimer(App_ServerTimer, APP_TIME_MS(1000),NULL);

    utcTime = u32ZCL_GetUTCTime();

    eZCL_WriteLocalAttributeValue(
                         2,
                         GENERAL_CLUSTER_ID_TIME,
                         TRUE,
                         FALSE,
                         FALSE,
                         E_CLD_TIME_ATTR_ID_TIME,
                         &utcTime);

    DBG_vPrintf(TRACE_APP_OTA,"UTC Time = %d\n",u32ZCL_GetUTCTime());

#ifdef TEST_WAITTOUPGRADE
    u32TestTime--;

    if(u32TestTime == 0)
    {
        tsOTA_UpgradeEndResponsePayload sUpgradeResponsePayload;
        sUpgradeResponsePayload.u32UpgradeTime=5;
        sUpgradeResponsePayload.u32CurrentTime=0;
        sUpgradeResponsePayload.u32FileVersion=2;
        sUpgradeResponsePayload.u16ImageType=0x0102;
        sUpgradeResponsePayload.u16ManufacturerCode =0x1037;

        eOTA_ServerUpgradeEndResponse(
                        2,
                        1,
                        &sDestinationAddressTest,
                        &sUpgradeResponsePayload,
                        100);
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
        DBG_vPrintf(TRACE_APP_OTA, "\nEVT: Unhandled Event\r\n");
        break;

    case E_ZCL_CBET_READ_ATTRIBUTES_RESPONSE:
        DBG_vPrintf(TRACE_APP_OTA, "\nEVT: Read attributes response");
        break;

    case E_ZCL_CBET_READ_REQUEST:
        DBG_vPrintf(TRACE_APP_OTA, "\nEVT: Read request");
        break;

    case E_ZCL_CBET_DEFAULT_RESPONSE:
        DBG_vPrintf(TRACE_APP_OTA, "\nEVT: Default response");
        break;

    case E_ZCL_CBET_ERROR:
        DBG_vPrintf(TRACE_APP_OTA, "\nEVT: Error");
        break;

    case E_ZCL_CBET_TIMER:
        DBG_vPrintf(TRACE_APP_OTA, "\nEVT: Timer");
        break;

    case E_ZCL_CBET_ZIGBEE_EVENT:
        DBG_vPrintf(TRACE_APP_OTA, "\nEVT: ZigBee");
        break;

    case E_ZCL_CBET_CLUSTER_CUSTOM:
        DBG_vPrintf(TRACE_APP_OTA, "\nEP EVT: Custom");
        break;

    default:
        DBG_vPrintf(TRACE_APP_OTA, "\nInvalid event type");
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
    DBG_vPrintf(TRACE_APP_OTA, "\nEntering cbZCL_EndpointCallback");

    switch (psEvent->eEventType)
    {

        case E_ZCL_CBET_UNHANDLED_EVENT:
            /* DBG_vPrintf(TRACE_ZCL, "\nEP EVT: Unhandled event");*/
            break;
        case E_ZCL_CBET_REPORT_INDIVIDUAL_ATTRIBUTES_CONFIGURE:
            {
                tsZCL_AttributeReportingConfigurationRecord    *psAttributeReportingRecord= &psEvent->uMessage.sAttributeReportingConfigurationRecord;
                DBG_vPrintf(TRACE_APP_OTA,"Individual Configure attribute for Cluster = %d\n",psEvent->psClusterInstance->psClusterDefinition->u16ClusterEnum);
                DBG_vPrintf(TRACE_APP_OTA,"eAttributeDataType = %d\n",psAttributeReportingRecord->eAttributeDataType);
                DBG_vPrintf(TRACE_APP_OTA,"u16AttributeEnum = %d\n",psAttributeReportingRecord->u16AttributeEnum );
                DBG_vPrintf(TRACE_APP_OTA,"u16MaximumReportingInterval = %d\n",psAttributeReportingRecord->u16MaximumReportingInterval );
                DBG_vPrintf(TRACE_APP_OTA,"u16MinimumReportingInterval = %d\n",psAttributeReportingRecord->u16MinimumReportingInterval );
                DBG_vPrintf(TRACE_APP_OTA,"u16TimeoutPeriodField = %d\n",psAttributeReportingRecord->u16TimeoutPeriodField );
                DBG_vPrintf(TRACE_APP_OTA,"u8DirectionIsReceived = %d\n",psAttributeReportingRecord->u8DirectionIsReceived );
                DBG_vPrintf(TRACE_APP_OTA,"uAttributeReportableChange = %d\n",psAttributeReportingRecord->uAttributeReportableChange );

                break;
            }
        case E_ZCL_CBET_READ_INDIVIDUAL_ATTRIBUTE_RESPONSE:
            /*DBG_vPrintf(TRACE_ZCL, "\nEP EVT: Rd Attr %04x RS %d AS %d", psEvent->uMessage.sIndividualAttributeResponse.u16AttributeEnum, psEvent->uMessage.sIndividualAttributeResponse.psAttributeStatus->eRequestStatus, psEvent->uMessage.sIndividualAttributeResponse.psAttributeStatus->eAttributeStatus); */
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
            DBG_vPrintf(TRACE_APP_OTA, "\nEP EVT: Custom Cl %04x\n", psEvent->uMessage.sClusterCustomMessage.u16ClusterId);

            switch(psEvent->uMessage.sClusterCustomMessage.u16ClusterId)
            {
                case OTA_CLUSTER_ID:
                {
                    tsOTA_CallBackMessage *psCallBackMessage = (tsOTA_CallBackMessage *)psEvent->uMessage.sClusterCustomMessage.pvCustomData;
                    if(psCallBackMessage->eEventId == E_CLD_OTA_COMMAND_UPGRADE_END_REQUEST )
                    {
                        tsCLD_PR_Ota               sOTAData;
                        DBG_vPrintf(TRACE_APP_OTA, "\nUpgrade End Req...");
                        eOTA_GetServerData(2,0,&sOTAData);
                        sOTAData.u32CurrentTime=0;
                        #ifdef OTA_DEMO_BUILD
                            sOTAData.u32RequestOrUpgradeTime =5;
                        #else
                            sOTAData.u32RequestOrUpgradeTime = 3*60*60; /* 3 Hours after an upgrade is over before switching the image.*/
                        #endif

#ifdef TEST_WAITTOUPGRADE
                        /*Set Upgrade time to WAIT FOR UPGRADE */
                        sOTAData.u32RequestOrUpgradeTime = 0xFFFFFFFF;
                        /*Trigger a test timer to send Upgrade end response after 10 seconds with upgrade time set to 5 sec*/
                        u32TestTime=10;
                        sDestinationAddressTest.eAddressMode = E_ZCL_AM_SHORT;
                        sDestinationAddressTest.uAddress.u16DestinationAddress = sOTAServer.sCLD_OTA_CustomDataStruct.sReceiveEventAddress.uSrcAddress.u16Addr;
#endif
                        eOTA_SetServerParams(2,0,&sOTAData);
                    }
                    if(psCallBackMessage->eEventId == E_CLD_OTA_COMMAND_QUERY_NEXT_IMAGE_REQUEST )
                    {

                    }
                    bToggle=TRUE;
                }
                    break;

                default :
                    break;
            }

            break;

        case E_ZCL_CBET_WRITE_INDIVIDUAL_ATTRIBUTE:
            DBG_vPrintf(TRACE_APP_OTA, "\nEP EVT: Write Individual Attribute");
            break;

        case E_ZCL_CBET_CLUSTER_UPDATE:
            DBG_vPrintf(TRACE_APP_OTA, "Update Id %04x\n", psEvent->psClusterInstance->psClusterDefinition->u16ClusterEnum);
            if (psEvent->psClusterInstance->psClusterDefinition->u16ClusterEnum == OTA_CLUSTER_ID)
            {
                /*Scenes Update */
            }
            break;


        default:
            DBG_vPrintf(TRACE_APP_OTA, "\nEP EVT: Invalid evt type 0x%x", (uint8)psEvent->eEventType);
            break;
    }
}
/****************************************************************************
 *
 * NAME: eHA_RegisterOTAServerEndPoint
 *
 * DESCRIPTION:
 * Registering a OTA Server EP
 *
 * PARAMETERS:
 * uint8 u8Ep                             Endpoint Number
 * tfpZCL_ZCLCallBackFunction fptr    Function pointer for the call back
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
teZCL_Status eHA_RegisterOTAServerEndPoint(uint8 u8Ep,tfpZCL_ZCLCallBackFunction fptr)
{
    teZCL_Status eStatus;
    /* Fill in end point details */
    sOTAServer.sEndPoint.u8EndPointNumber = u8Ep;
    sOTAServer.sEndPoint.u16ManufacturerCode = ZCL_MANUFACTURER_CODE;
    sOTAServer.sEndPoint.u16ProfileEnum = HA_PROFILE_ID;
    sOTAServer.sEndPoint.bIsManufacturerSpecificProfile = FALSE;
    sOTAServer.sEndPoint.u16NumberOfClusters = sizeof(tsHA_OTAServerInstances)/sizeof(tsZCL_ClusterInstance);
    sOTAServer.sEndPoint.psClusterInstance = &(sOTAServer.sOTAServerCluster.sOTAServerClusterInst);
    sOTAServer.sEndPoint.bDisableDefaultResponse = TRUE;
    sOTAServer.sEndPoint.pCallBackFunctions = fptr;
    eStatus = eOTA_Create(
                       &sOTAServer.sOTAServerCluster.sOTAServerClusterInst,
                       TRUE,  /* server */
                       &sCLD_OTA,
                       &sOTAServer.sCLD_OTA,  /* cluster definition */
                       u8Ep,
                       attribData,
                       &sOTAServer.sCLD_OTA_CustomDataStruct
                       );
    if (eStatus!= E_ZCL_SUCCESS)

    {
        DBG_vPrintf(TRACE_APP_OTA, "eOTA_Create  failed: %d\n", eStatus);
        /* Need to convert from cluster specific to ZCL return type so we lose the extra information of the return code*/
        return E_ZCL_FAIL;
    }




#if (defined CLD_TIME && defined TIME_SERVER)
    if (eCLD_TimeCreateTime(
                    &sOTAServer.sOTAServerCluster.sTimeServerClusterInst,
                    TRUE,
                    &sCLD_Time,
                    &sOTAServer.sTimeCluster,
                    &au8TimeClusterAttributeControlBits[0]) != E_ZCL_SUCCESS)
    {
        DBG_vPrintf(TRACE_APP_OTA, "eCLD_TimeCreateTime  failed\n");
        return E_ZCL_FAIL;
    }
#endif

    return eZCL_Register(&sOTAServer.sEndPoint);

}
/****************************************************************************
 *
 * NAME: eApp_HA_RegisterEndpoint
 *
 * DESCRIPTION:
 * Register ZHA endpoints
 *
 * PARAMETER
 * Type                        Name                  Descirption
 * tfpZCL_ZCLCallBackFunction  fptr                  Pointer to ZCL Callback function
 *
 * RETURNS:
 * teZCL_Status
 *
 ****************************************************************************/
PRIVATE teZCL_Status eApp_HA_RegisterEndpoint(tfpZCL_ZCLCallBackFunction fptr)
{

    return eHA_RegisterOTAServerEndPoint(2,fptr);
}
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

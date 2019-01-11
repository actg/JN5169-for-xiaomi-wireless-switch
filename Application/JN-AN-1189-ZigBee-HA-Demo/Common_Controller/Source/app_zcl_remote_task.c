/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          app_zcl_remote_task.c
 *
 * DESCRIPTION:        ZHA Remote Control Behavior (Implementation)
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
#include "zha_remote_node.h"
#include "ahi_aes.h"
#include "app_events.h"
#include "ha.h"

#include "app_led_control.h"
#include "app_zcl_remote_task.h"

#ifdef ColorDimmerSwitch
    #include "App_ColorDimmerSwitch.h"
#endif

#ifdef RemoteControl
    #include <string.h>
    #include "App_RemoteControl.h"
    #include "haEzFindAndBind.h"
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
    #define TRACE_REMOTE_TASK   TRUE
#else
    #define TRACE_REMOTE_TASK   FALSE
#endif

#ifndef DEBUG_CIRCULAR_ROUTE
    #define TRACE_CIRCULAR_ROUTE FALSE
#else
    #define TRACE_CIRCULAR_ROUTE TRUE
#endif

#ifdef RemoteControl
    #define CLAMP(x, low, high)  (((x) > (high)) ? (high) : (((x) < (low)) ? (low) : (x)))
    #define ILLUMINANCE_MAXIMUM_LUX_LEVEL                               4015
    #define ILLUMINANCE_LUX_LEVEL_DIVISOR                               16 /*(ILLUMINANCE_MAXIMUM_LUX_LEVEL/CLD_LEVELCONTROL_MAX_LEVEL)*/
    #define MIN_LEVEL                                                   1
    #define MAX_LEVEL                                                   254
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
PRIVATE void vSetAddress(tsZCL_Address * psAddress, bool_t bBroadcast);
#ifdef RemoteControl
PRIVATE uint8 u8ConvertLuxToLevel(uint16 u16MeauseredLux);
#endif
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

extern tsDeviceDesc sDeviceDesc;
extern uint16 u16GroupId;
extern teShiftLevel eShiftLevel;
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
            DBG_vPrintf(TRACE_REMOTE_TASK, "Error: eApp_HA_RegisterEndpoint:%d\r\n", eZCL_Status);
    }

    DBG_vPrintf(TRACE_REMOTE_TASK, "Chan Mask %08x\n", ZPS_psAplAibGetAib()->apsChannelMask);
    DBG_vPrintf(TRACE_REMOTE_TASK, "\nRxIdle TRUE");

    OS_eStartSWTimer(APP_TickTimer, ZCL_TICK_TIME, NULL);

    vAPP_ZCL_DeviceSpecific_Init();
}

/****************************************************************************
 *
 * NAME: ZCL_Task
 *
 * DESCRIPTION:
 * ZCL Task for the Remote
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
    static uint8 u8Status=0;
    static uint8 u8Flashes;

    u8Status = ~u8Status;

    if ( sDeviceDesc.eNodeState != E_RUNNING )
    {
        APP_vSetLeds(E_SHIFT_3 & u8Status );
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
                APP_vSetLeds(E_SHIFT_3);
            else
                APP_vSetLeds(eShiftLevel);
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
#ifdef RemoteControl
    vEZ_EPCallBackHandler(psEvent);
#endif
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

#ifdef RemoteControl
        case E_ZCL_CBET_REPORT_INDIVIDUAL_ATTRIBUTE:
        {
            tsZCL_IndividualAttributesResponse    *psIndividualAttributeResponse= &psEvent->uMessage.sIndividualAttributeResponse;
            tsZCL_Address sAddress;
            DBG_vPrintf(TRACE_ZCL,"Individual Report attribute for Cluster = %d\n",psEvent->psClusterInstance->psClusterDefinition->u16ClusterEnum);
            DBG_vPrintf(TRACE_ZCL,"eAttributeDataType = %d\n",psIndividualAttributeResponse->eAttributeDataType);
            DBG_vPrintf(TRACE_ZCL,"u16AttributeEnum = %d\n",psIndividualAttributeResponse->u16AttributeEnum );
            DBG_vPrintf(TRACE_ZCL,"eAttributeStatus = %d\n",psIndividualAttributeResponse->eAttributeStatus );

            if((MEASUREMENT_AND_SENSING_CLUSTER_ID_ILLUMINANCE_MEASUREMENT == psEvent->psClusterInstance->psClusterDefinition->u16ClusterEnum) &&
                            (psIndividualAttributeResponse->u16AttributeEnum == E_CLD_ILLMEAS_ATTR_ID_MEASURED_VALUE))
            {
              uint16 u16MeasuredValue = 0;
              memcpy((uint8 *)&u16MeasuredValue,(uint8 *)psIndividualAttributeResponse->pvAttributeData,2);
              DBG_vPrintf(TRACE_REMOTE_TASK,"MeasuredLux = %d\n",u16MeasuredValue);
              sAddress.eAddressMode = E_ZCL_AM_GROUP;
              sAddress.uAddress.u16DestinationAddress = psEvent->pZPSevent->uEvent.sApsDataIndEvent.uSrcAddress.u16Addr;
              APP_ZCL_vSendHAMoveToLevel(sAddress,u8ConvertLuxToLevel(u16MeasuredValue),0,FALSE);
            }
            break;
        }
#endif
        case E_ZCL_CBET_READ_INDIVIDUAL_ATTRIBUTE_RESPONSE:
            {
                uint32 i;
                DBG_vPrintf(TRACE_REMOTE_TASK|TRACE_CIRCULAR_ROUTE, " Read Attrib Rsp %d %02x\n", psEvent->uMessage.sIndividualAttributeResponse.eAttributeStatus,
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

                case GENERAL_CLUSTER_ID_IDENTIFY:
                    DBG_vPrintf(TRACE_ZCL, "- for identify cluster\r\n");
                    #ifdef RemoteControl
                        if(sRemote.sIdentifyServerCluster.u16IdentifyTime == 0)
                        {
                            APP_vSetLeds(eShiftLevel);
                        }
                    #endif
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
                }
                break;

        default:
            DBG_vPrintf(TRACE_ZCL, "EP EVT: Invalid event type\r\n");
            break;
    }
}

/****************************************************************************
 *
 * NAME: vSetAddress
 *
 * DESCRIPTION: set the appropriate address parameters for the current addressing mode
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vSetAddress(tsZCL_Address * psAddress, bool_t bBroadcast) {

    if (bBroadcast) {
        psAddress->eAddressMode = E_ZCL_AM_BROADCAST;
        psAddress->uAddress.eBroadcastMode = ZPS_E_APL_AF_BROADCAST_RX_ON;
    } else if (bAddrMode) {
        psAddress->eAddressMode = E_ZCL_AM_GROUP;
        psAddress->uAddress.u16DestinationAddress = u16GroupId;
    } else {
        if(sDeviceState.sMatchDev[sDeviceState.u8Index].u16Address <= 0xFFF8 )
        {
            psAddress->eAddressMode = E_ZCL_AM_SHORT_NO_ACK;
            psAddress->uAddress.u16DestinationAddress = sDeviceState.sMatchDev[sDeviceState.u8Index].u16Address;
        }
        else
        {
            psAddress->eAddressMode = E_ZCL_AM_ENUM_END;
            psAddress->uAddress.u16DestinationAddress = 0xFFFF;
        }
    }
}

/****************************************************************************
 *
 * NAME: APP_ZCL_vSendHAOnOff
 *
 * DESCRIPTION:
 *    Send out ON or OFF command, the address mode(group/unicast/bound etc)
 *    is taken from the selected light index set by the caller
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_ZCL_vSendHAOnOff(teCLD_OnOff_Command eCmd) {

    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE);

    if ((eCmd == E_CLD_ONOFF_CMD_ON) || (eCmd == E_CLD_ONOFF_CMD_OFF) || (eCmd \
            == E_CLD_ONOFF_CMD_TOGGLE))
    {
        eCLD_OnOffCommandSend(
                u8MyEndpoint,
                sDeviceState.sMatchDev[sDeviceState.u8Index].u8Ep,
                &sAddress, &u8Seq, eCmd);
    }
}


/****************************************************************************
 *
 * NAME: APP_ZCL_vSendHAIdentify
 *
 * DESCRIPTION:
 *    Send out Identify command, the address mode(unicast)
 *    is taken from the selected light index set by the caller
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_ZCL_vSendHAIdentify( uint16 u16Time) {
    uint8 u8Seq;
    tsZCL_Address sAddress;
    tsCLD_Identify_IdentifyRequestPayload sPayload;

    sPayload.u16IdentifyTime = u16Time;

    sAddress.eAddressMode = E_ZCL_AM_SHORT_NO_ACK;
    sAddress.uAddress.u16DestinationAddress = sDeviceState.sMatchDev[sDeviceState.u8Index].u16Address;

    eCLD_IdentifyCommandIdentifyRequestSend(
                            u8MyEndpoint,
                            sDeviceState.sMatchDev[sDeviceState.u8Index].u8Ep,
                            &sAddress,
                            &u8Seq,
                            &sPayload);
}

/****************************************************************************
 *
 * NAME: APP_ZCL_vSendHAIdentifyQuery
 *
 * DESCRIPTION:
 *    Send out IdentifyQuery command, the address mode(group/unicast/bound etc)
 *    is taken from the selected light index set by the caller
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_ZCL_vSendHAIdentifyQuery( void) {
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress,FALSE);

    eCLD_IdentifyCommandIdentifyQueryRequestSend(
                            u8MyEndpoint,
                            sDeviceState.sMatchDev[sDeviceState.u8Index].u8Ep,
                            &sAddress,
                            &u8Seq);
}


/****************************************************************************
 *
 * NAME: APP_ZCL_vSendHAMoveLevel
 *
 * DESCRIPTION:
 *    Send out Level Up or Down command, the address mode(group/unicast/bound etc)
 *    is taken from the selected light index set by the caller
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_ZCL_vSendHAMoveLevel(teCLD_LevelControl_MoveMode eMode, uint8 u8Rate, bool_t bWithOnOff)
{
    tsCLD_LevelControl_MoveCommandPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress,FALSE);

    sPayload.u8Rate = u8Rate;
    sPayload.u8MoveMode = eMode;

    eCLD_LevelControlCommandMoveCommandSend(
                                    u8MyEndpoint,
                                    sDeviceState.sMatchDev[sDeviceState.u8Index].u8Ep,
                                    &sAddress,
                                    &u8Seq,
                                    bWithOnOff, /* with on off */
                                    &sPayload);
}

/****************************************************************************
 *
 * NAME: APP_ZCL_vSendHAMoveToLevel
 *
 * DESCRIPTION:
 *    Send out Level Up or Down command, the address mode(group/unicast/bound etc)
 *    is taken from the selected light index set by the caller
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_ZCL_vSendHAMoveToLevel(tsZCL_Address sAddress, uint8 u8CurrentLevel, uint16 u16TransitionTime,bool_t bWithOnOff)
{
    tsCLD_LevelControl_MoveToLevelCommandPayload sPayload;
    uint8 u8Seq;

    sPayload.u8Level = u8CurrentLevel;
    sPayload.u16TransitionTime = u16TransitionTime;

    eCLD_LevelControlCommandMoveToLevelCommandSend(
                                    u8MyEndpoint,
                                    sDeviceState.sMatchDev[sDeviceState.u8Index].u8Ep,
                                    &sAddress,
                                    &u8Seq,
                                    bWithOnOff,
                                    &sPayload);
}
/****************************************************************************
 *
 * NAME: APP_ZCL_vSendHAStopLevel
 *
 * DESCRIPTION:
 *    Send out Level Stop command, the address mode(group/unicast/bound etc)
 *    is taken from the selected light index set by the caller
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_ZCL_vSendHAStopLevel(void)
{
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE);
    eCLD_LevelControlCommandStopCommandSend(
                        u8MyEndpoint,
                        sDeviceState.sMatchDev[sDeviceState.u8Index].u8Ep,
                        &sAddress,
                        &u8Seq);
}


/****************************************************************************
 *
 * NAME: APP_ZCL_vSendHAStepLevel
 *
 * DESCRIPTION:
 *    Send out Step Level command, the address mode(group/unicast/bound etc)
 *    is taken from the selected light index set by the caller
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_ZCL_vSendHAStepLevel(teCLD_LevelControl_MoveMode eMode)
{
    tsCLD_LevelControl_StepCommandPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE);

    sPayload.u16TransitionTime = 0x000a;
    sPayload.u8StepMode = eMode;
    sPayload.u8StepSize = 0x20;
    eCLD_LevelControlCommandStepCommandSend(
                        u8MyEndpoint,
                        sDeviceState.sMatchDev[sDeviceState.u8Index].u8Ep,
                        &sAddress,
                        &u8Seq,
                        FALSE,               /* with on off */
                        &sPayload);
}

#ifdef CLD_SCENES

/****************************************************************************
 *
 * NAME: vAppRecallSceneById
 *
 * DESCRIPTION:
 *    Send out Recall Scene command, the address is group addressing
 *    is taken from the selected light index set by the caller
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppRecallSceneById( uint8 u8SceneId, uint16 u16GroupId)
{

    tsCLD_ScenesRecallSceneRequestPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    sAddress.eAddressMode = E_ZCL_AM_GROUP;
    sAddress.uAddress.u16DestinationAddress = u16GroupId;

    DBG_vPrintf(TRACE_REMOTE_TASK, "\nRecall Scene %d\n", u8SceneId);

    sPayload.u16GroupId = u16GroupId;
    sPayload.u8SceneId = u8SceneId;

    eCLD_ScenesCommandRecallSceneRequestSend(
                            u8MyEndpoint,
                            sDeviceState.sMatchDev[sDeviceState.u8Index].u8Ep,
                            &sAddress,
                            &u8Seq,
                            &sPayload);

}
/****************************************************************************
 *
 * NAME: vAppStoreSceneById
 *
 * DESCRIPTION:
 *    Send out Store Scene command, the address mode is group addressing
 *    is taken from the selected light index set by the caller
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppStoreSceneById(uint8 u8SceneId, uint16 u16GroupId)
{
    tsCLD_ScenesStoreSceneRequestPayload sPayload;

    uint8 u8Seq;
    tsZCL_Address sAddress;

    sAddress.eAddressMode = E_ZCL_AM_GROUP;
    sAddress.uAddress.u16DestinationAddress = u16GroupId;

    sPayload.u16GroupId = u16GroupId;
    sPayload.u8SceneId = u8SceneId;


    eCLD_ScenesCommandStoreSceneRequestSend(
                            u8MyEndpoint,
                            sDeviceState.sMatchDev[sDeviceState.u8Index].u8Ep,   /* dst ep */
                            &sAddress,
                            &u8Seq,
                            &sPayload);

}

#endif

/****************************************************************************
 *
 * NAME: APP_ZCL_vSendHAAddGroup
 *
 * DESCRIPTION:
 *    Send out Add Group command, the address mode is unicast addressing and
 *    is taken from the selected light index set by the caller
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_ZCL_vSendHAAddGroup( uint16 u16GroupId)
{

    tsCLD_Groups_AddGroupRequestPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    sAddress.eAddressMode = E_ZCL_AM_SHORT_NO_ACK;
    sAddress.uAddress.u16DestinationAddress = sDeviceState.sMatchDev[sDeviceState.u8Index].u16Address;

    sPayload.sGroupName.pu8Data = (uint8*)"";
    sPayload.sGroupName.u8Length = 0;
    sPayload.sGroupName.u8MaxLength = 0;
    sPayload.u16GroupId = u16GroupId;

    eCLD_GroupsCommandAddGroupRequestSend(
                            u8MyEndpoint,
                            sDeviceState.sMatchDev[sDeviceState.u8Index].u8Ep,
                            &sAddress,
                            &u8Seq,
                            &sPayload);

}

/****************************************************************************
 *
 * NAME: APP_ZCL_vSendHARemoveGroup
 *
 * DESCRIPTION:
 *    Send out remove group command, the address mode (group/unicast/bound etc)
 *    is taken from the selected light index set by the caller
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_ZCL_vSendHARemoveGroup( uint16 u16GroupId)
{

    tsCLD_Groups_RemoveGroupRequestPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    sAddress.eAddressMode = E_ZCL_AM_SHORT_NO_ACK;
    sAddress.uAddress.u16DestinationAddress = sDeviceState.sMatchDev[sDeviceState.u8Index].u16Address;

    sPayload.u16GroupId = u16GroupId;

    eCLD_GroupsCommandRemoveGroupRequestSend(
                            u8MyEndpoint,
                            sDeviceState.sMatchDev[sDeviceState.u8Index].u8Ep,
                            &sAddress,
                            &u8Seq,
                            &sPayload);

}

/****************************************************************************
 *
 * NAME: APP_ZCL_vSendHARemoveAllGroups
 *
 * DESCRIPTION:
 *    Send out Remove All group command, the address mode(group/unicast/bound etc)
 *    is taken from the selected light index set by the caller
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_ZCL_vSendHARemoveAllGroups(bool_t bBroadcast)
{

    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, bBroadcast);

    eCLD_GroupsCommandRemoveAllGroupsRequestSend(
                            u8MyEndpoint,
                            sDeviceState.sMatchDev[sDeviceState.u8Index].u8Ep,
                            &sAddress,
                            &u8Seq);

}

#ifdef CLD_COLOUR_CONTROL
/****************************************************************************
 *
 * NAME: APP_ZCL_vSendHAMoveToColourTemperature
 *
 * DESCRIPTION:
 *    Send out Move to Color Temp command, the address mode(group/unicast/bound etc)
 *    is taken from the selected light index set by the caller
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_ZCL_vSendHAMoveToColourTemperature(uint16 u16ColorTemp,uint16 u16TransitionTime) {

    uint8 u8Seq;
    tsZCL_Address sAddress;
    vSetAddress(&sAddress, FALSE);
    tsCLD_ColourControl_MoveToColourTemperatureCommandPayload sPayload;

    sPayload.u16ColourTemperatureMired = u16ColorTemp;
    sPayload.u16TransitionTime = u16TransitionTime;

    eCLD_ColourControlCommandMoveToColourTemperatureCommandSend(
                                    u8MyEndpoint,
                                    sDeviceState.sMatchDev[sDeviceState.u8Index].u8Ep,
                                    &sAddress,
                                    &u8Seq,
                                    &sPayload);
}

/****************************************************************************
 *
 * NAME: APP_ZCL_vSendHAMoveColourTemperature
 *
 * DESCRIPTION:
 *    Send out Move Color Temp command, the address mode(group/unicast/bound etc)
 *    is taken from the selected light index set by the caller
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_ZCL_vSendHAMoveColourTemperature( teCLD_ColourControl_MoveMode eMode,
                                       uint16 u16StepsPerSec,
                                       uint16 u16ColourTemperatureMin,
                                       uint16 u16ColourTemperatureMax)
{
    tsCLD_ColourControl_MoveColourTemperatureCommandPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE);

    sPayload.eMode = eMode;
    sPayload.u16Rate = u16StepsPerSec;
    sPayload.u16ColourTemperatureMiredMin = u16ColourTemperatureMin;
    sPayload.u16ColourTemperatureMiredMax = u16ColourTemperatureMax;

    eCLD_ColourControlCommandMoveColourTemperatureCommandSend(
                        u8MyEndpoint,
                        sDeviceState.sMatchDev[sDeviceState.u8Index].u8Ep,
                        &sAddress,
                        &u8Seq,
                        &sPayload);
}

/****************************************************************************
 *
 * NAME: APP_ZCL_vSendHAMoveHue
 *
 * DESCRIPTION:
 *    Send out Move Hue command, the address mode(group/unicast/bound etc)
 *    is taken from the selected light index set by the caller
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_ZCL_vSendHAMoveHue( teCLD_ColourControl_MoveMode eMode,
                         uint8                        u8Rate)
{
    tsCLD_ColourControl_MoveHueCommandPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE);

    sPayload.eMode = eMode;
    sPayload.u8Rate = u8Rate;

    eCLD_ColourControlCommandMoveHueCommandSend(
                        u8MyEndpoint,
                        sDeviceState.sMatchDev[sDeviceState.u8Index].u8Ep,
                        &sAddress,
                        &u8Seq,
                        &sPayload);
}
/****************************************************************************
 *
 * NAME: APP_ZCL_vSendHAMoveSaturation
 *
 * DESCRIPTION:
 *    Send out Move Staturation command, the address mode(group/unicast/bound etc)
 *    is taken from the selected light index set by the caller
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_ZCL_vSendHAMoveSaturation( teCLD_ColourControl_MoveMode eMode,
                                uint8                        u8Rate)
{
    tsCLD_ColourControl_MoveSaturationCommandPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE);

    sPayload.eMode = eMode;
    sPayload.u8Rate = u8Rate;

    eCLD_ColourControlCommandMoveSaturationCommandSend(
                        u8MyEndpoint,
                        sDeviceState.sMatchDev[sDeviceState.u8Index].u8Ep,
                        &sAddress,
                        &u8Seq,
                        &sPayload);
}

/****************************************************************************
 *
 * NAME: APP_ZCL_vSendHAMoveToColour
 *
 * DESCRIPTION:
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_ZCL_vSendHAMoveToColour( uint8 u8Colour)
{
    tsCLD_ColourControl_MoveToColourCommandPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE);

    /* transition over 2 seconds */
    sPayload.u16TransitionTime = 20;

    switch (u8Colour)
    {
        case 0:
            sPayload.u16ColourX = (CLD_COLOURCONTROL_RED_X * 65536) - 10;
            sPayload.u16ColourY = (CLD_COLOURCONTROL_RED_Y * 65536);
            break;
        case 1:
            sPayload.u16ColourX = (CLD_COLOURCONTROL_BLUE_X * 65536);
            sPayload.u16ColourY = (CLD_COLOURCONTROL_BLUE_Y * 65536);
            break;
        case 2:
            sPayload.u16ColourX = (CLD_COLOURCONTROL_GREEN_X * 65536);
            sPayload.u16ColourY = (CLD_COLOURCONTROL_GREEN_Y * 65536);
            break;
        case 3:
            sPayload.u16ColourX = (CLD_COLOURCONTROL_WHITE_X * 65536);
            sPayload.u16ColourY = (CLD_COLOURCONTROL_WHITE_Y * 65536);
            break;
        default:
            return;
            break;
    }

    eCLD_ColourControlCommandMoveToColourCommandSend(
                        u8MyEndpoint,
                        sDeviceState.sMatchDev[sDeviceState.u8Index].u8Ep,
                        &sAddress,
                        &u8Seq,
                        &sPayload);
}

/****************************************************************************
 *
 * NAME: APP_ZCL_vSendHAMovetoHueAndSat
 *
 * DESCRIPTION: Go To a particular Hue and Sat
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_ZCL_vSendHAMovetoHueAndSat( uint8 u8Direction)
{
    tsCLD_ColourControl_MoveToHueAndSaturationCommandPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;
    static uint8 u8Step=0;

    vSetAddress(&sAddress, FALSE);

    /* transition over 2 seconds */
    sPayload.u16TransitionTime = 20;

    if (u8Direction!=0) {
        u8Step++;
        if (u8Step > 6){
            u8Step=0;
        }
    } else {
        u8Step--;
        if (u8Step == 255){
            u8Step=6;
        }
    }


    switch(u8Step) {
        case 0:
            sPayload.u8Hue = 0;
            sPayload.u8Saturation = 0;
        break;
        case 1:
            sPayload.u8Hue = 0x0000;
            sPayload.u8Saturation = 254;
            break;
        case 2:
            sPayload.u8Hue = 0x2e;
            sPayload.u8Saturation = 254;
            break;
        case 3:
            sPayload.u8Hue = 0x55;
            sPayload.u8Saturation = 254;
            break;
        case 4:
            sPayload.u8Hue = 0x7d;
            sPayload.u8Saturation = 254;
            break;
        case 5:
            sPayload.u8Hue = 0xaa;
            sPayload.u8Saturation = 254;
            break;
        case 6:
            sPayload.u8Hue = 0xdd;
            sPayload.u8Saturation = 254;
            break;
    }
    eCLD_ColourControlCommandMoveToHueAndSaturationCommandSend(
                                    u8MyEndpoint,
                                    sDeviceState.sMatchDev[sDeviceState.u8Index].u8Ep,
                                    &sAddress,
                                    &u8Seq,
                                    &sPayload );

}
#endif

#ifdef RemoteControl
/****************************************************************************
 *
 * NAME: u8ConvertLuxToLevel
 *
 * DESCRIPTION:
 * Converts the illuminance to a level
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE uint8 u8ConvertLuxToLevel(uint16 u16MeauseredLux)
{
    uint8 u8Level = 0;
    u8Level = (CLD_LEVELCONTROL_MAX_LEVEL - (u16MeauseredLux/ILLUMINANCE_LUX_LEVEL_DIVISOR));
    u8Level = CLAMP( u8Level,MIN_LEVEL,MAX_LEVEL );
    DBG_vPrintf(TRACE_REMOTE_TASK,"u8ConvertLuxToLevel = %d\n",u8Level);
    return u8Level;
}
#endif

/****************************************************************************
 *
 * NAME: vPingUCASTTarget
 *
 * DESCRIPTION:
 * Tries to send a read attribute ZCL Version of Basic cluster of the Light
 * that is currently controlled using unicast mode.
 * The right place to call this function is when button is pressed.
 *
 * If a response is heard back , it resets the logic if not for threshold
 * amount of numbers,this sends out a NWK status to parent.
 *
 *
 ****************************************************************************/
PUBLIC void vPingUCASTTarget(void)
{
    uint8 u8Seq;
    tsZCL_Address sAddress;

    uint16   au16AttributeRequestList[]={0}; /* ZCL version attribute of Basic cluster*/

    /*Following statement is to get the current address mode from the switch */
    vSetAddress(&sAddress, FALSE);

    /*
     * If the mode is unicast then start observing for the packet delivery every APP_THRESHOLD_NO_OF_UCAST_TO_SEND_READ_ATTR
     * transactions to send a read attribute req
     *
     * */

    if(E_ZCL_AM_SHORT_NO_ACK == sAddress.eAddressMode)
    {
        sDeviceState.sMatchDev[sDeviceState.u8Index].u8NumberOfUcasts++;
        if( sDeviceState.sMatchDev[sDeviceState.u8Index].u8NumberOfUcasts >= APP_THRESHOLD_TO_SEND_READ_ATTR)
        {

            if(sDeviceState.sMatchDev[sDeviceState.u8Index].u8NumberOfUcasts < APP_THRESHOLD_FORCE_ROUTE_DISCOVERY )
            {
                DBG_vPrintf(TRACE_CIRCULAR_ROUTE,"Sending eZCL_SendReadAttributesRequest for %d \n",sDeviceState.sMatchDev[sDeviceState.u8Index].u8NumberOfUcasts);
                teZCL_Status eStatus=eZCL_SendReadAttributesRequest(
                                                                u8MyEndpoint,                                        /*uint8                       u8SourceEndPointId,*/
                                                                sDeviceState.sMatchDev[sDeviceState.u8Index].u8Ep,    /*uint8                       u8DestinationEndPointId,*/
                                                                0,                                                  /*Basic//uint16               u16ClusterId,*/
                                                                FALSE,                                              /*bool_t                      bDirectionIsServerToClient,*/
                                                                &sAddress,                                          /*tsZCL_Address              *psDestinationAddress,*/
                                                                &u8Seq,                                              /*uint8                      *pu8TransactionSequenceNumber,*/
                                                                1,                                                    /*uint8                       u8NumberOfAttributesInRequest,*/
                                                                FALSE,                                                /*bool_t                      bIsManufacturerSpecific,*/
                                                                0x1037,                                             /*uint16                      u16ManufacturerCode,*/
                                                                au16AttributeRequestList                            /*uint16                     *pu16AttributeRequestList*/
                                                            );
                if(E_ZCL_SUCCESS != eStatus)
                {
                    DBG_vPrintf(TRACE_CIRCULAR_ROUTE,"eZCL_SendReadAttributesRequest Status %d \n",eStatus);
                }
            }
            else
            {
                void * thisNet = ZPS_pvAplZdoGetNwkHandle();
                ZPS_tsNwkNib * thisNib = ZPS_psNwkNibGetHandle(thisNet);

                sDeviceState.sMatchDev[sDeviceState.u8Index].u8NumberOfUcasts=0;

                DBG_vPrintf(TRACE_CIRCULAR_ROUTE,"Sending ZPS_vNwkSendNwkStatusCommand\n");
                /* If the threshold has reached ,
                 * then send a NWK status instead of read attribute
                 * */

                ZPS_vNwkSendNwkStatusCommand( thisNet,
                                              sAddress.uAddress.u16DestinationAddress,
                                              thisNib->sTbl.psNtActv[0].u16NwkAddr,
                                              0,
                                              1);
            }
        }
    }
    else
    {
        /* the switch is not doing any an UCAST currently , then reset */
        sDeviceState.sMatchDev[sDeviceState.u8Index].u8NumberOfUcasts=0;
    }
}
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

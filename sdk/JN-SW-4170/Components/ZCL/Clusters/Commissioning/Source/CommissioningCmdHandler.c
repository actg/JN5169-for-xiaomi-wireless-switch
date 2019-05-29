/****************************************************************************
 *
 * MODULE:             Commissioning Cluster
 *
 * COMPONENT:          $RCSfile $
 *
 * AUTHOR:             Lee Mitchell
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/Components/ZCL/Trunk/Clusters/Commissioning/Source/CommissioningCmdHandler.c $
 *
 * REVISION:           $Revision: 71852 $
 *
 * DATED:              $Date: 2015-08-12 11:00:24 +0200 (Wed, 12 Aug 2015) $
 *
 * $LastChangedDate: 2015-08-12 11:00:24 +0200 (Wed, 12 Aug 2015) $
 *
 * $Id: CommissioningCmdHandler.c 71852 2015-08-12 09:00:24Z nxp57621 $
 *
 * DESCRIPTION:
 * Message event handler functions
 *
 * LAST MODIFIED BY:   $Author: nxp57621 $
 *                     $Modtime: $
 *
 ****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products [NXP Microcontrollers such as JN5168, JN5164,
 * JN5161, JN5148, JN5142, JN5139]. 
 * You, and any third parties must reproduce the copyright and warranty notice 
 * and any other legend of ownership on each  copy or partial copy of the software.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
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
 ****************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#include <jendefs.h>
#include <string.h>
//#include "zps_apl_aib.h"
#include "dlist.h"
#include "zcl.h"
#include "zcl_customcommand.h"

#include "Commissioning.h"
#include "Commissioning_internal.h"

#ifdef CLD_GROUPS
#include "Groups_internal.h"
#endif

#include "zcl_options.h"

#include "dbg.h"

#ifdef DEBUG_CLD_COMMISSIONING
#define TRACE_COMMS    TRUE
#else
#define TRACE_COMMS    FALSE
#endif

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#if defined(CLD_COMMISSIONING) && !defined(COMMISSIONING_SERVER) && !defined(COMMISSIONING_CLIENT)
#error You Must Have either COMMISSIONING_SERVER and/or COMMISSIONING_CLIENT defined in zcl_options.h
#endif

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
#ifdef CLD_COMMISSIONING                        
    
#ifdef COMMISSIONING_SERVER
PRIVATE teZCL_Status eCLD_CommissioningHandleRestartDevice(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance);
                            
PRIVATE  teZCL_Status eCLD_CommissioningHandleModifyStartupParams(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            uint8                       u8CommandId);
#endif

#ifdef COMMISSIONING_CLIENT
PRIVATE teZCL_Status eCLD_CommissioningHandleResponse(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance);
                       
#endif 
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        Public Functions                                              ***/
/****************************************************************************/

/****************************************************************************
 **
 ** NAME:       eCLD_CommissioningCommandHandler
 **
 ** DESCRIPTION:
 ** Handles Message Cluster custom commands
 **
 ** PARAMETERS:               Name                      Usage
 ** ZPS_tsAfEvent            *pZPSevent                 Zigbee stack event structure
 ** tsZCL_EndPointDefinition *psEndPointDefinition      EP structure
 ** tsZCL_ClusterInstance    *psClusterInstance         Cluster structure
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC  teZCL_Status eCLD_CommissioningCommandHandler(
                    ZPS_tsAfEvent               *pZPSevent,
                    tsZCL_EndPointDefinition    *psEndPointDefinition,
                    tsZCL_ClusterInstance       *psClusterInstance)
{

	tsZCL_HeaderParams sZCL_HeaderParams;
    tsCLD_CommissioningCustomDataStructure *psCommon;

    /* Get pointer to custom data structure */
    psCommon = (tsCLD_CommissioningCustomDataStructure*)psClusterInstance->pvEndPointCustomStructPtr;

    /* Store return address details */
    eZCL_SetReceiveEventAddressStructure(pZPSevent, &psCommon->sReceiveEventAddress);

    // further error checking can only be done once we have interrogated the ZCL payload
    u16ZCL_ReadCommandHeader(pZPSevent->uEvent.sApsDataIndEvent.hAPduInst,
                             &sZCL_HeaderParams);
    // get EP mutex
    #ifndef COOPERATIVE
        eZCL_GetMutex(psEndPointDefinition);
    #endif

    // fill in callback event structure
    eZCL_SetCustomCallBackEvent(&psCommon->sCustomCallBackEvent, pZPSevent, sZCL_HeaderParams.u8TransactionSequenceNumber, psEndPointDefinition->u8EndPointNumber);

    /* Fill in message */
    psCommon->sCallBackMessage.u8CommandId = sZCL_HeaderParams.u8CommandIdentifier;

    /* Handle messages appropriate for the cluster type (Client/Server) */
    if(psClusterInstance->bIsServer)
    {

#ifdef COMMISSIONING_SERVER
        // SERVER
        switch(sZCL_HeaderParams.u8CommandIdentifier)
        {

            case (E_CLD_COMMISSIONING_CMD_RESTART_DEVICE):
            {
                eCLD_CommissioningHandleRestartDevice(pZPSevent, psEndPointDefinition, psClusterInstance);
                break;
            }

#ifdef  CLD_COMMISSIONING_CMD_SAVE_STARTUP_PARAMS
            case E_CLD_COMMISSIONING_CMD_SAVE_STARTUP_PARAMS:
#endif
#ifdef CLD_COMMISSIONING_CMD_RESTORE_STARTUP_PARAMS
            case E_CLD_COMMISSIONING_CMD_RESTORE_STARTUP_PARAMS:
#endif
            case E_CLD_COMMISSIONING_CMD_RESET_STARTUP_PARAMS:
                eCLD_CommissioningHandleModifyStartupParams(pZPSevent, psEndPointDefinition, psClusterInstance,sZCL_HeaderParams.u8CommandIdentifier);
                break;

            default:
            {
                // unlock
                #ifndef COOPERATIVE
                    eZCL_ReleaseMutex(psEndPointDefinition);
                #endif

                return(E_ZCL_ERR_CUSTOM_COMMAND_HANDLER_NULL_OR_RETURNED_ERROR);
                break;
            }
        }
#endif

    }
    else
    {

#ifdef COMMISSIONING_CLIENT
        // CLIENT
        switch(sZCL_HeaderParams.u8CommandIdentifier)
        {
            case E_CLD_COMMISSIONING_CMD_RESTART_DEVICE:
#ifdef  CLD_COMMISSIONING_CMD_SAVE_STARTUP_PARAMS
            case E_CLD_COMMISSIONING_CMD_SAVE_STARTUP_PARAMS:
#endif
#ifdef CLD_COMMISSIONING_CMD_RESTORE_STARTUP_PARAMS
            case E_CLD_COMMISSIONING_CMD_RESTORE_STARTUP_PARAMS:
#endif
            case E_CLD_COMMISSIONING_CMD_RESET_STARTUP_PARAMS:
                eCLD_CommissioningHandleResponse(pZPSevent, psEndPointDefinition, psClusterInstance);
                break;

            default:
            {
                // unlock
                #ifndef COOPERATIVE
                    eZCL_ReleaseMutex(psEndPointDefinition);
                #endif

                return(E_ZCL_ERR_CUSTOM_COMMAND_HANDLER_NULL_OR_RETURNED_ERROR);
                break;
            }
        }
#endif

    }

    // unlock
    #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


    // delete the i/p buffer on return
    return(E_ZCL_SUCCESS);

}

/****************************************************************************/
/***        Private Functions                                             ***/
/****************************************************************************/
#ifdef COMMISSIONING_SERVER
/****************************************************************************
 **
 ** NAME:       eCLD_CommissioningHandleRestartDevice
 **
 ** DESCRIPTION:
 ** Handles Restart Device request
 **
 ** PARAMETERS:               Name                      Usage
 ** ZPS_tsAfEvent            *pZPSevent                 Zigbee stack event structure
 ** tsZCL_EndPointDefinition *psEndPointDefinition      EP structure
 ** tsZCL_ClusterInstance    *psClusterInstance         Cluster structure
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PRIVATE  teZCL_Status eCLD_CommissioningHandleRestartDevice(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance)
{

    teZCL_Status eStatus;
    tsCLD_Commissioning_RestartDevicePayload sReqPayload;
    tsCLD_Commissioning_ResponsePayload      sRespPayload;
    uint8   u8TransactionSequenceNumber;
    tsCLD_CommissioningCustomDataStructure *psCommon;
    tsZCL_Address sZCL_Address;

    /* Get pointer to custom data structure */
    psCommon = (tsCLD_CommissioningCustomDataStructure*)psClusterInstance->pvEndPointCustomStructPtr;
    
    /* Receive the command */
    eStatus = eCLD_CommissioningCommandRestartDeviceReceive(
                                            pZPSevent,
                                            &u8TransactionSequenceNumber,
                                            &sReqPayload);
    if(eStatus != E_ZCL_SUCCESS)
    {
        DBG_vPrintf(TRACE_COMMS, "eCLD_CommissioningCommandRestartDeviceReceive Error: %d\r\n", eStatus);
        return eStatus;
    }

    /* Message data for callback */
    psCommon->sCallBackMessage.uReqMessage.psRestartDevicePayload = &sReqPayload;
    psCommon->sCallBackMessage.uRespMessage.psCommissioningResponsePayload = &sRespPayload;

    /* call callback */
    psEndPointDefinition->pCallBackFunctions(&psCommon->sCustomCallBackEvent);

    // build address structure
    eZCL_BuildClientTransmitAddressStructure(&sZCL_Address, &psCommon->sReceiveEventAddress);

    eStatus = eCLD_CommissioningCommandResponseSend(pZPSevent->uEvent.sApsDataIndEvent.u8DstEndpoint,
                                                     pZPSevent->uEvent.sApsDataIndEvent.u8SrcEndpoint,
                                                     &sZCL_Address,
                                                     &u8TransactionSequenceNumber,
                                                     &sRespPayload,
                                                     E_CLD_COMMISSIONING_CMD_RESTART_DEVICE);

    return eStatus;
}
/****************************************************************************
 **
 ** NAME:       eCLD_CommissioningHandleModifyStartupParams
 **
 ** DESCRIPTION:
 ** Handles Save, Restore or Reset Start up Parameters request
 **
 ** PARAMETERS:               Name                      Usage
 ** ZPS_tsAfEvent            *pZPSevent                 Zigbee stack event structure
 ** tsZCL_EndPointDefinition *psEndPointDefinition      EP structure
 ** tsZCL_ClusterInstance    *psClusterInstance         Cluster structure
 ** uint8                     u8CommandId               Command ID
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PRIVATE  teZCL_Status eCLD_CommissioningHandleModifyStartupParams(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            uint8                       u8CommandId)
{

    teZCL_Status eStatus;
    tsCLD_Commissioning_ModifyStartupParametersPayload sReqPayload;
    tsCLD_Commissioning_ResponsePayload      sRespPayload;
    uint8   u8TransactionSequenceNumber;
    tsCLD_CommissioningCustomDataStructure *psCommon;
    tsZCL_Address sZCL_Address;

    /* Get pointer to custom data structure */
    psCommon = (tsCLD_CommissioningCustomDataStructure*)psClusterInstance->pvEndPointCustomStructPtr;
    
    /* Receive the command */
    eStatus = eCLD_CommissioningCommandModifyStartupParamsReceive(
                                            pZPSevent,
                                            &u8TransactionSequenceNumber,
                                            &sReqPayload);
    if(eStatus != E_ZCL_SUCCESS)
    {
        DBG_vPrintf(TRACE_COMMS, "eCLD_CommissioningCommandModifyStartupParamsReceive Error: %d\r\n", eStatus);
        return eStatus;
    }

    /* Message data for callback */
    psCommon->sCallBackMessage.uReqMessage.psModifyStartupParamsPayload = &sReqPayload;
    psCommon->sCallBackMessage.uRespMessage.psCommissioningResponsePayload = &sRespPayload;

    /* call callback */
    psEndPointDefinition->pCallBackFunctions(&psCommon->sCustomCallBackEvent);

    // build address structure
    eZCL_BuildClientTransmitAddressStructure(&sZCL_Address, &psCommon->sReceiveEventAddress);

    eStatus = eCLD_CommissioningCommandResponseSend(pZPSevent->uEvent.sApsDataIndEvent.u8DstEndpoint,
                                                     pZPSevent->uEvent.sApsDataIndEvent.u8SrcEndpoint,
                                                     &sZCL_Address,
                                                     &u8TransactionSequenceNumber,
                                                     &sRespPayload,
                                                     (teCLD_Commissioning_Command)u8CommandId);

    return eStatus;
}
#endif /* COMMISSIONING_SERVER */

#ifdef COMMISSIONING_CLIENT
/****************************************************************************
 **
 ** NAME:       eCLD_CommissioningHandleResponse
 **
 ** DESCRIPTION:
 ** Handles Response received by commissioning cluster
 **
 ** PARAMETERS:               Name                      Usage
 ** ZPS_tsAfEvent            *pZPSevent                 Zigbee stack event structure
 ** tsZCL_EndPointDefinition *psEndPointDefinition      EP structure
 ** tsZCL_ClusterInstance    *psClusterInstance         Cluster structure
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PRIVATE  teZCL_Status eCLD_CommissioningHandleResponse(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance)
{

    teZCL_Status eStatus;
    tsCLD_Commissioning_ResponsePayload sPayload;
    uint8   u8TransactionSequenceNumber;
    tsCLD_CommissioningCustomDataStructure *psCommon;

    /* Get pointer to custom data structure */
    psCommon = (tsCLD_CommissioningCustomDataStructure*)psClusterInstance->pvEndPointCustomStructPtr;

    /* Receive the command */
    eStatus = eCLD_CommissioningCommandResponseReceive(
                                            pZPSevent,
                                            &u8TransactionSequenceNumber,
                                            &sPayload);
    if(eStatus != E_ZCL_SUCCESS)
    {
        DBG_vPrintf(TRACE_COMMS, "eCLD_CommissioningCommandResponseReceive Error: %d\r\n", eStatus);
        return eStatus;
    }

    /* Message data for callback */
    psCommon->sCallBackMessage.uRespMessage.psCommissioningResponsePayload = &sPayload;

    /* call callback */
    psEndPointDefinition->pCallBackFunctions(&psCommon->sCustomCallBackEvent);

    return E_ZCL_SUCCESS;
}
#endif /* COMMISSIONING_CLIENT */

#endif
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

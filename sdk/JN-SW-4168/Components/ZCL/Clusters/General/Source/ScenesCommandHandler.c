/****************************************************************************
 *
 * MODULE:             Scenes Cluster
 *
 * COMPONENT:          $RCSfile $
 *
 * AUTHOR:             Lee Mitchell
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/UnifiedZCL_ZLL102_HA122_Maintenance/Clusters/General/Source/ScenesCommandHandler.c $
 *
 * REVISION:           $Revision: 88298 $
 *
 * DATED:              $Date: 2017-05-16 09:58:29 +0100 (Tue, 16 May 2017) $
 *
 * $LastChangedDate: 2017-05-16 09:58:29 +0100 (Tue, 16 May 2017) $
 *
 * $Id: ScenesCommandHandler.c 88298 2017-05-16 08:58:29Z nxp29741 $
 *
 * DESCRIPTION:
 * Message event handler functions                     $Modtime: $
 *
 * LAST MODIFIED BY:   $Author: nxp29741 $
 *                     $Modtime: $
 *
 ****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products [NXP Microcontrollers such as JN5148, JN5142, JN5139].
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
#include "zps_apl_af.h"
#include "zps_nwk_pub.h"

#include "dlist.h"
#include "zcl.h"
#include "zcl_customcommand.h"

#include "Scenes.h"
#include "Scenes_internal.h"

#include "OnOff_internal.h"

#ifdef CLD_LEVEL_CONTROL
#include "LevelControl.h"
#endif

#ifdef CLD_COLOUR_CONTROL
#include "ColourControl.h"
#endif

#include "zcl_options.h"



#include "dbg.h"

#ifdef DEBUG_CLD_SCENES
#define TRACE_SCENES    TRUE
#else
#define TRACE_SCENES    FALSE
#endif

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#if defined(CLD_SCENES) && !defined(SCENES_SERVER) && !defined(SCENES_CLIENT)
#error You Must Have either SCENES_SERVER and/or SCENES_CLIENT defined zcl_options.h
#endif

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
typedef enum pack
{
    PARSE_CLUSTER_ID,
    PARSER_SKIP,
    PARSER_COPY_TO_DESTINATION
} teZCL_ParseState;
/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
#ifdef SCENES_SERVER
PRIVATE teZCL_Status eCLD_ScenesHandleAddSceneRequest(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition,
							tsZCL_Address *psZCL_Address,
							tsCLD_ScenesCustomDataStructure *psCommon);
							
PRIVATE teZCL_Status eCLD_ScenesCommandAddSceneResponseSend(
                    uint8           u8SourceEndPointId,
                    uint8           u8DestinationEndPointId,
                    tsZCL_Address   *psDestinationAddress,
                    uint8           *pu8TransactionSequenceNumber,
                    tsCLD_ScenesAddSceneResponsePayload *psPayload);

PRIVATE teZCL_Status eCLD_ScenesHandleViewSceneRequest(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition,
							tsZCL_Address *psZCL_Address,
							tsCLD_ScenesCustomDataStructure *psCommon);

PRIVATE teZCL_Status eCLD_ScenesHandleRemoveSceneRequest(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition,
							tsZCL_Address *psZCL_Address,
							tsCLD_ScenesCustomDataStructure *psCommon);

PRIVATE teZCL_Status eCLD_ScenesHandleRemoveAllScenesRequest(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition,
							tsZCL_Address *psZCL_Address,
							tsCLD_ScenesCustomDataStructure *psCommon);

PRIVATE teZCL_Status eCLD_ScenesHandleStoreSceneRequest(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition,
							tsZCL_Address *psZCL_Address,
							tsCLD_ScenesCustomDataStructure *psCommon);

PRIVATE teZCL_Status eCLD_ScenesHandleRecallSceneRequest(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition,
							tsZCL_Address *psZCL_Address,
							tsCLD_ScenesCustomDataStructure *psCommon);

PRIVATE teZCL_Status eCLD_ScenesHandleGetSceneMembershipRequest(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition,
							tsZCL_Address *psZCL_Address,
							tsCLD_ScenesCustomDataStructure *psCommon);

#ifdef  CLD_SCENES_SUPPORT_ZLL_ENHANCED_COMMANDS
PRIVATE teZCL_Status eCLD_ScenesHandleEnhancedAddSceneRequest(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition,
							tsZCL_Address *psZCL_Address,
							tsCLD_ScenesCustomDataStructure *psCommon);

PRIVATE teZCL_Status eCLD_ScenesHandleEnhancedViewSceneRequest(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition,
							tsZCL_Address *psZCL_Address,
							tsCLD_ScenesCustomDataStructure *psCommon);

PRIVATE teZCL_Status eCLD_ScenesHandleCopySceneRequest(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition,
							tsZCL_Address *psZCL_Address,
							tsCLD_ScenesCustomDataStructure *psCommon);
#endif
#endif

#ifdef SCENES_CLIENT
PRIVATE teZCL_Status eCLD_ScenesHandleAddSceneResponse(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition);

PRIVATE teZCL_Status eCLD_ScenesHandleViewSceneResponse(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition);

PRIVATE teZCL_Status eCLD_ScenesHandleRemoveSceneResponse(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition);

PRIVATE teZCL_Status eCLD_ScenesHandleRemoveAllScenesResponse(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition);

PRIVATE teZCL_Status eCLD_ScenesHandleStoreSceneResponse(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition);

PRIVATE teZCL_Status eCLD_ScenesHandleGetSceneMembershipResponse(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition);

#ifdef  CLD_SCENES_SUPPORT_ZLL_ENHANCED_COMMANDS
PRIVATE teZCL_Status eCLD_ScenesHandleEnhancedAddSceneResponse(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition);

PRIVATE teZCL_Status eCLD_ScenesHandleEnhancedViewSceneResponse(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition);

PRIVATE teZCL_Status eCLD_ScenesHandleCopySceneResponse(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition);
#endif
PRIVATE  teZCL_Status eCLD_ScenesHandleSaveSceneConfig(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition);

#endif

#ifdef SCENES_SERVER
PRIVATE teZCL_Status eCLD_ScenesSetLastConfiguredBy(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance);

PRIVATE teZCL_Status eZCL_CustomCommandReceiveScenes(
                    ZPS_tsAfEvent               *pZPSevent,
                    tsZCL_EndPointDefinition   *psEndPointDefinition,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsZCL_RxPayloadItem         *psPayloadDefinition,
                    uint16                       u16InitialOffsetinPayload);
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
 ** NAME:       eCLD_ScenesCommandHandler
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
PUBLIC  teZCL_Status eCLD_ScenesCommandHandler(
                    ZPS_tsAfEvent               *pZPSevent,
                    tsZCL_EndPointDefinition    *psEndPointDefinition,
                    tsZCL_ClusterInstance       *psClusterInstance)
{

	tsZCL_HeaderParams sZCL_HeaderParams;
    tsCLD_ScenesCustomDataStructure *psCommon;

    tsZCL_Address sZCL_Address;
#if defined ( SCENES_SERVER)
    teZCL_Status eStatus = E_ZCL_SUCCESS;
#endif
#if defined( SCENES_SERVER) || defined (SCENES_CLIENT )
	 uint16 u16ActualQuantity;
    /* The u16ActualQuantity and asPayloadDefinition can be declared local to each command handler.
     * This is declared as common to all handlers with default values to save memory*/
    tsZCL_RxPayloadItem asPayloadDefinition[] = {
        	    {1,                                         &u16ActualQuantity,                     E_ZCL_ENUM8,    0},
        	    {1,                                         &u16ActualQuantity,                     E_ZCL_UINT16,   0},
        	    {1,                                         &u16ActualQuantity,                     E_ZCL_UINT8,    0},
        	    {1,                                         &u16ActualQuantity,                     E_ZCL_UINT16,   0},
        	    {1,                                         &u16ActualQuantity,                     E_ZCL_CSTRING,  0},
        	    {CLD_SCENES_MAX_SCENE_STORAGE_BYTES,    	&u16ActualQuantity,  					E_ZCL_UINT8,    0},
    };
#endif
    /* Get pointer to custom data structure */
    psCommon = (tsCLD_ScenesCustomDataStructure*)psClusterInstance->pvEndPointCustomStructPtr;

    /* Store return address details */
    eZCL_SetReceiveEventAddressStructure(pZPSevent, &psCommon->sReceiveEventAddress);

	    // build address structure
    eZCL_BuildClientTransmitAddressStructure(&sZCL_Address, &psCommon->sReceiveEventAddress);

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
        // SERVER
        switch(sZCL_HeaderParams.u8CommandIdentifier)
        {
						case (E_CLD_SCENES_CMD_CONFIG):
						{
								eCLD_ScenesHandleSaveSceneConfig(pZPSevent, psEndPointDefinition, psClusterInstance, &asPayloadDefinition[0]);
								break;
						}
						
#ifdef SCENES_SERVER
            case (E_CLD_SCENES_CMD_ADD):
            {
                eCLD_ScenesHandleAddSceneRequest(pZPSevent, psEndPointDefinition, psClusterInstance,&asPayloadDefinition[1],&sZCL_Address,psCommon);
                break;
            }

            case (E_CLD_SCENES_CMD_VIEW):
            {
                eCLD_ScenesHandleViewSceneRequest(pZPSevent, psEndPointDefinition, psClusterInstance,&asPayloadDefinition[1],&sZCL_Address,psCommon);
                break;
            }

            case (E_CLD_SCENES_CMD_REMOVE):
            {
                eCLD_ScenesHandleRemoveSceneRequest(pZPSevent, psEndPointDefinition, psClusterInstance, &asPayloadDefinition[1],&sZCL_Address,psCommon);
                break;
            }

            case (E_CLD_SCENES_CMD_REMOVE_ALL):
            {
                eCLD_ScenesHandleRemoveAllScenesRequest(pZPSevent, psEndPointDefinition, psClusterInstance, &asPayloadDefinition[1],&sZCL_Address,psCommon);
                break;
            }

            case (E_CLD_SCENES_CMD_STORE):
            {
                eCLD_ScenesHandleStoreSceneRequest(pZPSevent, psEndPointDefinition, psClusterInstance, &asPayloadDefinition[1],&sZCL_Address,psCommon);
                break;
            }

            case (E_CLD_SCENES_CMD_RECALL):
            {
                eStatus = eCLD_ScenesHandleRecallSceneRequest(pZPSevent, psEndPointDefinition, psClusterInstance, &asPayloadDefinition[1],&sZCL_Address,psCommon);
                /* E_ZCL_FAIL means malformed default response already sent */
                if((eStatus !=  E_ZCL_FAIL) && \
                    (((eStatus == E_ZCL_SUCCESS) && !(sZCL_HeaderParams.bDisableDefaultResponse)) || \
                     (eStatus != E_ZCL_SUCCESS)))
                {
                    DBG_vPrintf(TRACE_SCENES, "End scenes Handler %02x\n", eStatus);
                    eZCL_SendDefaultResponse(pZPSevent, eStatus);
                }
                break;
            }

            case (E_CLD_SCENES_CMD_GET_SCENE_MEMBERSHIP):
            {
                eCLD_ScenesHandleGetSceneMembershipRequest(pZPSevent, psEndPointDefinition, psClusterInstance, &asPayloadDefinition[1],&sZCL_Address,psCommon);
                break;
            }

#ifdef  CLD_SCENES_SUPPORT_ZLL_ENHANCED_COMMANDS
            case E_CLD_SCENES_CMD_ENHANCED_ADD_SCENE:
                eCLD_ScenesHandleEnhancedAddSceneRequest(pZPSevent, psEndPointDefinition, psClusterInstance, &asPayloadDefinition[1],&sZCL_Address,psCommon);
                break;

            case E_CLD_SCENES_CMD_ENHANCED_VIEW_SCENE:
                eCLD_ScenesHandleEnhancedViewSceneRequest(pZPSevent, psEndPointDefinition, psClusterInstance, &asPayloadDefinition[1],&sZCL_Address,psCommon);
                break;

            case E_CLD_SCENES_CMD_COPY_SCENE:
                eCLD_ScenesHandleCopySceneRequest(pZPSevent, psEndPointDefinition, psClusterInstance,&asPayloadDefinition[0],&sZCL_Address,psCommon);
                break;
#endif
#endif 
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
    }
    else
    {
#ifdef SCENES_CLIENT
        // CLIENT
        switch(sZCL_HeaderParams.u8CommandIdentifier)
        {
            case (E_CLD_SCENES_CMD_ADD):
            {
                eCLD_ScenesHandleAddSceneResponse(pZPSevent, psEndPointDefinition, psClusterInstance, &asPayloadDefinition[0]);
                break;
            }

            case (E_CLD_SCENES_CMD_VIEW):
            {
                eCLD_ScenesHandleViewSceneResponse(pZPSevent, psEndPointDefinition, psClusterInstance, &asPayloadDefinition[0]);
                break;
            }

            case (E_CLD_SCENES_CMD_REMOVE):
            {
                eCLD_ScenesHandleRemoveSceneResponse(pZPSevent, psEndPointDefinition, psClusterInstance, &asPayloadDefinition[0]);
                break;
            }

            case (E_CLD_SCENES_CMD_REMOVE_ALL):
            {
                eCLD_ScenesHandleRemoveAllScenesResponse(pZPSevent, psEndPointDefinition, psClusterInstance, &asPayloadDefinition[0]);
                break;
            }

            case (E_CLD_SCENES_CMD_STORE):
            {
                eCLD_ScenesHandleStoreSceneResponse(pZPSevent, psEndPointDefinition, psClusterInstance, &asPayloadDefinition[0]);
                break;
            }

            case (E_CLD_SCENES_CMD_GET_SCENE_MEMBERSHIP):
            {
                eCLD_ScenesHandleGetSceneMembershipResponse(pZPSevent, psEndPointDefinition, psClusterInstance, &asPayloadDefinition[0]);
                break;
            }

#ifdef  CLD_SCENES_SUPPORT_ZLL_ENHANCED_COMMANDS
            case E_CLD_SCENES_CMD_ENHANCED_ADD_SCENE:
                eCLD_ScenesHandleEnhancedAddSceneResponse(pZPSevent, psEndPointDefinition, psClusterInstance, &asPayloadDefinition[0]);
                break;

            case E_CLD_SCENES_CMD_ENHANCED_VIEW_SCENE:
                eCLD_ScenesHandleEnhancedViewSceneResponse(pZPSevent, psEndPointDefinition, psClusterInstance, &asPayloadDefinition[0]);
                break;

            case E_CLD_SCENES_CMD_COPY_SCENE:
                eCLD_ScenesHandleCopySceneResponse(pZPSevent, psEndPointDefinition, psClusterInstance, &asPayloadDefinition[0]);
                break;
#endif

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
#ifdef SCENES_SERVER
/****************************************************************************
 **
 ** NAME:       eCLD_ScenesHandleAddSceneRequest
 **
 ** DESCRIPTION:
 ** Handles add scene request
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
PRIVATE  teZCL_Status eCLD_ScenesHandleAddSceneRequest(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition, 
							tsZCL_Address *psZCL_Address,
							tsCLD_ScenesCustomDataStructure *psCommon)
{

    teZCL_Status eStatus;
    tsCLD_ScenesAddSceneRequestPayload sPayload;
    tsCLD_ScenesAddSceneResponsePayload sResponse;
    uint8 au8SceneName[CLD_SCENES_MAX_SCENE_NAME_LENGTH];
    uint8 au8ExtensionData[CLD_SCENES_MAX_SCENE_STORAGE_BYTES];
    uint8   u8TransactionSequenceNumber;

    DBG_vPrintf(TRACE_SCENES, "\neCLD_ScenesCommandAddSceneRequestReceive: ");

    /* Point to storage for received string */
    sPayload.sSceneName.pu8Data = au8SceneName;
    sPayload.sSceneName.u8Length = 0;
    sPayload.sSceneName.u8MaxLength = sizeof(au8SceneName);

    /* Point to storage for scene extension data */
    sPayload.sExtensionField.pu8Data = au8ExtensionData;
    sPayload.sExtensionField.u16Length = 0;
    sPayload.sExtensionField.u8MaxLength = sizeof(au8ExtensionData);

    /* Receive the command */
    pasPayloadDefinition[0].pvDestination = &sPayload.u16GroupId;
    pasPayloadDefinition[1].pvDestination = &sPayload.u8SceneId;
	pasPayloadDefinition[2].pvDestination=  &sPayload.u16TransitionTime;
	pasPayloadDefinition[3].pvDestination = &sPayload.sSceneName;
	pasPayloadDefinition[4].pvDestination = sPayload.sExtensionField.pu8Data;

	pasPayloadDefinition[4].u16MaxQuantity = sPayload.sExtensionField.u8MaxLength;
	pasPayloadDefinition[4].pu16ActualQuantity = &sPayload.sExtensionField.u16Length;


	eStatus = eZCL_CustomCommandReceive(pZPSevent,
									 &u8TransactionSequenceNumber,
									 pasPayloadDefinition,
									 5,
									 E_ZCL_ACCEPT_LESS|E_ZCL_DISABLE_DEFAULT_RESPONSE);
	if (eStatus == E_ZCL_SUCCESS)
	{

		tsZCL_RxPayloadItem sPayloadDefinitionPayLoad;
		sPayloadDefinitionPayLoad.u16MaxQuantity = sPayload.sExtensionField.u8MaxLength;
		sPayloadDefinitionPayLoad.eType = E_ZCL_UINT8;
		sPayloadDefinitionPayLoad.pu16ActualQuantity=&(sPayload.sExtensionField.u16Length);
		memset(sPayload.sExtensionField.pu8Data,0,sPayload.sExtensionField.u8MaxLength);
		sPayloadDefinitionPayLoad.pvDestination = sPayload.sExtensionField.pu8Data;
		eZCL_CustomCommandReceiveScenes(pZPSevent,
                                     psEndPointDefinition,
                                     &u8TransactionSequenceNumber,
                                     &sPayloadDefinitionPayLoad,
                                     /* GroupId (2) + Scene Id (1) + TransitionTime(2)*/
                                     5);
    }

    if(eStatus != E_ZCL_SUCCESS)
    {
        DBG_vPrintf(TRACE_SCENES, "Receive Error: %d", eStatus);
        return eStatus;
    }

    DBG_vPrintf(TRACE_SCENES, "NameLen=%d ExtLen=%d", sPayload.sSceneName.u8Length, sPayload.sExtensionField.u16Length);

#ifdef CLD_COLOUR_CONTROL
    /* Finding the Extension Field Set for Color Control Cluster and
       setting HSV fileds to zero as only XY fields should be considered */
    int i = 0, j = 0;

    while(i < sPayload.sExtensionField.u16Length)
    {
        if(((sPayload.sExtensionField.pu8Data[i+1] << 8) | sPayload.sExtensionField.pu8Data[i]) == LIGHTING_CLUSTER_ID_COLOUR_CONTROL)
        {
            if(sPayload.sExtensionField.pu8Data[i+2] > 0x04)
            {
                /* Starts from an index after the CurrentX and CurrentY */
                j = 5;
                while(j <= sPayload.sExtensionField.pu8Data[i+2])
                {
                    /* As XY mode make other fields to 0 */
                    sPayload.sExtensionField.pu8Data[i+j+2] = 0;
                    j++;
                }
            }
            /* Coming out of the while loop */
            i = sPayload.sExtensionField.u16Length;
        }
        else
        {
            /* Jumping to the next Extension Field Set : i + 2 Bytes for the ClusterId field + 1 Byte for length field + Length of the Extension Field */
            i = i + 2 + 1 + sPayload.sExtensionField.pu8Data[i+2];
        }
    }
#endif //CLD_COLOUR_CONTROL

    /* Message data for callback */
    psCommon->sCallBackMessage.uMessage.psAddSceneRequestPayload = &sPayload;

    /* call callback */
    psEndPointDefinition->pCallBackFunctions(&psCommon->sCustomCallBackEvent);


    /* Try and add the scene to the table */
    eStatus = eCLD_ScenesAddScene(psEndPointDefinition,
                                  psClusterInstance,
                                  &sPayload,
                                  FALSE);

    DBG_vPrintf(TRACE_SCENES, "AddScene: %d", eStatus);

    /* Construct response */
    switch(eStatus)
    {

    case E_ZCL_ERR_INVALID_VALUE:
        sResponse.eStatus = E_CLD_SCENES_CMD_STATUS_INVALID_FIELD;
        break;

    case E_ZCL_ERR_INSUFFICIENT_SPACE:
        sResponse.eStatus = E_CLD_SCENES_CMD_STATUS_INSUFFICIENT_SPACE;
        break;

    case E_ZCL_SUCCESS:
        sResponse.eStatus = E_CLD_SCENES_CMD_STATUS_SUCCESS;

        /* Update attributes */
        eCLD_ScenesCountScenes(psEndPointDefinition, psClusterInstance, &((tsCLD_Scenes*)psClusterInstance->pvEndPointSharedStructPtr)->u8SceneCount);
#ifdef CLD_SCENES_ATTR_LAST_CONFIGURED_BY
        eCLD_ScenesSetLastConfiguredBy(pZPSevent, psEndPointDefinition, psClusterInstance);
        vCLD_ScenesGenerateIndividualAttributeCallback(psEndPointDefinition, psClusterInstance, E_CLD_SCENES_ATTR_ID_LAST_CONFIGURED_BY);
#endif
        break;

    default:
        sResponse.eStatus = E_CLD_SCENES_CMD_STATUS_FAILURE;
        break;

    }

    vSaveScenesNVM();

    /* Check if need to respond back ?*/
    if ( !bZCL_SendCommandResponse( pZPSevent) )
    {
        /* bound, group cast, or broadcast, so don't send a response */
        return E_ZCL_SUCCESS;
    }

    sResponse.u16GroupId = sPayload.u16GroupId;
    sResponse.u8SceneId  = sPayload.u8SceneId;

    eStatus = eCLD_ScenesCommandAddSceneResponseSend(pZPSevent->uEvent.sApsDataIndEvent.u8DstEndpoint,
                                                     pZPSevent->uEvent.sApsDataIndEvent.u8SrcEndpoint,
                                                     psZCL_Address,
                                                     &u8TransactionSequenceNumber,
                                                     &sResponse);

    DBG_vPrintf(TRACE_SCENES, " Send: %d", eStatus);

    return eStatus;
}


/****************************************************************************
 **
 ** NAME:       eCLD_ScenesHandleViewSceneRequest
 **
 ** DESCRIPTION:
 ** Handles view scene request
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
PRIVATE  teZCL_Status eCLD_ScenesHandleViewSceneRequest(
                            ZPS_tsAfEvent                   *pZPSevent,
                            tsZCL_EndPointDefinition        *psEndPointDefinition,
                            tsZCL_ClusterInstance           *psClusterInstance,
                            tsZCL_RxPayloadItem 		    *pasPayloadDefinition,
                            tsZCL_Address                   *psZCL_Address,
                            tsCLD_ScenesCustomDataStructure *psCommon)
{

    teZCL_Status eStatus;
    tsCLD_ScenesViewSceneRequestPayload sPayload;
    tsCLD_ScenesViewSceneResponsePayload sResponse;
    uint8 au8NoSceneName[1] = {0};
    uint8 au8NoExtensionData[1] = {0};
    tsCLD_ScenesTableEntry *psTableEntry;
    uint8   u8TransactionSequenceNumber;
#ifdef CLD_COLOUR_CONTROL
        uint8 au8TempSceneData[CLD_SCENES_MAX_SCENE_STORAGE_BYTES];
#endif

    /* Initialise variable length fields */
    sResponse.sSceneName.pu8Data = au8NoSceneName;
    sResponse.sSceneName.u8Length = 0;
    sResponse.sExtensionField.pu8Data = au8NoExtensionData;
    sResponse.sExtensionField.u16Length = 0;


    DBG_vPrintf(TRACE_SCENES, "\neCLD_ScenesHandleViewSceneRequest ");

    /* Receive the command */
    pasPayloadDefinition[0].pvDestination =  &sPayload.u16GroupId;
    pasPayloadDefinition[1].pvDestination =  &sPayload.u8SceneId;


    eStatus = eZCL_CustomCommandReceive(pZPSevent,
                                        &u8TransactionSequenceNumber,
                                        pasPayloadDefinition,
                                        2,
                                        E_ZCL_ACCEPT_EXACT|E_ZCL_DISABLE_DEFAULT_RESPONSE);

    if(eStatus != E_ZCL_SUCCESS)
    {
        DBG_vPrintf(TRACE_SCENES, "Error: %d", eStatus);
        return eStatus;
    }

    /* Message data for callback */
    psCommon->sCallBackMessage.uMessage.psViewSceneRequestPayload = &sPayload;

    /* call callback */
    psEndPointDefinition->pCallBackFunctions(&psCommon->sCustomCallBackEvent);

    /* Try and find requested scene */
    eStatus = eCLD_ScenesFindScene(psEndPointDefinition,
                                   psClusterInstance,
                                   sPayload.u16GroupId,
                                   sPayload.u8SceneId,
                                   &psTableEntry);

    /* Check if need to respond back ?*/
    if ( !bZCL_SendCommandResponse( pZPSevent) )
    {
        /* bound, group cast, or broadcast, so don't send a response */
        return E_ZCL_SUCCESS;
    }

    /* Construct response */
    switch(eStatus)
    {

    case E_ZCL_SUCCESS:
        sResponse.eStatus = E_CLD_SCENES_CMD_STATUS_SUCCESS;

        sResponse.sSceneName.pu8Data = psTableEntry->au8SceneName;
        sResponse.sSceneName.u8Length = strlen((char*)psTableEntry->au8SceneName);
        sResponse.sSceneName.u8MaxLength = sizeof(psTableEntry->au8SceneName);

        sResponse.u16TransitionTime = psTableEntry->u16TransitionTime;

        /* CCB #1744
         * .. When using the view scene response command, only the CurrentX and 
         * CurrentY entries from the scene table shall be included in the command.
         */
#ifdef CLD_COLOUR_CONTROL
        memset(au8TempSceneData, 0, CLD_SCENES_MAX_SCENE_STORAGE_BYTES);
        uint8 i = 0, x = 0, y = 0;

        /* If extension field set for ColourControl Cluster found, 
         * storing psTableEntry->au8SceneData in au8TempSceneData with CurrentX 
         * and CurrentY fields(Skipping HSL fields).
         */
        while(i < psTableEntry->u16SceneDataLength)
        {
            if(((psTableEntry->au8SceneData[i+1] << 8) | psTableEntry->au8SceneData[i]) == LIGHTING_CLUSTER_ID_COLOUR_CONTROL)
            {
                /* Taking only CurrentX and CurrentY from scene table*/
                switch(psTableEntry->au8SceneData[i+2])
                {
                    case 0x04:
                        while(y < (i + 2 + 1 + 4)) {
                            au8TempSceneData[x++] = psTableEntry->au8SceneData[y++];
                        }
                        i = y;
                        break;
                    case 0x0B:
                        while(y < (i + 2 + 1 + 4)) {
                            au8TempSceneData[x++] = psTableEntry->au8SceneData[y++];
                        }
                        /* Adjusting the length field*/
                        au8TempSceneData[x-0x05] = 0x04;
                        /* Skipping the HSL fields*/
                        y = i + 2 + 1 + 0x0B;
                        i = y;
                        break;
                    default:
                        return E_CLD_SCENES_CMD_STATUS_FAILURE;
                        break;
                }
            }
            else
            {
                /* Store Extension Field Set for non-color cluster
                 * from psTableEntry to au8TempSceneData, as it is.
                 * ( i + 2Bytes for ClusterId field + 1Byte for Length field + Length)
                 */
                while(y < (i + 2 + 1 + psTableEntry->au8SceneData[i+2])) {
                    au8TempSceneData[x++] = psTableEntry->au8SceneData[y++];
                }
                i = y;
            }
        }
        
#ifdef DEBUG_CLD_SCENES
        DBG_vPrintf(TRACE_SCENES,"\n psTableEntry->au8SceneData \n");
        i=0;
        while(i < psTableEntry->u16SceneDataLength)
        {
            DBG_vPrintf(TRACE_SCENES," %02x", psTableEntry->au8SceneData[i++]);
        }
        DBG_vPrintf(TRACE_SCENES,"\n au8TempSceneData \n");
        i=0;
        while(i < x)
        {
            DBG_vPrintf(TRACE_SCENES," %02x", au8TempSceneData[i++]);
        }
#endif

        sResponse.sExtensionField.pu8Data = au8TempSceneData;
        sResponse.sExtensionField.u16Length = x;
        sResponse.sExtensionField.u8MaxLength = sizeof(psTableEntry->au8SceneData);
#else
        sResponse.sExtensionField.pu8Data = psTableEntry->au8SceneData;
        sResponse.sExtensionField.u16Length = psTableEntry->u16SceneDataLength;
        sResponse.sExtensionField.u8MaxLength = sizeof(psTableEntry->au8SceneData);
#endif //CLD_COLOUR_CONTROL

        DBG_vPrintf(TRACE_SCENES, "NameLen=%d ExtLen=%d", sResponse.sSceneName.u8Length, sResponse.sExtensionField.u16Length);
        break;

    case E_ZCL_ERR_INVALID_VALUE:
        sResponse.eStatus = E_CLD_SCENES_CMD_STATUS_INVALID_FIELD;
        break;

    case E_ZCL_ERR_SCENE_NOT_FOUND:
        sResponse.eStatus = E_CLD_SCENES_CMD_STATUS_NOT_FOUND;
        break;

    default:
        sResponse.eStatus = E_CLD_SCENES_CMD_STATUS_FAILURE;
        break;

    }
    sResponse.u16GroupId = sPayload.u16GroupId;
    sResponse.u8SceneId  = sPayload.u8SceneId;

    eStatus = eCLD_ScenesCommandViewSceneResponseSend(pZPSevent->uEvent.sApsDataIndEvent.u8DstEndpoint,
                                                     pZPSevent->uEvent.sApsDataIndEvent.u8SrcEndpoint,
                                                     psZCL_Address,
                                                     &u8TransactionSequenceNumber,
                                                     &sResponse);

    return eStatus;

}


/****************************************************************************
 **
 ** NAME:       eCLD_ScenesHandleRemoveSceneRequest
 **
 ** DESCRIPTION:
 ** Handles remove scene request
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
PRIVATE  teZCL_Status eCLD_ScenesHandleRemoveSceneRequest(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition,
							tsZCL_Address *psZCL_Address,
							tsCLD_ScenesCustomDataStructure *psCommon)
{

    teZCL_Status eStatus;
    tsCLD_ScenesRemoveSceneRequestPayload sPayload;
    tsCLD_ScenesRemoveSceneResponsePayload sResponse;
    uint8   u8TransactionSequenceNumber;

    /* Receive the command */
    pasPayloadDefinition[0].pvDestination =   &sPayload.u16GroupId;
    pasPayloadDefinition[1].pvDestination =   &sPayload.u8SceneId;

    eStatus = eZCL_CustomCommandReceive(pZPSevent,
                                         &u8TransactionSequenceNumber,
                                         pasPayloadDefinition,
                                         2,
                                         E_ZCL_ACCEPT_EXACT|E_ZCL_DISABLE_DEFAULT_RESPONSE);

    if(eStatus != E_ZCL_SUCCESS)
    {
        DBG_vPrintf(TRACE_SCENES, "\neCLD_ScenesCommandRemoveSceneRequestReceive Error: %d", eStatus);
        return eStatus;
    }

    /* Message data for callback */
    psCommon->sCallBackMessage.uMessage.psRemoveSceneRequestPayload = &sPayload;

    /* call callback */
    psEndPointDefinition->pCallBackFunctions(&psCommon->sCustomCallBackEvent);

    /* Try and remove the scene from the table */
    eStatus = eCLD_ScenesRemoveScene(psEndPointDefinition,
                                     psClusterInstance,
                                     &sPayload);

    /* Construct response */
    switch(eStatus)
    {

    case E_ZCL_SUCCESS:
        sResponse.eStatus = E_CLD_SCENES_CMD_STATUS_SUCCESS;

        /* Update attributes */
        eCLD_ScenesCountScenes(psEndPointDefinition, psClusterInstance, &((tsCLD_Scenes*)psClusterInstance->pvEndPointSharedStructPtr)->u8SceneCount);
#ifdef CLD_SCENES_ATTR_LAST_CONFIGURED_BY
        eCLD_ScenesSetLastConfiguredBy(pZPSevent, psEndPointDefinition, psClusterInstance);
        vCLD_ScenesGenerateIndividualAttributeCallback(psEndPointDefinition, psClusterInstance, E_CLD_SCENES_ATTR_ID_LAST_CONFIGURED_BY);
#endif
        break;

    case E_ZCL_FAIL:
        sResponse.eStatus = E_CLD_SCENES_CMD_STATUS_NOT_FOUND;
        break;

    case E_ZCL_ERR_INVALID_VALUE:
        sResponse.eStatus = E_CLD_SCENES_CMD_STATUS_INVALID_FIELD;
        break;

    default:
        sResponse.eStatus = E_CLD_SCENES_CMD_STATUS_FAILURE;
        break;

    }

    vSaveScenesNVM();

    /* Check if need to respond back ?*/
    if ( !bZCL_SendCommandResponse( pZPSevent) )
    {
        /* bound, group cast, or broadcast, so don't send a response */
        return E_ZCL_SUCCESS;
    }

    sResponse.u16GroupId = sPayload.u16GroupId;
    sResponse.u8SceneId = sPayload.u8SceneId;

    eStatus = eCLD_ScenesCommandRemoveSceneResponseSend(pZPSevent->uEvent.sApsDataIndEvent.u8DstEndpoint,
                                                        pZPSevent->uEvent.sApsDataIndEvent.u8SrcEndpoint,
                                                        psZCL_Address,
                                                        &u8TransactionSequenceNumber,
                                                        &sResponse);

    return eStatus;
}


/****************************************************************************
 **
 ** NAME:       eCLD_ScenesHandleRemoveAllScenesRequest
 **
 ** DESCRIPTION:
 ** Handles remove all scenes request
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
PRIVATE  teZCL_Status eCLD_ScenesHandleRemoveAllScenesRequest(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition,
							tsZCL_Address *psZCL_Address,
							tsCLD_ScenesCustomDataStructure *psCommon)
{

    teZCL_Status eStatus;
    tsCLD_ScenesRemoveAllScenesRequestPayload sPayload;
    tsCLD_ScenesRemoveAllScenesResponsePayload sResponse;
    uint8   u8TransactionSequenceNumber;

    /* Receive the command */
    pasPayloadDefinition[0].pvDestination =   &sPayload.u16GroupId;
    
    eStatus =  eZCL_CustomCommandReceive(pZPSevent,
                                        &u8TransactionSequenceNumber,
                                        pasPayloadDefinition,
                                        1,
                                        E_ZCL_ACCEPT_EXACT|E_ZCL_DISABLE_DEFAULT_RESPONSE);

    if(eStatus != E_ZCL_SUCCESS)
    {
        DBG_vPrintf(TRACE_SCENES, "\neCLD_ScenesCommandRemoveAllScenesRequestReceive Error: %d", eStatus);
        return eStatus;
    }

    /* Message data for callback */
    psCommon->sCallBackMessage.uMessage.psRemoveAllScenesRequestPayload = &sPayload;

    /* call callback */
    psEndPointDefinition->pCallBackFunctions(&psCommon->sCustomCallBackEvent);

    /* Delete all scene entries for this group */
    eStatus = eCLD_ScenesRemoveAllScenes(psEndPointDefinition->u8EndPointNumber,
                                         sPayload.u16GroupId,
                                         (uint64)0xffffffffffffffffLL);

    /* Construct response */
    switch(eStatus)
    {

    case E_ZCL_SUCCESS:
        sResponse.eStatus = E_CLD_SCENES_CMD_STATUS_SUCCESS;
        /* Update attributes */
        // ToDo:JV: Removeed below line as u8SceneCount is decremented inside eCLD_ScenesRemoveAllScenes
        //((tsCLD_Scenes*)psClusterInstance->pvEndPointSharedStructPtr)->u8SceneCount = 0; 
#ifdef CLD_SCENES_ATTR_LAST_CONFIGURED_BY
        eCLD_ScenesSetLastConfiguredBy(pZPSevent, psEndPointDefinition, psClusterInstance);
        vCLD_ScenesGenerateIndividualAttributeCallback(psEndPointDefinition, psClusterInstance, E_CLD_SCENES_ATTR_ID_LAST_CONFIGURED_BY);
#endif
        break;

    case E_ZCL_ERR_INVALID_VALUE:
        sResponse.eStatus = E_CLD_SCENES_CMD_STATUS_INVALID_FIELD;
        break;

    default:
        sResponse.eStatus = E_CLD_SCENES_CMD_STATUS_FAILURE;
        break;

    }

    vSaveScenesNVM();

    /* Check if need to respond back ?*/
    if ( !bZCL_SendCommandResponse( pZPSevent) )
    {
        /* bound, group cast, or broadcast, so don't send a response */
        return E_ZCL_SUCCESS;
    }

    sResponse.u16GroupId = sPayload.u16GroupId;

    eStatus = eCLD_ScenesCommandRemoveAllScenesResponseSend(pZPSevent->uEvent.sApsDataIndEvent.u8DstEndpoint,
                                                            pZPSevent->uEvent.sApsDataIndEvent.u8SrcEndpoint,
                                                            psZCL_Address,
                                                            &u8TransactionSequenceNumber,
                                                            &sResponse);

    return eStatus;
}


/****************************************************************************
 **
 ** NAME:       eCLD_ScenesHandleStoreSceneRequest
 **
 ** DESCRIPTION:
 ** Handles store scene request
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
PRIVATE  teZCL_Status eCLD_ScenesHandleStoreSceneRequest(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition,
							tsZCL_Address *psZCL_Address,
							tsCLD_ScenesCustomDataStructure *psCommon)
{

    teZCL_Status eStatus;
    tsCLD_ScenesStoreSceneRequestPayload sPayload;
    tsCLD_ScenesStoreSceneResponsePayload sResponse;
    tsCLD_ScenesTableEntry *psTableEntry;
    uint8   u8TransactionSequenceNumber;
    tsZCL_CallBackEvent sZCL_CallBackEvent;

    /* Receive the command */
    pasPayloadDefinition[0].pvDestination =   &sPayload.u16GroupId;
    pasPayloadDefinition[1].pvDestination =   &sPayload.u8SceneId;

    eStatus = eZCL_CustomCommandReceive(pZPSevent,
                                        &u8TransactionSequenceNumber,
                                        pasPayloadDefinition,
                                        2,
                                        E_ZCL_ACCEPT_EXACT|E_ZCL_DISABLE_DEFAULT_RESPONSE);
										
										

    if(eStatus != E_ZCL_SUCCESS)
    {
        DBG_vPrintf(TRACE_SCENES, "\neCLD_ScenesCommandStoreSceneRequestReceive Error: %d", eStatus);
        return eStatus;
    }

    /* Message data for callback */
    psCommon->sCallBackMessage.uMessage.psStoreSceneRequestPayload = &sPayload;

    /* call callback */
    psEndPointDefinition->pCallBackFunctions(&psCommon->sCustomCallBackEvent);

    /* Scene not valid */
    ((tsCLD_Scenes*)psClusterInstance->pvEndPointSharedStructPtr)->bSceneValid = FALSE;

    /* Try and get a table entry for the scene */
    eStatus = eCLD_ScenesStoreScene(psEndPointDefinition,
                                    psClusterInstance,
                                    sPayload.u16GroupId,
                                    sPayload.u8SceneId,
                                    &psTableEntry);


    switch(eStatus)
    {

    case E_ZCL_ERR_INVALID_VALUE:
        sResponse.eStatus = E_CLD_SCENES_CMD_STATUS_INVALID_FIELD;
        break;

    case E_ZCL_ERR_INSUFFICIENT_SPACE:
        sResponse.eStatus = E_CLD_SCENES_CMD_STATUS_INSUFFICIENT_SPACE;
        break;

    case E_ZCL_SUCCESS:
        sResponse.eStatus = E_CLD_SCENES_CMD_STATUS_SUCCESS;

        /* Save all clusters on this end point */
        eStatus = eCLD_ScenesSaveClusters(psEndPointDefinition,
                                          sizeof(psTableEntry->au8SceneData),
                                          &psTableEntry->u16SceneDataLength,
                                          psTableEntry->au8SceneData,
                                          FALSE);
        if(eStatus != E_ZCL_SUCCESS)
        {
            DBG_vPrintf(TRACE_SCENES, "\neCLD_ScenesSaveClusters returned %d", eStatus);
            sResponse.eStatus = E_CLD_SCENES_CMD_STATUS_INSUFFICIENT_SPACE;
        }

#ifdef DEBUG_CLD_SCENES
        {
            int n;

            for(n = 0; n < psTableEntry->u16SceneDataLength; n++)
            {
                DBG_vPrintf(TRACE_SCENES, " %02x", psTableEntry->au8SceneData[n]);
            }
        }
#endif

        /* Update attributes */
        eCLD_ScenesCountScenes(psEndPointDefinition, psClusterInstance, &((tsCLD_Scenes*)psClusterInstance->pvEndPointSharedStructPtr)->u8SceneCount);

        ((tsCLD_Scenes*)psClusterInstance->pvEndPointSharedStructPtr)->bSceneValid      = TRUE;
        ((tsCLD_Scenes*)psClusterInstance->pvEndPointSharedStructPtr)->u16CurrentGroup  = sPayload.u16GroupId;
        ((tsCLD_Scenes*)psClusterInstance->pvEndPointSharedStructPtr)->u8CurrentScene   = sPayload.u8SceneId;

#ifdef CLD_SCENES_ATTR_LAST_CONFIGURED_BY
        eCLD_ScenesSetLastConfiguredBy(pZPSevent, psEndPointDefinition, psClusterInstance);
#endif


        /* Inform the application that the cluster has just been updated */
        sZCL_CallBackEvent.u8EndPoint = psEndPointDefinition->u8EndPointNumber;
        sZCL_CallBackEvent.psClusterInstance = psClusterInstance;
        sZCL_CallBackEvent.pZPSevent = NULL;
        sZCL_CallBackEvent.eEventType = E_ZCL_CBET_CLUSTER_UPDATE;

        // inform user
        psEndPointDefinition->pCallBackFunctions(&sZCL_CallBackEvent);



        break;

    default:
        break;

    }

    vSaveScenesNVM();

    /* Check if need to respond back ?*/
    if ( !bZCL_SendCommandResponse( pZPSevent) )
    {
        /* bound, group cast, or broadcast, so don't send a response */
        return E_ZCL_SUCCESS;
    }

    /* Construct response */
    sResponse.u16GroupId = sPayload.u16GroupId;
    sResponse.u8SceneId  = sPayload.u8SceneId;

    eStatus = eCLD_ScenesCommandStoreSceneResponseSend(pZPSevent->uEvent.sApsDataIndEvent.u8DstEndpoint,
                                                       pZPSevent->uEvent.sApsDataIndEvent.u8SrcEndpoint,
                                                       psZCL_Address,
                                                       &u8TransactionSequenceNumber,
                                                       &sResponse);

    return eStatus;
}


/****************************************************************************
 **
 ** NAME:       eCLD_ScenesHandleRecallSceneRequest
 **
 ** DESCRIPTION:
 ** Handles recall scene request
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
PRIVATE  teZCL_Status eCLD_ScenesHandleRecallSceneRequest(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition,
							tsZCL_Address *psZCL_Address,
							tsCLD_ScenesCustomDataStructure *psCommon)
{

    teZCL_Status eStatus;
    tsCLD_ScenesRecallSceneRequestPayload sPayload;
    tsCLD_ScenesTableEntry *psTableEntry;
    tsCLD_ScenesTableEntry *psOldActiveScene;


    /* Receive the command */
    pasPayloadDefinition[0].pvDestination =   &sPayload.u16GroupId;
    pasPayloadDefinition[1].pvDestination =   &sPayload.u8SceneId;

    eStatus = eZCL_CustomCommandReceive(pZPSevent,
                                        &psCommon->sCustomCallBackEvent.u8TransactionSequenceNumber,
                                        pasPayloadDefinition,
                                        2,
                                        E_ZCL_ACCEPT_EXACT|E_ZCL_DISABLE_DEFAULT_RESPONSE);


    if(eStatus != E_ZCL_SUCCESS)
    {
        DBG_vPrintf(TRACE_SCENES, "\neCLD_ScenesCommandRecallSceneRequestReceive Error: %d", eStatus);
        return eStatus;
    }

    /* Message data for callback */
    psCommon->sCallBackMessage.uMessage.psRecallSceneRequestPayload = &sPayload;

    /* call callback */
    psEndPointDefinition->pCallBackFunctions(&psCommon->sCustomCallBackEvent);


    /* See if the scene exists */
    eStatus = eCLD_ScenesFindScene(psEndPointDefinition,
                                   psClusterInstance,
                                   sPayload.u16GroupId,
                                   sPayload.u8SceneId,
                                   &psTableEntry);
    if(eStatus != E_ZCL_SUCCESS)
    {
        DBG_vPrintf(TRACE_SCENES, "\neCLD_ScenesFindScene returned %d", eStatus);
        if (eStatus == E_ZCL_ERR_INVALID_VALUE)
        {
            eStatus = E_ZCL_CMDS_INVALID_FIELD;
        }
        else if (eStatus == E_ZCL_ERR_SCENE_NOT_FOUND)
        {
            eStatus = E_ZCL_CMDS_NOT_FOUND;
        }
        return eStatus;
    }

#if (defined CLD_COLOUR_CONTROL && defined CLD_COLOURCONTROL_ATTR_COLOUR_MODE)
    /* Finding the Extension Field Set for Color Control Cluster and 
       updating u8ColourMode based on Extension Field Set */
    int i = 0;
    while(i < psTableEntry->u16SceneDataLength)
    {
        if(((psTableEntry->au8SceneData[i+1] << 8) | psTableEntry->au8SceneData[i]) == LIGHTING_CLUSTER_ID_COLOUR_CONTROL)
        {
            /* When CurrentX and CurrentY fields have non Zero value, setting ColorMode to CurrentXY
               else setting ColorMode to HSV */
            if((psTableEntry->au8SceneData[i+3] > 0x00) || 
               (psTableEntry->au8SceneData[i+4] > 0x00) ||
               (psTableEntry->au8SceneData[i+5] > 0x00) ||
               (psTableEntry->au8SceneData[i+6] > 0x00))
            {
                eCLD_ColourControlHandleColourModeChange(psEndPointDefinition->u8EndPointNumber,
                                                     E_CLD_COLOURCONTROL_COLOURMODE_CURRENT_X_AND_CURRENT_Y);
            }
            else
            {
                #if (CLD_COLOURCONTROL_COLOUR_CAPABILITIES & COLOUR_CAPABILITY_ENHANCE_HUE_SUPPORTED)
                    eCLD_ColourControlHandleColourModeChange(psEndPointDefinition->u8EndPointNumber,
                                                             E_CLD_COLOURCONTROL_COLOURMODE_ENHANCED_CURRENT_HUE_AND_CURRENT_SATURATION);
                #else
                    eCLD_ColourControlHandleColourModeChange(psEndPointDefinition->u8EndPointNumber,
                                                             E_CLD_COLOURCONTROL_COLOURMODE_CURRENT_HUE_AND_CURRENT_SATURATION);
                #endif
            }
            /* Coming out of the while loop */
            i = psTableEntry->u16SceneDataLength;
        }
        else
        {
            /* Jumping to the next Extension Field Set : i + 2 Bytes for the ClusterId field + 1 Byte for length field + Length of the Extension Field */
            i = i + 2 + 1 + psTableEntry->au8SceneData[i+2];
        }
    }
#endif //CLD_COLOUR_CONTROL && CLD_COLOURCONTROL_ATTR_COLOUR_MODE

    /* See if there are any active scenes */
    eStatus = eCLD_ScenesFindActiveScene(psEndPointDefinition,
                                         psClusterInstance,
                                         &psOldActiveScene);
    /* If an active scene was found, make it inactive and set transition timer to 0 */
    if(eStatus == E_ZCL_SUCCESS)
    {
        psOldActiveScene->bActive = FALSE;
        psOldActiveScene->u32TransitionTimer = 0;
    }

    /* Before making new scene active, stopping the level control cluster's ongoing transitions */
    #ifdef LEVEL_CONTROL_SERVER
        eCLD_LevelControlStopTransition(psEndPointDefinition->u8EndPointNumber);
    #endif

    /* Make new scene active */
    psTableEntry->u32TransitionTimer = psTableEntry->u16TransitionTime * 10;
#ifdef CLD_SCENES_SUPPORT_ZLL_ENHANCED_COMMANDS
    psTableEntry->u32TransitionTimer += psTableEntry->u8TransitionTime100ms;
#endif

    psTableEntry->bActive = TRUE;
    psTableEntry->bInTransit = TRUE;

    /* Update attributes */
    ((tsCLD_Scenes*)psClusterInstance->pvEndPointSharedStructPtr)->bSceneValid = TRUE;
    vCLD_ScenesGenerateIndividualAttributeCallback(psEndPointDefinition, psClusterInstance, E_CLD_SCENES_ATTR_ID_SCENE_VALID);

    ((tsCLD_Scenes*)psClusterInstance->pvEndPointSharedStructPtr)->u16CurrentGroup = sPayload.u16GroupId;
    vCLD_ScenesGenerateIndividualAttributeCallback(psEndPointDefinition, psClusterInstance, E_CLD_SCENES_ATTR_ID_CURRENT_GROUP);

    ((tsCLD_Scenes*)psClusterInstance->pvEndPointSharedStructPtr)->u8CurrentScene = sPayload.u8SceneId;
    vCLD_ScenesGenerateIndividualAttributeCallback(psEndPointDefinition, psClusterInstance, E_CLD_SCENES_ATTR_ID_CURRENT_SCENE);

#ifdef DEBUG_CLD_SCENES
    {
        int x;
        DBG_vPrintf(TRACE_SCENES, "\nActivating scene Group%04x Scene%02x Time%d Name=", psTableEntry->u16GroupId, psTableEntry->u8SceneId, psTableEntry->u16TransitionTime);
        for(x = 0; x < psTableEntry->u8SceneNameLength; x++)
        {
            DBG_vPrintf(TRACE_SCENES, "%c", psTableEntry->au8SceneName[x]);
        }

        for(x = 0; x < psTableEntry->u16SceneDataLength; x++)
        {
            DBG_vPrintf(TRACE_SCENES, " %02x", psTableEntry->au8SceneData[x]);
        }

    }
#endif

#if ((defined ONOFF_SERVER) && (defined CLD_ONOFF_ATTR_GLOBAL_SCENE_CONTROL))
    /* Set Global Scene Control attribute to true */
    eCLD_OnOffSetGlobalSceneControl(psEndPointDefinition->u8EndPointNumber, TRUE);
#endif    

    return E_ZCL_SUCCESS;
}


/****************************************************************************
 **
 ** NAME:       eCLD_ScenesHandleGetSceneMembershipRequest
 **
 ** DESCRIPTION:
 ** Handles get scene membership request
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
PRIVATE  teZCL_Status eCLD_ScenesHandleGetSceneMembershipRequest(
                            ZPS_tsAfEvent                   *pZPSevent,
                            tsZCL_EndPointDefinition        *psEndPointDefinition,
                            tsZCL_ClusterInstance           *psClusterInstance,
                            tsZCL_RxPayloadItem 		    *pasPayloadDefinition,
							tsZCL_Address                   *psZCL_Address,
							tsCLD_ScenesCustomDataStructure *psCommon)
{

    teZCL_Status eStatus;
    tsCLD_ScenesGetSceneMembershipRequestPayload sPayload;
    tsCLD_ScenesGetSceneMembershipResponsePayload sResponse;
    uint8   u8TransactionSequenceNumber;
    uint8 u8NumberOfScenes=0;
    uint8 au8ScenesList[CLD_SCENES_MAX_NUMBER_OF_SCENES];

    /* Receive the command */
    pasPayloadDefinition[0].pvDestination =   &sPayload.u16GroupId;

    eStatus =eZCL_CustomCommandReceive(pZPSevent,
                                        &u8TransactionSequenceNumber,
                                        pasPayloadDefinition,
                                        1,
                                        E_ZCL_ACCEPT_EXACT|E_ZCL_DISABLE_DEFAULT_RESPONSE);

    if(eStatus != E_ZCL_SUCCESS)
    {
        DBG_vPrintf(TRACE_SCENES, "\neCLD_ScenesCommandGetSceneMembershipRequestReceive Error: %d", eStatus);
        return eStatus;
    }

    /* Message data for callback */
    psCommon->sCallBackMessage.uMessage.psGetSceneMembershipRequestPayload = &sPayload;

    /* call callback */
    psEndPointDefinition->pCallBackFunctions(&psCommon->sCustomCallBackEvent);

    eStatus = eCLD_ScenesListScenes(psEndPointDefinition,
                                    psClusterInstance,
                                    sPayload.u16GroupId,
                                    &u8NumberOfScenes,
                                    au8ScenesList);

    switch(eStatus)
    {

    case E_ZCL_ERR_INVALID_VALUE:
        sResponse.eStatus = E_CLD_SCENES_CMD_STATUS_INVALID_FIELD;
        break;

    case E_ZCL_SUCCESS:
        sResponse.eStatus = E_CLD_SCENES_CMD_STATUS_SUCCESS;
        break;

    default:
        break;

    }


#ifdef ZLL_CMD_RESPONSE_OPTION
    if(!bZCL_SendCommandResponse( pZPSevent))
#else
    /* Check if need to respond back ?
     * Special Case : Send response for group cast request if scene entry found for the group.
     */
    if(  !bZCL_SendCommandResponse( pZPSevent) && ( u8NumberOfScenes == 0 )  )
#endif
    {
        /* group cast or broadcast without any scene, so don't send a response */
        return E_ZCL_SUCCESS;
    }

    /* Construct response */
    sResponse.u16GroupId = sPayload.u16GroupId;
    sResponse.u8SceneCount = u8NumberOfScenes;
    sResponse.pu8SceneList = au8ScenesList;

    eStatus = eCLD_ScenesCountScenes(psEndPointDefinition,
                                     psClusterInstance,
                                     &u8NumberOfScenes);

    sResponse.u8Capacity = CLD_SCENES_MAX_NUMBER_OF_SCENES - u8NumberOfScenes;

    eStatus = eCLD_ScenesCommandGetSceneMembershipResponseSend(pZPSevent->uEvent.sApsDataIndEvent.u8DstEndpoint,
                                                               pZPSevent->uEvent.sApsDataIndEvent.u8SrcEndpoint,
                                                               psZCL_Address,
                                                               &u8TransactionSequenceNumber,
                                                               &sResponse);

    return eStatus;
}
#endif

#ifdef SCENES_CLIENT
/****************************************************************************
 **
 ** NAME:       eCLD_ScenesHandleAddSceneResponse
 **
 ** DESCRIPTION:
 ** Handles add scene response
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
PRIVATE  teZCL_Status eCLD_ScenesHandleAddSceneResponse(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition)
{

    teZCL_Status eStatus;
    tsCLD_ScenesAddSceneResponsePayload sPayload;
    tsCLD_ScenesCustomDataStructure *psCommon;

    /* Get pointer to custom data structure */
    psCommon = (tsCLD_ScenesCustomDataStructure*)psClusterInstance->pvEndPointCustomStructPtr;

    /* Receive the command */
    pasPayloadDefinition[0].pvDestination =   &sPayload.eStatus;
    pasPayloadDefinition[1].pvDestination =   &sPayload.u16GroupId;
    pasPayloadDefinition[2].pvDestination =   &sPayload.u8SceneId;

    eStatus = eZCL_CustomCommandReceive(pZPSevent,
                                        &psCommon->sCustomCallBackEvent.u8TransactionSequenceNumber,
                                        pasPayloadDefinition,
                                        3,
                                        E_ZCL_ACCEPT_EXACT);

    if(eStatus != E_ZCL_SUCCESS)
    {
        DBG_vPrintf(TRACE_SCENES, "\neCLD_ScenesCommandAddSceneResponseReceive Error: %d", eStatus);
        return eStatus;
    }

    /* Message data for callback */
    psCommon->sCallBackMessage.uMessage.psAddSceneResponsePayload = &sPayload;

    /* call callback */
    psEndPointDefinition->pCallBackFunctions(&psCommon->sCustomCallBackEvent);

    return E_ZCL_SUCCESS;
}


/****************************************************************************
 **
 ** NAME:       eCLD_ScenesHandleViewSceneResponse
 **
 ** DESCRIPTION:
 ** Handles view scene response
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
PRIVATE  teZCL_Status eCLD_ScenesHandleViewSceneResponse(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition)
{

    teZCL_Status eStatus;
    tsCLD_ScenesViewSceneResponsePayload sPayload;
    uint8 au8SceneName[CLD_SCENES_MAX_SCENE_NAME_LENGTH];
    uint8 au8ExtensionData[CLD_SCENES_MAX_SCENE_STORAGE_BYTES];
    tsCLD_ScenesCustomDataStructure *psCommon;

    /* Initialise variable length fields */
    sPayload.sSceneName.pu8Data = au8SceneName;
    sPayload.sSceneName.u8MaxLength = sizeof(au8SceneName);
    sPayload.sExtensionField.pu8Data = au8ExtensionData;
    sPayload.sExtensionField.u8MaxLength = sizeof(au8ExtensionData);

    /* Get pointer to custom data structure */
    psCommon = (tsCLD_ScenesCustomDataStructure*)psClusterInstance->pvEndPointCustomStructPtr;

    /* Receive the command */
    pasPayloadDefinition[0].pvDestination =   &sPayload.eStatus;
    pasPayloadDefinition[1].pvDestination =   &sPayload.u16GroupId;
    pasPayloadDefinition[2].pvDestination =   &sPayload.u8SceneId;
	pasPayloadDefinition[3].pvDestination =   &sPayload.u16TransitionTime;
	pasPayloadDefinition[4].pvDestination =   &sPayload.sSceneName;
	pasPayloadDefinition[5].pvDestination =   sPayload.sExtensionField.pu8Data;

	pasPayloadDefinition[5].u16MaxQuantity =   CLD_SCENES_MAX_SCENE_STORAGE_BYTES;
	pasPayloadDefinition[5].pu16ActualQuantity =  &sPayload.sExtensionField.u16Length;

	eStatus = eZCL_CustomCommandReceive(pZPSevent,
                                        &psCommon->sCustomCallBackEvent.u8TransactionSequenceNumber,
                                        pasPayloadDefinition,
                                        6,
                                        E_ZCL_ACCEPT_LESS);

    if(eStatus != E_ZCL_SUCCESS)
    {
        DBG_vPrintf(TRACE_SCENES, "\neCLD_ScenesHandleViewSceneResponse Error: %d", eStatus);
        return eStatus;
    }

    /* Message data for callback */
    psCommon->sCallBackMessage.uMessage.psViewSceneResponsePayload = &sPayload;

    /* call callback */
    psEndPointDefinition->pCallBackFunctions(&psCommon->sCustomCallBackEvent);

    return E_ZCL_SUCCESS;
}


/****************************************************************************
 **
 ** NAME:       eCLD_ScenesHandleRemoveSceneResponse
 **
 ** DESCRIPTION:
 ** Handles remove scene response
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
PRIVATE  teZCL_Status eCLD_ScenesHandleRemoveSceneResponse(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition)
{

    teZCL_Status eStatus;
    tsCLD_ScenesRemoveSceneResponsePayload sPayload;
    tsCLD_ScenesCustomDataStructure *psCommon;

    /* Get pointer to custom data structure */
    psCommon = (tsCLD_ScenesCustomDataStructure*)psClusterInstance->pvEndPointCustomStructPtr;

    /* Receive the command */
    pasPayloadDefinition[0].pvDestination =   &sPayload.eStatus;
    pasPayloadDefinition[1].pvDestination =   &sPayload.u16GroupId;
    pasPayloadDefinition[2].pvDestination =   &sPayload.u8SceneId;

    eStatus = eZCL_CustomCommandReceive(pZPSevent,
                                        &psCommon->sCustomCallBackEvent.u8TransactionSequenceNumber,
                                        pasPayloadDefinition,
                                        3,
                                        E_ZCL_ACCEPT_EXACT);

    if(eStatus != E_ZCL_SUCCESS)
    {
        DBG_vPrintf(TRACE_SCENES, "\neCLD_ScenesCommandRemoveSceneResponseReceive Error: %d", eStatus);
        return eStatus;
    }

    /* Message data for callback */
    psCommon->sCallBackMessage.uMessage.psRemoveSceneResponsePayload = &sPayload;

    /* call callback */
    psEndPointDefinition->pCallBackFunctions(&psCommon->sCustomCallBackEvent);

    return E_ZCL_SUCCESS;
}


/****************************************************************************
 **
 ** NAME:       eCLD_ScenesHandleRemoveAllScenesResponse
 **
 ** DESCRIPTION:
 ** Handles remove all scenes response
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
PRIVATE  teZCL_Status eCLD_ScenesHandleRemoveAllScenesResponse(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition)
{

    teZCL_Status eStatus;
    tsCLD_ScenesRemoveAllScenesResponsePayload sPayload;
    tsCLD_ScenesCustomDataStructure *psCommon;

    /* Get pointer to custom data structure */
    psCommon = (tsCLD_ScenesCustomDataStructure*)psClusterInstance->pvEndPointCustomStructPtr;

    /* Receive the command */
    pasPayloadDefinition[0].pvDestination =   &sPayload.eStatus;
    pasPayloadDefinition[1].pvDestination =   &sPayload.u16GroupId;

    eStatus = eZCL_CustomCommandReceive(pZPSevent,
                                         &psCommon->sCustomCallBackEvent.u8TransactionSequenceNumber,
                                         pasPayloadDefinition,
                                         2,
                                         E_ZCL_ACCEPT_EXACT);

    if(eStatus != E_ZCL_SUCCESS)
    {
        DBG_vPrintf(TRACE_SCENES, "\neCLD_ScenesCommandRemoveAllScenesResponseReceive Error: %d", eStatus);
        return eStatus;
    }

    /* Message data for callback */
    psCommon->sCallBackMessage.uMessage.psRemoveAllScenesResponsePayload = &sPayload;

    /* call callback */
    psEndPointDefinition->pCallBackFunctions(&psCommon->sCustomCallBackEvent);

    return E_ZCL_SUCCESS;
}


/****************************************************************************
 **
 ** NAME:       eCLD_ScenesHandleStoreSceneResponse
 **
 ** DESCRIPTION:
 ** Handles store scene response
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
PRIVATE  teZCL_Status eCLD_ScenesHandleStoreSceneResponse(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition)
{

    teZCL_Status eStatus;
    tsCLD_ScenesStoreSceneResponsePayload sPayload;
    tsCLD_ScenesCustomDataStructure *psCommon;

    /* Get pointer to custom data structure */
    psCommon = (tsCLD_ScenesCustomDataStructure*)psClusterInstance->pvEndPointCustomStructPtr;

    /* Receive the command */
    pasPayloadDefinition[0].pvDestination =   &sPayload.eStatus;
    pasPayloadDefinition[1].pvDestination =   &sPayload.u16GroupId;
	pasPayloadDefinition[2].pvDestination =   &sPayload.u8SceneId;

    eStatus = eZCL_CustomCommandReceive(pZPSevent,
                                         &psCommon->sCustomCallBackEvent.u8TransactionSequenceNumber,
                                         pasPayloadDefinition,
                                         3,
                                         E_ZCL_ACCEPT_EXACT);

    if(eStatus != E_ZCL_SUCCESS)
    {
        DBG_vPrintf(TRACE_SCENES, "\neCLD_ScenesCommandStoreSceneResponseReceive Error: %d", eStatus);
        return eStatus;
    }

    /* Message data for callback */
    psCommon->sCallBackMessage.uMessage.psStoreSceneResponsePayload = &sPayload;

    /* call callback */
    psEndPointDefinition->pCallBackFunctions(&psCommon->sCustomCallBackEvent);

    return E_ZCL_SUCCESS;
}


/****************************************************************************
 **
 ** NAME:       eCLD_ScenesHandleGetSceneMembershipResponse
 **
 ** DESCRIPTION:
 ** Handles Get Scene Membership response
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
PRIVATE  teZCL_Status eCLD_ScenesHandleGetSceneMembershipResponse(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition)
{

    teZCL_Status eStatus;
    tsCLD_ScenesGetSceneMembershipResponsePayload sPayload;
    uint8 au8ScenesList[CLD_SCENES_MAX_NUMBER_OF_SCENES];
    tsCLD_ScenesCustomDataStructure *psCommon;

    sPayload.pu8SceneList = au8ScenesList;

    /* Get pointer to custom data structure */
    psCommon = (tsCLD_ScenesCustomDataStructure*)psClusterInstance->pvEndPointCustomStructPtr;

    /* Receive the command */
    pasPayloadDefinition[0].pvDestination = &sPayload.eStatus;
    pasPayloadDefinition[1].pvDestination = &sPayload.u8Capacity;
    pasPayloadDefinition[2].pvDestination = &sPayload.u16GroupId;
    pasPayloadDefinition[3].pvDestination = &sPayload.u8SceneCount;
    pasPayloadDefinition[4].pvDestination = sPayload.pu8SceneList;

    pasPayloadDefinition[1].eType =E_ZCL_UINT8;
    pasPayloadDefinition[2].eType =E_ZCL_UINT16;
    pasPayloadDefinition[3].eType =E_ZCL_UINT8;
    pasPayloadDefinition[4].eType =E_ZCL_UINT8;

    pasPayloadDefinition[4].u16MaxQuantity =CLD_SCENES_MAX_NUMBER_OF_SCENES;

    eStatus = eZCL_CustomCommandReceive(pZPSevent,
                                        &psCommon->sCustomCallBackEvent.u8TransactionSequenceNumber,
                                        pasPayloadDefinition,
                                        5,
                                        E_ZCL_ACCEPT_LESS);

    if(eStatus != E_ZCL_SUCCESS)
    {
        DBG_vPrintf(TRACE_SCENES, "\neCLD_ScenesCommandGetSceneMembershipResponseReceive Error: %d", eStatus);
        return eStatus;
    }

    /* Message data for callback */
    psCommon->sCallBackMessage.uMessage.psGetSceneMembershipResponsePayload = &sPayload;

    /* call callback */
    psEndPointDefinition->pCallBackFunctions(&psCommon->sCustomCallBackEvent);

    return E_ZCL_SUCCESS;
}

#ifdef  CLD_SCENES_SUPPORT_ZLL_ENHANCED_COMMANDS
/****************************************************************************
 **
 ** NAME:       eCLD_ScenesHandleEnhancedAddSceneResponse
 **
 ** DESCRIPTION:
 ** Handles Enhanced Add Scene response
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
PRIVATE  teZCL_Status eCLD_ScenesHandleEnhancedAddSceneResponse(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition)
{
    teZCL_Status eStatus;
    tsCLD_ScenesEnhancedAddSceneResponsePayload sPayload;
    tsCLD_ScenesCustomDataStructure *psCommon;

    /* Get pointer to custom data structure */
    psCommon = (tsCLD_ScenesCustomDataStructure*)psClusterInstance->pvEndPointCustomStructPtr;

    /* Receive the command */
    pasPayloadDefinition[0].pvDestination = &sPayload.eStatus;
    pasPayloadDefinition[1].pvDestination = &sPayload.u16GroupId;
    pasPayloadDefinition[2].pvDestination = &sPayload.u8SceneId;

    eStatus = eZCL_CustomCommandReceive(pZPSevent,
                                        &psCommon->sCustomCallBackEvent.u8TransactionSequenceNumber,
                                        pasPayloadDefinition,
                                        3,
                                        E_ZCL_ACCEPT_EXACT);

    if(eStatus != E_ZCL_SUCCESS)
    {
        DBG_vPrintf(TRACE_SCENES, "\neCLD_ScenesCommandAddSceneResponseReceive Error: %d", eStatus);
        return eStatus;
    }

    /* Message data for callback */
    psCommon->sCallBackMessage.uMessage.psEnhancedAddSceneResponsePayload = &sPayload;

    /* call callback */
    psEndPointDefinition->pCallBackFunctions(&psCommon->sCustomCallBackEvent);

    return E_ZCL_SUCCESS;
}


/****************************************************************************
 **
 ** NAME:       eCLD_ScenesHandleEnhancedViewSceneResponse
 **
 ** DESCRIPTION:
 ** Handles Enhanced View Scene response
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
PRIVATE  teZCL_Status eCLD_ScenesHandleEnhancedViewSceneResponse(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition)
{
    teZCL_Status eStatus;
    tsCLD_ScenesEnhancedViewSceneResponsePayload sPayload;
    uint8 au8SceneName[CLD_SCENES_MAX_SCENE_NAME_LENGTH];
    uint8 au8ExtensionData[CLD_SCENES_MAX_SCENE_STORAGE_BYTES];
    //uint8   u8TransactionSequenceNumber;
    tsCLD_ScenesCustomDataStructure *psCommon;

    /* Initialise variable length fields */
    sPayload.sSceneName.pu8Data = au8SceneName;
    sPayload.sSceneName.u8MaxLength = sizeof(au8SceneName);
    sPayload.sExtensionField.pu8Data = au8ExtensionData;
    sPayload.sExtensionField.u8MaxLength = sizeof(au8ExtensionData);

    /* Get pointer to custom data structure */
    psCommon = (tsCLD_ScenesCustomDataStructure*)psClusterInstance->pvEndPointCustomStructPtr;

    /* Receive the command */
    pasPayloadDefinition[0].pvDestination = &sPayload.eStatus;
    pasPayloadDefinition[1].pvDestination = &sPayload.u16GroupId;
	pasPayloadDefinition[2].pvDestination = &sPayload.u8SceneId;
	pasPayloadDefinition[3].pvDestination = &sPayload.u16TransitionTime;
	pasPayloadDefinition[4].pvDestination = &sPayload.sSceneName;
	pasPayloadDefinition[5].pvDestination = sPayload.sExtensionField.pu8Data;

    eStatus =  eZCL_CustomCommandReceive(pZPSevent,
                                         &psCommon->sCustomCallBackEvent.u8TransactionSequenceNumber,
                                         pasPayloadDefinition,
                                         6,
                                         E_ZCL_ACCEPT_LESS);

    if(eStatus != E_ZCL_SUCCESS)
    {
        DBG_vPrintf(TRACE_SCENES, "\neCLD_ScenesHandleViewSceneResponse Error: %d", eStatus);
        return eStatus;
    }

    /* Message data for callback */
    psCommon->sCallBackMessage.uMessage.psEnhancedViewSceneResponsePayload = &sPayload;

    /* call callback */
    psEndPointDefinition->pCallBackFunctions(&psCommon->sCustomCallBackEvent);

    return E_ZCL_SUCCESS;
}


/****************************************************************************
 **
 ** NAME:       eCLD_ScenesHandleCopySceneResponse
 **
 ** DESCRIPTION:
 ** Handles Copy Scene response
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
PRIVATE  teZCL_Status eCLD_ScenesHandleCopySceneResponse(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition)
{
    teZCL_Status eStatus;
    tsCLD_ScenesCopySceneResponsePayload sPayload;
    //uint8   u8TransactionSequenceNumber;
    tsCLD_ScenesCustomDataStructure *psCommon;


    /* Get pointer to custom data structure */
    psCommon = (tsCLD_ScenesCustomDataStructure*)psClusterInstance->pvEndPointCustomStructPtr;

    /* Receive the command */
    pasPayloadDefinition[0].pvDestination = &sPayload.u8Status;
    pasPayloadDefinition[1].pvDestination = &sPayload.u16FromGroupId;
	pasPayloadDefinition[2].pvDestination = &sPayload.u8FromSceneId;


    eStatus = eZCL_CustomCommandReceive(pZPSevent,
                                        &psCommon->sCustomCallBackEvent.u8TransactionSequenceNumber,
                                        pasPayloadDefinition,
                                        3,
                                        E_ZCL_ACCEPT_EXACT);

    if(eStatus != E_ZCL_SUCCESS)
    {
        DBG_vPrintf(TRACE_SCENES, "\neCLD_ScenesHandleViewSceneResponse Error: %d", eStatus);
        return eStatus;
    }

    /* Message data for callback */
    psCommon->sCallBackMessage.uMessage.psCopySceneResponsePayload = &sPayload;

    /* call callback */
    psEndPointDefinition->pCallBackFunctions(&psCommon->sCustomCallBackEvent);

    return E_ZCL_SUCCESS;
}

#endif

PRIVATE  teZCL_Status eCLD_ScenesHandleSaveSceneConfig(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem 		*pasPayloadDefinition)
{
	teZCL_Status eStatus=E_ZCL_SUCCESS;
	uint8 u16GroupId=0;
	uint8 u8TransactionSequenceNumber;
	uint8 u8NumberOfScenes=0;

	/* Receive the command */
	pasPayloadDefinition[0].pvDestination = &u16GroupId;

	eStatus =eZCL_CustomCommandReceive(pZPSevent,
																			&u8TransactionSequenceNumber,
																			pasPayloadDefinition,
																			1,
																			E_ZCL_ACCEPT_EXACT|E_ZCL_DISABLE_DEFAULT_RESPONSE);

	if(eStatus != E_ZCL_SUCCESS)
	{
			DBG_vPrintf(TRACE_SCENES, "\neCLD_ScenesHandleSaveSceneConfig Error: %d", eStatus);
	}else{
			eCLD_ScenesSaveConfig(u16GroupId);	
	}

	return eStatus;
}

#endif // SCENES_CLIENT

/****************************************************************************
 **
 ** NAME:       eCLD_ScenesSetLastConfiguredBy
 **
 ** DESCRIPTION:
 ** Saves the Mac address of the sender of the last message in the last
 ** configured by attribute
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
#ifdef SCENES_SERVER
PRIVATE  teZCL_Status eCLD_ScenesSetLastConfiguredBy(
        ZPS_tsAfEvent               *pZPSevent,
        tsZCL_EndPointDefinition    *psEndPointDefinition,
        tsZCL_ClusterInstance       *psClusterInstance)
{

#ifdef CLD_SCENES_ATTR_LAST_CONFIGURED_BY

    uint64 u64MacAddress;
    #ifdef STRICT_PARAM_CHECK
        if((pZPSevent == NULL) || (psEndPointDefinition == NULL) || (psClusterInstance == NULL))
        {
            return E_ZCL_ERR_PARAMETER_NULL;
        }
    #endif

    if(pZPSevent->uEvent.sApsDataIndEvent.u8SrcAddrMode == E_ZCL_AM_IEEE)
    {
        ((tsCLD_Scenes*)psClusterInstance->pvEndPointSharedStructPtr)->u64LastConfiguredBy = pZPSevent->uEvent.sApsDataIndEvent.uSrcAddress.u64Addr;
    }
    else
    {
        u64MacAddress = ZPS_u64NwkNibFindExtAddr(ZPS_pvNwkGetHandle(), pZPSevent->uEvent.sApsDataIndEvent.uSrcAddress.u16Addr);
        if(u64MacAddress == ZPS_NWK_NULL_EXT_ADDR)
        {
            u64MacAddress = (uint64)0xffffffffffffffffLL;
        }
        ((tsCLD_Scenes*)psClusterInstance->pvEndPointSharedStructPtr)->u64LastConfiguredBy = u64MacAddress;
    }

#endif

    return E_ZCL_SUCCESS;

}
#endif

#ifdef SCENES_SERVER
#ifdef  CLD_SCENES_SUPPORT_ZLL_ENHANCED_COMMANDS
/****************************************************************************
 **
 ** NAME:       eCLD_ScenesHandleEnhancedAddSceneRequest
 **
 ** DESCRIPTION:
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
PRIVATE  teZCL_Status eCLD_ScenesHandleEnhancedAddSceneRequest(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem         *pasPayloadDefinition,
                            tsZCL_Address               *psZCL_Address,
                            tsCLD_ScenesCustomDataStructure *psCommon)
{
    teZCL_Status eStatus;
    tsCLD_ScenesEnhancedAddSceneRequestPayload sPayload;
    tsCLD_ScenesEnhancedAddSceneResponsePayload sResponse;
    uint8 au8SceneName[CLD_SCENES_MAX_SCENE_NAME_LENGTH];
    uint8 au8ExtensionData[CLD_SCENES_MAX_SCENE_STORAGE_BYTES];
    uint8   u8TransactionSequenceNumber;

    DBG_vPrintf(TRACE_SCENES, "\neCLD_ScenesHandleEnhancedAddSceneRequest: ");

    /* Point to storage for received string */
    sPayload.sSceneName.pu8Data = au8SceneName;
    sPayload.sSceneName.u8Length = 0;
    sPayload.sSceneName.u8MaxLength = sizeof(au8SceneName);

    /* Point to storage for scene extension data */
    sPayload.sExtensionField.pu8Data = au8ExtensionData;
    sPayload.sExtensionField.u16Length = 0;
    sPayload.sExtensionField.u8MaxLength = sizeof(au8ExtensionData);

    /* Receive the command */
    pasPayloadDefinition[0].pvDestination = &sPayload.u16GroupId;
    pasPayloadDefinition[1].pvDestination = &sPayload.u8SceneId;
    pasPayloadDefinition[2].pvDestination = &sPayload.u16TransitionTime100ms;
    pasPayloadDefinition[3].pvDestination = &sPayload.sSceneName;
    pasPayloadDefinition[4].pvDestination = sPayload.sExtensionField.pu8Data;

    pasPayloadDefinition[4].u16MaxQuantity = sPayload.sExtensionField.u8MaxLength;
    pasPayloadDefinition[4].pu16ActualQuantity = &sPayload.sExtensionField.u16Length;

    eStatus =  eZCL_CustomCommandReceive(pZPSevent,
                                       &u8TransactionSequenceNumber,
                                       pasPayloadDefinition,
                                       5,
                                       E_ZCL_ACCEPT_LESS|E_ZCL_DISABLE_DEFAULT_RESPONSE);
    if (eStatus == E_ZCL_SUCCESS)
    {
        tsZCL_RxPayloadItem sPayloadDefinitionPayLoad;
        sPayloadDefinitionPayLoad.u16MaxQuantity = sPayload.sExtensionField.u8MaxLength;
        sPayloadDefinitionPayLoad.eType = E_ZCL_UINT8;
        sPayloadDefinitionPayLoad.pu16ActualQuantity=&(sPayload.sExtensionField.u16Length);
        memset(sPayload.sExtensionField.pu8Data,0,sPayload.sExtensionField.u8MaxLength);
        sPayloadDefinitionPayLoad.pvDestination = sPayload.sExtensionField.pu8Data;
        eZCL_CustomCommandReceiveScenes(pZPSevent,
                                        psEndPointDefinition,
                                        &u8TransactionSequenceNumber,
                                        &sPayloadDefinitionPayLoad,
                                        /* GroupId (2) + Scene Id (1) + TransitionTime(2)*/
                                        5);
    }
    else
    {
        DBG_vPrintf(TRACE_SCENES, " Error: %d", eStatus);
        return eStatus;
    }

#ifdef CLD_COLOUR_CONTROL
    /* Finding the Extension Field Set for Color Control Cluster and
       Updating irrelavent fields to zero. */
    int i = 0,j = 0;
    while(i < sPayload.sExtensionField.u16Length)
    {
        if(((sPayload.sExtensionField.pu8Data[i+1] << 8) | sPayload.sExtensionField.pu8Data[i]) == LIGHTING_CLUSTER_ID_COLOUR_CONTROL)
        {
            /* CCB#11683
               On receipt of the enhanced add scene command of the scenes cluster,
               if the CurrentX and CurrentY parameters are set to zero, the scene
               shall be composed of only the EnhancedCurrentHue, CurrentSaturation,
               ColorLoopActive, ColorLoopDirection and ColorLoopTime parameters.
               If the CurrentX and CurrentY parameters are not set to zero, the 
               scene shall be composed of only the CurrentX and CurrentY parameters.
               All other scene table entries shall be set to zero. */
            if(sPayload.sExtensionField.pu8Data[i+2] > 0x04)
            {
                /* Starts from an index after the CurrentX and CurrentY */
                j = 5;
                while(j <= sPayload.sExtensionField.pu8Data[i+2])
                {
                    /*If CurrentX <> 0 || CurrentY <> 0 THEN  XY Mode ELSE Hue\Sat mode */
                    if((sPayload.sExtensionField.pu8Data[i+3] > 0x00) || 
                       (sPayload.sExtensionField.pu8Data[i+4] > 0x00) ||
                       (sPayload.sExtensionField.pu8Data[i+5] > 0x00) ||
                       (sPayload.sExtensionField.pu8Data[i+6] > 0x00))
                    {
                        /* As XY mode make other fields to 0 */
                        sPayload.sExtensionField.pu8Data[i+j+2] = 0;
                    }
                    j++;
                }
            }  
            /* Coming out of the while loop */
            i = sPayload.sExtensionField.u16Length;
        }
        else
        {
            /* Jumping to the next Extension Field Set : i + 2 Bytes for the ClusterId field + 1 Byte for length field + Length of the Extension Field */
            i = i + 2 + 1 + sPayload.sExtensionField.pu8Data[i+2];
        }
    }
#endif //CLD_COLOUR_CONTROL

    /* Message data for callback */
    psCommon->sCallBackMessage.uMessage.psEnhancedAddSceneRequestPayload = &sPayload;

    /* call callback */
    psEndPointDefinition->pCallBackFunctions(&psCommon->sCustomCallBackEvent);

    DBG_vPrintf(TRACE_SCENES, "SNL%d SEL%d", sPayload.sSceneName.u8Length, sPayload.sExtensionField.u16Length);

    /* Try and add the scene to the table */
    eStatus = eCLD_ScenesAddScene(psEndPointDefinition,
                                  psClusterInstance,
                                  (tsCLD_ScenesAddSceneRequestPayload*)&sPayload,
                                  TRUE);

    /* Construct response */
    switch(eStatus)
    {

    case E_ZCL_ERR_INVALID_VALUE:
        sResponse.eStatus = E_CLD_SCENES_CMD_STATUS_INVALID_FIELD;
        break;

    case E_ZCL_ERR_INSUFFICIENT_SPACE:
        sResponse.eStatus = E_CLD_SCENES_CMD_STATUS_INSUFFICIENT_SPACE;
        break;

    case E_ZCL_SUCCESS:
        sResponse.eStatus = E_CLD_SCENES_CMD_STATUS_SUCCESS;

        /* Update attributes */
        eCLD_ScenesCountScenes(psEndPointDefinition, psClusterInstance, &((tsCLD_Scenes*)psClusterInstance->pvEndPointSharedStructPtr)->u8SceneCount);
#ifdef CLD_SCENES_ATTR_LAST_CONFIGURED_BY
        eCLD_ScenesSetLastConfiguredBy(pZPSevent, psEndPointDefinition, psClusterInstance);
        vCLD_ScenesGenerateIndividualAttributeCallback(psEndPointDefinition, psClusterInstance, E_CLD_SCENES_ATTR_ID_LAST_CONFIGURED_BY);
#endif
        break;

    default:
        sResponse.eStatus = E_CLD_SCENES_CMD_STATUS_FAILURE;
        break;

    }

    vSaveScenesNVM();

    /* Check if need to respond back ?*/
    if ( !bZCL_SendCommandResponse( pZPSevent) )
    {
        /* bound, group cast, or broadcast, so don't send a response */
        return E_ZCL_SUCCESS;
    }

    sResponse.u16GroupId = sPayload.u16GroupId;
    sResponse.u8SceneId  = sPayload.u8SceneId;

    eStatus = eCLD_ScenesCommandEnhancedAddSceneResponseSend(pZPSevent->uEvent.sApsDataIndEvent.u8DstEndpoint,
                                                     pZPSevent->uEvent.sApsDataIndEvent.u8SrcEndpoint,
                                                     psZCL_Address,
                                                     &u8TransactionSequenceNumber,
                                                     &sResponse);

    return eStatus;
}


/****************************************************************************
 **
 ** NAME:       eCLD_ScenesHandleEnhancedViewSceneRequest
 **
 ** DESCRIPTION:
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
PRIVATE  teZCL_Status eCLD_ScenesHandleEnhancedViewSceneRequest(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem         *pasPayloadDefinition,
                            tsZCL_Address               *psZCL_Address,
                            tsCLD_ScenesCustomDataStructure *psCommon)
{
    teZCL_Status eStatus;
    tsCLD_ScenesEnhancedViewSceneRequestPayload sPayload;
    tsCLD_ScenesEnhancedViewSceneResponsePayload sResponse;
    uint8 au8NoSceneName[1] = {0};
    uint8 au8NoExtensionData[1] = {0};
    tsCLD_ScenesTableEntry *psTableEntry;
    uint8   u8TransactionSequenceNumber;

    /* Initialise variable length fields */
    sResponse.sSceneName.pu8Data = au8NoSceneName;
    sResponse.sSceneName.u8Length = 0;
    sResponse.sExtensionField.pu8Data = au8NoExtensionData;
    sResponse.sExtensionField.u16Length = 0;

    DBG_vPrintf(TRACE_SCENES, "\neCLD_ScenesHandleEnhancedViewSceneRequest: ");

    /* Receive the command */
    pasPayloadDefinition[0].pvDestination = &sPayload.u16GroupId;
    pasPayloadDefinition[1].pvDestination = &sPayload.u8SceneId;

    eStatus =  eZCL_CustomCommandReceive(pZPSevent,
                                        &u8TransactionSequenceNumber,
                                        pasPayloadDefinition,
                                        2,
                                        E_ZCL_ACCEPT_EXACT|E_ZCL_DISABLE_DEFAULT_RESPONSE);

    if(eStatus != E_ZCL_SUCCESS)
    {
        DBG_vPrintf(TRACE_SCENES, "Error: %d", eStatus);
        return eStatus;
    }

    /* Message data for callback */
    psCommon->sCallBackMessage.uMessage.psEnhancedViewSceneRequestPayload = &sPayload;

    /* call callback */
    psEndPointDefinition->pCallBackFunctions(&psCommon->sCustomCallBackEvent);

    /* Try and find requested scene */
    eStatus = eCLD_ScenesFindScene(psEndPointDefinition,
                                   psClusterInstance,
                                   sPayload.u16GroupId,
                                   sPayload.u8SceneId,
                                   &psTableEntry);

    DBG_vPrintf(TRACE_SCENES, "Find: %d", eStatus);

    /* Construct response */
    switch(eStatus)
    {

    case E_ZCL_SUCCESS:
        sResponse.eStatus = E_CLD_SCENES_CMD_STATUS_SUCCESS;

        sResponse.sSceneName.pu8Data = psTableEntry->au8SceneName;
        sResponse.sSceneName.u8Length = strlen((char*)psTableEntry->au8SceneName);
        sResponse.sSceneName.u8MaxLength = sizeof(psTableEntry->au8SceneName);

        sResponse.u16TransitionTime = psTableEntry->u16TransitionTime * 10 + psTableEntry->u8TransitionTime100ms;

        sResponse.sExtensionField.pu8Data = psTableEntry->au8SceneData;
        sResponse.sExtensionField.u16Length = psTableEntry->u16SceneDataLength;
        sResponse.sExtensionField.u8MaxLength = sizeof(psTableEntry->au8SceneData);

        DBG_vPrintf(TRACE_SCENES, "SNL%d SEL%d", sResponse.sSceneName.u8Length, sResponse.sExtensionField.u16Length);

        break;

    case E_ZCL_ERR_INVALID_VALUE:
        sResponse.eStatus = E_CLD_SCENES_CMD_STATUS_INVALID_FIELD;
        break;

    case E_ZCL_ERR_SCENE_NOT_FOUND:
        sResponse.eStatus = E_CLD_SCENES_CMD_STATUS_NOT_FOUND;
        break;

    default:
        sResponse.eStatus = E_CLD_SCENES_CMD_STATUS_FAILURE;
        break;

    }
    sResponse.u16GroupId = sPayload.u16GroupId;
    sResponse.u8SceneId  = sPayload.u8SceneId;

    /* Check if need to respond back ?*/
    if ( !bZCL_SendCommandResponse( pZPSevent) )
    {
        /* bound, group cast, or broadcast, so don't send a response */
        return E_ZCL_SUCCESS;
    }

    eStatus = eCLD_ScenesCommandEnhancedViewSceneResponseSend(pZPSevent->uEvent.sApsDataIndEvent.u8DstEndpoint,
                                                     pZPSevent->uEvent.sApsDataIndEvent.u8SrcEndpoint,
                                                     psZCL_Address,
                                                     &u8TransactionSequenceNumber,
                                                     &sResponse);

    DBG_vPrintf(TRACE_SCENES, "Send: %d", eStatus);

    return eStatus;

}


/****************************************************************************
 **
 ** NAME:       eCLD_ScenesHandleCopySceneRequest
 **
 ** DESCRIPTION:
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
PRIVATE  teZCL_Status eCLD_ScenesHandleCopySceneRequest(
                            ZPS_tsAfEvent               *pZPSevent,
                            tsZCL_EndPointDefinition    *psEndPointDefinition,
                            tsZCL_ClusterInstance       *psClusterInstance,
                            tsZCL_RxPayloadItem         *pasPayloadDefinition,
                            tsZCL_Address               *psZCL_Address,
                            tsCLD_ScenesCustomDataStructure *psCommon)
{
    uint8 u8Status;
    tsCLD_ScenesCopySceneRequestPayload sPayload;
    tsCLD_ScenesCopySceneResponsePayload sResponse;
    uint8   u8TransactionSequenceNumber;

    DBG_vPrintf(TRACE_SCENES, "\neCLD_ScenesHandleCopySceneRequest: ");

    /* Receive the command */
    pasPayloadDefinition[0].pvDestination = &sPayload.u8Mode;
    pasPayloadDefinition[1].pvDestination = &sPayload.u16FromGroupId;
    pasPayloadDefinition[2].pvDestination = &sPayload.u8FromSceneId;
    pasPayloadDefinition[3].pvDestination = &sPayload.u16ToGroupId;
    pasPayloadDefinition[4].pvDestination = &sPayload.u8ToSceneId;
    pasPayloadDefinition[4].eType =E_ZCL_UINT8;

    u8Status = eZCL_CustomCommandReceive(pZPSevent,
                                        &u8TransactionSequenceNumber,
                                        pasPayloadDefinition,
                                        5,
                                        E_ZCL_ACCEPT_EXACT|E_ZCL_DISABLE_DEFAULT_RESPONSE);


    if(u8Status != E_ZCL_SUCCESS)
    {
        DBG_vPrintf(TRACE_SCENES, "Error: %d", u8Status);
        return u8Status;
    }

    DBG_vPrintf(TRACE_SCENES, "Mode%d Group%d:%d Scene%d:%d", sPayload.u8Mode,
                                                              sPayload.u16FromGroupId, sPayload.u16ToGroupId,
                                                              sPayload.u8FromSceneId, sPayload.u8ToSceneId);

    /* Message data for callback */
    psCommon->sCallBackMessage.uMessage.psCopySceneRequestPayload = &sPayload;

    /* call callback */
    psEndPointDefinition->pCallBackFunctions(&psCommon->sCustomCallBackEvent);

    /* Copy all scene's or just one ? */
    if(sPayload.u8Mode & CLD_SCENES_COPY_ALL_SCENES)
    {

        /* Copy all scene's from one group to another */
        u8Status = eCLD_ScenesCopyAllScenes(psEndPointDefinition,
                                           psClusterInstance,
                                           sPayload.u16FromGroupId,
                                           sPayload.u16ToGroupId);

    }
    else
    {

        /* Copy a single scene */
        u8Status = eCLD_ScenesCopyScene(psEndPointDefinition,
                                       psClusterInstance,
                                       sPayload.u16FromGroupId,
                                       sPayload.u8FromSceneId,
                                       sPayload.u16ToGroupId,
                                       sPayload.u8ToSceneId);

    }

    vSaveScenesNVM();

    /* If message was addressed to multiple nodes, exit, no response */
    if((pZPSevent->uEvent.sApsDataIndEvent.u8DstAddrMode == ZPS_E_ADDR_MODE_BOUND)  ||
       (pZPSevent->uEvent.sApsDataIndEvent.u8DstAddrMode == ZPS_E_ADDR_MODE_GROUP))
    {
        return E_ZCL_SUCCESS;
    }

    switch(u8Status)
    {

    case E_ZCL_SUCCESS:
        sResponse.u8Status = E_CLD_SCENES_CMD_STATUS_SUCCESS;
        break;

    case E_CLD_SCENES_NO_RESOURCES:
        sResponse.u8Status = E_CLD_SCENES_CMD_STATUS_INSUFFICIENT_SPACE;
        break;

    case E_CLD_SCENES_NOT_FOUND:
        sResponse.u8Status = E_CLD_SCENES_CMD_STATUS_INVALID_FIELD;
        break;

    case E_CLD_GROUPS_NOT_FOUND:
        sResponse.u8Status = E_CLD_SCENES_CMD_STATUS_INVALID_FIELD;
        break;

    default:
        break;

    }

    /* Check if need to respond back ?*/
    if ( !bZCL_SendCommandResponse( pZPSevent) )
    {
        /* bound, group cast, or broadcast, so don't send a response */
        return E_ZCL_SUCCESS;
    }

    sResponse.u16FromGroupId = sPayload.u16FromGroupId;
    sResponse.u8FromSceneId = sPayload.u8FromSceneId;

    u8Status = eCLD_ScenesCommandCopySceneResponseSend(pZPSevent->uEvent.sApsDataIndEvent.u8DstEndpoint,
                                                     pZPSevent->uEvent.sApsDataIndEvent.u8SrcEndpoint,
                                                     psZCL_Address,
                                                     &u8TransactionSequenceNumber,
                                                     &sResponse);


    return u8Status;

}
#endif
#endif
#ifdef SCENES_SERVER
/****************************************************************************
 **
 ** NAME:       eZCL_CustomCommandReceiveScenes
 **
 ** DESCRIPTION:
 ** handles rx of a custom command for scenes cluster for variable payload in add scenes
 **
 ** PARAMETERS:               Name                          Usage
 ** ZPS_tsAfEvent            *pZPSevent                     Zigbee stack event structure
 ** tsZCL_EndPointDefinition *psEndPointDefinition          EP structure
 ** tsZCL_ClusterInstance    *psClusterInstance             Cluster structure
 ** uint8                    *pu8TransactionSequenceNumber  Sequence number Pointer
 ** tsZCL_RxPayloadItem      *psPayloadDefinition           Payload definition
 ** uint16                   u16InitialOffsetinPayload      Inialial offset
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/

PRIVATE teZCL_Status eZCL_CustomCommandReceiveScenes(
                    ZPS_tsAfEvent               *pZPSevent,
                    tsZCL_EndPointDefinition    *psEndPointDefinition,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsZCL_RxPayloadItem         *psPayloadDefinition,
                    uint16                       u16InitialOffsetinPayload)
{

    tsZCL_ClusterInstance *psZCL_ClusterInstance;
    uint16 u16ClusterIden;
    uint8 u8Len;

    int x;
    uint16 u16Offset;
    uint16 u16HeaderSize;
    uint16 u16PayloadSize;
    teZCL_ParseState eParseState;

    tsZCL_HeaderParams sZCL_HeaderParams;

    // parameter checks
    // input parameter checks
    if(
    #ifdef STRICT_PARAM_CHECK
           (pZPSevent == NULL)                                ||
           (psEndPointDefinition == NULL)                     ||
    #endif
       (psPayloadDefinition == NULL)                      ||
       (psPayloadDefinition->pu16ActualQuantity == NULL)   ||
       (psPayloadDefinition->pvDestination == NULL) )
    {
        return(E_ZCL_ERR_PARAMETER_NULL);
    }


    // parse command header
    u16HeaderSize =  u16ZCL_ReadCommandHeader(pZPSevent->uEvent.sApsDataIndEvent.hAPduInst,
                             &sZCL_HeaderParams);

    // get payload size
    u16PayloadSize = PDUM_u16APduInstanceGetPayloadSize(pZPSevent->uEvent.sApsDataIndEvent.hAPduInst);

    /* get offset just before the scene name length */
    u16Offset = u16HeaderSize + u16InitialOffsetinPayload;
    
    /* Add the offset of 1 byte for string name length */
    u16Offset += u16ZCL_APduInstanceReadNBO(pZPSevent->uEvent.sApsDataIndEvent.hAPduInst, u16Offset, E_ZCL_UINT8, &u8Len);
    
    /* Set offset to start of extension field set by adding the offset of scene name*/
    u16Offset += u8Len;

    u8Len = 0;
    
    eParseState=PARSE_CLUSTER_ID;
    /* For each item in the list */
    for(x = 0; (x < psPayloadDefinition->u16MaxQuantity) && (u16Offset < u16PayloadSize); )
    {
        switch(eParseState)
        {
            case PARSE_CLUSTER_ID :
                /*Read ClusterID*/
                u16Offset += u16ZCL_APduInstanceReadNBO(pZPSevent->uEvent.sApsDataIndEvent.hAPduInst, u16Offset, E_ZCL_UINT16, &u16ClusterIden);
                u16Offset += u16ZCL_APduInstanceReadNBO(pZPSevent->uEvent.sApsDataIndEvent.hAPduInst, u16Offset, E_ZCL_UINT8, &u8Len);
                /*is the length all right*/
                if((u16Offset+u8Len) > (u16PayloadSize) )
                {
                    return (E_ZCL_ERR_PARAMETER_NULL);
                }
                /*Serch for the cluster */
                /*if not found go to skip , else go to copy*/
                if(eZCL_SearchForClusterEntry(psEndPointDefinition->u8EndPointNumber, u16ClusterIden, TRUE, &psZCL_ClusterInstance) != E_ZCL_SUCCESS)
                {
                    eParseState=PARSER_SKIP;
                }
                else
                {
                    u16Offset -=3;
                    u8Len += 3;
                    eParseState=PARSER_COPY_TO_DESTINATION;
                }
                break;

            case PARSER_COPY_TO_DESTINATION :
                if(u8Len)
                {
                    u8Len--;
                    u16Offset += u16ZCL_APduInstanceReadNBO(pZPSevent->uEvent.sApsDataIndEvent.hAPduInst, u16Offset, E_ZCL_UINT8, ((uint8 *)((uint8 *)(psPayloadDefinition->pvDestination) + x++)));
                }
                else
                {
                    eParseState=PARSE_CLUSTER_ID;
                }
                break;
            case PARSER_SKIP :
                u16Offset = u16Offset+u8Len;
                eParseState=PARSE_CLUSTER_ID;
                break;
            default:
                break;
        }
        *psPayloadDefinition->pu16ActualQuantity = x;
    }
    return(E_ZCL_SUCCESS);
}


/****************************************************************************
 **
 ** NAME:       eCLD_ScenesCommandAddSceneResponseSend
 **
 ** DESCRIPTION:
 ** Builds and sends an add scene response cluster command
 **
 ** PARAMETERS:                 Name                           Usage
 ** uint8                       u8SourceEndPointId             Source EP Id
 ** uint8                       u8DestinationEndPointId        Destination EP Id
 ** tsZCL_Address              *psDestinationAddress           Destination Address
 ** uint8                      *pu8TransactionSequenceNumber   Sequence number Pointer
 ** tsCLD_ScenesAddSceneResponsePayload *psPayload             Payload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PRIVATE  teZCL_Status eCLD_ScenesCommandAddSceneResponseSend(
                                        uint8           u8SourceEndPointId,
                                        uint8           u8DestinationEndPointId,
                                        tsZCL_Address   *psDestinationAddress,
                                        uint8           *pu8TransactionSequenceNumber,
                                        tsCLD_ScenesAddSceneResponsePayload *psPayload)
{

    tsZCL_TxPayloadItem asPayloadDefinition[] = {
            {1,                                     E_ZCL_ENUM8,    &psPayload->eStatus},
            {1,                                     E_ZCL_UINT16,   &psPayload->u16GroupId},
            {1,                                     E_ZCL_UINT8,    &psPayload->u8SceneId},
                                              };

    return eZCL_CustomCommandSend(u8SourceEndPointId,
                                  u8DestinationEndPointId,
                                  psDestinationAddress,
                                  GENERAL_CLUSTER_ID_SCENES,
                                  TRUE,
                                  E_CLD_SCENES_CMD_ADD,
                                  pu8TransactionSequenceNumber,
                                  asPayloadDefinition,
                                  FALSE,
                                  0,
                                  sizeof(asPayloadDefinition) / sizeof(tsZCL_TxPayloadItem)
                                 );

}

#endif
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

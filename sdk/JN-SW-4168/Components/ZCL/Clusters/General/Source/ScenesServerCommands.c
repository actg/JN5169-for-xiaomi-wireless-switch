/*****************************************************************************
 *
 * MODULE:             Scenes Cluster
 *
 * COMPONENT:          ScenesServerCommands.c
 *
 * AUTHOR:             Lee Mitchell
 *
 * DESCRIPTION:        Send a Scenes cluster command
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/UnifiedZCL_ZLL102_HA122_Maintenance/Clusters/General/Source/ScenesServerCommands.c $
 *
 * $Revision: 76155 $
 *
 * $LastChangedBy: nxp57621 $
 *
 * $LastChangedDate: 2016-01-19 09:15:01 +0000 (Tue, 19 Jan 2016) $
 *
 * $Id: ScenesServerCommands.c 76155 2016-01-19 09:15:01Z nxp57621 $
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

#include "zcl.h"
#include "zcl_customcommand.h"

#include "Scenes.h"
#include "Scenes_internal.h"

#include "pdum_apl.h"
#include "zps_apl.h"
#include "zps_apl_af.h"



#include "dbg.h"

#ifdef DEBUG_CLD_SCENES
#define TRACE_SCENES    TRUE
#else
#define TRACE_SCENES    FALSE
#endif

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/

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
 ** NAME:       eCLD_ScenesCommandAddSceneResponseReceive
 **
 ** DESCRIPTION:
 ** handles rx of add scene response
 **
 ** PARAMETERS:               Name                          Usage
 ** ZPS_tsAfEvent              *pZPSevent                   Zigbee stack event structure
 ** tsZCL_EndPointDefinition *psEndPointDefinition          EP structure
 ** tsZCL_ClusterInstance    *psClusterInstance             Cluster structure
 ** uint8                    *pu8TransactionSequenceNumber  Sequence number Pointer
 ** tsCLD_ScenesAddSceneResponsePayload *psPayload          Payload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC  teZCL_Status eCLD_ScenesCommandAddSceneResponseReceive(
                    ZPS_tsAfEvent               *pZPSevent,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_ScenesAddSceneResponsePayload *psPayload)
{

    uint16 u16ActualQuantity;

    tsZCL_RxPayloadItem asPayloadDefinition[] = {
    {1,                                         &u16ActualQuantity,                     E_ZCL_ENUM8,    &psPayload->eStatus},
    {1,                                         &u16ActualQuantity,                     E_ZCL_UINT16,   &psPayload->u16GroupId},
    {1,                                         &u16ActualQuantity,                     E_ZCL_UINT8,    &psPayload->u8SceneId},
                                                };

    return eZCL_CustomCommandReceive(pZPSevent,
                                     pu8TransactionSequenceNumber,
                                     asPayloadDefinition,
                                     sizeof(asPayloadDefinition) / sizeof(tsZCL_RxPayloadItem),
                                     E_ZCL_ACCEPT_EXACT);

}


/****************************************************************************
 **
 ** NAME:       eCLD_ScenesCommandViewSceneResponseSend
 **
 ** DESCRIPTION:
 ** Builds and sends a view scene response cluster command
 **
 ** PARAMETERS:                 Name                           Usage
 ** uint8                       u8SourceEndPointId             Source EP Id
 ** uint8                       u8DestinationEndPointId        Destination EP Id
 ** tsZCL_Address              *psDestinationAddress           Destination Address
 ** uint8                      *pu8TransactionSequenceNumber   Sequence number Pointer
 ** tsCLD_ScenesViewSceneResponsePayload *psPayload            Payload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC  teZCL_Status eCLD_ScenesCommandViewSceneResponseSend(
                                        uint8           u8SourceEndPointId,
                                        uint8           u8DestinationEndPointId,
                                        tsZCL_Address   *psDestinationAddress,
                                        uint8           *pu8TransactionSequenceNumber,
                                        tsCLD_ScenesViewSceneResponsePayload *psPayload)
{

    uint8 u8ItemsInPayload;

    tsZCL_TxPayloadItem asPayloadDefinition[] = {
            {1,                                     E_ZCL_ENUM8,    &psPayload->eStatus},
            {1,                                     E_ZCL_UINT16,   &psPayload->u16GroupId},
            {1,                                     E_ZCL_UINT8,    &psPayload->u8SceneId},
            {1,                                     E_ZCL_UINT16,   &psPayload->u16TransitionTime},
            {1,                                     E_ZCL_CSTRING,  &psPayload->sSceneName},
            {psPayload->sExtensionField.u16Length,  E_ZCL_UINT8,    psPayload->sExtensionField.pu8Data},
                                              };

    /* We only respond with all fields if the result was success */
    if(psPayload->eStatus != E_CLD_SCENES_CMD_STATUS_SUCCESS)
    {
        u8ItemsInPayload = 3;
    }
    else
    {
        u8ItemsInPayload = sizeof(asPayloadDefinition) / sizeof(tsZCL_TxPayloadItem);
    }

    return eZCL_CustomCommandSend(u8SourceEndPointId,
                                  u8DestinationEndPointId,
                                  psDestinationAddress,
                                  GENERAL_CLUSTER_ID_SCENES,
                                  TRUE,
                                  E_CLD_SCENES_CMD_VIEW,
                                  pu8TransactionSequenceNumber,
                                  asPayloadDefinition,
                                  FALSE,
                                  0,
                                  u8ItemsInPayload
                                 );

}


/****************************************************************************
 **
 ** NAME:       eCLD_ScenesCommandViewSceneResponseReceive
 **
 ** DESCRIPTION:
 ** handles rx of view scene response
 **
 ** PARAMETERS:               Name                          Usage
 ** ZPS_tsAfEvent              *pZPSevent                   Zigbee stack event structure
 ** tsZCL_EndPointDefinition *psEndPointDefinition          EP structure
 ** tsZCL_ClusterInstance    *psClusterInstance             Cluster structure
 ** uint8                    *pu8TransactionSequenceNumber  Sequence number Pointer
 ** tsCLD_ScenesViewSceneResponsePayload *psPayload          Payload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC  teZCL_Status eCLD_ScenesCommandViewSceneResponseReceive(
                    ZPS_tsAfEvent               *pZPSevent,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_ScenesViewSceneResponsePayload *psPayload)
{

    uint16 u16ActualQuantity;

    tsZCL_RxPayloadItem asPayloadDefinition[] = {
    {1,                                         &u16ActualQuantity,                     E_ZCL_ENUM8,    &psPayload->eStatus},
    {1,                                         &u16ActualQuantity,                     E_ZCL_UINT16,   &psPayload->u16GroupId},
    {1,                                         &u16ActualQuantity,                     E_ZCL_UINT8,    &psPayload->u8SceneId},
    {1,                                         &u16ActualQuantity,                     E_ZCL_UINT16,   &psPayload->u16TransitionTime},
    {1,                                         &u16ActualQuantity,                     E_ZCL_CSTRING,  &psPayload->sSceneName},
    {CLD_SCENES_MAX_SCENE_STORAGE_BYTES,        &psPayload->sExtensionField.u16Length,  E_ZCL_UINT8,    psPayload->sExtensionField.pu8Data},
                                                };

    return eZCL_CustomCommandReceive(pZPSevent,
                                     pu8TransactionSequenceNumber,
                                     asPayloadDefinition,
                                     sizeof(asPayloadDefinition) / sizeof(tsZCL_RxPayloadItem),
                                     E_ZCL_ACCEPT_LESS);

}


/****************************************************************************
 **
 ** NAME:       eCLD_ScenesCommandRemoveSceneResponseSend
 **
 ** DESCRIPTION:
 ** Builds and sends a remove scene response cluster command
 **
 ** PARAMETERS:                 Name                           Usage
 ** uint8                       u8SourceEndPointId             Source EP Id
 ** uint8                       u8DestinationEndPointId        Destination EP Id
 ** tsZCL_Address              *psDestinationAddress           Destination Address
 ** uint8                      *pu8TransactionSequenceNumber   Sequence number Pointer
 ** tsCLD_ScenesRemoveSceneResponsePayload *psPayload             Payload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC  teZCL_Status eCLD_ScenesCommandRemoveSceneResponseSend(
                                        uint8           u8SourceEndPointId,
                                        uint8           u8DestinationEndPointId,
                                        tsZCL_Address   *psDestinationAddress,
                                        uint8           *pu8TransactionSequenceNumber,
                                        tsCLD_ScenesRemoveSceneResponsePayload *psPayload)
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
                                  E_CLD_SCENES_CMD_REMOVE,
                                  pu8TransactionSequenceNumber,
                                  asPayloadDefinition,
                                  FALSE,
                                  0,
                                  sizeof(asPayloadDefinition) / sizeof(tsZCL_TxPayloadItem)
                                 );

}


/****************************************************************************
 **
 ** NAME:       eCLD_ScenesCommandRemoveSceneResponseReceive
 **
 ** DESCRIPTION:
 ** handles rx of remove scene response
 **
 ** PARAMETERS:               Name                          Usage
 ** ZPS_tsAfEvent              *pZPSevent                   Zigbee stack event structure
 ** tsZCL_EndPointDefinition *psEndPointDefinition          EP structure
 ** tsZCL_ClusterInstance    *psClusterInstance             Cluster structure
 ** uint8                    *pu8TransactionSequenceNumber  Sequence number Pointer
 ** tsCLD_ScenesAddSceneResponsePayload *psPayload          Payload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC  teZCL_Status eCLD_ScenesCommandRemoveSceneResponseReceive(
                    ZPS_tsAfEvent               *pZPSevent,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_ScenesRemoveSceneResponsePayload *psPayload)
{

    uint16 u16ActualQuantity;

    tsZCL_RxPayloadItem asPayloadDefinition[] = {
    {1,                                         &u16ActualQuantity,                     E_ZCL_ENUM8,    &psPayload->eStatus},
    {1,                                         &u16ActualQuantity,                     E_ZCL_UINT16,   &psPayload->u16GroupId},
    {1,                                         &u16ActualQuantity,                     E_ZCL_UINT8,    &psPayload->u8SceneId},
                                                };

    return eZCL_CustomCommandReceive(pZPSevent,
                                     pu8TransactionSequenceNumber,
                                     asPayloadDefinition,
                                     sizeof(asPayloadDefinition) / sizeof(tsZCL_RxPayloadItem),
                                     E_ZCL_ACCEPT_EXACT);

}


/****************************************************************************
 **
 ** NAME:       eCLD_ScenesCommandRemoveAllScenesResponseSend
 **
 ** DESCRIPTION:
 ** Builds and sends a remove all scenes response cluster command
 **
 ** PARAMETERS:                 Name                           Usage
 ** uint8                       u8SourceEndPointId             Source EP Id
 ** uint8                       u8DestinationEndPointId        Destination EP Id
 ** tsZCL_Address              *psDestinationAddress           Destination Address
 ** uint8                      *pu8TransactionSequenceNumber   Sequence number Pointer
 ** tsCLD_ScenesRemoveAllScenesResponsePayload *psPayload             Payload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC  teZCL_Status eCLD_ScenesCommandRemoveAllScenesResponseSend(
                                        uint8           u8SourceEndPointId,
                                        uint8           u8DestinationEndPointId,
                                        tsZCL_Address   *psDestinationAddress,
                                        uint8           *pu8TransactionSequenceNumber,
                                        tsCLD_ScenesRemoveAllScenesResponsePayload *psPayload)
{

    tsZCL_TxPayloadItem asPayloadDefinition[] = {
            {1,                                     E_ZCL_ENUM8,    &psPayload->eStatus},
            {1,                                     E_ZCL_UINT16,   &psPayload->u16GroupId},
                                              };

    return eZCL_CustomCommandSend(u8SourceEndPointId,
                                  u8DestinationEndPointId,
                                  psDestinationAddress,
                                  GENERAL_CLUSTER_ID_SCENES,
                                  TRUE,
                                  E_CLD_SCENES_CMD_REMOVE_ALL,
                                  pu8TransactionSequenceNumber,
                                  asPayloadDefinition,
                                  FALSE,
                                  0,
                                  sizeof(asPayloadDefinition) / sizeof(tsZCL_TxPayloadItem)
                                 );

}


/****************************************************************************
 **
 ** NAME:       eCLD_ScenesCommandRemoveAllScenesResponseReceive
 **
 ** DESCRIPTION:
 ** handles rx of remove all scenes response
 **
 ** PARAMETERS:               Name                          Usage
 ** ZPS_tsAfEvent              *pZPSevent                   Zigbee stack event structure
 ** tsZCL_EndPointDefinition *psEndPointDefinition          EP structure
 ** tsZCL_ClusterInstance    *psClusterInstance             Cluster structure
 ** uint8                    *pu8TransactionSequenceNumber  Sequence number Pointer
 ** tsCLD_ScenesRemoveAllScenesResponsePayload *psPayload          Payload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC  teZCL_Status eCLD_ScenesCommandRemoveAllScenesResponseReceive(
                    ZPS_tsAfEvent               *pZPSevent,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_ScenesRemoveAllScenesResponsePayload *psPayload)
{

    uint16 u16ActualQuantity;

    tsZCL_RxPayloadItem asPayloadDefinition[] = {
    {1,                                         &u16ActualQuantity,                     E_ZCL_ENUM8,    &psPayload->eStatus},
    {1,                                         &u16ActualQuantity,                     E_ZCL_UINT16,   &psPayload->u16GroupId},
                                                };

    return eZCL_CustomCommandReceive(pZPSevent,
                                     pu8TransactionSequenceNumber,
                                     asPayloadDefinition,
                                     sizeof(asPayloadDefinition) / sizeof(tsZCL_RxPayloadItem),
                                     E_ZCL_ACCEPT_EXACT);

}


/****************************************************************************
 **
 ** NAME:       eCLD_ScenesCommandStoreSceneResponseSend
 **
 ** DESCRIPTION:
 ** Builds and sends a Store scene response cluster command
 **
 ** PARAMETERS:                 Name                           Usage
 ** uint8                       u8SourceEndPointId             Source EP Id
 ** uint8                       u8DestinationEndPointId        Destination EP Id
 ** tsZCL_Address              *psDestinationAddress           Destination Address
 ** uint8                      *pu8TransactionSequenceNumber   Sequence number Pointer
 ** tsCLD_ScenesStoreSceneResponsePayload *psPayload             Payload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC  teZCL_Status eCLD_ScenesCommandStoreSceneResponseSend(
                                        uint8           u8SourceEndPointId,
                                        uint8           u8DestinationEndPointId,
                                        tsZCL_Address   *psDestinationAddress,
                                        uint8           *pu8TransactionSequenceNumber,
                                        tsCLD_ScenesStoreSceneResponsePayload *psPayload)
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
                                  E_CLD_SCENES_CMD_STORE,
                                  pu8TransactionSequenceNumber,
                                  asPayloadDefinition,
                                  FALSE,
                                  0,
                                  sizeof(asPayloadDefinition) / sizeof(tsZCL_TxPayloadItem)
                                 );

}


/****************************************************************************
 **
 ** NAME:       eCLD_ScenesCommandStoreSceneResponseReceive
 **
 ** DESCRIPTION:
 ** handles rx of Store scene response
 **
 ** PARAMETERS:               Name                          Usage
 ** ZPS_tsAfEvent              *pZPSevent                   Zigbee stack event structure
 ** tsZCL_EndPointDefinition *psEndPointDefinition          EP structure
 ** tsZCL_ClusterInstance    *psClusterInstance             Cluster structure
 ** uint8                    *pu8TransactionSequenceNumber  Sequence number Pointer
 ** tsCLD_ScenesAddSceneResponsePayload *psPayload          Payload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC  teZCL_Status eCLD_ScenesCommandStoreSceneResponseReceive(
                    ZPS_tsAfEvent               *pZPSevent,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_ScenesStoreSceneResponsePayload *psPayload)
{

    uint16 u16ActualQuantity;

    tsZCL_RxPayloadItem asPayloadDefinition[] = {
    {1,                                         &u16ActualQuantity,                     E_ZCL_ENUM8,    &psPayload->eStatus},
    {1,                                         &u16ActualQuantity,                     E_ZCL_UINT16,   &psPayload->u16GroupId},
    {1,                                         &u16ActualQuantity,                     E_ZCL_UINT8,    &psPayload->u8SceneId},
                                                };

    return eZCL_CustomCommandReceive(pZPSevent,
                                     pu8TransactionSequenceNumber,
                                     asPayloadDefinition,
                                     sizeof(asPayloadDefinition) / sizeof(tsZCL_RxPayloadItem),
                                     E_ZCL_ACCEPT_EXACT);

}

/****************************************************************************
 **
 ** NAME:       eCLD_ScenesCommandGetSceneMembershipResponseSend
 **
 ** DESCRIPTION:
 ** Builds and sends a Get Scene Membership response cluster command
 **
 ** PARAMETERS:                 Name                           Usage
 ** uint8                       u8SourceEndPointId             Source EP Id
 ** uint8                       u8DestinationEndPointId        Destination EP Id
 ** tsZCL_Address              *psDestinationAddress           Destination Address
 ** uint8                      *pu8TransactionSequenceNumber   Sequence number Pointer
 ** tsCLD_ScenesGetSceneMembershipResponsePayload *psPayload             Payload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC  teZCL_Status eCLD_ScenesCommandGetSceneMembershipResponseSend(
                                        uint8           u8SourceEndPointId,
                                        uint8           u8DestinationEndPointId,
                                        tsZCL_Address   *psDestinationAddress,
                                        uint8           *pu8TransactionSequenceNumber,
                                        tsCLD_ScenesGetSceneMembershipResponsePayload *psPayload)
{

    uint8 u8ItemsInPayload;

    tsZCL_TxPayloadItem asPayloadDefinition[] = {
            {1,                                     E_ZCL_ENUM8,    &psPayload->eStatus},
            {1,                                     E_ZCL_UINT8,    &psPayload->u8Capacity},
            {1,                                     E_ZCL_UINT16,   &psPayload->u16GroupId},
            {1,                                     E_ZCL_UINT8,    &psPayload->u8SceneCount},
            {psPayload->u8SceneCount,               E_ZCL_UINT8,    psPayload->pu8SceneList}
                                              };

    /* We only respond with all fields if the result was success */
    if(psPayload->eStatus != E_CLD_SCENES_CMD_STATUS_SUCCESS)
    {
        u8ItemsInPayload = 3;
    }
    else
    {
        u8ItemsInPayload = sizeof(asPayloadDefinition) / sizeof(tsZCL_TxPayloadItem);
    }

    return eZCL_CustomCommandSend(u8SourceEndPointId,
                                  u8DestinationEndPointId,
                                  psDestinationAddress,
                                  GENERAL_CLUSTER_ID_SCENES,
                                  TRUE,
                                  E_CLD_SCENES_CMD_GET_SCENE_MEMBERSHIP,
                                  pu8TransactionSequenceNumber,
                                  asPayloadDefinition,
                                  FALSE,
                                  0,
                                  u8ItemsInPayload
                                 );

}


/****************************************************************************
 **
 ** NAME:       eCLD_ScenesCommandGetSceneMembershipResponseReceive
 **
 ** DESCRIPTION:
 ** handles rx of Get Scene Membership scene response
 **
 ** PARAMETERS:               Name                          Usage
 ** ZPS_tsAfEvent              *pZPSevent                   Zigbee stack event structure
 ** tsZCL_EndPointDefinition *psEndPointDefinition          EP structure
 ** tsZCL_ClusterInstance    *psClusterInstance             Cluster structure
 ** uint8                    *pu8TransactionSequenceNumber  Sequence number Pointer
 ** tsCLD_ScenesGetSceneMembershipResponsePayload *psPayload          Payload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC  teZCL_Status eCLD_ScenesCommandGetSceneMembershipResponseReceive(
                    ZPS_tsAfEvent               *pZPSevent,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_ScenesGetSceneMembershipResponsePayload *psPayload)
{

    uint16 u16ActualQuantity;

    tsZCL_RxPayloadItem asPayloadDefinition[] = {
    {1,                                 &u16ActualQuantity, E_ZCL_ENUM8,    &psPayload->eStatus},
    {1,                                 &u16ActualQuantity, E_ZCL_UINT8,    &psPayload->u8Capacity},
    {1,                                 &u16ActualQuantity, E_ZCL_UINT16,   &psPayload->u16GroupId},
    {1,                                 &u16ActualQuantity, E_ZCL_UINT8,    &psPayload->u8SceneCount},
    {CLD_SCENES_MAX_NUMBER_OF_SCENES,   &u16ActualQuantity, E_ZCL_UINT8,    psPayload->pu8SceneList},
                                                };

    return eZCL_CustomCommandReceive(pZPSevent,
                                     pu8TransactionSequenceNumber,
                                     asPayloadDefinition,
                                     sizeof(asPayloadDefinition) / sizeof(tsZCL_RxPayloadItem),
                                     E_ZCL_ACCEPT_LESS);

}

#ifdef  CLD_SCENES_SUPPORT_ZLL_ENHANCED_COMMANDS
/****************************************************************************
 **
 ** NAME:       eCLD_ScenesCommandEnhancedAddSceneResponseSend
 **
 ** DESCRIPTION:
 ** Builds and sends an Enhanced Add Scene response cluster command
 **
 ** PARAMETERS:                 Name                           Usage
 ** uint8                       u8SourceEndPointId             Source EP Id
 ** uint8                       u8DestinationEndPointId        Destination EP Id
 ** tsZCL_Address              *psDestinationAddress           Destination Address
 ** uint8                      *pu8TransactionSequenceNumber   Sequence number Pointer
 ** tsCLD_ScenesEnhancedAddSceneResponsePayload *psPayload     Payload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC  teZCL_Status eCLD_ScenesCommandEnhancedAddSceneResponseSend(
                                        uint8           u8SourceEndPointId,
                                        uint8           u8DestinationEndPointId,
                                        tsZCL_Address   *psDestinationAddress,
                                        uint8           *pu8TransactionSequenceNumber,
                                        tsCLD_ScenesEnhancedAddSceneResponsePayload *psPayload)
{

    tsZCL_TxPayloadItem asPayloadDefinition[] = {
            {1,      E_ZCL_ENUM8,    &psPayload->eStatus},
            {1,      E_ZCL_UINT16,   &psPayload->u16GroupId},
            {1,      E_ZCL_UINT8,    &psPayload->u8SceneId},
                                              };

    return eZCL_CustomCommandSend(u8SourceEndPointId,
                                  u8DestinationEndPointId,
                                  psDestinationAddress,
                                  GENERAL_CLUSTER_ID_SCENES,
                                  TRUE,
                                  E_CLD_SCENES_CMD_ENHANCED_ADD_SCENE,
                                  pu8TransactionSequenceNumber,
                                  asPayloadDefinition,
                                  FALSE,
                                  0,
                                  sizeof(asPayloadDefinition) / sizeof(tsZCL_TxPayloadItem)
                                 );
}


/****************************************************************************
 **
 ** NAME:       eCLD_ScenesCommandEnhancedAddSceneResponseReceive
 **
 ** DESCRIPTION:
 ** handles rx of Enhanced Add Scene response
 **
 ** PARAMETERS:               Name                          Usage
 ** ZPS_tsAfEvent              *pZPSevent                   Zigbee stack event structure
 ** tsZCL_EndPointDefinition *psEndPointDefinition          EP structure
 ** tsZCL_ClusterInstance    *psClusterInstance             Cluster structure
 ** uint8                    *pu8TransactionSequenceNumber  Sequence number Pointer
 ** tsCLD_ScenesEnhancedAddSceneResponsePayload *psPayload  Payload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC  teZCL_Status eCLD_ScenesCommandEnhancedAddSceneResponseReceive(
                    ZPS_tsAfEvent               *pZPSevent,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_ScenesEnhancedAddSceneResponsePayload *psPayload)
{

    uint16 u16ActualQuantity;

    tsZCL_RxPayloadItem asPayloadDefinition[] = {
    {1,                                 &u16ActualQuantity, E_ZCL_ENUM8,    &psPayload->eStatus},
    {1,                                 &u16ActualQuantity, E_ZCL_UINT16,   &psPayload->u16GroupId},
    {1,                                 &u16ActualQuantity, E_ZCL_UINT8,    &psPayload->u8SceneId},
                                                };

    return eZCL_CustomCommandReceive(pZPSevent,
                                     pu8TransactionSequenceNumber,
                                     asPayloadDefinition,
                                     sizeof(asPayloadDefinition) / sizeof(tsZCL_RxPayloadItem),
                                     E_ZCL_ACCEPT_EXACT);

}

/****************************************************************************
 **
 ** NAME:       eCLD_ScenesCommandEnhancedViewSceneResponseSend
 **
 ** DESCRIPTION:
 ** Builds and sends an Enhanced View Scene response cluster command
 **
 ** PARAMETERS:                 Name                           Usage
 ** uint8                       u8SourceEndPointId             Source EP Id
 ** uint8                       u8DestinationEndPointId        Destination EP Id
 ** tsZCL_Address              *psDestinationAddress           Destination Address
 ** uint8                      *pu8TransactionSequenceNumber   Sequence number Pointer
 ** tsCLD_ScenesEnhancedViewSceneResponsePayload *psPayload    Payload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC  teZCL_Status eCLD_ScenesCommandEnhancedViewSceneResponseSend(
                                        uint8           u8SourceEndPointId,
                                        uint8           u8DestinationEndPointId,
                                        tsZCL_Address   *psDestinationAddress,
                                        uint8           *pu8TransactionSequenceNumber,
                                        tsCLD_ScenesEnhancedViewSceneResponsePayload *psPayload)
{

    tsZCL_TxPayloadItem asPayloadDefinition[] = {
            {1,      E_ZCL_ENUM8,    &psPayload->eStatus},
            {1,      E_ZCL_UINT16,   &psPayload->u16GroupId},
            {1,      E_ZCL_UINT8,    &psPayload->u8SceneId},
            {1,      E_ZCL_UINT16,   &psPayload->u16TransitionTime},
            {1,      E_ZCL_CSTRING,  &psPayload->sSceneName},
            {psPayload->sExtensionField.u16Length,  E_ZCL_UINT8,    psPayload->sExtensionField.pu8Data},
                                              };

    return eZCL_CustomCommandSend(u8SourceEndPointId,
                                  u8DestinationEndPointId,
                                  psDestinationAddress,
                                  GENERAL_CLUSTER_ID_SCENES,
                                  TRUE,
                                  E_CLD_SCENES_CMD_ENHANCED_VIEW_SCENE,
                                  pu8TransactionSequenceNumber,
                                  asPayloadDefinition,
                                  FALSE,
                                  0,
                                  sizeof(asPayloadDefinition) / sizeof(tsZCL_TxPayloadItem)
                                 );

}

/****************************************************************************
 **
 ** NAME:       eCLD_ScenesCommandEnhancedViewSceneResponseReceive
 **
 ** DESCRIPTION:
 ** handles rx of Enhanced View Scene response
 **
 ** PARAMETERS:               Name                          Usage
 ** ZPS_tsAfEvent              *pZPSevent                   Zigbee stack event structure
 ** tsZCL_EndPointDefinition *psEndPointDefinition          EP structure
 ** tsZCL_ClusterInstance    *psClusterInstance             Cluster structure
 ** uint8                    *pu8TransactionSequenceNumber  Sequence number Pointer
 ** tsCLD_ScenesEnhancedViewSceneResponsePayload *psPayload Payload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC  teZCL_Status eCLD_ScenesCommandEnhancedViewSceneResponseReceive(
                    ZPS_tsAfEvent               *pZPSevent,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_ScenesEnhancedViewSceneResponsePayload *psPayload)
{

    uint16 u16ActualQuantity;

    tsZCL_RxPayloadItem asPayloadDefinition[] = {
    {1,                                 &u16ActualQuantity, E_ZCL_ENUM8,    &psPayload->eStatus},
    {1,                                 &u16ActualQuantity, E_ZCL_UINT16,   &psPayload->u16GroupId},
    {1,                                 &u16ActualQuantity, E_ZCL_UINT16,   &psPayload->u16TransitionTime},
    {1,                                 &u16ActualQuantity, E_ZCL_CSTRING,  &psPayload->sSceneName},
    {CLD_SCENES_MAX_SCENE_STORAGE_BYTES,&psPayload->sExtensionField.u16Length,  E_ZCL_UINT8,    psPayload->sExtensionField.pu8Data},
                                                };

    return eZCL_CustomCommandReceive(pZPSevent,
                                     pu8TransactionSequenceNumber,
                                     asPayloadDefinition,
                                     sizeof(asPayloadDefinition) / sizeof(tsZCL_RxPayloadItem),
                                     E_ZCL_ACCEPT_EXACT);

}


/****************************************************************************
 **
 ** NAME:       eCLD_ScenesCommandCopySceneResponseSend
 **
 ** DESCRIPTION:
 ** Builds and sends a Copy Scene response cluster command
 **
 ** PARAMETERS:                 Name                           Usage
 ** uint8                       u8SourceEndPointId             Source EP Id
 ** uint8                       u8DestinationEndPointId        Destination EP Id
 ** tsZCL_Address              *psDestinationAddress           Destination Address
 ** uint8                      *pu8TransactionSequenceNumber   Sequence number Pointer
 ** tsCLD_ScenesCopySceneResponsePayload *psPayload            Payload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC  teZCL_Status eCLD_ScenesCommandCopySceneResponseSend(
                                        uint8           u8SourceEndPointId,
                                        uint8           u8DestinationEndPointId,
                                        tsZCL_Address   *psDestinationAddress,
                                        uint8           *pu8TransactionSequenceNumber,
                                        tsCLD_ScenesCopySceneResponsePayload *psPayload)
{

    tsZCL_TxPayloadItem asPayloadDefinition[] = {
            {1,      E_ZCL_UINT8,    &psPayload->u8Status},
            {1,      E_ZCL_UINT16,   &psPayload->u16FromGroupId},
            {1,      E_ZCL_UINT8,    &psPayload->u8FromSceneId},
                                              };

    return eZCL_CustomCommandSend(u8SourceEndPointId,
                                  u8DestinationEndPointId,
                                  psDestinationAddress,
                                  GENERAL_CLUSTER_ID_SCENES,
                                  TRUE,
                                  E_CLD_SCENES_CMD_COPY_SCENE,
                                  pu8TransactionSequenceNumber,
                                  asPayloadDefinition,
                                  FALSE,
                                  0,
                                  sizeof(asPayloadDefinition) / sizeof(tsZCL_TxPayloadItem)
                                 );
}


/****************************************************************************
 **
 ** NAME:       eCLD_ScenesCommandCopySceneResponseReceive
 **
 ** DESCRIPTION:
 ** handles rx of Copy Scene scene response
 **
 ** PARAMETERS:               Name                          Usage
 ** ZPS_tsAfEvent              *pZPSevent                   Zigbee stack event structure
 ** tsZCL_EndPointDefinition *psEndPointDefinition          EP structure
 ** tsZCL_ClusterInstance    *psClusterInstance             Cluster structure
 ** uint8                    *pu8TransactionSequenceNumber  Sequence number Pointer
 ** tsCLD_ScenesCopySceneResponsePayload *psPayload         Payload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC  teZCL_Status eCLD_ScenesCommandCopySceneResponseReceive(
                    ZPS_tsAfEvent               *pZPSevent,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_ScenesCopySceneResponsePayload *psPayload)
{

    uint16 u16ActualQuantity;

    tsZCL_RxPayloadItem asPayloadDefinition[] = {
    {1,                                 &u16ActualQuantity, E_ZCL_UINT8,    &psPayload->u8Status},
    {1,                                 &u16ActualQuantity, E_ZCL_UINT16,   &psPayload->u16FromGroupId},
    {1,                                 &u16ActualQuantity, E_ZCL_UINT8,    &psPayload->u8FromSceneId},
                                                };

    return eZCL_CustomCommandReceive(pZPSevent,
                                     pu8TransactionSequenceNumber,
                                     asPayloadDefinition,
                                     sizeof(asPayloadDefinition) / sizeof(tsZCL_RxPayloadItem),
                                     E_ZCL_ACCEPT_EXACT);

}

#endif
/****************************************************************************/
/***        Private Functions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

/*****************************************************************************
 *
 * MODULE:             Scenes Cluster
 *
 * COMPONENT:          Scenes_internal.h
 *
 * AUTHOR:             Lee Mitchell
 *
 * DESCRIPTION:        The internal API for the Scenes Cluster
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/UnifiedZCL_ZLL102_HA122_Maintenance/Clusters/General/Source/Scenes_internal.h $
 *
 * $Revision: 87492 $
 *
 * $LastChangedBy: nxp29772 $
 *
 * $LastChangedDate: 2017-03-24 08:39:29 +0000 (Fri, 24 Mar 2017) $
 *
 * $Id: Scenes_internal.h 87492 2017-03-24 08:39:29Z nxp29772 $
 *
 *****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products  [NXP Microcontrollers such as JN5168, JN5164,
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

#ifndef  SCENES_INTERNAL_H_INCLUDED
#define  SCENES_INTERNAL_H_INCLUDED

#if defined __cplusplus
extern "C" {
#endif

/****************************************************************************/
/***        Include Files                                                 ***/
/****************************************************************************/

#include "jendefs.h"

#include "zcl.h"
#include "Scenes.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC void vCLD_ScenesGenerateIndividualAttributeCallback(
                    tsZCL_EndPointDefinition    *psEndPointDefinition,
                    tsZCL_ClusterInstance       *psClusterInstance,
                    uint16 u16AttributeId);

PUBLIC teZCL_Status eCLD_ScenesCommandHandler(
                    ZPS_tsAfEvent               *pZPSevent,
                    tsZCL_EndPointDefinition    *psEndPointDefinition,
                    tsZCL_ClusterInstance       *psClusterInstance);

PUBLIC teZCL_Status eCLD_ScenesCommandAddSceneRequestSend(
                    uint8           u8SourceEndPointId,
                    uint8           u8DestinationEndPointId,
                    tsZCL_Address   *psDestinationAddress,
                    uint8           *pu8TransactionSequenceNumber,
                    tsCLD_ScenesAddSceneRequestPayload *psPayload);




PUBLIC teZCL_Status eCLD_ScenesCommandAddSceneResponseReceive(
                    ZPS_tsAfEvent               *pZPSevent,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_ScenesAddSceneResponsePayload *psPayload);

PUBLIC teZCL_Status eCLD_ScenesCommandViewSceneResponseSend(
                    uint8           u8SourceEndPointId,
                    uint8           u8DestinationEndPointId,
                    tsZCL_Address   *psDestinationAddress,
                    uint8           *pu8TransactionSequenceNumber,
                    tsCLD_ScenesViewSceneResponsePayload *psPayload);

PUBLIC teZCL_Status eCLD_ScenesCommandViewSceneResponseReceive(
                    ZPS_tsAfEvent               *pZPSevent,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_ScenesViewSceneResponsePayload *psPayload);

PUBLIC teZCL_Status eCLD_ScenesCommandRemoveSceneResponseSend(
                    uint8           u8SourceEndPointId,
                    uint8           u8DestinationEndPointId,
                    tsZCL_Address   *psDestinationAddress,
                    uint8           *pu8TransactionSequenceNumber,
                    tsCLD_ScenesRemoveSceneResponsePayload *psPayload);

PUBLIC teZCL_Status eCLD_ScenesCommandRemoveAllScenesResponseSend(
                    uint8           u8SourceEndPointId,
                    uint8           u8DestinationEndPointId,
                    tsZCL_Address   *psDestinationAddress,
                    uint8           *pu8TransactionSequenceNumber,
                    tsCLD_ScenesRemoveAllScenesResponsePayload *psPayload);


PUBLIC teZCL_Status eCLD_ScenesCommandStoreSceneResponseSend(
                    uint8           u8SourceEndPointId,
                    uint8           u8DestinationEndPointId,
                    tsZCL_Address   *psDestinationAddress,
                    uint8           *pu8TransactionSequenceNumber,
                    tsCLD_ScenesStoreSceneResponsePayload *psPayload);

PUBLIC teZCL_Status eCLD_ScenesCommandGetSceneMembershipResponseSend(
                    uint8           u8SourceEndPointId,
                    uint8           u8DestinationEndPointId,
                    tsZCL_Address   *psDestinationAddress,
                    uint8           *pu8TransactionSequenceNumber,
                    tsCLD_ScenesGetSceneMembershipResponsePayload *psPayload);


#ifdef  CLD_SCENES_SUPPORT_ZLL_ENHANCED_COMMANDS
PUBLIC teZCL_Status eCLD_ScenesCommandEnhancedAddSceneRequestSend(
                    uint8           u8SourceEndPointId,
                    uint8           u8DestinationEndPointId,
                    tsZCL_Address   *psDestinationAddress,
                    uint8           *pu8TransactionSequenceNumber,
                    tsCLD_ScenesEnhancedAddSceneRequestPayload *psPayload);


PUBLIC teZCL_Status eCLD_ScenesCommandEnhancedAddSceneResponseSend(
                    uint8           u8SourceEndPointId,
                    uint8           u8DestinationEndPointId,
                    tsZCL_Address   *psDestinationAddress,
                    uint8           *pu8TransactionSequenceNumber,
                    tsCLD_ScenesEnhancedAddSceneResponsePayload *psPayload);

PUBLIC teZCL_Status eCLD_ScenesCommandEnhancedViewSceneRequestSend(
                    uint8           u8SourceEndPointId,
                    uint8           u8DestinationEndPointId,
                    tsZCL_Address   *psDestinationAddress,
                    uint8           *pu8TransactionSequenceNumber,
                    tsCLD_ScenesEnhancedViewSceneRequestPayload *psPayload);

PUBLIC teZCL_Status eCLD_ScenesCommandEnhancedViewSceneResponseSend(
                    uint8           u8SourceEndPointId,
                    uint8           u8DestinationEndPointId,
                    tsZCL_Address   *psDestinationAddress,
                    uint8           *pu8TransactionSequenceNumber,
                    tsCLD_ScenesEnhancedViewSceneResponsePayload *psPayload);


PUBLIC teZCL_Status eCLD_ScenesCommandCopySceneSceneRequestSend(
                    uint8           u8SourceEndPointId,
                    uint8           u8DestinationEndPointId,
                    tsZCL_Address   *psDestinationAddress,
                    uint8           *pu8TransactionSequenceNumber,
                    tsCLD_ScenesCopySceneRequestPayload *psPayload);


PUBLIC teZCL_Status eCLD_ScenesCommandCopySceneResponseSend(
                    uint8           u8SourceEndPointId,
                    uint8           u8DestinationEndPointId,
                    tsZCL_Address   *psDestinationAddress,
                    uint8           *pu8TransactionSequenceNumber,
                    tsCLD_ScenesCopySceneResponsePayload *psPayload);

#endif

PUBLIC teZCL_Status eCLD_ScenesAddScene(
                    tsZCL_EndPointDefinition    *psEndPointDefinition,
                    tsZCL_ClusterInstance       *psClusterInstance,
                    tsCLD_ScenesAddSceneRequestPayload *psPayload,
                    bool_t                      bEnhanced);

PUBLIC teZCL_Status eCLD_ScenesStoreScene(
                    tsZCL_EndPointDefinition    *psEndPointDefinition,
                    tsZCL_ClusterInstance       *psClusterInstance,
                    uint16                      u16GroupId,
                    uint8                       u8SceneId,
                    tsCLD_ScenesTableEntry      **ppsTableEntry);

PUBLIC teZCL_Status eCLD_ScenesFindScene(
                    tsZCL_EndPointDefinition    *psEndPointDefinition,
                    tsZCL_ClusterInstance       *psClusterInstance,
                    uint16                      u16GroupId,
                    uint8                       u8SceneId,
                    tsCLD_ScenesTableEntry      **ppsTableEntry);

PUBLIC teZCL_Status eCLD_ScenesFindActiveScene(
                    tsZCL_EndPointDefinition    *psEndPointDefinition,
                    tsZCL_ClusterInstance       *psClusterInstance,
                    tsCLD_ScenesTableEntry      **ppsTableEntry);

PUBLIC teZCL_Status eCLD_ScenesListScenes(
                    tsZCL_EndPointDefinition    *psEndPointDefinition,
                    tsZCL_ClusterInstance       *psClusterInstance,
                    uint16                      u16GroupId,
                    uint8                       *pu8NumberOfScenes,
                    uint8                       *pau8ListOfScenes);

PUBLIC teZCL_Status eCLD_ScenesCountScenes(
                    tsZCL_EndPointDefinition    *psEndPointDefinition,
                    tsZCL_ClusterInstance       *psClusterInstance,
                    uint8                       *pu8NumberOfScenes);

PUBLIC teZCL_Status eCLD_ScenesRemoveScene(
                    tsZCL_EndPointDefinition    *psEndPointDefinition,
                    tsZCL_ClusterInstance       *psClusterInstance,
                    tsCLD_ScenesRemoveSceneRequestPayload *psPayload);

PUBLIC teZCL_Status eCLD_ScenesRemoveAllScenes(
                    uint8                        u8SourceEndPointId,
                    uint16                       u16GroupId,
                    uint64                       u64LastConfiguredBy);

#ifdef  CLD_SCENES_SUPPORT_ZLL_ENHANCED_COMMANDS
PUBLIC teZCL_Status eCLD_ScenesCopyScene(
                    tsZCL_EndPointDefinition    *psEndPointDefinition,
                    tsZCL_ClusterInstance       *psClusterInstance,
                    uint16                      u16FromGroupId,
                    uint8                       u8FromSceneId,
                    uint16                      u16ToGroupId,
                    uint8                       u8ToSceneId);

PUBLIC teZCL_Status eCLD_ScenesCopyAllScenes(
                    tsZCL_EndPointDefinition    *psEndPointDefinition,
                    tsZCL_ClusterInstance       *psClusterInstance,
                    uint16                      u16FromGroupId,
                    uint16                      u16ToGroupId);
#endif

PUBLIC teZCL_Status eCLD_ScenesSaveClusters(
                    tsZCL_EndPointDefinition *psEndPointDefinition,
                    uint16 u16MaxLength,
                    uint16 *pu16Length,
                    uint8 *pu8Buffer,
                    bool_t bIsTemporary );

PUBLIC teZCL_Status eCLD_ScenesRestoreClusters(
                    tsZCL_EndPointDefinition *psEndPointDefinition,
                    uint16 u16Length,
                    uint8 *pu8Buffer,
                    uint32 u32RemainingTime);

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

#if defined __cplusplus
}
#endif

#endif  /* SCENES_INTERNAL_H_INCLUDED */

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

/*****************************************************************************
 *
 * MODULE:             Identify Cluster
 *
 * COMPONENT:          IdentifyClientCommands.h
 *
 * AUTHOR:             Lee Mitchell
 *
 * DESCRIPTION:        Send an Identify cluster command
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/UnifiedZCL_ZLL102_HA122_Maintenance/Clusters/General/Source/IdentifyClientCommands.c $
 *
 * $Revision: 65575 $
 *
 * $LastChangedBy: nxp57621 $
 *
 * $LastChangedDate: 2014-11-14 11:35:30 +0000 (Fri, 14 Nov 2014) $
 *
 * $Id: IdentifyClientCommands.c 65575 2014-11-14 11:35:30Z nxp57621 $
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

#include "zcl.h"
#include "zcl_customcommand.h"

#include "Identify.h"
#include "Identify_internal.h"

#include "pdum_apl.h"
#include "zps_apl.h"
#include "zps_apl_af.h"

#include "dbg.h"

#ifdef DEBUG_CLD_IDENTIFY
#define TRACE_IDENTIFY    TRUE
#else
#define TRACE_IDENTIFY    FALSE
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
 ** NAME:       eCLD_IdentifyCommandIdentifyRequestSend
 **
 ** DESCRIPTION:
 ** Builds and sends an identify cluster command
 **
 ** PARAMETERS:                 Name                           Usage
 ** uint8                       u8SourceEndPointId             Source EP Id
 ** uint8                       u8DestinationEndPointId        Destination EP Id
 ** tsZCL_Address              *psDestinationAddress           Destination Address
 ** uint8                      *pu8TransactionSequenceNumber   Sequence number Pointer
 ** tsCLD_Identify_IdentifyRequestPayload *psPayload           Payload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC  teZCL_Status eCLD_IdentifyCommandIdentifyRequestSend(
                                        uint8              u8SourceEndPointId,
                                        uint8           u8DestinationEndPointId,
                                        tsZCL_Address   *psDestinationAddress,
                                        uint8           *pu8TransactionSequenceNumber,
                                        tsCLD_Identify_IdentifyRequestPayload *psPayload)
{

    tsZCL_TxPayloadItem asPayloadDefinition[] = {
            {1,                         E_ZCL_UINT16,   &psPayload->u16IdentifyTime},
                                              };

    return eZCL_CustomCommandSend(u8SourceEndPointId,
                                  u8DestinationEndPointId,
                                  psDestinationAddress,
                                  GENERAL_CLUSTER_ID_IDENTIFY,
                                  FALSE,
                                  E_CLD_IDENTIFY_CMD_IDENTIFY,
                                  pu8TransactionSequenceNumber,
                                  asPayloadDefinition,
                                  FALSE,
                                  0,
                                  sizeof(asPayloadDefinition) / sizeof(tsZCL_TxPayloadItem));

}


/****************************************************************************
 **
 ** NAME:       eCLD_IdentifyCommandIdentifyRequestReceive
 **
 ** DESCRIPTION:
 ** handles rx of identify request
 **
 ** PARAMETERS:               Name                          Usage
 ** ZPS_tsAfEvent              *pZPSevent                   Zigbee stack event structure
 ** tsZCL_EndPointDefinition *psEndPointDefinition          EP structure
 ** tsZCL_ClusterInstance    *psClusterInstance             Cluster structure
 ** uint8                    *pu8TransactionSequenceNumber  Sequence number Pointer
 ** tsCLD_Groups_AddGroupRequestPayload *psPayload          Payload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC  teZCL_Status eCLD_IdentifyCommandIdentifyRequestReceive(
                    ZPS_tsAfEvent               *pZPSevent,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_Identify_IdentifyRequestPayload *psPayload)
{

    uint16 u16ActualQuantity;

    tsZCL_RxPayloadItem asPayloadDefinition[] = {
    {1, &u16ActualQuantity, E_ZCL_UINT16,   &psPayload->u16IdentifyTime},
                                                };

    return eZCL_CustomCommandReceive(pZPSevent,
                                     pu8TransactionSequenceNumber,
                                     asPayloadDefinition,
                                     sizeof(asPayloadDefinition) / sizeof(tsZCL_RxPayloadItem),
                                     E_ZCL_ACCEPT_EXACT);

}


/****************************************************************************
 **
 ** NAME:       eCLD_IdentifyCommandIdentifyQueryRequestSend
 **
 ** DESCRIPTION:
 ** Builds and sends an identify cluster command
 **
 ** PARAMETERS:                 Name                           Usage
 ** uint8                       u8SourceEndPointId             Source EP Id
 ** uint8                       u8DestinationEndPointId        Destination EP Id
 ** tsZCL_Address              *psDestinationAddress           Destination Address
 ** uint8                      *pu8TransactionSequenceNumber   Sequence number Pointer
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC  teZCL_Status eCLD_IdentifyCommandIdentifyQueryRequestSend(
                                        uint8           u8SourceEndPointId,
                                        uint8           u8DestinationEndPointId,
                                        tsZCL_Address   *psDestinationAddress,
                                        uint8           *pu8TransactionSequenceNumber)
{

    return eZCL_CustomCommandSend(u8SourceEndPointId,
                                  u8DestinationEndPointId,
                                  psDestinationAddress,
                                  GENERAL_CLUSTER_ID_IDENTIFY,
                                  FALSE,
                                  E_CLD_IDENTIFY_CMD_IDENTIFY_QUERY,
                                  pu8TransactionSequenceNumber,
                                  0,
                                  FALSE,
                                  0,
                                  0);

}


/****************************************************************************
 **
 ** NAME:       eCLD_IdentifyCommandIdentifyQueryRequestReceive
 **
 ** DESCRIPTION:
 ** handles rx of identify request
 **
 ** PARAMETERS:               Name                          Usage
 ** ZPS_tsAfEvent              *pZPSevent                   Zigbee stack event structure
 ** tsZCL_EndPointDefinition *psEndPointDefinition          EP structure
 ** tsZCL_ClusterInstance    *psClusterInstance             Cluster structure
 ** uint8                    *pu8TransactionSequenceNumber  Sequence number Pointer
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC  teZCL_Status eCLD_IdentifyCommandIdentifyQueryRequestReceive(
                    ZPS_tsAfEvent               *pZPSevent,
                    uint8                       *pu8TransactionSequenceNumber)
{
/* ZLL test event 24/02/12
 * Only send default reponse on error
 * further default response processing occurs after the
 * command has been processed
 *
 *
 */

    return eZCL_CustomCommandReceive(pZPSevent,
                                     pu8TransactionSequenceNumber,
                                     0,
                                     0,
                                     E_ZCL_ACCEPT_EXACT|E_ZCL_DISABLE_DEFAULT_RESPONSE);

}

#ifdef CLD_IDENTIFY_ATTR_COMMISSION_STATE
/****************************************************************************
 **
 ** NAME:       eCLD_IdentifyUpdateCommissionStateCommandSend
 **
 ** DESCRIPTION:
 ** Builds and sends an identify cluster command
 **
 ** PARAMETERS:                                 Name                           Usage
 ** uint8                                       u8SourceEndPointId              Source EP Id
 ** uint8                                       u8DestinationEndPointId         Destination EP Id
 ** tsZCL_Address                               *psDestinationAddress           Destination Address
 ** uint8                                       *pu8TransactionSequenceNumber   Sequence number Pointer
 ** tsCLD_Identify_UpdateCommissionStatePayload *psPayload                      Payload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC  teZCL_Status eCLD_IdentifyUpdateCommissionStateCommandSend(
                                        uint8                                       u8SourceEndPointId,
                                        uint8                                       u8DestinationEndPointId,
                                        tsZCL_Address                               *psDestinationAddress,
                                        uint8                                       *pu8TransactionSequenceNumber,
                                        tsCLD_Identify_UpdateCommissionStatePayload *psPayload)
{

    tsZCL_TxPayloadItem asPayloadDefinition[] = {
            {1,                         E_ZCL_ENUM8,                &psPayload->u8Action},
            {1,                         E_ZCL_BMAP8,   &psPayload->u8CommissionStateMask},
                                              };

    return eZCL_CustomCommandSend(u8SourceEndPointId,
                                  u8DestinationEndPointId,
                                  psDestinationAddress,
                                  GENERAL_CLUSTER_ID_IDENTIFY,
                                  FALSE,
                                  E_CLD_IDENTIFY_CMD_UPDATE_COMMISSION_STATE,
                                  pu8TransactionSequenceNumber,
                                  asPayloadDefinition,
                                  FALSE,
                                  0,
                                  sizeof(asPayloadDefinition) / sizeof(tsZCL_TxPayloadItem));

}
#endif


#ifdef  CLD_IDENTIFY_SUPPORT_ZLL_ENHANCED_COMMANDS
/****************************************************************************
 **
 ** NAME:       eCLD_IdentifyCommandIdentifyTriggerEffectSend
 **
 ** DESCRIPTION:
 ** Builds and sends an identify cluster command
 **
 ** PARAMETERS:                 Name                           Usage
 ** uint8                       u8SourceEndPointId             Source EP Id
 ** uint8                       u8DestinationEndPointId        Destination EP Id
 ** tsZCL_Address              *psDestinationAddress           Destination Address
 ** uint8                      *pu8TransactionSequenceNumber   Sequence number Pointer
 ** uint8                      u8effectId
 ** uint8                      u8EffectVarient
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC  teZCL_Status eCLD_IdentifyCommandTriggerEffectSend(
                uint8           u8SourceEndPointId,
                uint8           u8DestinationEndPointId,
                tsZCL_Address   *psDestinationAddress,
                uint8           *pu8TransactionSequenceNumber,
                uint8           u8EffectId,
                uint8           u8EffectVarient)
{

    tsZCL_TxPayloadItem asPayloadDefinition[] = {
            {1,  E_ZCL_UINT8,   &u8EffectId},
            {1,  E_ZCL_UINT8,   &u8EffectVarient},
                                              };

    return eZCL_CustomCommandSend(u8SourceEndPointId,
                                  u8DestinationEndPointId,
                                  psDestinationAddress,
                                  GENERAL_CLUSTER_ID_IDENTIFY,
                                  FALSE,
                                  E_CLD_IDENTIFY_CMD_TRIGGER_EFFECT,
                                  pu8TransactionSequenceNumber,
                                  asPayloadDefinition,
                                  FALSE,
                                  0,
                                  sizeof(asPayloadDefinition) / sizeof(tsZCL_TxPayloadItem));
}
#endif

/****************************************************************************/
/***        Private Functions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

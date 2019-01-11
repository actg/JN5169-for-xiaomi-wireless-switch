/*****************************************************************************
 *
 * MODULE:             On/Off Cluster
 *
 * COMPONENT:          OnOffCommands.h
 *
 * AUTHOR:             Lee Mitchell
 *
 * DESCRIPTION:        Send an on/off cluster command
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/UnifiedZCL_ZLL102_HA122_Maintenance/Clusters/General/Source/OnOffCommands.c $
 *
 * $Revision: 65741 $
 *
 * $LastChangedBy: nxp57621 $
 *
 * $LastChangedDate: 2014-11-19 07:04:45 +0000 (Wed, 19 Nov 2014) $
 *
 * $Id: OnOffCommands.c 65741 2014-11-19 07:04:45Z nxp57621 $
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

#include "OnOff.h"
#include "OnOff_internal.h"

#include "pdum_apl.h"
#include "zps_apl.h"
#include "zps_apl_af.h"

#include "dbg.h"
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
 ** NAME:       eCLD_OnOffCommandSend
 **
 ** DESCRIPTION:
 ** Builds and sends an on/off cluster command
 **
 ** PARAMETERS:                 Name                           Usage
 ** uint8                       u8SourceEndPointId             Source EP Id
 ** uint8                       u8DestinationEndPointId        Destination EP Id
 ** tsZCL_Address              *psDestinationAddress           Destination Address
 ** uint8                      *pu8TransactionSequenceNumber   Sequence number Pointer
 ** teCLD_OnOff_Command         eCommand                       Message type
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC  teZCL_Status eCLD_OnOffCommandSend(
                                        uint8              u8SourceEndPointId,
                                        uint8           u8DestinationEndPointId,
                                        tsZCL_Address   *psDestinationAddress,
                                        uint8           *pu8TransactionSequenceNumber,
                                        teCLD_OnOff_Command   eCommand)
{

    return eZCL_CustomCommandSend(u8SourceEndPointId,
                                  u8DestinationEndPointId,
                                  psDestinationAddress,
                                  GENERAL_CLUSTER_ID_ONOFF,
                                  FALSE,
                                  (uint8)eCommand,
                                  pu8TransactionSequenceNumber,
                                  0,
                                  FALSE,
                                  0,
                                  0
                                 );

}


/****************************************************************************
 **
 ** NAME:       eCLD_OnOffCommandReceive
 **
 ** DESCRIPTION:
 ** handles rx of an On/Off command
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
PUBLIC  teZCL_Status eCLD_OnOffCommandReceive(
                    ZPS_tsAfEvent               *pZPSevent,
                    uint8                       *pu8TransactionSequenceNumber)
{

    return eZCL_CustomCommandReceive(pZPSevent,
                                     pu8TransactionSequenceNumber,
                                     0,
                                     0,
                                     E_ZCL_ACCEPT_EXACT);

}

#ifdef  CLD_ONOFF_SUPPORT_ZLL_ENHANCED_COMMANDS
/****************************************************************************
 **
 ** NAME:       eCLD_OnOffCommandOffWithEffectSend
 **
 ** DESCRIPTION:
 ** Builds and sends an off with effect On/Off cluster command
 **
 ** PARAMETERS:                 Name                           Usage
 ** uint8                       u8SourceEndPointId             Source EP Id
 ** uint8                       u8DestinationEndPointId        Destination EP Id
 ** tsZCL_Address              *psDestinationAddress           Destination Address
 ** uint8                      *pu8TransactionSequenceNumber   Sequence number Pointer
 ** tsCLD_OnOff_OffEffectRequestPayload *psPayload             Message payload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC teZCL_Status eCLD_OnOffCommandOffWithEffectSend(
                uint8           u8SourceEndPointId,
                uint8           u8DestinationEndPointId,
                tsZCL_Address   *psDestinationAddress,
                uint8           *pu8TransactionSequenceNumber,
                tsCLD_OnOff_OffWithEffectRequestPayload *psPayload)
{

    tsZCL_TxPayloadItem asPayloadDefinition[] = {
                {1,      E_ZCL_UINT8,   &psPayload->u8EffectId},
                {1,      E_ZCL_UINT8,   &psPayload->u8EffectVariant},
                                                 };

        return eZCL_CustomCommandSend(u8SourceEndPointId,
                                      u8DestinationEndPointId,
                                      psDestinationAddress,
                                      GENERAL_CLUSTER_ID_ONOFF,
                                      FALSE,
                                      E_CLD_ONOFF_CMD_OFF_EFFECT,
                                      pu8TransactionSequenceNumber,
                                      asPayloadDefinition,
                                      FALSE,
                                      0,
                                      sizeof(asPayloadDefinition) / sizeof(tsZCL_TxPayloadItem)
                                     );
}


/****************************************************************************
 **
 ** NAME:       eCLD_OnOffCommandOffWithEffectReceive
 **
 ** DESCRIPTION:
 ** handles rx of off with effect commands
 **
 ** PARAMETERS:              Name                           Usage
 ** ZPS_tsAfEvent            *pZPSevent                     Zigbee stack event structure
 ** tsZCL_EndPointDefinition *psEndPointDefinition          EP structure
 ** tsZCL_ClusterInstance    *psClusterInstance             Cluster structure
 ** uint8                    *pu8TransactionSequenceNumber  Sequence number Pointer
 ** tsCLD_OnOff_OffWithEffectRequestPayload *psPayload      Payload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC teZCL_Status eCLD_OnOffCommandOffWithEffectReceive(
                ZPS_tsAfEvent               *pZPSevent,
                uint8                       *pu8TransactionSequenceNumber,
                tsCLD_OnOff_OffWithEffectRequestPayload *psPayload)
{

    uint16 u16ActualQuantity;

    tsZCL_RxPayloadItem asPayloadDefinition[] = {
            {1, &u16ActualQuantity, E_ZCL_UINT8,   &psPayload->u8EffectId},
            {1, &u16ActualQuantity, E_ZCL_UINT8,   &psPayload->u8EffectVariant},
                                                 };

    return eZCL_CustomCommandReceive(pZPSevent,
                                     pu8TransactionSequenceNumber,
                                     asPayloadDefinition,
                                     sizeof(asPayloadDefinition) / sizeof(tsZCL_RxPayloadItem),
                                     E_ZCL_ACCEPT_EXACT);

}


/****************************************************************************
 **
 ** NAME:       eCLD_OnOffCommandOnWithTimedOffSend
 **
 ** DESCRIPTION:
 ** Builds and sends an on with timed off - On/Off cluster command
 **
 ** PARAMETERS:                 Name                           Usage
 ** uint8                       u8SourceEndPointId             Source EP Id
 ** uint8                       u8DestinationEndPointId        Destination EP Id
 ** tsZCL_Address              *psDestinationAddress           Destination Address
 ** uint8                      *pu8TransactionSequenceNumber   Sequence number Pointer
 ** tsCLD_OnOff_OnWithTimedOffRequestPayload *psPayload        Message payload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC teZCL_Status eCLD_OnOffCommandOnWithTimedOffSend(
                uint8           u8SourceEndPointId,
                uint8           u8DestinationEndPointId,
                tsZCL_Address   *psDestinationAddress,
                uint8           *pu8TransactionSequenceNumber,
                tsCLD_OnOff_OnWithTimedOffRequestPayload *psPayload)
{

    tsZCL_TxPayloadItem asPayloadDefinition[] = {
                {1,       E_ZCL_UINT8,  &psPayload->u8OnOff},
                {1,       E_ZCL_UINT16, &psPayload->u16OnTime},
                {1,       E_ZCL_UINT16, &psPayload->u16OffTime},
                                                  };

        return eZCL_CustomCommandSend(u8SourceEndPointId,
                                      u8DestinationEndPointId,
                                      psDestinationAddress,
                                      GENERAL_CLUSTER_ID_ONOFF,
                                      FALSE,
                                      E_CLD_ONOFF_CMD_ON_TIMED_OFF,
                                      pu8TransactionSequenceNumber,
                                      asPayloadDefinition,
                                      FALSE,
                                      0,
                                      sizeof(asPayloadDefinition) / sizeof(tsZCL_TxPayloadItem)
                                     );
}


/****************************************************************************
 **
 ** NAME:       eCLD_OnOffCommandOnWithTimedOffReceive
 **
 ** DESCRIPTION:
 ** handles rx of on with timed off commands
 **
 ** PARAMETERS:               Name                          Usage
 ** ZPS_tsAfEvent            *pZPSevent                     Zigbee stack event structure
 ** tsZCL_EndPointDefinition *psEndPointDefinition          EP structure
 ** tsZCL_ClusterInstance    *psClusterInstance             Cluster structure
 ** uint8                    *pu8TransactionSequenceNumber  Sequence number Pointer
 ** tsCLD_OnOff_OnWithTimedOffRequestPayload *psPayload     Payload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC teZCL_Status eCLD_OnOffCommandOnWithTimedOffReceive(
                ZPS_tsAfEvent               *pZPSevent,
                uint8                       *pu8TransactionSequenceNumber,
                tsCLD_OnOff_OnWithTimedOffRequestPayload *psPayload)
{

    uint16 u16ActualQuantity;

    tsZCL_RxPayloadItem asPayloadDefinition[] = {
            {1, &u16ActualQuantity, E_ZCL_UINT8,    &psPayload->u8OnOff},
            {1, &u16ActualQuantity, E_ZCL_UINT16,   &psPayload->u16OnTime},
            {1, &u16ActualQuantity, E_ZCL_UINT16,   &psPayload->u16OffTime},
                                                 };

    return eZCL_CustomCommandReceive(pZPSevent,
                                     pu8TransactionSequenceNumber,
                                     asPayloadDefinition,
                                     sizeof(asPayloadDefinition) / sizeof(tsZCL_RxPayloadItem),
                                     E_ZCL_ACCEPT_EXACT);

}

#endif
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

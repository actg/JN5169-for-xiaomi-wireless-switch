/*****************************************************************************
 *
 * MODULE:             Identify Cluster
 *
 * COMPONENT:          IdentifyServerCommands.h
 *
 * AUTHOR:             Lee Mitchell
 *
 * DESCRIPTION:        Send an Identify cluster command
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/UnifiedZCL_ZLL102_HA122_Maintenance/Clusters/General/Source/IdentifyServerCommands.c $
 *
 * $Revision: 65741 $
 *
 * $LastChangedBy: nxp57621 $
 *
 * $LastChangedDate: 2014-11-19 07:04:45 +0000 (Wed, 19 Nov 2014) $
 *
 * $Id: IdentifyServerCommands.c 65741 2014-11-19 07:04:45Z nxp57621 $
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
 ** NAME:       eCLD_IdentifyCommandIdentifyQueryResponseSend
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
PUBLIC  teZCL_Status eCLD_IdentifyCommandIdentifyQueryResponseSend(
                                        uint8           u8SourceEndPointId,
                                        uint8           u8DestinationEndPointId,
                                        tsZCL_Address   *psDestinationAddress,
                                        uint8           *pu8TransactionSequenceNumber,
                                        tsCLD_Identify_IdentifyQueryResponsePayload *psPayload)
{

    tsZCL_TxPayloadItem asPayloadDefinition[] = {
            {1,                         E_ZCL_UINT16,   &psPayload->u16Timeout},
                                              };

    return eZCL_CustomCommandSend(u8SourceEndPointId,
                                  u8DestinationEndPointId,
                                  psDestinationAddress,
                                  GENERAL_CLUSTER_ID_IDENTIFY,
                                  TRUE,
                                  E_CLD_IDENTIFY_CMD_IDENTIFY,
                                  pu8TransactionSequenceNumber,
                                  asPayloadDefinition,
                                  FALSE,
                                  0,
                                  sizeof(asPayloadDefinition) / sizeof(tsZCL_TxPayloadItem));

}


/****************************************************************************
 **
 ** NAME:       eCLD_IdentifyCommandIdentifyQueryResponseReceive
 **
 ** DESCRIPTION:
 ** handles rx of identify query response
 **
 ** PARAMETERS:               Name                          Usage
 ** ZPS_tsAfEvent              *pZPSevent                   Zigbee stack event structure
 ** tsZCL_EndPointDefinition *psEndPointDefinition          EP structure
 ** tsZCL_ClusterInstance    *psClusterInstance             Cluster structure
 ** uint8                    *pu8TransactionSequenceNumber  Sequence number Pointer
 ** tsCLD_Identify_IdentifyQueryResponsePayload *psPayload  Payload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC  teZCL_Status eCLD_IdentifyCommandIdentifyQueryResponseReceive(
                    ZPS_tsAfEvent               *pZPSevent,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_Identify_IdentifyQueryResponsePayload *psPayload)
{

    uint16 u16ActualQuantity;

    tsZCL_RxPayloadItem asPayloadDefinition[] = {
    {1, &u16ActualQuantity, E_ZCL_UINT16,   &psPayload->u16Timeout},
                                                };

    return eZCL_CustomCommandReceive(pZPSevent,
                                        pu8TransactionSequenceNumber,
                                        asPayloadDefinition,
                                        sizeof(asPayloadDefinition) / sizeof(tsZCL_RxPayloadItem),
                                        E_ZCL_ACCEPT_EXACT);

}

#ifdef CLD_IDENTIFY_ATTR_COMMISSION_STATE
/****************************************************************************
 **
 ** NAME:       eCLD_IdentifyUpdateCommissionStateCommandReceive
 **
 ** DESCRIPTION:
 ** Receives an Identify Update Commission state Command
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
PUBLIC  teZCL_Status eCLD_IdentifyUpdateCommissionStateCommandReceive(
                                        ZPS_tsAfEvent                               *pZPSevent,
                                        uint8                                       *pu8TransactionSequenceNumber,
                                        tsCLD_Identify_UpdateCommissionStatePayload *psPayload)
{

    uint16 u16ActualQuantity;

    tsZCL_RxPayloadItem asPayloadDefinition[] = {
    {1, &u16ActualQuantity, E_ZCL_ENUM8,   &psPayload->u8Action},
    {1, &u16ActualQuantity, E_ZCL_BMAP8,   &psPayload->u8CommissionStateMask},
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

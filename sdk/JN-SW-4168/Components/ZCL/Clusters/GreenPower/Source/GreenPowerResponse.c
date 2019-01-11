/****************************************************************************
 *
 * MODULE:             ZGP Response command
 *
 * COMPONENT:          GreenPowerResponse.c
 *
 * AUTHOR:             Ramakrishna
 *
 * DESCRIPTION:        ZGP Response command send and receive functions
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/UnifiedZCL_ZLL102_HA122_Maintenance/Clusters/GreenPower/Source/GreenPowerResponse.c $
 *
 * $Revision: 65741 $
 *
 * $LastChangedBy: nxp57621 $
 *
 * $LastChangedDate: 2014-11-19 07:04:45 +0000 (Wed, 19 Nov 2014) $
 *
 * $Id: GreenPowerResponse.c 65741 2014-11-19 07:04:45Z nxp57621 $
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
#include "zcl_options.h"
#include "GreenPower.h"
#include "GreenPower_internal.h"

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
#ifndef GP_DISABLE_ZGP_RESPONSE_CMD
/****************************************************************************
 **
 ** NAME:       eGP_ZgpResponseSend
 **
 ** DESCRIPTION:
 ** Sends ZGP Response command
 **
 ** PARAMETERS:                     Name                           Usage
 ** uint8                           u8SourceEndPointId             Source EP Id
 ** uint8                           u8DestinationEndPointId        Destination EP Id
 ** tsZCL_Address                   *psDestinationAddress           Destination Address
 ** uint8                           *pu8TransactionSequenceNumber   Sequence number Pointer
 ** tsGP_ZgpResponseCmdPayload      *psZgpResponseCmdPayload        Response Cmd Payload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/

PUBLIC teZCL_Status eGP_ZgpResponseSend(
                    uint8                                  u8SourceEndPointId,
                    uint8                                  u8DestinationEndPointId,
                    tsZCL_Address                          *psDestinationAddress,
                    uint8                                  *pu8TransactionSequenceNumber,
                    tsGP_ZgpResponseCmdPayload             *psZgpResponseCmdPayload)
{
    tsZCL_TxPayloadItem asPayloadDefinition[] = {
            {1,  E_ZCL_BMAP8,    &psZgpResponseCmdPayload->b8Options},
            {1,  E_ZCL_UINT16,   &psZgpResponseCmdPayload->u16TempMasterShortAddr},
            {1,  E_ZCL_BMAP8,    &psZgpResponseCmdPayload->b8TempMasterTxChannel},
            {1,  E_ZCL_UINT32,   &psZgpResponseCmdPayload->uZgpdDeviceAddr.u32ZgpdSrcId},
            {1,  E_ZCL_UINT8,    &psZgpResponseCmdPayload->eZgpdCmdId},
            {1,  E_ZCL_OSTRING,  &psZgpResponseCmdPayload->sZgpdCommandPayload}
           };


#ifdef GP_IEEE_ADDR_SUPPORT
    if((psZgpResponseCmdPayload->b8Options & GP_APPLICATION_ID_MASK) == 2)
    {
        asPayloadDefinition[3].eType = E_ZCL_IEEE_ADDR;
        asPayloadDefinition[3].pvData = &psZgpResponseCmdPayload->uZgpdDeviceAddr.u64ZgpdIEEEAddr;
    }
#else
    if((psZgpResponseCmdPayload->b8Options & GP_APPLICATION_ID_MASK) == 2)
    {
        return E_ZCL_ERR_INVALID_VALUE;
    }
#endif


    return eZCL_CustomCommandSend(u8SourceEndPointId,
                              u8DestinationEndPointId,
                              psDestinationAddress,
                              GREENPOWER_CLUSTER_ID,
                              TRUE,
                              E_GP_ZGP_RESPONSE,
                              pu8TransactionSequenceNumber,
                              asPayloadDefinition,
                              FALSE,
                              0,
                              sizeof(asPayloadDefinition)/sizeof(tsZCL_TxPayloadItem));

}

/****************************************************************************
 **
 ** NAME:       eGP_ZgpResponseReceive
 **
 ** DESCRIPTION:
 ** Handles ZGP response comamnd
 **
 ** PARAMETERS:                 Name                            Usage
 ** ZPS_tsAfEvent               *pZPSevent                      Zigbee stack event structure
 ** uint16                      u16Offset,                      Offset
 ** tsGP_ZgpResponseCmdPayload  *psZgpResponseCmdPayload        payload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC teZCL_Status eGP_ZgpResponseReceive(
                    ZPS_tsAfEvent                          *pZPSevent,
                    uint16                                 u16Offset,
                    tsGP_ZgpResponseCmdPayload             *psZgpResponseCmdPayload)
{

    uint8 u8TransactionSequenceNumber;
    zbmap8 b8Options;
    uint16 u16ActualQuantity;

    tsZCL_RxPayloadItem asPayloadDefinition[] = {
            {1, &u16ActualQuantity, E_ZCL_BMAP8,    &psZgpResponseCmdPayload->b8Options},
            {1, &u16ActualQuantity, E_ZCL_UINT16,   &psZgpResponseCmdPayload->u16TempMasterShortAddr},
            {1, &u16ActualQuantity, E_ZCL_BMAP8,    &psZgpResponseCmdPayload->b8TempMasterTxChannel},
            {1, &u16ActualQuantity, E_ZCL_UINT32,   &psZgpResponseCmdPayload->uZgpdDeviceAddr.u32ZgpdSrcId},
            {1, &u16ActualQuantity, E_ZCL_UINT8,    &psZgpResponseCmdPayload->eZgpdCmdId},
            {1, &u16ActualQuantity, E_ZCL_OSTRING,  &psZgpResponseCmdPayload->sZgpdCommandPayload},
           };
    /* Get options field from payload */
    u16ZCL_APduInstanceReadNBO(pZPSevent->uEvent.sApsDataIndEvent.hAPduInst,
                               u16Offset,
                               E_ZCL_BMAP8,
                               &b8Options);

#ifdef GP_IEEE_ADDR_SUPPORT
    if((b8Options & GP_APPLICATION_ID_MASK) == 2)
    {
        asPayloadDefinition[3].eType = E_ZCL_IEEE_ADDR;
        asPayloadDefinition[3].pvDestination = &psZgpResponseCmdPayload->uZgpdDeviceAddr.u64ZgpdIEEEAddr;
    }
#else
    if((b8Options & GP_APPLICATION_ID_MASK) == 2)
    {
        return E_ZCL_ERR_INVALID_VALUE;
    }
#endif


    return eZCL_CustomCommandReceive(pZPSevent,
                                 &u8TransactionSequenceNumber,
                                 asPayloadDefinition,
                                 sizeof(asPayloadDefinition)/sizeof(tsZCL_RxPayloadItem),
                                 E_ZCL_ACCEPT_EXACT|E_ZCL_DISABLE_DEFAULT_RESPONSE);

}
#endif
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

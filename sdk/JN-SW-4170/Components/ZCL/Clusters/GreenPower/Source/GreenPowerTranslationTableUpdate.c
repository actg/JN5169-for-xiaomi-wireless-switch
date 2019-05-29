/****************************************************************************
 *
 * MODULE:             ZGP Translation Table Update command
 *
 * COMPONENT:          GreenPowerTranslationTableUpdate.c
 *
 * AUTHOR:             Ramakrishna
 *
 * DESCRIPTION:        ZGP Translation table update command send and receive functions
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/Components/ZCL/Trunk/Clusters/GreenPower/Source/GreenPowerTranslationTableUpdate.c $
 *
 * $Revision: 90834 $
 *
 * $LastChangedBy: nxp29741 $
 *
 * $LastChangedDate: 2017-10-30 17:47:17 +0100 (Mon, 30 Oct 2017) $
 *
 * $Id: GreenPowerTranslationTableUpdate.c 90834 2017-10-30 16:47:17Z nxp29741 $
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

/****************************************************************************
 **
 ** NAME:       eGP_ZgpTranslationTableUpdateSend
 **
 ** DESCRIPTION:
 ** Sends ZGP Translation table update command
 **
 ** PARAMETERS:         Name                           Usage
 ** uint8               u8SourceEndPointId             Source EP Id
 ** uint8               u8DestinationEndPointId        Destination EP Id
 ** tsZCL_Address      *psDestinationAddress           Destination Address
 ** uint8              *pu8TransactionSequenceNumber   Sequence number Pointer
 ** tsGP_ZgpTransTableUpdateCmdPayload *psZgpTransTableUpdatePayload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/

PUBLIC teZCL_Status eGP_ZgpTranslationTableUpdateSend(
                    uint8                                  u8SourceEndPointId,
                    uint8                                  u8DestinationEndPointId,
                    tsZCL_Address                          *psDestinationAddress,
                    uint8                                  *pu8TransactionSequenceNumber,
                    tsGP_ZgpTranslationUpdateCmdPayload    *psZgpTransTableUpdatePayload)
{

    zbmap16 b16Options;
    uint8 u8ItemsInPayload, u8NumbersOfTranslations, i;
    /* Payload with application id 2 will take an entry more */
    tsZCL_TxPayloadItem asPayloadDefinition[3 + (GP_MAX_TRANSLATION_UPDATE_ENTRY * 8)] = {
            {1,  E_ZCL_BMAP16,   &psZgpTransTableUpdatePayload->b16Options},
            {1,  E_ZCL_UINT32,   &psZgpTransTableUpdatePayload->uZgpdDeviceAddr.u32ZgpdSrcId},
           };

    /* Get options field from payload */
    b16Options = psZgpTransTableUpdatePayload->b16Options;

    u8ItemsInPayload = 2; //  mandatory items in command payload
#ifdef GP_IEEE_ADDR_SUPPORT
    if((b16Options & GP_APPLICATION_ID_MASK) == 2)
    {
        asPayloadDefinition[1].eType = E_ZCL_IEEE_ADDR;
        asPayloadDefinition[1].pvData = &psZgpTransTableUpdatePayload->uZgpdDeviceAddr.sZgpdDeviceAddrAppId2.u64ZgpdIEEEAddr;

        asPayloadDefinition[2].eType = E_ZCL_UINT8;
        asPayloadDefinition[2].pvData = &psZgpTransTableUpdatePayload->uZgpdDeviceAddr.sZgpdDeviceAddrAppId2.u8EndPoint;
        asPayloadDefinition[2].u16Quantity = 1;

        u8ItemsInPayload++; //  Endpoint added
    }
#else
    if((b16Options & GP_APPLICATION_ID_MASK) == 2)
    {
        return E_ZCL_ERR_INVALID_VALUE;
    }
#endif

    u8NumbersOfTranslations = (b16Options & GP_TRANS_UPDATE_NUM_OF_TRANSLATIONS_MASK) >> 5;

    for(i=0; i<u8NumbersOfTranslations; i++)
    {
        asPayloadDefinition[u8ItemsInPayload].u16Quantity = 1;
        asPayloadDefinition[u8ItemsInPayload].eType = E_ZCL_UINT8;
        asPayloadDefinition[u8ItemsInPayload].pvData = &psZgpTransTableUpdatePayload->asTranslationUpdateEntry[i].u8Index;
        u8ItemsInPayload++;
        asPayloadDefinition[u8ItemsInPayload].u16Quantity = 1;
        asPayloadDefinition[u8ItemsInPayload].eType = E_ZCL_UINT8;
        asPayloadDefinition[u8ItemsInPayload].pvData = &psZgpTransTableUpdatePayload->asTranslationUpdateEntry[i].eZgpdCommandId;
        u8ItemsInPayload++;
        asPayloadDefinition[u8ItemsInPayload].u16Quantity = 1;
        asPayloadDefinition[u8ItemsInPayload].eType = E_ZCL_UINT8;
        asPayloadDefinition[u8ItemsInPayload].pvData = &psZgpTransTableUpdatePayload->asTranslationUpdateEntry[i].u8EndpointId;
        u8ItemsInPayload++;
        asPayloadDefinition[u8ItemsInPayload].u16Quantity = 1;
        asPayloadDefinition[u8ItemsInPayload].eType = E_ZCL_UINT16;
        asPayloadDefinition[u8ItemsInPayload].pvData = &psZgpTransTableUpdatePayload->asTranslationUpdateEntry[i].u16ProfileID;
        u8ItemsInPayload++;
        asPayloadDefinition[u8ItemsInPayload].u16Quantity = 1;
        asPayloadDefinition[u8ItemsInPayload].eType = E_ZCL_UINT16;
        asPayloadDefinition[u8ItemsInPayload].pvData = &psZgpTransTableUpdatePayload->asTranslationUpdateEntry[i].u16ZbClusterId;
        u8ItemsInPayload++;
        asPayloadDefinition[u8ItemsInPayload].u16Quantity = 1;
        asPayloadDefinition[u8ItemsInPayload].eType = E_ZCL_UINT8;
        asPayloadDefinition[u8ItemsInPayload].pvData = &psZgpTransTableUpdatePayload->asTranslationUpdateEntry[i].u8ZbCommandId;
        u8ItemsInPayload++;
        asPayloadDefinition[u8ItemsInPayload].u16Quantity = 1;
        asPayloadDefinition[u8ItemsInPayload].eType = E_ZCL_UINT8;
        asPayloadDefinition[u8ItemsInPayload].pvData = &psZgpTransTableUpdatePayload->asTranslationUpdateEntry[i].u8ZbCmdLength;
        u8ItemsInPayload++;

        if((psZgpTransTableUpdatePayload->asTranslationUpdateEntry[i].u8ZbCmdLength  != 0)&&
          (psZgpTransTableUpdatePayload->asTranslationUpdateEntry[i].u8ZbCmdLength  != 0xFF))
        {
            if(psZgpTransTableUpdatePayload->asTranslationUpdateEntry[i].u8ZbCmdLength > GP_MAX_ZB_CMD_PAYLOAD_LENGTH)
            {
                return E_ZCL_ERR_INVALID_VALUE;
            }

            asPayloadDefinition[u8ItemsInPayload].u16Quantity = psZgpTransTableUpdatePayload->asTranslationUpdateEntry[i].u8ZbCmdLength;
            asPayloadDefinition[u8ItemsInPayload].eType = E_ZCL_UINT8;
            asPayloadDefinition[u8ItemsInPayload].pvData = &psZgpTransTableUpdatePayload->asTranslationUpdateEntry[i].au8ZbCmdPayload[0];
            u8ItemsInPayload++;

        }
    }

    return eZCL_CustomCommandSend(u8SourceEndPointId,
                              u8DestinationEndPointId,
                              psDestinationAddress,
                              GREENPOWER_CLUSTER_ID,
                              FALSE,
                              E_GP_ZGP_TRANSLATION_TABLE_UPDATE,
                              pu8TransactionSequenceNumber,
                              asPayloadDefinition,
                              FALSE,
                              0,
                              u8ItemsInPayload);

}

/****************************************************************************
 **
 ** NAME:       eGP_ZgpTranslationTableUpdateReceive
 **
 ** DESCRIPTION:
 ** Handles ZGP Pairing Search comamnd
 **
 ** PARAMETERS:               Name                          Usage
 ** ZPS_tsAfEvent            *pZPSevent                     Zigbee stack event structure
 ** uint16                    u16Offset,                    Offset
 ** tsGP_ZgpTranslationUpdateCmdPayload *psZgpTransTableUpdatePayload payload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/

PUBLIC teZCL_Status eGP_ZgpTranslationTableUpdateReceive(
                    ZPS_tsAfEvent                          *pZPSevent,
                    uint16                                 u16Offset,
                    tsGP_ZgpTranslationUpdateCmdPayload    *psZgpTransTableUpdatePayload)
{

    uint8 u8TransactionSequenceNumber;
    uint16 u16ActualQuantity, u16ZbCmdPyldLengthIndex = 0;
    zbmap16 b16Options;
    uint8  u8ItemsInPayload, u8NumbersOfTranslations, i, u8ZbCmdPyldLength = 0;

    /* Payload with application id 2 will take an entry more */
    tsZCL_RxPayloadItem asPayloadDefinition[3 + (GP_MAX_TRANSLATION_UPDATE_ENTRY * 8)] = {
            {1, &u16ActualQuantity, E_ZCL_BMAP16,   &psZgpTransTableUpdatePayload->b16Options},
            {1, &u16ActualQuantity, E_ZCL_UINT32,   &psZgpTransTableUpdatePayload->uZgpdDeviceAddr.u32ZgpdSrcId},
           };
    /* Get options field from payload */
    u16ZCL_APduInstanceReadNBO(pZPSevent->uEvent.sApsDataIndEvent.hAPduInst,
                               u16Offset,
                               E_ZCL_BMAP16,
                               &b16Options);

    u8ItemsInPayload = 2; //  mandatory items in command payload
    u16ZbCmdPyldLengthIndex = 6;

#ifdef GP_IEEE_ADDR_SUPPORT
    if((b16Options & GP_APPLICATION_ID_MASK) == 2)
    {
    	asPayloadDefinition[1].u16MaxQuantity = 1;
        asPayloadDefinition[1].eType = E_ZCL_IEEE_ADDR;
        asPayloadDefinition[1].pvDestination = &psZgpTransTableUpdatePayload->uZgpdDeviceAddr.sZgpdDeviceAddrAppId2.u64ZgpdIEEEAddr;
        u16ZbCmdPyldLengthIndex += 4;

        asPayloadDefinition[u8ItemsInPayload].u16MaxQuantity = 1;
        asPayloadDefinition[u8ItemsInPayload].eType = E_ZCL_UINT8;
        asPayloadDefinition[ u8ItemsInPayload].pvDestination = &psZgpTransTableUpdatePayload->uZgpdDeviceAddr.sZgpdDeviceAddrAppId2.u8EndPoint;
        u16ZbCmdPyldLengthIndex += 1;
        u8ItemsInPayload++;

    }
#else
    if((b16Options & GP_APPLICATION_ID_MASK) == 2)
    {
        return E_ZCL_ERR_INVALID_VALUE;
    }
#endif

    u8NumbersOfTranslations = (b16Options & GP_TRANS_UPDATE_NUM_OF_TRANSLATIONS_MASK) >> 5;

    for(i=0; i<u8NumbersOfTranslations; i++)
    {
        asPayloadDefinition[u8ItemsInPayload].u16MaxQuantity = 1;
        asPayloadDefinition[u8ItemsInPayload].pu16ActualQuantity =  &u16ActualQuantity;
        asPayloadDefinition[u8ItemsInPayload].eType = E_ZCL_UINT8;
        asPayloadDefinition[u8ItemsInPayload].pvDestination = &psZgpTransTableUpdatePayload->asTranslationUpdateEntry[i].u8Index;
        u8ItemsInPayload++;
        asPayloadDefinition[u8ItemsInPayload].u16MaxQuantity = 1;
        asPayloadDefinition[u8ItemsInPayload].pu16ActualQuantity =  &u16ActualQuantity;
        asPayloadDefinition[u8ItemsInPayload].eType = E_ZCL_UINT8;
        asPayloadDefinition[u8ItemsInPayload].pvDestination = &psZgpTransTableUpdatePayload->asTranslationUpdateEntry[i].eZgpdCommandId;
        u8ItemsInPayload++;
        asPayloadDefinition[u8ItemsInPayload].u16MaxQuantity = 1;
        asPayloadDefinition[u8ItemsInPayload].pu16ActualQuantity =  &u16ActualQuantity;
        asPayloadDefinition[u8ItemsInPayload].eType = E_ZCL_UINT8;
        asPayloadDefinition[u8ItemsInPayload].pvDestination = &psZgpTransTableUpdatePayload->asTranslationUpdateEntry[i].u8EndpointId;
        u8ItemsInPayload++;
        asPayloadDefinition[u8ItemsInPayload].u16MaxQuantity = 1;
        asPayloadDefinition[u8ItemsInPayload].pu16ActualQuantity =  &u16ActualQuantity;
        asPayloadDefinition[u8ItemsInPayload].eType = E_ZCL_UINT16;
        asPayloadDefinition[u8ItemsInPayload].pvDestination = &psZgpTransTableUpdatePayload->asTranslationUpdateEntry[i].u16ProfileID;
        u8ItemsInPayload++;
        asPayloadDefinition[u8ItemsInPayload].u16MaxQuantity = 1;
        asPayloadDefinition[u8ItemsInPayload].pu16ActualQuantity =  &u16ActualQuantity;
        asPayloadDefinition[u8ItemsInPayload].eType = E_ZCL_UINT16;
        asPayloadDefinition[u8ItemsInPayload].pvDestination = &psZgpTransTableUpdatePayload->asTranslationUpdateEntry[i].u16ZbClusterId;
        u8ItemsInPayload++;
        asPayloadDefinition[u8ItemsInPayload].u16MaxQuantity = 1;
        asPayloadDefinition[u8ItemsInPayload].pu16ActualQuantity =  &u16ActualQuantity;
        asPayloadDefinition[u8ItemsInPayload].eType = E_ZCL_UINT8;
        asPayloadDefinition[u8ItemsInPayload].pvDestination = &psZgpTransTableUpdatePayload->asTranslationUpdateEntry[i].u8ZbCommandId;
        u8ItemsInPayload++;
        asPayloadDefinition[u8ItemsInPayload].u16MaxQuantity = 1;
        asPayloadDefinition[u8ItemsInPayload].pu16ActualQuantity =  &u16ActualQuantity;
        asPayloadDefinition[u8ItemsInPayload].eType = E_ZCL_UINT8;
        asPayloadDefinition[u8ItemsInPayload].pvDestination = &psZgpTransTableUpdatePayload->asTranslationUpdateEntry[i].u8ZbCmdLength;
        u8ItemsInPayload++;

        u16ZbCmdPyldLengthIndex += 8;
        u16ZCL_APduInstanceReadNBO(pZPSevent->uEvent.sApsDataIndEvent.hAPduInst,
                                   u16Offset+u16ZbCmdPyldLengthIndex,
                                   E_ZCL_UINT8,
                                   &u8ZbCmdPyldLength);

        u16ZbCmdPyldLengthIndex++;

        if((u8ZbCmdPyldLength  != 0)&&(u8ZbCmdPyldLength  != 0xFF))
        {
            if(u8ZbCmdPyldLength > GP_MAX_ZB_CMD_PAYLOAD_LENGTH)
            {
                return E_ZCL_ERR_INVALID_VALUE;
            }
            asPayloadDefinition[u8ItemsInPayload].pu16ActualQuantity =  &u16ActualQuantity;
            asPayloadDefinition[u8ItemsInPayload].u16MaxQuantity = u8ZbCmdPyldLength;
            asPayloadDefinition[u8ItemsInPayload].eType = E_ZCL_UINT8;
            asPayloadDefinition[u8ItemsInPayload].pvDestination = &psZgpTransTableUpdatePayload->asTranslationUpdateEntry[i].au8ZbCmdPayload[0];
            u8ItemsInPayload++;
            u16ZbCmdPyldLengthIndex += u8ZbCmdPyldLength;
        }
    }


    return eZCL_CustomCommandReceive(pZPSevent,
                                 &u8TransactionSequenceNumber,
                                 asPayloadDefinition,
                                 u8ItemsInPayload,
                                 E_ZCL_ACCEPT_EXACT|E_ZCL_DISABLE_DEFAULT_RESPONSE);

}

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

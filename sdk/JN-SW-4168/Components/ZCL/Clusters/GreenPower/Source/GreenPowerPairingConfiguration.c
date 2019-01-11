/****************************************************************************
 *
 * MODULE:             ZGP Pairing Configuration command
 *
 * COMPONENT:          GreenPowerPairingConfiguration.c
 *
 * AUTHOR:             Ramakrishna
 *
 * DESCRIPTION:        ZGP pairing configuration command send and receive functions
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/UnifiedZCL_ZLL102_HA122_Maintenance/Clusters/GreenPower/Source/GreenPowerPairingConfiguration.c $
 *
 * $Revision: 65741 $
 *
 * $LastChangedBy: nxp57621 $
 *
 * $LastChangedDate: 2014-11-19 07:04:45 +0000 (Wed, 19 Nov 2014) $
 *
 * $Id: GreenPowerPairingConfiguration.c 65741 2014-11-19 07:04:45Z nxp57621 $
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
 ** NAME:       eGP_ZgpPairingConfigSend
 **
 ** DESCRIPTION:
 ** Sends ZGP pairing configuration command
 **
 ** PARAMETERS:         Name                           Usage
 ** uint8               u8SourceEndPointId             Source EP Id
 ** uint8               u8DestinationEndPointId        Destination EP Id
 ** tsZCL_Address      *psDestinationAddress           Destination Address
 ** uint8              *pu8TransactionSequenceNumber   Sequence number Pointer
 ** tsGP_ZgpPairingSearchCmdPayload *psZgpPairingSearchPayload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/

PUBLIC teZCL_Status eGP_ZgpPairingConfigSend(
                    uint8                                  u8SourceEndPointId,
                    uint8                                  u8DestinationEndPointId,
                    tsZCL_Address                          *psDestinationAddress,
                    uint8                                  *pu8TransactionSequenceNumber,
                    tsGP_ZgpPairingConfigCmdPayload        *psZgpPairingConfigPayload)
{

    zbmap16 b16Options;
    uint8 u8ItemsInPayload, u8NumOfPairedEndpoints = 0;

    tsZCL_TxPayloadItem asPayloadDefinition[] = {
            {1,  E_ZCL_UINT8,    &psZgpPairingConfigPayload->u8Actions},
            {1,  E_ZCL_BMAP16,   &psZgpPairingConfigPayload->b16Options},
            {1,  E_ZCL_UINT32,   &psZgpPairingConfigPayload->uZgpdDeviceAddr.u32ZgpdSrcId},
            {1,  E_ZCL_UINT8,    &psZgpPairingConfigPayload->eZgpdDeviceId},
            {1,  E_ZCL_UINT8,    &psZgpPairingConfigPayload->u8ZgpsGroupListEntries},
            {1,  E_ZCL_UINT16,   psZgpPairingConfigPayload->asZgpsGroupList},
            {1,  E_ZCL_UINT16,   &psZgpPairingConfigPayload->u16ZgpdAssignedAlias},
            {1,  E_ZCL_UINT8,    &psZgpPairingConfigPayload->u8ForwardingRadius},
            {1,  E_ZCL_BMAP8,    &psZgpPairingConfigPayload->b8SecOptions},
            {1,  E_ZCL_UINT32,   &psZgpPairingConfigPayload->u32ZgpdSecFrameCounter},
            {1,  E_ZCL_KEY_128,  &psZgpPairingConfigPayload->sZgpdKey},
            {1,  E_ZCL_UINT8,    &psZgpPairingConfigPayload->u8NumberOfPairedEndpoints},
            {u8NumOfPairedEndpoints,  E_ZCL_UINT8,    &psZgpPairingConfigPayload->au8PairedEndpoints[0]}
           };

    /* Get options field from payload */
    b16Options = psZgpPairingConfigPayload->b16Options;

    u8ItemsInPayload = 4; //  mandatory items in command payload
#ifdef GP_IEEE_ADDR_SUPPORT
    if((b16Options & GP_APPLICATION_ID_MASK) == 2)
    {
        asPayloadDefinition[2].eType = E_ZCL_IEEE_ADDR;
        asPayloadDefinition[2].pvData = &psZgpPairingConfigPayload->uZgpdDeviceAddr.u64ZgpdIEEEAddr;
    }
#else
    if((b16Options & GP_APPLICATION_ID_MASK) == 2)
    {
        return E_ZCL_ERR_INVALID_VALUE;
    }
#endif

    if(((b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3) == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID)
    {
        u8ItemsInPayload += 2;
        asPayloadDefinition[5].u16Quantity = psZgpPairingConfigPayload->u8ZgpsGroupListEntries*2;
    }

    if(b16Options & GP_SINK_TABLE_ASSIGNED_ADDR_MASK)
    {
        u8ItemsInPayload++;
        if(u8ItemsInPayload == 5)
        {
            asPayloadDefinition[4].eType = E_ZCL_UINT16;
            asPayloadDefinition[4].pvData = &psZgpPairingConfigPayload->u16ZgpdAssignedAlias;
        }
    }

    u8ItemsInPayload++; //forwarding radius mandatory field

    asPayloadDefinition[u8ItemsInPayload - 1].eType = E_ZCL_UINT8;
    asPayloadDefinition[u8ItemsInPayload - 1].pvData = &psZgpPairingConfigPayload->u8ForwardingRadius;

    if(b16Options & GP_SINK_TABLE_SECURITY_USE_MASK)
    {
        u8ItemsInPayload++; //security options field
        asPayloadDefinition[u8ItemsInPayload - 1].eType = E_ZCL_BMAP8;
        asPayloadDefinition[u8ItemsInPayload - 1].pvData = &psZgpPairingConfigPayload->b8SecOptions;
    }

    /* check if sequence number capability or security is present*/
    if((b16Options & GP_SINK_TABLE_SEQ_NUM_CAP_MASK)||
                (b16Options & GP_SINK_TABLE_SECURITY_USE_MASK))
    {
        u8ItemsInPayload++; //security frame counter
        asPayloadDefinition[u8ItemsInPayload - 1].eType = E_ZCL_UINT32;
        asPayloadDefinition[u8ItemsInPayload - 1].pvData = &psZgpPairingConfigPayload->u32ZgpdSecFrameCounter;
    }

    //if security options are available
    if(b16Options & GP_SINK_TABLE_SECURITY_USE_MASK)
    {
        //teGP_GreenPowerSecLevel    eSecLevel;
        //teGP_GreenPowerSecKeyType  eSecKeyType;

        //eSecLevel = psZgpPairingConfigPayload->b8SecOptions & GP_SECURITY_LEVEL_MASK;
        //eSecKeyType = (psZgpPairingConfigPayload->b8SecOptions & GP_SECURITY_KEY_TYPE_MASK) >> 2;
        //if security key is available
        //if((eSecLevel != E_GP_NO_SECURITY)&&(eSecKeyType != E_GP_DERIVED_INDIVIDUAL_ZGPD_KEY))
        {
            u8ItemsInPayload++; //security key
            asPayloadDefinition[u8ItemsInPayload - 1].eType = E_ZCL_KEY_128;
            asPayloadDefinition[u8ItemsInPayload - 1].pvData = &psZgpPairingConfigPayload->sZgpdKey;
        }
    }

    u8ItemsInPayload++; //Number of paired endpoints mandatory field

    asPayloadDefinition[u8ItemsInPayload - 1].eType = E_ZCL_UINT8;
    asPayloadDefinition[u8ItemsInPayload - 1].pvData = &psZgpPairingConfigPayload->u8NumberOfPairedEndpoints;

    if( (psZgpPairingConfigPayload->u8NumberOfPairedEndpoints > 0) &&
	    (psZgpPairingConfigPayload->u8NumberOfPairedEndpoints < 0xfd))
    {
        u8ItemsInPayload++; //paired endpoints optional field
        u8NumOfPairedEndpoints = psZgpPairingConfigPayload->u8NumberOfPairedEndpoints;
        asPayloadDefinition[u8ItemsInPayload - 1].u16Quantity = u8NumOfPairedEndpoints;
        asPayloadDefinition[u8ItemsInPayload - 1].eType = E_ZCL_UINT8;
        asPayloadDefinition[u8ItemsInPayload - 1].pvData = &psZgpPairingConfigPayload->au8PairedEndpoints[0];
    }

    return eZCL_CustomCommandSend(u8SourceEndPointId,
                              u8DestinationEndPointId,
                              psDestinationAddress,
                              GREENPOWER_CLUSTER_ID,
                              FALSE,
                              E_GP_ZGP_PAIRING_CONFIGURATION,
                              pu8TransactionSequenceNumber,
                              asPayloadDefinition,
                              FALSE,
                              0,
                              u8ItemsInPayload);

}

/****************************************************************************
 **
 ** NAME:       eGP_ZgpPairingConfigReceive
 **
 ** DESCRIPTION:
 ** Handles ZGP Pairing Search comamnd
 **
 ** PARAMETERS:               Name                          Usage
 ** ZPS_tsAfEvent            *pZPSevent                     Zigbee stack event structure
 ** uint16                    u16Offset,                    Offset
 ** tsGP_ZgpPairingConfigCmdPayload *psZgpPairingConfigPayload payload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/

PUBLIC teZCL_Status eGP_ZgpPairingConfigReceive(
                    ZPS_tsAfEvent                          *pZPSevent,
                    uint16                                 u16Offset,
                    tsGP_ZgpPairingConfigCmdPayload        *psZgpPairingConfigPayload)
{

    uint8 u8TransactionSequenceNumber,i;
    uint16 u16ActualQuantity;
    zbmap16 b16Options;
    uint8 u8ItemsInPayload, u8NumOfPairedEndpoints = 0, u8NumOfPairedEndpointIndex = 0, u8GroupListEntries;
    tsGP_ZgpsGroupList asZgpsGroupList[20];
    teZCL_Status eStatus;
    uint8 b8SecOptions;

    tsZCL_RxPayloadItem asPayloadDefinition[] = {
            {1, &u16ActualQuantity,  E_ZCL_UINT8,    &psZgpPairingConfigPayload->u8Actions},
            {1, &u16ActualQuantity,  E_ZCL_BMAP16,   &psZgpPairingConfigPayload->b16Options},
            {1, &u16ActualQuantity,  E_ZCL_UINT32,   &psZgpPairingConfigPayload->uZgpdDeviceAddr.u32ZgpdSrcId},
            {1, &u16ActualQuantity,  E_ZCL_UINT8,    &psZgpPairingConfigPayload->eZgpdDeviceId},
            {1, &u16ActualQuantity,  E_ZCL_UINT8,    &psZgpPairingConfigPayload->u8ZgpsGroupListEntries},
            {1, &u16ActualQuantity,  E_ZCL_UINT16,   asZgpsGroupList},
            {1, &u16ActualQuantity,  E_ZCL_UINT16,   &psZgpPairingConfigPayload->u16ZgpdAssignedAlias},
            {1, &u16ActualQuantity,  E_ZCL_UINT8,    &psZgpPairingConfigPayload->u8ForwardingRadius},
            {1, &u16ActualQuantity,  E_ZCL_BMAP8,    &psZgpPairingConfigPayload->b8SecOptions},
            {1, &u16ActualQuantity,  E_ZCL_UINT32,   &psZgpPairingConfigPayload->u32ZgpdSecFrameCounter},
            {1, &u16ActualQuantity,  E_ZCL_KEY_128,  &psZgpPairingConfigPayload->sZgpdKey},
            {1, &u16ActualQuantity,  E_ZCL_UINT8,    &psZgpPairingConfigPayload->u8NumberOfPairedEndpoints},
            {u8NumOfPairedEndpoints, &u16ActualQuantity, E_ZCL_UINT8,    &psZgpPairingConfigPayload->au8PairedEndpoints[0]}
           };

    /* Get options field from payload */
    u16ZCL_APduInstanceReadNBO(pZPSevent->uEvent.sApsDataIndEvent.hAPduInst,
                               u16Offset+1,
                               E_ZCL_BMAP16,
                               &b16Options);

    u8ItemsInPayload = 4; //  mandatory items in command payload
    u8NumOfPairedEndpointIndex = 8;
#ifdef GP_IEEE_ADDR_SUPPORT
    if((b16Options & GP_APPLICATION_ID_MASK) == 2)
    {
        asPayloadDefinition[2].eType = E_ZCL_IEEE_ADDR;
        asPayloadDefinition[2].pvDestination = &psZgpPairingConfigPayload->uZgpdDeviceAddr.u64ZgpdIEEEAddr;
        u8NumOfPairedEndpointIndex += 4;
    }
#else
    if((b16Options & GP_APPLICATION_ID_MASK) == 2)
    {
        return E_ZCL_ERR_INVALID_VALUE;
    }
#endif

    if(((b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3) == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID)
    {
        /* Get Number of group list entries field from payload */
        u16ZCL_APduInstanceReadNBO(pZPSevent->uEvent.sApsDataIndEvent.hAPduInst,
                                   u16Offset+u8NumOfPairedEndpointIndex,
                                   E_ZCL_UINT8,
                                   &u8GroupListEntries);
        if(u8GroupListEntries > 20)
        {
            return E_ZCL_ERR_INSUFFICIENT_SPACE;
        }
        u8ItemsInPayload += 2;
        asPayloadDefinition[5].u16MaxQuantity = u8GroupListEntries*2;
        u8NumOfPairedEndpointIndex += 1+ (u8GroupListEntries*4);
    }

    if(b16Options & GP_SINK_TABLE_ASSIGNED_ADDR_MASK)
    {
        u8ItemsInPayload++;
        if(u8ItemsInPayload == 5)
        {
            asPayloadDefinition[4].eType = E_ZCL_UINT16;
            asPayloadDefinition[4].pvDestination = &psZgpPairingConfigPayload->u16ZgpdAssignedAlias;
        }
        u8NumOfPairedEndpointIndex += 2;
    }

    u8ItemsInPayload++; //forwarding radius mandatory field

    asPayloadDefinition[u8ItemsInPayload - 1].eType = E_ZCL_UINT8;
    asPayloadDefinition[u8ItemsInPayload - 1].pvDestination = &psZgpPairingConfigPayload->u8ForwardingRadius;
    u8NumOfPairedEndpointIndex++;

    if(b16Options & GP_SINK_TABLE_SECURITY_USE_MASK)
    {

        u16ZCL_APduInstanceReadNBO(pZPSevent->uEvent.sApsDataIndEvent.hAPduInst,
                                   u16Offset+u8NumOfPairedEndpointIndex,
                                   E_ZCL_UINT8,
                                   &b8SecOptions);

         u8ItemsInPayload++; //security options field
         asPayloadDefinition[u8ItemsInPayload - 1].eType = E_ZCL_BMAP8;
         asPayloadDefinition[u8ItemsInPayload - 1].pvDestination = &psZgpPairingConfigPayload->b8SecOptions;
         u8NumOfPairedEndpointIndex++;
    }

    /* check if sequence number capability or security is present*/
    if((b16Options & GP_SINK_TABLE_SEQ_NUM_CAP_MASK)||
               (b16Options & GP_SINK_TABLE_SECURITY_USE_MASK))
    {
        u8ItemsInPayload++; //security frame counter
        asPayloadDefinition[u8ItemsInPayload - 1].eType = E_ZCL_UINT32;
        asPayloadDefinition[u8ItemsInPayload - 1].pvDestination = &psZgpPairingConfigPayload->u32ZgpdSecFrameCounter;
        u8NumOfPairedEndpointIndex += 4;
    }

    //if security options are available
    if(b16Options & GP_SINK_TABLE_SECURITY_USE_MASK)
    {
        teGP_GreenPowerSecLevel    eSecLevel;
        teGP_GreenPowerSecKeyType  eSecKeyType;

        eSecLevel = b8SecOptions & GP_SECURITY_LEVEL_MASK;
        eSecKeyType = (b8SecOptions & GP_SECURITY_KEY_TYPE_MASK) >> 2;
        //if security key is available
        if((eSecLevel != E_GP_NO_SECURITY)&&(eSecKeyType != E_GP_DERIVED_INDIVIDUAL_ZGPD_KEY))
        {
            u8ItemsInPayload++; //security key
            asPayloadDefinition[u8ItemsInPayload - 1].eType = E_ZCL_KEY_128;
            asPayloadDefinition[u8ItemsInPayload - 1].pvDestination = &psZgpPairingConfigPayload->sZgpdKey;
            u8NumOfPairedEndpointIndex += 16;
        }
    }

    u8ItemsInPayload++; //Number of paired endpoints mandatory field

    asPayloadDefinition[u8ItemsInPayload - 1].eType = E_ZCL_UINT8;
    asPayloadDefinition[u8ItemsInPayload - 1].pvDestination = &psZgpPairingConfigPayload->u8NumberOfPairedEndpoints;

    u16ZCL_APduInstanceReadNBO(pZPSevent->uEvent.sApsDataIndEvent.hAPduInst,
                               u16Offset+u8NumOfPairedEndpointIndex,
                               E_ZCL_UINT8,
                               &u8NumOfPairedEndpoints);

    if((u8NumOfPairedEndpoints > 0)&&
       (u8NumOfPairedEndpoints < 0xfd))
    {
        if(u8NumOfPairedEndpoints > GP_MAX_PAIRED_ENDPOINTS)
        {
            return E_ZCL_ERR_INVALID_VALUE;
        }
        u8ItemsInPayload++; //paired endpoints optional field

        asPayloadDefinition[u8ItemsInPayload - 1].u16MaxQuantity = u8NumOfPairedEndpoints;
        asPayloadDefinition[u8ItemsInPayload - 1].eType = E_ZCL_UINT8;
        asPayloadDefinition[u8ItemsInPayload - 1].pvDestination = &psZgpPairingConfigPayload->au8PairedEndpoints[0];
    }


    eStatus =  eZCL_CustomCommandReceive(pZPSevent,
                                 &u8TransactionSequenceNumber,
                                 asPayloadDefinition,
                                 u8ItemsInPayload,
                                 E_ZCL_ACCEPT_EXACT|E_ZCL_DISABLE_DEFAULT_RESPONSE);

    if(psZgpPairingConfigPayload->u8ZgpsGroupListEntries > GP_MAX_SINK_GROUP_LIST)
    {
        psZgpPairingConfigPayload->u8ZgpsGroupListEntries = GP_MAX_SINK_GROUP_LIST;
    }
    for(i = 0; i < psZgpPairingConfigPayload->u8ZgpsGroupListEntries; i++)
    {
        psZgpPairingConfigPayload->asZgpsGroupList[i].u16SinkGroup = asZgpsGroupList[i].u16SinkGroup;
        psZgpPairingConfigPayload->asZgpsGroupList[i].u16Alias = asZgpsGroupList[i].u16Alias;
    }

    return eStatus;
}

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

/****************************************************************************
 *
 * MODULE:             ZGP Pairing command
 *
 * COMPONENT:          GreenPowerPairing.c
 *
 * AUTHOR:             Ramakrishna
 *
 * DESCRIPTION:        ZGP pairing command send and receive functions
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/UnifiedZCL_ZLL102_HA122_Maintenance/Clusters/GreenPower/Source/GreenPowerPairing.c $
 *
 * $Revision: 65741 $
 *
 * $LastChangedBy: nxp57621 $
 *
 * $LastChangedDate: 2014-11-19 07:04:45 +0000 (Wed, 19 Nov 2014) $
 *
 * $Id: GreenPowerPairing.c 65741 2014-11-19 07:04:45Z nxp57621 $
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
 ** NAME:       eGP_ZgpPairingSend
 **
 ** DESCRIPTION:
 ** Sends ZGP pairing command
 **
 ** PARAMETERS:         Name                           Usage
 ** uint8               u8SourceEndPointId             Source EP Id
 ** uint8               u8DestinationEndPointId        Destination EP Id
 ** tsZCL_Address      *psDestinationAddress           Destination Address
 ** uint8              *pu8TransactionSequenceNumber   Sequence number Pointer
 ** tsGP_ZgpPairingCmdPayload *psZgpPairingPayload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/

PUBLIC teZCL_Status eGP_ZgpPairingSend(
                    uint8                                  u8SourceEndPointId,
                    uint8                                  u8DestinationEndPointId,
                    tsZCL_Address                          *psDestinationAddress,
                    uint8                                  *pu8TransactionSequenceNumber,
                    tsGP_ZgpPairingCmdPayload              *psZgpPairingPayload)
{

    zbmap24 b24Options;
    uint8 u8ItemsInPayload;

    tsZCL_TxPayloadItem asPayloadDefinition[] = {
            {1,  E_ZCL_BMAP24,   &psZgpPairingPayload->b24Options},
            {1,  E_ZCL_UINT32,   &psZgpPairingPayload->uZgpdDeviceAddr.u32ZgpdSrcId},
            {1,  E_ZCL_UINT16,   &psZgpPairingPayload->u16SinkGroupID},
            {1,  E_ZCL_UINT8,    &psZgpPairingPayload->u8DeviceId},
            {1,  E_ZCL_UINT32,   &psZgpPairingPayload->u32ZgpdSecFrameCounter},
            {1,  E_ZCL_KEY_128,  &psZgpPairingPayload->sZgpdKey},
            {1,  E_ZCL_UINT16,   &psZgpPairingPayload->u16AssignedAlias},
            {1,  E_ZCL_UINT8,    &psZgpPairingPayload->u8ForwardingRadius}

           };

    /* Get options field from payload */
    b24Options = psZgpPairingPayload->b24Options;

    u8ItemsInPayload = 2; //  mandatory items in command payload
#ifdef GP_IEEE_ADDR_SUPPORT
    if((b24Options & GP_APPLICATION_ID_MASK) == 2)
    {
        asPayloadDefinition[1].eType = E_ZCL_IEEE_ADDR;
        asPayloadDefinition[1].pvData = &psZgpPairingPayload->uZgpdDeviceAddr.u64ZgpdIEEEAddr;
    }
#else
    if((b24Options & GP_APPLICATION_ID_MASK) == 2)
    {
        return E_ZCL_ERR_INVALID_VALUE;
    }
#endif

    if(!(b24Options & GP_PAIRING_REMOVE_GPD_MASK))
    {
        if((((b24Options & GP_PAIRING_COMM_MODE_MASK) >> 5) == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_DGROUP_ID)||
          (((b24Options & GP_PAIRING_COMM_MODE_MASK) >> 5) == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID))
        {
            u8ItemsInPayload += 1; //  increase sink group id field
        }
        else
        {
            return E_ZCL_ERR_INVALID_VALUE;
        }

        if(b24Options & GP_PAIRING_ADD_SINK_MASK)
        {
            u8ItemsInPayload += 1; //  increase device id field

            if(b24Options & GP_PAIRING_SECURITY_COUNTER_PRESENT_MASK)
            {
                u8ItemsInPayload += 1; //  increase security frame counter field
            }

            if(b24Options & GP_PAIRING_SECURITY_KEY_PRESENT_MASK)
            {
                u8ItemsInPayload += 1; //  increase security key field
                /* if security frame counter is not present in payload
                 * then security key field would be at 5th position */
                if(u8ItemsInPayload == 5)
                {
                    asPayloadDefinition[4].eType = E_ZCL_KEY_128;
                    asPayloadDefinition[4].pvData = &psZgpPairingPayload->sZgpdKey;
                }
            }

            if(b24Options & GP_PAIRING_ASSIGNED_ALIAS_PRESENT_MASK)
            {
                u8ItemsInPayload += 1; //  increase assigned alias field
                /* if security frame counter and security key are not present in payload
                 * then assigned alias field would be at 5th position */
                if(u8ItemsInPayload == 5)
                {
                    asPayloadDefinition[4].eType = E_ZCL_UINT16;
                    asPayloadDefinition[4].pvData = &psZgpPairingPayload->u16AssignedAlias;
                }
                /* if one of the field, security frame counter or security key is not present in payload
                 * then assigned alias field would be at 6th position */
                else if(u8ItemsInPayload == 6)
                {
                    asPayloadDefinition[5].eType = E_ZCL_UINT16;
                    asPayloadDefinition[5].pvData = &psZgpPairingPayload->u16AssignedAlias;
                }
            }

            if(b24Options & GP_PAIRING_FORWARDING_RADIUS_PRESENT_MASK)
            {
                u8ItemsInPayload += 1; //  increase forwarding radius field
                /* if security frame counter, security key and assigned alias are not present in payload
                 * then forwarding radius field would be at 5th position */
                if(u8ItemsInPayload == 5)
                {
                    asPayloadDefinition[4].eType = E_ZCL_UINT8;
                    asPayloadDefinition[4].pvData = &psZgpPairingPayload->u8ForwardingRadius;
                }
                /* if any 2 field, security frame counter or security key or assigned address
                 * is not present in payload then forwarding radius field would be at 6th position */
                else if(u8ItemsInPayload == 6)
                {
                    asPayloadDefinition[5].eType = E_ZCL_UINT8;
                    asPayloadDefinition[5].pvData = &psZgpPairingPayload->u8ForwardingRadius;
                }
                /* if any one field, security frame counter or security key or assigned address
                 * is not present in payload then forwarding radius field would be at 7th position */
                else if(u8ItemsInPayload == 7)
                {
                    asPayloadDefinition[6].eType = E_ZCL_UINT8;
                    asPayloadDefinition[6].pvData = &psZgpPairingPayload->u8ForwardingRadius;
                }
            }
        }
    }

    return eZCL_CustomCommandSend(u8SourceEndPointId,
                              u8DestinationEndPointId,
                              psDestinationAddress,
                              GREENPOWER_CLUSTER_ID,
                              TRUE,
                              E_GP_ZGP_PAIRING,
                              pu8TransactionSequenceNumber,
                              asPayloadDefinition,
                              FALSE,
                              0,
                              u8ItemsInPayload);

}

/****************************************************************************
 **
 ** NAME:       eGP_ZgpPairingReceive
 **
 ** DESCRIPTION:
 ** Handles ZGP Pairing command
 **
 ** PARAMETERS:               Name                          Usage
 ** ZPS_tsAfEvent            *pZPSevent                     Zigbee stack event structure
 ** uint16                    u16Offset,                    Offset
 ** tsGP_ZgpPairingSearchCmdPayload *psZgpPairingSearchPayload payload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/

PUBLIC teZCL_Status eGP_ZgpPairingReceive(
                    ZPS_tsAfEvent                          *pZPSevent,
                    uint16                                 u16Offset,
                    tsGP_ZgpPairingCmdPayload              *psZgpPairingPayload)
{

    uint8 u8TransactionSequenceNumber;
    uint16 u16ActualQuantity;
    zbmap24 b24Options;
    uint8  u8ItemsInPayload;

    tsZCL_RxPayloadItem asPayloadDefinition[] = {
             {1, &u16ActualQuantity, E_ZCL_BMAP24,   &psZgpPairingPayload->b24Options},
             {1, &u16ActualQuantity, E_ZCL_UINT32,   &psZgpPairingPayload->uZgpdDeviceAddr.u32ZgpdSrcId},
             {1, &u16ActualQuantity, E_ZCL_UINT16,   &psZgpPairingPayload->u16SinkGroupID},
             {1, &u16ActualQuantity, E_ZCL_UINT8,    &psZgpPairingPayload->u8DeviceId},
             {1, &u16ActualQuantity, E_ZCL_UINT32,   &psZgpPairingPayload->u32ZgpdSecFrameCounter},
             {1, &u16ActualQuantity, E_ZCL_KEY_128,  &psZgpPairingPayload->sZgpdKey},
             {1, &u16ActualQuantity, E_ZCL_UINT16,   &psZgpPairingPayload->u16AssignedAlias},
             {1, &u16ActualQuantity, E_ZCL_UINT8,    &psZgpPairingPayload->u8ForwardingRadius}
                       };
    /* Get options field from payload */
    u16ZCL_APduInstanceReadNBO(pZPSevent->uEvent.sApsDataIndEvent.hAPduInst,
                               u16Offset,
                               E_ZCL_BMAP24,
                               &b24Options);

    u8ItemsInPayload = 2; //  mandatory items in command payload
#ifdef GP_IEEE_ADDR_SUPPORT
    if((b24Options & GP_APPLICATION_ID_MASK) == 2)
    {
        asPayloadDefinition[1].eType = E_ZCL_IEEE_ADDR;
        asPayloadDefinition[1].pvDestination = &psZgpPairingPayload->uZgpdDeviceAddr.u64ZgpdIEEEAddr;
    }
#else
    if((b24Options & GP_APPLICATION_ID_MASK) == 2)
    {
        return E_ZCL_ERR_INVALID_VALUE;
    }
#endif

    if(!(b24Options & GP_PAIRING_REMOVE_GPD_MASK))
    {
        if((((b24Options & GP_PAIRING_COMM_MODE_MASK) >> 5) == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_DGROUP_ID)||
          (((b24Options & GP_PAIRING_COMM_MODE_MASK) >> 5) == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID))
        {
               u8ItemsInPayload += 1; //  increase sink group id field
           }
           else
           {
               return E_ZCL_ERR_INVALID_VALUE;
           }

           if(b24Options & GP_PAIRING_ADD_SINK_MASK)
           {
               u8ItemsInPayload += 1; //  increase device id field

               if(b24Options & GP_PAIRING_SECURITY_COUNTER_PRESENT_MASK)
               {
                   u8ItemsInPayload += 1; //  increase security frame counter field
               }

               if(b24Options & GP_PAIRING_SECURITY_KEY_PRESENT_MASK)
               {
                   u8ItemsInPayload += 1; //  increase security key field
                   /* if security frame counter is not present in payload
                    * then security key field would be at 5th position */
                   if(u8ItemsInPayload == 5)
                   {
                       asPayloadDefinition[4].eType = E_ZCL_KEY_128;
                       asPayloadDefinition[4].pvDestination = &psZgpPairingPayload->sZgpdKey;
                   }
               }

               if(b24Options & GP_PAIRING_ASSIGNED_ALIAS_PRESENT_MASK)
               {
                   u8ItemsInPayload += 1; //  increase assigned alias field
                   /* if security frame counter and security key are not present in payload
                    * then assigned alias field would be at 5th position */
                   if(u8ItemsInPayload == 5)
                   {
                       asPayloadDefinition[4].eType = E_ZCL_UINT16;
                       asPayloadDefinition[4].pvDestination = &psZgpPairingPayload->u16AssignedAlias;
                   }
                   /* if one of the field, security frame counter or security key is not present in payload
                    * then assigned alias field would be at 6th position */
                   else if(u8ItemsInPayload == 6)
                   {
                       asPayloadDefinition[5].eType = E_ZCL_UINT16;
                       asPayloadDefinition[5].pvDestination = &psZgpPairingPayload->u16AssignedAlias;
                   }
               }

               if(b24Options & GP_PAIRING_FORWARDING_RADIUS_PRESENT_MASK)
               {
                   u8ItemsInPayload += 1; //  increase forwarding radius field
                   /* if security frame counter, security key and assigned alias are not present in payload
                    * then forwarding radius field would be at 5th position */
                   if(u8ItemsInPayload == 5)
                   {
                       asPayloadDefinition[4].eType = E_ZCL_UINT8;
                       asPayloadDefinition[4].pvDestination = &psZgpPairingPayload->u8ForwardingRadius;
                   }
                   /* if any 2 field, security frame counter or security key or assigned address
                    * is not present in payload then forwarding radius field would be at 6th position */
                   else if(u8ItemsInPayload == 6)
                   {
                       asPayloadDefinition[5].eType = E_ZCL_UINT8;
                       asPayloadDefinition[5].pvDestination = &psZgpPairingPayload->u8ForwardingRadius;
                   }
                   /* if any one field, security frame counter or security key or assigned address
                    * is not present in payload then forwarding radius field would be at 7th position */
                   else if(u8ItemsInPayload == 7)
                   {
                       asPayloadDefinition[6].eType = E_ZCL_UINT8;
                       asPayloadDefinition[6].pvDestination = &psZgpPairingPayload->u8ForwardingRadius;
                   }
               }
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

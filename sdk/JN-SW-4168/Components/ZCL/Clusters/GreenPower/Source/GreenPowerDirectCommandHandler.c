/*****************************************************************************
 *
 * MODULE:             Green Power Direct command handler
 *
 * COMPONENT:          GreenPowerDirectCommandHandler.c
 *
 * AUTHOR:             Ramakrishna
 *
 * DESCRIPTION:        The handling functions for the Green Power direct commands
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/UnifiedZCL_ZLL102_HA122_Maintenance/Clusters/GreenPower/Source/GreenPowerDirectCommandHandler.c $
 *
 * $Revision: 82092 $
 *
 * $LastChangedBy: nxp29757 $
 *
 * $LastChangedDate: 2016-08-08 10:21:57 +0100 (Mon, 08 Aug 2016) $
 *
 * $Id: GreenPowerDirectCommandHandler.c 82092 2016-08-08 09:21:57Z nxp29757 $
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

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#include <jendefs.h>
#include <string.h>
#include "dlist.h"
#include "zcl.h"
#include "GreenPower.h"
#include "GreenPower_internal.h"
#include "dbg.h"
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifndef TRACE_GP_DEBUG
#define TRACE_GP_DEBUG FALSE
#endif
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
PRIVATE teZCL_Status eGP_GreenPowerDataCmdHandler(
                    ZPS_tsAfEvent               *pZPSevent,
                    tsZCL_EndPointDefinition    *psEndPointDefinition,
                    tsZCL_ClusterInstance       *psClusterInstance);
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

/****************************************************************************
 **
 ** NAME:       eGP_GreenPowerDirectCommandHandler
 **
 ** DESCRIPTION:
 ** Green Power direct command handler
 **
 ** PARAMETERS:                    Name                           Usage
 ** ZPS_tsAfEvent               *pZPSevent                  ZPS event
 ** tsZCL_EndPointDefinition    *psEndPointDefinition       endpoint definition
 ** tsZCL_ClusterInstance       *psClusterInstance          cluster instance
 **
 ** RETURN:
 ** teZCL_Status
 ****************************************************************************/
PUBLIC teZCL_Status eGP_GreenPowerDirectCommandHandler(
                    ZPS_tsAfEvent               *pZPSevent,
                    tsZCL_EndPointDefinition    *psEndPointDefinition,
                    tsZCL_ClusterInstance       *psClusterInstance)
{
    tsGP_GreenPowerCustomData   *psGpCustomDataStructure;
    teZCL_Status                eStatus = E_ZCL_SUCCESS;
    uint8                       u8ZgpdCmdId;

    /* Get Command Id & custom data structure pointer */
    u8ZgpdCmdId = (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u8CommandId;
    psGpCustomDataStructure = (tsGP_GreenPowerCustomData*)psClusterInstance->pvEndPointCustomStructPtr;
    DBG_vPrintf(TRACE_GP_DEBUG, "ZGPD Direct command Id: 0x%02x\n", u8ZgpdCmdId);
    DBG_vPrintf(TRACE_GP_DEBUG, "ZGPD Direct command status: 0x%02x\n", pZPSevent->uEvent.sApsZgpDataIndEvent.u8Status);
    DBG_vPrintf(TRACE_GP_DEBUG, "ZGPD Direct command security Level: %d\n", pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel);
    //DBG_vPrintf(TRACE_GP_DEBUG, "ZGPD Sequence number: %d\r\n",pZPSevent->uEvent.sApsZgpDataIndEvent.u8SeqNum);
    // get EP mutex
    #ifndef COOPERATIVE
        eZCL_GetMutex(psEndPointDefinition);
    #endif


    /* Check Device Mode and Auto Commission Flag Set */
    /* If device in commission mode, Auto commission flag set, packet would be treated
       commission packet */
    if(psGpCustomDataStructure->eGreenPowerDeviceMode &&
            pZPSevent->uEvent.sApsZgpDataIndEvent.bAutoCommissioning)
    {

        /* As device in commission mode, it should broadcast the packet as
           commission notification */
        /* Device should handle also auto commission packet for self */
        eStatus = eGP_GreenPowerAutoCommissionCmdHandler(
                                            pZPSevent,
                                            psEndPointDefinition,
                                            psClusterInstance);
    }
    /* If GP device is commission mode and rxed GP commands related to commission */
    /* When GP sends commission related commands, Auto Commission Flag shall be false */
    else if(psGpCustomDataStructure->eGreenPowerDeviceMode &&
            !pZPSevent->uEvent.sApsZgpDataIndEvent.bAutoCommissioning)
    {
        /* Handle commands based on GP command type */
        switch(u8ZgpdCmdId)
        {
            case E_GP_COMMISSIONING:
            {
                eStatus = eGP_GreenPowerCommissionCmdHandler(
                                        pZPSevent,
                                        psEndPointDefinition,
                                        psClusterInstance);

                break;
            }

            case E_GP_DECOMMISSIONING:
                eStatus = eGP_GreenPowerDeCommissionCmdHandler(
                                        pZPSevent,
                                        psEndPointDefinition,
                                        psClusterInstance);
                break;

            case E_GP_SUCCESS:
                eStatus = eGP_GreenPowerSuccessCmdHandler(
                                        pZPSevent,
                                        psEndPointDefinition,
                                        psClusterInstance);
                break;

            case E_GP_CHANNEL_REQUEST:
            {
                eStatus = eGP_GreenPowerChannelReqCmdHandler(
                                        pZPSevent,
                                        psEndPointDefinition,
                                        psClusterInstance);
                break;
            }

            default:
                /* Unsupported GP Cmd Type */
                eStatus = E_ZCL_FAIL;
                break;
        }
    }
    /* if device is in operating mode then auto commission flag does not matter,
       packet would be treated as data packet */
    else if(psGpCustomDataStructure->eGreenPowerDeviceMode == E_GP_OPERATING_MODE)
    {
        /* Handle commands based on GP command type */
        switch(u8ZgpdCmdId)
        {
            /* In operational mode drop commissioning commands */
            case E_GP_COMMISSIONING:
            case E_GP_DECOMMISSIONING:
            case E_GP_SUCCESS:
            case E_GP_CHANNEL_REQUEST:
                break;

            default:
                /* data GP Cmd Type */
                eStatus = eGP_GreenPowerDataCmdHandler(pZPSevent,
                                                       psEndPointDefinition,
                                                       psClusterInstance);
                if (eStatus != E_ZCL_SUCCESS)
                {
                    DBG_vPrintf(TRACE_GP_DEBUG, "Error: eGP_GreenPowerDataCmdHandler:%d\r\n", eStatus);
                }
                break;
        }
    }

    // release mutex
    #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


    return eStatus;
}

/****************************************************************************
 **
 ** NAME:       eGP_GreenPowerAutoCommissionCmdHandler
 **
 ** DESCRIPTION:
 ** Green Power auto commissioning command handler
 **
 ** PARAMETERS:                    Name                           Usage
 ** ZPS_tsAfEvent               *pZPSevent                  ZPS event
 ** tsZCL_EndPointDefinition    *psEndPointDefinition       endpoint definition
 ** tsZCL_ClusterInstance       *psClusterInstance          cluster instance
 **
 ** RETURN:
 ** teZCL_Status
 ****************************************************************************/
PUBLIC teZCL_Status eGP_GreenPowerAutoCommissionCmdHandler(
                    ZPS_tsAfEvent               *pZPSevent,
                    tsZCL_EndPointDefinition    *psEndPointDefinition,
                    tsZCL_ClusterInstance       *psClusterInstance)
{
    tsGP_GreenPowerCustomData                       *psGpCustomDataStructure;
    tsGP_ZgpDataIndication                          sZgpDataIndication;
    uint8                                    eStatus = E_ZCL_SUCCESS;


#ifdef GP_COMBO_MIN_DEVICE
    uint8                                           u8ZgpdCmdId;
    tsGP_ZgpsSinkTable                              sZgpsSinkTable;
    bool                                            bIsSinkTableEntryPresent = FALSE;
    uint8                                           u8SinkStatus;
    uint32                                          u32SecFrameCounter;
    tsZCL_Address                                   sDestinationAddress;
    uint8                                           b8ZgpsCommModeAttr;
    tsGP_ZgpCommissionIndication                    sZgpCommissionIndication;
    uint8                                           u8SecKeyType = E_GP_NO_KEY;
#endif

#ifdef GP_PROXY_DEVICE
    tsGP_ZgppProxyTable                             sZgppProxyTable;
    bool_t                                          bIsProxyTableEntryPresent = FALSE;
#endif

    /* Get Command Id & custom data structure pointer */
#ifdef GP_COMBO_MIN_DEVICE
    u8ZgpdCmdId = (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u8CommandId;
#endif
    psGpCustomDataStructure = (tsGP_GreenPowerCustomData*)psClusterInstance->pvEndPointCustomStructPtr;

    // get EP mutex
    #ifndef COOPERATIVE
        eZCL_GetMutex(psEndPointDefinition);
    #endif



    // fill in callback event structure
    eZCL_SetCustomCallBackEvent(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent,
                pZPSevent, 0, psEndPointDefinition->u8EndPointNumber);

    /* Check Application Id */
    /* Copy Green Power Device Address */
    if(pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId == GP_APPL_ID_4_BYTE)
    {
        sZgpDataIndication.uZgpdDeviceAddr.u32ZgpdSrcId = pZPSevent->uEvent.sApsZgpDataIndEvent.u32SrcId;
    }
#ifdef GP_IEEE_ADDR_SUPPORT
    else
    {
        sZgpDataIndication.uZgpdDeviceAddr.u64ZgpdIEEEAddr =
            pZPSevent->uEvent.sApsZgpDataIndEvent.uSrcAddress.u64Addr;
    }
#endif
#ifdef GP_COMBO_MIN_DEVICE
    /* Based on device type, check freshness of packet */
    if(psGpCustomDataStructure->eGreenPowerDeviceType == E_GP_ZGP_COMBO_MIN_DEVICE)
    {
        /* Get Green Power communication Mode attribute value */
        eZCL_ReadLocalAttributeValue(
               psEndPointDefinition->u8EndPointNumber,
               GREENPOWER_CLUSTER_ID,
               TRUE,
               FALSE,
               FALSE,
               E_CLD_GP_ATTR_ZGPS_COMMUNICATION_MODE,
               &b8ZgpsCommModeAttr);
        /* clear sink table */
        memset(&sZgpsSinkTable, 0, sizeof(tsGP_ZgpsSinkTable));

        bIsSinkTableEntryPresent = bGP_IsSinkTableEntryPresent(
                    psEndPointDefinition->u8EndPointNumber,
                    (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId,
                    &sZgpDataIndication.uZgpdDeviceAddr,
                    E_GP_SINK_TABLE_GET_ENTRY,
                    &sZgpsSinkTable,
                    (teGP_GreenPowerCommunicationMode)b8ZgpsCommModeAttr);

        /* check sink table entry presented or not for this ZGPD */
        if(bIsSinkTableEntryPresent)
        {
            uint32 u32SeqNoOrCounter;

            if(sZgpsSinkTable.b16Options & GP_SINK_TABLE_SECURITY_USE_MASK)
            {
                  u32SeqNoOrCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u32SecFrameCounter;
            }
            else
            {
                  u32SeqNoOrCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u8SeqNum;
            }

            /* Freshness check */
            if(FALSE == bGP_IsFreshPkt(psEndPointDefinition->u8EndPointNumber,
                                        (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId,
                                        &sZgpsSinkTable.uZgpdDeviceAddr,
                                        psGpCustomDataStructure,
                                        &sZgpsSinkTable,
                                        u32SeqNoOrCounter))
            {
                // release mutex
                #ifndef COOPERATIVE
                    eZCL_ReleaseMutex(psEndPointDefinition);
                #endif


                return eStatus;
            }
        }
    }
#endif

#ifdef GP_PROXY_DEVICE
    /* Based on device type, check freshness of packet */
    if(psGpCustomDataStructure->eGreenPowerDeviceType == E_GP_ZGP_PROXY_DEVICE)
    {
        /* clear sink table */
        memset(&sZgppProxyTable, 0, sizeof(tsGP_ZgppProxyTable));

        bIsProxyTableEntryPresent = bGP_IsProxyTableEntryPresent(
                    psEndPointDefinition->u8EndPointNumber,
                    (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId,
                    &sZgpDataIndication.uZgpdDeviceAddr,
                    E_GP_PROXY_TABLE_GET_ENTRY,
                    &sZgppProxyTable);

        /* check sink table entry presented or not for this ZGPD */
        if(bIsProxyTableEntryPresent)
        {
            uint32 u32SeqNoOrCounter;

            if(sZgppProxyTable.b16Options & GP_PROXY_TABLE_SECURITY_USE_MASK)
            {
                  u32SeqNoOrCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u32SecFrameCounter;
            }
            else
            {
                  u32SeqNoOrCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u8SeqNum;
            }

            /* Freshness check */
            if(FALSE == bGP_IsFreshPkt(psEndPointDefinition->u8EndPointNumber,
                                        (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId,
                                        &sZgppProxyTable.uZgpdDeviceAddr,
                                        psGpCustomDataStructure,
                                        &sZgppProxyTable,
                                        u32SeqNoOrCounter))
            {
                // release mutex
                #ifndef COOPERATIVE
                    eZCL_ReleaseMutex(psEndPointDefinition);
                #endif


                return eStatus;
            }
        }
    }
#endif
    /* Copy payload length */
    sZgpDataIndication.u8PDUSize = (uint8)PDUM_u16APduInstanceGetPayloadSize(pZPSevent->uEvent.sApsZgpDataIndEvent.hAPduInst);

    /* check length */
    if(sZgpDataIndication.u8PDUSize == 0xFF)
    {
        sZgpDataIndication.u8PDUSize = 0x00;
    }

    /* Check Green Power Payload length */
    if(sZgpDataIndication.u8PDUSize > GP_MAX_ZB_CMD_PAYLOAD_LENGTH)
    {
        /* Inform application unsupported payload length as we are buffering packet for delayed transmission */
        psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_CMD_UNSUPPORTED_PAYLOAD_LENGTH;

        /* Give Application Callback for functionality matching */
        psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);
        return E_ZCL_SUCCESS;
    }

    /* Commission Notification should be transmitted between delay dmin and dmax */
    sZgpDataIndication.u8Status = pZPSevent->uEvent.sApsZgpDataIndEvent.u8Status;
    sZgpDataIndication.u8CommandId = pZPSevent->uEvent.sApsZgpDataIndEvent.u8CommandId;
    sZgpDataIndication.u8LinkQuality = pZPSevent->uEvent.sApsZgpDataIndEvent.u8LinkQuality;
    sZgpDataIndication.u2ApplicationId = pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId;
    sZgpDataIndication.u2SecurityKeyType = pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityKeyType;
    sZgpDataIndication.u2SecurityLevel = pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel;
    sZgpDataIndication.bAutoCommissioning = pZPSevent->uEvent.sApsZgpDataIndEvent.bAutoCommissioning;
    sZgpDataIndication.bRxAfterTx = pZPSevent->uEvent.sApsZgpDataIndEvent.bRxAfterTx;
    sZgpDataIndication.u8SeqNum = pZPSevent->uEvent.sApsZgpDataIndEvent.u8SeqNum;
    sZgpDataIndication.u32Mic = pZPSevent->uEvent.sApsZgpDataIndEvent.u32Mic;
    sZgpDataIndication.bTunneledPkt = FALSE;
    /* If no security and security fail security frame counter should carry seq no */
    if(pZPSevent->uEvent.sApsZgpDataIndEvent.u8Status != E_GP_SEC_SUCCESS )
    {
        sZgpDataIndication.u32SecFrameCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u8SeqNum;
    }
    else
    {
        sZgpDataIndication.u32SecFrameCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u32SecFrameCounter;
    }

    /* Copy Payload */
    sZgpDataIndication.pu8Pdu = (uint8*)PDUM_pvAPduInstanceGetPayload(pZPSevent->uEvent.sApsZgpDataIndEvent.hAPduInst);

#ifdef GP_PROXY_DEVICE
    /* If It is Proxy device then check Proxy Table whether any entry is there for this GPD */
    if(psGpCustomDataStructure->eGreenPowerDeviceType == E_GP_ZGP_PROXY_DEVICE)
    {
        /* check entry presetend for this GPD */
        if(bIsProxyTableEntryPresent)
        {
            /* Set InRange flag to 1 */
            sZgppProxyTable.b16Options |= GP_PROXY_TABLE_IN_RANGE_MASK;
        }
        else
        {
            /* Before creating proxy table entry, update proxy table entry info */
            if(pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId == GP_APPL_ID_4_BYTE)
            {
                sZgppProxyTable.b16Options = GP_APPL_ID_4_BYTE;
                sZgppProxyTable.uZgpdDeviceAddr.u32ZgpdSrcId = pZPSevent->uEvent.sApsZgpDataIndEvent.u32SrcId;
            }
#ifdef GP_IEEE_ADDR_SUPPORT
            else
            {
                sZgppProxyTable.b16Options = GP_APPL_ID_8_BYTE;
                sZgppProxyTable.uZgpdDeviceAddr.u64ZgpdIEEEAddr =
                    pZPSevent->uEvent.sApsZgpDataIndEvent.uSrcAddress.u64Addr;
            }
#endif
            sZgppProxyTable.b16Options |= GP_PROXY_TABLE_ENTRY_ACTIVE_MASK; /* Active and Invalid flag */
            sZgppProxyTable.b16Options |= GP_PROXY_TABLE_IN_RANGE_MASK; /* Set InRange flag to 1 */
            sZgppProxyTable.b16Options |= GP_PROXY_TABLE_SEQ_NUM_CAP_MASK; /* Seq Cap flag */

            /* Check Security status */
            if( (pZPSevent->uEvent.sApsZgpDataIndEvent.u8Status == E_GP_SEC_SUCCESS) ||
                (pZPSevent->uEvent.sApsZgpDataIndEvent.u8Status > E_GP_SEC_NO_SECURITY) )
            {
                //uint8 u8ZgpSecKeyType;
                ZPS_tsZgpGpstEntry     *psZgpGpstEntry;
                uint8 u8SecIndex, u8SecKeyType = 0;
                ZPS_tuZgpGreenPowerId uZgpGreenPowerId;

            if(pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId == GP_APPL_ID_4_BYTE)
            {
                uZgpGreenPowerId.u32SrcId = sZgppProxyTable.uZgpdDeviceAddr.u32ZgpdSrcId;
                psZgpGpstEntry = ZPS_psZgpFindGpstEntry(pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId, uZgpGreenPowerId,                                             &u8SecIndex);
            }
#ifdef GP_IEEE_ADDR_SUPPORT
            else
            {
                uZgpGreenPowerId.u64Address = sZgppProxyTable.uZgpdDeviceAddr.u64ZgpdIEEEAddr;
                psZgpGpstEntry = ZPS_psZgpFindGpstEntry(pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId,
                                    uZgpGreenPowerId, &u8SecIndex);
            }
#endif

                /* check pointer */
                if(psZgpGpstEntry)
                {
                    u8SecKeyType = psZgpGpstEntry->u8KeyType;
                }

                sZgppProxyTable.b16Options |= GP_PROXY_TABLE_SECURITY_USE_MASK;
                sZgppProxyTable.b8SecOptions = (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel;
                sZgppProxyTable.b8SecOptions |= (u8SecKeyType << 2);

                /* based on security level, key type to derived */
                /*if(pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel > E_GP_ONE_LSB_FC_SHORT_MIC)
                {
                    u8SecKeyType = (uint8)(0x04 | pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel);
                }
                else
                {
                    u8SecKeyType = (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel;
                }

                sZgppProxyTable.b8SecOptions |= (u8SecKeyType << 2);*/

                /* Get from Shared Security Key Type */
                /* Read Sec Key Type from the attribute */
                /*if(eZCL_ReadLocalAttributeValue(
                        psEndPointDefinition->u8EndPointNumber,
                        GREENPOWER_CLUSTER_ID,
                        TRUE,
                        FALSE,
                        FALSE,
                        E_CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY_TYPE,
                        &u8ZgpSecKeyType) != E_ZCL_SUCCESS)
                {
                    // release mutex
                    #ifndef COOPERATIVE
                        eZCL_ReleaseMutex(psEndPointDefinition);
                    #endif


                    return eStatus;
                }
                else
                {
                    u8SecKeyType = u8ZgpSecKeyType;
                }

                sZgppProxyTable.b8SecOptions |= (u8SecKeyType << 2);*/
            }
        }

        /* Create proxy table for this GPD */
        if((eStatus = eGP_AddProxyTableEntry(
                psEndPointDefinition->u8EndPointNumber,
                            &sZgppProxyTable)) != E_GP_PROXY_TABLE_SUCCESS)
        {
            // release mutex
            #ifndef COOPERATIVE
                eZCL_ReleaseMutex(psEndPointDefinition);
            #endif


            return eStatus;
        }

        /* Buffer the GP commission packet for transmitting GP Commission notification as this broadcat transmission in case of RxAfterTx = FALSE
         * or RxAfterTx = TRUE, it has to wait till gppTunnelingDelay */
        eStatus = eGp_BufferTransmissionPacket(
                            &sZgpDataIndication,
                            E_GP_COMMISSION_NOTIFICATION,
                            psGpCustomDataStructure);

        // release mutex
        #ifndef COOPERATIVE
            eZCL_ReleaseMutex(psEndPointDefinition);
        #endif


        return eStatus;
    }
#endif
    /* check, if the received pkt is protected then check security status */
    if(pZPSevent->uEvent.sApsZgpDataIndEvent.u8Status == E_GP_SEC_SUCCESS ||
            pZPSevent->uEvent.sApsZgpDataIndEvent.u8Status == E_GP_SEC_NO_SECURITY)
    {
        uint8 u8ZgpsSecLevel = E_GP_NO_SECURITY;

        /* Get the Zgps Security level attribute */
        if(eZCL_ReadLocalAttributeValue(
                psEndPointDefinition->u8EndPointNumber,
                GREENPOWER_CLUSTER_ID,
                TRUE,
                FALSE,
                FALSE,
                E_CLD_GP_ATTR_ZGPS_SECURITY_LEVEL,
                &u8ZgpsSecLevel) != E_ZCL_SUCCESS)
        {
            // release mutex
            #ifndef COOPERATIVE
                eZCL_ReleaseMutex(psEndPointDefinition);
            #endif


            return eStatus;
        }
        else
        {
            /* check ZGPD has minimum security support which required by the GP infra device */
            if(u8ZgpsSecLevel > (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel)
            {
                /* Give a callback to user saying that secuity mismatch */
                psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_SECURITY_LEVEL_MISMATCH;
                psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);

                /* drop the packet */
                // release mutex
                #ifndef COOPERATIVE
                    eZCL_ReleaseMutex(psEndPointDefinition);
                #endif


                return eStatus;
            }
        }
    }
    else
    {
        /* Give a callback to user saying that secuity processing failed */
        psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_SECURITY_PROCESSING_FAILED;
        psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);

        /* If security processing failed, then drop the packet */
        // release mutex
        #ifndef COOPERATIVE
            eZCL_ReleaseMutex(psEndPointDefinition);
        #endif


        return eStatus;
    }

#if 0
    /* For combo min devices, not required to act as temp master for commissioning cmd packets */

    /* As this broadcast packet, transmit packet b/w dmin and dmax */
    eStatus = eGp_BufferTransmissionPacket(
                        &sZgpDataIndication,
                        E_GP_COMMISSION_NOTIFICATION,
                        psGpCustomDataStructure);
#endif
#ifdef GP_COMBO_MIN_DEVICE
    /* Give Indication when device is in pairing mode */
    if(psGpCustomDataStructure->eGreenPowerDeviceMode == E_GP_PAIRING_COMMISSION_MODE /*&&
            !psGpCustomDataStructure->bIsCommissionIndGiven*/)
    {
        /* Give a call back to the user as Commission data indication event */
        /* Populate commission data indication event structure */
        sZgpCommissionIndication.eCmdType = E_GP_DATA_CMD_AUTO_COMM;
        sZgpCommissionIndication.eStatus = E_ZCL_SUCCESS; /* Assume Positive status */
        sZgpCommissionIndication.psGpToZclCommandInfo = NULL;
        sZgpCommissionIndication.uCommands.sZgpDataCmd.b8AppId =
                        (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId;

        /* Check Application Id */
        if(sZgpCommissionIndication.uCommands.sZgpDataCmd.b8AppId == GP_APPL_ID_4_BYTE)
        {
            sZgpCommissionIndication.uCommands.sZgpDataCmd.uZgpdDeviceAddr.u32ZgpdSrcId =
                pZPSevent->uEvent.sApsZgpDataIndEvent.u32SrcId;
        }
#ifdef GP_IEEE_ADDR_SUPPORT
        else
        {
            sZgpCommissionIndication.uCommands.sZgpDataCmd.uZgpdDeviceAddr.u64ZgpdIEEEAddr =
                pZPSevent->uEvent.sApsZgpDataIndEvent.uSrcAddress.u64Addr;
        }
#endif

        sZgpCommissionIndication.uCommands.sZgpDataCmd.eZgpdCmdId = u8ZgpdCmdId;
        sZgpCommissionIndication.uCommands.sZgpDataCmd.u8ZgpdCmdPayloadLength =
            (uint8)PDUM_u16APduInstanceGetPayloadSize(pZPSevent->uEvent.sApsZgpDataIndEvent.hAPduInst);
        sZgpCommissionIndication.uCommands.sZgpDataCmd.pu8ZgpdCmdPayload =
            (uint8*)PDUM_pvAPduInstanceGetPayload(pZPSevent->uEvent.sApsZgpDataIndEvent.hAPduInst);

        psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_COMMISSION_DATA_INDICATION;
        psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.uMessage.psZgpCommissionIndication =
                                                                     &sZgpCommissionIndication;

        /* Give Application Callback for functionality matching */
        psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);
    }
    else
    {
        sZgpCommissionIndication.eStatus = E_ZCL_FAIL;
        sZgpCommissionIndication.psGpToZclCommandInfo = NULL;
    }


    /* Check callback event status */
    /* If application sets status success that means functionality matched with rxed zgpd properties */
    /* If device type is combo min and return status is not success we should add to sink table as it is P2 entry */
    /* If status not success, for other devices like combo, target, target plus no need to add the sink table event */
    /****************************************************************/
    /************ In second release this will be updated ************/
    /****************************************************************/
    /*if(sZgpCommissionIndication.eStatus == E_ZCL_SUCCESS || psGpCustomDataStructure.eGreenPowerDeviceType == E_GP_ZGP_COMBO_MIN_DEVICE)
    {

    }*/

    /* check sec status of event indication */
    if(pZPSevent->uEvent.sApsZgpDataIndEvent.u8Status == E_GP_SEC_SUCCESS)
    {
        uint8 u8ZgpSecKeyType;

        sZgpsSinkTable.b16Options |= GP_SINK_TABLE_SECURITY_USE_MASK;

        /* based on security level, key type to derived */
        /*if(pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel > E_GP_ONE_LSB_FC_SHORT_MIC)
        {
            u8SecKeyType = (uint8)(0x04 | pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel);
        }
        else
        {
            u8SecKeyType = (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel;
        }*/

        /* If it is present in sink table */
        if(bIsSinkTableEntryPresent)
        {
            u8SecKeyType = sZgpsSinkTable.b8SecOptions >> 2;
        }
        else
        {
            /* Get from Shared Security Key Type */
            /* Read Sec Key Type from the attribute */
            if(eZCL_ReadLocalAttributeValue(
                    psEndPointDefinition->u8EndPointNumber,
                    GREENPOWER_CLUSTER_ID,
                    TRUE,
                    FALSE,
                    FALSE,
                    E_CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY_TYPE,
                    &u8ZgpSecKeyType) != E_ZCL_SUCCESS)
            {
                // release mutex
                #ifndef COOPERATIVE
                    eZCL_ReleaseMutex(psEndPointDefinition);
                #endif


                return eStatus;
            }

            u8SecKeyType = u8ZgpSecKeyType;

            /* Copy key to Sink Table which is used for security processing */
            /****************************************************************/
            /****************************************************************/
            /**************Will be Done During Integration*******************/
            /****************************************************************/
            /****************************************************************/
        }
        if(pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel == E_GP_ONE_LSB_FC_SHORT_MIC)
        {
            u32SecFrameCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u8SeqNum;
        }
        else
        {
            u32SecFrameCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u32SecFrameCounter;
        }
    }
    else
    {
        u32SecFrameCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u8SeqNum;
    }
    /* If it is not present in sink table */
    if(!bIsSinkTableEntryPresent)
    {
        sZgpsSinkTable.u8GroupCastRadius = GP_GROUPCAST_RADIUS;
    }

    /* Update pairing information in Sink Table */
    u8SinkStatus = eGP_UpdateSinkTable(
                        psEndPointDefinition,
                        psGpCustomDataStructure,
                        &sZgpsSinkTable,
                        sZgpCommissionIndication.psGpToZclCommandInfo,
                        (uint8)sZgpDataIndication.u2ApplicationId,
                        sZgpDataIndication.uZgpdDeviceAddr,
                        (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel,
                        u8SecKeyType,
                        b8ZgpsCommModeAttr,
                        u32SecFrameCounter,
                        sZgpCommissionIndication.eStatus,
                        FALSE,
                        FALSE,
                        FALSE);

#endif
    //pairing success
    if(psGpCustomDataStructure->eGreenPowerDeviceMode == E_GP_REMOTE_COMMISSION_MODE)
    {

         eStatus = eGp_BufferTransmissionPacket(
                        &sZgpDataIndication,
                        E_GP_COMMISSION_NOTIFICATION,
                        psGpCustomDataStructure);

        if(psGpCustomDataStructure->bCommissionExitModeOnFirstPairSuccess)
        {
            psGpCustomDataStructure->bCommissionExitModeOnFirstPairSuccess = FALSE;
            psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_COMMISSION_MODE_EXIT;
			psGpCustomDataStructure->u16CommissionWindow = 0x00;

            /* Change to device mode to operation mode */
            psGpCustomDataStructure->eGreenPowerDeviceMode = E_GP_OPERATING_MODE;
            psGpCustomDataStructure->u64CommissionSetAddress = 0x00;

            /* Call End Point Call back to indicate exit commission mode */
            psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);

        }

        // release mutex
        #ifndef COOPERATIVE
            eZCL_ReleaseMutex(psEndPointDefinition);
        #endif


        return eStatus;
    }
#ifdef GP_COMBO_MIN_DEVICE
    /* Make Device Announce, if entry added to sink table */
    if(u8SinkStatus == E_GP_SINK_TABLE_SUCCESS)
    {
        eStatus = eGP_UpdateApsGroupTableAndDeviceAnnounce(
                    psEndPointDefinition,
                    psGpCustomDataStructure,
                    &sZgpsSinkTable,
                    &sZgpDataIndication,
                    sZgpCommissionIndication.eStatus);

        psGpCustomDataStructure->bIsCommissionIndGiven = TRUE;
    }
    else
    {
        uint8 b8ZgpsCommExitModeAttr;
        /* Get Green Power Exit Mode attribute value */
        eZCL_ReadLocalAttributeValue(
                psEndPointDefinition->u8EndPointNumber,
                GREENPOWER_CLUSTER_ID,
                TRUE,
                FALSE,
                FALSE,
                E_CLD_GP_ATTR_ZGPS_COMMISSIONING_EXIT_MODE,
                &b8ZgpsCommExitModeAttr);

        if(b8ZgpsCommExitModeAttr & GP_CMSNG_EXIT_MODE_ON_PAIRING_SUCCESS_MASK)
        {
            eZCL_SetCustomCallBackEvent(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent, 0, 0, psEndPointDefinition->u8EndPointNumber);

            psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_COMMISSION_MODE_EXIT;
			psGpCustomDataStructure->u16CommissionWindow = 0x00;			

            /* Change to device mode to operation mode */
            psGpCustomDataStructure->eGreenPowerDeviceMode = E_GP_OPERATING_MODE;
            /* Call End Point Call back to indicate exit commission mode */
            psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);
#ifndef GP_DISABLE_PROXY_COMMISSION_MODE_CMD
            /* send proxy commissioning mode command (exit) */
            sDestinationAddress.eAddressMode = E_ZCL_AM_BROADCAST;
            sDestinationAddress.uAddress.eBroadcastMode = ZPS_E_APL_AF_BROADCAST_RX_ON;
            eGP_ProxyCommissioningMode(psEndPointDefinition->u8EndPointNumber,
                                        ZCL_GP_PROXY_ENDPOINT_ID,
                                        sDestinationAddress,
                                        E_GP_PROXY_COMMISSION_EXIT);
#endif
        }
    }
#endif
    // release mutex
    #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


    return eStatus;
}

/****************************************************************************
 **
 ** NAME:       eGP_GreenPowerChannelReqCmdHandler
 **
 ** DESCRIPTION:
 ** Green Power channel Request command handler
 **
 ** PARAMETERS:                    Name                           Usage
 ** ZPS_tsAfEvent               *pZPSevent                  ZPS event
 ** tsZCL_EndPointDefinition    *psEndPointDefinition       endpoint definition
 ** tsZCL_ClusterInstance       *psClusterInstance          cluster instance
 **
 ** RETURN:
 ** teZCL_Status
 ****************************************************************************/
PUBLIC teZCL_Status eGP_GreenPowerChannelReqCmdHandler(
                    ZPS_tsAfEvent               *pZPSevent,
                    tsZCL_EndPointDefinition    *psEndPointDefinition,
                    tsZCL_ClusterInstance       *psClusterInstance)
{
    tsGP_GreenPowerCustomData                       *psGpCustomDataStructure;
    tsGP_ZgpDataIndication                          sZgpDataIndication;
    teZCL_Status                                    eStatus = E_ZCL_SUCCESS;
    psGpCustomDataStructure = (tsGP_GreenPowerCustomData*)psClusterInstance->pvEndPointCustomStructPtr;
    //DBG_vPrintf(TRACE_GP_DEBUG, "\nChannel Request Received\r\n");
    if(psGpCustomDataStructure->u16TransmitChannelTimeout)
    {
        return eStatus;
    }
    // get EP mutex
    #ifndef COOPERATIVE
        eZCL_GetMutex(psEndPointDefinition);
    #endif


    /* If device is proxy then it has to wait upto zgppTunnelDelay ms */
    /* If device is combo min then it has to wait upto Dmax ms */
    /* Check Application Id */
    /* Copy Green Power Device Address */
    if(pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId == GP_APPL_ID_4_BYTE)
    {
        sZgpDataIndication.uZgpdDeviceAddr.u32ZgpdSrcId = pZPSevent->uEvent.sApsZgpDataIndEvent.u32SrcId;
    }
#ifdef GP_IEEE_ADDR_SUPPORT
    else
    {
        sZgpDataIndication.uZgpdDeviceAddr.u64ZgpdIEEEAddr =
            pZPSevent->uEvent.sApsZgpDataIndEvent.uSrcAddress.u64Addr;
    }
#endif

    /* Commission Notification for channel Req should be transmitted after zgppTunneling Delay (b/w Dmin and Dmax)*/
    sZgpDataIndication.u8PDUSize = (uint8)PDUM_u16APduInstanceGetPayloadSize(pZPSevent->uEvent.sApsZgpDataIndEvent.hAPduInst);
    sZgpDataIndication.u8Status = pZPSevent->uEvent.sApsZgpDataIndEvent.u8Status;
    sZgpDataIndication.u8CommandId = pZPSevent->uEvent.sApsZgpDataIndEvent.u8CommandId;
    sZgpDataIndication.u8LinkQuality = pZPSevent->uEvent.sApsZgpDataIndEvent.u8LinkQuality;
    sZgpDataIndication.u2ApplicationId = pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId;
    sZgpDataIndication.u2SecurityKeyType = pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityKeyType;
    sZgpDataIndication.u2SecurityLevel = pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel;
    sZgpDataIndication.bAutoCommissioning = pZPSevent->uEvent.sApsZgpDataIndEvent.bAutoCommissioning;
    sZgpDataIndication.bRxAfterTx = pZPSevent->uEvent.sApsZgpDataIndEvent.bRxAfterTx;
    sZgpDataIndication.u8SeqNum = pZPSevent->uEvent.sApsZgpDataIndEvent.u8SeqNum;
    sZgpDataIndication.u32Mic = pZPSevent->uEvent.sApsZgpDataIndEvent.u32Mic;
    sZgpDataIndication.bTunneledPkt = FALSE;
#ifndef PC_PLATFORM_BUILD
    sZgpDataIndication.u16NwkShortAddr = ZPS_u16AplZdoGetNwkAddr();
#endif

    /* If no security and security fail security frame counter should carry seq no */
    if(pZPSevent->uEvent.sApsZgpDataIndEvent.u8Status != E_GP_SEC_SUCCESS )
    {
        sZgpDataIndication.u32SecFrameCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u8SeqNum;
    }
    else
    {
        sZgpDataIndication.u32SecFrameCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u32SecFrameCounter;
    }

    /* Copy Payload */
    sZgpDataIndication.pu8Pdu = (uint8*)PDUM_pvAPduInstanceGetPayload(pZPSevent->uEvent.sApsZgpDataIndEvent.hAPduInst);

    /* Give a callback to the user, it can act as temp master for channel request command,
     * if user says yes send commission notification otherwise drop the packet */
    // fill in callback event structure
    /* If GP device is proxy, proxy always go into remote commission mode */
    /* Sink device will act as proxy when it goes into remote pairing mode */
#ifdef GP_PROXY_DEVICE
    if(psGpCustomDataStructure->eGreenPowerDeviceMode == E_GP_REMOTE_COMMISSION_MODE)
    {
       eZCL_SetCustomCallBackEvent(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent,
                    pZPSevent, 0, psEndPointDefinition->u8EndPointNumber);

        /* Set Event Type */
       psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_RECEIVED_CHANNEL_REQUEST;

       /* Expecting positive reposne from app and set to act as temp master flag as TRUE */
       psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.uMessage.bIsActAsTempMaster = TRUE;

       /* Give a call back event to app */
       psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);

       /* Check flag */
       if(psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.uMessage.bIsActAsTempMaster)
       {
           /* Buffer this PKT for tunneling commission notification As this broadcast packet, transmit packet after zgppTunneling Delay */
           eStatus = eGp_BufferTransmissionPacket(
                               &sZgpDataIndication,
                               E_GP_COMMISSION_NOTIFICATION,
                               psGpCustomDataStructure);
       }
    }
#endif

#ifdef GP_COMBO_MIN_DEVICE
    /* Buffer this PKT for tunneling ZGP Response, transmit packet after Dmax Delay */
    /* Only for Combo Min device only */
    if(psGpCustomDataStructure->eGreenPowerDeviceType == E_GP_ZGP_COMBO_MIN_DEVICE &&
            psGpCustomDataStructure->eGreenPowerDeviceMode == E_GP_PAIRING_COMMISSION_MODE)
    {
        eStatus = eGp_BufferTransmissionPacket(
                        &sZgpDataIndication,
                        E_GP_RESPONSE,
                        psGpCustomDataStructure);
    }
#endif
    // release mutex
    #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


    return eStatus;
}

/****************************************************************************
 **
 ** NAME:       eGP_GreenPowerCommissionCmdHandler
 **
 ** DESCRIPTION:
 ** Green Power Commission command handler
 **
 ** PARAMETERS:                    Name                           Usage
 ** ZPS_tsAfEvent               *pZPSevent                  ZPS event
 ** tsZCL_EndPointDefinition    *psEndPointDefinition       endpoint definition
 ** tsZCL_ClusterInstance       *psClusterInstance          cluster instance
 **
 ** RETURN:
 ** teZCL_Status
 ****************************************************************************/
PUBLIC teZCL_Status eGP_GreenPowerCommissionCmdHandler(
                    ZPS_tsAfEvent               *pZPSevent,
                    tsZCL_EndPointDefinition    *psEndPointDefinition,
                    tsZCL_ClusterInstance       *psClusterInstance)
{
    tsGP_GreenPowerCustomData                       *psGpCustomDataStructure;
    tsGP_ZgpDataIndication                          sZgpDataIndication;

#ifdef GP_PROXY_DEVICE
    tsGP_ZgppProxyTable                             sZgppProxyTable;
    bool_t                                          bIsProxyTableEntryPresent = FALSE;
#endif
#ifdef GP_COMBO_MIN_DEVICE
    tsGP_ZgpsSinkTable                              sZgpsSinkTable;
    bool_t                                          bIsSinkTableEntryPresent = FALSE;
    tsGP_ZgpCommissionIndication                    sZgpCommissionIndication;
    tsZCL_Address                                   sDestinationAddress;
    uint32                                          u32SecFrameCounter;
    uint8                                           b8ZgpsCommModeAttr, u8SecLevel = E_GP_NO_SECURITY;
    uint8                                          u8SinkStatus;
    //bool_t                                          bIsCommissionIndGiven = FALSE;
    bool_t                                          bIsFixedLocation = FALSE, bIsRxOnCap = FALSE;
    bool_t                                          bIsSeqNumCap;
#endif

#ifdef GP_COMBO_MIN_DEVICE
    uint8                                           u8SecKeyType = E_GP_NO_KEY;
#endif
    uint8                                    eStatus = E_ZCL_SUCCESS;

    psGpCustomDataStructure = (tsGP_GreenPowerCustomData*)psClusterInstance->pvEndPointCustomStructPtr;
    //DBG_vPrintf(TRACE_GP_DEBUG, "\neGP_GreenPowerCommissionCmdHandler\r\n");
    // get EP mutex
    #ifndef COOPERATIVE
        eZCL_GetMutex(psEndPointDefinition);
    #endif


    /* Initialize callback event */
    eZCL_SetCustomCallBackEvent(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent,
                 pZPSevent, 0, psEndPointDefinition->u8EndPointNumber);

    /* Check Application Id */
    /* Copy Green Power Device Address */
    if(pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId == GP_APPL_ID_4_BYTE)
    {
        sZgpDataIndication.uZgpdDeviceAddr.u32ZgpdSrcId = pZPSevent->uEvent.sApsZgpDataIndEvent.u32SrcId;
    }
#ifdef GP_IEEE_ADDR_SUPPORT
    else
    {
        sZgpDataIndication.uZgpdDeviceAddr.u64ZgpdIEEEAddr =
            pZPSevent->uEvent.sApsZgpDataIndEvent.uSrcAddress.u64Addr;
    }
#endif

#ifdef GP_COMBO_MIN_DEVICE
    sZgpCommissionIndication.uCommands.sZgpCommissionCmd.u32ZgpdOutgoingCounter = 0;
    /* Based on device type, check freshness of packet */
    if(psGpCustomDataStructure->eGreenPowerDeviceType == E_GP_ZGP_COMBO_MIN_DEVICE)
    {
        /* Get Green Power communication Mode attribute value */
        eZCL_ReadLocalAttributeValue(psEndPointDefinition->u8EndPointNumber,
                                     GREENPOWER_CLUSTER_ID,
                                     TRUE,
                                     FALSE,
                                     FALSE,
                                     E_CLD_GP_ATTR_ZGPS_COMMUNICATION_MODE,
                                     &b8ZgpsCommModeAttr);

        /* clear sink table */
        memset(&sZgpsSinkTable, 0, sizeof(tsGP_ZgpsSinkTable));

        bIsSinkTableEntryPresent = bGP_IsSinkTableEntryPresent(
                    psEndPointDefinition->u8EndPointNumber,
                    (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId,
                    &sZgpDataIndication.uZgpdDeviceAddr,
                    E_GP_SINK_TABLE_GET_ENTRY,
                    &sZgpsSinkTable,
                    b8ZgpsCommModeAttr);

        /* check sink table entry presented or not for this ZGPD */
        if(bIsSinkTableEntryPresent)
        {
            uint32 u32SeqNoOrCounter;

            if((pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel == E_GP_FULL_FC_FULL_MIC)||
               (pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel == E_GP_ENC_FULL_FC_FULL_MIC))

            {
                  u32SeqNoOrCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u32SecFrameCounter;
            }
            else
            {
                  u32SeqNoOrCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u8SeqNum;
            }

            /* Freshness check */
            if(FALSE == bGP_IsFreshPkt(psEndPointDefinition->u8EndPointNumber,
                                        (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId,
                                        &sZgpsSinkTable.uZgpdDeviceAddr,
                                        psGpCustomDataStructure,
                                        &sZgpsSinkTable,
                                        u32SeqNoOrCounter))
            {
                // release mutex
                #ifndef COOPERATIVE
                    eZCL_ReleaseMutex(psEndPointDefinition);
                #endif

                DBG_vPrintf(TRACE_GP_DEBUG, "bGP_IsFreshPkt fail-1\n");
                return eStatus;
            }
        }
        else
        {
            if((pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel == E_GP_NO_SECURITY)||
               (pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel == E_GP_ONE_LSB_FC_SHORT_MIC))
            {
                sZgpsSinkTable.u32ZgpdSecFrameCounter = (uint32)pZPSevent->uEvent.sApsZgpDataIndEvent.u8SeqNum;
            }
            else
            {
                sZgpsSinkTable.u32ZgpdSecFrameCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u32SecFrameCounter;
            }
        }
    }
#endif

#ifdef GP_PROXY_DEVICE
    /* Based on device type, check freshness of packet */
    if(psGpCustomDataStructure->eGreenPowerDeviceType == E_GP_ZGP_PROXY_DEVICE)
    {
        /* clear sink table */
        memset(&sZgppProxyTable, 0, sizeof(tsGP_ZgppProxyTable));

        bIsProxyTableEntryPresent = bGP_IsProxyTableEntryPresent(
                    psEndPointDefinition->u8EndPointNumber,
                    (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId,
                    &sZgpDataIndication.uZgpdDeviceAddr,
                    E_GP_PROXY_TABLE_GET_ENTRY,
                    &sZgppProxyTable);

        /* check sink table entry presented or not for this ZGPD */
        if(bIsProxyTableEntryPresent)
        {
            uint32 u32SeqNoOrCounter;

            if((pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel == E_GP_FULL_FC_FULL_MIC)||
               (pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel == E_GP_ENC_FULL_FC_FULL_MIC))

            {
                  u32SeqNoOrCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u32SecFrameCounter;
            }
            else
            {
                  u32SeqNoOrCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u8SeqNum;
            }

            /* Freshness check */
            if(FALSE == bGP_IsFreshPkt(psEndPointDefinition->u8EndPointNumber,
                                        (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId,
                                        &sZgppProxyTable.uZgpdDeviceAddr,
                                        psGpCustomDataStructure,
                                        &sZgppProxyTable,
                                        u32SeqNoOrCounter))
            {
                // release mutex
                #ifndef COOPERATIVE
                    eZCL_ReleaseMutex(psEndPointDefinition);
                #endif

                return eStatus;
            }
        }
        else
        {
            if((pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel == E_GP_NO_SECURITY)||
               (pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel == E_GP_ONE_LSB_FC_SHORT_MIC))
            {
                sZgppProxyTable.u32ZgpdSecFrameCounter = (uint32)pZPSevent->uEvent.sApsZgpDataIndEvent.u8SeqNum;
            }
            else
            {
                sZgppProxyTable.u32ZgpdSecFrameCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u32SecFrameCounter;
            }
        }
    }
#endif
    /* If device is proxy then it has to wait upto zgppTunnelDelay ms */
    /* If device is combo min then it has to wait upto Dmax ms */


    /* Commission Notification for channel Req should be transmitted after zgppTunneling Delay (b/w Dmin and Dmax)*/
    sZgpDataIndication.u8PDUSize = (uint8)PDUM_u16APduInstanceGetPayloadSize(pZPSevent->uEvent.sApsZgpDataIndEvent.hAPduInst);
    sZgpDataIndication.u8Status = pZPSevent->uEvent.sApsZgpDataIndEvent.u8Status;
    sZgpDataIndication.u8CommandId = pZPSevent->uEvent.sApsZgpDataIndEvent.u8CommandId;
    sZgpDataIndication.u8LinkQuality = pZPSevent->uEvent.sApsZgpDataIndEvent.u8LinkQuality;
    sZgpDataIndication.u2ApplicationId = pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId;
    sZgpDataIndication.u2SecurityKeyType = pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityKeyType;
    sZgpDataIndication.u2SecurityLevel = pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel;
    sZgpDataIndication.bAutoCommissioning = pZPSevent->uEvent.sApsZgpDataIndEvent.bAutoCommissioning;
    sZgpDataIndication.bRxAfterTx = pZPSevent->uEvent.sApsZgpDataIndEvent.bRxAfterTx;
    sZgpDataIndication.u8SeqNum = pZPSevent->uEvent.sApsZgpDataIndEvent.u8SeqNum;
    sZgpDataIndication.u32Mic = pZPSevent->uEvent.sApsZgpDataIndEvent.u32Mic;
    sZgpDataIndication.bTunneledPkt = FALSE;
#ifndef PC_PLATFORM_BUILD
    sZgpDataIndication.u16NwkShortAddr = ZPS_u16AplZdoGetNwkAddr();
#endif

    /* If no security and security fail security frame counter should carry seq no */
    if(pZPSevent->uEvent.sApsZgpDataIndEvent.u8Status != E_GP_SEC_SUCCESS )
    {
        sZgpDataIndication.u32SecFrameCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u8SeqNum;
    }
    else
    {
        sZgpDataIndication.u32SecFrameCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u32SecFrameCounter;
    }

    /* check length */
    if(sZgpDataIndication.u8PDUSize == 0xFF)
    {
        sZgpDataIndication.u8PDUSize = 0x00;
    }

    /* Check Green Power Payload length */
    if(sZgpDataIndication.u8PDUSize > GP_MAX_ZB_CMD_PAYLOAD_LENGTH)
    {
        /* Inform application unsupported payload length as we are buffering packet for delayed transmission */
        psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_CMD_UNSUPPORTED_PAYLOAD_LENGTH;

        /* Give Application Callback for functionality matching */
        psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);

        // release mutex
        #ifndef COOPERATIVE
            eZCL_ReleaseMutex(psEndPointDefinition);
        #endif


        return E_ZCL_SUCCESS;
    }

    /* Copy Payload */
    sZgpDataIndication.pu8Pdu = (uint8*)PDUM_pvAPduInstanceGetPayload(pZPSevent->uEvent.sApsZgpDataIndEvent.hAPduInst);

#ifdef GP_PROXY_DEVICE
    /* If It is Proxy device then check Proxy Table whether any entry is there for this GPD */
    if(psGpCustomDataStructure->eGreenPowerDeviceType == E_GP_ZGP_PROXY_DEVICE)
    {
        uint8 u8CommissionCmdOptionField = *((uint8*)PDUM_pvAPduInstanceGetPayload(pZPSevent->uEvent.sApsZgpDataIndEvent.hAPduInst) + 1);

        /* check entry presetend for this GPD */
        if(bIsProxyTableEntryPresent)
        {
            /* Set InRange flag to 1 */
            sZgppProxyTable.b16Options |= GP_PROXY_TABLE_IN_RANGE_MASK;
        }
        else
        {
            /* Before creating proxy table entry, update proxy table entry info */
            if(pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId == GP_APPL_ID_4_BYTE)
            {
                sZgppProxyTable.b16Options = GP_APPL_ID_4_BYTE;
                sZgppProxyTable.uZgpdDeviceAddr.u32ZgpdSrcId = pZPSevent->uEvent.sApsZgpDataIndEvent.u32SrcId;
            }
#ifdef GP_IEEE_ADDR_SUPPORT
            else
            {
                sZgppProxyTable.b16Options = GP_APPL_ID_8_BYTE;
                sZgppProxyTable.uZgpdDeviceAddr.u64ZgpdIEEEAddr =
                    pZPSevent->uEvent.sApsZgpDataIndEvent.uSrcAddress.u64Addr;
            }
#endif
            sZgppProxyTable.b16Options |= GP_PROXY_TABLE_ENTRY_ACTIVE_MASK; /* Active and Invalid flag */
            sZgppProxyTable.b16Options |= GP_PROXY_TABLE_IN_RANGE_MASK; /* Set InRange flag to 1 */
            sZgppProxyTable.b16Options |= ((u8CommissionCmdOptionField & GP_COMM_CMD_MAC_SEQ_NUM_CAP_MASK) << 5); /* Seq Cap flag */
            sZgppProxyTable.b16Options |= ((u8CommissionCmdOptionField & GP_COMM_CMD_FIXED_LOCATION_MASK) << 5);  /* Fixed location flag */

            /* Check Security status */
            if( (pZPSevent->uEvent.sApsZgpDataIndEvent.u8Status == E_GP_SEC_SUCCESS) ||
                (pZPSevent->uEvent.sApsZgpDataIndEvent.u8Status > E_GP_SEC_NO_SECURITY) )
            {
                ZPS_tsZgpGpstEntry     *psZgpGpstEntry;
                uint8 u8SecIndex, u8SecKeyType = 0;
                ZPS_tuZgpGreenPowerId uZgpGreenPowerId;

                if(pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId == GP_APPL_ID_4_BYTE)
                {
                    uZgpGreenPowerId.u32SrcId = sZgppProxyTable.uZgpdDeviceAddr.u32ZgpdSrcId;
                    psZgpGpstEntry = ZPS_psZgpFindGpstEntry(pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId, uZgpGreenPowerId,                                             &u8SecIndex);
                }
#ifdef GP_IEEE_ADDR_SUPPORT
                else
                {
                    uZgpGreenPowerId.u64Address = sZgppProxyTable.uZgpdDeviceAddr.u64ZgpdIEEEAddr;
                    psZgpGpstEntry = ZPS_psZgpFindGpstEntry(pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId,
                                        uZgpGreenPowerId, &u8SecIndex);
                }
#endif
                /* check pointer */
                if(psZgpGpstEntry)
                {
                    u8SecKeyType = psZgpGpstEntry->u8KeyType;
                }
                sZgppProxyTable.b16Options |= GP_PROXY_TABLE_SECURITY_USE_MASK;
                sZgppProxyTable.b8SecOptions = (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel;
                sZgppProxyTable.b8SecOptions |= u8SecKeyType << 2;
            }
        }

        /* Create proxy table for this GPD */
        if((eStatus = eGP_AddProxyTableEntry(
                        psEndPointDefinition->u8EndPointNumber,
                        &sZgppProxyTable)) != E_GP_PROXY_TABLE_SUCCESS)
        {
            // release mutex
            #ifndef COOPERATIVE
                eZCL_ReleaseMutex(psEndPointDefinition);
            #endif


            return eStatus;
        }

        /* Buffer the GP commission packet for transmitting GP Commission notification as this broadcat transmission in case of RxAfterTx = FALSE
         * or RxAfterTx = TRUE, it has to wait till gppTunnelingDelay */
        eStatus = eGp_BufferTransmissionPacket(
                            &sZgpDataIndication,
                            E_GP_COMMISSION_NOTIFICATION,
                            psGpCustomDataStructure);

        // release mutex
        #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


        return eStatus;
    }
#endif
#ifdef GP_COMBO_MIN_DEVICE
    /* check, if the received pkt is protected then check security status */
    if(pZPSevent->uEvent.sApsZgpDataIndEvent.u8Status == E_GP_SEC_SUCCESS ||
       pZPSevent->uEvent.sApsZgpDataIndEvent.u8Status == E_GP_SEC_NO_SECURITY)
    {
        uint8 u8ZgpsSecLevel = E_GP_NO_SECURITY;

        /* Get the Zgps Security level attribute */
        if(eZCL_ReadLocalAttributeValue(
                psEndPointDefinition->u8EndPointNumber,
                GREENPOWER_CLUSTER_ID,
                TRUE,
                FALSE,
                FALSE,
                E_CLD_GP_ATTR_ZGPS_SECURITY_LEVEL,
                &u8ZgpsSecLevel) != E_ZCL_SUCCESS)
        {
            // release mutex
            #ifndef COOPERATIVE
                eZCL_ReleaseMutex(psEndPointDefinition);
            #endif


            return eStatus;
        }
        else
        {
            bool_t bIsSecCheckPassed = FALSE;
            uint8 u8ZgpSecKeyType = E_GP_NO_KEY;
            uint8 *pu8Payload = (uint8*)PDUM_pvAPduInstanceGetPayload(pZPSevent->uEvent.sApsZgpDataIndEvent.hAPduInst);

            /* check Seq Key Requested or not */
            if(((*(pu8Payload+1) & GP_COMM_CMD_ZGP_SEC_KEY_REQ_MASK))&&
               (pZPSevent->uEvent.sApsZgpDataIndEvent.bRxAfterTx == FALSE))
            {
                // release mutex
                #ifndef COOPERATIVE
                    eZCL_ReleaseMutex(psEndPointDefinition);
                #endif


                return E_ZCL_SUCCESS;
            }
#ifdef CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY_TYPE
            /* Read Sec Key Type from the attribute */
            if(eZCL_ReadLocalAttributeValue(
                    psEndPointDefinition->u8EndPointNumber,
                    GREENPOWER_CLUSTER_ID,
                    TRUE,
                    FALSE,
                    FALSE,
                    E_CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY_TYPE,
                    &u8ZgpSecKeyType) != E_ZCL_SUCCESS)
            {
                // release mutex
                #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


                return eStatus;
            }
#endif
            /* Parse Extended option field to get Sec Level Capability and Key */
            /* Check Extended Options field present or not */
            if(*(pu8Payload+1) & GP_COMM_CMD_EXT_OPT_FIELD_MASK)
            {
                u8SecLevel = (*(pu8Payload+2) & GP_COMM_CMD_EXT_OPT_SEC_LEVEL_MASK);
                u8SecKeyType = (*(pu8Payload+2) & GP_COMM_CMD_EXT_OPT_KEY_TYPE_MASK) >> 2;

                /* check Sec Key Type */
                if(!u8SecKeyType)
                {
                    u8SecKeyType = u8ZgpSecKeyType;
                }
            }
            else
            {
                /* check Seq Key Requested or not */
                if((*(pu8Payload+1) & GP_COMM_CMD_ZGP_SEC_KEY_REQ_MASK))
                {
                    /* check entry in sink table */
                    if(bIsSinkTableEntryPresent &&
                            pZPSevent->uEvent.sApsZgpDataIndEvent.u8Status == E_GP_SEC_SUCCESS)
                    {
                        u8SecLevel = sZgpsSinkTable.b8SecOptions & GP_SECURITY_LEVEL_MASK;
                        u8SecKeyType = sZgpsSinkTable.b8SecOptions >> 2;
                    }
                    else if(pZPSevent->uEvent.sApsZgpDataIndEvent.u8Status == E_GP_SEC_SUCCESS)
                    {
                        u8SecLevel = (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel;
                        u8SecKeyType = u8ZgpSecKeyType;
                    }
                    else
                    {
                        u8SecLevel = E_GP_ONE_LSB_FC_SHORT_MIC;
                        u8SecKeyType = u8ZgpSecKeyType;
                    }
                }
                else
                {
                    u8SecLevel = E_GP_NO_SECURITY;
                    u8SecKeyType = E_GP_NO_KEY;
                }
            }

             /* ZGPD doesn't support security then no security fields shouldn't present in extended option field */
            if( !(*(pu8Payload+1) & GP_COMM_CMD_EXT_OPT_FIELD_MASK) &&
                (u8ZgpsSecLevel == E_GP_NO_SECURITY) &&
                ((uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel == E_GP_NO_SECURITY) )
            {
                bIsSecCheckPassed = TRUE;
            }
            else if(*(pu8Payload+1) & GP_COMM_CMD_EXT_OPT_FIELD_MASK)
            {
                if( (u8SecLevel >= u8ZgpsSecLevel) &&
                    //(u8ZgpsSecLevel > E_GP_NO_SECURITY) &&
                    ( (u8SecKeyType == E_GP_ZIGBEE_NWK_KEY) ||
                      (u8SecKeyType == E_GP_ZGPD_GROUP_KEY) ||
                      (u8SecKeyType == E_GP_NWK_KEY_DERIVED_ZGPD_GROUP_KEY) ||
                      (u8SecKeyType == E_GP_DERIVED_INDIVIDUAL_ZGPD_KEY) ) &&
                    (*(pu8Payload+2) & GP_COMM_CMD_EXT_OPT_ZGPD_OUT_GOING_COUNTER_MASK) )
                {
                    bIsSecCheckPassed = TRUE;
                }
                else if( (u8SecLevel >= u8ZgpsSecLevel) &&
                        // (u8ZgpsSecLevel > E_GP_NO_SECURITY) &&
                         ( (u8SecKeyType == E_GP_OUT_OF_THE_BOX_ZGPD_KEY) ||
                           (u8SecKeyType == E_GP_DERIVED_INDIVIDUAL_ZGPD_KEY) )&&
                         (*(pu8Payload+2) & GP_COMM_CMD_EXT_OPT_ZGPD_OUT_GOING_COUNTER_MASK) &&
                         (*(pu8Payload+2) & GP_COMM_CMD_EXT_OPT_ZGPD_KEY_PRESENT_MASK) )
                {
                    bIsSecCheckPassed = TRUE;
                    /* check Seq Key Requested or not */
                    if((*(pu8Payload+1) & GP_COMM_CMD_ZGP_SEC_KEY_REQ_MASK))
                    {
                        u8SecKeyType = u8ZgpSecKeyType;
                    }
                    else
                    {
                        /* Copy the Key */
                        if(*(pu8Payload+2) & GP_COMM_CMD_EXT_OPT_ZGPD_KEY_ENC_MASK)
                        {
                            /*Decrypt the key */

#ifdef CLD_GP_ATTR_ZGP_LINK_KEY
                            AESSW_Block_u uNonce, uOutKey, uInKey, uLinkKey ;

                            uint32 /*u32MIC,*/ u32SrcId = 0;
                            uint8 u8Header[4]/*, u8KeyMic[4]*/;
#ifndef PC_PLATFORM_BUILD
                            bool_t bVerified;
                            uint8 i;
#endif
                            uint64 u64Address = 0;
#ifdef GP_IEEE_ADDR_SUPPORT
                            u64Address = pZPSevent->uEvent.sApsZgpDataIndEvent.uSrcAddress.u64Addr;
#endif

                            memcpy(uInKey.au8,pu8Payload+3,E_ZCL_KEY_128_SIZE);

                            // get EP mutex
                            #ifndef COOPERATIVE
        eZCL_GetMutex(psEndPointDefinition);
    #endif

                            /* Get Green Power communication Mode attribute value */
                            eZCL_ReadLocalAttributeValue(
                                    psEndPointDefinition->u8EndPointNumber,
                                    GREENPOWER_CLUSTER_ID,
                                    TRUE,
                                    FALSE,
                                    FALSE,
                                    E_CLD_GP_ATTR_ZGP_LINK_KEY,
                                    (uint8*)&uLinkKey);

                            // release mutex
                            #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif

                            //memcpy(&u32MIC, pu8Payload+3+E_ZCL_KEY_128_SIZE, 4);
                            //u8KeyMic[0] = (uint8)u32MIC;
                            //u8KeyMic[1] = (uint8)(u32MIC >> 8);
                            //u8KeyMic[2] = (uint8)(u32MIC >> 16);
                            //u8KeyMic[3] = (uint8)(u32MIC >> 24);

                            if(pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId == GP_APPL_ID_4_BYTE)
                            {
                                u32SrcId = pZPSevent->uEvent.sApsZgpDataIndEvent.u32SrcId;
                            }
#ifdef GP_IEEE_ADDR_SUPPORT
                            else
                            {
                                u32SrcId = (uint32)u64Address;
                            }
#endif
                            u8Header[0] = (uint8)u32SrcId;
                            u8Header[1] = (uint8)(u32SrcId >> 8);
                            u8Header[2] = (uint8)(u32SrcId >> 16);
                            u8Header[3] = (uint8)(u32SrcId >> 24);

                            if(pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId)
                            {
                                uNonce.au8[0] = (uint8)u64Address;
                                uNonce.au8[1] = (uint8)(u64Address >> 8);
                                uNonce.au8[2] = (uint8)(u64Address >> 16);
                                uNonce.au8[3] = (uint8)(u64Address >> 24);
                                uNonce.au8[4] = (uint8)(u64Address >> 32);
                                uNonce.au8[5] = (uint8)(u64Address >> 40);
                                uNonce.au8[6] = (uint8)(u64Address >> 48);
                                uNonce.au8[7] = (uint8)(u64Address >> 56);
                            }
                            else
                            {
                                memcpy(uNonce.au8,u8Header,4);
                                memcpy(&uNonce.au8[4],u8Header,4);
                            }

                            memcpy(&uNonce.au8[8],u8Header,4);

                            uNonce.au8[12] = 5;
#ifndef PC_PLATFORM_BUILD
                            AESSW_bCCMstar(&uLinkKey,
                                           TRUE,
                                           XCV_REG_AES_SET_MODE_CCM_D,
                                           4,
                                           4,
                                           16,
                                           &uNonce,
                                           u8Header,
                                           uInKey.au8,
                                           uOutKey.au8,
                                           pu8Payload+3+E_ZCL_KEY_128_SIZE,
                                           &bVerified);

                            DBG_vPrintf(TRACE_GP_DEBUG, "Decrypted key:");
                            for(i=0;i<AESSW_BLK_SIZE;i++)
                                DBG_vPrintf(TRACE_GP_DEBUG, " 0x%x,", uOutKey.au8[i]);
                            DBG_vPrintf(TRACE_GP_DEBUG, "\n");
                            if(bVerified == FALSE)
                            {
                                DBG_vPrintf(TRACE_GP_DEBUG, "Decrypted key verified %d",bVerified);
                                /* Give a callback to user saying that secuity processing failed */
                                psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_SECURITY_PROCESSING_FAILED;
                                psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);

                                /* If security processing failed, then drop the packet */
                                // release mutex
                                #ifndef COOPERATIVE
                                    eZCL_ReleaseMutex(psEndPointDefinition);
                                #endif


                                return eStatus;
                            }
#endif
                            memcpy(sZgpsSinkTable.sZgpdKey.au8Key, uOutKey.au8, E_ZCL_KEY_128_SIZE);
#else
                            /* Give a callback to user saying that link key not enabled */
                            psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_LINK_KEY_IS_NOT_ENABLED;
                            psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);

                             /* drop the packet */
                             // release mutex
                            #ifndef COOPERATIVE
                                eZCL_ReleaseMutex(psEndPointDefinition);
                            #endif


                            return eStatus;
#endif
                        }
                        else
                        {
                            memcpy(sZgpsSinkTable.sZgpdKey.au8Key, pu8Payload+3, E_ZCL_KEY_128_SIZE);
                        }
                    }
                }
                else if( (u8SecLevel >= u8ZgpsSecLevel) &&
                         (u8ZgpsSecLevel > E_GP_NO_SECURITY) &&
                         (u8SecKeyType == E_GP_NO_KEY) &&
                         !(*(pu8Payload+2) & GP_COMM_CMD_EXT_OPT_ZGPD_OUT_GOING_COUNTER_MASK) )
                {
                    bIsSecCheckPassed = TRUE;
                }
                else if( (u8SecLevel >= u8ZgpsSecLevel) &&
                         (u8ZgpsSecLevel > E_GP_NO_SECURITY) &&
                         ( ((*(pu8Payload+1) & GP_COMM_CMD_ZGP_SEC_KEY_REQ_MASK) && !(uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.bRxAfterTx) ||
                           ((*(pu8Payload+1) & GP_COMM_CMD_ZGP_SEC_KEY_REQ_MASK) && !u8SecLevel) ) )
                {
                    bIsSecCheckPassed = FALSE;
                }
                else if( (*(pu8Payload+1) & GP_COMM_CMD_EXT_OPT_FIELD_MASK) &&
                         (u8ZgpsSecLevel == E_GP_NO_SECURITY) )
                {
                    bIsSecCheckPassed = FALSE;
                }

                if((pZPSevent->uEvent.sApsZgpDataIndEvent.u8Status == E_GP_SEC_NO_SECURITY)&&
                       (u8ZgpsSecLevel > E_GP_NO_SECURITY) &&
                       (!(*(pu8Payload+2) & GP_COMM_CMD_EXT_OPT_ZGPD_KEY_PRESENT_MASK))&&
                       (!(*(pu8Payload+1) & GP_COMM_CMD_ZGP_SEC_KEY_REQ_MASK)))
                {
                    bIsSecCheckPassed = FALSE;
                }

                if((u8ZgpsSecLevel == E_GP_NO_SECURITY) && (u8SecLevel == E_GP_NO_SECURITY)&&
                   ((uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel == E_GP_NO_SECURITY)&&
                   (!(*(pu8Payload+1) & GP_COMM_CMD_ZGP_SEC_KEY_REQ_MASK)))
                {
                    bIsSecCheckPassed = TRUE;
                }

                if((u8ZgpsSecLevel == E_GP_NO_SECURITY) && (u8SecLevel == E_GP_NO_SECURITY)&&
                   ((uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel == E_GP_NO_SECURITY)&&
                   (*(pu8Payload+1) & GP_COMM_CMD_ZGP_SEC_KEY_REQ_MASK))
                {
                    bIsSecCheckPassed = FALSE;
                }
            }

            /* check ZGPD has minimum security support which required by the GP infra device */
            if(!bIsSecCheckPassed)
            {
                /* Give a callback to user saying that secuity mismatch */
                psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_SECURITY_LEVEL_MISMATCH;
                psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);

                /* drop the packet */
                // release mutex
                #ifndef COOPERATIVE
                    eZCL_ReleaseMutex(psEndPointDefinition);
                #endif


                return eStatus;
            }
#ifdef CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY_TYPE
            /* Check SecKey Type */
            /* check ZGP sec key type, if it is other than OOB key then overwrite the key type */
            if( (u8SecKeyType != E_GP_OUT_OF_THE_BOX_ZGPD_KEY) &&
                (u8ZgpSecKeyType != E_GP_NO_KEY) &&
                 pZPSevent->uEvent.sApsZgpDataIndEvent.bRxAfterTx)
            {
                u8SecKeyType = u8ZgpSecKeyType;
            }
#endif
        }
    }
    else
    {
        /* Give a callback to user saying that secuity processing failed */
        psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_SECURITY_PROCESSING_FAILED;
        psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);

        /* If security processing failed, then drop the packet */
        // release mutex
        #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


        return eStatus;
    }

    /* Give Indication when device is in pairing mode */
    if(psGpCustomDataStructure->eGreenPowerDeviceMode == E_GP_PAIRING_COMMISSION_MODE &&
            !psGpCustomDataStructure->bIsCommissionIndGiven)
    {
        uint8 *pu8Payload = (uint8*)PDUM_pvAPduInstanceGetPayload(pZPSevent->uEvent.sApsZgpDataIndEvent.hAPduInst);

        /* Give a call back to the user as Commission data indication event */
        /* Populate commission data indication event structure */
        sZgpCommissionIndication.eCmdType = E_GP_COMM_CMD;
        sZgpCommissionIndication.eStatus = E_ZCL_SUCCESS; /* Assume Positive status */
        sZgpCommissionIndication.psGpToZclCommandInfo = NULL;
        sZgpCommissionIndication.uCommands.sZgpCommissionCmd.b8AppId =
                        (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId;

        /* Check Application Id */
        if(sZgpCommissionIndication.uCommands.sZgpCommissionCmd.b8AppId == GP_APPL_ID_4_BYTE)
        {
            sZgpCommissionIndication.uCommands.sZgpCommissionCmd.uZgpdDeviceAddr.u32ZgpdSrcId =
                pZPSevent->uEvent.sApsZgpDataIndEvent.u32SrcId;
        }
#ifdef GP_IEEE_ADDR_SUPPORT
        else
        {
            sZgpCommissionIndication.uCommands.sZgpCommissionCmd.uZgpdDeviceAddr.u64ZgpdIEEEAddr =
                pZPSevent->uEvent.sApsZgpDataIndEvent.uSrcAddress.u64Addr;
        }
#endif

        sZgpCommissionIndication.uCommands.sZgpCommissionCmd.eZgpdDeviceId = *pu8Payload;
        sZgpCommissionIndication.uCommands.sZgpCommissionCmd.b8Options = *(pu8Payload + 1);

        /* check extended option field present or not */
        if(sZgpCommissionIndication.uCommands.sZgpCommissionCmd.b8Options & GP_COMM_CMD_EXT_OPT_FIELD_MASK )
        {
            sZgpCommissionIndication.uCommands.sZgpCommissionCmd.b8ExtendedOptions = *(pu8Payload + 2);

            /* check security key present in the commission packet */
            if(sZgpCommissionIndication.uCommands.sZgpCommissionCmd.b8ExtendedOptions & GP_COMM_CMD_EXT_OPT_ZGPD_KEY_PRESENT_MASK)
            {
                /* copy the 16 byte key */
                //memcpy(sZgpCommissionIndication.uCommands.sZgpCommissionCmd.sZgpdKey.au8Key, (pu8Payload+3), E_ZCL_KEY_128_SIZE);
                memcpy(sZgpCommissionIndication.uCommands.sZgpCommissionCmd.sZgpdKey.au8Key, sZgpsSinkTable.sZgpdKey.au8Key, E_ZCL_KEY_128_SIZE);
            }

            /* check MIC present in GP commission command */
            if( (sZgpCommissionIndication.uCommands.sZgpCommissionCmd.b8ExtendedOptions & GP_COMM_CMD_EXT_OPT_ZGPD_KEY_PRESENT_MASK) &&
                (sZgpCommissionIndication.uCommands.sZgpCommissionCmd.b8ExtendedOptions & GP_COMM_CMD_EXT_OPT_ZGPD_KEY_ENC_MASK))
            {
                uint8 *pu8Data = pu8Payload + 19;
#ifdef PC_BUILD
                sZgpCommissionIndication.uCommands.sZgpCommissionCmd.u32ZgpdKeyMic = *((uint32 *)(pu8Payload + 19));
#else
                sZgpCommissionIndication.uCommands.sZgpCommissionCmd.u32ZgpdKeyMic = *pu8Data++;
                sZgpCommissionIndication.uCommands.sZgpCommissionCmd.u32ZgpdKeyMic |= (*pu8Data++) << 8;
                sZgpCommissionIndication.uCommands.sZgpCommissionCmd.u32ZgpdKeyMic |= (*pu8Data++) << 16;
                sZgpCommissionIndication.uCommands.sZgpCommissionCmd.u32ZgpdKeyMic |= (*pu8Data++) << 24;
#endif
            }

            /* check outgoing counter field present or not */
            if(sZgpCommissionIndication.uCommands.sZgpCommissionCmd.b8ExtendedOptions & GP_COMM_CMD_EXT_OPT_ZGPD_OUT_GOING_COUNTER_MASK)
            {
                uint8 *pu8Data = pu8Payload + 19;

                if( (sZgpCommissionIndication.uCommands.sZgpCommissionCmd.b8ExtendedOptions & GP_COMM_CMD_EXT_OPT_ZGPD_KEY_PRESENT_MASK) &&
                    (sZgpCommissionIndication.uCommands.sZgpCommissionCmd.b8ExtendedOptions & GP_COMM_CMD_EXT_OPT_ZGPD_KEY_ENC_MASK))
                {
                    pu8Data = pu8Payload + 23;
                }
                else if(sZgpCommissionIndication.uCommands.sZgpCommissionCmd.b8ExtendedOptions & GP_COMM_CMD_EXT_OPT_ZGPD_KEY_PRESENT_MASK)
                {
                    pu8Data = pu8Payload + 19;
                }
                else
                {
                    pu8Data = pu8Payload + 3;
                }

                sZgpCommissionIndication.uCommands.sZgpCommissionCmd.u32ZgpdOutgoingCounter = *pu8Data++;
                sZgpCommissionIndication.uCommands.sZgpCommissionCmd.u32ZgpdOutgoingCounter |= (*pu8Data++) << 8;
                sZgpCommissionIndication.uCommands.sZgpCommissionCmd.u32ZgpdOutgoingCounter |= (*pu8Data++) << 16;
                sZgpCommissionIndication.uCommands.sZgpCommissionCmd.u32ZgpdOutgoingCounter |= (*pu8Data++) << 24;
            }
        }

        psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_COMMISSION_DATA_INDICATION;
        psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.uMessage.psZgpCommissionIndication =
                                                                     &sZgpCommissionIndication;

        /* Give Application Callback for functionality matching */
        psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);

        /* Set to TRUE as Commission Indication gived to App */
        //bIsCommissionIndGiven = TRUE;
    }
    else
    {
        sZgpCommissionIndication.eStatus = E_ZCL_FAIL;
        sZgpCommissionIndication.psGpToZclCommandInfo = NULL;
    }


    /* Check callback event status */
    /* If application sets status success that means functionality matched with rxed zgpd properties */
    /* If device type is combo min and return status is not success we should add to sink table as it is P2 entry */
    /* If status not success, for other devices like combo, target, target plus no need to add the sink table event */
    /****************************************************************/
    /************ In second release this will be updated ************/
    /****************************************************************/
    /*if(sZgpCommissionIndication.eStatus == E_ZCL_SUCCESS || psGpCustomDataStructure.eGreenPowerDeviceType == E_GP_ZGP_COMBO_MIN_DEVICE)
    {

    }*/

    bIsSeqNumCap = (*((uint8*)PDUM_pvAPduInstanceGetPayload(pZPSevent->uEvent.sApsZgpDataIndEvent.hAPduInst)+1) &
                        GP_COMM_CMD_MAC_SEQ_NUM_CAP_MASK);
    bIsFixedLocation = (*((uint8*)PDUM_pvAPduInstanceGetPayload(pZPSevent->uEvent.sApsZgpDataIndEvent.hAPduInst)+1) &
                        GP_COMM_CMD_FIXED_LOCATION_MASK) >> 6;
    bIsRxOnCap = (*((uint8*)PDUM_pvAPduInstanceGetPayload(pZPSevent->uEvent.sApsZgpDataIndEvent.hAPduInst)+1) &
                        GP_COMM_CMD_RX_ON_CAP_MASK) >> 1;

    /* check sec status of event indication */
    if(pZPSevent->uEvent.sApsZgpDataIndEvent.u8Status == E_GP_SEC_SUCCESS)
    {
        u32SecFrameCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u32SecFrameCounter;
    }
    else
    {
        u32SecFrameCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u8SeqNum;
    }

    if(sZgpCommissionIndication.uCommands.sZgpCommissionCmd.u32ZgpdOutgoingCounter)
    {
        u32SecFrameCounter = sZgpCommissionIndication.uCommands.sZgpCommissionCmd.u32ZgpdOutgoingCounter;
        sZgpDataIndication.u32SecFrameCounter = u32SecFrameCounter;
    }

    if(!psGpCustomDataStructure->bIsCommissionIndGiven)
    {
        /* If it is not present in sink table */
        if(!bIsSinkTableEntryPresent)
        {
            sZgpsSinkTable.u8GroupCastRadius = GP_GROUPCAST_RADIUS;
            //sZgpsSinkTable.eZgpdDeviceId = sZgpCommissionIndication.uCommands.sZgpCommissionCmd.eZgpdDeviceId;
        }
        /* Update pairing information in Sink Table */
        u8SinkStatus = eGP_UpdateSinkTable(
                        psEndPointDefinition,
                        psGpCustomDataStructure,
                        &sZgpsSinkTable,
                        sZgpCommissionIndication.psGpToZclCommandInfo,
                        (uint8)sZgpDataIndication.u2ApplicationId,
                        sZgpDataIndication.uZgpdDeviceAddr,
                        u8SecLevel,
                        u8SecKeyType,
                        b8ZgpsCommModeAttr,
                        u32SecFrameCounter,
                        sZgpCommissionIndication.eStatus,
                        bIsSeqNumCap,
                        bIsRxOnCap,
                        bIsFixedLocation);
    }
    else
    {
        u8SinkStatus = E_GP_SINK_TABLE_SUCCESS;
    }
    //If device is in remote pairing mode then exit the commission mode
    if(psGpCustomDataStructure->eGreenPowerDeviceMode == E_GP_REMOTE_COMMISSION_MODE)
    {
        if(!pZPSevent->uEvent.sApsZgpDataIndEvent.bRxAfterTx)
        {
            eStatus = eGp_BufferTransmissionPacket(
                        &sZgpDataIndication,
                        E_GP_COMMISSION_NOTIFICATION,
                        psGpCustomDataStructure);
        }

        if(psGpCustomDataStructure->bCommissionExitModeOnFirstPairSuccess)
        {
            psGpCustomDataStructure->bCommissionExitModeOnFirstPairSuccess = FALSE;
            psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_COMMISSION_MODE_EXIT;
			psGpCustomDataStructure->u16CommissionWindow = 0x00;			

            /* Change to device mode to operation mode */
            psGpCustomDataStructure->eGreenPowerDeviceMode = E_GP_OPERATING_MODE;
            psGpCustomDataStructure->u64CommissionSetAddress = 0x00;

            /* Call End Point Call back to indicate exit commission mode */
            psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);

        }

        // release mutex
        #ifndef COOPERATIVE
            eZCL_ReleaseMutex(psEndPointDefinition);
        #endif


        return eStatus;
    }

    /* Make Device Announce, if entry added to sink table and device is self pairing mode */
    if(u8SinkStatus == E_GP_SINK_TABLE_SUCCESS)
    {
        /* check RxAfter Flag, if it is TRUE, sink has to send Commission Reply command, it wait for Dmax delay */
        if(pZPSevent->uEvent.sApsZgpDataIndEvent.bRxAfterTx && ((psGpCustomDataStructure->u3CommissionReplySentCount == 0)||
                (psGpCustomDataStructure->u3CommissionReplySentCount == 2)||
                (psGpCustomDataStructure->u3CommissionReplySentCount == 4)))
        {
            eStatus = eGp_BufferTransmissionPacket(
                                &sZgpDataIndication,
                                E_GP_RESPONSE,
                                psGpCustomDataStructure);
        }
        else if(!pZPSevent->uEvent.sApsZgpDataIndEvent.bRxAfterTx)
        {
           eStatus = eGP_UpdateApsGroupTableAndDeviceAnnounce(
                                    psEndPointDefinition,
                                    psGpCustomDataStructure,
                                    &sZgpsSinkTable,
                                    &sZgpDataIndication,
                                    sZgpCommissionIndication.eStatus);
        }

        psGpCustomDataStructure->bIsCommissionIndGiven = TRUE;
        if(psGpCustomDataStructure->u3CommissionReplySentCount < 5)
        {
            psGpCustomDataStructure->u3CommissionReplySentCount++;
        }
    }
    else
    {
        /* Exit The commission mode */
        uint8 b8ZgpsCommExitModeAttr;

        /* Get Green Power Exit Mode attribute value */
        eZCL_ReadLocalAttributeValue(
                psEndPointDefinition->u8EndPointNumber,
                GREENPOWER_CLUSTER_ID,
                TRUE,
                FALSE,
                FALSE,
                E_CLD_GP_ATTR_ZGPS_COMMISSIONING_EXIT_MODE,
                &b8ZgpsCommExitModeAttr);

        if(b8ZgpsCommExitModeAttr & GP_CMSNG_EXIT_MODE_ON_PAIRING_SUCCESS_MASK)
        {
            eZCL_SetCustomCallBackEvent(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent, 0, 0,
                    psEndPointDefinition->u8EndPointNumber);

            psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_COMMISSION_MODE_EXIT;
				psGpCustomDataStructure->u16CommissionWindow = 0x00;			

            /* Change to device mode to operation mode */
            psGpCustomDataStructure->eGreenPowerDeviceMode = E_GP_OPERATING_MODE;
            /* Call End Point Call back to indicate exit commission mode */
            psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);
            /* send proxy commissioning mode command (exit) */
            sDestinationAddress.eAddressMode = E_ZCL_AM_BROADCAST;
            sDestinationAddress.uAddress.eBroadcastMode = ZPS_E_APL_AF_BROADCAST_RX_ON;
#ifndef GP_DISABLE_PROXY_COMMISSION_MODE_CMD
            eGP_ProxyCommissioningMode(psEndPointDefinition->u8EndPointNumber,
                                        ZCL_GP_PROXY_ENDPOINT_ID,
                                        sDestinationAddress,
                                        E_GP_PROXY_COMMISSION_EXIT);
#endif
        }
    }
#endif
    // release mutex
    #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


    return eStatus;
}

/****************************************************************************
 **
 ** NAME:       eGP_GreenPowerDeCommissionCmdHandler
 **
 ** DESCRIPTION:
 ** Green Power De Commission command handler
 **
 ** PARAMETERS:                    Name                           Usage
 ** ZPS_tsAfEvent               *pZPSevent                  ZPS event
 ** tsZCL_EndPointDefinition    *psEndPointDefinition       endpoint definition
 ** tsZCL_ClusterInstance       *psClusterInstance          cluster instance
 **
 ** RETURN:
 ** teZCL_Status
 ****************************************************************************/
PUBLIC teZCL_Status eGP_GreenPowerDeCommissionCmdHandler(
                    ZPS_tsAfEvent               *pZPSevent,
                    tsZCL_EndPointDefinition    *psEndPointDefinition,
                    tsZCL_ClusterInstance       *psClusterInstance)
{
    tsGP_GreenPowerCustomData                       *psGpCustomDataStructure;
    tsGP_ZgpDataIndication                          sZgpDataIndication;
#ifdef GP_PROXY_DEVICE
    tsGP_ZgppProxyTable                             sZgppProxyTable;
    bool_t                                          bIsProxyTableEntryPresent = FALSE;
#endif
#ifdef GP_COMBO_MIN_DEVICE
    tsGP_ZgpsSinkTable                              sZgpsSinkTable;
    bool_t                                          bIsSinkTableEntryPresent = FALSE;
    tsZCL_Address                                   sDestinationAddress;
    tsGP_ZgpPairingCmdPayload                       sZgpPairingPayload;
    tsGP_ZgpPairingConfigCmdPayload                 sZgpPairingConfigPayload;
	tsGP_ZgpDecommissionIndication                  sZgpDecommissionIndication;
#endif

    teZCL_Status                                    eStatus = E_ZCL_SUCCESS;


    sZgpDataIndication.bTunneledPkt = FALSE;
    psGpCustomDataStructure = (tsGP_GreenPowerCustomData*)psClusterInstance->pvEndPointCustomStructPtr;

    // get EP mutex
    #ifndef COOPERATIVE
        eZCL_GetMutex(psEndPointDefinition);
    #endif


    /* Initialize callback event */
    eZCL_SetCustomCallBackEvent(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent,
                 pZPSevent, 0, psEndPointDefinition->u8EndPointNumber);

    /* Handled only device is Pairing Commissioning Mode for combo min devices */
    if(psGpCustomDataStructure->eGreenPowerDeviceType == E_GP_ZGP_COMBO_MIN_DEVICE &&
            psGpCustomDataStructure->eGreenPowerDeviceMode == E_GP_REMOTE_COMMISSION_MODE)
    {
        /* If security processing failed, then drop the packet */
        // release mutex
        #ifndef COOPERATIVE
            eZCL_ReleaseMutex(psEndPointDefinition);
        #endif


        return E_ZCL_SUCCESS;
    }

    /* check, if the received pkt is protected then check security status */
    if(pZPSevent->uEvent.sApsZgpDataIndEvent.u8Status == E_GP_SEC_SUCCESS ||
            pZPSevent->uEvent.sApsZgpDataIndEvent.u8Status == E_GP_SEC_NO_SECURITY)
    {

#ifdef GP_COMBO_MIN_DEVICE
        uint8 u8ZgpsSecLevel = E_GP_NO_SECURITY;

        /* Get the Zgps Security level attribute */
        if(eZCL_ReadLocalAttributeValue(
                psEndPointDefinition->u8EndPointNumber,
                GREENPOWER_CLUSTER_ID,
                TRUE,
                FALSE,
                FALSE,
                E_CLD_GP_ATTR_ZGPS_SECURITY_LEVEL,
                &u8ZgpsSecLevel) != E_ZCL_SUCCESS)
        {
            // release mutex
            #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


            return eStatus;
        }
        else
        {
            /* check ZGPD has minimum security support which required by the GP infra device */
            if(u8ZgpsSecLevel > (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel)
            {
                /* Give a callback to user saying that secuity mismatch */
                psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_SECURITY_LEVEL_MISMATCH;
                psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);

                /* drop the packet */
                // release mutex
                #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


                return eStatus;
            }
        }
#endif
    }
    else
    {
        /* Give a callback to user saying that secuity processing failed */
        psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_SECURITY_PROCESSING_FAILED;
        psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);

        /* If security processing failed, then drop the packet */
        // release mutex
        #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


        return eStatus;
    }

    /* Check Application Id */
    /* Copy Green Power Device Address */
    if(pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId == GP_APPL_ID_4_BYTE)
    {
        sZgpDataIndication.uZgpdDeviceAddr.u32ZgpdSrcId = pZPSevent->uEvent.sApsZgpDataIndEvent.u32SrcId;
    }
#ifdef GP_IEEE_ADDR_SUPPORT
    else
    {
        sZgpDataIndication.uZgpdDeviceAddr.u64ZgpdIEEEAddr =
            pZPSevent->uEvent.sApsZgpDataIndEvent.uSrcAddress.u64Addr;
    }
#endif

#ifdef GP_PROXY_DEVICE
    /* Based on device type, check freshness of packet */
    if(psGpCustomDataStructure->eGreenPowerDeviceType == E_GP_ZGP_PROXY_DEVICE)
    {
        /* clear sink table */
        memset(&sZgppProxyTable, 0, sizeof(tsGP_ZgppProxyTable));

        bIsProxyTableEntryPresent = bGP_IsProxyTableEntryPresent(
                    psEndPointDefinition->u8EndPointNumber,
                    (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId,
                    &sZgpDataIndication.uZgpdDeviceAddr,
                    E_GP_PROXY_TABLE_GET_ENTRY,
                    &sZgppProxyTable);

        //DBG_vPrintf(TRACE_GP_DEBUG, "\nbIsProxyTableEntryPresent: %d\n",bIsProxyTableEntryPresent);
        /* check proxy table entry presented or not for this ZGPD */
        if(bIsProxyTableEntryPresent)
        {
            uint32 u32SeqNoOrCounter;

            if(sZgppProxyTable.b16Options & GP_PROXY_TABLE_SECURITY_USE_MASK)
            {
                  u32SeqNoOrCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u32SecFrameCounter;
            }
            else
            {
                  u32SeqNoOrCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u8SeqNum;
            }

            /* Freshness check */
            if(FALSE == bGP_IsFreshPkt(psEndPointDefinition->u8EndPointNumber,
                                        (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId,
                                        &sZgppProxyTable.uZgpdDeviceAddr,
                                        psGpCustomDataStructure,
                                        &sZgppProxyTable,
                                        u32SeqNoOrCounter))
            {
                // release mutex
                #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif

                DBG_vPrintf(TRACE_GP_DEBUG, "bGP_IsFreshPkt Fail-1\n");
                return eStatus;
            }

            /* Proxy tunnel the packet using broadcast, packet has to be buffered for sending after Dmin */
            /* Commission Notification for channel Req should be transmitted after zgppTunneling Delay (b/w Dmin and Dmax)*/
            sZgpDataIndication.u8PDUSize = (uint8)PDUM_u16APduInstanceGetPayloadSize(pZPSevent->uEvent.sApsZgpDataIndEvent.hAPduInst);
            sZgpDataIndication.u8Status = pZPSevent->uEvent.sApsZgpDataIndEvent.u8Status;
            sZgpDataIndication.u8CommandId = pZPSevent->uEvent.sApsZgpDataIndEvent.u8CommandId;
            sZgpDataIndication.u8LinkQuality = pZPSevent->uEvent.sApsZgpDataIndEvent.u8LinkQuality;
            sZgpDataIndication.u2ApplicationId = pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId;
            sZgpDataIndication.u2SecurityKeyType = pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityKeyType;
            sZgpDataIndication.u2SecurityLevel = pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel;
            sZgpDataIndication.bAutoCommissioning = pZPSevent->uEvent.sApsZgpDataIndEvent.bAutoCommissioning;
            sZgpDataIndication.bRxAfterTx = pZPSevent->uEvent.sApsZgpDataIndEvent.bRxAfterTx;
            sZgpDataIndication.u8SeqNum = pZPSevent->uEvent.sApsZgpDataIndEvent.u8SeqNum;
            sZgpDataIndication.u32Mic = pZPSevent->uEvent.sApsZgpDataIndEvent.u32Mic;

#ifndef PC_PLATFORM_BUILD
            sZgpDataIndication.u16NwkShortAddr = ZPS_u16AplZdoGetNwkAddr();
#endif

            /* If no security and security fail security frame counter should carry seq no */
            if(pZPSevent->uEvent.sApsZgpDataIndEvent.u8Status != E_GP_SEC_SUCCESS )
            {
                sZgpDataIndication.u32SecFrameCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u8SeqNum;
            }
            else
            {
                sZgpDataIndication.u32SecFrameCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u32SecFrameCounter;
            }

            /* check length */
            if(sZgpDataIndication.u8PDUSize == 0xFF)
            {
                sZgpDataIndication.u8PDUSize = 0x00;
            }

            /* Check Green Power Payload length */
            if(sZgpDataIndication.u8PDUSize > GP_MAX_ZB_CMD_PAYLOAD_LENGTH)
            {
                /* Inform application unsupported payload length as we are buffering packet for delayed transmission */
                psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_CMD_UNSUPPORTED_PAYLOAD_LENGTH;

                /* Give Application Callback for functionality matching */
                psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);

                // release mutex
                #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


                return E_ZCL_SUCCESS;
            }

            /* Copy Payload */
            sZgpDataIndication.pu8Pdu = (uint8*)PDUM_pvAPduInstanceGetPayload(pZPSevent->uEvent.sApsZgpDataIndEvent.hAPduInst);

            eStatus = eGp_BufferTransmissionPacket(
                                &sZgpDataIndication,
                                E_GP_COMMISSION_NOTIFICATION,
                                psGpCustomDataStructure);
        }
    }
#endif
#ifdef GP_COMBO_MIN_DEVICE
    /* Based on device type, check freshness of packet */
    if(psGpCustomDataStructure->eGreenPowerDeviceType == E_GP_ZGP_COMBO_MIN_DEVICE)
    {
        uint8 u8TransactionSequenceNumber;
        uint8 b8ZgpsCommModeAttr;
        uint8 b8ZgpsCommExitModeAttr;

        /* Get Green Power communication Mode attribute value */
        eZCL_ReadLocalAttributeValue(
              psEndPointDefinition->u8EndPointNumber,
              GREENPOWER_CLUSTER_ID,
              TRUE,
              FALSE,
              FALSE,
              E_CLD_GP_ATTR_ZGPS_COMMUNICATION_MODE,
              &b8ZgpsCommModeAttr);

        /* clear sink table */
        memset(&sZgpsSinkTable, 0, sizeof(tsGP_ZgpsSinkTable));

        bIsSinkTableEntryPresent = bGP_IsSinkTableEntryPresent(
                    psEndPointDefinition->u8EndPointNumber,
                    (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId,
                    &sZgpDataIndication.uZgpdDeviceAddr,
                    E_GP_SINK_TABLE_GET_ENTRY,
                    &sZgpsSinkTable,
                    b8ZgpsCommModeAttr);
        //DBG_vPrintf(TRACE_GP_DEBUG, "\bIsSinkTableEntryPresent: %d\n",bIsSinkTableEntryPresent);
        /* check sink table entry presented or not for this ZGPD */
        if(bIsSinkTableEntryPresent)
        {
            uint32 u32SeqNoOrCounter;

            if(sZgpsSinkTable.b16Options & GP_SINK_TABLE_SECURITY_USE_MASK)
            {
                  u32SeqNoOrCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u32SecFrameCounter;
            }
            else
            {
                  u32SeqNoOrCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u8SeqNum;
            }

            /* Freshness check */
            if(FALSE == bGP_IsFreshPkt(psEndPointDefinition->u8EndPointNumber,
                                        (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId,
                                        &sZgpsSinkTable.uZgpdDeviceAddr,
                                        psGpCustomDataStructure,
                                        &sZgpsSinkTable,
                                        u32SeqNoOrCounter))
            {
                // release mutex
                #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif

                DBG_vPrintf(TRACE_GP_DEBUG, "bGP_IsFreshPkt Fail-2\n");
                return eStatus;
            }

            /* Give a callback to the application to remove translation table entries for this ZGPD */
            psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_DECOMM_CMD_RCVD;
         
            sZgpDecommissionIndication.uZgpdDeviceAddr  =              sZgpDataIndication.uZgpdDeviceAddr;
            sZgpDecommissionIndication.u8ApplicationId =(uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId;
            

            psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.uMessage.psZgpDecommissionIndication = &sZgpDecommissionIndication;

            /* Give Application Callback for functionality matching */
            psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);

            sDestinationAddress.eAddressMode = E_ZCL_AM_BROADCAST;
            sDestinationAddress.uAddress.eBroadcastMode = ZPS_E_APL_AF_BROADCAST_RX_ON;

            /* Remove Group Table entries at APS level for this ZGPD */
            /* Add to the group only if communication mode is derived or assigned */
            if(((sZgpsSinkTable.b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3) == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_DGROUP_ID)
            {
                /* Add derived group Id */
                uint16  u16DerivedGroupId;
                u16DerivedGroupId = u16GP_DeriveAliasSrcAddr(
                        (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId,
                        sZgpDataIndication.uZgpdDeviceAddr);

                eStatus = ZPS_eAplZdoGroupEndpointRemove(u16DerivedGroupId, ZCL_GP_PROXY_ENDPOINT_ID);
            }
            else if(((sZgpsSinkTable.b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3) == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID)
            {
                /* Find No. of pre-commissioned groups are presented in the list */
                uint8   u8Count;

                for(u8Count = 0; u8Count < sZgpsSinkTable.u8ZgpsGroupListEntries; u8Count++)
                {
                    eStatus = ZPS_eAplZdoGroupEndpointRemove(sZgpsSinkTable.asZgpsGroupList[u8Count].u16SinkGroup, ZCL_GP_PROXY_ENDPOINT_ID);
                }

                sZgpPairingConfigPayload.b16Options = (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId;

                /* Check App Id */
                if((sZgpsSinkTable.b16Options & GP_SINK_TABLE_APP_ID_MASK) == GP_APPL_ID_4_BYTE)
                {
                    sZgpPairingConfigPayload.uZgpdDeviceAddr.u32ZgpdSrcId = sZgpsSinkTable.uZgpdDeviceAddr.u32ZgpdSrcId;
                }
#ifdef GP_IEEE_ADDR_SUPPORT
                else
                {
                    sZgpPairingConfigPayload.uZgpdDeviceAddr.u64ZgpdIEEEAddr = sZgpsSinkTable.uZgpdDeviceAddr.u64ZgpdIEEEAddr;
                }
#endif
                sZgpPairingConfigPayload.u8Actions = E_GP_PAIRING_CONFIG_REMOVE_GPD;
                sZgpPairingConfigPayload.eZgpdDeviceId = sZgpsSinkTable.eZgpdDeviceId;
                sZgpPairingConfigPayload.u8ForwardingRadius = sZgpsSinkTable.u8GroupCastRadius;
                sZgpPairingConfigPayload.u8NumberOfPairedEndpoints = 0xFE;

                /* Send GP Pairing configuration command */
                eGP_ZgpPairingConfigSend(
                        psEndPointDefinition->u8EndPointNumber,
                        ZCL_GP_PROXY_ENDPOINT_ID,
                        &sDestinationAddress,
                        &u8TransactionSequenceNumber,
                        &sZgpPairingConfigPayload);
            }

            /* Send GP Pairing Cmd with Remove GPD field set */
            sZgpPairingPayload.b24Options = (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId;

            /* Check App Id */
            if((sZgpsSinkTable.b16Options & GP_SINK_TABLE_APP_ID_MASK) == GP_APPL_ID_4_BYTE)
            {
                sZgpPairingPayload.uZgpdDeviceAddr.u32ZgpdSrcId = sZgpsSinkTable.uZgpdDeviceAddr.u32ZgpdSrcId;
            }
#ifdef GP_IEEE_ADDR_SUPPORT
            else
            {
                sZgpPairingPayload.uZgpdDeviceAddr.u64ZgpdIEEEAddr = sZgpsSinkTable.uZgpdDeviceAddr.u64ZgpdIEEEAddr;
            }
#endif
            sZgpPairingPayload.b24Options |= GP_PAIRING_REMOVE_GPD_MASK;

            /* Send GP Pairing command as broadcast */
            eGP_ZgpPairingSend(
                        psEndPointDefinition->u8EndPointNumber,
                        ZCL_GP_PROXY_ENDPOINT_ID,
                        &sDestinationAddress,
                        &u8TransactionSequenceNumber,
                        &sZgpPairingPayload);

            /* Remove GPD */
            eGP_RemoveSinkTableEntry(
                    psEndPointDefinition->u8EndPointNumber,
                    &sZgpsSinkTable);


            /* Get Green Power Exit Mode attribute value */
            eZCL_ReadLocalAttributeValue(
                    psEndPointDefinition->u8EndPointNumber,
                    GREENPOWER_CLUSTER_ID,
                    TRUE,
                    FALSE,
                    FALSE,
                    E_CLD_GP_ATTR_ZGPS_COMMISSIONING_EXIT_MODE,
                    &b8ZgpsCommExitModeAttr);

            if(b8ZgpsCommExitModeAttr & GP_CMSNG_EXIT_MODE_ON_PAIRING_SUCCESS_MASK)
            {
                eZCL_SetCustomCallBackEvent(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent, 0, 0,
                        psEndPointDefinition->u8EndPointNumber);

                psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_COMMISSION_MODE_EXIT;
				psGpCustomDataStructure->u16CommissionWindow = 0x00;

                /* Change to device mode to operation mode */
                psGpCustomDataStructure->eGreenPowerDeviceMode = E_GP_OPERATING_MODE;
                /* Call End Point Call back to indicate exit commission mode */
                psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);
                /* send proxy commissioning mode command (exit) */
                sDestinationAddress.eAddressMode = E_ZCL_AM_BROADCAST;
                sDestinationAddress.uAddress.eBroadcastMode = ZPS_E_APL_AF_BROADCAST_RX_ON;
#ifndef GP_DISABLE_PROXY_COMMISSION_MODE_CMD
                eGP_ProxyCommissioningMode(psEndPointDefinition->u8EndPointNumber,
                                            ZCL_GP_PROXY_ENDPOINT_ID,
                                            sDestinationAddress,
                                            E_GP_PROXY_COMMISSION_EXIT);
#endif
            }

        }
    }
#endif
    // release mutex
    #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


    return eStatus;
}

/****************************************************************************
 **
 ** NAME:       eGP_GreenPowerSuccessCmdHandler
 **
 ** DESCRIPTION:
 ** Green Power GP Success command handler
 **
 ** PARAMETERS:                    Name                           Usage
 ** ZPS_tsAfEvent               *pZPSevent                  ZPS event
 ** tsZCL_EndPointDefinition    *psEndPointDefinition       endpoint definition
 ** tsZCL_ClusterInstance       *psClusterInstance          cluster instance
 **
 ** RETURN:
 ** teZCL_Status
 ****************************************************************************/
PUBLIC teZCL_Status eGP_GreenPowerSuccessCmdHandler(
                    ZPS_tsAfEvent                               *pZPSevent,
                    tsZCL_EndPointDefinition                    *psEndPointDefinition,
                    tsZCL_ClusterInstance                       *psClusterInstance)
{
    tsGP_GreenPowerCustomData                       *psGpCustomDataStructure;
    tsGP_ZgpDataIndication                          sZgpDataIndication;
#ifdef GP_PROXY_DEVICE
    tsGP_ZgppProxyTable                             sZgppProxyTable;
    bool_t                                          bIsProxyTableEntryPresent = FALSE;
#endif
#ifdef GP_COMBO_MIN_DEVICE
    tsGP_ZgpsSinkTable                              sZgpsSinkTable;
    bool_t                                          bIsSinkTableEntryPresent = FALSE;
#endif
    teZCL_Status                                    eStatus = E_ZCL_SUCCESS;

    sZgpDataIndication.bTunneledPkt = FALSE;
    psGpCustomDataStructure = (tsGP_GreenPowerCustomData*)psClusterInstance->pvEndPointCustomStructPtr;
    //DBG_vPrintf(TRACE_GP_DEBUG, "eGP_GreenPowerSuccessCmdHandler\r\n");
    // get EP mutex
    #ifndef COOPERATIVE
        eZCL_GetMutex(psEndPointDefinition);
    #endif


    /* Initialize callback event */
    eZCL_SetCustomCallBackEvent(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent,
                 pZPSevent, 0, psEndPointDefinition->u8EndPointNumber);

    /* Check Application Id */
    /* Copy Green Power Device Address */
    if(pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId == GP_APPL_ID_4_BYTE)
    {
        sZgpDataIndication.uZgpdDeviceAddr.u32ZgpdSrcId = pZPSevent->uEvent.sApsZgpDataIndEvent.u32SrcId;
    }
#ifdef GP_IEEE_ADDR_SUPPORT
    else
    {
        sZgpDataIndication.uZgpdDeviceAddr.u64ZgpdIEEEAddr =
            pZPSevent->uEvent.sApsZgpDataIndEvent.uSrcAddress.u64Addr;
    }
#endif

#ifdef GP_COMBO_MIN_DEVICE
    /* Based on device type, check freshness of packet */
    if(psGpCustomDataStructure->eGreenPowerDeviceType == E_GP_ZGP_COMBO_MIN_DEVICE)
    {
        uint8 b8ZgpsCommModeAttr;

        /* Get Green Power communication Mode attribute value */
        eZCL_ReadLocalAttributeValue(
              psEndPointDefinition->u8EndPointNumber,
              GREENPOWER_CLUSTER_ID,
              TRUE,
              FALSE,
              FALSE,
              E_CLD_GP_ATTR_ZGPS_COMMUNICATION_MODE,
              &b8ZgpsCommModeAttr);

        /* clear sink table */
        memset(&sZgpsSinkTable, 0, sizeof(tsGP_ZgpsSinkTable));

        bIsSinkTableEntryPresent = bGP_IsSinkTableEntryPresent(
                    psEndPointDefinition->u8EndPointNumber,
                    (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId,
                    &sZgpDataIndication.uZgpdDeviceAddr,
                    E_GP_SINK_TABLE_GET_ENTRY,
                    &sZgpsSinkTable,
                    b8ZgpsCommModeAttr);

        /* check sink table entry presented or not for this ZGPD */
        if(bIsSinkTableEntryPresent)
        {

            if(pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel == 0)
            {
                sZgpsSinkTable.u32ZgpdSecFrameCounter = (uint32)pZPSevent->uEvent.sApsZgpDataIndEvent.u8SeqNum;
            }
            else
            {
                sZgpsSinkTable.u32ZgpdSecFrameCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u32SecFrameCounter;
            }

            bGP_IsSinkTableEntryPresent(
                                psEndPointDefinition->u8EndPointNumber,
                                (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId,
                                &sZgpDataIndication.uZgpdDeviceAddr,
                                E_GP_SINK_TABLE_SET_ENTRY,
                                &sZgpsSinkTable,
                                b8ZgpsCommModeAttr);
#if 0
            /* Freshness check */
            if(FALSE == bGP_IsFreshPkt(psEndPointDefinition->u8EndPointNumber,
                                        (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId,
                                        &sZgpsSinkTable.uZgpdDeviceAddr,
                                        psGpCustomDataStructure,
                                        &sZgpsSinkTable,
                                        u32SeqNoOrCounter))
            {
                // release mutex
                #ifndef COOPERATIVE
                    eZCL_ReleaseMutex(psEndPointDefinition);
                #endif


                return eStatus;
            }
#endif
        }
    }
#endif

    /* Proxy tunnel the packet using broadcast, packet has to be buffered for sending after Dmin */
    /* Commission Notification for channel Req should be transmitted after zgppTunneling Delay (b/w Dmin and Dmax)*/
    sZgpDataIndication.u8PDUSize = (uint8)PDUM_u16APduInstanceGetPayloadSize(pZPSevent->uEvent.sApsZgpDataIndEvent.hAPduInst);
    sZgpDataIndication.u8Status = pZPSevent->uEvent.sApsZgpDataIndEvent.u8Status;
    sZgpDataIndication.u8CommandId = pZPSevent->uEvent.sApsZgpDataIndEvent.u8CommandId;
    sZgpDataIndication.u8LinkQuality = pZPSevent->uEvent.sApsZgpDataIndEvent.u8LinkQuality;
    sZgpDataIndication.u2ApplicationId = pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId;
    sZgpDataIndication.u2SecurityKeyType = pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityKeyType;
    sZgpDataIndication.u2SecurityLevel = pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel;
    sZgpDataIndication.bAutoCommissioning = pZPSevent->uEvent.sApsZgpDataIndEvent.bAutoCommissioning;
    sZgpDataIndication.bRxAfterTx = pZPSevent->uEvent.sApsZgpDataIndEvent.bRxAfterTx;
    sZgpDataIndication.u8SeqNum = pZPSevent->uEvent.sApsZgpDataIndEvent.u8SeqNum;
    sZgpDataIndication.u32Mic = pZPSevent->uEvent.sApsZgpDataIndEvent.u32Mic;

#ifndef PC_PLATFORM_BUILD
    sZgpDataIndication.u16NwkShortAddr = ZPS_u16AplZdoGetNwkAddr();
#endif

    /* If no security and security fail security frame counter should carry seq no */
    if(pZPSevent->uEvent.sApsZgpDataIndEvent.u8Status != E_GP_SEC_SUCCESS )
    {
        sZgpDataIndication.u32SecFrameCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u8SeqNum;
    }
    else
    {
        sZgpDataIndication.u32SecFrameCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u32SecFrameCounter;
    }

    /* check length */
    if(sZgpDataIndication.u8PDUSize == 0xFF)
    {
        sZgpDataIndication.u8PDUSize = 0x00;
    }

    /* Check Green Power Payload length */
    if(sZgpDataIndication.u8PDUSize > GP_MAX_ZB_CMD_PAYLOAD_LENGTH)
    {
        /* Inform application unsupported payload length as we are buffering packet for delayed transmission */
        psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_CMD_UNSUPPORTED_PAYLOAD_LENGTH;

        /* Give Application Callback for functionality matching */
        psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);

        // release mutex
        #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


        return E_ZCL_SUCCESS;
    }

    /* Copy Payload */
    sZgpDataIndication.pu8Pdu = (uint8*)PDUM_pvAPduInstanceGetPayload(pZPSevent->uEvent.sApsZgpDataIndEvent.hAPduInst);

#ifdef GP_PROXY_DEVICE
    /* Based on device type, check freshness of packet */
    if(psGpCustomDataStructure->eGreenPowerDeviceType == E_GP_ZGP_PROXY_DEVICE)
    {
        /* clear sink table */
        memset(&sZgppProxyTable, 0, sizeof(tsGP_ZgppProxyTable));

        bIsProxyTableEntryPresent = bGP_IsProxyTableEntryPresent(
                    psEndPointDefinition->u8EndPointNumber,
                    (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId,
                    &sZgpDataIndication.uZgpdDeviceAddr,
                    E_GP_PROXY_TABLE_GET_ENTRY,
                    &sZgppProxyTable);

        /* check sink table entry presented or not for this ZGPD */
        if(bIsProxyTableEntryPresent)
        {
            if(pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel == 0)
            {
                sZgppProxyTable.u32ZgpdSecFrameCounter = (uint32)pZPSevent->uEvent.sApsZgpDataIndEvent.u8SeqNum;
            }
            else
            {
                sZgppProxyTable.u32ZgpdSecFrameCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u32SecFrameCounter;
            }

            bGP_IsProxyTableEntryPresent(
                                psEndPointDefinition->u8EndPointNumber,
                                (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId,
                                &sZgpDataIndication.uZgpdDeviceAddr,
                                E_GP_PROXY_TABLE_SET_ENTRY,
                                &sZgppProxyTable);
#if 0
            /* Freshness check */
            if(FALSE == bGP_IsFreshPkt(psEndPointDefinition->u8EndPointNumber,
                                        (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId,
                                        &sZgppProxyTable.uZgpdDeviceAddr,
                                        psGpCustomDataStructure,
                                        &sZgppProxyTable,
                                        u32SeqNoOrCounter))
            {
                // release mutex
                #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


                return eStatus;
            }
#endif
        }

        /* broadcast the as GP Commission Notitification hence buffer the packet */
        eStatus = eGp_BufferTransmissionPacket(
                            &sZgpDataIndication,
                            E_GP_COMMISSION_NOTIFICATION,
                            psGpCustomDataStructure);
    }
#endif

#ifdef GP_COMBO_MIN_DEVICE
    if(psGpCustomDataStructure->eGreenPowerDeviceType == E_GP_ZGP_COMBO_MIN_DEVICE &&
            psGpCustomDataStructure->bIsCommissionReplySent)
    {
        /* Give Indication to the user */
        psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_SUCCESS_CMD_RCVD;

        /* Call End Point Call back to indicate exit commission mode */
        psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);

        eStatus = eGP_UpdateApsGroupTableAndDeviceAnnounce(
                                 psEndPointDefinition,
                                 psGpCustomDataStructure,
                                 &sZgpsSinkTable,
                                 &sZgpDataIndication,
                                 E_ZCL_SUCCESS);
    }
#endif
    // release mutex
    #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


    return eStatus;
}

/****************************************************************************
 **
 ** NAME:       eGP_GreenPowerDataCmdHandler
 **
 ** DESCRIPTION:
 ** Green Power direct data command handler
 **
 ** PARAMETERS:                    Name                           Usage
 ** ZPS_tsAfEvent               *pZPSevent                  ZPS event
 ** tsZCL_EndPointDefinition    *psEndPointDefinition       endpoint definition
 ** tsZCL_ClusterInstance       *psClusterInstance          cluster instance
 **
 ** RETURN:
 ** teZCL_Status
 ****************************************************************************/
PRIVATE teZCL_Status eGP_GreenPowerDataCmdHandler(
                    ZPS_tsAfEvent               *pZPSevent,
                    tsZCL_EndPointDefinition    *psEndPointDefinition,
                    tsZCL_ClusterInstance       *psClusterInstance)
{

    tsGP_GreenPowerCustomData    *psGpCustomDataStructure;
    tuGP_ZgpdDeviceAddr          uZgpdDeviceAddr;

#ifdef GP_PROXY_DEVICE
    tsGP_ZgppProxyTable          sProxyTableEntry;
    bool_t                       bIsProxyTableEntryPresent;
#else
    tsGP_ZgpsSinkTable           sSinkTableEntry;
    bool_t                       bIsSinkTableEntryPresent;
    teGP_GreenPowerCommunicationMode  eCommunicationMode;
#endif

    teZCL_Status                 eStatus = E_ZCL_SUCCESS;
    tsZCL_Address                sDestinationAddress;
    uint8                        u8TransactionSequenceNumber, u8AliasSeqNum, i;
    tsGP_ZgpNotificationCmdPayload    sZgpNotificationPayload;
    uint16                       u16AliasShortAddr, u16SecMask;
    uint32                       u32SeqNoOrCounter;
    uint8                        au8GPCmdpayload[GP_MAX_ZB_CMD_PAYLOAD_LENGTH], u8GroupListEntriesCount;
    tsGP_ZgpsGroupList           asGroupList[GP_MAX_SINK_GROUP_LIST];
    teGP_GreenPowerSecLevel      eSecurityLevel = E_GP_NO_SECURITY;
    teGP_GreenPowerSecKeyType    eSecurityKeyType = E_GP_NO_KEY;

    /* If the GP-DATA.indication Status is not SECURITY_SUCCESS/NO_SECURITY then drop the packet */
    if((pZPSevent->uEvent.sApsZgpDataIndEvent.u8Status != E_GP_SEC_SUCCESS)&&
      (pZPSevent->uEvent.sApsZgpDataIndEvent.u8Status != E_GP_SEC_NO_SECURITY))
    {
        return eStatus;
    }
    /* Get custom data structure pointer */
    psGpCustomDataStructure = (tsGP_GreenPowerCustomData*)psClusterInstance->pvEndPointCustomStructPtr;
    //DBG_vPrintf(TRACE_GP_DEBUG, "eGP_GreenPowerDataCmdHandler\r\n");
    // get EP mutex
    #ifndef COOPERATIVE
        eZCL_GetMutex(psEndPointDefinition);
    #endif

    /* Check Application Id */
    /* Copy Green Power Device Address */
    if(pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId == GP_APPL_ID_4_BYTE)
    {
        uZgpdDeviceAddr.u32ZgpdSrcId = pZPSevent->uEvent.sApsZgpDataIndEvent.u32SrcId;
        sZgpNotificationPayload.b16Options = GP_APPL_ID_4_BYTE;
    }
#ifdef GP_IEEE_ADDR_SUPPORT
    else
    {
        uZgpdDeviceAddr.u64ZgpdIEEEAddr = pZPSevent->uEvent.sApsZgpDataIndEvent.uSrcAddress.u64Addr;
        sZgpNotificationPayload.b16Options = GP_APPL_ID_8_BYTE;
    }
#endif

#ifdef GP_PROXY_DEVICE
    /* clear proxy table */
    memset(&sProxyTableEntry, 0, sizeof(tsGP_ZgppProxyTable));

     /* check proxy table entry presented or not for this ZGPD */

    bIsProxyTableEntryPresent = bGP_IsProxyTableEntryPresent(psEndPointDefinition->u8EndPointNumber,
                                                       (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId,
                                                       &uZgpdDeviceAddr,
                                                       E_GP_PROXY_TABLE_GET_ENTRY,
                                                       &sProxyTableEntry);
    if(bIsProxyTableEntryPresent)
    {
        if((!(sProxyTableEntry.b16Options & GP_PROXY_TABLE_ENTRY_VALID_MASK))||
          (!(sProxyTableEntry.b16Options & GP_PROXY_TABLE_ENTRY_ACTIVE_MASK)))
        {
            bIsProxyTableEntryPresent = FALSE;
        }
    }
    //DBG_vPrintf(TRACE_GP_DEBUG, "bGP_IsProxyTableEntryPresent:%d\r\n", bIsProxyTableEntryPresent);
    if(bIsProxyTableEntryPresent)
    {
        if(sProxyTableEntry.b16Options & GP_PROXY_TABLE_ENTRY_ACTIVE_MASK)
        {
            /* If there is an active Proxy Table entry for this GPD ID with the InRange flag set to 0b0,
             * the Proxy sets the InRange flag to 0b1 */
            if(!(sProxyTableEntry.b16Options & GP_PROXY_TABLE_IN_RANGE_MASK))
            {
                sProxyTableEntry.b16Options |= GP_PROXY_TABLE_IN_RANGE_MASK;
                bGP_IsProxyTableEntryPresent(psEndPointDefinition->u8EndPointNumber,
                                                    (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId,
                                                    &uZgpdDeviceAddr,
                                                    E_GP_PROXY_TABLE_UPDATE_ENTRY_ON_DATA_RECEIVE,
                                                    &sProxyTableEntry);
            }

            if(sProxyTableEntry.b16Options & GP_PROXY_TABLE_ENTRY_VALID_MASK)
            { /*  check the security level */

                if(sProxyTableEntry.b16Options & GP_PROXY_TABLE_SECURITY_USE_MASK)
                {
                    eSecurityLevel = sProxyTableEntry.b8SecOptions & GP_SECURITY_LEVEL_MASK;
                    eSecurityKeyType = (sProxyTableEntry.b8SecOptions & GP_SECURITY_KEY_TYPE_MASK) >> 2;

                    /* check for security level, device commissioned with some security level (>0) but send unprotected command */
                    if(eSecurityLevel != pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel)
                    {
                        return E_ZCL_SUCCESS;
                    }
                }

                /* if SecurityLevel and the SecurityKeyType do not match then drop the packet */
                /*if((pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel != eSecurityLevel)||
                  (pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityKeyType != eSecurityKeyType))
                {

                    // release mutex
                    #ifndef COOPERATIVE
                        eZCL_ReleaseMutex(psEndPointDefinition);
                    #endif


                    return eStatus;
                }*/
            }
        }

        if(sProxyTableEntry.b16Options & GP_PROXY_TABLE_SECURITY_USE_MASK)
        {
             u32SeqNoOrCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u32SecFrameCounter;
        }
        else
        {
            u32SeqNoOrCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u8SeqNum;
        }

       /* Freshness check */
       if(FALSE == bGP_IsFreshPkt(psEndPointDefinition->u8EndPointNumber,
                                   (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId,
                                   &uZgpdDeviceAddr,
                                   psGpCustomDataStructure,
                                   &sProxyTableEntry,
                                   u32SeqNoOrCounter))
       {
     // release mutex
    #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


           return eStatus;
       }

    }
#else
    /* clear sink table */
    memset(&sSinkTableEntry, 0, sizeof(tsGP_ZgpsSinkTable));

    /* check sink table entry presented or not for this ZGPD */

    bIsSinkTableEntryPresent = bGP_IsSinkTableEntryPresent(psEndPointDefinition->u8EndPointNumber,
                                                    (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId,
                                                    &uZgpdDeviceAddr,
                                                    E_GP_SINK_TABLE_GET_ENTRY,
                                                    &sSinkTableEntry,
                                                    E_GP_UNI_FORWARD_ZGP_NOTIFICATION_BY_PROXIES_BOTH);

    if(bIsSinkTableEntryPresent == FALSE)
    {
        bIsSinkTableEntryPresent = bGP_IsSinkTableEntryPresent(psEndPointDefinition->u8EndPointNumber,
                                                (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId,
                                                &uZgpdDeviceAddr,
                                                E_GP_SINK_TABLE_GET_ENTRY,
                                                &sSinkTableEntry,
                                                E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_DGROUP_ID);
    }

    if(bIsSinkTableEntryPresent == FALSE)
    {
        bIsSinkTableEntryPresent = bGP_IsSinkTableEntryPresent(psEndPointDefinition->u8EndPointNumber,
                                                (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId,
                                                  &uZgpdDeviceAddr,
                                                  E_GP_SINK_TABLE_GET_ENTRY,
                                                  &sSinkTableEntry,
                                                  E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID);
    }

    if(bIsSinkTableEntryPresent)
    {
        if(sSinkTableEntry.b16Options & GP_SINK_TABLE_SECURITY_USE_MASK)
        {
              u32SeqNoOrCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u32SecFrameCounter;
              eSecurityLevel = sSinkTableEntry.b8SecOptions & GP_SECURITY_LEVEL_MASK;
              eSecurityKeyType = (sSinkTableEntry.b8SecOptions & GP_SECURITY_KEY_TYPE_MASK) >> 2;

              /* check for security level, device commissioned with some security level (>0) but send unprotected command */
              if(eSecurityLevel != pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel)
              {
                  return E_ZCL_SUCCESS;
              }
        }
        else
        {
              u32SeqNoOrCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u8SeqNum;
        }

        /* security Check
         * (pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel != eSecurityLevel)||
           (pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityKeyType != eSecurityKeyType)||
         */
        /* Freshness check */
        if(FALSE == bGP_IsFreshPkt(psEndPointDefinition->u8EndPointNumber,
                                    (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId,
                                    &uZgpdDeviceAddr,
                                    psGpCustomDataStructure,
                                    &sSinkTableEntry,
                                    u32SeqNoOrCounter))
        {
            // release mutex
            #ifndef COOPERATIVE
                eZCL_ReleaseMutex(psEndPointDefinition);
            #endif


            return eStatus;
        }
        /* if ZGPD is in range , its priority in the sink table should be 2*/
        if(sSinkTableEntry.eGreenPowerSinkTablePriority == E_GP_SINK_TABLE_P_3)
        {
            sSinkTableEntry.eGreenPowerSinkTablePriority = E_GP_SINK_TABLE_P_2;
            bGP_IsSinkTableEntryPresent(psEndPointDefinition->u8EndPointNumber,
                                        (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId,
                                        &uZgpdDeviceAddr,
                                        E_GP_SINK_TABLE_SET_ENTRY,
                                        &sSinkTableEntry,
                                        (teGP_GreenPowerCommunicationMode)((sSinkTableEntry.b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3));
        }

        if(eGP_GPDFHandler( pZPSevent,
                            psEndPointDefinition,
                            psGpCustomDataStructure,
                            (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId,
                            &uZgpdDeviceAddr,
                            (teGP_ZgpdCommandId)pZPSevent->uEvent.sApsZgpDataIndEvent.u8CommandId,
                            (uint8)PDUM_u16APduInstanceGetPayloadSize(pZPSevent->uEvent.sApsZgpDataIndEvent.hAPduInst),
                            (uint8*)PDUM_pvAPduInstanceGetPayload(pZPSevent->uEvent.sApsZgpDataIndEvent.hAPduInst)) == E_ZCL_SUCCESS)
        {
            /* if device has translation entry for this ZGPD and paired, its priority in the
               sink table should be 1*/
            if((sSinkTableEntry.eGreenPowerSinkTablePriority == E_GP_SINK_TABLE_P_2)||
               (sSinkTableEntry.eGreenPowerSinkTablePriority == E_GP_SINK_TABLE_P_3))
            {
                sSinkTableEntry.eGreenPowerSinkTablePriority = E_GP_SINK_TABLE_P_1;
                bGP_IsSinkTableEntryPresent(psEndPointDefinition->u8EndPointNumber,
                                            (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId,
                                            &uZgpdDeviceAddr,
                                            E_GP_SINK_TABLE_SET_ENTRY,
                                            &sSinkTableEntry,
                                            (teGP_GreenPowerCommunicationMode)((sSinkTableEntry.b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3));
            }
        }
    }
#endif
#ifdef GP_PROXY_DEVICE
    if(bIsProxyTableEntryPresent)
#else
     if(bIsSinkTableEntryPresent)
#endif
     {
        /* If the ZGPD command was received directly in ZGP-DATA.indication, and the ZGPCm has a
         * entry in its Sink Table for the ZGPD then ZGPCm will construct and send a ZGP Notification
         * command for each of the paired groups */

        sZgpNotificationPayload.uZgpdDeviceAddr = uZgpdDeviceAddr;
        sZgpNotificationPayload.eZgpdCmdId = pZPSevent->uEvent.sApsZgpDataIndEvent.u8CommandId;
        sZgpNotificationPayload.sZgpdCommandPayload.u8MaxLength =
            (uint8)PDUM_u16APduInstanceGetPayloadSize(pZPSevent->uEvent.sApsZgpDataIndEvent.hAPduInst);
        sZgpNotificationPayload.sZgpdCommandPayload.u8Length =
            (uint8)PDUM_u16APduInstanceGetPayloadSize(pZPSevent->uEvent.sApsZgpDataIndEvent.hAPduInst);
           sZgpNotificationPayload.sZgpdCommandPayload.pu8Data = au8GPCmdpayload;
        /* Copy Payload */
        if(sZgpNotificationPayload.sZgpdCommandPayload.u8Length)
        {
            memcpy(au8GPCmdpayload,
                    (uint8*)PDUM_pvAPduInstanceGetPayload(pZPSevent->uEvent.sApsZgpDataIndEvent.hAPduInst),
                    sZgpNotificationPayload.sZgpdCommandPayload.u8Length);
        }

        /* Check RxAfter Flag of ZGP data indication */
        if(pZPSevent->uEvent.sApsZgpDataIndEvent.bRxAfterTx)
        {
            /****************************************************************/
            /************ In second release this will be updated ************/
            /****************************************************************/
            sZgpNotificationPayload.b16Options |= GP_NOTIFICATION_APPOINT_TEMP_MASTER_MASK;
#ifndef PC_PLATFORM_BUILD
            sZgpNotificationPayload.u16ZgppShortAddr = ZPS_u16AplZdoGetNwkAddr();
#endif
            sZgpNotificationPayload.i8ZgppDistance = i8GP_GetProxyDistance((uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u8LinkQuality);
        }

        /* Set Security Level */
        u16SecMask = (uint16)(eSecurityLevel << 6);
        sZgpNotificationPayload.b16Options |= u16SecMask;

        /* Set Key type */
        u16SecMask = 0;
        u16SecMask = (uint16)(eSecurityKeyType << 8);
        sZgpNotificationPayload.b16Options |= u16SecMask;

        /* Set the Security Frame Counter */
        if(eSecurityLevel == E_GP_NO_SECURITY)
        {
            sZgpNotificationPayload.u32ZgpdSecFrameCounter =
                                        (uint32)pZPSevent->uEvent.sApsZgpDataIndEvent.u8SeqNum;
        }
        else
        {
            sZgpNotificationPayload.u32ZgpdSecFrameCounter =
                                        pZPSevent->uEvent.sApsZgpDataIndEvent.u32SecFrameCounter;
        }
#ifdef GP_PROXY_DEVICE
        if(sProxyTableEntry.b16Options & GP_PROXY_TABLE_DERIVED_GROUP_GPS_MASK)
#else
        /* Get communication mode */
        eCommunicationMode = (sSinkTableEntry.b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3;

        if(eCommunicationMode == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_DGROUP_ID)
#endif
        {
            sZgpNotificationPayload.b16Options |= GP_NOTIFICATION_ALSO_DERIVED_GROUP_MASK;
#ifdef GP_PROXY_DEVICE
            if(sProxyTableEntry.b16Options & GP_PROXY_TABLE_COMMISSION_GROUP_GPS_MASK)
            {
                sZgpNotificationPayload.b16Options |= GP_NOTIFICATION_ALSO_COMMISSION_GROUP_MASK;
            }
#endif
            sDestinationAddress.eAddressMode = E_ZCL_AM_GROUP;
            sDestinationAddress.uAddress.u16GroupAddress = u16GP_DeriveAliasSrcAddr(
                                                                (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId,
                                                                uZgpdDeviceAddr);
#ifdef GP_PROXY_DEVICE
            /* Update group cast radius in custom data structure which will be used for transmission */
            psGpCustomDataStructure->u8GroupCastRadius = sProxyTableEntry.u8GroupCastRadius;

           if(sProxyTableEntry.b16Options & GP_PROXY_TABLE_ASSIGNED_ALIAS_MASK)
           {
               u16AliasShortAddr = sProxyTableEntry.u16ZgpdAssignedAlias;
           }
#else
           /* Update group cast radius in custom data structure which will be used for transmission */
           psGpCustomDataStructure->u8GroupCastRadius = sSinkTableEntry.u8GroupCastRadius;

           if(sSinkTableEntry.b16Options & GP_SINK_TABLE_ASSIGNED_ADDR_MASK)
           {
               u16AliasShortAddr = sSinkTableEntry.u16ZgpdAssignedAlias;
           }
#endif
           else
           {
               u16AliasShortAddr = sDestinationAddress.uAddress.u16GroupAddress ;
           }
           /* get alias sequence number */
           u8AliasSeqNum = u8GP_DeriveAliasSeqNum(pZPSevent->uEvent.sApsZgpDataIndEvent.u8SeqNum,
                                                  E_GP_ZGP_NOTIFICATION,
                                                  E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_DGROUP_ID);

           /* set alias short address and alias sequence number in stack before sending the notification command */
           ZPS_vAfSetZgpAlias(u16AliasShortAddr, u8AliasSeqNum);

           eStatus = eGP_ZgpNotificationSend(
                               psEndPointDefinition->u8EndPointNumber,
                               ZCL_GP_PROXY_ENDPOINT_ID,
                               &sDestinationAddress,
                               &u8TransactionSequenceNumber,
                               &sZgpNotificationPayload);
        }
#ifdef GP_PROXY_DEVICE
        if(sProxyTableEntry.b16Options & GP_PROXY_TABLE_COMMISSION_GROUP_GPS_MASK)
#else
        if(eCommunicationMode == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID)
#endif
        {
            sZgpNotificationPayload.b16Options |= GP_NOTIFICATION_ALSO_COMMISSION_GROUP_MASK;
            sDestinationAddress.eAddressMode = E_ZCL_AM_GROUP;

            /* get alias sequence number */
            u8AliasSeqNum = u8GP_DeriveAliasSeqNum(pZPSevent->uEvent.sApsZgpDataIndEvent.u8SeqNum,
                                                     E_GP_ZGP_NOTIFICATION,
                                                     E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID);
#ifdef GP_PROXY_DEVICE
            /* Update group cast radius in custom data structure which will be used for transmission */
            psGpCustomDataStructure->u8GroupCastRadius = sProxyTableEntry.u8GroupCastRadius;
            u8GroupListEntriesCount = sProxyTableEntry.u8SinkGroupListEntries;
            memcpy(asGroupList,sProxyTableEntry.asSinkGroupList,u8GroupListEntriesCount*sizeof(tsGP_ZgpsGroupList));
#else
            /* Update group cast radius in custom data structure which will be used for transmission */
            psGpCustomDataStructure->u8GroupCastRadius = sSinkTableEntry.u8GroupCastRadius;
            u8GroupListEntriesCount = sSinkTableEntry.u8ZgpsGroupListEntries;
            memcpy(asGroupList,sSinkTableEntry.asZgpsGroupList,u8GroupListEntriesCount*sizeof(tsGP_ZgpsGroupList));
#endif

            for(i = 0; i < u8GroupListEntriesCount; i++)
            {
                sDestinationAddress.uAddress.u16GroupAddress = asGroupList[i].u16SinkGroup;

                if(asGroupList[i].u16Alias != 0xFFFF )
                {
                    u16AliasShortAddr = asGroupList[i].u16Alias;
                }
                else
                {
                    u16AliasShortAddr = u16GP_DeriveAliasSrcAddr(
                               (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId,
                               uZgpdDeviceAddr);
                }

                /* set alias short address and alias sequence number in stack before sending the notification command */
                ZPS_vAfSetZgpAlias(u16AliasShortAddr, u8AliasSeqNum);

                eStatus = eGP_ZgpNotificationSend(
                                       psEndPointDefinition->u8EndPointNumber,
                                       ZCL_GP_PROXY_ENDPOINT_ID,
                                       &sDestinationAddress,
                                       &u8TransactionSequenceNumber,
                                       &sZgpNotificationPayload);

            }
        }
        else
        {
            /* unicast */
        }
     }
    // release mutex
    #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


    return eStatus;
}

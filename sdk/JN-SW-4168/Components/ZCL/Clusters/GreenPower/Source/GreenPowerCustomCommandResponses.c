/****************************************************************************
 *
 * MODULE:             ZGP custom command handler functions
 *
 * COMPONENT:          GreenPowerCustomCommandResponses.c
 *
 * AUTHOR:             Ramakrishna
 *
 * DESCRIPTION:        ZGP custom command handler functions
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/UnifiedZCL_ZLL102_HA122_Maintenance/Clusters/GreenPower/Source/GreenPowerCustomCommandResponses.c $
 *
 * $Revision: 88181 $
 *
 * $LastChangedBy: nxp29741 $
 *
 * $LastChangedDate: 2017-05-08 11:35:51 +0100 (Mon, 08 May 2017) $
 *
 * $Id: GreenPowerCustomCommandResponses.c 88181 2017-05-08 10:35:51Z nxp29741 $
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
#include <string.h>
#include "zcl.h"
#include "zcl_customcommand.h"
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

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        Public Functions                                              ***/
/****************************************************************************/
#ifndef GP_DISABLE_PROXY_COMMISSION_MODE_CMD
/****************************************************************************
 **
 ** NAME:       eGP_HandleProxyCommissioningMode
 **
 ** DESCRIPTION:
 ** Handles Green power Cluster proxy commissioning mode command
 **
 ** PARAMETERS:               Name                      Usage
 ** ZPS_tsAfEvent            *pZPSevent                 Zigbee stack event structure
 ** tsZCL_EndPointDefinition *psEndPointDefinition      EP structure
 ** tsZCL_ClusterInstance    *psClusterInstance         Cluster structure
 ** uint16                    u16Offset                 offset
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/

PUBLIC teZCL_Status eGP_HandleProxyCommissioningMode(
                    ZPS_tsAfEvent                  *pZPSevent,
                    tsZCL_EndPointDefinition       *psEndPointDefinition,
                    tsZCL_ClusterInstance          *psClusterInstance,
                    uint16                         u16Offset)
{
    tsGP_GreenPowerCustomData                   *psGPCustomDataStructure;
    tsGP_ZgpProxyCommissioningModeCmdPayload    sZgpProxyCommissioningModeCmdPayload;
    teZCL_Status                                eStatus = E_ZCL_SUCCESS;
    tsZCL_Address                               sDestAddress = {E_ZCL_AM_SHORT,  {pZPSevent->uEvent.sApsDataIndEvent.uSrcAddress.u16Addr}};
    uint64                                      u64RemoteIeeeAddress = 0;

    // initialise pointer
    psGPCustomDataStructure = (tsGP_GreenPowerCustomData *)psClusterInstance->pvEndPointCustomStructPtr;
    DBG_vPrintf(TRACE_GP_DEBUG, "\n eGP_HandleProxyCommissioningMode \n");
    // get EP mutex
    #ifndef COOPERATIVE
        eZCL_GetMutex(psEndPointDefinition);
    #endif


    // fill in callback event structure
    eZCL_SetCustomCallBackEvent(&psGPCustomDataStructure->sGPCommon.sGPCustomCallBackEvent,
                pZPSevent, 0, psEndPointDefinition->u8EndPointNumber);

    // get information
    if((eStatus = eGP_ProxyCommissioningModeReceive(
                                    pZPSevent,
                                    u16Offset,
                                    &sZgpProxyCommissioningModeCmdPayload)) != E_ZCL_SUCCESS)
    {
        // release mutex
        #ifndef COOPERATIVE
            eZCL_ReleaseMutex(psEndPointDefinition);
        #endif


        return eStatus;
    }

#ifndef PC_PLATFORM_BUILD
    /* Check for IEEE address and device will go into commission mode only if
     * finds the IEEE address in any of ZPS tables */
    u64RemoteIeeeAddress = ZPS_u64NwkNibFindExtAddr(ZPS_pvNwkGetHandle(),
                                sDestAddress.uAddress.u16DestinationAddress);

    /* If IEEE address is not present then return */
    if(!u64RemoteIeeeAddress)
    {
        DBG_vPrintf(TRACE_GP_DEBUG, "\n eGP_HandleProxyCommissioningMode- IEEE not available \n");
        // release mutex
        #ifndef COOPERATIVE
            eZCL_ReleaseMutex(psEndPointDefinition);
        #endif


        return E_ZCL_FAIL;
    }
#endif

    /* Check device mode and action field of proxy commission mode command */
    /* Device address matched to device that put in commission mode */
    if(psGPCustomDataStructure->eGreenPowerDeviceMode &&
            psGPCustomDataStructure->u64CommissionSetAddress == u64RemoteIeeeAddress &&
            !(sZgpProxyCommissioningModeCmdPayload.b8Options & GP_PROXY_CMSNG_MODE_ACTION_FIELD_MASK))
    {

        psGPCustomDataStructure->eGreenPowerDeviceMode = E_GP_OPERATING_MODE;
        psGPCustomDataStructure->u64CommissionSetAddress = 0x00;

        /* Set Event Type */
        psGPCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_COMMISSION_MODE_EXIT;
		psGPCustomDataStructure->u16CommissionWindow = 0x00;

        /* Call End Point Callback event informing that device exiting commissioning */
        psEndPointDefinition->pCallBackFunctions(&psGPCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);
    }
    else if(psGPCustomDataStructure->eGreenPowerDeviceMode == E_GP_OPERATING_MODE &&
           ( sZgpProxyCommissioningModeCmdPayload.b8Options & GP_PROXY_CMSNG_MODE_ACTION_FIELD_MASK))
    {
        /* Set device mode to Remote commission mode */
        psGPCustomDataStructure->eGreenPowerDeviceMode = E_GP_REMOTE_COMMISSION_MODE;

        /* Set Commission Exit Mode Details */
        /* If proxy commission mode command has commission timeout field then set timeout value */
        if(sZgpProxyCommissioningModeCmdPayload.b8Options & GP_PROXY_CMSNG_MODE_EXIT_MODE_ON_WINDOW_EXPIRE_MASK)
        {
            psGPCustomDataStructure->u16CommissionWindow =
                    (sZgpProxyCommissioningModeCmdPayload.u16CommissioningWindow * 50);
        }

        if(sZgpProxyCommissioningModeCmdPayload.b8Options & GP_PROXY_CMSNG_MODE_EXIT_MODE_ON_PAIRING_SUCCESS_MASK)
        {
            psGPCustomDataStructure->bCommissionExitModeOnFirstPairSuccess = TRUE;
        }
        else if(sZgpProxyCommissioningModeCmdPayload.b8Options & GP_PROXY_CMSNG_MODE_EXIT_MODE_ON_PROXY_MODE_CMD_MASK)
        {
            psGPCustomDataStructure->bCommissionExitModeOnCommissionModeExitCmd = TRUE;
        }

        psGPCustomDataStructure->u64CommissionSetAddress = u64RemoteIeeeAddress;

         /* Call end point callback event for informing that device moved to remote pairing mode */
         /* Set Event Type */
        psGPCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_COMMISSION_MODE_ENTER;
        psEndPointDefinition->pCallBackFunctions(&psGPCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);

    }

    /* Set Commission Indication Given Flag */
    psGPCustomDataStructure->bIsCommissionIndGiven = FALSE;

    // release mutex
    #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


    return eStatus;
}
#endif
#ifdef GP_COMBO_MIN_DEVICE
/****************************************************************************
 **
 ** NAME:       eGP_HandleZgpNotification
 **
 ** DESCRIPTION:
 ** Handles Green power Cluster ZGP Notification command
 **
 ** PARAMETERS:               Name                      Usage
 ** ZPS_tsAfEvent            *pZPSevent                 Zigbee stack event structure
 ** tsZCL_EndPointDefinition *psEndPointDefinition      EP structure
 ** tsZCL_ClusterInstance    *psClusterInstance         Cluster structure
 ** uint16                    u16Offset                 offset
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/

PUBLIC teZCL_Status eGP_HandleZgpNotification(
                    ZPS_tsAfEvent                  *pZPSevent,
                    tsZCL_EndPointDefinition       *psEndPointDefinition,
                    tsZCL_ClusterInstance          *psClusterInstance,
                    uint16                         u16Offset)
{
    uint8 au8Data[GP_MAX_ZB_CMD_PAYLOAD_LENGTH] = {0}, u8ApplicationId;
    bool_t bSecurityOptions = FALSE, bIsSinkTableEntryPresent = FALSE;
    tsGP_GreenPowerCustomData *psGPCustomDataStructure;
    tsGP_ZgpNotificationCmdPayload sNotificationCmdPyld = {0};
    tsGP_ZgpsSinkTable             sSinkTableEntry;
    teZCL_Status eStatus;
    uint16       u16SourceAddress = 0;
    teGP_GreenPowerCommunicationMode eCommunicationMode;
    teGP_GreenPowerSecLevel    eSinkEntrySecLevel = E_GP_NO_SECURITY, eRcvdSecLevel = E_GP_NO_SECURITY;
    teGP_GreenPowerSecKeyType  eSinkEntrySecKeyType = E_GP_NO_KEY, eRcvdSecKeyType = E_GP_NO_KEY;
    // initialise pointer
    psGPCustomDataStructure = (tsGP_GreenPowerCustomData *)psClusterInstance->pvEndPointCustomStructPtr;

    // get EP mutex
    #ifndef COOPERATIVE
        eZCL_GetMutex(psEndPointDefinition);
    #endif


    // if cluster is not in operating mode then drop the Notification packet
    if((psGPCustomDataStructure->eGreenPowerDeviceMode != E_GP_OPERATING_MODE)
#ifndef PC_PLATFORM_BUILD
        ||(pZPSevent->uEvent.sApsDataIndEvent.u8DstAddrMode != ZPS_E_ADDR_MODE_GROUP)
#endif
       )
    {
        // release mutex
        #ifndef COOPERATIVE
            eZCL_ReleaseMutex(psEndPointDefinition);
        #endif


        return E_ZCL_SUCCESS;
    }

    sNotificationCmdPyld.sZgpdCommandPayload.pu8Data = au8Data;
    sNotificationCmdPyld.sZgpdCommandPayload.u8Length = 0;
    sNotificationCmdPyld.sZgpdCommandPayload.u8MaxLength = GP_MAX_ZB_CMD_PAYLOAD_LENGTH;

    // get information
    eStatus = eGP_ZgpNotificationReceive(pZPSevent,  u16Offset, &sNotificationCmdPyld);

    if(eStatus != E_ZCL_SUCCESS)
    {
        // release mutex
        #ifndef COOPERATIVE
            eZCL_ReleaseMutex(psEndPointDefinition);
        #endif


        return eStatus;
    }

    u8ApplicationId = (uint8)(sNotificationCmdPyld.b16Options & GP_APPLICATION_ID_MASK);
    /* Check security level of packet */
    eRcvdSecLevel = (sNotificationCmdPyld.b16Options & GP_NOTIFICATION_SECURITY_LEVEL_MASK) >> 6;
    if(eRcvdSecLevel != E_GP_NO_SECURITY)
    {
        bSecurityOptions = TRUE;
        eRcvdSecKeyType = (sNotificationCmdPyld.b16Options & GP_NOTIFICATION_SECURITY_KEY_TYPE_MASK) >> 8;
    }
#ifndef PC_PLATFORM_BUILD
    u16SourceAddress = pZPSevent->uEvent.sApsDataIndEvent.uSrcAddress.u16Addr;
#endif
    /* Check duplicate packet or not */
    if(bGP_IsDuplicatePkt(psEndPointDefinition->u8EndPointNumber,
                          psClusterInstance->bIsServer,
                          u8ApplicationId,
                          sNotificationCmdPyld.uZgpdDeviceAddr,
                          bSecurityOptions,
                          sNotificationCmdPyld.u32ZgpdSecFrameCounter,
                          sNotificationCmdPyld.eZgpdCmdId,
                          sNotificationCmdPyld.sZgpdCommandPayload.u8Length,
                          sNotificationCmdPyld.sZgpdCommandPayload.pu8Data,
                          u16SourceAddress,
                          psGPCustomDataStructure))
    {
        // release mutex
        #ifndef COOPERATIVE
            eZCL_ReleaseMutex(psEndPointDefinition);
        #endif


        return E_ZCL_SUCCESS;
    }

    if(sNotificationCmdPyld.b16Options & GP_NOTIFICATION_ALSO_UNICAST_MASK)
    {
        eCommunicationMode = E_GP_UNI_FORWARD_ZGP_NOTIFICATION_BY_PROXIES_BOTH;
    }

    bIsSinkTableEntryPresent = bGP_IsSinkTableEntryPresent(psEndPointDefinition->u8EndPointNumber,
                                            u8ApplicationId,
                                            &sNotificationCmdPyld.uZgpdDeviceAddr,
                                            E_GP_SINK_TABLE_GET_ENTRY,
                                            &sSinkTableEntry,
                                            eCommunicationMode);

    if(bIsSinkTableEntryPresent == FALSE)
    {
        if(sNotificationCmdPyld.b16Options & GP_NOTIFICATION_ALSO_DERIVED_GROUP_MASK)
        {
            eCommunicationMode = E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_DGROUP_ID;
        }

        bIsSinkTableEntryPresent = bGP_IsSinkTableEntryPresent(psEndPointDefinition->u8EndPointNumber,
                                                u8ApplicationId,
                                                &sNotificationCmdPyld.uZgpdDeviceAddr,
                                                E_GP_SINK_TABLE_GET_ENTRY,
                                                &sSinkTableEntry,
                                                eCommunicationMode);
    }

    if(bIsSinkTableEntryPresent == FALSE)
    {
        if(sNotificationCmdPyld.b16Options & GP_NOTIFICATION_ALSO_COMMISSION_GROUP_MASK)
        {
            eCommunicationMode = E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID;
        }

        bIsSinkTableEntryPresent = bGP_IsSinkTableEntryPresent(psEndPointDefinition->u8EndPointNumber,
                                                u8ApplicationId,
                                                &sNotificationCmdPyld.uZgpdDeviceAddr,
                                                E_GP_SINK_TABLE_GET_ENTRY,
                                                &sSinkTableEntry,
                                                eCommunicationMode);
    }

    if(bIsSinkTableEntryPresent)
    {
#ifndef PC_PLATFORM_BUILD
        uint8 i;
        uint16 u16DerivedGroupAddr;

        /* check received and supported communication mode */

        /* Get communication mode */
        eCommunicationMode = (sSinkTableEntry.b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3;

        if(eCommunicationMode == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_DGROUP_ID)
        {
            u16DerivedGroupAddr = u16GP_DeriveAliasSrcAddr(u8ApplicationId, sNotificationCmdPyld.uZgpdDeviceAddr);
            if(u16DerivedGroupAddr != pZPSevent->uEvent.sApsDataIndEvent.uDstAddress.u16Addr)
            {
                // release mutex
                #ifndef COOPERATIVE
                    eZCL_ReleaseMutex(psEndPointDefinition);
                #endif


                return E_ZCL_SUCCESS;
            }
        }
        else if(eCommunicationMode == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID)
        {
            for(i = 0; i < sSinkTableEntry.u8ZgpsGroupListEntries; i++)
            {
                if(sSinkTableEntry.asZgpsGroupList[i].u16SinkGroup == pZPSevent->uEvent.sApsDataIndEvent.uDstAddress.u16Addr)
                {
                    break;
                }
            }
            if((sSinkTableEntry.u8ZgpsGroupListEntries == 0)||(i ==  sSinkTableEntry.u8ZgpsGroupListEntries))
            {
                // release mutex
                #ifndef COOPERATIVE
                    eZCL_ReleaseMutex(psEndPointDefinition);
                #endif


                return E_ZCL_SUCCESS;
            }
        }
#endif
        if(sSinkTableEntry.b16Options & GP_SINK_TABLE_SECURITY_USE_MASK)
        {
            eSinkEntrySecLevel = sSinkTableEntry.b8SecOptions & GP_SECURITY_LEVEL_MASK;
            eSinkEntrySecKeyType = (sSinkTableEntry.b8SecOptions & GP_SECURITY_KEY_TYPE_MASK) >> 2;

            /* check for security level, device commissioned with some security level (>0) but send unprotected command */
            if(eSinkEntrySecLevel != ((sNotificationCmdPyld.b16Options & GP_NOTIFICATION_SECURITY_LEVEL_MASK) >> 6))
            {
                return E_ZCL_SUCCESS;
            }
        }

        /* security check & Freshness check */
        if((eSinkEntrySecLevel != eRcvdSecLevel)||
           (eSinkEntrySecKeyType != eRcvdSecKeyType)||
           (FALSE == bGP_IsFreshPkt(psEndPointDefinition->u8EndPointNumber,
                                   u8ApplicationId,
                                   &sNotificationCmdPyld.uZgpdDeviceAddr,
                                   psGPCustomDataStructure,
                                   &sSinkTableEntry,
                                   sNotificationCmdPyld.u32ZgpdSecFrameCounter)))
        {
            // release mutex
            #ifndef COOPERATIVE
                eZCL_ReleaseMutex(psEndPointDefinition);
            #endif


            return E_ZCL_SUCCESS;
        }

        if(eGP_GPDFHandler( pZPSevent,
                            psEndPointDefinition,
                            psGPCustomDataStructure,
                            u8ApplicationId,
                            &sNotificationCmdPyld.uZgpdDeviceAddr,
                            sNotificationCmdPyld.eZgpdCmdId,
                            sNotificationCmdPyld.sZgpdCommandPayload.u8Length,
                            sNotificationCmdPyld.sZgpdCommandPayload.pu8Data) == E_ZCL_SUCCESS)
        {
            /* if device has translation entry for this ZGPD and paired, its priority in the sink table should be 1*/
            if((sSinkTableEntry.eGreenPowerSinkTablePriority == E_GP_SINK_TABLE_P_2)||
               (sSinkTableEntry.eGreenPowerSinkTablePriority == E_GP_SINK_TABLE_P_3))
            {
                sSinkTableEntry.eGreenPowerSinkTablePriority = E_GP_SINK_TABLE_P_1;
                bGP_IsSinkTableEntryPresent(psEndPointDefinition->u8EndPointNumber,
                                            u8ApplicationId,
                                            &sNotificationCmdPyld.uZgpdDeviceAddr,
                                            E_GP_SINK_TABLE_SET_ENTRY,
                                            &sSinkTableEntry,
                                            eCommunicationMode);
            }
        }
    }

    // release mutex
    #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


    return E_ZCL_SUCCESS;
}
#endif
#ifndef GP_DISABLE_COMMISSION_NOTIFICATION_CMD
/****************************************************************************
 **
 ** NAME:       eGP_HandleZgpCommissioningNotification
 **
 ** DESCRIPTION:
 ** Handles Green power Cluster ZGP Commissioning Notification command
 **
 ** PARAMETERS:               Name                      Usage
 ** ZPS_tsAfEvent            *pZPSevent                 Zigbee stack event structure
 ** tsZCL_EndPointDefinition *psEndPointDefinition      EP structure
 ** tsZCL_ClusterInstance    *psClusterInstance         Cluster structure
 ** uint16                    u16Offset                 offset
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/

PUBLIC teZCL_Status eGP_HandleZgpCommissioningNotification(
                    ZPS_tsAfEvent                  *pZPSevent,
                    tsZCL_EndPointDefinition       *psEndPointDefinition,
                    tsZCL_ClusterInstance          *psClusterInstance,
                    uint16                         u16Offset)
{
    tsGP_GreenPowerCustomData                   *psGpCustomDataStructure;
    tsGP_ZgpCommissioningNotificationCmdPayload sZgpCommissioningNotificationCmdPayload;
    tsGP_ZgpDataIndication                      sZgpDataIndication;

#ifdef GP_COMBO_MIN_DEVICE
    tsGP_ZgpsSinkTable                          sSinkTableEntry;
    bool_t                                      bIsSinkEntryPresent = FALSE;
    uint8                                       b8ZgpsCommModeAttr;
    bool_t                                      bIsSeqNumCap = FALSE, bIsFixedLocation = FALSE, bIsRxOnCap = FALSE;
    tsZCL_Address                               sDestinationAddress;
    tsGP_ZgpCommissionIndication                sZgpCommissionIndication;
    uint8                                       u8SecLevel = E_GP_NO_SECURITY, u8SecKeyType = E_GP_NO_KEY;
#endif

#ifdef GP_PROXY_DEVICE
    tsGP_ZgppProxyTable                         sProxyTableEntry;
    bool_t                                      bIsProxyEntryPresent = FALSE;
#endif

    uint8                                		u8Status;
    uint8                                       au8Data[GP_MAX_ZB_CMD_PAYLOAD_LENGTH] = {0};
    uint8                                       u8ApplicationId;
    // initialise pointer
    psGpCustomDataStructure = (tsGP_GreenPowerCustomData *)psClusterInstance->pvEndPointCustomStructPtr;

    // if cluster is not in commission mode then drop the commission Notification packet
    if(psGpCustomDataStructure->eGreenPowerDeviceMode == E_GP_OPERATING_MODE)
    {
        return E_ZCL_SUCCESS;
    }

    // get EP mutex
    #ifndef COOPERATIVE
        eZCL_GetMutex(psEndPointDefinition);
    #endif


    // fill in callback event structure
    eZCL_SetCustomCallBackEvent(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent,
                pZPSevent, 0, psEndPointDefinition->u8EndPointNumber);

    sZgpCommissioningNotificationCmdPayload.sZgpdCommandPayload.pu8Data = au8Data;
    sZgpCommissioningNotificationCmdPayload.sZgpdCommandPayload.u8Length = 0;
    sZgpCommissioningNotificationCmdPayload.sZgpdCommandPayload.u8MaxLength = GP_MAX_ZB_CMD_PAYLOAD_LENGTH;

    // get information
    u8Status = eGP_ZgpCommissioningNotificationReceive(
                                pZPSevent,
                                u16Offset,
                                &sZgpCommissioningNotificationCmdPayload);

    /* Check Status */
    if(u8Status != E_ZCL_SUCCESS)
    {
        // release mutex
        #ifndef COOPERATIVE
            eZCL_ReleaseMutex(psEndPointDefinition);
        #endif


        return u8Status;
    }
#ifdef GP_COMBO_MIN_DEVICE
    if((sZgpCommissioningNotificationCmdPayload.eZgpdCmdId == E_GP_CHANNEL_REQUEST)&&
         (psGpCustomDataStructure->u16TransmitChannelTimeout))
    {
        // release mutex
        #ifndef COOPERATIVE
            eZCL_ReleaseMutex(psEndPointDefinition);
        #endif


        return E_ZCL_SUCCESS;
    }
#endif
    DBG_vPrintf(TRACE_GP_DEBUG, "\nInside Comm Notification\r\n");
    u8ApplicationId = (uint8)(sZgpCommissioningNotificationCmdPayload.b16Options & GP_APPLICATION_ID_MASK);



#if 0
    /* Check duplicate packet or not */
    if(bGP_IsDuplicatePkt(psEndPointDefinition->u8EndPointNumber,
                          psClusterInstance->bIsServer,
                          u8ApplicationId,
                          sZgpCommissioningNotificationCmdPayload.uZgpdDeviceAddr,
                          bSecurityOptions,
                          sZgpCommissioningNotificationCmdPayload.u32ZgpdSecFrameCounter,
                          sZgpCommissioningNotificationCmdPayload.eZgpdCmdId,
                          sZgpCommissioningNotificationCmdPayload.sZgpdCommandPayload.u8Length,
                          sZgpCommissioningNotificationCmdPayload.sZgpdCommandPayload.pu8Data,
                          u16SourceAddress,
                          psGpCustomDataStructure))
    {
        // release mutex
        #ifndef COOPERATIVE
            eZCL_ReleaseMutex(psEndPointDefinition);
        #endif


        return E_ZCL_SUCCESS;
    }
    else
#endif

    {
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
            memset(&sSinkTableEntry, 0, sizeof(tsGP_ZgpsSinkTable));

            bIsSinkEntryPresent = bGP_IsSinkTableEntryPresent(
                                    psEndPointDefinition->u8EndPointNumber,
                                    u8ApplicationId,
                                    &sZgpCommissioningNotificationCmdPayload.uZgpdDeviceAddr,
                                    E_GP_SINK_TABLE_GET_ENTRY,
                                    &sSinkTableEntry,
                                    b8ZgpsCommModeAttr);

            /* check sink table entry presented or not for this ZGPD */
            if((bIsSinkEntryPresent)&&(!(sZgpCommissioningNotificationCmdPayload.b16Options & GP_CMSNG_NOTIFICATION_APPOINT_TEMP_MASTER_MASK)))
            {
                if(sZgpCommissioningNotificationCmdPayload.eZgpdCmdId == E_GP_SUCCESS)
                {
                    sSinkTableEntry.u32ZgpdSecFrameCounter = sZgpCommissioningNotificationCmdPayload.u32ZgpdSecFrameCounter;
                    bGP_IsSinkTableEntryPresent(psEndPointDefinition->u8EndPointNumber,
                                                u8ApplicationId,
                                                &sZgpCommissioningNotificationCmdPayload.uZgpdDeviceAddr,
                                                E_GP_SINK_TABLE_SET_ENTRY,
                                                &sSinkTableEntry,
                                                b8ZgpsCommModeAttr);
                }
                else
                {
                    uint32 u32SeqNoOrCounter;

                    if(sSinkTableEntry.b16Options & GP_SINK_TABLE_SECURITY_USE_MASK)
                    {
                          u32SeqNoOrCounter = sZgpCommissioningNotificationCmdPayload.u32ZgpdSecFrameCounter;
                    }
                    else
                    {
                          u32SeqNoOrCounter = sZgpCommissioningNotificationCmdPayload.u32ZgpdSecFrameCounter;
                    }

                    /* Freshness check */
                    if(FALSE == bGP_IsFreshPkt(psEndPointDefinition->u8EndPointNumber,
                                                u8ApplicationId,
                                                &sSinkTableEntry.uZgpdDeviceAddr,
                                                psGpCustomDataStructure,
                                                &sSinkTableEntry,
                                                u32SeqNoOrCounter))
                    {
                        // release mutex
                        #ifndef COOPERATIVE
                            eZCL_ReleaseMutex(psEndPointDefinition);
                        #endif

                        //DBG_vPrintf(TRACE_GP_DEBUG, "bGP_IsFreshPkt Fail\r\n");
                        return u8Status;
                    }
                }
            }
        }
#endif
#ifdef GP_PROXY_DEVICE
        /* Based on device type, check freshness of packet */
        if(psGpCustomDataStructure->eGreenPowerDeviceType == E_GP_ZGP_PROXY_DEVICE)
        {
            /* clear sink table */
            memset(&sProxyTableEntry, 0, sizeof(tsGP_ZgppProxyTable));

            bIsProxyEntryPresent = bGP_IsProxyTableEntryPresent(
                                    psEndPointDefinition->u8EndPointNumber,
                                    u8ApplicationId,
                                    &sZgpCommissioningNotificationCmdPayload.uZgpdDeviceAddr,
                                    E_GP_SINK_TABLE_GET_ENTRY,
                                    &sProxyTableEntry);

            /* check sink table entry presented or not for this ZGPD */
            if(bIsProxyEntryPresent)
            {
                uint32 u32SeqNoOrCounter;

                if(sProxyTableEntry.b16Options & GP_PROXY_TABLE_SECURITY_USE_MASK)
                {
                      u32SeqNoOrCounter = sZgpCommissioningNotificationCmdPayload.u32ZgpdSecFrameCounter;
                }
                else
                {
                      u32SeqNoOrCounter = sZgpCommissioningNotificationCmdPayload.u32ZgpdSecFrameCounter;
                }

                /* Freshness check */
                if(FALSE == bGP_IsFreshPkt(psEndPointDefinition->u8EndPointNumber,
                                            u8ApplicationId,
                                            &sProxyTableEntry.uZgpdDeviceAddr,
                                            psGpCustomDataStructure,
                                            &sProxyTableEntry,
                                            u32SeqNoOrCounter))
                {
                    // release mutex
                    #ifndef COOPERATIVE
                        eZCL_ReleaseMutex(psEndPointDefinition);
                    #endif


                    return u8Status;
                }
            }
        }

#endif
        /* check Application Id in option field */
        if( (sZgpCommissioningNotificationCmdPayload.b16Options & GP_APPLICATION_ID_MASK) == GP_APPL_ID_4_BYTE)
        {
            sZgpDataIndication.uZgpdDeviceAddr.u32ZgpdSrcId = sZgpCommissioningNotificationCmdPayload.uZgpdDeviceAddr.u32ZgpdSrcId;
        }
#ifdef GP_IEEE_ADDR_SUPPORT
        else
        {
            sZgpDataIndication.uZgpdDeviceAddr.u64ZgpdIEEEAddr =
                sZgpCommissioningNotificationCmdPayload.uZgpdDeviceAddr.u64ZgpdIEEEAddr;
        }
#endif

        sZgpDataIndication.u8PDUSize = sZgpCommissioningNotificationCmdPayload.sZgpdCommandPayload.u8Length;
        sZgpDataIndication.u8CommandId = sZgpCommissioningNotificationCmdPayload.eZgpdCmdId;
        sZgpDataIndication.u2ApplicationId = (sZgpCommissioningNotificationCmdPayload.b16Options & GP_APPLICATION_ID_MASK);
        sZgpDataIndication.u16NwkShortAddr = sZgpCommissioningNotificationCmdPayload.u16ZgppShortAddr;
        sZgpDataIndication.i8ProxyDistance = sZgpCommissioningNotificationCmdPayload.i8ZgppDistance;
        sZgpDataIndication.bTunneledPkt = TRUE;
        /* Check Key Type */
        if(((sZgpCommissioningNotificationCmdPayload.b16Options & GP_CMSNG_NOTIFICATION_SECURITY_KEY_TYPE_MASK) >> 6) > E_GP_NWK_KEY_DERIVED_ZGPD_GROUP_KEY)
        {
            sZgpDataIndication.u2SecurityKeyType = 0x01; /* Individual Key */
        }
        else
        {
            sZgpDataIndication.u2SecurityKeyType = 0x00; /* Common Key */
        }

        sZgpDataIndication.u2SecurityLevel = (sZgpCommissioningNotificationCmdPayload.b16Options & GP_CMSNG_NOTIFICATION_SECURITY_LEVEL_MASK) >> 4;

        sZgpDataIndication.u32SecFrameCounter = sZgpCommissioningNotificationCmdPayload.u32ZgpdSecFrameCounter;

        if(sZgpDataIndication.u2SecurityLevel == 0)
        {
            sZgpDataIndication.u8SeqNum = (uint8)sZgpCommissioningNotificationCmdPayload.u32ZgpdSecFrameCounter;
        }

        /* for auto commissioned, check Cmd type */
        if(sZgpDataIndication.u8CommandId < E_GP_COMMISSIONING)
        {
            sZgpDataIndication.bAutoCommissioning = TRUE;
        }

        /* For RxAfterTx, check temp master flag  */
        if(sZgpCommissioningNotificationCmdPayload.b16Options & GP_CMSNG_NOTIFICATION_APPOINT_TEMP_MASTER_MASK)
        {
            sZgpDataIndication.bRxAfterTx = TRUE;
        }

        /* For Mic, check security processing flag */
        if(sZgpCommissioningNotificationCmdPayload.b16Options & GP_CMSNG_NOTIFICATION_SEC_PROCESS_FAIL_MASK)
        {
            sZgpDataIndication.u32Mic = sZgpCommissioningNotificationCmdPayload.u32Mic;
        }

        /* Payload length 0xff allowed */
        if(sZgpDataIndication.u8PDUSize == 0xFF)
        {
            sZgpDataIndication.u8PDUSize = 0; /* set to zero */
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
        sZgpDataIndication.pu8Pdu = sZgpCommissioningNotificationCmdPayload.sZgpdCommandPayload.pu8Data;

        if(((sZgpCommissioningNotificationCmdPayload.eZgpdCmdId == E_GP_SUCCESS)||(sZgpCommissioningNotificationCmdPayload.eZgpdCmdId == E_GP_DECOMMISSIONING))&&
                        psGpCustomDataStructure->eGreenPowerDeviceType == E_GP_ZGP_PROXY_DEVICE)
        {
            // release mutex
            #ifndef COOPERATIVE
                eZCL_ReleaseMutex(psEndPointDefinition);
            #endif


            return E_ZCL_SUCCESS;
        }

#ifdef GP_COMBO_MIN_DEVICE
        /* Check Cmd Type, if it is success command inform user and send device announce */
        if( sZgpCommissioningNotificationCmdPayload.eZgpdCmdId == E_GP_SUCCESS &&
            psGpCustomDataStructure->eGreenPowerDeviceType == E_GP_ZGP_COMBO_MIN_DEVICE &&
            psGpCustomDataStructure->bIsCommissionReplySent)
        {

            /* Give Indication to the user */
            psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_SUCCESS_CMD_RCVD;

            /* Call End Point Call back to indicate exit commission mode */
            psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);

            u8Status = eGP_UpdateApsGroupTableAndDeviceAnnounce(
                                     psEndPointDefinition,
                                     psGpCustomDataStructure,
                                     &sSinkTableEntry,
                                     &sZgpDataIndication,
                                     E_ZCL_SUCCESS);

            // release mutex
            #ifndef COOPERATIVE
                eZCL_ReleaseMutex(psEndPointDefinition);
            #endif


            return E_ZCL_SUCCESS;
        }

        /* Handle GP Decommission Packet if device is GP Combo Min */
        if(sZgpCommissioningNotificationCmdPayload.eZgpdCmdId == E_GP_DECOMMISSIONING &&
                psGpCustomDataStructure->eGreenPowerDeviceType == E_GP_ZGP_COMBO_MIN_DEVICE &&
                psGpCustomDataStructure->eGreenPowerDeviceMode == E_GP_PAIRING_COMMISSION_MODE)
        {
            tsGP_ZgpPairingCmdPayload                       sZgpPairingPayload;
            tsGP_ZgpPairingConfigCmdPayload                 sZgpPairingConfigPayload;
            uint8                                           u8TransactionSequenceNumber;
            bool_t                                          b8ZgpsCommExitModeAttr;

            /* check sink table entry presented or not for this ZGPD */
            if(bIsSinkEntryPresent)
            {
                /* Give a callback to the application to remove translation table entries for this ZGPD */
                psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_DECOMM_CMD_RCVD;
                psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.uMessage.psZgpDecommissionIndication->uZgpdDeviceAddr =
                                                                                         sZgpDataIndication.uZgpdDeviceAddr;
                psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.uMessage.psZgpDecommissionIndication->u8ApplicationId =
                                                                                                     (uint8)sZgpDataIndication.u2ApplicationId;

                /* Give Application Callback for functionality matching */
                psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);

                sDestinationAddress.eAddressMode = E_ZCL_AM_BROADCAST;
                sDestinationAddress.uAddress.eBroadcastMode = ZPS_E_APL_AF_BROADCAST_RX_ON;

                /* Remove Group Table entries at APS level for this ZGPD */
                /* Add to the group only if communication mode is derived or assigned */
                if(((sSinkTableEntry.b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3) == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_DGROUP_ID)
                {
                    /* Add derived group Id */
                    uint16  u16DerivedGroupId;
                    u16DerivedGroupId = u16GP_DeriveAliasSrcAddr(
                            (uint8)sZgpDataIndication.u2ApplicationId,
                            sZgpDataIndication.uZgpdDeviceAddr);

                    u8Status = ZPS_eAplZdoGroupEndpointRemove(u16DerivedGroupId, ZCL_GP_PROXY_ENDPOINT_ID);
                }
                else if(((sSinkTableEntry.b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3) == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID)
                {
                    /* Find No. of pre-commissioned groups are presented in the list */
                    uint8   u8Count;

                    for(u8Count = 0; u8Count < sSinkTableEntry.u8ZgpsGroupListEntries; u8Count++)
                    {
                        u8Status = ZPS_eAplZdoGroupEndpointRemove(sSinkTableEntry.asZgpsGroupList[u8Count].u16SinkGroup, ZCL_GP_PROXY_ENDPOINT_ID);
                    }

                    sZgpPairingConfigPayload.b16Options = (uint8)sZgpDataIndication.u2ApplicationId;

                    /* Check App Id */
                    if((sSinkTableEntry.b16Options & GP_SINK_TABLE_APP_ID_MASK) == GP_APPL_ID_4_BYTE)
                    {
                        sZgpPairingConfigPayload.uZgpdDeviceAddr.u32ZgpdSrcId = sSinkTableEntry.uZgpdDeviceAddr.u32ZgpdSrcId;
                    }
#ifdef GP_IEEE_ADDR_SUPPORT
                    else
                    {
                        sZgpPairingConfigPayload.uZgpdDeviceAddr.u64ZgpdIEEEAddr = sSinkTableEntry.uZgpdDeviceAddr.u64ZgpdIEEEAddr;
                    }
#endif
                    sZgpPairingConfigPayload.u8Actions = E_GP_PAIRING_CONFIG_REMOVE_GPD;
                    sZgpPairingConfigPayload.eZgpdDeviceId = sSinkTableEntry.eZgpdDeviceId;
                    sZgpPairingConfigPayload.u8ForwardingRadius = sSinkTableEntry.u8GroupCastRadius;
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
                sZgpPairingPayload.b24Options = (uint8)sZgpDataIndication.u2ApplicationId;

                /* Check App Id */
                if((sSinkTableEntry.b16Options & GP_SINK_TABLE_APP_ID_MASK) == GP_APPL_ID_4_BYTE)
                {
                    sZgpPairingPayload.uZgpdDeviceAddr.u32ZgpdSrcId = sSinkTableEntry.uZgpdDeviceAddr.u32ZgpdSrcId;
                }
#ifdef GP_IEEE_ADDR_SUPPORT
                else
                {
                    sZgpPairingPayload.uZgpdDeviceAddr.u64ZgpdIEEEAddr = sSinkTableEntry.uZgpdDeviceAddr.u64ZgpdIEEEAddr;
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
                        &sSinkTableEntry);

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
            //else
            {
                 // release mutex
                 #ifndef COOPERATIVE
                    eZCL_ReleaseMutex(psEndPointDefinition);
                #endif


                 return E_ZCL_SUCCESS;
            }
        }
        else if(sZgpCommissioningNotificationCmdPayload.eZgpdCmdId == E_GP_DECOMMISSIONING &&
                psGpCustomDataStructure->eGreenPowerDeviceType == E_GP_ZGP_COMBO_MIN_DEVICE &&
                psGpCustomDataStructure->eGreenPowerDeviceMode == E_GP_REMOTE_COMMISSION_MODE)
        {
            // release mutex
            #ifndef COOPERATIVE
                eZCL_ReleaseMutex(psEndPointDefinition);
            #endif


            return E_ZCL_SUCCESS;
        }
#endif

        /* Temp Master fields present for both channel request cmd and GP Commission Cmd with RxAfter = TRUE */
        /* check Temp Master Field */
        if(sZgpCommissioningNotificationCmdPayload.b16Options & GP_CMSNG_NOTIFICATION_APPOINT_TEMP_MASTER_MASK)
        {
            /* check any GP channel request/Commission Packet buffer as it can receive over directly or tunnel notification */
            tsGP_ZgpBufferedApduRecord                  *psZgpBufferedApduRecord;
            bool                                        bIsCommNotiGpRespBuffered = FALSE;

            /* take head of list */
            psZgpBufferedApduRecord = (tsGP_ZgpBufferedApduRecord *)psDLISTgetHead(&psGpCustomDataStructure->lGpAllocList);

            if(psZgpBufferedApduRecord == NULL)
            {
                DBG_vPrintf(TRACE_GP_DEBUG, "No Buffered Lists\r\n");
            }

            /* traverse through list look for this cmd Id and GP Device address */
            while(psZgpBufferedApduRecord)
            {
                int8 i8Distance = psZgpBufferedApduRecord->sBufferedApduInfo.i8ProxyDistance;

                DBG_vPrintf(TRACE_GP_DEBUG, "eGreenPowerDeviceType:%d\r\n", psGpCustomDataStructure->eGreenPowerDeviceType);
                DBG_vPrintf(TRACE_GP_DEBUG, "u8CommandId:%d\r\n", psZgpBufferedApduRecord->sBufferedApduInfo.u8CommandId);
                DBG_vPrintf(TRACE_GP_DEBUG, "eGreenPowerBufferedCommand:%d\r\n", psZgpBufferedApduRecord->sBufferedApduInfo.eGreenPowerBufferedCommand);
                DBG_vPrintf(TRACE_GP_DEBUG, "u2ApplicationId:%d\r\n", psZgpBufferedApduRecord->sBufferedApduInfo.u2ApplicationId);
                DBG_vPrintf(TRACE_GP_DEBUG, "Stored u32ZgpdSrcId:%d\r\n", psZgpBufferedApduRecord->sBufferedApduInfo.uZgpdDeviceAddr.u32ZgpdSrcId);
                DBG_vPrintf(TRACE_GP_DEBUG, "Rxed u32ZgpdSrcId:%d\r\n", sZgpCommissioningNotificationCmdPayload.uZgpdDeviceAddr.u32ZgpdSrcId);

                /* check command ID and GP device address */
                if( (psZgpBufferedApduRecord->sBufferedApduInfo.u8CommandId == E_GP_CHANNEL_REQUEST ||
                        psZgpBufferedApduRecord->sBufferedApduInfo.u8CommandId == E_GP_COMMISSIONING) &&
                    (psZgpBufferedApduRecord->sBufferedApduInfo.eGreenPowerBufferedCommand == E_GP_COMMISSION_NOTIFICATION ||
                        psZgpBufferedApduRecord->sBufferedApduInfo.eGreenPowerBufferedCommand == E_GP_RESPONSE) &&
                    ( (psZgpBufferedApduRecord->sBufferedApduInfo.uZgpdDeviceAddr.u32ZgpdSrcId ==
                                                    sZgpCommissioningNotificationCmdPayload.uZgpdDeviceAddr.u32ZgpdSrcId &&
                       psZgpBufferedApduRecord->sBufferedApduInfo.u2ApplicationId == GP_APPL_ID_4_BYTE)
#ifdef GP_IEEE_ADDR_SUPPORT
                        || (psZgpBufferedApduRecord->sBufferedApduInfo.uZgpdDeviceAddr.u64ZgpdIEEEAddr ==
                                                    sZgpCommissioningNotificationCmdPayload.uZgpdDeviceAddr.u64ZgpdIEEEAddr &&
                            psZgpBufferedApduRecord->sBufferedApduInfo.u2ApplicationId == GP_APPL_ID_8_BYTE)
#endif
                ))
                {
                    /* If device is proxy, stop transmission if proxy distance of received packet is less */
                    /* check proxy distance
                     * Delete buffered record from the list, if proxy distance of rxed pkt is less or
                     * distance same and address of temp address is lower than previous */
                    if( (psGpCustomDataStructure->eGreenPowerDeviceType == E_GP_ZGP_PROXY_DEVICE) &&
                        ( (sZgpCommissioningNotificationCmdPayload.i8ZgppDistance < i8Distance) ||
                          (sZgpCommissioningNotificationCmdPayload.i8ZgppDistance == i8Distance &&
                                    sZgpCommissioningNotificationCmdPayload.u16ZgppShortAddr <
                                    psZgpBufferedApduRecord->sBufferedApduInfo.u16NwkShortAddr) ) )
                    {
                        tsGP_ZgpBufferedApduRecord                  *psTempZgpBufferedApduRecord;

                        /* For combo min device, it has to check any GP response packet buffered or not */
                        /* get the next list */
                        psTempZgpBufferedApduRecord = (tsGP_ZgpBufferedApduRecord *)psDLISTgetNext((DNODE *)psZgpBufferedApduRecord);

                        /* Delete Node */
                        psDLISTremove(&psGpCustomDataStructure->lGpAllocList,
                                (DNODE *)psZgpBufferedApduRecord);

                        // add to free list
                        vDLISTaddToTail(&psGpCustomDataStructure->lGpDeAllocList,
                                (DNODE *)psZgpBufferedApduRecord);


                        /* If no records in the list, break the loop */
                        if(psTempZgpBufferedApduRecord == NULL)
                        {
                            break;
                        }
                        else
                        {
                            psZgpBufferedApduRecord = psTempZgpBufferedApduRecord;
                        }
                    }
                }

                /* If device is combo min, device has to select temp master */
                if( psGpCustomDataStructure->eGreenPowerDeviceType == E_GP_ZGP_COMBO_MIN_DEVICE &&
                    (psZgpBufferedApduRecord->sBufferedApduInfo.u8CommandId == E_GP_CHANNEL_REQUEST ||
                            psZgpBufferedApduRecord->sBufferedApduInfo.u8CommandId == E_GP_COMMISSIONING) &&
                    psZgpBufferedApduRecord->sBufferedApduInfo.eGreenPowerBufferedCommand == E_GP_RESPONSE &&
                    ( (psZgpBufferedApduRecord->sBufferedApduInfo.uZgpdDeviceAddr.u32ZgpdSrcId ==
                                                    sZgpCommissioningNotificationCmdPayload.uZgpdDeviceAddr.u32ZgpdSrcId &&
                            psZgpBufferedApduRecord->sBufferedApduInfo.u2ApplicationId == GP_APPL_ID_4_BYTE)
#ifdef GP_IEEE_ADDR_SUPPORT
                        || (psZgpBufferedApduRecord->sBufferedApduInfo.uZgpdDeviceAddr.u64ZgpdIEEEAddr ==
                                                    sZgpCommissioningNotificationCmdPayload.uZgpdDeviceAddr.u64ZgpdIEEEAddr &&
                            psZgpBufferedApduRecord->sBufferedApduInfo.u2ApplicationId == GP_APPL_ID_8_BYTE)
#endif
                ))
                {
                    bIsCommNotiGpRespBuffered = TRUE;

                    /* check proxy distance
                     * if proxy distance of rxed pkt is less or
                     * distance same and address of temp address is lower than previous */
                    if( (sZgpCommissioningNotificationCmdPayload.i8ZgppDistance < i8Distance) ||
                            (sZgpCommissioningNotificationCmdPayload.i8ZgppDistance == i8Distance &&
                                    sZgpCommissioningNotificationCmdPayload.u16ZgppShortAddr <
                                    psZgpBufferedApduRecord->sBufferedApduInfo.u16NwkShortAddr) )
                    {
                        /* Overwrite previous record */
                        psZgpBufferedApduRecord->sBufferedApduInfo.u16NwkShortAddr =
                                                        sZgpCommissioningNotificationCmdPayload.u16ZgppShortAddr;
                        psZgpBufferedApduRecord->sBufferedApduInfo.i8ProxyDistance = sZgpCommissioningNotificationCmdPayload.i8ZgppDistance;
                    }
                }

                /* get the next list */
                psZgpBufferedApduRecord = (tsGP_ZgpBufferedApduRecord *)psDLISTgetNext((DNODE *)psZgpBufferedApduRecord);
            }

            /* If Comm Notification for GP Resp not buffered, then buffer it that means this is the first pkt rxed pkt for Channel Req */
            if( psGpCustomDataStructure->eGreenPowerDeviceType == E_GP_ZGP_COMBO_MIN_DEVICE &&
                psGpCustomDataStructure->eGreenPowerDeviceMode == E_GP_PAIRING_COMMISSION_MODE &&
                !bIsCommNotiGpRespBuffered &&
                (sZgpCommissioningNotificationCmdPayload.eZgpdCmdId == E_GP_CHANNEL_REQUEST))
            {
                u8Status = eGp_BufferTransmissionPacket(
                                &sZgpDataIndication,
                                E_GP_RESPONSE,
                                psGpCustomDataStructure);
            }

            if(psGpCustomDataStructure->eGreenPowerDeviceType == E_GP_ZGP_COMBO_MIN_DEVICE &&
                    (sZgpCommissioningNotificationCmdPayload.eZgpdCmdId == E_GP_CHANNEL_REQUEST))
            {
                // release mutex
                #ifndef COOPERATIVE
                    eZCL_ReleaseMutex(psEndPointDefinition);
                #endif

                return E_ZCL_SUCCESS;
            }
        }

#ifdef GP_PROXY_DEVICE
        /* Create Proxy Table entry for supporting mobility devices */
        if(psGpCustomDataStructure->eGreenPowerDeviceType == E_GP_ZGP_PROXY_DEVICE)
        {
            if( sZgpCommissioningNotificationCmdPayload.eZgpdCmdId == E_GP_COMMISSIONING ||
                sZgpCommissioningNotificationCmdPayload.eZgpdCmdId < E_GP_COMMISSIONING )
            {
                uint8 u8CommissionCmdOptionField = *(sZgpCommissioningNotificationCmdPayload.sZgpdCommandPayload.pu8Data+1);

                /* check entry presetend for this GPD */
                if(bIsProxyEntryPresent)
                {
                    /* Set InRange flag to 1 */
                    sProxyTableEntry.b16Options |= GP_PROXY_TABLE_IN_RANGE_MASK;
                }
                else
                {
                    /* Before creating proxy table entry, update proxy table entry info */
                    if((sZgpCommissioningNotificationCmdPayload.b16Options & GP_APPLICATION_ID_MASK) == GP_APPL_ID_4_BYTE)
                    {
                        sProxyTableEntry.b16Options = GP_APPL_ID_4_BYTE;
                        sProxyTableEntry.uZgpdDeviceAddr.u32ZgpdSrcId = sZgpCommissioningNotificationCmdPayload.uZgpdDeviceAddr.u32ZgpdSrcId;
                    }
#ifdef GP_IEEE_ADDR_SUPPORT
                    else
                    {
                        sProxyTableEntry.b16Options = GP_APPL_ID_8_BYTE;
                        sProxyTableEntry.uZgpdDeviceAddr.u64ZgpdIEEEAddr =
                            sZgpCommissioningNotificationCmdPayload.uZgpdDeviceAddr.u64ZgpdIEEEAddr;
                    }
#endif
                    /* Check Cmd is Commission command or Auto Commission Cmd */
                    if(sZgpCommissioningNotificationCmdPayload.eZgpdCmdId == E_GP_COMMISSIONING)
                    {
                        sProxyTableEntry.b16Options |= ((u8CommissionCmdOptionField & GP_COMM_CMD_MAC_SEQ_NUM_CAP_MASK) << 5); /* Seq Cap flag */
                        sProxyTableEntry.b16Options |= ((u8CommissionCmdOptionField & GP_COMM_CMD_FIXED_LOCATION_MASK) << 5);  /* Fixed location flag */
                    }
                    else
                    {
                        sProxyTableEntry.b16Options |= GP_PROXY_TABLE_SEQ_NUM_CAP_MASK; /* Seq Cap flag */
                    }

                    sProxyTableEntry.b16Options |= GP_PROXY_TABLE_ENTRY_ACTIVE_MASK; /* Active and Invalid flag */
                    sProxyTableEntry.b16Options |= GP_PROXY_TABLE_IN_RANGE_MASK; /* Set InRange flag to 1 */

                    /* Check Security level */
                    if((sZgpCommissioningNotificationCmdPayload.b16Options & GP_CMSNG_NOTIFICATION_SECURITY_LEVEL_MASK) >> 4)
                    {
                        sProxyTableEntry.b16Options |= GP_PROXY_TABLE_SECURITY_USE_MASK;
                        sProxyTableEntry.b8SecOptions = (sZgpCommissioningNotificationCmdPayload.b16Options & GP_CMSNG_NOTIFICATION_SECURITY_LEVEL_MASK) >> 4;
                    }
                }

                /* Create proxy table for this GPD */
                eGP_AddProxyTableEntry(
                                psEndPointDefinition->u8EndPointNumber,
                                &sProxyTableEntry);
            }

            // release mutex
            #ifndef COOPERATIVE
                eZCL_ReleaseMutex(psEndPointDefinition);
            #endif

            return E_ZCL_SUCCESS;
        }
#endif

#ifdef GP_COMBO_MIN_DEVICE
        /* check, if the received pkt is protected then check security status */
        if(!(sZgpCommissioningNotificationCmdPayload.b16Options & GP_CMSNG_NOTIFICATION_SEC_PROCESS_FAIL_MASK))
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


                return u8Status;
            }
            else
            {
                bool_t bIsSecCheckPassed = FALSE;
                uint8 *pu8Payload = (uint8*)sZgpCommissioningNotificationCmdPayload.sZgpdCommandPayload.pu8Data;
                uint8 u8ZgpSecKeyType = E_GP_NO_KEY;

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


                    return u8Status;
                }
#endif
                u8SecLevel = (uint8)((sZgpCommissioningNotificationCmdPayload.b16Options & GP_CMSNG_NOTIFICATION_SECURITY_LEVEL_MASK) >> 4);
                u8SecKeyType = (uint8)((sZgpCommissioningNotificationCmdPayload.b16Options & GP_CMSNG_NOTIFICATION_SECURITY_KEY_TYPE_MASK) >> 6);

                /* Check Cmd Id for Auto Commission*/
                if(sZgpCommissioningNotificationCmdPayload.eZgpdCmdId < E_GP_COMMISSIONING &&
                        (((sZgpCommissioningNotificationCmdPayload.b16Options & GP_CMSNG_NOTIFICATION_SECURITY_LEVEL_MASK) >> 4)) >= u8ZgpsSecLevel)
                {
                    bIsSecCheckPassed = TRUE;
                }
                else
                {
                    /* Parse Extended option field to get Sec Level Capability and Key */
                    /* Check Extended Options field present or not */
                    if(*(pu8Payload+1) & GP_COMM_CMD_EXT_OPT_FIELD_MASK)
                    {
                        u8SecLevel = (*(pu8Payload+2) & GP_COMM_CMD_EXT_OPT_SEC_LEVEL_MASK);
                        u8SecKeyType = (*(pu8Payload+2) & GP_COMM_CMD_EXT_OPT_KEY_TYPE_MASK) >> 2;

                        if(!u8SecKeyType)
                        {
                            u8SecKeyType = u8ZgpSecKeyType;
                        }
                    }

                    /* ZGPD doesn't support security then no security fields shouldn't present in extended option field */
                    if( !(*(pu8Payload+1) & GP_COMM_CMD_EXT_OPT_FIELD_MASK) &&
                        (u8ZgpsSecLevel == E_GP_NO_SECURITY) &&
                        ((sZgpCommissioningNotificationCmdPayload.b16Options & GP_CMSNG_NOTIFICATION_SECURITY_LEVEL_MASK) >> 4 == E_GP_NO_SECURITY) )
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
                                 //(u8ZgpsSecLevel > E_GP_NO_SECURITY) &&
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
                                    uint8  i;
#endif
                                    uint64 u64Address = 0;
#ifdef GP_IEEE_ADDR_SUPPORT
                                    u64Address = sZgpCommissioningNotificationCmdPayload.uZgpdDeviceAddr.u64ZgpdIEEEAddr;
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

                                    if((sZgpCommissioningNotificationCmdPayload.b16Options & GP_APPLICATION_ID_MASK)== GP_APPL_ID_4_BYTE)
                                    {
                                        u32SrcId = sZgpCommissioningNotificationCmdPayload.uZgpdDeviceAddr.u32ZgpdSrcId;
                                    }
                                    else
                                    {
                                        u32SrcId = (uint32)u64Address;
                                    }

                                    u8Header[0] = (uint8)u32SrcId;
                                    u8Header[1] = (uint8)(u32SrcId >> 8);
                                    u8Header[2] = (uint8)(u32SrcId >> 16);
                                    u8Header[3] = (uint8)(u32SrcId >> 24);

                                    if((sZgpCommissioningNotificationCmdPayload.b16Options & GP_APPLICATION_ID_MASK)== GP_APPL_ID_8_BYTE)
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
                                        DBG_vPrintf(TRACE_GP_DEBUG, "Decrypted key verified %d\n",bVerified);
                                         /* Give a callback to user saying that secuity processing failed */
                                        psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_SECURITY_PROCESSING_FAILED;
                                        psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);

                                         /* If security processing failed, then drop the packet */
                                         // release mutex
                                        #ifndef COOPERATIVE
                                            eZCL_ReleaseMutex(psEndPointDefinition);
                                        #endif


                                        return u8Status;
                                    }
#endif
                                    memcpy(sSinkTableEntry.sZgpdKey.au8Key, uOutKey.au8, E_ZCL_KEY_128_SIZE);
                                    memcpy(pu8Payload+3, uOutKey.au8, E_ZCL_KEY_128_SIZE);
#else
                                    /* Give a callback to user saying that link key not enabled */
                                    psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_LINK_KEY_IS_NOT_ENABLED;
                                    psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);

                                     /* drop the packet */
                                     // release mutex
                                    #ifndef COOPERATIVE
                                        eZCL_ReleaseMutex(psEndPointDefinition);
                                    #endif


                                    return u8Status;
#endif
                                }
                                else
                                {
                                    memcpy(sSinkTableEntry.sZgpdKey.au8Key, pu8Payload+3, E_ZCL_KEY_128_SIZE);
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
                                 ( ((*(pu8Payload+1) & GP_COMM_CMD_ZGP_SEC_KEY_REQ_MASK) &&
                                         !(sZgpCommissioningNotificationCmdPayload.b16Options & GP_CMSNG_NOTIFICATION_APPOINT_TEMP_MASTER_MASK) ) ||
                                   ((*(pu8Payload+1) & GP_COMM_CMD_ZGP_SEC_KEY_REQ_MASK) && !u8SecLevel) ) )
                        {
                            bIsSecCheckPassed = FALSE;
                        }
                        else if( (*(pu8Payload+1) & GP_COMM_CMD_EXT_OPT_FIELD_MASK) &&
                                 (u8ZgpsSecLevel == E_GP_NO_SECURITY) )
                        {
                            bIsSecCheckPassed = FALSE;
                        }

                        if((u8ZgpsSecLevel > E_GP_NO_SECURITY) &&
                           (((sZgpCommissioningNotificationCmdPayload.b16Options & GP_CMSNG_NOTIFICATION_SECURITY_LEVEL_MASK) >> 4) == E_GP_NO_SECURITY)&&
                           (!(*(pu8Payload+2) & GP_COMM_CMD_EXT_OPT_ZGPD_KEY_PRESENT_MASK))&&
                           (!(*(pu8Payload+1) & GP_COMM_CMD_ZGP_SEC_KEY_REQ_MASK)))
                        {
                            bIsSecCheckPassed = FALSE;
                        }

                        if((u8ZgpsSecLevel == E_GP_NO_SECURITY) && (u8SecLevel == E_GP_NO_SECURITY)&&
                                (!(*(pu8Payload+1) & GP_COMM_CMD_ZGP_SEC_KEY_REQ_MASK)))
                        {
                            bIsSecCheckPassed = TRUE;
                        }

                        if((u8ZgpsSecLevel == E_GP_NO_SECURITY) && (u8SecLevel == E_GP_NO_SECURITY)&&
                                (*(pu8Payload+1) & GP_COMM_CMD_ZGP_SEC_KEY_REQ_MASK))
                        {
                            bIsSecCheckPassed = FALSE;
                        }
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


                    return u8Status;
                }
                else
                {
                    if(((*(pu8Payload+1) & GP_COMM_CMD_ZGP_SEC_KEY_REQ_MASK))&&(!(sZgpCommissioningNotificationCmdPayload.b16Options & GP_CMSNG_NOTIFICATION_APPOINT_TEMP_MASTER_MASK)))
                    {
                        #ifndef COOPERATIVE
                            eZCL_ReleaseMutex(psEndPointDefinition);
                        #endif


                        return u8Status;
                    }
                }

                /* Check SecKey Type */
                if( (u8SecKeyType != E_GP_NO_KEY) &&
                     sZgpCommissioningNotificationCmdPayload.b16Options & GP_CMSNG_NOTIFICATION_APPOINT_TEMP_MASTER_MASK)
                {
                    if( (u8SecKeyType != E_GP_OUT_OF_THE_BOX_ZGPD_KEY) &&
                        (u8ZgpSecKeyType != E_GP_NO_KEY) )
                    {
                        u8SecKeyType = u8ZgpSecKeyType;
                    }
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


            return u8Status;
        }

        /* If device is in remote commissioning mode, it is not required add to sink table reason that
         * only nearest node to ZGPD will do sink table groupcast communication */
        sZgpCommissionIndication.psGpToZclCommandInfo = NULL;

        if(psGpCustomDataStructure->eGreenPowerDeviceMode == E_GP_PAIRING_COMMISSION_MODE &&
                ((!psGpCustomDataStructure->bIsCommissionIndGiven)||(sZgpDataIndication.bAutoCommissioning == TRUE)))
        {
            /* Give a callback to application about commission indication */
            sZgpCommissionIndication.eCmdType = E_GP_COMM_NOTF_CMD;
            sZgpCommissionIndication.eStatus = E_ZCL_SUCCESS; /* Assume Positive status */

            sZgpCommissionIndication.uCommands.sZgpCommissioningNotificationCmdPayload =
                                                    sZgpCommissioningNotificationCmdPayload;

            psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_COMMISSION_DATA_INDICATION;
            psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.uMessage.psZgpCommissionIndication =
                                                                         &sZgpCommissionIndication;

            /* Give Application Callback for functionality matching */
            psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);
        }
        else
        {
            sZgpCommissionIndication.eStatus = E_ZCL_FAIL;
        }

        /* If it is auto commission packet then sequence capable is TRUE */
        /* check cmd Id */
        if((uint8)sZgpCommissioningNotificationCmdPayload.eZgpdCmdId < E_GP_COMMISSIONING)
        {
            bIsSeqNumCap = FALSE;
            bIsRxOnCap = FALSE;
            bIsFixedLocation = FALSE;
        }
        else
        {
            uint8 b8ExtendedOptions;
            /* Parse the GP Command */
            bIsSeqNumCap = (*(sZgpCommissioningNotificationCmdPayload.sZgpdCommandPayload.pu8Data+1) &
                                GP_COMM_CMD_MAC_SEQ_NUM_CAP_MASK);

            bIsRxOnCap = (*(sZgpCommissioningNotificationCmdPayload.sZgpdCommandPayload.pu8Data+1) &
                            GP_COMM_CMD_RX_ON_CAP_MASK) >> 1;

            bIsFixedLocation = (*(sZgpCommissioningNotificationCmdPayload.sZgpdCommandPayload.pu8Data+1) &
                            GP_COMM_CMD_FIXED_LOCATION_MASK) >> 6;

            if(*(sZgpCommissioningNotificationCmdPayload.sZgpdCommandPayload.pu8Data+1) & GP_COMM_CMD_EXT_OPT_FIELD_MASK)
            {
                b8ExtendedOptions = *(sZgpCommissioningNotificationCmdPayload.sZgpdCommandPayload.pu8Data+2);
                if(b8ExtendedOptions & GP_COMM_CMD_EXT_OPT_ZGPD_OUT_GOING_COUNTER_MASK)
                {
                    uint8 *pu8Data;

                    if( (b8ExtendedOptions & GP_COMM_CMD_EXT_OPT_ZGPD_KEY_PRESENT_MASK) &&
                        (b8ExtendedOptions & GP_COMM_CMD_EXT_OPT_ZGPD_KEY_ENC_MASK))
                    {
                        pu8Data = sZgpCommissioningNotificationCmdPayload.sZgpdCommandPayload.pu8Data + 23;
                    }
                    else if(b8ExtendedOptions & GP_COMM_CMD_EXT_OPT_ZGPD_KEY_PRESENT_MASK)
                    {
                        pu8Data = sZgpCommissioningNotificationCmdPayload.sZgpdCommandPayload.pu8Data + 19;
                    }
                    else
                    {
                        pu8Data = sZgpCommissioningNotificationCmdPayload.sZgpdCommandPayload.pu8Data + 3;
                    }

                    sZgpCommissioningNotificationCmdPayload.u32ZgpdSecFrameCounter = *pu8Data++;
                    sZgpCommissioningNotificationCmdPayload.u32ZgpdSecFrameCounter |= (*pu8Data++) << 8;
                    sZgpCommissioningNotificationCmdPayload.u32ZgpdSecFrameCounter |= (*pu8Data++) << 16;
                    sZgpCommissioningNotificationCmdPayload.u32ZgpdSecFrameCounter |= (*pu8Data++) << 24;
                    sZgpDataIndication.u32SecFrameCounter = sZgpCommissioningNotificationCmdPayload.u32ZgpdSecFrameCounter;
                }
            }
        }

        if(!psGpCustomDataStructure->bIsCommissionIndGiven)
        {
            /* If it is not present in sink table */
            if(!bIsSinkEntryPresent)
            {
                sSinkTableEntry.u8GroupCastRadius = GP_GROUPCAST_RADIUS;
            }
            /* Update pairing information in Sink Table */
            u8Status = eGP_UpdateSinkTable(
                            psEndPointDefinition,
                            psGpCustomDataStructure,
                            &sSinkTableEntry,
                            sZgpCommissionIndication.psGpToZclCommandInfo,
                            (uint8)sZgpDataIndication.u2ApplicationId,
                            sZgpDataIndication.uZgpdDeviceAddr,
                            u8SecLevel,
                            u8SecKeyType,
                            b8ZgpsCommModeAttr,
                            sZgpCommissioningNotificationCmdPayload.u32ZgpdSecFrameCounter,
                            sZgpCommissionIndication.eStatus,
                            bIsSeqNumCap,
                            bIsRxOnCap,
                            bIsFixedLocation);
        }
        else
        {
            u8Status = E_GP_SINK_TABLE_SUCCESS;
        }
#endif
        //If device is in remote pairing mode then exit the commission mode
        if(psGpCustomDataStructure->eGreenPowerDeviceMode == E_GP_REMOTE_COMMISSION_MODE)
        {
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


            return u8Status;
        }
#ifdef GP_COMBO_MIN_DEVICE
        /* Make Device Announce, if entry added to sink table and device is self pairing mode */
        if(u8Status == E_GP_SINK_TABLE_SUCCESS)
        {
            /* check RxAfter Flag, if it is TRUE, sink has to send Commission Reply command, it wait for Dmax delay */
            if( (sZgpCommissioningNotificationCmdPayload.b16Options & GP_CMSNG_NOTIFICATION_APPOINT_TEMP_MASTER_MASK) &&
                ((psGpCustomDataStructure->u3CommissionReplySentCount == 0)||
                (psGpCustomDataStructure->u3CommissionReplySentCount == 2)||
                (psGpCustomDataStructure->u3CommissionReplySentCount == 4)))
            {
                u8Status = eGp_BufferTransmissionPacket(
                                    &sZgpDataIndication,
                                    E_GP_RESPONSE,
                                    psGpCustomDataStructure);
            }
            else if(!(sZgpCommissioningNotificationCmdPayload.b16Options & GP_CMSNG_NOTIFICATION_APPOINT_TEMP_MASTER_MASK))
            {
               u8Status = eGP_UpdateApsGroupTableAndDeviceAnnounce(
                                        psEndPointDefinition,
                                        psGpCustomDataStructure,
                                        &sSinkTableEntry,
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
    }

    // release mutex
    #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


    return u8Status;
}
#endif

#ifdef GP_PROXY_DEVICE
/****************************************************************************
 **
 ** NAME:       eGP_HandleZgpPairing
 **
 ** DESCRIPTION:
 ** Handles Green power Cluster ZGP pairing command
 **
 ** PARAMETERS:               Name                      Usage
 ** ZPS_tsAfEvent            *pZPSevent                 Zigbee stack event structure
 ** tsZCL_EndPointDefinition *psEndPointDefinition      EP structure
 ** tsZCL_ClusterInstance    *psClusterInstance         Cluster structure
 ** uint16                    u16Offset                 offset
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/

PUBLIC teZCL_Status eGP_HandleZgpPairing(
                    ZPS_tsAfEvent                  *pZPSevent,
                    tsZCL_EndPointDefinition       *psEndPointDefinition,
                    tsZCL_ClusterInstance          *psClusterInstance,
                    uint16                         u16Offset)
{
    tsGP_GreenPowerCustomData                   *psGpCustomDataStructure;
    tsGP_ZgpPairingCmdPayload                   sZgpPairingCmdPayload;
    tsGP_ZgppProxyTable                         sProxyTableEntry;
    teZCL_Status                                eStatus;
    uint8 										u8CommunicationMode;
    uint8                                       u8ApplicationId, i;
    bool_t                                      bIsProxyEntryPresent;
    teGP_GreenPowerSecLevel    eSecLevel;
    teGP_GreenPowerSecKeyType  eSecKeyType;
        // initialise pointer
    psGpCustomDataStructure = (tsGP_GreenPowerCustomData *)psClusterInstance->pvEndPointCustomStructPtr;

    // get EP mutex
    #ifndef COOPERATIVE
        eZCL_GetMutex(psEndPointDefinition);
    #endif


    // fill in callback event structure
    eZCL_SetCustomCallBackEvent(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent,
                pZPSevent, 0, psEndPointDefinition->u8EndPointNumber);

    // get information
    eStatus = eGP_ZgpPairingReceive(
                                pZPSevent,
                                u16Offset,
                                &sZgpPairingCmdPayload);

    /* Check Status */
    if(eStatus != E_ZCL_SUCCESS)
    {
        // release mutex
        #ifndef COOPERATIVE
            eZCL_ReleaseMutex(psEndPointDefinition);
        #endif


        return eStatus;
    }

    u8ApplicationId = (uint8)(sZgpPairingCmdPayload.b24Options & GP_APPLICATION_ID_MASK);

    bIsProxyEntryPresent = bGP_IsProxyTableEntryPresent(psEndPointDefinition->u8EndPointNumber,
                                               u8ApplicationId,
                                               &sZgpPairingCmdPayload.uZgpdDeviceAddr,
                                               E_GP_PROXY_TABLE_GET_ENTRY,
                                               &sProxyTableEntry);

    if((bIsProxyEntryPresent)&&(sProxyTableEntry.b16Options & GP_PROXY_TABLE_ENTRY_ACTIVE_MASK))
    {
        if(((psGpCustomDataStructure->eGreenPowerDeviceMode == E_GP_OPERATING_MODE)&&
                (!(sProxyTableEntry.b16Options & GP_PROXY_TABLE_ENTRY_VALID_MASK))))
        {
            // release mutex
            #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


            return eStatus;
        }
        if(sZgpPairingCmdPayload.b24Options & GP_PAIRING_REMOVE_GPD_MASK )
        {
#ifdef CLD_GP_ATTR_ZGPP_BLOCKED_GPD_ID
             /* TBD */
#else
            //sProxyTableEntry.b16Options |= ~GP_PROXY_TABLE_ENTRY_ACTIVE_MASK;
            eGP_RemoveProxyTableEntry(psEndPointDefinition->u8EndPointNumber, &sProxyTableEntry);
#endif
        }
        else
        {
            if(!(sZgpPairingCmdPayload.b24Options & GP_PAIRING_ADD_SINK_MASK ))
            {
                u8CommunicationMode = (sZgpPairingCmdPayload.b24Options & GP_PAIRING_COMM_MODE_MASK) >> 5;

                if((sProxyTableEntry.b16Options & GP_PROXY_TABLE_COMMISSION_GROUP_GPS_MASK)&&
                        (sProxyTableEntry.u8SinkGroupListEntries != 0)&&(u8CommunicationMode == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID))
                {
                    for(i=0;i < sProxyTableEntry.u8SinkGroupListEntries; i++)
                    {
                        if(sZgpPairingCmdPayload.u16SinkGroupID == sProxyTableEntry.asSinkGroupList[i].u16SinkGroup)
                        {
                            sProxyTableEntry.asSinkGroupList[i].u16SinkGroup = sProxyTableEntry.asSinkGroupList[sProxyTableEntry.u8SinkGroupListEntries - 1].u16SinkGroup;
                            sProxyTableEntry.asSinkGroupList[i].u16Alias = sProxyTableEntry.asSinkGroupList[sProxyTableEntry.u8SinkGroupListEntries - 1].u16Alias;
                            sProxyTableEntry.u8SinkGroupListEntries--;
                            if(sProxyTableEntry.u8SinkGroupListEntries == 0)
                            {
                                //sProxyTableEntry.u8SearchCounter = 0;
#ifdef CLD_GP_ATTR_ZGPP_BLOCKED_GPD_ID
             /* TBD */
#else
                                //sProxyTableEntry.b16Options |= ~GP_PROXY_TABLE_ENTRY_ACTIVE_MASK;
                                if(sProxyTableEntry.b16Options & GP_PROXY_TABLE_DERIVED_GROUP_GPS_MASK)
                                {
                                    sProxyTableEntry.b16Options &= ~GP_PROXY_TABLE_COMMISSION_GROUP_GPS_MASK;
                                }
                                else
                                {
                                    eGP_RemoveProxyTableEntry(psEndPointDefinition->u8EndPointNumber, &sProxyTableEntry);
                                }
#endif
                            }
                            bGP_IsProxyTableEntryPresent(psEndPointDefinition->u8EndPointNumber,
                                                         u8ApplicationId,
                                                         &sZgpPairingCmdPayload.uZgpdDeviceAddr,
                                                         E_GP_PROXY_TABLE_SET_ENTRY,
                                                         &sProxyTableEntry);
                            break;
                        }
                    }
                }
                if(u8CommunicationMode == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_DGROUP_ID)
                {
                    if(sProxyTableEntry.b16Options & GP_PROXY_TABLE_DERIVED_GROUP_GPS_MASK)
                    {
                        if(sProxyTableEntry.b16Options & GP_PROXY_TABLE_COMMISSION_GROUP_GPS_MASK)
                        {
                            sProxyTableEntry.b16Options &= ~GP_PROXY_TABLE_DERIVED_GROUP_GPS_MASK;
                            bGP_IsProxyTableEntryPresent(psEndPointDefinition->u8EndPointNumber,
                                                         u8ApplicationId,
                                                         &sZgpPairingCmdPayload.uZgpdDeviceAddr,
                                                         E_GP_PROXY_TABLE_SET_ENTRY,
                                                         &sProxyTableEntry);
                        }
                        else
                        {
                            eGP_RemoveProxyTableEntry(psEndPointDefinition->u8EndPointNumber, &sProxyTableEntry);
                        }
                    }
                }
            }
            else
            {
                sProxyTableEntry.b16Options |= GP_PROXY_TABLE_ENTRY_VALID_MASK;
                u8CommunicationMode = (sZgpPairingCmdPayload.b24Options & GP_PAIRING_COMM_MODE_MASK) >> 5;
                if(u8CommunicationMode == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_DGROUP_ID)
                {
                    sProxyTableEntry.b16Options |= GP_PROXY_TABLE_DERIVED_GROUP_GPS_MASK;
                }
                else if(u8CommunicationMode == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID)
                {
                    sProxyTableEntry.b16Options |= GP_PROXY_TABLE_COMMISSION_GROUP_GPS_MASK;
                }

                if((sProxyTableEntry.b16Options & GP_PROXY_TABLE_COMMISSION_GROUP_GPS_MASK)&&
                   (u8CommunicationMode == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID))
                {
                    for(i=0;i < sProxyTableEntry.u8SinkGroupListEntries; i++)
                    {
                        if(sZgpPairingCmdPayload.u16SinkGroupID == sProxyTableEntry.asSinkGroupList[i].u16SinkGroup)
                        {
                            break;
                        }
                    }
                    if((i == sProxyTableEntry.u8SinkGroupListEntries)&&(sProxyTableEntry.u8SinkGroupListEntries < GP_MAX_SINK_GROUP_LIST))
                    {
                        sProxyTableEntry.asSinkGroupList[sProxyTableEntry.u8SinkGroupListEntries].u16SinkGroup = sZgpPairingCmdPayload.u16SinkGroupID;
                        sProxyTableEntry.asSinkGroupList[sProxyTableEntry.u8SinkGroupListEntries].u16Alias = sZgpPairingCmdPayload.u16AssignedAlias;
                        sProxyTableEntry.u8SinkGroupListEntries++;
                        eStatus = ZPS_eAplZdoGroupEndpointAdd(sZgpPairingCmdPayload.u16SinkGroupID, ZCL_GP_PROXY_ENDPOINT_ID);
                        /* Check Status */
                        if(eStatus != E_ZCL_SUCCESS)
                        {
                            psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_ADDING_GROUP_TABLE_FAIL;
                            psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.uMessage.eAddGroupTableStatus = eStatus;
                           /* Give Application Callback for sink table update */
                            psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);
                        }
                    }
                }

                if(sZgpPairingCmdPayload.b24Options & GP_PAIRING_GPD_FIXED_MASK)
                {
                    sProxyTableEntry.b16Options |= GP_PROXY_TABLE_GPD_FIXED_MASK;
                }

                if(sZgpPairingCmdPayload.b24Options & GP_PAIRING_SEQ_NUM_CAP_MASK)
                {
                    sProxyTableEntry.b16Options |= GP_PROXY_TABLE_SEQ_NUM_CAP_MASK;
                }

                eSecLevel = (sZgpPairingCmdPayload.b24Options & GP_PAIRING_SEC_LEVEL_MASK) >> 9;
                eSecKeyType = (sZgpPairingCmdPayload.b24Options & GP_PAIRING_SEC_KEY_TYPE_MASK) >> 11;
                //if security key is available
                if(eSecLevel != E_GP_NO_SECURITY)
                {
                    sProxyTableEntry.b16Options |= GP_PROXY_TABLE_SECURITY_USE_MASK;
                    sProxyTableEntry.b8SecOptions = eSecLevel;
                    sProxyTableEntry.b8SecOptions |= eSecKeyType << 2;
                }
                else
                {
                    sProxyTableEntry.b16Options &= ~GP_PROXY_TABLE_SECURITY_USE_MASK;
                }

                if(sZgpPairingCmdPayload.b24Options & GP_PAIRING_SECURITY_COUNTER_PRESENT_MASK)
                {
                    sProxyTableEntry.u32ZgpdSecFrameCounter = sZgpPairingCmdPayload.u32ZgpdSecFrameCounter;
                }

                if(sZgpPairingCmdPayload.b24Options & GP_PAIRING_SECURITY_KEY_PRESENT_MASK)
                {
                    memcpy(&sProxyTableEntry.sZgpdKey.au8Key, sZgpPairingCmdPayload.sZgpdKey.au8Key, E_ZCL_KEY_128_SIZE);
                }

                if((sZgpPairingCmdPayload.b24Options & GP_PAIRING_ASSIGNED_ALIAS_PRESENT_MASK)&&
                   (u8CommunicationMode == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_DGROUP_ID))
                {
                    sProxyTableEntry.u16ZgpdAssignedAlias = sZgpPairingCmdPayload.u16AssignedAlias;
                    sProxyTableEntry.b16Options |= GP_PROXY_TABLE_ASSIGNED_ALIAS_MASK;
                }

                if(sZgpPairingCmdPayload.b24Options & GP_PAIRING_FORWARDING_RADIUS_PRESENT_MASK)
                {
                    sProxyTableEntry.u8GroupCastRadius = sZgpPairingCmdPayload.u8ForwardingRadius;
                }
                bGP_IsProxyTableEntryPresent(psEndPointDefinition->u8EndPointNumber,
                                                               u8ApplicationId,
                                                               &sZgpPairingCmdPayload.uZgpdDeviceAddr,
                                                               E_GP_PROXY_TABLE_SET_ENTRY,
                                                               &sProxyTableEntry);

            }
        }
        //pairing success
        if(psGpCustomDataStructure->eGreenPowerDeviceMode == E_GP_REMOTE_COMMISSION_MODE)
        {
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
        }
    }

    // release mutex
    #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


    return eStatus;

}
#endif

#ifdef GP_COMBO_MIN_DEVICE
#ifndef GP_DISABLE_TRANSLATION_TABLE_REQ_CMD
/****************************************************************************
 **
 ** NAME:       eGP_HandleZgpTranslationRequest
 **
 ** DESCRIPTION:
 ** Handles Green power Cluster ZGP translation request command
 **
 ** PARAMETERS:               Name                      Usage
 ** ZPS_tsAfEvent            *pZPSevent                 Zigbee stack event structure
 ** tsZCL_EndPointDefinition *psEndPointDefinition      EP structure
 ** tsZCL_ClusterInstance    *psClusterInstance         Cluster structure
 ** uint16                    u16Offset                 offset
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/

PUBLIC teZCL_Status eGP_HandleZgpTranslationRequest(
                    ZPS_tsAfEvent                  *pZPSevent,
                    tsZCL_EndPointDefinition       *psEndPointDefinition,
                    tsZCL_ClusterInstance          *psClusterInstance,
                    uint16                         u16Offset)
{
    tsGP_GreenPowerCustomData                   *psGpCustomDataStructure;
    tsGP_ZgpTransTableResponseCmdPayload        sZgpTransRspCmdPayload;
    teZCL_Status                                eStatus;
    uint8                                       u8Count = 0,u8TotalCount = 0, i, u8TransactionSequenceNumber, u8StartIndex;
    tsZCL_Address                               sZCL_Address;
    uint16                                      u16hApduSize, u16PayloadSize = 3/* header size */;
#ifdef GP_IEEE_ADDR_SUPPORT
    uint8 j;
#endif
    // initialise pointer
    psGpCustomDataStructure = (tsGP_GreenPowerCustomData *)psClusterInstance->pvEndPointCustomStructPtr;


    // get EP mutex
    #ifndef COOPERATIVE
        eZCL_GetMutex(psEndPointDefinition);
    #endif


    // fill in callback event structure
    eZCL_SetCustomCallBackEvent(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent,
                pZPSevent, 0, psEndPointDefinition->u8EndPointNumber);

    // get information
    eStatus = eGP_ZgpTranslationTableRequestReceive(
                                pZPSevent,
                                &u8StartIndex);

    /* Check Status */
    if(eStatus != E_ZCL_SUCCESS)
    {
        // release mutex
        #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


        return eStatus;
    }
    /* Get hAPdu Size */
    u16hApduSize = PDUM_u16APduGetSize(hZCL_GetBufferPoolHandle());

    sZgpTransRspCmdPayload.u8Status = E_ZCL_SUCCESS;
    sZgpTransRspCmdPayload.b8Options = GP_APPL_ID_4_BYTE;
    /* Traverse translation table */
    for(i = 0; i < psGpCustomDataStructure->u8NoOfTranslationTableEntries; i++)
    {
        /* check for translation pointer is populated or not */
        if(psGpCustomDataStructure->psZgpsTranslationTableEntry[i].psGpToZclCmdInfo != NULL)
        {
            u8TotalCount++;
        }
    }

    sZgpTransRspCmdPayload.u8TotalNumOfEntries = u8TotalCount;
#ifdef GP_IEEE_ADDR_SUPPORT
    /* Traverse translation table 2 times - first for GP_APPL_ID_4_BYTE and second for GP_APPL_ID_8_BYTE */
    for(j = 0; j < 2; j++)
    {
#endif
        sZgpTransRspCmdPayload.u8StartIndex = u8StartIndex;

        if(u8StartIndex < psGpCustomDataStructure->u8NoOfTranslationTableEntries)
        {
            /* Traverse translation table */
            for(i = u8StartIndex; i < psGpCustomDataStructure->u8NoOfTranslationTableEntries; i++)
            {
                /* check for translation pointer is populated or not */
                if((psGpCustomDataStructure->psZgpsTranslationTableEntry[i].psGpToZclCmdInfo != NULL)&&
                  (psGpCustomDataStructure->psZgpsTranslationTableEntry[i].b8Options == sZgpTransRspCmdPayload.b8Options))
                {
                    u8Count++;

                    if(u8Count == 1)
                    {
                        sZgpTransRspCmdPayload.u8StartIndex = i;
                    }
                }
            }
        }

        if(u8Count)
        {
            sZgpTransRspCmdPayload.u8EntriesCount = u8Count;
            u8Count = 0;
            u16PayloadSize += 5; //length of first 5 field of translation table response command payload
            /* Traverse translation table */
            for(i = u8StartIndex; i < psGpCustomDataStructure->u8NoOfTranslationTableEntries; i++)
            {
                /* check for translation pointer is populated or not */
                if((psGpCustomDataStructure->psZgpsTranslationTableEntry[i].psGpToZclCmdInfo != NULL)&&
                   (psGpCustomDataStructure->psZgpsTranslationTableEntry[i].b8Options == sZgpTransRspCmdPayload.b8Options))
                {
                    sZgpTransRspCmdPayload.asTransTblRspEntry[u8Count].uZgpdDeviceAddr =
                            psGpCustomDataStructure->psZgpsTranslationTableEntry[i].uZgpdDeviceAddr;

                    if(sZgpTransRspCmdPayload.b8Options == GP_APPL_ID_4_BYTE)
                    {
                        u16PayloadSize += 4;
                    }
                    else
                    {
                        u16PayloadSize += 8;
                    }
                    sZgpTransRspCmdPayload.asTransTblRspEntry[u8Count].eZgpdCommandId = psGpCustomDataStructure->psZgpsTranslationTableEntry[i].psGpToZclCmdInfo->eZgpdCommandId;
                    sZgpTransRspCmdPayload.asTransTblRspEntry[u8Count].u8EndpointId = psGpCustomDataStructure->psZgpsTranslationTableEntry[i].psGpToZclCmdInfo->u8EndpointId;
                    if(sZgpTransRspCmdPayload.asTransTblRspEntry[u8Count].u8EndpointId == 0xFD)
                    {
                        sZgpTransRspCmdPayload.asTransTblRspEntry[u8Count].u16ProfileID = 0xFFFF;
                    }
                    else
                    {
                        sZgpTransRspCmdPayload.asTransTblRspEntry[u8Count].u16ProfileID = psGpCustomDataStructure->u16ProfileId;
                    }
                    sZgpTransRspCmdPayload.asTransTblRspEntry[u8Count].u16ZbClusterId = psGpCustomDataStructure->psZgpsTranslationTableEntry[i].psGpToZclCmdInfo->u16ZbClusterId;
                    sZgpTransRspCmdPayload.asTransTblRspEntry[u8Count].u8ZbCommandId = psGpCustomDataStructure->psZgpsTranslationTableEntry[i].psGpToZclCmdInfo->u8ZbCommandId;
                    sZgpTransRspCmdPayload.asTransTblRspEntry[u8Count].u8ZbCmdLength = psGpCustomDataStructure->psZgpsTranslationTableEntry[i].psGpToZclCmdInfo->u8ZbCmdLength;
                    u16PayloadSize += 8; // length of fix fields of translation table list field

                    if((psGpCustomDataStructure->psZgpsTranslationTableEntry[i].psGpToZclCmdInfo->u8ZbCmdLength  != 0)&&
                      (psGpCustomDataStructure->psZgpsTranslationTableEntry[i].psGpToZclCmdInfo->u8ZbCmdLength  != 0xFF))
                    {
                        memcpy(sZgpTransRspCmdPayload.asTransTblRspEntry[u8Count].au8ZbCmdPayload,
                                psGpCustomDataStructure->psZgpsTranslationTableEntry[i].psGpToZclCmdInfo->au8ZbCmdPayload,
                                psGpCustomDataStructure->psZgpsTranslationTableEntry[i].psGpToZclCmdInfo->u8ZbCmdLength);
                        u16PayloadSize += psGpCustomDataStructure->psZgpsTranslationTableEntry[i].psGpToZclCmdInfo->u8ZbCmdLength; // length of ZB command payload of translation table list field
                    }
                    /* check if payload size increase by APDU size than send till last entry updated */
                    if(u16hApduSize < u16PayloadSize)
                    {
                        sZgpTransRspCmdPayload.u8EntriesCount = u8Count;
                        break;
                    }

                    u8Count++;

                    if(u8Count >= GP_MAX_TRANSLATION_RESPONSE_ENTRY)
                    {
                        sZgpTransRspCmdPayload.u8EntriesCount = u8Count;
                        break;
                    }
                }
            }
        }
        else
        {
            sZgpTransRspCmdPayload.u8EntriesCount = 0;
        }

        // build address structure
        eZCL_BuildTransmitAddressStructure(pZPSevent, &sZCL_Address);
#ifndef GP_DISABLE_TRANSLATION_TABLE_RSP_CMD
        eStatus = eGP_ZgpTranslationTableResponseSend(
                            pZPSevent->uEvent.sApsDataIndEvent.u8DstEndpoint,
                            pZPSevent->uEvent.sApsDataIndEvent.u8SrcEndpoint,
                            &sZCL_Address,
                            &u8TransactionSequenceNumber,
                            &sZgpTransRspCmdPayload);
#endif
#ifdef GP_IEEE_ADDR_SUPPORT
        sZgpTransRspCmdPayload.b8Options = GP_APPL_ID_8_BYTE;
        u8Count = 0;
    }
#endif
    // release mutex
    #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


    return eStatus;

}
#endif
#ifndef GP_DISABLE_TRANSLATION_TABLE_RSP_CMD
/****************************************************************************
 **
 ** NAME:       eGP_HandleZgpTranslationResponse
 **
 ** DESCRIPTION:
 ** Handles Green power Cluster ZGP translation response command
 **
 ** PARAMETERS:               Name                      Usage
 ** ZPS_tsAfEvent            *pZPSevent                 Zigbee stack event structure
 ** tsZCL_EndPointDefinition *psEndPointDefinition      EP structure
 ** tsZCL_ClusterInstance    *psClusterInstance         Cluster structure
 ** uint16                    u16Offset                 offset
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/

PUBLIC teZCL_Status eGP_HandleZgpTranslationResponse(
                    ZPS_tsAfEvent                  *pZPSevent,
                    tsZCL_EndPointDefinition       *psEndPointDefinition,
                    tsZCL_ClusterInstance          *psClusterInstance,
                    uint16                         u16Offset)
{
    tsGP_GreenPowerCustomData                   *psGpCustomDataStructure;
    tsGP_ZgpTransTableResponseCmdPayload        sZgpTransRspCmdPayload;
    teZCL_Status                                eStatus;

    // initialise pointer
    psGpCustomDataStructure = (tsGP_GreenPowerCustomData *)psClusterInstance->pvEndPointCustomStructPtr;


    // get EP mutex
    #ifndef COOPERATIVE
        eZCL_GetMutex(psEndPointDefinition);
    #endif


    // fill in callback event structure
    eZCL_SetCustomCallBackEvent(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent,
                pZPSevent, 0, psEndPointDefinition->u8EndPointNumber);

    // get information
    eStatus = eGP_ZgpTranslationTableResponseReceive(
                                pZPSevent,
                                u16Offset,
                                &sZgpTransRspCmdPayload);

    /* Check Status */
    if(eStatus != E_ZCL_SUCCESS)
    {
        // release mutex
        #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


        return eStatus;
    }

    psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_TRANSLATION_TABLE_RESPONSE_RCVD;
    psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.uMessage.psZgpTransRspCmdPayload =
                                                                 &sZgpTransRspCmdPayload;

    /* Give Application Callback to pass received Translation table response */
    psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);

    // release mutex
    #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


    return eStatus;

}
#endif
/****************************************************************************
 **
 ** NAME:       eGP_HandleZgpTranslationTableUpdate
 **
 ** DESCRIPTION:
 ** Handles Green power Cluster ZGP Translation table update command
 **
 ** PARAMETERS:               Name                      Usage
 ** ZPS_tsAfEvent            *pZPSevent                 Zigbee stack event structure
 ** tsZCL_EndPointDefinition *psEndPointDefinition      EP structure
 ** tsZCL_ClusterInstance    *psClusterInstance         Cluster structure
 ** uint16                    u16Offset                 offset
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/

PUBLIC teZCL_Status eGP_HandleZgpTranslationTableUpdate(
                    ZPS_tsAfEvent                  *pZPSevent,
                    tsZCL_EndPointDefinition       *psEndPointDefinition,
                    tsZCL_ClusterInstance          *psClusterInstance,
                    uint16                         u16Offset)
{
    tsGP_GreenPowerCustomData                   *psGpCustomDataStructure;
    tsGP_ZgpTranslationUpdateCmdPayload         sZgpTransTableUpdatePayload;
    teZCL_Status                                eStatus;
    uint8                                       u8ApplicationId, i, u8NumbersOfTranslations;
    bool_t                                      bTransUpdateFail = FALSE;
    teGP_TranslationTableUpdateAction eAction;
    uint16 u16ClusterId;
    uint8 u8EndPointIndex = 0;
    
    // initialise pointer
    psGpCustomDataStructure = (tsGP_GreenPowerCustomData *)psClusterInstance->pvEndPointCustomStructPtr;

    // get EP mutex
    #ifndef COOPERATIVE
        eZCL_GetMutex(psEndPointDefinition);
    #endif


    // fill in callback event structure
    eZCL_SetCustomCallBackEvent(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent,
                pZPSevent, 0, psEndPointDefinition->u8EndPointNumber);

    // get information
    eStatus = eGP_ZgpTranslationTableUpdateReceive(
                                pZPSevent,
                                u16Offset,
                                &sZgpTransTableUpdatePayload);

    /* Check Status */
    if(eStatus != E_ZCL_SUCCESS)
    {
        // release mutex
        #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


        return eStatus;
    }

    u8ApplicationId = sZgpTransTableUpdatePayload.b16Options & GP_APPLICATION_ID_MASK;
    eAction = (sZgpTransTableUpdatePayload.b16Options & GP_TRANS_UPDATE_ACTION_MASK) >> 3;

    if(((u8ApplicationId != GP_APPL_ID_4_BYTE)&&(u8ApplicationId != GP_APPL_ID_8_BYTE))||(eAction > E_GP_TRANSLATION_TABLE_REMOVE_ENTRY))
    {
        // release mutex
        #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


        return E_ZCL_ERR_INVALID_VALUE;
    }

    u8NumbersOfTranslations = (sZgpTransTableUpdatePayload.b16Options & GP_TRANS_UPDATE_NUM_OF_TRANSLATIONS_MASK) >> 5;

    for(i=0; i<u8NumbersOfTranslations; i++)
    {
        u16ClusterId = sZgpTransTableUpdatePayload.asTranslationUpdateEntry[i].u16ZbClusterId;

        if(u16ClusterId == 0xFFFF)
        {
            u16ClusterId = u16GP_GetClusterId(sZgpTransTableUpdatePayload.asTranslationUpdateEntry[i].eZgpdCommandId);
        }

        if (((sZgpTransTableUpdatePayload.asTranslationUpdateEntry[i].u8Index < GP_NUMBER_OF_TRANSLATION_TABLE_ENTRIES)||
          (sZgpTransTableUpdatePayload.asTranslationUpdateEntry[i].u8Index == 0xFF))&&
          (TRUE == bGP_IsZgpdCommandSupported(sZgpTransTableUpdatePayload.asTranslationUpdateEntry[i].eZgpdCommandId,sZgpTransTableUpdatePayload.asTranslationUpdateEntry[i].u8ZbCommandId, u16ClusterId ))&&
          ((eZCL_SearchForEPIndex(sZgpTransTableUpdatePayload.asTranslationUpdateEntry[i].u8EndpointId,&u8EndPointIndex) == E_ZCL_SUCCESS) || (sZgpTransTableUpdatePayload.asTranslationUpdateEntry[i].u8EndpointId == 0xFF))&&
          (sZgpTransTableUpdatePayload.asTranslationUpdateEntry[i].u16ProfileID == psGpCustomDataStructure->u16ProfileId))
        {

            tsGP_ZgpsTranslationTableUpdate sZgpsTransTableUpdate;

            psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_TRANSLATION_TABLE_UPDATE;
            sZgpsTransTableUpdate.eAction = eAction;
            sZgpsTransTableUpdate.eStatus = E_GP_TRANSLATION_UPDATE_SUCCESS;
            sZgpsTransTableUpdate.u8ApplicationId = u8ApplicationId;
            sZgpsTransTableUpdate.uZgpdDeviceAddr = sZgpTransTableUpdatePayload.uZgpdDeviceAddr;
            sZgpsTransTableUpdate.psTranslationUpdateEntry = &sZgpTransTableUpdatePayload.asTranslationUpdateEntry[i];

            psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.uMessage.psTransationTableUpdate =
                                                                         &sZgpsTransTableUpdate;

            /* Give Application Callback to pass received Translation table response */
            psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);

            if(psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.uMessage.psTransationTableUpdate->eStatus == E_GP_TRANSLATION_UPDATE_FAIL)
            {
                bTransUpdateFail = TRUE;
            }

        }
        else
        {
            bTransUpdateFail = TRUE;
        }
    }

    if(bTransUpdateFail)
    {
        eZCL_SendDefaultResponse(pZPSevent, E_ZCL_CMDS_FAILURE);
        eStatus = E_ZCL_SUCCESS;
    }

    // release mutex
    #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


    return eStatus;

}

#endif
#ifdef GP_PROXY_DEVICE
#ifndef GP_DISABLE_ZGP_RESPONSE_CMD
/****************************************************************************
 **
 ** NAME:       eGP_HandleZgpReponse
 **
 ** DESCRIPTION:
 ** Handles Green power Cluster ZGP Response Command
 **
 ** PARAMETERS:               Name                      Usage
 ** ZPS_tsAfEvent            *pZPSevent                 Zigbee stack event structure
 ** tsZCL_EndPointDefinition *psEndPointDefinition      EP structure
 ** tsZCL_ClusterInstance    *psClusterInstance         Cluster structure
 ** uint16                    u16Offset                 offset
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/

PUBLIC teZCL_Status eGP_HandleZgpReponse(
                    ZPS_tsAfEvent                  *pZPSevent,
                    tsZCL_EndPointDefinition       *psEndPointDefinition,
                    tsZCL_ClusterInstance          *psClusterInstance,
                    uint16                         u16Offset)
{
    tsGP_GreenPowerCustomData                   *psGpCustomDataStructure;
    tsGP_ZgpResponseCmdPayload                  sZgpResponseCmdPayload;
    teZCL_Status                                eStatus = E_ZCL_SUCCESS;
    uint8                                       au8Payload[GP_MAX_ZB_CMD_PAYLOAD_LENGTH] = {0},i;
    ZPS_teStatus                                eZPSStatus;
    ZPS_tsZgpGreenPowerReq                      sZgpDataReq;
    PDUM_thAPduInstance                         hAPduInst;
    tsGP_ZgppProxyTable                         sZgppProxyTable;
    bool_t                                      bIsProxyTableEntryPresent = FALSE;
    uint8 *pu8Start;
    /* Get the psGpCustomDataStructure */
    psGpCustomDataStructure = (tsGP_GreenPowerCustomData*)psClusterInstance->pvEndPointCustomStructPtr;

    // get EP mutex
    #ifndef COOPERATIVE
        eZCL_GetMutex(psEndPointDefinition);
    #endif


    /* Initialise string pointer for pay load */
    sZgpResponseCmdPayload.sZgpdCommandPayload.pu8Data = au8Payload;
    sZgpResponseCmdPayload.sZgpdCommandPayload.u8Length = 0;
    sZgpResponseCmdPayload.sZgpdCommandPayload.u8MaxLength = GP_MAX_ZB_CMD_PAYLOAD_LENGTH;

    /* Get the GP Response payload from received packet */
    if(eGP_ZgpResponseReceive(
                    pZPSevent,
                    u16Offset,
                    &sZgpResponseCmdPayload) == E_ZCL_SUCCESS)
    {
        /* Check Temp Master field, if it mathces to own network address then add to Tx Queue for transmission to GPD */
        uint16 u16NwkAddr = 0;

#ifndef PC_PLATFORM_BUILD
        u16NwkAddr = ZPS_u16AplZdoGetNwkAddr();
#endif

        memset(&sZgppProxyTable, 0, sizeof(tsGP_ZgppProxyTable));

        bIsProxyTableEntryPresent = bGP_IsProxyTableEntryPresent(
                                    psEndPointDefinition->u8EndPointNumber,
                                    sZgpResponseCmdPayload.b8Options,
                                    &sZgpResponseCmdPayload.uZgpdDeviceAddr,
                                    E_GP_PROXY_TABLE_GET_ENTRY,
                                    &sZgppProxyTable);

        hAPduInst = hZCL_AllocateAPduInstance();
        /* check buffer size */
        if((hAPduInst == PDUM_INVALID_HANDLE)||
           (PDUM_u16APduGetSize(hZCL_GetBufferPoolHandle()) < sZgpResponseCmdPayload.sZgpdCommandPayload.u8Length))
        {
            // free buffer and return
            PDUM_eAPduFreeAPduInstance(hAPduInst);
            // release mutex
            #ifndef COOPERATIVE
                eZCL_ReleaseMutex(psEndPointDefinition);
            #endif


            return E_ZCL_ERR_ZBUFFER_FAIL;
        }
        pu8Start = (uint8 *)(PDUM_pvAPduInstanceGetPayload(hAPduInst));

        for(i = 0; i<sZgpResponseCmdPayload.sZgpdCommandPayload.u8Length;i++)
        {
            *pu8Start++ = sZgpResponseCmdPayload.sZgpdCommandPayload.pu8Data[i];
        }
        PDUM_eAPduInstanceSetPayloadSize(hAPduInst, sZgpResponseCmdPayload.sZgpdCommandPayload.u8Length);

        sZgpDataReq.u8TxOptions = 0x01;
        sZgpDataReq.bDataFrame = TRUE;
        sZgpDataReq.u8ApplicationId = sZgpResponseCmdPayload.b8Options;

        if(sZgpDataReq.u8ApplicationId == GP_APPL_ID_4_BYTE)
        {
            sZgpDataReq.uGpId.u32SrcId = sZgpResponseCmdPayload.uZgpdDeviceAddr.u32ZgpdSrcId;
        }
#ifdef GP_IEEE_ADDR_SUPPORT
        else
        {
            sZgpDataReq.uGpId.u64Address = sZgpResponseCmdPayload.uZgpdDeviceAddr.u64ZgpdIEEEAddr;
        }
#endif
        sZgpDataReq.u16TxQueueEntryLifetime = 5000; //5 sec
        sZgpDataReq.u8Handle = u8GP_GetDataReqHandle(psGpCustomDataStructure);
        sZgpDataReq.u8SeqNum = u8GetTransactionSequenceNumber();
        sZgpDataReq.u16Panid = 0xFFFF;
        sZgpDataReq.u16DstAddr = 0xFFFF;

        if(u16NwkAddr == sZgpResponseCmdPayload.u16TempMasterShortAddr)
        {
            /* Add to Tx Queue of Stack for sending GP channel configuration */
            if(sZgpResponseCmdPayload.eZgpdCmdId == E_GP_CHANNEL_CONFIGURATION)
            {
                psGpCustomDataStructure->u16TransmitChannelTimeout = 250; //5 sec timeout
#ifndef PC_PLATFORM_BUILD
                psGpCustomDataStructure->u8OperationalChannel = ZPS_u8AplZdoGetRadioChannel();
                ZPS_vNwkNibSetChannel( ZPS_pvAplZdoGetNwkHandle(), (sZgpResponseCmdPayload.b8TempMasterTxChannel & 0x0F) + 11);
#endif
                if((sZgpResponseCmdPayload.uZgpdDeviceAddr.u32ZgpdSrcId == 0)&&
                   (sZgpDataReq.u8ApplicationId == GP_APPL_ID_4_BYTE))
                {
                    sZgpDataReq.bDataFrame = FALSE;
                }
            }
            else if(sZgpResponseCmdPayload.eZgpdCmdId == E_GP_COMMISSIONING_REPLY)
            {
                //sZgpDataReq.u16TxQueueEntryLifetime = psGpCustomDataStructure->u16CommissionWindow*20; //in miliseconds
            }
            sZgppProxyTable.b16Options |= GP_PROXY_TABLE_FIRST_TO_FWD_MASK;

            eZPSStatus = zps_vDStub_DataReq(&sZgpDataReq, hAPduInst,TRUE,(uint8)sZgpResponseCmdPayload.eZgpdCmdId);
            DBG_vPrintf(TRACE_GP_DEBUG, "zps_vDStub_DataReq:%d\r\n", eZPSStatus);
        }
        else
        {
            sZgppProxyTable.b16Options &= ~GP_PROXY_TABLE_FIRST_TO_FWD_MASK;
            eZPSStatus = zps_vDStub_DataReq(&sZgpDataReq, hAPduInst,FALSE,(uint8)sZgpResponseCmdPayload.eZgpdCmdId);
        }

        /* update first to forward flag */
        if(bIsProxyTableEntryPresent)
        {
            bGP_IsProxyTableEntryPresent(psEndPointDefinition->u8EndPointNumber,
                                         sZgpResponseCmdPayload.b8Options,
                                         &sZgpResponseCmdPayload.uZgpdDeviceAddr,
                                         E_GP_PROXY_TABLE_SET_ENTRY,
                                         &sZgppProxyTable);
        }

        // free buffer and return
        PDUM_eAPduFreeAPduInstance(hAPduInst);
    }

    // release mutex
    #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


    return eStatus;
}
#endif
#endif
#ifdef GP_COMBO_MIN_DEVICE
#ifndef GP_DISABLE_PAIRING_SEARCH_CMD
/****************************************************************************
 **
 ** NAME:       eGP_HandleZgpPairingSearch
 **
 ** DESCRIPTION:
 ** Handles Green power Cluster ZGP pairing search command
 **
 ** PARAMETERS:               Name                      Usage
 ** ZPS_tsAfEvent            *pZPSevent                 Zigbee stack event structure
 ** tsZCL_EndPointDefinition *psEndPointDefinition      EP structure
 ** tsZCL_ClusterInstance    *psClusterInstance         Cluster structure
 ** uint16                    u16Offset                 offset
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC teZCL_Status eGP_HandleZgpPairingSearch(
                    ZPS_tsAfEvent                  *pZPSevent,
                    tsZCL_EndPointDefinition       *psEndPointDefinition,
                    tsZCL_ClusterInstance          *psClusterInstance,
                    uint16                         u16Offset)
{
    tsGP_GreenPowerCustomData                   *psGpCustomDataStructure;
    tsGP_ZgpPairingSearchCmdPayload             sZgpPairingSearhPayload;
    teZCL_Status                                eStatus;
    uint8                                       u8ApplicationId, u8TransactionSequenceNumber;
    tsGP_ZgpsSinkTable                          sSinkTableEntry;
    bool_t                                      bSendPairing = FALSE, bIsSinkTableEntryPresent = FALSE;
    tsGP_ZgpPairingCmdPayload                   sZgpPairingPayload;
    tsZCL_Address                               sDestinationAddress;
    ZPS_tsAplZdpDeviceAnnceReq                  sZdpDeviceAnnceReq;
    uint16                                      u16AliasShortAddr;
    PDUM_thAPduInstance                         hAPduInst;
    teGP_GreenPowerCommunicationMode            eCommunicationMode;
    // initialise pointer
    psGpCustomDataStructure = (tsGP_GreenPowerCustomData *)psClusterInstance->pvEndPointCustomStructPtr;

    // get EP mutex
    #ifndef COOPERATIVE
        eZCL_GetMutex(psEndPointDefinition);
    #endif


    // fill in callback event structure
    eZCL_SetCustomCallBackEvent(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent,
                pZPSevent, 0, psEndPointDefinition->u8EndPointNumber);

    // get information
    eStatus = eGP_ZgpPairingSearchReceive(
                                pZPSevent,
                                u16Offset,
                                &sZgpPairingSearhPayload);

    /* Check Status */
    if(eStatus != E_ZCL_SUCCESS)
    {
        // release mutex
        #ifndef COOPERATIVE
            eZCL_ReleaseMutex(psEndPointDefinition);
        #endif


        return eStatus;
    }

    u8ApplicationId = sZgpPairingSearhPayload.b16Options & GP_APPLICATION_ID_MASK;

    if((u8ApplicationId != GP_APPL_ID_4_BYTE)&&(u8ApplicationId != GP_APPL_ID_8_BYTE))
    {
        // release mutex
        #ifndef COOPERATIVE
            eZCL_ReleaseMutex(psEndPointDefinition);
        #endif


        return E_ZCL_ERR_INVALID_VALUE;
    }

    if(sZgpPairingSearhPayload.b16Options & GP_PAIRING_SEARCH_RQST_UNICAST_SINK_MASK)
    {
        eCommunicationMode = E_GP_UNI_FORWARD_ZGP_NOTIFICATION_BY_PROXIES_BOTH;
    }

    bIsSinkTableEntryPresent = bGP_IsSinkTableEntryPresent(psEndPointDefinition->u8EndPointNumber,
                                            u8ApplicationId,
                                            &sZgpPairingSearhPayload.uZgpdDeviceAddr,
                                            E_GP_SINK_TABLE_GET_ENTRY,
                                            &sSinkTableEntry,
                                            eCommunicationMode);

    if(bIsSinkTableEntryPresent == FALSE)
    {
        if(sZgpPairingSearhPayload.b16Options & GP_PAIRING_SEARCH_RQST_DERIVED_GROUPCAST_SINK_MASK)
        {
            eCommunicationMode = E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_DGROUP_ID;
        }

        bIsSinkTableEntryPresent = bGP_IsSinkTableEntryPresent(psEndPointDefinition->u8EndPointNumber,
                                                u8ApplicationId,
                                                &sZgpPairingSearhPayload.uZgpdDeviceAddr,
                                                E_GP_SINK_TABLE_GET_ENTRY,
                                                &sSinkTableEntry,
                                                eCommunicationMode);
    }

    if(bIsSinkTableEntryPresent == FALSE)
    {
        if(sZgpPairingSearhPayload.b16Options & GP_PAIRING_SEARCH_RQST_COMMISSION_GROUPCAST_SINK_MASK)
        {
            eCommunicationMode = E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID;
        }

        bIsSinkTableEntryPresent = bGP_IsSinkTableEntryPresent(psEndPointDefinition->u8EndPointNumber,
                                                u8ApplicationId,
                                                &sZgpPairingSearhPayload.uZgpdDeviceAddr,
                                                E_GP_SINK_TABLE_GET_ENTRY,
                                                &sSinkTableEntry,
                                                eCommunicationMode);
    }


    if(bIsSinkTableEntryPresent)
    {

        /* check requested and supported communication mode */

        /* Get communication mode */
        eCommunicationMode = (sSinkTableEntry.b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3;

        if((eCommunicationMode == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_DGROUP_ID)&&
           (sZgpPairingSearhPayload.b16Options & GP_PAIRING_SEARCH_RQST_DERIVED_GROUPCAST_SINK_MASK))
        {
            bSendPairing = TRUE;
        }
        else if((eCommunicationMode == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID)&&
                (sZgpPairingSearhPayload.b16Options & GP_PAIRING_SEARCH_RQST_COMMISSION_GROUPCAST_SINK_MASK))
        {
            bSendPairing = TRUE;
        }
        if(bSendPairing)
        {
            sZgpPairingPayload.b24Options = u8ApplicationId;
            sZgpPairingPayload.b24Options |= GP_PAIRING_ADD_SINK_MASK;
            sZgpPairingPayload.b24Options |= eCommunicationMode << 5;

            if(sSinkTableEntry.b16Options & GP_SINK_TABLE_FIXED_LOCATION_MASK)
            {
                sZgpPairingPayload.b24Options |= GP_PAIRING_GPD_FIXED_MASK;
            }

            if(sSinkTableEntry.b16Options & GP_SINK_TABLE_SEQ_NUM_CAP_MASK)
            {
                sZgpPairingPayload.b24Options |= GP_PAIRING_SEQ_NUM_CAP_MASK;
            }

            if(sSinkTableEntry.b16Options & GP_SINK_TABLE_SECURITY_USE_MASK)
            {
                teGP_GreenPowerSecLevel    eSecLevel;
                teGP_GreenPowerSecKeyType  eSecKeyType;

                eSecLevel = sSinkTableEntry.b8SecOptions & GP_SECURITY_LEVEL_MASK;
                eSecKeyType = (sSinkTableEntry.b8SecOptions & GP_SECURITY_KEY_TYPE_MASK) >> 2;

                sZgpPairingPayload.b24Options |= eSecLevel << 9;
                sZgpPairingPayload.b24Options |= eSecKeyType << 11;
            }

            if(sZgpPairingSearhPayload.b16Options & GP_PAIRING_SEARCH_RQST_SECURITY_COUNTER_MASK)
            {
                sZgpPairingPayload.b24Options |= GP_PAIRING_SECURITY_COUNTER_PRESENT_MASK;
                sZgpPairingPayload.u32ZgpdSecFrameCounter = sSinkTableEntry.u32ZgpdSecFrameCounter;
            }

            if(sZgpPairingSearhPayload.b16Options & GP_PAIRING_SEARCH_RQST_SECURITY_KEY_MASK)
            {
                sZgpPairingPayload.b24Options |= GP_PAIRING_SECURITY_KEY_PRESENT_MASK;
                sZgpPairingPayload.sZgpdKey = sSinkTableEntry.sZgpdKey;
            }

            if(sSinkTableEntry.b16Options & GP_SINK_TABLE_ASSIGNED_ADDR_MASK)
            {
                sZgpPairingPayload.b24Options |= GP_PAIRING_ASSIGNED_ALIAS_PRESENT_MASK;
                sZgpPairingPayload.u16AssignedAlias = sSinkTableEntry.u16ZgpdAssignedAlias;
            }

            sZgpPairingPayload.b24Options |= GP_PAIRING_FORWARDING_RADIUS_PRESENT_MASK;
            sZgpPairingPayload.u8ForwardingRadius = sSinkTableEntry.u8GroupCastRadius;

            sZgpPairingPayload.uZgpdDeviceAddr = sZgpPairingSearhPayload.uZgpdDeviceAddr;
            if(eCommunicationMode == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_DGROUP_ID)
            {
                sZgpPairingPayload.u16SinkGroupID = u16GP_DeriveAliasSrcAddr(u8ApplicationId, sZgpPairingSearhPayload.uZgpdDeviceAddr);
            }
            else if(eCommunicationMode == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID)
            {
                sZgpPairingPayload.u16SinkGroupID = sSinkTableEntry.asZgpsGroupList[0].u16SinkGroup;
                sZgpPairingPayload.u16AssignedAlias = sSinkTableEntry.asZgpsGroupList[0].u16Alias;
                sZgpPairingPayload.b24Options |= GP_PAIRING_ASSIGNED_ALIAS_PRESENT_MASK;
            }

            sZgpPairingPayload.u8DeviceId = sSinkTableEntry.eZgpdDeviceId;

            sDestinationAddress.eAddressMode = E_ZCL_AM_BROADCAST;
            sDestinationAddress.uAddress.eBroadcastMode = ZPS_E_APL_AF_BROADCAST_RX_ON;
            eStatus = eGP_ZgpPairingSend(
                                psEndPointDefinition->u8EndPointNumber,
                                ZCL_GP_PROXY_ENDPOINT_ID,
                                &sDestinationAddress,
                                &u8TransactionSequenceNumber,
                                &sZgpPairingPayload);

            if(eCommunicationMode == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID)
            {
                uint8 i;
                for(i = 1; i < sSinkTableEntry.u8ZgpsGroupListEntries; i++)
                {
                    sZgpPairingPayload.u16SinkGroupID = sSinkTableEntry.asZgpsGroupList[i].u16SinkGroup;
                    sZgpPairingPayload.u16AssignedAlias = sSinkTableEntry.asZgpsGroupList[i].u16Alias;
                    sZgpPairingPayload.b24Options |= GP_PAIRING_ASSIGNED_ALIAS_PRESENT_MASK;
                    /* Send GP Pairing command as broadcast */
                    eGP_ZgpPairingSend(
                            psEndPointDefinition->u8EndPointNumber,
                            ZCL_GP_PROXY_ENDPOINT_ID,
                            &sDestinationAddress,
                            &u8TransactionSequenceNumber,
                            &sZgpPairingPayload);
                }
            }


            /* send device announce */
            if(eCommunicationMode == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID)
            {
                uint8 i;
                for(i = 0; i < sSinkTableEntry.u8ZgpsGroupListEntries; i++)
                {
                    u16AliasShortAddr = sSinkTableEntry.asZgpsGroupList[i].u16Alias;
                    sZdpDeviceAnnceReq.u16NwkAddr = u16AliasShortAddr;
                    sZdpDeviceAnnceReq.u64IeeeAddr = 0xFFFFFFFFFFFFFFFFULL;
                    sZdpDeviceAnnceReq.u8Capability = 0x00;

                    /* Populate device announce request */

                    /* allocate Apdu instance */
                    hAPduInst = hZCL_AllocateAPduInstance();

                    if(hAPduInst != NULL)
                    {
                        /* Before announcing call ZPS API */
                        ZPS_vAfZgpDeviceActive(u16AliasShortAddr);

                        ZPS_vAfSetZgpAlias(u16AliasShortAddr, 0x00);

                        if((eStatus = ZPS_eAplZdpDeviceAnnceRequest(hAPduInst,
                                                                    &u8TransactionSequenceNumber,
                                                                    &sZdpDeviceAnnceReq)) != E_ZCL_SUCCESS)
                        {
                             /* Free hAPDU */
                            PDUM_eAPduFreeAPduInstance(hAPduInst);
                        }
                    }
                }
            }
            else
            {
                if(sSinkTableEntry.b16Options & GP_SINK_TABLE_ASSIGNED_ADDR_MASK)
                {
                    u16AliasShortAddr = sSinkTableEntry.u16ZgpdAssignedAlias;
                }
                else
                {
                    u16AliasShortAddr = u16GP_DeriveAliasSrcAddr(u8ApplicationId,
                                                                 sZgpPairingPayload.uZgpdDeviceAddr);
                }
                sZdpDeviceAnnceReq.u16NwkAddr = u16AliasShortAddr;
                sZdpDeviceAnnceReq.u64IeeeAddr = 0xFFFFFFFFFFFFFFFFULL;
                sZdpDeviceAnnceReq.u8Capability = 0x00;

                /* Populate device announce request */

                /* allocate Apdu instance */
                hAPduInst = hZCL_AllocateAPduInstance();

                if(hAPduInst != NULL)
                {
                    /* Before announcing call ZPS API */
                    ZPS_vAfZgpDeviceActive(u16AliasShortAddr);

                    ZPS_vAfSetZgpAlias(u16AliasShortAddr, 0x00);

                    if((eStatus = ZPS_eAplZdpDeviceAnnceRequest(hAPduInst,
                                                                &u8TransactionSequenceNumber,
                                                                &sZdpDeviceAnnceReq)) != E_ZCL_SUCCESS)
                    {
                         /* Free hAPDU */
                        PDUM_eAPduFreeAPduInstance(hAPduInst);
                    }
                }
            }
            /* Save APS transaction seq number */
            psGpCustomDataStructure->u8APSDeviceAnnounceSeqNum = u8TransactionSequenceNumber;
        }
    }
    // release mutex
    #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


    return eStatus;

}
#endif
/****************************************************************************
 **
 ** NAME:       eGP_HandleZgpPairingConfig
 **
 ** DESCRIPTION:
 ** Handles Green power Cluster ZGP pairing configuration command
 **
 ** PARAMETERS:               Name                      Usage
 ** ZPS_tsAfEvent            *pZPSevent                 Zigbee stack event structure
 ** tsZCL_EndPointDefinition *psEndPointDefinition      EP structure
 ** tsZCL_ClusterInstance    *psClusterInstance         Cluster structure
 ** uint16                    u16Offset                 offset
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/

PUBLIC teZCL_Status eGP_HandleZgpPairingConfig(
                    ZPS_tsAfEvent                  *pZPSevent,
                    tsZCL_EndPointDefinition       *psEndPointDefinition,
                    tsZCL_ClusterInstance          *psClusterInstance,
                    uint16                         u16Offset)
{
    tsGP_GreenPowerCustomData                   *psGpCustomDataStructure;
    tsGP_ZgpPairingConfigCmdPayload             sZgpPairingConfigPayload = {0};
    uint8		                                u8Status, u8SinkStatus;
    uint8                                       u8ApplicationId, u8TransactionSequenceNumber,i,j;
    tsGP_ZgpsSinkTable                          sSinkTableEntry = {0};
    bool_t                                      bSendDeviceAnnounce = FALSE;
    tsGP_ZgpPairingCmdPayload                   sZgpPairingPayload;
    tsZCL_Address                               sDestinationAddress;
    ZPS_tsAplZdpDeviceAnnceReq                  sZdpDeviceAnnceReq;
    uint16                                      u16AliasShortAddr;
    teGP_GreenPowerPairingConfigAction          ePairingConfigAction;
    teGP_GreenPowerCommunicationMode            eCommunicationMode;
    teGP_GreenPowerSecLevel                     eSecurityLevel;
    teGP_GreenPowerSecKeyType                   eSecKeyType = E_GP_NO_KEY;
    PDUM_thAPduInstance                         hAPduInst;
    tsGP_ZgpsPairingConfigCmdRcvd   			sZgpsPairingConfigCmdRcvd;
    // initialise pointer
    psGpCustomDataStructure = (tsGP_GreenPowerCustomData *)psClusterInstance->pvEndPointCustomStructPtr;

    // get EP mutex
    #ifndef COOPERATIVE
        eZCL_GetMutex(psEndPointDefinition);
    #endif


    // fill in callback event structure
    eZCL_SetCustomCallBackEvent(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent,
                pZPSevent, 0, psEndPointDefinition->u8EndPointNumber);

    // get information
    u8Status = eGP_ZgpPairingConfigReceive(
                                pZPSevent,
                                u16Offset,
                                &sZgpPairingConfigPayload);

    /* Check Status */
    if(u8Status != E_ZCL_SUCCESS)
    {
        // release mutex
        #ifndef COOPERATIVE
            eZCL_ReleaseMutex(psEndPointDefinition);
        #endif


        return u8Status;
    }

    ePairingConfigAction = sZgpPairingConfigPayload.u8Actions & GP_PAIRING_CONFIG_ACTION_MASK;

    u8ApplicationId = sZgpPairingConfigPayload.b16Options & GP_APPLICATION_ID_MASK;

    if((u8ApplicationId != GP_APPL_ID_4_BYTE)&&(u8ApplicationId != GP_APPL_ID_8_BYTE))
    {
        // release mutex
        #ifndef COOPERATIVE
            eZCL_ReleaseMutex(psEndPointDefinition);
        #endif


        return E_ZCL_ERR_INVALID_VALUE;
    }

    eCommunicationMode = (sZgpPairingConfigPayload.b16Options & GP_SINK_TABLE_COMM_MODE_MASK)  >> 3;
    if(sZgpPairingConfigPayload.b16Options & GP_SINK_TABLE_SECURITY_USE_MASK)
    {
        eSecurityLevel = sZgpPairingConfigPayload.b8SecOptions & GP_SECURITY_LEVEL_MASK;
    }
    else
    {
        eSecurityLevel = 0;
    }

    if((ePairingConfigAction == E_GP_PAIRING_CONFIG_EXTEND_SINK_TABLE_ENTRY)||
      (ePairingConfigAction == E_GP_PAIRING_CONFIG_REPLACE_SINK_TABLE_ENTRY))
    {
        /* check if GPS supports the Security level requested */
        //if(sZgpPairingConfigPayload.b16Options & GP_SINK_TABLE_SECURITY_USE_MASK)
        {
            if(eSecurityLevel < ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->b8ZgpsSecLevel)
            {
               // release mutex
                #ifndef COOPERATIVE
                    eZCL_ReleaseMutex(psEndPointDefinition);
                #endif


                return E_ZCL_SUCCESS;
            }
        }
        /* check if GPS supports the communication mode requested */
        if(((eCommunicationMode == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID) &&
          (!(((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->b24ZgpsFeatures & GP_FEATURE_COMMISSION_GC_COMM)))||
          ((eCommunicationMode == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_DGROUP_ID) &&
          (!(((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->b24ZgpsFeatures & GP_FEATURE_DERIVED_GC_COMM))))
        {
           // release mutex
            #ifndef COOPERATIVE
                eZCL_ReleaseMutex(psEndPointDefinition);
            #endif


            return E_ZCL_SUCCESS;
        }
    }

    if(bGP_IsSinkTableEntryPresent(psEndPointDefinition->u8EndPointNumber,
                                   u8ApplicationId,
                                   &sZgpPairingConfigPayload.uZgpdDeviceAddr,
                                   E_GP_SINK_TABLE_GET_ENTRY,
                                   &sSinkTableEntry,
                                   (teGP_GreenPowerCommunicationMode)((sZgpPairingConfigPayload.b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3)))
    {

        if((ePairingConfigAction == E_GP_PAIRING_CONFIG_REPLACE_SINK_TABLE_ENTRY)||
          (ePairingConfigAction == E_GP_PAIRING_CONFIG_REMOVE_SINK_TABLE_ENTRY))
        {
            if((ePairingConfigAction == E_GP_PAIRING_CONFIG_REMOVE_SINK_TABLE_ENTRY)&&(sZgpPairingConfigPayload.u8Actions & GP_PAIRING_CONFIG_SEND_GP_PAIRING_MASK))
            {
                 sZgpPairingPayload.b24Options = u8ApplicationId;

                 sZgpPairingPayload.b24Options |= eCommunicationMode << 5;

                 if(sSinkTableEntry.b16Options & GP_SINK_TABLE_FIXED_LOCATION_MASK)
                 {
                     sZgpPairingPayload.b24Options |= GP_PAIRING_GPD_FIXED_MASK;
                 }

                 if(sSinkTableEntry.b16Options & GP_SINK_TABLE_SEQ_NUM_CAP_MASK)
                 {
                     sZgpPairingPayload.b24Options |= GP_PAIRING_SEQ_NUM_CAP_MASK;
                 }

                 if(sSinkTableEntry.b16Options & GP_SINK_TABLE_SECURITY_USE_MASK)
                 {
                     teGP_GreenPowerSecLevel    eSecLevel;

                     eSecLevel = sSinkTableEntry.b8SecOptions & GP_SECURITY_LEVEL_MASK;
                     eSecKeyType = (sSinkTableEntry.b8SecOptions & GP_SECURITY_KEY_TYPE_MASK) >> 2;

                     sZgpPairingPayload.b24Options |= eSecLevel << 9;
                     sZgpPairingPayload.b24Options |= eSecKeyType << 11;
                 }
                 sZgpPairingPayload.uZgpdDeviceAddr = sSinkTableEntry.uZgpdDeviceAddr;

                 if((teGP_GreenPowerCommunicationMode)((sSinkTableEntry.b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3) == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_DGROUP_ID)
                 {
                     sZgpPairingPayload.u16SinkGroupID = u16GP_DeriveAliasSrcAddr(u8ApplicationId, sSinkTableEntry.uZgpdDeviceAddr);
                 }
                 else if((teGP_GreenPowerCommunicationMode)((sSinkTableEntry.b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3) == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID)
                 {
                     sZgpPairingPayload.u16SinkGroupID = sZgpPairingConfigPayload.asZgpsGroupList[0].u16SinkGroup;
                 }

                 sDestinationAddress.eAddressMode = E_ZCL_AM_BROADCAST;
                 sDestinationAddress.uAddress.eBroadcastMode = ZPS_E_APL_AF_BROADCAST_RX_ON;
                 u8Status = eGP_ZgpPairingSend(
                                     psEndPointDefinition->u8EndPointNumber,
                                     ZCL_GP_PROXY_ENDPOINT_ID,
                                     &sDestinationAddress,
                                     &u8TransactionSequenceNumber,
                                     &sZgpPairingPayload);

                 if((teGP_GreenPowerCommunicationMode)((sSinkTableEntry.b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3) == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID)
                 {
                     uint8 i;
                     for(i = 1; i < sZgpPairingConfigPayload.u8ZgpsGroupListEntries; i++)
                     {
                         sZgpPairingPayload.u16SinkGroupID = sZgpPairingConfigPayload.asZgpsGroupList[i].u16SinkGroup;
                         //sZgpPairingPayload.u16AssignedAlias = sSinkTableEntry.asZgpsGroupList[i].u16Alias;
                         //sZgpPairingPayload.b24Options |= GP_PAIRING_ASSIGNED_ALIAS_PRESENT_MASK;
                         /* Send GP Pairing command as broadcast */
                         eGP_ZgpPairingSend(
                                 psEndPointDefinition->u8EndPointNumber,
                                  ZCL_GP_PROXY_ENDPOINT_ID,
                                  &sDestinationAddress,
                                  &u8TransactionSequenceNumber,
                                  &sZgpPairingPayload);
                     }
                 }
            }
            /* Remove GPEP from group at APS level */
            if((teGP_GreenPowerCommunicationMode)((sSinkTableEntry.b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3) == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_DGROUP_ID)
            {
                vGP_RemoveGPEPFromGroup(psGpCustomDataStructure, psEndPointDefinition, &sSinkTableEntry);

                /* remove sink table entry */
                u8Status = eGP_RemoveSinkTableEntry(psEndPointDefinition->u8EndPointNumber, &sSinkTableEntry);
            }
            else if((teGP_GreenPowerCommunicationMode)((sSinkTableEntry.b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3) == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID)
            {
                for(i = 0; i < sZgpPairingConfigPayload.u8ZgpsGroupListEntries; i++)
                {
                    u8Status = ZPS_eAplZdoGroupEndpointRemove(sZgpPairingConfigPayload.asZgpsGroupList[i].u16SinkGroup, ZCL_GP_PROXY_ENDPOINT_ID);
                    /* Check Status */
                     if(u8Status != E_ZCL_SUCCESS)
                     {
                         psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_REMOVING_GROUP_TABLE_FAIL;
                         psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.uMessage.eRemoveGroupTableStatus = u8Status;
                        /* Give Application Callback for sink table update */
                         psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);
                    }
                }
                /* remove sink table entry */
                for(i=0;i < sZgpPairingConfigPayload.u8ZgpsGroupListEntries; i++)
                {
                    for(j=0;j<sSinkTableEntry.u8ZgpsGroupListEntries;j++)
                    {
                        if(sZgpPairingConfigPayload.asZgpsGroupList[i].u16SinkGroup == sSinkTableEntry.asZgpsGroupList[j].u16SinkGroup)
                        {
                            sSinkTableEntry.asZgpsGroupList[j].u16SinkGroup = sSinkTableEntry.asZgpsGroupList[sSinkTableEntry.u8ZgpsGroupListEntries - 1].u16SinkGroup;
                            sSinkTableEntry.asZgpsGroupList[j].u16Alias = sSinkTableEntry.asZgpsGroupList[sSinkTableEntry.u8ZgpsGroupListEntries - 1].u16Alias;
                            sSinkTableEntry.u8ZgpsGroupListEntries--;
                            break;
                        }
                    }
                    if(sSinkTableEntry.u8ZgpsGroupListEntries == 0)
                    {
                        u8Status = eGP_RemoveSinkTableEntry(psEndPointDefinition->u8EndPointNumber, &sSinkTableEntry);
                        break;
                    }
                }
                if(sSinkTableEntry.u8ZgpsGroupListEntries != 0)
                {
                    bGP_IsSinkTableEntryPresent(psEndPointDefinition->u8EndPointNumber,
                                               u8ApplicationId,
                                               &sZgpPairingConfigPayload.uZgpdDeviceAddr,
                                               E_GP_SINK_TABLE_SET_ENTRY,
                                               &sSinkTableEntry,
                                               (teGP_GreenPowerCommunicationMode)((sZgpPairingConfigPayload.b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3));
                    sZgpsPairingConfigCmdRcvd.eTranslationTableAction = E_GP_PAIRING_CONFIG_TRANSLATION_TABLE_NO_ACTION;
                }
            }

            psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_PAIRING_CONFIGURATION_CMD_RCVD;
            sZgpsPairingConfigCmdRcvd.eAction = ePairingConfigAction;

            if(sZgpsPairingConfigCmdRcvd.eTranslationTableAction != E_GP_PAIRING_CONFIG_TRANSLATION_TABLE_NO_ACTION)
            {
                sZgpsPairingConfigCmdRcvd.eTranslationTableAction = E_GP_PAIRING_CONFIG_TRANSLATION_TABLE_REMOVE_ENTRY;
            }
            sZgpsPairingConfigCmdRcvd.eZgpdDeviceId = sZgpPairingConfigPayload.eZgpdDeviceId;
            sZgpsPairingConfigCmdRcvd.u8ApplicationId = u8ApplicationId;
            if(u8ApplicationId == GP_APPL_ID_4_BYTE)
            {
                sZgpsPairingConfigCmdRcvd.uZgpdDeviceAddr.u32ZgpdSrcId = sZgpPairingConfigPayload.uZgpdDeviceAddr.u32ZgpdSrcId;
            }
#ifdef GP_IEEE_ADDR_SUPPORT
            else
            {
                sZgpsPairingConfigCmdRcvd.uZgpdDeviceAddr.u64ZgpdIEEEAddr = sZgpPairingConfigPayload.uZgpdDeviceAddr.u64ZgpdIEEEAddr;
            }
#endif
            sZgpsPairingConfigCmdRcvd.u8NumberOfPairedEndpoints = sZgpPairingConfigPayload.u8NumberOfPairedEndpoints;

            if((sZgpPairingConfigPayload.u8NumberOfPairedEndpoints != 0xFD)&&
              (sZgpPairingConfigPayload.u8NumberOfPairedEndpoints != 0xFE)&&
              (sZgpPairingConfigPayload.u8NumberOfPairedEndpoints != 0xFF))
            {
                memcpy(sZgpsPairingConfigCmdRcvd.au8PairedEndpointList, sZgpPairingConfigPayload.au8PairedEndpoints, sZgpPairingConfigPayload.u8NumberOfPairedEndpoints);
            }
            sZgpsPairingConfigCmdRcvd.eCommunicationMode =  (teGP_GreenPowerCommunicationMode)((sZgpPairingConfigPayload.b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3);
            if(sZgpsPairingConfigCmdRcvd.eCommunicationMode == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID)
            {
                sZgpsPairingConfigCmdRcvd.u8ZgpsGroupListEntries = sZgpPairingConfigPayload.u8ZgpsGroupListEntries;
                memcpy(sZgpsPairingConfigCmdRcvd.asZgpsGroupList, sZgpPairingConfigPayload.asZgpsGroupList, sZgpPairingConfigPayload.u8ZgpsGroupListEntries*sizeof(tsGP_ZgpsGroupList));
            }
            psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.uMessage.psPairingConfigCmdRcvd = &sZgpsPairingConfigCmdRcvd;
            /* Give Application Callback for translation table update */
            psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);

        }

    }

    if((ePairingConfigAction == E_GP_PAIRING_CONFIG_REMOVE_GPD)||
       (ePairingConfigAction == E_GP_PAIRING_CONFIG_REPLACE_SINK_TABLE_ENTRY))
    {
        uint8 i;
        /* check for all communication mode if sink table entry present */
        for(i = 0; i < E_GP_UNI_FORWARD_ZGP_NOTIFICATION_BY_PROXIES_LIGHTWEIGHT; i++)
        {
            if(bGP_IsSinkTableEntryPresent(psEndPointDefinition->u8EndPointNumber,
                                           u8ApplicationId,
                                           &sZgpPairingConfigPayload.uZgpdDeviceAddr,
                                           E_GP_SINK_TABLE_GET_ENTRY,
                                           &sSinkTableEntry,
                                           i))
            {

                if(sZgpPairingConfigPayload.u8Actions & GP_PAIRING_CONFIG_SEND_GP_PAIRING_MASK)
                {
                    sZgpPairingPayload.b24Options = u8ApplicationId;
                    sZgpPairingPayload.b24Options |= GP_PAIRING_REMOVE_GPD_MASK;
                    sZgpPairingPayload.b24Options |= i << 5;

                     if(sSinkTableEntry.b16Options & GP_SINK_TABLE_FIXED_LOCATION_MASK)
                     {
                         sZgpPairingPayload.b24Options |= GP_PAIRING_GPD_FIXED_MASK;
                     }

                     if(sSinkTableEntry.b16Options & GP_SINK_TABLE_SEQ_NUM_CAP_MASK)
                     {
                         sZgpPairingPayload.b24Options |= GP_PAIRING_SEQ_NUM_CAP_MASK;
                     }

                     if(sSinkTableEntry.b16Options & GP_SINK_TABLE_SECURITY_USE_MASK)
                     {
                         teGP_GreenPowerSecLevel    eSecLevel;

                         eSecLevel = sSinkTableEntry.b8SecOptions & GP_SECURITY_LEVEL_MASK;
                         eSecKeyType = (sSinkTableEntry.b8SecOptions & GP_SECURITY_KEY_TYPE_MASK) >> 2;

                         sZgpPairingPayload.b24Options |= eSecLevel << 9;
                         sZgpPairingPayload.b24Options |= eSecKeyType << 11;
                     }
                     sZgpPairingPayload.uZgpdDeviceAddr = sSinkTableEntry.uZgpdDeviceAddr;
                     sDestinationAddress.eAddressMode = E_ZCL_AM_BROADCAST;
                     sDestinationAddress.uAddress.eBroadcastMode = ZPS_E_APL_AF_BROADCAST_RX_ON;
                     u8Status = eGP_ZgpPairingSend(
                                         psEndPointDefinition->u8EndPointNumber,
                                         ZCL_GP_PROXY_ENDPOINT_ID,
                                         &sDestinationAddress,
                                         &u8TransactionSequenceNumber,
                                         &sZgpPairingPayload);


                }
                /* Remove GPEP from group at APS level */
                vGP_RemoveGPEPFromGroup(psGpCustomDataStructure, psEndPointDefinition, &sSinkTableEntry);
                /* remove sink table entry */
                eGP_RemoveSinkTableEntry(psEndPointDefinition->u8EndPointNumber, &sSinkTableEntry);

                psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_PAIRING_CONFIGURATION_CMD_RCVD;
                sZgpsPairingConfigCmdRcvd.eAction = ePairingConfigAction;
                sZgpsPairingConfigCmdRcvd.eTranslationTableAction = E_GP_PAIRING_CONFIG_TRANSLATION_TABLE_REMOVE_ENTRY;

                sZgpsPairingConfigCmdRcvd.eZgpdDeviceId = sZgpPairingConfigPayload.eZgpdDeviceId;
                sZgpsPairingConfigCmdRcvd.u8ApplicationId = u8ApplicationId;
                if(u8ApplicationId == GP_APPL_ID_4_BYTE)
                {
                    sZgpsPairingConfigCmdRcvd.uZgpdDeviceAddr.u32ZgpdSrcId = sZgpPairingConfigPayload.uZgpdDeviceAddr.u32ZgpdSrcId;
                }
#ifdef GP_IEEE_ADDR_SUPPORT
                else
                {
                    sZgpsPairingConfigCmdRcvd.uZgpdDeviceAddr.u64ZgpdIEEEAddr = sZgpPairingConfigPayload.uZgpdDeviceAddr.u64ZgpdIEEEAddr;
                }
#endif
                sZgpsPairingConfigCmdRcvd.u8NumberOfPairedEndpoints = sZgpPairingConfigPayload.u8NumberOfPairedEndpoints;

                if((sZgpPairingConfigPayload.u8NumberOfPairedEndpoints != 0xFD)&&
                  (sZgpPairingConfigPayload.u8NumberOfPairedEndpoints != 0xFE)&&
                  (sZgpPairingConfigPayload.u8NumberOfPairedEndpoints != 0xFF))
                {
                    memcpy(sZgpsPairingConfigCmdRcvd.au8PairedEndpointList, sZgpPairingConfigPayload.au8PairedEndpoints, sZgpPairingConfigPayload.u8NumberOfPairedEndpoints);
                }
                sZgpsPairingConfigCmdRcvd.eCommunicationMode =  (teGP_GreenPowerCommunicationMode)((sZgpPairingConfigPayload.b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3);
                if(sZgpsPairingConfigCmdRcvd.eCommunicationMode == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID)
                {
                    sZgpsPairingConfigCmdRcvd.u8ZgpsGroupListEntries = sZgpPairingConfigPayload.u8ZgpsGroupListEntries;
                    memcpy(sZgpsPairingConfigCmdRcvd.asZgpsGroupList, sZgpPairingConfigPayload.asZgpsGroupList, sZgpPairingConfigPayload.u8ZgpsGroupListEntries*sizeof(tsGP_ZgpsGroupList));
                }
                psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.uMessage.psPairingConfigCmdRcvd = &sZgpsPairingConfigCmdRcvd;
                /* Give Application Callback for translation table update */
                psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);

            }
        }
    }

    if((ePairingConfigAction == E_GP_PAIRING_CONFIG_EXTEND_SINK_TABLE_ENTRY)||
      (ePairingConfigAction == E_GP_PAIRING_CONFIG_REPLACE_SINK_TABLE_ENTRY))
    {

        /* Populate sink table entry */
        sSinkTableEntry.b16Options = sZgpPairingConfigPayload.b16Options;
        if(u8ApplicationId == GP_APPL_ID_4_BYTE)
        {
            sSinkTableEntry.uZgpdDeviceAddr.u32ZgpdSrcId = sZgpPairingConfigPayload.uZgpdDeviceAddr.u32ZgpdSrcId;
        }
#ifdef GP_IEEE_ADDR_SUPPORT
        else
        {
            sSinkTableEntry.uZgpdDeviceAddr.u64ZgpdIEEEAddr = sZgpPairingConfigPayload.uZgpdDeviceAddr.u64ZgpdIEEEAddr;
        }
#endif
        //sSinkTableEntry.uZgpdDeviceAddr = sZgpPairingConfigPayload.uZgpdDeviceAddr;
        sSinkTableEntry.eZgpdDeviceId = sZgpPairingConfigPayload.eZgpdDeviceId;
        sSinkTableEntry.u16ZgpdAssignedAlias = sZgpPairingConfigPayload.u16ZgpdAssignedAlias;
        sSinkTableEntry.u8GroupCastRadius = sZgpPairingConfigPayload.u8ForwardingRadius;
        sSinkTableEntry.b8SecOptions = sZgpPairingConfigPayload.b8SecOptions;
        sSinkTableEntry.u32ZgpdSecFrameCounter = sZgpPairingConfigPayload.u32ZgpdSecFrameCounter;
        sSinkTableEntry.sZgpdKey = sZgpPairingConfigPayload.sZgpdKey;
        if(ePairingConfigAction == E_GP_PAIRING_CONFIG_EXTEND_SINK_TABLE_ENTRY)
        {
            memcpy(&sSinkTableEntry.asZgpsGroupList[sSinkTableEntry.u8ZgpsGroupListEntries], sZgpPairingConfigPayload.asZgpsGroupList, sZgpPairingConfigPayload.u8ZgpsGroupListEntries*sizeof(tsGP_ZgpsGroupList));
            sSinkTableEntry.u8ZgpsGroupListEntries += sZgpPairingConfigPayload.u8ZgpsGroupListEntries;
        }
        else
        {
            memcpy(&sSinkTableEntry.asZgpsGroupList[0], sZgpPairingConfigPayload.asZgpsGroupList, sZgpPairingConfigPayload.u8ZgpsGroupListEntries*sizeof(tsGP_ZgpsGroupList));
            sSinkTableEntry.u8ZgpsGroupListEntries = sZgpPairingConfigPayload.u8ZgpsGroupListEntries;
        }

        sSinkTableEntry.eGreenPowerSinkTablePriority = E_GP_SINK_TABLE_P_2;

        /* Add to Sink Table */
        u8SinkStatus = eGP_AddSinkTableEntry(psEndPointDefinition->u8EndPointNumber,    &sSinkTableEntry);

        /* check u8Status  and give call back accordingly */
        if(u8SinkStatus == E_GP_SINK_TABLE_SUCCESS)
        {
            psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_SINK_TABLE_ENTRY_ADDED;
            psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.uMessage.psZgpsSinkTable = &sSinkTableEntry;
        }
        else
        {
            psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_SINK_TABLE_FULL;
        }

        /* Give Application Callback for sink table update */
        psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);

        if(u8SinkStatus == E_GP_SINK_TABLE_SUCCESS)
        {
            psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_PAIRING_CONFIGURATION_CMD_RCVD;
            sZgpsPairingConfigCmdRcvd.eAction = ePairingConfigAction;
            sZgpsPairingConfigCmdRcvd.eTranslationTableAction = E_GP_PAIRING_CONFIG_TRANSLATION_TABLE_ADD_ENTRY;

            sZgpsPairingConfigCmdRcvd.eZgpdDeviceId = sZgpPairingConfigPayload.eZgpdDeviceId;
            sZgpsPairingConfigCmdRcvd.u8ApplicationId = u8ApplicationId;
            if(u8ApplicationId == GP_APPL_ID_4_BYTE)
            {
                sZgpsPairingConfigCmdRcvd.uZgpdDeviceAddr.u32ZgpdSrcId = sZgpPairingConfigPayload.uZgpdDeviceAddr.u32ZgpdSrcId;
            }
#ifdef GP_IEEE_ADDR_SUPPORT
            else
            {
                sZgpsPairingConfigCmdRcvd.uZgpdDeviceAddr.u64ZgpdIEEEAddr = sZgpPairingConfigPayload.uZgpdDeviceAddr.u64ZgpdIEEEAddr;
            }
#endif
            sZgpsPairingConfigCmdRcvd.u8NumberOfPairedEndpoints = sZgpPairingConfigPayload.u8NumberOfPairedEndpoints;

            if((sZgpPairingConfigPayload.u8NumberOfPairedEndpoints != 0xFD)&&
              (sZgpPairingConfigPayload.u8NumberOfPairedEndpoints != 0xFE)&&
              (sZgpPairingConfigPayload.u8NumberOfPairedEndpoints != 0xFF))
            {
                memcpy(sZgpsPairingConfigCmdRcvd.au8PairedEndpointList, sZgpPairingConfigPayload.au8PairedEndpoints, sZgpPairingConfigPayload.u8NumberOfPairedEndpoints);
            }
            sZgpsPairingConfigCmdRcvd.eCommunicationMode =  (teGP_GreenPowerCommunicationMode)((sZgpPairingConfigPayload.b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3);
            if(sZgpsPairingConfigCmdRcvd.eCommunicationMode == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID)
            {
                sZgpsPairingConfigCmdRcvd.u8ZgpsGroupListEntries = sZgpPairingConfigPayload.u8ZgpsGroupListEntries;
                memcpy(sZgpsPairingConfigCmdRcvd.asZgpsGroupList, sZgpPairingConfigPayload.asZgpsGroupList, sZgpPairingConfigPayload.u8ZgpsGroupListEntries*sizeof(tsGP_ZgpsGroupList));
            }
            /* Give Application Callback  */
            psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.uMessage.psPairingConfigCmdRcvd = &sZgpsPairingConfigCmdRcvd;
            psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);

            bSendDeviceAnnounce = TRUE;
            /* Add GPEP to group at APS level */
            vGP_AddGPEPToGroup(psGpCustomDataStructure, psEndPointDefinition, &sSinkTableEntry);
        }
    }

    if(ePairingConfigAction == E_GP_PAIRING_CONFIG_NO_ACTION)
    {
        eCommunicationMode = E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_DGROUP_ID;
    }
    else
    {
        eCommunicationMode = (sZgpPairingConfigPayload.b16Options & GP_SINK_TABLE_COMM_MODE_MASK)  >> 3;
    }

    for(i=1; i < E_GP_UNI_FORWARD_ZGP_NOTIFICATION_BY_PROXIES_LIGHTWEIGHT; i++)
    {
        if(bGP_IsSinkTableEntryPresent(psEndPointDefinition->u8EndPointNumber,
                                       u8ApplicationId,
                                       &sZgpPairingConfigPayload.uZgpdDeviceAddr,
                                       E_GP_SINK_TABLE_GET_ENTRY,
                                       &sSinkTableEntry,
                                       eCommunicationMode) == TRUE)
        {
            if(sZgpPairingConfigPayload.u8Actions & GP_PAIRING_CONFIG_SEND_GP_PAIRING_MASK)
            {
                 sZgpPairingPayload.b24Options = u8ApplicationId;
                 sZgpPairingPayload.b24Options |= GP_PAIRING_ADD_SINK_MASK;
                 sZgpPairingPayload.b24Options |= eCommunicationMode << 5;

                 if(sSinkTableEntry.b16Options & GP_SINK_TABLE_FIXED_LOCATION_MASK)
                 {
                     sZgpPairingPayload.b24Options |= GP_PAIRING_GPD_FIXED_MASK;
                 }

                 if(sSinkTableEntry.b16Options & GP_SINK_TABLE_SEQ_NUM_CAP_MASK)
                 {
                     sZgpPairingPayload.b24Options |= GP_PAIRING_SEQ_NUM_CAP_MASK;
                 }

                 if(sSinkTableEntry.b16Options & GP_SINK_TABLE_SECURITY_USE_MASK)
                 {
                     teGP_GreenPowerSecLevel    eSecLevel;

                     eSecLevel = sSinkTableEntry.b8SecOptions & GP_SECURITY_LEVEL_MASK;
                     eSecKeyType = (sSinkTableEntry.b8SecOptions & GP_SECURITY_KEY_TYPE_MASK) >> 2;

                     sZgpPairingPayload.b24Options |= eSecLevel << 9;
                     sZgpPairingPayload.b24Options |= eSecKeyType << 11;
                 }

                   sZgpPairingPayload.b24Options |= GP_PAIRING_SECURITY_COUNTER_PRESENT_MASK;
                   sZgpPairingPayload.u32ZgpdSecFrameCounter = sSinkTableEntry.u32ZgpdSecFrameCounter;

                 if(eSecKeyType != E_GP_NO_KEY)
                 {
                     sZgpPairingPayload.b24Options |= GP_PAIRING_SECURITY_KEY_PRESENT_MASK;
                     sZgpPairingPayload.sZgpdKey = sSinkTableEntry.sZgpdKey;
                 }

                 if(sSinkTableEntry.b16Options & GP_SINK_TABLE_ASSIGNED_ADDR_MASK)
                 {
                     sZgpPairingPayload.b24Options |= GP_PAIRING_ASSIGNED_ALIAS_PRESENT_MASK;
                     sZgpPairingPayload.u16AssignedAlias = sSinkTableEntry.u16ZgpdAssignedAlias;
                 }

                 sZgpPairingPayload.b24Options |= GP_PAIRING_FORWARDING_RADIUS_PRESENT_MASK;
                 sZgpPairingPayload.u8ForwardingRadius = sSinkTableEntry.u8GroupCastRadius;

                 sZgpPairingPayload.uZgpdDeviceAddr = sSinkTableEntry.uZgpdDeviceAddr;

                 if((teGP_GreenPowerCommunicationMode)((sSinkTableEntry.b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3) == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_DGROUP_ID)
                 {
                     sZgpPairingPayload.u16SinkGroupID = u16GP_DeriveAliasSrcAddr(u8ApplicationId, sSinkTableEntry.uZgpdDeviceAddr);
                 }
                 else if((teGP_GreenPowerCommunicationMode)((sSinkTableEntry.b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3) == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID)
                 {
                     sZgpPairingPayload.u16SinkGroupID = sSinkTableEntry.asZgpsGroupList[0].u16SinkGroup;
                     sZgpPairingPayload.u16AssignedAlias = sSinkTableEntry.asZgpsGroupList[0].u16Alias;
                     sZgpPairingPayload.b24Options |= GP_PAIRING_ASSIGNED_ALIAS_PRESENT_MASK;
                 }

                 sZgpPairingPayload.u8DeviceId = sSinkTableEntry.eZgpdDeviceId;

                 sDestinationAddress.eAddressMode = E_ZCL_AM_BROADCAST;
                 sDestinationAddress.uAddress.eBroadcastMode = ZPS_E_APL_AF_BROADCAST_RX_ON;
                 u8Status = eGP_ZgpPairingSend(
                                     psEndPointDefinition->u8EndPointNumber,
                                     ZCL_GP_PROXY_ENDPOINT_ID,
                                     &sDestinationAddress,
                                     &u8TransactionSequenceNumber,
                                     &sZgpPairingPayload);

                 if((teGP_GreenPowerCommunicationMode)((sSinkTableEntry.b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3) == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID)
                 {
                     uint8 i;
                     for(i = 1; i < sSinkTableEntry.u8ZgpsGroupListEntries; i++)
                     {
                         sZgpPairingPayload.u16SinkGroupID = sSinkTableEntry.asZgpsGroupList[i].u16SinkGroup;
                         sZgpPairingPayload.u16AssignedAlias = sSinkTableEntry.asZgpsGroupList[i].u16Alias;
                         sZgpPairingPayload.b24Options |= GP_PAIRING_ASSIGNED_ALIAS_PRESENT_MASK;
                         /* Send GP Pairing command as broadcast */
                         eGP_ZgpPairingSend(
                                 psEndPointDefinition->u8EndPointNumber,
                                  ZCL_GP_PROXY_ENDPOINT_ID,
                                  &sDestinationAddress,
                                  &u8TransactionSequenceNumber,
                                  &sZgpPairingPayload);
                     }
                 }

                 if((bSendDeviceAnnounce)||(ePairingConfigAction == E_GP_PAIRING_CONFIG_NO_ACTION))
                 {
                     /* send device announce */
                     if((teGP_GreenPowerCommunicationMode)((sSinkTableEntry.b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3) == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID)
                     {
                         uint8 i;
                         for(i = 0; i < sSinkTableEntry.u8ZgpsGroupListEntries; i++)
                         {
                             /* check alias address */
                             if(sSinkTableEntry.asZgpsGroupList[i].u16Alias >= 0xFFF8)
                             {
                                u16AliasShortAddr = u16GP_DeriveAliasSrcAddr(
                                                        (uint8)(sSinkTableEntry.b16Options & GP_APPLICATION_ID_MASK),
                                                        sSinkTableEntry.uZgpdDeviceAddr);
                             }
                             else
                             {
                                u16AliasShortAddr = sSinkTableEntry.asZgpsGroupList[i].u16Alias;
                             }
                             sZdpDeviceAnnceReq.u16NwkAddr = u16AliasShortAddr;
                             sZdpDeviceAnnceReq.u64IeeeAddr = 0xFFFFFFFFFFFFFFFFULL;
                             sZdpDeviceAnnceReq.u8Capability = 0x00;

                             /* Populate device announce request */

                             /* allocate Apdu instance */
                             hAPduInst = hZCL_AllocateAPduInstance();

                             if(hAPduInst != NULL)
                             {
                                 /* Before announcing call ZPS API */
                                 ZPS_vAfZgpDeviceActive(u16AliasShortAddr);

                                 ZPS_vAfSetZgpAlias(u16AliasShortAddr, 0x00);

                                 if((u8Status = ZPS_eAplZdpDeviceAnnceRequest(
                                                                          hAPduInst,
                                                                          &u8TransactionSequenceNumber,
                                                                          &sZdpDeviceAnnceReq)) != E_ZCL_SUCCESS)
                                 {
                                   /* Free hAPDU */
                                     PDUM_eAPduFreeAPduInstance(hAPduInst);
                                 }
                              }
                         }
                     }
                     else
                     {
                        if(sSinkTableEntry.b16Options & GP_SINK_TABLE_ASSIGNED_ADDR_MASK)
                        {
                            u16AliasShortAddr = sSinkTableEntry.u16ZgpdAssignedAlias;
                        }
                        else
                        {
                            u16AliasShortAddr = u16GP_DeriveAliasSrcAddr(u8ApplicationId,
                                                                     sZgpPairingPayload.uZgpdDeviceAddr);
                        }
                        sZdpDeviceAnnceReq.u16NwkAddr = u16AliasShortAddr;
                        sZdpDeviceAnnceReq.u64IeeeAddr = 0xFFFFFFFFFFFFFFFFULL;
                        sZdpDeviceAnnceReq.u8Capability = 0x00;

                        /* Populate device announce request */

                        /* allocate Apdu instance */
                        hAPduInst = hZCL_AllocateAPduInstance();

                        if(hAPduInst != NULL)
                        {
                            /* Before announcing call ZPS API */
                            ZPS_vAfZgpDeviceActive(u16AliasShortAddr);

                            ZPS_vAfSetZgpAlias(u16AliasShortAddr, 0x00);

                            if((u8Status = ZPS_eAplZdpDeviceAnnceRequest(
                                                                     hAPduInst,
                                                                     &u8TransactionSequenceNumber,
                                                                     &sZdpDeviceAnnceReq)) != E_ZCL_SUCCESS)
                            {
                              /* Free hAPDU */
                                PDUM_eAPduFreeAPduInstance(hAPduInst);
                            }
                         }
                     }

                     /* Save APS transaction seq number */
                     psGpCustomDataStructure->u8APSDeviceAnnounceSeqNum = u8TransactionSequenceNumber;
                 }
             }
        }
        if(ePairingConfigAction == E_GP_PAIRING_CONFIG_NO_ACTION)
        {
            eCommunicationMode = i+1;
        }
        else
        {
            break;
        }
    }
    // release mutex
    #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


    return E_ZCL_SUCCESS;

}
#endif
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

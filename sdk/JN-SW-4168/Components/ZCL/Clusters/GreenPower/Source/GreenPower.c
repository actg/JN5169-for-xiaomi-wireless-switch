/*****************************************************************************
 *
 * MODULE:             Green Power Cluster
 *
 * COMPONENT:          GreenPower.c
 *
 * AUTHOR:             Ramakrishna
 *
 * DESCRIPTION:        The API for the Green Power Cluster
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/UnifiedZCL_ZLL102_HA122_Maintenance/Clusters/GreenPower/Source/GreenPower.c $
 *
 * $Revision: 88181 $
 *
 * $LastChangedBy: nxp29741 $
 *
 * $LastChangedDate: 2017-05-08 11:35:51 +0100 (Mon, 08 May 2017) $
 *
 * $Id: GreenPower.c 88181 2017-05-08 10:35:51Z nxp29741 $
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
PRIVATE bool_t bGP_UpdateSecurityFrameCounter(ZPS_tsZgpSecReq *psSec, uint32 *pu32FrameCounter);
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

/* Define the attributes in the Green Power cluster */
const tsZCL_AttributeDefinition asCLD_GreenPowerClusterAttributeDefinitions[] = {
#ifdef GP_COMBO_MIN_DEVICE
    /* server attributes */
    {E_CLD_GP_ATTR_ZGPS_MAX_SINK_TABLE_ENTRIES,      (E_ZCL_AF_RD),                           E_ZCL_UINT8,     (uint32)(&((tsCLD_GreenPower*)(0))->u8ZgpsMaxSinkTableEntries), 0},
    {E_CLD_GP_ATTR_ZGPS_SINK_TABLE,                  (E_ZCL_AF_RD),                           E_ZCL_LOSTRING,  (uint32)(&((tsCLD_GreenPower*)(0))->sSinkTable), 0},
    {E_CLD_GP_ATTR_ZGPS_COMMUNICATION_MODE,          (E_ZCL_AF_WR | E_ZCL_AF_RD),             E_ZCL_BMAP8,     (uint32)(&((tsCLD_GreenPower*)(0))->b8ZgpsCommunicationMode), 0},
    {E_CLD_GP_ATTR_ZGPS_COMMISSIONING_EXIT_MODE,     (E_ZCL_AF_WR | E_ZCL_AF_RD),             E_ZCL_BMAP8,     (uint32)(&((tsCLD_GreenPower*)(0))->b8ZgpsCommissioningExitMode), 0},

#ifdef  CLD_GP_ATTR_ZGPS_COMMISSIONING_WINDOW
    {E_CLD_GP_ATTR_ZGPS_COMMISSIONING_WINDOW,        (E_ZCL_AF_WR | E_ZCL_AF_RD),             E_ZCL_UINT16,    (uint32)(&((tsCLD_GreenPower*)(0))->u16ZgpsCommissioningWindow), 0},
#endif

    {E_CLD_GP_ATTR_ZGPS_SECURITY_LEVEL,              (E_ZCL_AF_WR | E_ZCL_AF_RD),             E_ZCL_BMAP8,     (uint32)(&((tsCLD_GreenPower*)(0))->b8ZgpsSecLevel), 0},
    {E_CLD_GP_ATTR_ZGPS_FEATURES,                    (E_ZCL_AF_RD),                           E_ZCL_BMAP24,    (uint32)(&((tsCLD_GreenPower*)(0))->b24ZgpsFeatures), 0},
    {E_CLD_GP_ATTR_ZGPS_ACTIVE_FEATURES,             (E_ZCL_AF_RD),                           E_ZCL_BMAP24,    (uint32)(&((tsCLD_GreenPower*)(0))->b24ZgpsActiveFeatures), 0},
#endif

#ifdef GP_PROXY_DEVICE
    /* Client Attributes */
    {E_CLD_GP_ATTR_ZGPP_MAX_PROXY_TABLE_ENTRIES,      (E_ZCL_AF_RD),                           E_ZCL_UINT8,     (uint32)(&((tsCLD_GreenPower*)(0))->u8ZgppMaxProxyTableEntries), 0},
    {E_CLD_GP_ATTR_ZGPP_PROXY_TABLE,                  (E_ZCL_AF_RD),                           E_ZCL_LOSTRING,  (uint32)(&((tsCLD_GreenPower*)(0))->sProxyTable), 0},

#ifdef  CLD_GP_ATTR_ZGPP_NOTIFICATION_RETRY_NUMBER
    {E_CLD_GP_ATTR_ZGPP_NOTIFICATION_RETRY_NUMBER,    (E_ZCL_AF_WR | E_ZCL_AF_RD),             E_ZCL_UINT8,     (uint32)(&((tsCLD_GreenPower*)(0))->u8ZgppNotificationRetryNumber), 0},
#endif

#ifdef  CLD_GP_ATTR_ZGPP_NOTIFICATION_RETRY_TIMER
    {E_CLD_GP_ATTR_ZGPP_NOTIFICATION_RETRY_TIMER,     (E_ZCL_AF_WR | E_ZCL_AF_RD),             E_ZCL_UINT8,     (uint32)(&((tsCLD_GreenPower*)(0))->u8ZgppNotificationRetryTimer), 0},
#endif

#ifdef  CLD_GP_ATTR_ZGPP_MAX_SEARCH_COUNTER
    {E_CLD_GP_ATTR_ZGPP_MAX_SEARCH_COUNTER,           (E_ZCL_AF_WR | E_ZCL_AF_RD),             E_ZCL_UINT8,     (uint32)(&((tsCLD_GreenPower*)(0))->u8ZgppMaxSearchCounter), 0},
#endif

#ifdef  CLD_GP_ATTR_ZGPP_BLOCKED_GPD_ID
    {E_CLD_GP_ATTR_ZGPP_BLOCKED_ZGPD_ID,              (E_ZCL_AF_RD),                           E_ZCL_LOSTRING,  (uint32)(&((tsCLD_GreenPower*)(0))->sZgppBlockedGpdID), 0},
#endif

    {E_CLD_GP_ATTR_ZGPP_FUNCTIONALITY,                (E_ZCL_AF_RD),                           E_ZCL_BMAP24,    (uint32)(&((tsCLD_GreenPower*)(0))->b24ZgppFunctionality), 0},
    {E_CLD_GP_ATTR_ZGPP_ACTIVE_FUNCTIONALITY,         (E_ZCL_AF_RD),                           E_ZCL_BMAP24,    (uint32)(&((tsCLD_GreenPower*)(0))->b24ZgppActiveFunctionality), 0},
#endif

    /* Shared Attributes b/w server and client */
#ifdef  CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY_TYPE
    {E_CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY_TYPE,      (E_ZCL_AF_WR | E_ZCL_AF_RD),             E_ZCL_BMAP8,     (uint32)(&((tsCLD_GreenPower*)(0))->b8ZgpSharedSecKeyType), 0},
#endif

#ifdef  CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY
    {E_CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY,           (E_ZCL_AF_WR | E_ZCL_AF_RD),             E_ZCL_KEY_128,   (uint32)(&((tsCLD_GreenPower*)(0))->sZgpSharedSecKey), 0},
#endif

#ifdef  CLD_GP_ATTR_ZGP_LINK_KEY
    {E_CLD_GP_ATTR_ZGP_LINK_KEY,                      (E_ZCL_AF_WR | E_ZCL_AF_RD),             E_ZCL_KEY_128,   (uint32)(&((tsCLD_GreenPower*)(0))->sZgpLinkKey), 0},
#endif

#ifdef  CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY_TYPE
    {E_CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY_TYPE,      (E_ZCL_AF_WR | E_ZCL_AF_RD | E_ZCL_AF_CA), E_ZCL_BMAP8,   (uint32)(&((tsCLD_GreenPower*)(0))->b8ZgpSharedSecKeyType), 0},
#endif

#ifdef  CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY
    {E_CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY,           (E_ZCL_AF_WR | E_ZCL_AF_RD | E_ZCL_AF_CA), E_ZCL_KEY_128, (uint32)(&((tsCLD_GreenPower*)(0))->sZgpSharedSecKey), 0},
#endif

#ifdef  CLD_GP_ATTR_ZGP_LINK_KEY
    {E_CLD_GP_ATTR_ZGP_LINK_KEY,                      (E_ZCL_AF_WR | E_ZCL_AF_RD | E_ZCL_AF_CA), E_ZCL_KEY_128, (uint32)(&((tsCLD_GreenPower*)(0))->sZgpLinkKey), 0},
#endif

};
/* define the ZGP command cluster table to find out cluster id with respect to ZGPD command id */
const tsGP_ZgpCommandClusterTable asZgpCommadClusterTable[] = {
    {E_GP_IDENTIFY,               GP_GENERAL_CLUSTER_ID_IDENTIFY},
    {E_GP_OFF,                    GP_GENERAL_CLUSTER_ID_ONOFF},
    {E_GP_ON,                     GP_GENERAL_CLUSTER_ID_ONOFF},
    {E_GP_TOGGLE,                 GP_GENERAL_CLUSTER_ID_ONOFF},
    {E_GP_LEVEL_CONTROL_STOP,     GP_GENERAL_CLUSTER_ID_LEVEL_CONTROL},
    {E_GP_MOVE_UP_WITH_ON_OFF,    GP_GENERAL_CLUSTER_ID_LEVEL_CONTROL},
    {E_GP_MOVE_DOWN_WITH_ON_OFF,  GP_GENERAL_CLUSTER_ID_LEVEL_CONTROL},
    {E_GP_STEP_UP_WITH_ON_OFF,    GP_GENERAL_CLUSTER_ID_LEVEL_CONTROL},
    {E_GP_STEP_DOWN_WITH_ON_OFF,  GP_GENERAL_CLUSTER_ID_LEVEL_CONTROL},
    {E_GP_ATTRIBUTE_REPORTING,    GP_GENERAL_CLUSTER_ID_TEMP_MEASUREMENT},
    {E_GP_SENSOR_COMMAND,         GP_GENERAL_CLUSTER_ID_TEMP_MEASUREMENT},
    {E_GP_ZGPD_CMD_ID_ENUM_END,   GP_INVALID_CLUSTER_ID }
};

tsZCL_ClusterDefinition sCLD_GreenPower = {
    GREENPOWER_CLUSTER_ID,
    FALSE,
    E_ZCL_SECURITY_NETWORK,
    (sizeof(asCLD_GreenPowerClusterAttributeDefinitions) / sizeof(tsZCL_AttributeDefinition)),
    (tsZCL_AttributeDefinition*)asCLD_GreenPowerClusterAttributeDefinitions,
    NULL
};

uint8 au8ServerGreenPowerClusterAttributeControlBits[(sizeof(asCLD_GreenPowerClusterAttributeDefinitions) / sizeof(tsZCL_AttributeDefinition))];
uint8 au8ClientGreenPowerClusterAttributeControlBits[(sizeof(asCLD_GreenPowerClusterAttributeDefinitions) / sizeof(tsZCL_AttributeDefinition))];

/****************************************************************************
 **
 ** NAME:       eGP_CreateGreenPower
 **
 ** DESCRIPTION:
 ** Creates Green Power cluster instance either server or client
 **
 ** PARAMETERS:                         Name                                Usage
 ** tsZCL_ClusterInstance               *psClusterInstance                  Cluster structure
 ** bool_t                              bIsServer                           TRUE or FALSE
 ** tsZCL_ClusterDefinition             *psClusterDefinition                Cluster Definition Structure
 ** void                                *pvEndPointSharedStructPtr          EndPoint Shared Structure
 ** uint8                               *pu8AttributeControlBits            Attribute Control Bits
 ** tsGP_GreenPowerCustomData           *psCustomDataStructure              Custom Data Structure
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/

PUBLIC teZCL_Status eGP_CreateGreenPower(
                tsZCL_ClusterInstance              *psClusterInstance,
                bool_t                              bIsServer,
                tsZCL_ClusterDefinition            *psClusterDefinition,
                void                               *pvEndPointSharedStructPtr,
                uint8                              *pu8AttributeControlBits,
                tsGP_GreenPowerCustomData          *psCustomDataStructure)
{
    tsGP_Common    *psGP_Common;
    uint8          u8Count = 0;

    #ifdef STRICT_PARAM_CHECK 
        /* Check pointers */
        if((psClusterInstance==NULL)            ||
           (psClusterDefinition==NULL)          ||
           (pvEndPointSharedStructPtr==NULL)    ||
           (psCustomDataStructure==NULL))
        {
            return E_ZCL_ERR_PARAMETER_NULL;
        }
    #endif

    // cluster data
    
    vZCL_InitializeClusterInstance(
                                   psClusterInstance, 
                                   bIsServer,
                                   psClusterDefinition,
                                   pvEndPointSharedStructPtr,
                                   pu8AttributeControlBits,
                                   psCustomDataStructure,
                                   eGP_GreenPowerCommandHandler);    

    psClusterInstance->pvEndPointCustomStructPtr = (void *)psCustomDataStructure;
    psClusterInstance->pStringCallBackFunction = u16GP_APduInstanceReadWriteLongString;
    // initialise pointer
    psGP_Common = &((tsGP_GreenPowerCustomData *)psClusterInstance->pvEndPointCustomStructPtr)->sGPCommon;

    // clear
    memset(psGP_Common, 0, sizeof(tsGP_Common));
    psGP_Common->sReceiveEventAddress.bInitialised = FALSE;

    // initialise the c/b structures
    psGP_Common->sGPCustomCallBackEvent.eEventType = E_ZCL_CBET_CLUSTER_CUSTOM;
    psGP_Common->sGPCustomCallBackEvent.uMessage.sClusterCustomMessage.u16ClusterId = psClusterInstance->psClusterDefinition->u16ClusterEnum;
    psGP_Common->sGPCustomCallBackEvent.uMessage.sClusterCustomMessage.pvCustomData = (void *)&psGP_Common->sGreenPowerCallBackMessage;
    psGP_Common->sGPCustomCallBackEvent.psClusterInstance = psClusterInstance;

#if 0
    // server attributes set default values
    ((tsCLD_GreenPower *)(pvEndPointSharedStructPtr))->u8ZgpsMaxSinkTableEntries = GP_NUMBER_OF_SINK_TABLE_ENTRIES;
    ((tsCLD_GreenPower *)(pvEndPointSharedStructPtr))->sSinkTable.u16MaxLength = GP_MAX_SINK_TABLE_LENGTH;
    ((tsCLD_GreenPower *)(pvEndPointSharedStructPtr))->sSinkTable.pu8Data = (uint8*)psCustomDataStructure->sRemoteTableAttr.uAttribute.asSinkTable;
    ((tsCLD_GreenPower *)(pvEndPointSharedStructPtr))->b8ZgpsCommunicationMode = E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_DGROUP_ID;
    ((tsCLD_GreenPower *)(pvEndPointSharedStructPtr))->b8ZgpsCommissioningExitMode = GP_CMSNG_EXIT_MODE_ON_PAIRING_SUCCESS_MASK;

#ifdef  CLD_GP_ATTR_ZGPS_COMMISSIONING_WINDOW
    ((tsCLD_GreenPower *)(pvEndPointSharedStructPtr))->u16ZgpsCommissioningWindow = GP_COMMISSION_WINDOW_DURATION;
    ((tsCLD_GreenPower *)(pvEndPointSharedStructPtr))->b8ZgpsCommissioningExitMode |= GP_CMSNG_EXIT_MODE_ON_WINDOW_EXPIRE_MASK;
#endif

    ((tsCLD_GreenPower *)(pvEndPointSharedStructPtr))->b8ZgpsSecLevel = E_GP_NO_SECURITY;
    ((tsCLD_GreenPower *)(pvEndPointSharedStructPtr))->b24ZgpsActiveFeatures = GP_ZGP_ACTIVE_FEATURES_ATTR_DEFAULT_VALUE;

    // client attributes set default values
    ((tsCLD_GreenPower *)(pvEndPointSharedStructPtr))->u8ZgppMaxProxyTableEntries = GP_NUMBER_OF_PROXY_TABLE_ENTRIES;
    ((tsCLD_GreenPower *)(pvEndPointSharedStructPtr))->sProxyTable.u16MaxLength = GP_MAX_PROXY_TABLE_LENGTH;
    ((tsCLD_GreenPower *)(pvEndPointSharedStructPtr))->sProxyTable.pu8Data = (uint8*)psCustomDataStructure->sRemoteTableAttr.uAttribute.asProxyTable;
#ifdef  CLD_GP_ATTR_ZGPP_NOTIFICATION_RETRY_NUMBER
    ((tsCLD_GreenPower *)(pvEndPointSharedStructPtr))->u8ZgppNotificationRetryNumber = 2;
#endif

#ifdef  CLD_GP_ATTR_ZGPP_NOTIFICATION_RETRY_TIMER
    ((tsCLD_GreenPower *)(pvEndPointSharedStructPtr))->u8ZgppNotificationRetryTimer = 0x64;
#endif

#ifdef  CLD_GP_ATTR_ZGPP_MAX_SEARCH_COUNTER
    ((tsCLD_GreenPower *)(pvEndPointSharedStructPtr))->u8ZgppMaxSearchCounter = 0x0A;
#endif

#ifdef  CLD_GP_ATTR_ZGPP_BLOCKED_GPD_ID
    ((tsCLD_GreenPower *)(pvEndPointSharedStructPtr))->sZgppBlockedGpdID.u16Length = 0;
#endif
    ((tsCLD_GreenPower *)(pvEndPointSharedStructPtr))->b24ZgppFunctionality = E_GP_NO_SECURITY;
    ((tsCLD_GreenPower *)(pvEndPointSharedStructPtr))->b24ZgppActiveFunctionality = GP_ZGP_ACTIVE_FEATURES_ATTR_DEFAULT_VALUE;
#endif
    /* Initialize list pointers */
    vDLISTinitialise(&psCustomDataStructure->lGpAllocList);
    vDLISTinitialise(&psCustomDataStructure->lGpDeAllocList);

    for(u8Count=0; u8Count < GP_MAX_NUMBER_BUFFERED_RECORDS; u8Count++)
    {
        /* add all APDUs to the to free list */
        vDLISTaddToTail(&psCustomDataStructure->lGpDeAllocList, (DNODE *)&psCustomDataStructure->asZgpBufferedApduRecord[u8Count]);
    }
    //initialize the aging time of duplicate table
    for(u8Count = 0; u8Count < GP_MAX_DUPLICATE_TABLE_ENTIRES; u8Count++)
    {
        psCustomDataStructure->asZgpDuplicateFilterTable[u8Count].u16AgingTime = 0;
    }
    psCustomDataStructure->u8GPDataReqHandle = 0x81;

    return E_ZCL_SUCCESS;
}


/****************************************************************************
**
** NAME:       eGP_FindGpCluster
**
** DESCRIPTION:
** Search for GreenPower cluster
**
** PARAMETERS:                   Name                            Usage
** uint8                         u8SourceEndPointId              Source EP Id
** bool                          bIsServer                       Server or Client
** tsZCL_EndPointDefinition      **ppsEndPointDefinition         EP
** tsZCL_ClusterInstance         **ppsClusterInstance            Cluster
** tsOTA_Common                  **ppsOTACustomDataStructure     event data
**
** RETURN:
** teZCL_Status
**
****************************************************************************/
PUBLIC teZCL_Status eGP_FindGpCluster(
                    uint8                          u8SourceEndPoint,
                    bool                           bIsServer,
                    tsZCL_EndPointDefinition       **ppsEndPointDefinition,
                    tsZCL_ClusterInstance          **ppsClusterInstance,
                    tsGP_GreenPowerCustomData      **ppsGpCustomDataStructure)
{

    /* Check EP range */
    if(u8SourceEndPoint == 0)
    {
        return(E_ZCL_ERR_EP_RANGE);
    }

    // check EP is registered and cluster is present in the device
    if(eZCL_SearchForEPentry(u8SourceEndPoint, ppsEndPointDefinition) != E_ZCL_SUCCESS)
    {
        return(E_ZCL_ERR_EP_RANGE);
    }

    // search for cluster entry
    if(eZCL_SearchForClusterEntry(u8SourceEndPoint, GREENPOWER_CLUSTER_ID, bIsServer, ppsClusterInstance) != E_ZCL_SUCCESS)
    {
        return(E_ZCL_ERR_CLUSTER_NOT_FOUND);
    }

    // initialise custom data pointer
    *ppsGpCustomDataStructure = (tsGP_GreenPowerCustomData *)(*ppsClusterInstance)->pvEndPointCustomStructPtr;

    /* Check custom data structure pointer */
    if(*ppsGpCustomDataStructure==NULL)
    {
        return(E_ZCL_ERR_CUSTOM_DATA_NULL);
    }

    return(E_ZCL_SUCCESS);
}

/****************************************************************************
**
** NAME:       u16GP_DeriveAliasSrcAddr
**
** DESCRIPTION:
** Derivation of alias source address
**
** PARAMETERS:                  Name                      Usage
** uint8                        u8ApplicationId           application id to identified type of ZGPD ID
** tuGP_ZgpdDeviceAddr          uZgpdID                   ZGPD ID
**
** RETURN:
** uint16
****************************************************************************/
PUBLIC uint16 u16GP_DeriveAliasSrcAddr(uint8 u8ApplicationId, tuGP_ZgpdDeviceAddr uZgpdID)
{
    uint16 u16AliasShortAddr;
    uint32 u32ZgpdSrcAddr = 0;

    /* check application Id */
    if(0 == u8ApplicationId)
    {
        u32ZgpdSrcAddr = uZgpdID.u32ZgpdSrcId;
    }
#ifdef GP_IEEE_ADDR_SUPPORT
    else
    {
        u32ZgpdSrcAddr =    (uint32)uZgpdID.u64ZgpdIEEEAddr;
    }
#endif

    u16AliasShortAddr = (uint16)u32ZgpdSrcAddr;     /* Take lower two bytes */

    /* Alias address shouldn't be ZCORD address and NWK broadcast addresses */
    if((u16AliasShortAddr != 0) && (u16AliasShortAddr < GP_NWK_MIN_BROADCAST_ADDRESS))
    {
        return(u16AliasShortAddr);
    }
    /* Logical OR with higher two bytes */
    u16AliasShortAddr ^= (uint16)(u32ZgpdSrcAddr >> 16);

    /* Alias address shouldn't be ZCORD address and NWK broadcast addresses */
    if((u16AliasShortAddr != 0) && (u16AliasShortAddr < GP_NWK_MIN_BROADCAST_ADDRESS))
    {
        return(u16AliasShortAddr);
    }

    u16AliasShortAddr = (uint16)u32ZgpdSrcAddr;
    /* if alias address is ZCORD address then return 0x0007 */
    if(u16AliasShortAddr == 0)
    {
      return(0x0007);
    }
    else
    {
        return(u16AliasShortAddr - 0x0008);
    }
}

/****************************************************************************
**
** NAME:       u8GP_DeriveAliasSeqNum
**
** DESCRIPTION:
** Derivation of alias sequence number
**
** PARAMETERS:                          Name                       Usage
** uint8                                u8GpdfSeqNum               GPDF Sequence number
** teGP_GreenPowerClusterCmdIds       . eGpCmdId                   GP Command id
** teGP_GreenPowerCommunicationMode     eCommunicationMode         communication mode
**
** RETURN:
** uint8
****************************************************************************/
PUBLIC uint8 u8GP_DeriveAliasSeqNum(
                    uint8                                  u8GpdfSeqNum,
                    teGP_GreenPowerClusterCmdIds           eGpCmdId,
                    teGP_GreenPowerCommunicationMode       eCommunicationMode)
{

    if(E_GP_ZGP_NOTIFICATION == eGpCmdId)
    {
        if(E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_DGROUP_ID == eCommunicationMode)
        {
            return  u8GpdfSeqNum;
        }
        else if(E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID == eCommunicationMode)
        {
            return(u8GpdfSeqNum - 13);
        }
    }
    else if(E_GP_ZGP_COMMOSSIONING_NOTIFICATION == eGpCmdId)
    {
        return(u8GpdfSeqNum - 12);
    }
    else if(E_GP_ZGP_TUNNELING_STOP == eGpCmdId)
    {
        return(u8GpdfSeqNum - 11);
    }
    else if(E_GP_ZGP_PAIRING_SEARCH == eGpCmdId)
    {
       return(u8GpdfSeqNum - 10);
    }

    return 0;
}

/****************************************************************************
 **
 ** NAME:       u32GP_CRC32
 **
 ** DESCRIPTION:
 ** Calculates 32 bit CRC
 **
 ** PARAMETERS:                  Name                      Usage
 ** uint8                        *pu8Data                  data pointer to calculate CRC
 ** uint32                       u32Len                    length of the data
 **
 ** RETURN:
 ** uint32
 ****************************************************************************/
PUBLIC uint32 u32GP_CRC32(uint8 *pu8Data, uint32 u32Len)
{
    uint32 u32Result;
    uint8 u8Octet;
    unsigned int i,j;

    u32Result = -1;

    for (i = 0; i < u32Len; i++)
    {
        u8Octet = *(pu8Data++);
        for (j = 0; j < 8; j++)
        {
            if ((u8Octet >> 7) ^ (u32Result >> 31))
            {
                u32Result = (u32Result << 1) ^ 0x04c11db7UL;
            }
            else
            {
                u32Result = (u32Result << 1);
            }
            u8Octet <<= 1;
        }
    }

    return ~u32Result; /* The complement of the remainder */
}

/****************************************************************************
 **
 ** NAME:       bGP_IsDuplicatePkt
 **
 ** DESCRIPTION:
 ** performing Duplicate filter check
 **
 ** PARAMETERS:                 Name                        Usage
 ** uint8                       u8SourceEndPointId          Source EP ID
 ** bool                        bIsServer                   Server cluster or client cluster
 ** uint16                      u16ShortAddr                Short Address
 ** bool_t                      bSecurityOptions            Security Options
 ** uint32                      u32SeqNoOrCounter           MAC Sequence Number or Security Frame Counter
 ** uint8                       u8CommandId                 GP Command Id
 ** uint8                       u8PayloadLength             GP Command Length
 ** uint8                       *pu8Payload                 GP Command payload
 ** uint16                      u16SourceAddress            Source short address
 **
 ** RETURN:
 ** bool_t
 ****************************************************************************/
PUBLIC bool_t bGP_IsDuplicatePkt(
                    uint8                                  u8SourceEndPointId,
                    bool                                   bIsServer,
                    uint8                                  u8ApplicationID,
                    tuGP_ZgpdDeviceAddr                    uZgpdDeviceAddr,
                    bool_t                                 bSecurityOptions,
                    uint32                                 u32SeqNoOrCounter,
                    uint8                                  u8CommandId,
                    uint8                                  u8PayloadLength,
                    uint8                                  *pu8Payload,
                    uint16                                 u16SourceAddress,
                    tsGP_GreenPowerCustomData              *psGpCustomDataStructure)
{
    //tsZCL_EndPointDefinition *psEndPointDefinition;
    //tsZCL_ClusterInstance *psClusterInstance;
    //tsGP_GreenPowerCustomData  *psGpCustomDataStructure;
    //teZCL_Status eStatus;
    uint8 i, u8TempData[GP_MAX_ZB_CMD_PAYLOAD_LENGTH + 16], u8Index = 0;
    uint32 u32CRC = 0;

    /* Find cluster */
    /*eStatus = eGP_FindGpCluster(u8SourceEndPointId,
                                bIsServer,
                                &psEndPointDefinition,
                                &psClusterInstance,
                                &psGpCustomDataStructure);


    if(eStatus != E_ZCL_SUCCESS)
    {
        return(eStatus);
    }
    */
    // get EP mutex
    //eZCL_GetMutex(psEndPointDefinition);

    /* If packet rxed with no security, calculate CRC over device address, counter, GP command id,
     * payload length and payload */
    if(!bSecurityOptions)
    {

        if(u8ApplicationID == GP_APPL_ID_4_BYTE)
        {
            memcpy(u8TempData,(uint8*)&uZgpdDeviceAddr.u32ZgpdSrcId,4);
            u8Index += 4;
        }
#ifdef GP_IEEE_ADDR_SUPPORT
        else
        {
            memcpy(u8TempData,(uint8*)&uZgpdDeviceAddr.u64ZgpdIEEEAddr,8);
            u8Index += 8;
        }
#endif

        memcpy(u8TempData+u8Index,(uint8*)&u16SourceAddress,2);
        u8Index += 2;

        memcpy(u8TempData+u8Index,(uint8*)&u32SeqNoOrCounter,4);
        u8Index += 4;
        u8TempData[u8Index++] = u8CommandId;
        u8TempData[u8Index++] = u8PayloadLength;

        if(u8PayloadLength > GP_MAX_ZB_CMD_PAYLOAD_LENGTH)
        { /* since we have taken u8TempData buffer of only GP_MAX_ZB_CMD_PAYLOAD_LENGTH + 8 byte
             so if payload is more than GP_MAX_ZB_CMD_PAYLOAD_LENGTH bytes
             we are taking only GP_MAX_ZB_CMD_PAYLOAD_LENGTH bytes in calculation */
            u8PayloadLength = GP_MAX_ZB_CMD_PAYLOAD_LENGTH;
        }

        memcpy(u8TempData+u8Index,pu8Payload,u8PayloadLength);

        u32CRC = u32GP_CRC32(u8TempData,(uint32)(u8Index+u8PayloadLength));
    }

    /* traverse through duplicate table to check entry is existed or not. If entry existed
     * returns TRUE otherwise FALSE */
    for(i = 0; i< GP_MAX_DUPLICATE_TABLE_ENTIRES; i++)
    {
        if(psGpCustomDataStructure->asZgpDuplicateFilterTable[i].u16AgingTime != 0)
        {
            if( ((psGpCustomDataStructure->asZgpDuplicateFilterTable[i].u3ApplicationID == GP_APPL_ID_4_BYTE)&&
                (psGpCustomDataStructure->asZgpDuplicateFilterTable[i].uZgpdDeviceAddr.u32ZgpdSrcId == uZgpdDeviceAddr.u32ZgpdSrcId))
#ifdef GP_IEEE_ADDR_SUPPORT
                || ((psGpCustomDataStructure->asZgpDuplicateFilterTable[i].u3ApplicationID == GP_APPL_ID_8_BYTE)&&
              (psGpCustomDataStructure->asZgpDuplicateFilterTable[i].uZgpdDeviceAddr.u64ZgpdIEEEAddr == uZgpdDeviceAddr.u64ZgpdIEEEAddr))
#endif
              )
            {

                if(psGpCustomDataStructure->asZgpDuplicateFilterTable[i].bSecurityOptions)
                {
                     /* compare */
                    if(psGpCustomDataStructure->asZgpDuplicateFilterTable[i].uData.u32SecFrameCounter == u32SeqNoOrCounter)
                    {
                        // release mutex
                        //eZCL_ReleaseMutex(psEndPointDefinition);
                        return TRUE;
                    }
                }
                else
                {   /* compare */
                    if(u32CRC == psGpCustomDataStructure->asZgpDuplicateFilterTable[i].uData.u32gpdCrc)
                    {
                        // release mutex
                        //eZCL_ReleaseMutex(psEndPointDefinition);
                        return TRUE;
                    }
                }
            }
        }
    }

    /* packet is not duplicate so add this entry in duplicate filter */
    for(i = 0; i< GP_MAX_DUPLICATE_TABLE_ENTIRES; i++)
     {
        /* find the free duplicate table entry */
        if(psGpCustomDataStructure->asZgpDuplicateFilterTable[i].u16AgingTime == 0)
        {
            psGpCustomDataStructure->asZgpDuplicateFilterTable[i].u16AgingTime = (GP_ZGP_DUPLICATE_TIMEOUT * 50);
            psGpCustomDataStructure->asZgpDuplicateFilterTable[i].u3ApplicationID = u8ApplicationID;
            psGpCustomDataStructure->asZgpDuplicateFilterTable[i].uZgpdDeviceAddr = uZgpdDeviceAddr;
            psGpCustomDataStructure->asZgpDuplicateFilterTable[i].bSecurityOptions = bSecurityOptions;
            if(bSecurityOptions)
            {
                psGpCustomDataStructure->asZgpDuplicateFilterTable[i].uData.u32SecFrameCounter = u32SeqNoOrCounter;
            }
            else
            {
                psGpCustomDataStructure->asZgpDuplicateFilterTable[i].uData.u32gpdCrc = u32CRC;
            }
            break;
        }
     }

    // release mutex
    //eZCL_ReleaseMutex(psEndPointDefinition);

    return FALSE;
}

/****************************************************************************
 **
 ** NAME:       u16GP_APduInstanceReadWriteLongString
 **
 ** DESCRIPTION:
 ** Performs either writing into APDU or updates attribute value based received command type
 **
 ** PARAMETERS:                  Name                               Usage
 ** uint8                        u8EndPoint                         End Point Id
 ** uint16                       u16AttributeId                     Attribute Id
 ** bool_t                       IsClientAttribute                  Client attribute or not
 ** bool_t                       bWriteAttributeValueIntoBuffer     Write into APDU buffer or update local attribute value
 ** PDUM_thAPduInstance          hAPduInst                          PDU buffer
 ** uint16                       u16Pos                             position in buffer
 ** uint16                       *pu16NoOfBytes                     Number of bytes to be written or read to/from APDU
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/

PUBLIC teZCL_Status u16GP_APduInstanceReadWriteLongString(
                    uint8                                  u8EndPoint,
                    uint16                                 u16AttributeId,
                    bool_t                                 IsClientAttribute,
                    bool_t                                 bWriteAttributeValueIntoBuffer,
                    PDUM_thAPduInstance                    hAPduInst,
                    uint16                                 u16Pos,
                    uint16                                 *pu16NoOfBytes)
{
    uint8 *pu8stringData;
    uint16 u16stringSize, /*u16stringDataLength, u16stringLengthField = 0, */u16APduSize;

    /* Check APDU instance handle */
    if(hAPduInst)
    {
#ifdef GP_COMBO_MIN_DEVICE
        /* Is Attribute Id sink table attribute Id and attribute should be server attribute */
        if((u16AttributeId == E_CLD_GP_ATTR_ZGPS_SINK_TABLE)&&(!IsClientAttribute))
        {
            /* write into APDU buffer or read from buffer */
            if(bWriteAttributeValueIntoBuffer)
            {
                // get APDU size
                uint16 u16APduSize = PDUM_u16APduGetSize(PDUM_thAPduInstanceGetApdu(hAPduInst));

                // get string size
                u16stringSize = u16GP_GetStringSizeOfSinkTable(u8EndPoint);

                // check that whole string can fit into the buffer
                // write to buffer
                if ((u16Pos + u16stringSize + 1) < u16APduSize)
                {
                    // get start
                    uint8 *pu8Start = (uint8 *)(PDUM_pvAPduInstanceGetPayload(hAPduInst)) + u16Pos;
                    // write type, return size
                    *pu16NoOfBytes = u16GP_WriteSinkTableString(u8EndPoint, pu8Start, u16stringSize);
                    return E_ZCL_SUCCESS;
                }
            }
            else
            {
                //uint16 u16typeSize;

                /* Get Attribute type and size */
                if(eZCL_GetAttributeTypeSizeFromBuffer(E_ZCL_LOSTRING,
                                                       hAPduInst,
                                                       u16Pos,
                                                       &u16stringSize)== E_ZCL_SUCCESS)
                {

                     // get APDU size
                    u16APduSize = PDUM_u16APduGetSize(PDUM_thAPduInstanceGetApdu(hAPduInst));

                    // get string size
                    /*u16stringSize = u16ZCL_GetStringAttributeTypeSizeFromBuffer(E_ZCL_LOSTRING,
                                                                                &u16stringDataLength,
                                                                                &u16stringLengthField,
                                                                                &pu8stringData,
                                                                                (uint8 *)(PDUM_pvAPduInstanceGetPayload(hAPduInst)) + u16Pos);
                    */
                    pu8stringData = (uint8 *)(PDUM_pvAPduInstanceGetPayload(hAPduInst)) + u16Pos +2;
                    // read from buffer
                    if ((u16Pos + u16stringSize - 1) < u16APduSize)
                    {
                        // write type, return size
                        *pu16NoOfBytes = u16GP_ReadSinkTableString(u8EndPoint, pu8stringData, u16stringSize);
                        return E_ZCL_SUCCESS;
                    }
                }
            }
        }
#endif
#ifdef GP_PROXY_DEVICE
        /* Is Attribute Id proxy table attribute Id and attribute should be client attribute */
        if((u16AttributeId == E_CLD_GP_ATTR_ZGPP_PROXY_TABLE)&&(IsClientAttribute))
        {
            /* write into APDU buffer or read from buffer */
            if(bWriteAttributeValueIntoBuffer)
            {
                // get APDU size
                uint16 u16APduSize = PDUM_u16APduGetSize(PDUM_thAPduInstanceGetApdu(hAPduInst));

                // get string size
                u16stringSize = u16GP_GetStringSizeOfProxyTable(u8EndPoint);

                // check that whole string can fit into the buffer
                // write to buffer
                if ((u16Pos + u16stringSize + 1) < u16APduSize)
                {
                    // get start
                    uint8 *pu8Start = (uint8 *)(PDUM_pvAPduInstanceGetPayload(hAPduInst)) + u16Pos;
                    // write type, return size
                    *pu16NoOfBytes = u16GP_WriteProxyTableString(u8EndPoint, pu8Start, u16stringSize);
                    return E_ZCL_SUCCESS;
                }
            }
            else
            {
                //uint16 u16typeSize;

                /* Get Attribute type and size */
                if(eZCL_GetAttributeTypeSizeFromBuffer(E_ZCL_LOSTRING,
                                                       hAPduInst,
                                                       u16Pos,
                                                       &u16stringSize)== E_ZCL_SUCCESS)
                {

                     // get APDU size
                    u16APduSize = PDUM_u16APduGetSize(PDUM_thAPduInstanceGetApdu(hAPduInst));

                    // get string size
                    /*u16stringSize = u16ZCL_GetStringAttributeTypeSizeFromBuffer(E_ZCL_LOSTRING,
                                                                                &u16stringDataLength,
                                                                                &u16stringLengthField,
                                                                                &pu8stringData,
                                                                                (uint8 *)(PDUM_pvAPduInstanceGetPayload(hAPduInst)) + u16Pos);
                    */
                    pu8stringData = (uint8 *)(PDUM_pvAPduInstanceGetPayload(hAPduInst)) + u16Pos +2;
                    // read from buffer
                    if ((u16Pos + u16stringSize - 1) < u16APduSize)
                    {
                        // write type, return size
                        *pu16NoOfBytes = u16GP_ReadProxyTableString(u8EndPoint, pu8stringData, u16stringSize);
                        return E_ZCL_SUCCESS;
                    }
                }
            }
        }
#endif
    }

    return E_ZCL_FAIL;
}

/****************************************************************************
 **
 ** NAME:       bGP_AliasPresent
 **
 ** DESCRIPTION:
 ** Verifying device announce address with ZGPD alias address
 **
 ** PARAMETERS:                    Name                           Usage
 ** uint16                         u16Address                     16-bit NWK address of device
 ** uint64                         u64IEEEAddr                    64-bit IEEE Address of device
 ** uint8                          u8AliasSeq                     Rxed APS sequece number in device announce
 **
 **
 ** RETURN:
 ** bool_t
 ****************************************************************************/
PUBLIC bool bGP_AliasPresent(uint16 u16Address, uint64 u64IEEEAddr, uint8 u8AliasSeq)
{
    tsZCL_EndPointDefinition        *psEndPointDefinition;
    tsZCL_ClusterInstance           *psClusterInstance;
    tsGP_GreenPowerCustomData       *psGpCustomDataStructure;
#ifdef GP_COMBO_MIN_DEVICE
    tsGP_ZgpsSinkTable              *psZgpsSinkTable;
#endif
#ifdef GP_PROXY_DEVICE
    tsGP_ZgppProxyTable             *psZgppProxyTable;
#endif
    teZCL_Status                    eStatus;
    uint8                           u8NumberOfendpoints, i, j;
    bool                            bIsGpClusterFound = FALSE, bAliasMatched = FALSE;
    ZPS_tsAplZdpDeviceAnnceReq      sZdpDeviceAnnceReq;
    PDUM_thAPduInstance             hAPduInst;
    uint8                           u8TransactionSequenceNumber;

    u8NumberOfendpoints = u8ZCL_GetNumberOfEndpointsRegistered();

    // find GP clusters on each EP - if any
    for(i=0; i<u8NumberOfendpoints; i++)
    {
       /* As local GP end point is not known find GP end point */
        if((eStatus = eGP_FindGpCluster(
                            u8ZCL_GetEPIdFromIndex(i),
                            TRUE,
                            &psEndPointDefinition,
                            &psClusterInstance,
                            &psGpCustomDataStructure)) == E_ZCL_SUCCESS)
        {
            bIsGpClusterFound = TRUE;
            break;
        }
    }

    // get EP mutex
    #ifndef COOPERATIVE
        eZCL_GetMutex(psEndPointDefinition);
    #endif


    /* If GP cluster found then verify alias address */
    /* Check only if IEEE address is other than 0xFFFFFFFFFFFFFFFF */
    if(bIsGpClusterFound && u64IEEEAddr != 0xFFFFFFFFFFFFFFFFULL)
    {
#ifdef GP_PROXY_DEVICE
        psZgppProxyTable = psGpCustomDataStructure->asZgppProxyTable;

        /* Traverse proxy table */
        for(i = 0; i < GP_NUMBER_OF_PROXY_TABLE_ENTRIES; i++)
        {
            /* check any of sink address list member matched with passed NWK address,
             * if yes then update the mapping of sink IEEE address to sink nwk addr */
             //TBD

            uint16 u16AliasAddr;
            /* check any of alias address matched with passed NWK address */

            /* Check if assigned address present then compare with it otherwise compare
             * with derived alias address */

            if(psZgppProxyTable[i].b16Options & GP_PROXY_TABLE_ASSIGNED_ALIAS_MASK)
            {
                u16AliasAddr = psZgppProxyTable[i].u16ZgpdAssignedAlias;
                /* compare */
                if(u16AliasAddr == u16Address)
                {
                    bAliasMatched = TRUE;
                }
            }

            if(psZgppProxyTable[i].b16Options & GP_PROXY_TABLE_COMMISSION_GROUP_GPS_MASK)
            {
                for(j = 0; j < psZgppProxyTable[i].u8SinkGroupListEntries; j++)
                {
                    if(psZgppProxyTable[i].asSinkGroupList[j].u16Alias == u16Address)
                    {
                        bAliasMatched = TRUE;
                        break;
                    }
                    else if((psZgppProxyTable[i].asSinkGroupList[j].u16Alias == 0xFFFF)&&(psZgppProxyTable[i].asSinkGroupList[j].u16SinkGroup != 0))
                    {
                        /* Get derived address for this device */
                        u16AliasAddr = u16GP_DeriveAliasSrcAddr(
                                (uint8)(psZgppProxyTable[i].b16Options & GP_APPLICATION_ID_MASK),
                                psZgppProxyTable[i].uZgpdDeviceAddr);
                        /* compare */
                        if(u16AliasAddr == u16Address)
                        {
                            bAliasMatched = TRUE;
                            break;
                        }
                    }
                }
            }

            if(psZgppProxyTable[i].b16Options & GP_PROXY_TABLE_DERIVED_GROUP_GPS_MASK)
            {
                /* Get derived address for this device */
                u16AliasAddr = u16GP_DeriveAliasSrcAddr(
                        (uint8)(psZgppProxyTable[i].b16Options & GP_APPLICATION_ID_MASK),
                        psZgppProxyTable[i].uZgpdDeviceAddr);
                /* compare */
                if(u16AliasAddr == u16Address)
                {
                    bAliasMatched = TRUE;
                }
            }
        }

#endif
#ifdef GP_COMBO_MIN_DEVICE
        psZgpsSinkTable = psGpCustomDataStructure->asZgpsSinkTable;

        /* Traverse sink table, check any of alias address matched with passed NWK address */
        for(i = 0; i < GP_NUMBER_OF_SINK_TABLE_ENTRIES; i++)
        {
            /* Check if assigned address present then compare with it otherwise compare
             * with derived alias address */
            if(psZgpsSinkTable[i].eGreenPowerSinkTablePriority != 0x00)
            {
                uint16 u16AliasAddr;
                teGP_GreenPowerCommunicationMode eCommunicationMode;
                /* Get communication mode */
                eCommunicationMode = (psZgpsSinkTable[i].b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3;
                /* check assigned address is present for this ZGPD */
                if(psZgpsSinkTable[i].b16Options & GP_SINK_TABLE_ASSIGNED_ADDR_MASK)
                {
                    u16AliasAddr = psZgpsSinkTable[i].u16ZgpdAssignedAlias;
                    /* compare */
                    if(u16AliasAddr == u16Address)
                    {
                        bAliasMatched = TRUE;
                    }
                }

                if(eCommunicationMode == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID)
                {
                    for(j = 0; j < psZgpsSinkTable[i].u8ZgpsGroupListEntries; j++)
                    {
                        if(psZgpsSinkTable[i].asZgpsGroupList[j].u16Alias == u16Address)
                        {
                            bAliasMatched = TRUE;
                            break;
                        }
                        else if((psZgpsSinkTable[i].asZgpsGroupList[j].u16Alias == 0xFFFF)&&(psZgpsSinkTable[i].asZgpsGroupList[j].u16SinkGroup != 0))
                        {
                            /* Get derived address for this device */
                            u16AliasAddr = u16GP_DeriveAliasSrcAddr(
                                    (uint8)(psZgpsSinkTable[i].b16Options & GP_APPLICATION_ID_MASK),
                                    psZgpsSinkTable[i].uZgpdDeviceAddr);
                            /* compare */
                            if(u16AliasAddr == u16Address)
                            {
                                bAliasMatched = TRUE;
                                break;
                            }
                        }
                    }
                }
                else
                {
                    /* Get derived address for this device */
                    u16AliasAddr = u16GP_DeriveAliasSrcAddr(
                            (uint8)(psZgpsSinkTable[i].b16Options & GP_APPLICATION_ID_MASK),
                            psZgpsSinkTable[i].uZgpdDeviceAddr);
                    /* compare */
                    if(u16AliasAddr == u16Address)
                    {
                        bAliasMatched = TRUE;
                    }
                }


            }
        }
#endif
    }

    if(bAliasMatched)
    {
        /* Populate device announce request */
        sZdpDeviceAnnceReq.u16NwkAddr = u16Address;
        sZdpDeviceAnnceReq.u64IeeeAddr = 0xFFFFFFFFFFFFFFFFULL;
        sZdpDeviceAnnceReq.u8Capability = 0x00;

        /* allocate Apdu instance */
        hAPduInst = hZCL_AllocateAPduInstance();

        if(hAPduInst != NULL)
        {
            ZPS_vAfSetZgpAlias(u16Address, 0x00);

            if((ZPS_eAplZdpDeviceAnnceRequest(hAPduInst,
                                              &u8TransactionSequenceNumber,
                                              &sZdpDeviceAnnceReq)) != E_ZCL_SUCCESS)
            {
                /* Free hAPDU */
                PDUM_eAPduFreeAPduInstance(hAPduInst);
            }
        }
    }
    // release mutex
    #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif

    return bAliasMatched;
}
/****************************************************************************
 **
 ** NAME:       u8GP_SecurityProcessCallback
 **
 ** DESCRIPTION:
 ** Process security of received GPDF when a callback is received from stack
 **
 ** PARAMETERS:                    Name                           Usage
 ** ZPS_tsZgpSecReq               psSec                      pointer of security request structure
 ** uint8                         pu8SecIndex                pointer to index of security table
 **
 **
 ** RETURN:
 ** uint8
 ****************************************************************************/
PUBLIC uint8 u8GP_SecurityProcessCallback(ZPS_tsZgpSecReq *psSec, uint8 *pu8SecIndex)
{

    ZPS_tsZgpGpstEntry     *psZgpGpstEntry;
    uint8 i;

    if(psSec->u8SecurityLevel == E_GP_NO_SECURITY)
    {
        return ((uint8)ZPS_E_PASS_UNPROCESSED);
    }
    DBG_vPrintf(TRACE_GP_DEBUG, "\nSecurity Request callback\n");
    psZgpGpstEntry = ZPS_psZgpFindGpstEntry((uint32)psSec->u8ApplicationId, psSec->uGpId, pu8SecIndex);

    /* GP security table entry not found for this GPD then add a entry in security table */
    if(psZgpGpstEntry == NULL)
    {
        if(bGP_AddDeviceSecurity(psSec) == FALSE)
        {
            DBG_vPrintf(TRACE_GP_DEBUG, "ZPS_E_DROP_FRAME\n");
            return((uint8)ZPS_E_DROP_FRAME);
        }

        psZgpGpstEntry = ZPS_psZgpFindGpstEntry((uint32)psSec->u8ApplicationId, psSec->uGpId, pu8SecIndex);
    }
    else if(psSec->u8KeyType && psZgpGpstEntry->u8KeyType < E_GP_OUT_OF_THE_BOX_ZGPD_KEY)
    {
        return ZPS_E_DROP_FRAME;
    }
    else if(!psSec->u8KeyType && psZgpGpstEntry->u8KeyType > E_GP_NWK_KEY_DERIVED_ZGPD_GROUP_KEY)
    {
        return ZPS_E_DROP_FRAME;
    }

#if 1
    DBG_vPrintf(TRACE_GP_DEBUG, "GPST index %d\n", *pu8SecIndex);
    DBG_vPrintf(TRACE_GP_DEBUG, "key:");
    for(i=0;i<AESSW_BLK_SIZE;i++)
    DBG_vPrintf(TRACE_GP_DEBUG, " 0x%x,", psZgpGpstEntry->uSecurityKey.au8[i]);
    DBG_vPrintf(TRACE_GP_DEBUG, "\nGPD ID 0x%08x\n", psZgpGpstEntry->uGpId.u32SrcId);
    DBG_vPrintf(TRACE_GP_DEBUG, "GPST security level %d\n", psZgpGpstEntry->u8SecurityLevel);
    DBG_vPrintf(TRACE_GP_DEBUG, "GPST key type %d\n", psZgpGpstEntry->u8KeyType);
    DBG_vPrintf(TRACE_GP_DEBUG, "GPST valid %d\n", psZgpGpstEntry->bValid);
#endif

    if(psSec->u8SecurityLevel == E_GP_ONE_LSB_FC_SHORT_MIC)
    {
        bGP_UpdateSecurityFrameCounter(psSec, &psZgpGpstEntry->u32Counter);
    }
    else
    {
        psZgpGpstEntry->u32Counter = psSec->u32FrameCounter;
    }

    return((uint8)ZPS_E_MATCH );
}
/****************************************************************************
 **
 ** NAME:       vGP_CallbackForPersistData(teGP_ZgpsPersistChange eGPChangeCause)
 **
 ** DESCRIPTION:
 ** call persist attribute data call back message to application
 **
 ** PARAMETERS:                    Name                           Usage
 ** teGP_ZgpsPersistChange 			eGPChangeCause
 **
 ** RETURN:
 ** None
 ****************************************************************************/
PUBLIC void vGP_CallbackForPersistData(teGP_ZgpsPersistChange eGPChangeCause)
{
#ifndef PC_PLATFORM_BUILD
    tsZCL_EndPointDefinition        *psEndPointDefinition;
    tsZCL_ClusterInstance           *psClusterInstance;
    tsGP_GreenPowerCustomData       *psGpCustomDataStructure;
    uint8                           u8NumberOfendpoints, i;
    tsGP_PersistedData              sPersistedData;

    u8NumberOfendpoints = u8ZCL_GetNumberOfEndpointsRegistered();

    // find GP clusters on each EP - if any
    for(i=0; i<u8NumberOfendpoints; i++)
    {
       /* As local GP end point is not known find GP end point */
#ifdef GP_COMBO_MIN_DEVICE
        if(eGP_FindGpCluster(u8ZCL_GetEPIdFromIndex(i),
                             TRUE,
                             &psEndPointDefinition,
                             &psClusterInstance,
                             &psGpCustomDataStructure) == E_ZCL_SUCCESS)
        {
            // get EP mutex
            #ifndef COOPERATIVE
                eZCL_GetMutex(psEndPointDefinition);
            #endif



            // server attributes set
            sPersistedData.psAttributes = ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr));
           /* sPersistedData.psAttributes->u8ZgpsMaxSinkTableEntries = ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->u8ZgpsMaxSinkTableEntries;
            sPersistedData.psAttributes->sSinkTable = ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->sSinkTable;
            sPersistedData.psAttributes->b8ZgpsCommunicationMode = ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->b8ZgpsCommunicationMode;
            sPersistedData.psAttributes->b8ZgpsCommissioningExitMode = ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->b8ZgpsCommissioningExitMode;

#ifdef  CLD_GP_ATTR_ZGPS_COMMISSIONING_WINDOW
            sPersistedData.psAttributes->u16ZgpsCommissioningWindow = ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->u16ZgpsCommissioningWindow;
#endif

            sPersistedData.psAttributes->b8ZgpsSecLevel = ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->b8ZgpsSecLevel;
            sPersistedData.psAttributes->b24ZgpsFeatures = ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->b24ZgpsFeatures;
            sPersistedData.psAttributes->b24ZgpsActiveFeatures = ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->b24ZgpsActiveFeatures;

#ifdef  CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY_TYPE
            sPersistedData.psAttributes->b8ZgpSharedSecKeyType = ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->b8ZgpSharedSecKeyType;
#endif

#ifdef  CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY
            sPersistedData.psAttributes->sZgpSharedSecKey = ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->sZgpSharedSecKey;
#endif

#ifdef  CLD_GP_ATTR_ZGP_LINK_KEY
            sPersistedData.psAttributes->sZgpLinkKey = ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->sZgpLinkKey;
#endif

*/
            //  memcpy(sPersistedData.pasZgpsSinkTable, psGpCustomDataStructure->asZgpsSinkTable, GP_NUMBER_OF_SINK_TABLE_ENTRIES * sizeof(tsGP_ZgpsSinkTable));
            sPersistedData.pasZgpsSinkTable = psGpCustomDataStructure->asZgpsSinkTable;
            psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_PERSIST_ATTRIBUTE_DATA;
            sPersistedData.eGPChangeCause = eGPChangeCause;
            psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.uMessage.psPersistedData = &sPersistedData;
            psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);
            // release mutex
			#ifndef COOPERATIVE
				eZCL_ReleaseMutex(psEndPointDefinition);
			#endif

			return;
        }
#endif
#ifdef GP_PROXY_DEVICE
           if( eGP_FindGpCluster(i,
                              FALSE,
                              &psEndPointDefinition,
                              &psClusterInstance,
                              &psGpCustomDataStructure) == E_ZCL_SUCCESS)
           {


        	   // client attributes set
        	   sPersistedData.psAttributes = ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr));
          /*  sPersistedData.psAttributes->u8ZgppMaxProxyTableEntries = ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->u8ZgppMaxProxyTableEntries;
            sPersistedData.psAttributes->sProxyTable = ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->sProxyTable;

#ifdef  CLD_GP_ATTR_ZGPP_NOTIFICATION_RETRY_NUMBER
            sPersistedData.psAttributes->u8ZgppNotificationRetryNumber = ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->u8ZgppNotificationRetryNumber;
#endif

#ifdef  CLD_GP_ATTR_ZGPP_NOTIFICATION_RETRY_TIMER
            sPersistedData.psAttributes->u8ZgppNotificationRetryTimer = ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->u8ZgppNotificationRetryTimer;
#endif

#ifdef  CLD_GP_ATTR_ZGPP_MAX_SEARCH_COUNTER
            sPersistedData.psAttributes->u8ZgppMaxSearchCounter = ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->u8ZgppMaxSearchCounter;
#endif

#ifdef  CLD_GP_ATTR_ZGPP_BLOCKED_GPD_ID
            sPersistedData.psAttributes->sZgppBlockedGpdID = ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->sZgppBlockedGpdID;
#endif
            sPersistedData.psAttributes->b24ZgppFunctionality = ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->b24ZgppFunctionality;
            sPersistedData.psAttributes->b24ZgppActiveFunctionality = ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->b24ZgppActiveFunctionality;

#ifdef  CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY_TYPE
            sPersistedData.psAttributes->b8ZgpSharedSecKeyType = ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->b8ZgpSharedSecKeyType;
#endif

#ifdef  CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY
            sPersistedData.psAttributes->sZgpSharedSecKey = ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->sZgpSharedSecKey;
#endif

#ifdef  CLD_GP_ATTR_ZGP_LINK_KEY
            sPersistedData.psAttributes->sZgpLinkKey = ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->sZgpLinkKey;
#endif */
        	  //  memcpy(sPersistedData.pasZgppProxyTable, psGpCustomDataStructure->asZgppProxyTable, GP_NUMBER_OF_PROXY_TABLE_ENTRIES * sizeof(tsGP_ZgppProxyTable));
        	 sPersistedData.pasZgppProxyTable = psGpCustomDataStructure->asZgppProxyTable;
        	 psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_PERSIST_ATTRIBUTE_DATA;
			sPersistedData.eGPChangeCause = eGPChangeCause;
			psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.uMessage.psPersistedData = &sPersistedData;
			psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);
			// release mutex
			#ifndef COOPERATIVE
				eZCL_ReleaseMutex(psEndPointDefinition);
			#endif

			return;
           }
#endif


    }

#endif
}


/****************************************************************************
 **
 ** NAME:       vGP_RestorePersistedData(tsGP_PersistedData *psPersistedData, bool_t bSetToDefault)
 **
 ** DESCRIPTION:
 ** Restore persisted attribute data during initialisation
 **
 ** PARAMETERS:                    Name                           Usage
 ** tsGP_PersistedData        *psPersistedData              persisted data pointer passed by application
 ** teGP_ResetToDefaultConfig  eSetToDefault                 if application want to set attribute data to default value then set TRUE
 ** RETURN:
 ** None
 ****************************************************************************/
PUBLIC void vGP_RestorePersistedData(tsGP_PersistedData 					*psPersistedData,
									teGP_ResetToDefaultConfig                 eSetToDefault)
{
    tsZCL_EndPointDefinition        *psEndPointDefinition;
    tsZCL_ClusterInstance           *psClusterInstance;
    tsGP_GreenPowerCustomData       *psGpCustomDataStructure;
    uint8                           u8NumberOfendpoints, i;

    u8NumberOfendpoints = u8ZCL_GetNumberOfEndpointsRegistered();

    // find GP clusters on each EP - if any
    for(i=0; i<u8NumberOfendpoints; i++)
    {
       /* As local GP end point is not known find GP end point */
        if(eGP_FindGpCluster(u8ZCL_GetEPIdFromIndex(i),
                             TRUE,
                             &psEndPointDefinition,
                             &psClusterInstance,
                             &psGpCustomDataStructure) == E_ZCL_SUCCESS)
        {
            // get EP mutex
            #ifndef COOPERATIVE
                eZCL_GetMutex(psEndPointDefinition);
            #endif


#ifdef GP_COMBO_MIN_DEVICE

            // server attributes set
			if(eSetToDefault & E_GP_DEFAULT_SINK_TABLE_VALUE)
            {
				
				((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->sSinkTable.pu8Data = (uint8*)psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asSinkTable;
            }
			else
			{
				uint8 j;
			

				for(j = 0; j< GP_NUMBER_OF_SINK_TABLE_ENTRIES; j++)
				{   /* check if sink table entry is not empty */
					if(psPersistedData->pasZgpsSinkTable[j].eGreenPowerSinkTablePriority != 0)
					{
						psPersistedData->pasZgpsSinkTable[j].u32ZgpdSecFrameCounter = 0;

					}

				}
			
			}
            if(eSetToDefault & E_GP_DEFAULT_ATTRIBUTE_VALUE)
            {    // server attributes set default value
            
                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->b8ZgpsCommunicationMode = E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_DGROUP_ID;
                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->b8ZgpsCommissioningExitMode = GP_CMSNG_EXIT_MODE_ON_PAIRING_SUCCESS_MASK;

#ifdef  CLD_GP_ATTR_ZGPS_COMMISSIONING_WINDOW
                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->u16ZgpsCommissioningWindow = GP_COMMISSION_WINDOW_DURATION;
                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->b8ZgpsCommissioningExitMode |= GP_CMSNG_EXIT_MODE_ON_WINDOW_EXPIRE_MASK;
#endif

                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->b8ZgpsSecLevel = E_GP_ONE_LSB_FC_SHORT_MIC;
                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->b24ZgpsActiveFeatures = GP_ZGP_ACTIVE_FEATURES_ATTR_DEFAULT_VALUE;
                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->b24ZgpsFeatures = GP_FEATURE_ZGP_FEATURE |
                                                                                                        GP_FEATURE_DIRECT_COMM |
                                                                                                        GP_FEATURE_DERIVED_GC_COMM |
                                                                                                        GP_FEATURE_COMMISSION_GC_COMM |
                                                                                                        GP_FEATURE_SINGLE_HOP_CMSNG |
                                                                                                        GP_FEATURE_MULTI_HOP_CMSNG |
                                                                                                        GP_FEATURE_ZGPD_SEC_LVL_0B00 |
                                                                                                        GP_FEATURE_ZGPD_SEC_LVL_0B11 |
                                                                                                        GP_FEATURE_SINK_TABLE_BASED_GC_FORWARDING |
                                                                                                        GP_FEATURE_TRANSLATION_TABLE;
#ifdef GP_IEEE_ADDR_SUPPORT
                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->b24ZgpsFeatures |= GP_FEATURE_ZGPD_IEEE_ADDR;
#endif
#ifdef  CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY_TYPE
                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->b8ZgpSharedSecKeyType = E_GP_NWK_KEY_DERIVED_ZGPD_GROUP_KEY;
#endif

#ifdef CLD_GP_ATTR_ZGP_LINK_KEY
                memcpy(((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->sZgpLinkKey.au8Key,"ZigBeeAlliance09",16);
#endif

            }
            else
            {
/*

                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->b8ZgpsCommunicationMode = psPersistedData->psAttributes->b8ZgpsCommunicationMode;
                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->b8ZgpsCommissioningExitMode = psPersistedData->psAttributes->b8ZgpsCommissioningExitMode;

#ifdef  CLD_GP_ATTR_ZGPS_COMMISSIONING_WINDOW
                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->u16ZgpsCommissioningWindow = psPersistedData->psAttributes->u16ZgpsCommissioningWindow;
#endif

                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->b8ZgpsSecLevel = psPersistedData->psAttributes->b8ZgpsSecLevel;
                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->b24ZgpsFeatures = psPersistedData->psAttributes->b24ZgpsFeatures;
                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->b24ZgpsActiveFeatures = psPersistedData->psAttributes->b24ZgpsActiveFeatures;

#ifdef  CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY_TYPE
                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->b8ZgpSharedSecKeyType = psPersistedData->psAttributes->b8ZgpSharedSecKeyType;
#endif

#ifdef  CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY
               ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->sZgpSharedSecKey = psPersistedData->psAttributes->sZgpSharedSecKey;
#endif

#ifdef  CLD_GP_ATTR_ZGP_LINK_KEY
               ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->sZgpLinkKey = psPersistedData->psAttributes->sZgpLinkKey;
#endif
*/

            }
            ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->u8ZgpsMaxSinkTableEntries = GP_NUMBER_OF_SINK_TABLE_ENTRIES;
            ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->sSinkTable.u16MaxLength = GP_MAX_SINK_TABLE_LENGTH;

#endif


            // client attributes set
            eGP_FindGpCluster(i,
                              FALSE,
                              &psEndPointDefinition,
                              &psClusterInstance,
                              &psGpCustomDataStructure);

#ifdef GP_PROXY_DEVICE
            if(eSetToDefault & E_GP_DEFAULT_PROXY_TABLE_VALUE)
            {
                // client attributes set default values
                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->u8ZgppMaxProxyTableEntries = GP_NUMBER_OF_PROXY_TABLE_ENTRIES;
                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->sProxyTable.u16MaxLength = GP_MAX_PROXY_TABLE_LENGTH;
                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->sProxyTable.pu8Data = (uint8*)psGpCustomDataStructure->asZgppProxyTable;
#ifdef  CLD_GP_ATTR_ZGPP_NOTIFICATION_RETRY_NUMBER
                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->u8ZgppNotificationRetryNumber = 2;
#endif

#ifdef  CLD_GP_ATTR_ZGPP_NOTIFICATION_RETRY_TIMER
                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->u8ZgppNotificationRetryTimer = 0x64;
#endif

#ifdef  CLD_GP_ATTR_ZGPP_MAX_SEARCH_COUNTER
                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->u8ZgppMaxSearchCounter = 0x0A;
#endif

#ifdef  CLD_GP_ATTR_ZGPP_BLOCKED_GPD_ID
                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->sZgppBlockedGpdID.u16Length = 0;
#endif
                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->b24ZgppFunctionality = GP_FEATURE_ZGP_FEATURE |
                                                                                                             GP_FEATURE_DIRECT_COMM |
                                                                                                             GP_FEATURE_DERIVED_GC_COMM |
                                                                                                             GP_FEATURE_COMMISSION_GC_COMM |
                                                                                                             GP_FEATURE_MULTI_HOP_CMSNG |
                                                                                                             GP_FEATURE_ZGPD_SEC_LVL_0B00 |
                                                                                                             GP_FEATURE_ZGPD_SEC_LVL_0B11;
#ifdef GP_IEEE_ADDR_SUPPORT
                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->b24ZgppFunctionality |= GP_FEATURE_ZGPD_IEEE_ADDR;
#endif
                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->b24ZgppActiveFunctionality = GP_ZGP_ACTIVE_FEATURES_ATTR_DEFAULT_VALUE;
#ifdef  CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY_TYPE
                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->b8ZgpSharedSecKeyType = E_GP_NWK_KEY_DERIVED_ZGPD_GROUP_KEY;
#endif

#ifdef CLD_GP_ATTR_ZGP_LINK_KEY
                memcpy(((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->sZgpLinkKey.au8Key,(uint8*)"ZigBeeAlliance09",16);
#endif

            }
            else
            {
           /*     ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->u8ZgppMaxProxyTableEntries = psPersistedData->psAttributes->u8ZgppMaxProxyTableEntries;
                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->sProxyTable = psPersistedData->psAttributes->sProxyTable;

#ifdef  CLD_GP_ATTR_ZGPP_NOTIFICATION_RETRY_NUMBER
                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->u8ZgppNotificationRetryNumber = psPersistedData->psAttributes->u8ZgppNotificationRetryNumber;
#endif

#ifdef  CLD_GP_ATTR_ZGPP_NOTIFICATION_RETRY_TIMER
                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->u8ZgppNotificationRetryTimer = psPersistedData->psAttributes->u8ZgppNotificationRetryTimer;
#endif

#ifdef  CLD_GP_ATTR_ZGPP_MAX_SEARCH_COUNTER
                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->u8ZgppMaxSearchCounter = psPersistedData->psAttributes->u8ZgppMaxSearchCounter;
#endif

#ifdef  CLD_GP_ATTR_ZGPP_BLOCKED_GPD_ID
                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->sZgppBlockedGpdID = psPersistedData->psAttributes->sZgppBlockedGpdID;
#endif
                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->b24ZgppFunctionality = psPersistedData->psAttributes->b24ZgppFunctionality;
                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->b24ZgppActiveFunctionality = psPersistedData->psAttributes->b24ZgppActiveFunctionality;

#ifdef  CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY_TYPE
                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->b8ZgpSharedSecKeyType = psPersistedData->psAttributes->b8ZgpSharedSecKeyType;
#endif

#ifdef  CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY
                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->sZgpSharedSecKey = psPersistedData->psAttributes->sZgpSharedSecKey;
#endif

#ifdef  CLD_GP_ATTR_ZGP_LINK_KEY
                ((tsCLD_GreenPower *)(psClusterInstance->pvEndPointSharedStructPtr))->sZgpLinkKey = psPersistedData->psAttributes->sZgpLinkKey;
#endif
                memcpy(psGpCustomDataStructure->asZgppProxyTable, psPersistedData->pasZgppProxyTable,  GP_NUMBER_OF_PROXY_TABLE_ENTRIES * sizeof(tsGP_ZgppProxyTable));*/
            }
#endif
            // release mutex
            #ifndef COOPERATIVE
                eZCL_ReleaseMutex(psEndPointDefinition);
            #endif

            return;
        }
    }
}

/****************************************************************************
 **
 ** NAME:       bGP_AddDeviceSecurity
 **
 ** DESCRIPTION:
 ** Restore persisted attribute data during initialisation
 **
 ** PARAMETERS:                    Name                           Usage
 ** tsGP_PersistedData        *psPersistedData              persisted data pointer passed by application
 ** bool_t                    bSetToDefault                 if application want to set attribute data to default value then set TRUE
 ** RETURN:
 ** None
 ****************************************************************************/
PUBLIC bool_t bGP_AddDeviceSecurity(ZPS_tsZgpSecReq *psSec)
{
    tsZCL_EndPointDefinition        *psEndPointDefinition;
    tsZCL_ClusterInstance           *psClusterInstance;
    tsGP_GreenPowerCustomData       *psGpCustomDataStructure;
    uint8                           u8NumberOfendpoints, i;
#ifdef GP_PROXY_DEVICE
    uint8 u8SecLevel;
#endif
    bool                            bIsGpClusterFound = FALSE;
    bool                            bIsServer;
    teZCL_Status                    eStatus;
    teGP_GreenPowerSecKeyType       eZgpSecKeyType;
    ZPS_tsZgpGpstEntry              sZgpGpstEntry;
    AESSW_Block_u                   uSecurityKey;
#ifdef CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY
    AESSW_Block_u                   uInKey;
#endif
    tuGP_ZgpdDeviceAddr             uZgpdDeviceAddr;
    bool                            bIsTableEntryPresent = FALSE;
    tsZCL_Key                       sZgpdKey;
#ifdef GP_COMBO_MIN_DEVICE
    tsGP_ZgpsSinkTable              sZgpsSinkTable;
    uint8                           b8ZgpsCommModeAttr;
    bIsServer = TRUE;
#else
    tsGP_ZgppProxyTable             sZgppProxyTable;
    bIsServer = FALSE;
#endif

    u8NumberOfendpoints = u8ZCL_GetNumberOfEndpointsRegistered();

    // find GP clusters on each EP - if any
    for(i=0; i<u8NumberOfendpoints; i++)
    {
       /* As local GP end point is not known find GP end point */
        if((eStatus = eGP_FindGpCluster(
                                u8ZCL_GetEPIdFromIndex(i),
                                bIsServer,
                                &psEndPointDefinition,
                                &psClusterInstance,
                                &psGpCustomDataStructure)) == E_ZCL_SUCCESS)
        {
            bIsGpClusterFound = TRUE;
            break;
        }
    }

    if(!bIsGpClusterFound)
    {
        return FALSE;
    }

    uZgpdDeviceAddr.u32ZgpdSrcId = psSec->uGpId.u32SrcId;
#ifdef GP_IEEE_ADDR_SUPPORT
    uZgpdDeviceAddr.u64ZgpdIEEEAddr = psSec->uGpId.u64Address;
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


        bIsTableEntryPresent = bGP_IsSinkTableEntryPresent(
                    psEndPointDefinition->u8EndPointNumber,
                    psSec->u8ApplicationId,
                    &uZgpdDeviceAddr,
                    E_GP_SINK_TABLE_GET_ENTRY,
                    &sZgpsSinkTable,
                    (teGP_GreenPowerCommunicationMode)b8ZgpsCommModeAttr);

        if(bIsTableEntryPresent&&(sZgpsSinkTable.b16Options & GP_SINK_TABLE_SECURITY_USE_MASK))
        {
           /* u8SecLevel = sZgpsSinkTable.b8SecOptions & GP_SECURITY_LEVEL_MASK;*/
//            if(u8SecLevel != psSec->u8SecurityLevel)
//            {
//                return FALSE;
//            }
            eZgpSecKeyType = sZgpsSinkTable.b8SecOptions >> 2;
            sZgpdKey = sZgpsSinkTable.sZgpdKey;
        }
        else
        {
            bIsTableEntryPresent = FALSE;
        }

    }
#endif

#ifdef GP_PROXY_DEVICE
    /* Based on device type, check freshness of packet */
    if(psGpCustomDataStructure->eGreenPowerDeviceType == E_GP_ZGP_PROXY_DEVICE)
    {
        /* clear sink table */
        memset(&sZgppProxyTable, 0, sizeof(tsGP_ZgppProxyTable));

        bIsTableEntryPresent = bGP_IsProxyTableEntryPresent(
                    psEndPointDefinition->u8EndPointNumber,
                    psSec->u8ApplicationId,
                    &uZgpdDeviceAddr,
                    E_GP_PROXY_TABLE_GET_ENTRY,
                    &sZgppProxyTable);

        if(bIsTableEntryPresent&&(sZgppProxyTable.b16Options & GP_PROXY_TABLE_SECURITY_USE_MASK))
        {
            u8SecLevel = sZgppProxyTable.b8SecOptions & GP_SECURITY_LEVEL_MASK;
            if(u8SecLevel != psSec->u8SecurityLevel)
            {
                return FALSE;
            }
            eZgpSecKeyType = sZgppProxyTable.b8SecOptions >> 2;
            sZgpdKey = sZgppProxyTable.sZgpdKey;
        }
        else
        {
            bIsTableEntryPresent = FALSE;
        }
    }
#endif

    /* populate key */
    if(!bIsTableEntryPresent)
    {
#ifdef CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY_TYPE
        // get EP mutex
        #ifndef COOPERATIVE
            eZCL_GetMutex(psEndPointDefinition);
        #endif

        /* Get Green Power communication Mode attribute value */
        eZCL_ReadLocalAttributeValue(
                  psEndPointDefinition->u8EndPointNumber,
                  GREENPOWER_CLUSTER_ID,
                  bIsServer,
                  FALSE,
                  FALSE,
                  E_CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY_TYPE,
                  (uint8*)&eZgpSecKeyType);

        // release mutex
        #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


#else
       // fill in callback event structure
        eZCL_SetCustomCallBackEvent(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent,
                                    0, 0, psEndPointDefinition->u8EndPointNumber);
        /* Set Event Type */
        psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_SHARED_SECURITY_KEY_TYPE_IS_NOT_ENABLED;
        /* Give a call back event to app */
        psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);
        return FALSE;
#endif
    }
    //DBG_vPrintf(TRACE_GP_DEBUG, "eZgpSecKeyType %d\n", eZgpSecKeyType);

    if((eZgpSecKeyType == E_GP_ZGPD_GROUP_KEY)||(eZgpSecKeyType == E_GP_DERIVED_INDIVIDUAL_ZGPD_KEY))
    {
#ifdef CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY
        // get EP mutex
        #ifndef COOPERATIVE
            eZCL_GetMutex(psEndPointDefinition);
        #endif

        /* Get Green Power communication Mode attribute value */
        eZCL_ReadLocalAttributeValue(
                  psEndPointDefinition->u8EndPointNumber,
                  GREENPOWER_CLUSTER_ID,
                  bIsServer,
                  FALSE,
                  FALSE,
                  E_CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY,
                  (uint8*)&uSecurityKey);

        // release mutex
        #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


        if(eZgpSecKeyType == E_GP_DERIVED_INDIVIDUAL_ZGPD_KEY)
        {
            uInKey = uSecurityKey;

            /* Get the derived individual key */
            ZPS_vZgpTransformKey(ZPS_E_ZGP_DERIVED_INDIVIDUAL_KEY,
                                psSec->u8ApplicationId,
                                psSec->uGpId.u32SrcId,
                                psSec->uGpId.u64Address,
                                &uInKey,
                                &uSecurityKey);
        }
#else
        // fill in callback event structure
        eZCL_SetCustomCallBackEvent(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent,
                                      0, 0, psEndPointDefinition->u8EndPointNumber);
         /* Set Event Type */
        psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_SHARED_SECURITY_KEY_IS_NOT_ENABLED;
         /* Give a call back event to app */
        psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);
        return FALSE;
#endif
    }
    else if(eZgpSecKeyType == E_GP_ZIGBEE_NWK_KEY)
    { /* Get the current network key */

        ZPS_vZgpTransformKey(ZPS_E_ZGP_ZIGBEE_NWK_KEY,
                             psSec->u8ApplicationId,
                             psSec->uGpId.u32SrcId,
                             psSec->uGpId.u64Address,
                             NULL,
                             &uSecurityKey);
    }
    else if(eZgpSecKeyType == E_GP_NWK_KEY_DERIVED_ZGPD_GROUP_KEY)
    { /* Get the current network key */

//        ZPS_vZgpTransformKey(ZPS_E_ZGP_ZIGBEE_NWK_KEY,
//                             psSec->u8ApplicationId,
//                             psSec->uGpId.u32SrcId,
//                             psSec->uGpId.u64Address,
//                             NULL,
//                             &uInKey);
        /* Get the network key - derived GPD group key */
        ZPS_vZgpTransformKey(ZPS_E_ZGP_NWK_KEY_DERIVED_GRP_KEY,
                             psSec->u8ApplicationId,
                             psSec->uGpId.u32SrcId,
                             psSec->uGpId.u64Address,
                             NULL,
                             &uSecurityKey);
    }
    else if((eZgpSecKeyType == E_GP_OUT_OF_THE_BOX_ZGPD_KEY)&&bIsTableEntryPresent)
    {
        memcpy(uSecurityKey.au8, sZgpdKey.au8Key, E_ZCL_KEY_128_SIZE);
    }
    else
    {
        return FALSE;
    }

    sZgpGpstEntry.uSecurityKey = uSecurityKey;
    sZgpGpstEntry.uGpId = psSec->uGpId;
    sZgpGpstEntry.u32Counter = psSec->u32FrameCounter;
    sZgpGpstEntry.u8SecurityLevel = psSec->u8SecurityLevel;
    sZgpGpstEntry.u8KeyType = (uint8)eZgpSecKeyType;
    sZgpGpstEntry.bValid = TRUE;

    return (ZPS_sZgpAddDeviceSecurity((uint32)psSec->u8ApplicationId, &sZgpGpstEntry));


}
/****************************************************************************
 **
 ** NAME:       bGP_UpdateSecurityFrameCounter
 **
 ** DESCRIPTION:
 ** update security frame counter for security level 1 from sink/proxy table
 **
 ** PARAMETERS:                    Name                           Usage
 **
 **
 ** RETURN:
 ** None
 ****************************************************************************/

PRIVATE bool_t bGP_UpdateSecurityFrameCounter(ZPS_tsZgpSecReq *psSec, uint32 *pu32FrameCounter)
{
    tsZCL_EndPointDefinition        *psEndPointDefinition;
    tsZCL_ClusterInstance           *psClusterInstance;
    tsGP_GreenPowerCustomData       *psGpCustomDataStructure;
    uint8                           u8NumberOfendpoints, i;
    bool                            bIsGpClusterFound = FALSE;
    bool                            bIsServer;
    teZCL_Status                    eStatus;
    tuGP_ZgpdDeviceAddr             uZgpdDeviceAddr;
    bool                            bIsTableEntryPresent = FALSE;

#ifdef GP_COMBO_MIN_DEVICE
    tsGP_ZgpsSinkTable              sZgpsSinkTable;
    uint8                           b8ZgpsCommModeAttr;
    bIsServer = TRUE;
#else
    tsGP_ZgppProxyTable             sZgppProxyTable;
    bIsServer = FALSE;
#endif

    u8NumberOfendpoints = u8ZCL_GetNumberOfEndpointsRegistered();

    // find GP clusters on each EP - if any
    for(i=0; i<u8NumberOfendpoints; i++)
    {
       /* As local GP end point is not known find GP end point */
        if((eStatus = eGP_FindGpCluster(
                                u8ZCL_GetEPIdFromIndex(i),
                                bIsServer,
                                &psEndPointDefinition,
                                &psClusterInstance,
                                &psGpCustomDataStructure)) == E_ZCL_SUCCESS)
        {
            bIsGpClusterFound = TRUE;
            break;
        }
    }

    if(!bIsGpClusterFound)
    {
        return FALSE;
    }

    uZgpdDeviceAddr.u32ZgpdSrcId = psSec->uGpId.u32SrcId;
#ifdef GP_IEEE_ADDR_SUPPORT
    uZgpdDeviceAddr.u64ZgpdIEEEAddr = psSec->uGpId.u64Address;
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


        bIsTableEntryPresent = bGP_IsSinkTableEntryPresent(
                    psEndPointDefinition->u8EndPointNumber,
                    psSec->u8ApplicationId,
                    &uZgpdDeviceAddr,
                    E_GP_SINK_TABLE_GET_ENTRY,
                    &sZgpsSinkTable,
                    (teGP_GreenPowerCommunicationMode)b8ZgpsCommModeAttr);

        if(bIsTableEntryPresent&&(sZgpsSinkTable.b16Options & GP_SINK_TABLE_SECURITY_USE_MASK))
        {
            uint8 u8SequenceNumber;
            u8SequenceNumber = (uint8)sZgpsSinkTable.u32ZgpdSecFrameCounter;
            if((uint8)psSec->u32FrameCounter >= u8SequenceNumber)
            {
                *pu32FrameCounter = ((uint8)psSec->u32FrameCounter | (sZgpsSinkTable.u32ZgpdSecFrameCounter & 0xFFFFFF00));
            }
            else
            {
                /* increment upper 3 bytes by 1 */
                uint32 u32SecCounter = (sZgpsSinkTable.u32ZgpdSecFrameCounter) + 0x100;
                *pu32FrameCounter = ((uint8)psSec->u32FrameCounter | (u32SecCounter & 0xFFFFFF00));
            }
        }
        else
        {
            *pu32FrameCounter = psSec->u32FrameCounter;
        }

    }
#endif

#ifdef GP_PROXY_DEVICE
    /* Based on device type, check freshness of packet */
    if(psGpCustomDataStructure->eGreenPowerDeviceType == E_GP_ZGP_PROXY_DEVICE)
    {
        /* clear sink table */
        memset(&sZgppProxyTable, 0, sizeof(tsGP_ZgppProxyTable));

        bIsTableEntryPresent = bGP_IsProxyTableEntryPresent(
                    psEndPointDefinition->u8EndPointNumber,
                    psSec->u8ApplicationId,
                    &uZgpdDeviceAddr,
                    E_GP_PROXY_TABLE_GET_ENTRY,
                    &sZgppProxyTable);

        if(bIsTableEntryPresent&&(sZgppProxyTable.b16Options & GP_PROXY_TABLE_SECURITY_USE_MASK))
        {
            uint8 u8SequenceNumber;
            u8SequenceNumber = (uint8)sZgppProxyTable.u32ZgpdSecFrameCounter;
            if((uint8)psSec->u32FrameCounter >= u8SequenceNumber)
            {
                *pu32FrameCounter = ((uint8)psSec->u32FrameCounter | (sZgppProxyTable.u32ZgpdSecFrameCounter & 0xFFFFFF00));
            }
            else
            {
                /* increment upper 3 bytes by 1 */
                uint32 u32SecCounter = (sZgppProxyTable.u32ZgpdSecFrameCounter) + 0x100;
                *pu32FrameCounter = ((uint8)psSec->u32FrameCounter | (u32SecCounter & 0xFFFFFF00));
            }
        }
        else
        {
            *pu32FrameCounter = psSec->u32FrameCounter;
        }
    }
#endif


    return (TRUE);


}
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

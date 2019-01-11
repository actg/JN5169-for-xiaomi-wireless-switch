/*****************************************************************************
 *
 * MODULE:             Commissioning Cluster
 *
 * COMPONENT:          Commissioning.c
 *
 * AUTHOR:
 *
 * DESCRIPTION:        Commissioning cluster definition
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/SE1v5/ZCL/Clusters/General/Source/Time.c $
 *
 * $Revision: 39026 $
 *
 * $LastChangedBy: nxp39458 $
 *
 * $LastChangedDate: 2012-02-23 18:15:22 +0530 (Thu, 23 Feb 2012) $
 *
 * $Id: Time.c 39026 2012-02-23 12:45:22Z nxp39458 $
 *
 *****************************************************************************
 *
 * This software is owned by Jennic and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on Jennic products. You, and any third parties must reproduce
 * the copyright and warranty notice and any other legend of ownership on each
 * copy or partial copy of the software.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS". JENNIC MAKES NO WARRANTIES, WHETHER
 * EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE,
 * ACCURACY OR LACK OF NEGLIGENCE. JENNIC SHALL NOT, IN ANY CIRCUMSTANCES,
 * BE LIABLE FOR ANY DAMAGES, INCLUDING, BUT NOT LIMITED TO, SPECIAL,
 * INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON WHATSOEVER.
 *
 * Copyright Jennic Ltd. 2009 All rights reserved
 *
 ****************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#include <jendefs.h>
#include "zcl.h"
#include "Commissioning.h"
#include "zcl_options.h"

#ifdef CLD_COMMISSIONING

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
#ifdef COMMISSIONING_SERVER
    const tsZCL_AttributeDefinition asCLD_CommissioningClusterAttributeDefinitions[] = {
            /* Commissioning attribute set (3.15.2.2) */
    #ifdef     CLD_COMM_ATTR_SHORT_ADDRESS
        {E_CLD_CMSNG_ATTR_ID_SHORT_ADDRESS,        (E_ZCL_AF_RD|E_ZCL_AF_WR),  E_ZCL_UINT16,        (uint32)(&((tsCLD_Commissioning*)(0))->u16ShortAddress),0},
    #endif

    #ifdef     CLD_COMM_ATTR_EXTENED_PAN_ID
        {E_CLD_CMSNG_ATTR_ID_EXT_PANID,            (E_ZCL_AF_RD|E_ZCL_AF_WR),  E_ZCL_IEEE_ADDR,     (uint32)(&((tsCLD_Commissioning*)(0))->u64ExtPanId),0},
    #endif

    #ifdef     CLD_COMM_ATTR_PAN_ID
        {E_CLD_CMSNG_ATTR_ID_PANID,                (E_ZCL_AF_RD|E_ZCL_AF_WR),  E_ZCL_UINT16,        (uint32)(&((tsCLD_Commissioning*)(0))->u16PANId),0},
    #endif

    #ifdef     CLD_COMM_ATTR_CHANNEL_MASK
        {E_CLD_CMSNG_ATTR_ID_CHANNEL_MASK,         (E_ZCL_AF_RD|E_ZCL_AF_WR),  E_ZCL_BMAP32,        (uint32)(&((tsCLD_Commissioning*)(0))->u32ChannelMask),0},
    #endif

    #ifdef     CLD_COMM_ATTR_PROTOCOL_VERSION
        {E_CLD_CMSNG_ATTR_ID_PROTOCOL_VERSION,     (E_ZCL_AF_RD|E_ZCL_AF_WR),  E_ZCL_UINT8,        (uint32)(&((tsCLD_Commissioning*)(0))->u8ProtocolVersion),0},
    #endif

    #ifdef     CLD_COMM_ATTR_STACK_PROFILE
        {E_CLD_CMSNG_ATTR_ID_STACK_PROFILE,        (E_ZCL_AF_RD|E_ZCL_AF_WR),  E_ZCL_UINT8,        (uint32)(&((tsCLD_Commissioning*)(0))->u8StackProfile),0},
    #endif

    #ifdef     CLD_COMM_ATTR_START_UP_CONTROL
        {E_CLD_CMSNG_ATTR_ID_STARTUP_CONTROl,      (E_ZCL_AF_RD|E_ZCL_AF_WR),  E_ZCL_ENUM8,         (uint32)(&((tsCLD_Commissioning*)(0))->e8StartUpControl),0},
    #endif

    #ifdef     CLD_COMM_ATTR_TC_ADDR
        {E_CLD_CMSNG_ATTR_ID_TC_ADDR,              (E_ZCL_AF_RD|E_ZCL_AF_WR),  E_ZCL_IEEE_ADDR,     (uint32)(&((tsCLD_Commissioning*)(0))->u64TcAddr),0},
    #endif

    #ifdef     CLD_COMM_ATTR_TC_MASTER_KEY
        {E_CLD_CMSNG_ATTR_ID_TC_MASTER_KEY,        (E_ZCL_AF_RD|E_ZCL_AF_WR),  E_ZCL_KEY_128,       (uint32)(&((tsCLD_Commissioning*)(0))->sTcMasterKey),0},
    #endif

    #ifdef     CLD_COMM_ATTR_NWK_KEY
        {E_CLD_CMSNG_ATTR_ID_NETWORK_KEY,          (E_ZCL_AF_RD|E_ZCL_AF_WR),  E_ZCL_KEY_128,       (uint32)(&((tsCLD_Commissioning*)(0))->sNwkKey),0},
    #endif


    #ifdef     CLD_COMM_ATTR_USE_INSECURE_JOIN
        {E_CLD_CMSNG_ATTR_ID_USE_INSECURE_JOIN,    (E_ZCL_AF_RD|E_ZCL_AF_WR),  E_ZCL_BOOL,          (uint32)(&((tsCLD_Commissioning*)(0))->bUseInsecureJoin),0},
    #endif

    #ifdef     CLD_COMM_ATTR_PRE_CONFIG_LINK_KEY
        {E_CLD_CMSNG_ATTR_ID_PRECONFIG_LINK_KEY,   (E_ZCL_AF_RD|E_ZCL_AF_WR),  E_ZCL_KEY_128,       (uint32)(&((tsCLD_Commissioning*)(0))->sPreConfigLinkKey),0},
    #endif


    #ifdef     CLD_COMM_ATTR_NWK_KEY_SEQ_NO
        {E_CLD_CMSNG_ATTR_ID_NWK_KEY_SEQ_NO,       (E_ZCL_AF_RD|E_ZCL_AF_WR),  E_ZCL_UINT8,         (uint32)(&((tsCLD_Commissioning*)(0))->u8NwkKeySeqNo),0},
    #endif

    #ifdef     CLD_COMM_ATTR_NWK_KEY_TYPE
        {E_CLD_CMSNG_ATTR_ID_NWK_KEY_TYPE,         (E_ZCL_AF_RD|E_ZCL_AF_WR),  E_ZCL_ENUM8,         (uint32)(&((tsCLD_Commissioning*)(0))->e8NwkKeyType),0},
    #endif

    #ifdef     CLD_COMM_ATTR_NWK_MANAGER_ADDR
        {E_CLD_CMSNG_ATTR_ID_NWK_MANAGER_ADDR,     (E_ZCL_AF_RD|E_ZCL_AF_WR),  E_ZCL_UINT16,        (uint32)(&((tsCLD_Commissioning*)(0))->u16NwkManagerAddr),0},
    #endif
        /* Join Parameters attribute set (3.15.2.2.2)*/
    #ifdef     CLD_COMM_ATTR_SCAN_ATTEMPTS
        {E_CLD_CMSNG_ATTR_ID_SCAN_ATTEMPTS,        (E_ZCL_AF_RD|E_ZCL_AF_WR),  E_ZCL_UINT8,         (uint32)(&((tsCLD_Commissioning*)(0))->u8ScanAttempts),0},
    #endif

    #ifdef     CLD_COMM_ATTR_TIME_BW_SCANS
        {E_CLD_CMSNG_ATTR_ID_TIME_BW_SCANS,        (E_ZCL_AF_RD|E_ZCL_AF_WR),  E_ZCL_UINT16,        (uint32)(&((tsCLD_Commissioning*)(0))->u16TimeBwScans),0},
    #endif

    #ifdef     CLD_COMM_ATTR_REJOIN_INTERVAL
        {E_CLD_CMSNG_ATTR_ID_REJOIN_INTERVAL,      (E_ZCL_AF_RD|E_ZCL_AF_WR),  E_ZCL_UINT16,        (uint32)(&((tsCLD_Commissioning*)(0))->u16RejoinInterval),0},
    #endif

    #ifdef     CLD_COMM_ATTR_MAX_REJOIN_INTERVAL
        {E_CLD_CMSNG_ATTR_ID_MAX_REJOIN_INTERVAL,   (E_ZCL_AF_RD|E_ZCL_AF_WR),  E_ZCL_UINT16,       (uint32)(&((tsCLD_Commissioning*)(0))->u16MaxRejoinInterval),0},
    #endif
        /* End Device Parameters attribute set (3.15.2.2.3)*/
    #ifdef     CLD_COMM_ATTR_INDIRECT_POLL_RATE
        {E_CLD_CMSNG_ATTR_ID_INDIRECT_POLL_RATE,    (E_ZCL_AF_RD|E_ZCL_AF_WR),  E_ZCL_UINT16,       (uint32)(&((tsCLD_Commissioning*)(0))->u16IndirectPollRate),0},
    #endif

    #ifdef     CLD_COMM_ATTR_PARENT_RETRY_THRSHLD
        {E_CLD_CMSNG_ATTR_ID_PARENT_RETRY_THRSHOLD,  (E_ZCL_AF_RD|E_ZCL_AF_WR),  E_ZCL_UINT8,       (uint32)(&((tsCLD_Commissioning*)(0))->u8ParentRetryThreshold),0},
    #endif
        /* Concentrator Parameters attribute set (3.15.2.2.4)*/
    #ifdef     CLD_COMM_ATTR_CONCENTRATOR_FLAG
        {E_CLD_CMSNG_ATTR_ID_CONCENTRATOR_FLAG,     (E_ZCL_AF_RD|E_ZCL_AF_WR),  E_ZCL_BOOL,         (uint32)(&((tsCLD_Commissioning*)(0))->bConcentratorFlag),0},
    #endif

    #ifdef     CLD_COMM_ATTR_CONCENTRATOR_RADIUS
        {E_CLD_CMSNG_ATTR_ID_CONCENTRATOR_RADIUS,   (E_ZCL_AF_RD|E_ZCL_AF_WR),  E_ZCL_UINT8,        (uint32)(&((tsCLD_Commissioning*)(0))->u8ConcentratorRadius),0},
    #endif

    #ifdef     CLD_COMM_ATTR_CONCENTRATOR_DISCVRY_TIME
        {E_CLD_CMSNG_ATTR_ID_CONCENTRATOR_DISCVRY_TIME,        (E_ZCL_AF_RD|E_ZCL_AF_WR),  E_ZCL_UINT8,        (uint32)(&((tsCLD_Commissioning*)(0))->u8ConcentratorDiscoveryTime),0},
    #endif

    };

    tsZCL_ClusterDefinition sCLD_Commissioning = {
            GENERAL_CLUSTER_ID_COMMISSIONING,
            FALSE,
            E_ZCL_SECURITY_APPLINK,
            (sizeof(asCLD_CommissioningClusterAttributeDefinitions) / sizeof(tsZCL_AttributeDefinition)),
            (tsZCL_AttributeDefinition*)asCLD_CommissioningClusterAttributeDefinitions
    };
    uint8 au8CommissioningClusterAttributeControlBits[(sizeof(asCLD_CommissioningClusterAttributeDefinitions) / sizeof(tsZCL_AttributeDefinition))];
#else
    tsZCL_ClusterDefinition sCLD_Commissioning = {
            GENERAL_CLUSTER_ID_COMMISSIONING,
            FALSE,
            E_ZCL_SECURITY_APPLINK,
            0,
            NULL
    };

#endif
/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
/****************************************************************************
 **
 ** NAME:       eCLD_CommissioningClusterCreate
 **
 ** DESCRIPTION:
 ** Creates a time cluster
 **
 ** PARAMETERS:                 Name                        Usage
 ** tsZCL_ClusterInstance    *psClusterInstance             Cluster structure
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC  teZCL_Status eCLD_CommissioningClusterCreate(
                tsZCL_ClusterInstance              *psClusterInstance,
                bool_t                              bIsServer,
                tsZCL_ClusterDefinition            *psClusterDefinition,
                uint8                               u8ClusterSecurity,
                void                               *pvEndPointSharedStructPtr,
                uint8                              *pu8AttributeControlBits)
{

    tsCLD_Commissioning *psCluster;

    #ifdef STRICT_PARAM_CHECK 
        /* Parameter check */
        if((psClusterInstance==NULL) ||
           (psClusterDefinition==NULL)  )
        {
            return E_ZCL_ERR_PARAMETER_NULL;
        }
    #endif

    /* Create an instance of a commissioning cluster */
    vZCL_InitializeClusterInstance(
                                   psClusterInstance, 
                                   bIsServer,
                                   psClusterDefinition,
                                   pvEndPointSharedStructPtr,
                                   pu8AttributeControlBits,
                                   NULL,
                                   NULL);

    /* Update cluster security */
    psClusterInstance->psClusterDefinition->u8ClusterControlFlags |= u8ClusterSecurity;

    //  attributes set default values
    psCluster = (tsCLD_Commissioning*)pvEndPointSharedStructPtr;


    return E_ZCL_SUCCESS;

}

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

#endif
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/


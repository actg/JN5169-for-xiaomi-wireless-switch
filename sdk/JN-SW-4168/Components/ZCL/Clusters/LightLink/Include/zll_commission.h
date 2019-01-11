/*****************************************************************************
 *
 * MODULE:              ZLL Commissoning Cluster
 *
 * COMPONENT:          zll_commission.h
 *
 * AUTHOR:
 *
 * DESCRIPTION:        Header for  Cluster
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/UnifiedZCL_ZLL102_HA122_Maintenance/Clusters/LightLink/Include/zll_commission.h $
 *
 * $Revision: 81940 $
 *
 * $LastChangedBy: nxp29772 $
 *
 * $LastChangedDate: 2016-07-29 13:17:14 +0100 (Fri, 29 Jul 2016) $
 *
 * $Id: zll_commission.h 81940 2016-07-29 12:17:14Z nxp29772 $
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

#ifndef ZLL_COMMISSION_H
#define ZLL_COMMISSION_H

#include <jendefs.h>
#include "dlist.h"
#include "zcl.h"
#include "zcl_customcommand.h"
#include "zcl_options.h"
#include "zll.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/* Cluster ID's */
#define ZLL_CLUSTER_ID_COMMISSIONING    0x1000

#define Z_COMMISSION_SERVER_DEVICE 0x1000
#define Z_COMMISSION_CLIENT_SERVER_DEVICE 0x1010
#define Z_COMMISSION_CLIENT_DEVICE 0x1020


#define ZLL_MAX_DEVICE_RECORDS          4
#define ZLL_MAX_GROUP_RECORDS          21
#define ZLL_MAX_ENDPOINT_RECORDS       8

#define ZLL_TEST_KEY_INDEX          0
#define ZLL_MASTER_KEY_INDEX        4
#define ZLL_CERTIFICATION_KEY_INDEX  15

#define ZLL_TEST_KEY_MASK            (1<<ZLL_TEST_KEY_INDEX)
#define ZLL_MASTER_KEY_MASK        (1<<ZLL_MASTER_KEY_INDEX)
#define ZLL_CERTIFICATION_KEY_MASK  (1<<ZLL_CERTIFICATION_KEY_INDEX)

//#define ZLL_SUPPORTED_KEYS (ZLL_TEST_KEY_MASK | ZLL_MASTER_KEY_MASK | ZLL_CERTIFICATION_KEY_MASK  )
#define ZLL_SUPPORTED_KEYS (ZLL_TEST_KEY_MASK | ZLL_CERTIFICATION_KEY_MASK  )

/*  Zigbee Information field bits */
#define ZLL_COORDINATOR         0x00
#define ZLL_ROUTER              0x01
#define ZLL_ZED                 0x02
#define ZLL_TYPE_MASK           0x03
#define ZLL_RXON_IDLE           (1<<2)

/* ZLL Information field bit masks */
#define ZLL_FACTORY_NEW         (1<<0)
#define ZLL_ADDR_ASSIGN         (1<<1)
#define ZLL_LINK_INIT           (1<<4)
#define ZLL_TIME_WINDOW         (1<<5)            // response only (don't care in request)

/* Identify duration field */
#define ZLL_IDENTIFY_STOP           0
#define ZLL_IDENTIFY_TIME_MS(a)     (a)
#define ZLL_IDENTIFY_DEFAULT        0xffff


/****************************************************************************/
/*              Cluster - Optional Attributes                */
/*                                                                          */
/* Add the following #define's to your zcl_options.h file to add optional   */
/* attributes.                               */
/****************************************************************************/

/* There are no attributes */

/* End of optional attributes */

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
#if 1
/* Attribute ID's */
typedef enum 
{
    E_CLD_HUH = 0x00,
    // there are no attributes
} teCLD_ZllCommission_ClusterID;

/* Identify Cluster */
typedef struct
{
    uint8 u8Huh;
} tsCLD_ZllCommission;


#endif

/* Command codes */
typedef enum 
{
    E_CLD_COMMISSION_CMD_SCAN_REQ = 0x00,               /* Mandatory (received by server) 0x00 */
    E_CLD_COMMISSION_CMD_SCAN_RSP,                      /* Mandatory (received by client) 0x01 */
    E_CLD_COMMISSION_CMD_DEVICE_INFO_REQ,               /* Mandatory (received by server) 0x02 */
    E_CLD_COMMISSION_CMD_DEVICE_INFO_RSP,               /* Mandatory (received by client) 0x03 */
    E_CLD_COMMISSION_CMD_IDENTIFY_REQ = 0x06,            /* Mandatory (received by server) 0x06 */
    E_CLD_COMMISSION_CMD_FACTORY_RESET_REQ,             /* Mandatory (received by server) 0x07 */
    E_CLD_COMMISSION_CMD_NETWORK_START_REQ = 0x10,      /* Mandatory (received by server) 0x10 */
    E_CLD_COMMISSION_CMD_NETWORK_START_RSP,             /* Mandatory (received by client) 0x11 */
    E_CLD_COMMISSION_CMD_NETWORK_JOIN_ROUTER_REQ,       /* Mandatory (received by server) 0x12 */
    E_CLD_COMMISSION_CMD_NETWORK_JOIN_ROUTER_RSP,       /* Mandatory (received by client) 0x13 */
    E_CLD_COMMISSION_CMD_NETWORK_JOIN_END_DEVICE_REQ,   /* Mandatory (received by server) 0x14 */
    E_CLD_COMMISSION_CMD_NETWORK_JOIN_END_DEVICE_RSP,   /* Mandatory (received by client) 0x15 */
    E_CLD_COMMISSION_CMD_NETWORK_UPDATE_REQ,            /* Mandatory (received by server) 0x16 */
} teCLD_ZllCommission_Command;

/* Scan Request command payload */
typedef struct
{
    uint32 u32TransactionId;
    uint8 u8ZigbeeInfo;
    uint8 u8ZllInfo;
} tsCLD_ZllCommission_ScanReqCommandPayload;

/* Scan Response command payload */
typedef struct
{
    uint32  u32TransactionId;
    uint8   u8RSSICorrection;
    uint8   u8ZigbeeInfo;
    uint8   u8ZllInfo;
    uint16  u16KeyMask;
    uint32  u32ResponseId;
    uint64  u64ExtPanId;
    uint8   u8NwkUpdateId;
    uint8   u8LogicalChannel;
    uint16  u16PanId;
    uint16  u16NwkAddr;
    uint8   u8NumberSubDevices;
    uint8   u8TotalGroupIds;
    uint8   u8Endpoint;
    uint16  u16ProfileId;
    uint16  u16DeviceId;
    uint8   u8Version;
    uint8   u8GroupIdCount;
} tsCLD_ZllCommission_ScanRspCommandPayload;


/* Device information Request command payload */
typedef struct
{
    uint32 u32TransactionId;
    uint8 u8StartIndex;
} tsCLD_ZllCommission_DeviceInfoReqCommandPayload;

/* Device Information Response command payload */
typedef struct
{
    uint32 u32TransactionId;
    uint8   u8NumberSubDevices;
    uint8   u8StartIndex;
    uint8   u8DeviceInfoRecordCount;
    tsCLD_ZllDeviceRecord asDeviceRecords[ZLL_MAX_DEVICE_RECORDS];
} tsCLD_ZllCommission_DeviceInfoRspCommandPayload;




/* Identify Request command payload */
typedef struct
{
    uint32  u32TransactionId;
    uint16   u16Duration;
} tsCLD_ZllCommission_IdentifyReqCommandPayload;

/* Factory Reset Request command payload */
typedef struct
{
    uint32 u32TransactionId;
} tsCLD_ZllCommission_FactoryResetReqCommandPayload;


/* Network Start Request command payload */
typedef struct
{
    uint32 u32TransactionId;
    uint64  u64ExtPanId;
    uint8   u8KeyIndex;
    uint8   au8NwkKey[16];
    uint8   u8LogicalChannel;
    uint16  u16PanId;
    uint16  u16NwkAddr;
    uint16  u16GroupIdBegin;
    uint16  u16GroupIdEnd;
    uint16  u16FreeNwkAddrBegin;
    uint16  u16FreeNwkAddrEnd;
    uint16  u16FreeGroupIdBegin;
    uint16  u16FreeGroupIdEnd;
    uint64  u64InitiatorIEEEAddr;
    uint16  u16InitiatorNwkAddr;
} tsCLD_ZllCommission_NetworkStartReqCommandPayload;


/* Network start Response command payload */
typedef struct
{
    uint32 u32TransactionId;
    uint8   u8Status;
    uint64  u64ExtPanId;
    uint8   u8NwkUpdateId;
    uint8   u8LogicalChannel;
    uint16  u16PanId;
} tsCLD_ZllCommission_NetworkStartRspCommandPayload;

/* Network Join Router Request command payload */
typedef struct
{
    uint32 u32TransactionId;
    uint64  u64ExtPanId;
    uint8   u8KeyIndex;
    uint8   au8NwkKey[16];
    uint8   u8NwkUpdateId;
    uint8   u8LogicalChannel;
    uint16  u16PanId;
    uint16  u16NwkAddr;
    uint16  u16GroupIdBegin;
    uint16  u16GroupIdEnd;
    uint16  u16FreeNwkAddrBegin;
    uint16  u16FreeNwkAddrEnd;
    uint16  u16FreeGroupIdBegin;
    uint16  u16FreeGroupIdEnd;
} tsCLD_ZllCommission_NetworkJoinRouterReqCommandPayload;


/* Network Join Router Response command payload */
typedef struct
{
    uint32  u32TransactionId;
    uint8   u8Status;
} tsCLD_ZllCommission_NetworkJoinRouterRspCommandPayload;


/*  command payload */
typedef struct
{
    uint32 u32TransactionId;
    uint64  u64ExtPanId;
    uint8   u8KeyIndex;
    uint8   au8NwkKey[16];
    uint8   u8NwkUpdateId;
    uint8   u8LogicalChannel;
    uint16  u16PanId;
    uint16  u16NwkAddr;
    uint16  u16GroupIdBegin;
    uint16  u16GroupIdEnd;
    uint16  u16FreeNwkAddrBegin;
    uint16  u16FreeNwkAddrEnd;
    uint16  u16FreeGroupIdBegin;
    uint16  u16FreeGroupIdEnd;
} tsCLD_ZllCommission_NetworkJoinEndDeviceReqCommandPayload;


/* Network join end device response command payload */
typedef struct
{
    uint32 u32TransactionId;
    uint8   u8Status;
} tsCLD_ZllCommission_NetworkJoinEndDeviceRspCommandPayload;


/* Network Update Request command payload */
typedef struct
{
    uint32 u32TransactionId;
    uint64  u64ExtPanId;
    uint8   u8NwkUpdateId;
    uint8   u8LogicalChannel;
    uint16  u16PanId;
    uint16  u16NwkAddr;
} tsCLD_ZllCommission_NetworkUpdateReqCommandPayload;

#if 0
/* Endpoint Information command payload */
typedef struct
{
    uint32 u32TransactionId;
    uint64  u64IEEEAddr;
    uint16  u16NwkAddr;
    uint8   u8Endpoint;
    uint16  u16ProfileID;
    uint16  u16DeviceID;
    uint8   u8Version;
} tsCLD_ZllCommission_EndpointInformationCommandPayload;
#endif









/* Definition of Call back Event Structure */
typedef struct
{
    uint8   u8CommandId;
    union
    {
        tsCLD_ZllCommission_ScanReqCommandPayload                   *psScanReqPayload;
        tsCLD_ZllCommission_ScanRspCommandPayload                   *psScanRspPayload;
        tsCLD_ZllCommission_IdentifyReqCommandPayload               *psIdentifyReqPayload;
        tsCLD_ZllCommission_DeviceInfoReqCommandPayload             *psDeviceInfoReqPayload;
        tsCLD_ZllCommission_DeviceInfoRspCommandPayload             *psDeviceInfoRspPayload;
        tsCLD_ZllCommission_FactoryResetReqCommandPayload           *psFactoryResetPayload;
        tsCLD_ZllCommission_NetworkStartReqCommandPayload           *psNwkStartReqPayload;
        tsCLD_ZllCommission_NetworkStartRspCommandPayload           *psNwkStartRspPayload;
        tsCLD_ZllCommission_NetworkJoinRouterReqCommandPayload      *psNwkJoinRouterReqPayload;
        tsCLD_ZllCommission_NetworkJoinRouterRspCommandPayload      *psNwkJoinRouterRspPayload;
        tsCLD_ZllCommission_NetworkJoinEndDeviceReqCommandPayload   *psNwkJoinEndDeviceReqPayload;
        tsCLD_ZllCommission_NetworkJoinEndDeviceRspCommandPayload   *psNwkJoinEndDeviceRspPayload;
        tsCLD_ZllCommission_NetworkUpdateReqCommandPayload          *psNwkUpdateReqPayload;
    } uMessage;
} tsCLD_ZllCommissionCallBackMessage;


/* Custom data structure */
typedef struct
{
    tsZCL_ReceiveEventAddressInterPan        sRxInterPanAddr;
    tsZCL_CallBackEvent                      sCustomCallBackEvent;
    tsCLD_ZllCommissionCallBackMessage       sCallBackMessage;
} tsCLD_ZllCommissionCustomDataStructure;

typedef struct
{
    teCLD_ZllCommission_Command eCommand;
    ZPS_tsInterPanAddress       sSrcAddr;
    union
    {
        tsCLD_ZllCommission_ScanReqCommandPayload                   sScanReqPayload;
        tsCLD_ZllCommission_ScanRspCommandPayload                   sScanRspPayload;
        tsCLD_ZllCommission_IdentifyReqCommandPayload               sIdentifyReqPayload;
        tsCLD_ZllCommission_DeviceInfoReqCommandPayload             sDeviceInfoReqPayload;
        tsCLD_ZllCommission_DeviceInfoRspCommandPayload             sDeviceInfoRspPayload;
        tsCLD_ZllCommission_FactoryResetReqCommandPayload           sFactoryResetPayload;
        tsCLD_ZllCommission_NetworkStartReqCommandPayload           sNwkStartReqPayload;
        tsCLD_ZllCommission_NetworkStartRspCommandPayload           sNwkStartRspPayload;
        tsCLD_ZllCommission_NetworkJoinRouterReqCommandPayload      sNwkJoinRouterReqPayload;
        tsCLD_ZllCommission_NetworkJoinRouterRspCommandPayload      sNwkJoinRouterRspPayload;
        tsCLD_ZllCommission_NetworkJoinEndDeviceReqCommandPayload   sNwkJoinEndDeviceReqPayload;
        tsCLD_ZllCommission_NetworkJoinEndDeviceRspCommandPayload   sNwkJoinEndDeviceRspPayload;
        tsCLD_ZllCommission_NetworkUpdateReqCommandPayload          sNwkUpdateReqPayload;
    }uPayload;
} tsZllMessage;


typedef struct
{
    union
    {
        tsCLD_ZllCommission_ScanReqCommandPayload                   sScanReqPayload;
        tsCLD_ZllCommission_ScanRspCommandPayload                   sScanRspPayload;
        tsCLD_ZllCommission_IdentifyReqCommandPayload               sIdentifyReqPayload;
        tsCLD_ZllCommission_DeviceInfoReqCommandPayload             sDeviceInfoReqPayload;
        tsCLD_ZllCommission_DeviceInfoRspCommandPayload             sDeviceInfoRspPayload;
        tsCLD_ZllCommission_FactoryResetReqCommandPayload           sFactoryResetPayload;
        tsCLD_ZllCommission_NetworkStartReqCommandPayload           sNwkStartReqPayload;
        tsCLD_ZllCommission_NetworkStartRspCommandPayload           sNwkStartRspPayload;
        tsCLD_ZllCommission_NetworkJoinRouterReqCommandPayload      sNwkJoinRouterReqPayload;
        tsCLD_ZllCommission_NetworkJoinRouterRspCommandPayload      sNwkJoinRouterRspPayload;
        tsCLD_ZllCommission_NetworkJoinEndDeviceReqCommandPayload   sNwkJoinEndDeviceReqPayload;
        tsCLD_ZllCommission_NetworkJoinEndDeviceRspCommandPayload   sNwkJoinEndDeviceRspPayload;
        tsCLD_ZllCommission_NetworkUpdateReqCommandPayload          sNwkUpdateReqPayload;
    }uPayload;
} tsZllPayloads;


/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC teZCL_Status eCLD_ZllCommissionCreateCommission(
                    tsZCL_ClusterInstance              *psClusterInstance,
                    bool_t                              bIsServer,
                    tsZCL_ClusterDefinition            *psClusterDefinition,
                    void                               *pvSharedStructPtr,
                    uint8              *pu8AttributeControlBits,
                    tsCLD_ZllCommissionCustomDataStructure  *psCustomDataStructure);

PUBLIC teZCL_Status eCLD_ZllCommissionCommandScanReqCommandSend(
                    ZPS_tsInterPanAddress       *psDestinationAddress,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_ZllCommission_ScanReqCommandPayload  *psPayload);

PUBLIC teZCL_Status eCLD_ZllCommissionCommandScanRspCommandSend(
                    ZPS_tsInterPanAddress       *psDestinationAddress,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_ZllCommission_ScanRspCommandPayload *psPayload);

PUBLIC teZCL_Status eCLD_ZllCommissionCommandDeviceInfoReqCommandSend(
                    ZPS_tsInterPanAddress       *psDestinationAddress,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_ZllCommission_DeviceInfoReqCommandPayload *psPayload);

PUBLIC teZCL_Status eCLD_ZllCommissionCommandDeviceInfoRspCommandSend(
                    ZPS_tsInterPanAddress       *psDestinationAddress,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_ZllCommission_DeviceInfoRspCommandPayload *psPayload);

PUBLIC teZCL_Status eCLD_ZllCommissionCommandDeviceIndentifyReqCommandSend(
                    ZPS_tsInterPanAddress       *psDestinationAddress,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_ZllCommission_IdentifyReqCommandPayload *psPayload);
/*
PUBLIC teZCL_Status eCLD_ZllCommissionCommandDeviceIdentifyRspCommandSend(
                    ZPS_tsInterPanAddress       *psDestinationAddress,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_ZllCommission_IdentifyRequestCommandPayload *psPayload);
*/
PUBLIC teZCL_Status eCLD_ZllCommissionCommandFactoryResetReqCommandSend(
                    ZPS_tsInterPanAddress       *psDestinationAddress,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_ZllCommission_FactoryResetReqCommandPayload *psPayload);

PUBLIC teZCL_Status eCLD_ZllCommissionCommandNetworkStartReqCommandSend(
                    ZPS_tsInterPanAddress       *psDestinationAddress,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_ZllCommission_NetworkStartReqCommandPayload *psPayload);

PUBLIC teZCL_Status eCLD_ZllCommissionCommandNetworkStartRspCommandSend(
                    ZPS_tsInterPanAddress       *psDestinationAddress,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_ZllCommission_NetworkStartRspCommandPayload *psPayload);

PUBLIC teZCL_Status eCLD_ZllCommissionCommandNetworkJoinRouterReqCommandSend(
                    ZPS_tsInterPanAddress       *psDestinationAddress,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_ZllCommission_NetworkJoinRouterReqCommandPayload *psPayload);

PUBLIC teZCL_Status eCLD_ZllCommissionCommandNetworkJoinRouterRspCommandSend(
                    ZPS_tsInterPanAddress       *psDestinationAddress,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_ZllCommission_NetworkJoinRouterRspCommandPayload *psPayload);

PUBLIC teZCL_Status eCLD_ZllCommissionCommandNetworkJoinEndDeviceReqCommandSend(
                    ZPS_tsInterPanAddress       *psDestinationAddress,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_ZllCommission_NetworkJoinEndDeviceReqCommandPayload *psPayload);

PUBLIC teZCL_Status eCLD_ZllCommissionCommandNetworkJoinEndDeviceRspCommandSend(
                    ZPS_tsInterPanAddress       *psDestinationAddress,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_ZllCommission_NetworkJoinEndDeviceRspCommandPayload *psPayload);

PUBLIC teZCL_Status eCLD_ZllCommissionCommandNetworkUpdateReqCommandSend(
                    ZPS_tsInterPanAddress       *psDestinationAddress,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_ZllCommission_NetworkUpdateReqCommandPayload *psPayload);



PUBLIC teZCL_Status eCLD_ZllCommissionCommandHandler(
                    ZPS_tsAfEvent               *pZPSevent,
                    tsZCL_EndPointDefinition    *psEndPointDefinition,
                    tsZCL_ClusterInstance       *psClusterInstance);


/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/


extern tsZCL_AttributeDefinition asCLD_ZllCommissionClusterAttributeDefinitions[];
extern tsZCL_ClusterDefinition sCLD_ZllCommission;

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

#endif /* ZLL_COMMISSION_H */

/*****************************************************************************
 *
 * MODULE:          Zigbee Protocol Stack Application Layer
 *
 * COMPONENT:       zps_apl_af.h
 *
 * AUTHOR:          MRW
 *
 * DESCRIPTION:     Provides a user friendly API to the application object
 *                  for making data requests
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/Zigbee%20Protocol%20Stack/Modules/APL/Branches/ZBPRO_R20_v1.1/Include/zps_apl_af.h $
 *
 * $Revision: 88639 $
 *
 * $LastChangedBy: nxp29741 $
 *
 * $LastChangedDate: 2017-06-01 14:17:09 +0100 (Thu, 01 Jun 2017) $
 *
 * $Id: zps_apl_af.h 88639 2017-06-01 13:17:09Z nxp29741 $
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
 * Copyright Jennic Ltd. 2008 All rights reserved
 *
 ****************************************************************************/

#ifndef ZPS_APL_AF_H_
#define ZPS_APL_AF_H_

#include <jendefs.h>
#include <mac_vs_sap.h>
#include <zps_nwk_sap.h>
#include <pdum_apl.h>
#include <zps_apl.h>
#include <zps_apl_aps.h>
#ifndef ZPS_APL_OPT_MULTIPLE_INSTANCES
#include <zps_apl_zdo.h>
#endif
#include <zps_apl_zdp.h>
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#ifndef ZPS_APL_INLINE
#define ZPS_APL_INLINE  INLINE
#endif


#ifndef ZPS_APL_ALWAYS_INLINE
#define ZPS_APL_ALWAYS_INLINE  ALWAYS_INLINE
#endif

#define ZPS_E_APL_AF_ALL_ENDPOINTS          (0xff)

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

typedef struct {
    void (*prCallback)(void *, void *);
    void *pvContext;
    void *pvParam;
} zps_tsTimeEvent;

/* Security modes for data requests */
typedef enum {
    ZPS_E_APL_AF_UNSECURE = 0,
    ZPS_E_APL_AF_SECURE     = 0x01,
    ZPS_E_APL_AF_SECURE_NWK = 0x02,
    ZPS_E_APL_AF_EXT_NONCE  = 0x10,
    ZPS_E_APL_AF_WILD_PROFILE  = 0x20,
} ZPS_teAplAfSecurityMode;


/* Zigbee Greenpower status codes */
typedef enum {
    ZPS_E_APL_AF_GP_SECURITY_SUCCESS = ZPS_E_SUCCESS,
    ZPS_E_APL_AF_GP_NO_SECURITY,
    ZPS_E_APL_AF_GP_COUNTER_FAILURE,
    ZPS_E_APL_AF_GP_AUTH_FAILURE,
    ZPS_E_APL_AF_GP_UNPROCESSED,
} ZPS_teAplAfGpDataIndStatus;

/* Broadcast modes for data requests */
typedef enum {
    ZPS_E_APL_AF_BROADCAST_ALL, /* broadcast to all nodes, including all end devices */
    ZPS_E_APL_AF_BROADCAST_RX_ON, /* broadcast to all nodes with their receivers enabled when idle */
    ZPS_E_APL_AF_BROADCAST_ZC_ZR /* broadcast only to coordinator and routers */
} ZPS_teAplAfBroadcastMode;

/* Node descriptor */
typedef struct {
    uint32                   : 8; /* padding */
    uint32 eLogicalType      : 3;
    uint32 bComplexDescAvail : 1;
    uint32 bUserDescAvail    : 1;
    uint32 eReserved         : 3; /* reserved */
    uint32 eFrequencyBand    : 5;
    uint32 eApsFlags         : 3;
    uint32 u8MacFlags        : 8;
    uint16 u16ManufacturerCode;
    uint8 u8MaxBufferSize;
    uint16 u16MaxRxSize;
    uint16 u16ServerMask;
    uint16 u16MaxTxSize;
    uint8 u8DescriptorCapability;
} ZPS_tsAplAfNodeDescriptor;

/* Node power descriptor */
typedef struct {
    uint32 eCurrentPowerMode        : 4;
    uint32 eAvailablePowerSources   : 4;
    uint32 eCurrentPowerSource      : 4;
    uint32 eCurrentPowerSourceLevel : 4;
} ZPS_tsAplAfNodePowerDescriptor;

/* Endpoint simple descriptor */
typedef struct {
    uint16 u16ApplicationProfileId;
    uint16 u16DeviceId;
    uint8  u8DeviceVersion;
    uint8  u8Endpoint;
    uint8  u8InClusterCount;
    uint8  u8OutClusterCount;
    const uint16 *pu16InClusterList;
    const uint16 *pu16OutClusterList;
    uint8 *au8InDiscoveryEnabledFlags;
    uint8 *au8OutDiscoveryEnabledFlags;
} ZPS_tsAplAfSimpleDescriptor;

/* Node's user descriptor */
typedef struct {
    char szUserDescriptor[16];
} ZPS_tsAplAfUserDescriptor;

typedef enum {
    ZPS_EVENT_NONE,                                     /*  0, 0x00 */
    ZPS_EVENT_APS_DATA_INDICATION,                      /*  1, 0x01 */
    ZPS_EVENT_APS_DATA_CONFIRM,                         /*  2, 0x02 */
    ZPS_EVENT_APS_DATA_ACK,                             /*  3, 0x03 */
    ZPS_EVENT_NWK_STARTED,                              /*  4, 0x04 */
    ZPS_EVENT_NWK_JOINED_AS_ROUTER,                     /*  5, 0x05 */
    ZPS_EVENT_NWK_JOINED_AS_ENDDEVICE,                  /*  6, 0x06 */
    ZPS_EVENT_NWK_FAILED_TO_START,                      /*  7, 0x07 */
    ZPS_EVENT_NWK_FAILED_TO_JOIN,                       /*  8, 0x08 */
    ZPS_EVENT_NWK_NEW_NODE_HAS_JOINED,                  /*  9, 0x09 */
    ZPS_EVENT_NWK_DISCOVERY_COMPLETE,                   /* 10, 0x0a */
    ZPS_EVENT_NWK_LEAVE_INDICATION,                     /* 11, 0x0b */
    ZPS_EVENT_NWK_LEAVE_CONFIRM,                        /* 12, 0x0c */
    ZPS_EVENT_NWK_STATUS_INDICATION,                    /* 13, 0x0d */
    ZPS_EVENT_NWK_ROUTE_DISCOVERY_CONFIRM,              /* 14, 0x0e */
    ZPS_EVENT_NWK_POLL_CONFIRM,                         /* 15, 0x0f */
    ZPS_EVENT_NWK_ED_SCAN,                              /* 16, 0x10 */
    ZPS_EVENT_ZDO_BIND,                                 /* 17, 0x11 */
    ZPS_EVENT_ZDO_UNBIND,                               /* 18, 0x12 */
    ZPS_EVENT_ZDO_LINK_KEY,                             /* 19, 0x13 */
    ZPS_EVENT_BIND_REQUEST_SERVER,                      /* 20, 0x14.*/
    ZPS_EVENT_ERROR,                                    /* 21, 0x15 */
    ZPS_EVENT_APS_INTERPAN_DATA_INDICATION,             /* 22, 0x16 */
    ZPS_EVENT_APS_INTERPAN_DATA_CONFIRM,                /* 23, 0x17 */
    ZPS_EVENT_APS_ZGP_DATA_INDICATION,                  /* 24, 0x18 */
    ZPS_EVENT_APS_ZGP_DATA_CONFIRM,                     /* 25, 0x19 */
} ZPS_teAfEventType;


typedef struct
{
    uint8  u8DstAddrMode;
    ZPS_tuAddress uDstAddress;
    uint8  u8DstEndpoint;
    uint8  u8SrcAddrMode;
    ZPS_tuAddress uSrcAddress;
    uint8  u8SrcEndpoint;
    uint16 u16ProfileId;
    uint16 u16ClusterId;
    PDUM_thAPduInstance hAPduInst;
    uint8 eStatus;
    uint8 eSecurityStatus;
    uint8 u8LinkQuality;
    uint32 u32RxTime;
    bool_t bFramePending;
} ZPS_tsAfDataIndEvent;

typedef struct {
    uint8 u8Status;
    uint8 u8SrcEndpoint;
    uint8 u8DstEndpoint;
    uint8 u8DstAddrMode;
    ZPS_tuAddress uDstAddr;
    uint8   u8SequenceNum;
} ZPS_tsAfDataConfEvent;

typedef struct {
    uint8   u8Status;
    uint8   u8SrcEndpoint;
    uint8   u8DstEndpoint;
    uint8   u8DstAddrMode;
    uint16  u16DstAddr;
    uint8   u8SequenceNum;
    uint16  u16ProfileId;
    uint16  u16ClusterId;
} ZPS_tsAfDataAckEvent;

typedef struct {
    uint8 u8Status;
} ZPS_tsAfNwkFormationEvent;

typedef struct
{
    uint16 u16Addr;
} ZPS_tsAfNwkJoinedEvent;

typedef struct
{
    uint8 u8Status;
} ZPS_tsAfNwkJoinFailedEvent;

typedef struct
{
    uint32 u32UnscannedChannels;
    uint8 eStatus;
    uint8 u8NetworkCount;
    uint8 u8SelectedNetwork;
    ZPS_tsNwkNetworkDescr * psNwkDescriptors;
} ZPS_tsAfNwkDiscoveryEvent;

typedef struct
{
    uint64 u64ExtAddr;     /**< Device's IEEE address */
    uint16 u16NwkAddr;     /**< Extended address of device wishing to associate */
    uint8  u8Capability;   /**< Device capabilities */
    uint8  u8Rejoin;       /**< The nature of the join or rejoin */
    uint8  u8SecureRejoin; /**< Indicates if the rejoin was a secure rejoin */
} ZPS_tsAfNwkJoinIndEvent;

typedef struct {
    uint64 u64ExtAddr;     /**< Device's IEEE address */
    uint8  u8Rejoin;
} ZPS_tsAfNwkLeaveIndEvent;

typedef struct {
    uint64 u64ExtAddr;
    uint8  eStatus;
    bool_t bRejoin;
} ZPS_tsAfNwkLeaveConfEvent;

typedef struct {
    uint16  u16NwkAddr;
    uint8   u8Status;
} ZPS_tsAfNwkStatusIndEvent;

typedef struct {
    uint16  u16DstAddress;
    uint8   u8Status;
    uint8   u8NwkStatus;
} ZPS_tsAfNwkRouteDiscoveryConfEvent;

typedef struct {
    uint8   u8Status;
} ZPS_tsAfPollConfEvent;

typedef struct {
    ZPS_tuAddress uDstAddr;
    uint8 u8DstAddrMode;
    uint8 u8SrcEp;
    uint8 u8DstEp;
} ZPS_tsAfZdoBindEvent;

typedef ZPS_tsAfZdoBindEvent ZPS_tsAfZdoUnbindEvent;

typedef struct {
    uint64 u64IeeeLinkAddr;
} ZPS_tsAfZdoLinkKeyEvent;

typedef ZPS_tsNwkNlmeCfmEdScan ZPS_tsAfNwkEdScanConfEvent;

typedef struct {
    enum {
        ZPS_ERROR_APDU_TOO_SMALL,
        ZPS_ERROR_APDU_INSTANCES_EXHAUSTED,
        ZPS_ERROR_NO_APDU_CONFIGURED,
        ZPS_ERROR_OS_MESSAGE_QUEUE_OVERRUN,
        ZPS_ERROR_APS_SECURITY_FAIL,
    } eError;

    union {
        struct {
            uint16 u16ProfileId;
            uint16 u16ClusterId;
            union {
                uint16 u16SrcAddr;
                uint64 u64SrcAddr;
            }uAddr;
            uint16 u16DataSize;
            PDUM_thAPdu hAPdu;
            uint8  u8SrcEndpoint;
            uint8  u8DstEndpoint;
            uint8  u8SrcAddrMode;
        }sAfErrorApdu;

        struct {
            OS_thMessage hMessage;
        } sAfErrorOsMessageOverrun;

    } uErrorData;
} ZPS_tsAfErrorEvent;


typedef struct
{
    uint8 u8Status;
    uint8 u8SrcEndpoint;
    uint32 u32FailureCount;
}ZPS_tsAfBindRequestServerEvent;


typedef struct
{
    ZPS_tsInterPanAddress sDstAddr;
    uint8  u8SrcAddrMode;
    uint16 u16SrcPan;
    uint64 u64SrcAddress;
    uint16 u16ProfileId;
    uint16 u16ClusterId;
    PDUM_thAPduInstance hAPduInst;
    uint8 eStatus;
    uint8 u8DstEndpoint;
    uint8 u8LinkQuality;
} ZPS_tsAfInterPanDataIndEvent;

typedef struct {
    uint8 u8Status;
    uint8 u8Handle;
} ZPS_tsAfInterPanDataConfEvent;


typedef struct
{
    uint32   u8Status               :8;
    uint32   u2ApplicationId        :2;
    uint32   u2SecurityLevel        :2;
    uint32   u2SecurityKeyType      :2;
    uint32   u8LinkQuality          :8;
    uint32   bAutoCommissioning     :1;
    uint32   bRxAfterTx             :1;
    uint32   u8CommandId            :8;
    uint32   u32Mic;
	ZPS_tuAddress uSrcAddress;
    uint32  u32SrcId;
    uint32  u32SecFrameCounter;
    uint16  u16SrcPanId;
    uint8   u8SrcAddrMode;
    uint8   u8SeqNum;
    PDUM_thAPduInstance hAPduInst;
} ZPS_tsAfZgpDataIndEvent;

typedef struct {
    uint8 u8Status;
    uint8 u8Handle;
} ZPS_tsAfZgpDataConfEvent;

typedef union
{
    ZPS_tsAfDataIndEvent                sApsDataIndEvent;
    ZPS_tsAfDataConfEvent               sApsDataConfirmEvent;
    ZPS_tsAfDataAckEvent                sApsDataAckEvent;
    ZPS_tsAfNwkFormationEvent           sNwkFormationEvent;
    ZPS_tsAfNwkJoinedEvent              sNwkJoinedEvent;
    ZPS_tsAfNwkJoinFailedEvent          sNwkJoinFailedEvent;
    ZPS_tsAfNwkDiscoveryEvent           sNwkDiscoveryEvent;
    ZPS_tsAfNwkJoinIndEvent             sNwkJoinIndicationEvent;
    ZPS_tsAfNwkLeaveIndEvent            sNwkLeaveIndicationEvent;
    ZPS_tsAfNwkLeaveConfEvent           sNwkLeaveConfirmEvent;
    ZPS_tsAfNwkStatusIndEvent           sNwkStatusIndicationEvent;
    ZPS_tsAfNwkRouteDiscoveryConfEvent  sNwkRouteDiscoveryConfirmEvent;
    ZPS_tsAfPollConfEvent               sNwkPollConfirmEvent;
    ZPS_tsAfNwkEdScanConfEvent          sNwkEdScanConfirmEvent;
    ZPS_tsAfErrorEvent                  sAfErrorEvent;
    ZPS_tsAfZdoBindEvent                sZdoBindEvent;
    ZPS_tsAfZdoUnbindEvent              sZdoUnbindEvent;
    ZPS_tsAfZdoLinkKeyEvent             sZdoLinkKeyEvent;
    ZPS_tsAfBindRequestServerEvent      sBindRequestServerEvent;
    ZPS_tsAfInterPanDataIndEvent        sApsInterPanDataIndEvent;
    ZPS_tsAfInterPanDataConfEvent       sApsInterPanDataConfirmEvent;
    ZPS_tsAfZgpDataIndEvent             sApsZgpDataIndEvent;
    ZPS_tsAfZgpDataConfEvent            sApsZgpDataConfirmEvent;
} ZPS_tuAfEventData;

/* event messages from the stack to the application */
typedef struct {
    ZPS_teAfEventType eType;
    ZPS_tuAfEventData uEvent;
} ZPS_tsAfEvent;

typedef struct {
    ZPS_tuAddress uDstAddr;
    uint16 u16ClusterId;
    uint16 u16ProfileId;
    uint8 u8SrcEp;
    ZPS_teAplApsdeAddressMode eDstAddrMode;
    uint8 u8DstEp;
    ZPS_teAplAfSecurityMode eSecurityMode;
    uint8 u8Radius;
}ZPS_tsAfProfileDataReq;

typedef enum
{
  ZPS_LEAVE_ORIGIN_NLME = 0,                  /* LEAVE_FROM_NLME */
  ZPS_LEAVE_ORIGIN_MGMT_LEAVE,                /* LEAVE_FROM_MGMT_LEAVE */
  ZPS_LEAVE_ORIGIN_REMOVE_DEVICE              /* LEAVE_FROM_REMOVE_DEVICE */
}ZPS_teLeaveActions;

typedef enum
{
  ZPS_E_ENTRY_ADDED = 0,                  /* LEAVE_FROM_NLME */
  ZPS_E_ENTRY_REPLACED,                /* LEAVE_FROM_MGMT_LEAVE */
  ZPS_E_QUEUE_FULL              /* LEAVE_FROM_REMOVE_DEVICE */
}ZPS_teZgpQueueActions;


typedef enum
{
  ZPS_E_ZGP_ZIGBEE_NWK_KEY = 1,
  ZPS_E_ZGP_GROUP_KEY = 2 ,
  ZPS_E_ZGP_NWK_KEY_DERIVED_GRP_KEY = 3,
  ZPS_E_ZGP_INDIVIDUAL_KEY = 4,
  ZPS_E_ZGP_DERIVED_INDIVIDUAL_KEY = 7,
  ZPS_E_ZGP_OAP_TC_LK = 8
}ZPS_teZgpKeyType;

typedef enum
{
    ZPS_E_MATCH = 0,
    ZPS_E_DROP_FRAME,
    ZPS_E_PASS_UNPROCESSED
}ZPS_teSecActions;
typedef union
{
    uint64 u64Address;
    uint32 u32SrcId;
}ZPS_tuZgpGreenPowerId;

typedef struct
{
    uint8 u8Handle;
    uint8 u8ApplicationId;
    uint8 u8SeqNum;
    uint8 u8TxOptions;
    uint16 u16Panid;
    uint16 u16DstAddr;
    uint16 u16TxQueueEntryLifetime;
    ZPS_tuZgpGreenPowerId uGpId;
    bool_t bDataFrame;
}ZPS_tsZgpGreenPowerReq;

typedef struct
{
    ZPS_tsZgpGreenPowerReq sReq;
    bool_t bValid;
    PDUM_thNPdu hNPdu;
}ZPS_tsZgpTxGpQueueEntry;

/* Security table structure */
typedef struct
{
    AESSW_Block_u uSecurityKey;
    ZPS_tuZgpGreenPowerId uGpId;
    uint32        u32Counter;
    uint8         u8SecurityLevel;
    uint8         u8KeyType;
    bool_t        bValid;
} ZPS_tsZgpGpstEntry;


typedef struct
{
    ZPS_tsZgpGpstEntry* psGpSecTable;
    uint8 u8Size;
}ZPS_tsZgpGpst;

typedef struct
{
    ZPS_tsZgpTxGpQueueEntry* psTxQTable;
    uint8 u8Size;
}ZPS_tsZgpTxGpQueue;

typedef struct
{
    ZPS_tsZgpGpst  *psGpst;
    ZPS_tsZgpTxGpQueue *psTxQueue;
    ZPS_tsTsvTimer *psTxAgingTimer;
    TSV_Timer_s *psTxBiDirTimer;
    uint16 u16MsecInterval;
    uint8 u8TxPoint;
}ZPS_tsZgpGreenPowerContext;

typedef struct
{
    ZPS_tuZgpGreenPowerId uGpId;
    uint32 u32FrameCounter;
    uint8 u8SecurityLevel;
    uint8 u8KeyType;
    uint8 u8ApplicationId;
}ZPS_tsZgpSecReq;

typedef uint8 (*pfnZgpType) (ZPS_tsZgpSecReq* psSec,uint8 *pu8SecIndex);


struct pdum_tsAPduInstance_tag {
    uint8 *au8Storage;
    uint16 u16Size;
    uint16 u16NextAPduInstIdx;
    uint16 u16APduIdx;
};

typedef struct pdum_tsAPduInstance_tag pdum_tsAPduInstance;

#define APDU_BUF(HANDLE, LOCATION)  ((pdum_tsAPduInstance*)HANDLE)->au8Storage[LOCATION]
#define APDU_BUF_INC(HANDLE, LOCATION)  ((pdum_tsAPduInstance*)HANDLE)->au8Storage[LOCATION++]

#define APDU_BUF_WRITE16(VAL, HANDLE, LOCATION) vWrite16Nbo(VAL, &APDU_BUF(HANDLE, LOCATION))
#define APDU_BUF_WRITE16_INC(VAL, HANDLE, LOCATION) vWrite16Nbo(VAL, &APDU_BUF(HANDLE, LOCATION)); LOCATION += 2

#define APDU_BUF_READ16(VAR, HANDLE, LOCATION) VAR = u16Read16Nbo( &APDU_BUF(HANDLE, LOCATION) )
#define APDU_BUF_READ16_INC(VAR, HANDLE, LOCATION) VAR = u16Read16Nbo( &APDU_BUF(HANDLE, LOCATION) ); LOCATION += 2

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC ZPS_teStatus ZPS_eAplAfInit(void);
PUBLIC void ZPS_vTCSetCallback(void*);
/****************************************************************************/
/***        Exported Private Functions (must not be called by ZPS user)     */
/****************************************************************************/

PUBLIC ZPS_teStatus zps_eAplAfSetEndpointState(void *pvApl, uint8 u8Endpoint, bool bEnabled);
PUBLIC ZPS_teStatus zps_eAplAfGetEndpointState(void *pvApl, uint8 u8Endpoint, bool *pbEnabled );
PUBLIC ZPS_teStatus zps_eAplAfSetEndpointDiscovery(void *pvApl, uint8 u8Endpoint, uint16 u16ClusterId, bool bOutput, bool bDiscoverable);
PUBLIC ZPS_teStatus zps_eAplAfGetEndpointDiscovery(void *pvApl, uint8 u8Endpoint, uint16 u16ClusterId, bool bOutput, bool_t *pbDiscoverable);
PUBLIC ZPS_teStatus zps_eAplAfGetNodeDescriptor(void *pvApl, ZPS_tsAplAfNodeDescriptor *psDesc);
PUBLIC ZPS_teStatus zps_eAplAfGetNodePowerDescriptor(void *pvApl, ZPS_tsAplAfNodePowerDescriptor *psDesc);
PUBLIC ZPS_teStatus zps_eAplAfGetSimpleDescriptor(void *pvApl, uint8 u8Endpoint, ZPS_tsAplAfSimpleDescriptor *psDesc);
PUBLIC ZPS_teStatus zps_eAplAfUnicastDataReq(void *pvApl, PDUM_thAPduInstance hAPduInst, uint32 u32ClId_DstEp_SrcEp, uint16 u16DestAddr, uint16 u16SecMd_Radius, uint8 *pu8SeqNum);
PUBLIC ZPS_teStatus zps_eAplAfUnicastIeeeDataReq(void *pvApl, PDUM_thAPduInstance hAPduInst, uint32 u32ClId_DstEp_SrcEp, uint64 *pu64DestAddr, uint16 u16SecMd_Radius, uint8 *pu8SeqNum);
PUBLIC ZPS_teStatus zps_eAplAfUnicastAckDataReq(void *pvApl, PDUM_thAPduInstance hAPduInst, uint32 u32ClId_DstEp_SrcEp, uint16 u16DestAddr, uint16 u16SecMd_Radius, uint8 *pu8SeqNum);
PUBLIC ZPS_teStatus zps_eAplAfUnicastIeeeAckDataReq(void *pvApl, PDUM_thAPduInstance hAPduInst, uint32 u32ClId_DstEp_SrcEp, uint64 *pu64DestAddr, uint16 u16SecMd_Radius, uint8 *pu8SeqNum);
PUBLIC ZPS_teStatus zps_eAplAfGroupDataReq(void *pvApl, PDUM_thAPduInstance hAPduInst, uint32 u32ClId_SrcEp, uint16 u16DstGroupAddr, uint16 u16SecMd_Radius, uint8 *pu8SeqNum);
PUBLIC ZPS_teStatus zps_eAplAfBroadcastDataReq(void *pvApl, PDUM_thAPduInstance hAPduInst, uint32 u32ClId_DstEp_SrcEp, ZPS_teAplAfBroadcastMode eBroadcastMode, uint16 u16SecMd_Radius, uint8 *pu8SeqNum);
PUBLIC ZPS_teStatus zps_eAplAfBoundDataReq(void *pvApl, PDUM_thAPduInstance hAPduInst, uint32 u32ClId_SrcEp, uint16 u16SecMd_Radius, uint8* pu8SeqNum);
PUBLIC ZPS_teStatus zps_eAplAfBoundAckDataReq(void *pvApl, PDUM_thAPduInstance hAPduInst, uint32 u32ClId_SrcEp, uint16 u16SecMd_Radius, uint8* pu8SeqNum);
PUBLIC ZPS_teStatus zps_eAplAfInterPanDataReq(void *pvApl,PDUM_thAPduInstance hAPduInst,uint32 u32ClId_ProfId,ZPS_tsInterPanAddress *psDstAddr, uint8 u8Handle);
PUBLIC ZPS_teStatus zps_eAplAfApsdeDataReq(void *pvApl, PDUM_thAPduInstance hAPduInst, ZPS_tsAfProfileDataReq* psProfileDataReq, uint8 *pu8SeqNum);
PUBLIC void ZPS_eAplZdoRegisterZdoLeaveActionCallback(void* fnPtr);
PUBLIC void zps_vAfInterPanInit(void *pvApl);
PUBLIC void ZPS_vZgpInitGpTxQueue(void);
PUBLIC void ZPS_vZgpInitGpSecurityTable(void);
PUBLIC void zps_vRegisterGreenPower(void *pvApl);
PUBLIC void zps_vSetIgnoreProfileCheck(void);
PUBLIC ZPS_teStatus zps_ePurgeBindTable(void *pvApl);
PUBLIC void zps_vPurgeAddressMap(void* pvApl);
PUBLIC bool_t ZPS_sZgpAddDeviceSecurity(uint32 u32ApplicationId, ZPS_tsZgpGpstEntry *psEntry);
PUBLIC void ZPS_vRegisterSecRequestResponseCallback(void* pFn);
PUBLIC void ZPS_vZgpTransformKey(ZPS_teZgpKeyType eKeyType, uint8 u8Applicationid, uint32 u32Srcid, uint64 u64MacAddress, AESSW_Block_u *puInKey,AESSW_Block_u *puOutKey);
PUBLIC ZPS_teStatus zps_vDStub_DataReq(ZPS_tsZgpGreenPowerReq *psDataReq,PDUM_thAPduInstance hAPduInst,uint8 u8Actions,uint8 u8CommandId);
PUBLIC ZPS_tsZgpGpstEntry* ZPS_psZgpFindGpstEntry(uint32 u32ApplicationId,ZPS_tuZgpGreenPowerId uGreenPowerId, uint8* pu8Index);
PUBLIC uint8 u8ZgpCCMStarEncrypt(uint8 *pu8Payload,
        uint8 u8PayloadLen,
        uint8 u8ApplicationId,
        uint16 u16NwkHdr,
        ZPS_tsZgpGpstEntry* psSec,
        uint16 u16Panid,
        uint16 u16DstAddr);

PUBLIC uint8 u8ZgpCCMStarDecrypt(
        AESSW_Block_u *puSecurityKey,
        uint8 *pu8Payload,
        uint8 u8PayloadLen,
        uint8 u8NwkHdr,
        uint8         u8ExtNwkHdr,
        uint8 u8SecurityLevel,
        uint8 u8ApplicationId,
        uint32 u32SecurityFrameCounter,
        ZPS_tuZgpGreenPowerId uGpId,
        uint16 u16Panid,
        uint16 u16DstAddr,
        uint32 u32Mic);
PUBLIC  ZPS_teStatus zps_eAplAfBoundDataReqNonBlocking( void                  *pvApl,
                                               PDUM_thAPduInstance    hAPduInst,
                                               uint32                 u32ClId_SrcEp,
                                               uint16                 u16SecMd_Radius,
                                               bool                   bAckReq );
PUBLIC void zps_vSaveAllZpsRecords(void *pvApl);
PUBLIC bool_t ZPS_bIsLinkKeyPresent(uint64 u64IeeeAddress);

PUBLIC void vWrite16Nbo(uint16 u16Word, uint8 *pu8Payload);
PUBLIC void vWrite32Nbo(uint32 u32Word, uint8 *pu8Payload);
PUBLIC void vWrite64Nbo(uint64 u64dWord, uint8 *pu8Payload);

PUBLIC uint16 u16Read16Nbo(uint8 *pu8Payload);

PUBLIC void ZPS_vAplZdoRegisterProfileCallback(void* fnPtr);
PUBLIC void ZPS_vAplZdoRegisterInterPanFilter(void* fnPtr);
PUBLIC void ZPS_vSetOrphanUpdateDisable ( bool_t bEnableOverride );
PUBLIC void ZPS_vAplAfEnableMcpsFilter ( bool_t bMcpsFilterEnable, uint8 u8ZpsDefaultFilterValue);
PUBLIC void ZPS_vRunningCRC32 ( uint8    u8Byte, uint32 *pu32Result );
PUBLIC void ZPS_vFinalCrc32 (uint32 *pu32Result);
PUBLIC void ZPS_vRemoveMacTableEntry(uint64 u64MacAddress);
PUBLIC ZPS_tsAplAfNodeDescriptor * zps_psGetLocalNodeDescriptor (void *pvApl);
PUBLIC ZPS_tsAplAfSimpleDescriptor* zps_psGetSimpleDescriptor (void *pvApl, uint8 u8Index);
PUBLIC uint8 zps_u8GetLocalScanDuration (void *pvApl);
PUBLIC ZPS_tsAplAfNodePowerDescriptor* zps_psGetLocalPowerDescriptor (void *pvApl);
PUBLIC void zps_vSetLocalPollInterval (void *pvApl, uint16 u16PollInterval);
PUBLIC void zps_vSetLocalMaxNumPollFailures (void *pvApl, uint16 u8PollFailure);
PUBLIC void zps_vSetLocalRxOnWhenIdle (void *pvApl, bool bSet);
PUBLIC void zps_vSetLocalScanDuration (void *pvApl, uint8 u8ScanDuration);
/****************************************************************************/
/***        In-line Functions                                            ***/
/****************************************************************************/

#ifndef ZPS_APL_OPT_MULTIPLE_INSTANCES

ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfApsdeDataReq(PDUM_thAPduInstance hAPduInst, ZPS_tsAfProfileDataReq* psProfileDataReq, uint8 *pu8SeqNum) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfApsdeDataReq(PDUM_thAPduInstance hAPduInst, ZPS_tsAfProfileDataReq* psProfileDataReq, uint8 *pu8SeqNum)
{
    return zps_eAplAfApsdeDataReq(ZPS_pvAplZdoGetAplHandle(), hAPduInst, psProfileDataReq, pu8SeqNum);
}

ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfSetEndpointState(uint8 u8Endpoint, bool bEnabled) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfSetEndpointState(uint8 u8Endpoint, bool bEnabled)
{
    return zps_eAplAfSetEndpointState(ZPS_pvAplZdoGetAplHandle(), u8Endpoint, bEnabled);
}

ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfGetEndpointState(uint8 u8Endpoint, bool *pbEnabled ) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfGetEndpointState(uint8 u8Endpoint, bool *pbEnabled )
{
    return zps_eAplAfGetEndpointState(ZPS_pvAplZdoGetAplHandle(), u8Endpoint, pbEnabled);
}

ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfSetEndpointDiscovery(uint8 u8Endpoint, uint16 u16ClusterId, bool bOutput, bool bDiscoverable) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfSetEndpointDiscovery(uint8 u8Endpoint, uint16 u16ClusterId, bool bOutput, bool bDiscoverable)
{
    return zps_eAplAfSetEndpointDiscovery(ZPS_pvAplZdoGetAplHandle(), u8Endpoint, u16ClusterId, bOutput, bDiscoverable);
}

ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfGetEndpointDiscovery(uint8 u8Endpoint, uint16 u16ClusterId, bool bOutput, bool_t *pbDiscoverable) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfGetEndpointDiscovery(uint8 u8Endpoint, uint16 u16ClusterId, bool bOutput, bool_t *pbDiscoverable)
{
    return zps_eAplAfGetEndpointDiscovery(ZPS_pvAplZdoGetAplHandle(), u8Endpoint, u16ClusterId, bOutput, pbDiscoverable);
}

ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfGetNodeDescriptor(ZPS_tsAplAfNodeDescriptor *psDesc) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfGetNodeDescriptor(ZPS_tsAplAfNodeDescriptor *psDesc)
{
    return zps_eAplAfGetNodeDescriptor(ZPS_pvAplZdoGetAplHandle(), psDesc);
}

ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfGetNodePowerDescriptor(ZPS_tsAplAfNodePowerDescriptor *psDesc) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfGetNodePowerDescriptor(ZPS_tsAplAfNodePowerDescriptor *psDesc)
{
    return zps_eAplAfGetNodePowerDescriptor(ZPS_pvAplZdoGetAplHandle(), psDesc);
}

ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfGetSimpleDescriptor(uint8 u8Endpoint, ZPS_tsAplAfSimpleDescriptor *psDesc) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfGetSimpleDescriptor(uint8 u8Endpoint, ZPS_tsAplAfSimpleDescriptor *psDesc)
{
    return zps_eAplAfGetSimpleDescriptor(ZPS_pvAplZdoGetAplHandle(), u8Endpoint, psDesc);
}

ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfUnicastDataReq(PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint8 u8SrcEndpoint, uint8 u8DstEndpoint, uint16 u16DestAddr, ZPS_teAplAfSecurityMode eSecurityMode, uint8 u8Radius, uint8 *pu8SeqNum) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfUnicastDataReq(PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint8 u8SrcEndpoint, uint8 u8DstEndpoint, uint16 u16DestAddr, ZPS_teAplAfSecurityMode eSecurityMode, uint8 u8Radius, uint8 *pu8SeqNum)
{
    return zps_eAplAfUnicastDataReq(ZPS_pvAplZdoGetAplHandle(), hAPduInst, (u16ClusterId << 16) | (u8DstEndpoint << 8) | u8SrcEndpoint, u16DestAddr, (eSecurityMode << 8) | u8Radius, pu8SeqNum);
}

ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfUnicastIeeeDataReq(PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint8 u8SrcEndpoint, uint8 u8DstEndpoint, uint64 u64DestAddr, ZPS_teAplAfSecurityMode eSecurityMode, uint8 u8Radius, uint8 *pu8SeqNum) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfUnicastIeeeDataReq(PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint8 u8SrcEndpoint, uint8 u8DstEndpoint, uint64 u64DestAddr, ZPS_teAplAfSecurityMode eSecurityMode, uint8 u8Radius, uint8 *pu8SeqNum)
{
    return zps_eAplAfUnicastIeeeDataReq(ZPS_pvAplZdoGetAplHandle(), hAPduInst, (u16ClusterId << 16) | (u8DstEndpoint << 8) | u8SrcEndpoint, &u64DestAddr,  (eSecurityMode << 8) | u8Radius, pu8SeqNum);
}

/* PR #236 http://trac/Zigbee-PRO/ticket/236 - corrected parameter order */
ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfUnicastAckDataReq(PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint8 u8SrcEndpoint, uint8 u8DstEndpoint, uint16 u16DestAddr, ZPS_teAplAfSecurityMode eSecurityMode, uint8 u8Radius, uint8 *pu8SeqNum) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfUnicastAckDataReq(PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint8 u8SrcEndpoint, uint8 u8DstEndpoint, uint16 u16DestAddr, ZPS_teAplAfSecurityMode eSecurityMode, uint8 u8Radius, uint8 *pu8SeqNum)
{
    return zps_eAplAfUnicastAckDataReq(ZPS_pvAplZdoGetAplHandle(), hAPduInst, (u16ClusterId << 16) | (u8DstEndpoint << 8) | u8SrcEndpoint, u16DestAddr, (eSecurityMode << 8) | u8Radius, pu8SeqNum);
}

ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfUnicastIeeeAckDataReq(PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint8 u8SrcEndpoint, uint8 u8DstEndpoint, uint64 u64DestAddr, ZPS_teAplAfSecurityMode eSecurityMode, uint8 u8Radius, uint8 *pu8SeqNum) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfUnicastIeeeAckDataReq(PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint8 u8SrcEndpoint, uint8 u8DstEndpoint, uint64 u64DestAddr, ZPS_teAplAfSecurityMode eSecurityMode, uint8 u8Radius, uint8 *pu8SeqNum)
{
    return zps_eAplAfUnicastIeeeAckDataReq(ZPS_pvAplZdoGetAplHandle(), hAPduInst, (u16ClusterId << 16) | (u8DstEndpoint << 8) | u8SrcEndpoint, &u64DestAddr, (eSecurityMode << 8) | u8Radius, pu8SeqNum);
}

ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfGroupDataReq(PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint8 u8SrcEndpoint, uint16 u16DstGroupAddr, ZPS_teAplAfSecurityMode eSecurityMode, uint8 u8Radius, uint8 *pu8SeqNum) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfGroupDataReq(PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint8 u8SrcEndpoint, uint16 u16DstGroupAddr, ZPS_teAplAfSecurityMode eSecurityMode, uint8 u8Radius, uint8 *pu8SeqNum)
{
    return zps_eAplAfGroupDataReq(ZPS_pvAplZdoGetAplHandle(), hAPduInst, (u16ClusterId << 16) | u8SrcEndpoint,  u16DstGroupAddr, (eSecurityMode << 8) | u8Radius, pu8SeqNum);
}

ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfBroadcastDataReq(PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint8 u8SrcEndpoint, uint8 u8DstEndpoint, ZPS_teAplAfBroadcastMode eBroadcastMode, ZPS_teAplAfSecurityMode eSecurityMode, uint8 u8Radius, uint8 *pu8SeqNum) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfBroadcastDataReq(PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint8 u8SrcEndpoint, uint8 u8DstEndpoint, ZPS_teAplAfBroadcastMode eBroadcastMode, ZPS_teAplAfSecurityMode eSecurityMode, uint8 u8Radius, uint8 *pu8SeqNum)
{
    return zps_eAplAfBroadcastDataReq(ZPS_pvAplZdoGetAplHandle(), hAPduInst, (u16ClusterId << 16) | (u8DstEndpoint << 8) | u8SrcEndpoint, eBroadcastMode, (eSecurityMode << 8) | u8Radius, pu8SeqNum);
}

ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfBoundDataReq(PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint8 u8SrcEndpoint, ZPS_teAplAfSecurityMode eSecurityMode, uint8 u8Radius, uint8* pu8SeqNum) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfBoundDataReq(PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint8 u8SrcEndpoint, ZPS_teAplAfSecurityMode eSecurityMode, uint8 u8Radius, uint8* pu8SeqNum)
{
    return zps_eAplAfBoundDataReq(ZPS_pvAplZdoGetAplHandle(), hAPduInst, (u16ClusterId << 16) | u8SrcEndpoint, (eSecurityMode << 8) | u8Radius, pu8SeqNum);
}

ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfBoundAckDataReq(PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint8 u8SrcEndpoint, ZPS_teAplAfSecurityMode eSecurityMode, uint8 u8Radius, uint8* pu8SeqNum) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfBoundAckDataReq(PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint8 u8SrcEndpoint, ZPS_teAplAfSecurityMode eSecurityMode, uint8 u8Radius, uint8* pu8SeqNum)
{
    return zps_eAplAfBoundAckDataReq(ZPS_pvAplZdoGetAplHandle(), hAPduInst, (u16ClusterId << 16) | u8SrcEndpoint, (eSecurityMode << 8) | u8Radius, pu8SeqNum);
}

ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfInterPanDataReq(PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint16 u16ProfileId,
                                        ZPS_tsInterPanAddress *psDstAddr, uint8 u8Handle) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfInterPanDataReq(PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint16 u16ProfileId, ZPS_tsInterPanAddress *psDstAddr, uint8 u8Handle)
{
    return zps_eAplAfInterPanDataReq(ZPS_pvAplZdoGetAplHandle(),
                                     hAPduInst,
                                     (u16ClusterId << 16) | u16ProfileId,
                                     psDstAddr,
                                     u8Handle);
}

ZPS_APL_INLINE void ZPS_vAfInterPanInit(void) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE void ZPS_vAfInterPanInit(void)
{
    zps_vAfInterPanInit(ZPS_pvAplZdoGetAplHandle());
}


ZPS_APL_INLINE void ZPS_vAfSetZgpAlias(uint16 u16AliasShortAddress, uint8 u8AliasSeq) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE void ZPS_vAfSetZgpAlias(uint16 u16AliasShortAddress, uint8 u8AliasSeq)
{
	zps_vNwkSetZgpAlias(ZPS_pvAplZdoGetNwkHandle(),u16AliasShortAddress,u8AliasSeq);
}


ZPS_APL_INLINE void ZPS_vAfZgpDeviceActive(uint16 u16Address) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE void ZPS_vAfZgpDeviceActive(uint16 u16Address)
{
	zps_vZgpDeviceActive(ZPS_pvAplZdoGetNwkHandle(),u16Address);
}

ZPS_APL_INLINE void ZPS_vRegisterGreenPower(void) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE void ZPS_vRegisterGreenPower(void)
{
	zps_vRegisterGreenPower(ZPS_pvAplZdoGetAplHandle());
}


ZPS_APL_INLINE void ZPS_vSetIgnoreProfileCheck(void) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE void ZPS_vSetIgnoreProfileCheck(void)
{
	zps_vSetIgnoreProfileCheck();
}


ZPS_APL_INLINE ZPS_teStatus ZPS_ePurgeBindTable(void) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_teStatus ZPS_ePurgeBindTable(void)
{
    return zps_ePurgeBindTable(ZPS_pvAplZdoGetAplHandle());
}

ZPS_APL_INLINE void ZPS_vPurgeAddressMap(void) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE void ZPS_vPurgeAddressMap(void)
{
    zps_vPurgeAddressMap(ZPS_pvAplZdoGetAplHandle());
}

ZPS_APL_INLINE void ZPS_vSaveAllZpsRecords(void) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE void ZPS_vSaveAllZpsRecords(void)
{
    zps_vSaveAllZpsRecords(ZPS_pvAplZdoGetAplHandle());
}

ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfBoundDataReqNonBlocking (PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint8 u8SrcEndpoint, ZPS_teAplAfSecurityMode eSecurityMode, uint8 u8Radius, bool bAck ) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfBoundDataReqNonBlocking (PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint8 u8SrcEndpoint, ZPS_teAplAfSecurityMode eSecurityMode, uint8 u8Radius, bool bAck )
{
    return zps_eAplAfBoundDataReqNonBlocking( ZPS_pvAplZdoGetAplHandle(),
                                     hAPduInst,
                                     (u16ClusterId << 16) | u8SrcEndpoint,
                                     (eSecurityMode << 8) | u8Radius,
                                     bAck );
}

ZPS_APL_INLINE ZPS_tsAplAfNodeDescriptor* ZPS_psGetLocalNodeDescriptor(void) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_tsAplAfNodeDescriptor* ZPS_psGetLocalNodeDescriptor(void)
{
    return zps_psGetLocalNodeDescriptor(ZPS_pvAplZdoGetAplHandle());
}

ZPS_APL_INLINE ZPS_tsAplAfSimpleDescriptor* ZPS_psGetSimpleDescriptor (uint8 u8Index) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_tsAplAfSimpleDescriptor* ZPS_psGetSimpleDescriptor (uint8 u8Index)
{
    return zps_psGetSimpleDescriptor(ZPS_pvAplZdoGetAplHandle(), u8Index);
}


ZPS_APL_INLINE uint8 ZPS_u8GetLocalScanDuration (void) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE uint8 ZPS_u8GetLocalScanDuration (void)
{
    return zps_u8GetLocalScanDuration(ZPS_pvAplZdoGetAplHandle());
}

ZPS_APL_INLINE ZPS_tsAplAfNodePowerDescriptor* ZPS_psGetLocalPowerDescriptor(void) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_tsAplAfNodePowerDescriptor* ZPS_psGetLocalPowerDescriptor(void)
{
    return zps_psGetLocalPowerDescriptor(ZPS_pvAplZdoGetAplHandle());
}


ZPS_APL_INLINE void ZPS_vSetLocalPollInterval(uint16 u16PollInterval) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE void ZPS_vSetLocalPollInterval(uint16 u16PollInterval)
{
    zps_vSetLocalPollInterval(ZPS_pvAplZdoGetAplHandle(), u16PollInterval);
}


ZPS_APL_INLINE void ZPS_vSetLocalMaxNumPollFailures(uint16 u8PollFailure) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE void ZPS_vSetLocalMaxNumPollFailures(uint16 u8PollFailure)
{
    zps_vSetLocalMaxNumPollFailures(ZPS_pvAplZdoGetAplHandle(), u8PollFailure);
}

ZPS_APL_INLINE void ZPS_vSetLocalRxOnWhenIdle(bool bSet) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE void ZPS_vSetLocalRxOnWhenIdle(bool bSet)
{
     zps_vSetLocalRxOnWhenIdle(ZPS_pvAplZdoGetAplHandle(),bSet);
}

ZPS_APL_INLINE void ZPS_vSetLocalScanDuration(uint8 u8ScanDuration) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE void ZPS_vSetLocalScanDuration(uint8 u8ScanDuration)
{
    zps_vSetLocalScanDuration(ZPS_pvAplZdoGetAplHandle(),u8ScanDuration);
}
#else

ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfSetEndpointState(void *pvApl, uint8 u8Endpoint, bool bEnabled) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfSetEndpointState(void *pvApl, uint8 u8Endpoint, bool bEnabled)
{
    return zps_eAplAfSetEndpointState(pvApl, u8Endpoint, bEnabled);
}

ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfGetEndpointState(void *pvApl, uint8 u8Endpoint, bool *pbEnabled ) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfGetEndpointState(void *pvApl, uint8 u8Endpoint, bool *pbEnabled )
{
    return zps_eAplAfGetEndpointState(pvApl, u8Endpoint, pbEnabled);
}

ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfSetEndpointDiscovery(void *pvApl, uint8 u8Endpoint, uint16 u16ClusterId, bool bOutput, bool bDiscoverable) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfSetEndpointDiscovery(void *pvApl, uint8 u8Endpoint, uint16 u16ClusterId, bool bOutput, bool bDiscoverable)
{
    return zps_eAplAfSetEndpointDiscovery(pvApl, u8Endpoint, u16ClusterId, bOutput, bDiscoverable);
}

ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfGetEndpointDiscovery(void *pvApl, uint8 u8Endpoint, uint16 u16ClusterId, bool bOutput, bool_t *pbDiscoverable) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfGetEndpointDiscovery(void *pvApl, uint8 u8Endpoint, uint16 u16ClusterId, bool bOutput, bool_t *pbDiscoverable)
{
    return zps_eAplAfGetEndpointDiscovery(pvApl, u8Endpoint, u16ClusterId, bOutput, pbDiscoverable);
}

ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfGetNodeDescriptor(void *pvApl, ZPS_tsAplAfNodeDescriptor *psDesc) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfGetNodeDescriptor(void *pvApl, ZPS_tsAplAfNodeDescriptor *psDesc)
{
    return zps_eAplAfGetNodeDescriptor(pvApl, psDesc);
}

ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfGetNodePowerDescriptor(void *pvApl, ZPS_tsAplAfNodePowerDescriptor *psDesc) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfGetNodePowerDescriptor(void *pvApl, ZPS_tsAplAfNodePowerDescriptor *psDesc)
{
    return zps_eAplAfGetNodePowerDescriptor(pvApl, psDesc);
}


ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfGetSimpleDescriptor(void *pvApl, uint8 u8Endpoint, ZPS_tsAplAfSimpleDescriptor *psDesc) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfGetSimpleDescriptor(void *pvApl, uint8 u8Endpoint, ZPS_tsAplAfSimpleDescriptor *psDesc)
{
    return zps_eAplAfGetSimpleDescriptor(pvApl, u8Endpoint, psDesc);
}

ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfUnicastDataReq(void *pvApl, PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint8 u8SrcEndpoint, uint8 u8DstEndpoint, uint16 u16DestAddr, ZPS_teAplAfSecurityMode eSecurityMode, uint8 u8Radius, uint8 *pu8SeqNum) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfUnicastDataReq(void *pvApl, PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint8 u8SrcEndpoint, uint8 u8DstEndpoint, uint16 u16DestAddr, ZPS_teAplAfSecurityMode eSecurityMode, uint8 u8Radius, uint8 *pu8SeqNum)
{
    return zps_eAplAfUnicastDataReq(pvApl, hAPduInst, (u16ClusterId << 16) | (u8DstEndpoint << 8) | u8SrcEndpoint, u16DestAddr, (eSecurityMode << 8) | u8Radius, pu8SeqNum);
}

ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfUnicastIeeeDataReq(void *pvApl, PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint8 u8SrcEndpoint, uint8 u8DstEndpoint, uint64 u64DestAddr, ZPS_teAplAfSecurityMode eSecurityMode, uint8 u8Radius, uint8 *pu8SeqNum) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfUnicastIeeeDataReq(void *pvApl, PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint8 u8SrcEndpoint, uint8 u8DstEndpoint, uint64 u64DestAddr, ZPS_teAplAfSecurityMode eSecurityMode, uint8 u8Radius, uint8 *pu8SeqNum)
{
    return zps_eAplAfUnicastIeeeDataReq(pvApl, hAPduInst, (u16ClusterId << 16) | (u8DstEndpoint << 8) | u8SrcEndpoint, &u64DestAddr,  (eSecurityMode << 8) | u8Radius, pu8SeqNum);
}

ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfUnicastAckDataReq(void *pvApl, PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint8 u8SrcEndpoint, uint8 u8DstEndpoint, uint16 u16DestAddr, ZPS_teAplAfSecurityMode eSecurityMode, uint8 u8Radius, uint8 *pu8SeqNum) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfUnicastAckDataReq(void *pvApl, PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint8 u8SrcEndpoint, uint8 u8DstEndpoint, uint16 u16DestAddr, ZPS_teAplAfSecurityMode eSecurityMode, uint8 u8Radius, uint8 *pu8SeqNum)
{
    return zps_eAplAfUnicastAckDataReq(pvApl, hAPduInst, (u16ClusterId << 16) | (u8DstEndpoint << 8) | u8SrcEndpoint, u16DestAddr, (eSecurityMode << 8) | u8Radius, pu8SeqNum);
}

ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfUnicastIeeeAckDataReq(void *pvApl, PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint8 u8SrcEndpoint, uint8 u8DstEndpoint, uint64 u64DestAddr, ZPS_teAplAfSecurityMode eSecurityMode, uint8 u8Radius, uint8 *pu8SeqNum) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfUnicastIeeeAckDataReq(void *pvApl, PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint8 u8SrcEndpoint, uint8 u8DstEndpoint, uint64 u64DestAddr, ZPS_teAplAfSecurityMode eSecurityMode, uint8 u8Radius, uint8 *pu8SeqNum)
{
    return zps_eAplAfUnicastIeeeAckDataReq(pvApl, hAPduInst, (u16ClusterId << 16) | (u8DstEndpoint << 8) | u8SrcEndpoint, &u64DestAddr, (eSecurityMode << 8) | u8Radius, pu8SeqNum);
}

ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfGroupDataReq(void *pvApl, PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint8 u8SrcEndpoint, uint16 u16DstGroupAddr, ZPS_teAplAfSecurityMode eSecurityMode, uint8 u8Radius, uint8 *pu8SeqNum) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfGroupDataReq(void *pvApl, PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint8 u8SrcEndpoint, uint16 u16DstGroupAddr, ZPS_teAplAfSecurityMode eSecurityMode, uint8 u8Radius, uint8 *pu8SeqNum)
{
    return zps_eAplAfGroupDataReq(pvApl, hAPduInst, (u16ClusterId << 16) | u8SrcEndpoint,  u16DstGroupAddr, (eSecurityMode << 8) | u8Radius, pu8SeqNum);
}

ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfBroadcastDataReq(void *pvApl, PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint8 u8SrcEndpoint, uint8 u8DstEndpoint, ZPS_teAplAfBroadcastMode eBroadcastMode, ZPS_teAplAfSecurityMode eSecurityMode, uint8 u8Radius, uint8 *pu8SeqNum) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfBroadcastDataReq(void *pvApl, PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint8 u8SrcEndpoint, uint8 u8DstEndpoint, ZPS_teAplAfBroadcastMode eBroadcastMode, ZPS_teAplAfSecurityMode eSecurityMode, uint8 u8Radius, uint8 *pu8SeqNum)
{
    return zps_eAplAfBroadcastDataReq(pvApl, hAPduInst, (u16ClusterId << 16) | (u8DstEndpoint << 8) | u8SrcEndpoint, eBroadcastMode, (eSecurityMode << 8) | u8Radius, pu8SeqNum);
}

ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfBoundDataReq(void *pvApl, PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint8 u8SrcEndpoint, ZPS_teAplAfSecurityMode eSecurityMode, uint8 u8Radius, uint8* pu8SeqNum) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfBoundDataReq(void *pvApl, PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint8 u8SrcEndpoint, ZPS_teAplAfSecurityMode eSecurityMode, uint8 u8Radius, uint8* pu8SeqNum)
{
    return zps_eAplAfBoundDataReq(pvApl, hAPduInst, (u16ClusterId << 16) | u8SrcEndpoint, (eSecurityMode << 8) | u8Radius, pu8SeqNum);
}

ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfBoundAckDataReq(void *pvApl, PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint8 u8SrcEndpoint, ZPS_teAplAfSecurityMode eSecurityMode, uint8 u8Radius, uint8* pu8SeqNum) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE ZPS_teStatus ZPS_eAplAfBoundAckDataReq(void *pvApl, PDUM_thAPduInstance hAPduInst, uint16 u16ClusterId, uint8 u8SrcEndpoint, ZPS_teAplAfSecurityMode eSecurityMode, uint8 u8Radius, uint8* pu8SeqNum)
{
    return zps_eAplAfBoundAckDataReq(pvApl, hAPduInst, (u16ClusterId << 16) | u8SrcEndpoint, (eSecurityMode << 8) | u8Radius, pu8SeqNum);
}
ZPS_APL_INLINE void ZPS_vAfInterPanInit(void *pvApl) ZPS_APL_ALWAYS_INLINE;
ZPS_APL_INLINE void ZPS_vAfInterPanInit(void *pvApl)
{
    zps_vAfInterPanInit(pvApl);
}
#endif

/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#endif /*ZPS_APL_AF_H_*/

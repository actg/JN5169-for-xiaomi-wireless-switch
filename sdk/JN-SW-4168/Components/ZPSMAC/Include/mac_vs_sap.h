/*****************************************************************************
 *
 * MODULE:          Zigbee Protocol Stack MAC shim layer
 *
 * COMPONENT:       mac_vs_sap.h
 *
 * AUTHOR:          RCC
 *
 * DESCRIPTION:     MAC shim layer to provide PDU manager i/f to NWK layer
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/Zigbee%20Protocol%20Stack/Modules/MAC/Branches/ZBPRO_R20_v1.1/Include/mac_vs_sap.h $
 *
 * $Revision: 81770 $
 *
 * $LastChangedBy: nxp29741 $
 *
 * $LastChangedDate: 2016-07-22 15:34:54 +0100 (Fri, 22 Jul 2016) $
 *
 * $Id: mac_vs_sap.h 81770 2016-07-22 14:34:54Z nxp29741 $
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

/**
 * @defgroup g_mac_vs_data MAC layer Service Access Point (SAP)
 */

#ifndef _mac_vs_data_h_
#define _mac_vs_data_h_

#ifdef __cplusplus
extern "C" {
#endif

/***********************/
/**** INCLUDE FILES ****/
/***********************/

#include "jendefs.h"
#include <os.h>
#include <pdum_nwk.h>
#include "mac_sap.h"
#include "mac_pib.h"
#include "AppApi.h"
#include "tsv_pub.h"
/************************/
/**** MACROS/DEFINES ****/
/************************/

#define MAC_MCPS_VS_TYPE_OFFSET 0x80

/**************************/
/**** TYPE DEFINITIONS ****/
/**************************/

/**********************/
/**** MCPS Request ****/
/**********************/

/**
 * @defgroup g_mac_sap_mcps_req MCPS Request objects
 * @ingroup g_mac_sap_mcps
 *
 * These are passed in a call to MAC_vHandleMcpsReqRsp.
 * Confirms to a Request will either be passed back synchronously on the function return,
 * or a special 'deferred' confirm will come back asynchronously via the
 * Deferred Confirm/Indication callback.
 * Responses have no effective confirmation of sending as they are in response to
 * an Indication; this will be indicated in the synchronous Confirm passed back.
 */

/**
 * @defgroup g_mac_sap_mcps_req_15_4 MCPS Request 802.15.4 specification parameters
 * @ingroup g_mac_sap_mcps_req
 *
 * @{
 */

/**
 * @brief Structure for MCPS-DATA.request
 *
 * Data transmit request. Use type MAC_MCPS_REQ_DATA
 */
typedef struct
{
    MAC_Addr_s  sSrcAddr;    /**< Source address */
    MAC_Addr_s  sDstAddr;    /**< Destination address */
    uint8       u8TxOptions; /**< Transmit options */
    uint8       u8Handle;    /**< MAC handle */
    uint8       u8Free;      /**< Whether NPDU is freed or not */
    PDUM_thNPdu hNPdu;       /**< NPDU handle */
} MAC_tsMcpsVsReqData;

/**
 * @brief Structure for MCPS-PURGE.request
 *
 * Purge request. Use type MAC_MCPS_REQ_PURGE
 */
typedef struct
{
    uint8 u8Handle;    /**< Handle of request to purge from queue */
} MAC_tsMcpsVsReqPurge;

/* @} */

/**********************/
/**** MCPS Confirm ****/
/**********************/

/**
 * @defgroup g_mac_sap_mcps_cfm MCPS Confirm objects
 * @ingroup g_mac_sap_mcps
 *
 * These come back synchronously as a returned parameter in the Request/Response call.
 * They can also be deferred and asynchronously posted via the Deferred Confirm/Indication callback.
 */

/**
 * @defgroup g_mac_sap_mcps_cfm_15_4 MCPS Confirm 802.15.4 specification parameters
 * @ingroup g_mac_sap_mcps_cfm
 *
 * @{
 */

/**
 * @brief Structure for MCPS-DATA.confirm
 *
 * Data transmit confirm. Use type MAC_MCPS_CFM_DATA
 */
typedef struct
{
    uint8 u8Status; /**< Status of request @sa MAC_Enum_e */
    uint8 u8Handle; /**< Handle matching associated request */
} MAC_tsMcpsVsCfmData;

/**
 * @brief Structure for MCPS-PURGE.confirm
 *
 * Data transmit confirm. Use type MAC_MCPS_CFM_PURGE
 */
typedef struct
{
    uint8 u8Status; /**< Status of request @sa MAC_Enum_e */
    uint8 u8Handle; /**< Handle matching associated request */
} MAC_tsMcpsVsCfmPurge;

/* @} */

/*************************/
/**** MCPS Indication ****/
/*************************/

/**
 * @defgroup g_mac_sap_mcps_ind MCPS Indication Object
 * @ingroup g_mac_sap_mcps
 *
 * These are sent asynchronously via the registered Deferred Confirm/Indication callback
 */

/**
 * @defgroup g_mac_sap_mcps_ind_15_4 MCPS Indication 802.15.4 specification parameters
 * @ingroup g_mac_sap_mcps_ind
 *
 * @{
 */

/**
 * @brief Structure for MCPS-DATA.indication
 *
 * Data received indication. Uses type MAC_MCPS_IND_DATA
 */
typedef struct
{
    MAC_Addr_s  sSrcAddr;       /**< Source address */
    MAC_Addr_s  sDstAddr;       /**< Destination address */
    uint8       u8LinkQuality;  /**< Link quality of received frame */
    uint8       u8SecurityUse;  /**< True if security was used */
    uint8       u8AclEntry;     /**< Security suite used */
    uint8       u8SeqNum;       /**< sequence number */
    uint32      u32ArrivalTime; /**< Arrival time    */
    PDUM_thNPdu hNPdu;          /**< NPDU handle */
    bool_t      bFramePending;  /*Frame pending set*/
} MAC_tsMcpsVsIndData;

/* @} */

/*****************************************/
/**** MCPS Request/Response Interface ****/
/*****************************************/

/**
 * @defgroup g_mac_sap_mcps_req_rsp_if MCPS Request/Response interface
 * @ingroup g_mac_sap_mcps g_mac_VS
 *
 * The interface for the client to issue an MCPS Request or Response
 * is via a function call to MAC_vHandleMcpsReqRsp.
 * @li Request/Response parameters are passed in via psMcpsReqRsp
 * @li Synchronous Confirm parameters are passed out via psMcpsSyncCfm
 * @li Deferred Confirms are posted back asynchronously via the
 *     Deferred Confirm/Indication callback.
 * @note There are currently no MCPS Responses specified
 *
 * @{
 */

/**
 * @brief MAC MCPS Request/Response enumeration.
 *
 * Enumeration of MAC MCPS Request/Response
 * @note Must not exceed 256 entries
 */
typedef enum
{
    MAC_MCPS_VS_REQ_DATA = MAC_MCPS_VS_TYPE_OFFSET,  /**< Use with MAC_tsMcpsVsReqRsp */
    MAC_MCPS_VS_REQ_PURGE,        /**< Use with MAC_tsMcpsVsReqPurge */
} MAC_teMcpsVsReqRspType;

#define NUM_MAC_MCPS_VS_REQ 1

/**
 * @brief MCPS Request/Response Parameter union
 *
 * Union of all the possible MCPS Requests and Responses
 * @note There are no Responses currently specified
 */
typedef union
{
    MAC_tsMcpsVsReqData  sVsReqData;   /**< Data request */
    MAC_tsMcpsVsReqPurge sVsReqPurge;  /**< Purge request */
} MAC_tuMcpsVsReqRspParam;

/**
 * @brief MCPS Request/Response object
 *
 * The object passed to MAC_vHandleMcpsReqRsp containing the request/response
 */
typedef struct
{
    uint8                   u8Type;          /**< Request type (@sa MAC_teMcpsReqRspVsType) */
    uint8                   u8ParamLength;   /**< Parameter length in following union */
    uint16                  u16Pad;          /**< Padding to force alignment */
    MAC_tuMcpsVsReqRspParam uParam;          /**< Union of all possible Requests */
} MAC_tsMcpsVsReqRsp;

/**
 * @brief MCPS Synchronouse Confirm Parameter union
 *
 * Union of all the possible MCPS Synchronous Confirms
 */
typedef union
{
    MAC_tsMcpsVsCfmData  sVsCfmData;
    MAC_tsMcpsVsCfmData  sVsCfmPurge;
} MAC_tuMcpsVsSyncCfmParam;

/**
 * @brief MCPS Synchronous Confirm
 *
 * The object returned by MAC_vHandleMcpsReqRsp containing the synchronous confirm.
 * The confirm type is implied as corresponding to the request
 * @note All Confirms may also be sent asynchronously via the registered Deferred Confirm/Indication callback;
 * this is notified by returning MAC_MCPS_CFM_DEFERRED.
 */
typedef struct
{
    uint8                    u8Status;        /**< Confirm status (@sa MAC_teMcpsSyncCfmVsStatus) */
    uint8                    u8ParamLength;   /**< Parameter length in following union */
    uint16                   u16Pad;          /**< Padding to force alignment */
    MAC_tuMcpsVsSyncCfmParam uParam;          /**< Union of all possible Confirms */
} MAC_tsMcpsVsSyncCfm;

/* @} */

/****************************************************/
/**** MCPS Deferred Confirm/Indication Interface ****/
/****************************************************/

/**
 * @defgroup g_mac_sap_mcps_dcfm_ind_if MCPS Deferred Confirm/Indication Interface
 * @ingroup g_mac_sap_mcps g_mac_VS
 *
 * The interface for the client to receive an MCPS Deferred Confirm or Indication
 * is via a function callback to the function registered using MAC_vMcpsDcfmIndRegister
 *
 * @{
 */

/**
 * @brief Deferred Confirm/Indication type
 *
 * Indicates the type of deferred confirm or indication
 * @note NB Must not exceed 256 entries
 */
typedef enum
{
    MAC_MCPS_VS_DCFM_DATA = MAC_MCPS_VS_TYPE_OFFSET,
    MAC_MCPS_VS_DCFM_PURGE,
    MAC_MCPS_VS_IND_DATA
} MAC_teMcpsVsDcfmIndType;

#define NUM_MAC_MCPS_VS_DCFM_IND 3

/**
 * @brief MCPS Deferred Confirm/Indication Parameter union
 *
 * Union of all the possible MCPS Deferred Confirms or Indications
 */
typedef union
{
    MAC_tsMcpsVsCfmData  sVsDcfmData;   /**< Deferred transmit data confirm */
    MAC_tsMcpsVsCfmPurge sVsDcfmPurge;  /**< Deferred purge confirm */
    MAC_tsMcpsVsIndData  sVsIndData;    /**< Received data indication */
} MAC_tuMcpsVsDcfmIndParam;

/**
 * @brief MCPS Deferred Confirm/Indication
 *
 * The object passed in the MCPS Deferred Confirm/Indication callback
 */
typedef struct
{
    uint8                    u8Type;          /**< Indication type (@sa MAC_teMcpsVsDcfmIndType) */
    uint8                    u8ParamLength;   /**< Parameter length in following union */
    uint16                   u16Pad;          /**< Padding to force alignment */
    MAC_tuMcpsVsDcfmIndParam uParam;          /**< Union of all possible Indications */
} MAC_tsMcpsVsDcfmInd;


typedef struct
{
    tsTxFrameFormat sTxFrame;
    TSV_Timer_s sTimer;
    uint8 u8HigherLayerRetryCount;
} tsHigherLayerTxFrame;

/* @} */

/**
 * @defgroup g_mac_sap_gen Generic headers
 * @ingroup g_mac_sap
 *
 * Generic headers which abstract the parameter interfaces to the function calls.
 * The headers reflect the common structure at the head of the derived structures
 * for MLME/MCPS
 *
 * @{
 */

#define MAC_MAX_ZBP_BEACON_PAYLOAD_LEN 15

typedef struct
{
    uint8          u8Status;                /**< Status of scan request @sa MAC_Enum_e */
    uint8          u8ScanType;              /**< Scan type */
    uint8          u8ResultListSize;        /**< Size of scan results list */
    uint8          u8Pad;                   /**< Padding to show alignment */
    uint32         u32UnscannedChannels;    /**< Bitmap of unscanned channels */
    uint8          au8EnergyDetect[MAC_MAX_SCAN_CHANNELS];
} MAC_tsMlmeVsCfmScan;


typedef struct
{
    MAC_PanDescr_s   sPANdescriptor;                                      /**< PAN descriptor */
    uint8            u8BSN;                                               /**< Beacon sequence number */
    uint8            au8BeaconPayload[MAC_MAX_ZBP_BEACON_PAYLOAD_LEN];    /**< Beacon payload */
} MAC_tsMlmeVsIndBeacon;

typedef union
{
    MAC_tsMlmeVsCfmScan         sVsDcfmScan;
    MAC_MlmeCfmAssociate_s      sDcfmAssociate;
    MAC_MlmeCfmDisassociate_s   sDcfmDisassociate;
    MAC_MlmeCfmPoll_s           sDcfmPoll;
    MAC_MlmeCfmRxEnable_s       sDcfmRxEnable;
    MAC_MlmeIndAssociate_s      sIndAssociate;
    MAC_MlmeIndDisassociate_s   sIndDisassociate;
    MAC_MlmeIndGts_s            sIndGts;
    MAC_tsMlmeVsIndBeacon       sVsIndBeacon;
    MAC_MlmeIndSyncLoss_s       sIndSyncLoss;
    MAC_MlmeIndCommStatus_s     sIndCommStatus;
    MAC_MlmeIndOrphan_s         sIndOrphan;
#if defined(DEBUG) && defined(EMBEDDED)
    MAC_MlmeIndVsDebug_s        sIndVsDebug;
#endif /* defined(DEBUG) && defined(EMBEDDED) */
} MAC_tuMlmeVsDcfmIndParam;

typedef struct
{
    uint8                    u8Type;          /**< Deferred Confirm/Indication type @sa MAC_MlmeDcfmIndType_e */
    uint8                    u8ParamLength;   /**< Parameter length in following union */
    uint16                   u16Pad;          /**< Padding to force alignment */
    MAC_tuMlmeVsDcfmIndParam uParam;          /**< Union of all possible Deferred Confirms/Indications */
} MAC_tsMlmeVsDcfmInd;


/****************************/
/**** EXPORTED VARIABLES ****/
/****************************/

/****************************/
/**** EXPORTED FUNCTIONS ****/
/****************************/

PUBLIC void MAC_vSetMutex(OS_thMutex hMacMutex);
PUBLIC void MAC_vHandleMcpsVsReqRsp(
	void* pvMac,
    MAC_tsMcpsVsReqRsp *psMcpsVsReqRsp,
    MAC_tsMcpsVsSyncCfm *psMcpsVsSyncCfm);

PUBLIC void MAC_vHandleMlmeVsReqRsp(
    void* pvMac,
    MAC_MlmeReqRsp_s *psMlmeReqRsp,
    MAC_MlmeSyncCfm_s *psMlmeSyncCfm);

#ifdef JENNIC_MAC_MiniMacShim
PUBLIC void
ZPS_vMiniMacShimInit(PR_GET_BUFFER prMlmeGetBuffer,
              PR_POST_CALLBACK prMlmeCallback,
              PR_GET_BUFFER prMcpsGetBuffer,
              PR_POST_CALLBACK prMcpsCallback,
              void *pfGetVsBuffer,
              void *pfVsCallback,
              void *pvApl,
              void *pvNwk,
              OS_thMutex hMacMutex);
#else
PUBLIC void MAC_vZpsRegisterMcpsVsDcfmIndCallbacks(
    void *pvMac,
    MAC_tsMcpsVsDcfmInd * (*prGetBufCB)(void *),
    void (*prPostCB)(void *, MAC_tsMcpsVsDcfmInd *),
    void *pvParam);
#endif 

#ifdef MAC_FILTER_INCOMING_DATA
PUBLIC uint32 MAC_eMacFilterAddAccept(uint16 u16Addr, uint8 u8LinkQuality);
#endif

#ifdef __cplusplus
};
#endif

#endif /* _mac_vs_data_h_ */

/* End of file $RCSfile: mac_sap.h,v $ *******************************************/

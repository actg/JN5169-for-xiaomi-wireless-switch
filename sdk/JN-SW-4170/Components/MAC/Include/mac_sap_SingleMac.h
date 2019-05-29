/****************************************************************************
 *
 * MODULE:             ZED-MAC
 *
 * DESCRIPTION:
 * ZED 802.15.4 Media Access Controller
 * SAP interface for MLME and MCPS
 *
 ****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products [NXP Microcontrollers such as JN5148, JN5142, JN5139].
 * You, and any third parties must reproduce the copyright and warranty notice
 * and any other legend of ownership on each copy or partial copy of the
 * software.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
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
 ***************************************************************************/

/**
 * @defgroup g_mac_sap MAC layer Service Access Point (SAP)
 */

/**
 * @defgroup g_mac_sap_pib PIB parameters
 *
 * Parameters associated with setting or getting PIB values
 * @ingroup g_mac_sap
 */

/**
 * @defgroup g_mac_sap_addr Addressing parameters
 *
 * Parameters associated with addressing
 * @ingroup g_mac_sap
 */

/**
 * @defgroup g_mac_sap_pdu PDU Framing parameters
 *
 * Parameters associated with PDU framing
 * @ingroup g_mac_sap
 */

/**
 * @defgroup g_mac_sap_sec Security parameters
 *
 * Parameters associated with security
 * @ingroup g_mac_sap
 */

/**
 * @defgroup g_mac_sap_scan Scanning parameters
 *
 * Parameters associated with scanning
 * @ingroup g_mac_sap
 */

/**
 * @defgroup g_mac_sap_bcn Beacon parameters
 *
 * Parameters associated with beaconing
 * @ingroup g_mac_sap
 */

/**
 * @defgroup g_mac_sap_mlme MAC SAP sublayer management entity (MLME)
 *
 * The MLME SAP API provides calls to conforming to the MLME SAP in [1]
 * @ingroup g_mac_sap
 */

/**
 * @defgroup g_mac_sap_mcps MAC SAP common part sublayer (MCPS)
 *
 * The MCPS SAP API provides calls to conforming to the MCPS SAP in [1]
 * @ingroup g_mac_sap
 */

/**
 * @defgroup g_mac_sap_vs Vendor-specific interface
 *
 * The vendor-specific SAP API provides calls which are in addition to those specified in the 802.15.4
 * specification. They are currently handled as additions to the MLME SAP interface.
 * @ingroup g_mac_sap
 */

/**
 * @mainpage Medium Access Control Layer Service Access Point Application Programmer's Interface
 *
 * @section p_mac_sap_intro Introduction
 * The Medium Access Control (MAC) Layer Service Access Point (SAP) Application Programmer's Interface (API)
 * provides the interface to the top of the MAC layer required by higher layer in the application programming.
 * The next layer up is typically the network layer.
 *
 * @section p_mac_sap_app Application interface
 * There is an Application interface which sits on top of the MAC SAP. It wraps the
 * initialisation and baseband interrupt handling, and provides a simple call/callback API
 * for access to the MAC SAP.
 *
 * See @link g_app_sap Application interface@endlink
 *
 * @section p_mac_sap_categories Categories within MAC SAP
 * - MCPS SAP API: See @link g_mac_sap_mcps MCPS SAP pages@endlink
 * - MLME SAP API: See @link g_mac_sap_mlme MLME SAP pages@endlink
 * - Vendor-specific SAP API: See @link g_mac_sap_vs Vendor-specific pages@endlink
 * - MAC PIB Direct Access: See @link g_mac_pib PIB direct access pages@endlink
 *
 * @section p_disclaimer Disclaimer
 * This document is subject to change. Please contact NXP for more information
 */

#ifndef _mac_sap_h_
#define _mac_sap_h_

#ifdef __cplusplus
extern "C" {
#endif

/***********************/
/**** INCLUDE FILES ****/
/***********************/

#include "jendefs.h"

/************************/
/**** MACROS/DEFINES ****/
/************************/

/* Literals */

/**
 * @name PHY constants
 * @ingroup g_mac_sap
 * PHY constants 'used' by the MAC
 * @{
 */
/** Maximum PHY packet (PDU) size */
#define MAC_MAX_PHY_PKT_SIZE            127
/** PHY turnaround time */
#define MAC_PHY_TURNAROUND_TIME         12
/* @} */

/**
 * @name Address sizes
 * @ingroup g_mac_sap_addr
 * Sizes of address fields in SAP structures
 * @{
 */
/** PAN ID field size in octets */
#define MAC_PAN_ID_LEN                  2
/** Short address field size in octets */
#define MAC_SHORT_ADDR_LEN              2
/** Extended address field size in octets */
#define MAC_EXT_ADDR_LEN                8
/** Extended address field size in words (32 bit) */
#define MAC_EXT_ADDR_LEN_WORDS          2
/* @} */

/**
 * @name Frame overheads
 * @ingroup g_mac_sap_pdu
 * Header size overheads for frames
 * @{
 */
/** Minimum Data Frame overhead */
#define MAC_MIN_DATA_FRM_OVERHEAD       9
/** Maximum Data Frame overhead */
#define MAC_MAX_DATA_FRM_OVERHEAD       25
/** Minimum Beacon Frame overhead */
#define MAC_MIN_BEACON_FRM_OVERHEAD     9
/** Maximum Beacon Frame overhead */
#define MAC_MAX_BEACON_FRM_OVERHEAD     15
/* @} */

/**
 * @name Payload maxima
 * @ingroup g_mac_sap_pdu
 * Maximum size of payloads
 * @{
 */
/** Maximum Data Frame payload */
#define MAC_MAX_DATA_PAYLOAD_LEN      (MAC_MAX_PHY_PKT_SIZE - MAC_MIN_DATA_FRM_OVERHEAD)
/** Maximum Beacon Frame payload */
#define MAC_MAX_BEACON_PAYLOAD_LEN    (MAC_MAX_PHY_PKT_SIZE - MAC_MIN_BEACON_FRM_OVERHEAD)
/* @} */

/**
 * @name PIB constants
 * @ingroup g_mac_sap_pib
 * PIB constant values
 * @{
 */
/** @a aNumSuperframeSlots: Maximum number of superframe slots */
#define MAC_NUM_SUPERFRAME_SLOTS        16
/** @a aMaxBeaconOverhead: Maximum beacon overhead */
#define MAC_MAX_BEACON_OVERHEAD         75
/** @a aBaseSlotDuration */
#define MAC_BASE_SLOT_DURATION          60
/** @a aBaseSuperframeDuration */
#define MAC_BASE_SUPERFRAME_DURATION    (MAC_BASE_SLOT_DURATION * MAC_NUM_SUPERFRAME_SLOTS)
/** @a aResponseWaitTime */
#define MAC_RESPONSE_WAIT_TIME          (32 * MAC_BASE_SUPERFRAME_DURATION)
/** @a aMinLIFSPeriod: Minimum number of symbols in a LIFS period */
#define MAC_MIN_LIFS_PERIOD             40
/** @a aMinSIFSPeriod: Minimum number of symbols in a SIFS period */
#define MAC_MIN_SIFS_PERIOD             12
/** @a aMinCAPLength: Minimum CAP length */
#define MAC_MIN_CAP_LENGTH              440
/** @a aMaxFrameResponseTime: Maximum frame response time */
#define MAC_MAX_FRAME_RESPONSE_TIME     1220
/** @a aUnitBackoffPeriod: Number of symbols for CSMA/CA backoff */
#define MAC_UNIT_BACKOFF_PERIOD         20
/** @a aMaxFrameRetries: Maximum number of CSMA/CA retries */
#define MAC_MAX_FRAME_RETRIES           3
/** @a aMaxLostBeacons: Maximum number of lost beacons before sync loss */
#define MAC_MAX_LOST_BEACONS            4
/** @a aGTSDescPersistenceTime: How many beacons a GTS descriptor persists for */
#define MAC_GTS_DESC_PERSISTENCE_TIME   4
/* @} */

/**
 * @name Scan constants
 * @ingroup g_mac_sap_scan
 * Scan constant values not in PIB
 * @note MAC_MAX_SCAN_PAN_DESCRS is configurable
 * @{
 */
/** Maximum number of scan channel (2.4GHz) is 16 but for Sub Gig this needs to be extended*/
#define MAC_MAX_SCAN_CHANNELS           27
/** Maximum number of PAN descriptors in record */
#define MAC_MAX_SCAN_PAN_DESCRS         8
/* @} */

/**
 * @name Security constants
 * @ingroup g_mac_sap_sec
 * Security constant values not in PIB or compile-time configurable
 * @note MAC_MAX_ACL_ENTRIES is configurable and will determine how much memory is required.
 * @{
 */
/** Maximum security material length */
#define MAC_MAX_SECURITY_MATERIAL_LEN   26
/* @} */

/**
 * @name Vendor-specific constants
 * @ingroup g_mac_sap_vs
 * Vendor-specific constant values not defined by specification
 * @{
 */
/** Debug message maximum length */
#define MAC_VS_DEBUG_LEN                128
/* @} */

#define PHY_PIB_CHANNELS_SUPPORTED_DEF 0x07fff800UL
#define PHY_PIB_CURRENT_CHANNEL_DEF    11
#define PHY_PIB_CURRENT_CHANNEL_MIN    11
#define PHY_PIB_CURRENT_CHANNEL_MAX    26

#define PHY_PIB_TX_POWER_DEF           PHY_PIB_TX_POWER_3DB_TOLERANCE
#define PHY_PIB_TX_POWER_MIN           0
#define PHY_PIB_TX_POWER_MAX           0xbf
#define PHY_PIB_TX_POWER_MASK          0x3f
#define PHY_PIB_TX_POWER_1DB_TOLERANCE 0x00
#define PHY_PIB_TX_POWER_3DB_TOLERANCE 0x40
#define PHY_PIB_TX_POWER_6DB_TOLERANCE 0x80

#define PHY_PIB_CCA_MODE_DEF           1
#define PHY_PIB_CCA_MODE_MIN           1
#define PHY_PIB_CCA_MODE_MAX           3

/**************************/
/**** TYPE DEFINITIONS ****/
/**************************/

/****************************/
/**** General Structures ****/
/****************************/

/*Security Selection*/
typedef enum
{
    MAC_SECURITY_2003_JN5148_LEGACY, /*HW Implementation*/
    MAC_SECURITY_2003_SOFTWARE,      /*SW implementation*/
    MAC_SECURITY_2006                /*2006 Security option not supported on JN5148*/
} MAC_SecutityMode_e;


/**
 * @ingroup g_mac_sap
 * @brief MAC SAP Type.
 *
 * Enumeration of SAP type
 */
typedef enum
{
    MAC_SAP_MLME = 0,   /**< SAP Type is MLME */
    MAC_SAP_MCPS = 1,   /**< SAP Type is MCPS */
    NUM_MAC_SAP
} MAC_Sap_e;

/**
 * @ingroup g_mac_sap
 * @brief MAC Enumeration Type.
 *
 * Enumerations as defined in Table 64 (section 7.1.17) (d18)
 * @note Refer to specification for definitive definitions.
 */
typedef enum
{
    MAC_ENUM_SUCCESS = 0,             /**< Success (0x00) */
    MAC_ENUM_BEACON_LOSS = 0xE0,      /**< Beacon loss after synchronisation request (0xE0) */
    MAC_ENUM_CHANNEL_ACCESS_FAILURE,  /**< CSMA/CA channel access failure (0xE1) */
    MAC_ENUM_DENIED,                  /**< GTS request denied (0xE2) */
    MAC_ENUM_DISABLE_TRX_FAILURE,     /**< Could not disable transmit or receive (0xE3) */
    MAC_ENUM_FAILED_SECURITY_CHECK,   /**< Incoming frame failed security check (0xE4) */
    MAC_ENUM_FRAME_TOO_LONG,          /**< Frame too long after security processing to be sent (0xE5) */
    MAC_ENUM_INVALID_GTS,             /**< GTS transmission failed (0xE6) */
    MAC_ENUM_INVALID_HANDLE,          /**< Purge request failed to find entry in queue (0xE7) */
    MAC_ENUM_INVALID_PARAMETER,       /**< Out-of-range parameter in primitive (0xE8) */
    MAC_ENUM_NO_ACK,                  /**< No acknowledgement received when expected (0xE9) */
    MAC_ENUM_NO_BEACON,               /**< Scan failed to find any beacons (0xEA) */
    MAC_ENUM_NO_DATA,                 /**< No response data after a data request (0xEB) */
    MAC_ENUM_NO_SHORT_ADDRESS,        /**< No allocated short address for operation (0xEC) */
    MAC_ENUM_OUT_OF_CAP,              /**< Receiver enable request could not be executed as CAP finished (0xED) */
    MAC_ENUM_PAN_ID_CONFLICT,         /**< PAN ID conflict has been detected (0xEE) */
    MAC_ENUM_REALIGNMENT,             /**< Coordinator realignment has been received (0xEF) */
    MAC_ENUM_TRANSACTION_EXPIRED,     /**< Pending transaction has expired and data discarded (0xF0) */
    MAC_ENUM_TRANSACTION_OVERFLOW,    /**< No capacity to store transaction (0xF1) */
    MAC_ENUM_TX_ACTIVE,               /**< Receiver enable request could not be executed as in transmit state (0xF2) */
    MAC_ENUM_UNAVAILABLE_KEY,         /**< Appropriate key is not available in ACL (0xF3) */
    MAC_ENUM_UNSUPPORTED_ATTRIBUTE    /**< PIB Set/Get on unsupported attribute (0xF4) */
} MAC_Enum_e;

/**
 * @ingroup g_mac_sap_scan
 * @brief MAC MLME Scan type.
 *
 * Enumerations as defined in Table 53 (section 7.1.11.1.1) (d18)
 */
typedef enum
{
    MAC_MLME_SCAN_TYPE_ENERGY_DETECT = 0,   /**< Energy detect scan */
    MAC_MLME_SCAN_TYPE_ACTIVE = 1,          /**< Active scan */
    MAC_MLME_SCAN_TYPE_PASSIVE = 2,         /**< Passive scan */
    MAC_MLME_SCAN_TYPE_ORPHAN = 3,          /**< Orphan scan */
    NUM_MAC_MLME_SCAN_TYPE
} MAC_MlmeScanType_e;

/**
 * @ingroup g_mac_sap_mcps
 * @brief MAC MCPS transmit options type.
 *
 * Enumerations as defined in Table 27 (section 7.1.1.1.3) (d18)
 */
typedef enum
{
    MAC_TX_OPTION_ACK      = 1,             /**< Acknowledge required */
    MAC_TX_OPTION_GTS      = 2,             /**< Transmit in GTS */
    MAC_TX_OPTION_INDIRECT = 4,             /**< Transmit indirectly */
    MAC_TX_OPTION_SECURITY = 8              /**< Use security */
} MAC_TransmitOption_e;

/**
 * @ingroup g_mac_sap_pib
 * @brief MAC PIB attribute.
 *
 * Enumerations of PIB attribute as defined in Tables 71 and 72 (section 7.5) (d18)
 * @note Refer to specification for definitive definitions.
 */
typedef enum
{
    MAC_PIB_ATTR_ACK_WAIT_DURATION = 0x40,      /**< macAckWaitDuration */
    MAC_PIB_ATTR_ASSOCIATION_PERMIT,            /**< macAssociationPermit */
    MAC_PIB_ATTR_AUTO_REQUEST,                  /**< macAutoRequest */
    MAC_PIB_ATTR_BATT_LIFE_EXT,                 /**< macBattLifeExt */
    MAC_PIB_ATTR_BATT_LIFE_EXT_PERIODS,         /**< macBattLifeExtPeriods */
    MAC_PIB_ATTR_BEACON_PAYLOAD,                /**< macBeaconPayload */
    MAC_PIB_ATTR_BEACON_PAYLOAD_LENGTH,         /**< macBeaconPayloadLength */
    MAC_PIB_ATTR_BEACON_ORDER,                  /**< macBeaconOrder */
    MAC_PIB_ATTR_BEACON_TX_TIME,                /**< macBeaconTxTime */
    MAC_PIB_ATTR_BSN,                           /**< macBSN */
    MAC_PIB_ATTR_COORD_EXTENDED_ADDRESS,        /**< macCoordExtendedAddress */
    MAC_PIB_ATTR_COORD_SHORT_ADDRESS,           /**< macCoordShortAddress */
    MAC_PIB_ATTR_DSN,                           /**< macDSN */
    MAC_PIB_ATTR_GTS_PERMIT,                    /**< macGTSPermit */
    MAC_PIB_ATTR_MAX_CSMA_BACKOFFS,             /**< macMaxCSMABackoffs */
    MAC_PIB_ATTR_MIN_BE,                        /**< macMinBE */
    MAC_PIB_ATTR_PAN_ID,                        /**< macPANId */
    MAC_PIB_ATTR_PROMISCUOUS_MODE,              /**< macPromiscuousMode */
    MAC_PIB_ATTR_RX_ON_WHEN_IDLE,               /**< macRxOnWhenIdle */
    MAC_PIB_ATTR_SHORT_ADDRESS,                 /**< macShortAddress */
    MAC_PIB_ATTR_SUPERFRAME_ORDER,              /**< macSuperframeOrder */
    MAC_PIB_ATTR_TRANSACTION_PERSISTENCE_TIME,  /**< macTransactionPersistenceTime */
    /* New for TG4b */
    MAC_PIB_ATTR_MAX_FRAME_TOTAL_WAIT_TIME = 0x58,/**< macMaxTotalFrameTxTime */
    MAC_PIB_ATTR_MAX_FRAME_RETRIES  = 0x59,     /**< macMaxFrameRetries */
    MAC_PIB_ATTR_RESPONSE_WAIT_TIME = 0x5a,     /**< macResponseWaitTime */
    /* Security attributes */
    MAC_PIB_ATTR_ACL_ENTRY_DESCRIPTOR_SET = 0x70,       /**< macACLEntryDescriptorSet */
    MAC_PIB_ATTR_ACL_ENTRY_DESCRIPTOR_SET_SIZE,         /**< macACLEntryDescriptorSetSize */
    MAC_PIB_ATTR_DEFAULT_SECURITY,                      /**< macDefaultSecurity */
    MAC_PIB_ATTR_ACL_DEFAULT_SECURITY_MATERIAL_LENGTH,  /**< macACLDefaultSecurityMaterialLength */
    MAC_PIB_ATTR_DEFAULT_SECURITY_MATERIAL,             /**< macDefaultSecurityMaterial */
    MAC_PIB_ATTR_DEFAULT_SECURITY_SUITE,                /**< macDefaultSecuritySuite */
    MAC_PIB_ATTR_SECURITY_MODE,                         /**< macSecurityMode */
    NUM_MAC_ATTR_PIB                                    /**< (endstop) */
} MAC_PibAttr_e;

/*
*******************************************************************
******************** README README README *************************
*******************************************************************
Splitting the defs. like this means that GDB recognises the packing.
Please use this format throughout.
*******************************************************************
*/

/**
 * @ingroup g_mac_sap_addr
 * @brief MAC Extended Address
 *
 * Full address specification
 */
typedef struct
{
    uint32 u32L;  /**< Low word */
    uint32 u32H;  /**< High word */
} MAC_ExtAddr_s;

/**
 * @ingroup g_mac_sap_addr
 * @brief MAC Address union
 *
 * Union of the two address types
 */
typedef union
{
    uint16 u16Short;     /**< Short address */
    MAC_ExtAddr_s sExt;  /**< Extended address */
} MAC_Addr_u;

/**
 * @ingroup g_mac_sap_addr
 * @brief MAC Address
 *
 * Full address specification
 */
typedef struct
{
    uint8      u8AddrMode;  /**< Address mode */
    uint16     u16PanId;    /**< PAN ID */
    MAC_Addr_u uAddr;       /**< Address */
} MAC_Addr_s;

/**
 * @ingroup g_mac_sap_sec
 * @brief MAC ACL entry descriptor
 *
 * ACL entry as passed over MLME, as defined in table 73 (d18)
 */
typedef struct
{
    MAC_ExtAddr_s sAclExtAddr;                                              /**< Extended address */
    uint16        u16AclShortAddr;                                          /**< Short address */
    uint16        u16AclPanId;                                              /**< PAN ID */
    uint8         u8AclSecuritySuite;                                       /**< Security suite */
    uint8         u8AclSecurityMaterialLen;                                 /**< Length of security material */
    uint8         au8AclSecurityMaterial[MAC_MAX_SECURITY_MATERIAL_LEN];    /**< Security material */
} MAC_SapAclEntry_s;

/**
 * @ingroup g_mac_sap_pib
 * @brief MAC PIB union
 *
 * Union of all PIB values as defined in table 71 (d18)
 */
typedef union
{
    uint8         u8AckWaitDuration;                            /**< macAckWaitDuration */
    uint8         u8AssociationPermit;                          /**< macAssociationPermit */
    uint8         u8AutoRequest;                                /**< macAutoRequest */
    uint8         u8BattLifeExt;                                /**< macBattLifeExt */
    uint8         u8BattLifeExtPeriods;                         /**< macBattLifeExtPeriods */
    uint8         au8BeaconPayload[MAC_MAX_BEACON_PAYLOAD_LEN]; /**< macBeaconPayload */
    uint8         u8BeaconPayloadLength;                        /**< macBeaconPayloadLength */
    uint8         u8BeaconOrder;                                /**< macBeaconOrder */
    uint32        u32BeaconTxTime;                              /**< macBeaconTxTime */
    uint8         u8Bsn;                                        /**< macBSN */
    MAC_ExtAddr_s sCoordExtAddr;                                /**< macCoordExtendedAddress */
    uint16        u16CoordShortAddr;                            /**< macCoordShortAddress */
    uint8         u8Dsn;                                        /**< macDSN */
    uint8         u8GtsPermit;                                  /**< macGTSPermit */
    uint8         u8MaxCsmaBackoffs;                            /**< macMaxCSMABackoffs */
    uint8         u8MinBe;                                      /**< macMinBE */
    uint16        u16PanId;                                     /**< macPANId */
    uint8         u8PromiscuousMode;                            /**< macPromiscuousMode */
    uint8         u8RxOnWhenIdle;                               /**< macRxOnWhenIdle */
    uint16        u16ShortAddr;                                 /**< macShortAddress */
    uint8         u8SuperframeOrder;                            /**< macSuperframeOrder */
    uint16        u16TransactionPersistenceTime;                /**< macTransactionPersistenceTime */
    /* Security attributes, as defined in table 72 (d18) */
    MAC_SapAclEntry_s sAclEntry;                                                    /**< ACL Entry table */
    uint8             u8AclEntryDescriptorSetSize;                                  /**< macACLEntryDescriptorSetSize */
    uint8             u8DefaultSecurity;                                            /**< macDefaultSecurity */
    uint8             u8AclDefaultSecurityMaterialLength;                           /**< macACLDefaultSecurityMaterialLength */
    uint8             au8DefaultSecurityMaterial[MAC_MAX_SECURITY_MATERIAL_LEN];    /**< macDefaultSecurityMaterial */
    uint8             u8DefaultSecuritySuite;                                       /**< macDefaultSecuritySuite */
    uint8             u8SecurityMode;                                               /**< macSecurityMode */
    /* New for TG4b */
    uint16 u16MaxTotalFrameTxTime;  /**< macMaxTotalFrameTxTime */
    uint8  u8ResponseWaitTime;      /**< macResponseWaitTime */

    uint8        u8MaxFrameRetries; /**<macMaxFrameRetries */
} MAC_Pib_u;

/**
 * @ingroup g_mac_sap_bcn
 * @brief PAN Descriptor
 *
 * PAN Descriptor as defined in table 41 (d18).
 * Indicates PAN parameters to a device obtained from a Beacon.
 */
typedef struct
{
    MAC_Addr_s sCoord;              /**< Coordinator address */
    uint8      u8LogicalChan;       /**< Logical channel */
    uint8      u8GtsPermit;         /**< True if beacon is from PAN coordinator which accepts GTS requests */
    uint8      u8LinkQuality;       /**< Link quality of the received beacon */
    uint8      u8SecurityUse;       /**< True if beacon received was secure */
    uint8      u8AclEntry;          /**< Security mode used in ACL entry */
    uint8      u8SecurityFailure;   /**< True if there was an error in security processing */
    uint16     u16SuperframeSpec;   /**< Superframe specification */
    uint32     u32TimeStamp;        /**< Timestamp of the received beacon */
} MAC_PanDescr_s;

/**********************/
/**** MLME Request ****/
/**********************/

/**
 * @defgroup g_mac_sap_mlme_req MLME Request objects
 * @ingroup g_mac_sap_mlme
 *
 * These are passed in a call to MAC_vHandleMlmeReqRsp.
 * Confirms to a Request will either be passed back synchronously on the function return,
 * or a special 'deferred' confirm will come back asynchronously via the
 * Deferred Confirm/Indication callback.
 * Responses have no effective confirmation of sending as they are in response to
 * an Indication; this will be indicated in the synchronous Confirm passed back.
 */

/**
 * @defgroup g_mac_sap_mlme_req_15_4 MLME Request 802.15.4 specification parameters
 * @ingroup g_mac_sap_mlme_req
 *
 * @{
 */

/**
 * @brief Structure for MLME-ASSOCIATE.request
 *
 * Association request. Use type MAC_MLME_REQ_ASSOCIATE
 */
typedef struct
{
    MAC_Addr_s sCoord;              /**< Coordinator to associate with */
    uint8      u8LogicalChan;       /**< Logical channel to associate on */
    uint8      u8Capability;        /**< Device's capability */
    uint8      u8SecurityEnable;    /**< True if security is to be used on command frames */
} MAC_MlmeReqAssociate_s;

/**
 * @brief Structure for MLME-DISASSOCIATE.request
 *
 * Disassociation request. Use type MAC_MLME_REQ_DISASSOCIATE
 * @note This is using the new proposal put forward by the ZigBee Alliance.
 * See e-mail to zigbee_interop from Karsten Vangsgaard, 20/04/04 23:27
 */
typedef struct
{
    MAC_Addr_s sAddr;               /**< Disassociating address of other end */
    uint8      u8Reason;            /**< Disassociation reason */
    uint8      u8SecurityEnable;    /**< True if security is to be used on command frames */
} MAC_MlmeReqDisassociate_s;

/**
 * @brief Structure for MLME-GET.request
 *
 * PIB get request. Use type MAC_MLME_REQ_GET
 */
typedef struct
{
    uint8 u8PibAttribute;       /**< Attribute @sa MAC_PibAttr_e */
    uint8 u8PibAttributeIndex;  /**< Index value used to specify which ACL entry to set. <b>Not part of 802.15.4</b> */
} MAC_MlmeReqGet_s;

/**
 * @brief Structure for MLME-GTS.request
 *
 * GTS request. Use type MAC_MLME_REQ_GTS
 */
typedef struct tagMAC_MlmeReqGts_s
{
    uint8 u8Characteristics;    /**< GTS characteristics */
    uint8 u8SecurityEnable;     /**< True if security is to be used on command frames */
} MAC_MlmeReqGts_s;

/**
 * @brief Structure for MLME-RESET.request
 *
 * MAC reset request. Use type MAC_MLME_REQ_RESET
 */
typedef struct
{
    uint8 u8SetDefaultPib;  /**< True if PIB is to be reset to default values */
} MAC_MlmeReqReset_s;

/**
 * @brief Structure for MLME-RX-ENABLE.request
 *
 * Receiver enable request. Use type MAC_MLME_REQ_RX_ENABLE
 */
typedef struct
{
    uint32 u32RxOnTime;     /**< Number of symbol periods from the start of the superframe before the receiver is enabled (beacon networks only) */
    uint32 u32RxOnDuration; /**< Number of symbol periods the receiver should be enabled for */
    uint8  u8DeferPermit;   /**< True if receiver enable can be deferred to the next superframe (beacon networks only) */
} MAC_MlmeReqRxEnable_s;

/**
 * @brief Structure for MLME-SCAN.request
 *
 * Scan request. Use type MAC_MLME_REQ_SCAN
 */
typedef struct tagMAC_MlmeReqScan_s
{
    uint32 u32ScanChannels; /**< Scan channels bitmap */
    uint8  u8ScanType;      /**< Scan type @sa MAC_MlmeScanType_e */
    uint8  u8ScanDuration;  /**< Scan duration */
} MAC_MlmeReqScan_s;

/**
 * @brief Structure for MLME-SET.request
 *
 * PIB set request. Use type MAC_MLME_REQ_SET
 */
typedef struct
{
    uint8     u8PibAttribute;       /**< Attribute @sa MAC_PibAttr_e */
    uint8     u8PibAttributeIndex;  /**< Index value used to specify which ACL entry to set. <b>Not part of 802.15.4</b> */
    uint16    u16Pad;               /**< Padding to show alignment */
    MAC_Pib_u uPibAttributeValue;   /**< Attribute value */
} MAC_MlmeReqSet_s;

/**
 * @brief Structure for MLME-START.request
 *
 * Superframe start request. Use type MAC_MLME_REQ_SYNC
 */
typedef struct
{
    uint16 u16PanId;            /**< The PAN ID indicated in the beacon */
    uint8  u8Channel;           /**< Channel to send beacon out on */
    uint8  u8BeaconOrder;       /**< Beacon order */
    uint8  u8SuperframeOrder;   /**< Superframe order */
    uint8  u8PanCoordinator;    /**< True if the Coordinator is a PAN Coordinator */
    uint8  u8BatteryLifeExt;    /**< True if battery life extension timings are to be used */
    uint8  u8Realignment;       /**< True if Coordinator realignment is sent when superframe parameters change */
    uint8  u8SecurityEnable;    /**< True if security is to be used on command frames */
} MAC_MlmeReqStart_s;

/**
 * @brief Structure for MLME-SYNC.request
 *
 * Superframe synchronisation request. Use type MAC_MLME_REQ_SYNC
 *
 */
typedef struct
{
    uint8  u8Channel;       /**< Channel to listen for beacon on */
    uint8  u8TrackBeacon;   /**< True if beacon is to be tracked */
} MAC_MlmeReqSync_s;

/**
 * @brief Structure for MLME-POLL.request
 *
 * Data poll request from Device. Use type MAC_MLME_REQ_POLL
 */
typedef struct
{
    MAC_Addr_s sCoord;              /**< Coordinator to poll for data */
    uint8      u8SecurityEnable;    /**< True if security is to be used on command frames */
} MAC_MlmeReqPoll_s;

/* @} */

/**
 * @defgroup g_mac_sap_mlme_req_vs MLME Request Vendor specific parameters
 * @ingroup g_mac_sap_mlme_req g_mac_sap_vs
 *
 * @{
 */

/**
 * @brief Structure for MLME-VS-EXT-ADDR.request
 *
 * Set External Address (usually constant and fixed per unit).
 * Use type MAC_MLME_REQ_VS_EXT_ADDR
 */
typedef struct
{
    MAC_ExtAddr_s sExtAddr; /**< Extended address to set */
} MAC_MlmeReqVsExtAddr_s;

#if defined(DEBUG) && defined(EMBEDDED)
/**
 * @brief Structure for MLME-VS-DEBUG.request
 *
 * Enable or disable debugging.
 * Use type MAC_MLME_REQ_VS_DEBUG
 */
typedef struct
{
    uint8 u8Debug;  /** True if debug is to be turned on, false if debug is to be turned off */
} MAC_MlmeReqVsDebug_s;

#endif /* defined(DEBUG) && defined(EMBEDDED) */

#ifdef MLME_VS_REG_RW

/**
 * @brief Structure for MLME-VS-RD-REG.request
 *
 * Request register read.
 * Use type MAC_MLME_REQ_VS_RD_REG
 */
typedef struct
{
    uint32 u32Offset;
} MAC_MlmeReqVsRdReg_s;

/**
 * @brief Structure for MLME-VS-WR-REG.request
 *
 * Request register write.
 * Use type MAC_MLME_REQ_VS_WR_REG
 */
typedef struct
{
    uint32 u32Offset;
    uint32 u32Data;
} MAC_MlmeReqVsWrReg_s;

#endif /* MLME_VS_REG_RW */

/* @} */

/**********************/
/**** MLME Confirm ****/
/**********************/

/**
 * @defgroup g_mac_sap_mlme_cfm MLME Confirm objects
 * @ingroup g_mac_sap_mlme
 *
 * These come back synchronously as a returned parameter in the Request/Response call.
 * They can also be deferred and asynchronously posted via the Deferred Confirm/Indication callback.
 * The status of the actual synchronous confirm is in u8SyncCfmStatus, whereas the MAC enumerated
 * status is returned in u8Status
 */

/**
 * @defgroup g_mac_sap_mlme_cfm_15_4 MLME Confirm 802.15.4 specification parameters
 * @ingroup g_mac_sap_mlme_cfm
 *
 * @{
 */

/**
 * @brief Structure for MLME-ASSOCIATE.confirm
 *
 * Association confirm
 */
typedef struct
{
    uint8  u8Status;            /**< Status of association @sa MAC_Enum_e */
    uint8  u8Pad;               /**< Padding to show alignment */
    uint16 u16AssocShortAddr;   /**< Associated Short Address */
} MAC_MlmeCfmAssociate_s;

/**
 * @brief Structure for MLME-DISASSOCIATE.confirm
 *
 * Disassociation confirm
 */
typedef struct
{
    uint8 u8Status; /**< Status of disassociation @sa MAC_Enum_e */
} MAC_MlmeCfmDisassociate_s;

/**
 * @brief Structure for MLME-GET.confirm
 *
 * PIB get confirm. Contains the value of the attribute requested
 * @note Always returned synchronously
 */
typedef struct
{
    uint8     u8Status;             /**< Status of PIB get @sa MAC_Enum_e */
    uint8     u8PibAttribute;       /**< PIB attribute requested */
    uint16    u16Pad;               /**< Padding to show alignment */
    MAC_Pib_u uPibAttributeValue;   /**< Value of attribute */
} MAC_MlmeCfmGet_s;

/**
 * @brief Structure for MLME-GTS.confirm
 *
 * GTS confirm
 */
typedef struct
{
    uint8 u8Status;             /**< Status of GTS request @sa MAC_Enum_e */
    uint8 u8Characteristics;    /**< GTS characteristics */
} MAC_MlmeCfmGts_s;

/**
 * @brief Structure for MLME-RESET.confirm
 *
 * Reset confirm
 */
typedef struct
{
    uint8 u8Status; /**< Status of receiver enable request @sa MAC_Enum_e */
} MAC_MlmeCfmReset_s;

/**
 * @brief Structure for MLME-RX-ENABLE.confirm
 *
 * Receiver enable confirm
 */
typedef struct
{
    uint8 u8Status; /**< Status of receiver enable request @sa MAC_Enum_e */
} MAC_MlmeCfmRxEnable_s;

/**
 * @brief Union of results in Scan confirm
 *
 * Either a list of energy detect values or a list of PAN Descriptors (@sa tagMAC_PanDescr_s)
 */
typedef union
{
    uint8          au8EnergyDetect[MAC_MAX_SCAN_CHANNELS];
    MAC_PanDescr_s asPanDescr[MAC_MAX_SCAN_PAN_DESCRS];
} MAC_ScanList_u;

/**
 * @brief Structure for MLME-SCAN.confirm
 *
 * Scan confirm
 * @note Always returned synchronously
 */
typedef struct
{
    uint8          u8Status;                /**< Status of scan request @sa MAC_Enum_e */
    uint8          u8ScanType;              /**< Scan type */
    uint8          u8ResultListSize;        /**< Size of scan results list */
    uint8          u8Pad;                   /**< Padding to show alignment */
    uint32         u32UnscannedChannels;    /**< Bitmap of unscanned channels */
    MAC_ScanList_u uList;                   /**< Scan results list */
} MAC_MlmeCfmScan_s;

/**
 * @brief Structure for MLME-SET.confirm
 *
 * PIB set confirm
 * @note Always returned synchronously
 */
typedef struct
{
    uint8 u8Status;         /**< Status of PIB set request @sa MAC_Enum_e */
    uint8 u8PibAttribute;   /**< PIB attribute set */
} MAC_MlmeCfmSet_s;

/**
 * @brief Structure for MLME-START.confirm
 *
 * Superframe start confirm
 */
typedef struct
{
    uint8 u8Status; /**< Status of superframe start request @sa MAC_Enum_e */
} MAC_MlmeCfmStart_s;

/**
 * @brief Structure for MLME-POLL.confirm
 *
 * Data poll confirm
 */
typedef struct
{
    uint8 u8Status; /**< Status of data poll request @sa MAC_Enum_e */
} MAC_MlmeCfmPoll_s;

/* @} */

/**
 * @defgroup g_mac_sap_mlme_cfm_VS MLME Confirm Vendor specific parameters
 * @ingroup g_mac_sap_mlme_cfm g_mac_sap_vs
 *
 * @{
 */

#ifdef MLME_VS_REG_RW

/**
 * @brief Structure containing read register value.
 *
 * Vendor-specific command to read a specific register
 * @note Always returned synchronously
 */
typedef struct
{
    uint32 u32Data;   /**< Register data */
} MAC_MlmeCfmVsRdReg_s;

#endif /* MLME_VS_REG_RW */

/* @} */

/*************************/
/**** MLME Indication ****/
/*************************/

/**
 * @defgroup g_mac_sap_mlme_ind MLME Indication objects
 * @ingroup g_mac_sap_mlme
 *
 * These are sent asynchronously via the registered Deferred Confirm/Indication callback
 */

/**
 * @defgroup g_mac_sap_mlme_ind_15_4 MLME Indication 802.15.4 specification parameters
 * @ingroup g_mac_sap_mlme_ind
 *
 * @{
 */

/**
 * @brief Structure for MLME-ASSOCIATE.indication
 *
 * Association indication. Uses type MAC_MLME_IND_ASSOCIATE
 */
typedef struct
{
    MAC_ExtAddr_s sDeviceAddr;      /**< Extended address of device wishing to associate */
    uint8         u8Capability;     /**< Device capabilities */
    uint8         u8SecurityUse;    /**< True if security was used on command frames */
    uint8         u8AclEntry;       /**< Security suite used */
} MAC_MlmeIndAssociate_s;

/**
 * @brief Structure for MLME-DISASSOCIATE.indication
 *
 * Disassociation indication. Uses type MAC_MLME_IND_DISASSOCIATE
 */
typedef struct
{
    MAC_ExtAddr_s sDeviceAddr;      /**< Extended address of device which has sent disassociation notification */
    uint8         u8Reason;         /**< Reason for disassociating */
    uint8         u8SecurityUse;    /**< True if security was used on command frames */
    uint8         u8AclEntry;       /**< Security suite used */
} MAC_MlmeIndDisassociate_s;

/**
 * @brief Structure for MLME-SYNC-LOSS.indication
 *
 * Synchronisation loss indication. Uses type MAC_MLME_SYNC_LOSS
 */
typedef struct
{
    uint8 u8Reason; /**< Synchronisation loss reason @sa MAC_Enum_e */
} MAC_MlmeIndSyncLoss_s;

/**
 * @brief Structure for MLME-GTS.indication
 *
 * GTS information indication. Uses type MAC_MLME_GTS_INDICATION
 */
typedef struct
{
    uint16 u16ShortAddr;        /**< Short address of device to which GTS has been allocated or deallocated */
    uint8  u8Characteristics;   /**< Characteristics of the GTS */
    uint8  u8Security;          /**< True if security was used on command frames */
    uint8  u8AclEntry;          /**< Security suite used */
} MAC_MlmeIndGts_s;

/**
 * @brief Structure for MLME-BEACON-NOTIFY.indication
 *
 * Beacon notification indication. Uses type MAC_MLME_BEACON_NOTIFY
 */
typedef struct
{
    MAC_PanDescr_s   sPANdescriptor;                    /**< PAN descriptor */
    uint8            u8BSN;                             /**< Beacon sequence number */
    uint8            u8PendAddrSpec;                    /**< Pending address specification */
    uint8            u8SDUlength;                       /**< Length of following payload */
    MAC_Addr_u       uAddrList[7];                      /**< Pending addresses */
    uint8            u8SDU[MAC_MAX_BEACON_PAYLOAD_LEN]; /**< Beacon payload */
} MAC_MlmeIndBeacon_s;

/**
 * @brief Structure for MLME-COMM-STATUS.indication
 *
 * Communication status indication. Uses type MAC_MLME_IND_COMM_STATUS
 * @note The PANId parameter for the primitive is contained within sSrcAddr.
 * The u16PanId element of sDstAddr is not used.
 */
typedef struct
{
    MAC_Addr_s sSrcAddr;    /**< Source address of frame */
    MAC_Addr_s sDstAddr;    /**< Destination address of frame */
    uint8      u8Status;    /**< Status of communication @sa MAC_Enum_e */
} MAC_MlmeIndCommStatus_s;

/**
 * @brief Structure for MLME-ORPHAN.indication
 *
 * Orphan indication. Uses type MAC_MLME_IND_ORPHAN
 */
typedef struct
{
    MAC_ExtAddr_s sDeviceAddr;      /**< Extended address of orphaned device */
    uint8         u8SecurityUse;    /**< True if security was used on command frames */
    uint8         u8AclEntry;       /**< Security suite used */
} MAC_MlmeIndOrphan_s;

/* @} */

/**
 * @defgroup g_mac_sap_mlme_ind_VS MLME Indication Vendor specific parameters
 * @ingroup g_mac_sap_mlme_ind g_mac_sap_vs
 *
 * @{
 */

#if defined(DEBUG) && defined(EMBEDDED)

/**
 * @brief Structure for MLME-VS-DEBUG.indication
 *
 * Debug message indication. Uses type MAC_MLME_IND_VS_DEBUG_INFO,
 * MAC_MLME_IND_VS_DEBUG_WARN, MAC_MLME_IND_VS_DEBUG_ERROR or
 * MAC_MLME_IND_VS_DEBUG_FATAL
 */
typedef struct tagMAC_MlmeIndVsDebug_s
{
    uint8 au8Data[MAC_VS_DEBUG_LEN];
} MAC_MlmeIndVsDebug_s;

#endif /* defined(DEBUG) && defined(EMBEDDED) */

/* @} */

/***********************/
/**** MLME Response ****/
/***********************/

/**
 * @defgroup g_mac_sap_mlme_rsp MLME Response objects
 * @ingroup g_mac_sap_mlme
 *
 * These are passed in a call to MAC_vHandleMlmeReqRsp.
 * Responses have no effective confirmation of sending as they are in response to
 * an Indication; this will be indicated in the synchronous Confirm passed back.
 */

/**
 * @defgroup g_mac_sap_mlme_rsp_15_4 MLME Response 802.15.4 specification parameters
 * @ingroup g_mac_sap_mlme_rsp
 *
 * @{
 */

/**
 * @brief Structure for MLME-ASSOCIATE.response
 *
 * Association response. Use type MAC_MLME_RSP_ASSOCIATE
 */
typedef struct
{
    MAC_ExtAddr_s sDeviceAddr;          /**< Device's extended address */
    uint16        u16AssocShortAddr;    /**< Short address allocated to Device */
    uint8         u8Status;             /**< Status of association */
    uint8         u8SecurityEnable;     /**< True if security is to be used on command frames */
} MAC_MlmeRspAssociate_s;

/**
 * @brief Structure for MLME-ORPHAN.response
 *
 * Orphan response. Use type MAC_MLME_RSP_ORPHAN
 */
typedef struct
{
    MAC_ExtAddr_s sOrphanAddr;          /**< Orphaned Device's extended address */
    uint16        u16OrphanShortAddr;   /**< Short address Orphaned Device should use */
    uint8         u8Associated;         /**< True if Device was previously associated */
    uint8         u8SecurityEnable;     /**< True if security is to be used on command frames */
} MAC_MlmeRspOrphan_s;

/* @} */

/*****************************************/
/**** MLME Request/Response Interface ****/
/*****************************************/

/**
 * @defgroup g_mac_sap_mlme_req_rsp_if MLME Request/Response interface
 * @ingroup g_mac_sap_mlme g_mac_VS
 *
 * The interface for the client to issue an MLME Request or Response
 * is via a function call to MAC_vHandleMlmeReqRsp.
 * @li Request/Response parameters are passed in via psMlmeReqRsp
 * @li Synchronous Confirm parameters are passed out via psMlmeSyncCfm
 * @li Deferred Confirms are posted back asynchronously via the
 *     Deferred Confirm/Indication callback.
 * @note Responses have no effective confirmation of sending as they are in response to
 * an Indication; this will be indicated in the synchronous Confirm passed back.
 *
 * @{
 */

/**
 * @brief MAC MLME Request/Response enumeration.
 *
 * Enumeration of MAC MLME Request/Response
 * @note Must not exceed 256 entries
 */
typedef enum
{
    MAC_MLME_REQ_ASSOCIATE = 0,     /**< Use with tagMAC_MlmeReqAssociate_s */
    MAC_MLME_REQ_DISASSOCIATE,      /**< Use with tagMAC_MlmeReqDisassociate_s */
    MAC_MLME_REQ_GET,               /**< Use with tagMAC_MlmeReqGet_s */
    MAC_MLME_REQ_GTS,               /**< Use with tagMAC_MlmeReqGts_s */
    MAC_MLME_REQ_RESET,             /**< Use with tagMAC_MlmeReqReset_s */
    MAC_MLME_REQ_RX_ENABLE,         /**< Use with tagMAC_MlmeReqRxEnable_s */
    MAC_MLME_REQ_SCAN,              /**< Use with tagMAC_MlmeReqScan_s */
    MAC_MLME_REQ_SET,               /**< Use with tagMAC_MlmeReqSet_s */
    MAC_MLME_REQ_START,             /**< Use with tagMAC_MlmeReqStart_s */
    MAC_MLME_REQ_SYNC,              /**< Use with tagMAC_MlmeReqSync_s */
    MAC_MLME_REQ_POLL,              /**< Use with tagMAC_MlmeReqPoll_s */
    MAC_MLME_RSP_ASSOCIATE,         /**< Use with tagMAC_MlmeRspAssociate_s */
    MAC_MLME_RSP_ORPHAN,            /**< Use with tagMAC_MlmeRspOrphan_s */
    MAC_MLME_REQ_VS_EXTADDR,        /**< Use with tagMAC_MlmeReqVsExtAddr_s */
#if defined(DEBUG) && defined(EMBEDDED)
    MAC_MLME_REQ_VS_DEBUG,          /**< Use with tagMAC_MlmeReqVsDebug_s */
#endif /* defined(DEBUG) && defined(EMBEDDED) */
#ifdef MLME_VS_REG_RW
    MAC_MLME_REQ_VS_RD_REG,         /**< Use with tagMAC_MlmeReqVsRdReg_s */
    MAC_MLME_REQ_VS_WR_REG,         /**< Use with tagMAC_MlmeReqVsWrReg_s */
#endif /* MLME_VS_REG_RW */
    NUM_MAC_MLME_REQ                /**< (endstop) */
} MAC_MlmeReqRspType_e;

/**
 * @brief MLME Request/Response Parameter union
 *
 * Union of all the possible MLME Requests and Responses, including
 * all the vendor-specific requests
 */
typedef union
{
    /* MLME Requests */
    MAC_MlmeReqAssociate_s    sReqAssociate;        /**< Association request */
    MAC_MlmeReqDisassociate_s sReqDisassociate;     /**< Disassociation request */
    MAC_MlmeReqGet_s          sReqGet;              /**< PIB get request */
    MAC_MlmeReqGts_s          sReqGts;              /**< GTS request */
    MAC_MlmeReqReset_s        sReqReset;            /**< MAC reset request */
    MAC_MlmeReqRxEnable_s     sReqRxEnable;         /**< Receiver enable request */
    MAC_MlmeReqScan_s         sReqScan;             /**< Scan request */
    MAC_MlmeReqSet_s          sReqSet;              /**< PIB set request */
    MAC_MlmeReqStart_s        sReqStart;            /**< Superframe start request */
    MAC_MlmeReqSync_s         sReqSync;             /**< Superframe sync request */
    MAC_MlmeReqPoll_s         sReqPoll;             /**< Data poll request */
    MAC_MlmeReqVsExtAddr_s    sReqVsExtAddr;        /**< VS set external address */
#if defined(DEBUG) && defined(EMBEDDED)
    MAC_MlmeReqVsDebug_s      sReqVsDebug;          /**< VS debug message */
#endif /* defined(DEBUG) && defined(EMBEDDED) */
#ifdef MLME_VS_REG_RW
    MAC_MlmeReqVsRdReg_s      sReqVsRdReg;          /**< VS read register */
    MAC_MlmeReqVsWrReg_s      sReqVsWrReg;          /**< VS write register */
#endif /* MLME_VS_REG_RW */
    MAC_MlmeRspAssociate_s    sRspAssociate;        /**< Association response */
    MAC_MlmeRspOrphan_s       sRspOrphan;           /**< Orphan response */
} MAC_MlmeReqRspParam_u;

/**
 * @brief MLME Request/Response
 *
 * The object passed to MAC_vHandleMlmeReqRsp containing the request
 */
typedef struct
{
    uint8                 u8Type;           /**< Request type (@sa MAC_MlmeReqRspType_e) */
    uint8                 u8ParamLength;    /**< Parameter length in following union */
    uint16                u16Pad;           /**< Padding to force alignment */
    MAC_MlmeReqRspParam_u uParam;           /**< Union of all possible Requests */
} MAC_MlmeReqRsp_s;

/**
 * @brief Synchronous confirm status
 *
 * Indicates in the synchronous confirm whether:
 * @li The Request was processed with or without error
 * @li The confirm will be deferred and posted via the Deferred Confirm/Indication callback
 * @li It is a dummy confirm to a Response.
 * @note NB Must not exceed 256 entries
 */
typedef enum
{
    MAC_MLME_CFM_OK,                /**< Synchronous confirm without error */
    MAC_MLME_CFM_ERROR,             /**< Synchronous confirm with error; see u8Status field */
    MAC_MLME_CFM_DEFERRED,          /**< Asynchronous deferred confirm will occur */
    MAC_MLME_CFM_NOT_APPLICABLE,    /**< Dummy synchronous confirm for MLME responses */
    NUM_MAC_MLME_CFM                /**< (endstop) */
} MAC_MlmeSyncCfmStatus_e;

/**
 * @brief MLME Synchronous Confirm Parameter union
 *
 * Union of all the possible MLME Synchronous Confirms, including
 * all the vendor-specific confirms
 */
typedef union
{
    MAC_MlmeCfmAssociate_s    sCfmAssociate;        /**< Association confirm */
    MAC_MlmeCfmDisassociate_s sCfmDisassociate;     /**< Disassociation confirm */
    MAC_MlmeCfmGet_s          sCfmGet;              /**< PIB get confirm */
    MAC_MlmeCfmGts_s          sCfmGts;              /**< GTS confirm */
    MAC_MlmeCfmScan_s         sCfmScan;             /**< Scan confirm */
    MAC_MlmeCfmSet_s          sCfmSet;              /**< PIB set confirm */
    MAC_MlmeCfmStart_s        sCfmStart;            /**< Superframe start confirm */
    MAC_MlmeCfmPoll_s         sCfmPoll;             /**< Data poll confirm */
    MAC_MlmeCfmReset_s        sCfmReset;            /**< Reset confirm */
    MAC_MlmeCfmRxEnable_s     sCfmRxEnable;         /**< Receiver enable confirm */
#ifdef MLME_VS_REG_RW
    MAC_MlmeCfmVsRdReg_s      sCfmVsRdReg;          /**< VS read Register confirm */
#endif /* MLME_VS_REG_RW */
} MAC_MlmeSyncCfmParam_u;

/**
 * @brief MLME Synchronous Confirm
 *
 * The object returned by MAC_vHandleMlmeReqRsp containing the synchronous confirm
 * @note All Confirms may also be sent asynchronously via the registered Deferred Confirm/Indication callback.
 * This is notified by returning MAC_MLME_CFM_DEFERRED.
 * The confirm type is implied as corresponding to the request
 */
typedef struct
{
    uint8                  u8Status;        /**< Confirm status (@sa MAC_MlmeCfmStatus_e) */
    uint8                  u8ParamLength;   /**< Parameter length in following union */
    uint16                 u16Pad;          /**< Padding to force alignment */
    MAC_MlmeSyncCfmParam_u uParam;          /**< Union of all possible Confirms */
} MAC_MlmeSyncCfm_s;

/* @} */

/****************************************************/
/**** MLME Deferred Confirm/Indication Interface ****/
/****************************************************/

/**
 * @defgroup g_mac_sap_mlme_dcfm_ind_if MLME Deferred Confirm/Indication Interface
 * @ingroup g_mac_sap_mlme g_mac_VS
 *
 * The interface for the client to receive an MLME Deferred Confirm or Indication
 * is via a function callback to the function registered using MAC_vMlmeDcfmIndRegister.
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
    MAC_MLME_DCFM_SCAN,                 /**< Use with tagMAC_MlmeCfmScan_s */
    MAC_MLME_DCFM_GTS,                  /**< Use with tagMAC_MlmeCfmGts_s */
    MAC_MLME_DCFM_ASSOCIATE,            /**< Use with tagMAC_MlmeCfmAssociate_s */
    MAC_MLME_DCFM_DISASSOCIATE,         /**< Use with tagMAC_MlmeCfmDisassociate_s */
    MAC_MLME_DCFM_POLL,                 /**< Use with tagMAC_MlmeCfmPoll_s */
    MAC_MLME_DCFM_RX_ENABLE,            /**< Use with tagMAC_MlmeCfmRxEnable_s */
    MAC_MLME_IND_ASSOCIATE,             /**< Use with tagMAC_MlmeIndAssociate_s */
    MAC_MLME_IND_DISASSOCIATE,          /**< Use with tagMAC_MlmeIndDisassociate_s */
    MAC_MLME_IND_SYNC_LOSS,             /**< Use with tagMAC_MlmeIndSyncLoss_s */
    MAC_MLME_IND_GTS,                   /**< Use with tagMAC_MlmeIndGts_s */
    MAC_MLME_IND_BEACON_NOTIFY,         /**< Use with tagMAC_MlmeIndBeacon_s */
    MAC_MLME_IND_COMM_STATUS,           /**< Use with tagMAC_MlmeIndCommStatus_s */
    MAC_MLME_IND_ORPHAN,                /**< Use with tagMAC_MlmeIndOrphan_s */
#if defined(DEBUG) && defined(EMBEDDED)
    MAC_MLME_IND_VS_DEBUG_INFO = 0xF0,  /**< Use with tagMAC_MlmeIndVsDebug_s */
    MAC_MLME_IND_VS_DEBUG_WARN,         /**< Use with tagMAC_MlmeIndVsDebug_s */
    MAC_MLME_IND_VS_DEBUG_ERROR,        /**< Use with tagMAC_MlmeIndVsDebug_s */
    MAC_MLME_IND_VS_DEBUG_FATAL,        /**< Use with tagMAC_MlmeIndVsDebug_s */
#endif /* defined(DEBUG) && defined(EMBEDDED) */
    NUM_MAC_MLME_IND,
    MAC_MLME_INVALID = 0xFF
} MAC_MlmeDcfmIndType_e;

/**
 * @brief MLME Indication and Deferred Confirm parameter union
 *
 * Union of all the possible MLME indications and deferred confirmations,
 * including all the vendor-specific indications
 */
typedef union
{
    MAC_MlmeCfmScan_s         sDcfmScan;
    MAC_MlmeCfmGts_s          sDcfmGts;
    MAC_MlmeCfmAssociate_s    sDcfmAssociate;
    MAC_MlmeCfmDisassociate_s sDcfmDisassociate;
    MAC_MlmeCfmPoll_s         sDcfmPoll;
    MAC_MlmeCfmRxEnable_s     sDcfmRxEnable;
    MAC_MlmeIndAssociate_s    sIndAssociate;
    MAC_MlmeIndDisassociate_s sIndDisassociate;
    MAC_MlmeIndGts_s          sIndGts;
    MAC_MlmeIndBeacon_s       sIndBeacon;
    MAC_MlmeIndSyncLoss_s     sIndSyncLoss;
    MAC_MlmeIndCommStatus_s   sIndCommStatus;
    MAC_MlmeIndOrphan_s       sIndOrphan;
#if defined(DEBUG) && defined(EMBEDDED)
    MAC_MlmeIndVsDebug_s      sIndVsDebug;
#endif /* defined(DEBUG) && defined(EMBEDDED) */
} MAC_MlmeDcfmIndParam_u;

/**
 * @brief MLME Indication
 *
 * The object passed to the registered Deferred Confirm/Indication callback.
 */
typedef struct
{
    uint8                  u8Type;          /**< Deferred Confirm/Indication type @sa MAC_MlmeDcfmIndType_e */
    uint8                  u8ParamLength;   /**< Parameter length in following union */
    uint16                 u16Pad;          /**< Padding to force alignment */
    MAC_MlmeDcfmIndParam_u uParam;          /**< Union of all possible Deferred Confirms/Indications */
} MAC_MlmeDcfmInd_s;

/* @} */

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
 * @brief Transmit frame structure
 *
 * Used by Data request
 */
typedef struct
{
    MAC_Addr_s sSrcAddr;                            /**< Source address */
    MAC_Addr_s sDstAddr;                            /**< Destination address */
    uint8      u8TxOptions;                         /**< Transmit options */
    uint8      u8SduLength;                         /**< Length of payload (MSDU) */
    uint8      au8Sdu[MAC_MAX_DATA_PAYLOAD_LEN];    /**< Payload (MSDU) */
} MAC_TxFrameData_s;

/**
 * @brief Structure for MCPS-DATA.request
 *
 * Data transmit request. Use type MAC_MCPS_REQ_DATA
 */
typedef struct
{
    uint8             u8Handle; /**< Handle of frame in queue */
    MAC_TxFrameData_s sFrame;   /**< Frame to send */
} MAC_McpsReqData_s;

/**
 * @brief Structure for MCPS-PURGE.request
 *
 * Purge request. Use type MAC_MCPS_REQ_PURGE
 */
typedef struct
{
    uint8          u8Handle;    /**< Handle of request to purge from queue */
} MAC_McpsReqPurge_s;

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
    uint8 u8Handle; /**< Handle matching associated request */
    uint8 u8Status; /**< Status of request @sa MAC_Enum_e */
} MAC_McpsCfmData_s;

/**
 * @brief Structure for MCPS-PURGE.confirm
 *
 * Data transmit confirm. Use type MAC_MCPS_CFM_PURGE
 */
typedef struct
{
    uint8 u8Handle; /**< Handle matching associated request */
    uint8 u8Status; /**< Status of request @sa MAC_Enum_e */
} MAC_McpsCfmPurge_s;

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
 * @brief Receive frame structure
 *
 * Used by Data indication
 */
typedef struct
{
    MAC_Addr_s sSrcAddr;                                /**< Source address */
    MAC_Addr_s sDstAddr;                                /**< Destination address */
    uint8      u8LinkQuality;                           /**< Link quality of received frame */
    uint8      u8SecurityUse;                           /**< True if security was used */
    uint8      u8AclEntry;                              /**< Security suite used */
    uint8      u8SduLength;                         /**< Length of payload (MSDU) */
    uint8      au8Sdu[MAC_MAX_DATA_PAYLOAD_LEN];    /**< Payload (MSDU) */
} MAC_RxFrameData_s;

/**
 * @brief Structure for MCPS-DATA.indication
 *
 * Data received indication. Uses type MAC_MCPS_IND_DATA
 */
typedef struct
{
    MAC_RxFrameData_s sFrame;   /**< Frame received */
} MAC_McpsIndData_s;

/* @} */

/***********************/
/**** MCPS Response ****/
/***********************/

/**
 * @defgroup g_mac_sap_mcps_rsp MCPS Response objects
 * @ingroup g_mac_sap_mcps
 *
 * @note There are currently no specified MCPS Responses
 */


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
    MAC_MCPS_REQ_DATA = 0,  /**< Use with tagMAC_McpsReqData_s */
    MAC_MCPS_REQ_PURGE,     /**< Use with tagMAC_McpsReqPurge_s */
    NUM_MAC_MCPS_REQ        /**> (endstop) */
} MAC_McpsReqRspType_e;

/**
 * @brief MCPS Request/Response Parameter union
 *
 * Union of all the possible MCPS Requests and Responses
 * @note There are no Responses currently specified
 */
typedef union
{
    MAC_McpsReqData_s  sReqData;   /**< Data request */
    MAC_McpsReqPurge_s sReqPurge;  /**< Purge request */
} MAC_McpsReqRspParam_u;

/**
 * @brief MCPS Request/Response object
 *
 * The object passed to MAC_vHandleMcpsReqRsp containing the request/response
 */
typedef struct
{
    uint8                 u8Type;          /**< Request type (@sa MAC_McpsReqRspType_e) */
    uint8                 u8ParamLength;   /**< Parameter length in following union */
    uint16                u16Pad;          /**< Padding to force alignment */
    MAC_McpsReqRspParam_u uParam;          /**< Union of all possible Requests */
} MAC_McpsReqRsp_s;

/**
 * @brief Synchronous confirm status
 *
 * Indicates in the synchronous confirm whether:
 * @li The Request was processed with or without error
 * @li The confirm will be deferred and posted via the Deferred Confirm/Indication callback
 * @li It is a dummy confirm to a Response.
 * @note NB Must not exceed 256 entries
 */
typedef enum
{
    MAC_MCPS_CFM_OK,        /**< Synchronous confirm without error */
    MAC_MCPS_CFM_ERROR,     /**< Synchronous confirm with error; see u8Status field */
    MAC_MCPS_CFM_DEFERRED,  /**< Asynchronous deferred confirm will occur */
    NUM_MAC_MCPS_CFM        /**< (endstop) */
} MAC_McpsSyncCfmStatus_e;

/**
 * @brief MCPS Synchronouse Confirm Parameter union
 *
 * Union of all the possible MCPS Synchronous Confirms
 */
typedef union
{
    MAC_McpsCfmData_s  sCfmData;
    MAC_McpsCfmPurge_s sCfmPurge;
} MAC_McpsSyncCfmParam_u;

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
    uint8                  u8Status;        /**< Confirm status (@sa MAC_McpsSyncCfmStatus_e) */
    uint8                  u8ParamLength;   /**< Parameter length in following union */
    uint16                 u16Pad;          /**< Padding to force alignment */
    MAC_McpsSyncCfmParam_u uParam;          /**< Union of all possible Confirms */
} MAC_McpsSyncCfm_s;

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
    MAC_MCPS_DCFM_DATA,
    MAC_MCPS_DCFM_PURGE,
    MAC_MCPS_IND_DATA,
    NUM_MAC_MCPS_IND
} MAC_McpsDcfmIndType_e;

/**
 * @brief MCPS Deferred Confirm/Indication Parameter union
 *
 * Union of all the possible MCPS Deferred Confirms or Indications
 */
typedef union
{
    MAC_McpsCfmData_s  sDcfmData;   /**< Deferred transmit data confirm */
    MAC_McpsCfmPurge_s sDcfmPurge;  /**< Deferred purge confirm */
    MAC_McpsIndData_s  sIndData;    /**< Received data indication */
} MAC_McpsDcfmIndParam_u;

/**
 * @brief MCPS Deferred Confirm/Indication
 *
 * The object passed in the MCPS Deferred Confirm/Indication callback
 */
typedef struct
{
    uint8                  u8Type;          /**< Indication type (@sa MAC_McpsDcfmIndType_e) */
    uint8                  u8ParamLength;   /**< Parameter length in following union */
    uint16                 u16Pad;          /**< Padding to force alignment */
    MAC_McpsDcfmIndParam_u uParam;          /**< Union of all possible Indications */
} MAC_McpsDcfmInd_s;

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

/**
 * @brief Generic Request/Response header
 *
 * Abstraction of the header used for all Requests/Responses
 * @note Must match with the first two fields of MCPS and MLME Requests/Responses
 */
typedef struct
{
    uint8  u8Type;          /**< Request/Response type */
    uint8  u8ParamLength;   /**< Parameter length */
    uint16 u16Pad;          /**< Padding to force alignment */
} MAC_ReqRspHdr_s;

/**
 * @brief Generic Synchronous Confirm header
 *
 * Abstraction of the header used for all Confirms
 * @note Must match with the first two fields of MCPS and MLME Confirms
 */
typedef struct
{
    uint8  u8Status;        /**< Confirm status */
    uint8  u8ParamLength;   /**< Parameter length */
    uint16 u16Pad;          /**< Padding to force alignment */
} MAC_SyncCfmHdr_s;

/**
 * @brief Generic Deferred Confirm/Indication header
 *
 * Abstraction of the header used for all Deferred Confirms and Indications
 * @note Must match with the first two fields of MCPS and MLME Deferred
 * Confirms and Indications
 */
typedef struct
{
    uint8  u8Type;          /**< Deferred confirm/Indication type */
    uint8  u8ParamLength;   /**< Parameter length */
    uint16 u16Pad;          /**< Padding to force alignment */
} MAC_DcfmIndHdr_s;

/* @} */

/**
 * @ingroup grp_phy_sap_pib
 * @brief PHY PIB attribute.
 *
 * Enumerations of PIB attribute as defined in Table 19 (section 6.5.2) (d18)
 * @note Refer to specification for definitive definitions.
 */
typedef enum
{
    PHY_PIB_ATTR_CURRENT_CHANNEL    = 0,  /**<  */
    PHY_PIB_ATTR_CHANNELS_SUPPORTED = 1,  /**<  */
    PHY_PIB_ATTR_TX_POWER           = 2,  /**<  */
    PHY_PIB_ATTR_CCA_MODE           = 3   /**<  */
} PHY_PibAttr_e;

/**
 * @ingroup grp_phy_sap_pib
 * @brief PHY Enumeration Type.
 *
 * Enumerations as defined in Table 16 (section 6.2.3) (d18)
 * @note Refer to specification for definitive definitions.
 * @note NOT A FULL LIST!
 */
typedef enum
{
    PHY_ENUM_INVALID_PARAMETER     = 0x05,
    PHY_ENUM_SUCCESS               = 0x07,
    PHY_ENUM_UNSUPPORTED_ATTRIBUTE = 0x0a
} PHY_Enum_e;

/****************************/
/**** EXPORTED VARIABLES ****/
/****************************/

/****************************/
/**** EXPORTED FUNCTIONS ****/
/****************************/

PUBLIC void
MAC_vHandleMlmeReqRsp(void *pvMac,
                      MAC_MlmeReqRsp_s *psMlmeReqRsp,
                      MAC_MlmeSyncCfm_s *psMlmeSyncCfm);

PUBLIC void
MAC_vHandleMcpsReqRsp(void *pvMac,
                      MAC_McpsReqRsp_s *psMcpsReqRsp,
                      MAC_McpsSyncCfm_s *psMcpsSyncCfm);

PUBLIC void
MAC_vRegisterMlmeDcfmIndCallbacks(void *pvMac,
                                  MAC_DcfmIndHdr_s * (*prGetBufCB)(void *),
                                  void (*prPostCB)(void *, MAC_DcfmIndHdr_s *),
                                  void *pvParam);

PUBLIC void
MAC_vRegisterMcpsDcfmIndCallbacks(void *pvMac,
                         MAC_DcfmIndHdr_s * (*prGetBufCB)(void *),
                         void (*prPostCB)(void *, MAC_DcfmIndHdr_s *),
                         void *pvParam);

PUBLIC PHY_Enum_e
phy_ePibSet(void *pvMac,
            PHY_PibAttr_e ePhyPibAttribute,
            uint32 u32PhyPibValue);

PUBLIC PHY_Enum_e
phy_ePibGet(void *pvMac,
            PHY_PibAttr_e ePhyPibAttribute,
            uint32 *pu32PhyPibValue);

#ifdef __cplusplus
};
#endif

#endif /* _mac_sap_h_ */

/* End of file $RCSfile: mac_sap.h,v $ *******************************************/

/****************************************************************************
 *
 * MODULE:             MAC
 *
 * DESCRIPTION:
 * MAC - The 802.15.4 Media Access Controller
 * Private header file to be included by module files only
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
 * @defgroup g_mac_pib MAC PIB
 *
 * Parameters associated with setting or getting PIB values.
 * PIB direct access allows getting and setting of PIB attributes directly by obtaining
 * the PIB handle and dereferencing it appropriately.
 * All PIB attributes can be read (got) in this manner
 * Most PIB attributes can be written (set) in this manner, however some PIB attributes
 * require an auxiliary function call to be called instead. This is because they also require
 * hardware register values to change as well.
 * The functions listed in this group indicate which PIB attributes need to be set in this manner
 * @ingroup g_mac
 */

#ifndef _mac_pib_h_
#define _mac_pib_h_

#ifdef __cplusplus
extern "C" {
#endif

/***********************/
/**** INCLUDE FILES ****/
/***********************/

#include "jendefs.h"
#include "mac_config.h"
#include "mac_sap.h"

/************************/
/**** MACROS/DEFINES ****/
/************************/

/*************/
/**** PIB ****/
/*************/

/**
 * @name PIB defaults, maxima and minima
 * @ingroup g_mac_pib
 * All the default values, minima and maxima for the MAC PIB
 * @{
 */

/** Association permit default */
#define MAC_PIB_ASSOCIATION_PERMIT_DEF              ((bool_t)FALSE)

/** Auto request default */
#define MAC_PIB_AUTO_REQUEST_DEF                    ((bool_t)TRUE)

/** Battery life extension default */
#define MAC_PIB_BATT_LIFE_EXT_DEF                   ((bool_t)FALSE)

/** Beacon order minimum */
#define MAC_PIB_BEACON_ORDER_MIN                    ((uint8)0)
/** Beacon order default */
#define MAC_PIB_BEACON_ORDER_DEF                    ((uint8)15)
/** Beacon order maximum */
#define MAC_PIB_BEACON_ORDER_MAX                    ((uint8)15)

/** Beacon transmit time minimum */
#define MAC_PIB_BEACON_TX_TIME_MIN                  ((uint32)0x000000)
/** Beacon transmit time default */
#define MAC_PIB_BEACON_TX_TIME_DEF                  ((uint32)0x000000)
/** Beacon transmit time maximum */
#define MAC_PIB_BEACON_TX_TIME_MAX                  ((uint32)0xFFFFFF)

/** Coordinator short address minimum */
#define MAC_PIB_COORD_SHORT_ADDRESS_MIN             ((uint16)0x0000)
/** Coordinator short address default */
#define MAC_PIB_COORD_SHORT_ADDRESS_DEF             ((uint16)0xFFFF)
/** Coordinator short address maximum */
#define MAC_PIB_COORD_SHORT_ADDRESS_MAX             ((uint16)0xFFFF)

/** GTS permit default */
#define MAC_PIB_GTS_PERMIT_DEF                      ((bool_t)TRUE)

/** Maximum CSMA backoffs minimum */
#define MAC_PIB_MAX_CSMA_BACKOFFS_MIN               ((uint8)0)
/** Maximum CSMA backoffs default */
#define MAC_PIB_MAX_CSMA_BACKOFFS_DEF               ((uint8)4)
/** Maximum CSMA backoffs maximum */
#define MAC_PIB_MAX_CSMA_BACKOFFS_MAX               ((uint8)5)

/** Default Maximum Frame Retries */
#define MAC_PIB_MAX_FRAME_RETRIES_DEF               ((uint8)3)

/** Minimum backoff exponent minimum */
#define MAC_PIB_MIN_BE_MIN                          ((uint8)0)
/** Minimum backoff exponent default */
#define MAC_PIB_MIN_BE_DEF                          ((uint8)3)
/** Minimum backoff exponent maximum */
#define MAC_PIB_MIN_BE_MAX                          ((uint8)3)

/** PAN ID minimum */
#define MAC_PIB_PAN_ID_MIN                          ((uint16)0x0000)
/** PAN ID default */
#define MAC_PIB_PAN_ID_DEF                          ((uint16)0xFFFF)
/** PAN ID maximum */
#define MAC_PIB_PAN_ID_MAX                          ((uint16)0xFFFF)

/** Promiscuous mode default */
#define MAC_PIB_PROMISCUOUS_MODE_DEF                ((bool_t)FALSE)

/** Receive on when idle default */
#define MAC_PIB_RX_ON_WHEN_IDLE_DEF                 ((bool_t)FALSE)

/** Short address minimum */
#define MAC_PIB_SHORT_ADDRESS_MIN                   ((uint16)0x0000)
/** Short address default */
#define MAC_PIB_SHORT_ADDRESS_DEF                   ((uint16)0xFFFF)
/** Short address maximum */
#define MAC_PIB_SHORT_ADDRESS_MAX                   ((uint16)0xFFFF)

/** Superframe order minimum */
#define MAC_PIB_SUPERFRAME_ORDER_MIN                ((uint8)0)
/** Superframe order default */
#define MAC_PIB_SUPERFRAME_ORDER_DEF                ((uint8)15)
/** Superframe order maximum */
#define MAC_PIB_SUPERFRAME_ORDER_MAX                ((uint8)15)

/** Transaction persistence time minimum */
#define MAC_PIB_TRANSACTION_PERSISTENCE_TIME_MIN    ((uint16)0x0000)
/** Transaction persistence time default */
#define MAC_PIB_TRANSACTION_PERSISTENCE_TIME_DEF    ((uint16)0x01F4)
/** Transaction persistence time maximum */
#define MAC_PIB_TRANSACTION_PERSISTENCE_TIME_MAX    ((uint16)0xFFFF)

/** Total frame transmit time minimum */
#define MAC_PIB_MAX_TOTAL_FRAME_TX_TIME_MIN         ((uint16)143)
/** Total frame transmit time default */
#define MAC_PIB_MAX_TOTAL_FRAME_TX_TIME_DEF         ((uint16)1220)
/** Total frame transmit time maximum */
#define MAC_PIB_MAX_TOTAL_FRAME_TX_TIME_MAX         ((uint16)25776)

/** Response wait time minimum */
#define MAC_PIB_RESPONSE_WAIT_TIME_MIN              ((uint8)2)
/** Response wait time default */
#define MAC_PIB_RESPONSE_WAIT_TIME_DEF              ((uint8)32)
/** Response wait time maximum */
#define MAC_PIB_RESPONSE_WAIT_TIME_MAX              ((uint8)64)

/** ACL entry descriptor set size minimum */
#define MAC_PIB_ACL_ENTRY_DESCRIPTOR_SET_SIZE_MIN   ((uint8)0)
/** ACL entry descriptor set size default */
#define MAC_PIB_ACL_ENTRY_DESCRIPTOR_SET_SIZE_DEF   ((uint8)0)
/** ACL entry descriptor set size maximum */
#define MAC_PIB_ACL_ENTRY_DESCRIPTOR_SET_SIZE_MAX   ((uint8)MAC_MAX_ACL_ENTRIES)

/** Use default security default */
#define MAC_PIB_DEFAULT_SECURITY_DEF                ((bool_t)FALSE)

/** Default security length minimum */
#define MAC_PIB_ACL_DEFAULT_SECURITY_LEN_MIN        ((uint8)0)
/** Default security length default */
#define MAC_PIB_ACL_DEFAULT_SECURITY_LEN_DEF        ((uint8)0x15)
/** Default security length maximum */
#define MAC_PIB_ACL_DEFAULT_SECURITY_LEN_MAX        ((uint8)MAC_MAX_SECURITY_MATERIAL_LEN)

/** Security suite minimum */
#define MAC_PIB_DEFAULT_SECURITY_SUITE_MIN          ((uint8)0)
/** Security suite default */
#define MAC_PIB_DEFAULT_SECURITY_SUITE_DEF          ((uint8)0)
/** Security suite maximum */
#define MAC_PIB_DEFAULT_SECURITY_SUITE_MAX          ((uint8)7)

/** Security mode minimum */
#define MAC_PIB_SECURITY_MODE_MIN                   ((uint8)0)
/** Security mode default */
#define MAC_PIB_SECURITY_MODE_DEF                   ((uint8)0)
/** Security mode maximum */
#define MAC_PIB_SECURITY_MODE_MAX                   ((uint8)2)

/** Security material: Key length in words */
#define MAC_KEY_LEN_WORDS           4
/** Security material: Key length in octets */
#define MAC_KEY_LEN_OCTETS          16
/** Security material: Frame counter length in words */
#define MAC_FRAME_COUNTER_WORDS     1
/** Security material: Frame counter length in octets */
#define MAC_FRAME_COUNTER_OCTETS    4

/** Security mode: Unsecured */
#define MAC_SECURITY_MODE_UNSECURED 0
/** Security mode: ACL mode */
#define MAC_SECURITY_MODE_ACL       1
/** Security mode: Secured */
#define MAC_SECURITY_MODE_SECURED   2

/** ACL freshness support: Lowest numbered ACL suite supporting freshness */
#define ACL_SUITE_FRESHNESS_MIN     1
/** ACL freshness support: Highest numbered ACL suite supporting freshness */
#define ACL_SUITE_FRESHNESS_MAX     4
/** ACL freshness support:  Length of security material supporting freshness */
#define ACL_SECURITY_FRESHNESS_LEN  26
/* @} */

#ifdef MAC_BUILD
#define b_PROMISCUOUS_MODE_READ_ONLY   bPromiscuousMode
#define b_RX_ON_WHEN_IDLE_READ_ONLY    bRxOnWhenIdle
#define u8_MAX_CSMA_BACKOFFS_READ_ONLY u8MaxCsmaBackoffs
#define u8_MIN_BE_READ_ONLY            u8MinBe
#define u16_PAN_ID_ONLY                u16PanId
#define u16_SHORT_ADDR_ONLY            u16ShortAddr
#else
#define b_PROMISCUOUS_MODE_READ_ONLY   bPromiscuousMode_ReadOnly
#define b_RX_ON_WHEN_IDLE_READ_ONLY    bRxOnWhenIdle_ReadOnly
#define u8_MAX_CSMA_BACKOFFS_READ_ONLY u8MaxCsmaBackoffs_ReadOnly
#define u8_MIN_BE_READ_ONLY            u8MinBe_ReadOnly
#define u16_PAN_ID_ONLY                u16PanId_ReadOnly
#define u16_SHORT_ADDR_ONLY            u16ShortAddr_ReadOnly
#endif

/**************************/
/**** TYPE DEFINITIONS ****/
/**************************/

/**
 * MAC PIB Ack wait duration
 * Enumeration of PIB Ack wait duration attribute
 * @ingroup g_mac_pib
 */
typedef enum
{
    MAC_PIB_ACK_WAIT_DURATION_HI = 54,
    MAC_PIB_ACK_WAIT_DURATION_LO = 120,
    NUM_MAC_PIB_ACK_WAIT_DURATION
} MAC_PibAckWaitDuration_e;

#define MAC_PIB_ACK_WAIT_DURATION_DEF       MAC_PIB_ACK_WAIT_DURATION_HI

/**
 * MAC PIB Battery life extension periods
 * Enumeration of PIB Battery life extension periods attribute
 * @ingroup g_mac_pib
 */
typedef enum
{
    MAC_PIB_BATT_LIFE_EXT_PERIODS_HI = 6,
    MAC_PIB_BATT_LIFE_EXT_PERIODS_LO = 8,
    NUM_MAC_PIB_BATT_LIFE_EXT_PERIODS
} MAC_PibBattLifeExtPeriods_e;

#define MAC_PIB_BATT_LIFE_EXT_PERIODS_DEF   MAC_PIB_BATT_LIFE_EXT_PERIODS_HI



/**
 * MAC Acl Entry.
 * Contains data for an Acl Entry.
 * @ingroup g_mac_pib
 */
typedef struct tagMAC_PibAclEntry_s
{
    MAC_ExtAddr_s sAclExtAddr;
    uint16 u16AclShortAddr;
    uint16 u16AclPanId;
    uint8 u8AclSecurityMaterialLength;
    uint8 u8AclSecuritySuite;
    MAC_PibSecurityMaterial_s sAclSecurityMaterial;

    /* If using hash tables for quick lookup, extra information is
       included in ACL entry */
#ifdef USE_HASH_TABLE_LOOKUP
    struct tagMAC_PibAclEntry_s *psNextShortHashEntry;
    struct tagMAC_PibAclEntry_s *psNextExtHashEntry;
#endif
} MAC_PibAclEntry_s;





/**
 * MAC PIB
 * The PIB itself
 * @ingroup g_mac_pib
 */
typedef struct
{
    uint8                       eAckWaitDuration;    /**< macAckWaitDuration attribute. @sa MAC_PibAckWaitDuration_e */
#ifdef ENABLE_OPT_MLME_ASSOCIATE
    bool_t                      bAssociationPermit;  /**< macAssociationPermit attribute */
#endif
    bool_t                      bAutoRequest;        /**< macAutoRequest attribute */
    bool_t                      bBattLifeExt;        /**< macBattLifeExt attribute */
    uint8                       eBattLifeExtPeriods; /**< macBattLifeExtPeriods attribute. @sa MAC_PibBattLifeExtPeriods_e */
#ifdef ENABLE_OPT_COORD
    uint8                       u8BeaconOrder;       /**< macBeaconOrder attribute */
    uint8                       u8SuperframeOrder;   /**< macSuperframeOrder attribute */
#endif
#if (defined ENABLE_OPT_MLME_GTS_COORD) && (defined ENABLE_OPT_COORD)
    bool_t                      bGtsPermit;          /**< macGTSPermit attribute */
#endif
#ifdef ENABLE_OPT_PROMISCUOUS
    bool_t                      b_PROMISCUOUS_MODE_READ_ONLY;    /**< macPromiscuousMode attribute */
#endif
    bool_t                      b_RX_ON_WHEN_IDLE_READ_ONLY;       /**< macRxOnWhenIdle attribute */
    uint8                       u8ResponseWaitTime;  /**< macResponseWaitTime */
    /* PIB security attributes */
    uint8                       u8AclEntrySetSize;   /**< macAclEntrySetSize attribute */
    bool_t                      bDefaultSecurity;    /**< macDefaultSecurity attribute */
    uint8                       u8AclDefaultSecurityMaterialLength; /**< macAclDefaultSecurityMaterialLength attribute */
    uint8                       u8DefaultSecuritySuite;             /**< macDefaultSecuritySuite attribute */
    uint8                       u8SecurityMode;      /**< macSecurityMode attribute */
    uint16                      u16CoordShortAddr;   /**< macCoordShortAddress attribute */
    uint16                      u16TransactionPersistenceTime;      /**< macTransactionPersistenceTime attribute */
    uint16                      u16MaxTotalFrameTxTime;             /**< macMaxTotalFrameTxTime */

    /**** The attributes below are NOT in the initialisation structure ****/

    /* Default 0 attributes */
#ifdef ENABLE_OPT_COORD
    uint8                       u8BeaconPayloadLength;  /**< macBeaconPayloadLength attrbute */
    uint8                       au8BeaconPayload[MAC_MAX_BEACON_PAYLOAD_LEN];/**< macBeaconPayload attrbute */
#endif
    MAC_ExtAddr_s               sCoordExtAddr;/**< macCoordExtendedAddress attribute */
    uint32                      u32BeaconTxTime;/**< macBeaconTxTime attribute */

    /* Explicitly initialised attributes */
#ifdef ENABLE_OPT_COORD
    uint8                       u8Bsn;/**< macBSN attribute */
#endif
    uint8                       u8Dsn;/**< macDSN attribute */
    uint8                       u8_MAX_CSMA_BACKOFFS_READ_ONLY; /**< macMaxCSMABackoffs attribute */
    uint8                       u8_MIN_BE_READ_ONLY;/**< macMinBE attribute */
    uint16                      u16_PAN_ID_ONLY;/**< macPANId attribute */
    uint16                      u16_SHORT_ADDR_ONLY;/**< macShortAddress attribute */

#ifdef ENABLE_OPT_SECURITY
    /* Structs and arrays at end to make initialisation from const initialiser easy */
    /**
     * macDefaultSecurityMaterial attribute
     * @note Split into relevant fields
     */
    MAC_PibSecurityMaterial_s   sDefaultSecurityMaterial;
    /**
     * ACL Entry Table
     */
    MAC_PibAclEntry_s           asAclEntryDescriptorSet[MAC_MAX_ACL_ENTRIES];
#endif

    uint8                       u8MaxFrameRetries; /**<macMaxFrameRetries */

    uint8                       bMacSecurityEnabled;

#ifdef ENABLE_OPT_SECURITY

#ifdef EARLY_MAC_2006
    MAC_PibSecurityMaterial_s   s2006SecurityMaterial;
#endif

    MAC_SecutityMode_e          eMacSecurityMode;
   /*2006 Secuirty Pib Attributes*/
#ifdef JENNIC_CHIP_FAMILY_JN514x
    /* Old layout for backward compatibility with ROM code */
    MAC_KeyDescriptor_s            *psMacKeyTable;
    uint8                           u8MacKeyTableEntries;
    MAC_DeviceDescriptor_s         *psMacDeviceTable;
    uint8                           u8MacDeviceTableEntries;
    MAC_SecurityLevelDescriptor_s  *psMacSecurityLevelTable;
    uint8                           u8MacSecuirtyLevelTableEntries;
    uint32                          u32MacFrameCounter;
#else
    /* New layout to reduce memory used */
    MAC_KeyDescriptor_s            *psMacKeyTable;
    MAC_DeviceDescriptor_s         *psMacDeviceTable;
    MAC_SecurityLevelDescriptor_s  *psMacSecurityLevelTable;
    uint32                          u32MacFrameCounter;
    uint8                           u8MacKeyTableEntries;
    uint8                           u8MacDeviceTableEntries;
    uint8                           u8MacSecuirtyLevelTableEntries;
#endif
    uint8                           u8MacAutoRequestSecurityLevel;
    uint8                           u8MacAutoRequestKeyIdMode;
    uint8                           au8MacAutoRequestKeySource[MAC_SECURITY_KEY_SOURCE_MAX_LENGTH];
    uint8                           u8MacAutoRequestKeyIndex;
    uint8                           au8MacDefaultKeySource[MAC_SECURITY_KEY_SOURCE_MAX_LENGTH];
    /*****************************/
#endif

} MAC_Pib_s;

/****************************/
/**** EXPORTED VARIABLES ****/

/****************************/

/****************************/
/**** EXPORTED FUNCTIONS ****/
/****************************/
#ifdef MAC_IN_ROM

typedef MAC_Pib_s * (*tprMAC_psPibGetHandle)(void *pvMac);
typedef void (*tprMAC_vPibSetShortAddr)(void *pvMac, uint16 u16ShortAddr);
typedef void (*tprMAC_vPibSetPanId)(void *pvMac, uint16 u16PanId);
typedef void (*tprMAC_vPibSetMinBe)(void *pvMac, uint8 u8MinBe);
typedef void (*tprMAC_vPibSetMaxCsmaBackoffs)(void *pvMac,
                                              uint8 u8MaxCsmaBackoffs);
#ifdef ENABLE_OPT_PROMISCUOUS
typedef void (*tprMAC_vPibSetPromiscuousMode)(void *pvMac,
                                              bool_t bNewState,
                                              bool_t bInReset);
#endif
typedef void (*tprMAC_vPibSetRxOnWhenIdle)(void *pvMac,
                                           bool_t bNewState,
                                           bool_t bInReset);
typedef void (*tprMAC_vSetExtAddr)(void *pvMac,
                                   MAC_ExtAddr_s *psExtAddr);

#define MAC_psPibGetHandle ((tprMAC_psPibGetHandle)(*(uint32 *)0x24))
#define MAC_vPibSetShortAddr ((tprMAC_vPibSetShortAddr)(*(uint32 *)0x28))
#define MAC_vPibSetPanId ((tprMAC_vPibSetPanId)(*(uint32 *)0x2c))
#define MAC_vPibSetMinBe ((tprMAC_vPibSetMinBe)(*(uint32 *)0x30))
#define MAC_vPibSetMaxCsmaBackoffs ((tprMAC_vPibSetMaxCsmaBackoffs)(*(uint32 *)0x34))
#ifdef ENABLE_OPT_PROMISCUOUS
#define MAC_vPibSetPromiscuousMode ((tprMAC_vPibSetPromiscuousMode)(*(uint32 *)0x38))
#endif
#define MAC_vPibSetRxOnWhenIdle ((tprMAC_vPibSetRxOnWhenIdle)(*(uint32 *)0x3c))
#define MAC_vSetExtAddr ((tprMAC_vSetExtAddr)(*(uint32 *)0x40))

#else

PUBLIC MAC_Pib_s *
MAC_psPibGetHandle(void *pvMac);

PUBLIC void
MAC_vPibSetShortAddr(void *pvMac,
                     uint16 u16ShortAddr);

PUBLIC void
MAC_vPibSetPanId(void *pvMac,
                 uint16 u16PanId);

PUBLIC void
MAC_vPibSetMinBe(void *pvMac,
                 uint8 u8MinBe);

PUBLIC void
MAC_vPibSetMaxCsmaBackoffs(void *pvMac,
                           uint8 u8MaxCsmaBackoffs);

#ifdef ENABLE_OPT_PROMISCUOUS
PUBLIC void
MAC_vPibSetPromiscuousMode(void *pvMac,
                           bool_t bNewState,
                           bool_t bInReset);
#endif

PUBLIC void
MAC_vPibSetRxOnWhenIdle(void *pvMac,
                        bool_t bNewState,
                        bool_t bInReset);

PUBLIC void
MAC_vSetExtAddr(void *pvMac,
                MAC_ExtAddr_s *psExtAddr);

#endif

#ifdef __cplusplus
};
#endif

#endif /* _mac_pib_h_ */

/* End of file $RCSfile: mac_pib.h,v $ *******************************************/

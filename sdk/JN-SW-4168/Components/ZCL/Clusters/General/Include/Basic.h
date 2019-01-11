/*****************************************************************************
 *
 * MODULE:             Basic Cluster
 *
 * COMPONENT:          Basic.h
 *
 * AUTHOR:             Lee Mitchell
 *
 * DESCRIPTION:        Header for Basic Cluster
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/UnifiedZCL_ZLL102_HA122_Maintenance/Clusters/General/Include/Basic.h $
 *
 * $Revision: 82333 $
 *
 * $LastChangedBy: nxp46755 $
 *
 * $LastChangedDate: 2016-08-19 11:12:02 +0100 (Fri, 19 Aug 2016) $
 *
 * $Id: Basic.h 82333 2016-08-19 10:12:02Z nxp46755 $
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

#ifndef BASIC_H
#define BASIC_H

#include <jendefs.h>
#include "zcl.h"
#include "zcl_options.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/*             Basic Cluster - Optional Attributes                          */
/*                                                                          */
/* Add the following #define's to your zcl_options.h file to add optional   */
/* attributes to the basic cluster.                                         */
/****************************************************************************/

#ifdef CLD_SM_SUPPORT_MIRROR

#ifndef CLD_BAS_ATTR_PHYSICAL_ENVIRONMENT
    /*Required for maintaining the Mirror capability at ESI*/
    #define CLD_BAS_ATTR_PHYSICAL_ENVIRONMENT
#endif

#endif

/* Enable the optional Application Version attribute */
//#define   CLD_BAS_ATTR_APPLICATION_VERSION

/* Enable the optional Stack Version attribute*/
//#define   CLD_BAS_ATTR_STACK_VERSION

/* Enable the optional Hardware Version attribute */
//#define   CLD_BAS_ATTR_HARDWARE_VERSION

/* Enable the optional Manufacturer Name attribute */
//#define   CLD_BAS_ATTR_MANUFACTURER_NAME

/* Enable the optional Model Identifier attribute */
//#define   CLD_BAS_ATTR_MODEL_IDENTIFIER

/* Enable the optional Date Code attribute */
//#define   CLD_BAS_ATTR_DATE_CODE

/* Enable the optional Location Description attribute */
//#define   CLD_BAS_ATTR_LOCATION_DESCRIPTION

/* Enable the optional Physical Environment attribute */
//#define   CLD_BAS_ATTR_PHYSICAL_ENVIRONMENT

/* Enable the optional Device Enabled attribute */
//#define   CLD_BAS_ATTR_DEVICE_ENABLED

/* Enable the optional Alarm Mask attribute */
//#define   CLD_BAS_ATTR_ALARM_MASK

/* Enable the optional Disable Local Config attribute */
//#define CLD_BAS_ATTR_DISABLE_LOCAL_CONFIG

/* ZLL enhanced attribute */
//#define CLD_BAS_ATTR_SW_BUILD_ID

/* End of optional attributes */
#ifndef CLD_BAS_APP_VERSION
#define CLD_BAS_APP_VERSION         (0x00)
#endif
#ifndef CLD_BAS_STACK_VERSION
#define CLD_BAS_STACK_VERSION       (0x00)
#endif
#ifndef CLD_BAS_HARDWARE_VERSION
#define CLD_BAS_HARDWARE_VERSION    (0x00)
#endif
#ifndef CLD_BAS_MANUF_NAME_SIZE
#define CLD_BAS_MANUF_NAME_SIZE     (0)
#endif
#ifndef CLD_BAS_MODEL_ID_SIZE
#define CLD_BAS_MODEL_ID_SIZE       (0)
#endif
#ifndef CLD_BAS_DATE_SIZE
#define CLD_BAS_DATE_SIZE           (0)
#endif
#ifndef CLD_BAS_POWER_SOURCE
#define CLD_BAS_POWER_SOURCE        E_CLD_BAS_PS_UNKNOWN
#endif

#ifndef CLD_BAS_APPLICATION_PROFILE_TYPE
#define CLD_BAS_APPLICATION_PROFILE_TYPE E_CLD_BAS_APT_ZIGBEE_HOME_AUTOMATION
#endif

#ifndef CLD_BAS_APPLICATION_PROFILE_VERSION
#define CLD_BAS_APPLICATION_PROFILE_VERSION (0)
#endif

#ifndef CLD_BAS_SW_BUILD_SIZE
#define CLD_BAS_SW_BUILD_SIZE       (0)
#endif
/* Cluster ID's */
#define GENERAL_CLUSTER_ID_BASIC                            0x0000

/* Alarm Mask */
#define CLD_BAS_ALARM_MASK_GENERAL_HARDWARE_FAULT           (1 << 0)
#define CLD_BAS_ALARM_MASK_GENERAL_SOFTWARE_FAULT           (1 << 1)

/* Disable Local Config */
#define CLD_BAS_DISABLE_LOCAL_CFG_RESET                     (1 << 0)
#define CLD_BAS_DISABLE_LOCAL_CFG_DISABLED                  (1 << 1)

#define CLD_BASIC_NUMBER_OF_MANDATORY_ATTRIBUTE              2  //ePowerSource and u8ZCLVersion

#ifdef CLD_BAS_ATTR_APPLICATION_VERSION
    #define ATTR_APPLICATION_VERSION                         1
#else
    #define ATTR_APPLICATION_VERSION                         0
#endif

#ifdef CLD_BAS_ATTR_STACK_VERSION
    #define ATTR_STACK_VERSION                               1
#else
    #define ATTR_STACK_VERSION                               0
#endif

#ifdef CLD_BAS_ATTR_HARDWARE_VERSION
    #define ATTR_HARDWARE_VERSION                            1
#else
    #define ATTR_HARDWARE_VERSION                            0
#endif

#ifdef CLD_BAS_ATTR_MANUFACTURER_NAME
    #define ATTR_MANUFACTURER_NAME                           1
#else
    #define ATTR_MANUFACTURER_NAME                           0
#endif
#ifdef CLD_BAS_ATTR_MODEL_IDENTIFIER
    #define ATTR_MODEL_IDENTIFIER                            1
#else
    #define ATTR_MODEL_IDENTIFIER                            0
#endif
#ifdef CLD_BAS_ATTR_DATE_CODE
    #define ATTR_DATE_CODE                                   1
#else
    #define ATTR_DATE_CODE                                   0
#endif
#ifdef CLD_BAS_ATTR_LOCATION_DESCRIPTION
    #define ATTR_LOCATION_DESCRIPTION                        1
#else
    #define ATTR_LOCATION_DESCRIPTION                        0
#endif
#ifdef CLD_BAS_ATTR_DEVICE_ENABLED
    #define ATTR_DEVICE_ENABLED                              1
#else
    #define ATTR_DEVICE_ENABLED                              0
#endif
#ifdef CLD_BAS_ATTR_PHYSICAL_ENVIRONMENT
    #define ATTR_PHYSICAL_ENVIRONMENT                        1
#else
    #define ATTR_PHYSICAL_ENVIRONMENT                        0
#endif


#ifdef CLD_BAS_ATTR_ALARM_MASK
    #define ATTR_ALARM_MASK                                  1
#else
    #define ATTR_ALARM_MASK                                  0
#endif
#ifdef CLD_BAS_ATTR_DISABLE_LOCAL_CONFIG
    #define ATTR_DISABLE_LOCAL_CONFIG                        1
#else
    #define ATTR_DISABLE_LOCAL_CONFIG                        0
#endif
#ifdef CLD_BAS_ATTR_SW_BUILD_ID
    #define ATTR_SW_BUILD_ID                                 1
#else
    #define ATTR_SW_BUILD_ID                                 0
#endif

#define CLD_BASIC_NUMBER_OF_OPTIONAL_ATTRIBUTE  \
    ATTR_APPLICATION_VERSION        +           \
    ATTR_STACK_VERSION              +           \
    ATTR_HARDWARE_VERSION           +           \
    ATTR_MANUFACTURER_NAME          +           \
    ATTR_MODEL_IDENTIFIER           +           \
    ATTR_DATE_CODE                  +           \
    ATTR_LOCATION_DESCRIPTION       +           \
    ATTR_DEVICE_ENABLED             +           \
    ATTR_PHYSICAL_ENVIRONMENT       +           \
    ATTR_ALARM_MASK                 +           \
    ATTR_DISABLE_LOCAL_CONFIG       +           \
    ATTR_SW_BUILD_ID

#define CLD_BASIC_MAX_NUMBER_OF_ATTRIBUTE       \
    CLD_BASIC_NUMBER_OF_OPTIONAL_ATTRIBUTE +    \
    CLD_BASIC_NUMBER_OF_MANDATORY_ATTRIBUTE
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/* Command codes */
typedef enum 
{
    E_CLD_BASIC_CMD_RESET_TO_FACTORY_DEFAULTS    = 0x00
} teCLD_Basic_Command;

typedef enum 
{
    /* Basic Device Information attribute set attribute ID's (3.2.2.2.1) */
    E_CLD_BAS_ATTR_ID_ZCL_VERSION                = 0x0000, /* Mandatory */
    E_CLD_BAS_ATTR_ID_APPLICATION_VERSION,
    E_CLD_BAS_ATTR_ID_STACK_VERSION,
    E_CLD_BAS_ATTR_ID_HARDWARE_VERSION,
    E_CLD_BAS_ATTR_ID_MANUFACTURER_NAME,
    E_CLD_BAS_ATTR_ID_MODEL_IDENTIFIER,
    E_CLD_BAS_ATTR_ID_DATE_CODE,
    E_CLD_BAS_ATTR_ID_POWER_SOURCE,                       /* Mandatory */
    E_CLD_BAS_ATTR_ID_APPLICATION_PROFILE_VERSION,        /* Optional as per HA1.2 errata 13-0553-40*/
    E_CLD_BAS_ATTR_ID_APPLICATION_PROFILE_TYPE,

    /* Basic Device Settings attribute set attribute ID's (3.2.2.2.10) */
    E_CLD_BAS_ATTR_ID_LOCATION_DESCRIPTION        = 0x0010,
    E_CLD_BAS_ATTR_ID_PHYSICAL_ENVIRONMENT,
    E_CLD_BAS_ATTR_ID_DEVICE_ENABLED,
    E_CLD_BAS_ATTR_ID_ALARM_MASK,
    E_CLD_BAS_ATTR_ID_DISABLE_LOCAL_CONFIG,
    E_CLD_BAS_ATTR_ID_SW_BUILD_ID               = 0x4000
} teCLD_BAS_ClusterID;


/* Power source */
typedef enum 
{
    E_CLD_BAS_PS_UNKNOWN                                            = 0x00,
    E_CLD_BAS_PS_SINGLE_PHASE_MAINS,
    E_CLD_BAS_PS_THREE_PHASE_MAINS,
    E_CLD_BAS_PS_BATTERY,
    E_CLD_BAS_PS_DC_SOURCE,
    E_CLD_BAS_PS_EMERGENCY_MAINS_CONSTANTLY_POWERED,
    E_CLD_BAS_PS_EMERGENCY_MAINS_AND_TRANSFER_SWITCH,
    E_CLD_BAS_PS_UNKNOWN_BATTERY_BACKED                                = 0x80,
    E_CLD_BAS_PS_SINGLE_PHASE_MAINS_BATTERY_BACKED,
    E_CLD_BAS_PS_THREE_PHASE_MAINS_BATTERY_BACKED,
    E_CLD_BAS_PS_BATTERY_BATTERY_BACKED,
    E_CLD_BAS_PS_DC_SOURCE_BATTERY_BACKED,
    E_CLD_BAS_PS_EMERGENCY_MAINS_CONSTANTLY_POWERED_BATTERY_BACKED,
    E_CLD_BAS_PS_EMERGENCY_MAINS_AND_TRANSFER_SWITCH_BATTERY_BACKED,
} teCLD_BAS_PowerSource;

/* Application Profile Type - APT */
typedef enum 
{
    E_CLD_BAS_APT_ZIGBEE_BUILDING_AUTOMATION                            = 0x00,
    E_CLD_BAS_APT_ZIGBEE_REMOTE_CONTROL,
    E_CLD_BAS_APT_ZIGBEE_SMART_ENERGY,
    E_CLD_BAS_APT_ZIGBEE_HEALTH_CARE,
    E_CLD_BAS_APT_ZIGBEE_HOME_AUTOMATION,
    E_CLD_BAS_APT_ZIGBEE_INPUT_DEVICE,
    E_CLD_BAS_APT_ZIGBEE_LIGHT_LINK,
    E_CLD_BAS_APT_ZIGBEE_RETAIL_SERVICES,
    E_CLD_BAS_APT_ZIGBEE_TELECOM_SERVICES
} teCLD_BAS_ApplicationProfileType;

/* Basic Cluster */
typedef struct
{
    zuint8                      u8ZCLVersion;

#ifdef CLD_BAS_ATTR_APPLICATION_VERSION
    zuint8                      u8ApplicationVersion;
#endif

#ifdef CLD_BAS_ATTR_STACK_VERSION
    zuint8                      u8StackVersion;
#endif

#ifdef CLD_BAS_ATTR_HARDWARE_VERSION
    zuint8                      u8HardwareVersion;
#endif

#ifdef CLD_BAS_ATTR_MANUFACTURER_NAME
    tsZCL_CharacterString       sManufacturerName;
    uint8                       au8ManufacturerName[32];
#endif

#ifdef CLD_BAS_ATTR_MODEL_IDENTIFIER
    tsZCL_CharacterString       sModelIdentifier;
    uint8                       au8ModelIdentifier[32];
#endif

#ifdef CLD_BAS_ATTR_DATE_CODE
    tsZCL_CharacterString       sDateCode;
    uint8                       au8DateCode[16];
#endif

    zenum8                      ePowerSource;

#ifdef CLD_BAS_ATTR_ID_APPLICATION_PROFILE_TYPE    
    zenum8                      eAppProfileType;
#endif

#ifdef CLD_BAS_ATTR_ID_APPLICATION_PROFILE_VERSION    
    uint32                       u32AppProfileVersion;
#endif
    
#ifdef CLD_BAS_ATTR_LOCATION_DESCRIPTION
    tsZCL_CharacterString       sLocationDescription;
    uint8                       au8LocationDescription[16];
#endif

#ifdef CLD_BAS_ATTR_PHYSICAL_ENVIRONMENT
    zenum8                      u8PhysicalEnvironment;
#endif

#ifdef CLD_BAS_ATTR_DEVICE_ENABLED
    zbool                       bDeviceEnabled;
#endif

#ifdef CLD_BAS_ATTR_ALARM_MASK
    zbmap8                      u8AlarmMask;
#endif

#ifdef CLD_BAS_ATTR_DISABLE_LOCAL_CONFIG
    zbmap8                      u8DisableLocalConfig;
#endif

#ifdef CLD_BAS_ATTR_SW_BUILD_ID
    tsZCL_CharacterString       sSWBuildID;
    uint8                   au8SWBuildID[16];
#endif

} tsCLD_Basic;


#ifdef CLD_SM_SUPPORT_MIRROR

/* Basic Cluster */
typedef struct
{
    zuint8                      u8ZCLVersion;

#ifdef CLD_BAS_MIRROR_ATTR_APPLICATION_VERSION
    zuint8                      u8ApplicationVersion;
#endif

#ifdef CLD_BAS_MIRROR_ATTR_STACK_VERSION
    zuint8                      u8StackVersion;
#endif

#ifdef CLD_BAS_MIRROR_ATTR_HARDWARE_VERSION
    zuint8                      u8HardwareVersion;
#endif

#ifdef CLD_BAS_MIRROR_ATTR_MANUFACTURER_NAME
    tsZCL_CharacterString       sManufacturerName;
    uint8                       au8ManufacturerName[32];
#endif

#ifdef CLD_BAS_MIRROR_ATTR_MODEL_IDENTIFIER
    tsZCL_CharacterString       sModelIdentifier;
    uint8                       au8ModelIdentifier[32];
#endif

#ifdef CLD_BAS_MIRROR_ATTR_DATE_CODE
    tsZCL_CharacterString       sDateCode;
    uint8                       au8DateCode[16];
#endif

    zenum8                      ePowerSource;

#ifdef CLD_BAS_ATTR_ID_APPLICATION_PROFILE_TYPE    
    zenum8                      eAppProfileType;
#endif

#ifdef CLD_BAS_ATTR_ID_APPLICATION_PROFILE_VERSION    
    uint32                       u32AppProfileVersion;
#endif
    
#ifdef CLD_BAS_MIRROR_ATTR_LOCATION_DESCRIPTION
    tsZCL_CharacterString       sLocationDescription;
    uint8                       au8LocationDescription[16];
#endif

#ifdef CLD_BAS_MIRROR_ATTR_PHYSICAL_ENVIRONMENT
    zenum8                      u8PhysicalEnvironment;
#endif

#ifdef CLD_BAS_MIRROR_ATTR_DEVICE_ENABLED
    zbool                       bDeviceEnabled;
#endif

#ifdef CLD_BAS_MIRROR_ATTR_ALARM_MASK
    zbmap8                      u8AlarmMask;
#endif

#ifdef CLD_BAS_MIRROR_ATTR_DISABLE_LOCAL_CONFIG
    zbmap8                      u8DisableLocalConfig;
#endif

} tsCLD_BasicMirror;


#endif


/* Definition of Basic Callback Event Structure */
typedef struct
{
    uint8                           u8CommandId;
} tsCLD_BasicCallBackMessage;


#ifdef CLD_SM_SUPPORT_MIRROR
tsZCL_ClusterDefinition sCLD_BasicMirror[CLD_SM_NUMBER_OF_MIRRORS];
#endif
/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC teZCL_Status eCLD_BasicCreateBasic(
                tsZCL_ClusterInstance              *psClusterInstance,
                bool_t                              bIsServer,
                tsZCL_ClusterDefinition            *psClusterDefinition,
                void                               *pvEndPointSharedStructPtr,
                uint8                              *pu8AttributeControlBits);

PUBLIC teZCL_Status eCLD_BasicCommandResetToFactoryDefaultsSend(
                    uint8                       u8SourceEndPointId,
                    uint8                       u8DestinationEndPointId,
                    tsZCL_Address               *psDestinationAddress,
                    uint8                       *pu8TransactionSequenceNumber);

#ifdef CLD_SM_SUPPORT_MIRROR
teZCL_Status eSE_RegisterMirroredBasicCluster(uint8 u8MirrorNum,
        tsZCL_ClusterInstance              *psClusterInstance,
        void                  *pvEndPointSharedStructPtr);
#endif

/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/
extern tsZCL_ClusterDefinition sCLD_Basic;
#ifdef BASIC_SERVER
    extern const tsZCL_AttributeDefinition asCLD_BasicClusterAttributeDefinitions[];
    extern uint8 au8BasicClusterAttributeControlBits[];
#endif    

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

#endif /* BASIC_H */

/*****************************************************************************
 *
 * MODULE:             ZCL Options
 *
 * COMPONENT:          zcl_options.h
 *
 * DESCRIPTION:        Options Header for ZigBee Cluster Library functions
 *                     [Color Scene Controller]
 *
 *****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products [NXP Microcontrollers such as JN5168, JN5179].
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
 * Copyright NXP B.V. 2016. All rights reserved
 *
 ***************************************************************************/

#ifndef ZCL_OPTIONS_H
#define ZCL_OPTIONS_H

#include <jendefs.h>

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
/****************************************************************************/
/*                      ZCL Specific initialization                         */
/****************************************************************************/
/* This is the NXP manufacturer code.If creating new a manufacturer         */
/* specific command apply to the Zigbee alliance for an Id for your company */
/* Also update the manufacturer code in .zpscfg: Node Descriptor->misc      */
/* Sets the number of endpoints that will be created by the ZCL library */
#define ZCL_MANUFACTURER_CODE                                0x1037

/* Number of endpoints supported by this device */
#define ZCL_NUMBER_OF_ENDPOINTS                             1

/* Set this Tue to disable non error default responses from clusters */
#define ZCL_DISABLE_DEFAULT_RESPONSES       (TRUE)
#define ZCL_DISABLE_APS_ACK                 (TRUE)

/* Enable wild card profile */
#define ZCL_ALLOW_WILD_CARD_PROFILE

/* Which Custom commands needs to be supported */
#define ZCL_ATTRIBUTE_READ_SERVER_SUPPORTED
#define ZCL_ATTRIBUTE_READ_CLIENT_SUPPORTED
#define ZCL_ATTRIBUTE_WRITE_SERVER_SUPPORTED

/****************************************************************************/
/*                             Enable Cluster                               */
/*                                                                          */
/* Add the following #define's to your zcl_options.h file to enable         */
/* cluster and their client or server instances                             */
/****************************************************************************/
#define CLD_BASIC
#define BASIC_SERVER
#define BASIC_CLIENT

#define CLD_ZLL_COMMISSION
#define ZLL_COMMISSION_CLIENT
#define ZLL_COMMISSION_SERVER

#define CLD_ZLL_UTILITY
#define ZLL_UTILITY_SERVER
#define ZLL_UTILITY_CLIENT

#define CLD_IDENTIFY
#define IDENTIFY_CLIENT
#define IDENTIFY_SERVER

#define CLD_GROUPS
#define GROUPS_CLIENT

#define CLD_ONOFF
#define ONOFF_CLIENT

#define CLD_LEVEL_CONTROL
#define LEVEL_CONTROL_CLIENT

#define CLD_SCENES
#define SCENES_CLIENT

#define CLD_COLOUR_CONTROL
#define COLOUR_CONTROL_CLIENT

/****************************************************************************/
/*             Basic Cluster - Optional Attributes                          */
/*                                                                          */
/* Add the following #define's to your zcl_options.h file to add optional   */
/* attributes to the basic cluster.                                         */
/****************************************************************************/
#define   CLD_BAS_ATTR_APPLICATION_VERSION
#define   CLD_BAS_ATTR_STACK_VERSION
#define   CLD_BAS_ATTR_HARDWARE_VERSION
#define   CLD_BAS_ATTR_MANUFACTURER_NAME
#define   CLD_BAS_ATTR_MODEL_IDENTIFIER
#define   CLD_BAS_ATTR_DATE_CODE
#define   CLD_BAS_ATTR_SW_BUILD_ID
#define   CLD_BAS_ATTR_GENERIC_DEVICE_CLASS
#define   CLD_BAS_ATTR_GENERIC_DEVICE_TYPE
#define   CLD_BAS_ATTR_PRODUCT_CODE
#define   CLD_BAS_ATTR_PRODUCT_URL

#define CLD_BAS_APP_VERSION         (1)
#define CLD_BAS_STACK_VERSION       (1)
#define CLD_BAS_HARDWARE_VERSION    (1)
#define CLD_BAS_MANUF_NAME_SIZE     (3)
#define CLD_BAS_MODEL_ID_SIZE       (17)
#define CLD_BAS_DATE_SIZE           (8)
#define CLD_BAS_POWER_SOURCE        E_CLD_BAS_PS_BATTERY
#define CLD_BAS_SW_BUILD_SIZE       (9)
#define CLD_BAS_URL_SIZE            (12)
#define CLD_BAS_PCODE_SIZE          (4)
#define CLD_BAS_DEVICE_CLASS        (0)

/****************************************************************************/
/*             TL Cluster - Optional Attributes                             */
/*                                                                          */
/* Add the following #define's to your zcl_options.h file to add optional   */
/* attributes to the TL cluster.                                            */
/****************************************************************************/
#define NUM_ENDPOINT_RECORDS        20
#define NUM_GROUP_RECORDS            4
/*
 * Use this if you have the ZLL Master Key
 */
//#define TL_SUPPORTED_KEYS ( TL_MASTER_KEY_MASK )
/*
 * Use the Test and Certification Keys
 */
#define TL_SUPPORTED_KEYS (TL_TEST_KEY_MASK | TL_CERTIFICATION_KEY_MASK )
#define TL_LEGACY_PROFILE_ID   (0xc05e);
#define TL_LEGACY_DEVICE_ID    (0x0810);
#define TL_LEGACY_VERSION_ID    (2)
/****************************************************************************/
/*             Colour Control Cluster - Optional Attributes                 */
/*                                                                          */
/* Add the following #define's to your zcl_options.h file to add optional   */
/* attributes to the time cluster.                                          */
/****************************************************************************/
#define CLD_COLOURCONTROL_RED_X     (0.68)  // 44564 -> 0xAE14
#define CLD_COLOURCONTROL_RED_Y     (0.31)  // 20316 -> 0x4F5C
#define CLD_COLOURCONTROL_GREEN_X   (0.11)  // 7208  -> 0x1C28
#define CLD_COLOURCONTROL_GREEN_Y   (0.82)  // 53739 -> 0xD1EB
#define CLD_COLOURCONTROL_BLUE_X    (0.13)  // 8519  -> 0x2147
#define CLD_COLOURCONTROL_BLUE_Y    (0.04)  // 2621   -> 0x0A3D
#define CLD_COLOURCONTROL_WHITE_X   (0.33)  // 21626 -> 0x5478
#define CLD_COLOURCONTROL_WHITE_Y   (0.33)  // 21626 -> 0x5478

/****************************************************************************/
/*             Scenes Cluster - Optional Attributes                         */
/*                                                                          */
/* Add the following #define's to your zcl_options.h file to add optional   */
/* attributes to the scenes cluster.                                        */
/****************************************************************************/
#define CLD_SCENES_MAX_SCENE_STORAGE_BYTES                  22

/****************************************************************************/
/*             Basic Cluster - Optional Commands                            */
/*                                                                          */
/* Add the following #define's to your zcl_options.h file to add optional   */
/* commands to the basic cluster.                                           */
/****************************************************************************/
#define CLD_BAS_CMD_RESET_TO_FACTORY_DEFAULTS

/****************************************************************************/
/*             Identify Cluster - Optional Commands                         */
/*                                                                          */
/* Add the following #define's to your zcl_options.h file to add optional   */
/* commands to the identify cluster.                                        */
/****************************************************************************/
#define  CLD_IDENTIFY_CMD_TRIGGER_EFFECT

/****************************************************************************/
/*             Scenes Cluster - Optional Commands                           */
/*                                                                          */
/* Add the following #define's to your zcl_options.h file to add optional   */
/* commands to the scenes cluster.                                          */
/****************************************************************************/
#define CLD_SCENES_CMD_COPY_SCENE
#define CLD_SCENES_CMD_ENHANCED_ADD_SCENE
#define CLD_SCENES_CMD_ENHANCED_VIEW_SCENE
/****************************************************************************/
/*             OnOff Cluster - Optional Commands                         */
/*                                                                          */
/* Add the following #define's to your zcl_options.h file to add optional   */
/* commands to the identify cluster.                                        */
/****************************************************************************/
#define CLD_ONOFF_CMD_OFF_WITH_EFFECT
#define CLD_ONOFF_CMD_ON_WITH_TIMED_OFF
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
PUBLIC void* psGetDeviceTable(void);
/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

#endif /* ZCL_OPTIONS_H */

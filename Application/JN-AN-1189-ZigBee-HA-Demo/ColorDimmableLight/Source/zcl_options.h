/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          zcl_options.h
 *
 * DESCRIPTION:        ZCL Options Header for ZHA ColorDimmableLight
 *
 ****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products [NXP Microcontrollers such as JN5168, JN5164,
 * JN5161, JN5148, JN5142, JN5139].
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
 * Copyright NXP B.V. 2013. All rights reserved
 *
 ***************************************************************************/

#ifndef ZCL_OPTIONS_H
#define ZCL_OPTIONS_H

#include <jendefs.h>

PUBLIC void vSaveScenesNVM(void);
PUBLIC void vLoadScenesNVM(void);
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#define COOPERATIVE
//#define HA_NO_APS_ACK
/* This is the NXP manufacturer code. If creating a new  manufacturer       */
/* specific command apply to the Zigbee alliance for an Id for your company */
/* Also update the manufacturer code in .zpscfg: Node Descriptor->misc      */

#define ZCL_MANUFACTURER_CODE                               CONFIG_MANUFACTURER_CODE

#define HA_NUMBER_OF_ZCL_APPLICATION_TIMERS                 3
#define HA_NUMBER_OF_ENDPOINTS                              1

/* Clusters used by this application */
#define CLD_BASIC
#define BASIC_SERVER

#define CLD_IDENTIFY
#define IDENTIFY_SERVER
#define CLD_IDENTIFY_TICKS_PER_SECOND                       10

#define CLD_GROUPS
#define GROUPS_SERVER
#define CLD_GROUPS_MAX_NUMBER_OF_GROUPS                     8
#define CLD_GROUPS_DISABLE_NAME_SUPPORT


#define CLD_ONOFF
#define ONOFF_SERVER

#define CLD_LEVEL_CONTROL
#define LEVEL_CONTROL_SERVER
#define CLD_LEVELCONTROL_TICKS_PER_SECOND                   10
#define CLD_LEVELCONTROL_MIN_LEVEL                          (1)
#define CLD_LEVELCONTROL_MAX_LEVEL                          (0xFE)


#define CLD_SCENES
#define SCENES_SERVER
#define CLD_SCENES_MAX_NUMBER_OF_SCENES                     16
#define CLD_SCENES_DISABLE_NAME_SUPPORT
#define CLD_SCENES_MAX_SCENE_NAME_LENGTH                    0
#define CLD_SCENES_MAX_SCENE_STORAGE_BYTES                  16
#define CLD_SCENES_ATTR_LAST_CONFIGURED_BY

#define CLD_COLOUR_CONTROL
#define COLOUR_CONTROL_SERVER

/* #define CLD_GREENPOWER */
#ifdef  CLD_GREENPOWER
    #define GREENPOWER_END_POINT_ID                             2
    #define GP_NUMBER_OF_TRANSLATION_TABLE_ENTRIES            12
    #define GP_COMBO_MIN_DEVICE
    #define GP_COMMISSION_WINDOW_DURATION 180
    #define CLD_GP_ATTR_ZGPS_COMMISSIONING_WINDOW
    //#define GP_DISABLE_SECURITY_FOR_CERTIFICATION
    /* #define GP_SECURITY */
    #ifdef GP_SECURITY
        /* enable security related attributes */
        #define CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY_TYPE
        #define CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY
        #define CLD_GP_ATTR_ZGP_LINK_KEY

        /* security level */
        #define GP_SECURITY_LEVEL E_GP_ENC_FULL_FC_FULL_MIC
        /* Possible values are  E_GP_NO_KEY, E_GP_ZIGBEE_NWK_KEY, E_GP_ZGPD_GROUP_KEY,
            E_GP_NWK_KEY_DERIVED_ZGPD_GROUP_KEY, E_GP_OUT_OF_THE_BOX_ZGPD_KEY, E_GP_DERIVED_INDIVIDUAL_ZGPD_KEY*/
    #define GP_KEYTPE             ( E_GP_ZGPD_GROUP_KEY )

        /* security mode */

        #define GPD_SEC_PRECONFIG_MODE

        #ifdef GPD_SEC_PRECONFIG_MODE
            /* GP key  */
            #define GP_SHARED_KEY  { 0xC0 , 0xC1 , 0xC2 , 0xC3 , 0xC4 , 0xC5 , 0xC6 , 0xC7 , 0xC8 , 0xC9 , 0xCa , 0xCb , 0xCc , 0xCd , 0xCe , 0xCf }

        #endif
    #else
        #define GP_SECURITY_LEVEL  E_GP_NO_SECURITY
    #endif
    /* 3 endpoints are required when GP supported. Endpoint 1 supports HA dimmable light clusters, endpoint 242 green power endpoint,
     * endpoint 2 is mapped green power endpoint. */

    #undef HA_NUMBER_OF_ENDPOINTS
    #define HA_NUMBER_OF_ENDPOINTS                             3
#endif

#ifdef BUILD_OTA
#define CLD_OTA
#endif
#ifdef  CLD_OTA
    #define OTA_CLIENT
    #define OTA_CLD_ATTR_CURRENT_FILE_VERSION
    #define OTA_MAX_CO_PROCESSOR_IMAGES                     0
    #define OTA_MAX_BLOCK_SIZE                              48      // For 69 devices the optimum size is 48 - for 68 devices it is 64
    //#define OTA_ENABLE_IMAGE_RE_INSTALL                            //Enables the OTA to re install same image, if enabled the server must have a mechanism to prevent the device constantly downloading */
#ifdef OTA_DEMO_BUILD    
    #define OTA_TIME_INTERVAL_BETWEEN_RETRIES               5       // Valid only if OTA_TIME_INTERVAL_BETWEEN_REQUESTS not defined
    #define CLD_OTA_MAX_BLOCK_PAGE_REQ_RETRIES                12
#else        
    #define OTA_TIME_INTERVAL_BETWEEN_REQUESTS              RND_u32GetRand(10,20)
    #define OTA_TIME_INTERVAL_BETWEEN_RETRIES               360      // Every 6 minutes // Valid only if OTA_TIME_INTERVAL_BETWEEN_REQUESTS not defined
    #define CLD_OTA_MAX_BLOCK_PAGE_REQ_RETRIES                240      // Retry Try for a day- 24 Hrs @ OTA_TIME_INTERVAL_BETWEEN_REQUESTS before finding the server again .
#endif

    #ifdef JENNIC_CHIP_FAMILY_JN516x
        #define OTA_MAX_IMAGES_PER_ENDPOINT                 1
    #else
        #define OTA_MAX_IMAGES_PER_ENDPOINT                 2
    #endif
    #define OTA_STRING_COMPARE

    #if JENNIC_CHIP == JN5169
        #define OTA_INTERNAL_STORAGE
        #ifdef OTA_ENCRYPTED
            #define INTERNAL_ENCRYPTED
        #endif
    #endif
#endif

#define CLD_BIND_SERVER
#define MAX_NUM_BIND_QUEUE_BUFFERS                             10
#define MAX_PDU_BIND_QUEUE_PAYLOAD_SIZE                       24

/****************************************************************************/
/*             Basic Cluster - Optional Attributes                          */
/*                                                                          */
/* Add the following #define's to your zcl_options.h file to add optional   */
/* attributes to the basic cluster.                                         */
/****************************************************************************/
#define ZCL_ATTRIBUTE_DISCOVERY_SERVER_SUPPORTED
#define ZCL_ATTRIBUTE_DISCOVERY_CLIENT_SUPPORTED
#define ZCL_ATTRIBUTE_READ_SERVER_SUPPORTED
#define ZCL_ATTRIBUTE_READ_CLIENT_SUPPORTED
#define ZCL_ATTRIBUTE_WRITE_SERVER_SUPPORTED
#define ZCL_ATTRIBUTE_REPORTING_SERVER_SUPPORTED
#define ZCL_ATTRIBUTE_REPORTING_CLIENT_SUPPORTED
#define ZCL_CONFIGURE_ATTRIBUTE_REPORTING_SERVER_SUPPORTED
#define ZCL_READ_ATTRIBUTE_REPORTING_CONFIGURATION_SERVER_SUPPORTED

#define HA_NUMBER_OF_REPORTS                 7
#define HA_SYSTEM_MIN_REPORT_INTERVAL       1
#define HA_SYSTEM_MAX_REPORT_INTERVAL       0x3c

#define CLD_BAS_ATTR_APPLICATION_VERSION
#define CLD_BAS_ATTR_STACK_VERSION
#define CLD_BAS_ATTR_HARDWARE_VERSION
#define CLD_BAS_ATTR_MANUFACTURER_NAME
#define CLD_BAS_ATTR_MODEL_IDENTIFIER
#define CLD_BAS_ATTR_DATE_CODE
#define CLD_BAS_CMD_RESET_TO_FACTORY_DEFAULTS

#define CLD_BAS_STACK_VERSION       (2)
#define CLD_BAS_POWER_SOURCE        E_CLD_BAS_PS_SINGLE_PHASE_MAINS


/****************************************************************************/
/*             Level Control Cluster - Optional Attributes                  */
/*                                                                          */
/* Add the following #define's to your zcl_options.h file to add optional   */
/* attributes to the level control cluster.                                 */
/****************************************************************************/

/* #define CLD_LEVELCONTROL_ATTR_REMAINING_TIME */
/* #define CLD_LEVELCONTROL_ATTR_ON_LEVEL       */
#define CLD_LEVELCONTROL_ATTR_ON_OFF_TRANSITION_TIME   3

/****************************************************************************/
/*             Scenes Cluster - Optional Attributes                         */
/*                                                                          */
/* Add the following #define's to your zcl_options.h file to add optional   */
/* attributes to the scenes cluster.                                        */
/****************************************************************************/

/****************************************************************************/
/*             Colour Control Cluster - Optional Attributes                 */
/*                                                                          */
/* Add the following #define's to your zcl_options.h file to add optional   */
/* attributes to the time cluster.                                          */
/****************************************************************************/
/* Colour information attribute set attribute ID's (5.2.2.2.1) */

#define CLD_COLOURCONTROL_ATTR_REMAINING_TIME
#define CLD_COLOURCONTROL_ATTR_COLOUR_MODE

/* Defined Primaries Information attribute attribute ID's set (5.2.2.2.2) */
#define CLD_COLOURCONTROL_ATTR_NUMBER_OF_PRIMARIES  3

#define CLD_COLOURCONTROL_RED_X     (0.68)
#define CLD_COLOURCONTROL_RED_Y     (0.31)
#define CLD_COLOURCONTROL_GREEN_X   (0.11)
#define CLD_COLOURCONTROL_GREEN_Y   (0.82)
#define CLD_COLOURCONTROL_BLUE_X    (0.13)
#define CLD_COLOURCONTROL_BLUE_Y    (0.04)
#define CLD_COLOURCONTROL_WHITE_X   (0.33)
#define CLD_COLOURCONTROL_WHITE_Y   (0.33)


#define CLD_COLOURCONTROL_PRIMARY_1_X           CLD_COLOURCONTROL_RED_X
#define CLD_COLOURCONTROL_PRIMARY_1_Y           CLD_COLOURCONTROL_RED_Y
#define CLD_COLOURCONTROL_PRIMARY_1_INTENSITY   (254 / 3)

#define CLD_COLOURCONTROL_PRIMARY_2_X           CLD_COLOURCONTROL_GREEN_X
#define CLD_COLOURCONTROL_PRIMARY_2_Y           CLD_COLOURCONTROL_GREEN_Y
#define CLD_COLOURCONTROL_PRIMARY_2_INTENSITY   (254 / 3)

#define CLD_COLOURCONTROL_PRIMARY_3_X           CLD_COLOURCONTROL_BLUE_X
#define CLD_COLOURCONTROL_PRIMARY_3_Y           CLD_COLOURCONTROL_BLUE_Y
#define CLD_COLOURCONTROL_PRIMARY_3_INTENSITY   (254 / 3)

#define CLD_COLOURCONTROL_PRIMARY_4_X           (0)
#define CLD_COLOURCONTROL_PRIMARY_4_Y           (0)
#define CLD_COLOURCONTROL_PRIMARY_4_INTENSITY   (0xff)

#define CLD_COLOURCONTROL_PRIMARY_5_X           (0)
#define CLD_COLOURCONTROL_PRIMARY_5_Y           (0)
#define CLD_COLOURCONTROL_PRIMARY_5_INTENSITY   (0xff)

#define CLD_COLOURCONTROL_PRIMARY_6_X           (0)
#define CLD_COLOURCONTROL_PRIMARY_6_Y           (0)
#define CLD_COLOURCONTROL_PRIMARY_6_INTENSITY   (0xff)

#define CLD_COLOURCONTROL_COLOUR_CAPABILITIES           (COLOUR_CAPABILITY_HUE_SATURATION_SUPPORTED | \
                                                         COLOUR_CAPABILITY_XY_SUPPORTED             | \
                                                         COLOUR_CAPABILITY_COLOUR_TEMPERATURE_SUPPORTED)


/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

#endif /* ZCL_OPTIONS_H */

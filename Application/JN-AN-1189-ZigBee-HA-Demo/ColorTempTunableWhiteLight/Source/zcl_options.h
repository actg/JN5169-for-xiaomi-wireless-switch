/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          zcl_options.h
 *
 * DESCRIPTION:        ZCL Options Header for ZHA CCTW
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
//#define CLD_COLOURCONTROL_COLOUR_TEMP_TUNABLE_WHITE_LIGHT
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
#define CLD_IDENTIFY_TICKS_PER_SECOND    10

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
    #ifdef GP_SECURITY
        #define CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY_TYPE
        #define CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY
        #define CLD_GP_ATTR_ZGP_LINK_KEY
        #define GP_SECURITY_LEVEL E_GP_ENC_FULL_FC_FULL_MIC
    #define GP_KEYTPE             ( E_GP_ZGPD_GROUP_KEY )
        #define GPD_SEC_PRECONFIG_MODE
        #ifdef GPD_SEC_PRECONFIG_MODE
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

#define CLD_BIND_SERVER
#define MAX_NUM_BIND_QUEUE_BUFFERS                             10
#define MAX_PDU_BIND_QUEUE_PAYLOAD_SIZE                       24

/****************************************************************************/
/*             Basic Cluster - Optional Attributes                          */
/*                                                                          */
/* Add the following #define's to your zcl_options.h file to add optional   */
/* attributes to the basic cluster.                                         */
/****************************************************************************/

#define ZCL_ATTRIBUTE_READ_SERVER_SUPPORTED
#define ZCL_ATTRIBUTE_WRITE_SERVER_SUPPORTED
#define ZCL_ATTRIBUTE_REPORTING_SERVER_SUPPORTED
#define ZCL_ATTRIBUTE_REPORTING_CLIENT_SUPPORTED
#define ZCL_CONFIGURE_ATTRIBUTE_REPORTING_SERVER_SUPPORTED
#define ZCL_READ_ATTRIBUTE_REPORTING_CONFIGURATION_SERVER_SUPPORTED

#define HA_NUMBER_OF_REPORTS            7
#define HA_SYSTEM_MIN_REPORT_INTERVAL   1
#define HA_SYSTEM_MAX_REPORT_INTERVAL   0x3c

#define CLD_BAS_ATTR_APPLICATION_VERSION
#define CLD_BAS_ATTR_STACK_VERSION
#define CLD_BAS_ATTR_HARDWARE_VERSION
#define CLD_BAS_ATTR_MANUFACTURER_NAME
#define CLD_BAS_ATTR_MODEL_IDENTIFIER
#define CLD_BAS_ATTR_DATE_CODE
#define CLD_BAS_ATTR_SW_BUILD_ID
#define CLD_BAS_CMD_RESET_TO_FACTORY_DEFAULTS

#define CLD_BAS_APP_VERSION         (1)
#define CLD_BAS_STACK_VERSION       (2)
#define CLD_BAS_HARDWARE_VERSION    (1)
#define CLD_BAS_MANUF_NAME_SIZE     (3)
#define CLD_BAS_MODEL_ID_SIZE       (22)
#define CLD_BAS_DATE_SIZE           (8)
#define CLD_BAS_POWER_SOURCE        E_CLD_BAS_PS_SINGLE_PHASE_MAINS
#define CLD_BAS_SW_BUILD_SIZE       (9)


#define CLD_ONOFF_ATTR_GLOBAL_SCENE_CONTROL
#define CLD_ONOFF_ATTR_ON_TIME
#define CLD_ONOFF_ATTR_OFF_WAIT_TIME


/****************************************************************************/
/*             Level Control Cluster - Optional Attributes                  */
/*                                                                          */
/* Add the following #define's to your zcl_options.h file to add optional   */
/* attributes to the level control cluster.                                 */
/****************************************************************************/

/*#define CLD_LEVELCONTROL_ATTR_REMAINING_TIME*/
#define CLD_LEVELCONTROL_ATTR_ON_OFF_TRANSITION_TIME    3
/*#define CLD_LEVELCONTROL_ATTR_ON_LEVEL*/

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

/* To support Move Color Temperature Command*/
#define CCTW_MOVE_TO_LIMIT
#define CLD_COLOURCONTROL_COLOUR_CAPABILITIES           (COLOUR_CAPABILITY_COLOUR_TEMPERATURE_SUPPORTED)
/* Max & Min Limits for colour temperature */
#define CLD_COLOURCONTROL_COLOUR_TEMPERATURE_PHY_MIN    (153U)  /* (1E6/153)   = 6500 Kelvin Colour Temperature */
#define CLD_COLOURCONTROL_COLOUR_TEMPERATURE_PHY_MAX    (370U)  /* (1E6/370) = 2700  Kelvin Colour Temperature */

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

/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          zcl_options.h
 *
 * DESCRIPTION:        ZCL Options Header for ZHA OTA Server
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
#define HA_NO_APS_ACK
/* This is the NXP manufacturer code.If creating new a manufacturer         */
/* specific command apply to the Zigbee alliance for an Id for your company */
/* Also update the manufacturer code in .zpscfg: Node Descriptor->misc      */

#define ZCL_MANUFACTURER_CODE                                0x1037

#define HA_NUMBER_OF_ZCL_APPLICATION_TIMERS                 3
#define HA_NUMBER_OF_ENDPOINTS                              2

/* Clusters used by this application */
#define CLD_BASIC
#define BASIC_SERVER

#define CLD_IDENTIFY
#define IDENTIFY_SERVER
#define CLD_IDENTIFY_TICKS_PER_SECOND                        10

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
#define CLD_LEVELCONTROL_MAX_LEVEL                          (0xfe)


#define CLD_SCENES
#define SCENES_SERVER
#define CLD_SCENES_MAX_NUMBER_OF_SCENES                     16
#define CLD_SCENES_DISABLE_NAME_SUPPORT
#define CLD_SCENES_MAX_SCENE_NAME_LENGTH                    0
#define CLD_SCENES_MAX_SCENE_STORAGE_BYTES                  10
#define CLD_SCENES_ATTR_LAST_CONFIGURED_BY

#define CLD_OTA
#ifdef    CLD_OTA
    #define OTA_SERVER
//    #define OTA_CLIENT
    #define OTA_MAX_CO_PROCESSOR_IMAGES                        0
    #define OTA_MAX_BLOCK_SIZE                                64
    #define OTA_TIME_INTERVAL_BETWEEN_RETRIES                5        // Valid only if OTA_TIME_INTERVAL_BETWEEN_REQUESTS not defined
    //#define OTA_TIME_INTERVAL_BETWEEN_REQUESTS            1
    //#define OTA_ACCEPT_ONLY_SIGNED_IMAGES
    #define OTA_COPY_MAC_ADDRESS
    #ifdef JENNIC_CHIP_FAMILY_JN516x
        //#define KEC_DECRYPT_PRIVATE_KEY
        #define OTA_MAX_IMAGES_PER_ENDPOINT                    1
    #else
        #define OTA_MAX_IMAGES_PER_ENDPOINT                    2
    #endif
    //#define OTA_MAINTAIN_CUSTOM_SERIALISATION_DATA
    //#define OTA_SIGNER_ADDRESS 2
    //#define OTA_NO_CERTIFICATE

    // Enable to test the abort from the server - TH 
    // The first block request response will be abort and further will pass through
    //#define OTA_SERVER_ABORT_DOWNLOAD_TEST_HARNESS


#endif


/* #define CLD_GREENPOWER */
#ifdef  CLD_GREENPOWER
#define GREENPOWER_END_POINT_ID                             2
#define GREENPOWER_MAX_TRANSLATION_TABLE_ENTRIES            10
#endif

#define CLD_TIME
#define TIME_SERVER
#define TIME_USE_NWK_SECURITY

/****************************************************************************/
/*             Basic Cluster - Optional Attributes                          */
/*                                                                          */
/* Add the following #define's to your zcl_options.h file to add optional   */
/* attributes to the basic cluster.                                         */
/****************************************************************************/

#define ZCL_ATTRIBUTE_READ_SERVER_SUPPORTED
#define ZCL_ATTRIBUTE_READ_CLIENT_SUPPORTED
#define ZCL_ATTRIBUTE_WRITE_SERVER_SUPPORTED
#define ZCL_ATTRIBUTE_REPORTING_SERVER_SUPPORTED
#define ZCL_CONFIGURE_ATTRIBUTE_REPORTING_SERVER_SUPPORTED
#define ZCL_READ_ATTRIBUTE_REPORTING_CONFIGURATION_SERVER_SUPPORTED

#define HA_NUMBER_OF_REPORTS 2
#define HA_SYSTEM_MIN_REPORT_INTERVAL   1
#define HA_SYSTEM_MAX_REPORT_INTERVAL   0x3c

#define CLD_BAS_ATTR_APPLICATION_VERSION
#define CLD_BAS_ATTR_STACK_VERSION
#define CLD_BAS_ATTR_HARDWARE_VERSION
#define CLD_BAS_ATTR_MANUFACTURER_NAME
#define CLD_BAS_ATTR_MODEL_IDENTIFIER
#define CLD_BAS_ATTR_DATE_CODE
#define CLD_BAS_ATTR_SW_BUILD_ID


#define CLD_BAS_APP_VERSION         (1)
#define CLD_BAS_STACK_VERSION       (2)
#define CLD_BAS_HARDWARE_VERSION    (1)
#define CLD_BAS_MANUF_NAME_SIZE     (3)
#define CLD_BAS_MODEL_ID_SIZE       (17)
#define CLD_BAS_DATE_SIZE           (8)
#define CLD_BAS_POWER_SOURCE        E_CLD_BAS_PS_SINGLE_PHASE_MAINS
#define CLD_BAS_SW_BUILD_SIZE       (9)

/* #define CLD_ONOFF_ATTR_GLOBAL_SCENE_CONTROL */
/* #define CLD_ONOFF_ATTR_ON_TIME              */
/* #define CLD_ONOFF_ATTR_OFF_WAIT_TIME        */

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

/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          zcl_options.h
 *
 * DESCRIPTION:        ZCL Options Header for ZHA Mains Power Outlet
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
/* Also update the manufacturer code in .zpscfg: Node Descriptor->misc      */
#define ZCL_MANUFACTURER_CODE                          0x1037

#define HA_NUMBER_OF_ZCL_APPLICATION_TIMERS         3
#define HA_NUMBER_OF_ENDPOINTS                         2

/* Clusters used by this application */
#define CLD_BASIC
#define BASIC_SERVER

#define CLD_IDENTIFY
#define IDENTIFY_SERVER

#define CLD_ONOFF
#define ONOFF_SERVER

#define CLD_SCENES
#define SCENES_SERVER

#define CLD_GROUPS
#define GROUPS_SERVER

//#define CLD_OTA
//#define OTA_CLIENT

/****************************************************************************/
/*             Basic Cluster - Configuration                                */
/****************************************************************************/
#define CLD_BAS_ATTR_APPLICATION_VERSION
#define CLD_BAS_ATTR_STACK_VERSION
#define CLD_BAS_ATTR_HARDWARE_VERSION
#define CLD_BAS_ATTR_MANUFACTURER_NAME
#define CLD_BAS_ATTR_MODEL_IDENTIFIER
#define CLD_BAS_ATTR_DATE_CODE
#define CLD_BAS_STACK_VERSION                       (2)
#define CLD_BAS_POWER_SOURCE                        E_CLD_BAS_PS_SINGLE_PHASE_MAINS

/****************************************************************************/
/*             Identify Cluster - Configuration                             */
/****************************************************************************/
#define CLD_IDENTIFY_TICKS_PER_SECOND               10

/****************************************************************************/
/*             Scenes Cluster - Configuration                               */
/****************************************************************************/
#define CLD_SCENES_MAX_NUMBER_OF_SCENES                16
#define CLD_SCENES_DISABLE_NAME_SUPPORT
#define CLD_SCENES_MAX_SCENE_NAME_LENGTH            0
#define CLD_SCENES_MAX_SCENE_STORAGE_BYTES          10
#define CLD_SCENES_ATTR_LAST_CONFIGURED_BY

/****************************************************************************/
/*             Groups Cluster - Configuration                               */
/****************************************************************************/
#define CLD_GROUPS_MAX_NUMBER_OF_GROUPS             8
#define CLD_GROUPS_DISABLE_NAME_SUPPORT

/****************************************************************************/
/*             OTA Cluster - Configuration                                  */
/****************************************************************************/
#define OTA_CLD_ATTR_CURRENT_FILE_VERSION
#define OTA_MAX_CO_PROCESSOR_IMAGES                  0
#define OTA_MAX_BLOCK_SIZE                            64
#define OTA_TIME_INTERVAL_BETWEEN_RETRIES               5
#define OTA_MAX_IMAGES_PER_ENDPOINT                   1

/****************************************************************************/
/*             Bind Server - Configuration                                  */
/****************************************************************************/
#define CLD_BIND_SERVER
#define MAX_NUM_BIND_QUEUE_BUFFERS                     10
#define MAX_PDU_BIND_QUEUE_PAYLOAD_SIZE               24

/****************************************************************************/
/*             Attribute Discovery - Configuration                          */
/****************************************************************************/
#define ZCL_ATTRIBUTE_DISCOVERY_SERVER_SUPPORTED
#define ZCL_ATTRIBUTE_DISCOVERY_CLIENT_SUPPORTED

/****************************************************************************/
/*             Attribute Read/Write - Configuration                         */
/****************************************************************************/
#define ZCL_ATTRIBUTE_READ_SERVER_SUPPORTED
#define ZCL_ATTRIBUTE_READ_CLIENT_SUPPORTED
#define ZCL_ATTRIBUTE_WRITE_SERVER_SUPPORTED

/****************************************************************************/
/*             Reporting - Configuration                                    */
/****************************************************************************/
#define HA_NUMBER_OF_REPORTS                         2
#define HA_SYSTEM_MIN_REPORT_INTERVAL               1
#define HA_SYSTEM_MAX_REPORT_INTERVAL               0x3c
#define ZCL_ATTRIBUTE_REPORTING_SERVER_SUPPORTED
#define ZCL_ATTRIBUTE_REPORTING_CLIENT_SUPPORTED
#define ZCL_CONFIGURE_ATTRIBUTE_REPORTING_SERVER_SUPPORTED
#define ZCL_READ_ATTRIBUTE_REPORTING_CONFIGURATION_SERVER_SUPPORTED

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

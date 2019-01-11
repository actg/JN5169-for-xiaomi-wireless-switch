/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          zha_remote_node.h
 *
 * DESCRIPTION:        ZHA Demo : Stack <-> Remote Control App Interaction
 *                     (Interface)
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

#ifndef APP_SENSOR_NODE_H_
#define APP_SENSOR_NODE_H_

#include "zps_nwk_sap.h"
#include "zps_nwk_nib.h"
#include "zps_nwk_pub.h"
#include "zps_apl.h"
#include "zps_apl_zdo.h"
#include "app_common.h"
#include "zcl_customcommand.h"
#include "app_led_control.h"
#ifdef PDM_EEPROM
 #include "app_pdm.h"
#endif

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#define NUMBER_DEVICE_TO_BE_DISCOVERED 5

#define MOVE_COLOUR_TEMPERATURE_MIN                 0 //153 /*ColourTempMin = 1E6/6500 */ By setting these to 0 - the color temperature will be limited by the bulb
#define MOVE_COLOUR_TEMPERATURE_MAX                 0 //370 /*ColourTempMax = 1E6/2700 */
#define COLOUR_TEMP_CHANGE_STEPS_PER_SEC            100
#define MOVE_TO_COLOUR_TEMP_IN_TRANSITION_TIME      0
#define LEVEL_CHANGE_STEPS_PER_SEC_SLOW             (20)
#define LEVEL_CHANGE_STEPS_PER_SEC_MED              (60)
#define LEVEL_CHANGE_STEPS_PER_SEC_FAST             (100)
#define HUE_CHANGE_STEPS_PER_SEC                    (20)
#define SATURATION_CHANGE_STEPS_PER_SEC             (20)
#define IDENTIFY_TIME_IN_SECS                       5
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
typedef struct{
    uint16 u16Address;
    uint16 u16ProfileId;
    uint16 u16DeviceId;
    uint8 u8Ep;
    uint8 u8NumberOfUcasts;
}tsMatchDev;

typedef struct{
    uint8 u8Index;
    uint8 u8Discovered;
    tsMatchDev sMatchDev[NUMBER_DEVICE_TO_BE_DISCOVERED];
}tsDeviceState;

typedef enum{
    SCENE_1=1,
    SCENE_2,
    SCENE_3,
    SCENE_4
}te_ScenesId;
/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC void APP_vInitialiseNode(void);
PUBLIC bool bLightsDiscovered(void);
PUBLIC void vInitCommission();
PUBLIC void vStartFastPolling(uint8 u8Seconds);

#ifdef SLEEP_ENABLE
    PUBLIC void vReloadSleepTimers(void);
    PUBLIC void vUpdateKeepAliveTimer(void);
    PUBLIC bool bWatingToSleep(void);
    PUBLIC void vWakeCallBack(void);
    #ifdef DEEP_SLEEP_ENABLE
        PUBLIC void vLoadDeepSleepTimer(uint8 u8SleepTime);
        PUBLIC void vSetUpWakeUpConditions(void);
    #endif
#endif

#ifdef CLD_SCENES
PUBLIC void vAppRecallSceneById(uint8 u8SceneId, uint16 u16GroupId);
PUBLIC void vAppEnhancedAddScene(uint8 u8Scene, uint16 u16GroupId);
PUBLIC void vAppEnhancedViewScene(uint8 u8SceneId, uint16 u16GroupId);
PUBLIC void vAppStoreSceneById(uint8 u8SceneId, uint16 u16GroupId);
#endif
PUBLIC void vAppDiscover(void);
PUBLIC void vSetTheNextLightIdentify(void);
PUBLIC void vAppChangeChannel( void);

/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/
extern tsDeviceState sDeviceState;
extern const uint8 u8MyEndpoint;
extern bool_t bAddrMode;
#ifdef RemoteControl
    extern bool_t bReadyToGroup;
#endif
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#endif /*APP_SENSOR_NDOE_H_*/

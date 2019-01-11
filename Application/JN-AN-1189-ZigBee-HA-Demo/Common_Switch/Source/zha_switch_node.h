/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          zha_switch_node.h
 *
 * DESCRIPTION:        ZHA Demo : Stack <-> Switch App Interaction
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
#ifdef PDM_EEPROM
 #include "app_pdm.h"
#endif
#ifdef CLD_OTA
#include "ota.h"
#endif
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#define BOARD_LED_D1_BIT               (11)


#define BOARD_LED_D1_PIN               (1UL << BOARD_LED_D1_BIT)
#define BOARD_LED_CTRL_MASK            (BOARD_LED_D1_PIN)

#ifdef DEEP_SLEEP_ENABLE
    #define DEEP_SLEEP_TIME 4 /* drop in the deep sleep after 4*12 secs + last iteration = 1 minutes */
#endif
#define APP_IDENTIFY_TIME_IN_SECS    5
#define NUMBER_DEVICE_TO_BE_DISCOVERED 5
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
/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC void APP_vInitialiseNode(void);
PUBLIC bool bLightsDiscovered(void);
PUBLIC void vInitCommission();
PUBLIC void vSetGroupAddress(uint16 u16GroupStart, uint8 u8NumGroups);
PUBLIC void APP_vSetLeds(bool bLed1On, bool bLed2On);
PUBLIC void vStartFastPolling(uint8 u8Seconds);

PUBLIC void vAppOnOff(teCLD_OnOff_Command eCmd);
PUBLIC void vAppLevelStepMove(teCLD_LevelControl_MoveMode eMode);
PUBLIC void vAppLevelMove(teCLD_LevelControl_MoveMode eMode, uint8 u8Rate, bool_t bWithOnOff);
PUBLIC void vAppLevelStop(void);

PUBLIC void vAppIdentify(uint16 u16Time);
PUBLIC void vAppIdentifyEffect(teCLD_Identify_EffectId eEffect);

PUBLIC void vSelectLight(void);

PUBLIC void vAppAddGroup(uint16 u16GroupId, bool_t bBroadcast);
PUBLIC void vAppRemoveGroup(uint16 u16GroupId, bool_t bBroadcast);
PUBLIC void vAppRemoveAllGroups(bool_t bBroadcast);

#ifdef SLEEP_ENABLE
    PUBLIC void vReloadSleepTimers(void);
    PUBLIC void vUpdateKeepAliveTimer(void);
    PUBLIC bool bWatingToSleep(void);
    PUBLIC void vWakeCallBack(void);
    #ifdef DEEP_SLEEP_ENABLE
        PUBLIC void vLoadDeepSleepTimer(uint8 u8SleepTime);
        PUBLIC bool bGoingDeepSleep(void);
    #endif
#endif

#ifdef CLD_SCENES
PUBLIC void vAppRecallSceneById(uint8 u8SceneId, uint16 u16GroupId);
PUBLIC void vAppEnhancedAddScene(uint8 u8Scene, uint16 u16GroupId);
PUBLIC void vAppEnhancedViewScene(uint8 u8SceneId, uint16 u16GroupId);
PUBLIC void vAppStoreSceneById(uint8 u8SceneId, uint16 u16GroupId);
#endif

PUBLIC void vAppIdentifyQuery(void);
PUBLIC void APP_vBlinkLeds(void);


PUBLIC void vAppDiscover(void);
PUBLIC void vSetThePrevLightIdentify(void);
PUBLIC void vSetTheNextLightIdentify(void);
PUBLIC void vAppChangeChannel( void);

PUBLIC teNODE_STATES eGetNodeState(void);

#ifdef CLD_OTA
PUBLIC tsOTA_PersistedData sGetOTACallBackPersistdata(void);
PUBLIC tsOTA_PersistedData * psGetOTACallBackPersistdata(void);
#endif
PUBLIC void vPingUCASTTarget(void);
/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/
extern PUBLIC tsDeviceState sDeviceState;
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#endif /*APP_SENSOR_NDOE_H_*/

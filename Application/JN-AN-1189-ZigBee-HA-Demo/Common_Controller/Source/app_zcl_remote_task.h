/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          app_zcl_remote_task.h
 *
 * DESCRIPTION:        ZHA Remote Control Behavior (Interface)
 *
 *****************************************************************************
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
 ****************************************************************************/

#ifndef APP_ZCL_TASK_H_
#define APP_ZCL_TASK_H_

/****************************************************************************/
/***        Include Files                                                 ***/
/****************************************************************************/
#include <jendefs.h>
#include "zcl.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#define ZCL_TICK_TIME           APP_TIME_MS(1000)

#define APP_THRESHOLD_TO_SEND_READ_ATTR   5
#define APP_THRESHOLD_FORCE_ROUTE_DISCOVERY (APP_THRESHOLD_TO_SEND_READ_ATTR+3)
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
PUBLIC void APP_ZCL_vInitialise(void);
PUBLIC void APP_ZCL_vSendHAOnOff(teCLD_OnOff_Command eCmd);
PUBLIC void APP_ZCL_vSendHAStepLevel(teCLD_LevelControl_MoveMode eMode);
PUBLIC void APP_ZCL_vSendHAMoveLevel(teCLD_LevelControl_MoveMode eMode, uint8 u8Rate, bool_t bWithOnOff);
PUBLIC void APP_ZCL_vSendHAStopLevel(void);
PUBLIC void APP_ZCL_vSendHAIdentify(uint16 u16Time);
PUBLIC void APP_ZCL_vSendHAIdentifyQuery(void);
PUBLIC void APP_ZCL_vSendHAAddGroup(uint16 u16GroupId);
PUBLIC void APP_ZCL_vSendHARemoveGroup(uint16 u16GroupId);
PUBLIC void APP_ZCL_vSendHARemoveAllGroups(bool_t bBroadcast);
PUBLIC void APP_ZCL_vSendHAMoveToLevel(tsZCL_Address sAddress, uint8 u8CurrentLevel, uint16 u16TransitionTime,bool_t bWithOnOff);
PUBLIC void vPingUCASTTarget(void);

#ifdef CLD_COLOUR_CONTROL
    PUBLIC void APP_ZCL_vSendHAMoveToColourTemperature(uint16 u16ColorTemp,uint16 u16TransitionTime);
    PUBLIC teZCL_Status eCLD_ColourControlCommandMoveColourTemperatureCommandSend(
            uint8                                                   u8SourceEndPointId,
            uint8                                                   u8DestinationEndPointId,
            tsZCL_Address                                           *psDestinationAddress,
            uint8                                                   *pu8TransactionSequenceNumber,
            tsCLD_ColourControl_MoveColourTemperatureCommandPayload *psPayload);
    PUBLIC void APP_ZCL_vSendHAMoveColourTemperature( teCLD_ColourControl_MoveMode eMode,
                                           uint16 u16StepsPerSec,
                                           uint16 u16ColourTemperatureMin,
                                           uint16 u16ColourTemperatureMax);

    PUBLIC void APP_ZCL_vSendHAMoveSaturation( teCLD_ColourControl_MoveMode eMode,
                                    uint8                        u8Rate);
    PUBLIC void APP_ZCL_vSendHAMoveHue( teCLD_ColourControl_MoveMode eMode,
                             uint8                        u8Rate);
    PUBLIC void APP_ZCL_vSendHAMoveToColour( uint8 u8Colour);
    PUBLIC void APP_ZCL_vSendHAMovetoHueAndSat( uint8 u8Direction);
#endif


/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

#endif /* APP_ZCL_TASK_H_ */

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

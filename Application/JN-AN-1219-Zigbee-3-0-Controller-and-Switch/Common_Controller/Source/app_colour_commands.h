/*****************************************************************************
 *
 * MODULE:             JN-AN-1219
 *
 * COMPONENT:          
 *
 * DESCRIPTION:        ZLO Demo: Remote Control Functionality -Interface
 *
 ****************************************************************************
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

#ifndef APP_COLOUR_COMMANDS_H_
#define APP_COLOUR_COMMANDS_H_

#include "ColourControl.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#define SAT_CHANGE_STEPS_PER_SEC        (20)
#define COL_TEMP_CHANGE_STEPS_PER_SEC   (100)
#define COL_TEMP_PHY_MIN                (0U)       /* Seting these two paramters to zero means the colour temperature    */
#define COL_TEMP_PHY_MAX                (0U)       /* is limited by the bulb capabilities, not what the remote sends out */
#define STOP_COLOUR_LOOP                FALSE

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
#ifdef CLD_COLOUR_CONTROL
PUBLIC void vAppMoveSaturation(teCLD_ColourControl_MoveMode eMode, uint8 u8StepsPerSec);
PUBLIC void vAppStepSaturation(teCLD_ColourControl_StepMode eMode, uint8 u8StepSize);
PUBLIC void vAppMoveToHue(uint8 u8Hue, teCLD_ColourControl_Direction eDirection, uint16 u16TransitionTime);
PUBLIC void vAppEnhancedMoveToHue(uint16 u16Hue, teCLD_ColourControl_Direction eDirection);
PUBLIC void vAppMoveToHueAndSaturation(uint8 u8Hue, uint8 u8Saturation, uint16 u16Time);
PUBLIC void vAppEnhancedMoveToHueAndSaturation(uint16 u16Hue, uint8 u8Saturation, uint16 u16Time);
PUBLIC void vAppGotoColour(void /*uint8 u8Colour*/);
PUBLIC void vAppMoveColour(int16 i16RateX, int16 i16RateY);
PUBLIC void vAppStepColour(int16 i16StepX, int16 i16StepY, uint16 u16TransitionTime);
PUBLIC void vAppMoveHue(teCLD_ColourControl_MoveMode eMode, uint8 u8StepsPerSec);
PUBLIC void vAppEnhancedMoveHue(teCLD_ColourControl_MoveMode eMode, uint16 u16StepsPerSec);
PUBLIC void vAppStepHue(teCLD_ColourControl_StepMode eMode, uint8 u8StepSize, uint8 u8TransitionTime);
PUBLIC void vAppEnhancedStepHue(teCLD_ColourControl_StepMode eMode, uint16 u16StepSize, uint16 u16TransitionTime);
PUBLIC void vAppMoveToSaturaiton(uint8 u8Saturation, uint16 u16TransitionTime);
PUBLIC void vAppStepColourTemperature(teCLD_ColourControl_StepMode eMode, uint16 u16StepSize);
PUBLIC void vAppStepMoveStop(void);
PUBLIC void vAppMoveToColourTemperature(uint16 u16ColourTemperatureMired, uint16 u16TransitionTime);
PUBLIC void vAppMoveColourTemperature(teCLD_ColourControl_MoveMode eMode, uint16 u16StepsPerSec, uint16 u16ColourTemperatureMin, uint16 u16ColourTemperatureMax);
PUBLIC void vAppColorLoopSet(uint8 u8UpdateFlags, teCLD_ColourControl_LoopAction eAction,teCLD_ColourControl_LoopDirection eDirection, uint16 u16Time, uint16 u16StartHue);
PUBLIC void vAppStopMoveStep();
PUBLIC void vAppGotoHueAndSat( uint8 u8Direction);
PUBLIC void vAPPColourLoopStop(void);
#endif





/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/



/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#endif /*APP_COLOUR_COMMANDS_H__*/

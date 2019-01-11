/*****************************************************************************
 *
 * MODULE:          JN-AN-1189
 *
 * COMPONENT:       app_switch_state_machine.h
 *
 * DESCRIPTION:     ZHA Demo: Remote Key Press Behaviour (Interface)
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
#ifndef APP_SWITCH_STATE_MACHINE_H_
#define APP_SWITCH_STATE_MACHINE_H_

/****************************************************************************/
/***        Include Files                                                 ***/
/****************************************************************************/
#include <jendefs.h>
#include "zcl.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#define BUTTON_DELAY_TIME_IN_MS 250

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

typedef enum{
    SCENE_1=1,
    SCENE_2
}te_ScenesId;

typedef enum{
    LIGHT_CONTROL_MODE,
    IDENTIFY_MODE,
    INDIVIDUAL_CONTROL_MODE,
    EZMODE_FIND_AND_BIND_MODE,
    NUMBER_OF_MODES
}te_SwitchState;

/* Kindly Maintain the order as the button numbers are assigned directly */

typedef enum{
    COMM_BUTTON_PRESSED,
    DOWN_PRESSED,
    ON_PRESSED,
    OFF_PRESSED,
    UP_PRESSED,
    UP_AND_ON_TOGETHER_PRESSED,
    UP_AND_OFF_TOGETHER_PRESSED,
    DOWN_AND_OFF_TOGETHER_PRESSED,
    DOWN_AND_ON_TOGETHER_PRESSED,
    COMM_AND_ON_TOGETHER_PRESSED,
    COMM_AND_OFF_TOGETHER_PRESSED,
    COMM_AND_UP_TOGETHER_PRESSED,
    COMM_AND_DOWN_TOGETHER_PRESSED,
    COMM_BUTTON_RELEASED,
    UP_RELEASED,
    DOWN_RELEASED,
    NUMBER_OF_TRANSITION_CODE
}te_TransitionCode;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC void vApp_ProcessKeyCombination(APP_tsEvent sButton);
PUBLIC te_SwitchState eGetSwitchState(void);
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

#endif /* APP_SWITCH_STATE_MACHINE_H_ */
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

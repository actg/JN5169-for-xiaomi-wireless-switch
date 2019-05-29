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

#ifndef APP__H_
#define aPP__NODEH_

#include "app_led_control.h"
#ifdef DR1159
#include "app_captouch_buttons.h"
#endif

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
#ifdef DR1199
/*
 * Alturnative key codes for use with the GUI
 */
typedef enum
{
    BUTTON_1,
    BUTTON_SW1,
    BUTTON_SW2,
    BUTTON_SW3,
    BUTTON_SW4,
    KEY_1 = 0x10,
    KEY_2,
    KEY_3,
    KEY_4,

    KEY_5,
    KEY_6,
    KEY_7,
    KEY_8,

    KEY_9,
    KEY_10,
    KEY_11,
    KEY_12,

    KEY_13,
    KEY_14,
    KEY_15,
    KEY_16,

} teUserKeyCodes;
#endif


/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
PUBLIC void APP_vHandleFactoryNewKeyPress(teUserKeyCodes eKeyCode);
PUBLIC void APP_vHandleKeyPress(teUserKeyCodes eKeyCode);
PUBLIC void APP_vHandleKeyRelease(teUserKeyCodes eKeyCode);


/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/
extern PUBLIC teShiftLevel eShiftLevel;


/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#endif /*APP___H_*/

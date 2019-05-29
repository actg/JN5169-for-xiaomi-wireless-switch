/*****************************************************************************
 *
 * MODULE:             JN-AN-1219
 *
 * COMPONENT:          app_led_control.h
 *
 * DESCRIPTION:        ZLO Demo -Led Control interface
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

#ifndef APP_LED_CONTROL_H
#define APP_LED_CONTROL_H

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/


typedef enum
{
    E_SHIFT_0,
    E_SHIFT_1,
    E_SHIFT_2,
    E_SHIFT_3
}teShiftLevel;

#ifdef DR1199
#if (JENNIC_CHIP_FAMILY == JN516x)
#define BOARD_LED_D1_BIT               (16)
#define BOARD_LED_D2_BIT               (13)
#else
#define BOARD_LED_D1_BIT               (8)
#define BOARD_LED_D2_BIT               (14)
#endif

#define BOARD_LED_D1_PIN               (1UL << BOARD_LED_D1_BIT)
#define BOARD_LED_D2_PIN               (1UL << BOARD_LED_D2_BIT)
#define BOARD_LED_CTRL_MASK            (BOARD_LED_D1_PIN | BOARD_LED_D2_PIN)

#define LED1    1
#define LED2    2

#endif


/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC void APP_vInitLeds(void);
PUBLIC void APP_vBlinkLeds(teShiftLevel eShiftLevel);
PUBLIC void APP_vSetLeds(teShiftLevel eShiftLevel);
PUBLIC void APP_cbTimerLedBlink(void *pvParam);

/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#endif /*APP_LED_CONTROL_H*/

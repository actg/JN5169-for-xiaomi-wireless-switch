/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          app_occupancy_buttons.h
 *
 * DESCRIPTION:        DK4 (DR1175/DR1199) Button Press detection (Implementation)
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

#ifndef APP_BUTTONS_H
#define APP_BUTTONS_H

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

#if (defined BUTTON_MAP_DR1199)

    typedef enum {
        APP_E_BUTTONS_BUTTON_1 = 0,
        APP_E_BUTTONS_BUTTON_SW4,
        APP_E_BUTTONS_BUTTON_SW3,
        APP_E_BUTTONS_BUTTON_SW2,
        APP_E_BUTTONS_BUTTON_SW1
    } APP_teButtons;

    #define APP_BUTTONS_NUM             (5UL)
    #define APP_BUTTONS_BUTTON_1        (8)
    #define APP_BUTTONS_BUTTON_SW4        (1)
    #define APP_BUTTONS_BUTTON_SW3        (17)
    #define APP_BUTTONS_BUTTON_SW2        (12)
    #define APP_BUTTONS_BUTTON_SW1        (11)
    #define APP_BUTTONS_DIO_MASK        ((1 << APP_BUTTONS_BUTTON_1)|(1 << APP_BUTTONS_BUTTON_SW4) | (1 << APP_BUTTONS_BUTTON_SW3) | (1 << APP_BUTTONS_BUTTON_SW2) | (1 << APP_BUTTONS_BUTTON_SW1))
    #define APP_BUTTONS_DIO_MASK_FOR_DEEP_SLEEP        ((1 << APP_BUTTONS_BUTTON_SW4) | (1 << APP_BUTTONS_BUTTON_SW3) | (1 << APP_BUTTONS_BUTTON_SW2) | (1 << APP_BUTTONS_BUTTON_SW1))

#else
    typedef enum {
        APP_E_BUTTONS_BUTTON_1
    } APP_teButtons;

    #define APP_BUTTONS_NUM             (1UL)
    #define APP_BUTTONS_BUTTON_1        (8)
    #define APP_BUTTONS_DIO_MASK        (1 << APP_BUTTONS_BUTTON_1)
#endif

typedef enum {
    E_INTERRUPT_UNKNOWN,
    E_INTERRUPT_BUTTON,
    E_INTERRUPT_WAKE_TIMER_EXPIRY
} teInterruptType;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
PUBLIC void APP_bButtonInitialise(void);
extern PUBLIC void vCbSystemControllerOTAVoltageCheck(uint32 u32DeviceId, uint32 u32ItemBitmap);
PUBLIC void vActionOnButtonActivationAfterDeepSleep(void);
PUBLIC void vSaveDioStateBeforeDeepSleep(void);
PUBLIC bool_t bGetPreSleepOccupancyState(void);

/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#endif /*APP_BUTTONS_H*/

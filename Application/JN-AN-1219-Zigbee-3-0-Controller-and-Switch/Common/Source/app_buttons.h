/*****************************************************************************
 *
 * MODULE:             JN-AN-1219
 *
 * COMPONENT:          app_buttons.h
 *
 * DESCRIPTION:        DK4 (DR1175/DR1199) Button Press detection (Interface)
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
 * Copyright NXP B.V. 2017. All rights reserved
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
    #if (defined APP_NTAG_ICODE) || (defined APP_NTAG_AES)
        typedef enum {
            APP_E_BUTTONS_BUTTON_1 = 0,
            APP_E_BUTTONS_BUTTON_SW1,
            APP_E_BUTTONS_BUTTON_SW2,
            APP_E_BUTTONS_BUTTON_SW3,
            APP_E_BUTTONS_BUTTON_SW4,
            APP_E_BUTTONS_NFC_FD /* Used for NTAG Field Detection */
        } APP_teButtons;
        #define APP_BUTTONS_NUM             (6UL)
        #if (JENNIC_CHIP_FAMILY == JN516x)
            #define APP_BUTTONS_BUTTON_1        (8)
            #define APP_BUTTONS_BUTTON_SW1      (11)
            #define APP_BUTTONS_BUTTON_SW2      (12)
            #define APP_BUTTONS_BUTTON_SW3      (17)
            #define APP_BUTTONS_BUTTON_SW4      (1)
            #define APP_BUTTONS_NFC_FD          (0)
        #elif (JENNIC_CHIP_FAMILY == JN517x)
            #define APP_BUTTONS_BUTTON_1        (4)
            #define APP_BUTTONS_BUTTON_SW1      (12)
            #define APP_BUTTONS_BUTTON_SW2      (13)
            #define APP_BUTTONS_BUTTON_SW3      (18)
            #define APP_BUTTONS_BUTTON_SW4      (5)
            #define APP_BUTTONS_NFC_FD          (17)
        #endif
        #define APP_BUTTONS_DIO_MASK        ((1 << APP_BUTTONS_BUTTON_1) | (1 << APP_BUTTONS_BUTTON_SW4) | (1 << APP_BUTTONS_BUTTON_SW3) | (1 << APP_BUTTONS_BUTTON_SW2) | (1 << APP_BUTTONS_BUTTON_SW1) | (1 << APP_BUTTONS_NFC_FD))
        #define APP_BUTTONS_DIO_MASK_FOR_DEEP_SLEEP        ((1 << APP_BUTTONS_BUTTON_SW4) | (1 << APP_BUTTONS_BUTTON_SW3) | (1 << APP_BUTTONS_BUTTON_SW2) | (1 << APP_BUTTONS_BUTTON_SW1) | (1 << APP_BUTTONS_NFC_FD))

    #else
        typedef enum {
            APP_E_BUTTONS_BUTTON_1 = 0,
            APP_E_BUTTONS_BUTTON_SW1
        } APP_teButtons;

		//for XiaoMi wireless switch
        #define APP_BUTTONS_NUM             (2UL)
        #if (JENNIC_CHIP_FAMILY == JN516x)
            #define APP_BUTTONS_BUTTON_1        (0)
            #define APP_BUTTONS_BUTTON_SW1      (16)
        #elif (JENNIC_CHIP_FAMILY == JN517x)
            #define APP_BUTTONS_BUTTON_1        (4)
            #define APP_BUTTONS_BUTTON_SW1      (12)
            #define APP_BUTTONS_BUTTON_SW2      (13)
            #define APP_BUTTONS_BUTTON_SW3      (18)
            #define APP_BUTTONS_BUTTON_SW4      (5)
        #endif
        #define APP_BUTTONS_DIO_MASK        ((1 << APP_BUTTONS_BUTTON_1) | (1 << APP_BUTTONS_BUTTON_SW1))
        #define APP_BUTTONS_DIO_MASK_FOR_DEEP_SLEEP        ((1 << APP_BUTTONS_BUTTON_1) | (1 << APP_BUTTONS_BUTTON_SW1))
		#define APP_BUTTONS_LONG_PRESSED_TIMEOUT	ZTIMER_TIME_MSEC(3000)
    #endif
#elif (defined DR1216 )
    /* DIO used for DR1216 switch */
    #define DIO_11 (0x800)
    #define DIO_15 (0x8000)
    #define DIO_12 (0x1000)
    #define DIO_13 (0x2000)

    /* Mask for all buttons */
    #define APP_BUTTONS_DIO_MASK (DIO_11|DIO_12|DIO_13|DIO_15)

    /* Button defines */
    #define BUTTON_ON       DIO_13     //DIO 11 for On button
    #define BUTTON_OFF      DIO_15     //DIO 15 for off button
    #define BUTTON_INCREASE DIO_12     //DIO 12 for light increase button
    #define BUTTON_DECREASE DIO_11     //DIO 13 for light decrease button

#elif  (defined GP_AUTO_SWITCH)
    #define DIO_8 (0x100)
    #define DIO_BUTTON_MASK (DIO_8)
    #define BUTTON_PRESSED       0x00               /*No DIO set */
    #define BUTTON_RELEASED      DIO_8              /*DIO 8 set when button released*/
    #define APP_BUTTONS_DIO_MASK DIO_8
#else
    typedef enum {
        APP_E_BUTTONS_BUTTON_1
    } APP_teButtons;
    #define APP_BUTTONS_NUM                     (1UL)
    #if (JENNIC_CHIP_FAMILY == JN516x)
        #define APP_BUTTONS_BUTTON_1            (0)
    #elif (JENNIC_CHIP_FAMILY == JN517x)
        #define APP_BUTTONS_BUTTON_1            (4)
    #endif
    #define APP_BUTTONS_DIO_MASK                (1 << APP_BUTTONS_BUTTON_1)
#endif

typedef enum {
    E_INTERRUPT_UNKNOWN,
    E_INTERRUPT_BUTTON,
    E_INTERRUPT_WAKE_TIMER_EXPIRY
} teInterruptType;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
PUBLIC bool_t APP_bButtonInitialise(void);
extern PUBLIC void vManageWakeUponSysControlISR(teInterruptType eInterruptType);

PUBLIC void APP_cbTimerButtonScan(void *pvParam);
PUBLIC void APP_cbTimerButtonDelay(void *pvParam);
PUBLIC void APP_cbTimerButtonLongPressed(void *pvParam);

#if (JENNIC_CHIP_FAMILY == JN517x)
PUBLIC void vISR_SystemController(uint32 u32DeviceId, uint32 u32BitMap);
#endif
#if (JENNIC_CHIP_FAMILY == JN516x)
PUBLIC void vISR_SystemController(void);
#endif


/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#endif /*APP_BUTTONS_H*/

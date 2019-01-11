
/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          EH_Button
 *
 * AUTHOR:             Rajeena
 *
 * DESCRIPTION:        ZigBee EH Button
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
 * Copyright NXP B.V. 2012. All rights reserved
 *
 ***************************************************************************/

#ifndef EH_BUTTON_H_
#define EH_BUTTON_H_
/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#include "jendefs.h"
#include "AppHardwareApi.h"
#include "PeripheralRegs.h"


/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

 /* DIO mapping for buttons on DK4 and EH switch */

#ifdef DK4

#define APP_E_BUTTONS_BUTTON_1  0x100
#define APP_E_BUTTONS_BUTTON_SW1  0x800
#define APP_E_BUTTONS_BUTTON_SW2  0x1000
#define APP_E_BUTTONS_BUTTON_SW3  0x20000
#define APP_E_BUTTONS_BUTTON_SW4  0x2


    #define APP_BUTTONS_NUM             (5UL)
    #define APP_BUTTONS_BUTTON_1        (8)
    #define APP_BUTTONS_BUTTON_SW4        (1)
    #define APP_BUTTONS_BUTTON_SW3        (11)
    #define APP_BUTTONS_BUTTON_SW2        (12)
    #define APP_BUTTONS_BUTTON_SW1        (17)
    #define APP_BUTTONS_DIO_MASK        ((1 << APP_BUTTONS_BUTTON_1)|(1 << APP_BUTTONS_BUTTON_SW4) | (1 << APP_BUTTONS_BUTTON_SW3) | (1 << APP_BUTTONS_BUTTON_SW2) | (1 << APP_BUTTONS_BUTTON_SW1))
    #define APP_ALL_BUTTON_RELEASED     (0xFFFCF)
#elif DR1216

    /* DIO used for switch */
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

#else
    #define DIO_8 (0x100)
    #define DIO_BUTTON_MASK (DIO_8)
    #define BUTTON_PRESSED       0x00               /*No DIO set */
    #define BUTTON_RELEASED      DIO_8              /*DIO 8 set when button released*/
    #define APP_BUTTONS_DIO_MASK DIO_8

#endif

/** Maximum time between two short press in  msec */
#define SHORT_PRESS_TIME                          (1000 *10)    /* 10 sec */



/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported variables                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Public Functions                                              ***/
/****************************************************************************/
bool bHandleButtonPress(bool bIsPowerUp);
bool bProcessGPDEvent(void);
bool bButtonInitialize(void);
#endif /* EH_BUTTON_H_ */

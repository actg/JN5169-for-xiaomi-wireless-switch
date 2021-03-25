/*****************************************************************************
 *
 * MODULE:             JN-AN-1219
 *
 * COMPONENT:          app_main.h
 *
 * DESCRIPTION:
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

#ifndef APP_MAIN_H
#define APP_MAIN_H

#include "ZQueue.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#if (JENNIC_CHIP_FAMILY == JN516x)
//for XiaoMi wireless switch
#define BOARD_LED_D1_BIT               (10)
#define BOARD_LED_D2_BIT               (11)
#else
#define BOARD_LED_D1_BIT               (8)
#define BOARD_LED_D2_BIT               (14)
#define BOARD_LED_D3_BIT               (0)
#endif

#define BOARD_LED_D1_PIN               (1UL << BOARD_LED_D1_BIT)
#define BOARD_LED_D2_PIN               (1UL << BOARD_LED_D2_BIT)

#define BOARD_LED_CTRL_MASK            (BOARD_LED_D1_PIN|BOARD_LED_D2_PIN)

#define LED1    1

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC void APP_vInitResources(void);
PUBLIC void APP_vSetUpHardware(void);
PUBLIC void APP_vMainLoop(void);
PUBLIC void APP_vInitLeds(void);
PUBLIC void APP_vSetLED(uint8 u8Led, bool_t bOn);

/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/

extern PUBLIC uint8 u8TimerPoll;
extern PUBLIC uint8 u8TimerButtonScan;
extern PUBLIC uint8 u8TimerTick;
extern PUBLIC uint8 u8TimerJoin;
extern PUBLIC uint8 u8TimerButtonDelay;
extern PUBLIC uint8 u8TimerChangeMode;
#if (defined APP_NTAG_ICODE) || (defined APP_NTAG_AES)
extern PUBLIC uint8 u8TimerNtag;
#endif
extern PUBLIC uint8 u8TimerButtonLongPressed;

extern PUBLIC tszQueue zps_msgMlmeDcfmInd;
extern PUBLIC tszQueue zps_msgMcpsDcfmInd;
extern PUBLIC tszQueue zps_TimeEvents;
extern PUBLIC tszQueue zps_msgMcpsDcfm;

extern PUBLIC tszQueue APP_msgAppEvents;
extern PUBLIC tszQueue APP_msgBdbEvents;

/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#endif /* APP_MAIN_H */







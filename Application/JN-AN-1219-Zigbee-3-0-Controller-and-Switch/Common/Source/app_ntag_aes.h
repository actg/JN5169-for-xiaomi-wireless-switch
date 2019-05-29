/*****************************************************************************
 *
 * MODULE:          JN-AN-1220 ZLO Sensor Demo
 *
 * COMPONENT:       app_ntag_aes.h
 *
 * DESCRIPTION:     ZLO Demo: Application layer for NTAG
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
#ifndef APP_NTAG_AES_H_
#define APP_NTAG_AES_H_

/****************************************************************************/
/***        Include Files                                                 ***/
/****************************************************************************/
#include <jendefs.h>
#include <ntag.h>

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#define APP_NTAG_ADDRESS          0xFFU  /* I2C Address (0xFF for automatic detection) */
#define APP_NTAG_I2C_LOCATION     FALSE  /* TRUE uses alternate I2C lines (DIO16, 17) instead of (DIO14, 15) */
#define APP_NTAG_I2C_FREQUENCY_HZ 100000 /* I2C prescale value */
#define APP_NTAG_TICK_MS          5      /* Interval of tick timer in ms */

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
PUBLIC bool_t APP_bNtagPdmLoad(void);
PUBLIC void APP_vNtagStart(uint8 u8NscType);
PUBLIC void APP_vNtagStop(void);
PUBLIC void APP_cbNtagTimer(void *pvParams);
PUBLIC void APP_cbNtagEvent(            /* Called when an event takes place */
       teNtagEvent  eNtagEvent,         /* Event raised */
       uint32       u32Address,
       uint32       u32Length,
       uint8        *pu8Data);          /* Event data (NULL if no data) */

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

#endif /* APP_NTAG_AES_H_ */
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

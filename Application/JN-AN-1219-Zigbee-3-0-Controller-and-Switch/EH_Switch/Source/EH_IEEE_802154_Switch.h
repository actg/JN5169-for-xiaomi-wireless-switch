/*****************************************************************************
 *
 * MODULE:             JN-AN-1219
 *
 * COMPONENT:          EH_IEEE_802154_Switch.h
 *
 * DESCRIPTION:        ZGP Switch implementation
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

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/


#ifndef EH_IEEE_802154_SWITCH_H_
#define EH_IEEE_802154_SWITCH_H_

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include "jendefs.h"
#include "AppHardwareApi.h"
#include "PeripheralRegs.h"
#include "string.h"
#include <dbg.h>
#include <dbg_uart.h>
#include "MMAC.h"
#include "EH_IEEE_802154_Switch.h"
#include "EH_Switch_Configurations.h"


/****************************************************************************/
/***        Macro Definitions                                          ***/
/****************************************************************************/
#ifndef DBG_DEVICE_SWITCH
#define DBG_DEVICE_SWITCH FALSE
#endif

/* Customer MAC address at page 5, word 7 (16-byte words, 16 words/page) */
#define MAC_ADDR1_BASE 0x01001570
/* Default MAC address at page 5, word 8 (16-byte words, 16 words/page) */
#define MAC_ADDR0_BASE 0x01001580

#define GP_ON_OFF_SWITCH                            0x02
#define GP_LEVEL_CONTROL_SWITCH                     0x03
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
typedef uint8     bmap8;

/****************************************************************************/
/***        Exported Variables                                           ***/
/****************************************************************************/
extern volatile bool_t bRxTimerExpired;;
extern volatile bool_t bEnableSleep;
/****************************************************************************/
/***        Exported Functions                                           ***/
/****************************************************************************/


PUBLIC void vSendMACFrame( bool bUpdatePersistentData);
void vEnableRxAndReceive(void);
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

#endif /* EH_IEEE_802154_SWITCH_H_ */


/*****************************************************************************
 *
 * MODULE:             JN-AN-1219
 *
 * COMPONENT:          EH_IEEE_Commands.h
 *
 * AUTHOR:             Rajeena
 *
 * DESCRIPTION:        ZigBee EH Commands
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

#ifndef EH_IEEE_COMMANDS_H_
#define EH_IEEE_COMMANDS_H_
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
#include "EH_IEEE_Features.h"


/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
/** macros for GPD security level  */

#define GPD_NO_SECURITY                                 (0x00)
#define GPD_FC_1LSB_MIC_2B_NO_ENC                       (0x01)
#define GPD_FC_4B_MIC_4B_NO_ENC                         (0x02)
#define GPD_FC_4B_MIC_4B_WITH_ENC                       (0x03)

#ifdef   GPD_SECURITY_LEVEL_FC_4B_MIC_4B_WITH_ENC
	#define GPD_SECURITY_LEVEL GPD_FC_4B_MIC_4B_WITH_ENC

#elif defined(GPD_SECURITY_LEVEL_FC_1LSB_MIC_2B_NO_ENC)
	#define GPD_SECURITY_LEVEL  GPD_FC_1LSB_MIC_2B_NO_ENC

#elif defined(GPD_SECURITY_LEVEL_FC_4B_MIC_4B_NO_ENC)
	#define GPD_SECURITY_LEVEL GPD_FC_4B_MIC_4B_NO_ENC

#else
	#define GPD_SECURITY_LEVEL GPD_NO_SECURITY
#endif


#define GPD_SOURCE_ID_SIZE                              (4)
#define SECURITY_LEVEL_5                                (0x05)
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

 /**  Green Power Security Key Types */
typedef enum PACk
{
    E_GPD_ZB_NWK_KEY = 0x01,
    E_GPD_GROUP_KEY,
    E_GPD_ZB_NWK_DERIVED_GROUP_KEY,
    E_GPD_INDIVIDUAL_KEY,
    DERIVED_INDIVIDUAL_GPD_KEY = 0x07
}teGPDSecurityKeyType;

/*  Green Power Supported Command Ids */
typedef enum GPD_CommandIDs
{
    E_GPD_OFF_CMD               = 0x20,
    E_GPD_ON_CMD                = 0x21,
    E_GPD_TOGGLE_CMD            = 0x22,
    E_GPD_MOVE_UP_CMD           = 0x35,
    E_GPD_MOVE_DOWN_CMD         = 0x36,
    E_GPD_LEVEL_CONTROL_STOP    = 0x34,
    E_GPD_COMMISSIOING_CMD      = 0xE0,
    E_GPD_DECOMMISSIOINING_CMD  = 0xE1,
    E_GPD_SUCCESS_CMD           = 0xE2,
    E_GPD_CHANNEL_REQ_CMD       = 0xE3,
    E_GPD_COMM_REPLY_CMD        = 0xF0,
    E_GPD_CHANNEL_CONFIG_CMD    = 0xF3,

}teGPD_CommandIDs;

/****************************************************************************/
/***        Exported variables                                              ***/
/****************************************************************************/

/***  Global variable containing the data to be transmitted */
extern tsMacFrame sGPD_MACFrame;

/***  Global variable containing the data to be received  */
extern tsMacFrame sGPD_MACReceivedFrame;
/****************************************************************************/
/***        Public Functions                                              ***/
/****************************************************************************/
void GPD_SendOperationalCommand(void);
void GPD_SendSpecificCommand(uint8 u8CommandId);
bool bGPD_ParseMACFrame(bool_t bIgnoreSecurity, ts_ReceivedPayload *psReceivedPayload);
void GPD_ConstructMACAndNetworkHeader(bool_t bAutoCommissioning, bool_t bSecured,bool_t bRxAfterTx);
bool bGPD_SecureFrame(uint8 u8GPDEncryptedDataIndex ,uint8     u8AESmode, uint32 u32FrameCounter, tsMacFrame *psMACFrame);
void GPD_ConstructMaintenaceFrame(void);
PUBLIC uint32 u32Reverse(uint32 u32InWord);
#endif /* EH_IEEE_COMMANDS_H_ */

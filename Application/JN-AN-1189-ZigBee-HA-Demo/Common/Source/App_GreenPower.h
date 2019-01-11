/*****************************************************************************
 *
 * MODULE:             JN-AN-1189 ZHA Demo
 *
 * COMPONENT:          App_GreenPower.h
 *
 * DESCRIPTION:        ZHA GP functionality - Interface
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
 **************************************************************************/
#ifndef APP_GREEN_POWER_H_
#define APP_GREEN_POWER_H_
/****************************************************************************/
/***        Include Files                                                 ***/
/****************************************************************************/
#include <jendefs.h>
#include "gp.h"
#include "GreenPower.h"
#include "zcl_options.h"

#ifdef CLD_GREENPOWER
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#define  MAX_TRANSLATION_TABLE_UPDATE_ENTRIES              3
/* Wrapper function to update GP time*/
#define vAppGPUpdateTime()    eGP_Update20mS(GREENPOWER_END_POINT_ID)
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

typedef struct
{
    uint8 u8RestoreDefaults;
    /* Translation Table */
    tsGP_TranslationTableEntry              asTranslationTableEntry[GP_NUMBER_OF_TRANSLATION_TABLE_ENTRIES];
    tsGP_GpToZclCommandInfo                 asGpToZclCmdInfoUpdate[MAX_TRANSLATION_TABLE_UPDATE_ENTRIES];
} tsGPPDMData;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

void vApp_RegisterGPDevice(tfpZCL_ZCLCallBackFunction fptrEPCallBack);
void vAppGPEnterCommissioningMode(void);
void vLoadGPData(void);
void vHandleGreenPowerEvent(tsGP_GreenPowerCallBackMessage *psGPMessage);
void vAppGPEnterDeCommissioningMode(void);
PUBLIC uint8 u8AppGetEPId(void);
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
extern tsGPPDMData sGPPDMData;
extern PDM_tsRecordDescriptor sGP_PDDesc;

#endif /* CLD_GREENPOWER */
#endif /* APP_GREEN_POWER_H_ */


/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

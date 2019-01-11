/*****************************************************************************
 *
 * MODULE:             Over The Air Upgrade
 *
 * COMPONENT:          ota_common.c
 *
 * AUTHOR:             Faisal Bhaiyat
 *
 * DESCRIPTION:        Over The Air Upgrade
 *
 * $HeadURL: http://svn/sware/Projects/SmartEnergy/Trunk/ZCL/Clusters/OTA/Source/ota_common.c $
 *
 * $Revision:  $
 *
 * $LastChangedBy: fbhai $
 *
 * $LastChangedDate: $
 *
 * $Id: ota_client.c  $
 *
 *****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products [NXP Microcontrollers such as JN5168, JN5164,
 * JN5161, JN5148, JN5142, JN5139].
 * You, and any third parties must reproduce the copyright and warranty notice
 * and any other legend of ownership on each  copy or partial copy of the software.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
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
 ****************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#include <jendefs.h>
#include "zcl.h"
#include "zcl_options.h"
#include "OTA.h"
#include "dbg.h"

#ifdef OTA_PC_BUILD
extern PUBLIC bool_t bAHI_FlashInit(
                             uint8    flashType,
                             void *pCustomFncTable);
extern PUBLIC bool_t bAHI_FlashEraseSector(
                             uint8              u8Sector);
extern PUBLIC bool_t bAHI_FullFlashProgram(
                             uint32             u32Addr,
                             uint16             u16Len,
                             uint8             *pu8Data);
extern PUBLIC bool_t bAHI_FullFlashRead(
                             uint32             u32Addr,
                             uint16             u16Len,
                             uint8             *pu8Data);
extern PUBLIC void vAHI_SwReset(void);
#else
#include <AppHardwareApi.h>
#endif

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/
/****************************************************************************
 **
 ** NAME:       vOtaFlashInitHw
 **
 ** DESCRIPTION:
 ** Initialise the external Flash
 **
 ** PARAMETERS:               Name                           Usage
 ** uint8                    u8FlashType                   Flash type
 ** void                    *pvFlashTable                  Flash table
 **
 ** RETURN:
 ** None
 ****************************************************************************/
PUBLIC  void vOtaFlashInitHw ( uint8    u8FlashType,
                               void    *pvFlashTable)
{
    bAHI_FlashInit(u8FlashType, NULL);
}
/****************************************************************************
 **
 ** NAME:       vOtaFlashErase
 **
 ** DESCRIPTION:
 ** Erase the Flash
 **
 ** PARAMETERS:               Name                           Usage
 ** uint8                    u8Sector                      sector number to erase
 **
 ** RETURN:
 ** None
 ****************************************************************************/
PUBLIC  void vOtaFlashErase(uint8 u8Sector)
{
    bAHI_FlashEraseSector(u8Sector);
}
/****************************************************************************
 **
 ** NAME:       vOtaFlashWrite
 **
 ** DESCRIPTION:
 ** Write data in the Flash
 **
 ** PARAMETERS:               Name                           Usage
 ** uint32                 u32FlashByteLocation           Flash byte location
 ** uint16                 u16Len                         Length of data
 ** uint8                 *pu8Data                        data bytes
 **
 ** RETURN:
 ** None
 ****************************************************************************/
PUBLIC  void vOtaFlashWrite(
                                  uint32     u32FlashByteLocation,
                                  uint16     u16Len,
                                  uint8     *pu8Data)
{
    bAHI_FullFlashProgram(u32FlashByteLocation, u16Len, pu8Data);

}
/****************************************************************************
 **
 ** NAME:       vOtaFlashRead
 **
 ** DESCRIPTION:
 ** Read data from the Flash
 **
 ** PARAMETERS:               Name                           Usage
 ** uint32                 u32FlashByteLocation           Flash byte location
 ** uint16                 u16Len                         Length of data
 ** uint8                 *pu8Data                        data bytes
 **
 ** RETURN:
 ** None
 ****************************************************************************/
PUBLIC  void vOtaFlashRead(
                                  uint32     u32FlashByteLocation,
                                  uint16     u16Len,
                                  uint8     *pu8Data)
{
    bAHI_FullFlashRead(u32FlashByteLocation,
                       u16Len,
                       pu8Data);

}
/****************************************************************************
 **
 ** NAME:       vOtaSwitchLoads
 **
 ** DESCRIPTION:
 ** Software reset
 **
 ** PARAMETERS:               Name                           Usage
 **
 ** RETURN:
 ** None
 ****************************************************************************/

PUBLIC  void vOtaSwitchLoads(void)
{
    vAHI_SwReset();
}

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

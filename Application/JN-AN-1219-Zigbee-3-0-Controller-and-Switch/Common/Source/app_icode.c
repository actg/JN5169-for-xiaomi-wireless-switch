/*****************************************************************************
 *
 * MODULE:          JN-AN-1217
 *
 * COMPONENT:       app_icode.c
 *
 * DESCRIPTION:     ZLO Demo: Encryption/decryption using installation codes
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

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include <string.h>
#include "dbg.h"
#include "app_icode.h"
#include "nfc_end.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifdef DEBUG_APP_ICODE
    #define TRACE_ICODE     TRUE
#else
    #define TRACE_ICODE     FALSE
#endif
#define CRC_POLYNOMIAL      0x8408

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
extern PUBLIC void zps_pvAesGetKeyFromInstallCode(uint8 *pu8installCode,
                    uint16 u16installCodeLength,
                    AESSW_Block_u *puresult);

/****************************************************************************
 *
 * NAME: APP_bInstallCode
 *
 * DESCRIPTION:
 * Fixed and expanded version of BDB_bOutOfBandCommissionGetKey()
 *
 * PARAMETERS:
 *
 * RETURNS:
 *
 * EVENTS:   None
 *
 ****************************************************************************/
PUBLIC bool_t APP_bInstallCode(bool_t          bEncrypt,
                               /* Inputs */
                               uint8*        pu8InstallCode,
                               uint8*        pu8Input,
                               uint64        u64ExtAddress,
                               /* Outputs */
                               uint8*         pu8Output,
                               uint8*         pu8Mic)
{
    bool_t           bReturn = FALSE;
    bool_t           bWriteKey;
    AESSW_Block_u    uAesNonce_b;
    AESSW_Block_u    uInstallKey_b;
    AESSW_Block_u    uAesKey;
    uint8            u8Byte;

    /* Derive installation key from install code - returned as a big endian ordered byte array */
    zps_pvAesGetKeyFromInstallCode (pu8InstallCode, 16, &uInstallKey_b);
    /* Derive AES key from Install key - converting uint32 components to native endianess
       AES treats key as uint32 array */
    uAesKey.au32[0] = NFC_END_u32FromBe(&uInstallKey_b.au8[ 0]);
    uAesKey.au32[1] = NFC_END_u32FromBe(&uInstallKey_b.au8[ 4]);
    uAesKey.au32[2] = NFC_END_u32FromBe(&uInstallKey_b.au8[ 8]);
    uAesKey.au32[3] = NFC_END_u32FromBe(&uInstallKey_b.au8[12]);
    /* Zero nonce */
    memset (uAesNonce_b.au8, 0, sizeof(uAesNonce_b.au8));
    /* Derive shifted nonce from MAC address converted into big endian order
       AES treats nonce as uint8 array */
    NFC_END_vBeFromU64(&uAesNonce_b.au8[1], u64ExtAddress);
    /* Copy encrypted data into decryption buffer for in-situ decryption */
    memcpy(pu8Output, pu8Input, 16);
    /* Apply key */
    bWriteKey = bACI_WriteKey((tsReg128*) &uAesKey);
    /* Written key ? */
    if(bWriteKey)
    {
        /* Perform Ccm Star */
        vACI_OptimisedCcmStar(
            bEncrypt,                 /* TRUE=Encrypt / FALSE=Decrypt */
            4,                        /* Required number of checksum bytes */
            0,                        /* Length of authentication data in bytes */
            16,                       /* Length of input data in bytes */
            &uAesNonce_b,             /* A pointer to the 128bit nonce data */
            NULL,                     /* Authentication data */
            pu8Output,                /* Input and output data  */
            pu8Mic,                   /* Checksum (MIC)   */
            &bReturn);                /* Authenticated flag */
        /* If encrypting return does not get set so use the write key value instead */
        if (bEncrypt) bReturn = bWriteKey;
    }

    /* Debug ? */
    #if TRACE_ICODE
    {
        DBG_vPrintf(TRACE_ICODE, "\nAPP_bInstallCode()\n{");
        DBG_vPrintf(TRACE_ICODE, "\n    Inputs:");
        DBG_vPrintf(TRACE_ICODE, "\n        bEncrypt            = %d", bEncrypt);
        DBG_vPrintf(TRACE_ICODE, "\n        pu8InstallCode      =");
        for (u8Byte = 0; u8Byte < 16; u8Byte++) DBG_vPrintf(TRACE_ICODE, " %02x", pu8InstallCode[u8Byte]);
        DBG_vPrintf(TRACE_ICODE, "\n        pu8Input            =");
        for (u8Byte = 0; u8Byte < 16; u8Byte++) DBG_vPrintf(TRACE_ICODE, " %02x", pu8Input[u8Byte]);
        DBG_vPrintf(TRACE_ICODE, "\n        u64ExtAddress       = %08x:%08x", (uint32)(u64ExtAddress >> 32), (uint32)(u64ExtAddress & 0xFFFFFFFF));
        DBG_vPrintf(TRACE_ICODE, "\n    Derived:");
        DBG_vPrintf(TRACE_ICODE, "\n        uInstallKey_b.au8   =");
        for (u8Byte = 0; u8Byte < 16; u8Byte++) DBG_vPrintf(TRACE_ICODE, " %02x", uInstallKey_b.au8[u8Byte]);
        DBG_vPrintf(TRACE_ICODE, "\n        uAesNonce_b.au8     =");
        for (u8Byte = 0; u8Byte < 16; u8Byte++) DBG_vPrintf(TRACE_ICODE, " %02x", uAesNonce_b.au8[u8Byte]);
        DBG_vPrintf(TRACE_ICODE, "\n        uAesKey.au32        =");
        for (u8Byte = 0; u8Byte <  4; u8Byte++) DBG_vPrintf(TRACE_ICODE, " %08x", uAesKey.au32[u8Byte]);
        DBG_vPrintf(TRACE_ICODE, "\n    Outputs:");
        DBG_vPrintf(TRACE_ICODE, "\n        pu8Output           =");
        for (u8Byte = 0; u8Byte < 16; u8Byte++) DBG_vPrintf(TRACE_ICODE, " %02x", pu8Output[u8Byte]);
        DBG_vPrintf(TRACE_ICODE, "\n        pu8Mic              =");
        for (u8Byte = 0; u8Byte <  4; u8Byte++) DBG_vPrintf(TRACE_ICODE, " %02x", pu8Mic[u8Byte]);
        DBG_vPrintf(TRACE_ICODE, "\n    Results:");
        DBG_vPrintf(TRACE_ICODE, "\n        bWriteKey           = %d", bWriteKey);
        DBG_vPrintf(TRACE_ICODE, "\n        bReturn             = %d", bReturn);
        DBG_vPrintf(TRACE_ICODE, "\n}");
    }
    #endif

    return bReturn;
}

/****************************************************************************
 *
 * NAME: APP_u16InstallCodeCrc
 *
 * DESCRIPTION:
 * Public version of zps_u16Crc()
 *
 * PARAMETERS:
 *
 * RETURNS:
 *
 * EVENTS:   None
 *
 ****************************************************************************/
PUBLIC uint16 APP_u16InstallCodeCrc(uint8* pu8InstallCode, uint16 u16Length)
{
  uint16 i;
  uint16 u16Data;
  uint16  u16Crc;

  u16Crc = 0xFFFF;

  /* Debug ? */
  #if TRACE_ICODE
  {
      uint16 u16Byte;

      DBG_vPrintf(TRACE_ICODE, "\nAPP_u16InstallCodeCrc()\n{");
      DBG_vPrintf(TRACE_ICODE, "\n    Inputs:");
      DBG_vPrintf(TRACE_ICODE, "\n        pu8InstallCode      =");
      for (u16Byte = 0; u16Byte < u16Length; u16Byte++) DBG_vPrintf(TRACE_ICODE, " %02x", pu8InstallCode[u16Byte]);
      DBG_vPrintf(TRACE_ICODE, "\n        u16Length           = %d", u16Length);
  }
  #endif

  if (u16Length > 0)
  {
     do {
        for (i = 0, u16Data = (uint16)0xff & *pu8InstallCode++;
             i < 8;
             i++, u16Data >>= 1) {
          if ((u16Crc & 0x0001) ^ (u16Data & 0x0001))
              u16Crc = (u16Crc >> 1) ^ CRC_POLYNOMIAL;
          else
              u16Crc >>= 1;
        }
      } while (--u16Length);
  }
  u16Crc = ~u16Crc;

  /* Debug ? */
  #if TRACE_ICODE
  {
      DBG_vPrintf(TRACE_ICODE, "\n    Outputs:");
      DBG_vPrintf(TRACE_ICODE, "\n        u16Crc              = x%04x", u16Crc);
      DBG_vPrintf(TRACE_ICODE, "\n}");
  }
  #endif

  return (u16Crc);
}

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

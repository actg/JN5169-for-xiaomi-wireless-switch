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
#if (defined JENNIC_CHIP_FAMILY_JN518x)
#include "OTA_private.h"
#include "fsl_flash.h"
#include "fsl_reset.h"
#define UNUSED(x) (void)(x)


uint32 u32LocalIndex = 0;
uint8 u8StandaloneBuffer [NVM_BYTES_PER_SEGMENT];
uint16 g_u16OtaPageIndex = 0;
bool_t g_bOtaFirstImagePage = FALSE;
bool_t bOTAWrites = FALSE;
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
#if (defined JENNIC_CHIP_FAMILY_JN518x)
    bOTAWrites = TRUE;
#endif
    bAHI_FullFlashProgram(u32FlashByteLocation, u16Len, pu8Data);
#if (defined JENNIC_CHIP_FAMILY_JN518x)
    bOTAWrites = FALSE;
#endif

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



#if (defined JENNIC_CHIP_FAMILY_JN518x)





/****************************************************************************
 **
 ** NAME:      bAHI_FlashInit
 **
 **
 ****************************************************************************/

PUBLIC bool_t bAHI_FlashInit(
                             uint8    flashType,
                             void *pCustomFncTable)
{
    UNUSED(pCustomFncTable);

     // Initialise Flash controller
     //FLASH_Init(FLASH); //This is not needed as init will be done directly from reset. //TBC
    u32LocalIndex = 0;
    memset (u8StandaloneBuffer, 0xFF, NVM_BYTES_PER_SEGMENT);
    return(TRUE);

}


/****************************************************************************
 **
 ** NAME:      OTA_iFixWriteDataInNVM
 **
 ** DESCRIPTION:
 ** Fix Segment Data Into NVM
 **
 ** PARAMETERS:                 Name                   Usage
 ** uint8                       u16PageIndex         NVM Page Number
 **
 ** RETURN:
 ** 0 - Pass 1- error
 **
 ****************************************************************************/

PUBLIC int OTA_iFixWriteDataInNVM(
    uint16      u16PageIndex)
{
    int iAPIreturn;
    uint32 i;

    if(g_bOtaFirstImagePage == TRUE)
    {
        uint8 u8TempByte;
        for ( i = 0; i < BOOTLOADER_HEADER_LENGTH ; i++)
        {
            u8TempByte = u8StandaloneBuffer[i] ^ 0xFB;
            u8StandaloneBuffer[i] = u8TempByte;
        }
        g_bOtaFirstImagePage = FALSE;
    }
    // perform a blank check
    iAPIreturn =
    FLASH_BlankCheck(
        FLASH,
        (uint8 *)(u16PageIndex * NVM_BYTES_PER_SEGMENT),
        (uint8 *)((u16PageIndex * NVM_BYTES_PER_SEGMENT) + (NVM_BYTES_PER_SEGMENT-1))
    );
    if(iAPIreturn != FLASH_DONE)
    {
        return(FALSE);
    }

    // program data
    iAPIreturn =
    FLASH_Program(
            FLASH,
            (uint32 *)(u16PageIndex * NVM_BYTES_PER_SEGMENT),

            (void *)u8StandaloneBuffer
            ,
             NVM_BYTES_PER_SEGMENT);

    if(iAPIreturn != FLASH_DONE)
    {
        return(-1);
    }

    u32LocalIndex = 0;
    memset (u8StandaloneBuffer, 0xFF, NVM_BYTES_PER_SEGMENT);
    return(0);
}

/****************************************************************************
 **
 ** NAME:      bAHI_FlashEraseSector
 **
 ** DESCRIPTION:
 ** Erases the NVM. This code erases the FLASH and then writes a known
 ** value to the FLASH
 **
 ** PARAMETERS:                 Name                   Usage
 ** uint8                       u8Sector            NVM Index Number
 **
 ** RETURN:
 ** 0 - Pass 1- error
 **
 ****************************************************************************/

PUBLIC bool_t bAHI_FlashEraseSector(
                             uint8              u8Sector)
{

    int iAPIreturn;
     /* JN518x a segment has the same definition as a Page in this implementation
       1 Page = 32 FLASH words = 32 * 16 = 512 Bytes AHI uses 32K sector sizes
       (32*1024)/512 gives a factor of 64 */
    uint32 u32SectorSize =  u8Sector * OTA_SECTOR_CONVERTION;
    // Erase the page
    /* Erase 64 pages i.e. 32K at a time */
    iAPIreturn = FLASH_ErasePages(FLASH, u32SectorSize, 64);

    if(iAPIreturn != FLASH_DONE)
    {
        return(FALSE);
    }
    // perform a blank check
    iAPIreturn =
    FLASH_BlankCheck(
        FLASH,
        (uint8 *)(u32SectorSize * NVM_BYTES_PER_SEGMENT),
        (uint8 *)((u32SectorSize * NVM_BYTES_PER_SEGMENT) + (NVM_BYTES_PER_SEGMENT-1))
    );
    if(iAPIreturn != FLASH_DONE)
    {
        return(FALSE);
    }

    return(TRUE);

}

/****************************************************************************
 **
 ** NAME:      OTA_iTestNVMblank
 **
 ** DESCRIPTION:
 ** Tests the NVM Page for Errors
 **
 ** PARAMETERS:                 Name                   Usage
 ** uint16                      u16PageIndex           NVM Page Number
 **
 ** RETURN:
 ** 0 - Pass -1- error, -2 test fail
 **
 ****************************************************************************/

PUBLIC int OTA_iTestNVMblank(
        uint16      u16PageIndex)
{
    int iAPIreturn;

    iAPIreturn =
    FLASH_BlankCheck(
        FLASH,
        (uint8 *)(u16PageIndex * NVM_BYTES_PER_SEGMENT),
        (uint8 *)((u16PageIndex * NVM_BYTES_PER_SEGMENT) + (NVM_BYTES_PER_SEGMENT-1))
    );

    if(iAPIreturn != FLASH_DONE)
    {
        return(-1);
    }

    return(0);

}

/****************************************************************************
 **
 ** NAME:      bAHI_FullFlashRead
 **
 ** DESCRIPTION:
 ** Reads Data from the NVM into a user buffer
 **
 ** PARAMETERS:                 Name                   Usage
 ** uint16                      u16PageIndex           NVM Page Number
 ** uint16                      u16PageByteAddress     NVM Logical Byte Address
 ** uint8                      *pu8DataBuffer          Data Buffer
 ** uint16                      u16Datalength          Data Buffer Length
 **
 ** RETURN:
 ** int 0 - pass, -1 fail
 **
 ****************************************************************************/

PUBLIC bool_t bAHI_FullFlashRead(
                             uint32             u32Addr,
                             uint16             u16Len,
                             uint8             *pu8Data)
{

    int i;
    volatile uint8 *pu8FlashAddress;
    int iAPIreturn;
   
    iAPIreturn =
    FLASH_BlankCheck(
        FLASH,
        (uint8 *)(u32Addr),
        (uint8 *)(u32Addr + u16Len)
    );
    if(iAPIreturn == FLASH_DONE)
    {
        return(-1);
    }
    pu8FlashAddress = (uint8 *)(u32Addr);
    for(i=0; i < u16Len; i++)
    {
        //loop on bytes
        pu8Data[i] = pu8FlashAddress[i];
    }

    return(0);
}


/****************************************************************************
 **
 ** NAME:      bAHI_FullFlashProgram
 **
 ** DESCRIPTION:
 ** Fix Segment Data Into NVM
 **
 ** PARAMETERS:                 Name                   Usage
 **  uint32                      u32Addr                flash address
 **  uint16                      u16Len                 number bytes to write
 **  uint8                       *pu8Data               data to write
 ** RETURN:
 ** 0 - Pass 1- error
 **
 ****************************************************************************/

PUBLIC bool_t bAHI_FullFlashProgram(
                             uint32             u32Addr,
                             uint16             u16Len,
                             uint8             *pu8Data)
{
    int iAPIreturn;

    if ( g_u16OtaPageIndex == 0   )
    {
        /* We should be writing 512 bytes at a time. For rolling write we need to know the start page
         * if this is a full write and not OTA write then the page index which is a global should be reset to 0*/
        g_u16OtaPageIndex = u32Addr / NVM_BYTES_PER_SEGMENT;
    }
    while ( u16Len > 0 )
    {
        while ( (u32LocalIndex <= NVM_BYTES_PER_SEGMENT- 1) && ( u16Len > 0 ) )
        {
            u8StandaloneBuffer [ u32LocalIndex++] = *pu8Data++;
            u16Len--;
        }

        if (  u32LocalIndex >= NVM_BYTES_PER_SEGMENT- 1  )
        {
            // Erase Current Data In Specified Page

            iAPIreturn =
            FLASH_ErasePages(FLASH, g_u16OtaPageIndex, 1);


            if(iAPIreturn != FLASH_DONE)
            {
                return(0);
            }
            if ( OTA_iFixWriteDataInNVM (g_u16OtaPageIndex) == 0 )
            {
                g_u16OtaPageIndex++;
            }
            else
            {
                return 0;
            }
        }

    }

    return(1);
}

/****************************************************************************
 **
 ** NAME:      bFlashWriteBufferedTailEndBytes
 **
 ** DESCRIPTION:
 ** Dump the contents of the buffer into flash
 **
 ** PARAMETERS:                 Name                   Usage
 **  uint32                      u32Addr                flash address
 **  uint16                      u16Len                 number bytes to write
 **  uint8                       *pu8Data               data to write
 ** RETURN:
 ** 0 - Pass 1- error
 **
 ****************************************************************************/
PUBLIC bool_t bFlashWriteBufferedTailEndBytes (uint32             u32Addr)
{
    int iAPIreturn;
    if ( g_u16OtaPageIndex == 0 )
    {
    	g_u16OtaPageIndex = u32Addr / 512;
    }
    // Erase Current Data In Specified Page
    iAPIreturn =
    FLASH_ErasePages(FLASH, g_u16OtaPageIndex, 1);
    if(iAPIreturn != FLASH_DONE)
    {
        return(FALSE);
    }
    if ( OTA_iFixWriteDataInNVM ( g_u16OtaPageIndex ) == 0)
    {
    	g_u16OtaPageIndex = 0;
        return TRUE;
    }
    return FALSE;
}

/****************************************************************************
 **
 ** NAME:      vAHI_SwReset
 **
 ** DESCRIPTION:
 ** Reset the device
 **
 ** PARAMETERS:                 Name                   Usage
 ** None
 ** RETURN:
 ** None
 ****************************************************************************/
PUBLIC void vAHI_SwReset(void)
{
    NVIC_SystemReset();
}

/****************************************************************************
 **
 ** NAME:      iFlashEraseSingleSector
 **
 ** DESCRIPTION:
 ** Reset the device
 **
 ** PARAMETERS:                 Name                   Usage
 ** uint32                      u32Sector              page to erase
 ** RETURN:
 ** int                         FLASH api return code
 ****************************************************************************/
PUBLIC int iFlashEraseSingleSector ( uint32 u32Sector )
{

    int iAPIreturn;
    iAPIreturn = FLASH_ErasePages(FLASH, u32Sector, 1);
    return iAPIreturn;
}


/****************************************************************************
 **
 ** NAME:      vOtaFlashValidatInvalidatImage
 **
 ** DESCRIPTION:
 ** Reset the device
 **
 ** PARAMETERS:                 Name                   Usage
 ** uint32                      u32BaseAddress         base address of image
 ** tsOTA_Common                psOTA_Common           custom struct handle
 ** tsZCL_EndPointDefinition    psEndPointDefinition   End point handle
 **
 ** RETURN:
 **
 ****************************************************************************/

PUBLIC void vOtaFlashValidatInvalidatImage ( uint32                     u32BaseAddress,
                                       tsOTA_Common               *psOTA_Common,
                                       tsZCL_EndPointDefinition   *psEndPointDefinition
                                     )
{
    uint32    i = 0 ;
    /* Read the first page xoring it with a magic number 0xFB  will validate it or invalidate it depending on what the page
     * contents are */
    vOtaFlashLockRead (psEndPointDefinition, psOTA_Common, u32BaseAddress, NVM_BYTES_PER_SEGMENT, u8StandaloneBuffer);

    while ( i < BOOTLOADER_HEADER_LENGTH )
    {
         u8StandaloneBuffer[ i++ ] ^=  0xFB;
    }
    iFlashEraseSingleSector ( (u32BaseAddress / 512) );
    /* Erase Internal Flash Header */
    g_u16OtaPageIndex = 0;
    bAHI_FullFlashProgram ( u32BaseAddress, NVM_BYTES_PER_SEGMENT, u8StandaloneBuffer );
}

#endif
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

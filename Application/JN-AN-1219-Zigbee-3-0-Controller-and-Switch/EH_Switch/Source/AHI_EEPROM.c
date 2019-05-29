/****************************************************************************
 *
 * MODULE:             JN-AN-1219
 *
 * COMPONENT:          AHI_EEPROM.c
 *
 * DESCRIPTION:
 * Basic API for EEPROM access on JN516x
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
#include "jendefs.h"
#include "AppHardwareApi.h"
#include "PeripheralRegs.h"
#include "PDM.h"
#include "AHI_EEPROM.h"

/* These were previously internal PDM functions */
extern PUBLIC bool_t bPDM_InitialiseEEPROM(bool_t bEEPROMreadRoutine);
extern PUBLIC void vPDM_WriteEEPROMfixSegmentData(uint8 u8SegmentIndex);

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
/* EEPROM configurable parameters */
#define EEPROM_SEGMENT_SIZE  (64)
#define EEPROM_USER_SEGMENTS (63)

/* Values derived from configurable parameters */
#define EEPROM_END_ADDR      (EEPROM_SEGMENT_SIZE * EEPROM_USER_SEGMENTS)

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
/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
/****************************************************************************/
/****************************************************************************
 **
 ** NAME:      vAHI_InitEEPROM
 **
 ** DESCRIPTION:
 ** Initializes EEPROM
 **
 ** PARAMETERS: Name          Usage
 **
 **
 ** RETURN:
 ** None
 **
 ****************************************************************************/
PUBLIC void vAHI_InitEEPROM(void)
{
    uint8 u8SegmentDatalength;
    u16AHI_InitialiseEEP(&u8SegmentDatalength);

}
/****************************************************************************
 **
 ** NAME:      bAHI_ReadEEPROMBlock
 **
 ** DESCRIPTION:
 ** Read bytes from the EEPROM into a user-supplied buffer. It is possible to
 ** read into the subsequent sector.
 **
 ** PARAMETERS: Name          Usage
 ** uint16      u16StartAddr  Start address in EEPROM
 ** uint16      u16Bytes      Bytes to read
 ** uint8 *     pu8Buffer     Buffer for read data
 **
 ** RETURN:
 ** TRUE if success, FALSE if parameter error
 **
 ****************************************************************************/
PUBLIC bool_t bAHI_ReadEEPROMBlock(uint16  u16StartAddr,
                                   uint16  u16Bytes,
                                   uint8  *pu8Buffer)
{
    int i;

    /* Checks on input parameters: ensure that read doesn't go past end of
     * last user segment */
    if ((u16StartAddr + u16Bytes) > EEPROM_END_ADDR)
    {
        return FALSE;
    }

    /* Set EEPROM for Read */
    (void)bPDM_InitialiseEEPROM(TRUE);

    /* Set EEPROM start read address */
    vREG_FECWrite(REG_FEC_EEADDR, u16StartAddr);

    /* Set command to 8-bit reads with read-prefetch */
    vREG_FECWrite(REG_FEC_EECMD, 0x8);

    for (i = 0; i < u16Bytes; i++)
    {
        pu8Buffer[i] = (uint8)u32REG_FECRead(REG_FEC_EERDATA);
    }

    return TRUE;
}

/****************************************************************************
 **
 ** NAME:      bAHI_ReadEEPROM
 **
 ** DESCRIPTION:
 ** Read bytes from the EEPROM into a user-supplied buffer. It is possible to
 ** read into the subsequent sector.
 **
 ** PARAMETERS: Name       Usage
 ** uint8       u8Segment  EEPROM Segment Number
 ** uint8       u8Offset   Byte offset into segment
 ** uint8       u8Bytes    Bytes to read
 ** uint8 *     pu8Buffer  Buffer for read data
 **
 ** RETURN:
 ** TRUE if success, FALSE if parameter error
 **
 ****************************************************************************/
PUBLIC bool_t bAHI_ReadEEPROM(uint8  u8Segment,
                              uint8  u8Offset,
                              uint8  u8Bytes,
                              uint8 *pu8Buffer)
{
    return bAHI_ReadEEPROMBlock(u8Segment * EEPROM_SEGMENT_SIZE + u8Offset,
                                u8Bytes,
                                pu8Buffer);
}

/****************************************************************************
 **
 ** NAME:      bAHI_WriteEEPROMBlock
 **
 ** DESCRIPTION:
 ** Write bytes to the EEPROM. Writes can span across segments.
 **
 ** PARAMETERS: Name       Usage
 ** uint16      u16StartAddr  Start address in EEPROM
 ** uint16      u16Bytes      Bytes to write
 ** uint8 *     pu8Buffer     Buffer for write data
 **
 ** RETURN:
 ** TRUE if success, FALSE if parameter error
 **
 ****************************************************************************/
PUBLIC bool_t bAHI_WriteEEPROMBlock(uint16  u16StartAddr,
                                    uint16  u16Bytes,
                                    uint8  *pu8Buffer)
{
    int i;
    uint8 u8Segment;
    uint8 u8SegmentBytes;

    /* Checks on input parameters: ensure that write doesn't go beyond end of
     * last user segment */
    if ((u16StartAddr + u16Bytes) > EEPROM_END_ADDR)
    {
        return FALSE;
    }

    while (u16Bytes)
    {
        /* Determine segment to write to, based on address */
        u8Segment = u16StartAddr / EEPROM_SEGMENT_SIZE;

        /* Set number of bytes between current start address and end of
         * current sector */
        u8SegmentBytes = EEPROM_SEGMENT_SIZE
                         - u16StartAddr % EEPROM_SEGMENT_SIZE;

        /* Check if number of bytes is more than number of bytes left to
         * write */
        if (((uint16)u8SegmentBytes) > u16Bytes)
        {
            /* Reduce to number of bytes left to write */
            u8SegmentBytes = u16Bytes;
        }

        /* Set EEPROM for write */
        (void)bPDM_InitialiseEEPROM(FALSE);

        /* Set EEPROM start write address */
        vREG_FECWrite(REG_FEC_EEADDR, u16StartAddr);

        /* Set command to 8-bit writes (always get auto address increment) */
        vREG_FECWrite(REG_FEC_EECMD, 0x3);

        for (i = 0; i < u8SegmentBytes; i++)
        {
            vREG_FECWrite(REG_FEC_EEWDATA, pu8Buffer[i]);
        }

        /* Fix Data Into EEPROM */
        vPDM_WriteEEPROMfixSegmentData(u8Segment);

        /* Update pointers and counters */
        u16StartAddr += u8SegmentBytes;
        pu8Buffer    += u8SegmentBytes;
        u16Bytes     -= u8SegmentBytes;
    }

    return TRUE;
}

/****************************************************************************
 **
 ** NAME:      bAHI_WriteEEPROM
 **
 ** DESCRIPTION:
 ** Write bytes to the specified segment and offset within that segment. Only
 ** writes within one segment per call are allowed.
 **
 ** PARAMETERS: Name       Usage
 ** uint8       u8Segment  EEPROM Segment Number
 ** uint8       u8Offset   Byte offset into segment
 ** uint8       u8Bytes    Bytes to write
 ** uint8 *     pu8Buffer  Buffer for write data
 **
 ** RETURN:
 ** TRUE if success, FALSE if parameter error
 **
 ****************************************************************************/
PUBLIC bool_t bAHI_WriteEEPROM(uint8  u8Segment,
                               uint8  u8Offset,
                               uint8  u8Bytes,
                               uint8 *pu8Buffer)
{
    return bAHI_WriteEEPROMBlock(u8Segment * EEPROM_SEGMENT_SIZE + u8Offset,
                                 u8Bytes,
                                 pu8Buffer);
}


/****************************************************************************/
/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/
/****************************************************************************/

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

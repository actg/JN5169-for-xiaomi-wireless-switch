/****************************************************************************
 *
 * MODULE:             JN-AN-1219
 *
 * COMPONENT:          AHI_EEPROM.h
 *
 * DESCRIPTION:
 * Basic API for EEPROM access on JN516x
 *
 ****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products [NXP Microcontrollers such as JN5148, JN5142, JN5139].
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
 * Copyright NXP B.V. 2013. All rights reserved
 *
 ***************************************************************************/

#ifndef AHI_EEPROM_INCLUDED
#define AHI_EEPROM_INCLUDED

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#if defined __cplusplus
extern "C" {
#endif

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
PUBLIC void vAHI_InitEEPROM(void);
PUBLIC bool_t bAHI_ReadEEPROMBlock(uint16  u16StartAddr,
                                   uint16  u16Bytes,
                                   uint8  *pu8Buffer);
PUBLIC bool_t bAHI_WriteEEPROMBlock(uint16  u16StartAddr,
                                    uint16  u16Bytes,
                                    uint8  *pu8Buffer);

PUBLIC bool_t bAHI_ReadEEPROM(uint8  u8Segment,
                              uint8  u8Offset,
                              uint8  u8Bytes,
                              uint8 *pu8Buffer);

PUBLIC bool_t bAHI_WriteEEPROM(uint8  u8Segment,
                               uint8  u8Offset,
                               uint8  u8Bytes,
                               uint8 *pu8Buffer);
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

#if defined __cplusplus
};
#endif

#endif /*AHI_EEPROM_INCLUDED*/

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

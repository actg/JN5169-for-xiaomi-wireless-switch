/*****************************************************************************
 *
 * MODULE: NCI_ENDianess Interface
 *
 * COMPONENT: nfc_end.h
 *
 * AUTHOR: Martin Looker$
 *
 * DESCRIPTION:
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/Components/NFC/Tags/+v1000/Include/nfc_end.h $
 *
 * $Revision: 83780 $
 *
 * $LastChangedBy: nxp29761 $
 *
 * $LastChangedDate: 2016-10-04 16:44:13 +0800 (Tue, 04 Oct 2016) $
 *
 * $Id: nfc_end.h 83780 2016-10-04 08:44:13Z nxp29761 $
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
#ifndef NFC_SEC_H_
#define NFC_SEC_H_

/****************************************************************************/
/***        Include Files                                                 ***/
/****************************************************************************/
#include <jendefs.h>
#include <AHI_AES.h>

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
PUBLIC uint64 NFC_END_u64FromBe(uint8 *pu8Buffer);
PUBLIC uint32 NFC_END_u32FromBe(uint8 *pu8Buffer);
PUBLIC uint16 NFC_END_u16FromBe(uint8 *pu8Buffer);

PUBLIC void NFC_END_vBeFromU64(uint8 *pu8Buffer, uint64 u64Value);
PUBLIC void NFC_END_vBeFromU32(uint8 *pu8Buffer, uint32 u32Value);
PUBLIC void NFC_END_vBeFromU16(uint8 *pu8Buffer, uint16 u16Value);

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

#endif /* NFC_END_H_ */
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

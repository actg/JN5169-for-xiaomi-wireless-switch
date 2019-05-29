/*****************************************************************************
 *
 * MODULE:
 *
 * COMPONENT:
 *
 * DESCRIPTION:
 *
 *****************************************************************************
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
 ****************************************************************************/

#ifndef PORTMACRO_JN518x_H
#define PORTMACRO_JN518x_H

#include "MicroSpecific.h"
#include "dbg.h"
#include "aessw_ccm.h"
/*-----------------------------------------------------------*/

/*-----------------------------------------------------------*/
/* Imported functions                                        */
/*-----------------------------------------------------------*/

/*-----------------------------------------------------------*/
/* Local functions                                        */
/*-----------------------------------------------------------*/

/*-----------------------------------------------------------*/
/* Imported variables                                        */
/*-----------------------------------------------------------*/



PUBLIC uint8 ZPS_eEnterCriticalSection(void* hMutex, uint32* psIntStore);
PUBLIC uint8 ZPS_eExitCriticalSection(void* hMutex, uint32* psIntStore);
PUBLIC uint8 ZPS_u8GrabMutexLock(void* hMutex, uint32* psIntStore);
PUBLIC uint8 ZPS_u8ReleaseMutexLock(void* hMutex, uint32* psIntStore);
PUBLIC uint32 u32Reverse(uint32 u32InWord);
PUBLIC void vACI_OptimisedCcmStar(
    bool_t         bEncrypt,
    uint8          u8M,
    uint8          u8alength,
    uint8          u8mlength,
    tuAES_Block   *puNonce,
    uint8         *pau8authenticationData,
    uint8         *pau8Data,
    uint8         *pau8checksumData,
    bool_t        *pbChecksumVerify);
PUBLIC bool_t bACI_WriteKey(tsReg128 *psKeyData);
PUBLIC void vSwipeEndian(AESSW_Block_u *puBlock, tsReg128 *psReg, bool_t bBlockToReg);
#endif /* PORTMACRO_JN518x_H */

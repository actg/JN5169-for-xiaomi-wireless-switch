/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          AgeChildren.h
 *
 * DESCRIPTION:        Child aging code to remove stale child entries
 *
 ****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products [NXP Microcontrollers such as JN5148, JN5142,
 * JN5139]. You, and any third parties must reproduce the copyright and
 * warranty notice and any other legend of ownership on each copy or partial
 * copy of the software.
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

#ifndef AGE_CHILD_H
#define AGE_CHILD_H

#include <jendefs.h>
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#define APP_MAX_NUMBER_OF_CHILD_ED					5
#define APP_NWK_ADRRESS_RESPONSE                    0x8000
#define APP_AGE_CHILDREN_START_TIME_IN_MS           (RND_u32GetRand(16000,20000))
#define APP_AGE_CHILDREN_NEXT_CHILD_SCAN_TIME_IN_MS (RND_u32GetRand(1600,2000))
#define APP_CHILD_AGING_ATTEMPTS				    1
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC void vCheckIfMyChild( ZPS_tsAfEvent  * sStackEvent);
PUBLIC void vAgeChildren_ChildJoined(ZPS_tsAfEvent  *psStackEvent);

/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#endif /*AGE_CHILD_H*/







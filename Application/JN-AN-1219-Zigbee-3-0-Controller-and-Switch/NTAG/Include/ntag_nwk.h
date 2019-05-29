/*****************************************************************************
 *
 * MODULE: NTAG_NWK Interface
 *
 * COMPONENT: ntag_nwk.h
 *
 * $AUTHOR: Martin Looker$
 *
 * DESCRIPTION:
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Application_Notes/JN-AN-1194-Zigbee-Gateway/Branches/nxp29761-NFC/Source/NCI/app_nci.h $
 *
 * $Revision: 73669 $
 *
 * $LastChangedBy: nxp29761 $
 *
 * $LastChangedDate: 2015-10-26 15:13:09 +0000 (Mon, 26 Oct 2015) $
 *
 * $Id: app_nci.h 73669 2015-10-26 15:13:09Z nxp29761 $
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
 * Copyright NXP B.V. 2016. All rights reserved
 *
 ***************************************************************************/
#ifndef NTAG_NWK_H_
#define NTAG_NWK_H_

/****************************************************************************/
/***        Include Files                                                 ***/
/****************************************************************************/
#include <jendefs.h>
#include "nfc_nwk.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
/* NTAG_NWK statuses */
typedef enum
{
	E_NTAG_NWK_IDLE,			/* Not running */
	E_NTAG_NWK_ACTIVE,			/* Running */
	E_NTAG_NWK_FAIL,			/* Completed - failed */
	E_NTAG_NWK_OK				/* Completed - success */
} teNtagNwkStatus;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
PUBLIC teNtagNwkStatus NTAG_NWK_eStart(tsNfcNwk *psNfcNwk);   /* Start processing    */
PUBLIC teNtagNwkStatus NTAG_NWK_eStop(void);			      /* Stop processing     */
PUBLIC teNtagNwkStatus NTAG_NWK_eStatus(void);			      /* Query status        */
PUBLIC teNtagNwkStatus NTAG_NWK_eTick(uint32 u32TickMs);      /* Continue processing */

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

#endif /* NTAG_NWK_H_ */
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

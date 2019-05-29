/*****************************************************************************
 *
 * MODULE:      NFC
 *
 * COMPONENT:   nfc.h
 *
 * AUTHOR:      Martin Looker
 *
 * DESCRIPTION: Common macros used by all NFC libraries
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/Components/NFC/Tags/+v1000/Include/nfc.h $
 *
 * $Revision: 86369 $
 *
 * $LastChangedBy: nxp29761 $
 *
 * $LastChangedDate: 2017-01-23 19:47:50 +0800 (Mon, 23 Jan 2017) $
 *
 * $Id: nfc.h 86369 2017-01-23 11:47:50Z nxp29761 $
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
/*!
 * \file  nfc.h
 *
 * \brief Common macros used by all NFC libraries
 *
 ***************************************************************************/
#ifndef NFC_H_
#define NFC_H_

/****************************************************************************/
/***        Include Files                                                 ***/
/****************************************************************************/
#include <jendefs.h>

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
/* NFC data sizes */
#define NFC_HEADER_SIZE             16  /*!< Size of NTAG header data (stored at byte address 0) */
#define NFC_VERSION_SIZE             8  /*!< Size of NTAG version data */

/* NTAG part number defines */
#define NFC_NTAG_UNKNOWN             0  /*!< Unknown NTAG model */
#define NFC_NTAG_NT3H1101        31101  /*!< NT3H1101 NTAG model */
#define NFC_NTAG_NT3H1201        31201  /*!< NT3H1201 NTAG model */
#define NFC_NTAG_NT3H2111        32111  /*!< NT3H2111 NTAG model */
#define NFC_NTAG_NT3H2211        32211  /*!< NT3H2211 NTAG model */

#endif /* NFC_H_ */
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

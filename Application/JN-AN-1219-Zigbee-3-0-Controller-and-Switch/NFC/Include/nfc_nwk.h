/*****************************************************************************
 *
 * MODULE:      NFC
 *
 * COMPONENT:   nfc_nwk.h
 *
 * AUTHOR:      Martin Looker
 *
 * DESCRIPTION: Common macros used by all NFC NWK NDEF processing
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/Components/NFC/Tags/+v1000/Include/nfc_nwk.h $
 *
 * $Revision: 83780 $
 *
 * $LastChangedBy: nxp29761 $
 *
 * $LastChangedDate: 2016-10-04 16:44:13 +0800 (Tue, 04 Oct 2016) $
 *
 * $Id: nfc_nwk.h 83780 2016-10-04 08:44:13Z nxp29761 $
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
 * \file  nfc_nwk.h
 *
 * \brief Common macros used by all NFC NWK NDEF processing
 *
 ***************************************************************************/
#ifndef NFC_NWK_H_
#define NFC_NWK_H_

/****************************************************************************/
/***        Include Files                                                 ***/
/****************************************************************************/
#include <jendefs.h>

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
/* Version */
#define NFC_NWK_PAYLOAD_VERSION             13  /*!< NFC NWK NDEF payload version number */
/* Key size */
#define NFC_NWK_PAYLOAD_KEY_SIZE            16  /*!< Size of payload key byte arrays */
#define NFC_NWK_PAYLOAD_MIC_SIZE             4  /*!< Size of payload MIC byte arrays */
/* NFC_NWK generic commands */
#define NFC_NWK_CMD_NONE                  0x00  /*!< Null command value */
/* NFC_NWK NTAG commands */
#define NFC_NWK_NTAG_CMD_JOIN_WITH_CODE   0x41  /*!< NTAG request to NCI to join using installation code encrypted key */
/* NFC_NWK NCI commands */
#define NFC_NWK_NCI_CMD_FACTORY_RESET     0xA0  /*!< NCI request to NTAG to perform a factory reset */
#define NFC_NWK_NCI_CMD_JOIN_WITH_CODE    0xA1  /*!< NCI request to NTAG to join using installatino code encrypted key */

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
#pragma GCC diagnostic ignored "-Wpacked"
#pragma GCC diagnostic ignored "-Wattributes"

/*! Data written by NTAG side */
typedef struct
{
    uint8           u8Version;           /*!< Data structure version */
    uint8           u8Command;           /*!< Command from NTAG to NCI */
    uint8           u8Sequence;          /*!< Write counter */
    uint16          u16DeviceId;         /*!< Device type ID */
    uint64          u64ExtAddress;       /*!< Extended address */
    uint16          u16ShortAddress;     /*!< Current short address */
    uint8           u8Channel;           /*!< Current channel */
    uint16          u16PanId;            /*!< Current PAN ID */
    uint64          u64ExtPanId;         /*!< Current extended PAN ID */
    uint8           au8Key[NFC_NWK_PAYLOAD_KEY_SIZE]; /*!< Installation code */
    uint16          u16Crc;              /*!< Installation code CRC */
} PACK tsNfcNwkNtag;

/*! Data written by NCI side */
typedef struct
{
    uint8           u8Command;           /*!< Command from NCI to NTAG */
    uint8           u8Sequence;          /*!< Write counter */
    uint16          u16DeviceId;         /*!< Device type ID */
    uint64          u64ExtAddress;       /*!< Network trust center extended address */
    uint16          u16ShortAddress;     /*!< Network trust center short address */
    uint8           u8Channel;           /*!< Network channel */
    uint16          u16PanId;            /*!< Network PAN ID */
    uint64          u64ExtPanId;         /*!< Network extended PAN ID */
    uint8           au8Key[NFC_NWK_PAYLOAD_KEY_SIZE]; /*!< Encrypted network key */
    uint8           au8Mic[NFC_NWK_PAYLOAD_MIC_SIZE]; /*!< MIC for encrypted key */
    uint8           u8KeySeqNum;         /*!< Network key sequence number */
} PACK tsNfcNwkNci;

/*! NTAG NWK NDEF payload data */
typedef struct
{
    tsNfcNwkNtag    sNtag;               /*!< Data written by ntag side */
    tsNfcNwkNci     sNci;                /*!< Data written by nci side */
} PACK tsNfcNwkPayload;

/*! Installation code structure */
typedef struct
{
    uint8  au8Key[NFC_NWK_PAYLOAD_KEY_SIZE]; /*!< Installation code */
    uint16 u16Crc;                           /*!< Installation code CRC */
} PACK tsNfcNwkInstallCode;

#pragma GCC diagnostic pop

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

#endif /* NFC_NWK_H_ */
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

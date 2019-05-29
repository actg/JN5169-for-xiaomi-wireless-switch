/*****************************************************************************
 *
 * MODULE: NFC_NWK Shared macros and structures
 *
 * COMPONENT: nfc_nwk.h
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
#ifndef NFC_NWK_H_
#define NFC_NWK_H_

/****************************************************************************/
/***        Include Files                                                 ***/
/****************************************************************************/
#include <jendefs.h>

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
/* NFC_NWK defines */
#define NFC_NWK_KEY_LENGTH	             16		  /* Size of security key */
#define NFC_NWK_DATA_SIZE	             236 	  /* MAKE PRIVATE Size of data buffer */
#define NFC_NWK_HEADER_SIZE              16 	  /* MAKE PRIVATE Size of header buffer */
#define NFC_NWK_VERSION_SIZE  			 8 		  /* MAKE PRIVATE Size of version buffer */
/* NFC_NWK commands */
#define NFC_NWK_CMD_NONE                 0x00
#define NFC_NWK_CMD_FACTORY_NEW          0x01
#define NFC_NWK_CMD_JOIN_NETWORK         0x02
#define NFC_NWK_CMD_SECURE_JOIN_NETWORK  0x03
#define NFC_NWK_CMD_LEAVE_NETWORK        0x04
/* NFC_NWK Commissioning device tpyes extracted from nsc.c (would be better using ZB types) */
#define NFC_NWK_NSC_IOT_GATEWAY_DEVICE          	   0x02
#define NFC_NWK_NSC_CLIMATE_MANAGER             	   0x03
#define NFC_NWK_NSC_DEVICE_ZIGBEE_ROUTER_DEVICE        0x04
#define NFC_NWK_NSC_DEVICE_CLIMATE_UI_SENSOR_DEVICE    0x20
#define NFC_NWK_NSC_DEVICE_CLIMATE_SENSOR_DEVICE       0x22
#define NFC_NWK_NSC_DEVICE_CLIMATE_ACTUATOR_VALVE      0x23
#define NFC_NWK_NSC_DEVICE_ZIGBEE_SMART_PLUG           0x30
#define NFC_NWK_NSC_DEVICE_LAMP_DIMMABLE               0x41
#define NFC_NWK_NSC_DEVICE_LAMP_TUNABLE_WHITE          0x42
#define NFC_NWK_NSC_DEVICE_LAMP_RGB                    0x43

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
/* NFC_NWK device data */
typedef struct
{
	uint8   u8NscType;
	uint8	u8Channel;
	uint16 u16ShortAddress;
	uint16 u16PanId;
	uint64 u64ExtAddress;
	uint64 u64ExtPanId;
} tsNfcNwkDev;

/* NFC_NWK network data */
typedef struct
{
	uint8   u8NscType;
	uint8	u8Command;
	uint8	u8Channel;
	uint16 u16PanId;
	uint64 u64ExtPanId;
	uint64 u64TrustCenterAddress;
	uint8  au8NetworkKey[NFC_NWK_KEY_LENGTH];
	uint8   u8KeySeqNum;
} tsNfcNwkNwk;

/* NFC_NWK data */
typedef struct
{
	tsNfcNwkDev sDev;
	tsNfcNwkNwk sNwk;
} tsNfcNwk;

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

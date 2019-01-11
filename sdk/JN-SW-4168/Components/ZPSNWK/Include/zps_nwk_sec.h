/*****************************************************************************
 *
 * MODULE:             ZPS NWK
 *
 * COMPONENT:          zps_nwk_sec.h
 *
 * AUTHOR:             Mark SHea
 *
 * DESCRIPTION:        ZPS NWK Security defines
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/Zigbee%20Protocol%20Stack/Modules/NWK/Branches/ZBPRO_R20_v1.1/Include/zps_nwk_sec.h $
 *
 * $Revision: 73473 $
 *
 * $LastChangedBy: nxp29741 $
 *
 * $LastChangedDate: 2015-10-20 16:55:42 +0100 (Tue, 20 Oct 2015) $
 *
 * $Id: zps_nwk_sec.h 73473 2015-10-20 15:55:42Z nxp29741 $
 *
 *****************************************************************************
 *
 * This software is owned by Jennic and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on Jennic products. You, and any third parties must reproduce
 * the copyright and warranty notice and any other legend of ownership on each
 * copy or partial copy of the software.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS". JENNIC MAKES NO WARRANTIES, WHETHER
 * EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE,
 * ACCURACY OR LACK OF NEGLIGENCE. JENNIC SHALL NOT, IN ANY CIRCUMSTANCES,
 * BE LIABLE FOR ANY DAMAGES, INCLUDING, BUT NOT LIMITED TO, SPECIAL,
 * INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON WHATSOEVER.
 *
 * Copyright Jennic Ltd. 2008 All rights reserved
 *
 ****************************************************************************/

/**
 * @defgroup g_zps_nwk ZPS Network Layer infrastructure
 */

#ifndef _zps_nwk_sec_h_
#define _zps_nwk_sec_h_

#ifdef __cplusplus
extern "C" {
#endif

/***********************/
/**** INCLUDE FILES ****/
/***********************/
#include "jendefs.h"
#include "AHI_AES.h"
#include "pdum_nwk.h"

/************************/
/**** MACROS/DEFINES ****/
/************************/

#define ZPS_SEC_KEY_LENGTH                  16

/* Security Levels */
#define ZPS_NWK_SEC_SECURITY_LEVEL_0        0       /* No Security */
#define ZPS_NWK_SEC_SECURITY_LEVEL_1        1       /* MIC-32 */
#define ZPS_NWK_SEC_SECURITY_LEVEL_2        2       /* MIC-64 */
#define ZPS_NWK_SEC_SECURITY_LEVEL_3        3       /* MIC-128 */
#define ZPS_NWK_SEC_SECURITY_LEVEL_4        4       /* ENC */
#define ZPS_NWK_SEC_SECURITY_LEVEL_5        5       /* ENC-MIC-32 */
#define ZPS_NWK_SEC_SECURITY_LEVEL_6        6       /* ENC-MIC-64 */
#define ZPS_NWK_SEC_SECURITY_LEVEL_7        7       /* ENC-MIC-128 */

#define ZPS_NWK_SEC_SECURITY_LEVEL_MASK     0x07

/* Key Identifiers */
#define ZPS_NWK_SEC_DATA_KEY                0
#define ZPS_NWK_SEC_NETWORK_KEY             1
#define ZPS_NWK_SEC_KEY_TRANSPORT_KEY       2
#define ZPS_NWK_SEC_KEY_KOAD_KEY            3
#define ZPS_NWK_SEC_KEY_INVALID_KEY         0xFF

extern const uint32 g_u32NwkFcSaveCountBitShift;

/**************************/
/**** TYPE DEFINITIONS ****/
/**************************/

typedef struct
{
    uint8 u8SecCtrl;
    uint32 u32FrameCounter;
    uint64 u64SrcAddr;
    uint8 u8KeySeqNum;
} ZPS_tsSecAuxHdr;

/****************************/
/**** EXPORTED VARIABLES ****/
/****************************/


/****************************/
/**** EXPORTED FUNCTIONS ****/
/****************************/
#ifdef ZPS_NWK_OPT_FS_DYNAMIC_SEC_LVL
PUBLIC uint8 ZPS_u8NwkSecGetMicLen( uint8 u8SecurityLevel );
#endif
PUBLIC bool_t ZPS_bNwkSecFindMatSet( void *pvNwk, uint8 u8ActiveKSN, uint8 *u8SecMatIndex );
PUBLIC bool_t ZPS_bNwkSecCheckFC( void *pvNwk, uint64 u64SrcAddr, uint32 u32RecFC);
PUBLIC bool_t ZPS_bNwkSecHaveNetworkKey( void *pvNwk );
PUBLIC bool_t ZPS_bNwkSecCheckMatSet( void *pvNwk, uint8 u8ActiveKSN );
PUBLIC void ZPS_vNwkSecResetDevice(void *pvNwk,uint64 u64DevAddr);
PUBLIC bool_t ZPS_bSecEncrypt(void *pvNwk,
                              uint8 *pu8CurrHdr,
                              uint32 u32OutgoingFrameCounter,
                              bool_t bExtNonce,
                              AESSW_Block_u *puKey,
                              uint8 u8KeyId,
                              uint8 u8KeySeqNum,
                              PDUM_thNPdu hNPdu);
PUBLIC bool_t ZPS_bSecDecrypt(void *pvNwk,
                              ZPS_tsSecAuxHdr *psAuxSecHdr,
                              uint8 *pu8AuxSecHdr,
                              AESSW_Block_u *puKey,
                              PDUM_thNPdu hNPdu);

PUBLIC void ZPS_vNwkResetOutgoingFrameCounter(void *pvNwk);
PUBLIC void ZPS_vRegisterPanIdNotification(void* vfn);
#ifdef __cplusplus
};
#endif

#endif /* _zps_nwk_sec_h_ */

/* End of file $Id: zps_nwk_sec.h 73473 2015-10-20 15:55:42Z nxp29741 $ *******************************************/

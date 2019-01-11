/*****************************************************************************
 *
 * MODULE:             Zigbee Protocol Stack MAC Shim
 *
 * COMPONENT:          zps_mac.h
 *
 * AUTHOR:             RCC
 *
 * DESCRIPTION:        MAC shim layer to provide PDU manager i/f to NWK layer
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/Zigbee%20Protocol%20Stack/Modules/MAC/Branches/ZBPRO_R20_v1.1/Include/zps_mac.h $
 *
 * $Revision: 19939 $
 *
 * $LastChangedBy: rcc $
 *
 * $LastChangedDate: 2009-09-18 10:07:44 +0100 (Fri, 18 Sep 2009) $
 *
 * $Id: zps_mac.h 19939 2009-09-18 09:07:44Z rcc $
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
 * Copyright Jennic Ltd. 2009 All rights reserved
 *
 ****************************************************************************/

#ifndef _zps_mac_h_
#define _zps_mac_h_

#ifdef __cplusplus
extern "C" {
#endif

/***********************/
/**** INCLUDE FILES ****/
/***********************/

#include "jendefs.h"
#include "mac_sap.h"

/************************/
/**** MACROS/DEFINES ****/
/************************/

/**************************/
/**** TYPE DEFINITIONS ****/
/**************************/

/****************************/
/**** EXPORTED VARIABLES ****/
/****************************/

extern PUBLIC const uint32 ZPS_g_u32MacVersion;

/****************************/
/**** EXPORTED FUNCTIONS ****/
/****************************/

PUBLIC void
ZPS_vNwkHandleMcpsDcfmInd(void *pvNwk,
                          MAC_DcfmIndHdr_s *psMcpsDcfmInd);

#ifdef __cplusplus
};
#endif

#endif /* _zps_mac_h_ */

/* End of file $Id: zps_mac.h 19939 2009-09-18 09:07:44Z rcc $ *******************************************/


/*****************************************************************************
 *
 * MODULE:             ZPS NWK
 *
 * COMPONENT:          zps_nwk_mac_sap.h
 *
 * AUTHOR:             RCC
 *
 * DESCRIPTION:        ZPS NWK Public exported API
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/Zigbee%20Protocol%20Stack/Modules/NWK/Branches/ZBPRO_R20_v1.1/Include/zps_nwk_mac_sap.h $
 *
 * $Revision: 87288 $
 *
 * $LastChangedBy: nxp29741 $
 *
 * $LastChangedDate: 2017-03-13 13:06:11 +0000 (Mon, 13 Mar 2017) $
 *
 * $Id: zps_nwk_mac_sap.h 87288 2017-03-13 13:06:11Z nxp29741 $
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

#ifndef _zps_nwk_mac_sap_h_
#define _zps_nwk_mac_sap_h_

#ifdef __cplusplus
extern "C" {
#endif

/***********************/
/**** INCLUDE FILES ****/
/***********************/

#include "jendefs.h"
#include "mac_sap.h"
#include "mac_vs_sap.h"

/************************/
/**** MACROS/DEFINES ****/
/************************/

/**************************/
/**** TYPE DEFINITIONS ****/
/**************************/

/****************************/
/**** EXPORTED VARIABLES ****/
/****************************/

/****************************/
/**** EXPORTED FUNCTIONS ****/
/****************************/

PUBLIC void
ZPS_vNwkHandleMlmeDcfmInd(void *pvNwk,
        MAC_DcfmIndHdr_s *psMlmeDcfmInd);

PUBLIC void
ZPS_vNwkHandleMcpsVsInd(void *pvNwk,
                            MAC_tsMcpsVsDcfmInd *psMcpsDcfmInd);
PUBLIC void ZPS_vNwkHandleMcpsVsDcfm (void *pvNwk,
                            MAC_tsMcpsVsCfmData *psMcpsDcfmInd);
#ifdef __cplusplus
};
#endif

#endif /* _zps_nwk_mac_sap_h_ */

/* End of file $Id: zps_nwk_mac_sap.h 87288 2017-03-13 13:06:11Z nxp29741 $ *******************************************/

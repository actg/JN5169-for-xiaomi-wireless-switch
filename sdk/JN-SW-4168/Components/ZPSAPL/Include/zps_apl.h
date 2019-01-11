/*****************************************************************************
 *
 * MODULE:      Zigbee Protocol Stack Application Layer
 *
 * COMPONENT:   zps_apl.h
 *
 * AUTHOR:      mwild
 *
 * DESCRIPTION: Application Layer global definitions
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/Zigbee%20Protocol%20Stack/Modules/APL/Branches/ZBPRO_R20_v1.1/Include/zps_apl.h $
 *
 * $Revision: 35329 $
 *
 * $LastChangedBy: nxp29741 $
 *
 * $LastChangedDate: 2011-10-04 14:17:49 +0100 (Tue, 04 Oct 2011) $
 *
 * $Id: zps_apl.h 35329 2011-10-04 13:17:49Z nxp29741 $
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

#ifndef ZPS_APL_H_
#define ZPS_APL_H_

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/*
 * general status type
 * The value returned can be from any layer of the ZigBee stack
 * Consult the relevant header file depending on the value
 * 0x80 - 0x8F : Zigbee device profile (zps_apl_zdp.h)
 * 0xA0 - 0xBF : Application support sub-layer (zps_apl_aps.h)
 * 0xC0 - 0xCF : Network layer (zps_nwk_sap.h)
 * 0xE0 - 0xFF : MAC layer (mac_sap.h)
 */
typedef uint8 ZPS_teStatus;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/

PUBLIC extern const uint32 ZPS_g_u32AplVersion;

/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#endif /* ZPS_APL_H_ */

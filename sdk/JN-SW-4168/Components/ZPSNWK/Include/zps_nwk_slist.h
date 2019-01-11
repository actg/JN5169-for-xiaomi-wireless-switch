/*****************************************************************************
 *
 * MODULE:             ZPS NWK
 *
 * COMPONENT:          zps_nwk_slist.h
 *
 * AUTHOR:             RCC
 *
 * DESCRIPTION:        ZPS NWK Single Linked List
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/Zigbee%20Protocol%20Stack/Modules/NWK/Branches/ZBPRO_R20_v1.1/Include/zps_nwk_slist.h $
 *
 * $Revision: 9335 $
 *
 * $LastChangedBy: mwild $
 *
 * $LastChangedDate: 2008-12-19 15:43:29 +0000 (Fri, 19 Dec 2008) $
 *
 * $Id: zps_nwk_slist.h 9335 2008-12-19 15:43:29Z mwild $
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

#ifndef _zps_nwk_slist_h_
#define _zps_nwk_slist_h_

#ifndef MODULE
#define MODULE /* no modifier implies global */
#endif

/***********************/
/**** INCLUDE FILES ****/
/***********************/

#include "jendefs.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************/
/**** MACROS/DEFINES ****/
/************************/

#define ZPS_NWK_SLIST_LIMBO_NODE ((zps_tsNwkSlistNode *)0xFFFFFFFF)

/**************************/
/**** TYPE DEFINITIONS ****/
/**************************/

/**
 * ZPS NWK Single linked list node
 * @ingroup g_zps_nwk_slist
 * @note
 * Based on Jeneric JennicStdLib but without the unnecessary stuff
 */
typedef struct zps_tsNwkSlistNode_tag zps_tsNwkSlistNode;
struct zps_tsNwkSlistNode_tag
{
    zps_tsNwkSlistNode *psNext;
};

/**
 * ZPS NWK Single linked list
 * @ingroup g_zps_nwk_slist
 * @note
 * Based on Jeneric JennicStdLib but without the unnecessary stuff
 */
typedef struct zps_tsNwkSlist_tag
{
    zps_tsNwkSlistNode *psHead;     /**< Head node in list (NULL if empty) */
    zps_tsNwkSlistNode *psTail;     /**< Tail node in list (NULL if empty) */
} zps_tsNwkSlist;

/****************************/
/**** IMPORTED FUNCTIONS ****/
/****************************/

/**************************/
/**** MODULE VARIABLES ****/
/**************************/

/****************************/
/**** EXPORTED FUNCTIONS ****/
/****************************/

MODULE void
zps_vNwkSlistInit(zps_tsNwkSlist *psList);

MODULE void
zps_vNwkSlistAddToHead(zps_tsNwkSlist *psList,
                       zps_tsNwkSlistNode *psNode);

MODULE void
zps_vNwkSlistAddToTail(zps_tsNwkSlist *psList,
                       zps_tsNwkSlistNode *psNode);

MODULE void
zps_vNwkSlistInsertAfter(zps_tsNwkSlist *psList,
                         zps_tsNwkSlistNode *psCurrentNode,
                         zps_tsNwkSlistNode *psNewNode);

MODULE zps_tsNwkSlistNode *
zps_psNwkSlistRemoveFromHead(zps_tsNwkSlist *psList);

MODULE zps_tsNwkSlistNode *
zps_psNwkSlistRemove(zps_tsNwkSlist *psList,
                     zps_tsNwkSlistNode *psNode);

MODULE void
zps_vNwkSlistMakeLimboNode(zps_tsNwkSlistNode *psNode);

MODULE bool_t
zps_bNwkSlistIsLimboNode(zps_tsNwkSlistNode *psNode);

#ifdef __cplusplus
};
#endif

#endif /* _mac_prv_h_ */

/* End of file $Id: zps_nwk_slist.h 9335 2008-12-19 15:43:29Z mwild $ *******************************************/

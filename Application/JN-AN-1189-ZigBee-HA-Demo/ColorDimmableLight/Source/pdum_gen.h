/****************************************************************************
 *
 *                 THIS IS A GENERATED FILE. DO NOT EDIT!
 *
 * MODULE:         PDUM
 *
 * COMPONENT:      pdum_gen.h
 *
 * DATE:           Mon Jan  7 17:03:41 2019
 *
 * AUTHOR:         Jennic PDU Manager Configuration Tool
 *
 * DESCRIPTION:    PDU definitions
 *
 ****************************************************************************
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

#ifndef _PDUM_GEN_H
#define _PDUM_GEN_H

#include <pdum_apl.h>

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
/* APDUs */
#define apduZDP &pdum_apduZDP
#define apduZCL &pdum_apduZCL

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/

/* APDUs */
extern const struct pdum_tsAPdu_tag pdum_apduZDP;
extern const struct pdum_tsAPdu_tag pdum_apduZCL;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC void PDUM_vInit(void);

/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#endif

/****************************************************************************
 *
 *                 THIS IS A GENERATED FILE. DO NOT EDIT!
 *
 * MODULE:         PDUM
 *
 * COMPONENT:      pdum_gen.c
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

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#include <jendefs.h>
#include <os.h>
#include <os_gen.h>
#include <pdum_nwk.h>
#include <pdum_apl.h>

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

struct pdum_tsAPdu_tag {
    struct pdum_tsAPduInstance_tag *psAPduInstances;
    uint16 u16FreeListHeadIdx;
    uint16 u16Size;
    uint16 u16NumInstances;
};

struct pdum_tsAPduInstance_tag {
    uint8 *au8Storage;
    uint16 u16Size;
    uint16 u16NextAPduInstIdx;
    uint16 u16APduIdx;
};

typedef struct pdum_tsAPduInstance_tag pdum_tsAPduInstance;
typedef struct pdum_tsAPdu_tag pdum_tsAPdu;


/****************************************************************************/
/***        Function Prototypes                                           ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/


/* NPDU Pool */
PRIVATE pdum_tsNPdu s_asNPduPool[15];

/* APDU Pool */
PRIVATE uint8 s_au8apduZDPInstance0Storage[100];
PRIVATE uint8 s_au8apduZDPInstance1Storage[100];
PRIVATE uint8 s_au8apduZDPInstance2Storage[100];
PUBLIC pdum_tsAPduInstance s_asapduZDPInstances[3] = {
    { s_au8apduZDPInstance0Storage, 0, 0, 0 },
    { s_au8apduZDPInstance1Storage, 0, 0, 0 },
    { s_au8apduZDPInstance2Storage, 0, 0, 0 },
};
PRIVATE uint8 s_au8apduZCLInstance0Storage[100];
PRIVATE uint8 s_au8apduZCLInstance1Storage[100];
PRIVATE uint8 s_au8apduZCLInstance2Storage[100];
PRIVATE uint8 s_au8apduZCLInstance3Storage[100];
PRIVATE uint8 s_au8apduZCLInstance4Storage[100];
PRIVATE uint8 s_au8apduZCLInstance5Storage[100];
PRIVATE uint8 s_au8apduZCLInstance6Storage[100];
PRIVATE uint8 s_au8apduZCLInstance7Storage[100];
PRIVATE uint8 s_au8apduZCLInstance8Storage[100];
PRIVATE uint8 s_au8apduZCLInstance9Storage[100];
PUBLIC pdum_tsAPduInstance s_asapduZCLInstances[10] = {
    { s_au8apduZCLInstance0Storage, 0, 0, 1 },
    { s_au8apduZCLInstance1Storage, 0, 0, 1 },
    { s_au8apduZCLInstance2Storage, 0, 0, 1 },
    { s_au8apduZCLInstance3Storage, 0, 0, 1 },
    { s_au8apduZCLInstance4Storage, 0, 0, 1 },
    { s_au8apduZCLInstance5Storage, 0, 0, 1 },
    { s_au8apduZCLInstance6Storage, 0, 0, 1 },
    { s_au8apduZCLInstance7Storage, 0, 0, 1 },
    { s_au8apduZCLInstance8Storage, 0, 0, 1 },
    { s_au8apduZCLInstance9Storage, 0, 0, 1 },
};

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

extern pdum_tsAPdu s_asAPduPool[2];

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

extern void pdum_vNPduInit(pdum_tsNPdu *psNPduPool, uint16 u16Size, OS_thMutex hMutex);
extern void pdum_vAPduInit(pdum_tsAPdu *asAPduPool, uint16 u16NumAPdus, OS_thMutex hMutex);

PUBLIC void PDUM_vInit(void)
{
    /* Version compatibility check */
#if JENNIC_CHIP_FAMILY == JN514x
    asm(".extern PDUM_Version_1v1" : ) ;
    asm("b.addi r0,r0,PDUM_Version_1v1" : );
#elif JENNIC_CHIP_FAMILY == JN513x
    asm(".extern PDUM_Version_1v1" : ) ;
    asm("l.addi r0,r0,hi(PDUM_Version_1v1)" : );
#endif
    pdum_vNPduInit(s_asNPduPool, 15, mutexMAC);
    pdum_vAPduInit(s_asAPduPool, 2, NULL);
}

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

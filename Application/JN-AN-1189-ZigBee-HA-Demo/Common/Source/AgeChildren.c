/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          AgeChildren.c
 *
 * DESCRIPTION:        Child aging code to remove stale child entries
 *
 ****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products [NXP Microcontrollers such as JN5148, JN5142,
 * JN5139]. You, and any third parties must reproduce the copyright and
 * warranty notice and any other legend of ownership on each copy or partial
 * copy of the software.
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
 * Copyright NXP B.V. 2013. All rights reserved
 *
 ***************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

/* Stack Includes */
#include <jendefs.h>
#include "dbg.h"
#include "os.h"
#include "os_gen.h"
#include "pdum_apl.h"
#include "pdum_gen.h"
#include "pdm.h"
#include "zps_apl_af.h"
#include "zps_apl_zdp.h"
#include "zps_apl_aib.h"
#include "zps_nwk_nib.h"
#include "zps_nwk_pub.h"
#include "app_timer_driver.h"
#include "AgeChildren.h"
#include "Utilities.h"
#include "appZdpExtraction.h"
#include "rnd_pub.h"
#include "app_zbp_utilities.h"
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifdef DEBUG_AGE_CHILDREN
#define TRACE_AGE_CHILDREN TRUE
#else
#define TRACE_AGE_CHILDREN FALSE
#endif


/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
PRIVATE bool bAgeChildren_IsChildActiveNow(uint16 u16ChildNwkAddress);
PRIVATE void vClearUsedBits(void);
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/




/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

PRIVATE uint8   u8ChildOfInterest = 0;
PRIVATE uint8   u8ChildAgingAttempt=0;
PRIVATE uint16  u16ActiveEDAddress[APP_MAX_NUMBER_OF_CHILD_ED] = { 0xFFFE,0xFFFE,0xFFFE,0xFFFE, 0xFFFE};

/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/


/****************************************************************************/
/***        Tasks                                                         ***/
/****************************************************************************/

/****************************************************************************
 *
 * NAME: APP_AgeOutChildren
 *
 * DESCRIPTION:
 * Cycles through the device's children on a context restore to find out if
 * they now have a different parent
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
OS_TASK(APP_AgeOutChildren)
{
    uint8 i;
    uint8 u8TransactionSequenceNumber;
    ZPS_tuAddress uAddress;
    ZPS_tsAplZdpNwkAddrReq sAplZdpNwkAddrReq;
    void * thisNet = ZPS_pvAplZdoGetNwkHandle();
    ZPS_tsNwkNib * thisNib = ZPS_psNwkNibGetHandle(thisNet);

    ZPS_teStatus eStatus = 0;

    /* u8ChildOfInterest stored as global so loop starts next location */
    for(i = u8ChildOfInterest ; i < thisNib->sTblSize.u16NtActv ; i++)
    {
        DBG_vPrintf(TRACE_AGE_CHILDREN, "Checking Index: %d \n", i);

        if((thisNib->sTbl.psNtActv[i].u16NwkAddr < 0xFFFE ) && (bAgeChildren_IsChildActiveNow(thisNib->sTbl.psNtActv[i].u16NwkAddr)== FALSE))
        {

            if ( ( ZPS_NWK_NT_AP_RELATIONSHIP_CHILD == thisNib->sTbl.psNtActv[i].uAncAttrs.bfBitfields.u2Relationship   ) && /* Only for child */
                 ( ZPS_NWK_NT_AP_DEVICE_TYPE_ZED    == thisNib->sTbl.psNtActv[i].uAncAttrs.bfBitfields.u1DeviceType     ) && /* Aging is for the END DEVICE as a child */
                 ( TRUE                             != thisNib->sTbl.psNtActv[i].uAncAttrs.bfBitfields.u1RxOnWhenIdle   ) && /* Only for Sleepy EDs */
                 ( TRUE                             == thisNib->sTbl.psNtActv[i].uAncAttrs.bfBitfields.u1Authenticated  ) && /* Deviec is authenticated */
                 ( TRUE                             == thisNib->sTbl.psNtActv[i].uAncAttrs.bfBitfields.u1Used           )    /* Used */
                )
            {
                /* Child found in the neighbour table, send out a address request */
                u8ChildOfInterest = i;

                PDUM_thAPduInstance hAPduInst;
                hAPduInst = PDUM_hAPduAllocateAPduInstance(apduZDP);

                if (hAPduInst == PDUM_INVALID_HANDLE)
                {
                    DBG_vPrintf(TRACE_AGE_CHILDREN, "IEEE Address Request - PDUM_INVALID_HANDLE\n");
                }
                else
                {
                    uAddress.u16Addr = 0xFFFD;
                    sAplZdpNwkAddrReq.u8RequestType = 0;
                    sAplZdpNwkAddrReq.u64IeeeAddr = ZPS_u64NwkNibGetMappedIeeeAddr(thisNet,thisNib->sTbl.psNtActv[i].u16Lookup);

                    /* At least check if the found mac is not a special one */
                    if( (sAplZdpNwkAddrReq.u64IeeeAddr != 0x0000000000000000) && (sAplZdpNwkAddrReq.u64IeeeAddr != 0xFFFFFFFFFFFFFFFF) )
                    {
                        DBG_vPrintf(TRACE_AGE_CHILDREN, "Child found in NT, sending addr request: 0x%04x\n", thisNib->sTbl.psNtActv[i].u16NwkAddr);
                        eStatus = ZPS_eAplZdpNwkAddrRequest(    hAPduInst,
                                                                        uAddress,
                                                                        FALSE,
                                                                        &u8TransactionSequenceNumber,
                                                                        &sAplZdpNwkAddrReq
                                                                        );
                    }

                    if (eStatus)
                    {
                        DBG_vPrintf(TRACE_AGE_CHILDREN, "Address Request failed: 0x%02x\n", eStatus);
                        PDUM_eAPduFreeAPduInstance(hAPduInst);
                    }
                    else
                    {
                        /* only increment the  counter on success or the ieee address to be looked up is found as 0x00000000.or special...., else try again next timer expiry */
                        u8ChildOfInterest++;
                        break;
                    }
                }
            }
        }
    }

    /* Table scan complete, stop the timer and clear down */
    if (i >= thisNib->sTblSize.u16NtActv)
    {

        u8ChildOfInterest = 0;
        u8ChildAgingAttempt++;
        if(u8ChildAgingAttempt > APP_CHILD_AGING_ATTEMPTS)
            OS_eStopSWTimer(APP_AgeOutChildrenTmr);
        else
            OS_eStartSWTimer(APP_AgeOutChildrenTmr, APP_TIME_MS(APP_AGE_CHILDREN_START_TIME_IN_MS), NULL);

    }
    /* Start the timer for the next scan of the neighbour table */
    else
    {
        OS_eStartSWTimer(APP_AgeOutChildrenTmr, APP_TIME_MS(APP_AGE_CHILDREN_NEXT_CHILD_SCAN_TIME_IN_MS), NULL);
    }
}


/****************************************************************************
 *
 * NAME: vCheckIfMyChild
 *
 * DESCRIPTION:
 * called on ZDP_REQ/RESP packet to see if it a NWK address response for
 * one of its own children, is so, remove
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vCheckIfMyChild( ZPS_tsAfEvent  * psStackEvent )
{
    ZPS_tsAfZdpEvent sAfZdpEvent;
    zps_bAplZdpUnpackResponse(psStackEvent,&sAfZdpEvent);

    if (ZPS_ZDP_NWK_ADDR_RSP_CLUSTER_ID == sAfZdpEvent.u16ClusterId)
    {
        if( (!sAfZdpEvent.uZdpData.sNwkAddrRsp.u8Status) &&
                (ZPS_u16AplZdoGetNwkAddr() != psStackEvent->uEvent.sApsDataIndEvent.uSrcAddress.u16Addr ) &&
                (bAgeChildren_IsChildActiveNow(sAfZdpEvent.uZdpData.sNwkAddrRsp.u16NwkAddrRemoteDev) == FALSE))
        {
            void * thisNet = ZPS_pvAplZdoGetNwkHandle();
            ZPS_tsNwkNib * thisNib = ZPS_psNwkNibGetHandle(thisNet);
            uint8 i;

            DBG_vPrintf(TRACE_AGE_CHILDREN, "NWK Lookup Resp: 0x%04x 0x%016llx\n",
                    sAfZdpEvent.uZdpData.sNwkAddrRsp.u16NwkAddrRemoteDev,
                    sAfZdpEvent.uZdpData.sNwkAddrRsp.u64IeeeAddrRemoteDev);

            for(i = 0 ; i < thisNib->sTblSize.u16NtActv ; i++)
            {

                if ((sAfZdpEvent.uZdpData.sNwkAddrRsp.u64IeeeAddrRemoteDev == ZPS_u64NwkNibGetMappedIeeeAddr(thisNet,thisNib->sTbl.psNtActv[i].u16Lookup)) &&
                    ( ZPS_NWK_NT_AP_RELATIONSHIP_CHILD == thisNib->sTbl.psNtActv[i].uAncAttrs.bfBitfields.u2Relationship ) &&
                    /* Only remove ED */
                    ( ZPS_NWK_NT_AP_DEVICE_TYPE_ZED == thisNib->sTbl.psNtActv[i].uAncAttrs.bfBitfields.u1DeviceType) &&
                    /* The RxOnIdle Child may also reply - C1 and C2 both has Rx On Idle
                     * C1 was associated with R3 now when R3 is off it rejoined R1
                     * C1<---->R1<--->R2<----->R3<---->C2
                     * R3 Going for check for match for C1 as well as C3, both have RxOnIdeal
                     * R1,C2,C1 are sending a response to R3 but only C1 need to be removed.
                     * */
                    (   ( TRUE != thisNib->sTbl.psNtActv[i].uAncAttrs.bfBitfields.u1RxOnWhenIdle)
                    ) )
                {

                    extern void ZPS_vRemoveMacTableEntry(uint64 u64MacAddress);

                    DBG_vPrintf(TRACE_AGE_CHILDREN, "\r\n IEEE response and NT Match");
                    DBG_vPrintf(TRACE_AGE_CHILDREN, "\n **************************Before******************************* \n");
                    vDisplayAddressMapTable();
                    vDisplayNT();
                    DBG_vPrintf(TRACE_AGE_CHILDREN, "\n *************************************************************** \n");
                    uint64 u64MacAddress = ZPS_u64NwkNibGetMappedIeeeAddr(thisNet,thisNib->sTbl.psNtActv[i].u16Lookup);

                    /*There is another API to remove the contents of the MAC table*/
                    ZPS_vRemoveMacTableEntry(u64MacAddress);

                    DBG_vPrintf(TRACE_AGE_CHILDREN, "\nPrintng table After ZPS_vRemoveMacTableEntry and Before vClearUsedBits \n");
                    vDisplayNT();

                    /*Clean up the Used bit*/
                    vClearUsedBits();

                    ZPS_vSaveAllZpsRecords();

                    DBG_vPrintf(TRACE_AGE_CHILDREN, "\n *****************************After****************************** \n");
                    vDisplayAddressMapTable();
                    vDisplayNT();
                    DBG_vPrintf(TRACE_AGE_CHILDREN, "\n *************************************************************** \n");
                }
            }
        }
    }
}

/****************************************************************************
 *
 * NAME: vAgeChildren_ChildJoined
 *
 * DESCRIPTION:
 * called on NWK event to mark a child has joined and make an entry
 * in an application array so that child aging that is called after 15 sec
 * will not remove it
 *
 * PARAMETERS:
 * ZPS_tsAfEvent  *psStackEvent : Pointer to ZPS stack event
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAgeChildren_ChildJoined(ZPS_tsAfEvent  *psStackEvent)
{
    uint8 i;
    DBG_vPrintf(TRACE_AGE_CHILDREN, "\n psStackEvent->uEvent.sNwkJoinIndicationEvent.u8Capability = %d, ED =  %d \n",
            psStackEvent->uEvent.sNwkJoinIndicationEvent.u8Capability,
            psStackEvent->uEvent.sNwkJoinIndicationEvent.u8Capability & 0x02);
    if((psStackEvent->uEvent.sNwkJoinIndicationEvent.u8Capability & 0x02) == 0)
    {
        if(bAgeChildren_IsChildActiveNow(psStackEvent->uEvent.sNwkJoinIndicationEvent.u16NwkAddr))
        {
            /* entry already present, return */
            DBG_vPrintf(TRACE_AGE_CHILDREN, "\n entry already present, return  \n");
            return;
        }
        for(i = 0; i < APP_MAX_NUMBER_OF_CHILD_ED; i++)
        {
            if(u16ActiveEDAddress[i] == 0xFFFE)
            {
                DBG_vPrintf(TRACE_AGE_CHILDREN, "\n entry added  \n");
                /* store child address that has just joined */
                u16ActiveEDAddress[i] = psStackEvent->uEvent.sNwkJoinIndicationEvent.u16NwkAddr;
                return;
            }
        }
    }
}
/****************************************************************************
 *
 * NAME: bAgeChildren_IsChildActiveNow
 *
 * DESCRIPTION:
 * Called to check if the child is rejoined after the router has restarted.
 *
 * PARAMETERS:
 * uint16 u16ChildNwkAddress : Short address of child
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE bool bAgeChildren_IsChildActiveNow(uint16 u16ChildNwkAddress)
{
    uint8 i;
    for(i = 0; i < APP_MAX_NUMBER_OF_CHILD_ED; i++)
    {
        if(u16ActiveEDAddress[i] == u16ChildNwkAddress)
        {
            return TRUE;
        }
    }
    return FALSE;
}

/****************************************************************************
 *
 * NAME: vClearUsedBits
 *
 * DESCRIPTION:
 * Called to clear the used bits in the NT for the child those are with
 * short address 0xFFFE.
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vClearUsedBits(void)
{
    void *pvNwk = ZPS_pvAplZdoGetNwkHandle();
    ZPS_tsNwkNib *psNib = ZPS_psNwkNibGetHandle(pvNwk);

    uint16 u16Counter;

    for(u16Counter = 0; u16Counter < psNib->sTblSize.u16NtActv; u16Counter++)
    {
        if(psNib->sTbl.psNtActv[u16Counter].u16NwkAddr == 0xfffe)
        {
            ZPS_vNtSetUsedStatus(pvNwk, &psNib->sTbl.psNtActv[u16Counter], FALSE);
        }
    }
}

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

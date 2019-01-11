/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          PingParent.c
 *
 * DESCRIPTION:        Pings the parent and check to take decision to rejoin.
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
#include "Utilities.h"
#include "PingParent.h"
#include "appZdpExtraction.h"
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#ifndef DEBUG_PING_PARENT
    #define TRACE_PING_PARENT FALSE
#else
    #define TRACE_PING_PARENT TRUE
#endif


/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/


/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
uint32 u32PingTime=0;

bool_t bPingSent = FALSE;
bool_t bPingRespRcvd = TRUE;
bool_t bPingReqApsAckFailure=FALSE;
uint8 u8TransactionSequenceNumber;
/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/


/****************************************************************************/
/***        Tasks                                                          ***/
/****************************************************************************/
/****************************************************************************
 *
 * NAME: vIncrementPingTime
 *
 * DESCRIPTION:
 * Increment the Time for ping
 *
 * PARAMETERS:
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vIncrementPingTime(uint8 u8Time)
{
    u32PingTime +=u8Time;
}

/****************************************************************************
 *
 * NAME: bPingParent
 *
 * DESCRIPTION:
 * Read Basic Cluster attribute
 *
 * PARAMETERS:
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC bool_t bPingParent(void)
{

    ZPS_tsNwkNib * thisNib;
    ZPS_teStatus eStatus=1;
    void * thisNet = ZPS_pvAplZdoGetNwkHandle();

    bPingSent=FALSE;
    bPingRespRcvd = FALSE;
    bPingReqApsAckFailure=FALSE;

    if(u32PingTime >=APP_PING_TIME_IN_SECOND )
    {
        u32PingTime=0;
        thisNib = ZPS_psNwkNibGetHandle(thisNet);
        PDUM_thAPduInstance hAPduInst;
        hAPduInst = PDUM_hAPduAllocateAPduInstance(apduZDP);

        if (hAPduInst == PDUM_INVALID_HANDLE)
        {
            DBG_vPrintf(TRACE_PING_PARENT, "IEEE Address Request - PDUM_INVALID_HANDLE\n");
        }
        else
        {
            ZPS_tuAddress uAddress;
            ZPS_tsAplZdpNwkAddrReq sAplZdpNwkAddrReq;

            uAddress.u16Addr = thisNib->sTbl.psNtActv[0].u16NwkAddr;

            sAplZdpNwkAddrReq.u64IeeeAddr = ZPS_u64NwkNibGetMappedIeeeAddr(thisNet,thisNib->sTbl.psNtActv[0].u16Lookup);
            sAplZdpNwkAddrReq.u8RequestType = 0;

            eStatus = ZPS_eAplZdpNwkAddrRequest(    hAPduInst,
                                                                uAddress,
                                                                FALSE,
                                                                &u8TransactionSequenceNumber,
                                                                &sAplZdpNwkAddrReq
                                                                );
            if (eStatus)
            {
                DBG_vPrintf(TRACE_PING_PARENT, "Address Request failed: 0x%02x\n", eStatus);
                PDUM_eAPduFreeAPduInstance(hAPduInst);
            }
        }
    }

    if(!eStatus)
    {
        bPingSent=TRUE;
        bPingRespRcvd = FALSE;
        bPingReqApsAckFailure=FALSE;
        return TRUE;
    }
    return FALSE;
}


OS_TASK(APP_PingTimerTask)
{
    OS_eStopSWTimer(App_PingTimer);
    if( (TRUE == bPingSent) && (FALSE == bPingRespRcvd) && (TRUE==bPingReqApsAckFailure))
    {
        ZPS_eAplZdoRejoinNetwork(FALSE);
    }
}

/****************************************************************************
 *
 * NAME: vPingRecv
 *
 * DESCRIPTION:
 * called on ZDP_REQ/RESP packet to see if it a NWK address response for
 * its parent is recieved else go for rejoin
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vPingRecv(ZPS_tsAfEvent  * psStackEvent)
{
    DBG_vPrintf(TRACE_PING_PARENT,"Ping Parent in vPingRecv Event = %d  \n",psStackEvent->eType);
    if((ZPS_EVENT_APS_DATA_INDICATION == psStackEvent->eType) &&
            (0 == psStackEvent->uEvent.sApsDataIndEvent.u8DstEndpoint))
    {
        ZPS_tsAfZdpEvent sAfZdpEvent;
        zps_bAplZdpUnpackResponse(psStackEvent, &sAfZdpEvent);

        if ( (ZPS_ZDP_NWK_ADDR_RSP_CLUSTER_ID == sAfZdpEvent.u16ClusterId) && bPingSent)
        {
            bPingRespRcvd = TRUE;
        }
    }
    else if( (ZPS_EVENT_APS_DATA_ACK == psStackEvent->eType) &&
             (0 == psStackEvent->uEvent.sApsDataAckEvent.u8DstEndpoint))
    {

        DBG_vPrintf(TRACE_PING_PARENT,"Ping Parent APS Ack u16ClusterId =%04x\n",psStackEvent->uEvent.sApsDataAckEvent.u16ClusterId);
        DBG_vPrintf(TRACE_PING_PARENT,"Ping Parent APS Ack u16ProfileId =%04x\n",psStackEvent->uEvent.sApsDataAckEvent.u16ProfileId);
        DBG_vPrintf(TRACE_PING_PARENT,"Ping Parent APS Ack u8SequenceNum =%02x\n",psStackEvent->uEvent.sApsDataAckEvent.u8SequenceNum);
        DBG_vPrintf(TRACE_PING_PARENT,"Ping Parent APS Req TransactionbSeq number =%02x\n",u8TransactionSequenceNumber);
        DBG_vPrintf(TRACE_PING_PARENT,"Ping Parent APS Ack u16DstAddr =%04x\n",psStackEvent->uEvent.sApsDataAckEvent.u16DstAddr);
        DBG_vPrintf(TRACE_PING_PARENT,"Ping Parent APS Ack u8DstAddrMode =%02x\n",psStackEvent->uEvent.sApsDataAckEvent.u8DstAddrMode);
        DBG_vPrintf(TRACE_PING_PARENT,"Ping Parent APS Ack u8DstEndpoint =%02x\n",psStackEvent->uEvent.sApsDataAckEvent.u8DstEndpoint);
        DBG_vPrintf(TRACE_PING_PARENT,"Ping Parent APS Ack u8SrcEndpoint =%02x\n",psStackEvent->uEvent.sApsDataAckEvent.u8SrcEndpoint);

        if( (psStackEvent->uEvent.sApsDataAckEvent.u8Status) &&(bPingSent))
        {
            /* Ping Sent --
             * The APS data ack with failure - may suggest a rejoin.
             * its better to check the tx APS counter to match the APS failure for the ping request
             * */
            DBG_vPrintf(TRACE_PING_PARENT,"\n\nAPS ACK FAILURE status = %d\n\n",psStackEvent->uEvent.sApsDataAckEvent.u8Status);
            bPingReqApsAckFailure =TRUE;
        }
    }
    else if(ZPS_EVENT_NWK_JOINED_AS_ENDDEVICE == psStackEvent->eType)
    {
        /* Device joined during the ping hence stop the timer and reset the count to stop a false rejoining*/
        u32PingTime=0;
        OS_eStopSWTimer(App_PingTimer);
    }

}
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

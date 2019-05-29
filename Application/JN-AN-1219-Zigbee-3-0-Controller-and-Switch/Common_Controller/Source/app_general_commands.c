/*****************************************************************************
 *
 * MODULE:             JN-AN-1219
 *
 * COMPONENT:          
 *
 * DESCRIPTION:        
 *
 ****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products [NXP Microcontrollers such as JN5168, JN5179].
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

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#include <jendefs.h>
#include "dbg.h"
#include "zps_gen.h"
#include "pdum_gen.h"
#include "app_common.h"
#include "zlo_controller_node.h"
#include "app_menu_handler.h"
#include "app_general_commands.h"
#include "app_group_commands.h"
#include "rnd_pub.h"

#ifdef DEBUG_APP
    #define TRACE_APP   TRUE
#else
    #define TRACE_APP   FALSE
#endif

#ifdef DEBUG_REMOTE_NODE
    #define TRACE_REMOTE_NODE   TRUE
#else
    #define TRACE_REMOTE_NODE   FALSE
#endif

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/



/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/



/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/


/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/


/****************************************************************************
 *
 * NAME: vSetAddress
 *
 * DESCRIPTION: set the appropriate address parameters for the current addressing mode
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vSetAddress(tsZCL_Address * psAddress, bool_t bBroadcast)
{

    if (bBroadcast)
    {
        psAddress->eAddressMode = E_ZCL_AM_BROADCAST;
        psAddress->uAddress.eBroadcastMode = ZPS_E_APL_AF_BROADCAST_RX_ON;
    }
    else if (bAddrMode)
    {
        psAddress->eAddressMode = E_ZCL_AM_GROUP;
        psAddress->uAddress.u16DestinationAddress = sGroupTable.asGroupRecords[u8GroupId].u16GroupId;
    }
    else
    {
        psAddress->eAddressMode = E_ZCL_AM_SHORT_NO_ACK;
        psAddress->uAddress.u16DestinationAddress = sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u16NwkAddr;
    }
}

/****************************************************************************
 *
 * NAME: vSetAddressMode
 *
 * DESCRIPTION: toggle between groupcast and unicast
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vSetAddressMode(void)
{
    bAddrMode = !bAddrMode;
#if TRACE_REMOTE_NODE
    if (bAddrMode)
    {
        DBG_vPrintf(TRACE_REMOTE_NODE, "\nG_CAST\n");
    }
    else
    {
        DBG_vPrintf(TRACE_REMOTE_NODE, "\nU_CAST\n");
    }
#endif
}

/****************************************************************************
 *
 * NAME: bAppSendBasicResetReq
 *
 * DESCRIPTION: send Send a Reset Basic cluster command
 *              the target will factory reset its ZCL data,
 *              but leave the Stack (Apl & Nak data uintact)
 *              ie remain active on the network
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void bAppSendBasicResetReq( void)
{
    uint8 u8SeqNum;
    tsZCL_Address sAddress;
    teZCL_Status eZCL_Status;

    vSetAddress(&sAddress, FALSE);

    eZCL_Status = eCLD_BasicCommandResetToFactoryDefaultsSend(
                            sDeviceTable.asDeviceRecords[0].u8Endpoint,
                            sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint, /*DstEP*/
                            &sAddress,
                            &u8SeqNum);

    DBG_vPrintf(TRACE_APP,"\nBasic Factory Reset eZCL_Status %02x  \n",eZCL_Status);
}


/****************************************************************************
 *
 * NAME: vAppChangeChannel
 *
 * DESCRIPTION: This function change the channel randomly to one of the other primaries
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppChangeChannel( void)
{
    ZPS_tsAplZdpMgmtNwkUpdateReq sZdpMgmtNwkUpdateReq;
    PDUM_thAPduInstance hAPduInst;
    ZPS_tuAddress uDstAddr;
    uint8 u8Seq;
    uint8 u8CurrentChannel, u8RandomNum;

    uint8 au8ZLLChannelSet[4] = {11,15,20,25};

    hAPduInst = PDUM_hAPduAllocateAPduInstance(apduZCL);
    if (hAPduInst != NULL)
    {
        sZdpMgmtNwkUpdateReq.u8ScanDuration = 0xfe;

        u8CurrentChannel = ZPS_u8AplZdoGetRadioChannel();
        u8RandomNum = RND_u32GetRand( 0, 3);
        if(u8CurrentChannel != au8ZLLChannelSet[u8RandomNum])
        {
            sZdpMgmtNwkUpdateReq.u32ScanChannels = (1<<au8ZLLChannelSet[u8RandomNum]);
        }
        else // Increment the channel by one rather than spending in RND_u32GetRand
        {
            // For roll over situation
            if(u8RandomNum == 3)
            {
                sZdpMgmtNwkUpdateReq.u32ScanChannels = (1<<au8ZLLChannelSet[0]);
            }
            else
            {
                sZdpMgmtNwkUpdateReq.u32ScanChannels = (1<<au8ZLLChannelSet[u8RandomNum+1]);
            }
        }

        sZdpMgmtNwkUpdateReq.u8NwkUpdateId = ZPS_psAplZdoGetNib()->sPersist.u8UpdateId + 1;
        uDstAddr.u16Addr = 0xfffd;

        if ( 0 == ZPS_eAplZdpMgmtNwkUpdateRequest( hAPduInst,
                                         uDstAddr,
                                         FALSE,
                                         &u8Seq,
                                         &sZdpMgmtNwkUpdateReq))
        {
            DBG_vPrintf(TRACE_REMOTE_NODE, "update Id\n");
            /* should really be in stack?? */
            ZPS_psAplZdoGetNib()->sPersist.u8UpdateId++;
        }
    }

}




/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

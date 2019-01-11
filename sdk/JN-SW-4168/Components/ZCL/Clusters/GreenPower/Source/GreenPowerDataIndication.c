/*****************************************************************************
 *
 * MODULE:             Green Power Cluster
 *
 * COMPONENT:          GreenPowerDataIndication.c
 *
 * AUTHOR:             Ramakrishna
 *
 * DESCRIPTION:        The handling functions for the Green Power direct data commands
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/UnifiedZCL_ZLL102_HA122_Maintenance/Clusters/GreenPower/Source/GreenPowerDataIndication.c $
 *
 * $Revision: 65890 $
 *
 * $LastChangedBy: nxp58432 $
 *
 * $LastChangedDate: 2014-11-21 09:31:00 +0000 (Fri, 21 Nov 2014) $
 *
 * $Id: GreenPowerDataIndication.c 65890 2014-11-21 09:31:00Z nxp58432 $
 *
 *****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products  [NXP Microcontrollers such as JN5168, JN5164,
 * JN5161, JN5148, JN5142, JN5139].
 * You, and any third parties must reproduce the copyright and warranty notice
 * and any other legend of ownership on each  copy or partial copy of the software.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
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
 * Copyright NXP B.V. 2012. All rights reserved
 *
 ****************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#include <jendefs.h>
#include <string.h>
#include "dlist.h"
#include "zcl.h"
#include "GreenPower.h"
#include "GreenPower_internal.h"
#include "zcl_common.h"
#include "dbg.h"
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifndef TRACE_GP_DEBUG
#define TRACE_GP_DEBUG FALSE
#endif
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
PRIVATE bool_t bGP_DuplicateFilterForDirectGpdf(
                    ZPS_tsAfEvent                          *pZPSevent,
                    uint8                                  u8GpEndpoint,
                    bool_t                                 bIsServer,
                    tsGP_GreenPowerCustomData              *psGpCustomDataStructure);

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/


/****************************************************************************
 **
 ** NAME:       vZCL_HandleZgpDataIndication
 **
 ** DESCRIPTION:
 ** Valididates the ZGP(Green Power) Data Indication Event
 **
 ** PARAMETERS:               Name                    Usage
 ** ZPS_tsAfEvent           *pZPSevent               Zigbee stack event structure
 ** uint8                   u8GpEndpoint             Green Power Local End Point
 ** RETURN:
 ** None
 **
 ****************************************************************************/
PUBLIC void vZCL_HandleZgpDataIndication(ZPS_tsAfEvent *pZPSevent, uint8 u8GpEndpoint)
{
    tsZCL_CallBackEvent         sZCL_CallBackEvent;
    tsZCL_EndPointDefinition    *psEndPointDefinition;
    tsZCL_ClusterInstance       *psClusterInstance;
    tsGP_GreenPowerCustomData   *psGpCustomDataStructure;
    bool_t                      bIsServer = TRUE;

    // fill in callback event
    sZCL_CallBackEvent.u8TransactionSequenceNumber = 0;
    sZCL_CallBackEvent.psClusterInstance = NULL;
    sZCL_CallBackEvent.pZPSevent = pZPSevent;
    sZCL_CallBackEvent.eZCL_Status = E_ZCL_SUCCESS;

#ifndef GP_IEEE_ADDR_SUPPORT
    if(pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId == 2)
    {
        sZCL_CallBackEvent.eZCL_Status = E_ZCL_ERR_INVALID_VALUE;
    }
#endif
    /* application id should not other than 0 and 2 OR if application id 2 then
     * MAC source address mode should be 3*/
    if(((pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId != 0) &&
         (pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId != 2)) ||
        ((pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId == 2) &&
        (pZPSevent->uEvent.sApsZgpDataIndEvent.u8SrcAddrMode != 3))||
        (sZCL_CallBackEvent.eZCL_Status != E_ZCL_SUCCESS))
    {
        sZCL_CallBackEvent.eZCL_Status = E_ZCL_ERR_MALFORMED_MESSAGE;
    }
    /* Default cluster instance is based on device type */
    /* This will be set in next release code */
    // find GP Cluster
    else if(eGP_FindGpCluster(u8GpEndpoint,
            bIsServer,
            &psEndPointDefinition,
            &psClusterInstance,
            &psGpCustomDataStructure) != E_ZCL_SUCCESS)
    {
        bIsServer = FALSE;

        if(eGP_FindGpCluster(u8GpEndpoint,
                        FALSE,
                        &psEndPointDefinition,
                        &psClusterInstance,
                        &psGpCustomDataStructure) != E_ZCL_SUCCESS)
        {
            sZCL_CallBackEvent.eZCL_Status = E_ZCL_ERR_CLUSTER_NOT_FOUND;
        }
    }

    /* check for duplicate pkt, if it is a duplicate then just drop it */
    if(sZCL_CallBackEvent.eZCL_Status == E_ZCL_SUCCESS)
    {
        /* Check Duplicate only for when device is in operation mode */
        if(bGP_DuplicateFilterForDirectGpdf(pZPSevent, u8GpEndpoint, bIsServer, psGpCustomDataStructure))
        {
            PDUM_eAPduFreeAPduInstance(pZPSevent->uEvent.sApsZgpDataIndEvent.hAPduInst);
            return;
        }

        eGP_GreenPowerDirectCommandHandler( pZPSevent,
                                            psEndPointDefinition,
                                            psClusterInstance);
    }


    if(E_ZCL_SUCCESS != sZCL_CallBackEvent.eZCL_Status)
    {
        sZCL_CallBackEvent.eEventType = E_ZCL_CBET_ZGP_DATA_IND_ERROR;
        psZCL_Common->pfZCLinternalCallBackFunction(&sZCL_CallBackEvent);
    }

    PDUM_eAPduFreeAPduInstance(pZPSevent->uEvent.sApsZgpDataIndEvent.hAPduInst);
}

/****************************************************************************
 **
 ** NAME:       vZCL_HandleZgpDataConfirm
 **
 ** DESCRIPTION:
 ** Valididates the ZGP(Green Power) Data Indication Event
 **
 ** PARAMETERS:               Name                    Usage
 ** ZPS_tsAfEvent           *pZPSevent               Zigbee stack event structure
 ** uint8                   u8GpEndpoint             Green Power Local End Point
 ** RETURN:
 ** None
 **
 ****************************************************************************/
PUBLIC void vZCL_HandleZgpDataConfirm(ZPS_tsAfEvent *pZPSevent, uint8 u8GpEndpoint)
{
    tsZCL_CallBackEvent         sZCL_CallBackEvent;
    tsZCL_EndPointDefinition    *psEndPointDefinition;
    tsZCL_ClusterInstance       *psClusterInstance;
    tsGP_GreenPowerCustomData   *psGpCustomDataStructure;
    bool_t                      bIsServer = TRUE;

    // fill in callback event
    sZCL_CallBackEvent.u8TransactionSequenceNumber = 0;
    sZCL_CallBackEvent.psClusterInstance = NULL;
    sZCL_CallBackEvent.pZPSevent = pZPSevent;
    sZCL_CallBackEvent.eZCL_Status = E_ZCL_SUCCESS;

    /* Default cluster instance is based on device type */
    /* This will be set in next release code */
    // find GP Cluster
    if(eGP_FindGpCluster(u8GpEndpoint,
            bIsServer,
            &psEndPointDefinition,
            &psClusterInstance,
            &psGpCustomDataStructure) != E_ZCL_SUCCESS)
    {
        bIsServer = FALSE;

        if(eGP_FindGpCluster(u8GpEndpoint,
                        FALSE,
                        &psEndPointDefinition,
                        &psClusterInstance,
                        &psGpCustomDataStructure) != E_ZCL_SUCCESS)
        {
            sZCL_CallBackEvent.eZCL_Status = E_ZCL_ERR_CLUSTER_NOT_FOUND;
        }
    }

    /* check for duplicate pkt, if it is a duplicate then just drop it */
    if(sZCL_CallBackEvent.eZCL_Status == E_ZCL_SUCCESS)
    {
        uint8 u8DataReqHandle;

        u8DataReqHandle = psGpCustomDataStructure->u8GPDataReqHandle;

        if(u8DataReqHandle == 0x81)
        {
            u8DataReqHandle = 0xFF;
        }
        else
        {
            u8DataReqHandle--;
        }

        if(pZPSevent->uEvent.sApsZgpDataConfirmEvent.u8Handle == u8DataReqHandle)
        {
            if(psGpCustomDataStructure->u16TransmitChannelTimeout)
            {
                psGpCustomDataStructure->u16TransmitChannelTimeout = 0;
#ifndef PC_PLATFORM_BUILD
                ZPS_vNwkNibSetChannel( ZPS_pvAplZdoGetNwkHandle(), psGpCustomDataStructure->u8OperationalChannel);
#endif
            }
        }
    }


    if(E_ZCL_SUCCESS != sZCL_CallBackEvent.eZCL_Status)
    {
        sZCL_CallBackEvent.eEventType = E_ZCL_CBET_ZGP_DATA_IND_ERROR;
        psZCL_Common->pfZCLinternalCallBackFunction(&sZCL_CallBackEvent);
    }

    PDUM_eAPduFreeAPduInstance(pZPSevent->uEvent.sApsZgpDataIndEvent.hAPduInst);
}
/****************************************************************************
 **
 ** NAME:       bGP_DuplicateFilterForDirectGpdf
 **
 ** DESCRIPTION:
 ** Duplicate filter
 **
 ** PARAMETERS:                    Name                           Usage
 ** ZPS_tsAfEvent               *pZPSevent                ZPS event
 ** uint8                       u8SourceEndPoint          Source endpoint
 ** bool_t                      bIsServer                 Is cluster server or client
 **
 ** RETURN:
 ** bool_t
 ****************************************************************************/
PRIVATE bool_t bGP_DuplicateFilterForDirectGpdf(
                    ZPS_tsAfEvent                          *pZPSevent,
                    uint8                                  u8SourceEndPoint,
                    bool_t                                 bIsServer,
                    tsGP_GreenPowerCustomData              *psGpCustomDataStructure)
{

    tuGP_ZgpdDeviceAddr uZgpdDeviceAddr;
    bool_t bSecurityOptions;
    uint32 u32SeqNoOrCounter;
    uint16 u16SourceAddress = 0;

    /* Check Application Id */
    /* Copy Green Power Device Address */
    if(pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId == GP_APPL_ID_4_BYTE)
    {
        uZgpdDeviceAddr.u32ZgpdSrcId = pZPSevent->uEvent.sApsZgpDataIndEvent.u32SrcId;
    }
#ifdef GP_IEEE_ADDR_SUPPORT
    else
    {
        uZgpdDeviceAddr.u64ZgpdIEEEAddr = pZPSevent->uEvent.sApsZgpDataIndEvent.uSrcAddress.u64Addr;
    }
#endif
    /* check security level */
    if(pZPSevent->uEvent.sApsZgpDataIndEvent.u2SecurityLevel == 0)
    {
        bSecurityOptions = FALSE;
        u32SeqNoOrCounter = (uint32)pZPSevent->uEvent.sApsZgpDataIndEvent.u8SeqNum;
    }
    else
    {
        bSecurityOptions = TRUE;
        u32SeqNoOrCounter = pZPSevent->uEvent.sApsZgpDataIndEvent.u32SecFrameCounter;
    }
#ifndef PC_PLATFORM_BUILD
    u16SourceAddress =  ZPS_u16AplZdoGetNwkAddr();
#endif
    return(bGP_IsDuplicatePkt(
                  u8SourceEndPoint,
                  bIsServer,
                  (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u2ApplicationId,
                  uZgpdDeviceAddr,
                  bSecurityOptions,
                  u32SeqNoOrCounter,
                  (uint8)pZPSevent->uEvent.sApsZgpDataIndEvent.u8CommandId,
                  (uint8)PDUM_u16APduInstanceGetPayloadSize(pZPSevent->uEvent.sApsZgpDataIndEvent.hAPduInst),
                  (uint8*)(PDUM_pvAPduInstanceGetPayload(pZPSevent->uEvent.sApsZgpDataIndEvent.hAPduInst)),
                  u16SourceAddress,
                  psGpCustomDataStructure));
}

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

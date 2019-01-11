/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          haEzFindAndBind.c
 *
 * DESCRIPTION:        HA EZ mode commissioning (Implementation)
 *
 *****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products [NXP Microcontrollers such as JN5168, JN5164,
 * JN5161, JN5148, JN5142, JN5139].
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
 * Copyright NXP B.V. 2013. All rights reserved
 *
 ****************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#include <jendefs.h>
#include "zps_apl.h"
#include "zps_apl_aps.h"
#include "pdum_gen.h"
#include "zcl.h"
#include "zcl_options.h"
#include "haEzFindAndBind.h"
#include "zcl_common.h"
#include "zps_apl_aib.h"
#include "dbg.h"
#include <string.h>
#include "Identify.h"
#include "pwrm.h"
#include "app_timer_driver.h"
#include "app_zbp_utilities.h"
#ifdef CLD_GROUPS
#include "groups.h"
#include "Groups_internal.h"
#endif
#include "appZdpExtraction.h"

#include "os_gen.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifndef DEBUG_EZMODE
#define TRACE_EZMODE FALSE
#else
#define TRACE_EZMODE TRUE
#endif

#define ZDP_IEEE_ADDR_RSP_CLUSTER_ID                (0x8001)
#define ZDP_SIMPLE_DESC_RSP_CLUSTER_ID                (0x8004)
#define E_CLD_IDENTIFY_CMD_IDENTIFY_QUERY_RESPONSE     E_CLD_IDENTIFY_CMD_IDENTIFY
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/

PRIVATE bool_t bEZ_IsClusterExcludedFromBinding(uint16 u16ClusterID,bool_t bServer);
PRIVATE teEZ_Status eEZ_HandleFindAndBind(uint8 u8SourceEndPointId, teEZ_Mode eEZ_Mode, uint8 u8State );

#ifdef EZ_MODE_TARGET
PRIVATE teEZ_Status eStartEZTarget(uint8 u8SourceEndPointId);
#endif

#ifdef EZ_MODE_INITIATOR
PRIVATE void vEZ_TimerClickCallback(void);
PRIVATE teZCL_Status eDiscover(uint8 u8SourceEndPointId);
PRIVATE teEZ_Status eReStartEZInitiator(uint8 u8SourceEndPointId);
PRIVATE teEZ_Status eStartEZInitiator(uint8 u8SourceEndPointId,uint8 u8State);
PRIVATE void vEZ_IEEEAddressReqSend( ZPS_tuAddress uSrcAddress, uint16 u16DstAddr);
PRIVATE void vEZ_SimpleDescriptorSend(uint8 u8DstEndpoint, uint16 u16DstAddr);
PRIVATE void vEZ_HandleZDPResponse(ZPS_tsAfEvent *pZPSevent);
PRIVATE void vEZ_HandleSimpleDescriptorResponse(tsEZ_Info *psEZInfo, ZPS_tsAfZdpEvent *psAfZdpEvent);
#ifdef EZ_ENABLE_GROUP
#ifdef EZ_CHECK_FOR_BINDING_GROUPING
    PRIVATE void vEZ_AddToGroupWhenIdentifying(uint8 u8SourceEndpoint, uint8 u8DstEndpoint,uint16 u16ShortAddress, bool_t bGroupCast);
#else
    PRIVATE void vEZ_AddToGroupWhenIdentifying(uint8 u8SourceEndpoint, uint8 u8DstEndpoint,uint16 u16ShortAddress);
#endif
#endif
#endif
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
PRIVATE tsEZ_FindAndBind sEZModeData = { 0};

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
/****************************************************************************
 *
 * NAME: eEZ_FindAndBind
 *
 * DESCRIPTION:
 * should be called for performing service discovery and binding of clusters
 * registered while endpoint registration on an initiator and for putting the
 * device in identify mode for EZ_MODE_TIME on an initiator.
 *
 * PARAMETERS:  Name                            Usage
 *                u8SourceEndpoint                the source endpoint
 *                eEZ_Mode                        the EZ find and bind mode.Possible
 *                                                values are
 *                                                E_EZ_INITIATOR and E_EZ_TARGET.
 * RETURNS:
 * None
 *
 ****************************************************************************/
PUBLIC teEZ_Status eEZ_FindAndBind(uint8 u8SourceEndPointId, teEZ_Mode eEZ_Mode)
{
    teEZ_Status eStatus;

    DBG_vPrintf(TRACE_EZMODE, "eEZ_FindAndBind start  \n");

    eStatus = eEZ_HandleFindAndBind(    u8SourceEndPointId,
                                        eEZ_Mode,
                                        E_EZ_FIND_AND_BIND_INITIATOR_IN_PROGRESS);
    return eStatus;
}
/****************************************************************************
 *
 * NAME: vEZ_FactoryReset
 *
 * DESCRIPTION:
 * should be called to remove(unbind) binding entries.
 *
 * PARAMETERS:  Name                            Usage
 *                u8SourceEndpoint                the source endpoint
 *
 * RETURNS:
 * None
 *
 ****************************************************************************/
PUBLIC void vEZ_FactoryReset(uint8 u8SourceEndpoint)
{
    int j;
    ZPS_tsAplAib * psAplAib;
    DBG_vPrintf(TRACE_EZMODE, "\nvEZ_FactoryReset Entry \n\n");

    /*********** Remove Binding Entries ******************************/
    DBG_vPrintf(TRACE_EZMODE, "\nGet binding table \n\n");
    /* get binding table */
    psAplAib  = ZPS_psAplAibGetAib();

    if(psAplAib->psAplApsmeAibBindingTable == NULL)
    {
        DBG_vPrintf(TRACE_EZMODE,"\n No Binding Table \n");
    }
    else
    {
        DBG_vPrintf(TRACE_EZMODE, "\r\nBind Size %d",  psAplAib->psAplApsmeAibBindingTable->psAplApsmeBindingTable[0].u32SizeOfBindingTable );

        for( j = 0 ; j < psAplAib->psAplApsmeAibBindingTable->psAplApsmeBindingTable[0].u32SizeOfBindingTable ; j++ )
        {
            /* unbind */
            ZPS_teStatus  eStatus;
            /* unbind each entry */
            eStatus = ZPS_eAplZdoUnbind(
                         psAplAib->psAplApsmeAibBindingTable->psAplApsmeBindingTable[0].
                         pvAplApsmeBindingTableEntryForSpSrcAddr[j].u16ClusterId,

                         psAplAib->psAplApsmeAibBindingTable->psAplApsmeBindingTable[0].
                         pvAplApsmeBindingTableEntryForSpSrcAddr[j].u8SourceEndpoint,

                         0xFFFF,
                         psAplAib->psAplApsmeAibBindingTable->psAplApsmeBindingTable[0].
                         pvAplApsmeBindingTableEntryForSpSrcAddr[j].uDstAddress.u64Addr,

                         psAplAib->psAplApsmeAibBindingTable->psAplApsmeBindingTable[0].
                         pvAplApsmeBindingTableEntryForSpSrcAddr[j].u8DestinationEndPoint);

            DBG_vPrintf(TRACE_EZMODE, "\r\n UnBind Status %d",  eStatus);
        }
    }
    /* Remove Grouping Entries */
    #ifdef EZ_ENABLE_GROUP
        #if (defined CLD_GROUPS && defined GROUPS_CLIENT)
        {
            tsZCL_Address sAddress;
            teZCL_Status eStatus;
            tsCLD_Groups_RemoveGroupRequestPayload sPayload;
            uint8           u8TransactionSequenceNumber;

            sAddress.eAddressMode = E_ZCL_AM_GROUP;
            sAddress.uAddress.u16GroupAddress = sEZModeData.u16GroupID;

            sPayload.u16GroupId=sEZModeData.u16GroupID;

            /* remove remote groups */
            eStatus = eCLD_GroupsCommandRemoveGroupRequestSend(
                                    u8SourceEndpoint,
                                    0xff,/* don't care group addr */
                                    &sAddress,
                                    &u8TransactionSequenceNumber,
                                    &sPayload);
            DBG_vPrintf(TRACE_EZMODE, "\r\n eCLD_GroupsCommandRemoveGroupRequestSend Status %d",  eStatus);
        }
        #endif
        /* remove local groups */
        ZPS_eAplZdoGroupAllEndpointRemove(u8SourceEndpoint);
    #endif
}

#ifdef EZ_MODE_INITIATOR
/****************************************************************************
 **
 ** NAME:       vEZ_EZModeNWKFindAndBindHandler
 **
 ** DESCRIPTION:
 ** This function is used to to handle Stack and timer evens for Find and Bind
 **
 ** PARAMETERS:                 Name               Usage
 ** ZPS_tsAfEvent*            pZPSevent        Pointer to stack event
 **
 **
 ** RETURN:
 ** None
 **
 ****************************************************************************/
PUBLIC void vEZ_EZModeNWKFindAndBindHandler(ZPS_tsAfEvent *pZPSevent)
{
    vEZ_HandleZDPResponse(pZPSevent);

    if(OS_E_SWTIMER_EXPIRED == OS_eGetSWTimerStatus(App_EZFindAndBindTimer))
    {
        if(OS_eGetSWTimerStatus(App_EZFindAndBindTimer) != OS_E_SWTIMER_STOPPED)
        {
            OS_eStopSWTimer(App_EZFindAndBindTimer);
        }

        vEZ_TimerClickCallback();
    }
}

/****************************************************************************
 **
 ** NAME:       vEZ_EPCallBackHandler
 **
 ** DESCRIPTION:
 ** This function is used to to handle identify query response and other aZDP
 ** responses during EZ find and bind
 **
 ** PARAMETERS:                 Name               Usage
 ** tsZCL_CallBackEvent            pCallBackEvent        ZCL call back structure
 **
 **
 ** RETURN:
 ** None
 **
 ****************************************************************************/
PUBLIC void vEZ_EPCallBackHandler(tsZCL_CallBackEvent *pCallBackEvent)
{
    uint8 i;
    uint64 u64IeeeAddr  = 0;

    DBG_vPrintf(TRACE_EZMODE, "vEZ_EPCallBackHandler event %0x\r\n", pCallBackEvent->eEventType);

    if  ( (pCallBackEvent->eEventType == E_ZCL_CBET_CLUSTER_CUSTOM) &&
          (pCallBackEvent->uMessage.sClusterCustomMessage.u16ClusterId == GENERAL_CLUSTER_ID_IDENTIFY))
    {

        if(        (E_EZ_FIND_AND_BIND_INITIATOR_IN_PROGRESS     ==    sEZModeData.sEZInfo[pCallBackEvent->u8EndPoint - 1].eEZFindAndBindState ) ||
                (E_EZ_GROUPING_IN_PROGRESS_STATE              ==    sEZModeData.sEZInfo[pCallBackEvent->u8EndPoint - 1].eEZFindAndBindState )        )
        {
            tsCLD_IdentifyCallBackMessage *psCallBackMessage;
            psCallBackMessage =    (tsCLD_IdentifyCallBackMessage*)pCallBackEvent->uMessage.sClusterCustomMessage.pvCustomData;

            if(E_CLD_IDENTIFY_CMD_IDENTIFY_QUERY_RESPONSE == psCallBackMessage->u8CommandId)
            {
                /*Save the discovery result */
                for(i=0;i < EZ_MAX_TARGET_DEVICES; i++)
                {
                    if(0==sEZModeData.sEZInfo[pCallBackEvent->u8EndPoint - 1].aAddressDetails[i].u8DstEndpoint)
                    {
                        sEZModeData.sEZInfo[pCallBackEvent->u8EndPoint - 1].aAddressDetails[i].u8DstEndpoint=
                                                        pCallBackEvent->pZPSevent->uEvent.sApsDataIndEvent.u8SrcEndpoint;

                        sEZModeData.sEZInfo[pCallBackEvent->u8EndPoint - 1].aAddressDetails[i].u16NwkAddr =
                                                        pCallBackEvent->pZPSevent->uEvent.sApsDataIndEvent.uSrcAddress.u16Addr;
                        break;
                    }
                }

                /* check if IEEE address of device is available */
                u64IeeeAddr  = ZPS_u64AplZdoLookupIeeeAddr(pCallBackEvent->pZPSevent->uEvent.sApsDataIndEvent.uSrcAddress.u16Addr);

                if(!u64IeeeAddr )
                {
                    vEZ_IEEEAddressReqSend(pCallBackEvent->pZPSevent->uEvent.sApsDataIndEvent.uSrcAddress,
                                                    pCallBackEvent->pZPSevent->uEvent.sApsDataIndEvent.uSrcAddress.u16Addr);
                }
                else
                {
                    /* IEEE address of target known, issue simple descriptor request */
                    vEZ_SimpleDescriptorSend(pCallBackEvent->pZPSevent->uEvent.sApsDataIndEvent.u8SrcEndpoint,
                                                    pCallBackEvent->pZPSevent->uEvent.sApsDataIndEvent.uSrcAddress.u16Addr);
                }
            }
        }
    }
}
#endif

#ifdef EZ_ENABLE_GROUP
/****************************************************************************
 *
 * NAME: eEZ_Group
 *
 * DESCRIPTION:
 * should be called for performing grouping with target.
 *
 * PARAMETERS:  Name                            Usage
 *                u8SourceEndpoint                the source endpoint
 *                eEZ_Mode                         the grouping mode.Possible values are
 *                                                E_EZ_INITIATOR and E_EZ_TARGET.
 * RETURNS:
 * None
 *
 ****************************************************************************/


PUBLIC teEZ_Status eEZ_Group (uint8 u8SourceEndpoint, teEZ_Mode eEZ_Mode)
{
    teEZ_Status eStatus;
    DBG_vPrintf(TRACE_EZMODE, "eEZ_Group start  \n");
    eStatus = eEZ_HandleFindAndBind(     u8SourceEndpoint,
                                        eEZ_Mode,
                                        E_EZ_GROUPING_IN_PROGRESS_STATE );

    return eStatus;
}
#endif
/****************************************************************************
 *
 * NAME: eEZ_GetFindAndBindState
 *
 * DESCRIPTION:
 * should be called invoked for current status of EZ commissioning
 *
 * PARAMETERS:  Name                            Usage
 *                u8SourceEndpoint                the source endpoint
 *
 * RETURNS:
 * teEZ_State
 *
 ****************************************************************************/
PUBLIC teEZ_FindAndBindState eEZ_GetFindAndBindState(uint8 u8SourceEndpoint)
{
    return sEZModeData.sEZInfo[u8SourceEndpoint - 1].eEZFindAndBindState;
}
/****************************************************************************
 *
 * NAME: vEZ_Exit
 *
 * DESCRIPTION:
 * should be called invoked to come out of EZ mode commissioning
 *
 * PARAMETERS:  Name                            Usage
 *                u8SourceEndpoint                the source endpoint
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vEZ_Exit(uint8 u8SourceEndpoint)
{
    uint16 u16IdentifyTime = 0;
    DBG_vPrintf(TRACE_EZMODE, "vEZ_Exit  \n");

    eZCL_WriteLocalAttributeValue(
                        u8SourceEndpoint,
                        GENERAL_CLUSTER_ID_IDENTIFY,
                        TRUE,
                        FALSE,
                        FALSE,
                        E_CLD_IDENTIFY_ATTR_ID_IDENTIFY_TIME,
                        &u16IdentifyTime);

    /* clear state variables */
    memset(&sEZModeData.sEZInfo[u8SourceEndpoint - 1],0,sizeof(sEZModeData.sEZInfo));
    #ifdef EZ_MODE_INITIATOR
        if(OS_eGetSWTimerStatus(App_EZFindAndBindTimer) != OS_E_SWTIMER_STOPPED)
        {
            OS_eStopSWTimer(App_EZFindAndBindTimer);
        }
    #endif
}

/****************************************************************************
 *
 * NAME: eEZ_ExcludeCluster
 *
 * DESCRIPTION:
 * should be called from application to set Set up policy
 *
 * PARAMETERS:  Name                            Usage
 *                u16ClusterID               ClusterID to be excluded from binding
 *
 * RETURNS:
 *
 *
 ****************************************************************************/
PUBLIC teEZ_ClusterExcludeStatus eEZ_ExcludeClusterFromEZBinding(uint16 u16ClusterID,bool_t bServer)
{
    teEZ_ClusterExcludeStatus eStatus = E_EZ_EXCLUSION_TABLE_FULL;

    DBG_vPrintf(TRACE_EZMODE, "eEZ_ExcludeClusterFromEZBinding\r\n");
    if(bEZ_IsClusterExcludedFromBinding(u16ClusterID,bServer))
    {
        eStatus  = E_EZ_CLUSTER_EXCLUSION_SUCCESS;
        DBG_vPrintf(TRACE_EZMODE, "already excluded \r\n");
    }
    else if(EZ_MAX_CLUSTER_EXCLUSION_SIZE > sEZModeData.u8ExclusionClusterCount)
    {
        sEZModeData.sClusterExclusionList[sEZModeData.u8ExclusionClusterCount].u16ClusterId = u16ClusterID;
        sEZModeData.sClusterExclusionList[sEZModeData.u8ExclusionClusterCount].bServer      = bServer;
        sEZModeData.u8ExclusionClusterCount++;
        eStatus = E_EZ_CLUSTER_EXCLUSION_SUCCESS;
        DBG_vPrintf(TRACE_EZMODE, "added successfully  \r\n");

    }
    else
    {
        DBG_vPrintf(TRACE_EZMODE, "E_EZ_EXCLUSION_TABLE_FULL  \r\n");
    }
    return eStatus;
}

/****************************************************************************
 *
 * NAME: vEZ_SetGroupId
 *
 * DESCRIPTION:
 * Sets the GroupId before commissioning.
 *
 * RETURNS:
 * void
 *
 *
 ****************************************************************************/
PUBLIC void vEZ_SetGroupId(uint16 u16GroupID)
{
    sEZModeData.u16GroupID = u16GroupID;
}

/****************************************************************************
 *
 * NAME: u16EZ_GetGroupId
 *
 * DESCRIPTION:
 * Gets the GroupId from commissioning.
 *
 * RETURNS:
 * 16 bit Group Id
 *
 *
 ****************************************************************************/
PUBLIC uint16 u16EZ_GetGroupId(void)
{
    return sEZModeData.u16GroupID;
}

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/
/****************************************************************************
 *
 * NAME: bEZ_IsClusterExcludedFromBinding
 *
 * DESCRIPTION:
 * Tests if a cluster is in exclusion list
 *
 * PARAMETERS:  Name                            Usage
 *                u16ClusterID               ClusterID to be excluded from binding
 *              bServer                    Server or client
 *
 * RETURNS:
 * True or False
 ****************************************************************************/
PRIVATE bool_t bEZ_IsClusterExcludedFromBinding(uint16 u16ClusterID,bool_t bServer)
{
    int i;

    for(i=0; i< sEZModeData.u8ExclusionClusterCount; i++)
    {
        if( (u16ClusterID == sEZModeData.sClusterExclusionList[i].u16ClusterId) &&
            (bServer == sEZModeData.sClusterExclusionList[i].bServer))
        {
            return TRUE;
        }
    }
    return FALSE;
}

/****************************************************************************
 *
 * NAME: eEZ_HandleFindAndBind
 *
 * DESCRIPTION:
 * should be called for performing service discovery and binding of clusters
 * registered while endpoint registration on an initiator and for putting the
 * device in identify mode for EZ_MODE_TIME on an initiator.
 *
 * PARAMETERS:  Name                            Usage
 *                u8SourceEndpoint                the source endpoint
 *                eEZ_Mode                         the EZ find and bind mode.Possible values are
 *                                                E_EZ_INITIATOR and E_EZ_TARGET.
 *                  u8State                            Grouping state or Find and bind state
 * RETURNS:
 * None
 *
 ****************************************************************************/
PRIVATE teEZ_Status eEZ_HandleFindAndBind(uint8 u8SourceEndPointId, teEZ_Mode eEZ_Mode, uint8 u8State )
{
    DBG_vPrintf(TRACE_EZMODE, "eEZ_HandleFindAndBind state = %d \n",sEZModeData.sEZInfo[u8SourceEndPointId - 1].eEZFindAndBindState);

    if( u8SourceEndPointId > EZ_NUMBER_OF_ENDPOINTS )
    {
        DBG_vPrintf(TRACE_EZMODE, "eEZ_HandleFindAndBind E_ZCL_ERR_EP_RANGE \n");
        return E_EZ_ERROR;
    }

    /* initiate find and bind in idle(initial) state only */
    if(E_EZ_FIND_AND_BIND_INITIAL_STATE == sEZModeData.sEZInfo[u8SourceEndPointId - 1].eEZFindAndBindState)
    {

        #ifdef EZ_MODE_INITIATOR
            if(E_EZ_INITIATOR == eEZ_Mode)
                return eStartEZInitiator(u8SourceEndPointId,u8State);
        #endif

        #ifdef EZ_MODE_TARGET
            /* handle Find and Bind in target mode */
            if(E_EZ_TARGET == eEZ_Mode)
                return eStartEZTarget(u8SourceEndPointId);
        #endif
    }
    else
    {
        return E_EZ_BUSY;
    }
    return E_EZ_ERROR;
}
#ifdef EZ_MODE_TARGET
/****************************************************************************
 **
 ** NAME:       eStartEZTarget
 **
 ** DESCRIPTION:
 ** Function to check if there is a client to server match with received simple
 ** descriptor and to source bind if there is a match.
 **
 ** PARAMETERS:             Name                   Usage
 ** uint8                    u8SourceEndPointId  EZ source EP Id
 **
 ** RETURN:
 ** None
 **
 ****************************************************************************/
PRIVATE teEZ_Status eStartEZTarget(uint8 u8SourceEndPointId)
{
    uint16 u16EZTime=EZ_MODE_TIME * 60;

    /* put in identify mode */
    ZPS_teStatus eZCLStatus =  eZCL_WriteLocalAttributeValue(
                u8SourceEndPointId,
                GENERAL_CLUSTER_ID_IDENTIFY,
                TRUE,
                FALSE,
                FALSE,
                E_CLD_IDENTIFY_ATTR_ID_IDENTIFY_TIME,
                &u16EZTime);
    if(eZCLStatus)
    {
        DBG_vPrintf(TRACE_EZMODE, "eEZ_HandleFindAndBind eZCL_WriteLocalAttributeValue %d \n",eZCLStatus);
        return E_EZ_ERROR;
    }

    #ifdef CLD_GROUPS
        eCLD_GroupsSetIdentifying(u8SourceEndPointId, TRUE);
    #endif

    vEnablePermitJoin(u16EZTime);
    return E_EZ_FIND_AND_BIND_TARGET_IN_PROGRESS;
}
#endif

#ifdef EZ_MODE_INITIATOR
/****************************************************************************
 **
 ** NAME:       vEZ_TimerClickCallback
 **
 ** DESCRIPTION:
 ** Timer Callback
 **
 ** PARAMETERS:                 Name               Usage
 **
 ** RETURN:
 ** None
 **
 ****************************************************************************/
PRIVATE void vEZ_TimerClickCallback(void)
{
    int i;
    uint16 u16TotalRemainingTime=0;
    tsEZ_FindAndBindEvent sEvent ={0};

    for(i = 0; i < EZ_NUMBER_OF_ENDPOINTS; i++)
    {
        if(E_EZ_FIND_AND_BIND_INITIAL_STATE != sEZModeData.sEZInfo[i].eEZFindAndBindState)
        {
            if(sEZModeData.sEZInfo[i].u16EZTime >0)
            {
                u16TotalRemainingTime+=sEZModeData.sEZInfo[i].u16EZTime;
                sEZModeData.sEZInfo[i].u16EZTime--;
            }
            else
            {
                vEZ_Exit(sEZModeData.sEZInfo[i].u8Endpoint);
                sEvent.eEventType=E_EZ_TIMEOUT;
                sEvent.u8InitiatorEp=sEZModeData.sEZInfo[i].u8Endpoint;
                vEZ_EZModeCb(&sEvent);
            }

            if( sEZModeData.sEZInfo[i].u8EZResponseWaitTime>0)
            {
                u16TotalRemainingTime+=sEZModeData.sEZInfo[i].u8EZResponseWaitTime;
                sEZModeData.sEZInfo[i].u8EZResponseWaitTime--;
            }
            else
            {
                eReStartEZInitiator(sEZModeData.sEZInfo[i].u8Endpoint);
            }
        }
    }

    if(u16TotalRemainingTime)
        OS_eStartSWTimer(App_EZFindAndBindTimer,APP_TIME_MS(1000),NULL);

    DBG_vPrintf(TRACE_EZMODE,"TimerClick = %d\n",u16TotalRemainingTime);
}

/****************************************************************************
 **
 ** NAME:       eStartEZInitiator
 **
 ** DESCRIPTION:
 ** Function to check if there is a client to server match with received simple
 ** descriptor and to source bind if there is a match.
 **
 ** PARAMETERS:             Name                   Usage
 ** uint8                    u8SourceEndPointId  EZ source EP Id
 **
 ** RETURN:
 ** None
 **
 ****************************************************************************/
PRIVATE teEZ_Status eStartEZInitiator(uint8 u8SourceEndPointId,uint8 u8State)
{

    teEZ_Status eStatus;

    /* clear state variables */
    memset(&sEZModeData.sEZInfo[u8SourceEndPointId - 1],0,sizeof(sEZModeData.sEZInfo));

    eStatus = eReStartEZInitiator(u8SourceEndPointId);
    if(E_EZ_ERROR == eStatus )
    {
        DBG_vPrintf(TRACE_EZMODE, "eEZ_HandleFindAndBind eCLD_IdentifyCommandIdentifyQueryRequestSend %d \n",eStatus);
        return eStatus;
    }

    /* change the state to in - progress */
    sEZModeData.sEZInfo[u8SourceEndPointId - 1].eEZFindAndBindState =    u8State;
    sEZModeData.sEZInfo[u8SourceEndPointId - 1].u8Endpoint = u8SourceEndPointId;
    /* EZ mode time backed up. Will be decremented on each ZCL tick */
    sEZModeData.sEZInfo[u8SourceEndPointId - 1].u16EZTime = EZ_MODE_TIME * 60;


    if(eStatus == E_EZ_FIND_AND_BIND_IN_PROGRESS || eStatus == E_EZ_GROUPING_IN_PROGRESS)
    {
        if(OS_E_SWTIMER_STOPPED != OS_eGetSWTimerStatus(App_EZFindAndBindTimer))
            OS_eStopSWTimer(App_EZFindAndBindTimer);

        OS_eStartSWTimer(App_EZFindAndBindTimer,APP_TIME_MS(500),NULL);
    }
    return E_EZ_FIND_AND_BIND_IN_PROGRESS;
}
/****************************************************************************
 **
 ** NAME:       eReStartEZInitiator
 **
 ** DESCRIPTION:
 ** Restart The discovery
 **
 ** PARAMETERS:             Name                   Usage
 ** uint8                    u8SourceEndPointId  EZ source EP Id
 **
 ** RETURN:
 ** None
 **
 ****************************************************************************/
PRIVATE teEZ_Status eReStartEZInitiator(uint8 u8SourceEndPointId)
{
    teZCL_Status eZCLStatus;
    eZCLStatus = eDiscover(u8SourceEndPointId);
    if(eZCLStatus)
    {
        DBG_vPrintf(TRACE_EZMODE, "eEZ_HandleFindAndBind eCLD_IdentifyCommandIdentifyQueryRequestSend %d \n",eZCLStatus);
        return E_EZ_ERROR;
    }

    sEZModeData.sEZInfo[u8SourceEndPointId-1].u8EZResponseWaitTime= EZ_RESPONSE_TIME;
    return E_EZ_FIND_AND_BIND_IN_PROGRESS;
}
/****************************************************************************
 **
 ** NAME:       eDiscover
 **
 ** DESCRIPTION:
 ** Starts a discovery
 **
 ** PARAMETERS:             Name                   Usage
 ** uint8                    u8SourceEndPointId  EZ source EP Id
 **
 ** RETURN:
 ** None
 **
 ****************************************************************************/
PRIVATE teZCL_Status eDiscover(uint8 u8SourceEndPointId)
{
    uint8                 u8TransactionSeqNo;
    tsZCL_Address         sAddress;
    teZCL_Status         eZCLStatus;
    /* Broadcast Identify query request */
    sAddress.eAddressMode                 = E_ZCL_AM_BROADCAST;
    sAddress.uAddress.eBroadcastMode     = ZPS_E_APL_AF_BROADCAST_ALL;

    eZCLStatus = eCLD_IdentifyCommandIdentifyQueryRequestSend(
                    u8SourceEndPointId,
                    0xFF,
                    &sAddress,
                    &u8TransactionSeqNo);
    return eZCLStatus;
}
/****************************************************************************
 **
 ** NAME:       vBindAndCallBack
 **
 ** DESCRIPTION:
 ** Starts a discovery
 **
 ** PARAMETERS:             Name                   Usage
 ** uint8                    u8SourceEndPointId  EZ source EP Id
 **
 ** RETURN:
 ** None
 **
 ****************************************************************************/
PRIVATE void vBindAndCallBack(uint16 u16ClusterID,tsEZ_Info *psEZInfo,
                                ZPS_tsAfZdpEvent *psAfZdpEvent,
                                uint64 * pu64DstIeeeAddr,
                                bool_t bAddAddressMapEntry)
{
    /* Match found, Bind */
    ZPS_teStatus eStatus = ZPS_eAplZdoBind(    u16ClusterID,
                                psEZInfo->u8Endpoint,
                                psAfZdpEvent->uZdpData.sSimpleDescRsp.u16NwkAddrOfInterest, 
                                *pu64DstIeeeAddr,
                                psAfZdpEvent->uZdpData.sSimpleDescRsp.sSimpleDescriptor.u8Endpoint);

    if(ZPS_E_SUCCESS == eStatus)
    {
        tsEZ_FindAndBindEvent sEvent;

        if(bAddAddressMapEntry)
        {
            ZPS_eAplZdoAddAddrMapEntry(    psAfZdpEvent->uZdpData.sSimpleDescRsp.u16NwkAddrOfInterest,
                                        *pu64DstIeeeAddr, FALSE);
        }
        sEvent.eEventType=E_EZ_BIND_CREATED_FOR_TARGET;
        sEvent.u8InitiatorEp=psEZInfo->u8Endpoint;
        sEvent.u8TargetEp=psAfZdpEvent->uZdpData.sSimpleDescRsp.sSimpleDescriptor.u8Endpoint;
        sEvent.u16TargetAddress = psAfZdpEvent->uZdpData.sSimpleDescRsp.u16NwkAddrOfInterest;
        sEvent.uEvent.u16ClusterId=u16ClusterID;
        vEZ_EZModeCb(&sEvent);
    }
}
/****************************************************************************
 **
 ** NAME:       vBindCluster
 **
 ** DESCRIPTION:
 ** Binds the Source's clusters' clients to the remote server.
 **
 ** PARAMETERS:             Name                   Usage
 ** tsEZ_Info *                psEZInfo            EZ source
 ** ZPS_tsAfEvent*            pZPSevent            Stack Event
 ** RETURN:
 ** None
 **
 ****************************************************************************/
PRIVATE void vBindCluster(tsEZ_Info *psEZInfo, ZPS_tsAfZdpEvent *psAfZdpEvent,
                           uint64 * pu64DstIeeeAddr,bool_t bAddAddressMapEntry,bool_t bServer)
{
    int i=0;
    int j=0;
    uint8 u8InitiatorCluster;
    uint8 u8TargetCluster;
    uint8 jj=0;


    uint16 * pCluster;
    ZPS_tsAplAfSimpleDescriptor sDescSelf;
    ZPS_tsAplZdpSimpleDescType *psSimpleDescRemote;

#ifdef EZ_CHECK_FOR_BINDING_GROUPING
    tsEZ_FindAndBindEvent sEvent={0};
#endif

    /* get simple descriptor of local node */
    ZPS_eAplAfGetSimpleDescriptor(psEZInfo->u8Endpoint, &sDescSelf);
    psSimpleDescRemote = &psAfZdpEvent->uZdpData.sSimpleDescRsp.sSimpleDescriptor;
    /*Set up the binding loop counts and initialiser for server or client */
    if(!bServer)
    {
        u8InitiatorCluster=sDescSelf.u8OutClusterCount;
        u8TargetCluster = psSimpleDescRemote->u8InClusterCount;
        jj=0;
        pCluster = (uint16*)sDescSelf.pu16OutClusterList;
    }
    else
    {
        u8InitiatorCluster=sDescSelf.u8InClusterCount;
        u8TargetCluster = psSimpleDescRemote->u8InClusterCount+psSimpleDescRemote->u8OutClusterCount;
        jj=psSimpleDescRemote->u8InClusterCount;
        pCluster = (uint16*)sDescSelf.pu16InClusterList;
    }

    /* Check for Initiator Client With Target Server cluster match */
    for(i=0; i<u8InitiatorCluster;i++ )
    {
        for(j=jj;j < u8TargetCluster ; j++)
        {
            uint16 u16ClusterID;
            /* In cluster First in the list then Out clusters in the received pay load */
            u16ClusterID = psAfZdpEvent->uLists.au16Data[j];
            if(    (u16ClusterID ==  pCluster[i]) &&
                (FALSE == bEZ_IsClusterExcludedFromBinding(u16ClusterID,bServer) ))
            {
                if(E_EZ_FIND_AND_BIND_INITIATOR_IN_PROGRESS ==    psEZInfo->eEZFindAndBindState )
                {
                    #ifdef EZ_CHECK_FOR_BINDING_GROUPING
                        sEvent.eEventType=E_EZ_CHECK_FOR_BIND_FOR_TARGET;
                        sEvent.u8InitiatorEp=psEZInfo->u8Endpoint;
                        sEvent.u8TargetEp=psSimpleDescRemote->u8Endpoint;
                        sEvent.uEvent.u16ClusterId=u16ClusterID;
                        sEvent.u16TargetAddress = psAfZdpEvent->uZdpData.sSimpleDescRsp.u16NwkAddrOfInterest;
                        sEvent.bAllowBindOrGroup = TRUE;
                        sEvent.psAfZdpEvent = psAfZdpEvent;
                        vEZ_EZModeCb(&sEvent);
                        if(sEvent.bAllowBindOrGroup)
                            vBindAndCallBack(u16ClusterID,psEZInfo,psAfZdpEvent,pu64DstIeeeAddr,bAddAddressMapEntry);
                    #else
                        vBindAndCallBack(u16ClusterID,psEZInfo,psAfZdpEvent,pu64DstIeeeAddr,bAddAddressMapEntry);
                    #endif

                    break;
                }
                #ifdef EZ_ENABLE_GROUP
                else if(E_EZ_GROUPING_IN_PROGRESS_STATE == psEZInfo->eEZFindAndBindState)
                {
                    #ifdef EZ_CHECK_FOR_BINDING_GROUPING
                        sEvent.eEventType=E_EZ_CHECK_FOR_GROUP_FOR_TARGET;
                        sEvent.u8InitiatorEp=psEZInfo->u8Endpoint;
                        sEvent.u8TargetEp=psSimpleDescRemote->u8Endpoint;
                        sEvent.uEvent.u16ClusterId=u16ClusterID;
                        sEvent.u16TargetAddress = psAfZdpEvent->uZdpData.sSimpleDescRsp.u16NwkAddrOfInterest;
                        sEvent.bAllowBindOrGroup = TRUE;
                        sEvent.psAfZdpEvent = psAfZdpEvent;
                        vEZ_EZModeCb(&sEvent);
                        if(sEvent.bAllowBindOrGroup)
                        {
                            vEZ_AddToGroupWhenIdentifying(psEZInfo->u8Endpoint,psSimpleDescRemote->u8Endpoint,
                                    psAfZdpEvent->uZdpData.sSimpleDescRsp.u16NwkAddrOfInterest,sEvent.bGroupCast );
                        }
                    #else
                        vEZ_AddToGroupWhenIdentifying(psEZInfo->u8Endpoint,psSimpleDescRemote->u8Endpoint,
                                psAfZdpEvent->uZdpData.sSimpleDescRsp.u16NwkAddrOfInterest);
                    #endif
                        return;
                }
                #endif
            }
        }
    }
}
/****************************************************************************
 **
 ** NAME:       vEZ_HandleSimpleDescriptorResponse
 **
 ** DESCRIPTION:
 ** Function to check if there is a client to server match with received simple
 ** descriptor and to source bind if there is a match.
 **
 ** PARAMETERS:                 Name               Usage
 ** tsEZ_Info                    *psEZInfo        backed up EZ details entry
 ** ZPS_tsAfEvent               pZPSevent        ZPS response received
 **
 ** RETURN:
 ** None
 **
 ****************************************************************************/
PRIVATE void vEZ_HandleSimpleDescriptorResponse(tsEZ_Info *psEZInfo, ZPS_tsAfZdpEvent *psAfZdpEvent)
{

	int i=0;
    uint64 u64DstIeeeAddr = 0;
    bool_t bAddAddressMapEntry=FALSE;

    DBG_vPrintf(TRACE_EZMODE, "vEZ_HandleSimpleDescriptorResponse started \r\n");

    /* Retreive IEEE from stack/ or from backed up data*/
    u64DstIeeeAddr = ZPS_u64AplZdoLookupIeeeAddr(psAfZdpEvent->uZdpData.sSimpleDescRsp.u16NwkAddrOfInterest);

    /* Retreive IEEE from stack/ or from backed up data*/
    bAddAddressMapEntry = TRUE;

    /* IEEE address is not present with ZStack, get it from backed up data */
	if(u64DstIeeeAddr == 0)
	{
		for(i = 0; i < EZ_MAX_TARGET_DEVICES; i++ )
		{
			if(psEZInfo->aAddressDetails[i].u16NwkAddr == psAfZdpEvent->uZdpData.sSimpleDescRsp.u16NwkAddrOfInterest)
			{
				u64DstIeeeAddr = psEZInfo->aAddressDetails[i].u64IeeeAddr ;
				bAddAddressMapEntry = TRUE;
				break;
			}
		}
	}

    DBG_vPrintf(TRACE_EZMODE, "vEZ_HandleSimpleDescriptorResponse IEEE address = %016llx \r\n",u64DstIeeeAddr);

    if(ZPS_NWK_ENUM_SUCCESS == psAfZdpEvent->uZdpData.sSimpleDescRsp.u8Status)
    {

        vBindCluster(psEZInfo,psAfZdpEvent,&u64DstIeeeAddr,bAddAddressMapEntry,FALSE);
        vBindCluster(psEZInfo,psAfZdpEvent,&u64DstIeeeAddr,bAddAddressMapEntry,TRUE);
    }
}
/****************************************************************************
 **
 ** NAME:       vEZ_IEEEAddressReqSend
 **
 ** DESCRIPTION:
 ** This function is used to send a ZDP simple descriptor request
 **
 ** PARAMETERS:                 Name               Usage
 ** uint8                    u8DstEndpoint        Destination end point to which request to be sent
 ** uint16                   u16DstAddr            Destination source address to which request to be sent
 **
 ** RETURN:
 ** None
 **
 ****************************************************************************/
PRIVATE void vEZ_IEEEAddressReqSend( ZPS_tuAddress uSrcAddress, uint16 u16DstAddr)
{
    uint8 u8TransactionSequenceNumber;
    ZPS_tsAplZdpIeeeAddrReq sZdpIeeeAddrReq;
    PDUM_thAPduInstance hAPduInst;

    /* IEEE address of target unknown, issue IEEE address request */
    sZdpIeeeAddrReq.u16NwkAddrOfInterest    = u16DstAddr;
    sZdpIeeeAddrReq.u8RequestType            = 0;
    sZdpIeeeAddrReq.u8StartIndex            = 0;

    hAPduInst = PDUM_hAPduAllocateAPduInstance(apduZDP);

    if (hAPduInst == PDUM_INVALID_HANDLE)
    {
        DBG_vPrintf(TRACE_EZMODE, "IEEE Address Request - PDUM_INVALID_HANDLE\n");
    }
    else
    {

        ZPS_teStatus eStatus = ZPS_eAplZdpIeeeAddrRequest(hAPduInst,
                                                      uSrcAddress,
                                                      FALSE,
                                                      &u8TransactionSequenceNumber,
                                                      &sZdpIeeeAddrReq);
        DBG_vPrintf(TRACE_EZMODE, "ZPS_eAplZdpIeeeAddrRequest status %0x\r\n", eStatus);
    }
}
/****************************************************************************
 **
 ** NAME:       vEZ_SimpleDescriptorSend
 **
 ** DESCRIPTION:
 ** This function is used to send a ZDP simple descriptor request
 **
 ** PARAMETERS:                 Name               Usage
 ** uint8                    u8DstEndpoint        Destination end point to which request to be sent
 ** uint16                   u16DstAddr            Destination source address to which request to be sent
 **
 ** RETURN:
 ** None
 **
 ****************************************************************************/

PRIVATE void vEZ_SimpleDescriptorSend(uint8 u8DstEndpoint, uint16 u16DstAddr)
{
    uint8 u8TransactionSequenceNumber;
    PDUM_thAPduInstance hAPduInst;
    ZPS_tsAplZdpSimpleDescReq sZdpSimpleDescReq;
    ZPS_tuAddress uDstAddr;
    uDstAddr.u16Addr = u16DstAddr;


    sZdpSimpleDescReq.u16NwkAddrOfInterest = u16DstAddr;
    sZdpSimpleDescReq.u8EndPoint = u8DstEndpoint;

    hAPduInst = PDUM_hAPduAllocateAPduInstance(apduZDP);

    if (hAPduInst == PDUM_INVALID_HANDLE)
    {
        DBG_vPrintf(TRACE_EZMODE, "Simple Desc Request - PDUM_INVALID_HANDLE\n");
    }
    else
    {
        ZPS_teStatus eStatus = ZPS_eAplZdpSimpleDescRequest(
             hAPduInst,
             uDstAddr,
             FALSE,
             &u8TransactionSequenceNumber,
             &sZdpSimpleDescReq);
        DBG_vPrintf(TRACE_EZMODE, "ZPS_eAplZdpSimpleDescRequest status %0x\r\n", eStatus);
    }
}

/****************************************************************************
 *
 * NAME: vEZ_HandleZDPResponse
 *
 * DESCRIPTION:
 * This function handles ZDP responses while EZ commissioning
 *
 * PARAMETERS:  Name                            Usage
 *                pZPSevent                        Stack events
 *
 * RETURNS:
 * None
 *
 ****************************************************************************/
PRIVATE void vEZ_HandleZDPResponse(ZPS_tsAfEvent *pZPSevent)
{
    int i;
    int j;
    ZPS_tsAfZdpEvent sAfZdpEvent;

    if((ZPS_EVENT_APS_DATA_INDICATION == pZPSevent->eType) &&
            (0 == pZPSevent->uEvent.sApsDataIndEvent.u8DstEndpoint))
    {
        zps_bAplZdpUnpackResponse(pZPSevent, &sAfZdpEvent);    
        for(i=0;i < EZ_NUMBER_OF_ENDPOINTS; i++)
        {
            for(j=0; j < EZ_MAX_TARGET_DEVICES;j++)
            {

                if(ZPS_ZDP_IEEE_ADDR_RSP_CLUSTER_ID == sAfZdpEvent.u16ClusterId)
                {
                    DBG_vPrintf(TRACE_EZMODE, "ZDP_IEEE_ADDR_RSP_CLUSTER_ID \r\n");
                    /* Back up iEEE address */
                    if(sAfZdpEvent.uZdpData.sIeeeAddrRsp.u16NwkAddrRemoteDev ==    sEZModeData.sEZInfo[i].aAddressDetails[j].u16NwkAddr )
                    {
                        sEZModeData.sEZInfo[i].aAddressDetails[j].u64IeeeAddr = sAfZdpEvent.uZdpData.sIeeeAddrRsp.u64IeeeAddrRemoteDev;

                        vEZ_SimpleDescriptorSend(sEZModeData.sEZInfo[i].aAddressDetails[j].u8DstEndpoint,sEZModeData.sEZInfo[i].aAddressDetails[j].u16NwkAddr );
                        return;
                    }
                }

                else if(ZPS_ZDP_SIMPLE_DESC_RSP_CLUSTER_ID == sAfZdpEvent.u16ClusterId)
                {
                    DBG_vPrintf(TRACE_EZMODE, "ZDP_SIMPLE_DESC_RSP_CLUSTER_ID \r\n");
                    if(sAfZdpEvent.uZdpData.sSimpleDescRsp.u16NwkAddrOfInterest == sEZModeData.sEZInfo[i].aAddressDetails[j].u16NwkAddr )
                    {
                        /* Handle simple descriptor response: check for match and bind */
                        vEZ_HandleSimpleDescriptorResponse(    &sEZModeData.sEZInfo[i],&sAfZdpEvent);
                        return;
                    }
                }
            }
        }
    }
}

/****************************************************************************
 *
 * NAME: vEZ_AddToGroupWhenIdentifying
 *
 * DESCRIPTION:
 * This function sends a add group if identify command
 *
 * PARAMETERS:  Name                            Usage
 *                u8SourceEndpoint              Stack events
 *                u16ShortAddress               network address to which add group if identify should be send
 *              bGroupCast                    If a group cast is required
 * RETURNS:
 * None
 *
 ****************************************************************************/

#ifdef EZ_ENABLE_GROUP
#ifdef EZ_CHECK_FOR_BINDING_GROUPING
    PRIVATE void vEZ_AddToGroupWhenIdentifying(uint8 u8SourceEndpoint, uint8 u8DstEndpoint,uint16 u16ShortAddress, bool_t bGroupCast )
#else
    PRIVATE void vEZ_AddToGroupWhenIdentifying(uint8 u8SourceEndpoint, uint8 u8DstEndpoint,uint16 u16ShortAddress )
#endif
{
    teZCL_Status eZCLStatus;
    uint8 u8Seq;
    tsZCL_Address sAddress;
    tsCLD_Groups_AddGroupRequestPayload sPayload;
    tsEZ_FindAndBindEvent sEvent={0};

    /* Broadcast Add group if identifying request */
    #ifdef EZ_CHECK_FOR_BINDING_GROUPING
        if(bGroupCast)
        {
            sAddress.eAddressMode                 = E_ZCL_AM_BROADCAST;
            sAddress.uAddress.eBroadcastMode     = ZPS_E_APL_AF_BROADCAST_RX_ON;
        }
        else
        {
            sAddress.eAddressMode                     = E_ZCL_AM_SHORT;
            sAddress.uAddress.u16DestinationAddress = u16ShortAddress;
        }
    #else
        sAddress.eAddressMode                     = E_ZCL_AM_SHORT;
        sAddress.uAddress.u16DestinationAddress = u16ShortAddress;
    #endif

    sPayload.sGroupName.pu8Data     = (uint8*)"";
    sPayload.sGroupName.u8Length     = 0;
    sPayload.sGroupName.u8MaxLength = 0;
    /*Set the NwkId as the group ID to make it unique - The nwk update addis not taken care here.*/
    sPayload.u16GroupId             = sEZModeData.u16GroupID;

    /* Sending the Add group to the device those are identifying*/
    eZCLStatus = eCLD_GroupsCommandAddGroupIfIdentifyingRequestSend(
                            u8SourceEndpoint,
                            u8DstEndpoint,
                            &sAddress,
                            &u8Seq,
                            &sPayload);

    sEZModeData.sEZInfo[u8SourceEndpoint].eEZFindAndBindState = E_EZ_GROUPING_IN_PROGRESS_STATE;
    DBG_vPrintf(TRACE_EZMODE, "eCLD_GroupsCommandAddGroupIfIdentifyingRequestSend status = %d, EP= %d\r\n",eZCLStatus,u8SourceEndpoint);
    sEZModeData.sEZInfo[u8SourceEndpoint - 1].u8EZResponseWaitTime= EZ_RESPONSE_TIME;

    sEvent.eEventType=E_EZ_GROUP_CREATED_FOR_TARGET;
    sEvent.u8InitiatorEp=u8SourceEndpoint;
    sEvent.u8TargetEp=u8DstEndpoint;
    sEvent.uEvent.u16GroupId=sEZModeData.u16GroupID;
    sEvent.u16TargetAddress = u16ShortAddress;
    vEZ_EZModeCb(&sEvent);
}
#endif
#endif
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/


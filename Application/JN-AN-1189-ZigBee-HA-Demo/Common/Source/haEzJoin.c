/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          haEzJoin.c
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
#include "haEzJoin.h"
#include "zps_apl_aib.h"
#include "dbg.h"
#include <string.h>
#include "pwrm.h"
#include "app_timer_driver.h"
#include "app_zbp_utilities.h"
#include "os_gen.h"
#include "appZpsBeaconHandler.h"
#include "rnd_pub.h"

#include "zcl.h"
#include <pdum_gen.h>

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#ifndef DEBUG_EZMODE
    #define TRACE_EZMODE FALSE
#else
    #define TRACE_EZMODE TRUE
#endif

#define LQI_CHANGE_UNIT 1
#define LQI_MIN_VALUE   29
#define LQI_MAX_VALUE   30

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
PRIVATE void vEZ_ClearStateVariables(void);

#ifdef SUPPORT_JOIN_ELSE_FORM
PRIVATE void vEZ_ModeFormOrJoinNwk( void );
PRIVATE void vFormingNetwork(ZPS_tsAfEvent *pZPSevent);
PRIVATE void vHandleFormedNwk(void);
PRIVATE void vHandleFailedToStart(void);
#endif

PRIVATE void vEZ_SortAndSaveNetworks(ZPS_tsAfNwkDiscoveryEvent *pNwkDes);
PRIVATE void vEZ_JoinSavedNetwork(void);
PRIVATE ZPS_tsNwkDiscNtEntry *sEZ_GetDiscEntry(uint64 *pExtendedPanId);
PRIVATE eChannelsSelected eEZ_SetChannel(void);
PRIVATE bool_t bBackOffTimerExpirred(void);

PRIVATE void vBackOff(bool_t bBackOffTimerExpirredFlag);
PRIVATE void vSetUpStart(void);
PRIVATE void vWaitDiscovery(ZPS_tsAfEvent *pZPSevent);
PRIVATE void vJoiningNetwork(ZPS_tsAfEvent *pZPSevent);
PRIVATE void vDeviceInTheNetwork(ZPS_tsAfEvent *pZPSevent,teEZ_JoinAction eJoinAction);

PRIVATE void vReDiscover(void);
PRIVATE void vHandleJoinedNwk(void);
PRIVATE void vHandleJoinFailed(void);
PRIVATE void vHandleDiscovery(ZPS_tsAfEvent *pZPSevent);

PRIVATE void vInitAssociationFilter( void);
PRIVATE void vSetAssociationFilter( void);
PRIVATE void vSetRejoinFilter( void);


/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
uint32 u32BackOffTime = 0;
/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

PRIVATE tsEZ_Join sEZModeData = { 0};
PRIVATE uint32 u32DefaultChannelMask=0x07fff800;
PRIVATE bool_t bRejoin;

PRIVATE tsBeaconFilterType sBeaconFilter;
PRIVATE uint64 au64ExtPanList[1];
/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
extern PUBLIC void vForceDeviceDeepSleep();
extern PUBLIC void vForceDeviceDeepSleepEx();

/****************************************************************************
 *
 * NAME: vEZ_ReJoin
 *
 * DESCRIPTION:
 *
 *
 * PARAMETERS:  Name                Usage
 *
 * RETURNS:
 * None
 *
 ****************************************************************************/
PUBLIC void vEZ_ReJoin(void)
{
    uint8 eStatus;
    ZPS_vNwkNibClearDiscoveryNT(ZPS_pvAplZdoGetNwkHandle());
    vSetRejoinFilter();
    eStatus = ZPS_eAplZdoRejoinNetwork(TRUE);
    DBG_vPrintf(TRACE_EZMODE,"ZPS_eAplZdoRejoinNetwork Status =%d\n",eStatus);
}

/****************************************************************************
 *
 * NAME: vEZ_RestoreDefaultAIBChMask
 *
 * DESCRIPTION:
 * The function restores the default channel mask from ZPS config.
 *
 * PARAMETERS:  Name                Usage
 *
 * RETURNS:
 * None
 *
 ****************************************************************************/
PUBLIC void vEZ_RestoreDefaultAIBChMask(void)
{
    u32DefaultChannelMask = ZPS_psAplAibGetAib()->u32ApsChannelMask;
}
/****************************************************************************
 *
 * NAME: vEZ_SetDefaultAIBChMask
 *
 * DESCRIPTION:
 *
 *
 * PARAMETERS:  Name                Usage
 *
 * RETURNS:
 * None
 *
 ****************************************************************************/
PUBLIC void vEZ_SetDefaultAIBChMask(void)
{
    void* pvNwk;
    pvNwk = ZPS_pvAplZdoGetNwkHandle();
    ZPS_psAplAibGetAib()->u32ApsChannelMask = 1 << ZPS_psNwkNibGetHandle( pvNwk)->sPersist.u8VsChannel;
    DBG_vPrintf(TRACE_EZMODE,"Default mask saved = 0x%08x, Mask Set to = 0x%08x\n",u32DefaultChannelMask,ZPS_psAplAibGetAib()->u32ApsChannelMask );
    /*Initialise for the first time*/
    vInitAssociationFilter();
}
/****************************************************************************
 *
 * NAME: eEZ_GetJoinState
 *
 * DESCRIPTION:
 *
 *
 * PARAMETERS:  Name                            Usage
 * None
 *
 * RETURNS:
 * None
 *
 ****************************************************************************/
PUBLIC teEZ_State eEZ_GetJoinState(void)
{
    return ((teEZ_State)sEZModeData.u8EZSetUpState);
}
/****************************************************************************
 *
 * NAME: vEZ_EZModeNWKJoinHandler
 *
 * DESCRIPTION:
 * EZ Mode Handle to be from application.
 *
 * PARAMETERS:  Name                            Usage
 * None
 *
 * RETURNS:
 * None
 *
 ****************************************************************************/
PUBLIC void vEZ_EZModeNWKJoinHandler(ZPS_tsAfEvent *pZPSevent,teEZ_JoinAction eJoinAction)
{
    bool_t bBackOffTimerExpirredFlag;
    bBackOffTimerExpirredFlag = bBackOffTimerExpirred();

    if( bBackOffTimerExpirredFlag && (sEZModeData.u8EZSetUpState != E_EZ_BACKOFF) )
    {
        /*Just Back Off with a timer for back off timing don't do anything else*/
        sEZModeData.u8EZSetUpState = E_EZ_BACKOFF;
        DBG_vPrintf(TRACE_EZMODE,"Getting into BackOff State\n");
    }
    else
    {
        /*Run The state machine */
        switch (sEZModeData.u8EZSetUpState)
        {
            case E_EZ_START:
            {
                vSetUpStart();
                break;
            }
            case E_EZ_WAIT_DISCOVERY_TIMEOUT:
            {
                vWaitDiscovery(pZPSevent);
                break;
            }
            case E_EZ_JOINING_NETWORK:
            {
                vJoiningNetwork(pZPSevent);
                break;
            }
            case E_EZ_DEVICE_IN_NETWORK:
            {
                vDeviceInTheNetwork(pZPSevent,eJoinAction);
                break;
            }
            #ifdef SUPPORT_JOIN_ELSE_FORM
            case E_EZ_NWK_FORMATION_TIMEOUT:
            {
                vFormingNetwork(pZPSevent);
                break;
            }
            #endif
            case E_EZ_BACKOFF:
            {
                vBackOff(bBackOffTimerExpirredFlag);
                break;
            }
            default :
                break;
        }
    }
}
#ifdef SUPPORT_JOIN_ELSE_FORM
/****************************************************************************
 *
 * NAME: vEZ_FormNWK
 *
 * DESCRIPTION:
 * Sets the bit to TRUE for forming the NWK
 *
 * PARAMETERS:  Name                            Usage
 *    None
 *
 * RETURNS:
 *
 *
 ****************************************************************************/

PUBLIC void vEZ_FormNWK(void)
{
    sEZModeData.bFormNwk=TRUE;
}
#endif
/****************************************************************************
 *
 * NAME: eEZ_UpdateEZState
 *
 * DESCRIPTION:
 * should be called from application once reloaded from PDM
 *
 * PARAMETERS:  Name                            Usage
 *                teEZ_State               EZ State
 *
 ****************************************************************************/

PUBLIC ZPS_teStatus eEZ_UpdateEZState(teEZ_State eEZState)
{
    ZPS_teStatus eStatus =ZPS_E_SUCCESS;

    sEZModeData.u8EZSetUpState = eEZState;

    DBG_vPrintf(TRACE_EZMODE, "\r\n vEZ_Update EZState state %d\n",  sEZModeData.u8EZSetUpState);
    if (sEZModeData.u8EZSetUpState == E_EZ_START )
    {
        /*If the State is start then start the Timers*/
        OS_eStartSWTimer(APP_JoinTimer,APP_TIME_MS(3000),NULL);
        OS_eStartSWTimer(APP_BackOffTimer,APP_TIME_MS(60000),NULL);
    }
    else if (sEZModeData.u8EZSetUpState == E_EZ_DEVICE_IN_NETWORK )
    {
        /*Restart The stack*/
        eStatus= ZPS_eAplZdoStartStack();
    }
    return eStatus;
}
#ifdef SUPPORT_JOIN_ELSE_FORM
/****************************************************************************
 *
 * NAME: vEZSetEZSetUpPolicy
 *
 * DESCRIPTION:
 * should be called from application to set Set up policy
 *
 * PARAMETERS:  Name                            Usage
 *
 ****************************************************************************/
PUBLIC void vEZ_SetUpPolicy(teEZ_SetUpPolicy ePolicy)
{
    sEZModeData.bSetUpPolicy = ePolicy;
    DBG_vPrintf(TRACE_EZMODE, "\r\n vEZ_SetUpPolicy  %d",  sEZModeData.bSetUpPolicy);

}
#endif
/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

/****************************************************************************
 *
 * NAME: vInitAssociationFilter
 *
 * DESCRIPTION:
 * Initialises the Association LQI value
 * And it loops back from max to min
 *
 * RETURNS:
 * void
 *
 *
 ****************************************************************************/
PRIVATE void vInitAssociationFilter( void)
{

    sBeaconFilter.pu64ExtendPanIdList = NULL;
    sBeaconFilter.u8ListSize = 0;

    sBeaconFilter.u8Lqi = LQI_MAX_VALUE;

    sBeaconFilter.u8FilterMap = BF_BITMAP_PERMIT_JOIN | BF_BITMAP_LQI;

    if (ZPS_ZDO_DEVICE_ENDDEVICE != ZPS_eAplZdoGetDeviceType())
        sBeaconFilter.u8FilterMap |= BF_BITMAP_CAP_ROUTER;
    else
        sBeaconFilter.u8FilterMap |= BF_BITMAP_CAP_ENDDEVICE;
}
/****************************************************************************
 *
 * NAME: vSetAssociationFilter
 *
 * DESCRIPTION:
 * Sets Association filters
 * The LQi value is set at MAX and on retry the values is reduced gradually
 * upto MIN value.
 * And it loops back from max to min
 *
 * RETURNS:
 * void
 *
 *
 ****************************************************************************/
PRIVATE void vSetAssociationFilter( void)
{
       sBeaconFilter.u8Lqi -= LQI_CHANGE_UNIT;
       if(sBeaconFilter.u8Lqi < LQI_MIN_VALUE )
           sBeaconFilter.u8Lqi = LQI_MAX_VALUE;

    DBG_vPrintf(TRACE_EZMODE,"Setting Filtes : sBeaconFilter.u8Lqi =%d\n sBeaconFilter.u8FilterMap = %d \n\n",sBeaconFilter.u8Lqi,sBeaconFilter.u8FilterMap);
}
/****************************************************************************
 *
 * NAME: vSetRejoinFilter
 *
 * DESCRIPTION:
 * Sets Association filters
 * The LQi value is set at MAX and on retry the values is reduced gradually
 * upto MIN value.
 * And it loops back from max to min
 *
 * RETURNS:
 * void
 *
 *
 ****************************************************************************/
PRIVATE void vSetRejoinFilter( void)
{
    au64ExtPanList[0] = ZPS_psAplAibGetAib()->u64ApsUseExtendedPanid;

    DBG_vPrintf(TRACE_EZMODE,"Rejoin - ZPS_u64AplZdoGetNetworkExtendedPanId = 0x%08x\n\n",au64ExtPanList[0]);
    sBeaconFilter.pu64ExtendPanIdList = au64ExtPanList;
    sBeaconFilter.u8ListSize = 1;
    sBeaconFilter.u8Lqi = LQI_MIN_VALUE;
    sBeaconFilter.u8FilterMap = BF_BITMAP_WHITELIST | BF_BITMAP_LQI;
    ZPS_bAppAddBeaconFilter( &sBeaconFilter);
}
/****************************************************************************
 *
 * NAME: vAttemptDiscovery
 *
 * DESCRIPTION:
 * Attempts discovery of the network with a given channel mask
 *
 * RETURNS:
 * void
 *
 *
 ****************************************************************************/
PRIVATE void vAttemptDiscovery(void)
{
    uint8 eStatus;
    teEZ_State EZ_State;
    uint16 u16TimeOut;

    sEZModeData.u8ScanAttempts++;

    if(bRejoin)
    {
        vEZ_ReJoin();
        EZ_State = E_EZ_JOINING_NETWORK;
        u16TimeOut = JOINING_TIMEOUT_IN_MS;
    }
    else
    {
        ZPS_vNwkNibClearDiscoveryNT(ZPS_pvAplZdoGetNwkHandle());
        /*Apply Association Filter*/
        ZPS_bAppAddBeaconFilter( &sBeaconFilter);
        eStatus = ZPS_eAplZdoDiscoverNetworks(  ZPS_psAplAibGetAib()->u32ApsChannelMask );
        EZ_State = E_EZ_WAIT_DISCOVERY_TIMEOUT;
        u16TimeOut = DISCOVERY_TIMEOUT_IN_MS;
        DBG_vPrintf(TRACE_EZMODE,"vAttemptDiscovery :- Discovery API Status =%d\n",eStatus);
    }

    vStartStopTimer(APP_JoinTimer,APP_TIME_MS(u16TimeOut),&(sEZModeData.u8EZSetUpState),EZ_State);
}
#ifdef SUPPORT_JOIN_ELSE_FORM
/****************************************************************************
 *
 * NAME: vAttemptFormNWK
 *
 * DESCRIPTION:
 * Attempts discovery of the network with a given channel mask
 *
 * RETURNS:
 * void
 *
 *
 ****************************************************************************/
PRIVATE void vAttemptFormNWK(void)
{
    ZPS_teStatus eStatus;
    sEZModeData.u8ScanAttempts++;
    ZPS_vNwkNibClearDiscoveryNT(ZPS_pvAplZdoGetNwkHandle());
    eStatus = ZPS_eAplZdoStartStack();
    DBG_vPrintf(TRACE_EZMODE,"vAttemptFormNWK :- StartStack =%d\n",eStatus);
    vStartStopTimer(APP_JoinTimer,APP_TIME_MS(NWK_FORMATION_TIMEOUT_IN_MS),&(sEZModeData.u8EZSetUpState),E_EZ_NWK_FORMATION_TIMEOUT);
}
#endif
/****************************************************************************
 *
 * NAME: vSetUpStart
 *
 * DESCRIPTION:
 * Starts the set up
 *
 * RETURNS:
 * void
 *
 *
 ****************************************************************************/
PRIVATE void vSetUpStart(void)
{
    if(OS_eGetSWTimerStatus(APP_JoinTimer) == OS_E_SWTIMER_EXPIRED)
    {
        vEZ_ClearStateVariables(); /*Clear All the variables related to set up*/
        eEZ_SetChannel();           /*Set Appropriate Channel in APS channel Mask*/
        #ifdef SUPPORT_JOIN_ELSE_FORM
        /* Form/Join network Base on configuration */
        if( (E_EZ_JOIN_ELSE_FORM_IF_NO_NETWORK == sEZModeData.bSetUpPolicy ) &&
            (ZPS_ZDO_DEVICE_ENDDEVICE         != ZPS_eAplZdoGetDeviceType())     )
        {
            DBG_vPrintf(TRACE_EZMODE, "vEZ_ModeFormOrJoinNwk on E_EZ_JOIN_ELSE_FORM_IF_NO_NETWORK  \n");
            vEZ_ModeFormOrJoinNwk();
        }

        if (FALSE == sEZModeData.bFormNwk)
        {
        #endif
            /*Not forming the Network ? - Ok, then attempt to discover */
        vAttemptDiscovery();
        #ifdef SUPPORT_JOIN_ELSE_FORM
        }

        else
        {
            /*Forming NWK*/
            vAttemptFormNWK();
        }
        #endif
    }
}
/****************************************************************************
 *
 * NAME: vDeviceInTheNetwork
 *
 * DESCRIPTION:
 * State when the device is already in the NWK
 *
 * RETURNS:
 * void
 *
 *
 ****************************************************************************/
PRIVATE void vDeviceInTheNetwork(ZPS_tsAfEvent *pZPSevent,teEZ_JoinAction eJoinAction)
{
		DBG_vPrintf(TRACE_EZMODE, "vDeviceInTheNetwork bRejoin=%d\n",bRejoin);
    bRejoin = (bool_t)eJoinAction;
    if(bRejoin)
    {
        uint8 aa;
        vStartStopTimer(APP_BackOffTimer,APP_TIME_MS(BACKOFF_TIMEOUT_IN_MS),&aa,aa);
        vStartStopTimer(APP_JoinTimer,APP_TIME_MS(500),&(sEZModeData.u8EZSetUpState),E_EZ_START);
    }
}
/****************************************************************************
 *
 * NAME: vWaitDiscovery
 *
 * DESCRIPTION:
 * Waits after a discovery was issued, so if the time out happens
 *
 * RETURNS:
 * void
 *
 *
 ****************************************************************************/
PRIVATE void vWaitDiscovery(ZPS_tsAfEvent *pZPSevent)
{

    if(OS_eGetSWTimerStatus(APP_JoinTimer) == OS_E_SWTIMER_EXPIRED)
    {
        vReDiscover();
    }
    else
    {
        if (pZPSevent->eType != ZPS_EVENT_NONE)
        {
            switch(pZPSevent->eType)
            {
                case(ZPS_EVENT_NWK_DISCOVERY_COMPLETE):
                    vHandleDiscovery(pZPSevent);
                    break;

                case(ZPS_EVENT_NWK_JOINED_AS_ROUTER):     /* fall through*/
                case(ZPS_EVENT_NWK_JOINED_AS_ENDDEVICE):
                    vHandleJoinedNwk();
                    break;

                case(ZPS_EVENT_NWK_FAILED_TO_JOIN):
                    if (ZPS_psAplAibGetAib()->u64ApsUseExtendedPanid != 0)
                    {
                        DBG_vPrintf(TRACE_EZMODE, "Restore epid %016llx\n", ZPS_psAplAibGetAib()->u64ApsUseExtendedPanid);
                        ZPS_vNwkNibSetExtPanId(ZPS_pvAplZdoGetNwkHandle(), ZPS_psAplAibGetAib()->u64ApsUseExtendedPanid);
                    }
                    vReDiscover();
                    break;

                default:
                    break;
            }
        }
    }
}
/****************************************************************************
 *
 * NAME: vBackOff
 *
 * DESCRIPTION:
 * BackOff state, where the device will not do anything but wait before it starts
 * to attempt joining
 *
 * RETURNS:
 * void
 *
 *
 ****************************************************************************/
PRIVATE void vBackOff(bool_t bBackOffTimerExpirredFlag )
{
    if(bBackOffTimerExpirredFlag)
    {
        /*Come back to Start Up state*/
        vStartStopTimer( APP_JoinTimer, APP_TIME_MS(RESTART_TIME_IN_MS),&(sEZModeData.u8EZSetUpState),E_EZ_START );
        DBG_vPrintf(TRACE_EZMODE,"BackOff State -> Start State\n");
    }
}

/****************************************************************************
 *
 * NAME: bBackOffTimerExpirred
 *
 * DESCRIPTION:
 * Returns if the back up time is over and maintains the back off timing
 *
 * RETURNS:
 * TRUE if back off time is over, else FALSE
 *
 *
 ****************************************************************************/
PRIVATE bool_t bBackOffTimerExpirred(void)
{
    if(OS_eGetSWTimerStatus(APP_BackOffTimer) == OS_E_SWTIMER_EXPIRED)
    {
        OS_eStopSWTimer(APP_BackOffTimer);
        OS_eStartSWTimer(APP_BackOffTimer, APP_TIME_MS(BACKOFF_TIMEOUT_IN_MS), NULL );
        /*Increament by 1 minute */
        u32BackOffTime++;
        DBG_vPrintf(TRACE_EZMODE,"Time in Minute  = %d\n",u32BackOffTime);

        /*15 Minutes past - Change state*/
        if(u32BackOffTime >= BACKOFF_TIME_IN_MINUTES)
        {
            u32BackOffTime=0;
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    return FALSE;
}
/****************************************************************************
 *
 * NAME: vJoiningNetwork
 *
 * DESCRIPTION:
 * Joining the NWK state.
 *
 * RETURNS:
 * void
 *
 *
 ****************************************************************************/
PRIVATE void vJoiningNetwork(ZPS_tsAfEvent *pZPSevent)
{

    if(OS_eGetSWTimerStatus(APP_JoinTimer) == OS_E_SWTIMER_EXPIRED)
    {
        DBG_vPrintf(TRACE_EZMODE, "Joining TimeOut -- \n\n\n\n");
        vHandleJoinFailed();
    }
    else
    {
        if (pZPSevent->eType != ZPS_EVENT_NONE)
        {
            switch(pZPSevent->eType)
            {
                case(ZPS_EVENT_NWK_JOINED_AS_ROUTER):     /* fall through*/
                case(ZPS_EVENT_NWK_JOINED_AS_ENDDEVICE):
                    vHandleJoinedNwk();
                    break;

                case(ZPS_EVENT_NWK_FAILED_TO_JOIN):
                    if(OS_eGetSWTimerStatus(APP_JoinTimer) != OS_E_SWTIMER_STOPPED)
                    {
                        OS_eStopSWTimer(APP_JoinTimer);
                    }
                    if (ZPS_psAplAibGetAib()->u64ApsUseExtendedPanid != 0)
                    {
                        DBG_vPrintf(TRACE_EZMODE, "Restore epid %016llx\n", ZPS_psAplAibGetAib()->u64ApsUseExtendedPanid);
                        ZPS_vNwkNibSetExtPanId(ZPS_pvAplZdoGetNwkHandle(), ZPS_psAplAibGetAib()->u64ApsUseExtendedPanid);
                    }
                    vHandleJoinFailed();
                    break;

                default:
                    break;
            }
        }
    }
}
#ifdef SUPPORT_JOIN_ELSE_FORM
/****************************************************************************
 *
 * NAME: vFormingNetwork
 *
 * DESCRIPTION:
 * Forming the NWK state.
 *
 * RETURNS:
 * void
 *
 *
 ****************************************************************************/
PRIVATE void vFormingNetwork(ZPS_tsAfEvent *pZPSevent)
{

    if(OS_eGetSWTimerStatus(APP_JoinTimer) == OS_E_SWTIMER_EXPIRED)
    {
        DBG_vPrintf(TRACE_EZMODE, "NWK Formation TimeOut -- \n\n\n\n");
        vHandleJoinFailed();
    }
    else
    {
        if (pZPSevent->eType != ZPS_EVENT_NONE)
        {
            switch(pZPSevent->eType)
            {
                case(ZPS_EVENT_NWK_STARTED):
                    vHandleFormedNwk();
                    break;

                case(ZPS_EVENT_NWK_FAILED_TO_START):
                    vHandleFailedToStart();
                    break;

                default:
                    break;
            }
        }
    }
}
#endif
/****************************************************************************
 *
 * NAME: vReDiscover
 *
 * DESCRIPTION:
 * Initiates re-discovery, if all the attepmts are over switches the state
 *
 * RETURNS:
 * void
 *
 *
 ****************************************************************************/
PRIVATE void vReDiscover(void)
{
    DBG_vPrintf(TRACE_EZMODE, "Discovery Failed to Join...retry times=%d\n",sEZModeData.u8ScanAttempts);
    if (sEZModeData.u8ScanAttempts >= MAX_DISCOVERY_ATTEMPT_PER_CHANNEL)
    {
        DBG_vPrintf(TRACE_EZMODE, "Gave up!!!\n");
        vForceDeviceDeepSleepEx();
    }
    else
    {
        vAttemptDiscovery();
    }
}
/****************************************************************************
 *
 * NAME: vEZ_SortAndSaveNetworks
 *
 * DESCRIPTION:
 * This function sorts discovered networks based on LQI and saves it
 *
 * PARAMETERS:  Name                            Usage
 *    None
 *
 * RETURNS:
 * None
 *
 ****************************************************************************/
PRIVATE void vEZ_SortAndSaveNetworks(ZPS_tsAfNwkDiscoveryEvent *pNwkDes)
{
    uint8 i=0;
    uint8 j=0;

    ZPS_tsNwkNetworkDescr sTempDesc;
    ZPS_tsNwkDiscNtEntry *pTempDiscEntry1;
    ZPS_tsNwkDiscNtEntry *pTempDiscEntry2;


    sEZModeData.u8JoinIndex = 0;
    sEZModeData.u8DiscoveredNwkCount = pNwkDes->u8NetworkCount;
    DBG_vPrintf(TRACE_EZMODE, "vEZ_SortAndSaveNetworks \n");

    for(i=0; (i < EZ_MAX_NETWORK_DESCRIPTOR ) && ( i < pNwkDes->u8NetworkCount); i++)
    {
        DBG_vPrintf(TRACE_EZMODE,"*");
        {
            /* copy descriptors */
            memcpy(&sEZModeData.asSavedNetworks[i],
                    &pNwkDes->psNwkDescriptors[i],
                    sizeof(ZPS_tsNwkNetworkDescr));
            DBG_vPrintf(TRACE_EZMODE, "Saving Open NWK ExPANID = 0x%16llx\n",sEZModeData.asSavedNetworks[i].u64ExtPanId);
        }
    }
    DBG_vPrintf(TRACE_EZMODE, "vEZ_SortAndSaveNetworks sEZModeData.u8DiscoveredNwkCount = %d\n",sEZModeData.u8DiscoveredNwkCount);
    for(i=0; i< sEZModeData.u8DiscoveredNwkCount; i++)
    {
        for(j=i+1; j< sEZModeData.u8DiscoveredNwkCount; j++)
        {
            pTempDiscEntry1 = sEZ_GetDiscEntry(&sEZModeData.asSavedNetworks[i].u64ExtPanId);
            pTempDiscEntry2 = sEZ_GetDiscEntry(&sEZModeData.asSavedNetworks[j].u64ExtPanId);

            DBG_vPrintf(TRACE_EZMODE,"\n\n\n");
            DBG_vPrintf(TRACE_EZMODE, "EPID 0x%16llx has LQI %d \n",sEZModeData.asSavedNetworks[i].u64ExtPanId,pTempDiscEntry1->u8LinkQuality);
            DBG_vPrintf(TRACE_EZMODE, "EPID 0x%16llx has LQI %d \n",sEZModeData.asSavedNetworks[j].u64ExtPanId,pTempDiscEntry2->u8LinkQuality);
            if((NULL != pTempDiscEntry1 ) &&(NULL != pTempDiscEntry2))
            {

                if(pTempDiscEntry1->u8LinkQuality < pTempDiscEntry2->u8LinkQuality)
                {
                    /* swap*/
                    memcpy(&sTempDesc,                         &(sEZModeData.asSavedNetworks[i]),    sizeof(ZPS_tsNwkNetworkDescr) );
                    memcpy(&sEZModeData.asSavedNetworks[i],    &(sEZModeData.asSavedNetworks[j]),     sizeof(ZPS_tsNwkNetworkDescr) );
                    memcpy(&sEZModeData.asSavedNetworks[j],    &sTempDesc,                            sizeof(ZPS_tsNwkNetworkDescr) );

                    DBG_vPrintf(TRACE_EZMODE, "vEZ_SortAndSaveNetworks  sorted pan id %16llx with panid%16llx at indexs %d with index %d\n",
                            sEZModeData.asSavedNetworks[j].u64ExtPanId,sEZModeData.asSavedNetworks[i].u64ExtPanId, j,i);
                }
            }
        }
    }
}
/****************************************************************************
 *
 * NAME:vEZ_JoinSavedNetwork
 *
 * DESCRIPTION:
 * This function joins to network stored at index sEZModeData.u8JoinIndex
 *
 * PARAMETERS:  Name                            Usage
 *    None
 *
 * RETURNS:
 * None
 *
 ****************************************************************************/
PRIVATE void vEZ_JoinSavedNetwork(void)
{
    uint8 u8Status;

    if( sEZModeData.u8DiscoveredNwkCount > 0)
    {
        while( sEZModeData.u8JoinIndex < sEZModeData.u8DiscoveredNwkCount  )
        {
            u8Status = ZPS_eAplZdoJoinNetwork(&(sEZModeData.asSavedNetworks[sEZModeData.u8JoinIndex]));
            sEZModeData.u8JoinIndex++;
            if(ZPS_E_SUCCESS != u8Status )
            {
                /* This should not happen */
                DBG_vPrintf(TRACE_EZMODE, "API failed in vEZ_JoinSavedNetwork %d\n",u8Status);
            }
            else
            {
                DBG_vPrintf(TRACE_EZMODE, "Join Network API Success \n");
                vStartStopTimer( APP_JoinTimer, APP_TIME_MS(JOINING_TIMEOUT_IN_MS),&(sEZModeData.u8EZSetUpState),E_EZ_JOINING_NETWORK );
                return ;
            }
        }
        if (sEZModeData.u8JoinIndex >= sEZModeData.u8DiscoveredNwkCount)
        {
            DBG_vPrintf(TRACE_EZMODE, "Exhausted NWK Join\n\n\n");
            vStartStopTimer( APP_JoinTimer, APP_TIME_MS(RESTART_TIME_IN_MS),&(sEZModeData.u8EZSetUpState),E_EZ_START );
        }
    }
    else
    {
        DBG_vPrintf(TRACE_EZMODE, "NO Open NWK,Gave up!!!\n\n\n");
				vForceDeviceDeepSleepEx();
    }
}
/****************************************************************************
 *
 * NAME: sEZ_GetDiscEntry
 *
 * DESCRIPTION:
 * This function retreives discovery table entry with given extended panid
 *
 * PARAMETERS:  Name                            Usage
 *    uint64 *pExtendedPanId                Pointer to a 64bit Exnd PAN ID
 *
 * RETURNS:
 * Pointer of type ZPS_tsNwkDiscNtEntry to discovery entry.
 *
 ****************************************************************************/
PRIVATE ZPS_tsNwkDiscNtEntry *sEZ_GetDiscEntry(uint64 *pExtendedPanId)
{
    uint32 i;
    ZPS_tsNwkNib *thisNib;
    thisNib = ZPS_psNwkNibGetHandle(ZPS_pvAplZdoGetNwkHandle());

    for( i = 0; i < thisNib->sTblSize.u8NtDisc; i++)
    {
        if(thisNib->sTbl.psNtDisc[i].u64ExtPanId == *pExtendedPanId )
        {
            return(&thisNib->sTbl.psNtDisc[i]);
        }
    }
    return NULL;
}

/****************************************************************************
 *
 * NAME: eEZ_SetChannel
 *
 * DESCRIPTION:
 * This function sets the primary channels and other channels alternatively
 *
 * PARAMETERS:  Name                            Usage
 *    None
 *
 * RETURNS:
 * None
 *
 ****************************************************************************/
PRIVATE eChannelsSelected eEZ_SetChannel(void)
{
    /* Rejoining hence put the full mask and let the Rejoin Filter takecare*/
    if(bRejoin)
    {
        ZPS_psAplAibGetAib()->u32ApsChannelMask = u32DefaultChannelMask;
        DBG_vPrintf(TRACE_EZMODE, "\n\n\nRejoining - Set Channel to 0x%08x\n",ZPS_psAplAibGetAib()->u32ApsChannelMask);
        return E_EZ_SCAN_ALL_CHANNEL_COMPLETED;
    }

    /*If Joining - start discovery channel by channel */

    /* Full mask in  primary->secondary order */
    const uint8 u8DiscChannels[] = { 11, 14, 15, 19, 20, 24, 25, 12, 13, 16, 17, 18, 21, 22, 23, 26 };
    static uint8 u8ChannelIndex = 0;
    bool bChannelSetOK = FALSE;

    DBG_vPrintf(TRACE_EZMODE, "eEZ_SetChannel\n");

    /* Loop until channel is set */
    /* ASSERT, at least 1 channel must be set in the user defined channel mask */
    while( !bChannelSetOK )
    {

        /* set a single channel from the primary/secondary selected by user */
        if( (u32DefaultChannelMask) & (1 << u8DiscChannels[u8ChannelIndex]))
        {
            ZPS_psAplAibGetAib()->u32ApsChannelMask = 1 << u8DiscChannels[u8ChannelIndex];

            bChannelSetOK = TRUE;
            DBG_vPrintf(TRACE_EZMODE, "\n\n\nSet Channel to %d\n",u8DiscChannels[u8ChannelIndex]);
        }
        if( u8DiscChannels[u8ChannelIndex] != 26)
        {
            u8ChannelIndex++;
        }
        else
        {
            u8ChannelIndex = 0;
        }
    }
    if(  11 == u8DiscChannels[u8ChannelIndex-1])
    {
        /* Set Filters when a new scan of the channels starts*/
        vSetAssociationFilter();
        DBG_vPrintf(TRACE_EZMODE, "Scan is over Channel \n");
        return E_EZ_SCAN_ALL_CHANNEL_COMPLETED;
    }
    else
    {
        return E_EZ_SCAN_HALF_CHANNEL_COMPLETED;
    }
}
#ifdef SUPPORT_JOIN_ELSE_FORM
/****************************************************************************
 *
 * NAME: vHandleFailedToStart
 *
 * DESCRIPTION:
 * Handles the start failed event
 *
 * PARAMETERS:  Name                            Usage
 *
 *
 * RETURNS:
 *
 *
 ****************************************************************************/
PRIVATE void vHandleFailedToStart(void)
{

}
#endif
/****************************************************************************
 *
 * NAME: vHandleDiscovery
 *
 * DESCRIPTION:
 * Handles discovery during the joining
 *
 * PARAMETERS:  Name                            Usage
 *                ZPS_tsAfEvent *pZPSevent        Stack event
 *
 * RETURNS:
 *
 *
 ****************************************************************************/
PRIVATE void vHandleDiscovery(ZPS_tsAfEvent *pZPSevent)
{
    DBG_vPrintf(TRACE_EZMODE, "ZPS_EVENT_NWK_DISCOVERY_COMPLETE......");
    if( /*( ZPS_E_SUCCESS != pZPSevent->uEvent.sNwkDiscoveryEvent.eStatus) || */(pZPSevent->uEvent.sNwkDiscoveryEvent.u8NetworkCount == 0) )
    {
        DBG_vPrintf(TRACE_EZMODE, "Discovery ERR Status = %d or No NWK Count = %d\n",pZPSevent->uEvent.sNwkDiscoveryEvent.eStatus,pZPSevent->uEvent.sNwkDiscoveryEvent.u8NetworkCount);
        vStartStopTimer(APP_JoinTimer,APP_TIME_MS(DISCOVERY_TIMEOUT_IN_MS),&(sEZModeData.u8EZSetUpState),E_EZ_WAIT_DISCOVERY_TIMEOUT);
    }
    else
    {
        DBG_vPrintf(TRACE_EZMODE, "NWK Found, Count = %d  \n",pZPSevent->uEvent.sNwkDiscoveryEvent.u8NetworkCount);
        vEZ_SortAndSaveNetworks(&(pZPSevent->uEvent.sNwkDiscoveryEvent));
        vEZ_JoinSavedNetwork();
    }
}

/****************************************************************************
 *
 * NAME: vHandleJoinedNwk
 *
 * DESCRIPTION:
 * Handles the Device joined state, the state needs to be persisted here
 *
 * PARAMETERS:
 *
 * RETURNS:
 *
 *
 ****************************************************************************/
PRIVATE void vHandleJoinedNwk(void)
{

    OS_eStopSWTimer(APP_JoinTimer);
    OS_eStopSWTimer(APP_BackOffTimer);
    /*Rejoin is cleared now */
    bRejoin=FALSE;
    /* Now device part of network. Update state variable in persistent storage */
    sEZModeData.u8EZSetUpState = E_EZ_DEVICE_IN_NETWORK;

    /* Store EPID for future rejoin */
    ZPS_eAplAibSetApsUseExtendedPanId(ZPS_u64NwkNibGetEpid( ZPS_pvAplZdoGetNwkHandle()));

    ZPS_u16AplZdoLookupAddr(ZPS_psAplAibGetAib()->u64ApsTrustCenterAddress);
}
#ifdef SUPPORT_JOIN_ELSE_FORM
/****************************************************************************
 *
 * NAME: vHandleFormedNwk
 *
 * DESCRIPTION:
 * Handles the Device joined state, the state needs to be persisted here
 *
 * PARAMETERS:
 *
 * RETURNS:
 *
 *
 ****************************************************************************/
PRIVATE void vHandleFormedNwk(void)
{

    OS_eStopSWTimer(APP_JoinTimer);
    OS_eStopSWTimer(APP_BackOffTimer);
    /* Now device part of network. Update state variable in persistent storage */
    sEZModeData.u8EZSetUpState = E_EZ_DEVICE_IN_NETWORK;
}
#endif
/****************************************************************************
 *
 * NAME: vHandleJoinFailed
 *
 * DESCRIPTION:
 * Handles the Device join failure state
 *
 * PARAMETERS:
 *
 * RETURNS:
 *
 *
 ****************************************************************************/
PRIVATE void vHandleJoinFailed(void)
{
		DBG_vPrintf(TRACE_EZMODE, "Join Failed bRejoin=%d\n",bRejoin);
    if(bRejoin)
    {
        //vStartStopTimer( APP_JoinTimer, APP_TIME_MS(1000),&(sEZModeData.u8EZSetUpState),E_EZ_START );
				DBG_vPrintf(TRACE_EZMODE, "Rejoin failed,Gave up!!!\n\n\n");
				vForceDeviceDeepSleepEx();        
    }
    else
        vEZ_JoinSavedNetwork();
}
#ifdef SUPPORT_JOIN_ELSE_FORM
/****************************************************************************
 *
 * NAME: vEZ_ModeFormOrJoinNwk
 *
 * DESCRIPTION:
 * Set Up device type so that it may either join or form the network
 *
 * PARAMETERS:  Name                            Usage
 * None
 *
 * RETURNS:
 * None
 *
 ****************************************************************************/
PRIVATE void vEZ_ModeFormOrJoinNwk( void )
{
    if (TRUE == sEZModeData.bFormNwk)
    {
        DBG_vPrintf(TRACE_EZMODE,"Forming NWK\n");
        ZPS_vNwkSetDeviceType(ZPS_pvNwkGetHandle(),ZPS_NWK_DT_COORDINATOR);
        ZPS_vSetZdoDeviceType(ZPS_ZDO_DEVICE_COORD);
    }
    else
    {
        DBG_vPrintf(TRACE_EZMODE,"Joining NWK\n");
        ZPS_vNwkSetDeviceType(ZPS_pvNwkGetHandle(),ZPS_NWK_DT_ROUTER);
        ZPS_vSetZdoDeviceType(ZPS_ZDO_DEVICE_ROUTER);
    }
}
#endif
/****************************************************************************
 **
 ** NAME:       vEZ_ClearStateVariables
 **
 ** DESCRIPTION:
 ** Function to reset variables
 **
 ** PARAMETERS:                 Name               Usage
 ** tsZCL_CallBackEvent        *psCallBackEvent    Timer Server Callback
 **
 ** RETURN:
 ** None
 **
 ****************************************************************************/
PRIVATE void vEZ_ClearStateVariables(void)
{
    DBG_vPrintf(TRACE_EZMODE, "vEZ_ClearStateVariables\r\n");
    sEZModeData.u8ScanAttempts = 0;
    sEZModeData.u8ScanDurationInSec = 0;
    sEZModeData.u8IsPrimaryChannelsScanned = 0;
    sEZModeData.u8SetUpTime = 0;
    sEZModeData.u8JoinIndex = 0;
    sEZModeData.u8DiscoveredNwkCount = 0;
    memset(sEZModeData.asSavedNetworks,0,sizeof(ZPS_tsNwkNetworkDescr)*EZ_MAX_NETWORK_DESCRIPTOR);
}
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/


/*****************************************************************************
 *
 * MODULE:             Smart Energy
 *
 * COMPONENT:          zcl_timer.c
 *
 * AUTHOR:             we1
 *
 * DESCRIPTION:       ZCL timer functions
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/Components/ZCL/Branches/Zigbee_3_0/Source/zcl_timer.c $
 *
 * $Revision: 65454 $
 *
 * $LastChangedBy: nxp57621 $
 *
 * $LastChangedDate: 2014-11-13 15:14:02 +0530 (Thu, 13 Nov 2014) $
 *
 * $Id: zcl_timer.c 65454 2014-11-13 09:44:02Z nxp57621 $
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
 ****************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#include <jendefs.h>
#include <string.h>

#include "dlist.h"

#include "zcl_common.h"

#include "zcl.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
PRIVATE bool boExpiredCheck(
                    tsZCL_TimerRecord          *psTimerRecord,
                    teZCL_CallBackEventType     eEventType);

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

/****************************************************************************
 **
 ** NAME:       eZCL_CreateTimer
 **
 ** DESCRIPTION:
 ** Creates ZCL timer
 **
 ** PARAMETERS:                 Name                     Usage
 ** uint8                       u8NumberOfTimers         No. Of Timers Device
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/

PUBLIC  teZCL_Status eZCL_CreateTimer(uint8 u8NumberOfTimers)
{
    int i;

    // create Timer record array
    vZCL_HeapAlloc(psZCL_Common->psTimerRecord, tsZCL_TimerRecord, (sizeof(tsZCL_TimerRecord))*u8NumberOfTimers, TRUE, "Timer_Record");
    if (psZCL_Common->psTimerRecord == NULL)
    {
        return E_ZCL_ERR_HEAP_FAIL;
    }

    /* initialise lists */
    vDLISTinitialise(&psZCL_Common->lTimerAllocList);
    vDLISTinitialise(&psZCL_Common->lTimerDeAllocList);

    psZCL_Common->u8NumberOfTimers = u8NumberOfTimers;

    // initialise structure
    for(i=0;i<u8NumberOfTimers;i++)
    {
        /* add all header slots to the to free list */
        vDLISTaddToHead(&psZCL_Common->lTimerDeAllocList, (DNODE *)&psZCL_Common->psTimerRecord[i]);
        // initialise
        psZCL_Common->psTimerRecord[i].eTimerMode = E_ZCL_TIMER_STOP;
        psZCL_Common->psTimerRecord[i].u32UTCTime = 0;
        psZCL_Common->psTimerRecord[i].pfZCLCallBackFunction = NULL;
    }

    return(E_ZCL_SUCCESS);
}

/****************************************************************************
 **
 ** NAME:       eZCL_TimerRegister
 **
 ** DESCRIPTION:
 ** Registers a timer with the ZCL
 **
 ** PARAMETERS:                 Name                    Usage
 ** teZCL_TimerMode             eTimerMode              Trigger Mode
 ** uint32                      u32UTCTime              Trigger Time
 ** tfpZCL_ZCLCallBackFunction  pfZCLCallBackFunction   Trigger Callback
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/

PUBLIC  teZCL_Status eZCL_TimerRegister(
                    teZCL_TimerMode             eTimerMode,
                    uint32                      u32UTCTime,
                    tfpZCL_ZCLCallBackFunction  pfZCLCallBackFunction)
{

    tsZCL_TimerRecord *psTimerRecord;

    if((eTimerMode >= E_ZCL_TIMER_ENUM_END) || (pfZCLCallBackFunction== NULL))
    {
        return(E_ZCL_ERR_PARAMETER_RANGE);
    }
#ifndef COOPERATIVE
    // get ZCL mutex
    vZCL_GetInternalMutex();
#endif
    // get first resource
    psTimerRecord = (tsZCL_TimerRecord *)psDLISTgetHead(&psZCL_Common->lTimerDeAllocList);
    if(psTimerRecord==NULL)
    {
        // release EP
		#ifndef COOPERATIVE
        vZCL_ReleaseInternalMutex();
		#endif
        return(E_ZCL_ERR_TIMER_RESOURCE);
    }

    psTimerRecord->eTimerMode = eTimerMode;
    psTimerRecord->u32UTCTime = u32UTCTime;

    if(psTimerRecord->eTimerMode == E_ZCL_TIMER_INTERVAL)
    {
        // make timer an absolute value, oneshot
        psTimerRecord->u32UTCTime += psZCL_Common->u32UTCTime;
    }

    psTimerRecord->pfZCLCallBackFunction = pfZCLCallBackFunction;

    // remove from dealloc list
    psDLISTremove(&psZCL_Common->lTimerDeAllocList, (DNODE *)psTimerRecord);
    // add to alloc list
    vDLISTaddToTail(&psZCL_Common->lTimerAllocList, (DNODE *)(psTimerRecord));

    // release EP
	#ifndef COOPERATIVE
    vZCL_ReleaseInternalMutex();
#endif
    return(E_ZCL_SUCCESS);
}

/****************************************************************************
 **
 ** NAME:       vZCL_TimerSchedulerUpdate
 **
 ** DESCRIPTION:
 ** Called to update the timer list and process user callbacks
 **
 ** PARAMETERS:                 Name                        Usage
 ** uint32                      u32UTCTime                  Current time
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/

PUBLIC void vZCL_TimerSchedulerUpdate(tsZCL_CallBackEvent *psZCLcallBackEvent)
{

    tsZCL_TimerRecord *psTimerRecord;
    tsZCL_TimerRecord *psTimerRecordCopy;
    bool_t boDeleteEntry;
#ifndef COOPERATIVE
    // get ZCL mutex
    vZCL_GetInternalMutex();
#endif	
    if(psZCLcallBackEvent->eEventType == E_ZCL_CBET_TIMER)
    {
      // increment ZCL's notion of time
        psZCL_Common->u32UTCTime++;
    }
      // get first resource
    psTimerRecord = (tsZCL_TimerRecord *)psDLISTgetHead(&psZCL_Common->lTimerAllocList);

    // search
    while(psTimerRecord != NULL)
    {
        // check whether timer entry has fired
        boDeleteEntry = boExpiredCheck(psTimerRecord, psZCLcallBackEvent->eEventType);
        psTimerRecordCopy = psTimerRecord;
        // get next list member
        psTimerRecord = (tsZCL_TimerRecord *)psDLISTgetNext((DNODE *)psTimerRecord);
        if(boDeleteEntry)
        {
            // remove it from alloc  list
            psDLISTremove(&psZCL_Common->lTimerAllocList, (DNODE *)psTimerRecordCopy);
            // add to free list
            vDLISTaddToTail(&psZCL_Common->lTimerDeAllocList, (DNODE *)psTimerRecordCopy);
        }
    }

#ifdef CLD_BIND_SERVER
    if(psZCLcallBackEvent->eEventType == E_ZCL_CBET_TIMER)
    {
        vZCL_BindServerTransmissionTimerCallback();
    }
#endif /* CLD_BIND_SERVER */

    // release EP
#ifndef COOPERATIVE	
    vZCL_ReleaseInternalMutex();
#endif	
}

/****************************************************************************
 **
 ** NAME:       vZCL_SetUTCTime
 **
 ** DESCRIPTION:
 ** Sets the ZCL time reference
 **
 ** PARAMETERS:                 Name                    Usage
 ** uint32                      u32UTCTime              Time
 **
 ** RETURN:
 ** nothing
 **
 ****************************************************************************/

PUBLIC void vZCL_SetUTCTime(uint32 u32UTCTime)
{
#ifndef COOPERATIVE
    // get ZCL mutex
    vZCL_GetInternalMutex();
#endif	
    // set time
    psZCL_Common->u32UTCTime = u32UTCTime;

    psZCL_Common->bTimeHasBeenSynchronised = TRUE;
    // release EP
	#ifndef COOPERATIVE
    vZCL_ReleaseInternalMutex();
	#endif

}

/****************************************************************************
 **
 ** NAME:       u32ZCL_GetUTCTime
 **
 ** DESCRIPTION:
 ** Sets the ZCL time reference
 **
 ** PARAMETERS:                 Name                    Usage
 ** none
 **
 ** RETURN:
 ** uint32 u32UTCTime
 **
 ****************************************************************************/

PUBLIC uint32 u32ZCL_GetUTCTime(void)
{
    uint32 u32UTCTime;
#ifndef COOPERATIVE
    // get ZCL mutex
    vZCL_GetInternalMutex();
#endif	

    // get time
    u32UTCTime = psZCL_Common->u32UTCTime;

    // release EP
	#ifndef COOPERATIVE
    vZCL_ReleaseInternalMutex();
#endif
    return(u32UTCTime);

}
/****************************************************************************
 **
 ** NAME:       eZCL_UpdateMsTimer
 **
 ** DESCRIPTION:
 **
 **
 ** PARAMETERS:               Name                    Usage
 ** tsZCL_EndPointDefinition *psEndPointDefinition    Pointer to endpoint structure
 ** teZCL_TimerResolution    eTimerResolution         Timer REsolution required
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC teZCL_Status eZCL_UpdateMsTimer(
                    tsZCL_EndPointDefinition   *psEndPointDefinition,
                    bool_t                      bEnable,
                    uint32                      u32TimerPeriodMs)
{
    #ifdef STRICT_PARAM_CHECK
        if(psEndPointDefinition == NULL)
        {
            return(E_ZCL_FAIL);
        }
    #endif
    memset(&psZCL_Common->sZCL_CallBackEvent, 0, sizeof(tsZCL_CallBackEvent));
    psZCL_Common->sZCL_CallBackEvent.u8EndPoint = psEndPointDefinition->u8EndPointNumber;
    if(bEnable)
    {
        psZCL_Common->sZCL_CallBackEvent.eEventType = E_ZCL_CBET_ENABLE_MS_TIMER;
    }
    else
    {
        psZCL_Common->sZCL_CallBackEvent.eEventType = E_ZCL_CBET_DISABLE_MS_TIMER;
    }
    psZCL_Common->sZCL_CallBackEvent.uMessage.u32TimerPeriodMs = u32TimerPeriodMs;
    psEndPointDefinition->pCallBackFunctions(&psZCL_Common->sZCL_CallBackEvent);

    return(E_ZCL_SUCCESS);
}
/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

/****************************************************************************
 **
 ** NAME:       boExpiredCheck
 **
 ** DESCRIPTION:
 ** Checks for expired timers - calls registered user c/b's
 **
 ** PARAMETERS:             Name              Usage
 ** tsZCL_TimerRecord       *psTimerRecord    Timer Record
 ** uint32                  u32UTCTime        Time Value
 **
 ** RETURN:
 ** 1 - Delete 0 - Don't
 **
 ****************************************************************************/

PRIVATE bool boExpiredCheck(
                    tsZCL_TimerRecord          *psTimerRecord,
                    teZCL_CallBackEventType     eEventType)
{

    // clear c/b structure
    memset(&psZCL_Common->sTimerCallBackEvent, 0, sizeof(tsZCL_CallBackEvent));
    psZCL_Common->sTimerCallBackEvent.eEventType = eEventType;
    psZCL_Common->sTimerCallBackEvent.uMessage.sTimerMessage.u32UTCTime = psZCL_Common->u32UTCTime;
    psZCL_Common->sTimerCallBackEvent.uMessage.sTimerMessage.eTimerMode = psTimerRecord->eTimerMode;
    psZCL_Common->sTimerCallBackEvent.eZCL_Status = E_ZCL_SUCCESS;

    switch(psTimerRecord->eTimerMode)
    {
        case(E_ZCL_TIMER_CLICK):
        {
            if(E_ZCL_CBET_TIMER == eEventType)            {
                // always call user callback after 1 sec
                psTimerRecord->pfZCLCallBackFunction(&psZCL_Common->sTimerCallBackEvent);
            }
            break;
        }
        case(E_ZCL_TIMER_CLICK_MS):
        {
            // always call user callback
            psTimerRecord->pfZCLCallBackFunction(&psZCL_Common->sTimerCallBackEvent);
            break;
        }

        case(E_ZCL_TIMER_MOD):
        {
            // make sure it triggers only once
            if((psZCL_Common->u32UTCTime/psTimerRecord->u32UTCTime) && (psZCL_Common->u32UTCTime%psTimerRecord->u32UTCTime==0))
            {
                psTimerRecord->pfZCLCallBackFunction(&psZCL_Common->sTimerCallBackEvent);
            }
            break;
        }

        case(E_ZCL_TIMER_INTERVAL):
        case(E_ZCL_TIMER_VALUE):
        {
            // allow late triggering for late registered times and for timer synching operations
            if(psZCL_Common->u32UTCTime>=psTimerRecord->u32UTCTime)
            {
                psTimerRecord->pfZCLCallBackFunction(&psZCL_Common->sTimerCallBackEvent);
                return(TRUE);
            }
            break;
        }

        default:
        {
            // delete its rubbish
            return(TRUE);
        }
    }

    // no deletion required
    return FALSE;

}

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/


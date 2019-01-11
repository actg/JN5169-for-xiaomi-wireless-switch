/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          app_sleep_handler.c
 *
 * DESCRIPTION:        ZHA Demo : Manages sleep configuration.
 *
 ****************************************************************************
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
 * Copyright NXP B.V. 2014. All rights reserved
 *
 ***************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include <jendefs.h>
#include <string.h>
#include "dbg.h"
#include "os.h"
#include "os_gen.h"
#include "pwrm.h"
#include "AppHardwareApi.h"
#include "pdum_gen.h"
#include "pdm.h"
#include "pdum_gen.h"
#include "app_common.h"
#include "PDM_IDs.h"
#include "zcl_options.h"
#include "app_zbp_utilities.h"
#include "zcl_common.h"
#include "app_sleep_handler.h"
#include "app_zcl_tick_handler.h"
#include "app_zcl_sensor_task.h"
#include "App_OccupancySensor.h"
#include "GenericBoard.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifndef DEBUG_SLEEP_HANDLER
    #define TRACE_SLEEP_HANDLER   FALSE
#else
    #define TRACE_SLEEP_HANDLER   TRUE
#endif

#if HA_SYSTEM_MAX_REPORT_INTERVAL == 0
    #define MAXIMUM_TIME_TO_SLEEP APP_OCCUPANCY_SENSOR_OCCUPIED_TO_UNOCCUPIED_DELAY + 1
#else
    #define MAXIMUM_TIME_TO_SLEEP HA_SYSTEM_MAX_REPORT_INTERVAL
#endif
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
PRIVATE uint8 u8NumberOfTimersTaskTimers(void);
PRIVATE void vScheduleSleep(bool_t bDeepSleep);
PRIVATE void vWakeCallBack(void);
PRIVATE void vStopNonSleepPreventingTimers(void);
PRIVATE void vStartNonSleepPreventingTimers(void);
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
PRIVATE pwrm_tsWakeTimerEvent    sWake;
/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
/****************************************************************************
 *
 * NAME:        vAttemptToSleep
 *
 * DESCRIPTION: Checks to see if any software timers are running that may
 * prevent us from going to sleep. If there is none, if wake timer 0 is
 * running, schedule none deep sleep, if there is schedule deep sleep
 * which is checked if its enabled in vScheduleSleep.
 *
 ****************************************************************************/
PUBLIC void vAttemptToSleep(void)
{
    DBG_vPrintf(TRACE_SLEEP_HANDLER, "\nAPP Sleep Handler: Activity Count = %d", PWRM_u16GetActivityCount());
    DBG_vPrintf(TRACE_SLEEP_HANDLER, "\nAPP Sleep Handler: Task Timers = %d", u8NumberOfTimersTaskTimers());

    /* Have we any software timers running that should prevent us from sleep*/
    if (0 == u8NumberOfTimersTaskTimers())
    {
        /* Stop any background timers that are non sleep preventing*/
        vStopNonSleepPreventingTimers();

        /* Check if Wake timer 0 is running.*/
        if (u8AHI_WakeTimerStatus() & E_AHI_WAKE_TIMER_MASK_0)
        {
            vScheduleSleep(FALSE);
        }
        else
        {
            vScheduleSleep(TRUE);
        }
    }
}


/****************************************************************************/
/***        Local Function                                                     ***/
/****************************************************************************/

/****************************************************************************
 *
 * NAME:        u8NumberOfTimersTaskTimers
 *
 * DESCRIPTION: Checks to see if any timers are running that shouldn't be
 * interrupted by sleeping.
 *
 ****************************************************************************/
PRIVATE uint8 u8NumberOfTimersTaskTimers(void)
{
    uint8 u8NumberOfRunningTimers = 0;

    if (OS_eGetSWTimerStatus(APP_ButtonsScanTimer) == OS_E_SWTIMER_RUNNING)
    {
        DBG_vPrintf(TRACE_SLEEP_HANDLER, "\nAPP Sleep Handler: APP_ButtonsScanTimer");
        u8NumberOfRunningTimers++;
    }

    if (OS_eGetSWTimerStatus(APP_JoinTimer) == OS_E_SWTIMER_RUNNING)
    {
        DBG_vPrintf(TRACE_SLEEP_HANDLER, "\nAPP Sleep Handler: APP_JoinTimer");
        u8NumberOfRunningTimers++;
    }

    if (OS_eGetSWTimerStatus(App_EZFindAndBindTimer) == OS_E_SWTIMER_RUNNING)
    {
        DBG_vPrintf(TRACE_SLEEP_HANDLER, "\nAPP Sleep Handler: App_EZFindAndBindTimer");
        u8NumberOfRunningTimers++;
    }

    if (OS_eGetSWTimerStatus(APP_PollTimer) == OS_E_SWTIMER_RUNNING)
    {
        DBG_vPrintf(TRACE_SLEEP_HANDLER, "\nAPP Sleep Handler: APP_PollTimer");
        u8NumberOfRunningTimers++;
    }

    if (OS_eGetSWTimerStatus(APP_BlinkTimer) == OS_E_SWTIMER_RUNNING)
    {
        DBG_vPrintf(TRACE_SLEEP_HANDLER, "\nAPP Sleep Handler: APP_JoinBlinkTimer");
        u8NumberOfRunningTimers++;
    }

    if (OS_eGetSWTimerStatus(APP_BackOffTimer) == OS_E_SWTIMER_RUNNING)
    {
        DBG_vPrintf(TRACE_SLEEP_HANDLER, "\nAPP Sleep Handler: APP_BackOffTimer");
        u8NumberOfRunningTimers++;
    }

    return u8NumberOfRunningTimers;
}

/****************************************************************************
 *
 * NAME:        vScheduleSleep
 *
 * DESCRIPTION: If we have deep sleep enabled and we attempting to deep sleep
 * then re-initialise the power manager for deep sleep
 *
 ****************************************************************************/
PRIVATE void vScheduleSleep(bool_t bDeepSleep)
{
#ifdef DEEP_SLEEP_ENABLE
    if (bDeepSleep)
    {
        PWRM_vInit(E_AHI_SLEEP_DEEP);
        DBG_vPrintf(TRACE_SLEEP_HANDLER, "\nAPP Sleep Handler: Deep Sleep");
    }
    else
    {
        PWRM_eScheduleActivity(&sWake, (MAXIMUM_TIME_TO_SLEEP - u32GetNumberOfZCLTicksSinceReport())*APP_TICKS_PER_SECOND , vWakeCallBack);
        DBG_vPrintf(TRACE_SLEEP_HANDLER, "\nAPP Sleep Handler: Osc on");
    }
#else
    PWRM_eScheduleActivity(&sWake, (MAXIMUM_TIME_TO_SLEEP - u32GetNumberOfZCLTicksSinceReport())*APP_TICKS_PER_SECOND , vWakeCallBack);
    DBG_vPrintf(TRACE_SLEEP_HANDLER, "\nAPP Sleep Handler: Osc on");
#endif
}

/****************************************************************************
 *
 * NAME:        vStopNonSleepPreventingTimers
 *
 * DESCRIPTION: The timers in this function should not stop us from sleep.
 * Stop the timers to reduce the activity count which will prevent sleep.
 *
 ****************************************************************************/
PRIVATE void vStopNonSleepPreventingTimers()
{
    if (OS_eGetSWTimerStatus(APP_TickTimer) != OS_E_SWTIMER_STOPPED)
        OS_eStopSWTimer(APP_TickTimer);

}

/****************************************************************************
 *
 * NAME:        vStartNonSleepPreventingTimers
 *
 * DESCRIPTION: Start the timers that wont stop us in vAttemptToSleep
 *
 ****************************************************************************/
PRIVATE void vStartNonSleepPreventingTimers(void)
{
    if (OS_eGetSWTimerStatus(APP_TickTimer) != OS_E_SWTIMER_RUNNING)
        OS_eStartSWTimer(APP_TickTimer, ZCL_TICK_TIME, NULL);
}

/****************************************************************************
 *
 * NAME: vWakeCallBack
 *
 * DESCRIPTION:
 * Wake up call back called upon wake up by the schedule activity event.
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vWakeCallBack(void)
{
    DBG_vPrintf(TRACE_SLEEP_HANDLER, "\nAPP Sleep Handler: vWakeCallBack\n");

#ifndef DEEP_SLEEP_ENABLE
    vUpdateZCLTickSinceSleep();
#endif

    vGenericLEDSetOutput(1, sSensor.sOccupancySensingServerCluster.u8Occupancy);

    /*Start the APP_TickTimer to continue the ZCL tasks */
    vStartNonSleepPreventingTimers();
}


/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

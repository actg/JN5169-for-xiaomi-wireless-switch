/*****************************************************************************
 *
 * MODULE:          JN-AN-1189
 *
 * COMPONENT:       app_PIR_pwm_events.c
 *
 * DESCRIPTION:     ZHA Demo: Driver behaviour for the PWM PIR sensor
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
 * Copyright NXP B.V. 2013. All rights reserved
 *
 ***************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include "dbg.h"
#include "app_events.h"
#include "zha_sensor_node.h"
#include "haEzFindAndBind.h"
#include "app_sensor_state_machine.h"
#include "os_gen.h"
#include "App_OccupancySensor.h"
#include "app_sleep_handler.h"
#include "app_PIR_events.h"
#include "app_reporting.h"
#include "app_occupancy_buttons.h"
#include "app_zbp_utilities.h"
#include "GenericBoard.h"
#include "AppHardwareApi.h"
#include "pwrm.h"
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifdef DEBUG_PIR_EVENTS
    #define TRACE_PIR_EVENTS   TRUE
#else
    #define TRACE_PIR_EVENTS  FALSE
#endif
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
PRIVATE uint32 u32GetRemainingOccupiedToUnoccupedTime(void);
PRIVATE void vHandlePIRPWMUnoccupiedToOccupiedTimerExpired(void);
PRIVATE void vHandlePIRPWMOccupiedToUnoccupiedTimerExpired(void);
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
PRIVATE uint32 u32NumberOfUnoccupiedToOccupiedTriggers = 0;
PRIVATE uint32 u32OccupiedToUnoccupedRemainingTime = 0;
PRIVATE teRunningTimer u8RunningTimerType = E_APP_TIMER_NONE;
PRIVATE bool_t bNewJoin = FALSE;
/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
/****************************************************************************
 *
 * NAME: vHandlePIRPWMFallingEdgeEvent
 *
 * DESCRIPTION:
 * We have received a falling edge event. Due to this being a PWM Sensor
 * we must receive a defined number of falling and rising edges before occupancy.
 * This function starts a timer (if its the first falling edge). If we are
 * occupied, we need to record how many ticks are left until we are deemed
 * as unoccupied. This is in case we don't hit the threshold we need to
 * restart the time where it previously was minus the time it took to check if
 * we were occupied.
 *
 ****************************************************************************/
PUBLIC void vHandleFallingEdgeEvent(void)
{
    DBG_vPrintf(TRACE_PIR_EVENTS,"\nAPP Occupancy Event: PWM Falling Edge");
    if (sSensor.sOccupancySensingServerCluster.u8Occupancy == 0x00)
    {
        /* If we are unoccupied we know the Occupied to Unoccupied timer isn't running*/
        if (0 == u32NumberOfUnoccupiedToOccupiedTriggers)
        {
            u8RunningTimerType = E_APP_TIMER_UNOCCUPIED_TO_OCCUPIED;
            vStartWakeTimer(sSensor.sOccupancySensingServerCluster.u8PIRUnoccupiedToOccupiedDelay);
        }
    }
    else
    {
        /* We are occupied so the Occupied to unoccupied timer is running*/
        if (0 == u32NumberOfUnoccupiedToOccupiedTriggers)
        {
            /* We need to stop the occupied to unoccupied timer and get how many ticks
             were are left. This is so if we don't hit the occupied threshold we can
             start the timer where we left off.
             */

            u32OccupiedToUnoccupedRemainingTime = u32GetRemainingOccupiedToUnoccupedTime();

            if (u32OccupiedToUnoccupedRemainingTime < sSensor.sOccupancySensingServerCluster.u8PIRUnoccupiedToOccupiedDelay)
            {
                /* this is a guard to make sure when subtracting the time left with the delay time
                we dont accidentally subtract "below" 0*/
                u32OccupiedToUnoccupedRemainingTime = sSensor.sOccupancySensingServerCluster.u8PIRUnoccupiedToOccupiedDelay;
            }
            u8RunningTimerType = E_APP_TIMER_UNOCCUPIED_TO_OCCUPIED;
            vStartWakeTimer(sSensor.sOccupancySensingServerCluster.u8PIRUnoccupiedToOccupiedDelay);
        }
    }
}

/****************************************************************************
 *
 * NAME: vHandlePIRPWMRisingEdgeEvent
 *
 * DESCRIPTION:
 * Increment the number of occupied triggers and attempt to sleep.
 *
 ****************************************************************************/
PUBLIC void vHandleRisingEdgeEvent(void)
{
    DBG_vPrintf(TRACE_PIR_EVENTS,"\nAPP Occupancy Event: PWM Rising Edge");

    /* Only increment the occupied trigger after we get a complete falling and rising edge*/
    u32NumberOfUnoccupiedToOccupiedTriggers++;
    vAttemptToSleep();
}

/****************************************************************************
 *
 * NAME: vHandlePIRPWMWakeTimerExpired
 *
 * DESCRIPTION:
 * Figure out which Timer type is running and call the related function.
 *
 ****************************************************************************/
PUBLIC void vHandleWakeTimeoutEvent(void)
{
    switch (u8RunningTimerType)
    {
        case E_APP_TIMER_OCCUPIED_TO_UNOCCUPIED:
            DBG_vPrintf(TRACE_PIR_EVENTS,"\nAPP Occupancy Event: E_APP_TIMER_OCCUPIED_TO_UNOCCUPIED");
            vHandlePIRPWMOccupiedToUnoccupiedTimerExpired();
            break;
        case E_APP_TIMER_UNOCCUPIED_TO_OCCUPIED:
            DBG_vPrintf(TRACE_PIR_EVENTS,"\nAPP Occupancy Event: E_APP_TIMER_UNOCCUPIED_TO_OCCUPIED");
            vHandlePIRPWMUnoccupiedToOccupiedTimerExpired();
            break;
        default:
            vAttemptToSleep();
            break;
    }
}

/****************************************************************************
 *
 * NAME: vHandlePIRPWMNewJoinEvent
 *
 * DESCRIPTION:
 * This method is called when we have just joined a new network, rejoined
 * a network or we have just come out of find and bind. If we are occupied,
 * send a report out, if we are unoccupied, just start the occupied to unoccupied
 * delay timer so we aren't potentially turning lights off prematurely.
 *
 ****************************************************************************/
PUBLIC void vHandleNewJoinEvent(void)
{
    switch (u8RunningTimerType)
    {
        case E_APP_TIMER_NONE:
        case E_APP_TIMER_OCCUPIED_TO_UNOCCUPIED:
            if (sSensor.sOccupancySensingServerCluster.u8Occupancy == E_CLD_OS_OCCUPIED)
            {
                vSendImmediateReport();
            }
            DBG_vPrintf(TRACE_PIR_EVENTS,"\nAPP Occupancy Event: Starting Occupied to Unoccupied timer");
            u8RunningTimerType = E_APP_TIMER_OCCUPIED_TO_UNOCCUPIED;
            vStartWakeTimer(sSensor.sOccupancySensingServerCluster.u16PIROccupiedToUnoccupiedDelay);
            break;
        case E_APP_TIMER_UNOCCUPIED_TO_OCCUPIED:
            bNewJoin = TRUE;
            break;

    }
}

/****************************************************************************
 *
 * NAME: vHandlePIRPWMUnoccupiedToOccupiedTimerExpired
 *
 * DESCRIPTION:
 * When the timer has expired for processing occupancy PWM triggers, if we
 * got enough PWM triggers, send an occupied report, if we didn't and we
 * are occupied, restart the occupied to unoccupied timer from where it
 * left off minus the amount of time it took to check if we were occupied
 * again. If we are not occupied, do nothing.
 *
 ****************************************************************************/
PRIVATE void vHandlePIRPWMUnoccupiedToOccupiedTimerExpired(void)
{
    u8RunningTimerType = E_APP_TIMER_NONE;

    if (u32NumberOfUnoccupiedToOccupiedTriggers >= sSensor.sOccupancySensingServerCluster.u8PIRUnoccupiedToOccupiedThreshold)
    {
        if (sSensor.sOccupancySensingServerCluster.u8Occupancy == 0x00)
        {
            /* We werent occupied before so send the report and change the state.*/
            DBG_vPrintf(TRACE_PIR_EVENTS,"\nAPP Occupancy Event: Occupied");
            sSensor.sOccupancySensingServerCluster.u8Occupancy = E_CLD_OS_OCCUPIED;
            vGenericLEDSetOutput(1, sSensor.sOccupancySensingServerCluster.u8Occupancy);
            vSendImmediateReport();
        }
        u8RunningTimerType = E_APP_TIMER_OCCUPIED_TO_UNOCCUPIED;
        vStartWakeTimer(sSensor.sOccupancySensingServerCluster.u16PIROccupiedToUnoccupiedDelay);

    }
    else /* We didnt get the number of PWM waves we require*/
    {
        if (bNewJoin)
        {
            u8RunningTimerType = E_APP_TIMER_OCCUPIED_TO_UNOCCUPIED;
            vStartWakeTimer(sSensor.sOccupancySensingServerCluster.u16PIROccupiedToUnoccupiedDelay);
        }
        else
        {
            if (sSensor.sOccupancySensingServerCluster.u8Occupancy == E_CLD_OS_OCCUPIED)
            {
                /* This wasn't an occupied event so we need to restart the timer from where
                 it was last also taking into account the amount of time we delayed processing
                 the unoccupied to occupied delay
                */
                u8RunningTimerType = E_APP_TIMER_OCCUPIED_TO_UNOCCUPIED;
                vStartWakeTimer(u32OccupiedToUnoccupedRemainingTime - sSensor.sOccupancySensingServerCluster.u8PIRUnoccupiedToOccupiedDelay);
            }
        }
    }
    bNewJoin = FALSE;
    u32NumberOfUnoccupiedToOccupiedTriggers = 0;
    vAttemptToSleep();
}

/****************************************************************************
 *
 * NAME: vHandlePIRPWMOccupiedToUnoccupiedTimerExpired
 *
 * DESCRIPTION:
 * We haven't received an occupied event within the specified occupied to
 * unoccupied time so go unoccupied and send a report.
 *
 ****************************************************************************/
PRIVATE void vHandlePIRPWMOccupiedToUnoccupiedTimerExpired(void)
{
    sSensor.sOccupancySensingServerCluster.u8Occupancy = 0x0;
    vGenericLEDSetOutput(1, sSensor.sOccupancySensingServerCluster.u8Occupancy);
    vSendImmediateReport();
    vAttemptToSleep();
}

/****************************************************************************
 *
 * NAME: u32GetRemainingOccupiedToUnoccupedTime
 *
 * DESCRIPTION:
 * Get the amount of ticks remaining on the occupied to unoccupied time delay.
 *
 ****************************************************************************/
PRIVATE uint32 u32GetRemainingOccupiedToUnoccupedTime(void)
{
    uint32 u64Ticks = 0;

    u64Ticks = u64AHI_WakeTimerReadLarge(E_AHI_WAKE_TIMER_0);
    vAHI_WakeTimerStop(E_AHI_WAKE_TIMER_0);
    vAHI_WakeTimerEnable(E_AHI_WAKE_TIMER_0, FALSE);

    u64Ticks =  u64Ticks / 10000 * u32AHI_WakeTimerCalibrate();

    DBG_vPrintf(TRACE_PIR_EVENTS,"\nAPP Occupancy Event: Occupied to Unoccuped Time remaining = %d", u64Ticks / 32600);
    return (u64Ticks / APP_TICKS_PER_SECOND);
}
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

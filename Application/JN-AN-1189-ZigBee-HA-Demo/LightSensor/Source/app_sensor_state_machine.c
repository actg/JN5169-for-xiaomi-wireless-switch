/*****************************************************************************
 *
 * MODULE:          JN-AN-1189
 *
 * COMPONENT:       app_sensor_state_machine.c
 *
 * DESCRIPTION:     ZHA Demo: Processes all stack events depending on it's state
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
#include "app_sensor_state_machine.h"
#include "app_common.h"
#include "os_gen.h"
#include "pwrm.h"
#include "haEzFindAndBind.h"
#include "App_LightSensor.h"
#include "TSL2550.h"
#include "app_nwk_event_handler.h"
#include "AppHardwareApi.h"
#include "app_zbp_utilities.h"
#include "pdum_gen.h"
#include "pdm.h"
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifdef DEBUG_SENSOR_STATE
    #define TRACE_SENSOR_STATE   TRUE
#else
    #define TRACE_SENSOR_STATE   FALSE
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

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
/****************************************************************************
 *
 * NAME: vAppHandleRunning
 *
 * DESCRIPTION:
 * Is called to handle stack events when we are currently in the network
 *
 ****************************************************************************/
PUBLIC void vAppHandleRunning(ZPS_tsAfEvent sStackEvent)
{
    DBG_vPrintf(TRACE_SENSOR_STATE, "\nAPP State Event: Running");

    switch(sStackEvent.eType)
    {
        case ZPS_EVENT_NWK_FAILED_TO_JOIN:
            vHandleFailedRejoin();
            break;
        case ZPS_EVENT_NWK_JOINED_AS_ENDDEVICE:
            vHandleNetworkJoinEndDevice();
            break;
        case ZPS_EVENT_NWK_LEAVE_INDICATION:
            vHandleNetworkLeave(sStackEvent);
            break;
        case ZPS_EVENT_NWK_POLL_CONFIRM:
            vHandlePollResponse(sStackEvent);
            break;
        default:
            break;
    }

    vEZ_EZModeNWKFindAndBindHandler(&sStackEvent);
}

/****************************************************************************
 *
 * NAME: vAppHandleStartup
 *
 * DESCRIPTION:
 * Is called to handle stack events when we are currently not in the network
 *
 ****************************************************************************/
PUBLIC void vAppHandleStartup(ZPS_tsAfEvent sStackEvent, teEZ_JoinAction eJoinState)
{
    vHandleNetworkJoinAndRejoin(&sStackEvent,eJoinState);
}


/****************************************************************************
 *
 * NAME: vStartWakeTimer
 *
 * DESCRIPTION:
 * Starts wake timer 0
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vStartWakeTimer(uint16 u16Tick)
{
      uint32 u32Ticks = 0;
      uint64 u64AdjustedTicks = 0;
      /* Disable Wake timer interrupt to use for calibration */
      vAHI_WakeTimerEnable(E_AHI_WAKE_TIMER_0, FALSE);
      uint32 u32CalibrationValue = u32AHI_WakeTimerCalibrate();
      (void)u8AHI_WakeTimerFiredStatus();
      /* Enable timer to use for sleeping */
      vAHI_WakeTimerEnable(E_AHI_WAKE_TIMER_0, TRUE);
      u64AdjustedTicks = u16Tick * APP_TICKS_PER_SECOND ;
      u64AdjustedTicks = u64AdjustedTicks * 10000 / u32CalibrationValue;
      if (u64AdjustedTicks > 0xffffffff) {
      /* overflowed os limit to max uint32*/
          u32Ticks = 0xfffffff;
      } else {
          u32Ticks = (uint32)u64AdjustedTicks;
      }
      DBG_vPrintf(TRACE_SENSOR_STATE, "\nAPP Sensor State: WakeTimer : u32CalibrationValue = %d u32Ticks %08x", u32CalibrationValue,u32Ticks);
      vAHI_WakeTimerStop(E_AHI_WAKE_TIMER_0);
      vAHI_WakeTimerStart(E_AHI_WAKE_TIMER_0, u32Ticks);
}
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

/*****************************************************************************
 *
 * MODULE:             Application
 *
 * COMPONENT:          app_timer_driver.c
 *
 * AUTHOR:             MRW
 *
 * DESCRIPTION:        OS hardware counter driver for tick timer
*/
/****************************************************************************
*
* This software is owned by NXP B.V. and/or its supplier and is protected
* under applicable copyright laws. All rights are reserved. We grant You,
* and any third parties, a license to use this software solely and
* exclusively on NXP products [NXP Microcontrollers such as JN5148, JN5142, JN5139]. 
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

* Copyright NXP B.V. 2012. All rights reserved
*
***************************************************************************/
/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#include <jendefs.h>
#include "os.h"
#include "os_gen.h"
#include "pwrm.h"
#include "AppHardwareApi.h"

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
asm("    .globl APP_TIMER_Version_1v0");
asm("APP_TIMER_Version_1v0:");
/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

PRIVATE volatile uint32 s_u32CompareTime;
PRIVATE volatile uint32 s_u32LastExpiredTime;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

/****************************************************************************
 *
 * NAME: APP_cbEnableTickTimer
 *
 * DESCRIPTION:
 * Callback function to enable the tick timer
 *
 * RETURNS:
 * Nothing
 *
 ****************************************************************************/
OS_HWCOUNTER_ENABLE_CALLBACK(APP_cbEnableTickTimer)
{
    vAHI_TickTimerIntEnable(FALSE);
    vAHI_TickTimerConfigure(E_AHI_TICK_TIMER_CONT);
    s_u32LastExpiredTime = s_u32CompareTime = u32AHI_TickTimerRead();
    PWRM_eStartActivity();
    vAHI_TickTimerIntPendClr();
    vAHI_TickTimerIntEnable(TRUE);
}

/****************************************************************************
 *
 * NAME: APP_cbDisableTickTimer
 *
 * DESCRIPTION:
 * Callback to disable the tick timer
 *
 * RETURNS:
 * Nothing
 *
 ****************************************************************************/
OS_HWCOUNTER_DISABLE_CALLBACK(APP_cbDisableTickTimer)
{
    vAHI_TickTimerIntEnable(FALSE);
    vAHI_TickTimerConfigure(E_AHI_TICK_TIMER_DISABLE);

    PWRM_eFinishActivity();
}

/****************************************************************************
 *
 * NAME: APP_cbGetTickTimer
 *
 * DESCRIPTION:
 * Callback to read the current value of the tick timer counter
 *
 * RETURNS:
 * Tick timer counter value
 *
 ****************************************************************************/
OS_HWCOUNTER_GET_CALLBACK(APP_cbGetTickTimer)
{
    return u32AHI_TickTimerRead();
}

/****************************************************************************
 *
 * NAME: SetTickCompare
 *
 * DESCRIPTION:
 * Set the tick timer compare register
 *
 * RETURNS:
 * True if the compare register value is in the future
 *
 ****************************************************************************/
OS_HWCOUNTER_SET_CALLBACK(APP_cbSetTickTimerCompare, u32CompareValue)
{
    /* calculations are relative to the last compare register value to account for counter wrap around */
    int32 s32NextDelta = u32CompareValue - s_u32LastExpiredTime;
    uint32 u32CurDelta = u32AHI_TickTimerRead() - s_u32LastExpiredTime;

    /*
     * Race condition here. If the tick counter has incremented passed the compare point
     * in the time between reading it and loading the compare register the interrupt will be missed.
     * Increase the delta to take account of this time. To minimise this time, the number of
     * instructions between the register read and write to the interval register should be minimised.
     */
    u32CurDelta += 100;

    if (s32NextDelta > 0 && u32CurDelta < s32NextDelta)
    {
        vAHI_TickTimerInterval(u32CompareValue);
        s_u32CompareTime = u32CompareValue;
        return TRUE;
    }

    return FALSE;
}

/****************************************************************************
 *
 * NAME: TickInterrupt
 *
 * DESCRIPTION:
 * Interrupt service routine which is invoked by the tick timer when the
 * counter value matches the compare register value
 *
 ****************************************************************************/
OS_ISR(APP_isrTickTimer)
{
    vAHI_TickTimerIntPendClr();

    /*
     * compare register is only 28bits wide so make sure the upper 4bits match
     * the set compare point
     */
    uint32 u32Delta = u32AHI_TickTimerRead() - s_u32CompareTime;
    if (0 == (u32Delta >> 28))
    {
        uint32 u32Temp = s_u32CompareTime;
        OS_eExpireSWTimers(APP_cntrTickTimer);
        s_u32LastExpiredTime = u32Temp;
    }
}

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

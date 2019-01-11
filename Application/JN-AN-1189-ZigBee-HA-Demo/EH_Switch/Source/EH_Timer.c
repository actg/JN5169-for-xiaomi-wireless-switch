
/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          EH_Timer.c
 *
 * AUTHOR:             Rajeena
 *
 * DESCRIPTION:        ZigBee EH Timer implementation
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
 * Copyright NXP B.V. 2012. All rights reserved
 *
 ***************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include "jendefs.h"
#include "AppHardwareApi.h"
#include "PeripheralRegs.h"
#include "string.h"
#include <dbg.h>
#include <dbg_uart.h>

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifndef DBG_DEVICE_SWITCH
#define DBG_DEVICE_SWITCH FALSE
#endif
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
/****************************************************************************/
/***        Exported Variables                                               ***/
/****************************************************************************/


/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

static volatile uint64 u64TimerIsrTicks = 0;
static uint8 u8TimerUsageCount = 0;
/****************************************************************************/
/***        Local Function Prototypes                                               ***/
/****************************************************************************/
void vEH_TickTimerCallback(uint32 u32DeviceId, uint32 u32ItemBitmap);
/****************************************************************************/
/***        Public Functions                                              ***/
/****************************************************************************/
/****************************************************************************
 *
 * NAME: u32EH_StartTimer
 *
 * DESCRIPTION:
 * Starts Tick timer
 *
 * RETURNS:
 * Returns the current time
 *
 ****************************************************************************/
uint32 u32EH_StartTimer(void)
{

    uint32  u32StartTime = 0;

    /* Enable Timer if already not enabled */
    if(u8TimerUsageCount == 0)
    {

         vAHI_TickTimerConfigure(E_AHI_TICK_TIMER_CONT);
         vAHI_TickTimerRegisterCallback(vEH_TickTimerCallback);

         u64TimerIsrTicks = 0x00;
    }
    u8TimerUsageCount++;


    vAHI_TickTimerIntEnable(FALSE);
    u32StartTime = u32AHI_TickTimerRead();

    u32StartTime += u64TimerIsrTicks << 28;
    vAHI_TickTimerIntPendClr();
    vAHI_TickTimerIntEnable(TRUE);


    return u32StartTime;
}

/****************************************************************************
 *
 * NAME: bEH_IsTimeElapsedInMicrosSec
 *
 * DESCRIPTION:
 * Checks whether given time is elapsed
 *
 * RETURNS:
 * TRUE: The given time elapsed
 * FALSE: The given time not elapsed
 *
 ****************************************************************************/

bool bEH_IsTimeElapsedInMicrosSec(uint32 u32Time, uint32 u32StartTime)
{

    uint32 u32CurrentTime;
    uint32 u32TimeElapsed;

    u32CurrentTime =  u32AHI_TickTimerRead();
    u32CurrentTime += u64TimerIsrTicks << 28;

    u32TimeElapsed = u32CurrentTime - u32StartTime;


    if((uint32)u32Time < (uint32)u32TimeElapsed )
    {
        return TRUE;

    }
    else
    {
        return FALSE;
    }
}
/****************************************************************************
 *
 * NAME: vEH_StopTimer
 *
 * DESCRIPTION:
 * Stops tick timer
 *
 * RETURNS:
 * void
 ****************************************************************************/
void vEH_StopTimer(void)
{
    /* Decrement the usage count */
    if(u8TimerUsageCount > 0)
    {
        u8TimerUsageCount--;
    }

    /* stop the timer if no body is using it */
    if(u8TimerUsageCount == 0)
    {

        vAHI_TickTimerIntEnable(FALSE);
        vAHI_TickTimerConfigure(E_AHI_TICK_TIMER_DISABLE);
        DBG_vPrintf(DBG_DEVICE_SWITCH, "\n Stopping Timer \n" );

    }

}

/****************************************************************************/
/***        Local Functions                                              ***/
/****************************************************************************/
/****************************************************************************
 *
 * NAME: vEH_TickTimerCallback
 *
 * DESCRIPTION:
 * Timer Interrupt call back handler
 *
 * RETURNS:
 * void
 ****************************************************************************/
void vEH_TickTimerCallback(uint32 u32DeviceId, uint32 u32ItemBitmap)
{

     if(E_AHI_DEVICE_TICK_TIMER == u32DeviceId)
     {
         u64TimerIsrTicks++;

     }
}



/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          app_occupancy_buttons.c
 *
 * DESCRIPTION:        DK4 (DR1175/DR1199) Button Press detection (Implementation)
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
#include <jendefs.h>
#include "os.h"
#include "os_gen.h"
#include "DBG.h"
#include "AppHardwareApi.h"
#include "app_events.h"
#include "app_timer_driver.h"
#include "pwrm.h"
#include "app_light_sensor_buttons.h"
#include "app_sensor_state_machine.h"
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifndef DEBUG_APP_BUTTON
    #define TRACE_APP_BUTTON               FALSE
#else
    #define TRACE_APP_BUTTON               TRUE
#endif

#define WAKE_FROM_DEEP_SLEEP     (1<<11)
#define DIO_STATE_NVM_LOCATION     0

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

#if (defined BUTTON_MAP_DR1199)
    PRIVATE uint8 s_u8ButtonDebounce[APP_BUTTONS_NUM] = { 0xff,0xff,0xff,0xff,0xff };
    PRIVATE uint8 s_u8DebounceChecks[APP_BUTTONS_NUM] = { 0,0,0,0,0 };
    PRIVATE uint32 u32PreviousDioState = 0;
    PRIVATE const uint32 s_u32ButtonDIOLine[APP_BUTTONS_NUM] =
    {
        1<<APP_BUTTONS_BUTTON_1,
        1<<APP_BUTTONS_BUTTON_SW4,
        1<<APP_BUTTONS_BUTTON_SW3,
        1<<APP_BUTTONS_BUTTON_SW2,
        1<<APP_BUTTONS_BUTTON_SW1

    };
#else
    PRIVATE uint8 s_u8ButtonDebounce[APP_BUTTONS_NUM] = { 0xff};
    PRIVATE uint8 s_u8DebounceChecks[APP_BUTTONS_NUM] = {0};
    PRIVATE const uint32 s_u32ButtonDIOLine[APP_BUTTONS_NUM] =
    {
        1<<APP_BUTTONS_BUTTON_1
    };
    PRIVATE uint32 u32PreviousDioState = 0;
#endif

PRIVATE uint32 u32DioInterrupts = 0;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
/****************************************************************************
 *
 * NAME: APP_bButtonInitialise
 *
 * DESCRIPTION:
 * Button Initialization
 *
 * PARAMETER: void
 *
 * RETURNS: bool
 *
 ****************************************************************************/
PUBLIC void APP_bButtonInitialise(void)
{
    /* Set DIO lines to inputs with buttons connected */
    vAHI_DioSetDirection(APP_BUTTONS_DIO_MASK, 0);

    /* Turn on pull-ups for DIO lines with buttons connected */
    vAHI_DioSetPullup(APP_BUTTONS_DIO_MASK, 0);

    if (FALSE == (u16AHI_PowerStatus() & WAKE_FROM_DEEP_SLEEP))
    {
        /* Set the edge detection for falling edges */
        vAHI_DioWakeEdge(0, APP_BUTTONS_DIO_MASK);
    }
    else
    {
        u32PreviousDioState = u32AHI_ReadNVData(DIO_STATE_NVM_LOCATION);
        DBG_vPrintf(TRACE_APP_BUTTON, "\nAPP Button: Previous Dio State = %d", u32PreviousDioState);
    }

    /* Enable interrupts to occur on selected edge */
    vAHI_DioWakeEnable(APP_BUTTONS_DIO_MASK, 0);
}

/****************************************************************************
 *
 * NAME: vISR_SystemController
 *
 * DESCRIPTION:
 * ISR called on system controller interrupt. This may be from the synchronous driver
 * (if used) or user pressing a button the the DK4 build
 *
 * PARAMETER:
 *
 * RETURNS:
 *
 ****************************************************************************/
#ifndef RTOS
OS_ISR(vISR_SystemController)
{

    ZPS_eAplZdoPoll();

    /* clear pending DIO changed bits by reading register */
    uint8 u8WakeInt = u8AHI_WakeTimerFiredStatus();
    u32DioInterrupts|=u32AHI_DioInterruptStatus();

    if (u8WakeInt & E_AHI_WAKE_TIMER_MASK_0)
    {
        APP_tsEvent sButtonEvent;

        /* wake timer interrupt got us here */
        DBG_vPrintf(TRACE_APP_BUTTON, "\nAPP Button: Wake Timer 0 Interrupt");
        vAHI_WakeTimerStop(E_AHI_WAKE_TIMER_0);

        /* Post a message to the stack so we aren't handling events
         * in interrupt context
         */
        sButtonEvent.eType = APP_E_EVENT_WAKE_TIMER;
        OS_ePostMessage(APP_msgEvents, &sButtonEvent);
    }

    DBG_vPrintf(TRACE_APP_BUTTON, "\nAPP Button: In vISR_SystemController");

    if( u32DioInterrupts & APP_BUTTONS_DIO_MASK )
    {
        DBG_vPrintf(TRACE_APP_BUTTON, "\nAPP Button: Dio Interrupt");
        /* disable edge detection until scan complete */
        vAHI_DioInterruptEnable(0, u32DioInterrupts & APP_BUTTONS_DIO_MASK);

        OS_eActivateTask(APP_ButtonsScanTask);

    }

    if (u8WakeInt & E_AHI_WAKE_TIMER_MASK_1)
    {
        APP_tsEvent sButtonEvent;

        /* wake timer interrupt got us here */
        DBG_vPrintf(TRACE_APP_BUTTON, "\nAPP Button: Wake Timer 1 Interrupt");
        PWRM_vWakeInterruptCallback();

        /* Post a message to the stack so we aren't handling events
         * in interrupt context
         */

        sButtonEvent.eType = APP_E_EVENT_PERIODIC_REPORT;
        OS_ePostMessage(APP_msgEvents, &sButtonEvent);
    }

#ifdef CHECK_VBO_FOR_OTA_ACTIVITY
    uint32 u32BOStatus = u32AHI_BrownOutPoll();
    vCbSystemControllerOTAVoltageCheck(E_AHI_DEVICE_SYSCTRL,u32BOStatus);
#endif
}

/****************************************************************************
 *
 * NAME: vISR_Timer2
 *
 * DESCRIPTION:
 * Stub function to allow DK4 'bulbs' to build
 *
 * PARAMETER:
 *
 * RETURNS:
 *
 ****************************************************************************/
OS_ISR(vISR_Timer2){}

#endif

/****************************************************************************
 *
 * NAME: APP_ButtonsScanTask
 *
 * DESCRIPTION:
 * An Sensor specific Debounce task. In the real world this maybe
 * removed as the digital input will be driven from a sensor.
 *
 * PARAMETER:
 *
 * RETURNS:
 *
 ****************************************************************************/
OS_TASK(APP_ButtonsScanTask)
{
    uint8 u8Count;
    uint32 u32DioInput = 0;
    bool_t bButtonEventFound = FALSE;

    /* Remove the Interrupt flag*/
    (void)u32AHI_DioInterruptStatus();
    u32DioInput = u32AHI_DioReadInput();

    DBG_vPrintf(TRACE_APP_BUTTON, "\nAPP Button: APP_ButtonsScanTask");

    /* Loop over all buttons to check there Dio states*/
    for (u8Count = 0;u8Count < APP_BUTTONS_NUM; u8Count++)
    {
        /* Check if we have an interrupt for this Dio*/
        if (u32DioInterrupts & s_u32ButtonDIOLine[u8Count])
        {
            /* Increment the amount of debounce checks we have performed*/
            s_u8DebounceChecks[u8Count]++;

            /* Shift the previous debounce checks and add the new debounce reading*/
            s_u8ButtonDebounce[u8Count] <<= 1;
            s_u8ButtonDebounce[u8Count] |= (u32DioInput & s_u32ButtonDIOLine[u8Count])?TRUE:FALSE;

            /* Check if we have performed 8 debounce checks*/
            if (s_u8DebounceChecks[u8Count] == 8)
            {
                /* Comes into this if statement if the previous button state
                 * was a falling edge and our new state is rising.
                 * We don't want to process the same interrupt twice
                 */

                if (s_u8ButtonDebounce[u8Count] == 0xFF && (u32PreviousDioState & s_u32ButtonDIOLine[u8Count]))
                {
                    APP_tsEvent sButtonEvent;
                    sButtonEvent.eType = APP_E_EVENT_BUTTON_UP;
                    sButtonEvent.uEvent.sButton.u8Button = u8Count;
                    sButtonEvent.uEvent.sButton.u32DIOState=u32DioInput;

                    /* Invert the previous state and record we are sending an event*/
                    u32PreviousDioState &= ~(s_u32ButtonDIOLine[u8Count]);
                    bButtonEventFound = TRUE;
                    DBG_vPrintf(TRACE_APP_BUTTON, "\nAPP Button: Button UP=%d, Dio State = %d", u8Count, u32PreviousDioState);

                    /* Post a message to the stack*/
                    OS_ePostMessage(APP_msgEvents, &sButtonEvent);

                }
                /* Comes into this if statement if the previous button state
                 * was a rising edge and our new state is falling.
                 * We don't want to process the same interrupt twice
                 */
                else if (s_u8ButtonDebounce[u8Count] == 0x0 && (0 == (u32PreviousDioState & s_u32ButtonDIOLine[u8Count])))
                {
                    APP_tsEvent sButtonEvent;
                    sButtonEvent.eType = APP_E_EVENT_BUTTON_DOWN;
                    sButtonEvent.uEvent.sButton.u8Button = u8Count;
                    sButtonEvent.uEvent.sButton.u32DIOState=u32DioInput;

                    /* Invert the previous state and record we are sending an event*/
                    u32PreviousDioState |= s_u32ButtonDIOLine[u8Count];
                    bButtonEventFound = TRUE;

                    DBG_vPrintf(TRACE_APP_BUTTON, "\nAPP Button: Button DN=%d, Dio State = %d", u8Count, u32PreviousDioState);

                    /* Post a message to the stack*/
                    OS_ePostMessage(APP_msgEvents, &sButtonEvent);

                }
                /* We need to check if we had a bad interrupt*/
                else if(s_u8ButtonDebounce[u8Count] > 0x0 && s_u8ButtonDebounce[u8Count] < 0xFF)
                {
                    APP_tsEvent sButtonEvent;
                    sButtonEvent.eType = APP_E_EVENT_FAILED_DEBOUNCE;

                    /* Record we are sending an event*/
                    bButtonEventFound = TRUE;

                    /* Post a message to the stack*/
                    OS_ePostMessage(APP_msgEvents, &sButtonEvent);
                    DBG_vPrintf(TRACE_APP_BUTTON, "\nAPP Button: Bad Debounce %d", u8Count);
                }

                /* Check what the previous state was and modify the wake edge we expect*/
                if (u32PreviousDioState & s_u32ButtonDIOLine[u8Count])
                {
                    vAHI_DioWakeEdge(s_u32ButtonDIOLine[u8Count], 0);
                }
                else
                {
                    vAHI_DioWakeEdge(0, s_u32ButtonDIOLine[u8Count]);
                }

                /* Remove the interrupt flag, enable the interrupt and restart the debounce counter*/
                u32DioInterrupts &= ~(s_u32ButtonDIOLine[u8Count]);
                vAHI_DioWakeEnable(s_u32ButtonDIOLine[u8Count], 0);
                s_u8DebounceChecks[u8Count] = 0;
            }
        }
        else
        {
            /* Enable the interrupt if we haven't got an interrupt for this Dio*/
            vAHI_DioWakeEnable(s_u32ButtonDIOLine[u8Count], 0);
        }
    }

    /* Check if we still have debounce checks remaining*/
    if (u32DioInterrupts & APP_BUTTONS_DIO_MASK)
    {
        DBG_vPrintf(TRACE_APP_BUTTON, "\nAPP Button: Debounce Timer Continued");
        OS_eStartSWTimer(APP_ButtonsScanTimer, APP_TIME_MS(5), NULL);
        DBG_vPrintf(TRACE_APP_BUTTON, "\nAPP Button: Timer Status = %d", OS_eGetSWTimerStatus(APP_ButtonsScanTimer));
    }
    else
    {

        if (FALSE == bButtonEventFound)
        {
            /* We didn't find a debounce event so we need to post a no change event*/
            APP_tsEvent sButtonEvent;
            sButtonEvent.eType = APP_E_EVENT_NO_BUTTON_CHANGE;

            OS_ePostMessage(APP_msgEvents, &sButtonEvent);
            DBG_vPrintf(TRACE_APP_BUTTON, "\nAPP Button: No Button Change");
        }

        /* Stop the debounce timer as we have finished*/
        DBG_vPrintf(TRACE_APP_BUTTON, "\nAPP Button: Debounce Timer Stopped");
        if(OS_eGetSWTimerStatus(APP_ButtonsScanTimer) != OS_E_SWTIMER_STOPPED)
            OS_eStopSWTimer(APP_ButtonsScanTimer);
    }
}

/****************************************************************************
 *
 * NAME: vActionOnButtonActivationAfterDeepSleep
 *
 * DESCRIPTION:
 * When we wake up, we have restarted so we need to manually check to see
 * what Dio woke us. Start the ButtonScanTask and disable wake interrupts
 *
 ****************************************************************************/
PUBLIC void vActionOnButtonActivationAfterDeepSleep(void)
{
    DBG_vPrintf(TRACE_APP_BUTTON, "\nAPP Button: Interrupt Status = %d", u32AHI_DioInterruptStatus());
    u32DioInterrupts |= APP_BUTTONS_DIO_MASK;
    vAHI_DioWakeEnable(0, u32DioInterrupts);
    OS_eActivateTask(APP_ButtonsScanTask);
}

/****************************************************************************
 *
 * NAME: vSaveDioStateBeforeDeepSleep
 *
 * DESCRIPTION:
 * Due to us going to sleep on a falling edge as well as a rising edge, we need
 * to save the Dio state into NVM so when we wake back up we know what edge we
 * had configured to wake us up.
 *
 ****************************************************************************/
PUBLIC void vSaveDioStateBeforeDeepSleep(void)
{
    DBG_vPrintf(TRACE_APP_BUTTON, "\nAPP Button: Writing %d to NVM", u32PreviousDioState);
    vAHI_WriteNVData(DIO_STATE_NVM_LOCATION, u32PreviousDioState);
    DBG_vPrintf(TRACE_APP_BUTTON, "\nAPP Button: Written %d to NVM", u32AHI_ReadNVData(DIO_STATE_NVM_LOCATION));
}

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

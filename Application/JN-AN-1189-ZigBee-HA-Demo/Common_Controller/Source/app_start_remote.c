/****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          app_start_remote.c
 *
 * DESCRIPTION:        ZHA Remote Control Application Initialisation and Startup
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
#include "pwrm.h"
#include "pdum_nwk.h"
#include "pdum_apl.h"
#include "pdm.h"
#include "dbg.h"
#include "dbg_uart.h"
#include "pdum_gen.h"
#include "os_gen.h"
#include "zps_gen.h"
#include "zps_apl_af.h"
#include "appapi.h"
#include "zha_remote_node.h"
#include "app_timer_driver.h"
#include "DriverCapTouch.h"
#include "low_bat_indicator.h"
#include "app_exceptions.h"

#include <string.h>

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifndef DEBUG_START_UP
    #define TRACE_START FALSE
#else
    #define TRACE_START TRUE
#endif

#ifndef DEBUG_SLEEP
    #define TRACE_SLEEP     FALSE
#else
    #define TRACE_SLEEP     TRUE
#endif

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/

PRIVATE void vInitialiseApp(void);

PRIVATE void vfExtendedStatusCallBack (ZPS_teExtendedStatus eExtendedStatus);
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
extern void *_stack_low_water_mark;

extern uint32 u32HeapStart;
extern uint32 u32HeapEnd;

bool_t bDeepSleep=FALSE;
/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/


/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

/**
 * Power manager Callback.
 * Called just before the device is put to sleep
 */

static PWRM_DECLARE_CALLBACK_DESCRIPTOR(PreSleep);
/**
 * Power manager Callback.
 * Called just after the device wakes up from sleep
 */
static PWRM_DECLARE_CALLBACK_DESCRIPTOR(Wakeup);
/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

/****************************************************************************
 *
 * NAME: PreSleep
 *
 * DESCRIPTION:
 *
 * PreSleep call back by the power manager before the controller put into sleep.
 *
 * PARAMETERS:      Name            RW  Usage
 *
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PWRM_CALLBACK(PreSleep)
{
    /* LED are used for the testing the sleep wake up */
    /*APP_vSetLeds(0);*/
    DBG_vPrintf(TRACE_SLEEP,"Sleeping mode %d...\n", bDeepSleep);
    /* If the power mode is with RAM held do the following
     * else not required as the entry point will init everything*/
    if( !bDeepSleep)
    {
       eTouchSleep();
       vAppApiSaveMacSettings();
    }
    /* Disable UART */
    vAHI_UartDisable(E_AHI_UART_0);
#ifdef RemoteControl
    bReadyToGroup = FALSE;
#endif

#ifdef SLEEP_ENABLE
#ifdef DEEP_SLEEP_ENABLE
    /* Set up wake up input */
    vSetUpWakeUpConditions();
#endif
#endif
}
/****************************************************************************
 *
 * NAME: Wakeup
 *
 * DESCRIPTION:
 *
 * Wakeup call back by the power manager after the controller wakes up from sleep.
 *
 * PARAMETERS:      Name            RW  Usage
 *
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PWRM_CALLBACK(Wakeup)
{
    /* LED are sused for the testing the sleep wake up */
    /*APP_vSetLeds(2);*/
    /*Stabilise the oscillator*/
    /* Wait until FALSE i.e. on XTAL  - otherwise uart data will be at wrong speed*/
    while (bAHI_GetClkSource() == TRUE);
    /* Now we are running on the XTAL, optimise the flash memory wait states.*/
    vAHI_OptimiseWaitStates();
    #ifndef PDM_EEPROM
        PDM_vWarmInitHW();
    #endif

    /*Clear wakeup status by reading the wake status*/
    u32AHI_DioWakeStatus();

    /* Reinitialise the battery monitor as sleep restores default 0f 2.0v */
    vLowBatIndicationInit( (LHS_LED_DIO | RHS_LED_DIO), E_BO_TRIP_2V4 );

    /*Wake up the touch interface */
    eTouchWake();

    /* Don't use RTS/CTS pins on UART0 as they are used for buttons */
    vAHI_UartSetRTSCTS(E_AHI_UART_0, FALSE);
    DBG_vUartInit(DBG_E_UART_0, DBG_E_UART_BAUD_RATE_115200);

    DBG_vPrintf(TRACE_SLEEP, "\nAPP: Woken up (CB)");
    DBG_vPrintf(TRACE_START, "\nAPP: Warm Waking powerStatus = 0x%x", u8AHI_PowerStatus());

    /* If the power status is OK and RAM held while sleeping
     * restore the MAC settings
     * */
    if( (u8AHI_PowerStatus()) && ( !bDeepSleep) )
    {
        /* Restore Mac settings (turns radio on)*/
        vMAC_RestoreSettings();
        DBG_vPrintf(TRACE_START, "\nAPP: MAC settings restored\n");

        /* Define HIGH_POWER_ENABLE to enable high power module */
        #ifdef HIGH_POWER_ENABLE
            vAHI_HighPowerModuleEnable(TRUE, TRUE);
        #endif
    }
    DBG_vPrintf(TRACE_START, "\nAPP: Restarting OS \n");
    /* Restart the OS */
    OS_vRestart();

    /* Activate the SleepTask, that would start the SW timer and polling would continue
     * */
    OS_eActivateTask(APP_SleepTask);
}

/****************************************************************************
 *
 * NAME: vAppMain
 *
 * DESCRIPTION:
 *
 * Entry point for application from a cold start.
 *
 * PARAMETERS:      Name            RW  Usage
 *
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppMain(void)
{
    /*
     * Wait until FALSE i.e. on XTAL  - otherwise uart data will be at wrong speed
     * */
    while (bAHI_GetClkSource() == TRUE);
    /*
     * Now we are running on the XTAL, optimise the flash memory wait states.
     * */
    vAHI_OptimiseWaitStates();

     /* Enable the Low Battery Detection function */

     vLowBatIndicationInit( (LHS_LED_DIO | RHS_LED_DIO), E_BO_TRIP_2V4 );


    /* Don't use RTS/CTS pins on UART0 as they are used for buttons */

    vAHI_UartSetRTSCTS(E_AHI_UART_0, FALSE);

    /* Initialize the debug diagnostics module to use UART0 at 115K Baud; */
    /* Do not use UART 1 if LEDs are used, as it shares DIO with the LEDS */

    DBG_vUartInit(DBG_E_UART_0, DBG_E_UART_BAUD_RATE_115200);
    DBG_vPrintf(TRACE_START, "\n\nAPP: Switch Power Up");

    /*
     * Delay to allow programmer to end and serial terminal to start on PC
     * */
    #ifdef TRACE_START
        /* Startup delay
         * */
        uint16 n;
        for(n = 0; n < 10000; n++)
        {
            DBG_vPrintf(TRACE_START, ".");
            vAHI_WatchdogRestart();
        }
    #endif

    /*
     * Initialise the stack overflow exception to trigger if the end of the
     * stack is reached. See the linker command file to adjust the allocated
     * stack size.
     */
    vAHI_SetStackOverflow(TRUE, (uint32)&_stack_low_water_mark);

    /*
     * Catch resets due to watchdog timer expiry. Comment out to harden code.
     * */
    if (bAHI_WatchdogResetEvent())
    {
        DBG_vPrintf(TRACE_START, "\nAPP: Watchdog timer has reset device!");
        #if HALT_ON_EXCEPTION
            vAHI_WatchdogStop();
            while (1);
        #endif
    }

    /*
     * Initialize ROM based software modules
     * */
#ifndef JENNIC_MAC_MiniMacShim     
    u32AppApiInit(NULL, NULL, NULL, NULL, NULL, NULL);
#endif

    /* Define HIGH_POWER_ENABLE to enable high power module */
    #ifdef HIGH_POWER_ENABLE
        vAHI_HighPowerModuleEnable(TRUE, TRUE);
    #endif

    /*
     * Start the RTOS
     * */
    OS_vStart(vInitialiseApp, vUnclaimedInterrupt, vOSError);

    /*
     * Idle task commences here
     * */

    while (TRUE)
    {
        /*
         * Re-load the watch-dog timer. Execution must return through the idle
         * task before the CPU is suspended by the power manager. This ensures
         * that at least one task / ISR has executed with in the watchdog period
         * otherwise the system will be reset.
         */
        vAHI_WatchdogRestart();

        /*
         * suspends CPU operation when the system is idle or puts the device to
         * sleep if there are no activities in progress
         */
        PWRM_vManagePower();
    }
}

/****************************************************************************
 *
 * NAME: vAppRegisterPWRMCallbacks
 *
 * DESCRIPTION:
 *
 * Power manager callback.
 * Called to allow the application to register
 * sleep and wake callbacks.
 *
 * PARAMETERS:      Name            RW  Usage
 *
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
void vAppRegisterPWRMCallbacks(void)
{
    PWRM_vRegisterPreSleepCallback(PreSleep);
    PWRM_vRegisterWakeupCallback(Wakeup);
}

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

/****************************************************************************
 *
 * NAME: vInitialiseApp
 *
 * DESCRIPTION:
 *
 * Initialises Zigbee stack, hardware and application.
 *
 * PARAMETERS:      Name            RW  Usage
 *
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vInitialiseApp(void)
{
    /*
     * Initialise JenOS modules. Initialise Power Manager even on non-sleeping nodes
     * as it allows the device to doze when in the idle task.
     * Parameter options: E_AHI_SLEEP_OSCON_RAMON or E_AHI_SLEEP_DEEP or ...
     */
    PWRM_vInit(E_AHI_SLEEP_OSCON_RAMON);
    bDeepSleep = FALSE;
    /* Initialise the Persistent Data Manager */
    #if JENNIC_CHIP == JN5169
       PDM_eInitialise(63, NULL);
    #else
       PDM_eInitialise(0, NULL);
    #endif


    /* Initialise Protocol Data Unit Manager */
    PDUM_vInit();

    ZPS_vExtendedStatusSetCallback(vfExtendedStatusCallBack);
    /* initialise application */
    APP_vInitialiseNode();
}
/****************************************************************************
 *
 * NAME: vfExtendedStatusCallBack
 *
 * DESCRIPTION:
 *
 * ZPS extended error callback .
 *
 * PARAMETERS:      Name            RW  Usage
 *
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vfExtendedStatusCallBack (ZPS_teExtendedStatus eExtendedStatus)
{
    DBG_vPrintf(TRACE_START,"ERROR: Extended status %x\n", eExtendedStatus);
}
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

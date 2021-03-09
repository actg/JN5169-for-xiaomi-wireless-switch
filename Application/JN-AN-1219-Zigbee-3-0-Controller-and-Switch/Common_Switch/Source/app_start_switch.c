/****************************************************************************
 *
 * MODULE:             JN-AN-1219
 *
 * COMPONENT:          app_start_remote.c
 *
 * DESCRIPTION:        ZLO Dimmmer Switch Application Initialisation and Startup
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
 * Copyright NXP B.V. 2017. All rights reserved
 *
 ***************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#include <jendefs.h>
#include "pwrm.h"
#include "pdum_nwk.h"
#include "pdum_apl.h"
#include "PDM.h"
#include "dbg.h"
#include "dbg_uart.h"
#include "pdum_gen.h"
#include "zps_gen.h"
#include "zps_apl_af.h"
#include "AppApi.h"
#include "app_events.h"
#include "app_zlo_switch_node.h"
#include "app_buttons.h"
#include <string.h>
#include "ZTimer.h"
#ifdef CLD_OTA
    #include "app_ota_client.h"
#endif
#include "app_main.h"
#ifdef APP_NTAG_ICODE
#include "ntag_nwk.h"
#include "app_ntag_icode.h"
#endif
#ifdef APP_NTAG_AES
#include "ntag_nwk.h"
#include "app_ntag_aes.h"
#endif

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifndef DEBUG_START_UP
    #define TRACE_START FALSE
#else
    #define TRACE_START TRUE
#endif

#define RAM_HELD 2

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/

PRIVATE void APP_vInitialise(void);
#ifdef SLEEP_ENABLE
    PRIVATE void vSetUpWakeUpConditions(bool_t bDeepSleep);
    #ifdef DEEP_SLEEP_ENABLE
        #define  vSetUpWakeUpConditionsForDeepSleep()   vSetUpWakeUpConditions(TRUE)
    #endif
#endif

void vfExtendedStatusCallBack (ZPS_teExtendedStatus eExtendedStatus);
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

static uint8 u8PowerMode=RAM_HELD;
/****************************************************************************/
/***        Local Variables                                               ***/
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
 * NAME: vAppMain
 *
 * DESCRIPTION:
 * Entry point for application from a cold start.
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppMain(void)
{

    #if JENNIC_CHIP_FAMILY == JN516x || JENNIC_CHIP_FAMILY == JN514x
        extern void *_stack_low_water_mark;
    #endif

    #if JENNIC_CHIP_FAMILY == JN516x
        /* Wait until FALSE i.e. on XTAL  - otherwise uart data will be at wrong speed */
         while (bAHI_GetClkSource() == TRUE);
         /* Now we are running on the XTAL, optimise the flash memory wait states */
         vAHI_OptimiseWaitStates();
    #endif

    /*
     * Don't use RTS/CTS pins on UART0 as they are used for buttons
     * */
    vAHI_UartSetRTSCTS(E_AHI_UART_0, FALSE);

    /*
     * Initialise the debug diagnostics module to use UART0 at 115K Baud;
     * Do not use UART 1 if LEDs are used, as it shares DIO with the LEDS
     * */
    DBG_vUartInit(DBG_E_UART_0, DBG_E_UART_BAUD_RATE_115200);
    #ifdef DEBUG_921600
    {
        /* Bump baud rate up to 921600 */
        vAHI_UartSetBaudDivisor(DBG_E_UART_0, 2);
        vAHI_UartSetClocksPerBit(DBG_E_UART_0, 8);
    }
    #endif
    DBG_vPrintf(TRACE_START, "APP: Switch Power Up\n");

    /*
     * Initialise the stack overflow exception to trigger if the end of the
     * stack is reached. See the linker command file to adjust the allocated
     * stack size.
     */
    #if JENNIC_CHIP_FAMILY == JN516x || JENNIC_CHIP_FAMILY == JN514x
        vAHI_SetStackOverflow(TRUE, (uint32)&_stack_low_water_mark);
    #endif
    /*
     * Catch resets due to watchdog timer expiry. Comment out to harden code.
     */
    if (bAHI_WatchdogResetEvent())
    {
        DBG_vPrintf(TRUE, "APP: Watchdog timer has reset device!\n");
        DBG_vDumpStack();
        #if HALT_ON_EXCEPTION
            vAHI_WatchdogStop();
            while (1);
        #endif
    }

    /* initialise ROM based software modules */
#ifndef JENNIC_MAC_MiniMacShim
    u32AppApiInit(NULL, NULL, NULL, NULL, NULL, NULL);
#endif

    /* Define HIGH_POWER_ENABLE to enable high power module */
    #ifdef HIGH_POWER_ENABLE
        vAHI_HighPowerModuleEnable(TRUE, TRUE);
    #endif

    APP_vSetUpHardware();

    APP_vInitResources();

    /* Set IIC DIO lines to outputs */
    vAHI_DioSetDirection(0, IIC_MASK);
    vAHI_DioSetOutput(IIC_MASK, 0);

    APP_vInitialise();

#if (defined APP_NTAG_ICODE) || (defined APP_NTAG_AES)
    DBG_vPrintf(TRACE_START, "\nAPP: Entering APP_vNtagPdmLoad()");
    /* Didn't start BDB using PDM data ? */
    if (FALSE == APP_bNtagPdmLoad())
#endif
    {
        DBG_vPrintf(TRACE_START, "APP: Entering BDB_vStart()\n");
        BDB_vStart();

#ifdef APP_NTAG_AES
        DBG_vPrintf(TRACE_START, "\nAPP: Entering APP_vNtagStart()");
        APP_vNtagStart(NFC_NWK_NSC_DEVICE_ZIGBEE_ROUTER_DEVICE);
#endif
    }

#ifdef APP_NTAG_ICODE
    /* Not waking from deep sleep ? */
    if (0 == (u16AHI_PowerStatus() & (1 << 11)))
    {
        DBG_vPrintf(TRACE_START, "\nAPP: Entering APP_vNtagStart()");
        APP_vNtagStart(DIMMERSWITCH_SWITCH_ENDPOINT);
    }
#endif

    DBG_vPrintf(TRACE_START, "APP: Entering APP_vMainLoop()\n");
    APP_vMainLoop();

}


/****************************************************************************
 *
 * NAME: vAppRegisterPWRMCallbacks
 *
 * DESCRIPTION:
 * Power manager callback.
 * Called to allow the application to register  sleep and wake callbacks.
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
 * NAME: APP_vInitialise
 *
 * DESCRIPTION:
 * Initialises Zigbee stack, hardware and application.
 *
 *
 * RETURNS:
 * void
 ****************************************************************************/
PRIVATE void APP_vInitialise(void)
{
    /*
     * Initialise JenOS modules. Initialise Power Manager even on non-sleeping nodes
     * as it allows the device to doze when in the idle task.
     * Parameter options: E_AHI_SLEEP_OSCON_RAMON or E_AHI_SLEEP_DEEP or ...
     */
    PWRM_vInit(E_AHI_SLEEP_OSCON_RAMON);

    PDM_eInitialise(63);

    /* Initialise Protocol Data Unit Manager */
    PDUM_vInit();

    ZPS_vExtendedStatusSetCallback(vfExtendedStatusCallBack);
    /* Initialise application */
    APP_vInitialiseNode();
}

#ifdef SLEEP_ENABLE
/****************************************************************************
 *
 * NAME: vSetUpWakeUpConditions
 *
 * DESCRIPTION:
 *
 * Set up the wake up inputs while going to sleep.
 *
 * PARAMETERS:      Name            RW  Usage
 *
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vSetUpWakeUpConditions(bool_t bDeepSleep)
{
   /*
    * Set the DIO with the right edges for wake up
    * */

    u32AHI_DioWakeStatus();                         /* clear interrupts */
    vAHI_DioSetDirection(APP_BUTTONS_DIO_MASK,0);   /* Set as Power Button(DIO0) as Input */

    //DBG_vPrintf(TRUE, "Going to sleep: Buttons:%08x Mask:%08x\n", u32AHI_DioReadInput() & APP_BUTTONS_DIO_MASK_FOR_DEEP_SLEEP, APP_BUTTONS_DIO_MASK_FOR_DEEP_SLEEP);

    #ifdef DEEP_SLEEP_ENABLE
    if(bDeepSleep)
    {
        vAHI_DioWakeEdge(0,APP_BUTTONS_DIO_MASK_FOR_DEEP_SLEEP);
        vAHI_DioWakeEnable(APP_BUTTONS_DIO_MASK_FOR_DEEP_SLEEP,0);
    }
    else
    #endif
    {
        vAHI_DioWakeEdge(0,APP_BUTTONS_DIO_MASK);       /* Set the wake up DIO Edge - Falling Edge */
        vAHI_DioWakeEnable(APP_BUTTONS_DIO_MASK,0);     /* Set the Wake up DIO Power Button */
    }
}
#endif

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
    #ifdef SLEEP_ENABLE
        DBG_vPrintf(TRACE_START,"Sleeping..\n");
        #ifdef DEEP_SLEEP_ENABLE
            DBG_vPrintf(TRACE_START,"Sleeping...bGoingDeepSleep = %d\n",bGoingDeepSleep());
        #endif
    #endif

    /* If the power mode is with RAM held do the following
     * else not required as the entry point will init everything*/
    if(u8PowerMode == RAM_HELD)
    {
       vAppApiSaveMacSettings();
    }

    ZTIMER_vSleep();

    /* Wait for the UART to complete any transmission */
    DBG_vUartFlush();

    /* Disable UART (if enabled) */
    vAHI_UartDisable(E_AHI_UART_0);

    /* Set up wake up input */
    #ifdef SLEEP_ENABLE
        #ifdef DEEP_SLEEP_ENABLE
            if(bGoingDeepSleep())
            {
                vSetUpWakeUpConditionsForDeepSleep();
            }
            else
        #endif
            {
                vSetUpWakeUpConditions(FALSE);
            }
    #endif
}
/****************************************************************************
 *
 * NAME: Wakeup
 *
 * DESCRIPTION:
 *
 * Wakeup call back by  power manager after the controller wakes up from sleep.
 *
 ****************************************************************************/
PWRM_CALLBACK(Wakeup)
{
    #ifdef CLD_OTA
        tsNvmDefs sNvmDefs;
    #endif

    /*Stabilise the oscillator*/
    #if JENNIC_CHIP_FAMILY == JN516x || JENNIC_CHIP_FAMILY == JN517x
        /* Wait until FALSE i.e. on XTAL  - otherwise uart data will be at wrong speed */
        while (bAHI_GetClkSource() == TRUE);
        /* Now we are running on the XTAL, optimise the flash memory wait states */
        vAHI_OptimiseWaitStates();
        #ifndef PDM_EEPROM
            PDM_vWarmInitHW();
        #endif
    #endif

    /* Don't use RTS/CTS pins on UART0 as they are used for buttons */
    vAHI_UartSetRTSCTS(E_AHI_UART_0, FALSE);
    DBG_vUartInit(DBG_E_UART_0, DBG_E_UART_BAUD_RATE_115200);

    DBG_vPrintf(TRACE_START,"Waking..\n");

    #ifdef DEBUG_921600
        /* Bump baud rate up to 921600 */
        vAHI_UartSetBaudDivisor(DBG_E_UART_0, 2);
        vAHI_UartSetClocksPerBit(DBG_E_UART_0, 8);
    #endif

    #ifdef CLD_OTA
        #if JENNIC_CHIP==JN5168
            sNvmDefs.u32SectorSize = 64*1024; /* Sector Size = 64K*/
            sNvmDefs.u8FlashDeviceType = E_FL_CHIP_AUTO;
        #elif JENNIC_CHIP==JN5169 || JENNIC_CHIP==JN5179
            sNvmDefs.u32SectorSize = 32*1024; /* Sector Size = 32K*/
            sNvmDefs.u8FlashDeviceType = E_FL_CHIP_INTERNAL;
        #else
            error define the chip
        #endif
        vOTA_FlashInit(NULL,&sNvmDefs);
    #endif

    DBG_vPrintf(TRACE_START, "\nAPP: Woken up (CB)");
    DBG_vPrintf(TRACE_START, "\nAPP: Warm Waking powerStatus = 0x%x", u8AHI_PowerStatus());

    /* If the power status is OK and RAM held while sleeping
     * restore the MAC settings
     * */
    if( (u8AHI_PowerStatus()) && (u8PowerMode == RAM_HELD) )
    {
        /* Restore Mac settings (turns radio on) */
        vMAC_RestoreSettings();
        DBG_vPrintf(TRACE_START, "\nAPP: MAC settings restored");

        /* Define HIGH_POWER_ENABLE to enable high power module */
        #ifdef HIGH_POWER_ENABLE
            vAHI_HighPowerModuleEnable(TRUE, TRUE);
        #endif
    }

    APP_vSetUpHardware();

    ZTIMER_vWake();

    /* Activate the SleepTask, that would start the SW timer and polling would continue */
    APP_vSleepTask();

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
void vfExtendedStatusCallBack (ZPS_teExtendedStatus eExtendedStatus)
{
    DBG_vPrintf(TRACE_START,"ERROR: Extended status %x\n", eExtendedStatus);
}
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

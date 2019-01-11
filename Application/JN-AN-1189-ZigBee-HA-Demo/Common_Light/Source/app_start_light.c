/****************************************************************************
 *
 * MODULE:             JN-AN-1189 ZHA Demo
 *
 * COMPONENT:          app_start_light.c
 *
 * DESCRIPTION:        ZHA Light Application Initialisation and Startup
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
#include "pwrm.h"
#include "pdm.h"
#include "dbg_uart.h"
#include "pdum_gen.h"
#include "os_gen.h"
#include "zps_gen.h"
#include "zps_apl.h"
#include "appapi.h"
#include "zha_light_node.h"
#include "app_exceptions.h"
#include "app_pdm.h"
#include "app_common.h"
#include "app_light_interpolation.h"
#include "DriverBulb_Shim.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#ifndef DEBUG_START_UP
	#define TRACE_START FALSE
#else
	#define TRACE_START TRUE
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

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

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
	#if JENNIC_CHIP_FAMILY == JN516x
		/* Wait until FALSE i.e. on XTAL  - otherwise uart data will be at wrong speed */
		 while (bAHI_GetClkSource() == TRUE);
		 /* Now we are running on the XTAL, optimise the flash memory wait states */
		 vAHI_OptimiseWaitStates();
	#endif

    /* Initialise the debug diagnostics module to use UART0 at 115K Baud;
     * Do not use UART 1 if LEDs are used, as it shares DIO with the LEDS
     */
    DBG_vUartInit(DBG_E_UART_0, DBG_E_UART_BAUD_RATE_115200);
    DBG_vPrintf(TRACE_START, "\n\nAPP: Light Power Up\n");

    /*
     * Initialise the stack overflow exception to trigger if the end of the
     * stack is reached. See the linker command file to adjust the allocated
     * stack size.
     */
    vAHI_SetStackOverflow(TRUE, (uint32)&_stack_low_water_mark);

    /* Early call to Bulb initialisation to enable fast start up    */
    /* Note HA does not persist the lamp state so power outages    */
    /* Will turn lights On. This is trade off against allowing      */
    /* users to still control the lights from wall switches         */

     vBULB_Init();

     vLI_SetCurrentValues(CLD_LEVELCONTROL_MAX_LEVEL ,255,255,255,4000);
     vLI_UpdateDriver();

     vBULB_SetOnOff(TRUE);

    /*
     * Catch resets due to watchdog timer expiry. Comment out to harden code.
     */
    if (bAHI_WatchdogResetEvent())
    {
        DBG_vPrintf(TRACE_START, "APP: Watchdog timer has reset device!\n");
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

    /* start the RTOS */
    OS_vStart(vInitialiseApp, vUnclaimedInterrupt, vOSError);
    DBG_vPrintf(TRACE_START, "OS started\n");

    /* idle task commences here */
    while (TRUE)
    {
        /* Re-load the watch-dog timer. Execution must return through the idle
         * task before the CPU is suspended by the power manager. This ensures
         * that at least one task / ISR has executed with in the watchdog period
         * otherwise the system will be reset.
         */
        vAHI_WatchdogRestart();

        /* Doze the CPU if the light is off otherwise burn cpu cycles when lamp lit to */
        /* prevent supply JN5168 supply current changes causing 'doze' flicker on bulb */

        if(DriverBulb_bOn() == FALSE)
        {
        	vAHI_CpuDoze();
        }
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
	/*Do nothing*/
}
/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

/****************************************************************************
 *
 * NAME: vInitialiseApp
 *
 * DESCRIPTION:
 * Initialises Zigbee stack, hardware and application.
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vInitialiseApp(void)
{
    /* Initialise the debug diagnostics module to use UART0 at 115K Baud;
     * Do not use UART 1 if LEDs are used, as it shares DIO with the LEDS
     */
    DBG_vUartInit(DBG_E_UART_0, DBG_E_UART_BAUD_RATE_115200);

    /* Initialise JenOS modules. Initialise Power Manager even on non-sleeping nodes
     * as it allows the device to doze when in the idle task
     */
    PWRM_vInit(E_AHI_SLEEP_OSCON_RAMON);

   #if JENNIC_CHIP == JN5169
       PDM_eInitialise(63, NULL);
   #else
       PDM_eInitialise(0, NULL);
   #endif


    /* Initialise Protocol Data Unit Manager */
    PDUM_vInit();

    ZPS_vExtendedStatusSetCallback(vfExtendedStatusCallBack);

    /* Initialise application */
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

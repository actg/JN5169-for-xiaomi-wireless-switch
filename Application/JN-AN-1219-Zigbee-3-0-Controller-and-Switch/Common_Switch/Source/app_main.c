/*****************************************************************************
 *
 * MODULE:             JN-AN-1219
 *
 * COMPONENT:          app_endpoint.c
 *
 * DESCRIPTION:        ZLO End Point event handler (Implementation)
 *
 *****************************************************************************
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
 ****************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#include <stdint.h>
#include "jendefs.h"
#include "ZQueue.h"
#include "ZTimer.h"
#include "portmacro.h"
#include "zps_apl_af.h"
#include "mac_vs_sap.h"
#include "AppHardwareApi.h"
#include "dbg.h"
#include "app_main.h"
#include "app_buttons.h"
#include "app_events.h"
#include "app_zcl_switch_task.h"
#include "app_zlo_switch_node.h"
#include "PDM.h"
#include "app_switch_state_machine.h"

#ifdef DimmerSwitch
#include "App_DimmerSwitch.h"
#endif
#ifdef APP_NTAG_ICODE
#include "app_ntag_icode.h"
#endif
#ifdef APP_NTAG_AES
#include "app_ntag_aes.h"
#endif

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#ifndef DEBUG_APP
#define TRACE_APP_MAIN   FALSE
#else
#define TRACE_APP_MAIN   TRUE
#endif

#define TIMER_QUEUE_SIZE             8
#define MLME_QUEQUE_SIZE            10
#define MCPS_QUEUE_SIZE             24
#define APP_QUEUE_SIZE               8
#define BDB_QUEUE_SIZE               3
#if (defined APP_NTAG_ICODE) || (defined APP_NTAG_AES)
#define APP_ZTIMER_STORAGE           6 /* NTAG: Added timer */
#else
#define APP_ZTIMER_STORAGE           7
#endif

#define MCPS_DCFM_QUEUE_SIZE 5


#if JENNIC_CHIP_FAMILY == JN517x
#define NVIC_INT_PRIO_LEVEL_SYSCTRL (1)
#define NVIC_INT_PRIO_LEVEL_BBC     (7)
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

PUBLIC uint8 u8TimerPoll;
PUBLIC uint8 u8TimerButtonScan;
PUBLIC uint8 u8TimerButtonDelay;
PUBLIC uint8 u8TimerTick;
PUBLIC uint8 u8TimerChangeMode;
#if (defined APP_NTAG_ICODE) || (defined APP_NTAG_AES)
PUBLIC uint8 u8TimerNtag;
#endif
PUBLIC uint8 u8TimerButtonLongPressed;
PUBLIC uint8 u8TimerLedBlinks;
extern PUBLIC ledVset_t ledVsetParam;
PUBLIC uint8 u8TimerSecondStep;

PUBLIC tszQueue APP_msgAppEvents;
PUBLIC tszQueue APP_msgBdbEvents;

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

PRIVATE ZTIMER_tsTimer asTimers[APP_ZTIMER_STORAGE + BDB_ZTIMER_STORAGE];

PRIVATE zps_tsTimeEvent asTimeEvent[TIMER_QUEUE_SIZE];
PRIVATE MAC_tsMcpsVsDcfmInd asMacMcpsDcfmInd[MCPS_QUEUE_SIZE];
PRIVATE MAC_tsMlmeVsDcfmInd asMacMlmeVsDcfmInd[MLME_QUEQUE_SIZE];
PRIVATE MAC_tsMcpsVsCfmData asMacMcpsDcfm[MCPS_DCFM_QUEUE_SIZE];

PRIVATE BDB_tsZpsAfEvent asBdbEvent[BDB_QUEUE_SIZE];
PRIVATE APP_tsEvent asAppEvent[APP_QUEUE_SIZE];
/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/


extern void zps_taskZPS(void);
extern void PWRM_vManagePower(void);

/****************************************************************************
 *
 * NAME: APP_vMainLoop
 *
 * DESCRIPTION:
 * Main application loop
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_vMainLoop(void)
{

    while (TRUE)
    {
        zps_taskZPS();

        bdb_taskBDB();

        ZTIMER_vTask();

        APP_taskSwitch();

        /* Re-load the watch-dog timer. Execution must return through the idle
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
 * NAME: APP_vSetUpHardware
 *
 * DESCRIPTION:
 * Set up interrupts
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_vSetUpHardware(void)
{
    #if (JENNIC_CHIP_FAMILY == JN517x)
        vAHI_SysCtrlRegisterCallback ( vISR_SystemController );
        u32AHI_Init();
        vAHI_InterruptSetPriority ( MICRO_ISR_MASK_BBC,        NVIC_INT_PRIO_LEVEL_BBC );
        vAHI_InterruptSetPriority ( MICRO_ISR_MASK_SYSCTRL, NVIC_INT_PRIO_LEVEL_SYSCTRL );
    #endif
    /* clear interrupt priority level  */
    #if (JENNIC_CHIP_FAMILY == JN516x)
        TARGET_INITIALISE();
        SET_IPL(0);
        portENABLE_INTERRUPTS();
    #endif
}

/****************************************************************************
 *
 * NAME: APP_vInitResources
 *
 * DESCRIPTION:
 * Initialise resources (timers, queue's etc)
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_vInitResources(void)
{

    /* Initialise the Z timer module */
    ZTIMER_eInit(asTimers, sizeof(asTimers) / sizeof(ZTIMER_tsTimer));

    /* Create Z timers */
    ZTIMER_eOpen(&u8TimerPoll,          APP_cbTimerPoll,        NULL, ZTIMER_FLAG_PREVENT_SLEEP);
    ZTIMER_eOpen(&u8TimerButtonScan,    APP_cbTimerButtonScan,  NULL, ZTIMER_FLAG_PREVENT_SLEEP);
    ZTIMER_eOpen(&u8TimerButtonDelay,   APP_cbTimerButtonDelay, NULL, ZTIMER_FLAG_PREVENT_SLEEP);
    ZTIMER_eOpen(&u8TimerTick,          APP_cbTimerZclTick,     NULL, ZTIMER_FLAG_PREVENT_SLEEP);
    ZTIMER_eOpen(&u8TimerChangeMode,    APP_cbTimerChangeMode,  NULL, ZTIMER_FLAG_PREVENT_SLEEP);
#if (defined APP_NTAG_ICODE) || (defined APP_NTAG_AES)
    ZTIMER_eOpen(&u8TimerNtag,          APP_cbNtagTimer,        NULL, ZTIMER_FLAG_PREVENT_SLEEP);
#endif
	ZTIMER_eOpen(&u8TimerButtonLongPressed,APP_cbTimerButtonLongPressed,NULL, ZTIMER_FLAG_PREVENT_SLEEP);
	ZTIMER_eOpen(&u8TimerLedBlinks,APP_cbTimerLedBlinks,&ledVsetParam, ZTIMER_FLAG_PREVENT_SLEEP);
	ZTIMER_eOpen(&u8TimerSecondStep,APP_cbTimerSteering,NULL, ZTIMER_FLAG_PREVENT_SLEEP);
    /* Create all the queues */
    ZQ_vQueueCreate(&APP_msgBdbEvents,          BDB_QUEUE_SIZE,         sizeof(BDB_tsZpsAfEvent),   (uint8*)asBdbEvent);
    ZQ_vQueueCreate(&APP_msgAppEvents,          APP_QUEUE_SIZE,         sizeof(APP_tsEvent),        (uint8*)asAppEvent);
    ZQ_vQueueCreate(&zps_msgMlmeDcfmInd,        MLME_QUEQUE_SIZE,       sizeof(MAC_tsMlmeVsDcfmInd),(uint8*)asMacMlmeVsDcfmInd);
    ZQ_vQueueCreate(&zps_msgMcpsDcfmInd,        MCPS_QUEUE_SIZE,        sizeof(MAC_tsMcpsVsDcfmInd),(uint8*)asMacMcpsDcfmInd);
    ZQ_vQueueCreate(&zps_TimeEvents,            TIMER_QUEUE_SIZE,       sizeof(zps_tsTimeEvent),    (uint8*)asTimeEvent);
    ZQ_vQueueCreate(&zps_msgMcpsDcfm, 			MCPS_DCFM_QUEUE_SIZE,	sizeof(MAC_tsMcpsVsCfmData),(uint8*)asMacMcpsDcfm);
}

/****************************************************************************
 *
 * NAME: APP_vInitLeds
 *
 * DESCRIPTION:
 * Initialises LED's
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_vInitLeds(void)
{
    vAHI_DioSetDirection(0, BOARD_LED_CTRL_MASK);
	vAHI_DioSetOutput(BOARD_LED_CTRL_MASK, 0);			//turn off
}

/****************************************************************************
 *
 * NAME: APP_vSetLED
 *
 * DESCRIPTION:
 * Initialises LED's
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_vSetLED(uint8 u8Led, bool_t bOn)
{
    if ( u8Led == LED1)
    {
        if (bOn)
        {
            /* leds on LvMi wireless switch driven high for on */
            vAHI_DioSetOutput(0, BOARD_LED_D1_PIN);
			vAHI_DioSetOutput(0, BOARD_LED_D2_PIN);
        }
        else
        {
			vAHI_DioSetOutput(BOARD_LED_D1_PIN , 0);
			vAHI_DioSetOutput(BOARD_LED_D2_PIN , 0);
        }
    }
}

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

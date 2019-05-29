/*****************************************************************************
 *
 * MODULE:             JN-AN-1219
 *
 * COMPONENT:          app_main.c
 *
 * DESCRIPTION:
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
 * Copyright NXP B.V. 2016. All rights reserved
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
#include "app_events.h"
#include "app_zcl_controller_task.h"
#include "app_zcl_controller_task.h"
#include "PDM.h"
#include "zlo_controller_node.h"
#include "app_led_control.h"
#include "bdb_api.h"
#ifdef DR1199
#include "app_buttons.h"
#include "uart.h"
#include "app_serial_interface.h"
#endif


#ifdef Controller_ColorController
#include "App_Controller_ColorController.h"
#endif

#ifdef Controller_ColorSceneController
#include "App_Controller_ColorSceneController.h"
#endif

#ifdef Controller_NonColorController
#include "App_Controller_NonColorController.h"
#endif

#ifdef Controller_NonColorSceneController
#include "App_Controller_NonColorSceneController.h"
#endif

#ifdef Controller_OnOffSensor
#include "App_Controller_OnOffSensor.h"
#endif

#if JENNIC_CHIP_FAMILY == JN517x
#define NVIC_INT_PRIO_LEVEL_SYSCTRL (1)
#define NVIC_INT_PRIO_LEVEL_BBC     (7)
#define NVIC_INT_PRIO_LEVEL_UART0   (5)
#endif

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#ifndef DEBUG_APP
#define TRACE_APP   FALSE
#else
#define TRACE_APP   TRUE
#endif

#define TIMER_QUEUE_SIZE             8
#define MLME_QUEQUE_SIZE            10
#define MCPS_QUEUE_SIZE             24
#define APP_QUEUE_SIZE               8
#define BDB_QUEUE_SIZE               3
#ifdef DR1199
#define TX_QUEUE_SIZE               10
#define RX_QUEUE_SIZE               30
#endif

#define MCPS_DCFM_QUEUE_SIZE 5


#ifndef DR1199
#define APP_ZTIMER_STORAGE           5
#else
#define APP_ZTIMER_STORAGE           6
#endif

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
#if (JENNIC_CHIP_FAMILY == JN517x)
PUBLIC void vISR_SystemController(uint32 u32Deviceid, uint32 u32BitMap);
#endif
/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

PUBLIC uint8 u8TimerLedBlink;
PUBLIC uint8 u8TimerId;
PUBLIC uint8 u8TimerAddGroup;
PUBLIC uint8 u8TimerPoll;
PUBLIC uint8 u8TimerZCL;
#ifdef DR1199
PUBLIC uint8 u8TimerButtonScan;
#endif

PUBLIC tszQueue APP_msgAppEvents;
PUBLIC tszQueue APP_msgBdbEvents;
#ifdef DR1199
PUBLIC tszQueue APP_msgSerialTx;
PUBLIC tszQueue APP_msgSerialRx;
#endif

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

PRIVATE ZTIMER_tsTimer asTimers[APP_ZTIMER_STORAGE + BDB_ZTIMER_STORAGE];

PRIVATE zps_tsTimeEvent asTimeEvent[TIMER_QUEUE_SIZE];
PRIVATE MAC_tsMcpsVsDcfmInd asMacMcpsDcfmInd[MCPS_QUEUE_SIZE];
PRIVATE MAC_tsMlmeVsDcfmInd asMacMlmeVsDcfmInd[MLME_QUEQUE_SIZE];
PRIVATE BDB_tsZpsAfEvent asBdbEvent[BDB_QUEUE_SIZE];
PRIVATE APP_tsEvent asAppEvent[APP_QUEUE_SIZE];
PRIVATE MAC_tsMcpsVsCfmData asMacMcpsDcfm[MCPS_DCFM_QUEUE_SIZE];

#ifdef DR1199
PRIVATE uint8               au8TxBuffer[TX_QUEUE_SIZE];
PRIVATE uint8               au8RxBuffer[RX_QUEUE_SIZE];
#endif


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

#ifdef DR1199
        APP_taskAtSerial();
#endif

        APP_taskController();

        /* Re-load the watch-dog timer. Execution must return through the idle
         * task before the CPU is suspended by the power manager. This ensures
         * that at least one task / ISR has executed within the watchdog period
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

#ifdef DR1199
    vAHI_Uart0RegisterCallback ( APP_isrUart );
#endif
    vAHI_SysCtrlRegisterCallback ( vISR_SystemController );
    u32AHI_Init();
    vAHI_InterruptSetPriority ( MICRO_ISR_MASK_BBC,        NVIC_INT_PRIO_LEVEL_BBC );
#ifdef DR1199
    vAHI_InterruptSetPriority ( MICRO_ISR_MASK_UART0,   NVIC_INT_PRIO_LEVEL_UART0 );
#endif
    vAHI_InterruptSetPriority ( MICRO_ISR_MASK_SYSCTRL, NVIC_INT_PRIO_LEVEL_SYSCTRL );
#endif

#if (JENNIC_CHIP_FAMILY == JN516x)
    TARGET_INITIALISE();
    /* clear interrupt priority level  */
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
    ZTIMER_eOpen(&u8TimerLedBlink,      APP_cbTimerLedBlink,    NULL, ZTIMER_FLAG_PREVENT_SLEEP);
    ZTIMER_eOpen(&u8TimerId,            APP_cbTimerId,          NULL, ZTIMER_FLAG_PREVENT_SLEEP);
    ZTIMER_eOpen(&u8TimerAddGroup,      APP_cbTimerAddGroup,    NULL, ZTIMER_FLAG_PREVENT_SLEEP);
    ZTIMER_eOpen(&u8TimerPoll,          APP_cbTimerPoll,        NULL, ZTIMER_FLAG_PREVENT_SLEEP);
    ZTIMER_eOpen(&u8TimerZCL,           APP_cbTimerZclTick,     NULL, ZTIMER_FLAG_PREVENT_SLEEP);

#ifdef DR1199
    ZTIMER_eOpen(&u8TimerButtonScan,    APP_cbTimerButtonScan,  NULL, ZTIMER_FLAG_PREVENT_SLEEP);
#endif

    /* Create all the queues */
    ZQ_vQueueCreate(&APP_msgBdbEvents,        BDB_QUEUE_SIZE,         sizeof(BDB_tsZpsAfEvent),   (uint8*)asBdbEvent);
    ZQ_vQueueCreate(&APP_msgAppEvents,        APP_QUEUE_SIZE,         sizeof(APP_tsEvent),        (uint8*)asAppEvent);
    ZQ_vQueueCreate(&zps_msgMlmeDcfmInd,      MLME_QUEQUE_SIZE,       sizeof(MAC_tsMlmeVsDcfmInd),(uint8*)asMacMlmeVsDcfmInd);
    ZQ_vQueueCreate(&zps_msgMcpsDcfmInd,      MCPS_QUEUE_SIZE,        sizeof(MAC_tsMcpsVsDcfmInd),(uint8*)asMacMcpsDcfmInd);
    ZQ_vQueueCreate(&zps_TimeEvents,          TIMER_QUEUE_SIZE,       sizeof(zps_tsTimeEvent),    (uint8*)asTimeEvent);
    ZQ_vQueueCreate(&zps_msgMcpsDcfm, 		  MCPS_DCFM_QUEUE_SIZE,	  sizeof(MAC_tsMcpsVsCfmData),(uint8*)asMacMcpsDcfm);

#ifdef DR1199
    ZQ_vQueueCreate(&APP_msgSerialTx,            TX_QUEUE_SIZE,   sizeof(uint8),    (uint8*)au8TxBuffer);
        ZQ_vQueueCreate(&APP_msgSerialRx,            RX_QUEUE_SIZE,   sizeof(uint8),    (uint8*)au8RxBuffer);
#endif
}

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

/*****************************************************************************
 *
 * MODULE:             JN-AN-1219
 *
 * COMPONENT:          app_buttons.c
 *
 * DESCRIPTION:        DK4 (DR1175/DR1199) Button Press detection (Implementation)
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
#include "dbg.h"
#include "AppHardwareApi.h"
#include "app_events.h"
#include "ZQueue.h"
#include "ZTimer.h"
#include "pwrm.h"
#include "app_buttons.h"
#include "app_main.h"
#include "app_zlo_switch_node.h"
#include "PDM.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifndef DEBUG_APP_BUTTON
    #define TRACE_APP_BUTTON            FALSE
#else
    #define TRACE_APP_BUTTON            TRUE
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

#if (defined BUTTON_MAP_DR1199)
    #if (defined APP_NTAG_ICODE) || (defined APP_NTAG_AES)
        PRIVATE uint8 s_u8ButtonDebounce[APP_BUTTONS_NUM] = { 0xff,0xff,0xff,0xff,0xff,0xff };
        PRIVATE uint8 s_u8ButtonState[APP_BUTTONS_NUM] = { 0,0,0,0,0,0 };
        PRIVATE const uint8 s_u8ButtonDIOLine[APP_BUTTONS_NUM] =
        {
            APP_BUTTONS_BUTTON_1,
            APP_BUTTONS_BUTTON_SW1,
            APP_BUTTONS_BUTTON_SW2,
            APP_BUTTONS_BUTTON_SW3,
            APP_BUTTONS_BUTTON_SW4,
        };
    #else
        PRIVATE uint8 s_u8ButtonDebounce[APP_BUTTONS_NUM] = { 0xff,0xff};
        PRIVATE uint8 s_u8ButtonState[APP_BUTTONS_NUM] = { 0,0};
        PRIVATE const uint8 s_u8ButtonDIOLine[APP_BUTTONS_NUM] =
        {
            APP_BUTTONS_BUTTON_1,
            APP_BUTTONS_BUTTON_SW1
        };
    #endif
#else
    PRIVATE uint8 s_u8ButtonDebounce[APP_BUTTONS_NUM] = { 0xff};
    PRIVATE uint8 s_u8ButtonState[APP_BUTTONS_NUM] = {0};
    PRIVATE const uint8 s_u8ButtonDIOLine[APP_BUTTONS_NUM] =
    {
        APP_BUTTONS_BUTTON_1
    };
#endif


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
PUBLIC bool_t APP_bButtonInitialise(void)
{
    /* Set DIO lines to inputs with buttons connected */
    vAHI_DioSetDirection(APP_BUTTONS_DIO_MASK, 0);

    /* Turn on pull-ups for DIO lines with buttons connected */
    vAHI_DioSetPullup((1 << APP_BUTTONS_BUTTON_1), (1 << APP_BUTTONS_BUTTON_SW1));

    /* Set the edge detection for falling edges */
    vAHI_DioInterruptEdge(0, APP_BUTTONS_DIO_MASK);

    /* Enable interrupts to occur on selected edge */
    vAHI_DioInterruptEnable(APP_BUTTONS_DIO_MASK, 0);

    uint32 u32Buttons = u32AHI_DioReadInput() & APP_BUTTONS_DIO_MASK;

    /* If we came out of deep sleep; perform appropriate action as well based
       on button press.*/
    APP_cbTimerButtonScan(NULL);

    if (u32Buttons != APP_BUTTONS_DIO_MASK)
    {
        return TRUE;
    }
    return FALSE;
}


/****************************************************************************
 *
 * NAME: vISR_SystemController (JN516x version)
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
#if (JENNIC_CHIP_FAMILY == JN516x)
PUBLIC void vISR_SystemController(void)
{
#ifdef SLEEP_ENABLE
    teInterruptType eInterruptType = E_INTERRUPT_UNKNOWN;
#endif
    /* clear pending DIO changed bits by reading register */
    uint8 u8WakeInt = u8AHI_WakeTimerFiredStatus();
    uint32 u32IOStatus = u32AHI_DioInterruptStatus();

    DBG_vPrintf(TRACE_APP_BUTTON, "In vISR_SystemController\n");

    if(u32IOStatus & APP_BUTTONS_DIO_MASK)
    {
        DBG_vPrintf(TRACE_APP_BUTTON, "u32IOStatus & APP_BUTTONS_DIO_MASK\n");
        /* disable edge detection until scan complete */
        vAHI_DioInterruptEnable(0, APP_BUTTONS_DIO_MASK);
        ZTIMER_eStop(u8TimerButtonScan);
        ZTIMER_eStart(u8TimerButtonScan, ZTIMER_TIME_MSEC(10));
#ifdef SLEEP_ENABLE
        eInterruptType = E_INTERRUPT_BUTTON;
#endif
    }

    if (u8WakeInt & E_AHI_WAKE_TIMER_MASK_1)
    {
        /* wake timer interrupt got us here */
        DBG_vPrintf(TRACE_APP_BUTTON, "APP: Wake Timer 1 Interrupt\n");
#ifdef SLEEP_ENABLE
        eInterruptType = E_INTERRUPT_WAKE_TIMER_EXPIRY;
        PWRM_vWakeInterruptCallback();
#endif

    }
#ifdef SLEEP_ENABLE
    vManageWakeUponSysControlISR(eInterruptType);
#endif

}
#endif

#if (JENNIC_CHIP_FAMILY == JN517x)
/****************************************************************************
 *
 * NAME: vISR_SystemController (JN517x version)
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
PUBLIC void vISR_SystemController(uint32 u32DeviceId, uint32 u32BitMap)
{
#ifdef SLEEP_ENABLE
    teInterruptType eInterruptType = E_INTERRUPT_UNKNOWN;
#endif

    DBG_vPrintf(TRACE_APP_BUTTON, "In vISR_SystemController Device %08x BitMap %08x\n",
            u32DeviceId,
            u32BitMap );

    if(u32BitMap & APP_BUTTONS_DIO_MASK)
    {
        DBG_vPrintf(TRACE_APP_BUTTON, "u32IOStatus & APP_BUTTONS_DIO_MASK\n");
        /* disable edge detection until scan complete */
        vAHI_DioInterruptEnable(0, APP_BUTTONS_DIO_MASK);
        ZTIMER_eStop(u8TimerButtonScan);
        ZTIMER_eStart(u8TimerButtonScan, ZTIMER_TIME_MSEC(10));
#ifdef SLEEP_ENABLE
        eInterruptType = E_INTERRUPT_BUTTON;
#endif
    }

    if (u32BitMap & E_AHI_SYSCTRL_WK1_MASK)
    {
        /* wake timer interrupt got us here */
        DBG_vPrintf(TRACE_APP_BUTTON, "APP: Wake Timer 1 Interrupt\n");
#ifdef SLEEP_ENABLE
        eInterruptType = E_INTERRUPT_WAKE_TIMER_EXPIRY;
        PWRM_vWakeInterruptCallback();
#endif

    }
#ifdef SLEEP_ENABLE
    vManageWakeUponSysControlISR(eInterruptType);
#endif

}
#endif

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
PUBLIC void ISR_vTimer2(void)
{

}


/****************************************************************************
 *
 * NAME: APP_cbTimerButtonScan
 *
 * DESCRIPTION:
 * Button scan task -only present on NON SSL builds
 *
 * PARAMETER:
 *
 * RETURNS:
 *
 ****************************************************************************/
PUBLIC void APP_cbTimerButtonScan(void *pvParam)
{
    /*
     * The DIO changed status register is reset here before the scan is performed.
     * This avoids a race condition between finishing a scan and re-enabling the
     * DIO to interrupt on a falling edge.
     */
    (void) u32AHI_DioInterruptStatus();

    uint8 u8AllReleased = 0xff;
    unsigned int i;
    uint32 u32DIOState = u32AHI_DioReadInput() & APP_BUTTONS_DIO_MASK;


    for (i = 0; i < APP_BUTTONS_NUM; i++)
    {
        uint8 u8Button = (uint8) ((u32DIOState >> s_u8ButtonDIOLine[i]) & 1);

        s_u8ButtonDebounce[i] <<= 1;
        s_u8ButtonDebounce[i] |= u8Button;
        u8AllReleased &= s_u8ButtonDebounce[i];

        if (0 == s_u8ButtonDebounce[i] && !s_u8ButtonState[i])
        {
            s_u8ButtonState[i] = TRUE;

            /*
             * button consistently depressed for 8 scan periods
             * so post message to application task to indicate
             * a button down event
             */
            APP_tsEvent sButtonEvent;
            sButtonEvent.eType = APP_E_EVENT_BUTTON_DOWN;
            sButtonEvent.uEvent.sButton.u8Button = i;
            sButtonEvent.uEvent.sButton.u32DIOState=u32DIOState;
            DBG_vPrintf(TRACE_APP_BUTTON, "Button DN=%d\n", i);

            ZQ_bQueueSend(&APP_msgAppEvents, &sButtonEvent);
        }
        else if (0xff == s_u8ButtonDebounce[i] && s_u8ButtonState[i] != FALSE)
        {
            s_u8ButtonState[i] = FALSE;

            /*
             * button consistently released for 8 scan periods
             * so post message to application task to indicate
             * a button up event
             */
            APP_tsEvent sButtonEvent;
            sButtonEvent.eType = APP_E_EVENT_BUTTON_UP;
            sButtonEvent.uEvent.sButton.u8Button = i;
            sButtonEvent.uEvent.sButton.u32DIOState=u32DIOState;
            DBG_vPrintf(TRACE_APP_BUTTON, "Button UP=%i\n", i);

            ZQ_bQueueSend(&APP_msgAppEvents, &sButtonEvent);
        }
    }

    if (0xff == u8AllReleased)
    {
        /*
         * all buttons high so set dio to interrupt on change
         */
        DBG_vPrintf(TRACE_APP_BUTTON, "ALL UP\n", i);
        vAHI_DioInterruptEnable(APP_BUTTONS_DIO_MASK, 0);
        ZTIMER_eStop(u8TimerButtonScan);

        APP_tsEvent sButtonEvent;
        sButtonEvent.eType = APP_E_EVENT_BUTTON_ALL_UP;
        sButtonEvent.uEvent.sButton.u8Button = 0;		//don't care
        sButtonEvent.uEvent.sButton.u32DIOState=0;		//don't care
        ZQ_bQueueSend(&APP_msgAppEvents, &sButtonEvent);			
    }
    else
    {
        /*
         * one or more buttons is still depressed so continue scanning
         */
        ZTIMER_eStart(u8TimerButtonScan, ZTIMER_TIME_MSEC(10));
    }
}

PUBLIC void APP_cbTimerButtonLongPressed(void *pvParam)
{
	DBG_vPrintf(TRACE_APP_BUTTON, "Reset Factory New\n");

	//blink LED indicate reset factory new
	
	
	PDM_vDeleteAllDataRecords();
	vAHI_SwReset();
}


/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

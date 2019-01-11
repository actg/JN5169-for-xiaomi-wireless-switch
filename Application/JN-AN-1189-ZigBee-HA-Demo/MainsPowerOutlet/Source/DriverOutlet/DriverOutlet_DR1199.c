/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          DriverOutlet_DR1199.c
 *
 * DESCRIPTION:        ZHA Demo Driver Mains Power Outlet - Implementation
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
 * Copyright NXP B.V. 2015. All rights reserved
 *
 ***************************************************************************/
/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
/* SDK includes */
#include <jendefs.h>
/* Hardware includes */
#include <AppHardwareApi.h>
/* Device includes */
#include "DriverOutlet.h"
/* RTOS include */
#include <os.h>
#include <os_gen.h>
#include <dbg.h>
#include <app_timer_driver.h>
#include <app_events.h>

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
/* DIO for the DR1199 board */
#define OUTPUT_DIO                    16    /* LED D1 on DR1199 */
#define OUTPUT_DIO_MASK                (1UL << OUTPUT_DIO)
#define STATUS_LED_DIO                13    /* LED D2 on DR1199 */
#define STATUS_LED_DIO_MASK            (1UL << STATUS_LED_DIO)
#define ON_OFF_BUTTON_DIO            11     /* SW1 on DR1199 */
#define ON_OFF_BUTTON_DIO_MASK        (1UL << ON_OFF_BUTTON_DIO)

#ifndef DEBUG_DRIVER_OUTLET
    #define TRACE_DRIVER_OUTLET        FALSE
#else
    #define TRACE_DRIVER_OUTLET        TRUE
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
/***        Global Variables                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
PRIVATE bool_t bOutputOn        = FALSE;
PRIVATE bool_t bStatusLedOn     = FALSE;
PRIVATE uint8 u8ButtonDebounce     = 0xFF;
PRIVATE uint8 u8ButtonState     = 0;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
/****************************************************************************
 *
 * NAMES:
 *
 * DESCRIPTION:
 *
 * PARAMETERS:      Name     RW  Usage
 *
 * RETURNS:
 *
 ****************************************************************************/
PUBLIC void DriverOutlet_vInit(void)
{
    /* Set DIO that drive the status LED and on/off relay to outputs */
    vAHI_DioSetDirection(0, (OUTPUT_DIO_MASK + STATUS_LED_DIO_MASK));

    /* Set DIO used to read on/off button to an input */
    vAHI_DioSetDirection(ON_OFF_BUTTON_DIO_MASK, 0);
    vAHI_DioSetPullup(ON_OFF_BUTTON_DIO_MASK, 0);

    /* Set the edge detection for falling edges */
    vAHI_DioInterruptEdge(0, ON_OFF_BUTTON_DIO_MASK);

    /* Enable interrupts to occur on selected edge */
    vAHI_DioInterruptEnable(ON_OFF_BUTTON_DIO_MASK, 0);
}

/****************************************************************************
 *
 * NAMES:
 *
 * DESCRIPTION:
 *
 * PARAMETERS:      Name     RW  Usage
 *
 * RETURNS:
 *
 ****************************************************************************/
PUBLIC void DriverOutlet_vOutputOn(void)
{
    DriverOutlet_vSetOutputOnOff(TRUE);
}

/****************************************************************************
 *
 * NAMES:
 *
 * DESCRIPTION:
 *
 * PARAMETERS:      Name     RW  Usage
 *
 * RETURNS:
 *
 ****************************************************************************/
PUBLIC void DriverOutlet_vOutputOff(void)
{
    DriverOutlet_vSetOutputOnOff(FALSE);
}

/****************************************************************************
 *
 * NAMES:
 *
 * DESCRIPTION:
 *
 * PARAMETERS:      Name     RW  Usage
 *
 * RETURNS:
 *
 ****************************************************************************/
PUBLIC void DriverOutlet_vSetOutputOnOff(bool_t bOn)
{
    if (bOn == TRUE)
    {
        vAHI_DioSetOutput(0, OUTPUT_DIO_MASK);
        DriverOutlet_vStatusLedOn();
    }
    else
    {
        vAHI_DioSetOutput(OUTPUT_DIO_MASK, 0);
        DriverOutlet_vStatusLedOff();
    }
    bOutputOn = bOn;
}

/****************************************************************************
 *
 * NAMES:
 *
 * DESCRIPTION:
 *
 * PARAMETERS:      Name     RW  Usage
 *
 * RETURNS:
 *
 ****************************************************************************/
PUBLIC bool_t DriverOutlet_bIsOutputOn(void)
{
    return (bOutputOn);
}

/****************************************************************************
 *
 * NAMES:
 *
 * DESCRIPTION:
 *
 * PARAMETERS:      Name     RW  Usage
 *
 * RETURNS:
 *
 ****************************************************************************/
PUBLIC void DriverOutlet_vStatusLedOn(void)
{
    DriverOutlet_vSetStatusLedOnOff(TRUE);
}

/****************************************************************************
 *
 * NAMES:
 *
 * DESCRIPTION:
 *
 * PARAMETERS:      Name     RW  Usage
 *
 * RETURNS:
 *
 ****************************************************************************/
PUBLIC void DriverOutlet_vStatusLedOff(void)
{
    DriverOutlet_vSetStatusLedOnOff(FALSE);
}

/****************************************************************************
 *
 * NAMES:
 *
 * DESCRIPTION:
 *
 * PARAMETERS:      Name     RW  Usage
 *
 * RETURNS:
 *
 ****************************************************************************/
PUBLIC bool_t DriverOutlet_bIsStatusLedOn(void)
{
    return (bStatusLedOn);
}

/****************************************************************************
 *
 * NAMES:
 *
 * DESCRIPTION:
 *
 * PARAMETERS:      Name     RW  Usage
 *
 * RETURNS:
 *
 ****************************************************************************/
PUBLIC void DriverOutlet_vSetStatusLedOnOff(bool_t bOn)
{
    if (bOn == TRUE)
    {
        vAHI_DioSetOutput(STATUS_LED_DIO_MASK, 0);
    }
    else
    {
        vAHI_DioSetOutput(0, STATUS_LED_DIO_MASK);
    }
    bStatusLedOn = bOn;
}

/****************************************************************************
 *
 * NAMES:
 *
 * DESCRIPTION:
 *
 * PARAMETERS:      Name     RW  Usage
 *
 * RETURNS:
 *
 ****************************************************************************/
PUBLIC bool_t DriverOutlet_bIsButtonDown(void)
{
    bool_t bResult = FALSE;

    uint32 u32DioState = u32AHI_DioReadInput() & ON_OFF_BUTTON_DIO_MASK;

    if (u32DioState != ON_OFF_BUTTON_DIO_MASK)
    {
        bResult = TRUE;
    }
    return bResult;
}

/****************************************************************************
 *
 * NAMES:
 *
 * DESCRIPTION:
 *
 * PARAMETERS:      Name     RW  Usage
 *
 * RETURNS:
 *
 ****************************************************************************/
OS_ISR(vISR_SystemController)
{
    /* Clear pending DIO changed bits by reading register */
    uint32 u32DioIntStatus = u32AHI_DioInterruptStatus();

    DBG_vPrintf(TRACE_DRIVER_OUTLET, "\n\rvISR_SystemController - DioIntStatus: 0x%x", u32DioIntStatus);

    if(u32DioIntStatus & ON_OFF_BUTTON_DIO_MASK)
    {
        /* Disable edge detection until scan complete */
        vAHI_DioInterruptEnable(0, ON_OFF_BUTTON_DIO_MASK);
        OS_eStartSWTimer(DriverOutlet_ButtonScanTimer, APP_TIME_MS(10), NULL);
    }
}

/****************************************************************************
 *
 * NAMES:
 *
 * DESCRIPTION:
 *
 * PARAMETERS:      Name     RW  Usage
 *
 * RETURNS:
 *
 ****************************************************************************/
OS_TASK(DriverOutlet_vButtonScanTask)
{
    /* The DIO changed status register is reset here before the scan is
       performed. This avoids a race condition between finishing a scan and
       re-enabling the DIO to interrupt on a falling edge. */
    (void)u32AHI_DioInterruptStatus();

    /* Read current button state */
    uint32 u32DioState = u32AHI_DioReadInput() & ON_OFF_BUTTON_DIO_MASK;
    uint8  u8Button = (uint8)((u32DioState >> ON_OFF_BUTTON_DIO) & 1UL);

    /* Debounce.. */
    u8ButtonDebounce <<= 1;
    u8ButtonDebounce  |= u8Button;

    if ((0x00 == u8ButtonDebounce) && (0 == u8ButtonState))
    {
        u8ButtonState = TRUE;

        /* Button consistently depressed for 8 scan periods so post message
           to application task to indicate a button down event. */
        APP_tsEvent sButtonEvent;
        sButtonEvent.eType = APP_E_EVENT_BUTTON_DOWN;
        sButtonEvent.uEvent.sButton.u8Button = DRIVEROUTLET_ON_OFF_BUTTON_ID;
        sButtonEvent.uEvent.sButton.u32DIOState = u32DioState;

        DBG_vPrintf(TRACE_DRIVER_OUTLET, "\n\rDriverOutlet_vButtonScanTask - Button DN\n");

        OS_ePostMessage(APP_msgEvents, &sButtonEvent);

        /* Button is still depressed so continue scanning... */
        OS_eContinueSWTimer(DriverOutlet_ButtonScanTimer, APP_TIME_MS(10), NULL);
    }
    else if ((0xFF == u8ButtonDebounce) && (u8ButtonState != 0))
    {
        u8ButtonState = FALSE;

        /* Button consistently released for 8 scan periods so post message
           to application task to indicate a button up event. */
        APP_tsEvent sButtonEvent;
        sButtonEvent.eType = APP_E_EVENT_BUTTON_UP;
        sButtonEvent.uEvent.sButton.u8Button = DRIVEROUTLET_ON_OFF_BUTTON_ID;
        sButtonEvent.uEvent.sButton.u32DIOState = u32DioState;

        DBG_vPrintf(TRACE_DRIVER_OUTLET, "\n\rDriverOutlet_vButtonScanTask - Button UP\n");

        OS_ePostMessage(APP_msgEvents, &sButtonEvent);

        if(OS_eGetSWTimerStatus(DriverOutlet_ButtonScanTimer) != OS_E_SWTIMER_STOPPED)
        {
            OS_eStopSWTimer(DriverOutlet_ButtonScanTimer);
        }

        /* Re-enable the DIO button interrupt no scanning is complete */
        vAHI_DioInterruptEnable(ON_OFF_BUTTON_DIO_MASK, 0);
    }
    else /* Button changed state but not debounced so keep scanning */
    {
        OS_eContinueSWTimer(DriverOutlet_ButtonScanTimer, APP_TIME_MS(10), NULL);
    }
}

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

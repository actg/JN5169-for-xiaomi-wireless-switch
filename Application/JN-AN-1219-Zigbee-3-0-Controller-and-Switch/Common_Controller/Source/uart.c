/****************************************************************************
 *
 * MODULE:             UART
 *
 * COMPONENT:          Uart interface for BDB Application Template AN1217 (Coorinator)
 *
 * VERSION:
 *
 * REVISION:
 *
 * DATED:
 *
 * STATUS:
 *
 * AUTHOR:
 *
 * DESCRIPTION:        Hardware abstarction layer for UART peripheral
 *
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
 * Copyright NXP B.V. 2016. All rights reserved
 *
 ****************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#include <jendefs.h>
#include "AppHardwareApi.h"

#include "dbg.h"

#include "uart.h"
#include "ZQueue.h"
#include "app_main.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#ifndef TRACE_UART
#define TRACE_UART  TRUE
#endif

/* default to uart 0 */
#ifndef UART
#define UART E_AHI_UART_0
#endif

#if (UART != E_AHI_UART_0 && UART != E_AHI_UART_1)
#error UART must be either 0 or 1
#endif

/* default BAUD rate 9600 */
#ifndef UART_BAUD_RATE
#define UART_BAUD_RATE        115200
#endif

#define UART_LCR_OFFSET     0x0C
#define UART_DLM_OFFSET     0x04

#if JENNIC_CHIP_FAMILY == JN513x

#if (UART == E_AHI_UART_0)
#define UART_START_ADR      0x30000000UL
#elif (UART == E_AHI_UART_1)
#define UART_START_ADR      0x40000000UL
#endif

#elif JENNIC_CHIP_FAMILY == JN514x

#if (UART == E_AHI_UART_0)
#define UART_START_ADR      0x02003000UL
#elif (UART == E_AHI_UART_1)
#define UART_START_ADR      0x02004000UL
#endif
#elif JENNIC_CHIP_FAMILY == JN516x
#if (UART == E_AHI_UART_0)
#define UART_START_ADR      0x02003000UL
#elif (UART == E_AHI_UART_1)
#define UART_START_ADR      0x02004000UL
#endif
#elif JENNIC_CHIP_FAMILY == JN517x
#if (UART == E_AHI_UART_0)
#define UART_START_ADR      0x40004000UL
#elif (UART == E_AHI_UART_1)
#define UART_START_ADR      0x40005000UL
#endif
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

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

/****************************************************************************
 *
 * NAME: vUART_Init
 *
 * DESCRIPTION:
 *
 * PARAMETERS:      Name            RW  Usage
 * None.
 *
 * RETURNS:
 * None.
 *
 * NOTES:
 * None.
 ****************************************************************************/
PUBLIC void UART_vInit(void)
{
    DBG_vPrintf(TRACE_UART, "Initialising UART ...");

    /* Enable UART 0 */
    vAHI_UartEnable(UART);

    vAHI_UartReset(UART, TRUE, TRUE);
    vAHI_UartReset(UART, FALSE, FALSE);

    /* Set the clock divisor register to give required buad, this has to be done
       directly as the normal routines (in ROM) do not support all baud rates */
    UART_vSetBaudRate(UART_BAUD_RATE);

    vAHI_UartSetRTSCTS(UART, TRUE);
    vAHI_UartSetControl(UART, FALSE, FALSE, E_AHI_UART_WORD_LEN_8, TRUE, FALSE); /* [I SP001222_P1 279] */
    vAHI_UartSetInterrupt(UART, FALSE, FALSE, FALSE, TRUE, E_AHI_UART_FIFO_LEVEL_1);    // No TX ints!

    DBG_vPrintf(TRACE_UART, "Done\n");
}

/****************************************************************************
 *
 * NAME: vUART_SetBuadRate
 *
 * DESCRIPTION:
 *
 * PARAMETERS: Name        RW  Usage
 *
 * RETURNS:
 *
 ****************************************************************************/

PUBLIC void UART_vSetBaudRate(uint32 u32BaudRate)
{
    uint16 u16Divisor;
    uint32 u32Remainder;

    /* Divisor  = 16MHz / (16 x baud rate) */
    u16Divisor = (uint16)(16000000UL / (16UL * u32BaudRate));

    /* Correct for rounding errors */
    u32Remainder = (uint32)(16000000UL % (16UL * u32BaudRate));

    if (u32Remainder >= ((16UL * u32BaudRate) / 2))
    {
        u16Divisor += 1;
    }

    vAHI_UartSetBaudDivisor(UART, u16Divisor);
}

/****************************************************************************
 *
 * NAME: UartIsr
 *
 * DESCRIPTION: Handle interrupts from uart
 *
 * PARAMETERS:      Name            RW  Usage
 * None.
 *
 * RETURNS:
 * None.
 *
 * NOTES:
 * None.
 ****************************************************************************/
#if (JENNIC_CHIP_FAMILY == JN516x)
PUBLIC void APP_isrUart(void)
{
    unsigned int irq = ((*((volatile uint32 *)(UART_START_ADR + 0x08))) >> 1) & 0x0007;
    uint8 u8Byte;

    if (irq & E_AHI_UART_INT_RXDATA) {
        uint8 u8Byte = u8AHI_UartReadData(UART);
        if(ZQ_bQueueSend(&APP_msgSerialRx, &u8Byte) == FALSE)
        {
            /* Failed to send the message to queue */
        }
    }

    if (irq & E_AHI_UART_INT_TX) {
        if(ZQ_bQueueReceive(&APP_msgSerialTx, &u8Byte) == TRUE)
        {
            vAHI_UartWriteData(UART, u8Byte);
            /* decrement activity counter for dequeued data */
        } else {
            /* disable tx interrupt as nothing to send */
            UART_vSetTxInterrupt(FALSE);
        }
    }
}
#endif

#if (JENNIC_CHIP_FAMILY == JN517x)
PUBLIC void APP_isrUart (uint32 u32Device, uint32 u32ItemBitmap)
{

   if (((UART == E_AHI_UART_0) && (u32Device == E_AHI_DEVICE_UART0)) ||
       ((UART == E_AHI_UART_1) && (u32Device == E_AHI_DEVICE_UART1)))
   {
       uint8 u8Byte;
       if ((u32ItemBitmap & 0x000000FF) & E_AHI_UART_INT_RXDATA) {
           uint8 u8Byte = u8AHI_UartReadData(UART);

           ZQ_bQueueSend(&APP_msgSerialRx, &u8Byte);
       }
       else if (u32ItemBitmap == E_AHI_UART_INT_TX) {

           if (TRUE == ZQ_bQueueReceive(&APP_msgSerialTx, &u8Byte)) {
               vAHI_UartWriteData(UART, u8Byte);
           } else {
               /* disable tx interrupt as nothing to send */
               UART_vSetTxInterrupt(FALSE);
           }
       }

   }
}
#endif


/****************************************************************************
 *
 * NAME: UART_vRtsStopFlow
 *
 * DESCRIPTION:
 * Set UART RS-232 RTS line high to stop any further data coming in
 *
 ****************************************************************************/

PUBLIC void UART_vRtsStopFlow(void)
{
    vAHI_UartSetControl(UART, FALSE, FALSE, E_AHI_UART_WORD_LEN_8, TRUE, E_AHI_UART_RTS_HIGH);
}

/****************************************************************************
 *
 * NAME: UART_vRtsStartFlow
 *
 * DESCRIPTION:
 * Set UART RS-232 RTS line low to allow further data
 *
 ****************************************************************************/

PUBLIC void UART_vRtsStartFlow(void)
{
    vAHI_UartSetControl(UART, FALSE, FALSE, E_AHI_UART_WORD_LEN_8, TRUE, E_AHI_UART_RTS_LOW);
}
/* [I SP001222_P1 283] end */

/****************************************************************************
 *
 * NAME: vUART_TxChar
 *
 * DESCRIPTION:
 * Set UART RS-232 RTS line low to allow further data
 *
 ****************************************************************************/
PUBLIC void UART_vTxChar(uint8 u8Char)
{
    vAHI_UartWriteData(UART, u8Char);
}

/****************************************************************************
 *
 * NAME: vUART_TxReady
 *
 * DESCRIPTION:
 * Set UART RS-232 RTS line low to allow further data
 *
 ****************************************************************************/
PUBLIC bool_t UART_bTxReady()
{
    return u8AHI_UartReadLineStatus(UART) & E_AHI_UART_LS_THRE;
}

/****************************************************************************
 *
 * NAME: vUART_SetTxInterrupt
 *
 * DESCRIPTION:
 * Enable / disable the tx interrupt
 *
 ****************************************************************************/
PUBLIC void UART_vSetTxInterrupt(bool_t bState)
{
    vAHI_UartSetInterrupt(UART, FALSE, FALSE, bState, TRUE, E_AHI_UART_FIFO_LEVEL_1);
}

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

/*****************************************************************************
 *
 * MODULE:             JN-AN-1217
 *
 * COMPONENT:          app_serial_commands.c
 *
 * DESCRIPTION:        Base Device Serial Commands: Coordinator application
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
 ***************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#include <jendefs.h>
#include "dbg.h"
#include "pwrm.h"
#include "zps_gen.h"
//#include "app_coordinator.h"
//#include "app_zcl_task.h"
#include "app_buttons.h"
#include "app_common.h"
#include "app_serial_interface.h"
#include "app_events.h"
#include "app_main.h"
#include "ZQueue.h"
#include "ZTimer.h"
#include "app_events.h"
#include "ZQueue.h"
#include "app_menu_handler.h"
#include "portmacro.h"
#include "uart.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifdef DEBUG_SERIAL
    #define TRACE_SERIAL      TRUE
    #define DEBUG_SL          TRUE
#else
    #define TRACE_SERIAL      FALSE
    #define DEBUG_SL           FALSE
#endif


/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
#define SL_WRITE(DATA)        bPutChar(DATA)

#define SL_START_CHAR          0x01
#define SL_ESC_CHAR            0x02
#define SL_END_CHAR            0x03


/** Enumerated list of states for receive state machine */
typedef enum
{
    E_STATE_RX_WAIT_START,
    E_STATE_RX_WAIT_TYPE,
    E_STATE_RX_WAIT_LEN,
    E_STATE_RX_WAIT_CRC,
    E_STATE_RX_WAIT_DATA,
}teSL_RxState;

#define RX_BUFFER_SIZE  8
typedef struct {
    uint8 au8Buffer[RX_BUFFER_SIZE];
    uint8 u8MsgType;
    uint8 u8MsgLength;
     uint8 u8CRC;
    uint8 u8Bytes;
    bool bInEsc;
}tsRxMessage;

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
PRIVATE void vSL_ProcessRxChar(uint8 u8Char);
PRIVATE bool bSL_ReadMessage(tsRxMessage * psRxMessage, uint8 u16MaxLength, uint8 u8Data);
PRIVATE void vSL_TxByte(bool bSpecialCharacter, uint8 u8Data);
PRIVATE uint8 u8SL_CalculateCRC(uint16 u16Type, uint16 u16Length, uint8 *pu8Data);

PUBLIC bool_t bPutChar( uint8    u8TxByte );
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
PRIVATE tsRxMessage sRxMessage;
PRIVATE tsMicroIntStorage    sStorage;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

/******************************************************************************
 * NAME: APP_taskAtParser
 *
 * DESCRIPTION:
 *
 *
 * PARAMETERS:      Name            Usage
 *
 * RETURNS:
 * None
 ****************************************************************************/
PUBLIC void APP_taskAtSerial( void)
{
    uint8 u8RxByte;
    if (ZQ_bQueueReceive(&APP_msgSerialRx, &u8RxByte) == TRUE)
    {
        vSL_ProcessRxChar(u8RxByte);
    }
}

/******************************************************************************
 * NAME: vSL_ProcessRxChar
 *
 * DESCRIPTION:
 * Processes the received character
 *
 * PARAMETERS:      Name            Usage
 * uint8            u8Char          Character
 *
 * RETURNS:
 * None
 ****************************************************************************/
PRIVATE void vSL_ProcessRxChar(uint8 u8Data)
{

    if (bSL_ReadMessage( &sRxMessage, RX_BUFFER_SIZE, u8Data))
    {
        // process complete message
        /*
         * only interested in key press messages
         */
        if (sRxMessage.u8MsgType == SERIAL_MSG_TYPE_BUTTON)
        {
            /*
             * Validatethe the key data before generating an
             * application event.
             * either an up or down event
             * And button number 0..15
             */
            if ( ((sRxMessage.au8Buffer[0] == APP_E_EVENT_BUTTON_DOWN) || (sRxMessage.au8Buffer[0] == APP_E_EVENT_BUTTON_UP))
                  &&
                  (sRxMessage.au8Buffer[1] < 16) )
            {
                APP_tsEvent sButtonEvent;
                sButtonEvent.eType = sRxMessage.au8Buffer[0];
                /* offset the button code to avoid confusion with the hardware switches */
                sButtonEvent.uEvent.sButton.u8Button = sRxMessage.au8Buffer[1] + KEY_1;
                sButtonEvent.uEvent.sButton.u32DIOState = 0;
                DBG_vPrintf(DEBUG_SL, "Button %d DN=%d\n",
                        sButtonEvent.uEvent.sButton.u8Button,
                        sButtonEvent.eType);

                ZQ_bQueueSend(&APP_msgAppEvents, &sButtonEvent);
            }
        }
    }
}

/****************************************************************************
 *
 * NAME: bSL_ReadMessage
 *
 * DESCRIPTION:
 * Attempt to read a complete message from the serial link
 *
 * PARAMETERS  Name                    RW  Usage
 *             pu16Type                W   Location to store incoming message type
 *             pu16Length              W   Location to store incoming message length
 *             u8MaxLength            R   Length of allocated message buffer
 *             pu8Message              W   Location to store message payload
 *
 * RETURNS:
 * TRUE if a complete valid message has been received
 *
 ***************************************************************************/
PRIVATE bool bSL_ReadMessage(tsRxMessage * psRxMessage, uint8 u8MaxLength, uint8 u8Data)
{

    static teSL_RxState eRxState = E_STATE_RX_WAIT_START;

    DBG_vPrintf(DEBUG_SL, "Process char %02x State %d Type %02x Bytes %d Length %d CRC %02x\n",
            u8Data, eRxState, psRxMessage->u8MsgType, psRxMessage->u8Bytes, psRxMessage->u8MsgLength
            ,psRxMessage->u8CRC);
    switch(u8Data)
    {

        case SL_START_CHAR:
            // Reset state machine
            psRxMessage->u8Bytes = 0;
            psRxMessage->bInEsc = FALSE;
            eRxState = E_STATE_RX_WAIT_TYPE;
            break;

        case SL_ESC_CHAR:
            // Escape next character
            psRxMessage->bInEsc = TRUE;
            break;

        case SL_END_CHAR:
            // End message
            DBG_vPrintf(DEBUG_SL, "Got END\n");
            eRxState = E_STATE_RX_WAIT_START;
            if ( psRxMessage->u8MsgLength < u8MaxLength)
            {
                if ( psRxMessage->u8CRC == u8SL_CalculateCRC(psRxMessage->u8MsgType, psRxMessage->u8MsgLength, psRxMessage->au8Buffer) )
                {
                    /* CRC matches - valid packet */
                    DBG_vPrintf(DEBUG_SL, "bSL_ReadMessage(%d, %d, %02x)\n", psRxMessage->u8MsgType,
                                                                             psRxMessage->u8MsgLength,
                                                                             psRxMessage->u8CRC);
                    return(TRUE);
                }
            }
            DBG_vPrintf(DEBUG_SL, "\nCRC BAD");
            break;

        default:
            if(psRxMessage->bInEsc)
            {
                /* Unescape the character */
                u8Data ^= 0x10;
                psRxMessage->bInEsc = FALSE;
            }
            DBG_vPrintf(DEBUG_SL, "Data 0x%x\n", u8Data & 0xFF);

            switch(eRxState)
            {

            case E_STATE_RX_WAIT_START:
                break;

            case E_STATE_RX_WAIT_TYPE:
                psRxMessage->u8MsgType = u8Data;
                eRxState++;
                break;


            case E_STATE_RX_WAIT_LEN:
                psRxMessage->u8MsgLength = u8Data;
                DBG_vPrintf(DEBUG_SL, "Length %d\n", psRxMessage->u8MsgLength);
                if(psRxMessage->u8MsgLength > u8MaxLength)
                {
                    DBG_vPrintf(DEBUG_SL, "Length > MaxLength\n");
                    eRxState = E_STATE_RX_WAIT_START;
                }
                else
                {
                    eRxState++;
                }
                break;

            case E_STATE_RX_WAIT_CRC:
                DBG_vPrintf(DEBUG_SL, "CRC %02x\n", u8Data);
                psRxMessage->u8CRC = u8Data;
                eRxState++;
                break;

            case E_STATE_RX_WAIT_DATA:
                if(psRxMessage->u8Bytes < psRxMessage->u8MsgLength)
                {
                    DBG_vPrintf(DEBUG_SL, "%02x ", u8Data);
                    psRxMessage->au8Buffer[psRxMessage->u8Bytes++] = u8Data;
                }
#if DEBUG_SL
                else
                {
                    DBG_vPrintf(DEBUG_SL, "Lenght overflow Got %d Expected %d\n", psRxMessage->u8Bytes, psRxMessage->u8MsgLength);
                }
#endif
                break;
            }
            break;
    }
    return(FALSE);
}


/****************************************************************************
 *
 * NAME: vSL_WriteMessage
 *
 * DESCRIPTION:
 * Write message to the serial link
 *
 * PARAMETERS: Name                   RW  Usage
 *             u16Type                R   Message type
 *             u16Length              R   Message length
 *             pu8Data                R   Message payload
 * RETURNS:
 * void
 ****************************************************************************/
PUBLIC void vSL_WriteMessage(uint8 u8Type, uint8 u8Length, uint8 *pu8Data)
{
    int n;
    uint8 u8CRC;

    u8CRC = u8SL_CalculateCRC(u8Type, u8Length, pu8Data);

    DBG_vPrintf(DEBUG_SL, "vSL_WriteMessage(%d, %d, %02x)\n", u8Type, u8Length, u8CRC);

    /* Send start character */
    vSL_TxByte(TRUE, SL_START_CHAR);

    /* Send message type */
    vSL_TxByte(FALSE, u8Type);

    /* Send message length */
    vSL_TxByte(FALSE, u8Length);

    /* Send message checksum */
    vSL_TxByte(FALSE, u8CRC);

    /* Send message payload */
    for(n = 0; n < u8Length; n++)
    {
        vSL_TxByte(FALSE, pu8Data[n]);
    }

    /* Send end character */
    vSL_TxByte(TRUE, SL_END_CHAR);
}

/****************************************************************************
 *
 * NAME: vSL_TxByte
 *
 * DESCRIPTION:
 * Send, escaping if required, a byte to the serial link
 *
 * PARAMETERS:  Name                RW  Usage
 *              bSpecialCharacter   R   TRUE if this byte should not be escaped
 *              u8Data              R   Character to send
 *
 * RETURNS:
 * void
 ****************************************************************************/
PRIVATE void vSL_TxByte(bool bSpecialCharacter, uint8 u8Data)
{
    if(!bSpecialCharacter && u8Data < 0x10)
    {
        /* Send escape character and escape byte */
        u8Data ^= 0x10;
        SL_WRITE(SL_ESC_CHAR);
    }
    SL_WRITE(u8Data);
}

/****************************************************************************
 *
 * NAME: bPutChar
 *
 * DESCRIPTION:
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/

PUBLIC bool_t bPutChar( uint8    u8TxByte )
{
    bool    bSent =  TRUE;

    ZPS_eEnterCriticalSection ( NULL, &sStorage);

    if ( UART_bTxReady ( ) && ZQ_bQueueIsEmpty ( &APP_msgSerialTx ) )
    {
        /* send byte now and enable irq */
        UART_vSetTxInterrupt(TRUE);
        UART_vTxChar(u8TxByte);
    }
    else
    {
        bSent = ( ZQ_bQueueSend (&APP_msgSerialTx, &u8TxByte ) );
    }

    ZPS_eExitCriticalSection ( NULL, &sStorage);
    return bSent;
}


/****************************************************************************
 *
 * NAME: u8SL_CalculateCRC
 *
 * DESCRIPTION:
 * Calculate CRC of packet
 *
 * PARAMETERS: Name                   RW  Usage
 *             u8Type                 R   Message type
 *             u16Length              R   Message length
 *             pu8Data                R   Message payload
 * RETURNS:
 * CRC of packet
 ****************************************************************************/
PRIVATE uint8 u8SL_CalculateCRC(uint16 u16Type, uint16 u16Length, uint8 *pu8Data)
{

    int n;
    uint8 u8CRC;

    u8CRC  = (u16Type   >> 0) & 0xff;
    u8CRC ^= (u16Type   >> 8) & 0xff;
    u8CRC ^= (u16Length >> 0) & 0xff;
    u8CRC ^= (u16Length >> 8) & 0xff;

    for(n = 0; n < u16Length; n++)
    {
        u8CRC ^= pu8Data[n];
    }

    return(u8CRC);
}


/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

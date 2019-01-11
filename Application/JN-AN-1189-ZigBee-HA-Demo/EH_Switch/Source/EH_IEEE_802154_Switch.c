/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          EH_IEEE_802154_Switch.c
 *
 * DESCRIPTION:        ZigBee GP switch main file
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
 * Copyright NXP B.V. 2012. All rights reserved
 *
 ***************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include "jendefs.h"
#include "AppHardwareApi.h"
#include "PeripheralRegs.h"
#include "string.h"
#include <dbg.h>
#include <dbg_uart.h>
#include "MMAC.h"
#include "EH_IEEE_802154_Switch.h"
#include "EH_Switch_Configurations.h"
#include "EH_IEEE_Features.h"
#include "EH_IEEE_Commands.h"
#include "EH_Button.h"
#include "AHI_EEPROM.h"
#include "EH_Timer.h"
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
/* Required to set BrownOut */
#define VBO_MASK            0x0000000eUL
#define SYSCON_SYS_IM_ADDR  0x0200000cUL
#define SYSCON_VBOCTRL_ADDR 0x02000044UL

/* DIO Used for Cap Switching */
#define DIO_1 (0x00000002)
#define DIO_2 (0x00000004)
#define DIO_3 (0x00000008)
/* Mask for all Cap switching buttons */
#define DIO_CAP_MASK (DIO_1|DIO_2|DIO_3)

#define BUTTON_PRESSED       0x00               /*No DIO set */
#define BUTTON_RELEASED      DIO_8              /*DIO 8 set when button released*/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
/* Brown Out */
typedef enum
{
    E_BO_TRIP_1V95 = 0,
    E_BO_TRIP_2V0  = 2,
    E_BO_TRIP_2V1  = 4,
    E_BO_TRIP_2V2  = 6,
    E_BO_TRIP_2V3  = 8,
    E_BO_TRIP_2V4  = 10,
    E_BO_TRIP_2V7  = 12,
    E_BO_TRIP_3V0  = 14
} teBrownOutTripVoltage;
/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/

#ifdef  GP_MEASURE_TIME
#ifndef DK4
void vAppBrownOutIntHandle(uint32 u32DeviceId, uint32 u32ItemBitmap);
#endif
#endif
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/


/* bTxComplete is used to flag TX completion from ISR to main code */
volatile bool_t bTxComplete;

/*bRxComplete is used to flag RX completion from ISR to main code */
volatile bool_t bRxComplete;


/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
/****************************************************************************
 *
 * NAME: vSendMACFrame
 *
 * DESCRIPTION:
 * Transmits MAC frame and updates persistent data
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/

PUBLIC void vSendMACFrame( bool bUpdatePersistentData)
{
    uint8 u8TxRepeats = 0;

    if(bUpdatePersistentData)
    {
        /* update persistence data and button press count*/
#ifdef GPD_SUPPORT_PERSISTENT_DATA
        bAHI_WriteEEPROMBlock(EEPROM_START_SECTOR,
                sizeof(tGPD_PersistantData),
                (uint8 *)&sGPDPersistentData);
#endif
    }
#ifndef DK4
    vREG_SysWrite(REG_SYS_WK_T1, sGPDData.u8ButtonCount);
#endif
    /* Start radio */
    vMMAC_ConfigureRadio();
    /* Set Dedicated single channel */
    vMMAC_SetChannel(sGPDPersistentData.u8Channel);
    do
    {
        /* Set transmit flag to false */
        bTxComplete = FALSE;
        /* Start Transmit with no CCA or ACK */
        vMMAC_StartMacTransmit(&sGPD_MACFrame, E_MMAC_TX_START_NOW
                                           | E_MMAC_TX_NO_AUTO_ACK
                                           | E_MMAC_TX_NO_CCA);

        /* While call-back not reset flag */
        while (bTxComplete != TRUE)
        {
           /* Interrupt will be generated when finished, so can doze now */
           vAHI_CpuDoze();
        }
        /* add one to repeat value */
        u8TxRepeats++;

    /* Keep transmitting until counter reached or power runs out
     * or if powered by mains for a max of 20 packets */
    } while (u8TxRepeats < sGPDPersistentData.u8NoOfTransPerChannel);

}
/****************************************************************************
 *
 * NAME: vEnableRxAndReceive
 *
 * DESCRIPTION:
 * Turns on Rx and receives data
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
#if defined( GPD_RX_AFTER_TX) || defined(GPD_RX_ENABLE)
void vEnableRxAndReceive()
{

    /* MAC clock gives time in 16us resolution */
    /* keep time as 10 milli seconds  */

    bRxComplete = FALSE;
    /* Set time corresponding to MAC clock */

    vMMAC_StartMacReceive(&sGPD_MACReceivedFrame, E_MMAC_RX_START_NOW
                            |E_MMAC_RX_NO_AUTO_ACK
                            |E_MMAC_RX_ALLOW_MALFORMED
                            |E_MMAC_RX_ALLOW_FCS_ERROR
                            |E_MMAC_RX_ADDRESS_MATCH);
#ifndef DK4
/* While call-back not reset flag */
    while( bRxComplete == FALSE)
    {
       /* Interrupt will be generated when finished, so can doze now */
       vAHI_CpuDoze();
    }
    vHandleRxMacFrame();

#else
    uint32 u32StartTime;
    u32StartTime = u32EH_StartTimer();
    while( FALSE == bRxComplete )
    {

        if( bEH_IsTimeElapsedInMicrosSec(APP_TIME_MS(GPD_RX_AFTER_TX_DURATION ) , u32StartTime))
        {
            vEH_StopTimer();
            DBG_vPrintf(DBG_DEVICE_SWITCH, "\n Stop wait to receive \n" );
            break;
        }

    }

    if(bRxComplete)
    {
        /* Process Received frame */

        DBG_vPrintf(DBG_DEVICE_SWITCH, "\n bRxComplete  vHandleRxMacFrame \n" );
        vHandleRxMacFrame();
    }
    else
    {
        DBG_vPrintf(DBG_DEVICE_SWITCH, "\n MAC receive Timer Expired \n" );
    }
#endif
}
#endif
/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/
/****************************************************************************
 *
 * NAME: vInterruptFired
 *
 * DESCRIPTION:
 * ISR for MAC RX/TX interrupts
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vInterruptFired(uint32 u32InterruptBitmap)
{
    /* Is the interrupt for Transmit completed */
    if (u32InterruptBitmap & E_MMAC_INT_TX_COMPLETE)
    {
        bTxComplete = TRUE;

    }
    else
    {
        /* Is the interrupt for Rx completed */
        if((u32InterruptBitmap & E_MMAC_INT_RX_COMPLETE))
        bRxComplete = TRUE;
    }
}
/****************************************************************************
 *
 * NAME: vCbSystemController
 *
 * DESCRIPTION:
 *
 *
 * RETURNS:
 *
 ****************************************************************************/
PUBLIC void vCbSystemController(uint32 u32DeviceId, uint32 u32ItemBitmap)
{
    /* Validate interrupt source when brown out state entered */
    if ((E_AHI_DEVICE_SYSCTRL == u32DeviceId) && (E_AHI_SYSCTRL_VREM_MASK == u32ItemBitmap))
    {
        /*switch the caps for extra boost of power*/
        vAHI_DioSetPullup((uint32) 0x0,DIO_CAP_MASK);
        vAHI_DioSetDirection ((uint32) 0x0, DIO_CAP_MASK);
        vAHI_DioSetOutput((uint32) DIO_CAP_MASK, 0x0);
    }

}
/****************************************************************************
 *
 * NAME: AppWarmStart
 *
 * DESCRIPTION:
 * Entry point for application from boot loader. Simply jumps to AppColdStart
 * as, in this instance, application will never warm start.
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void AppWarmStart(void)
{

    bool  bEnableSleep = TRUE;
#ifdef DR1216
    static uint8 u8data;
#endif
    /* Wait for the 32MHz */
    while(bAHI_Clock32MHzStable() == FALSE);

    /* Init AHI. This will clear the wake interrupt */
    u32AHI_Init();

    /* Turn off Pull ups required for non DK4 devices */
#ifndef DK4
    vAHI_DioSetPullup    ((uint32) 0x0, APP_BUTTONS_DIO_MASK);
    /* Make button DIO an input */
    vAHI_DioSetDirection ((uint32) APP_BUTTONS_DIO_MASK, 0x0);
#endif
    /* WORKAROUND for [lpsw4269]Set trip voltage, enable SVM & disable reset on BO */
       *(uint32 *)SYSCON_VBOCTRL_ADDR = E_BO_TRIP_2V0 |1;
       vAHI_SysCtrlRegisterCallback(vCbSystemController);
       /* check we're OK on startup of SVM (also adds delay for config change*/
       if (bAHI_BrownOutStatus() == TRUE)
       {
           vCbSystemController(E_AHI_DEVICE_SYSCTRL,E_AHI_SYSCTRL_VREM_MASK);
       }
       /* Enable Rising Event mask (VDD below BO trip voltage) */
       *(uint32 *)SYSCON_SYS_IM_ADDR |= E_AHI_SYSCTRL_VREM_MASK;
#ifdef DK4
    /* Initialize DIO on DK4 switch*/
    bool bClearPDM;
    bClearPDM = bButtonInitialize();
#endif
    /* Enable MAC, and enable interrupts */
    vMMAC_Enable();
    vMMAC_EnableInterrupts(vInterruptFired);

#ifdef DBG_ENABLE
    /* Initialise debugging */
    DBG_vUartInit(DBG_E_UART_0, DBG_E_UART_BAUD_RATE_115200);
#endif


#ifdef GPD_SUPPORT_PERSISTENT_DATA
    vAHI_InitEEPROM();
#endif

    /* Stop Watch dog */
#ifdef DK4
    vAHI_WatchdogStop();
       if(bClearPDM)
       {
           bHandleButtonPress(TRUE);
       }
#else
#ifdef DR1216

        switch(u32AHI_DioReadInput()&APP_BUTTONS_DIO_MASK)
            {
                case BUTTON_ON:
                    u8data=0x01;
                    bAHI_WriteEEPROMBlock(60,sizeof(uint8),(uint8 *)&u8data);
                    HandleGPDStateMachine(E_GPD_ON_CMD);
                    break;

                case BUTTON_OFF:
                    u8data=0x01;
                    bAHI_WriteEEPROMBlock(60,sizeof(uint8),(uint8 *)&u8data);
                    HandleGPDStateMachine(E_GPD_OFF_CMD);
                    break;

                case BUTTON_INCREASE:
                    HandleGPDStateMachine(E_GPD_MOVE_UP_CMD);
                    break;

                case BUTTON_DECREASE:
                    HandleGPDStateMachine(E_GPD_MOVE_DOWN_CMD);
                    break;

                default:
                    bAHI_ReadEEPROMBlock(60,sizeof(uint8),(uint8 *)&u8data);
                    if (u8data == 0x01)
                    {
                        u8data=0x00;
                        bAHI_WriteEEPROMBlock(60,sizeof(uint8),(uint8 *)&u8data);
                    }
                    else
                    {
                        HandleGPDStateMachine(E_GPD_LEVEL_CONTROL_STOP);
                    }
                    break;
             }

#else

      /* Read data from epprom */
      switch(u32AHI_DioReadInput()&0x100)
          {
        case BUTTON_PRESSED:
            DBG_vPrintf(DBG_DEVICE_SWITCH, "\nButton Pressed");
            /* Send a packet */
            HandleGPDStateMachine(0);
            break;

        case BUTTON_RELEASED:
            DBG_vPrintf(DBG_DEVICE_SWITCH, "\nButton Released");
            /* Do nothing */
            break;

        default:
            break;
          }

#endif
#endif
    /* If we get this for the device must be powered */
    while (1)
    {
#ifdef DK4
         /* Handle Button Press on DK4, commands are initiated on button press*/
        bEnableSleep = bHandleButtonPress(FALSE);

#endif


        if(bEnableSleep)
        {
            vAHI_CpuDoze();
        }

    }

}
/****************************************************************************
 *
 * NAME: vAppBrownOutIntHandle
 *
 * DESCRIPTION:
 * Brown out interrupt handler
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
#ifdef  GP_MEASURE_TIME
#ifndef DK4
void vAppBrownOutIntHandle(uint32 u32DeviceId, uint32 u32ItemBitmap)
{
    if(u32ItemBitmap & E_AHI_SYSCTRL_VREM_MASK)
    {
        vAHI_DioSetOutput(E_AHI_DIO7_INT , E_AHI_DIO6_INT);
    }

}
#endif
#endif
/****************************************************************************
 *
 * NAME: AppColdStart
 *
 * DESCRIPTION:
 * Cold Start of application
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void AppColdStart(void)
{

#ifndef GPD_SUPPORT_PERSISTENT_DATA
#ifdef DK4
    /* Random number for MAC sequnce if persistence is not supported. On DK4
     * random number generator started in continuous mode where as in EH as
     * single shot */
    vAHI_StartRandomNumberGenerator(E_AHI_RND_CONTINUOUS, E_AHI_INTS_DISABLED);

#else
    vAHI_StartRandomNumberGenerator(E_AHI_RND_SINGLE_SHOT, E_AHI_INTS_DISABLED);
#endif
#endif

    /* AppWarmStart continues the start sequence */
    AppWarmStart();
    while(1); /* Don't need this, but leave it in as it makes the code smaller
               * (hints to compiler that it doesn't have to restore registers
               * on exit from function) */
}

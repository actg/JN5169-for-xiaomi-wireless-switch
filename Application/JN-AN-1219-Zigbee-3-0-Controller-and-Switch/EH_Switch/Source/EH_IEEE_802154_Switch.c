/*****************************************************************************
 *
 * MODULE:            JN-AN-1219
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

#ifdef DK4
#include "app_main.h"
#include "ZTimer.h"
#endif
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
/* Required to set BrownOut */
#if 0
#define VBO_MASK            0x0000000eUL
#define SYSCON_SYS_IM_ADDR  0x0200000cUL
#define SYSCON_VBOCTRL_ADDR 0x02000044UL
#endif

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
/*
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
*/
/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
#ifdef DK4
PUBLIC void APP_vInitResources(void);
#endif
volatile bool_t bEnableSleep = TRUE;
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

    /* Start radio */
    vMMAC_ConfigureRadio();
    /* Set Dedicated single channel and power.
     	 * Power Set to nominal value of 3 Dbm
     	 * User to specify the value they require dependant on HW */
    vMMAC_SetChannelAndPower(sGPDPersistentData.u8Channel, 3);
    /* Set Dedicated single channel */
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
        DBG_vPrintf(DBG_DEVICE_SWITCH, "\n vSendMACFrame channel = %d  \n", sGPDPersistentData.u8Channel );
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
void vEnableRxAndReceive(void)
{

    /* MAC clock gives time in 16us resolution */
    /* keep time as 10 milli seconds  */

    bRxComplete = FALSE;
    /* Set time corresponding to MAC clock */

    vMMAC_StartMacReceive(&sGPD_MACReceivedFrame, E_MMAC_RX_START_NOW
                            |E_MMAC_RX_NO_AUTO_ACK
                            );
#ifndef DK4
/* While call-back not reset flag */
    while( bRxComplete == FALSE)
    {
        /* Interrupt will be generated when finished, so can doze now */
        vAHI_CpuDoze();
    }
    vHandleRxMacFrame();

#else
    ZTIMER_eStop(u8TimerReceive);
    ZTIMER_eStart(u8TimerReceive, ZTIMER_TIME_MSEC(250));

    while( FALSE == bRxComplete )
    {

         if(ZTIMER_eGetState(u8TimerReceive) == E_ZTIMER_STATE_EXPIRED)
         {
            ZTIMER_eStop(u8TimerReceive);
            DBG_vPrintf(DBG_DEVICE_SWITCH, "\n Stop wait to receive \n" );
            break;
        }
        ZTIMER_vTask();

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

#ifdef DK4
    bool bClearPDM;
#endif
    /* Wait for the 32MHz */
    while(bAHI_Clock32MHzStable() == FALSE);

    /* Init AHI. This will clear the wake interrupt */
    u32AHI_Init();


    /* WORKAROUND for [lpsw4269]Set trip voltage, enable SVM & disable reset on BO */
   // *(uint32 *)SYSCON_VBOCTRL_ADDR = E_BO_TRIP_2V0 |1;
    vAHI_BrownOutConfigure( E_AHI_VBOREF_2V0, FALSE, TRUE, FALSE, TRUE);


    vAHI_SysCtrlRegisterCallback(vCbSystemController);
    /* check we're OK on startup of SVM (also adds delay for config change*/
    if (bAHI_BrownOutStatus() == TRUE)
    {
        vCbSystemController(E_AHI_DEVICE_SYSCTRL,E_AHI_SYSCTRL_VREM_MASK);
    }
    /* Enable Rising Event mask (VDD below BO trip voltage) */
 //done above   *(uint32 *)SYSCON_SYS_IM_ADDR |= E_AHI_SYSCTRL_VREM_MASK;

#ifdef DK4
    /* Initialize DIO on DK4 switch*/
    APP_vInitResources();
    bClearPDM =
#endif

    bButtonInitialize();

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
        vClearPersistentData(TRUE);
    }
#else

    #ifdef DR1216
        vHandleDR1216ButtonPress();
    #else
        vHandleEHButtonPress();
    #endif
#endif

    /* If we get this far the device must be powered */
    while (1)
    {
#ifdef DK4

        ZTIMER_vTask();
#endif


        if(bEnableSleep)
        {
            vAHI_CpuDoze();
        }
    }
}

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

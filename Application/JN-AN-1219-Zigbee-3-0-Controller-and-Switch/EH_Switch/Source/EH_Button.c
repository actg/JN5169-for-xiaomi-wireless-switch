/*****************************************************************************
 *
 * MODULE:             JN-AN-1219
 *
 * COMPONENT:          EH_Button.c
 *
 * DESCRIPTION:        EH switch button handling
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
#include "jendefs.h"
#include "AppHardwareApi.h"
#include "PeripheralRegs.h"
#include "string.h"
#include <dbg.h>
#include <dbg_uart.h>
#include "EH_Button.h"
#include "EH_IEEE_Features.h"
#include "EH_IEEE_Commands.h"
#include "app_buttons.h"
#include "AHI_EEPROM.h"
#include "ZTimer.h"
#include "app_main.h"
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/** Time in msec to wait to enable button interrupts when a button interrupt is detected */
#define BUTTON_STABLE_DURATION                  (15)

#define NEXT_MOVE_CMD_DURATION                  (500) /* 500m sec */

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
/****************************************************************************/
/***        Exported Variables                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

/* flag indicating whether button press detected, updated from ISR */
volatile bool bButtonPressed = 0;

/* The button which is pressed/released , updated from ISR */
volatile uint32 u32Button = 0;

/****************************************************************************/
/***        Local Function Prototypes                                               ***/
/****************************************************************************/
 void vEH_ButtonCallback(uint32 u32DeviceId, uint32 u32ItemBitmap);
 void vEH_TickTimerCallback(uint32 u32DeviceId, uint32 u32ItemBitmap);
#if (JENNIC_CHIP_FAMILY == JN516x)
 void ISR_vTickTimer(void);
#else
 void ZTIMER_vAhiCallback ( uint32 u32Device, uint32 u32ItemBitmap);
#endif
/****************************************************************************/
/***        Public Functions                                              ***/
/****************************************************************************/


/****************************************************************************
 * NAME: vHandleButtonPress
 *
 * DESCRIPTION:
 * handles button press event on Dk4 and initiates appropriate commands
 *
 * RETURNS:
 * Return whether device can go to sleep
 *
 ****************************************************************************/
#ifdef DK4
void vHandleButtonPress(te_TransitionCode  eCode )
{
    static bool bIsCommMode = 0;
    vLoadPersistentData();

    switch(eCode)
    {

    case COMM_BUTTON_PRESSED:
        /* if already in operational state, switch to commissioning state */
        if(sGPDPersistentData.b8CommissioiningStatusBits & COMM_COMP_SET_BIT)
        {
            sGPDPersistentData.b8CommissioiningStatusBitsPrevious =
                    sGPDPersistentData.b8CommissioiningStatusBits;
#ifdef GPD_SUPPORT_PERSISTENT_DATA
            bAHI_WriteEEPROMBlock(EEPROM_START_SECTOR,
                    sizeof(tGPD_PersistantData),
                    (uint8 *)&sGPDPersistentData);
            DBG_vPrintf(DBG_DEVICE_SWITCH, "\n  reverted= %d, previous = %d",
                sGPDPersistentData.b8CommissioiningStatusBits ,
                sGPDPersistentData.b8CommissioiningStatusBitsPrevious
                );
#endif
            bIsCommMode = TRUE;
        }
        break;

    case ON_PRESSED:
        /* Switch 1: mapping
         * 1. Commissioning Commands
         * 2. On Or  Toggle Command
         * 3. De commissioning command
         * 4. Factory Reset
         * */
        if(bIsCommMode)
        {
            sGPDPersistentData.b8CommissioiningStatusBits = CHANNEL_SET_BIT;
            DBG_vPrintf(DBG_DEVICE_SWITCH, "\n Commissioning \n");
            bIsCommMode = FALSE;
        }
        DBG_vPrintf(DBG_DEVICE_SWITCH, "\n ON_PRESSED HandleGPDStateMachine \n");
        HandleGPDStateMachine(0);
        //tbd short press
        break;

    case OFF_PRESSED:
        DBG_vPrintf(DBG_DEVICE_SWITCH, "\n APP_E_BUTTONS_BUTTON_SW2 \n");
        /* Button 2 mapping :
         * Off command , Decommissioning command if Dio8 pressed */
        if(bIsCommMode)
        {
            if(sGPDPersistentData.b8CommissioiningStatusBits & COMM_COMP_SET_BIT)
            {
                vSendDecommissioingCmd();

                bIsCommMode = FALSE;
            }
        }
        else
        {
            HandleGPDStateMachine(E_GPD_OFF_CMD);
        }
        break;

    case UP_PRESSED:
        DBG_vPrintf(DBG_DEVICE_SWITCH, "\n APP_E_BUTTONS_BUTTON_SW3 \n");
        /* Button 3 mapping :
         * Move up with on/off( button press) ,
         * Level control stop (button release ) */

        HandleGPDStateMachine(E_GPD_MOVE_UP_CMD);

        break;

    case DOWN_PRESSED:
        HandleGPDStateMachine(E_GPD_MOVE_DOWN_CMD);
        break;

    case DOWN_RELEASED:
    case UP_RELEASED:
        HandleGPDStateMachine(E_GPD_LEVEL_CONTROL_STOP);
        break;

    case UP_AND_ON_TOGETHER_PRESSED:
        /* This is used in current commissioning failed case.
         * Revert state */
        DBG_vPrintf(DBG_DEVICE_SWITCH, "\n UP_AND_ON_TOGETHER_PRESSED = %d, previous = %d",
                sGPDPersistentData.b8CommissioiningStatusBits ,
                sGPDPersistentData.b8CommissioiningStatusBitsPrevious
                );
        if((sGPDPersistentData.b8CommissioiningStatusBits == CHANNEL_SET_BIT) &&
        (sGPDPersistentData.b8CommissioiningStatusBitsPrevious & COMM_COMP_SET_BIT))
        {
            sGPDPersistentData.b8CommissioiningStatusBits =
                    sGPDPersistentData.b8CommissioiningStatusBitsPrevious;
            sGPDPersistentData.b8CommissioiningStatusBitsPrevious = 0;
#ifdef GPD_SUPPORT_PERSISTENT_DATA
            bAHI_WriteEEPROMBlock(EEPROM_START_SECTOR,
                    sizeof(tGPD_PersistantData),
                    (uint8 *)&sGPDPersistentData);
            DBG_vPrintf(DBG_DEVICE_SWITCH, "\n  reverted= %d, previous = %d",
                sGPDPersistentData.b8CommissioiningStatusBits ,
                sGPDPersistentData.b8CommissioiningStatusBitsPrevious
                );
#endif
        }
        break;

    default:
        //DBG_vPrintf(DBG_DEVICE_SWITCH, "\n  Button Handler default= 0x%x", eCode);
        break;
    }

}
#endif
/****************************************************************************
 * NAME: bButtonInitialize
 *
 * DESCRIPTION:
 * Button Initialization function, enables interrupts only on DK4
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
bool bButtonInitialize(void)
{

#ifdef DK4

   bool bReset = APP_bButtonInitialise();

   vAHI_SysCtrlRegisterCallback(&vEH_ButtonCallback);
   vAHI_TickTimerRegisterCallback(&vEH_TickTimerCallback);
   return(bReset);
#else
    /* Disable internal pull-up */
    vAHI_DioSetPullup    ((uint32) 0x0, APP_BUTTONS_DIO_MASK);
    /* Make button DIO an input */
    vAHI_DioSetDirection ((uint32) APP_BUTTONS_DIO_MASK, 0x0);
    return FALSE;
#endif

}
#ifdef DR1216
void vHandleDR1216ButtonPress(void)
{
    static uint8 u8data;
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
}
#endif
#ifdef GP_AUTO_SWITCH
void vHandleEHButtonPress(void)
{
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
}
#endif
/****************************************************************************/
/***        Local Functions                                              ***/
/****************************************************************************/
/****************************************************************************
 * NAME: vEH_ButtonCallback
 *
 * DESCRIPTION:
 * Button Interrupt CallBack
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
void vEH_TickTimerCallback(uint32 u32DeviceId, uint32 u32ItemBitmap)
{
#if (JENNIC_CHIP_FAMILY == JN516x)
    ISR_vTickTimer();
#else
    ZTIMER_vAhiCallback ( u32DeviceId, u32ItemBitmap);
#endif
}

void vEH_ButtonCallback(uint32 u32DeviceId, uint32 u32ItemBitmap)
{
#ifdef DK4
	DBG_vPrintf(TRUE, "\n =======================  vEH_ButtonCallback \n ");

    bEnableSleep = FALSE;

    if((u32DeviceId == E_AHI_DEVICE_SYSCTRL) && (u32ItemBitmap & APP_BUTTONS_DIO_MASK))
    {
        /* disable edge detection until scan complete */
        vAHI_DioInterruptEnable(0, APP_BUTTONS_DIO_MASK);
        ZTIMER_eStop(u8TimerButtonScan);
        ZTIMER_eStart(u8TimerButtonScan, ZTIMER_TIME_MSEC(10));
    }
#endif
}



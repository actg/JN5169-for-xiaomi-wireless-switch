
/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          EH_Button.c
 *
 * AUTHOR:             Rajeena
 *
 * DESCRIPTION:        ZigBee EH Button implementation
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
#include "EH_Button.h"
#include "EH_IEEE_Features.h"
#include "EH_Timer.h"
#include "EH_IEEE_Commands.h"
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/** Time in msec to wait to enable button interrupts when a button interrupt is detected */
#define BUTTON_STABLE_DURATION                  (15)

#define NEXT_MOVE_CMD_DURATION                    (500) /* 500m sec */

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
bool bHandleButtonPress(bool bIsPowerUp)
{
     uint32 u32StartTime;
     bool bEnableSleep = TRUE;
    /* ISR will set bButtonPressed to true */
    if(bButtonPressed)
    {

        switch(u32Button)
        {
            /* Switch 1: mapping
             * 1. Commissioning Commands
             * 2. On Or  Toggle Command
             * 3. De commissioning command
             * 4. Factory Reset
             * */
            case APP_E_BUTTONS_BUTTON_SW1:
                bEnableSleep = bProcessGPDEvent();
                break;

            case APP_E_BUTTONS_BUTTON_SW2:
                DBG_vPrintf(DBG_DEVICE_SWITCH, "\n APP_E_BUTTONS_BUTTON_SW2 \n");
                /* Button 2 mapping :
                 * Off command */
                HandleGPDStateMachine(E_GPD_OFF_CMD);
                bButtonPressed = FALSE;

                break;
            case APP_E_BUTTONS_BUTTON_SW3:
                DBG_vPrintf(DBG_DEVICE_SWITCH, "\n APP_E_BUTTONS_BUTTON_SW3 \n");
                /* Button 3 mapping :
                 * Move up with on/off( button press) ,
                 * Level control stop (button release ) */
                {
                    HandleGPDStateMachine(E_GPD_MOVE_UP_CMD);
                    bButtonPressed = FALSE;
                    uint32 u32DIOVal2 = u32AHI_DioReadInput();
                    uint32 u32DIOVal = u32AHI_DioReadInput();
                    /* start timer to account next button press interval */
                    u32StartTime = u32EH_StartTimer();
                    while(u32DIOVal2 == u32DIOVal)
                    {
                        if(bEH_IsTimeElapsedInMicrosSec((uint32)( APP_TIME_MS(NEXT_MOVE_CMD_DURATION)) ,u32StartTime))
                        {
                            u32StartTime = u32EH_StartTimer();
                            u32DIOVal = u32AHI_DioReadInput();

                        }

                    }
                    DBG_vPrintf(DBG_DEVICE_SWITCH, "\n APP_E_BUTTONS_BUTTON_SW3 Release u32DIOVal = 0x%8x \n",u32DIOVal);
                    HandleGPDStateMachine(E_GPD_LEVEL_CONTROL_STOP);
                }

                break;
            case APP_E_BUTTONS_BUTTON_SW4:
                DBG_vPrintf(DBG_DEVICE_SWITCH, "\n APP_E_BUTTONS_BUTTON_SW4 \n");
                /* Button 4 mapping :
                 * Move Down with on / off( button press),
                 * Level control stop(button release )       */
                {
                    HandleGPDStateMachine(E_GPD_MOVE_DOWN_CMD);
                    bButtonPressed = FALSE;
                    uint32 u32DIOVal = u32AHI_DioReadInput();
                    uint32 u32DIOVal2 = u32AHI_DioReadInput();
                    u32StartTime = u32EH_StartTimer();
                    while(u32DIOVal2 == u32DIOVal)
                    {
                        if(bEH_IsTimeElapsedInMicrosSec((uint32)( APP_TIME_MS(NEXT_MOVE_CMD_DURATION)) ,u32StartTime))
                        {
                            u32StartTime = u32EH_StartTimer();
                            u32DIOVal = u32AHI_DioReadInput();

                        }

                    }
                    DBG_vPrintf(DBG_DEVICE_SWITCH, "\n APP_E_BUTTONS_BUTTON_SW4 Release u32DIOVal = 0x%8x\n",u32DIOVal);
                    HandleGPDStateMachine(E_GPD_LEVEL_CONTROL_STOP);
                }


                break;
            case APP_BUTTONS_BUTTON_1:
                if(bIsPowerUp)
                {
                    vClearPersistentData(TRUE);
                }

                bButtonPressed = FALSE;
                break;
            default:
                DBG_vPrintf(DBG_DEVICE_SWITCH, "\n  Button Handler u32Button = 0x%8x", u32Button);
                break;
        }
        /* enable interrupts again (on DK4)  */

            DBG_vPrintf(DBG_DEVICE_SWITCH, "\n Enable int 1 \n" );
            (void) u32AHI_DioInterruptStatus();
            vAHI_DioInterruptEnable(APP_BUTTONS_DIO_MASK, 0);
    }


    return bEnableSleep;
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
     /* Set DIO lines to inputs with buttons connected */
     vAHI_DioSetDirection(APP_BUTTONS_DIO_MASK, 0);

    vAHI_SysCtrlRegisterCallback(&vEH_ButtonCallback);

    /* Turn on pull-ups for DIO lines with buttons connected */
    vAHI_DioSetPullup(APP_BUTTONS_DIO_MASK, 0);

    /* Set the edge detection for falling edges */
    vAHI_DioInterruptEdge(0, APP_BUTTONS_DIO_MASK);

    /* Enable interrupts to occur on selected edge */
    vAHI_DioInterruptEnable(APP_BUTTONS_DIO_MASK, 0);
    uint32 u32ButtonStatus = u32AHI_DioReadInput() ;
   if ((u32ButtonStatus & 0x100) == 0x00)
   {
       u32Button = APP_BUTTONS_BUTTON_1;
       bButtonPressed = TRUE;
        /* disable edge detection until handling of button press complete */
        vAHI_DioInterruptEnable(0, APP_BUTTONS_DIO_MASK);
       return TRUE;
   }
   return FALSE;

#else

    /* Disable internal pull-up */
    vAHI_DioSetPullup    ((uint32) 0x0, APP_BUTTONS_DIO_MASK);
    /* Make button DIO an input */
    vAHI_DioSetDirection ((uint32) APP_BUTTONS_DIO_MASK, 0x0);

      return TRUE;

#endif

}

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

void vEH_ButtonCallback(uint32 u32DeviceId, uint32 u32ItemBitmap)
{
#ifdef DK4
      /* clear pending DIO changed bits by reading register */
        (void) u32AHI_DioInterruptStatus();
        uint32 u32IntStatus = u32AHI_DioReadInput();

        /* disable edge detection until handling of button press complete */
        vAHI_DioInterruptEnable(0, APP_BUTTONS_DIO_MASK);
        DBG_vPrintf(DBG_DEVICE_SWITCH, "\nvEH_ButtonCallback u32DeviceId = 0x%8x, u32ItemBitmap = 0x%8x u32IntStatus = 0x%8x" , u32DeviceId,u32ItemBitmap, u32IntStatus);

        /* Update flags indicating that Button press detected */
        bButtonPressed = TRUE;
        u32Button = u32ItemBitmap;
#endif
}
/****************************************************************************
 * NAME: bProcessGPDEvent
 *
 * DESCRIPTION:
 * Handles SW1 functionalities
 *
 * RETURNS:
 * Return whether device can go to sleep
 *
 ****************************************************************************/
bool bProcessGPDEvent(void)
 {
    bool bEnableSleep = TRUE;
     /* send command based on the state the device is in */
    HandleGPDStateMachine(0);

#ifdef DK4


    /** wait till short press time is elapsed , enabling interrupts . If next
     * short press is initiated, interrupt should be fired while this time interval */


    /* wait till button release */
    bButtonPressed = FALSE;
    uint32 u32DIOVal = u32AHI_DioReadInput();
    uint32 u32DIOVal2 = u32AHI_DioReadInput();
    while(u32DIOVal2 == u32DIOVal)
    {
        u32DIOVal = u32AHI_DioReadInput();
    }
    /* stop timer if already running (by previous button press )*/
        vEH_StopTimer();
         uint32 u32StartTime;
        /* start timer to account next button press interval */
        u32StartTime = u32EH_StartTimer();
        u32Button = 0;
        (void) u32AHI_DioInterruptStatus();
        vAHI_DioInterruptEnable(APP_BUTTONS_DIO_MASK, 0);
    while( 1)
    {

        if(bEH_IsTimeElapsedInMicrosSec( APP_TIME_MS(SHORT_PRESS_TIME) ,u32StartTime))
        {

            vEH_StopTimer();
            sGPDData.u8ButtonCount = 0;
            DBG_vPrintf(DBG_DEVICE_SWITCH, "\n short press timer expired \n" );

            break;
        }
        if((u32Button ==  APP_E_BUTTONS_BUTTON_SW1)||
            (u32Button ==  APP_E_BUTTONS_BUTTON_SW2) ||
            (u32Button ==  APP_E_BUTTONS_BUTTON_SW3)||
            (u32Button ==  APP_E_BUTTONS_BUTTON_SW4)
                )

        {
            bEnableSleep = FALSE;
            (void) u32AHI_DioInterruptStatus();
            DBG_vPrintf(DBG_DEVICE_SWITCH, "\n short press timer detected \n" );
            break;
        }

    }


#endif
    return bEnableSleep;
 }


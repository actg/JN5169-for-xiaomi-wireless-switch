/*****************************************************************************
 *
 * MODULE:          JN-AN-1189
 *
 * COMPONENT:       app_switch_state_machine.c
 *
 * DESCRIPTION:     ZHA Demo: Remote Key Press Behaviour (Implementation)
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
 * Copyright NXP B.V. 2013. All rights reserved
 *
 ***************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include "dbg.h"
#include "app_events.h"
#include "app_buttons.h"
#include "zha_switch_node.h"

#include "haEzFindAndBind.h"
#include "app_switch_state_machine.h"
#include "App_DimmerSwitch.h"
#include "os_gen.h"
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifdef DEBUG_SWITCH_STATE
    #define TRACE_SWITCH_STATE   TRUE
#else
    #define TRACE_SWITCH_STATE   FALSE
#endif
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
PRIVATE void vManageIndividualControlMode(te_SwitchState *peSwitchState,
                                          te_TransitionCode eTransitionCode );

PRIVATE void vManageIdentifyMode(te_SwitchState *peSwitchState,
                                          te_TransitionCode eTransitionCode );

PRIVATE void vManageLightControlState(te_SwitchState *peSwitchState,
                                          te_TransitionCode eTransitionCode );

PRIVATE void vManageEZModeCommissioning(te_SwitchState *peSwitchState,
                                          te_TransitionCode eTransitionCode );

PRIVATE void vSwitchStateMachine(te_TransitionCode eTransitionCode );

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

extern uint16 u16GroupId;

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
PRIVATE te_SwitchState eSwitchState;
PRIVATE te_TransitionCode eTransitionButtonCode;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
/****************************************************************************
 *
 * NAME: eGetDelayedButtonCode
 *
 * DESCRIPTION:
 * Gets the delayed command that is stored
 *
 * RETURNS:
 * stored transition code
 *
 ****************************************************************************/
te_TransitionCode eGetDelayedButtonCode(void)
{
    return eTransitionButtonCode;
}
/****************************************************************************
 *
 * NAME: vStopStartModeChangeTimer
 *
 * DESCRIPTION:
 * Stops and starts the commissioning timer with required ticks
 *
 * PARAMETERS:
 * u32Ticks     Ticks for timer start
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vStopStartModeChangeTimer( uint32 u32Ticks )
{
    if( OS_eGetSWTimerStatus(App_ChangeModeTimer) != OS_E_SWTIMER_STOPPED )
    {
        OS_eStopSWTimer(App_ChangeModeTimer);
    }
    #ifdef SLEEP_ENABLE
        if( FALSE == bWatingToSleep())
        {
            OS_eStartSWTimer(App_ChangeModeTimer, u32Ticks, NULL );
        }
    #else
        OS_eStartSWTimer(App_ChangeModeTimer, u32Ticks, NULL );
    #endif
}
/****************************************************************************
 *
 * NAME: vDQButtonPress
 *
 * DESCRIPTION:
 * Destroys delayed command that is stored
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vDQButtonPress()
{
    eTransitionButtonCode = NUMBER_OF_TRANSITION_CODE;
    OS_eStopSWTimer(APP_tmrButtonDelayTimer);
}
/****************************************************************************
 *
 * NAME: vQButtonPress
 *
 * DESCRIPTION:
 * Stores delayed command that is stored
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vQButtonPress( te_TransitionCode eTransitionCode)
{
    eTransitionButtonCode=eTransitionCode;
    /*Set up the button delay timer*/
    OS_eStartSWTimer(APP_tmrButtonDelayTimer,APP_TIME_MS(BUTTON_DELAY_TIME_IN_MS),NULL);
}

/****************************************************************************
 *
 * NAME: vSendDelayedCommands
 *
 * DESCRIPTION:
 * Sends the delayed commands in the individual control or commissioning mode
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vSendDelayedCommands(te_TransitionCode eTransitionCode)
{
    DBG_vPrintf(TRACE_SWITCH_STATE,"\nIn vSendDelayedCommands with TransitionCode = %d -> ",eTransitionCode);
    switch(eTransitionCode)
    {
          case ON_PRESSED:
              DBG_vPrintf(TRACE_SWITCH_STATE," E_CLD_ONOFF_CMD_ON \n");
              vAppOnOff(E_CLD_ONOFF_CMD_ON);
              break;

          case OFF_PRESSED:
              DBG_vPrintf(TRACE_SWITCH_STATE," E_CLD_ONOFF_CMD_OFF \n");
              vAppOnOff(E_CLD_ONOFF_CMD_OFF);
              break;

          case UP_PRESSED:
              DBG_vPrintf(TRACE_SWITCH_STATE," E_CLD_LEVELCONTROL_MOVE_MODE_UP \n");
              vAppLevelMove(E_CLD_LEVELCONTROL_MOVE_MODE_UP, 65, TRUE);
              break;

          case DOWN_PRESSED:
              DBG_vPrintf(TRACE_SWITCH_STATE," E_CLD_LEVELCONTROL_MOVE_MODE_DOWN \n");
              vAppLevelMove(E_CLD_LEVELCONTROL_MOVE_MODE_DOWN, 65, FALSE);
              break;

          default :
              break;
    }
    vDQButtonPress();
}

/****************************************************************************
 *
 * NAME: vManageIndividualControlMode
 *
 * DESCRIPTION:
 * Manage the Individual control modes for the lights in unicast mode
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vManageIndividualControlMode(te_SwitchState *peSwitchState, te_TransitionCode eTransitionCode )
{
      /* Calls individual function
       * Changes state
       * Addressing for individual functions
       *               Individual or group ? - well the address will be taken based on the state */
    DBG_vPrintf(TRACE_SWITCH_STATE,"\nIn vManageIndividualControlMode(Mode = %d) TransitionCode = %d -> ", *peSwitchState,eTransitionCode);
    switch(eTransitionCode)
    {
        /* Fall through for the button presses as there will be a delayed action*/
          case ON_PRESSED:

          case OFF_PRESSED:

          case UP_PRESSED:

          case DOWN_PRESSED:
              vQButtonPress(eTransitionCode);
              break;

          case UP_AND_ON_TOGETHER_PRESSED:
              vDQButtonPress();
              DBG_vPrintf(TRACE_SWITCH_STATE," vAppStoreSceneById = 1 \n");
              vAppStoreSceneById(SCENE_1, u16GroupId);
              *peSwitchState = LIGHT_CONTROL_MODE;
              break;

          case DOWN_AND_OFF_TOGETHER_PRESSED:
              vDQButtonPress();
              DBG_vPrintf(TRACE_SWITCH_STATE," vAppStoreSceneById = 2 \n");
              vAppStoreSceneById(SCENE_2, u16GroupId);
              *peSwitchState = LIGHT_CONTROL_MODE;
              break;

         case COMM_BUTTON_PRESSED:
              *peSwitchState = IDENTIFY_MODE;
              vAppDiscover();
              break;

          case DOWN_RELEASED:
          case UP_RELEASED:
              vDQButtonPress();
              DBG_vPrintf(TRACE_SWITCH_STATE," vAppLevelStop \n");
              vAppLevelStop();
              break;

          default :
              break;
    }
    /*Restart the Timer from expiring */
    if( OS_eGetSWTimerStatus(App_ChangeModeTimer) == OS_E_SWTIMER_EXPIRED )
    {
        OS_eStopSWTimer(App_ChangeModeTimer);
        *peSwitchState = LIGHT_CONTROL_MODE;
    }
    else
        vStopStartModeChangeTimer(APP_TIME_MS(30000));
}
/****************************************************************************
 *
 * NAME: vManageIdentifyMode
 *
 * DESCRIPTION:
 * Manage the Identify mode for the lights in unicast mode and grouping.
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vManageIdentifyMode(te_SwitchState *peSwitchState, te_TransitionCode eTransitionCode )
{
      /* Calls individual function
       * Changes state
       * Addressing for individual functions
       *               Individual or group ? - well the address will be taken based on the state */
    DBG_vPrintf(TRACE_SWITCH_STATE,"\nIn vManageIdentifyMode(Mode = %d) TransitionCode = %d -> ", *peSwitchState,eTransitionCode);

    switch(eTransitionCode)
    {
        case COMM_AND_ON_TOGETHER_PRESSED:
            DBG_vPrintf(TRACE_SWITCH_STATE," vAppAddGroup \n");
            vAppAddGroup( u16GroupId, FALSE);
            break;

        case COMM_AND_OFF_TOGETHER_PRESSED:
            DBG_vPrintf(TRACE_SWITCH_STATE," vAppRemoveGroup \n");
            vAppRemoveGroup( u16GroupId, FALSE );
            break;

        case COMM_AND_UP_TOGETHER_PRESSED:
            DBG_vPrintf(TRACE_SWITCH_STATE," vSetTheNextLightIdentify \n");
            vSetTheNextLightIdentify();
            break;

        case COMM_AND_DOWN_TOGETHER_PRESSED:
            DBG_vPrintf(TRACE_SWITCH_STATE," vSetThePrevLightIdentify \n");
            vSetThePrevLightIdentify();
            break;

        case COMM_BUTTON_RELEASED:
            *peSwitchState = INDIVIDUAL_CONTROL_MODE;
            vStopStartModeChangeTimer(APP_TIME_MS(30000));
            break;
        default :
            break;
    }
}
/****************************************************************************
 *
 * NAME: vManageLightControlState
 *
 * DESCRIPTION:
 * Manage the Light control state in group mode. This is power on state for the
 * state machine.
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vManageLightControlState(te_SwitchState *peSwitchState, te_TransitionCode eTransitionCode )
{
      /* Calls individual function
       * Changes state
       * Addressing for individual functions
       *               Individual or group ? - well the address will be taken based on the state */

    DBG_vPrintf(TRACE_SWITCH_STATE,"\nIn vManageLightControlState(Mode = %d) TransitionCode = %d -> ", *peSwitchState,eTransitionCode);

      switch(eTransitionCode)
      {
          case ON_PRESSED:
              DBG_vPrintf(TRACE_SWITCH_STATE," E_CLD_ONOFF_CMD_ON \n");
              vAppOnOff(E_CLD_ONOFF_CMD_ON);
              break;

          case OFF_PRESSED:
              DBG_vPrintf(TRACE_SWITCH_STATE," E_CLD_ONOFF_CMD_OFF \n");
              vAppOnOff(E_CLD_ONOFF_CMD_OFF);
              break;

          case UP_PRESSED:
              DBG_vPrintf(TRACE_SWITCH_STATE," E_CLD_LEVELCONTROL_MOVE_MODE_UP \n");
              vAppLevelMove(E_CLD_LEVELCONTROL_MOVE_MODE_UP, 65, TRUE);
              break;

          case DOWN_PRESSED:
              DBG_vPrintf(TRACE_SWITCH_STATE," E_CLD_LEVELCONTROL_MOVE_MODE_DOWN \n");
              vAppLevelMove(E_CLD_LEVELCONTROL_MOVE_MODE_DOWN, 65, FALSE);
              break;

          case UP_AND_ON_TOGETHER_PRESSED:
              DBG_vPrintf(TRACE_SWITCH_STATE," vAppRecallSceneById = 1 \n");
              vAppRecallSceneById(SCENE_1, u16GroupId);
              break;

          case DOWN_AND_OFF_TOGETHER_PRESSED:
              DBG_vPrintf(TRACE_SWITCH_STATE," vAppRecallSceneById = 2 \n");
              vAppRecallSceneById(SCENE_2, u16GroupId);
              break;

          case COMM_BUTTON_PRESSED:
              *peSwitchState = IDENTIFY_MODE;
              vAppDiscover();
              break;

          case COMM_AND_UP_TOGETHER_PRESSED:
          {
              vAPP_ZCL_DeviceSpecific_SetIdentifyTime(0xFF);
              *peSwitchState = EZMODE_FIND_AND_BIND_MODE;
            }
              break;

          case DOWN_RELEASED:
          case UP_RELEASED:
              DBG_vPrintf(TRACE_SWITCH_STATE," vAppLevelStop \n");
              vAppLevelStop();
              break;

          default :
              break;
      }
}

/****************************************************************************
 *
 * NAME: vManageEZModeCommissioning
 *
 * DESCRIPTION:
 * Manage the Light commisioning in the EZ mode method where either
 *                                      use find and group or find and bind
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vManageEZModeCommissioning(te_SwitchState *peSwitchState, te_TransitionCode eTransitionCode )
{
      /* Calls individual function
       * Changes state
       * Addressing for individual functions
       * Individual or group ? - well the address will be taken based on the state */
    DBG_vPrintf(TRACE_SWITCH_STATE,"\nIn vManageEZModeCommissioning(Mode = %d) TransitionCode = %d -> ", *peSwitchState,eTransitionCode);

    switch(eTransitionCode)
    {
        case COMM_AND_ON_TOGETHER_PRESSED:
            DBG_vPrintf(TRACE_SWITCH_STATE," eEZ_FindAndBind \n");
            eEZ_FindAndBind(1,E_EZ_INITIATOR);
            break;

        case COMM_AND_OFF_TOGETHER_PRESSED:
            DBG_vPrintf(TRACE_SWITCH_STATE," vEZ_FactoryReset \n");
            vEZ_SetGroupId(u16GroupId);
            vEZ_FactoryReset(1);
            break;

        case COMM_AND_UP_TOGETHER_PRESSED:
            #if EZ_ENABLE_GROUP
                vEZ_SetGroupId(u16GroupId);
                eEZ_Group(1,E_EZ_INITIATOR);
            #endif
            break;

        case COMM_AND_DOWN_TOGETHER_PRESSED:
            /*App would change the channel*/
            vAppChangeChannel();
            break;

        case COMM_BUTTON_RELEASED:
            vAPP_ZCL_DeviceSpecific_IdentifyOff();
            vEZ_Exit(1);
            *peSwitchState = LIGHT_CONTROL_MODE;
            break;

        default :
            break;
    }
}
/****************************************************************************
 *
 * NAME: vSwitchStateMachine
 *
 * DESCRIPTION:
 * The control state machine called form the button handler function.
 *
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vSwitchStateMachine(te_TransitionCode eTransitionCode )
{
    switch (eSwitchState)
    {
        case  LIGHT_CONTROL_MODE:
            vManageLightControlState(&eSwitchState, eTransitionCode);
            break;

        case IDENTIFY_MODE:
            vManageIdentifyMode(&eSwitchState, eTransitionCode);
            break;

        case INDIVIDUAL_CONTROL_MODE:
            vManageIndividualControlMode(&eSwitchState, eTransitionCode);
            break;

        case EZMODE_FIND_AND_BIND_MODE:
            vManageEZModeCommissioning(&eSwitchState, eTransitionCode);
            break;

        default:
            break;
    }
}
/****************************************************************************
 *
 * NAME: vApp_ProcessKeyCombination
 *
 * DESCRIPTION:
 * Interpretes the button press and calls the state machine.
 *
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vApp_ProcessKeyCombination(APP_tsEvent sButton)
{
    te_TransitionCode eTransitionCode=NUMBER_OF_TRANSITION_CODE;
    DBG_vPrintf(TRACE_SWITCH_STATE, "\nButton Event = %d",sButton.eType);
    switch(sButton.eType)
    {
        case APP_E_EVENT_BUTTON_DOWN:
            DBG_vPrintf(TRACE_SWITCH_STATE, "\nButton Number= %d",sButton.uEvent.sButton.u8Button);
            DBG_vPrintf(TRACE_SWITCH_STATE, "\nDIO State    = %08x\n",sButton.uEvent.sButton.u32DIOState);

            eTransitionCode=sButton.uEvent.sButton.u8Button;

            DBG_vPrintf(TRACE_SWITCH_STATE, "\nTransition Code = %d\n",eTransitionCode);

            vSwitchStateMachine(eTransitionCode);
            vPingUCASTTarget();
            break;

        case APP_E_EVENT_BUTTON_UP:
            DBG_vPrintf(TRACE_SWITCH_STATE, "\nButton Number= %d",sButton.uEvent.sButton.u8Button);
            DBG_vPrintf(TRACE_SWITCH_STATE, "\nDIO State    = %08x\n",sButton.uEvent.sButton.u32DIOState);
            switch (sButton.uEvent.sButton.u8Button)
            {
                case 0:
                    eTransitionCode=COMM_BUTTON_RELEASED;
                    break;
                case 1:
                    eTransitionCode=DOWN_RELEASED;
                    break;
                case 4:
                    eTransitionCode=UP_RELEASED;
                    break;
                default :
                    break;
            }
            vSwitchStateMachine(eTransitionCode);
            break;
        default :
            break;
    }
}
/****************************************************************************
 *
 * NAME: eGetSwitchState
 *
 * DESCRIPTION:
 * Access function for the switch state.
 *
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC te_SwitchState eGetSwitchState(void)
{
    return eSwitchState;
}

/****************************************************************************
 *
 * NAME: APP_tskDelayedButtonAction
 *
 * DESCRIPTION:
 * Activated by the button delay timer and sends out the delayed command.
 *
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
OS_TASK(APP_tskDelayedButtonAction)
{
    /*Get the stored transition code */
    te_TransitionCode eTransitionCode = eGetDelayedButtonCode();
    /*Destroy the stored button code */
    vDQButtonPress();
    /*Take action based on the button code*/
    if( DOWN_PRESSED <= eTransitionCode && UP_PRESSED >= eTransitionCode )
    {
        vSendDelayedCommands(eTransitionCode);
    }

}


/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

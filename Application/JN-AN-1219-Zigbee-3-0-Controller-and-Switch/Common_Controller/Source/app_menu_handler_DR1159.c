/*****************************************************************************
 *
 * MODULE:             JN-AN-1219
 *
 * COMPONENT:          
 *
 * DESCRIPTION:        
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
#include "PDM.h"
#include "zps_gen.h"
#include "pdum_gen.h"
#include "app_common.h"
#include "bdb_api.h"
#include "zlo_controller_node.h"
#include "app_menu_handler.h"
#include "app_general_commands.h"
#include "app_on_off_commands.h"
#include "app_level_commands.h"
#include "app_colour_commands.h"
#include "app_scenes_commands.h"
#include "app_group_commands.h"
#include "app_identify_commands.h"
#include "AppHardwareApi.h"

#ifdef DEBUG_APP
    #define TRACE_APP   TRUE
#else
    #define TRACE_APP   FALSE
#endif

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/



/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/



/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
PUBLIC teShiftLevel eShiftLevel = E_SHIFT_0;

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
extern bool_t bSendFactoryResetOverAir;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/



/****************************************************************************
 *
 * NAME: 
 *
 * DESCRIPTION:
 * 
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_vHandleFactoryNewKeyPress(teUserKeyCodes eKeyCode)
{
    tsBDB_ZCLEvent sEvent;

    switch (eKeyCode)
    {
    case KEY_8:
        bSendFactoryResetOverAir=TRUE;
        DBG_vPrintf(TRACE_APP, "Button 8\n");
        break;

    case KEY_16:
        /*Add to Group 0 */
        vAppSetGroupId(0);
        sEvent.eType = BDB_E_ZCL_EVENT_TL_START;
        DBG_vPrintf(TRACE_APP, "CAll BDB ZCL Handler\n");
        BDB_vZclEventHandler(&sEvent);
        break;

    case KEY_1:
        // try classic discover and join
        sBDB.sAttrib.u32bdbPrimaryChannelSet = BDB_PRIMARY_CHANNEL_SET;
        sBDB.sAttrib.u32bdbSecondaryChannelSet = BDB_SECONDARY_CHANNEL_SET;
        BDB_eNsStartNwkSteering();
        DBG_vPrintf(TRACE_APP, "Button 1 -> Network sterring %08x\n", sBDB.sAttrib.u32bdbPrimaryChannelSet);
        break;

    case KEY_4:
        DBG_vPrintf(TRACE_APP, "\nAPP: Erasing flash records");
        PDM_vDeleteAllDataRecords();
        vAHI_SwReset();
        break;

    default:
        break;
    }
}

/****************************************************************************
 *
 * NAME: APP_vHandleKeyPress
 *
 * Button map is as follow, please update as changes are made:
 *
 * +--------------------+ +--------------------+ +--------------------+ +--------------------+
 * |0 Brightness Up     | |0 Move Hue Up       | |0 Move Saturation Up| |0 On                |
 * |1 Brightness Up     | |1 Move Color Temp Up| |1 Set Color Loop    | |1 On                |
 * |2 Brightness Up     | |2                   | |2                   | |2 On                |
 * |3 Factory New(Note1)| |3                   | |3                   | |3 On                |
 * |                    | |                    | |                    | |                    |
 * |        1(+)        | |       2(1)         | |       3(2)         | |       4(|)         |
 * +--------------------+ +--------------------+ +--------------------+ +--------------------+
 * +--------------------+ +--------------------+ +--------------------+ +--------------------+
 * |0 Brightness Down   | |0 Move Hue Down     | |0 Move Saturation Down|0 Off               |
 * |1 Brightness Down   | |1 Move Color Temp Down|1 Set Color Loop Stop |1 Off               |
 * |2 Brightness Down   | |2                   | |2                   | |2 Off               |
 * |3 Factory New(Note1)| |3                   | |3                   | |3 Off               |
 * |                    | |                    | |                    | |                    |
 * |       5(-)         | |       6(3)         | |        7(4)        | |        8(O)        | |                    | |                    | |                    | |                    |
 * +--------------------+ +--------------------+ +--------------------+ +--------------------+
 * +--------------------+ +--------------------+ +--------------------+ +--------------------+
 * |0 Recall Scene 1    | |0 Recall Scene 2    | |0 Recall Scene 3    | |0 Recall Scene 4    |
 * |1 Scene Save 1      | |1 Scene Save 2      | |1 Scene Save 3      | |1 Scene Save 4      |
 * |2                   | |2                   | |2                   | |2                   |
 * |3                   | |3                   | |3                   | |3                   |
 * |                    | |                    | |                    | |                    |
 * |        9(A)        | |       10(B)        | |       11(C)        | |       12(D)        |
 * +--------------------+ +--------------------+ +--------------------+ +--------------------+
 * +--------------------+ +--------------------+ +--------------------+ +--------------------+
 * |0 Shift             | |0 Unicast/Groupcast | |0 Identify/Next Light |0 TouchLink         |
 * |1 Shift             | |1 Unicast/Groupcast | |1 Identify/Next Light |1 TouchLink         |
 * |2 Shift             | |2 Unicast/Groupcast | |2 Identify/Next Light |2 TouchLink         |
 * |3 Shift             | |3 Unicast/Groupcast | |3 Identify/Next Light |3 TouchLink         |
 * |                    | |                    | |                    | |                    |
 * |       13(*)        | |       14(?)        | |       15(>)        | |      16(#)         |
 * +--------------------+ +--------------------+ +--------------------+ +--------------------+
 * Note1: FactoryNew(erases persistent data from the self(remote control unit))
 *        KeySequence: '-' '+' '-'
 *
 * DESCRIPTION:
 * Handles key presses
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_vHandleKeyPress(teUserKeyCodes eKeyCode)
{
    static uint8 u8SelfFR=0;

    tsBDB_ZCLEvent sEvent;

    switch (eShiftLevel)
    {
    case E_SHIFT_0:
       bSendFactoryResetOverAir = FALSE;
        u8SelfFR = 0;

        switch (eKeyCode)
        {
        case KEY_1: // Brightness Up
            vAppLevelMove(E_CLD_LEVELCONTROL_MOVE_MODE_UP, LEVEL_CHANGE_STEPS_PER_SEC_FAST, TRUE);
            break;
        case KEY_2: // Move Hue Up
            #ifdef CLD_COLOUR_CONTROL
            #if STOP_COLOUR_LOOP
            vAPPColourLoopStop();
            #endif
            vAppEnhancedMoveHue(E_CLD_COLOURCONTROL_MOVE_MODE_UP, 4000);
            #endif
            break;
        case KEY_3: // Move Saturation Up
            #ifdef CLD_COLOUR_CONTROL
            #if STOP_COLOUR_LOOP
            vAPPColourLoopStop();
            #endif
            vAppMoveSaturation(E_CLD_COLOURCONTROL_MOVE_MODE_UP, SAT_CHANGE_STEPS_PER_SEC);
            #endif
            break;
        case KEY_4: // On
            vAppOnOff(E_CLD_ONOFF_CMD_ON);
            break;
        case KEY_5: // Brightness Down
            vAppLevelMove(E_CLD_LEVELCONTROL_MOVE_MODE_DOWN, LEVEL_CHANGE_STEPS_PER_SEC_FAST, FALSE);
            break;
        case KEY_6: // Move Hue Down
            #ifdef CLD_COLOUR_CONTROL
            #if STOP_COLOUR_LOOP
            vAPPColourLoopStop();
            #endif
            vAppEnhancedMoveHue(E_CLD_COLOURCONTROL_MOVE_MODE_DOWN, 4000);
            #endif
            break;
        case KEY_7: // Move Saturation Down
            #ifdef CLD_COLOUR_CONTROL
            #if STOP_COLOUR_LOOP
            vAPPColourLoopStop();
            #endif
            vAppMoveSaturation(E_CLD_COLOURCONTROL_MOVE_MODE_DOWN, SAT_CHANGE_STEPS_PER_SEC);
            #endif
            break;
        case KEY_8: // Off
            vAppOnOff( E_CLD_ONOFF_CMD_OFF_EFFECT);
            break;
        case KEY_9: // Recall Scene 1
            #ifdef CLD_SCENES
            bAddrMode = TRUE;
            vAppRecallSceneById(1, sGroupTable.asGroupRecords[0].u16GroupId);
            #endif
            break;
        case KEY_10: // Recall Scene 2
             #ifdef CLD_SCENES
             bAddrMode=TRUE;
             vAppRecallSceneById(2, sGroupTable.asGroupRecords[0].u16GroupId);
             #endif

             break;
        case KEY_11: // Recall Scene 3
            #ifdef CLD_SCENES
            bAddrMode=TRUE;
            vAppRecallSceneById(3, sGroupTable.asGroupRecords[0].u16GroupId);
            #endif

            break;
        case KEY_12: // Recall Scene 4
            #ifdef CLD_SCENES
            bAddrMode=TRUE;
            vAppRecallSceneById(4,sGroupTable.asGroupRecords[0].u16GroupId);
            #endif
            break;
        case KEY_13: // Shift
            eShiftLevel += 1;
            break;
        case KEY_14: // Unicast/Groupcast Toggle
            bAddrMode = !bAddrMode;
            break;
        case KEY_15: // Identify / Next Light
            bAddrMode=FALSE;
            vSelectLight();
            break;
        case KEY_16:
            // TouchLink and Add to Default Group
            vAppSetGroupId(0);
            sEvent.eType = BDB_E_ZCL_EVENT_TL_START;
            BDB_vZclEventHandler(&sEvent);
            break;
        default : //Default
                 break;
        }
        break;

    case E_SHIFT_1:
        bSendFactoryResetOverAir=FALSE;
        u8SelfFR =0;
        switch (eKeyCode)
        {
        case KEY_1: // Brightness Up
            vAppLevelMove(E_CLD_LEVELCONTROL_MOVE_MODE_UP, LEVEL_CHANGE_STEPS_PER_SEC_MED, TRUE);
            break;
        case KEY_2: // Move Color Temperature Up
            #ifdef CLD_COLOUR_CONTROL
            #if STOP_COLOUR_LOOP
            vAPPColourLoopStop();
            #endif
            vAppMoveColourTemperature(E_CLD_COLOURCONTROL_MOVE_MODE_UP,
                                      COL_TEMP_CHANGE_STEPS_PER_SEC,
                                      COL_TEMP_PHY_MIN,
                                      COL_TEMP_PHY_MAX);
            #endif
            break;
        case KEY_3: // Set Color Loop
            #ifdef CLD_COLOUR_CONTROL
            vAppColorLoopSet(0x07,                                                            // flags
                             E_CLD_COLOURCONTROL_COLOURLOOP_ACTION_ACTIVATE_FROM_CURRENT,    // action
                             E_CLD_COLOURCONTROL_COLOURLOOP_DIRECTION_INCREMENT,            // direction
                             20,                                                             // Finish a loop in 60 secs
                             0x00);                                                            // start hue
            #endif
            break;
        case KEY_4: // On
            vAppOnOff(E_CLD_ONOFF_CMD_ON);
            break;
        case KEY_5: // Brightness Down
            vAppLevelMove(E_CLD_LEVELCONTROL_MOVE_MODE_DOWN, LEVEL_CHANGE_STEPS_PER_SEC_MED, FALSE);
            break;
        case KEY_6: //Move Temperature Down
            #ifdef CLD_COLOUR_CONTROL
            #if STOP_COLOUR_LOOP
            vAPPColourLoopStop();
            #endif
            /* move the real colour temperature down */
            vAppMoveColourTemperature(E_CLD_COLOURCONTROL_MOVE_MODE_DOWN,
                                         COL_TEMP_CHANGE_STEPS_PER_SEC,
                                         COL_TEMP_PHY_MIN,
                                         COL_TEMP_PHY_MAX);

            #endif
            break;
        case KEY_7: //Stop color Loop
            #ifdef CLD_COLOUR_CONTROL
            vAPPColourLoopStop();                                                    // stat hue
            #endif
            break;
        case KEY_8: // Off
            vAppOnOff(E_CLD_ONOFF_CMD_OFF_EFFECT);
            break;
        case KEY_9: // Scene Save 1
            #ifdef CLD_SCENES
            bAddrMode=TRUE;
            vAppStoreSceneById(1,sGroupTable.asGroupRecords[0].u16GroupId);
            eShiftLevel = 0;
            #endif
            break;
        case KEY_10: // Scene Save 2
            #ifdef CLD_SCENES
            bAddrMode=TRUE;
            vAppStoreSceneById(2,sGroupTable.asGroupRecords[0].u16GroupId);
            eShiftLevel = 0;
            #endif
            break;
        case KEY_11: // Scene Save 3
            #ifdef CLD_SCENES
            bAddrMode=TRUE;
            vAppStoreSceneById(3,sGroupTable.asGroupRecords[0].u16GroupId);
            eShiftLevel = 0;
            #endif
            break;
        case KEY_12: // Scene Save 4
            #ifdef CLD_SCENES
            bAddrMode=TRUE;
            vAppStoreSceneById(4,sGroupTable.asGroupRecords[0].u16GroupId);
            eShiftLevel = 0;
            #endif
            break;
        case KEY_13: // Shift
            eShiftLevel += 1;
            break;
        case KEY_14: // Unicast/Groupcast Toggle
            bAddrMode = !bAddrMode;
            break;
        case KEY_15: // Identify/Next Light
            bAddrMode=FALSE;
            vSelectLight();
            break;
        case KEY_16: // TouchLink and Add to Default Group
            sBDB.sAttrib.u16bdbCommissioningGroupID = sGroupTable.asGroupRecords[u8GroupId].u16GroupId;
            BDB_eFbTriggerAsInitiator(COLORSCENECONTROLLER_REMOTE_ENDPOINT);
            u8KeepAliveTime = FIND_AND_BIND_IME;
            break;
        default : //Default
             break;
        }
        break;

    case E_SHIFT_2:
        switch(eKeyCode)
        {
        case KEY_1: // Brightness Up
            vAppLevelMove(E_CLD_LEVELCONTROL_MOVE_MODE_UP, LEVEL_CHANGE_STEPS_PER_SEC_SLOW, TRUE);
            break;
        case KEY_2:
            #ifdef CLD_COLOUR_CONTROL
            #if STOP_COLOUR_LOOP
            vAPPColourLoopStop();
            #endif
            vAppGotoHueAndSat( 1);
            //vAppGotoColour();
            #endif
            break;
        case KEY_3:
            break;
        case KEY_4: // On
            vAppOnOff(E_CLD_ONOFF_CMD_ON);
            break;
        case KEY_5: // Brightness Down
            vAppLevelMove(E_CLD_LEVELCONTROL_MOVE_MODE_DOWN, LEVEL_CHANGE_STEPS_PER_SEC_SLOW, FALSE);
            break;
        case KEY_6:
            #ifdef CLD_COLOUR_CONTROL
            #if STOP_COLOUR_LOOP
            vAPPColourLoopStop();
            #endif
            vAppGotoHueAndSat( 0);
            #endif
            break;
        case KEY_8: // Off
            vAppOnOff(E_CLD_ONOFF_CMD_OFF_EFFECT);
            break;
        case KEY_11:
            BDB_eNsStartNwkSteering();
            break;
        case KEY_12: //Channel change from any channel other than 15 to 15 or from 15 to 11
            vAppChangeChannel();
            break;
        case KEY_13: // Shift
            eShiftLevel += 1;
            break;
        case KEY_14: // Unicast/Groupcast Toggle
            bAddrMode = !bAddrMode;
            break;
        case KEY_15: // Identify/Next Light
            bAddrMode=FALSE;
            vSelectLight();
            break;
        case KEY_16: // TouchLink and Add to Default Group
            vAppSetGroupId(0);
            sEvent.eType = BDB_E_ZCL_EVENT_TL_START;
            BDB_vZclEventHandler(&sEvent);
            break;
        default : //Default
             break;
        }
        break;

    case E_SHIFT_3:
        switch(eKeyCode)
        {
        case KEY_1:
            if(u8SelfFR==1)u8SelfFR=2;
            break;
        case KEY_2:
            break;
        case KEY_3:
            bAppSendBasicResetReq();
            break;
        case KEY_4: // On
            vAppOnOff(E_CLD_ONOFF_CMD_ON);
            break;
        case KEY_5: // Reset Self to Factory New
            if (u8SelfFR==0)u8SelfFR=1;
            if(u8SelfFR==2)
            {
                u8SelfFR=0;

                if (ZPS_E_SUCCESS !=  ZPS_eAplZdoLeaveNetwork(0, FALSE,FALSE))
                {
                    /* Leave failed, probably lost parent, so just reset everything */

                    APP_vFactoryResetRecords();
                    /* force a restart */
                    vAHI_SwReset();
                }
            }
            break;
        case KEY_8: // Off
            vAppOnOff(E_CLD_ONOFF_CMD_OFF_EFFECT);
            break;
        case KEY_9:
            vAppIdentifyEffect(E_CLD_IDENTIFY_EFFECT_BLINK);
            break;
        case KEY_10:
             vAppIdentifyEffect(E_CLD_IDENTIFY_EFFECT_BREATHE);
             break;
        case KEY_11:
             vAppIdentifyEffect(E_CLD_IDENTIFY_EFFECT_OKAY);
             break;
        case KEY_12:
             vAppIdentifyEffect(E_CLD_IDENTIFY_EFFECT_CHANNEL_CHANGE);
             break;
        case KEY_13: // Shift
             eShiftLevel = E_SHIFT_0;
             break;
        case KEY_14: // Unicast/Groupcast Toggle
             bAddrMode = !bAddrMode;
             break;
        case KEY_15: // Identify/Next Light
             bAddrMode=FALSE;
             vSelectLight();
             break;
        case KEY_16: // Factory Reset TouchLink Target
             sEvent.eType = BDB_E_ZCL_EVENT_TL_START;
                     bSendFactoryResetOverAir = TRUE;
                     BDB_vZclEventHandler(&sEvent);
             break;
        default : //Default
            u8SelfFR =0;
            bSendFactoryResetOverAir=FALSE;
                break;
        }
        break;

    default:
         u8SelfFR =0;
         break;
    }

    /* Update LED's to reflect shift level */
     APP_vSetLeds(eShiftLevel);
     APP_vBlinkLeds(eShiftLevel);



}


/****************************************************************************
 *
 * NAME: APP_vHandleKeyRelease
 *
 * DESCRIPTION:
 * handle any actions required if a key is released,
 * eg send a stop move command
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_vHandleKeyRelease(teUserKeyCodes eKeyCode)
{
    switch(eShiftLevel)
    {
    case E_SHIFT_0:
        switch(eKeyCode)
        {
        case KEY_1:
            vAppLevelStop(FALSE);
            break;
        case KEY_2: // Stop Move Hue
            #ifdef CLD_COLOUR_CONTROL
            vAppEnhancedMoveHue(E_CLD_COLOURCONTROL_MOVE_MODE_STOP, 0);
            #endif
            break;
        case KEY_3:
            // Stop Move Saturation
            #ifdef CLD_COLOUR_CONTROL
            vAppMoveSaturation(E_CLD_COLOURCONTROL_MOVE_MODE_STOP, 0);
            #endif
            break;
        case KEY_5:
            vAppLevelStop(FALSE);
            break;
        case KEY_6:
            // Stop Move Hue
            #ifdef CLD_COLOUR_CONTROL
            vAppEnhancedMoveHue(E_CLD_COLOURCONTROL_MOVE_MODE_STOP, 0);
            #endif
            break;
        case KEY_7:
            // Stop Move Saturation
            #ifdef CLD_COLOUR_CONTROL
            vAppMoveSaturation(E_CLD_COLOURCONTROL_MOVE_MODE_STOP, 0);
            #endif
            break;
        default:
            break;
        }
        break;
    case E_SHIFT_1:
        switch(eKeyCode)
        {
        case KEY_1:
            vAppLevelStop(FALSE);
            break;
        case KEY_2: // Stop Step Color Temperature
            #ifdef CLD_COLOUR_CONTROL
            vAppMoveColourTemperature(E_CLD_COLOURCONTROL_MOVE_MODE_STOP, 0, COL_TEMP_PHY_MIN,COL_TEMP_PHY_MAX);
            #endif
            break;
        case KEY_5:
            vAppLevelStop(FALSE);
            break;
        case KEY_6:
            // Stop Step Color Temperature
            #ifdef CLD_COLOUR_CONTROL
            vAppMoveColourTemperature(E_CLD_COLOURCONTROL_MOVE_MODE_STOP, 0, COL_TEMP_PHY_MIN,COL_TEMP_PHY_MAX);
            #endif
                    break;
        default:
            break;
        }
        break;
    case E_SHIFT_2:
        switch(eKeyCode)
        {
        case KEY_1:
            vAppLevelStop(FALSE);
            break;
        case KEY_5:
            vAppLevelStop(FALSE);
            break;

        default:
           break;
        }
        break;
    case E_SHIFT_3:
        break;
    }
}



/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

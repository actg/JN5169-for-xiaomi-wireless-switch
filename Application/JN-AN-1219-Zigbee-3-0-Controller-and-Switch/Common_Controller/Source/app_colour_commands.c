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
#include "zps_gen.h"
#include "pdum_gen.h"
#include "app_common.h"
#include "zlo_controller_node.h"
#include "app_menu_handler.h"
#include "app_general_commands.h"
#include "app_colour_commands.h"


#ifdef DEBUG_REMOTE_NODE
    #define TRACE_REMOTE_NODE   TRUE
#else
    #define TRACE_REMOTE_NODE   FALSE
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

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/


/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/



#ifdef CLD_COLOUR_CONTROL
/****************************************************************************
 *
 * NAME: vAppMoveHue
 *
 * DESCRIPTION: sends a move hue command to a light or lights
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppMoveHue(teCLD_ColourControl_MoveMode eMode, uint8 u8StepsPerSec)
{
    tsCLD_ColourControl_MoveHueCommandPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE);

    sPayload.eMode = eMode;
    sPayload.u8Rate = u8StepsPerSec;
    sPayload.u8OptionsMask = 0;
    sPayload.u8OptionsOverride = 0;

    eCLD_ColourControlCommandMoveHueCommandSend(
                        sDeviceTable.asDeviceRecords[0].u8Endpoint,
                        sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint,
                        &sAddress,
                        &u8Seq,
                        &sPayload);
}


/****************************************************************************
 *
 * NAME: vAppEnhancedMoveHue
 *
 * DESCRIPTION: sends a enhanced move hue command to a light or lights
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppEnhancedMoveHue( teCLD_ColourControl_MoveMode eMode, uint16 u16StepsPerSec)
{
    tsCLD_ColourControl_EnhancedMoveHueCommandPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE);

    sPayload.eMode = eMode;
    sPayload.u16Rate = u16StepsPerSec;
    sPayload.u8OptionsMask = 0;
    sPayload.u8OptionsOverride = 0;

    eCLD_ColourControlCommandEnhancedMoveHueCommandSend(
                        sDeviceTable.asDeviceRecords[0].u8Endpoint,
                        sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint,   // dst ep
                        &sAddress,
                        &u8Seq,
                        &sPayload);
}


/****************************************************************************
 *
 * NAME: vAppStepHue
 *
 * DESCRIPTION: sends a move step hue command to a light or lights
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppStepHue(teCLD_ColourControl_StepMode eMode, uint8 u8StepSize, uint8 u8TransitionTime)
{
    tsCLD_ColourControl_StepHueCommandPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE);
    sPayload.eMode = eMode;
    sPayload.u8StepSize = u8StepSize;
    sPayload.u8TransitionTime = u8TransitionTime;
    sPayload.u8OptionsMask = 0;
    sPayload.u8OptionsOverride = 0;

    eCLD_ColourControlCommandStepHueCommandSend(
                        sDeviceTable.asDeviceRecords[0].u8Endpoint,
                        sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint,
                        &sAddress,
                        &u8Seq,
                        &sPayload);
}


/****************************************************************************
 *
 * NAME: vAppEnhancedStepHue
 *
 * DESCRIPTION: sends an enhanced move step hue command to a light or lights
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppEnhancedStepHue(teCLD_ColourControl_StepMode eMode, uint16 u16StepSize, uint16 u16TransitionTime)
{
    tsCLD_ColourControl_EnhancedStepHueCommandPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE);

    sPayload.eMode = eMode;
    sPayload.u16StepSize = u16StepSize;
    sPayload.u16TransitionTime = u16TransitionTime;
    sPayload.u8OptionsMask = 0;
    sPayload.u8OptionsOverride = 0;

    eCLD_ColourControlCommandEnhancedStepHueCommandSend(
                        sDeviceTable.asDeviceRecords[0].u8Endpoint,
                        sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint,
                        &sAddress,
                        &u8Seq,
                        &sPayload);
}

/****************************************************************************
 *
 * NAME: vAppMoveToSaturaiton
 *
 * DESCRIPTION: sends a move to saturation command to a light or lights
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppMoveToSaturaiton(uint8 u8Saturation, uint16 u16TransitionTime)
{
    tsCLD_ColourControl_MoveToSaturationCommandPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE);
    sPayload.u8Saturation = u8Saturation;
    sPayload.u16TransitionTime = u16TransitionTime;
    sPayload.u8OptionsMask = 0;
    sPayload.u8OptionsOverride = 0;

    eCLD_ColourControlCommandMoveToSaturationCommandSend(
                        sDeviceTable.asDeviceRecords[0].u8Endpoint,
                        sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint,
                        &sAddress,
                        &u8Seq,
                        &sPayload);
}

/****************************************************************************
 *
 * NAME: vAppMoveToHueAndSaturation
 *
 * DESCRIPTION: sends a move to hue and saturation command to a light or lights
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
    PUBLIC void vAppMoveToHueAndSaturation(uint8 u8Hue, uint8 u8Saturation, uint16 u16Time)
{
    tsCLD_ColourControl_MoveToHueAndSaturationCommandPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE);

    sPayload.u8Hue = u8Hue;
    sPayload.u8Saturation = u8Saturation;
    sPayload.u16TransitionTime = u16Time;
    sPayload.u8OptionsMask = 0;
    sPayload.u8OptionsOverride = 0;

    eCLD_ColourControlCommandMoveToHueAndSaturationCommandSend(
                        sDeviceTable.asDeviceRecords[0].u8Endpoint,
                        sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint,   // dst ep
                        &sAddress,
                        &u8Seq,
                        &sPayload);
}

/****************************************************************************
 *
 * NAME: vAppEnhancedMoveToHueAndSaturation
 *
 * DESCRIPTION: sends an enhanced move to jue and saturation command to a light or lights
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppEnhancedMoveToHueAndSaturation(uint16 u16Hue, uint8 u8Saturation, uint16 u16Time)
{
    tsCLD_ColourControl_EnhancedMoveToHueAndSaturationCommandPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE);

    sPayload.u16EnhancedHue = u16Hue;
    sPayload.u8Saturation = u8Saturation;
    sPayload.u16TransitionTime = u16Time;
    sPayload.u8OptionsMask = 0;
    sPayload.u8OptionsOverride = 0;

    eCLD_ColourControlCommandEnhancedMoveToHueAndSaturationCommandSend(
            sDeviceTable.asDeviceRecords[0].u8Endpoint,
                        sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint,   // dst ep
                        &sAddress,
                        &u8Seq,
                        &sPayload);
}


/****************************************************************************
 *
 * NAME: vAppGotoColour
 *
 * DESCRIPTION: sends a goto colour XY command to a light or lights
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppGotoColour( void /*uint8 u8Colour*/)
{
    tsCLD_ColourControl_MoveToColourCommandPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;
    static uint8 u8Colour = 0;

    vSetAddress(&sAddress, FALSE);

    /* transition over 2 seconds */
    sPayload.u16TransitionTime = 20;
    sPayload.u8OptionsMask = 0;
    sPayload.u8OptionsOverride = 0;

    switch (u8Colour)
    {
        case 0:
            sPayload.u16ColourX = (CLD_COLOURCONTROL_RED_X * 65536) - 10;
            sPayload.u16ColourY = (CLD_COLOURCONTROL_RED_Y * 65536);
            break;
        case 1:
            sPayload.u16ColourX = (CLD_COLOURCONTROL_BLUE_X * 65536);
            sPayload.u16ColourY = (CLD_COLOURCONTROL_BLUE_Y * 65536);
            break;
        case 2:
            sPayload.u16ColourX = (CLD_COLOURCONTROL_GREEN_X * 65536);
            sPayload.u16ColourY = (CLD_COLOURCONTROL_GREEN_Y * 65536);
            break;
        case 3:
            sPayload.u16ColourX = (CLD_COLOURCONTROL_WHITE_X * 65536);
            sPayload.u16ColourY = (CLD_COLOURCONTROL_WHITE_Y * 65536);
            break;
        default:
            return;
            break;
    }

    u8Colour++;
    if (u8Colour > 3)
    {
        u8Colour = 0;
    }

    eCLD_ColourControlCommandMoveToColourCommandSend(
                        sDeviceTable.asDeviceRecords[0].u8Endpoint,
                        sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint,   // dst ep
                        &sAddress,
                        &u8Seq,
                        &sPayload);
}

/****************************************************************************
 *
 * NAME: vAppGotoHueAndSat
 *
 * DESCRIPTION:
 * send a goto hue and saturatuion command to a light or lights
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppGotoHueAndSat( uint8 u8Direction)
{
tsCLD_ColourControl_EnhancedMoveToHueAndSaturationCommandPayload sPayload;

uint8 u8Seq;
tsZCL_Address sAddress;
static uint8 u8Step=0;



    vSetAddress(&sAddress, FALSE);

    /* transition over 2 seconds */
    sPayload.u16TransitionTime = 20;

    if (u8Direction!=0)
{
        u8Step++;
        if (u8Step > 6){
            u8Step=0;
        }
    }
    else
    {
        u8Step--;
        if (u8Step == 255){
            u8Step=6;
        }
    }


    switch(u8Step)
{
        case 0:
            sPayload.u16EnhancedHue = 0;
            sPayload.u8Saturation = 0;
        break;
        case 1:
            sPayload.u16EnhancedHue = 0x0000;
            sPayload.u8Saturation = 254;
            break;
        case 2:
            sPayload.u16EnhancedHue = 0x2e00;
            sPayload.u8Saturation = 254;
            break;
        case 3:
            sPayload.u16EnhancedHue = 0x5500;
            sPayload.u8Saturation = 254;
            break;
        case 4:
            sPayload.u16EnhancedHue = 0x7d00;
            sPayload.u8Saturation = 254;
            break;
        case 5:
            sPayload.u16EnhancedHue = 0xaa00;
            sPayload.u8Saturation = 254;
            break;
        case 6:
            sPayload.u16EnhancedHue = 0xdd00;
            sPayload.u8Saturation = 254;
            break;
    }
    sPayload.u8OptionsMask = 0;
    sPayload.u8OptionsOverride = 0;

    eCLD_ColourControlCommandEnhancedMoveToHueAndSaturationCommandSend(
             sDeviceTable.asDeviceRecords[0].u8Endpoint,
                                    sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint,   // dst ep
                                    &sAddress,
                                    &u8Seq,
                                    &sPayload );

}

/****************************************************************************
 *
 * NAME: vAppMoveColour
 *
 * DESCRIPTION: send a move colour XY command to a light or lights
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppMoveColour(int16 i16RateX, int16 i16RateY)
{
    tsCLD_ColourControl_MoveColourCommandPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE);

    sPayload.i16RateX = i16RateX;
    sPayload.i16RateY = i16RateY;
    sPayload.u8OptionsMask = 0;
    sPayload.u8OptionsOverride = 0;

    eCLD_ColourControlCommandMoveColourCommandSend(
                        sDeviceTable.asDeviceRecords[0].u8Endpoint,
                        sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint,   // dst ep
                        &sAddress,
                        &u8Seq,
                        &sPayload);
}

/****************************************************************************
 *
 * NAME: vAppStepColour
 *
 * DESCRIPTION: send a move step colour XY command to a light or lights
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppStepColour(int16 i16StepX, int16 i16StepY, uint16 u16TransitionTime)
{
    tsCLD_ColourControl_StepColourCommandPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE);

    sPayload.i16StepX = i16StepX;
    sPayload.i16StepY = i16StepY;
    sPayload.u16TransitionTime = u16TransitionTime;
    sPayload.u8OptionsMask = 0;
    sPayload.u8OptionsOverride = 0;

    eCLD_ColourControlCommandStepColourCommandSend(
                        sDeviceTable.asDeviceRecords[0].u8Endpoint,
                        sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint,   // dst ep
                        &sAddress,
                        &u8Seq,
                        &sPayload);
}


/****************************************************************************
 *
 * NAME: vAppMoveToHue
 *
 * DESCRIPTION: send a move to hue command to a light or lights
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppMoveToHue(uint8 u8Hue, teCLD_ColourControl_Direction eDirection, uint16 u16TransitionTime)
{

    tsCLD_ColourControl_MoveToHueCommandPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE);

    DBG_vPrintf(TRACE_REMOTE_NODE, "\nMoveTo %02x", u8Hue);

    sPayload.u8Hue = u8Hue;
    sPayload.eDirection = eDirection;
    sPayload.u16TransitionTime = u16TransitionTime;
    sPayload.u8OptionsMask = 0;
    sPayload.u8OptionsOverride = 0;

    eCLD_ColourControlCommandMoveToHueCommandSend(
                        sDeviceTable.asDeviceRecords[0].u8Endpoint,
                        sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint,
                        &sAddress,
                        &u8Seq,
                        &sPayload);
}


/****************************************************************************
 *
 * NAME: vAppEnhancedMoveToHue
 *
 * DESCRIPTION: send an enhanced move to hue command to a light or lights
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppEnhancedMoveToHue(uint16 u16Hue, teCLD_ColourControl_Direction eDirection)
{

    tsCLD_ColourControl_EnhancedMoveToHueCommandPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE);

    DBG_vPrintf(TRACE_REMOTE_NODE, "\nEnc MoveHueTo %04x", u16Hue);

    sPayload.eDirection = eDirection;
    sPayload.u16TransitionTime = 10;
    sPayload.u16EnhancedHue = u16Hue;
    sPayload.u8OptionsMask = 0;
    sPayload.u8OptionsOverride = 0;

    eCLD_ColourControlCommandEnhancedMoveToHueCommandSend(
            sDeviceTable.asDeviceRecords[0].u8Endpoint,
            sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint,   // dst ep
            &sAddress,
            &u8Seq,
            &sPayload);
}


/****************************************************************************
 *
 * NAME: vAppMoveSaturation
 *
 * DESCRIPTION: send a move saturatuion command to a light or lights
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppMoveSaturation( teCLD_ColourControl_MoveMode eMode, uint8 u8StepsPerSec)
{
    tsCLD_ColourControl_MoveSaturationCommandPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE);

    sPayload.eMode = eMode;
    sPayload.u8Rate = u8StepsPerSec;
    sPayload.u8OptionsMask = 0;
   sPayload.u8OptionsOverride = 0;

    eCLD_ColourControlCommandMoveSaturationCommandSend(
                        sDeviceTable.asDeviceRecords[0].u8Endpoint,
                        sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint,   // dst ep
                        &sAddress,
                        &u8Seq,
                        &sPayload);
}


/****************************************************************************
 *
 * NAME: vAppStepSaturation
 *
 * DESCRIPTION: send a move step saturatuion command to a light or lights
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppStepSaturation( teCLD_ColourControl_StepMode eMode, uint8 u8StepSize)
{
    tsCLD_ColourControl_StepSaturationCommandPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE);

    sPayload.eMode = eMode;
    sPayload.u8StepSize = u8StepSize;
    sPayload.u8TransitionTime = 0x0006;
    sPayload.u8OptionsMask = 0;
    sPayload.u8OptionsOverride = 0;

    eCLD_ColourControlCommandStepSaturationCommandSend(
                        sDeviceTable.asDeviceRecords[0].u8Endpoint,
                        sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint,   // dst ep
                        &sAddress,
                        &u8Seq,
                        &sPayload);
}

/****************************************************************************
 *
 * NAME: vAppMoveToColourTemperature
 *
 * DESCRIPTION: send a move colour temperature command to a light or lights
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppMoveToColourTemperature(uint16 u16ColourTemperatureMired,
                                        uint16 u16TransitionTime)
{
    tsCLD_ColourControl_MoveToColourTemperatureCommandPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE);

    sPayload.u16ColourTemperatureMired = u16ColourTemperatureMired;
    sPayload.u16TransitionTime = u16TransitionTime;
    sPayload.u8OptionsMask = 0;
    sPayload.u8OptionsOverride = 0;

    eCLD_ColourControlCommandMoveToColourTemperatureCommandSend(
                        sDeviceTable.asDeviceRecords[0].u8Endpoint,
                        sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint,
                        &sAddress,
                        &u8Seq,
                        &sPayload);
}

/****************************************************************************
 *
 * NAME: vAppMoveColourTemperature
 *
 * DESCRIPTION: send a move to colour temperature command to a light or lights
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppMoveColourTemperature( teCLD_ColourControl_MoveMode eMode,
                                       uint16 u16StepsPerSec,
                                       uint16 u16ColourTemperatureMin,
                                       uint16 u16ColourTemperatureMax)
{
    tsCLD_ColourControl_MoveColourTemperatureCommandPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE);

    sPayload.eMode = eMode;
    sPayload.u16Rate = u16StepsPerSec;
    sPayload.u16ColourTemperatureMiredMin = u16ColourTemperatureMin;
    sPayload.u16ColourTemperatureMiredMax = u16ColourTemperatureMax;
    sPayload.u8OptionsMask = 0;
    sPayload.u8OptionsOverride = 0;

    eCLD_ColourControlCommandMoveColourTemperatureCommandSend(
                        sDeviceTable.asDeviceRecords[0].u8Endpoint,
                        sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint,
                        &sAddress,
                        &u8Seq,
                        &sPayload);
}

/****************************************************************************
 *
 * NAME: vAppStepMoveStop
 *
 * DESCRIPTION: send a move stop command to a light or lights
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppStepMoveStop(void)
{
    uint8 u8Seq;
    tsZCL_Address sAddress;
    tsCLD_ColourControl_StopMoveStepCommandPayload sPayload;

    sPayload.u8OptionsMask = 0;
    sPayload.u8OptionsOverride = 0;

    vSetAddress(&sAddress, FALSE);

    eCLD_ColourControlCommandStopMoveStepCommandSend(
                        sDeviceTable.asDeviceRecords[0].u8Endpoint,
                        sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint,   // dst ep
                        &sAddress,
                        &u8Seq,
                        &sPayload);
}


/****************************************************************************
 *
 * NAME: vAppStepColourTemperature
 *
 * DESCRIPTION: send a move step colour temperature command to a light or lights
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppStepColourTemperature( teCLD_ColourControl_StepMode eMode, uint16 u16StepSize)
{
    tsCLD_ColourControl_StepColourTemperatureCommandPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE);

    sPayload.eMode = eMode;
    sPayload.u16StepSize = u16StepSize;
    sPayload.u16TransitionTime = 10;
    sPayload.u16ColourTemperatureMiredMin = 4;
    sPayload.u16ColourTemperatureMiredMax = 1000;
    sPayload.u8OptionsMask = 0;
    sPayload.u8OptionsOverride = 0;

    eCLD_ColourControlCommandStepColourTemperatureCommandSend(
                        sDeviceTable.asDeviceRecords[0].u8Endpoint,
                        sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint,
                        &sAddress,
                        &u8Seq,
                        &sPayload);
}

/****************************************************************************
 *
 * NAME: vAPPColourLoopStop
 *
 * DESCRIPTION: send a colour loop stop command to a light or lights
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAPPColourLoopStop(void)
{
    vAppColorLoopSet(E_CLD_COLOURCONTROL_FLAGS_UPDATE_ACTION,            // flags
                     E_CLD_COLOURCONTROL_COLOURLOOP_ACTION_DEACTIVATE,        // action
                     0x00,                                                    // direction
                     0x00,                                                    // time
                     0x00);
}

/****************************************************************************
 *
 * NAME: vAppColorLoopSet
 *
 * DESCRIPTION: send a colour loop set command to a light or lights
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppColorLoopSet(uint8 u8UpdateFlags, teCLD_ColourControl_LoopAction eAction,
                             teCLD_ColourControl_LoopDirection eDirection,
                             uint16 u16Time, uint16 u16StartHue)
{
    uint8 u8Seq;
    tsZCL_Address sAddress;
    tsCLD_ColourControl_ColourLoopSetCommandPayload sPayload;

    sPayload.u8UpdateFlags = u8UpdateFlags;
    sPayload.eAction       = eAction;
    sPayload.eDirection    = eDirection;
    sPayload.u16Time       = u16Time;
    sPayload.u16StartHue   = u16StartHue;
    sPayload.u8OptionsMask = 0;
    sPayload.u8OptionsOverride = 0;

   vSetAddress(&sAddress, FALSE);

   eCLD_ColourControlCommandColourLoopSetCommandSend(
                        sDeviceTable.asDeviceRecords[0].u8Endpoint,
                        sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint,
                        &sAddress,
                        &u8Seq,
                        &sPayload);
}

#endif





/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

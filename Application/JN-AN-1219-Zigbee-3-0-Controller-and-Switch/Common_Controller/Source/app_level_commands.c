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
#include "app_level_commands.h"


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

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/


/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/



/****************************************************************************
 *
 * NAME: vAppLevelMove
 *
 * DESCRIPTION: sends a move level command to a light or lights
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppLevelMove(teCLD_LevelControl_MoveMode eMode, uint8 u8Rate, bool_t bWithOnOff)
{
    tsCLD_LevelControl_MoveCommandPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE);

    sPayload.u8Rate = u8Rate;
    sPayload.u8MoveMode = eMode;

    eCLD_LevelControlCommandMoveCommandSend(sDeviceTable.asDeviceRecords[0].u8Endpoint,
                                            sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint,
                                            &sAddress,
                                            &u8Seq,
                                            bWithOnOff, /* with on off */
                                            &sPayload);
}


/****************************************************************************
 *
 * NAME: vAppLevelStop
 *
 * DESCRIPTION: sends a move level stop command to a light or lights
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppLevelStop(bool_t bWithOnOff)
{
    uint8 u8Seq;
    tsZCL_Address sAddress;
    teZCL_Status eStatus;

    tsCLD_LevelControl_StopCommandPayload  sPayload;

    sPayload.u8OptionsMask = 0;
    sPayload.u8OptionsOverride = 0;


    vSetAddress(&sAddress, FALSE);
    eStatus = eCLD_LevelControlCommandStopCommandSend(
                        sDeviceTable.asDeviceRecords[0].u8Endpoint,
                        sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint,
                        &sAddress,
                        &u8Seq,
                        bWithOnOff,
                        &sPayload);
#if TRACE_APP
    if ( eStatus != E_ZCL_SUCCESS)
    {
        DBG_vPrintf(TRACE_APP, "\neCLD_LevelControlCommandStopCommandSend  eStatus = %d", eStatus);
    }
#endif

}

/****************************************************************************
 *
 * NAME: vAppLevelStepMove
 *
 * DESCRIPTION: sends a move step level command to a light or lights
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppLevelStepMove(teCLD_LevelControl_MoveMode eMode, uint8 u8StepSize, uint16 u16TransitionTime, bool_t bWithOnOff)
{
    tsCLD_LevelControl_StepCommandPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE);

    sPayload.u16TransitionTime = u16TransitionTime;
    sPayload.u8StepMode = eMode;
    sPayload.u8StepSize = u8StepSize;
    eCLD_LevelControlCommandStepCommandSend(
            sDeviceTable.asDeviceRecords[0].u8Endpoint,
                        sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint,
                        &sAddress,
                        &u8Seq,
                        bWithOnOff,
                        &sPayload);
}



/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

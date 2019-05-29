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
#include "app_on_off_commands.h"


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
 * NAME: vAppOnOff
 *
 * DESCRIPTION: sends an on off command to a light or lights
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppOnOff(teCLD_OnOff_Command eCmd)
{
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE);

    if ((eCmd == E_CLD_ONOFF_CMD_ON) ||
         (eCmd == E_CLD_ONOFF_CMD_OFF) ||
         (eCmd == E_CLD_ONOFF_CMD_TOGGLE) ||
         (eCmd == E_CLD_ONOFF_CMD_ON_RECALL_GLOBAL_SCENE))
    {
        eCLD_OnOffCommandSend( sDeviceTable.asDeviceRecords[0].u8Endpoint,
                               sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint,
                               &sAddress,
                               &u8Seq,
                               eCmd);
    } else if (eCmd == E_CLD_ONOFF_CMD_OFF_EFFECT)
    {
        tsCLD_OnOff_OffWithEffectRequestPayload sPayload;
        sPayload.u8EffectId = 0;
        sPayload.u8EffectVariant = 0;

        eCLD_OnOffCommandOffWithEffectSend(
                sDeviceTable.asDeviceRecords[0].u8Endpoint,
                sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint,
                &sAddress, &u8Seq, &sPayload);
    }
    else if (E_CLD_ONOFF_CMD_ON_TIMED_OFF)
    {
        tsCLD_OnOff_OnWithTimedOffRequestPayload sPayload;
        sPayload.u8OnOff = 0x00;  // 0x01 for accept if OnOff = 1
        sPayload.u16OnTime = 0;   // 1/10th of a second
        sPayload.u16OffTime = 20; // 1/10th of a second

        eCLD_OnOffCommandOnWithTimedOffSend(
                sDeviceTable.asDeviceRecords[0].u8Endpoint,
                sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint,
                &sAddress, &u8Seq, &sPayload);
    }

}

/****************************************************************************
 *
 * NAME: vAppOffEffect
 *
 * DESCRIPTION: sends an off with effect command to a light or lights
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
#ifndef UNUSED_COMMANDS
PRIVATE void vAppOffEffect( uint8 u8Effect, uint8 u8Varient)
{
    uint8 u8Seq;
    tsZCL_Address sAddress;
    tsCLD_OnOff_OffWithEffectRequestPayload sPayload;

    sPayload.u8EffectId = u8Effect;
    sPayload.u8EffectVariant = u8Varient;


    sAddress.eAddressMode = E_ZCL_AM_SHORT_NO_ACK;
    sAddress.uAddress.u16DestinationAddress = sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u16NwkAddr;

    eCLD_OnOffCommandOffWithEffectSend(sDeviceTable.asDeviceRecords[0].u8Endpoint,
            sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint,
                            &sAddress,
                            &u8Seq,
                            &sPayload );
}
#endif



/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

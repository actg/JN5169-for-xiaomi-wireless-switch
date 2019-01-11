/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          App_DimmerSwitch.c
 *
 * DESCRIPTION:        ZHA Demo: Dimmer Switch Implementation
 *
 *****************************************************************************
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
 ****************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include <jendefs.h>
#include "zps_gen.h"
#include "GenericBoard.h"
#include "App_DimmerSwitch.h"
#include <string.h>

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
tsHA_DimmerSwitchDevice sSwitch;
/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
const uint8 u8MyEndpoint = DIMMERSWITCH_SWITCH_ENDPOINT;

/****************************************************************************
 **
 ** NAME: eApp_HA_RegisterEndpoint
 **
 ** DESCRIPTION:
 ** Register ZHA endpoints
 **
 ** PARAMETER
 ** Type                                Name                    Descirption
 ** tfpZCL_ZCLCallBackFunction          fptr                    Pointer to ZCL Callback function
 **
 **
 **
 ** RETURNS:
 ** teZCL_Status
 *
 ****************************************************************************/
teZCL_Status eApp_HA_RegisterEndpoint(tfpZCL_ZCLCallBackFunction fptr)

{
    return eHA_RegisterDimmerSwitchEndPoint(DIMMERSWITCH_SWITCH_ENDPOINT,
                                                fptr,
                                                &sSwitch);
}

/****************************************************************************
 *
 * NAME: vAPP_ZCL_DeviceSpecific_Init
 *
 * DESCRIPTION:
 * ZCL Device Specific initialization
 *
 * PARAMETER: void
 *
 * RETURNS: void
 *
 ****************************************************************************/
void vAPP_ZCL_DeviceSpecific_Init(void)
{
    /* Initialise the strings in Basic */
    sSwitch.sBasicServerCluster.sManufacturerName.u8Length = strlen(CONFIG_MANUFACTURER_NAME);
    memcpy(sSwitch.sBasicServerCluster.au8ManufacturerName, CONFIG_MANUFACTURER_NAME, sSwitch.sBasicServerCluster.sManufacturerName.u8Length);
    sSwitch.sBasicServerCluster.sModelIdentifier.u8Length = strlen(CONFIG_MODEL_ID);
    memcpy(sSwitch.sBasicServerCluster.au8ModelIdentifier, CONFIG_MODEL_ID, sSwitch.sBasicServerCluster.sModelIdentifier.u8Length);
    sSwitch.sBasicServerCluster.sDateCode.u8Length = strlen(CONFIG_DATE_CODE);
    memcpy(sSwitch.sBasicServerCluster.au8DateCode, CONFIG_DATE_CODE, sSwitch.sBasicServerCluster.sDateCode.u8Length);
    sSwitch.sBasicServerCluster.u8ApplicationVersion = CONFIG_APP_SW_VERSION;
    sSwitch.sBasicServerCluster.u8HardwareVersion = CONFIG_HW_VERSION; 
}
/****************************************************************************
 *
 * NAME: vAPP_ZCL_DeviceSpecific_SetIdentifyTime
 *
 * DESCRIPTION:
 * ZCL Device Specific setting of identify time
 *
 * PARAMETER:
 * uint16 u16Time Identify time duration
 *
 * RETURNS: void
 *
 ****************************************************************************/
PUBLIC void vAPP_ZCL_DeviceSpecific_SetIdentifyTime(uint16 u16Time)
{
    sSwitch.sIdentifyServerCluster.u16IdentifyTime=u16Time;
}
/****************************************************************************
 *
 * NAME: vAPP_ZCL_DeviceSpecific_UpdateIdentify
 *
 * DESCRIPTION:
 * ZCL Device Specific initialization
 *
 * PARAMETER: void
 *
 * RETURNS: void
 *
 ****************************************************************************/
PUBLIC void vAPP_ZCL_DeviceSpecific_UpdateIdentify(void)
{
    vGenericLEDSetOutput(1, sSwitch.sIdentifyServerCluster.u16IdentifyTime%2);
}
/****************************************************************************
 *
 * NAME: vAPP_ZCL_DeviceSpecific_IdentifyOff
 *
 * DESCRIPTION:
 * ZCL Device Specific initialization
 *
 * PARAMETER: void
 *
 * RETURNS: void
 *
 ****************************************************************************/
PUBLIC void vAPP_ZCL_DeviceSpecific_IdentifyOff(void)
{
    vAPP_ZCL_DeviceSpecific_SetIdentifyTime(0);
    vGenericLEDSetOutput(1, 0);
}

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

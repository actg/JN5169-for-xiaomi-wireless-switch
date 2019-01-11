/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          App_ColorTempTunableWhiteLight.c
 *
 * DESCRIPTION:        ZHA Light Application (Implementation)
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
#include <jendefs.h>
#include "zps_gen.h"
#include "App_ColorTempTunableWhiteLight.h"
#include "AppHardwareApi.h"
#include "dbg.h"
#include <string.h>

#include "app_light_interpolation.h"
#include "DriverBulb_Shim.h"


/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

tsHA_ColourDimmableLightDevice sLight;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

/****************************************************************************
 *
 * NAME: eApp_HA_RegisterEndpoint
 *
 * DESCRIPTION:
 * Register ZLL endpoints
 *
 * PARAMETER
 * Type                        Name                  Descirption
 * tfpZCL_ZCLCallBackFunction  fptr                  Pointer to ZCL Callback function
 * tsZLL_CommissionEndpoint    psCommissionEndpoint  Pointer to Commission Endpoint
 *
 * RETURNS:
 * teZCL_Status
 *
 ****************************************************************************/
teZCL_Status eApp_HA_RegisterEndpoint(tfpZCL_ZCLCallBackFunction fptr)
{

    return eHA_RegisterColourDimmableLightEndPoint(COLORTEMPTUNABLEWHITELIGHT_LIGHT_ENDPOINT,
                                              fptr,
                                              &sLight);
}
/****************************************************************************
 *
 * NAME: vAPP_ZCL_DeviceSpecific_Init
 *
 * DESCRIPTION:
 * ZLL Device Specific initialization
 *
 * PARAMETER: void
 *
 * RETURNS: void
 *
 ****************************************************************************/
void vAPP_ZCL_DeviceSpecific_Init(void)
{
    /* Initialise the strings in Basic */
    memcpy(sLight.sBasicServerCluster.au8ManufacturerName, "NXP", CLD_BAS_MANUF_NAME_SIZE);
    memcpy(sLight.sBasicServerCluster.au8ModelIdentifier, "ZHA-ColorTemeratureLight", CLD_BAS_MODEL_ID_SIZE);
    memcpy(sLight.sBasicServerCluster.au8DateCode, "20130926", CLD_BAS_DATE_SIZE);
    memcpy(sLight.sBasicServerCluster.au8SWBuildID, "4000-0001", CLD_BAS_SW_BUILD_SIZE);

    /* Set the initial value to 4000 Kelvin */
    sLight.sColourControlServerCluster.u16ColourTemperatureMired = (1E6/4000);

#if (defined DR1221) || (defined DR1221_DIMIC)
    {
    uint16 u16PhyMax;
    uint16 u16PhyMin;

    DriverBulb_vGetColourTempPhyMinMax(&u16PhyMin,&u16PhyMax);
    sLight.sColourControlServerCluster.u16ColourTemperatureMiredPhyMin = u16PhyMin;
    sLight.sColourControlServerCluster.u16ColourTemperatureMiredPhyMax = u16PhyMax;
    }
#endif
}

#ifdef CLD_BAS_CMD_RESET_TO_FACTORY_DEFAULTS
/****************************************************************************
 *
 * NAME: vApp_ZCL_ResetDeviceStructure
 *
 * DESCRIPTION:
 * Resets the device structure
 *
 * PARAMETER: void
 *
 * RETURNS: void
 *
 ****************************************************************************/
PUBLIC void vApp_ZCL_ResetDeviceStructure(void)
{
    memset(&sLight,0,sizeof(tsHA_ColourDimmableLightDevice));
}
#endif

/****************************************************************************
 *
 * NAME: vTunableWhiteLightSetLevels
 *
 * DESCRIPTION:
 * Device Specific build driver interface
 *
 * PARAMETER: the on/off state, the level, and colour temperature
 *
 ****************************************************************************/


PUBLIC void vTunableWhiteLightSetLevels(bool_t bOn, uint32 u32Level, int32 i32ColourTemperature)
{
    if (bOn) /* only move the colour temperature if lamp is on */
    {
        vLI_Start(u32Level, 0,0,0,(1E6/i32ColourTemperature));
    }
    else
    {
        vLI_Stop();
    }
    vBULB_SetOnOff(bOn);
}

/****************************************************************************
 *
 * NAME: vAppGetEPId
 *
 * DESCRIPTION:
 * Gets endpoint id
 *
 *  RETURNS:
 *  Returns endpoint id
 *
 ****************************************************************************/
PUBLIC uint8 u8AppGetEPId(void)
{
    return COLORTEMPTUNABLEWHITELIGHT_LIGHT_ENDPOINT;
}
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

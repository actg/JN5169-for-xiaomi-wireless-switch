/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          App_ColorDimmableLight.c
 *
 * DESCRIPTION:        ZHA Color Light Application (Implementation)
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
#include "App_ColorDimmableLight.h"
#include "AppHardwareApi.h"
#include <PeripheralRegs.h>
#include "dbg.h"
#include <string.h>

#include "app_light_interpolation.h"
#include "DriverBulb_Shim.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifdef DEBUG_APP
#define TRACE_APP TRUE
#else
#define TRACE_APP FALSE
#endif


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
PUBLIC teZCL_Status eApp_HA_RegisterEndpoint(tfpZCL_ZCLCallBackFunction fptr)
{

    return eHA_RegisterColourDimmableLightEndPoint(COLORDIMMABLELIGHT_LIGHT_ENDPOINT,
                                              fptr,
                                              &sLight);
}

/****************************************************************************
 *
 * NAME: vApp_eCLD_ColourControl_GetRGB
 *
 * DESCRIPTION:
 * To get RGB value
 *
 * PARAMETER
 * Type        Name                    Descirption
 * uint8 *     pu8Red                  Pointer to Red in RGB value
 * uint8 *     pu8Green                Pointer to Green in RGB value
 * uint8 *     pu8Blue                 Pointer to Blue in RGB value
 *
 * RETURNS:
 * teZCL_Status
 *
 ****************************************************************************/
PUBLIC void vApp_eCLD_ColourControl_GetRGB(uint8 *pu8Red,uint8 *pu8Green,uint8 *pu8Blue)
{
    eCLD_ColourControl_GetRGB(COLORDIMMABLELIGHT_LIGHT_ENDPOINT,
                              pu8Red,
                              pu8Green,
                              pu8Blue);
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
PUBLIC void vAPP_ZCL_DeviceSpecific_Init(void)
{
    /* Initialise the strings in Basic */
    sLight.sBasicServerCluster.sManufacturerName.u8Length = strlen(CONFIG_MANUFACTURER_NAME);
    memcpy(sLight.sBasicServerCluster.au8ManufacturerName, CONFIG_MANUFACTURER_NAME, sLight.sBasicServerCluster.sManufacturerName.u8Length);
    sLight.sBasicServerCluster.sModelIdentifier.u8Length = strlen(CONFIG_MODEL_ID);
    memcpy(sLight.sBasicServerCluster.au8ModelIdentifier, CONFIG_MODEL_ID, sLight.sBasicServerCluster.sModelIdentifier.u8Length);
    sLight.sBasicServerCluster.sDateCode.u8Length = strlen(CONFIG_DATE_CODE);
    memcpy(sLight.sBasicServerCluster.au8DateCode, CONFIG_DATE_CODE, sLight.sBasicServerCluster.sDateCode.u8Length);
    sLight.sBasicServerCluster.u8ApplicationVersion = CONFIG_APP_SW_VERSION;
    sLight.sBasicServerCluster.u8HardwareVersion = CONFIG_HW_VERSION;
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
 * NAME: vRGBLight_SetLevels
 *
 * DESCRIPTION:
 * Set the RGB and levels and triggers the linear interpolation process
 *
 ****************************************************************************/
PUBLIC void vRGBLight_SetLevels(bool_t bOn, uint8 u8Level, uint8 u8Red, uint8 u8Green, uint8 u8Blue)
{
    if (bOn == TRUE)
    {
        vLI_Start(u8Level, u8Red, u8Green, u8Blue,0);
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
    return COLORDIMMABLELIGHT_LIGHT_ENDPOINT;
}

/****************************************************************************/
/* OS stubs to ensure DK4/Evalbulbs are can be built from the real bulb     */
/* os config diagram which has support for 5 interrupt sources              */
/****************************************************************************/


#if (defined DR1175) || (defined DR1173)

OS_ISR(vISR_PwmTimer)
{
    (void) u8AHI_TimerFired(E_AHI_TIMER_0);
    (void) u8AHI_TimerFired(E_AHI_TIMER_1);
    (void) u8AHI_TimerFired(E_AHI_TIMER_2);
}

OS_ISR(vISR_SettleTimer)
{
    (void) u8AHI_TimerFired(E_AHI_TIMER_4);
}

OS_ISR(vISR_AdcDone)
{
    vREG_AnaWrite(REG_ANPER_IS,REG_ANPER_INT_CAPT_MASK);
}
#endif


/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

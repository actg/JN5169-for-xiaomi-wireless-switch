/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          App_DimmableLight.c
 *
 * DESCRIPTION:        ZHA Demo Dimmable Light -Implementation
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
#include "App_DimmableLight.h"
#include "AppHardwareApi.h"
#include "dbg.h"
#include "os.h"
#include <string.h>

#include "app_light_interpolation.h"
#include "DriverBulb_Shim.h"


/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
tsHA_DimmableLightDevice sLight;


/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

/****************************************************************************
 *
 * NAME: eApp_HA_RegisterEndpoint
 *
 * DESCRIPTION:
 * Register ZHA endpoints
 *
 * PARAMETER
 * Type                        Name                  Descirption
 * tfpZCL_ZCLCallBackFunction  fptr                  Pointer to ZCL Callback function
 *
 * RETURNS:
 * teZCL_Status
 *
 ****************************************************************************/
PUBLIC teZCL_Status eApp_HA_RegisterEndpoint(tfpZCL_ZCLCallBackFunction fptr)
{
    return eHA_RegisterDimmableLightEndPoint(DIMMABLELIGHT_LIGHT_ENDPOINT,
                                              fptr,
                                              &sLight);
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
PUBLIC void vAPP_ZCL_DeviceSpecific_Init()
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
    memset(&sLight,0,sizeof(tsHA_DimmableLightDevice));
}
#endif

/****************************************************************************
 *
 * NAME: vWhiteLightSetLevels
 *
 * DESCRIPTION:
 * White light level set
 *
 * PARAMETER: the on/off state, the level
 *
 * RETURNS: void
 *
 ****************************************************************************/
PUBLIC void vWhiteLightSetLevels(bool bOn, uint8 u8Level)
{
    if (bOn)
    {
        vLI_Start(u8Level, 0,0,0,0);
    }
    else
    {
        vLI_Stop();
    }
    vBULB_SetOnOff(bOn);
}


/****************************************************************************
 *
 * NAME: vISR_Timer2, vISR_SystemController
 *
 * DESCRIPTION:
 * OS Interrupt Service Routines stubs. These are normally provided
 * by The driver files when using real bulbs. DR1175/90  are the exceptions
 * as in ZLL the functions are provided outside the driver so this pattern has
 * to be replicated in ZHA so the driver can be profile agnostic.
 * They should never be called but to be safe they clear all interrupts down.
 *
 ****************************************************************************/
#if (defined DR1175) || (defined DR1190)

OS_ISR(vISR_Timer3)
{
    (void) u8AHI_TimerFired(E_AHI_TIMER_3);
}

OS_ISR(vISR_Timer4)
{
    (void) u8AHI_TimerFired(E_AHI_TIMER_4);
}

OS_ISR(vISR_SystemController)
{
    *(volatile uint32 *) 0x02000010UL = 0xffffffffUL;
}

#endif

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
    return DIMMABLELIGHT_LIGHT_ENDPOINT;
}
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

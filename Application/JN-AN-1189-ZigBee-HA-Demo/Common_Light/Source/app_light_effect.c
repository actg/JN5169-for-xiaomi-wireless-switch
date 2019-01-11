/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          app_light_effects.c
 *
 * DESCRIPTION:        Light effects implementation
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
#include "dbg.h"
#include "app_light_effect.h"
#include "app_zcl_light_task.h"
#include "haEzJoin.h"
#include "DriverBulb.h"
#include "zcl_options.h"
#include "app_common.h"
#include <string.h>

#ifdef DEBUG_PATH
#define TRACE_PATH  TRUE
#else
#define TRACE_PATH  FALSE
#endif

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
tsIdEffect sIdEffect;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
/****************************************************************************
 *
 * NAME: u8GetEffect
 *
 * DESCRIPTION:
 * Gets the current effect
 *
 * PARAMETER: void
 *
 * RETURNS: void
 *
 ****************************************************************************/
PUBLIC uint8 u8GetEffect (void)
{
    return sIdEffect.u8Effect;
}
/****************************************************************************
 *
 * NAME: App_vLightEffect
 *
 * DESCRIPTION:
 * Acts on the breath effect
 *
 * PARAMETER: void
 *
 * RETURNS: void
 *
 ****************************************************************************/
PUBLIC void App_vLightEffect(void)
{

    if( E_EZ_DEVICE_IN_NETWORK != eEZ_GetJoinState() )
    {
        if( E_CLD_IDENTIFY_EFFECT_STOP_EFFECT == u8GetEffect())
        {
                vStartEffect(E_CLD_IDENTIFY_EFFECT_BREATHE);
        }
    }
}

/****************************************************************************
 *
 * NAME: vIdEffectTick
 *
 * DESCRIPTION:
 * ZLL Device Specific identify tick
 *
 * PARAMETER: void
 *
 * RETURNS: void
 *
 ****************************************************************************/
PUBLIC void vIdEffectTick(uint8 u8Endpoint) {

    if (u8Endpoint != sLight.sEndPoint.u8EndPointNumber) {
        return;
    }
    if (sIdEffect.u8Effect < E_CLD_IDENTIFY_EFFECT_STOP_EFFECT)
    {
        if (sIdEffect.u8Tick > 0)
        {
            DBG_vPrintf(TRACE_PATH, "\nPath 5");

            sIdEffect.u8Tick--;
            /* Set the light parameters */
            #if (defined CLD_COLOUR_CONTROL) && !(defined ColorTempTunableWhiteLight)
              vRGBLight_SetLevels(TRUE,sIdEffect.u8Level,
                      sIdEffect.u8Red,
                      sIdEffect.u8Green,
                      sIdEffect.u8Blue);


            #elif (defined CLD_LEVEL_CONTROL) && !(defined ColorTempTunableWhiteLight)
               vWhiteLightSetLevels(TRUE,sIdEffect.u8Level);


            #elif (defined CLD_LEVEL_CONTROL) && (defined ColorTempTunableWhiteLight)
               vTunableWhiteLightSetLevels(TRUE, sIdEffect.u8Level, sLight.sColourControlServerCluster.u16ColourTemperatureMired);
            #else
                    /* must be on-off device */
            #endif
            /* Now adjust parameters ready for for next round */
            switch (sIdEffect.u8Effect) {
                #if !(defined CLD_COLOUR_CONTROL) || (defined ColorTempTunableWhiteLight)
                case E_CLD_IDENTIFY_EFFECT_OKAY:
                #endif
                case E_CLD_IDENTIFY_EFFECT_BLINK:
                    if(sIdEffect.u8Tick > 5)
                        sIdEffect.u8Level=0;
                    break;

                case E_CLD_IDENTIFY_EFFECT_BREATHE:
                    if (sIdEffect.bDirection) {
                        if (sIdEffect.u8Level >= 250) {
                            sIdEffect.u8Level -= 50;
                            sIdEffect.bDirection = 0;
                        } else {
                            sIdEffect.u8Level += 50;
                        }
                    } else {
                        if (sIdEffect.u8Level == 0) {
                            /* go back up, check for stop*/
                            sIdEffect.u8Count--;
                            if ((sIdEffect.u8Count) && ( !sIdEffect.bFinish)) {
                                sIdEffect.u8Level += 50;
                                sIdEffect.bDirection = 1;
                            } else {
                                /* lpsw2773 - stop the effect on the next tick */
                                sIdEffect.u8Tick = 0;
                            }
                        } else {
                            sIdEffect.u8Level -= 50;
                        }
                    }
                    break;
                default:
                    if ( sIdEffect.bFinish ) {
                        sIdEffect.u8Tick = 0;
                    }
                }
        } else {
            /*
             * Effect finished, restore the light
             */
            DBG_vPrintf(TRACE_PATH, "\nPath 6");
            sIdEffect.u8Effect = E_CLD_IDENTIFY_EFFECT_STOP_EFFECT;
            sIdEffect.bDirection = FALSE;
            APP_ZCL_vSetIdentifyTime(0);
            #if (defined CLD_COLOUR_CONTROL) && !(defined ColorTempTunableWhiteLight)
            uint8 u8Red, u8Green, u8Blue;
            vApp_eCLD_ColourControl_GetRGB(&u8Red, &u8Green, &u8Blue);
            vRGBLight_SetLevels(sLight.sOnOffServerCluster.bOnOff,
                                    sLight.sLevelControlServerCluster.u8CurrentLevel,
                                    u8Red,
                                    u8Green,
                                    u8Blue);

            #elif (defined CLD_LEVEL_CONTROL) && !(defined ColorTempTunableWhiteLight)
            vWhiteLightSetLevels(sLight.sOnOffServerCluster.bOnOff,
                                sLight.sLevelControlServerCluster.u8CurrentLevel );

            #elif (defined CLD_LEVEL_CONTROL) && (defined ColorTempTunableWhiteLight)
            vTunableWhiteLightSetLevels(sLight.sOnOffServerCluster.bOnOff,
                                        sLight.sLevelControlServerCluster.u8CurrentLevel,
                                        sLight.sColourControlServerCluster.u16ColourTemperatureMired);
            #endif

        }
    }
}

/****************************************************************************
 *
 * NAME: vStartEffect
 *
 * DESCRIPTION:
 * ZLL Device Specific identify effect set up
 *
 * PARAMETER: void
 *
 * RETURNS: void
 *
 ****************************************************************************/
PUBLIC void vStartEffect(uint8 u8Effect) {
    switch (u8Effect) {
        case E_CLD_IDENTIFY_EFFECT_BLINK:
            sIdEffect.u8Effect = E_CLD_IDENTIFY_EFFECT_BLINK;
            sIdEffect.u8Level = 250;
            sIdEffect.bFinish = FALSE;
            /*APP_ZCL_vSetIdentifyTime(2); -- Templete*/
            sIdEffect.u8Tick = 10;
            break;
        case 3:
            sIdEffect.u8Effect = 3;
            sIdEffect.u8Level = 250;
            sIdEffect.u8Red = 255;
            sIdEffect.u8Green = 0;
            sIdEffect.u8Blue = 0;
            sIdEffect.bFinish = FALSE;
            APP_ZCL_vSetIdentifyTime(180);
            sIdEffect.u8Tick = 10;
            break;
        case E_CLD_IDENTIFY_EFFECT_BREATHE:
            sIdEffect.u8Effect = E_CLD_IDENTIFY_EFFECT_BREATHE;
            sIdEffect.bDirection = 1;
            sIdEffect.bFinish = FALSE;
            sIdEffect.u8Level = 0;
            sIdEffect.u8Count = 15;
            #if (defined CLD_COLOUR_CONTROL) && !(defined ColorTempTunableWhiteLight)
                eCLD_ColourControl_GetRGB( sLight.sEndPoint.u8EndPointNumber, &sIdEffect.u8Red, &sIdEffect.u8Green, &sIdEffect.u8Blue);
            #endif
            /*APP_ZCL_vSetIdentifyTime(255);-- Templete*/
            sIdEffect.u8Tick = 200;
            break;
        case E_CLD_IDENTIFY_EFFECT_OKAY:
            sIdEffect.u8Effect = E_CLD_IDENTIFY_EFFECT_OKAY;
            sIdEffect.bFinish = FALSE;
            sIdEffect.u8Level = 250;
            sIdEffect.u8Red = 0;
            sIdEffect.u8Green = 255;
            sIdEffect.u8Blue = 0;
            APP_ZCL_vSetIdentifyTime(2);
            sIdEffect.u8Tick = 10;
            break;
        case E_CLD_IDENTIFY_EFFECT_CHANNEL_CHANGE:
            sIdEffect.u8Effect = E_CLD_IDENTIFY_EFFECT_CHANNEL_CHANGE;
            sIdEffect.u8Level = 250;
            sIdEffect.u8Red = 255;
            sIdEffect.u8Green = 127;
            sIdEffect.u8Blue = 4;
            sIdEffect.bFinish = FALSE;
            /*APP_ZCL_vSetIdentifyTime(9);*/
            sIdEffect.u8Tick = 80;
            break;

        case E_CLD_IDENTIFY_EFFECT_FINISH_EFFECT:
            if (sIdEffect.u8Effect < E_CLD_IDENTIFY_EFFECT_STOP_EFFECT)
            {
                sIdEffect.bFinish = TRUE;
            }
            break;
        case E_CLD_IDENTIFY_EFFECT_STOP_EFFECT:
            sIdEffect.u8Effect = E_CLD_IDENTIFY_EFFECT_STOP_EFFECT;
            APP_ZCL_vSetIdentifyTime(1);
            break;
    }
}
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/


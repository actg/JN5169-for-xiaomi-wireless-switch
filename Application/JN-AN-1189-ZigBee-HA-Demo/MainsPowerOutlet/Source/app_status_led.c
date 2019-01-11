/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          app_status_led.c
 *
 * DESCRIPTION:
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
#include <string.h>
#include "dbg.h"
#include "app_status_led.h"
#include "app_zcl_outlet_task.h"
#include "haEzJoin.h"
#include "DriverOutlet.h"
#include "zcl_options.h"
#include "app_common.h"

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
PUBLIC uint8 u8GetEffect(void)
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
    if (E_EZ_DEVICE_IN_NETWORK != eEZ_GetJoinState())
    {
        if (E_CLD_IDENTIFY_EFFECT_STOP_EFFECT == u8GetEffect())
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
PUBLIC void vIdEffectTick(uint8 u8Endpoint)
{
    if (sOutletDevice.sEndPoint.u8EndPointNumber == u8Endpoint)
    {
        if (sIdEffect.u8Effect < E_CLD_IDENTIFY_EFFECT_STOP_EFFECT)
        {
            if (sIdEffect.u8Tick > 0)
            {
                sIdEffect.u8Tick--;

                switch (sIdEffect.u8Effect)
                {
                    case E_CLD_IDENTIFY_EFFECT_BLINK:
                    {
                        if(sIdEffect.u8Tick > 5)
                        {
                            DriverOutlet_vStatusLedOff();
                        }
                    }
                    break;

                    case E_CLD_IDENTIFY_EFFECT_BREATHE:
                    {
                        if (TRUE == DriverOutlet_bIsStatusLedOn())
                        {
                            DriverOutlet_vStatusLedOff();
                        }
                        else
                        {
                            DriverOutlet_vStatusLedOn();
                        }
                    }
                    break;

                    default:
                    {
                        if (sIdEffect.bFinish)
                        {
                            sIdEffect.u8Tick = 0;
                        }
                    }
                    break;
                }
            }
            else
            {
                /*
                 * Effect finished, restore the output state
                 */
                sIdEffect.u8Effect = E_CLD_IDENTIFY_EFFECT_STOP_EFFECT;
                APP_ZCL_vSetIdentifyTime(0);
                DriverOutlet_vSetStatusLedOnOff(sOutletDevice.sOnOffServerCluster.bOnOff);
            }
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
PUBLIC void vStartEffect(uint8 u8Effect)
{
    switch (u8Effect)
    {
        case E_CLD_IDENTIFY_EFFECT_BLINK:
        {
            sIdEffect.u8Effect = E_CLD_IDENTIFY_EFFECT_BLINK;
            sIdEffect.bFinish = FALSE;
            sIdEffect.u8Tick = 10;
        }
        break;

        case E_CLD_IDENTIFY_EFFECT_BREATHE:
        {
            sIdEffect.u8Effect = E_CLD_IDENTIFY_EFFECT_BREATHE;
            sIdEffect.bFinish = FALSE;
            sIdEffect.u8Count = 15;
            sIdEffect.u8Tick = 200;
        }
        break;

        case E_CLD_IDENTIFY_EFFECT_FINISH_EFFECT:
        {
            if (sIdEffect.u8Effect < E_CLD_IDENTIFY_EFFECT_STOP_EFFECT)
            {
                sIdEffect.bFinish = TRUE;
            }
        }
        break;

        case E_CLD_IDENTIFY_EFFECT_STOP_EFFECT:
        {
            sIdEffect.u8Effect = E_CLD_IDENTIFY_EFFECT_STOP_EFFECT;
            APP_ZCL_vSetIdentifyTime(0);
            DriverOutlet_vSetStatusLedOnOff(sOutletDevice.sOnOffServerCluster.bOnOff);
        }
        break;

        default:
            break;
    }
}

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

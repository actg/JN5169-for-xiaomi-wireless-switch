/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          app_common.h
 *
 * DESCRIPTION:        Application Device Type Includes
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
 * Copyright NXP B.V. 2013. All rights reserved
 *
 ***************************************************************************/

#ifndef APP_COMMON_H_
#define APP_COMMON_H_

#include "app_timer_driver.h"

/* Device specific includes
 * As a new light or controller is added it needs an entry here
 *
 */
#ifdef DimmerSwitch
    #include "App_DimmerSwitch.h"
#endif

#ifdef ColorDimmerSwitch
    #include "App_ColorDimmerSwitch.h"
#endif

#ifdef DimmableLight
    #include "App_DimmableLight.h"
#endif

#ifdef DimmableLightOpenHome
    #include "App_DimmableLightOpenHome.h"
#endif

#ifdef OTAColorDimmableLightWithOccupancy
    #include "App_OTAColorDimmableLightWithOccupancy.h"
#endif

#ifdef ColorTempTunableWhiteLight
    #include "App_ColorTempTunableWhiteLight.h"
#endif

#ifdef ColorDimmableLight
    #include "App_ColorDimmableLight.h"
#endif

#ifdef OccupancySensor
    #include "App_OccupancySensor.h"
#endif

#ifdef LightSensor
    #include "App_LightSensor.h"
#endif

#ifdef RemoteControl
    #include "App_RemoteControl.h"
#endif

#ifdef MainsPowerOutlet
    #include "App_MainsPowerOutlet.h"
#endif
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#ifdef POLL_BUILD
#define POLL_TIME_ICONTROL      APP_TIME_MS(60000)
#endif

#define POLL_TIME               APP_TIME_MS(500)			//500ms
#define POLL_TIME_FAST          APP_TIME_MS(100)
#define TEN_HZ_TICK_TIME        APP_TIME_MS(100)

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
typedef enum
{
    E_STARTUP,
    E_LEAVE_WAIT,
    E_LEAVE_RESET,
    E_NFN_START,
    E_DISCOVERY,
    E_NETWORK_FORMATION,
    E_JOINING_NETWORK,
    E_REJOINING,
    E_NETWORK_INIT,
    E_RESCAN,
    E_RUNNING
} teNODE_STATES;

typedef struct
{
    teNODE_STATES   eNodeState;
    teNODE_STATES   eNodePrevState;
}tsDeviceDesc;
/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#endif /*APP_COMMON_H_*/

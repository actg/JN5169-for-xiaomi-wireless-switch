/*****************************************************************************
 *
 * MODULE:             ThermostatUIConfigUIConfig Cluster
 *
 * COMPONENT:          ThermostatUIConfigUIConfig.h
 *
 * AUTHOR:             Shweta Chauhan
 *
 * DESCRIPTION:        Header for ThermostatUIConfigUIConfig Cluster
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/UnifiedZCL_ZLL102_HA122_Maintenance/Clusters/HVAC/Include/ThermostatUIConfig.h $
 *
 * $Revision: 65965 $
 *
 * $LastChangedBy: nxp58432 $
 *
 * $LastChangedDate: 2014-11-25 05:39:23 +0000 (Tue, 25 Nov 2014) $
 *
 * $Id: ThermostatUIConfig.h 65965 2014-11-25 05:39:23Z nxp58432 $
 *
 *****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products  [NXP Microcontrollers such as JN5168, JN5164,
 * JN5161, JN5148, JN5142, JN5139]. 
 * You, and any third parties must reproduce the copyright and warranty notice 
 * and any other legend of ownership on each  copy or partial copy of the software.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  
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

#ifndef THERMOSTAT_UI_CONFIG_H
#define THERMOSTAT_UI_CONFIG_H

#include <jendefs.h>
#include "zcl.h"
#include "zcl_options.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/*       ThermostatUIConfigUIConfig Cluster - Optional Attributes              */
/*                                                                          */
/* Add the following #define's to your zcl_options.h file to add optional   */
/* attributes to the temperature measurement cluster.                       */
/****************************************************************************/

/* End of optional attributes */


/* Cluster ID's */
#define HVAC_CLUSTER_ID_THERMOSTAT_UI_CONFIG                                             0x0204


/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

typedef enum 
{
    /* ThermostatUIConfigUIConfig attribute set attribute ID's (6.6.2.2) */
    E_CLD_THERMOSTAT_UI_CONFIG_ATTR_ID_TEMPERATURE_DISPLAY_MODE               = 0x0000,         /* Mandatory */
    E_CLD_THERMOSTAT_UI_CONFIG_ATTR_ID_KEYPAD_LOCKOUT                                           /* Mandatory */
} teCLD_ThermostatUIConfig_AttributeID;

/* Temperature Display */
typedef enum 
{
    E_CLD_THERMOSTAT_UI_CONFIG_TEMPERATURE_DISPLAY_MODE_CELSIUS                 = 0x00,
    E_CLD_THERMOSTAT_UI_CONFIG_TEMPERATURE_DISPLAY_MODE_FAHRENHEIT
} teCLD_ThermostatUIConfig_TemperatureDisplay;

/* Keypad Lockout */
typedef enum 
{
    E_CLD_THERMOSTAT_UI_CONFIG_KEYPAD_LOCKOUT_NO_LOCKOUT                               = 0x00,
    E_CLD_THERMOSTAT_UI_CONFIG_KEYPAD_LOCKOUT_LEVEL_1_LOCKOUT,
    E_CLD_THERMOSTAT_UI_CONFIG_KEYPAD_LOCKOUT_LEVEL_2_LOCKOUT,
    E_CLD_THERMOSTAT_UI_CONFIG_KEYPAD_LOCKOUT_LEVEL_3_LOCKOUT,
    E_CLD_THERMOSTAT_UI_CONFIG_KEYPAD_LOCKOUT_LEVEL_4_LOCKOUT,
    E_CLD_THERMOSTAT_UI_CONFIG_KEYPAD_LOCKOUT_LEVEL_5_LOCKOUT
} teCLD_ThermostatUIConfig_KeyPadLockout;

/* ThermostatUIConfig Cluster */
typedef struct
{
    zenum8                 eTemperatureDisplayMode;
    
    zenum8                 eKeypadLockout;
} tsCLD_ThermostatUIConfig;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC teZCL_Status eCLD_ThermostatUIConfigCreateThermostatUIConfig(
                tsZCL_ClusterInstance                   *psClusterInstance,
                bool_t                                  bIsServer,
                tsZCL_ClusterDefinition                 *psClusterDefinition,
                void                                    *pvEndPointSharedStructPtr,
                uint8                                   *pu8AttributeControlBits);
#ifdef THERMOSTAT_UI_CONFIG_SERVER
PUBLIC teZCL_Status eCLD_ThermostatUIConfigConvertTemp(
                uint8                                   u8SourceEndPointId,
                bool                                    bConvertFToC,
                int16                                   *pi16Temperature); 
#endif                
/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/

extern const tsZCL_AttributeDefinition asCLD_ThermostatUIConfigClusterAttributeDefinitions[];
extern tsZCL_ClusterDefinition sCLD_ThermostatUIConfig;

#ifdef THERMOSTAT_UI_CONFIG_SERVER
    extern uint8 au8ThermostatUIConfigServerAttributeControlBits[];
#endif

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

#endif /* THERMOSTAT_UI_CONFIG_H */

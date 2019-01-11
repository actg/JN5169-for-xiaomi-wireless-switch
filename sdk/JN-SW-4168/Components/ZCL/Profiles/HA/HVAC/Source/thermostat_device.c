/*****************************************************************************
 *
 * MODULE:             THERMOSTAT DEVICE
 *
 * COMPONENT:          thermostat_device.c
 *
 * AUTHOR:             nlv10675
 *
 * DESCRIPTION:        ZigBee Thermostat device profile functions
 *
 * $HeadURL: $
 *
 * $Revision: $
 *
 * $LastChangedBy: $
 *
 * $LastChangedDate: $
 *
 * $Id: $
 *
 *****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products [NXP Microcontrollers such as JN5148, JN5142, JN5139]. 
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
 * Copyright NXP B.V. 2013. All rights reserved
 *
 ****************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#include <jendefs.h>
#include <string.h>
#include "zps_apl.h"
#include "zcl_heap.h"
#include "thermostat_device.h"

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
 * NAME: eHA_RegisterThermostatEndPoint
 *
 * DESCRIPTION:
 * Registers a Thermostat device with the ZCL layer
 *
 * PARAMETERS:  Name                            Usage
 *              u8EndPointIdentifier            Endpoint being registered
 *              cbCallBack                      Pointer to endpoint callback
 *              psDeviceInfo                    Pointer to struct containing
 *                                              data for endpoint
 *
 * RETURNS:
 * teZCL_Status
 *
 ****************************************************************************/
PUBLIC teZCL_Status eHA_RegisterThermostatEndPoint(uint8 u8EndPointIdentifier,
                                                   tfpZCL_ZCLCallBackFunction cbCallBack,
                                                   tsHA_ThermostatDevice *psDeviceInfo)
{

    /* Fill in end point details */
    psDeviceInfo->sEndPoint.u8EndPointNumber = u8EndPointIdentifier;
    psDeviceInfo->sEndPoint.u16ManufacturerCode = ZCL_MANUFACTURER_CODE;
    psDeviceInfo->sEndPoint.u16ProfileEnum = HA_PROFILE_ID;
    psDeviceInfo->sEndPoint.bIsManufacturerSpecificProfile = FALSE;
    psDeviceInfo->sEndPoint.u16NumberOfClusters = sizeof(tsHA_ThermostatDeviceClusterInstances) / sizeof(tsZCL_ClusterInstance);
    psDeviceInfo->sEndPoint.psClusterInstance = (tsZCL_ClusterInstance*)&psDeviceInfo->sClusterInstance;
    psDeviceInfo->sEndPoint.bDisableDefaultResponse = TRUE;
    psDeviceInfo->sEndPoint.pCallBackFunctions = cbCallBack;

    /* All HA devices have 2 mandatory clusters - Basic(server) and Identify(server) */
#if (defined CLD_BASIC) && (defined BASIC_SERVER)
    /* Create an instance of a Basic cluster as a server */
    eCLD_BasicCreateBasic(&psDeviceInfo->sClusterInstance.sBasicServer,
                          TRUE,
                          &sCLD_Basic,
                          &psDeviceInfo->sBasicServerCluster,
                          &au8BasicClusterAttributeControlBits[0]);
#endif

#if (defined CLD_IDENTIFY) && (defined IDENTIFY_SERVER)
    /* Create an instance of an Identify cluster as a server */
    eCLD_IdentifyCreateIdentify(&psDeviceInfo->sClusterInstance.sIdentifyServer,
                          TRUE,
                          &sCLD_Identify,
                          &psDeviceInfo->sIdentifyServerCluster,
                          &au8IdentifyServerAttributeControlBits[0],
                          &psDeviceInfo->sIdentifyServerCustomDataStructure);
#endif

    /* Optional Clusters Common to All HA Server Devices */
#if (defined CLD_POWER_CONFIGURATION) && (defined POWER_CONFIGURATION_SERVER)
    /* Create an instance of a Power Configuration cluster as a server */
    eCLD_PowerConfigurationCreatePowerConfiguration(&psDeviceInfo->sClusterInstance.sPowerConfigurationServer,
                          TRUE,
                          &sCLD_PowerConfiguration,
                          &psDeviceInfo->sPowerConfigServerCluster,
                          &au8PowerConfigurationServerAttributeControlBits[0]);
#endif

#if (defined CLD_DEVICE_TEMPERATURE_CONFIGURATION) && (defined DEVICE_TEMPERATURE_CONFIGURATION_SERVER)
    /* Create an instance of a Device Temperature Configuration cluster as a server */
    eCLD_DeviceTemperatureConfigurationCreateDeviceTemperatureConfiguration(&psDeviceInfo->sClusterInstance.sDeviceTemperatureConfigurationServer,
                          TRUE,
                          &sCLD_DeviceTemperatureConfiguration,
                          &psDeviceInfo->sDeviceTemperatureConfigurationServerCluster,
                          &au8DeviceTempConfigServerClusterAttributeControlBits[0]);
#endif

#if (defined CLD_ALARMS) && (defined ALARMS_SERVER)
    /* Create an instance of an Alarms cluster as a server */
    eCLD_AlarmsCreateAlarms(&psDeviceInfo->sClusterInstance.sAlarmsServer,
                          TRUE,
                          &sCLD_Alarms,
                          &psDeviceInfo->sAlarmsServerCluster,
                          &au8AlarmsServerAttributeControlBits[0],
                          &psDeviceInfo->sAlarmsServerCustomDataStructure);
#endif

#if (defined CLD_POLL_CONTROL) && (defined POLL_CONTROL_SERVER)
    /* Create an instance of a Poll Control cluster as a server */
    eCLD_PollControlCreatePollControl(
                          &psDeviceInfo->sClusterInstance.sPollControlServer,
                          TRUE,
                          &sCLD_PollControl,
                          &psDeviceInfo->sPollControlServerCluster,
                          &au8PollControlServerAttributeControlBits[0],
                          &psDeviceInfo->sPollControlServerCustomDataStructure);
#endif
    
#if (defined CLD_SCENES) && (defined SCENES_SERVER)
    /* Create an instance of a Scenes cluster as a server */
    eCLD_ScenesCreateScenes(&psDeviceInfo->sClusterInstance.sScenesServer,
                          TRUE,
                          &sCLD_Scenes,
                          &psDeviceInfo->sScenesServerCluster,
                          &au8ScenesServerAttributeControlBits[0],
                          &psDeviceInfo->sScenesServerCustomDataStructure,
                          &psDeviceInfo->sEndPoint);
#endif

#if (defined CLD_GROUPS) && (defined GROUPS_SERVER)
    /* Create an instance of a Groups cluster as a server */
    eCLD_GroupsCreateGroups(&psDeviceInfo->sClusterInstance.sGroupsServer,
                          TRUE,
                          &sCLD_Groups,
                          &psDeviceInfo->sGroupsServerCluster,
                          &au8GroupsServerAttributeControlBits[0],
                          &psDeviceInfo->sGroupsServerCustomDataStructure,
                          &psDeviceInfo->sEndPoint);
#endif
   
    /* Optional Clusters Common to All HA Client Devices */
#if (defined CLD_SCENES) && (defined SCENES_CLIENT)
    /* Create an instance of a Scenes cluster as a client */
    eCLD_ScenesCreateScenes(&psDeviceInfo->sClusterInstance.sScenesClient,
                          FALSE,
                          &sCLD_Scenes,
                          NULL,
                          NULL,
                          &psDeviceInfo->sScenesClientCustomDataStructure,
                          &psDeviceInfo->sEndPoint);
#endif

#if (defined CLD_GROUPS) && (defined GROUPS_CLIENT)
    /* Create an instance of a Groups cluster as a client */
    eCLD_GroupsCreateGroups(&psDeviceInfo->sClusterInstance.sGroupsClient,
                          FALSE,
                          &sCLD_Groups,
                          NULL,
                          NULL,
                          &psDeviceInfo->sGroupsClientCustomDataStructure,
                          &psDeviceInfo->sEndPoint);
#endif    
    
    /* Mandatory Clusters supported by Thermostat Server Device */
#if (defined CLD_THERMOSTAT) && (defined THERMOSTAT_SERVER)
    /* Create an instance of a Thermostat cluster as a server */
    eCLD_ThermostatCreateThermostat(&psDeviceInfo->sClusterInstance.sThermostatServer,
                          TRUE,
                          &sCLD_Thermostat,
                          &psDeviceInfo->sThermostatServerCluster,
                          NULL,
                          &psDeviceInfo->sThermostatServerCustomDataStructure);
#endif

    /* Optional Clusters supported by Thermostat Server Device */
#if (defined CLD_THERMOSTAT_UI_CONFIG) && (defined THERMOSTAT_UI_CONFIG_SERVER)
    /* Create an instance of a Thermostat UI Config cluster as a server */
    eCLD_ThermostatUIConfigCreateThermostatUIConfig(&psDeviceInfo->sClusterInstance.sThermostatUIConfigurationServer,
                          TRUE,
                          &sCLD_ThermostatUIConfig,
                          &psDeviceInfo->sThermostatUIConfigServerCluster,
                          &au8ThermostatUIConfigServerAttributeControlBits[0]);
#endif

#if (defined CLD_TEMPERATURE_MEASUREMENT) && (defined TEMPERATURE_MEASUREMENT_SERVER)
    /* Create an instance of a Temperature Measurement cluster as a server */
    eCLD_TemperatureMeasurementCreateTemperatureMeasurement(
                          &psDeviceInfo->sClusterInstance.sTemperatureMeasurementServer,
                          TRUE,
                          &sCLD_TemperatureMeasurement,
                          &psDeviceInfo->sTemperatureMeasurementServerCluster,
                          &au8TemperatureMeasurementServerAttributeControlBits[0]);
#endif

#if (defined CLD_OCCUPANCY_SENSING) && (defined OCCUPANCY_SENSING_SERVER)
    /* Create an instance of an Occupancy Sensing cluster as a server */
    eCLD_OccupancySensingCreateOccupancySensing(
                          &psDeviceInfo->sClusterInstance.sOccupancySensingServer,
                          TRUE,
                          &sCLD_OccupancySensing,
                          &psDeviceInfo->sOccupancySensingServerCluster,
                          &au8OccupancySensingServerAttributeControlBits[0]);
#endif

#if (defined CLD_RELATIVE_HUMIDITY_MEASUREMENT) && (defined RELATIVE_HUMIDITY_MEASUREMENT_SERVER)
    /* Create an instance of a Relative Humidity Measurement cluster as a server */
    eCLD_RelativeHumidityMeasurementCreateRelativeHumidityMeasurement(
                          &psDeviceInfo->sClusterInstance.sRelativeHumidityMeasurementServer,
                          TRUE,
                          &sCLD_RelativeHumidityMeasurement,
                          &psDeviceInfo->sRelativeHumidityMeasurementServerCluster,
                          &au8RelativeHumidityMeasurementServerAttributeControlBits[0]);
#endif

    /* Optional Clusters supported by Thermostat Client Device */
#if (defined CLD_TEMPERATURE_MEASUREMENT) && (defined TEMPERATURE_MEASUREMENT_CLIENT)
    /* Create an instance of a Temperature Measurement cluster as a client */
    eCLD_TemperatureMeasurementCreateTemperatureMeasurement(
                          &psDeviceInfo->sClusterInstance.sTemperatureMeasurementClient,
                          FALSE,
                          &sCLD_TemperatureMeasurement,
                          NULL,
                          NULL);
#endif

#if (defined CLD_OCCUPANCY_SENSING) && (defined OCCUPANCY_SENSING_CLIENT)
    /* Create an instance of an Occupancy Sensing cluster as a client */
    eCLD_OccupancySensingCreateOccupancySensing(
                          &psDeviceInfo->sClusterInstance.sOccupancySensingClient,
                          FALSE,
                          &sCLD_OccupancySensing,
                          NULL,
                          NULL);
#endif

#if (defined CLD_RELATIVE_HUMIDITY_MEASUREMENT) && (defined RELATIVE_HUMIDITY_MEASUREMENT_CLIENT)
    /* Create an instance of a Relative Humidity Measurement cluster as a client */
    eCLD_RelativeHumidityMeasurementCreateRelativeHumidityMeasurement(
                          &psDeviceInfo->sClusterInstance.sRelativeHumidityMeasurementClient,
                          FALSE,
                          &sCLD_RelativeHumidityMeasurement,
                          NULL,
                          NULL);
#endif

#ifdef CLD_OTA

    #ifdef OTA_CLIENT
   if (eOTA_Create(
       &psDeviceInfo->sClusterInstance.sOTAClient,
       FALSE,  /* client */
       &sCLD_OTA,
       &psDeviceInfo->sCLD_OTA,  /* cluster definition */
       u8EndPointIdentifier,
       NULL,
       &psDeviceInfo->sCLD_OTA_CustomDataStruct
       )!= E_ZCL_SUCCESS)

    {
        // Need to convert from cluster specific to ZCL return type so we lose the extra information of the return code
        return E_ZCL_FAIL;
    }
    #endif
    
    #ifdef OTA_SERVER
   if (eOTA_Create(
       &psDeviceInfo->sClusterInstance.sOTAServer,
       TRUE,  /* Server */
       &sCLD_OTA,
       NULL,  /* cluster definition */
       u8EndPointIdentifier,
       NULL,
       &psDeviceInfo->sCLD_OTA_ServerCustomDataStruct
       )!= E_ZCL_SUCCESS)

    {
        // Need to convert from cluster specific to ZCL return type so we lose the extra information of the return code
        return E_ZCL_FAIL;
    }
    #endif 
    
#endif

#if (defined CLD_TIME && defined TIME_CLIENT)
    if (eCLD_TimeCreateTime(
                    &psDeviceInfo->sClusterInstance.sTimeClient,
                    FALSE,
                    &sCLD_Time,
                    NULL,
                    NULL) != E_ZCL_SUCCESS)
    {
        return E_ZCL_FAIL;
    }
#endif    

    /* Optional client clusters */
#if (defined CLD_THERMOSTAT) && (defined THERMOSTAT_CLIENT)
        /* Create an instance of a Thermostat cluster as a client */
        eCLD_ThermostatCreateThermostat(&psDeviceInfo->sClusterInstance.sThermostatClient,
                              FALSE,
                              &sCLD_Thermostat,
                              NULL,
                              NULL,
                              &psDeviceInfo->sThermostatClientCustomDataStructure);
#endif

#if (defined CLD_IDENTIFY) && (defined IDENTIFY_CLIENT)
    /* Create an instance of an Identify cluster as a client */
    eCLD_IdentifyCreateIdentify(&psDeviceInfo->sClusterInstance.sIdentifyClient,
                          FALSE,
                          &sCLD_Identify,
                          NULL,
                          NULL,
                          &psDeviceInfo->sIdentifyClientCustomDataStructure);
#endif


#if (defined CLD_POLL_CONTROL) && (defined POLL_CONTROL_CLIENT)
    /* Create an instance of a Poll Control cluster as a client */
    eCLD_PollControlCreatePollControl(
                          &psDeviceInfo->sClusterInstance.sPollControlClient,
                          FALSE,
                          &sCLD_PollControl,
                          NULL,
                          NULL,
                          &psDeviceInfo->sPollControlClientCustomDataStructure);
#endif

#if (defined CLD_ELECTRICAL_MEASUREMENT && defined ELECTRICAL_MEASUREMENT_SERVER)
    if (eCLD_ElectricalMeasurementCreateElectricalMeasurement(
    		&psDeviceInfo->sClusterInstance.sElectricalMeasurementServer,
		    TRUE,
			&sCLD_ElectricalMeasurement,
			&psDeviceInfo->sCLD_ElectricalMeasurement,
			au8ElectricalMeasurementServerAttributeControlBits)!= E_ZCL_SUCCESS)
    {
        return E_ZCL_FAIL;
    }

#endif

#if (defined CLD_FAN_CONTROL && defined FAN_CONTROL_SERVER)
    if (eCLD_FanControlCreateFanControl(
            &psDeviceInfo->sClusterInstance.sFanControlServer,
            TRUE,
            &sCLD_FanControl,
            &psDeviceInfo->sCLD_FanControl,
            au8FanControlServerAttributeControlBits)!= E_ZCL_SUCCESS)
    {
        return E_ZCL_FAIL;
    }

#endif

#if (defined DIAGNOSTICS_SERVER)
    if (eCLD_DiagnosticsCreateDiagnostics(
            &psDeviceInfo->sClusterInstance.sDiagnosticServer,
            TRUE,
            &sCLD_Diagnostics,
            &psDeviceInfo->sCLD_Diagnostic,
            au8DiagnosticsServerClusterAttributeControlBits)!= E_ZCL_SUCCESS)
    {
        return E_ZCL_FAIL;
    }

#endif

    return eZCL_Register(&psDeviceInfo->sEndPoint);
}

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/


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
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/UnifiedZCL_ZLL102_HA122_Maintenance/Profiles/HA/HVAC/Source/temperature_sensor.c $
 *
 * $Revision: 66165 $
 *
 * $LastChangedBy: nxp58432 $
 *
 * $LastChangedDate: 2014-12-01 10:10:49 +0000 (Mon, 01 Dec 2014) $
 *
 * $Id: temperature_sensor.c 66165 2014-12-01 10:10:49Z nxp58432 $
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
#include "temperature_sensor.h"

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
 * NAME: eHA_RegisterTemperatureSensorEndPoint
 *
 * DESCRIPTION:
 * Registers a TemperatureSensor device with the ZCL layer
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
PUBLIC teZCL_Status eHA_RegisterTemperatureSensorEndPoint(uint8 u8EndPointIdentifier,
                                                   tfpZCL_ZCLCallBackFunction cbCallBack,
                                                   tsHA_TemperatureSensorDevice *psDeviceInfo)
{

    /* Fill in end point details */
    psDeviceInfo->sEndPoint.u8EndPointNumber = u8EndPointIdentifier;
    psDeviceInfo->sEndPoint.u16ManufacturerCode = ZCL_MANUFACTURER_CODE;
    psDeviceInfo->sEndPoint.u16ProfileEnum = HA_PROFILE_ID;
    psDeviceInfo->sEndPoint.bIsManufacturerSpecificProfile = FALSE;
    psDeviceInfo->sEndPoint.u16NumberOfClusters = sizeof(tsHA_TemperatureSensorDeviceClusterInstances) / sizeof(tsZCL_ClusterInstance);
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
    
    /* Mandatory Server Clusters supported by Temperature Sensor Device */
#if (defined CLD_TEMPERATURE_MEASUREMENT) && (defined TEMPERATURE_MEASUREMENT_SERVER)
    /* Create an instance of a Temperature Measurement cluster as a server */
    eCLD_TemperatureMeasurementCreateTemperatureMeasurement(
                          &psDeviceInfo->sClusterInstance.sTemperatureMeasurementServer,
                          TRUE,
                          &sCLD_TemperatureMeasurement,
                          &psDeviceInfo->sTemperatureMeasurementServerCluster,
                          &au8TemperatureMeasurementServerAttributeControlBits[0]);
#endif

    /* Mandatory Client Clusters supported by Temperature Sensor Device */
#if (defined CLD_IDENTIFY) && (defined IDENTIFY_CLIENT)
    /* Create an instance of an Identify cluster as a client */
    eCLD_IdentifyCreateIdentify(&psDeviceInfo->sClusterInstance.sIdentifyClient,
                          FALSE,
                          &sCLD_Identify,
                          NULL,
                          NULL,
                          &psDeviceInfo->sIdentifyClientCustomDataStructure);
#endif

    /* Optional client clusters supported by Temperature Sensor Device */
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

    return eZCL_Register(&psDeviceInfo->sEndPoint);
}

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/


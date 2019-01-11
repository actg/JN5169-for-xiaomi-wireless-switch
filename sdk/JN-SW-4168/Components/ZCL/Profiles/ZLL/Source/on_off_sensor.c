/*****************************************************************************
 *
 * MODULE:             Smart Lighting Profile
 *
 * COMPONENT:
 *
 * AUTHOR:
 *
 * DESCRIPTION:        ZigBee Smart Lighting profile functions
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/UnifiedZCL_ZLL102_HA122_Maintenance/Profiles/ZLL/Source/on_off_sensor.c $
 *
 * $Revision: 66247 $
 *
 * $LastChangedBy: nxp46755 $
 *
 * $LastChangedDate: 2014-12-03 07:49:12 +0000 (Wed, 03 Dec 2014) $
 *
 * $Id: on_off_sensor.c 66247 2014-12-03 07:49:12Z nxp46755 $
 *
 *****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products [NXP Microcontrollers such as JN5168, JN5164,
 * JN5161, JN5148, JN5142, JN5139]. 
 * You, and any third parties must reproduce the copyright and warranty notice 
 * and any other legend of ownership on each  copy or partial copy of the software.
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
 * Copyright NXP B.V. 2012. All rights reserved
 *
 ****************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#include <jendefs.h>
#include "zps_apl.h"
#include "zcl_heap.h"
#include "on_off_sensor.h"

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
 * NAME: eZLL_RegisterOnOffSensorEndPoint
 *
 * DESCRIPTION:
 * Registers a on off sensor device with the ZCL layer
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

PUBLIC teZCL_Status eZLL_RegisterOnOffSensorEndPoint(uint8 u8EndPointIdentifier,
                                              tfpZCL_ZCLCallBackFunction cbCallBack,
                                              tsZLL_OnOffSensorDevice *psDeviceInfo)
{
    /* Fill in end point details */
    psDeviceInfo->sEndPoint.u8EndPointNumber = u8EndPointIdentifier;
    psDeviceInfo->sEndPoint.u16ManufacturerCode = ZLL_MANUFACTURER_CODE;
    psDeviceInfo->sEndPoint.u16ProfileEnum = HA_PROFILE_ID;
    psDeviceInfo->sEndPoint.bIsManufacturerSpecificProfile = FALSE;
    psDeviceInfo->sEndPoint.u16NumberOfClusters = sizeof(tsZLL_OnOffSensorDeviceClusterInstances) / sizeof(tsZCL_ClusterInstance);
    psDeviceInfo->sEndPoint.psClusterInstance = (tsZCL_ClusterInstance*)&psDeviceInfo->sClusterInstance;
    psDeviceInfo->sEndPoint.bDisableDefaultResponse = ZLL_DISABLE_DEFAULT_RESPONSES;
    psDeviceInfo->sEndPoint.pCallBackFunctions = cbCallBack;

    #if (defined CLD_BASIC) && (defined BASIC_SERVER)
        /* Create an instance of a Basic cluster as a server */
        eCLD_BasicCreateBasic(&psDeviceInfo->sClusterInstance.sBasicServer,
                              TRUE,
                              &sCLD_Basic,
                              &psDeviceInfo->sBasicServerCluster,
                              &au8BasicClusterAttributeControlBits[0]);
    #endif

    #if (defined CLD_BASIC) && (defined BASIC_CLIENT)
        /* Create an instance of a Basic cluster as a client */
        eCLD_BasicCreateBasic(&psDeviceInfo->sClusterInstance.sBasicClient,
                              FALSE,
                              &sCLD_Basic,
                              NULL, //&psDeviceInfo->sBasicClientCluster,
                              NULL/*&au8RemoteBasicClusterAttributeControlBits[0]*/);
    #endif

    #if (defined CLD_ZLL_UTILITY) && (defined ZLL_UTILITY_SERVER)
        /* Create an instance of a basic cluster as a server */
        eCLD_ZllUtilityCreateUtility(&psDeviceInfo->sClusterInstance.sZllUtilityServer,
                              TRUE,
                              &sCLD_ZllUtility,
                              NULL/*&psDeviceInfo->sZllUtilityCluster*/,
                              NULL/*(uint8*)&psDeviceInfo->sZllUtilityClusterAttributeStatus*/,
                              &psDeviceInfo->sZllUtilityServerCustomDataStructure);
    #endif

    #if (defined CLD_ZLL_UTILITY) && (defined ZLL_UTILITY_CLIENT)
        /* Create an instance of a basic cluster as a server */
        eCLD_ZllUtilityCreateUtility(&psDeviceInfo->sClusterInstance.sZllUtilityClient,
                              FALSE,
                              &sCLD_ZllUtility,
                              NULL/*&psDeviceInfo->sZllUtilityCluster*/,
                              NULL/*(uint8*)&psDeviceInfo->sZllUtilityClusterAttributeStatus*/,
                              &psDeviceInfo->sZllUtilityClientCustomDataStructure);
    #endif

    /*
     * Mandatory client clusters
     */
    #if (defined CLD_ONOFF) && (defined ONOFF_CLIENT)
        /* Create an instance of an On/Off cluster as a client */
        eCLD_OnOffCreateOnOff(&psDeviceInfo->sClusterInstance.sOnOffClient,
                              FALSE,
                              &sCLD_OnOff,
                              NULL, //&psDeviceInfo->sOnOffClientCluster,
                              NULL, //&au8OnOffClientAttributeControlBits[0],
                              NULL  /* no cust data struct for client */);
    #endif

    #if (defined CLD_LEVEL_CONTROL) && (defined LEVEL_CONTROL_CLIENT)
        /* Create an instance of a Level Control cluster as a client */
        eCLD_LevelControlCreateLevelControl(&psDeviceInfo->sClusterInstance.sLevelControlClient,
                              FALSE,
                              &sCLD_LevelControl,
                              NULL, //&psDeviceInfo->sLevelControlClientCluster,
                              NULL, //&au8LevelControlClientAttributeControlBits[0],
                              &psDeviceInfo->sLevelControlClientCustomDataStructure);
    #endif

    #if (defined CLD_SCENES) && (defined SCENES_CLIENT)
        /* Create an instance of a Scenes cluster as a client */
        eCLD_ScenesCreateScenes(&psDeviceInfo->sClusterInstance.sScenesClient,
                              FALSE,
                              &sCLD_Scenes,
                              NULL,//&psDeviceInfo->sScenesClientCluster,
                              NULL,//&au8ScenesClientAttributeControlBits[0],
                              &psDeviceInfo->sScenesClientCustomDataStructure,
                              &psDeviceInfo->sEndPoint);
    #endif

    #if (defined CLD_GROUPS) && (defined GROUPS_CLIENT)
        /* Create an instance of a Groups cluster as a client */
        eCLD_GroupsCreateGroups(&psDeviceInfo->sClusterInstance.sGroupsClient,
                              FALSE,
                              &sCLD_Groups,
                              NULL,//&psDeviceInfo->sGroupsClientCluster,
                              NULL,//&au8GroupsClientAttributeControlBits[0],
                              &psDeviceInfo->sGroupsClientCustomDataStructure,
                              &psDeviceInfo->sEndPoint);
    #endif

    #if (defined CLD_IDENTIFY) && (defined IDENTIFY_CLIENT)
        /* Create an instance of an Identify cluster as a client */
        eCLD_IdentifyCreateIdentify(&psDeviceInfo->sClusterInstance.sIdentifyClient,
                              FALSE,
                              &sCLD_Identify,
                              NULL,//&psDeviceInfo->sIdentifyClientCluster,
                              NULL,//&au8IdentifyClientAttributeControlBits[0],
                              &psDeviceInfo->sIdentifyClientCustomDataStructure);
    #endif

    #if (defined CLD_COLOUR_CONTROL) && (defined COLOUR_CONTROL_CLIENT)
        /* Create an instance of a Colour Control cluster as a client */
        eCLD_ColourControlCreateColourControl(
                              &psDeviceInfo->sClusterInstance.sColourControlClient,
                              FALSE,
                              &sCLD_ColourControl,
                              NULL, //&psDeviceInfo->sColourControlClientCluster,
                              NULL, //&au8ColourControlClientAttributeControlBits[0],
                              &psDeviceInfo->sColourControlClientCustomDataStructure);
    #endif

    return eZCL_Register(&psDeviceInfo->sEndPoint);

}


/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/


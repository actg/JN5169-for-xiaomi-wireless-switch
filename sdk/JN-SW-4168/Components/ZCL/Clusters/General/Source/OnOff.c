/*****************************************************************************
 *
 * MODULE:             On/Off Cluster
 *
 * COMPONENT:          OnOff.c
 *
 * AUTHOR:             Lee Mitchell
 *
 * DESCRIPTION:        On/Off cluster definition
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/UnifiedZCL_ZLL102_HA122_Maintenance/Clusters/General/Source/OnOff.c $
 *
 * $Revision: 88146 $
 *
 * $LastChangedBy: nxp29741 $
 *
 * $LastChangedDate: 2017-05-02 13:28:52 +0100 (Tue, 02 May 2017) $
 *
 * $Id: OnOff.c 88146 2017-05-02 12:28:52Z nxp29741 $
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

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#include <jendefs.h>
#include "zcl.h"
#include "zcl_options.h"
#include "zcl_customcommand.h"
#include "OnOff.h"
#include "string.h"
#include "OnOff_internal.h"


#include "dbg.h"
#ifdef DEBUG_CLD_ONOFF
#define TRACE_ONOFF TRUE
#else
#define TRACE_ONOFF FALSE
#endif
#ifdef CLD_SCENES
#include "Scenes.h"
#endif
#ifdef CLD_ONOFF

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/

PRIVATE teZCL_Status eCLD_OnOffSceneEventHandler(
                        teZCL_SceneEvent            eEvent,
                        tsZCL_EndPointDefinition   *psEndPointDefinition,
                        tsZCL_ClusterInstance      *psClusterInstance);

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
#ifdef ONOFF_SERVER
const tsZCL_AttributeDefinition asCLD_OnOffClusterAttributeDefinitions[] = {

    {E_CLD_ONOFF_ATTR_ID_ONOFF,                 (E_ZCL_AF_RD|E_ZCL_AF_SE|E_ZCL_AF_RP),  E_ZCL_BOOL,     (uint32)(&((tsCLD_OnOff*)(0))->bOnOff),0},     /* Mandatory */
    
#ifdef CLD_ONOFF_ATTR_ID_ON_CONFIGURABLE_DURATION
    {E_CLD_ONOFF_ATTR_ID_ON_CONFIGURABLE_DURATION,     (E_ZCL_AF_RD|E_ZCL_AF_SE|E_ZCL_AF_WR),  E_ZCL_UINT16,     (uint32)(&((tsCLD_OnOff*)(0))->u16OnConfigurableDuration),0},
#endif

#ifdef CLD_ONOFF_ATTR_ID_DURATION_UNIT_OF_MEASUREMENT
    {E_CLD_ONOFF_ATTR_ID_DURATION_UNIT_OF_MEASUREMENT, (E_ZCL_AF_RD|E_ZCL_AF_SE|E_ZCL_AF_WR),  E_ZCL_ENUM8,     (uint32)(&((tsCLD_OnOff*)(0))->eDurationUnitOfMeasurement),0},
#endif

#ifdef CLD_ONOFF_ATTR_ID_MAX_DURATION
    {E_CLD_ONOFF_ATTR_ID_MAX_DURATION,                 (E_ZCL_AF_RD|E_ZCL_AF_SE|E_ZCL_AF_WR),  E_ZCL_UINT16,     (uint32)(&((tsCLD_OnOff*)(0))->u16MaxDuration),0},
#endif
    
#ifdef CLD_ONOFF_ATTR_GLOBAL_SCENE_CONTROL
    {E_CLD_ONOFF_ATTR_ID_GLOBAL_SCENE_CONTROL,  (E_ZCL_AF_RD),              E_ZCL_BOOL,     (uint32)(&((tsCLD_OnOff*)(0))->bGlobalSceneControl),0},     /* Optional */
#endif
#ifdef CLD_ONOFF_ATTR_ON_TIME
    {E_CLD_ONOFF_ATTR_ID_ON_TIME,               (E_ZCL_AF_RD|E_ZCL_AF_WR),  E_ZCL_UINT16,   (uint32)(&((tsCLD_OnOff*)(0))->u16OnTime),0},     /* Optinal */
#endif
#ifdef CLD_ONOFF_ATTR_OFF_WAIT_TIME
    {E_CLD_ONOFF_ATTR_ID_OFF_WAIT_TIME,         (E_ZCL_AF_RD|E_ZCL_AF_WR),  E_ZCL_UINT16,   (uint32)(&((tsCLD_OnOff*)(0))->u16OffWaitTime),0}     /* Optinal */
#endif
};

#endif
/* List of attributes in the scene extension table */
tsZCL_SceneExtensionTable sCLD_OnOffSceneExtensionTable =
{
        eCLD_OnOffSceneEventHandler,
        1,
        {E_CLD_ONOFF_ATTR_ID_ONOFF}
};
#ifdef ZCL_COMMAND_DISCOVERY_SUPPORTED
const tsZCL_CommandDefinition asCLD_OnOffClusterCommandDefinitions[] = {
    {E_CLD_ONOFF_CMD_OFF,                E_ZCL_CF_RX},     /* Mandatory */
    {E_CLD_ONOFF_CMD_ON,                 E_ZCL_CF_RX},     /* Mandatory */
    {E_CLD_ONOFF_CMD_TOGGLE,             E_ZCL_CF_RX}     /* Mandatory */    
    
};
#endif
#ifdef ONOFF_SERVER
tsZCL_ClusterDefinition sCLD_OnOff = {
        GENERAL_CLUSTER_ID_ONOFF,
        FALSE,
        E_ZCL_SECURITY_NETWORK,
        (sizeof(asCLD_OnOffClusterAttributeDefinitions) / sizeof(tsZCL_AttributeDefinition)),
        (tsZCL_AttributeDefinition*)asCLD_OnOffClusterAttributeDefinitions,
        &sCLD_OnOffSceneExtensionTable
#ifdef ZCL_COMMAND_DISCOVERY_SUPPORTED        
        ,
        (sizeof(asCLD_OnOffClusterCommandDefinitions) / sizeof(tsZCL_CommandDefinition)),
        (tsZCL_CommandDefinition*)asCLD_OnOffClusterCommandDefinitions        
#endif        
};

#else
tsZCL_ClusterDefinition sCLD_OnOff = {
        GENERAL_CLUSTER_ID_ONOFF,
        FALSE,
        E_ZCL_SECURITY_NETWORK,
        0,
        NULL,
        NULL
#ifdef ZCL_COMMAND_DISCOVERY_SUPPORTED
        ,
        0,
        NULL
#endif
};
#endif
#if (defined CLD_ONOFF) && (defined ONOFF_SERVER)
    uint8 au8OnOffServerAttributeControlBits[(sizeof(asCLD_OnOffClusterAttributeDefinitions) / sizeof(tsZCL_AttributeDefinition))];
#endif


/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

/****************************************************************************
 **
 ** NAME:       eCLD_OnOffCreateOnOff
 **
 ** DESCRIPTION:
 ** Creates an on/off cluster
 **
 ** PARAMETERS:                     Name                        Usage
 ** tsZCL_ClusterInstance           *psClusterInstance          Cluster structure
 ** bool_t                          bIsServer                   Server Client flag
 ** tsZCL_ClusterDefinition         *psClusterDefinition        Cluster Definition
 ** void                            *pvEndPointSharedStructPtr  Endpoint shared structure
 ** uint8                           *pu8AttributeControlBits    Attribute control bits
 ** tsCLD_OnOffCustomDataStructure  *psCustomDataStructure      Custom data Structure
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/

PUBLIC  teZCL_Status eCLD_OnOffCreateOnOff(
                tsZCL_ClusterInstance              *psClusterInstance,
                bool_t                              bIsServer,
                tsZCL_ClusterDefinition            *psClusterDefinition,
                void                               *pvEndPointSharedStructPtr,
                uint8                              *pu8AttributeControlBits,
                tsCLD_OnOffCustomDataStructure     *psCustomDataStructure)
{

    #ifdef STRICT_PARAM_CHECK 
        /* Parameter check */
        if(psClusterInstance==NULL)
        {
            return E_ZCL_ERR_PARAMETER_NULL;
        }
    #endif
    
    // cluster data
    vZCL_InitializeClusterInstance(
           psClusterInstance, 
           bIsServer,
           psClusterDefinition,
           pvEndPointSharedStructPtr,
           pu8AttributeControlBits,
           NULL,
           eCLD_OnOffCommandHandler);    
    
    if(psClusterInstance->pvEndPointSharedStructPtr != NULL)
	{
		// set default state
		((tsCLD_OnOff *)(psClusterInstance->pvEndPointSharedStructPtr))->bOnOff = FALSE;

	#ifdef CLD_ONOFF_ATTR_GLOBAL_SCENE_CONTROL
		((tsCLD_OnOff *)(psClusterInstance->pvEndPointSharedStructPtr))->bGlobalSceneControl = TRUE;
	#endif

	#ifdef CLD_ONOFF_ATTR_ON_TIME
		((tsCLD_OnOff *)(psClusterInstance->pvEndPointSharedStructPtr))->u16OnTime = 0;
	#endif

	#ifdef CLD_ONOFF_ATTR_OFF_WAIT_TIME
		((tsCLD_OnOff *)(psClusterInstance->pvEndPointSharedStructPtr))->u16OffWaitTime = 0;
	#endif

	#ifdef CLD_ONOFF_ATTR_ID_DURATION_UNIT_OF_MEASUREMENT
		((tsCLD_OnOff *)(psClusterInstance->pvEndPointSharedStructPtr))->eDurationUnitOfMeasurement = 0x03;
	#endif
	}

    return E_ZCL_SUCCESS;

}


/****************************************************************************
 **
 ** NAME:       eCLD_OnOffSetState
 **
 ** DESCRIPTION:
 ** Can be used by other clusters to set the state of the on/off attribute
 **
 ** PARAMETERS:                 Name                        Usage
 ** uint8                       u8SourceEndPointId          EndPoint Id
 ** bool                        bOn                         On or Off
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/

PUBLIC  teZCL_Status eCLD_OnOffSetState(uint8 u8SourceEndPointId, bool bOn)
{

    teZCL_Status eStatus;
    tsZCL_EndPointDefinition *psEndPointDefinition;
    tsZCL_ClusterInstance *psClusterInstance;
    void *psCustomDataStructure;
    tsZCL_CallBackEvent sZCL_CallBackEvent;
    tsCLD_OnOff *psSharedStruct;

    /* Find pointers to cluster */
    eStatus = eZCL_FindCluster(GENERAL_CLUSTER_ID_ONOFF, u8SourceEndPointId, TRUE, &psEndPointDefinition, &psClusterInstance, (void*)&psCustomDataStructure);
    if(eStatus != E_ZCL_SUCCESS)
    {
        return eStatus;
    }

    DBG_vPrintf(TRACE_ONOFF, "\neCLD_OnOffSetState(%d,%d)", u8SourceEndPointId, bOn);

    /* Point to shared struct */
    psSharedStruct = (tsCLD_OnOff *)psClusterInstance->pvEndPointSharedStructPtr;

    // get EP mutex
    #ifndef COOPERATIVE
        eZCL_GetMutex(psEndPointDefinition);
    #endif


    /* Set attribute state */
    if(bOn == TRUE)
    {
        psSharedStruct->bOnOff = 1;

#if (defined CLD_ONOFF_ATTR_ON_TIME) && (defined CLD_ONOFF_ATTR_OFF_WAIT_TIME)
        /* See ZLL spec, 6.6.1.1.1 */
        if(psSharedStruct->u16OnTime == 0)
        {
            psSharedStruct->u16OffWaitTime = 0;
    }
#endif

    }
    else
    {
        psSharedStruct->bOnOff = 0;

#ifdef CLD_ONOFF_ATTR_ON_TIME
        /* See ZLL spec, 6.6.1.1.1 */
        psSharedStruct->u16OnTime = 0;
#endif

    }

    /* Generate a callback to let the user know that an update event occurred */
    sZCL_CallBackEvent.u8EndPoint           = psEndPointDefinition->u8EndPointNumber;
    sZCL_CallBackEvent.psClusterInstance    = psClusterInstance;
    sZCL_CallBackEvent.pZPSevent            = NULL;
    sZCL_CallBackEvent.eEventType           = E_ZCL_CBET_CLUSTER_UPDATE;
    psEndPointDefinition->pCallBackFunctions(&sZCL_CallBackEvent);

#if (defined CLD_SCENES) && (defined SCENES_SERVER)
    vCLD_ScenesUpdateSceneValid( psEndPointDefinition);
#endif

    // release EP
    #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


    return E_ZCL_SUCCESS;

}


/****************************************************************************
 **
 ** NAME:       eCLD_OnOffGetState
 **
 ** DESCRIPTION:
 ** Can be used by other clusters to get the state of the on/off attribute
 **
 ** PARAMETERS:                 Name                        Usage
 ** uint8                       u8SourceEndPointId          EndPoint Id
 ** bool                        *pbOn                       On or Off
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/

PUBLIC  teZCL_Status eCLD_OnOffGetState(uint8 u8SourceEndPointId, bool* pbOn)
{

    teZCL_Status eStatus;
    tsZCL_EndPointDefinition *psEndPointDefinition;
    tsZCL_ClusterInstance *psClusterInstance;
    void *psCustomDataStructure;

    /* Find pointers to cluster */
    eStatus = eZCL_FindCluster(GENERAL_CLUSTER_ID_ONOFF, u8SourceEndPointId, TRUE, &psEndPointDefinition, &psClusterInstance, (void*)&psCustomDataStructure);
    if(eStatus != E_ZCL_SUCCESS)
    {
        return eStatus;
    }

    /* Get attribute state */
    if(((tsCLD_OnOff *)(psClusterInstance->pvEndPointSharedStructPtr))->bOnOff == 1)
    {
        *pbOn = TRUE;
    }
    else
    {
        *pbOn = FALSE;
    }

    return E_ZCL_SUCCESS;

}


#if (defined CLD_ONOFF_SUPPORT_ZLL_ENHANCED_COMMANDS) && (defined ONOFF_SERVER)
/****************************************************************************
 **
 ** NAME:       eCLD_OnOffUpdate
 **
 ** DESCRIPTION:
 ** Updates the the state of an On/Off cluster
 **
 ** PARAMETERS:                 Name                        Usage
 ** uint8                       u8SourceEndPointId          Source EP Id
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC  teZCL_Status eCLD_OnOffUpdate(uint8 u8SourceEndPointId)
{

    teZCL_Status eStatus;
    tsZCL_CallBackEvent sZCL_CallBackEvent;
    tsZCL_EndPointDefinition *psEndPointDefinition;
    tsCLD_OnOffCustomDataStructure *psCustomDataStructure;
    tsZCL_ClusterInstance *psClusterInstance;

    tsCLD_OnOff *psSharedStruct;

    /* Find pointers to cluster */
    eStatus = eZCL_FindCluster(GENERAL_CLUSTER_ID_ONOFF, u8SourceEndPointId, TRUE, &psEndPointDefinition, &psClusterInstance, (void*)&psCustomDataStructure);
    if(eStatus != E_ZCL_SUCCESS)
    {
        return eStatus;
    }

    psSharedStruct = (tsCLD_OnOff*)psClusterInstance->pvEndPointSharedStructPtr;

    /* get EP mutex */
    #ifndef COOPERATIVE
        eZCL_GetMutex(psEndPointDefinition);
    #endif



    /*
     * If the values of the OnTime and OffWaitTime attributes are both less than 0xffff, the device shall then
     * update the device every 1/10th second until both the OnTime and OffWaitTime attributes are equal to
     * 0x0000, as follows:
     *
     * If the value of the OnOff attribute is equal to 0x01 (on) and the value of the OnTime attribute
     * is greater than zero, the device shall decrement the value of the OnTime attribute. If the value
     * of the OnTime attribute reaches 0x0000, the device shall set the OffWaitTime and OnOff
     * attributes to 0x0000 and 0x00, respectively.
     *
     * If the value of the OnOff attribute is equal to 0x00 (off) and the value of the OffWaitTime
     * attribute is greater than zero, the device shall decrement the value of the OffWaitTime
     * attribute. If the value of the OffWaitTime attribute reaches 0x0000, the device shall terminate
     * the update.
     */
    if((psSharedStruct->u16OnTime < 0xffff) && (psSharedStruct->u16OffWaitTime < 0xffff) &&
       ((psSharedStruct->u16OnTime != 0) || (psSharedStruct->u16OffWaitTime != 0)))
    {

        DBG_vPrintf(TRACE_ONOFF, "\neCLD_OnOffUpdate: ");

        if((psSharedStruct->bOnOff == 0x01) && (psSharedStruct->u16OnTime > 0))
        {
            psSharedStruct->u16OnTime--;
            if(psSharedStruct->u16OnTime == 0)
            {
                psSharedStruct->u16OffWaitTime = 0x0000;
                psSharedStruct->bOnOff = 0x00;
            }
        }
        else if((psSharedStruct->bOnOff == 0x00) && (psSharedStruct->u16OffWaitTime > 0))
        {
            psSharedStruct->u16OffWaitTime--;
        }

        DBG_vPrintf(TRACE_ONOFF, "OnTime=%d OffWaitTime=%d On=%d", psSharedStruct->u16OnTime, psSharedStruct->u16OffWaitTime, psSharedStruct->bOnOff);

        /* Generate a callback to let the user know that an update event occurred */
        sZCL_CallBackEvent.u8EndPoint           = psEndPointDefinition->u8EndPointNumber;
        sZCL_CallBackEvent.psClusterInstance    = psClusterInstance;
        sZCL_CallBackEvent.pZPSevent            = NULL;
        sZCL_CallBackEvent.eEventType           = E_ZCL_CBET_CLUSTER_UPDATE;
        psEndPointDefinition->pCallBackFunctions(&sZCL_CallBackEvent);

#if (defined CLD_SCENES) && (defined SCENES_SERVER)
    vCLD_ScenesUpdateSceneValid( psEndPointDefinition);
#endif

    }


    /* release EP mutex */
    #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


    return(E_ZCL_SUCCESS);
}

#endif

/****************************************************************************
 **
 ** NAME:       eCLD_OnOffClusterIsPresent
 **
 ** DESCRIPTION:
 ** Can be used by other clusters or the local application to check if
 ** an on/off cluster exists on the specified endpoint
 **
 ** PARAMETERS:                 Name                        Usage
 ** uint8                       u8SourceEndPointId          EndPoint Id
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC  teZCL_Status eCLD_OnOffClusterIsPresent(
        uint8                   u8SourceEndPointId)
{

    tsZCL_EndPointDefinition *psEndPointDefinition;
    tsZCL_ClusterInstance *psClusterInstance;
    tsCLD_OnOffCustomDataStructure *psCustomDataStructure;

    /* Find pointers to cluster */
    return eZCL_FindCluster(GENERAL_CLUSTER_ID_ONOFF, u8SourceEndPointId, TRUE, &psEndPointDefinition, &psClusterInstance, (void*)&psCustomDataStructure);

}

#if ((defined ONOFF_SERVER) && (defined CLD_ONOFF_ATTR_GLOBAL_SCENE_CONTROL))
/****************************************************************************
 **
 ** NAME:       eCLD_OnOffSetGlobalSceneControl
 **
 ** DESCRIPTION:
 ** Can be used by other clusters to set the global scene control attribute
 **
 ** PARAMETERS:                 Name                        Usage
 ** uint8                       u8SourceEndPointId          Source EP Id
 ** bool                        bGlobalSceneControl         Global Scene Control
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC  teZCL_Status eCLD_OnOffSetGlobalSceneControl(uint8 u8SourceEndPointId, bool bGlobalSceneControl)
{

    teZCL_Status eStatus;
    tsZCL_EndPointDefinition *psEndPointDefinition;
    tsCLD_OnOffCustomDataStructure *psCustomDataStructure;
    tsZCL_ClusterInstance *psClusterInstance;

    tsCLD_OnOff *psSharedStruct;

    DBG_vPrintf(TRACE_ONOFF, "\nONOFF: SetGlobalSceneControl %d", bGlobalSceneControl);

    /* Find pointers to cluster */
    eStatus = eZCL_FindCluster(GENERAL_CLUSTER_ID_ONOFF, u8SourceEndPointId, TRUE, &psEndPointDefinition, &psClusterInstance, (void*)&psCustomDataStructure);
    if(eStatus != E_ZCL_SUCCESS)
    {
        DBG_vPrintf(TRACE_ONOFF, "Err No Cluster");
        return eStatus;
    }

    psSharedStruct = (tsCLD_OnOff*)psClusterInstance->pvEndPointSharedStructPtr;

    /* get EP mutex */
    #ifndef COOPERATIVE
        eZCL_GetMutex(psEndPointDefinition);
    #endif


    if(bGlobalSceneControl == TRUE)
    {
        psSharedStruct->bGlobalSceneControl = 0x01;
    }
    else
    {
        psSharedStruct->bGlobalSceneControl = 0x00;
    }

    /* release EP mutex */
    #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


    DBG_vPrintf(TRACE_ONOFF, "OK");

    return(E_ZCL_SUCCESS);
}

#endif

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/
/****************************************************************************
 **
 ** NAME:       eCLD_OnOffSceneEventHandler
 **
 ** DESCRIPTION:
 ** Handles events generated by a scenes cluster (if present)
 **
 ** PARAMETERS:                 Name                        Usage
 ** teZCL_SceneEvent            eEvent                      Scene Event
 ** tsZCL_EndPointDefinition    *psEndPointDefinition       End Point Definition
 ** tsZCL_ClusterInstance       *psClusterInstance          Cluster structure
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/

PRIVATE  teZCL_Status eCLD_OnOffSceneEventHandler(
                        teZCL_SceneEvent            eEvent,
                        tsZCL_EndPointDefinition   *psEndPointDefinition,
                        tsZCL_ClusterInstance      *psClusterInstance)
{

    tsZCL_CallBackEvent sZCL_CallBackEvent;
#ifdef CLD_ONOFF_ATTR_GLOBAL_SCENE_CONTROL
    tsCLD_OnOff *psSharedStruct = (tsCLD_OnOff *)psClusterInstance->pvEndPointSharedStructPtr;
#endif

    switch(eEvent)
    {

    case E_ZCL_SCENE_EVENT_SAVE:
        DBG_vPrintf(TRACE_ONOFF, "\nONOFF: Scene Event: Save");
        break;

    case E_ZCL_SCENE_EVENT_RECALL:
        DBG_vPrintf(TRACE_ONOFF, "\nONOFF: Scene Event: Recall");

        /* See ZLL specification 6.6.1.2.1 */
#ifdef CLD_ONOFF_ATTR_GLOBAL_SCENE_CONTROL
        psSharedStruct->bGlobalSceneControl = 1;
#endif

        /* Inform the application that the cluster has just been updated */
        sZCL_CallBackEvent.u8EndPoint = psEndPointDefinition->u8EndPointNumber;
        sZCL_CallBackEvent.psClusterInstance = psClusterInstance;
        sZCL_CallBackEvent.pZPSevent = NULL;
        sZCL_CallBackEvent.eEventType = E_ZCL_CBET_CLUSTER_UPDATE;

        // call user
        psEndPointDefinition->pCallBackFunctions(&sZCL_CallBackEvent);

#if (defined CLD_SCENES) && (defined SCENES_SERVER)
    vCLD_ScenesUpdateSceneValid( psEndPointDefinition);
#endif

        break;

    }

    return E_ZCL_SUCCESS;
}


#endif
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/


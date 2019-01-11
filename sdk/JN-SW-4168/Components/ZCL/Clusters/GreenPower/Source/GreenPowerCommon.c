/*****************************************************************************
 *
 * MODULE:             Green Power Cluster
 *
 * COMPONENT:          GreenPowerCommon.c
 *
 * AUTHOR:             Ramakrishna
 *
 * DESCRIPTION:        The API for the Green Power Cluster
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/UnifiedZCL_ZLL102_HA122_Maintenance/Clusters/GreenPower/Source/GreenPowerCommon.c $
 *
 * $Revision: 69169 $
 *
 * $LastChangedBy: nxp58432 $
 *
 * $LastChangedDate: 2015-04-27 08:50:08 +0100 (Mon, 27 Apr 2015) $
 *
 * $Id: GreenPowerCommon.c 69169 2015-04-27 07:50:08Z nxp58432 $
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

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include <jendefs.h>
#include <string.h>
#include <stdlib.h>
#include "zcl.h"
#include "zcl_options.h"
#include "GreenPower.h"
#include "GreenPower_internal.h"
#include "Identify.h"
#include "LevelControl.h"
#include "OnOff.h"
#include "dbg.h"
#include "rnd_pub.h"
#include "zcl_customcommand.h"
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifndef TRACE_GP_DEBUG
#define TRACE_GP_DEBUG FALSE
#endif
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
#ifdef GP_COMBO_MIN_DEVICE
PRIVATE teZCL_Status eGP_TranslateCommandIntoZcl(
                    uint8                                  u8GpEndPointId,
                    uint8                                  u8MatchedIndex,
                    uint8                                  u8MatchedCmdIndex,
                    tsGP_GreenPowerCustomData              *psGpCustomDataStructure,
                    uint8                                  u8GpdCommandPayloadLength,
                    uint8                                  *pu8GpdCommandPayload);

//PRIVATE uint16 u16GP_GetClusterId(teGP_ZgpdCommandId   eZgpdCommandId);

PRIVATE teZCL_Status eGP_BufferLoopBackPacket(
                    tsZCL_EndPointDefinition               *psEndPointDefinition,
                    tsGP_GreenPowerCustomData              *psGpCustomDataStructure,
                    uint8                                  u8TranslationIndex,
                    uint8                                  u8ApplicationId,
                    tuGP_ZgpdDeviceAddr                    *puZgpdAddress,
                    teGP_ZgpdCommandId                     eZgpdCommandId,
                    uint8                                  u8GpdCommandPayloadLength,
                    uint8                                  *pu8GpdCommandPayload);

PRIVATE bool bIsCommandMapped(teGP_ZgpdCommandId                     eZgpdCommandId,
							  uint8                					*pMatchedCmdIndex,
							  tsGP_TranslationTableEntry 			*psTranslationTableEntry);
#endif
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        Public Functions                                              ***/
/****************************************************************************/
#ifdef GP_COMBO_MIN_DEVICE
/****************************************************************************
 **
 ** NAME:       bIsCommandMapped
 **
 ** DESCRIPTION:
 ** Checks if the received command is mapped in translation table
 **
 ** PARAMETERS:                   Name                           Usage
 ** teGP_ZgpdCommandId                     eZgpdCommandId,
 ** uint8                					*pMatchedCmdIndex
 ** tsGP_TranslationTableEntry *psTranslationTableEntry
 **
 ** RETURN:
 ** TRUE or FALSE
 **
 ****************************************************************************/
PRIVATE bool bIsCommandMapped(teGP_ZgpdCommandId                     eZgpdCommandId,
							  uint8                					*pMatchedCmdIndex,
							  tsGP_TranslationTableEntry 			*psTranslationTableEntry)
{
	uint8 i;
	for(i = 0; i < psTranslationTableEntry->u8NoOfCmdInfo; i ++ )
	{
			if((psTranslationTableEntry->psGpToZclCmdInfo[i].eZgpdCommandId == eZgpdCommandId)&&
			  (psTranslationTableEntry->psGpToZclCmdInfo[i].u8EndpointId != 0xFD))
			{
				*pMatchedCmdIndex = i;
				return TRUE;
			}
		}
	return FALSE;

}

/****************************************************************************
 **
 ** NAME:       eGP_GPDFHandler
 **
 ** DESCRIPTION:
 ** Process received command through translation table
 **
 ** PARAMETERS:                   Name                           Usage
 ** ZPS_tsAfEvent                 *pZPSevent                     ZPS event
 ** tsZCL_EndPointDefinition      *psEndPointDefinition          Endpoint definition
 ** tsGP_GreenPowerCustomData     *psGpCustomDataStructure       Custom data
 ** uint8                         u8ApplicationId                Application ID
 ** tuGP_ZgpdDeviceAddr           *puZgpdAddress                 ZGP device address
 ** teGP_ZgpdCommandId            eZgpdCommandId                 command id
 ** uint8                         u8GpdCommandPayloadLength      GPD command length
 ** uint8                         *pu8GpdCommandPayload          GPD command payload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC teZCL_Status eGP_GPDFHandler(
                    ZPS_tsAfEvent                          *pZPSevent,
                    tsZCL_EndPointDefinition               *psEndPointDefinition,
                    tsGP_GreenPowerCustomData              *psGpCustomDataStructure,
                    uint8                                  u8ApplicationId,
                    tuGP_ZgpdDeviceAddr                    *puZgpdAddress,
                    teGP_ZgpdCommandId                     eZgpdCommandId,
                    uint8                                  u8GpdCommandPayloadLength,
                    uint8                                  *pu8GpdCommandPayload)
{
    uint8 i, u8MatchedCmdIndex;
    bool_t bMatchSuccess = FALSE, bZgpIdMatch = FALSE, bPacketBuffered = FALSE;

    #ifdef STRICT_PARAM_CHECK
        /* Check pointers */
        if((psEndPointDefinition==NULL)  ||
           (psGpCustomDataStructure==NULL))
        {
            return E_ZCL_ERR_PARAMETER_NULL;
        }
    #endif
    /* Traverse translation table */
    for(i = 0; i < psGpCustomDataStructure->u8NoOfTranslationTableEntries; i++)
    {
        /* check for translation pointer is populated or not */
        if(psGpCustomDataStructure->psZgpsTranslationTableEntry[i].psGpToZclCmdInfo != NULL)
        {
            /* check application id type */
            if((psGpCustomDataStructure->psZgpsTranslationTableEntry[i].b8Options & (uint8)GP_APPLICATION_ID_MASK) == u8ApplicationId)
            {
                /* Is application id type is 4 bytes source id */
                if(u8ApplicationId == GP_APPL_ID_4_BYTE)
                {
                    if(psGpCustomDataStructure->psZgpsTranslationTableEntry[i].uZgpdDeviceAddr.u32ZgpdSrcId == puZgpdAddress->u32ZgpdSrcId)
                    {
                        bZgpIdMatch = TRUE;
                    }
                }
#ifdef GP_IEEE_ADDR_SUPPORT
                else
                {
                    if(psGpCustomDataStructure->psZgpsTranslationTableEntry[i].uZgpdDeviceAddr.u64ZgpdIEEEAddr == puZgpdAddress->u64ZgpdIEEEAddr)
                    {
                        bZgpIdMatch = TRUE;
                    }
                }
#endif

                /* Check entry found in translation table or not */
                if(bZgpIdMatch)
                {
                    bZgpIdMatch = FALSE;

                    if((eZgpdCommandId == E_GP_ATTRIBUTE_REPORTING)&&
                       (psGpCustomDataStructure->psZgpsTranslationTableEntry[i].psGpToZclCmdInfo->eZgpdCommandId == E_GP_SENSOR_COMMAND))
                    {
                        eZgpdCommandId = E_GP_SENSOR_COMMAND;
                    }
                    /* checking for matched GP command id */
                    if(bIsCommandMapped(eZgpdCommandId, &u8MatchedCmdIndex, &psGpCustomDataStructure->psZgpsTranslationTableEntry[i]))
                   /* if((psGpCustomDataStructure->psZgpsTranslationTableEntry[i].psGpToZclCmdInfo[u8MatchedCmdIndex].eZgpdCommandId == eZgpdCommandId)&&
                            (psGpCustomDataStructure->psZgpsTranslationTableEntry[i].psGpToZclCmdInfo[u8MatchedCmdIndex].u8EndpointId != 0xFD))*/
                    {
                        /* if once we already pushed the ZCL packet to stack for this GPD command then
                         * buffer for next push */
                        if(bMatchSuccess)
                        {
                            bPacketBuffered = TRUE;

                            eGP_BufferLoopBackPacket(
                                    psEndPointDefinition,
                                    psGpCustomDataStructure,
                                    i,
                                    u8ApplicationId,
                                    puZgpdAddress,
                                    eZgpdCommandId,
                                    u8GpdCommandPayloadLength,
                                    pu8GpdCommandPayload);
                        }
                        else
                        {
                            bMatchSuccess = TRUE;
                            /* translate ZGP Command into ZCL command and send it to linked endpoint */
                            eGP_TranslateCommandIntoZcl(
                                    psEndPointDefinition->u8EndPointNumber,
                                    i,
                                    u8MatchedCmdIndex,
                                    psGpCustomDataStructure,
                                    u8GpdCommandPayloadLength,
                                    pu8GpdCommandPayload);
                        }
                    }
                }
            }
        }
        if(bPacketBuffered)
            break;
    }
    // fill in callback event structure
    eZCL_SetCustomCallBackEvent(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent,
                pZPSevent, 0, psEndPointDefinition->u8EndPointNumber);

    /* Checking for entry found in translation table or not */
    if(bMatchSuccess)
    {
         /* Set Event Type */
        psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_ZGPD_COMMAND_RCVD;
        /* Give a call back event to app */
        psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);
        return E_ZCL_SUCCESS;
    }
    else
    {     /* Set Event Type */
        psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_ZGPD_CMD_RCVD_WO_TRANS_ENTRY;
        /* Give a call back event to app */
        psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);
        return E_ZCL_FAIL;
    }
}

/****************************************************************************
 **
 ** NAME:       bGP_IsSinkTableEntryPresent
 **
 ** DESCRIPTION:
 ** Finding entry in sink table
 **
 ** PARAMETERS:                         Name                            Usage
 ** uint8                               u8GpEndPointId                  Endpoint Id
 ** uint8                               u8ApplicationId                 Application Id
 ** tuGP_ZgpdDeviceAddr                 *puZgpdAddress                  Pointer to GP device address
 ** teGP_GreenPowerSinkTableAction      eSinkTableAction                Get or Set the sink table
 ** tsGP_ZgpsSinkTable                  *psSinkTableEntry               Pointer to Sink Table Entry
 ** teGP_GreenPowerCommunicationMode    eCommunicationMode              communication mode for GPD
 ** RETURN:
 ** bool_t
 **
 ****************************************************************************/
PUBLIC bool_t bGP_IsSinkTableEntryPresent(
                    uint8                                  u8GpEndPointId,
                    uint8                                  u8ApplicationId,
                    tuGP_ZgpdDeviceAddr                    *puZgpdAddress,
                    teGP_GreenPowerSinkTableAction         eSinkTableAction,
                    tsGP_ZgpsSinkTable                     *psSinkTableEntry,
                    teGP_GreenPowerCommunicationMode       eCommunicationMode)
{
    tsZCL_EndPointDefinition                *psEndPointDefinition;
    tsZCL_ClusterInstance                   *psClusterInstance;
    tsGP_GreenPowerCustomData               *psGpCustomDataStructure;
    uint8                   				u8Status;
    uint8                                   i;
    bool_t                                  bZgpIdMatch = FALSE;


    /* Check pointers */
    if((puZgpdAddress == NULL)  ||
       (psSinkTableEntry == NULL))
    {
        return FALSE;
    }
   //find GP cluster
   if((u8Status = eGP_FindGpCluster(
            u8GpEndPointId,
            TRUE,
            &psEndPointDefinition,
            &psClusterInstance,
            &psGpCustomDataStructure)) != E_ZCL_SUCCESS)
    {
        return FALSE;
    }

   // get EP mutex
   #ifndef COOPERATIVE
        eZCL_GetMutex(psEndPointDefinition);
   #endif


    for(i = 0; i< GP_NUMBER_OF_SINK_TABLE_ENTRIES; i++)
    {   /* check if sink table entry is not empty */
        if(psGpCustomDataStructure->asZgpsSinkTable[i].eGreenPowerSinkTablePriority != 0)
        {
            /* check if application id is same */
            if((uint8)(psGpCustomDataStructure->asZgpsSinkTable[i].b16Options & GP_APPLICATION_ID_MASK) == u8ApplicationId)
            {
                if(u8ApplicationId == GP_APPL_ID_4_BYTE)
                {   /* check if GPD device address is same */
                    if((psGpCustomDataStructure->asZgpsSinkTable[i].uZgpdDeviceAddr.u32ZgpdSrcId == puZgpdAddress->u32ZgpdSrcId)&&
                      (eCommunicationMode == ((psGpCustomDataStructure->asZgpsSinkTable[i].b16Options & GP_SINK_TABLE_COMM_MODE_MASK)  >> 3)))
                    {
                        bZgpIdMatch = TRUE;
                    }
                }
#ifdef GP_IEEE_ADDR_SUPPORT
                else
                {
                    if((psGpCustomDataStructure->asZgpsSinkTable[i].uZgpdDeviceAddr.u64ZgpdIEEEAddr == puZgpdAddress->u64ZgpdIEEEAddr)&&
                      (eCommunicationMode == ((psGpCustomDataStructure->asZgpsSinkTable[i].b16Options & GP_SINK_TABLE_COMM_MODE_MASK)  >> 3)))
                    {
                        bZgpIdMatch = TRUE;
                    }
                }
#endif
                /* if sink table entry is present */
                if(bZgpIdMatch)
                {   /* take action according to sink table action parameter */
                    if((eSinkTableAction == E_GP_SINK_TABLE_SET_ENTRY)||(E_GP_SINK_TABLE_UPDATE_ENTRY_ON_DATA_RECEIVE == eSinkTableAction))
                    {
                        memcpy(&psGpCustomDataStructure->asZgpsSinkTable[i],psSinkTableEntry,sizeof(tsGP_ZgpsSinkTable));
                        if(E_GP_SINK_TABLE_UPDATE_ENTRY_ON_DATA_RECEIVE != eSinkTableAction)
						{
							vGP_CallbackForPersistData(E_GP_ADD_REMOVE_UPDATE_SINK_TABLE);
						}
                    }
                    else
                    {
                        memcpy(psSinkTableEntry,&psGpCustomDataStructure->asZgpsSinkTable[i],sizeof(tsGP_ZgpsSinkTable));
                    }

                    // release mutex
                    #ifndef COOPERATIVE
                        eZCL_ReleaseMutex(psEndPointDefinition);
                    #endif

                    return TRUE;
                }
            }
        }
    }

    // release mutex
    #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


    return FALSE;
}

/****************************************************************************
 **
 ** NAME:       eGP_AddSinkTableEntry
 **
 ** DESCRIPTION:
 ** Adding Entry to sink table
 **
 ** PARAMETERS:                         Name                            Usage
 ** uint8                               u8GreenPowerEndPointId          Endpoint Id
 ** tsGP_ZgpsSinkTable                  *psSinkTableEntry               Pointer to Sink Table
 **
 ** RETURN:
 ** teGP_GreenPowerStatus
 **
 ****************************************************************************/
PUBLIC teGP_GreenPowerStatus eGP_AddSinkTableEntry(
                    uint8                                  u8GreenPowerEndPointId,
                    tsGP_ZgpsSinkTable                     *psSinkTableEntry)
{
    uint8                          i;
    tsZCL_EndPointDefinition       *psEndPointDefinition;
    tsZCL_ClusterInstance          *psClusterInstance;
    tsGP_GreenPowerCustomData      *psGpCustomDataStructure;
    uint8				           u8Status;

    /* Check pointers */
    if(psSinkTableEntry == NULL)
    {
        return E_ZCL_ERR_PARAMETER_NULL;
    }
    //find GP cluster
    if((u8Status = eGP_FindGpCluster(
            u8GreenPowerEndPointId,
            TRUE,
            &psEndPointDefinition,
            &psClusterInstance,
            &psGpCustomDataStructure)) != E_ZCL_SUCCESS)
    {
        return u8Status;
    }

    // get EP mutex
    #ifndef COOPERATIVE
        eZCL_GetMutex(psEndPointDefinition);
    #endif


    /* check if entry already exist for this ZGPD then update it with new values */
    if(bGP_IsSinkTableEntryPresent(u8GreenPowerEndPointId,
                                   (uint8)(psSinkTableEntry->b16Options & GP_APPLICATION_ID_MASK),
                                   &psSinkTableEntry->uZgpdDeviceAddr,
                                   E_GP_SINK_TABLE_SET_ENTRY,
                                   psSinkTableEntry,
                                   (teGP_GreenPowerCommunicationMode)((psSinkTableEntry->b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3)))
    {
        // release mutex
        #ifndef COOPERATIVE
            eZCL_ReleaseMutex(psEndPointDefinition);
        #endif


        return E_GP_SINK_TABLE_SUCCESS;
    }

    for(i = 0; i< GP_NUMBER_OF_SINK_TABLE_ENTRIES; i++)
    {
        /* check for empty entry */
        if(psGpCustomDataStructure->asZgpsSinkTable[i].eGreenPowerSinkTablePriority == 0)
        {
            memcpy(&psGpCustomDataStructure->asZgpsSinkTable[i],psSinkTableEntry,sizeof(tsGP_ZgpsSinkTable));
            vGP_CallbackForPersistData(E_GP_ADD_REMOVE_UPDATE_SINK_TABLE);
            // release mutex
            #ifndef COOPERATIVE
                eZCL_ReleaseMutex(psEndPointDefinition);
            #endif


            return E_GP_SINK_TABLE_SUCCESS;
        }
    }

    /* No empty entry found, check for lower priority */
    if((psSinkTableEntry->eGreenPowerSinkTablePriority == E_GP_SINK_TABLE_P_2)||
       (psSinkTableEntry->eGreenPowerSinkTablePriority == E_GP_SINK_TABLE_P_1))
    {
        for(i = 0; i< GP_NUMBER_OF_SINK_TABLE_ENTRIES; i++)
        {
            /* check for empty entry */
            if(psGpCustomDataStructure->asZgpsSinkTable[i].eGreenPowerSinkTablePriority == E_GP_SINK_TABLE_P_3)
            {
                memcpy(&psGpCustomDataStructure->asZgpsSinkTable[i],psSinkTableEntry,sizeof(tsGP_ZgpsSinkTable));

                vGP_CallbackForPersistData(E_GP_ADD_REMOVE_UPDATE_SINK_TABLE);
                // release mutex
                #ifndef COOPERATIVE
                    eZCL_ReleaseMutex(psEndPointDefinition);
                #endif


                return E_GP_SINK_TABLE_SUCCESS;
            }
        }
    }
    /* if entry is of priority 1 then it can replace lower priority entry */
    if(psSinkTableEntry->eGreenPowerSinkTablePriority == E_GP_SINK_TABLE_P_1)
    {
        for(i = 0; i< GP_NUMBER_OF_SINK_TABLE_ENTRIES; i++)
        {
            /* check for priority 2 entry */
            if(psGpCustomDataStructure->asZgpsSinkTable[i].eGreenPowerSinkTablePriority == E_GP_SINK_TABLE_P_2)
            {
                memcpy(&psGpCustomDataStructure->asZgpsSinkTable[i],psSinkTableEntry,sizeof(tsGP_ZgpsSinkTable));
                vGP_CallbackForPersistData(E_GP_ADD_REMOVE_UPDATE_SINK_TABLE);
                // release mutex
                #ifndef COOPERATIVE
                    eZCL_ReleaseMutex(psEndPointDefinition);
                #endif


                return E_GP_SINK_TABLE_SUCCESS;
            }
        }
    }

    // release mutex
    #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


    return E_GP_NO_SINK_TABLES;
}

/****************************************************************************
 **
 ** NAME:       eGP_RemoveSinkTableEntry
 **
 ** DESCRIPTION:
 ** Removing Entry from sink table
 **
 ** PARAMETERS:                         Name                            Usage
 ** uint8                               u8GreenPowerEndPointId          Endpoint Id
 ** tsGP_ZgpsSinkTable                  *psSinkTableEntry               Pointer to Sink Table
 **
 ** RETURN:
 ** teGP_GreenPowerStatus
 **
 ****************************************************************************/
PUBLIC teGP_GreenPowerStatus eGP_RemoveSinkTableEntry(
                    uint8                                  u8GreenPowerEndPointId,
                    tsGP_ZgpsSinkTable                     *psSinkTableEntry)
{
    uint8                          i;
    tsZCL_EndPointDefinition       *psEndPointDefinition;
    tsZCL_ClusterInstance          *psClusterInstance;
    tsGP_GreenPowerCustomData      *psGpCustomDataStructure;
    uint8				            u8Status;
    uint8                          u8ApplicationId;
    teGP_GreenPowerCommunicationMode       eCommunicationMode;
    bool_t                         bZgpIdMatch = FALSE;

    /* Check pointers */
    if(psSinkTableEntry == NULL)
    {
        return E_ZCL_ERR_PARAMETER_NULL;
    }
    //find GP cluster
    if((u8Status = eGP_FindGpCluster(
            u8GreenPowerEndPointId,
            TRUE,
            &psEndPointDefinition,
            &psClusterInstance,
            &psGpCustomDataStructure)) != E_ZCL_SUCCESS)
    {
        return u8Status;
    }

    // get EP mutex
    #ifndef COOPERATIVE
        eZCL_GetMutex(psEndPointDefinition);
    #endif


    u8ApplicationId = psSinkTableEntry->b16Options & GP_APPLICATION_ID_MASK;
    eCommunicationMode = (psSinkTableEntry->b16Options & GP_SINK_TABLE_COMM_MODE_MASK)  >> 3;

    for(i = 0; i< GP_NUMBER_OF_SINK_TABLE_ENTRIES; i++)
    {   /* check if sink table entry is not empty */
        if(psGpCustomDataStructure->asZgpsSinkTable[i].eGreenPowerSinkTablePriority != 0)
        {
            /* check if application id is same */
            if((uint8)(psGpCustomDataStructure->asZgpsSinkTable[i].b16Options & GP_APPLICATION_ID_MASK) == u8ApplicationId)
            {
                if(u8ApplicationId == GP_APPL_ID_4_BYTE)
                {   /* check if GPD device address is same */
                    if((psGpCustomDataStructure->asZgpsSinkTable[i].uZgpdDeviceAddr.u32ZgpdSrcId == psSinkTableEntry->uZgpdDeviceAddr.u32ZgpdSrcId)&&
                      (eCommunicationMode == ((psGpCustomDataStructure->asZgpsSinkTable[i].b16Options & GP_SINK_TABLE_COMM_MODE_MASK)  >> 3)))
                    {
                        bZgpIdMatch = TRUE;
                    }
                }
#ifdef GP_IEEE_ADDR_SUPPORT
                else
                {
                    if((psGpCustomDataStructure->asZgpsSinkTable[i].uZgpdDeviceAddr.u64ZgpdIEEEAddr == psSinkTableEntry->uZgpdDeviceAddr.u64ZgpdIEEEAddr)&&
                      (eCommunicationMode == ((psGpCustomDataStructure->asZgpsSinkTable[i].b16Options & GP_SINK_TABLE_COMM_MODE_MASK)  >> 3)))
                    {
                        bZgpIdMatch = TRUE;
                    }
                }
#endif
                /* if sink table entry is present */
                if(bZgpIdMatch)
                {   /* remove sink table entry */
                    memset(&psGpCustomDataStructure->asZgpsSinkTable[i],0,sizeof(tsGP_ZgpsSinkTable));
                    vGP_CallbackForPersistData(E_GP_ADD_REMOVE_UPDATE_SINK_TABLE);
                    // release mutex
                    #ifndef COOPERATIVE
                        eZCL_ReleaseMutex(psEndPointDefinition);
                    #endif

                    return E_GP_SINK_TABLE_SUCCESS;
                }
            }
        }
    }
    // release mutex
    #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


    return E_GP_NO_SINK_TABLES;
}


/****************************************************************************
 **
 ** NAME:       u16GP_GetStringSizeOfSinkTable
 **
 ** DESCRIPTION:
 ** Get Size of Sink Table
 **
 ** PARAMETERS:                     Name                            Usage
 ** uint8                           u8GreenPowerEndPointId          End Point id
 **
 ** RETURN:
 ** uint16
 **
 ****************************************************************************/
PUBLIC uint16 u16GP_GetStringSizeOfSinkTable(uint8 u8GreenPowerEndPointId)
{
    tsZCL_EndPointDefinition                *psEndPointDefinition;
    tsZCL_ClusterInstance                   *psClusterInstance;
    tsGP_GreenPowerCustomData               *psGpCustomDataStructure;
    uint16                                  u16Length = 0, b16Options;
    uint8                                   i;

    //find GP cluster
    if((eGP_FindGpCluster(  u8GreenPowerEndPointId,
                            TRUE,
                            &psEndPointDefinition,
                            &psClusterInstance,
                            &psGpCustomDataStructure)) != E_ZCL_SUCCESS)
    {
        return 0;
    }

    for(i = 0; i< GP_NUMBER_OF_SINK_TABLE_ENTRIES; i++)
    {
        /* check for entry */
        if(psGpCustomDataStructure->asZgpsSinkTable[i].eGreenPowerSinkTablePriority != 0)
        {
            u16Length += 2; //2 byte options field
            b16Options = psGpCustomDataStructure->asZgpsSinkTable[i].b16Options;

            if((b16Options & GP_APPLICATION_ID_MASK) == GP_APPL_ID_4_BYTE)
            {
                u16Length += 4; //4 byte GPD ID
            }
            else
            {
                u16Length += 8; //8 byte GPD ID
            }

            u16Length += 1; //1 byte Device ID
            /* if communication mode is pre commissioned then take group list length also */
            if(((b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3) == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID)
            {
                u16Length += (psGpCustomDataStructure->asZgpsSinkTable[i].u8ZgpsGroupListEntries * 4) +1;
            }
            /* check if assigned address is present */
            if(b16Options & GP_SINK_TABLE_ASSIGNED_ADDR_MASK)
            {
                u16Length += 2; //2 byte GPD Assigned Alias
            }

            u16Length += 1; //1 byte Radius
            //if security options are available
            if(b16Options & GP_SINK_TABLE_SECURITY_USE_MASK)
            {
                teGP_GreenPowerSecLevel    eSecLevel;
                teGP_GreenPowerSecKeyType  eSecKeyType;
                u16Length += 1; //1 byte security options
                eSecLevel = psGpCustomDataStructure->asZgpsSinkTable[i].b8SecOptions & GP_SECURITY_LEVEL_MASK;
                eSecKeyType = (psGpCustomDataStructure->asZgpsSinkTable[i].b8SecOptions & GP_SECURITY_KEY_TYPE_MASK) >> 2;
                //if security key is available
                if((eSecLevel != E_GP_NO_SECURITY)&&(eSecKeyType != E_GP_DERIVED_INDIVIDUAL_ZGPD_KEY))
                {
                    u16Length += 16; //16 byte security key
                }
            }
            /* check if sequence number capability or security is present*/
            if((b16Options & GP_SINK_TABLE_SEQ_NUM_CAP_MASK)||
                        (b16Options & GP_SINK_TABLE_SECURITY_USE_MASK))
            {
                u16Length += 4; //4 byte security frame counter
            }
        }
    }
    //return calculated length
    return u16Length;
}

/****************************************************************************
 **
 ** NAME:       u16GP_WriteSinkTableString
 **
 ** DESCRIPTION:
 ** Write sink table as string into passed data pointer
 **
 ** PARAMETERS:                      Name                           Usage
 ** uint8                         u8GreenPowerEndPointId        Green Power Endpoint id
 ** uint8                         *pu8Data                      data pointer to write
 ** uint16                        u16StringSize                 String size
 **
 ** RETURN:
 ** uint16
 **
 ****************************************************************************/
PUBLIC uint16 u16GP_WriteSinkTableString(
                    uint8                                  u8GreenPowerEndPointId,
                    uint8                                  *pu8Data,
                    uint16                                 u16StringSize)
{
    tsZCL_EndPointDefinition                *psEndPointDefinition;
    tsZCL_ClusterInstance                   *psClusterInstance;
    tsGP_GreenPowerCustomData               *psGpCustomDataStructure;
    uint16                                  b16Options;
    uint8                                   i;
    uint8 *pu8Start = pu8Data;

    //find GP Cluster
    if((eGP_FindGpCluster(  u8GreenPowerEndPointId,
                            TRUE,
                            &psEndPointDefinition,
                            &psClusterInstance,
                            &psGpCustomDataStructure)) != E_ZCL_SUCCESS)
    {
        return 0;
    }
    /* write first 2 bytes as string length */
    *pu8Data++ = (uint8)u16StringSize;
    *pu8Data++ = (u16StringSize >> 8);

    for(i = 0; i< GP_NUMBER_OF_SINK_TABLE_ENTRIES; i++)
    {
        /* check for entry */
        if(psGpCustomDataStructure->asZgpsSinkTable[i].eGreenPowerSinkTablePriority != 0)
        {
            b16Options = psGpCustomDataStructure->asZgpsSinkTable[i].b16Options;
            *pu8Data++ = (uint8)b16Options;//2 byte options field
            *pu8Data++ = (b16Options >> 8);

            if((b16Options & GP_APPLICATION_ID_MASK) == GP_APPL_ID_4_BYTE)
            {
                //4 byte GPD ID
                uint32 u32Data = psGpCustomDataStructure->asZgpsSinkTable[i].uZgpdDeviceAddr.u32ZgpdSrcId;
                *pu8Data++ = (uint8)u32Data;
                *pu8Data++ = (uint8)(u32Data >> 8);
                *pu8Data++ = (uint8)(u32Data >> 16);
                *pu8Data++ = (uint8)(u32Data >> 24);
            }
#ifdef GP_IEEE_ADDR_SUPPORT
            else
            {
                uint64 u64Data = psGpCustomDataStructure->asZgpsSinkTable[i].uZgpdDeviceAddr.u64ZgpdIEEEAddr;
                 //8 byte GPD ID
                *pu8Data++ = (uint8)(u64Data & 0xff);
                *pu8Data++ = (uint8)(u64Data >> 8);
                *pu8Data++ = (uint8)(u64Data >> 16);
                *pu8Data++ = (uint8)(u64Data >> 24);
                *pu8Data++ = (uint8)(u64Data >> 32);
                *pu8Data++ = (uint8)(u64Data >> 40);
                *pu8Data++ = (uint8)(u64Data >> 48);
                *pu8Data++ = (uint8)(u64Data >> 56);
            }
#endif
            *pu8Data++ = psGpCustomDataStructure->asZgpsSinkTable[i].eZgpdDeviceId; //1 byte Device ID
            /* if communication mode is pre commissioned then add group list also */
            if(((b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3) == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID)
            {
                uint8 j;
                *pu8Data++ = psGpCustomDataStructure->asZgpsSinkTable[i].u8ZgpsGroupListEntries;//1 byte group list length

                for(j=0; j< psGpCustomDataStructure->asZgpsSinkTable[i].u8ZgpsGroupListEntries; j++)
                {
                    //2 byte sink group field
                    *pu8Data++ = (uint8)psGpCustomDataStructure->asZgpsSinkTable[i].asZgpsGroupList[j].u16SinkGroup;
                    *pu8Data++ = (uint8)(psGpCustomDataStructure->asZgpsSinkTable[i].asZgpsGroupList[j].u16SinkGroup >> 8);
                    //2 byte Alias field
                    *pu8Data++ = (uint8)psGpCustomDataStructure->asZgpsSinkTable[i].asZgpsGroupList[j].u16Alias;
                    *pu8Data++ = (uint8)(psGpCustomDataStructure->asZgpsSinkTable[i].asZgpsGroupList[j].u16Alias >> 8);
                }
            }
            /* check if assigned address is present */
            if(b16Options & GP_SINK_TABLE_ASSIGNED_ADDR_MASK)
            {
                //2 byte GPD Assigned Alias
                *pu8Data++ = (uint8)psGpCustomDataStructure->asZgpsSinkTable[i].u16ZgpdAssignedAlias;
                *pu8Data++ = (uint8)(psGpCustomDataStructure->asZgpsSinkTable[i].u16ZgpdAssignedAlias >> 8);
            }
            //1 byte Radius
            *pu8Data++ = psGpCustomDataStructure->asZgpsSinkTable[i].u8GroupCastRadius;
            //if security options are available
            if(b16Options & GP_SINK_TABLE_SECURITY_USE_MASK)
            {
                //1 byte security options
                *pu8Data++ = psGpCustomDataStructure->asZgpsSinkTable[i].b8SecOptions;
            }
            /* check if sequence number capability or security is present*/
            if((b16Options & GP_SINK_TABLE_SEQ_NUM_CAP_MASK)||
                        (b16Options & GP_SINK_TABLE_SECURITY_USE_MASK))
            {
                //4 byte security frame counter
                uint32 u32Data = psGpCustomDataStructure->asZgpsSinkTable[i].u32ZgpdSecFrameCounter;
                *pu8Data++ = (uint8)u32Data;
                *pu8Data++ = (uint8)(u32Data >> 8);
                *pu8Data++ = (uint8)(u32Data >> 16);
                *pu8Data++ = (uint8)(u32Data >> 24);
            }
            //if security options are available
            if(b16Options & GP_SINK_TABLE_SECURITY_USE_MASK)
            {
                teGP_GreenPowerSecLevel    eSecLevel;
                teGP_GreenPowerSecKeyType  eSecKeyType;

                eSecLevel = psGpCustomDataStructure->asZgpsSinkTable[i].b8SecOptions & GP_SECURITY_LEVEL_MASK;
                eSecKeyType = (psGpCustomDataStructure->asZgpsSinkTable[i].b8SecOptions & GP_SECURITY_KEY_TYPE_MASK) >> 2;
                /* check if security key is available */
                if((eSecLevel != E_GP_NO_SECURITY)&&(eSecKeyType != E_GP_DERIVED_INDIVIDUAL_ZGPD_KEY))
                {
                    //16 byte security key
                    memcpy(pu8Data, psGpCustomDataStructure->asZgpsSinkTable[i].sZgpdKey.au8Key, E_ZCL_KEY_128_SIZE);
                    pu8Data +=  E_ZCL_KEY_128_SIZE;
                }
            }
        }
    }

    return (uint16)(pu8Data - pu8Start);
}
/****************************************************************************
 **
 ** NAME:       u16GP_ReadSinkTableString
 **
 ** DESCRIPTION:
 ** Read sink table from string from passed data pointer
 **
 ** PARAMETERS:                      Name                           Usage
 ** uint8                         u8GreenPowerEndPointId        Green Power Endpoint id
 ** uint8                         *pu8Data                      data pointer to read
 ** uint16                        u16StringSize                 String size
 **
 ** RETURN:
 ** uint16
 **
 ****************************************************************************/
PUBLIC uint16 u16GP_ReadSinkTableString(
                    uint8                                  u8GreenPowerEndPointId,
                    uint8                                  *pu8Data,
                    uint16                                 u16StringSize)
{
    tsZCL_EndPointDefinition                *psEndPointDefinition;
    tsZCL_ClusterInstance                   *psClusterInstance;
    tsGP_GreenPowerCustomData               *psGpCustomDataStructure;
    uint16                                  b16Options;
    uint8                                   i;
    uint8 *pu8Start;
    uint16 u16RemainingStringSize = u16StringSize;
    //find GP cluster
    if((eGP_FindGpCluster(  u8GreenPowerEndPointId,
                            TRUE,
                            &psEndPointDefinition,
                            &psClusterInstance,
                            &psGpCustomDataStructure)) != E_ZCL_SUCCESS)
    {
        return 0;
    }
    /* if there is no sink table entry in response */
    if(u16StringSize == 2)
    {
        return 2;
    }

    /* if string size is less than minimum size of sink table entry */
    if(u16StringSize < GP_SINK_TABLE_MINIMUM_LENGTH)
    {
        return 0;
    }

    for(i = 0; i< GP_NUMBER_OF_SINK_TABLE_ENTRIES; i++)
    {
        uint16 u16SinkEntryLength = 0;

        pu8Start = pu8Data;
        //2 byte options field
        b16Options = *pu8Data++;
        b16Options |= (*pu8Data++) << 8;

        /* calculate the length of sink table entry from option field */
        if((b16Options & GP_APPLICATION_ID_MASK) == GP_APPL_ID_8_BYTE)
        {
            u16SinkEntryLength = 8; //8 byte IEEE address
        }
        else
        {
            u16SinkEntryLength = 4; //4 byte source id
        }
        u16SinkEntryLength++; //1 byte device ID
        /* if communication mode is pre commissioned mode then group list is also present in sink table */
        if(((b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3) == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID)
        {
            uint8 u8GroupListEntries;

            if((u16RemainingStringSize - u16SinkEntryLength) < 1)
            {
                return 0;
            }
            u8GroupListEntries = *(pu8Data + u16SinkEntryLength);
            u16SinkEntryLength += 1/* 1 byte group list length */+ (4*u8GroupListEntries);
        }

        /* check if assigned address is available */
        if(b16Options & GP_SINK_TABLE_ASSIGNED_ADDR_MASK)
        {
            u16SinkEntryLength += 2;  //2 byte GPD Assigned Alias
        }

        u16SinkEntryLength++; //1 byte Radius
        //if security options are available
        if(b16Options & GP_SINK_TABLE_SECURITY_USE_MASK)
        {
            u16SinkEntryLength++; //1 byte security options
            u16SinkEntryLength += E_ZCL_KEY_128_SIZE;
        }
        /* check if sequence number capability or security is present*/
        if((b16Options & GP_SINK_TABLE_SEQ_NUM_CAP_MASK)||
                    (b16Options & GP_SINK_TABLE_SECURITY_USE_MASK))
        {
            u16SinkEntryLength += 4; //4 byte security frame counter
        }

        u16SinkEntryLength +=2; //2 byte options field

        if(u16RemainingStringSize < u16SinkEntryLength)
        {
            return 0;
        }

        psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asSinkTable[i].eGreenPowerSinkTablePriority = E_GP_SINK_TABLE_P_3;
        psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asSinkTable[i].b16Options = b16Options;

        if((b16Options & GP_APPLICATION_ID_MASK) == GP_APPL_ID_4_BYTE)
        {
            //4 byte GPD ID
            uint32 u32Val = *pu8Data++;
            u32Val |= (*pu8Data++) << 8;
            u32Val |= (*pu8Data++) << 16;
            u32Val |= (*pu8Data++) << 24;
            psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asSinkTable[i].uZgpdDeviceAddr.u32ZgpdSrcId = u32Val;
        }
#ifdef GP_IEEE_ADDR_SUPPORT
        else
        {
            //8 byte GPD ID
            uint64 u64Val = (uint32)*pu8Data++;
            u64Val |= (uint64)(*pu8Data++) << 8;
            u64Val |= (uint64)(*pu8Data++) << 16;
            u64Val |= (uint64)(*pu8Data++) << 24;
            u64Val |= (uint64)(*pu8Data++) << 32;
            u64Val |= (uint64)(*pu8Data++) << 40;
            u64Val |= (uint64)(*pu8Data++) << 48;
            u64Val |= (uint64)(*pu8Data++) << 56;
            psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asSinkTable[i].uZgpdDeviceAddr.u64ZgpdIEEEAddr = u64Val;
        }
#endif
        psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asSinkTable[i].eZgpdDeviceId = *pu8Data++;//1 byte Device ID

        /* if communication mode is pre commissioned mode then group list is also present in sink table */
        if(((b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3) == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID)
        {
            uint8 j;
            psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asSinkTable[i].u8ZgpsGroupListEntries = (*pu8Data++);//1 byte group list length

            for(j=0; j< psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asSinkTable[i].u8ZgpsGroupListEntries; j++)
            {
                if(j < GP_MAX_SINK_GROUP_LIST)
                {
                    //2 byte sink group field
                    psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asSinkTable[i].asZgpsGroupList[j].u16SinkGroup = *pu8Data++;
                    psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asSinkTable[i].asZgpsGroupList[j].u16SinkGroup |= (*pu8Data++) << 8;
                    //2 byte Alias field
                    psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asSinkTable[i].asZgpsGroupList[j].u16Alias = *pu8Data++;
                    psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asSinkTable[i].asZgpsGroupList[j].u16Alias |= (*pu8Data++) << 8;
                }
                else
                {
                    pu8Data += 4;
                }
            }
        }
        /* check if assigned address is available */
        if(b16Options & GP_SINK_TABLE_ASSIGNED_ADDR_MASK)
        {
            //2 byte GPD Assigned Alias
            psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asSinkTable[i].u16ZgpdAssignedAlias = *pu8Data++;
            psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asSinkTable[i].u16ZgpdAssignedAlias |= (*pu8Data++) << 8;
        }
        //1 byte Radius
        psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asSinkTable[i].u8GroupCastRadius = *pu8Data++;
        //if security options are available
        if(b16Options & GP_SINK_TABLE_SECURITY_USE_MASK)
        {
            //1 byte security options
            psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asSinkTable[i].b8SecOptions= *pu8Data++;
        }
        /* check if sequence number capability or security is present*/
        if((b16Options & GP_SINK_TABLE_SEQ_NUM_CAP_MASK)||
                    (b16Options & GP_SINK_TABLE_SECURITY_USE_MASK))
        {
            //4 byte security frame counter
            uint32 u32Val = *pu8Data++;
            u32Val |= (*pu8Data++) << 8;
            u32Val |= (*pu8Data++) << 16;
            u32Val |= (*pu8Data++) << 24;
            psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asSinkTable[i].u32ZgpdSecFrameCounter = u32Val;
        }
        //if security options are available
        if(b16Options & GP_SINK_TABLE_SECURITY_USE_MASK)
        {
            //teGP_GreenPowerSecLevel    eSecLevel;
            //teGP_GreenPowerSecKeyType  eSecKeyType;

            //eSecLevel = psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asSinkTable[i].b8SecOptions & GP_SECURITY_LEVEL_MASK;
            //eSecKeyType = (psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asSinkTable[i].b8SecOptions & GP_SECURITY_KEY_TYPE_MASK) >> 2;
            /* check if security key is available */
            //if((eSecLevel != E_GP_NO_SECURITY)&&(eSecKeyType != E_GP_DERIVED_INDIVIDUAL_ZGPD_KEY))
            {
                //16 byte security key
                memcpy(psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asSinkTable[i].sZgpdKey.au8Key, pu8Data, E_ZCL_KEY_128_SIZE);
                pu8Data +=  E_ZCL_KEY_128_SIZE;
            }
        }

        u16RemainingStringSize -= (uint16)(pu8Data - pu8Start);

        if(u16RemainingStringSize < GP_SINK_TABLE_MINIMUM_LENGTH)
        {
            break;
        }
    }

    return (uint16)(u16StringSize);
}
#endif
#ifdef GP_PROXY_DEVICE
/****************************************************************************
 **
 ** NAME:       bGP_IsProxyTableEntryPresent
 **
 ** DESCRIPTION:
 ** Finding entry in proxy table
 **
 ** PARAMETERS:                         Name                            Usage
 ** uint8                               u8GpEndPointId                  Endpoint Id
 ** uint8                               u8ApplicationId                 Application Id
 ** tuGP_ZgpdDeviceAddr                 *puZgpdAddress                  Pointer to GP device address
 ** teGP_GreenPowerProxyTableAction     eProxyTableAction               Get or Set the proxy table
 ** tsGP_ZgppProxyTable                 *psProxyTableEntry              Pointer to Proxy Table Entry
 **
 ** RETURN:
 ** bool_t
 **
 ****************************************************************************/
PUBLIC bool_t bGP_IsProxyTableEntryPresent(
                    uint8                                  u8GpEndPointId,
                    uint8                                  u8ApplicationId,
                    tuGP_ZgpdDeviceAddr                    *puZgpdAddress,
                    teGP_GreenPowerProxyTableAction        eProxyTableAction,
                    tsGP_ZgppProxyTable                    *psProxyTableEntry)
{
    tsZCL_EndPointDefinition                *psEndPointDefinition;
    tsZCL_ClusterInstance                   *psClusterInstance;
    tsGP_GreenPowerCustomData               *psGpCustomDataStructure;
    uint8				                   u8Status;
    uint8                                   i;
    bool_t                                  bZgpIdMatch = FALSE;


    /* Check pointers */
    if((puZgpdAddress == NULL)  ||
       (psProxyTableEntry == NULL))
    {
        return FALSE;
    }
   //find GP cluster
   if((u8Status = eGP_FindGpCluster(
            u8GpEndPointId,
            FALSE,
            &psEndPointDefinition,
            &psClusterInstance,
            &psGpCustomDataStructure)) != E_ZCL_SUCCESS)
    {
        return FALSE;
    }

   // get EP mutex
   #ifndef COOPERATIVE
        eZCL_GetMutex(psEndPointDefinition);
   #endif


    for(i = 0; i< GP_NUMBER_OF_PROXY_TABLE_ENTRIES; i++)
    {
        /* check if proxy table entry is not empty */
        if(psGpCustomDataStructure->asZgppProxyTable[i].bProxyTableEntryOccupied == TRUE)
        {

            //DBG_vPrintf(TRACE_GP_DEBUG, "E_GP_PROXY_TABLE_ENTRY_FOUND \n");
            //DBG_vPrintf(TRACE_GP_DEBUG, "Proxy Table Options: 0x%04x\n", psGpCustomDataStructure->asZgppProxyTable[i].b16Options);
            //DBG_vPrintf(TRACE_GP_DEBUG, "ZGPD Src Id: 0x%08x\n", psGpCustomDataStructure->asZgppProxyTable[i].uZgpdDeviceAddr.u32ZgpdSrcId);

            /* check if application id is same */
            if((uint8)(psGpCustomDataStructure->asZgppProxyTable[i].b16Options & GP_APPLICATION_ID_MASK) == u8ApplicationId)
            {
                if(u8ApplicationId == GP_APPL_ID_4_BYTE)
                {   /* check if GPD device address is same */
                    if(psGpCustomDataStructure->asZgppProxyTable[i].uZgpdDeviceAddr.u32ZgpdSrcId == puZgpdAddress->u32ZgpdSrcId)
                    {
                        bZgpIdMatch = TRUE;
                    }
                }
#ifdef GP_IEEE_ADDR_SUPPORT
                else
                {
                    if(psGpCustomDataStructure->asZgppProxyTable[i].uZgpdDeviceAddr.u64ZgpdIEEEAddr == puZgpdAddress->u64ZgpdIEEEAddr)
                    {
                        bZgpIdMatch = TRUE;
                    }
                }
#endif
                /* if proxy table entry is present */
                if(bZgpIdMatch)
                {   /* take action according to proxy table action parameter */
                    if((eProxyTableAction == E_GP_PROXY_TABLE_SET_ENTRY)||(eProxyTableAction == E_GP_PROXY_TABLE_UPDATE_ENTRY_ON_DATA_RECEIVE))
                    {
                        memcpy(&psGpCustomDataStructure->asZgppProxyTable[i],psProxyTableEntry,sizeof(tsGP_ZgppProxyTable));
                        if(E_GP_PROXY_TABLE_UPDATE_ENTRY_ON_DATA_RECEIVE != eProxyTableAction)
                        {
                        	vGP_CallbackForPersistData(E_GP_ADD_REMOVE_UPDATE_PROXY_TABLE);
                        }

                    }
                    else
                    {
                        memcpy(psProxyTableEntry,&psGpCustomDataStructure->asZgppProxyTable[i],sizeof(tsGP_ZgppProxyTable));
                    }

                    // release mutex
                    #ifndef COOPERATIVE
                        eZCL_ReleaseMutex(psEndPointDefinition);
                    #endif

                    return TRUE;
                }
            }
        }
    }

    // release mutex
    #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


    return FALSE;
}

/****************************************************************************
 **
 ** NAME:       eGP_AddProxyTableEntry
 **
 ** DESCRIPTION:
 ** Adding Entry to sink table
 **
 ** PARAMETERS:                         Name                            Usage
 ** uint8                               u8GreenPowerEndPointId          Endpoint Id
 ** tsGP_ZgpsSinkTable                  *psSinkTableEntry               Pointer to Sink Table
 **
 ** RETURN:
 ** teGP_GreenPowerStatus
 **
 ****************************************************************************/
PUBLIC teGP_GreenPowerStatus eGP_AddProxyTableEntry(
                    uint8                                  u8GreenPowerEndPointId,
                    tsGP_ZgppProxyTable                    *psProxyTableEntry)
{
    uint8                          i;
    tsZCL_EndPointDefinition       *psEndPointDefinition;
    tsZCL_ClusterInstance          *psClusterInstance;
    tsGP_GreenPowerCustomData      *psGpCustomDataStructure;
    uint8				            u8Status;

    /* Check pointers */
    if(psProxyTableEntry == NULL)
    {
        return E_ZCL_ERR_PARAMETER_NULL;
    }

    //find GP cluster
    if((u8Status = eGP_FindGpCluster(
            u8GreenPowerEndPointId,
            FALSE,
            &psEndPointDefinition,
            &psClusterInstance,
            &psGpCustomDataStructure)) != E_ZCL_SUCCESS)
    {
        return u8Status;
    }

    // get EP mutex
    #ifndef COOPERATIVE
        eZCL_GetMutex(psEndPointDefinition);
    #endif


    /* check if entry already exist for this ZGPD then update it with new values */
    if(bGP_IsProxyTableEntryPresent(u8GreenPowerEndPointId,
                                   (uint8)(psProxyTableEntry->b16Options & GP_APPLICATION_ID_MASK),
                                   &psProxyTableEntry->uZgpdDeviceAddr,
                                   E_GP_PROXY_TABLE_SET_ENTRY,
                                   psProxyTableEntry))
    {
        // release mutex
        #ifndef COOPERATIVE
            eZCL_ReleaseMutex(psEndPointDefinition);
        #endif


        return E_GP_PROXY_TABLE_SUCCESS;
    }

    for(i = 0; i< GP_NUMBER_OF_PROXY_TABLE_ENTRIES; i++)
    {
        /* check for empty entry */
        if(psGpCustomDataStructure->asZgppProxyTable[i].bProxyTableEntryOccupied == FALSE)
        {
            memcpy(&psGpCustomDataStructure->asZgppProxyTable[i], psProxyTableEntry, sizeof(tsGP_ZgppProxyTable));

            psGpCustomDataStructure->asZgppProxyTable[i].bProxyTableEntryOccupied = TRUE;
            vGP_CallbackForPersistData(E_GP_ADD_REMOVE_UPDATE_PROXY_TABLE);

            // release mutex
            #ifndef COOPERATIVE
                eZCL_ReleaseMutex(psEndPointDefinition);
            #endif


            return E_GP_PROXY_TABLE_SUCCESS;
        }
    }

    // release mutex
    #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


    return E_GP_NO_PROXY_TABLES;
}
/****************************************************************************
 **
 ** NAME:       eGP_RemoveProxyTableEntry
 **
 ** DESCRIPTION:
 ** Removing Entry from proxy table
 **
 ** PARAMETERS:                         Name                            Usage
 ** uint8                               u8GreenPowerEndPointId          Endpoint Id
 ** tsGP_ZgppProxyTable                  *psProxyTableEntry               Pointer to Sink Table
 **
 ** RETURN:
 ** teGP_GreenPowerStatus
 **
 ****************************************************************************/
PUBLIC teGP_GreenPowerStatus eGP_RemoveProxyTableEntry(
                    uint8                                  u8GreenPowerEndPointId,
                    tsGP_ZgppProxyTable                    *psProxyTableEntry)
{
    uint8                          i;
    tsZCL_EndPointDefinition       *psEndPointDefinition;
    tsZCL_ClusterInstance          *psClusterInstance;
    tsGP_GreenPowerCustomData      *psGpCustomDataStructure;
    uint8				            u8Status;
    uint8                          u8ApplicationId;
    bool_t                         bZgpIdMatch;

    /* Check pointers */
    if(psProxyTableEntry == NULL)
    {
        return E_ZCL_ERR_PARAMETER_NULL;
    }
    //find GP cluster
    if((u8Status = eGP_FindGpCluster(
            u8GreenPowerEndPointId,
            FALSE,
            &psEndPointDefinition,
            &psClusterInstance,
            &psGpCustomDataStructure)) != E_ZCL_SUCCESS)
    {
        return u8Status;
    }

    // get EP mutex
    #ifndef COOPERATIVE
        eZCL_GetMutex(psEndPointDefinition);
    #endif


    u8ApplicationId = (uint8)(psProxyTableEntry->b16Options & GP_APPLICATION_ID_MASK);
    //eCommunicationMode = (psProxyTableEntry->b16Options & GP_SINK_TABLE_COMM_MODE_MASK)  >> 3;

    for(i = 0; i< GP_NUMBER_OF_PROXY_TABLE_ENTRIES; i++)
    {   /* check if sink table entry is not empty */
        if(psGpCustomDataStructure->asZgppProxyTable[i].bProxyTableEntryOccupied == TRUE)
        {
            /* check if application id is same */
            if((uint8)(psGpCustomDataStructure->asZgppProxyTable[i].b16Options & GP_APPLICATION_ID_MASK) == u8ApplicationId)
            {
                if(u8ApplicationId == GP_APPL_ID_4_BYTE)
                {   /* check if GPD device address is same */
                    if(psGpCustomDataStructure->asZgppProxyTable[i].uZgpdDeviceAddr.u32ZgpdSrcId == psProxyTableEntry->uZgpdDeviceAddr.u32ZgpdSrcId)
                    {
                        bZgpIdMatch = TRUE;
                    }
                }
#ifdef GP_IEEE_ADDR_SUPPORT
                else
                {
                    if(psGpCustomDataStructure->asZgppProxyTable[i].uZgpdDeviceAddr.u64ZgpdIEEEAddr == psProxyTableEntry->uZgpdDeviceAddr.u64ZgpdIEEEAddr)
                    {
                        bZgpIdMatch = TRUE;
                    }
                }
#endif
                /* if sink table entry is present */
                if(bZgpIdMatch)
                {   /* remove sink table entry */
                    memset(&psGpCustomDataStructure->asZgppProxyTable[i],0,sizeof(tsGP_ZgppProxyTable));
                    vGP_CallbackForPersistData(E_GP_ADD_REMOVE_UPDATE_PROXY_TABLE);
                    // release mutex
                    #ifndef COOPERATIVE
                        eZCL_ReleaseMutex(psEndPointDefinition);
                    #endif

                    return E_GP_PROXY_TABLE_SUCCESS;
                }
            }
        }
    }
    // release mutex
    #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


    return E_GP_NO_PROXY_TABLES;
}

/****************************************************************************
 **
 ** NAME:       u16GP_GetStringSizeOfProxyTable
 **
 ** DESCRIPTION:
 ** Get Size of Proxy Table
 **
 ** PARAMETERS:                     Name                            Usage
 ** uint8                           u8GreenPowerEndPointId          End Point id
 **
 ** RETURN:
 ** uint16
 **
 ****************************************************************************/
PUBLIC uint16 u16GP_GetStringSizeOfProxyTable(uint8 u8GreenPowerEndPointId)
{
    tsZCL_EndPointDefinition                *psEndPointDefinition;
    tsZCL_ClusterInstance                   *psClusterInstance;
    tsGP_GreenPowerCustomData               *psGpCustomDataStructure;
    uint16                                  u16Length = 0, b16Options;
    uint8                                   i;

    //find GP cluster
    if((eGP_FindGpCluster(  u8GreenPowerEndPointId,
                            FALSE,
                            &psEndPointDefinition,
                            &psClusterInstance,
                            &psGpCustomDataStructure)) != E_ZCL_SUCCESS)
    {
        return 0;
    }

    for(i = 0; i< GP_NUMBER_OF_PROXY_TABLE_ENTRIES; i++)
    {
        /* check for entry */
        if(psGpCustomDataStructure->asZgppProxyTable[i].bProxyTableEntryOccupied == TRUE)
        {
            u16Length += 2; //2 byte options field
            b16Options = psGpCustomDataStructure->asZgppProxyTable[i].b16Options;

            if((b16Options & GP_APPLICATION_ID_MASK) == GP_APPL_ID_4_BYTE)
            {
                u16Length += 4; //4 byte GPD ID
            }
            else
            {
                u16Length += 8; //8 byte GPD ID
            }

            /* check if assigned address is present */
            if(b16Options & GP_PROXY_TABLE_ASSIGNED_ALIAS_MASK)
            {
                u16Length += 2; //2 byte GPD Assigned Alias
            }

            /* if communication mode is pre commissioned then take group list length also */
            if(b16Options & GP_PROXY_TABLE_COMMISSION_GROUP_GPS_MASK)
            {
                u16Length += (psGpCustomDataStructure->asZgppProxyTable[i].u8SinkGroupListEntries * 4) +1;
            }

            u16Length += 1; //1 byte Radius
            //if security options are available
            if(b16Options & GP_PROXY_TABLE_SECURITY_USE_MASK)
            {
                teGP_GreenPowerSecLevel    eSecLevel;
                teGP_GreenPowerSecKeyType  eSecKeyType;
                u16Length += 1; //1 byte security options
                eSecLevel = psGpCustomDataStructure->asZgppProxyTable[i].b8SecOptions & GP_SECURITY_LEVEL_MASK;
                eSecKeyType = (psGpCustomDataStructure->asZgppProxyTable[i].b8SecOptions & GP_SECURITY_KEY_TYPE_MASK) >> 2;
                //if security key is available
                if((eSecLevel != E_GP_NO_SECURITY)&&(eSecKeyType != E_GP_DERIVED_INDIVIDUAL_ZGPD_KEY))
                {
                    u16Length += 16; //16 byte security key
                }
            }
            /* check if sequence number capability or security is present*/
            if((b16Options & GP_PROXY_TABLE_SEQ_NUM_CAP_MASK)||
                        (b16Options & GP_PROXY_TABLE_SECURITY_USE_MASK))
            {
                u16Length += 4; //4 byte security frame counter
            }

            /* check if search counter is present*/
            if((!(b16Options & GP_PROXY_TABLE_ENTRY_ACTIVE_MASK))||
                        (!(b16Options & GP_PROXY_TABLE_ENTRY_VALID_MASK)))
            {
                u16Length += 1; //1 byte search counter
            }
        }
    }
    //return calculated length
    return u16Length;
}

/****************************************************************************
 **
 ** NAME:       u16GP_WriteProxyTableString
 **
 ** DESCRIPTION:
 ** Write proxy table as string into passed data pointer
 **
 ** PARAMETERS:                      Name                           Usage
 ** uint8                         u8GreenPowerEndPointId        Green Power Endpoint id
 ** uint8                         *pu8Data                      data pointer to write
 ** uint16                        u16StringSize                 String size
 **
 ** RETURN:
 ** uint16
 **
 ****************************************************************************/
PUBLIC uint16 u16GP_WriteProxyTableString(
                    uint8                                  u8GreenPowerEndPointId,
                    uint8                                  *pu8Data,
                    uint16                                 u16StringSize)
{
    tsZCL_EndPointDefinition                *psEndPointDefinition;
    tsZCL_ClusterInstance                   *psClusterInstance;
    tsGP_GreenPowerCustomData               *psGpCustomDataStructure;
    uint16                                  b16Options;
    uint8                                   i;
    uint8 *pu8Start = pu8Data;

    //find GP Cluster
    if((eGP_FindGpCluster(  u8GreenPowerEndPointId,
                            FALSE,
                            &psEndPointDefinition,
                            &psClusterInstance,
                            &psGpCustomDataStructure)) != E_ZCL_SUCCESS)
    {
        return 0;
    }
    /* write first 2 bytes as string length */
    *pu8Data++ = (uint8)u16StringSize;
    *pu8Data++ = (u16StringSize >> 8);

    for(i = 0; i< GP_NUMBER_OF_PROXY_TABLE_ENTRIES; i++)
    {
        /* check for entry */
        if(psGpCustomDataStructure->asZgppProxyTable[i].bProxyTableEntryOccupied == TRUE)
        {
            b16Options = psGpCustomDataStructure->asZgppProxyTable[i].b16Options;
            *pu8Data++ = (uint8)b16Options;//2 byte options field
            *pu8Data++ = (b16Options >> 8);

            if((b16Options & GP_APPLICATION_ID_MASK) == GP_APPL_ID_4_BYTE)
            {
                //4 byte GPD ID
                uint32 u32Data = psGpCustomDataStructure->asZgppProxyTable[i].uZgpdDeviceAddr.u32ZgpdSrcId;
                *pu8Data++ = (uint8)u32Data;
                *pu8Data++ = (uint8)(u32Data >> 8);
                *pu8Data++ = (uint8)(u32Data >> 16);
                *pu8Data++ = (uint8)(u32Data >> 24);
            }
#ifdef GP_IEEE_ADDR_SUPPORT
            else
            {
                uint64 u64Data = psGpCustomDataStructure->asZgppProxyTable[i].uZgpdDeviceAddr.u64ZgpdIEEEAddr;
                 //8 byte GPD ID
                *pu8Data++ = (uint8)(u64Data & 0xff);
                *pu8Data++ = (uint8)(u64Data >> 8);
                *pu8Data++ = (uint8)(u64Data >> 16);
                *pu8Data++ = (uint8)(u64Data >> 24);
                *pu8Data++ = (uint8)(u64Data >> 32);
                *pu8Data++ = (uint8)(u64Data >> 40);
                *pu8Data++ = (uint8)(u64Data >> 48);
                *pu8Data++ = (uint8)(u64Data >> 56);
            }
#endif
            /* check if assigned address is present */
            if(b16Options & GP_PROXY_TABLE_ASSIGNED_ALIAS_MASK)
            {
                uint16 u16AsignedAlias = psGpCustomDataStructure->asZgppProxyTable[i].u16ZgpdAssignedAlias;
                *pu8Data++ = (uint8)u16AsignedAlias;//2 byte asigned alias field
                *pu8Data++ = (u16AsignedAlias >> 8);
            }

            //if security options are available
            if(b16Options & GP_PROXY_TABLE_SECURITY_USE_MASK)
            {
                //1 byte security options
                *pu8Data++ = psGpCustomDataStructure->asZgppProxyTable[i].b8SecOptions;
            }

            /* check if sequence number capability or security is present*/
            if((b16Options & GP_PROXY_TABLE_SEQ_NUM_CAP_MASK)||
                        (b16Options & GP_PROXY_TABLE_SECURITY_USE_MASK))
            {
                //4 byte security frame counter
                uint32 u32Data = psGpCustomDataStructure->asZgppProxyTable[i].u32ZgpdSecFrameCounter;
                *pu8Data++ = (uint8)u32Data;
                *pu8Data++ = (uint8)(u32Data >> 8);
                *pu8Data++ = (uint8)(u32Data >> 16);
                *pu8Data++ = (uint8)(u32Data >> 24);
            }
            //if security options are available
            if(b16Options & GP_PROXY_TABLE_SECURITY_USE_MASK)
            {
                teGP_GreenPowerSecLevel    eSecLevel;
                teGP_GreenPowerSecKeyType  eSecKeyType;

                eSecLevel = psGpCustomDataStructure->asZgppProxyTable[i].b8SecOptions & GP_SECURITY_LEVEL_MASK;
                eSecKeyType = (psGpCustomDataStructure->asZgppProxyTable[i].b8SecOptions & GP_SECURITY_KEY_TYPE_MASK) >> 2;
                /* check if security key is available */
                if((eSecLevel != E_GP_NO_SECURITY)&&(eSecKeyType != E_GP_DERIVED_INDIVIDUAL_ZGPD_KEY))
                {
                    //16 byte security key
                    memcpy(pu8Data, psGpCustomDataStructure->asZgppProxyTable[i].sZgpdKey.au8Key, E_ZCL_KEY_128_SIZE);
                    pu8Data +=  E_ZCL_KEY_128_SIZE;
                }
            }
            /* if communication mode is pre commissioned then add group list also */
            if(b16Options & GP_PROXY_TABLE_COMMISSION_GROUP_GPS_MASK)
            {
                uint8 j;
                *pu8Data++ = psGpCustomDataStructure->asZgppProxyTable[i].u8SinkGroupListEntries;//1 byte group list length

                for(j=0; j< psGpCustomDataStructure->asZgppProxyTable[i].u8SinkGroupListEntries; j++)
                {
                    //2 byte sink group field
                    *pu8Data++ = (uint8)psGpCustomDataStructure->asZgppProxyTable[i].asSinkGroupList[j].u16SinkGroup;
                    *pu8Data++ = (uint8)(psGpCustomDataStructure->asZgppProxyTable[i].asSinkGroupList[j].u16SinkGroup >> 8);
                    //2 byte Alias field
                    *pu8Data++ = (uint8)psGpCustomDataStructure->asZgppProxyTable[i].asSinkGroupList[j].u16Alias;
                    *pu8Data++ = (uint8)(psGpCustomDataStructure->asZgppProxyTable[i].asSinkGroupList[j].u16Alias >> 8);
                }
            }

            //1 byte Radius
            *pu8Data++ = psGpCustomDataStructure->asZgppProxyTable[i].u8GroupCastRadius;
            /* check if search counter is present*/
            if((!(b16Options & GP_PROXY_TABLE_ENTRY_ACTIVE_MASK))||
                        (!(b16Options & GP_PROXY_TABLE_ENTRY_VALID_MASK)))
            {
                *pu8Data++ = psGpCustomDataStructure->asZgppProxyTable[i].u8SearchCounter;//1 byte search counter field
            }
        }
    }

    return (uint16)(pu8Data - pu8Start);
}
/****************************************************************************
 **
 ** NAME:       u16GP_ReadProxyTableString
 **
 ** DESCRIPTION:
 ** Read proxy table from string from passed data pointer
 **
 ** PARAMETERS:                      Name                           Usage
 ** uint8                         u8GreenPowerEndPointId        Green Power Endpoint id
 ** uint8                         *pu8Data                      data pointer to read
 ** uint16                        u16StringSize                 String size
 **
 ** RETURN:
 ** uint16
 **
 ****************************************************************************/
PUBLIC uint16 u16GP_ReadProxyTableString(
                    uint8                                  u8GreenPowerEndPointId,
                    uint8                                  *pu8Data,
                    uint16                                 u16StringSize)
{
    tsZCL_EndPointDefinition                *psEndPointDefinition;
    tsZCL_ClusterInstance                   *psClusterInstance;
    tsGP_GreenPowerCustomData               *psGpCustomDataStructure;
    uint16                                  b16Options;
    uint8                                   i;
    uint8 *pu8Start;
    uint16 u16RemainingStringSize = u16StringSize;
    //find GP cluster
    if((eGP_FindGpCluster(  u8GreenPowerEndPointId,
                            FALSE,
                            &psEndPointDefinition,
                            &psClusterInstance,
                            &psGpCustomDataStructure)) != E_ZCL_SUCCESS)
    {
        return 0;
    }
    /* if there is no proxy table entry in response */
    if(u16StringSize == 2)
    {
        return 2;
    }
    /* if string size is less than minimum size of proxy table entry */
    if(u16StringSize < GP_PROXY_TABLE_MINIMUM_LENGTH)
    {
        return 0;
    }

    for(i = 0; i< GP_NUMBER_OF_PROXY_TABLE_ENTRIES; i++)
    {
        uint16 u16ProxyEntryLength = 0;


        pu8Start = pu8Data;
        //2 byte options field
        b16Options = *pu8Data++;
        b16Options |= (*pu8Data++) << 8;

        /* calculate the length of proxy table entry from option field */
        if((b16Options & GP_APPLICATION_ID_MASK) == GP_APPL_ID_4_BYTE)
        {
            u16ProxyEntryLength = 8; //8 byte IEEE address
        }
        else
        {
            u16ProxyEntryLength = 4; //4 byte source id
        }

        /* check if assigned address is present */
        if(b16Options & GP_PROXY_TABLE_ASSIGNED_ALIAS_MASK)
        {
            u16ProxyEntryLength += 2;  //2 byte GPD Assigned Alias
        }

        //if security options are available
        if(b16Options & GP_PROXY_TABLE_SECURITY_USE_MASK)
        {
            u16ProxyEntryLength++; //1 byte security options
            u16ProxyEntryLength += E_ZCL_KEY_128_SIZE;
        }

        /* check if sequence number capability or security is present*/
        if((b16Options & GP_PROXY_TABLE_SEQ_NUM_CAP_MASK)||
                    (b16Options & GP_PROXY_TABLE_SECURITY_USE_MASK))
        {
            u16ProxyEntryLength += 4; //4 byte security frame counter
        }

        /* if communication mode is unicast mode then sink address list is also present in proxy table */
        if(b16Options & GP_PROXY_TABLE_UNICAST_GPS_MASK)
        {
            uint8 u8AddressListEntries;
            if(u16RemainingStringSize < (1 + u16ProxyEntryLength))
            {
                return 0;
            }
            u8AddressListEntries = *(pu8Data + u16ProxyEntryLength);
            u16ProxyEntryLength += 1/* 1 byte address list length */+ (10*u8AddressListEntries);
        }
        /* if communication mode is pre commissioned mode then group list is also present in proxy table */
        if(b16Options & GP_PROXY_TABLE_COMMISSION_GROUP_GPS_MASK)
        {
            uint8 u8GroupListEntries;

            if(u16RemainingStringSize < (1 + u16ProxyEntryLength))
            {
                return 0;
            }
            u8GroupListEntries = *(pu8Data + u16ProxyEntryLength);
            u16ProxyEntryLength += 1/* 1 byte group list length */+ (4*u8GroupListEntries);
        }

        u16ProxyEntryLength++; //1 byte Radius
        /* check if search counter is present*/
        if((!(b16Options & GP_PROXY_TABLE_ENTRY_ACTIVE_MASK))||
                    (!(b16Options & GP_PROXY_TABLE_ENTRY_VALID_MASK)))
        {
            u16ProxyEntryLength++;//1 byte search counter field
        }

        u16ProxyEntryLength +=2; //2 byte options field

        if(u16RemainingStringSize < u16ProxyEntryLength)
        {
            return 0;
        }

        psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asProxyTable[i].bProxyTableEntryOccupied = TRUE;
        psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asProxyTable[i].b16Options = b16Options;

        if((b16Options & GP_APPLICATION_ID_MASK) == GP_APPL_ID_4_BYTE)
        {
            //4 byte GPD ID
            uint32 u32Val = *pu8Data++;
            u32Val |= (*pu8Data++) << 8;
            u32Val |= (*pu8Data++) << 16;
            u32Val |= (*pu8Data++) << 24;
            psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asProxyTable[i].uZgpdDeviceAddr.u32ZgpdSrcId = u32Val;
        }
#ifdef GP_IEEE_ADDR_SUPPORT
        else
        {
            //8 byte GPD ID
            uint64 u64Val = (uint32)*pu8Data++;
            u64Val |= (uint64)(*pu8Data++) << 8;
            u64Val |= (uint64)(*pu8Data++) << 16;
            u64Val |= (uint64)(*pu8Data++) << 24;
            u64Val |= (uint64)(*pu8Data++) << 32;
            u64Val |= (uint64)(*pu8Data++) << 40;
            u64Val |= (uint64)(*pu8Data++) << 48;
            u64Val |= (uint64)(*pu8Data++) << 56;
            psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asProxyTable[i].uZgpdDeviceAddr.u64ZgpdIEEEAddr = u64Val;
        }
#endif
        /* check if assigned address is present */
        if(b16Options & GP_PROXY_TABLE_ASSIGNED_ALIAS_MASK)
        {
            //4 byte GPD ID
            uint16 u16Val = *pu8Data++;
            u16Val |= (*pu8Data++) << 8;
            psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asProxyTable[i].u16ZgpdAssignedAlias = u16Val;
        }

        //if security options are available
        if(b16Options & GP_PROXY_TABLE_SECURITY_USE_MASK)
        {
            //1 byte security options
            psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asProxyTable[i].b8SecOptions = *pu8Data++;
        }

        /* check if sequence number capability or security is present*/
        if((b16Options & GP_PROXY_TABLE_SEQ_NUM_CAP_MASK)||
                    (b16Options & GP_PROXY_TABLE_SECURITY_USE_MASK))
        {
            //4 byte security frame counter
            uint32 u32Val = *pu8Data++;
            u32Val |= (*pu8Data++) << 8;
            u32Val |= (*pu8Data++) << 16;
            u32Val |= (*pu8Data++) << 24;
            psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asProxyTable[i].u32ZgpdSecFrameCounter = u32Val;
        }
        //if security options are available
        if(b16Options & GP_PROXY_TABLE_SECURITY_USE_MASK)
        {
            //teGP_GreenPowerSecLevel    eSecLevel;
            //teGP_GreenPowerSecKeyType  eSecKeyType;

            //eSecLevel = psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asProxyTable[i].b8SecOptions & GP_SECURITY_LEVEL_MASK;
            //eSecKeyType = (psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asProxyTable[i].b8SecOptions & GP_SECURITY_KEY_TYPE_MASK) >> 2;
            /* check if security key is available */
            //if((eSecLevel != E_GP_NO_SECURITY)&&(eSecKeyType != E_GP_DERIVED_INDIVIDUAL_ZGPD_KEY))
            {
                //16 byte security key
                memcpy(psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asProxyTable[i].sZgpdKey.au8Key, pu8Data, E_ZCL_KEY_128_SIZE);
                pu8Data +=  E_ZCL_KEY_128_SIZE;
            }
        }

        /* if communication mode is unicast mode then sink address list is also present in proxy table */
        if(b16Options & GP_PROXY_TABLE_UNICAST_GPS_MASK)
        {
            uint8 u8SinkAddressListEntries;
            u8SinkAddressListEntries = (*pu8Data++);//1 byte address list length

            pu8Data += 10*u8SinkAddressListEntries; //increase the pointer by length of address list
        }

        /* if communication mode is pre commissioned mode then group list is also present in proxy table */
        if(b16Options & GP_PROXY_TABLE_COMMISSION_GROUP_GPS_MASK)
        {
            uint8 j;
            psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asProxyTable[i].u8SinkGroupListEntries = (*pu8Data++);//1 byte group list length

            for(j=0; j< psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asProxyTable[i].u8SinkGroupListEntries; j++)
            {
                if(j < GP_MAX_SINK_GROUP_LIST)
                {
                    //2 byte sink group field
                    psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asProxyTable[i].asSinkGroupList[j].u16SinkGroup = *pu8Data++;
                    psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asProxyTable[i].asSinkGroupList[j].u16SinkGroup |= (*pu8Data++) << 8;
                    //2 byte Alias field
                    psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asProxyTable[i].asSinkGroupList[j].u16Alias = *pu8Data++;
                    psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asProxyTable[i].asSinkGroupList[j].u16Alias |= (*pu8Data++) << 8;
                }
                else
                {
                    pu8Data += 4;
                }
            }
        }
        //1 byte Radius
        psGpCustomDataStructure->sRemoteTableAttr.uAttribute.asProxyTable[i].u8GroupCastRadius = *pu8Data++;

        /* check if search counter is present*/
        if((!(b16Options & GP_PROXY_TABLE_ENTRY_ACTIVE_MASK))||
                    (!(b16Options & GP_PROXY_TABLE_ENTRY_VALID_MASK)))
        {
            psGpCustomDataStructure->asZgppProxyTable[i].u8SearchCounter = *pu8Data++;//1 byte search counter field
        }

        u16RemainingStringSize -= (uint16)(pu8Data - pu8Start);

        if(u16RemainingStringSize < GP_PROXY_TABLE_MINIMUM_LENGTH)
        {
            break;
        }
    }

    return (uint16)(u16StringSize);
}
#endif
/****************************************************************************
 **
 ** NAME:       bGP_IsFreshPkt
 **
 ** DESCRIPTION:
 ** Checking for fresh packet
 **
 ** PARAMETERS:                    Name                           Usage
 ** uint8                       u8EndPointId                  Source endpoint id
 ** uint8                       u8ApplicationId               Application id
 ** tuGP_ZgpdDeviceAddr         *puZgpdAddress                address of GPD
 ** tsGP_GreenPowerCustomData   *psGpCustomDataStructure      custom data structure
 ** tsGP_ZgpsSinkTable          *psSinkTableEntry             sink table entry
 ** uint32                      u32SeqNoOrCounter             sequence number or frame counter
 ** RETURN:
 ** bool_t
 ****************************************************************************/
PUBLIC bool_t bGP_IsFreshPkt(
                    uint8                                  u8EndPointId,
                    uint8                                  u8ApplicationId,
                    tuGP_ZgpdDeviceAddr                    *puZgpdAddress,
                    tsGP_GreenPowerCustomData              *psGpCustomDataStructure,
#ifdef GP_PROXY_DEVICE
                    tsGP_ZgppProxyTable                    *psTableEntry,
#else
                    tsGP_ZgpsSinkTable                     *psTableEntry,
#endif
                    uint32                                 u32SeqNoOrCounter)
{

    uint8 u8Temp;
    /* check if GPD supports sequence number capability or security */
#ifdef GP_COMBO_MIN_DEVICE
    if((psTableEntry->b16Options & GP_SINK_TABLE_SEQ_NUM_CAP_MASK)||
            (psTableEntry->b16Options & GP_SINK_TABLE_SECURITY_USE_MASK))
#else
    if((psTableEntry->b16Options & GP_PROXY_TABLE_SEQ_NUM_CAP_MASK)||
                (psTableEntry->b16Options & GP_PROXY_TABLE_SECURITY_USE_MASK))
#endif
    {
#ifdef GP_COMBO_MIN_DEVICE
        if(psTableEntry->b16Options & GP_SINK_TABLE_SECURITY_USE_MASK)
#else
        if(psTableEntry->b16Options & GP_PROXY_TABLE_SECURITY_USE_MASK)
#endif
        {
            if((psTableEntry->b8SecOptions  & GP_SECURITY_LEVEL_MASK)== E_GP_ONE_LSB_FC_SHORT_MIC)
            {
                ZPS_tsZgpGpstEntry                          *psZgpGpstEntry;
                uint8                                       u8SecIndex;
                ZPS_tuZgpGreenPowerId                       uGPID;

                uGPID.u32SrcId = psTableEntry->uZgpdDeviceAddr.u32ZgpdSrcId;
#ifdef GP_IEEE_ADDR_SUPPORT
                uGPID.u64Address = psTableEntry->uZgpdDeviceAddr.u64ZgpdIEEEAddr;
#endif
                psZgpGpstEntry = ZPS_psZgpFindGpstEntry((uint32)u8ApplicationId, uGPID, &u8SecIndex);

                if(psZgpGpstEntry != NULL)
                    u32SeqNoOrCounter = psZgpGpstEntry->u32Counter;
            }
            if((u32SeqNoOrCounter == 0)&&(psTableEntry->u32ZgpdSecFrameCounter == 0))
            {
                return TRUE;
            }
            if(u32SeqNoOrCounter <= psTableEntry->u32ZgpdSecFrameCounter)
            {
                return FALSE;
            }
        }
        else
        {
        	if(psTableEntry->u32ZgpdSecFrameCounter != 0)
        	{
				u8Temp = (uint8)(u32SeqNoOrCounter - psTableEntry->u32ZgpdSecFrameCounter);

				if((u8Temp == 0)||(u8Temp >= 128 ))
				{
					return FALSE;
				}
        	}
        }
        /* updates the Security frame counter field of the Sink Table entry */
        psTableEntry->u32ZgpdSecFrameCounter = u32SeqNoOrCounter;
    }
    else
    {
        psTableEntry->u32ZgpdSecFrameCounter = u32SeqNoOrCounter;
    }

#ifdef GP_PROXY_DEVICE
    bGP_IsProxyTableEntryPresent(u8EndPointId,
                                 u8ApplicationId,
                                 puZgpdAddress,
                                 E_GP_PROXY_TABLE_UPDATE_ENTRY_ON_DATA_RECEIVE,
                                 psTableEntry);
#else
    bGP_IsSinkTableEntryPresent(u8EndPointId,
                                u8ApplicationId,
                                puZgpdAddress,
                                E_GP_SINK_TABLE_UPDATE_ENTRY_ON_DATA_RECEIVE,
                                psTableEntry,
                                (teGP_GreenPowerCommunicationMode)((psTableEntry->b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3));
#endif
    return TRUE;
}

/****************************************************************************
 **
 ** NAME:       eGp_BufferTransmissionPacket
 **
 ** DESCRIPTION:
 ** Buffer PDU Info for Delay Transmission
 **
 ** PARAMETERS:                                  Name                        Usage
 ** tsGP_ZgpDataIndication                  *psZgpDataIndication           pointer of Data indication structure
 ** teGP_GreenPowerBufferedCommands         eGreenPowerBufferedCommand     enum of command to buffer
 ** tsGP_GreenPowerCustomData               *psGreenPowerCustomData        Custom Data Structure
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC teZCL_Status eGp_BufferTransmissionPacket(
                    tsGP_ZgpDataIndication              *psZgpDataIndication,
                    teGP_GreenPowerBufferedCommands     eGreenPowerBufferedCommand,
                    tsGP_GreenPowerCustomData           *psGreenPowerCustomData)
{
    tsGP_ZgpBufferedApduRecord          *psZgpBufferedApduRecord;
    uint8                               u8Delay;
    static bool_t                       bIsSeedInit = FALSE;
    uint32                              u32Rand;

    /* If seed is not initialized then initialize it */
    if(bIsSeedInit == FALSE)
    {
#ifndef PC_PLATFORM_BUILD
        //srand(ZPS_u16AplZdoGetNwkAddr());
#endif
        bIsSeedInit = TRUE;
    }

    /* Generate random between 20-100 as minimum tick is 20ms */
    /**********************************************************/
    /*****Getting Random Number between two number ************/
    /***** int r = rand();*************************************/
    /* r = (r % 700) + 100;************************************/

    u32Rand = RND_u32GetRand(19,101);
    u8Delay = (uint8)(u32Rand / 20); /* gets ticks in multiple of 20 ms*/

    /* If remainder greater than 10 then plus one tick */
    if((u32Rand % 20) > 10)
    {
        u8Delay++;
    }

    /* if buffered command is loop back command then no need of random delay, using constant delay */
    if(E_GP_LOOP_BACK == eGreenPowerBufferedCommand)
    {
        u8Delay = 3;
    }
    else if(psZgpDataIndication->u8CommandId == E_GP_CHANNEL_REQUEST) /* Tunneling delay based on link quality */
    {
        u8Delay = u8GP_GetProxyDelay((uint8)psZgpDataIndication->u8LinkQuality);
    }
    else if(psZgpDataIndication->u8CommandId == E_GP_COMMISSIONING && psZgpDataIndication->bRxAfterTx) /* Tunneling delay based on link quality */
    {
        u8Delay = u8GP_GetProxyDelay((uint8)psZgpDataIndication->u8LinkQuality);
    }
    else if(eGreenPowerBufferedCommand == E_GP_PAIRING)
    {
    	 u8Delay = 3;
    }
    /* If GP device is ComboMin and GP Cmd is Channel Req/Commission, then delay should Dmax = 100 ms */
    /* Dmax is wait time for collecting GP channel req/commission commands from proxy devices to select TempMaster */
    if( psGreenPowerCustomData->eGreenPowerDeviceType == E_GP_ZGP_COMBO_MIN_DEVICE &&
        (psZgpDataIndication->u8CommandId == E_GP_CHANNEL_REQUEST || psZgpDataIndication->u8CommandId == E_GP_COMMISSIONING) &&
        eGreenPowerBufferedCommand == E_GP_RESPONSE )
    {
        u8Delay = 5;
    }

    if(eGreenPowerBufferedCommand == E_GP_PROXY_COMMISION)
    {
        u8Delay = 10;
    }
    /* Allocate buffer for Saving PDU */
    psZgpBufferedApduRecord = (tsGP_ZgpBufferedApduRecord *)psDLISTgetHead(&psGreenPowerCustomData->lGpDeAllocList);

    /* check allocated pointer */
    if(psZgpBufferedApduRecord)
    {
        /* Copy Buffered PDU info which will be used for scheduling transmission */
        psZgpBufferedApduRecord->sBufferedApduInfo.u8Delay = u8Delay;
        psZgpBufferedApduRecord->sBufferedApduInfo.eGreenPowerBufferedCommand = eGreenPowerBufferedCommand;
        psZgpBufferedApduRecord->sBufferedApduInfo.u8Status = psZgpDataIndication->u8Status;
        psZgpBufferedApduRecord->sBufferedApduInfo.u8CommandId = psZgpDataIndication->u8CommandId;
        psZgpBufferedApduRecord->sBufferedApduInfo.u8LinkQuality = psZgpDataIndication->u8LinkQuality;
        psZgpBufferedApduRecord->sBufferedApduInfo.u2SecurityKeyType = psZgpDataIndication->u2SecurityKeyType;
        psZgpBufferedApduRecord->sBufferedApduInfo.u2ApplicationId = psZgpDataIndication->u2ApplicationId;
        psZgpBufferedApduRecord->sBufferedApduInfo.u2SecurityLevel = psZgpDataIndication->u2SecurityLevel;
        psZgpBufferedApduRecord->sBufferedApduInfo.bAutoCommissioning = psZgpDataIndication->bAutoCommissioning;
        psZgpBufferedApduRecord->sBufferedApduInfo.bRxAfterTx = psZgpDataIndication->bRxAfterTx;
        psZgpBufferedApduRecord->sBufferedApduInfo.u32Mic = psZgpDataIndication->u32Mic;
        psZgpBufferedApduRecord->sBufferedApduInfo.u32SecFrameCounter = psZgpDataIndication->u32SecFrameCounter;
        psZgpBufferedApduRecord->sBufferedApduInfo.uZgpdDeviceAddr = psZgpDataIndication->uZgpdDeviceAddr;
        psZgpBufferedApduRecord->sBufferedApduInfo.u8PDUSize = psZgpDataIndication->u8PDUSize;
        psZgpBufferedApduRecord->sBufferedApduInfo.u8SeqNum = psZgpDataIndication->u8SeqNum;
        psZgpBufferedApduRecord->sBufferedApduInfo.u8TranslationIndex = psZgpDataIndication->u8TranslationIndex;
        psZgpBufferedApduRecord->sBufferedApduInfo.u16NwkShortAddr = psZgpDataIndication->u16NwkShortAddr;
        if(psZgpDataIndication->bTunneledPkt)
        {
            psZgpBufferedApduRecord->sBufferedApduInfo.i8ProxyDistance = psZgpDataIndication->i8ProxyDistance;
        }
        else
        {
            psZgpBufferedApduRecord->sBufferedApduInfo.i8ProxyDistance = i8GP_GetProxyDistance(
                                                                        (uint8)psZgpDataIndication->u8LinkQuality);
        }


        /* Copy Data only if pu8PDU != NULL */
        if(psZgpDataIndication->pu8Pdu != NULL)
        {
            /* Copy Payload */
            memcpy(psZgpBufferedApduRecord->sBufferedApduInfo.au8PDU, psZgpDataIndication->pu8Pdu, psZgpDataIndication->u8PDUSize);
        }

        /* Remove from the dealloc list */
        psDLISTremove(&psGreenPowerCustomData->lGpDeAllocList,
                (DNODE *)psZgpBufferedApduRecord);

        /* Add to the Alloc list as tail */
        vDLISTaddToTail(&psGreenPowerCustomData->lGpAllocList,
                            (DNODE *)psZgpBufferedApduRecord);
    }
    else
    {
        return E_ZCL_FAIL;

    }

    return E_ZCL_SUCCESS;
}

/****************************************************************************
 **
 ** NAME:       vGp_TransmissionTimerCallback
 **
 ** DESCRIPTION:
 ** Transmitting Buffered Packets for Broadcast
 **
 ** PARAMETERS:                         Name                            Usage
 ** uint8                           u8SrcEndPointId                 Source Endpoint Id
 ** tsZCL_EndPointDefinition        *psEndPointDefinition           End Point defintion
 ** tsGP_GreenPowerCustomData       *psGpCustomDataStructure         Custom Data Structure
 ** RETURN:
 ** void
 **
 ****************************************************************************/
PUBLIC void vGp_TransmissionTimerCallback(
                    uint8                                  u8SrcEndPointId,
                    tsZCL_EndPointDefinition               *psEndPointDefinition,
                    tsGP_GreenPowerCustomData              *psGpCustomDataStructure)
{

    tsGP_ZgpCommissioningNotificationCmdPayload sZgpCommissioningNotificationCmdPayload;
    tsGP_ZgpBufferedApduRecord                  *psZgpBufferedApduRecord;
    PDUM_thAPduInstance                         hAPduInst;
    ZPS_tsAplZdpDeviceAnnceReq                  sZdpDeviceAnnceReq;
#ifdef GP_COMBO_MIN_DEVICE
    tsGP_ZgpsSinkTable                          sZgpsSinkTable;
    bool                                        bIsSinkTableEntryPresent = FALSE;
#endif
#ifdef GP_PROXY_DEVICE
    tsGP_ZgppProxyTable                         sZgppProxyTable;
    bool_t                                      bIsProxyTableEntryPresent = FALSE;
#endif
    tsZCL_Address                               sDestinationAddress;
    teZCL_Status                                eStatus;
    uint8                                       u8TransactionSequenceNumber;
#ifdef GP_COMBO_MIN_DEVICE
    uint8 u8MatchedCmdIndex;
#endif
    uint8                                       u8SecLevel, u8SecKeyType = E_GP_NO_KEY;

    bool                                        bIsHeadNode = FALSE;

    /* Get Head Pointer of Alloc List */
    psZgpBufferedApduRecord = (tsGP_ZgpBufferedApduRecord *)psDLISTgetHead(&psGpCustomDataStructure->lGpAllocList);

    /* Check Pointer */
    while(psZgpBufferedApduRecord)
    {
        /* Decrement delay, transmit packet if delay reached zero */
        if(psZgpBufferedApduRecord->sBufferedApduInfo.u8Delay)
        {
            psZgpBufferedApduRecord->sBufferedApduInfo.u8Delay--;
        }

        if(psZgpBufferedApduRecord->sBufferedApduInfo.u8Delay == 0x00)
        {
            uint16 u16AliasShortAddr;
            uint8  u8AliasSeqNum;


            if(E_GP_LOOP_BACK == psZgpBufferedApduRecord->sBufferedApduInfo.eGreenPowerBufferedCommand)
            {
#ifdef GP_COMBO_MIN_DEVICE
                bool_t bZgpIdMatch = FALSE, bMatchSuccess = FALSE;
                uint8 i, u8ApplicationId = (uint8)psZgpBufferedApduRecord->sBufferedApduInfo.u2ApplicationId;
                /* Traverse translation table */
                for(i = psZgpBufferedApduRecord->sBufferedApduInfo.u8TranslationIndex; i < psGpCustomDataStructure->u8NoOfTranslationTableEntries; i++)
                {
                    /* check for translation pointer is populated or not */
                    if(psGpCustomDataStructure->psZgpsTranslationTableEntry[i].psGpToZclCmdInfo != NULL)
                    {
                        /* check application id type */
                        if((psGpCustomDataStructure->psZgpsTranslationTableEntry[i].b8Options & (uint8)GP_APPLICATION_ID_MASK) == u8ApplicationId)
                        {
                            /* Is application id type is 4 bytes source id */
                            if(u8ApplicationId == GP_APPL_ID_4_BYTE)
                            {
                                if(psGpCustomDataStructure->psZgpsTranslationTableEntry[i].uZgpdDeviceAddr.u32ZgpdSrcId == psZgpBufferedApduRecord->sBufferedApduInfo.uZgpdDeviceAddr.u32ZgpdSrcId)
                                {
                                    bZgpIdMatch = TRUE;
                                }
                            }
#ifdef GP_IEEE_ADDR_SUPPORT
                            else
                            {
                                if(psGpCustomDataStructure->psZgpsTranslationTableEntry[i].uZgpdDeviceAddr.u64ZgpdIEEEAddr == psZgpBufferedApduRecord->sBufferedApduInfo.uZgpdDeviceAddr.u64ZgpdIEEEAddr)
                                {
                                    bZgpIdMatch = TRUE;
                                }
                            }
#endif

                            /* Check entry found in translation table or not */
                            if(bZgpIdMatch)
                            {
                                bZgpIdMatch = FALSE;
                                /* checking for matched GP command id */
                                if(bIsCommandMapped((teGP_ZgpdCommandId)psZgpBufferedApduRecord->sBufferedApduInfo.u8CommandId,
								  &u8MatchedCmdIndex,
								  &psGpCustomDataStructure->psZgpsTranslationTableEntry[i]))
                              /*  if((psGpCustomDataStructure->psZgpsTranslationTableEntry[i].psGpToZclCmdInfo[u8MatchedCmdIndex].eZgpdCommandId == (teGP_ZgpdCommandId)psZgpBufferedApduRecord->sBufferedApduInfo.u8CommandId)&&
                                        (psGpCustomDataStructure->psZgpsTranslationTableEntry[i].psGpToZclCmdInfo[u8MatchedCmdIndex].u8EndpointId != 0xFD))*/
                                {

                                    bMatchSuccess = TRUE;
                                    /* translate ZGP Command into ZCL command and send it to linked endpoint */
                                    eGP_TranslateCommandIntoZcl(
                                            u8SrcEndPointId,
                                            i,
                                            u8MatchedCmdIndex,
                                            psGpCustomDataStructure,
                                            psZgpBufferedApduRecord->sBufferedApduInfo.u8PDUSize,
                                            psZgpBufferedApduRecord->sBufferedApduInfo.au8PDU);
                                }
                            }
                        }
                    }
                    psZgpBufferedApduRecord->sBufferedApduInfo.u8TranslationIndex++;
                    /* if ZCL packet is already pushed to stack then wait for some time to push next packet */
                    if(bMatchSuccess)
                    {
                        psZgpBufferedApduRecord->sBufferedApduInfo.u8Delay = 3;
                        break;
                    }
                }
#endif
            }
            else
            {
#ifdef GP_COMBO_MIN_DEVICE
                uint8              b8ZgpsCommModeAttr;
                // get EP mutex
                #ifndef COOPERATIVE
                    eZCL_GetMutex(psEndPointDefinition);
                #endif

                /* Get Green Power communication Mode attribute value */
                eZCL_ReadLocalAttributeValue(
                       u8SrcEndPointId,
                       GREENPOWER_CLUSTER_ID,
                       TRUE,
                       FALSE,
                       FALSE,
                       E_CLD_GP_ATTR_ZGPS_COMMUNICATION_MODE,
                       &b8ZgpsCommModeAttr);

                // release mutex
                #ifndef COOPERATIVE
                    eZCL_ReleaseMutex(psEndPointDefinition);
                #endif

                /* clear sink table */
                memset(&sZgpsSinkTable, 0, sizeof(tsGP_ZgpsSinkTable));

                bIsSinkTableEntryPresent = bGP_IsSinkTableEntryPresent(
                            u8SrcEndPointId,
                            (uint8)psZgpBufferedApduRecord->sBufferedApduInfo.u2ApplicationId,
                            &psZgpBufferedApduRecord->sBufferedApduInfo.uZgpdDeviceAddr,
                            E_GP_SINK_TABLE_GET_ENTRY,
                            &sZgpsSinkTable,
                            (teGP_GreenPowerCommunicationMode)b8ZgpsCommModeAttr);

                /* Check entry is there in sink table or not */
                if(bIsSinkTableEntryPresent&&
                        (sZgpsSinkTable.b16Options & GP_SINK_TABLE_ASSIGNED_ADDR_MASK))
                {
                    u16AliasShortAddr = sZgpsSinkTable.u16ZgpdAssignedAlias;
                }
                else
                {
                    u16AliasShortAddr = u16GP_DeriveAliasSrcAddr(
                            (uint8)psZgpBufferedApduRecord->sBufferedApduInfo.u2ApplicationId,
                            psZgpBufferedApduRecord->sBufferedApduInfo.uZgpdDeviceAddr);
                }
#endif
#ifdef GP_PROXY_DEVICE
                /* clear proxy table */
                memset(&sZgppProxyTable, 0, sizeof(tsGP_ZgppProxyTable));

                bIsProxyTableEntryPresent = bGP_IsProxyTableEntryPresent(
                            u8SrcEndPointId,
                            (uint8)psZgpBufferedApduRecord->sBufferedApduInfo.u2ApplicationId,
                            &psZgpBufferedApduRecord->sBufferedApduInfo.uZgpdDeviceAddr,
                            E_GP_PROXY_TABLE_GET_ENTRY,
                            &sZgppProxyTable);

                /* Check entry is there in proxy table or not */
                if(bIsProxyTableEntryPresent&&
                        (sZgppProxyTable.b16Options & GP_PROXY_TABLE_ASSIGNED_ALIAS_MASK))
                {
                    u16AliasShortAddr = sZgppProxyTable.u16ZgpdAssignedAlias;
                }
                else
                {
                    u16AliasShortAddr = u16GP_DeriveAliasSrcAddr(
                            (uint8)psZgpBufferedApduRecord->sBufferedApduInfo.u2ApplicationId,
                            psZgpBufferedApduRecord->sBufferedApduInfo.uZgpdDeviceAddr);
                }
#endif
                sDestinationAddress.eAddressMode = E_ZCL_AM_BROADCAST;
                sDestinationAddress.uAddress.eBroadcastMode = ZPS_E_APL_AF_BROADCAST_RX_ON;

                /* check command type */
                switch(psZgpBufferedApduRecord->sBufferedApduInfo.eGreenPowerBufferedCommand)
                {
#ifndef GP_DISABLE_COMMISSION_NOTIFICATION_CMD
                    case E_GP_COMMISSION_NOTIFICATION:
                    {
                        uint8 u8ZgpSecKeyType;

                        /* Derive alias sequence number */
                        u8AliasSeqNum = u8GP_DeriveAliasSeqNum(
                                psZgpBufferedApduRecord->sBufferedApduInfo.u8SeqNum,
                                 E_GP_ZGP_COMMOSSIONING_NOTIFICATION,0xFF);

                        /* Check Application Id */
                        if(psZgpBufferedApduRecord->sBufferedApduInfo.u2ApplicationId == GP_APPL_ID_4_BYTE)
                        {
                            sZgpCommissioningNotificationCmdPayload.uZgpdDeviceAddr.u32ZgpdSrcId =
                                psZgpBufferedApduRecord->sBufferedApduInfo.uZgpdDeviceAddr.u32ZgpdSrcId;
                        }
#ifdef GP_IEEE_ADDR_SUPPORT
                        else
                        {
                            sZgpCommissioningNotificationCmdPayload.uZgpdDeviceAddr.u64ZgpdIEEEAddr =
                                                        psZgpBufferedApduRecord->sBufferedApduInfo.uZgpdDeviceAddr.u64ZgpdIEEEAddr;
                        }
#endif
                        sZgpCommissioningNotificationCmdPayload.b16Options =
                                                        (uint16)psZgpBufferedApduRecord->sBufferedApduInfo.u2ApplicationId;

                        /* Security related */
                        if(psZgpBufferedApduRecord->sBufferedApduInfo.u8Status > E_GP_SEC_NO_SECURITY)
                        {
                            sZgpCommissioningNotificationCmdPayload.b16Options |= GP_CMSNG_NOTIFICATION_SEC_PROCESS_FAIL_MASK;
                            /* Set Security Level */
                            u8SecLevel = 0;
                            u8SecKeyType = E_GP_NO_KEY;
                        }
                        else
                        {
                            /* Set Security Level */
                            u8SecLevel = (uint8)psZgpBufferedApduRecord->sBufferedApduInfo.u2SecurityLevel;

                            /* Set Key type */
                            /* Check Key Type */
                            /* check Sec Status */
                            if(psZgpBufferedApduRecord->sBufferedApduInfo.u8Status == E_GP_SEC_SUCCESS)
                            {
#ifdef GP_COMBO_MIN_DEVICE
                                uint8              b8ZgpsCommModeAttr;
                                /* Get Green Power communication Mode attribute value */
                                eZCL_ReadLocalAttributeValue(u8SrcEndPointId,
                                                             GREENPOWER_CLUSTER_ID,
                                                             TRUE,
                                                             FALSE,
                                                             FALSE,
                                                             E_CLD_GP_ATTR_ZGPS_COMMUNICATION_MODE,
                                                             &b8ZgpsCommModeAttr);
                                /* Check entry present in the sink table or not */
                                /* clear sink table */
                                memset(&sZgpsSinkTable, 0, sizeof(tsGP_ZgpsSinkTable));

                                bIsSinkTableEntryPresent = bGP_IsSinkTableEntryPresent(
                                                                psEndPointDefinition->u8EndPointNumber,
                                                                (uint8)psZgpBufferedApduRecord->sBufferedApduInfo.u2ApplicationId,
                                                                &sZgpCommissioningNotificationCmdPayload.uZgpdDeviceAddr,
                                                                E_GP_SINK_TABLE_GET_ENTRY,
                                                                &sZgpsSinkTable,
                                                                (teGP_GreenPowerCommunicationMode)b8ZgpsCommModeAttr);

                                if(bIsSinkTableEntryPresent)
                                {
                                    u8SecKeyType = (sZgpsSinkTable.b8SecOptions & GP_SECURITY_KEY_TYPE_MASK) >> 2;
                                }
                                else
                                {
                                    /* Check default key type for sink device */
                                    /* Read Sec Key Type from the attribute */
                                    if(eZCL_ReadLocalAttributeValue(
                                            psEndPointDefinition->u8EndPointNumber,
                                            GREENPOWER_CLUSTER_ID,
                                            TRUE,
                                            FALSE,
                                            FALSE,
                                            E_CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY_TYPE,
                                            &u8ZgpSecKeyType) != E_ZCL_SUCCESS)
                                    {
                                        u8SecKeyType = E_GP_NO_KEY;
                                    }
                                    else
                                    {
                                        u8SecKeyType = u8ZgpSecKeyType;
                                    }
                                }
#endif
#ifdef GP_PROXY_DEVICE

                                /* Check entry present in the proxy table or not */
                                /* clear proxy table */
                                memset(&sZgppProxyTable, 0, sizeof(tsGP_ZgppProxyTable));

                                bIsProxyTableEntryPresent = bGP_IsProxyTableEntryPresent(
                                                                psEndPointDefinition->u8EndPointNumber,
                                                                (uint8)psZgpBufferedApduRecord->sBufferedApduInfo.u2ApplicationId,
                                                                &sZgpCommissioningNotificationCmdPayload.uZgpdDeviceAddr,
                                                                E_GP_PROXY_TABLE_GET_ENTRY,
                                                                &sZgppProxyTable);

                                if(bIsProxyTableEntryPresent)
                                {
                                    u8SecKeyType = (sZgppProxyTable.b8SecOptions & GP_SECURITY_KEY_TYPE_MASK) >> 2;
                                }
                                else
                                {
                                    /* Check default key type for proxy device */
                                    /* Read Sec Key Type from the attribute */
                                    if(eZCL_ReadLocalAttributeValue(
                                            psEndPointDefinition->u8EndPointNumber,
                                            GREENPOWER_CLUSTER_ID,
                                            FALSE,
                                            FALSE,
                                            FALSE,
                                            E_CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY_TYPE,
                                            &u8ZgpSecKeyType) != E_ZCL_SUCCESS)
                                    {
                                        u8SecKeyType = E_GP_NO_KEY;
                                    }
                                    else
                                    {
                                        u8SecKeyType = u8ZgpSecKeyType;
                                    }
                                }
#endif
                            }
                            else if(psZgpBufferedApduRecord->sBufferedApduInfo.u8Status == E_GP_SEC_NO_SECURITY)
                            {
                                u8SecKeyType = E_GP_NO_KEY;
                            }
                        }
                        sZgpCommissioningNotificationCmdPayload.b16Options |= (u8SecLevel << 4);
                        //u8SecKeyType = (uint8)psZgpBufferedApduRecord->sBufferedApduInfo.u2SecurityKeyType;
                        sZgpCommissioningNotificationCmdPayload.b16Options |= (u8SecKeyType << 6);

                        /* Set the command id */
                        sZgpCommissioningNotificationCmdPayload.eZgpdCmdId =
                            (teGP_ZgpdCommandId)psZgpBufferedApduRecord->sBufferedApduInfo.u8CommandId;

                        /* Set the Security Frame Counter */
                        sZgpCommissioningNotificationCmdPayload.u32ZgpdSecFrameCounter =
                            psZgpBufferedApduRecord->sBufferedApduInfo.u32SecFrameCounter;

                        if(sZgpCommissioningNotificationCmdPayload.b16Options & GP_CMSNG_NOTIFICATION_SEC_PROCESS_FAIL_MASK)
                        {
                            sZgpCommissioningNotificationCmdPayload.u32Mic = psZgpBufferedApduRecord->sBufferedApduInfo.u32Mic;
                        }

                        /* Copy payload */
                        sZgpCommissioningNotificationCmdPayload.sZgpdCommandPayload.u8Length =
                                                psZgpBufferedApduRecord->sBufferedApduInfo.u8PDUSize;
                        sZgpCommissioningNotificationCmdPayload.sZgpdCommandPayload.u8MaxLength =
                                                psZgpBufferedApduRecord->sBufferedApduInfo.u8PDUSize;
                        sZgpCommissioningNotificationCmdPayload.sZgpdCommandPayload.pu8Data =
                                                psZgpBufferedApduRecord->sBufferedApduInfo.au8PDU;

                        /* check cmd type
                         * Appoint temp master for channel request command */
                        if( (sZgpCommissioningNotificationCmdPayload.eZgpdCmdId == E_GP_CHANNEL_REQUEST) ||
                            (sZgpCommissioningNotificationCmdPayload.eZgpdCmdId == E_GP_COMMISSIONING &&
                                psZgpBufferedApduRecord->sBufferedApduInfo.bRxAfterTx) )
                        {
#ifndef PC_PLATFORM_BUILD
                            sZgpCommissioningNotificationCmdPayload.u16ZgppShortAddr = ZPS_u16AplZdoGetNwkAddr();
#endif
                            sZgpCommissioningNotificationCmdPayload.i8ZgppDistance = psZgpBufferedApduRecord->sBufferedApduInfo.i8ProxyDistance;

                            /* Set Temp Master field in option field */
                            sZgpCommissioningNotificationCmdPayload.b16Options |= (1 << 3);
                        }
                        else
                        {
                            ZPS_vAfSetZgpAlias(u16AliasShortAddr, u8AliasSeqNum);
                        }

                        eStatus = eGP_ZgpCommissioningNotificationSend(
                                            u8SrcEndPointId,
                                            ZCL_GP_PROXY_ENDPOINT_ID,
                                            &sDestinationAddress,
                                            &u8TransactionSequenceNumber,
                                            &sZgpCommissioningNotificationCmdPayload);
                        break;
                    }
#endif

#ifndef GP_DISABLE_ZGP_RESPONSE_CMD
#ifdef GP_COMBO_MIN_DEVICE
                    case E_GP_RESPONSE:
                    {
                        /* If device is combo min , Send GP Response frame to Proxy device or add to queue if device
                         * itself if temp master */
                        /* Combo Min has to wait upto Dmax ms  (100 ms) to collect the tunnel pkts from other and choose best one */
                        /* As combo min doing both proxy and sink wait upto Dmax ms */
                        /* Send the GP response to Proxy or add to queue for sending to GP based on temp master */
                        /* Check NWK Address of buffered PKT */
                        uint16 u16NwkAddr = 0;
                        uint8 au8GPCommissionReplyPayload[GP_MAX_COMMISSION_REPLY_PAYLOAD_LENGTH];
                        uint8 u8Payloadlength = 1, u8GPCommissionPayloadOptions;

#ifndef PC_PLATFORM_BUILD
                        u16NwkAddr = ZPS_u16AplZdoGetNwkAddr();
#endif
                        /* Send GP Response for Channel Configuration to the Proxy Device */
                        tsGP_ZgpResponseCmdPayload sZgpResponseCmdPayload;
                        uint8 u8TxChannel, u8TransmitChannel;

                        /* Populate the Response payload */
                        sZgpResponseCmdPayload.b8Options = (uint8)psZgpBufferedApduRecord->sBufferedApduInfo.u2ApplicationId;

                        /* Check Application Id */
                        if(psZgpBufferedApduRecord->sBufferedApduInfo.u2ApplicationId == GP_APPL_ID_4_BYTE)
                        {
                            sZgpResponseCmdPayload.uZgpdDeviceAddr.u32ZgpdSrcId =
                                psZgpBufferedApduRecord->sBufferedApduInfo.uZgpdDeviceAddr.u32ZgpdSrcId;
                        }
#ifdef GP_IEEE_ADDR_SUPPORT
                        else
                        {
                            sZgpResponseCmdPayload.uZgpdDeviceAddr.u64ZgpdIEEEAddr =
                                                        psZgpBufferedApduRecord->sBufferedApduInfo.uZgpdDeviceAddr.u64ZgpdIEEEAddr;
                        }
#endif

                        /* Get Current channel */
                        /* ZPS_u8AplZdoGetRadioChannel() API returns channel number from 11 - 26
                         * so subtract channel value by 11 */
#ifndef PC_PLATFORM_BUILD
                        u8TxChannel = ZPS_u8AplZdoGetRadioChannel() - 11; /* 0 - 11, 1 - 12, 15 - 26 */
#endif
                        sZgpResponseCmdPayload.u16TempMasterShortAddr = psZgpBufferedApduRecord->sBufferedApduInfo.u16NwkShortAddr;

                        /* check GP Cmd Id */
                        if(psZgpBufferedApduRecord->sBufferedApduInfo.u8CommandId == E_GP_CHANNEL_REQUEST)
                        {
                            /* broadcast to the proxy */
                            /* u8TransmitChannel is the channel on which Response GPDF will be sent */
                            u8TransmitChannel = (psZgpBufferedApduRecord->sBufferedApduInfo.au8PDU[0] & 0x0F);
                            sZgpResponseCmdPayload.b8TempMasterTxChannel = u8TransmitChannel;
                            sZgpResponseCmdPayload.eZgpdCmdId = E_GP_CHANNEL_CONFIGURATION;
                            sZgpResponseCmdPayload.sZgpdCommandPayload.u8Length = 1;
                            sZgpResponseCmdPayload.sZgpdCommandPayload.u8MaxLength = 1;
                            sZgpResponseCmdPayload.sZgpdCommandPayload.pu8Data = &u8TxChannel;
                        }
                        else
                        {


                            /* Set the payload to zero */
                            memset(au8GPCommissionReplyPayload, 0, GP_MAX_COMMISSION_REPLY_PAYLOAD_LENGTH);

                            u8GPCommissionPayloadOptions = psZgpBufferedApduRecord->sBufferedApduInfo.au8PDU[1];

                            sZgpResponseCmdPayload.b8TempMasterTxChannel = u8TxChannel;
                            sZgpResponseCmdPayload.eZgpdCmdId = E_GP_COMMISSIONING_REPLY;

                            /* check PAN ID request */
                            if(u8GPCommissionPayloadOptions & GP_COMM_CMD_PANID_REQ_MASK)
                            {
                                uint16 u16PanId = 0;

                                /* Set PANId present flag */
                                au8GPCommissionReplyPayload[0] = TRUE;
#ifndef PC_PLATFORM_BUILD
                                u16PanId = ZPS_u16AplZdoGetNetworkPanId();
#endif
                                /* Get Network Pan Id */
                                au8GPCommissionReplyPayload[1] = (uint8)u16PanId;
                                au8GPCommissionReplyPayload[2] = (uint8)(u16PanId >> 8);

                                u8Payloadlength += 2;
                            }

                            /* check Sec Level */
                            if(sZgpsSinkTable.b8SecOptions & GP_SECURITY_LEVEL_MASK)
                            {
                                /* Set Sec Level & Sec Key type */
                                au8GPCommissionReplyPayload[0] |= ((sZgpsSinkTable.b8SecOptions & GP_SECURITY_LEVEL_MASK) << 3);
                                //au8GPCommissionReplyPayload[0] |= ((sZgpsSinkTable.b8SecOptions & GP_SECURITY_KEY_TYPE_MASK) << 3);

                                /* Check ZGPD requested key from Commission Payload */
                                if(u8GPCommissionPayloadOptions & GP_COMM_CMD_ZGP_SEC_KEY_REQ_MASK)
                                {
                                    AESSW_Block_u                   uSecurityKey;
#ifdef CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY
                                    AESSW_Block_u                   uInKey;
#endif
                                    uint64                          u64Address = 0;
#ifdef CLD_GP_ATTR_ZGP_LINK_KEY
                                    AESSW_Block_u                   uNonce,uOutKey;
                                    uint32 u32MIC = 0, u32SrcId, u32Counter;
                                    uint8 u8Header[4];
                                    uint8 i;
#endif
#ifdef GP_IEEE_ADDR_SUPPORT
                                    u64Address = psZgpBufferedApduRecord->sBufferedApduInfo.uZgpdDeviceAddr.u64ZgpdIEEEAddr;
#endif
                                    au8GPCommissionReplyPayload[0] |= ((sZgpsSinkTable.b8SecOptions & GP_SECURITY_KEY_TYPE_MASK) << 3);
                                    au8GPCommissionReplyPayload[0] |= (1 << 1);
                                    u8SecKeyType = (sZgpsSinkTable.b8SecOptions & GP_SECURITY_KEY_TYPE_MASK) >> 2;
                                    /* Copy Key */

                                    if((u8SecKeyType == E_GP_ZGPD_GROUP_KEY)||(u8SecKeyType == E_GP_DERIVED_INDIVIDUAL_ZGPD_KEY))
                                    {
#ifdef CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY
                                       // get EP mutex
                                        #ifndef COOPERATIVE
                                            eZCL_GetMutex(psEndPointDefinition);
                                        #endif

                                        /* Get Green Power communication Mode attribute value */
                                        eZCL_ReadLocalAttributeValue(
                                                 psEndPointDefinition->u8EndPointNumber,
                                                 GREENPOWER_CLUSTER_ID,
                                                 TRUE,
                                                 FALSE,
                                                 FALSE,
                                                 E_CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY,
                                                 (uint8*)&uSecurityKey);

                                        // release mutex
                                        #ifndef COOPERATIVE
                                            eZCL_ReleaseMutex(psEndPointDefinition);
                                        #endif


                                        if(u8SecKeyType == E_GP_DERIVED_INDIVIDUAL_ZGPD_KEY)
                                        {
                                            uInKey = uSecurityKey;

                                            /* Get the derived individual key */
                                            ZPS_vZgpTransformKey(ZPS_E_ZGP_DERIVED_INDIVIDUAL_KEY,
                                                               (uint8)psZgpBufferedApduRecord->sBufferedApduInfo.u2ApplicationId,
                                                               psZgpBufferedApduRecord->sBufferedApduInfo.uZgpdDeviceAddr.u32ZgpdSrcId,
                                                               u64Address,
                                                               &uInKey,
                                                               &uSecurityKey);
                                        }
#else
                                        // fill in callback event structure
                                        eZCL_SetCustomCallBackEvent(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent,
                                                                      0, 0, psEndPointDefinition->u8EndPointNumber);
                                         /* Set Event Type */
                                        psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_SHARED_SECURITY_KEY_IS_NOT_ENABLED;
                                         /* Give a call back event to app */
                                        psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);
                                        eStatus = E_ZCL_FAIL;
                                        break;
#endif
                                    }
                                    else if(u8SecKeyType == E_GP_ZIGBEE_NWK_KEY)
                                    {
                                        /* Get the current network key */
                                        ZPS_vZgpTransformKey(ZPS_E_ZGP_ZIGBEE_NWK_KEY,
                                                             (uint8)psZgpBufferedApduRecord->sBufferedApduInfo.u2ApplicationId,
                                                             psZgpBufferedApduRecord->sBufferedApduInfo.uZgpdDeviceAddr.u32ZgpdSrcId,
                                                             u64Address,
                                                             NULL,
                                                             &uSecurityKey);

                                    }
                                    else if(u8SecKeyType == E_GP_NWK_KEY_DERIVED_ZGPD_GROUP_KEY)
                                    {
                                        /* Get the current network key */
//                                        ZPS_vZgpTransformKey(ZPS_E_ZGP_ZIGBEE_NWK_KEY,
//                                                             (uint8)psZgpBufferedApduRecord->sBufferedApduInfo.u2ApplicationId,
//                                                             psZgpBufferedApduRecord->sBufferedApduInfo.uZgpdDeviceAddr.u32ZgpdSrcId,
//                                                             u64Address,
//                                                             NULL,
//                                                             &uInKey);
                                        /* Get the network key - derived GPD group key */
                                        ZPS_vZgpTransformKey(ZPS_E_ZGP_NWK_KEY_DERIVED_GRP_KEY,
                                                             (uint8)psZgpBufferedApduRecord->sBufferedApduInfo.u2ApplicationId,
                                                             psZgpBufferedApduRecord->sBufferedApduInfo.uZgpdDeviceAddr.u32ZgpdSrcId,
                                                             u64Address,
                                                             NULL,
                                                             &uSecurityKey);
                                    }
                                    else if(u8SecKeyType == E_GP_OUT_OF_THE_BOX_ZGPD_KEY)
                                    {
                                        memcpy(uSecurityKey.au8, sZgpsSinkTable.sZgpdKey.au8Key, E_ZCL_KEY_128_SIZE);
                                    }
                                    else
                                    {
                                        DBG_vPrintf(TRACE_GP_DEBUG, "Invalid ZgpSecKeyType\n");
                                        eStatus = E_ZCL_FAIL;
                                        break;
                                    }

#ifdef CLD_GP_ATTR_ZGP_LINK_KEY
                                    /* check whether is GPD is capable of decrypting security key or not */
                                    if(psZgpBufferedApduRecord->sBufferedApduInfo.au8PDU[2] & GP_COMM_CMD_EXT_OPT_ZGPD_KEY_ENC_MASK)
                                    {
                                        /* Encryption of Key and Adding MIC */
                                        // get EP mutex
                                        #ifndef COOPERATIVE
                                            eZCL_GetMutex(psEndPointDefinition);
                                        #endif

                                        /* Get Green Power communication Mode attribute value */
                                        eZCL_ReadLocalAttributeValue(
                                                psEndPointDefinition->u8EndPointNumber,
                                                GREENPOWER_CLUSTER_ID,
                                                TRUE,
                                                FALSE,
                                                FALSE,
                                                E_CLD_GP_ATTR_ZGP_LINK_KEY,
                                                (uint8*)&uInKey);

                                        // release mutex
                                        #ifndef COOPERATIVE
                                            eZCL_ReleaseMutex(psEndPointDefinition);
                                        #endif


                                        au8GPCommissionReplyPayload[0] |= 0x04;

                                        if(psZgpBufferedApduRecord->sBufferedApduInfo.u2ApplicationId)
                                        {
                                            u32SrcId = (uint32)u64Address;
                                        }
                                        else
                                        {
                                            u32SrcId = psZgpBufferedApduRecord->sBufferedApduInfo.uZgpdDeviceAddr.u32ZgpdSrcId;
                                        }
#if 0
                                        if(psZgpBufferedApduRecord->sBufferedApduInfo.u2SecurityLevel == 0)
                                        {
                                            //u32Counter = psZgpBufferedApduRecord->sBufferedApduInfo.u8SeqNum + 1;

                                            u32Counter = (((uint32)(psZgpBufferedApduRecord->sBufferedApduInfo.au8PDU[6]) << 24) |
                                                          ((uint32)(psZgpBufferedApduRecord->sBufferedApduInfo.au8PDU[5]) << 16) |
                                                          ((uint32)(psZgpBufferedApduRecord->sBufferedApduInfo.au8PDU[4]) << 8)  |
                                                                   psZgpBufferedApduRecord->sBufferedApduInfo.au8PDU[3]);
                                            u32Counter++;
                                        }
                                        else
#endif
                                        {
                                            u32Counter = psZgpBufferedApduRecord->sBufferedApduInfo.u32SecFrameCounter + 1;
                                        }
                                        u8Header[0] = (uint8)u32SrcId;
                                        u8Header[1] = (uint8)(u32SrcId >> 8);
                                        u8Header[2] = (uint8)(u32SrcId >> 16);
                                        u8Header[3] = (uint8)(u32SrcId >> 24);

                                        if(psZgpBufferedApduRecord->sBufferedApduInfo.u2ApplicationId)
                                        {
                                            uNonce.au8[0] = (uint8)u64Address;
                                            uNonce.au8[1] = (uint8)(u64Address >> 8);
                                            uNonce.au8[2] = (uint8)(u64Address >> 16);
                                            uNonce.au8[3] = (uint8)(u64Address >> 24);
                                            uNonce.au8[4] = (uint8)(u64Address >> 32);
                                            uNonce.au8[5] = (uint8)(u64Address >> 40);
                                            uNonce.au8[6] = (uint8)(u64Address >> 48);
                                            uNonce.au8[7] = (uint8)(u64Address >> 56);
                                            uNonce.au8[12] = 0xC5;
                                        }
                                        else
                                        {
                                            memset(uNonce.au8,0,4);
                                            memcpy(&uNonce.au8[4],u8Header,4);
                                            uNonce.au8[12] = 0x05;
                                        }

                                        uNonce.au8[8] = (uint8)u32Counter;
                                        uNonce.au8[9] = (uint8)(u32Counter >> 8);
                                        uNonce.au8[10] = (uint8)(u32Counter >> 16);
                                        uNonce.au8[11] = (uint8)(u32Counter >> 24);

#ifndef PC_PLATFORM_BUILD
                                        AESSW_bCCMstar(&uInKey,
                                                       TRUE,
                                                       XCV_REG_AES_SET_MODE_CCM,
                                                       4,
                                                       4,
                                                       16,
                                                       &uNonce,
                                                       u8Header,
                                                       uSecurityKey.au8,
                                                       uOutKey.au8,
                                                       (uint8*)&u32MIC,
                                                       NULL);
#endif
                                        DBG_vPrintf(TRACE_GP_DEBUG, "\nEncrypted key:");
                                        for(i=0;i<AESSW_BLK_SIZE;i++)
                                            DBG_vPrintf(TRACE_GP_DEBUG, " 0x%x,", uOutKey.au8[i]);

                                        DBG_vPrintf(TRACE_GP_DEBUG, "\nMIC :0x%08x\r\n", u32MIC);

                                        uSecurityKey = uOutKey;
                                    }
#endif
                                    memcpy(&au8GPCommissionReplyPayload[u8Payloadlength],
                                           uSecurityKey.au8,
                                           E_ZCL_KEY_128_SIZE);

                                    u8Payloadlength += E_ZCL_KEY_128_SIZE;
#ifdef CLD_GP_ATTR_ZGP_LINK_KEY
                                    /* check whether is GPD is capable of decrypting security key or not */
                                    if(psZgpBufferedApduRecord->sBufferedApduInfo.au8PDU[2] & GP_COMM_CMD_EXT_OPT_ZGPD_KEY_ENC_MASK)
                                    {

                                        au8GPCommissionReplyPayload[u8Payloadlength++] = (uint8)(u32MIC >> 24);
                                        au8GPCommissionReplyPayload[u8Payloadlength++] = (uint8)(u32MIC >> 16);
                                        au8GPCommissionReplyPayload[u8Payloadlength++] = (uint8)(u32MIC >> 8);
                                        au8GPCommissionReplyPayload[u8Payloadlength++] = (uint8)(u32MIC);
                                        DBG_vPrintf(TRACE_GP_DEBUG, "\nMIC HERE  :0x%08x\r\n", u32MIC);
                                    }

                                    else
                                    {
                                    	 DBG_vPrintf(TRACE_GP_DEBUG, "\nMIC NOT ADDED = option = %d   condition = %d\r\n", psZgpBufferedApduRecord->sBufferedApduInfo.au8PDU[2],
                                    			 (psZgpBufferedApduRecord->sBufferedApduInfo.au8PDU[2] & GP_COMM_CMD_EXT_OPT_ZGPD_KEY_ENC_MASK));
                                    }
#endif
                                }
                            }

                            sZgpResponseCmdPayload.sZgpdCommandPayload.u8Length = u8Payloadlength;
                            sZgpResponseCmdPayload.sZgpdCommandPayload.u8MaxLength = u8Payloadlength;
                            sZgpResponseCmdPayload.sZgpdCommandPayload.pu8Data = au8GPCommissionReplyPayload;
                            psGpCustomDataStructure->bIsCommissionReplySent = TRUE;
                        }

                        if(u16NwkAddr == psZgpBufferedApduRecord->sBufferedApduInfo.u16NwkShortAddr)
                        {
                            /* Add to Tx Queue of Stack for sending GP channel configuration */
                            ZPS_tsZgpGreenPowerReq                      sZgpDataReq;
                            PDUM_thAPduInstance                         hAPduInst;
                            uint8                                       *pu8Start,i;
                            ZPS_teStatus                                eZPSStatus;
                            hAPduInst = hZCL_AllocateAPduInstance();
                            /* check buffer size */
                            if((hAPduInst == PDUM_INVALID_HANDLE)||
                               (PDUM_u16APduGetSize(hZCL_GetBufferPoolHandle()) < sZgpResponseCmdPayload.sZgpdCommandPayload.u8Length))
                            {
                                // free buffer and return
                                PDUM_eAPduFreeAPduInstance(hAPduInst);
                                break;
                            }
                            sZgpDataReq.bDataFrame = TRUE;
                            pu8Start = (uint8 *)(PDUM_pvAPduInstanceGetPayload(hAPduInst));

                            for(i = 0; i<sZgpResponseCmdPayload.sZgpdCommandPayload.u8Length;i++)
                            {
                                *pu8Start++ = sZgpResponseCmdPayload.sZgpdCommandPayload.pu8Data[i];
                            }
                            PDUM_eAPduInstanceSetPayloadSize(hAPduInst, sZgpResponseCmdPayload.sZgpdCommandPayload.u8Length);

                            sZgpDataReq.u8TxOptions = 0x01;
                            sZgpDataReq.u8ApplicationId = sZgpResponseCmdPayload.b8Options;
                            if(sZgpDataReq.u8ApplicationId == GP_APPL_ID_4_BYTE)
                            {
                                sZgpDataReq.uGpId.u32SrcId = sZgpResponseCmdPayload.uZgpdDeviceAddr.u32ZgpdSrcId;
                            }
#ifdef GP_IEEE_ADDR_SUPPORT
                            else
                            {
                                sZgpDataReq.uGpId.u64Address = sZgpResponseCmdPayload.uZgpdDeviceAddr.u64ZgpdIEEEAddr;
                            }
#endif
                            sZgpDataReq.u16TxQueueEntryLifetime = 5000; //5 sec
                            sZgpDataReq.u8Handle = u8GP_GetDataReqHandle(psGpCustomDataStructure);
                            sZgpDataReq.u8SeqNum = psZgpBufferedApduRecord->sBufferedApduInfo.u8SeqNum;
                            sZgpDataReq.u16Panid = 0xFFFF;
                            sZgpDataReq.u16DstAddr = 0xFFFF;
                            /* Add to Tx Queue of Stack for sending GP channel configuration */
                            if(sZgpResponseCmdPayload.eZgpdCmdId == E_GP_CHANNEL_CONFIGURATION)
                            {
                                psGpCustomDataStructure->u16TransmitChannelTimeout = 250; //5 sec timeout
#ifndef PC_PLATFORM_BUILD
                                psGpCustomDataStructure->u8OperationalChannel = ZPS_u8AplZdoGetRadioChannel();
                                ZPS_vNwkNibSetChannel( ZPS_pvAplZdoGetNwkHandle(), (sZgpResponseCmdPayload.b8TempMasterTxChannel & 0x0F) + 11);
#endif
                            }
                            else if(sZgpResponseCmdPayload.eZgpdCmdId == E_GP_COMMISSIONING_REPLY)
                            {
                                //sZgpDataReq.u16TxQueueEntryLifetime = psGpCustomDataStructure->u16CommissionWindow*20; //in miliseconds
                            }

                            /*if((psZgpBufferedApduRecord->sBufferedApduInfo.u2SecurityLevel == E_GP_FULL_FC_FULL_MIC)||
                               (psZgpBufferedApduRecord->sBufferedApduInfo.u2SecurityLevel == E_GP_ENC_FULL_FC_FULL_MIC))
                            {
                                ZPS_tsZgpGpstEntry                          *psZgpGpstEntry;
                                uint8                                       u8SecIndex;

                                psZgpGpstEntry = ZPS_psZgpFindGpstEntry((uint32)sZgpDataReq.u8ApplicationId, sZgpDataReq.uGpId, &u8SecIndex);

                                if(psZgpGpstEntry != NULL)
                                    psZgpGpstEntry->u32Counter = psZgpBufferedApduRecord->sBufferedApduInfo.u32SecFrameCounter;
                            }*/

                            if((sZgpResponseCmdPayload.eZgpdCmdId == E_GP_CHANNEL_CONFIGURATION)&&
                               (sZgpDataReq.uGpId.u32SrcId == 0)&&
                               (sZgpDataReq.u8ApplicationId == GP_APPL_ID_4_BYTE))
                            {
                                sZgpDataReq.bDataFrame = FALSE;
                            }

                            eZPSStatus = zps_vDStub_DataReq(&sZgpDataReq, hAPduInst,TRUE,(uint8)sZgpResponseCmdPayload.eZgpdCmdId);
                            DBG_vPrintf(TRACE_GP_DEBUG, "zps_vDStub_DataReq:%d\r\n", eZPSStatus);
                            // free buffer and return
                            PDUM_eAPduFreeAPduInstance(hAPduInst);
                        }
                        else
                        {
                            /* Send ZGP Response Pkt */
                            eStatus = eGP_ZgpResponseSend(
                                        u8SrcEndPointId,
                                        ZCL_GP_PROXY_ENDPOINT_ID,
                                        &sDestinationAddress,
                                        &u8TransactionSequenceNumber,
                                        &sZgpResponseCmdPayload);
                        }
                        break;
                    }
#endif
#endif
                    case E_GP_DEVICE_ANNOUNCE:
                    {
                        tsGP_ZgpsGroupList                  asGroupList[GP_MAX_SINK_GROUP_LIST];
                        uint8                               u8GroupListEntriesCount = 1,i;

                        memset(asGroupList,0xFF,GP_MAX_SINK_GROUP_LIST*sizeof(tsGP_ZgpsGroupList));

#ifdef GP_PROXY_DEVICE
                        if(sZgppProxyTable.b16Options & GP_PROXY_TABLE_COMMISSION_GROUP_GPS_MASK)
                        {
                            u8GroupListEntriesCount = sZgppProxyTable.u8SinkGroupListEntries;
                            memcpy(asGroupList,sZgppProxyTable.asSinkGroupList,u8GroupListEntriesCount*sizeof(tsGP_ZgpsGroupList));

                        }
#endif
#ifdef GP_COMBO_MIN_DEVICE
                        if(((sZgpsSinkTable.b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3) == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID)
                        {
                            u8GroupListEntriesCount = sZgpsSinkTable.u8ZgpsGroupListEntries;
                            memcpy(asGroupList,sZgpsSinkTable.asZgpsGroupList,u8GroupListEntriesCount*sizeof(tsGP_ZgpsGroupList));
                        }
#endif

                        for(i = 0; i < u8GroupListEntriesCount; i++)
                        {
                            if(asGroupList[i].u16Alias < 0xFFF8 )
                            {
                                u16AliasShortAddr = asGroupList[i].u16Alias;
                            }
                            else
                            {
#ifdef GP_COMBO_MIN_DEVICE
                                u16AliasShortAddr = u16GP_DeriveAliasSrcAddr(
                                                    (uint8)(sZgpsSinkTable.b16Options & GP_APPLICATION_ID_MASK),
                                                    sZgpsSinkTable.uZgpdDeviceAddr);
#endif

#ifdef GP_PROXY_DEVICE
                                u16AliasShortAddr = u16GP_DeriveAliasSrcAddr(
                                                    (uint8)(sZgppProxyTable.b16Options & GP_APPLICATION_ID_MASK),
                                                    sZgppProxyTable.uZgpdDeviceAddr);
#endif
                            }
                            sZdpDeviceAnnceReq.u16NwkAddr = u16AliasShortAddr;
                            sZdpDeviceAnnceReq.u64IeeeAddr = 0xFFFFFFFFFFFFFFFFULL;
                            sZdpDeviceAnnceReq.u8Capability = 0x00;

                            /* Populate device announce request */

                            /* allocate Apdu instance */
                            hAPduInst = hZCL_AllocateAPduInstance();

                            if(hAPduInst != NULL)
                            {
                                /* Before announcing call ZPS API */
                                ZPS_vAfZgpDeviceActive(u16AliasShortAddr);

                                ZPS_vAfSetZgpAlias(u16AliasShortAddr, 0x00);

                                if((eStatus = ZPS_eAplZdpDeviceAnnceRequest(
                                    hAPduInst,
                                    &u8TransactionSequenceNumber,
                                    &sZdpDeviceAnnceReq)) != E_ZCL_SUCCESS)
                                {
                                    /* Free hAPDU */
                                    PDUM_eAPduFreeAPduInstance(hAPduInst);
                                }
                            }
                        }

                        /* Save APS transaction seq number */
                        psGpCustomDataStructure->u8APSDeviceAnnounceSeqNum = u8TransactionSequenceNumber;
                        break;
                    }
#ifdef GP_COMBO_MIN_DEVICE
                    case E_GP_PAIRING:
                    {
                        /* broadcast GP Pairing command */
                        tsGP_ZgpPairingCmdPayload sZgpPairingCmdPayload;
                        uint8 u8CommunicationMode;

                        /* initializing pairing Command */
                        memset((uint8*)&sZgpPairingCmdPayload, 0, sizeof(tsGP_ZgpPairingCmdPayload));

                        sZgpPairingCmdPayload.b24Options = sZgpsSinkTable.b16Options & GP_SINK_TABLE_APP_ID_MASK;

                        if((sZgpsSinkTable.b16Options & GP_SINK_TABLE_APP_ID_MASK) == GP_APPL_ID_4_BYTE)
                        {
                            sZgpPairingCmdPayload.uZgpdDeviceAddr.u32ZgpdSrcId = sZgpsSinkTable.uZgpdDeviceAddr.u32ZgpdSrcId;
                        }
#ifdef GP_IEEE_ADDR_SUPPORT
                        else
                        {
                            sZgpPairingCmdPayload.uZgpdDeviceAddr.u64ZgpdIEEEAddr = sZgpsSinkTable.uZgpdDeviceAddr.u64ZgpdIEEEAddr;
                        }
#endif
                        /* Set Add Sink flag for this ZGPD */
                        sZgpPairingCmdPayload.b24Options |= GP_PAIRING_ADD_SINK_MASK;

                        /* Set Default Communication mode of the Sink  */
                        sZgpPairingCmdPayload.b24Options |= ((sZgpsSinkTable.b16Options & GP_SINK_TABLE_COMM_MODE_MASK) << 2);

                        /* Set ZGPD Fixed flag, if it is the auto commission packet, set fixed to 0 */
                        if(!psZgpBufferedApduRecord->sBufferedApduInfo.bAutoCommissioning)
                        {
                            sZgpPairingCmdPayload.b24Options |= (sZgpsSinkTable.b16Options & GP_SINK_TABLE_FIXED_LOCATION_MASK);

                            /* Set MAC Seq Cap Flag */
                            sZgpPairingCmdPayload.b24Options |=
                                (((sZgpsSinkTable.b16Options & GP_SINK_TABLE_SEQ_NUM_CAP_MASK) >> 5) << 8);
                        }
                        else
                        {
                            /* For Auto Comm Pkt, this flag always to be set 1 */
                            //sZgpPairingCmdPayload.b24Options |= (TRUE << 8);
                        }

                        /* Set Security Level */
                        sZgpPairingCmdPayload.b24Options |= ((sZgpsSinkTable.b8SecOptions & GP_SECURITY_LEVEL_MASK) << 9);
                        /* Set Sec Key type */
                        sZgpPairingCmdPayload.b24Options |= ((sZgpsSinkTable.b8SecOptions & GP_SECURITY_KEY_TYPE_MASK) << 9);

                        /* Set security frame counter flag */
                        sZgpPairingCmdPayload.b24Options |= GP_PAIRING_SECURITY_COUNTER_PRESENT_MASK;

                        /* check security level or MAC seq number Capable */
                        if( (sZgpsSinkTable.b8SecOptions & GP_SECURITY_LEVEL_MASK) ||
                            (sZgpsSinkTable.b16Options & GP_SINK_TABLE_SEQ_NUM_CAP_MASK) )
                        {
                            sZgpPairingCmdPayload.u32ZgpdSecFrameCounter = sZgpsSinkTable.u32ZgpdSecFrameCounter;
                        }
                        else
                        {
                            sZgpPairingCmdPayload.u32ZgpdSecFrameCounter = (uint32)0x00;
                        }

                        if(sZgpsSinkTable.b16Options & GP_SINK_TABLE_SECURITY_USE_MASK)
                        {
                            /* Set ZGPDKey present flag */
                            sZgpPairingCmdPayload.b24Options |=  GP_PAIRING_SECURITY_KEY_PRESENT_MASK;

                            /* Copy Key from Sink Table */
                            memcpy(sZgpPairingCmdPayload.sZgpdKey.au8Key, sZgpsSinkTable.sZgpdKey.au8Key, E_ZCL_KEY_128_SIZE);
                        }
                        /* Set Assigned allias flag based on sink table flag for this ZGPD */
                        if(sZgpsSinkTable.b16Options & GP_SINK_TABLE_ASSIGNED_ADDR_MASK)
                        {
                            sZgpPairingCmdPayload.b24Options |= GP_PAIRING_ASSIGNED_ALIAS_PRESENT_MASK;
                            sZgpPairingCmdPayload.u16AssignedAlias = sZgpsSinkTable.u16ZgpdAssignedAlias;
                        }

                        /* check communication mode */
                        u8CommunicationMode = (sZgpsSinkTable.b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3;

                        if(u8CommunicationMode == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_DGROUP_ID ||
                                u8CommunicationMode == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID)
                        {
                            /* Set Forward Radius flag */
                            sZgpPairingCmdPayload.b24Options |= GP_PAIRING_FORWARDING_RADIUS_PRESENT_MASK;
                            sZgpPairingCmdPayload.u8ForwardingRadius = sZgpsSinkTable.u8GroupCastRadius;

                            /* check communication mode */
                            if(u8CommunicationMode == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_DGROUP_ID)
                            {
                                sZgpPairingCmdPayload.u16SinkGroupID = u16GP_DeriveAliasSrcAddr(
                                                                        (uint8)(sZgpsSinkTable.b16Options & GP_SINK_TABLE_APP_ID_MASK),
                                                                        sZgpPairingCmdPayload.uZgpdDeviceAddr);
                            }
                            else
                            {
                                sZgpPairingCmdPayload.u16SinkGroupID = sZgpsSinkTable.asZgpsGroupList[0].u16SinkGroup;
                                sZgpPairingCmdPayload.u16AssignedAlias = sZgpsSinkTable.asZgpsGroupList[0].u16Alias;
                                sZgpPairingCmdPayload.b24Options |= GP_PAIRING_ASSIGNED_ALIAS_PRESENT_MASK;
                            }
                        }

                        /* Set ZGPD Device Id */
                        sZgpPairingCmdPayload.u8DeviceId = sZgpsSinkTable.eZgpdDeviceId;

                        if(u8CommunicationMode == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID)
                        {
                            uint8 i;
                            tsGP_ZgpPairingConfigCmdPayload sZgpPairingConfigPayload;
                            for(i = 0; i < sZgpsSinkTable.u8ZgpsGroupListEntries; i++)
                            {
                                sZgpPairingCmdPayload.u16SinkGroupID = sZgpsSinkTable.asZgpsGroupList[i].u16SinkGroup;
                                sZgpPairingCmdPayload.u16AssignedAlias = sZgpsSinkTable.asZgpsGroupList[i].u16Alias;
                                sZgpPairingCmdPayload.b24Options |= GP_PAIRING_ASSIGNED_ALIAS_PRESENT_MASK;
                                /* Send GP Pairing command as broadcast */
                                eGP_ZgpPairingSend(
                                         u8SrcEndPointId,
                                         ZCL_GP_PROXY_ENDPOINT_ID,
                                         &sDestinationAddress,
                                         &u8TransactionSequenceNumber,
                                         &sZgpPairingCmdPayload);
                            }

                            /* Send Pairing Configuration Command */
                            sZgpPairingConfigPayload.u8Actions = E_GP_PAIRING_CONFIG_EXTEND_SINK_TABLE_ENTRY;
                            sZgpPairingConfigPayload.b16Options = sZgpsSinkTable.b16Options;
                            sZgpPairingConfigPayload.u8ForwardingRadius = sZgpsSinkTable.u8GroupCastRadius;
                            sZgpPairingConfigPayload.u8NumberOfPairedEndpoints = 0xFE;

                            /* Check App Id */
                            if((sZgpsSinkTable.b16Options & GP_SINK_TABLE_APP_ID_MASK) == GP_APPL_ID_4_BYTE)
                            {
                                sZgpPairingConfigPayload.uZgpdDeviceAddr.u32ZgpdSrcId = sZgpsSinkTable.uZgpdDeviceAddr.u32ZgpdSrcId;
                            }
#ifdef GP_IEEE_ADDR_SUPPORT
                            else
                            {
                                sZgpPairingConfigPayload.uZgpdDeviceAddr.u64ZgpdIEEEAddr = sZgpsSinkTable.uZgpdDeviceAddr.u64ZgpdIEEEAddr;
                            }
#endif
                            sZgpPairingConfigPayload.eZgpdDeviceId = sZgpsSinkTable.eZgpdDeviceId;
                            sZgpPairingConfigPayload.u8ZgpsGroupListEntries = sZgpsSinkTable.u8ZgpsGroupListEntries;
                            sZgpPairingConfigPayload.u16ZgpdAssignedAlias = sZgpsSinkTable.u16ZgpdAssignedAlias;
                            sZgpPairingConfigPayload.b8SecOptions = sZgpsSinkTable.b8SecOptions;
                            sZgpPairingConfigPayload.u32ZgpdSecFrameCounter = sZgpsSinkTable.u32ZgpdSecFrameCounter;
                            sZgpPairingConfigPayload.sZgpdKey = sZgpsSinkTable.sZgpdKey;

                            for(i = 0; i < sZgpsSinkTable.u8ZgpsGroupListEntries; i++)
                            {
                                sZgpPairingConfigPayload.asZgpsGroupList[i].u16SinkGroup = sZgpsSinkTable.asZgpsGroupList[i].u16SinkGroup;
                                sZgpPairingConfigPayload.asZgpsGroupList[i].u16Alias = sZgpsSinkTable.asZgpsGroupList[i].u16Alias;
                            }

                            eGP_ZgpPairingConfigSend(
                                    u8SrcEndPointId,
                                    ZCL_GP_PROXY_ENDPOINT_ID,
                                    &sDestinationAddress,
                                    &u8TransactionSequenceNumber,
                                    &sZgpPairingConfigPayload);
                        }
                        else
                        {
                            /* Send GP Pairing command as broadcast */
                            eGP_ZgpPairingSend(
                                        u8SrcEndPointId,
                                        ZCL_GP_PROXY_ENDPOINT_ID,
                                        &sDestinationAddress,
                                        &u8TransactionSequenceNumber,
                                        &sZgpPairingCmdPayload);
                        }

                        break;
                    }
                    case E_GP_PROXY_COMMISION:
                    {
                        uint8 b8ZgpsCommExitModeAttr;

                        /* Get Green Power Exit Mode attribute value */
                        eZCL_ReadLocalAttributeValue(
                                u8SrcEndPointId,
                                GREENPOWER_CLUSTER_ID,
                                TRUE,
                                FALSE,
                                FALSE,
                                E_CLD_GP_ATTR_ZGPS_COMMISSIONING_EXIT_MODE,
                                &b8ZgpsCommExitModeAttr);

                        if(b8ZgpsCommExitModeAttr & GP_CMSNG_EXIT_MODE_ON_PAIRING_SUCCESS_MASK)
                        {
                            eZCL_SetCustomCallBackEvent(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent, 0, 0, u8SrcEndPointId);

                            psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_COMMISSION_MODE_EXIT;
							psGpCustomDataStructure->u16CommissionWindow = 0x00;

                            /* Change to device mode to operation mode */
                            psGpCustomDataStructure->eGreenPowerDeviceMode = E_GP_OPERATING_MODE;
                            /* Call End Point Call back to indicate exit commission mode */
                            psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);
#ifndef GP_DISABLE_PROXY_COMMISSION_MODE_CMD
                            /* send proxy commissioning mode command (exit) */
                            sDestinationAddress.eAddressMode = E_ZCL_AM_BROADCAST;
                            sDestinationAddress.uAddress.eBroadcastMode = ZPS_E_APL_AF_BROADCAST_RX_ON;
                            eGP_ProxyCommissioningMode(u8SrcEndPointId,
                                                        ZCL_GP_PROXY_ENDPOINT_ID,
                                                        sDestinationAddress,
                                                        E_GP_PROXY_COMMISSION_EXIT);
#endif
                        }
                    }
                    break;
#endif
                    default:
                        break;
                }
            }

            /* if it is a loop back command then remove from the allocated list only when it traversed for all translation table entry */
            if(((E_GP_LOOP_BACK == psZgpBufferedApduRecord->sBufferedApduInfo.eGreenPowerBufferedCommand)&&
              (psGpCustomDataStructure->u8NoOfTranslationTableEntries == psZgpBufferedApduRecord->sBufferedApduInfo.u8TranslationIndex))||
              (E_GP_LOOP_BACK != psZgpBufferedApduRecord->sBufferedApduInfo.eGreenPowerBufferedCommand))
            {
                tsGP_ZgpBufferedApduRecord *psTempZgpBufferedApduRecord =
                                                (tsGP_ZgpBufferedApduRecord *)psDLISTgetHead(&psGpCustomDataStructure->lGpAllocList);

                /* Check, removed node is head of the list? */
                if(psZgpBufferedApduRecord == psTempZgpBufferedApduRecord)
                {
                    bIsHeadNode = TRUE;
                }

                /* Before Transmission delete from alloc list and add to the dealloc list */
                psDLISTremove(&psGpCustomDataStructure->lGpAllocList,
                        (DNODE *)psZgpBufferedApduRecord);

                // add to free list
                vDLISTaddToTail(&psGpCustomDataStructure->lGpDeAllocList,
                        (DNODE *)psZgpBufferedApduRecord);
            }

            /* After device announce, everything should be sequential, buffer respective packets for broadcast transmission */
            if(psZgpBufferedApduRecord->sBufferedApduInfo.eGreenPowerBufferedCommand == E_GP_DEVICE_ANNOUNCE)
            {
                tsGP_ZgpDataIndication   sZgpDataIndication;
                uint8                    au8GPCmdpayload[GP_MAX_ZB_CMD_PAYLOAD_LENGTH];
                sZgpDataIndication.pu8Pdu = au8GPCmdpayload;

                /* copy from buffer data indication */
                //memcpy((uint8*)&sZgpDataIndication, (uint8*)&psZgpBufferedApduRecord->sBufferedApduInfo,
                //              sizeof(tsGP_ZgpDataIndication));
                sZgpDataIndication.u2ApplicationId = psZgpBufferedApduRecord->sBufferedApduInfo.u2ApplicationId;
                sZgpDataIndication.u8Status = psZgpBufferedApduRecord->sBufferedApduInfo.u8Status;
                sZgpDataIndication.uZgpdDeviceAddr = psZgpBufferedApduRecord->sBufferedApduInfo.uZgpdDeviceAddr;
                sZgpDataIndication.bAutoCommissioning = psZgpBufferedApduRecord->sBufferedApduInfo.bAutoCommissioning;
                /* Copy Payload */
                /*memcpy(sZgpDataIndication.pu8Pdu, psZgpBufferedApduRecord->sBufferedApduInfo.au8PDU,
                                                    psZgpBufferedApduRecord->sBufferedApduInfo.u8PDUSize);*/
                sZgpDataIndication.pu8Pdu = NULL; /* Pairing command transmitted using Sink Table information */

                /* Send Pairing Information as Broadcast, Buffer the packet as it is broadcast transmission */
                eGp_BufferTransmissionPacket(
                                    &sZgpDataIndication,
                                    E_GP_PAIRING,
                                    psGpCustomDataStructure);

            }
            else if(psZgpBufferedApduRecord->sBufferedApduInfo.eGreenPowerBufferedCommand == E_GP_PAIRING)
            {
                /* Only devices are in pairing mode, GP pairing commands would send Commission exit command*/
                /* So exit the commission mode and send exit mode command */
                tsGP_ZgpDataIndication   sZgpDataIndication;
                sZgpDataIndication.pu8Pdu = NULL; /* Pairing command transmitted using Sink Table information */

                  /* Send Pairing Information as Broadcast, Buffer the packet as it is broadcast transmission */
                eGp_BufferTransmissionPacket(
                                      &sZgpDataIndication,
                                      E_GP_PROXY_COMMISION,
                                      psGpCustomDataStructure);

            }
        }

        if(bIsHeadNode)
        {
            /* Get Head Pointer of Alloc List */
            psZgpBufferedApduRecord = (tsGP_ZgpBufferedApduRecord *)psDLISTgetHead(&psGpCustomDataStructure->lGpAllocList);
            bIsHeadNode = FALSE;
        }
        else
        {
            /* get the next pointer */
            psZgpBufferedApduRecord = (tsGP_ZgpBufferedApduRecord *)psDLISTgetNext((DNODE *)psZgpBufferedApduRecord);
        }
    }
}

/****************************************************************************
 **
 ** NAME:       i8GP_GetProxyDistance
 **
 ** DESCRIPTION:
 ** Calculation proxy distance based on link quality
 **
 ** PARAMETERS:                      Name                           Usage
 ** uint8                           u8LinkQuality                   Link Quality of received packet
 **
 ** RETURN:
 ** int8
 **
 ****************************************************************************/
PUBLIC int8 i8GP_GetProxyDistance(uint8 u8LinkQuality)
{
    /* Timer Tick Resolution is 20 ms and more tunneling delay means less link quality
     * Max delay is 100 ms. From table (A.3.6.3.1.2) 20ms - 1, 40 - 6, 60 - 12, 80 - 22, 100 - 60 */
    int8 i8Distance = 0;

    /* check Link Quality */
    if(u8LinkQuality <= 51)
    {
        i8Distance = 60;
    }
    else if(u8LinkQuality > 51 && u8LinkQuality <= 102)
    {
        i8Distance = 22;
    }
    else if(u8LinkQuality > 102 && u8LinkQuality <= 153)
    {
        i8Distance = 12;
    }
    else if(u8LinkQuality > 153 && u8LinkQuality <= 204)
    {
        i8Distance = 6;
    }
    else if(u8LinkQuality > 204)
    {
        i8Distance = 1;
    }

    return i8Distance;
}

/****************************************************************************
 **
 ** NAME:       u8GP_GetProxyDelay
 **
 ** DESCRIPTION:
 ** Calculation tunneling delay based on link quality
 **
 ** PARAMETERS:                      Name                           Usage
 ** uint8                           u8LinkQuality                   Link Quality of received packet
 **
 ** RETURN:
 ** int8
 **
 ****************************************************************************/
PUBLIC uint8 u8GP_GetProxyDelay(uint8 u8LinkQuality)
{
    /* Timer Tick Resolution is 20 ms and more tunneling delay means less link quality
     * Max delay is 100 ms. From table (A.3.6.3.1.2) 20ms - 1, 40 - 6, 60 - 12, 80 - 22, 100 - 60 */
    uint8 u8Delay = 0;

    /* check Link Quality */
    if(u8LinkQuality <= 51)
    {
        u8Delay = 5;
    }
    else if(u8LinkQuality > 51 && u8LinkQuality <= 102)
    {
        u8Delay = 4;
    }
    else if(u8LinkQuality > 102 && u8LinkQuality <= 153)
    {
        u8Delay = 3;
    }
    else if(u8LinkQuality > 153 && u8LinkQuality <= 204)
    {
        u8Delay = 2;
    }
    else if(u8LinkQuality > 204)
    {
        u8Delay = 1;
    }

    return u8Delay;
}
#ifdef GP_COMBO_MIN_DEVICE
/****************************************************************************
 **
 ** NAME:       bGP_IsZgpdCommandSupported
 **
 ** DESCRIPTION:
 ** check if ZGPD command is supported or not
 **
 ** PARAMETERS:                         Name                            Usage
    teGP_ZgpdCommandId           eZgpdCommandId                      Zgpd Command id
 ** RETURN:
 ** bool_t
 **
 ****************************************************************************/
PUBLIC bool_t bGP_IsZgpdCommandSupported(teGP_ZgpdCommandId   eZgpdCommandId, uint8 u8ZbCommandId, uint16 u16ClusterId)
{

    if((u8ZbCommandId == E_CLD_IDENTIFY_CMD_IDENTIFY)&&
       (u16ClusterId == GP_GENERAL_CLUSTER_ID_IDENTIFY))
    {
       return TRUE;
    }

   //case E_GP_OFF:
   //case E_GP_ON:
   //case E_GP_TOGGLE:
   //case E_GP_LEVEL_CONTROL_STOP:
    else if((((u8ZbCommandId == E_CLD_ONOFF_CMD_OFF)||
           (u8ZbCommandId == E_CLD_ONOFF_CMD_ON)||
           (u8ZbCommandId == E_CLD_ONOFF_CMD_TOGGLE))&&
           (u16ClusterId == GP_GENERAL_CLUSTER_ID_ONOFF))||
           ((u8ZbCommandId == E_CLD_LEVELCONTROL_CMD_STOP)&&
            (u16ClusterId == GP_GENERAL_CLUSTER_ID_LEVEL_CONTROL)))
    {
        return TRUE;
    }
    else
    {
        switch(eZgpdCommandId)
        {
            //case E_GP_IDENTIFY:
            //case E_GP_OFF:
            //case E_GP_ON:
            //case E_GP_TOGGLE:
            //case E_GP_LEVEL_CONTROL_STOP:
            case E_GP_MOVE_UP_WITH_ON_OFF:
            case E_GP_MOVE_DOWN_WITH_ON_OFF:
            case E_GP_STEP_UP_WITH_ON_OFF:
            case E_GP_STEP_DOWN_WITH_ON_OFF:
            case E_GP_COMMISSIONING:
            case E_GP_DECOMMISSIONING:
            case E_GP_SUCCESS:
            case E_GP_CHANNEL_REQUEST:
            case E_GP_COMMISSIONING_REPLY:
            case E_GP_CHANNEL_CONFIGURATION:
            case E_GP_ATTRIBUTE_REPORTING:
            case E_GP_SENSOR_COMMAND:
                return TRUE;
            default:
                return FALSE;
        }
    }
}

/****************************************************************************
 **
 ** NAME:       vGP_RemoveGPEPFromGroup
 **
 ** DESCRIPTION:
 ** Remove GPEP from group at APS level
 **
 ** PARAMETERS:                      Name                           Usage
 ** tsGP_GreenPowerCustomData      *psGpCustomDataStructure
 ** tsZCL_EndPointDefinition       *psEndPointDefinition
 ** tsGP_ZgpsSinkTable             *psSinkTableEntry
 **
 ** RETURN:
 ** none
 **
 ****************************************************************************/
PUBLIC void vGP_RemoveGPEPFromGroup(tsGP_GreenPowerCustomData   *psGpCustomDataStructure,
                                    tsZCL_EndPointDefinition    *psEndPointDefinition,
                                    tsGP_ZgpsSinkTable          *psSinkTableEntry)
{
    teZCL_Status   eStatus = E_ZCL_SUCCESS;

    if(((psSinkTableEntry->b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3) == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_DGROUP_ID)
    {
        /* remove from derived group Id */
        uint16  u16DerivedGroupId;
        u16DerivedGroupId = u16GP_DeriveAliasSrcAddr(
                                 (uint8)psSinkTableEntry->b16Options & GP_APPLICATION_ID_MASK,
                                 psSinkTableEntry->uZgpdDeviceAddr);

        eStatus = ZPS_eAplZdoGroupEndpointRemove(u16DerivedGroupId, ZCL_GP_PROXY_ENDPOINT_ID);
        /* Check Status */
        if(eStatus != E_ZCL_SUCCESS)
        {
            psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_REMOVING_GROUP_TABLE_FAIL;
            psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.uMessage.eRemoveGroupTableStatus = eStatus;
           /* Give Application Callback for group table remove failure */
            psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);
        }
    }
    else if(((psSinkTableEntry->b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3) == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID)
    {
        /* Find No. of pre-commissioned groups are presented in the list */
        uint8   u8Count;

        for(u8Count = 0; u8Count < psSinkTableEntry->u8ZgpsGroupListEntries; u8Count++)
        {
            eStatus = ZPS_eAplZdoGroupEndpointRemove(psSinkTableEntry->asZgpsGroupList[u8Count].u16SinkGroup, ZCL_GP_PROXY_ENDPOINT_ID);
            /* Check Status */
             if(eStatus != E_ZCL_SUCCESS)
             {
                 psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_REMOVING_GROUP_TABLE_FAIL;
                 psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.uMessage.eRemoveGroupTableStatus = eStatus;
                /* Give Application Callback for sink table update */
                 psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);
            }
        }
    }
}
/****************************************************************************
 **
 ** NAME:       vGP_AddGPEPToGroup
 **
 ** DESCRIPTION:
 ** Add GPEP to group at APS level
 **
 ** PARAMETERS:                      Name                           Usage
 ** tsGP_GreenPowerCustomData      *psGpCustomDataStructure
 ** tsZCL_EndPointDefinition       *psEndPointDefinition
 ** tsGP_ZgpsSinkTable             *psSinkTableEntry
 **
 ** RETURN:
 ** none
 **
 ****************************************************************************/
PUBLIC void vGP_AddGPEPToGroup(     tsGP_GreenPowerCustomData   *psGpCustomDataStructure,
                                    tsZCL_EndPointDefinition    *psEndPointDefinition,
                                    tsGP_ZgpsSinkTable          *psSinkTableEntry)
{
    teZCL_Status   eStatus = E_ZCL_SUCCESS;

    if(((psSinkTableEntry->b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3) == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_DGROUP_ID)
    {
        /* remove from derived group Id */
        uint16  u16DerivedGroupId;
        u16DerivedGroupId = u16GP_DeriveAliasSrcAddr(
                                 (uint8)psSinkTableEntry->b16Options & GP_APPLICATION_ID_MASK,
                                 psSinkTableEntry->uZgpdDeviceAddr);

        eStatus = ZPS_eAplZdoGroupEndpointAdd(u16DerivedGroupId, ZCL_GP_PROXY_ENDPOINT_ID);
        /* Check Status */
        if(eStatus != E_ZCL_SUCCESS)
        {
            psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_ADDING_GROUP_TABLE_FAIL;
            psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.uMessage.eAddGroupTableStatus = eStatus;
           /* Give Application Callback for group table remove failure */
            psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);
        }
    }
    else if(((psSinkTableEntry->b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3) == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID)
    {
        /* Find No. of pre-commissioned groups are presented in the list */
        uint8   u8Count;

        for(u8Count = 0; u8Count < psSinkTableEntry->u8ZgpsGroupListEntries; u8Count++)
        {
            eStatus = ZPS_eAplZdoGroupEndpointAdd(psSinkTableEntry->asZgpsGroupList[u8Count].u16SinkGroup, ZCL_GP_PROXY_ENDPOINT_ID);
            /* Check Status */
             if(eStatus != E_ZCL_SUCCESS)
             {
                 psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_ADDING_GROUP_TABLE_FAIL;
                 psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.uMessage.eAddGroupTableStatus = eStatus;
                /* Give Application Callback for sink table update */
                 psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);
            }
        }
    }
}

/****************************************************************************
 **
 ** NAME:       eGP_TranslateCommandIntoZcl
 **
 ** DESCRIPTION:
 ** Translate GPD command into ZCL command
 **
 ** PARAMETERS:                      Name                           Usage
 ** uint8                         u8MatchedIndex                Matched index of table
 ** tsGP_GreenPowerCustomData     *psGpCustomDataStructure      Custom data
 ** uint8                         u8GpdCommandPayloadLength     command length
 ** uint8                         *pu8GpdCommandPayload         GPD comamnd payload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PRIVATE teZCL_Status eGP_TranslateCommandIntoZcl(
                    uint8                                  u8GpEndPointId,
                    uint8                                  u8MatchedIndex,
                    uint8                                  u8MatchedCmdIndex,
                    tsGP_GreenPowerCustomData              *psGpCustomDataStructure,
                    uint8                                  u8GpdCommandPayloadLength,
                    uint8                                  *pu8GpdCommandPayload)
{
    uint8 u8TransactionNum, u8DstEndpoint;
    tsCLD_LevelControl_MoveCommandPayload sMoveCmdPayload = {0x00, 0xFF};
    tsCLD_LevelControl_StepCommandPayload sStepCmdPayload = {0x00, 0x00, 0xFFFF};
    tsZCL_Address   sDestinationAddress;
    teZCL_Status    eStatus;
    uint16          u16ClusterId;

    sDestinationAddress.eAddressMode = E_ZCL_AM_SHORT_NO_ACK;
#ifndef PC_PLATFORM_BUILD
    sDestinationAddress.uAddress.u16DestinationAddress = ZPS_u16AplZdoGetNwkAddr();
#endif
    /* if cluster id is 0xFFFF in translation table then take cluster id from ZGP command cluster table */
    if(psGpCustomDataStructure->psZgpsTranslationTableEntry[u8MatchedIndex].psGpToZclCmdInfo[u8MatchedCmdIndex].u16ZbClusterId == 0xFFFF)
    {
        u16ClusterId = u16GP_GetClusterId(psGpCustomDataStructure->psZgpsTranslationTableEntry[u8MatchedIndex].psGpToZclCmdInfo[u8MatchedCmdIndex].eZgpdCommandId);
    }
    else
    {
        u16ClusterId = psGpCustomDataStructure->psZgpsTranslationTableEntry[u8MatchedIndex].psGpToZclCmdInfo[u8MatchedCmdIndex].u16ZbClusterId;
    }

    u8DstEndpoint = psGpCustomDataStructure->psZgpsTranslationTableEntry[u8MatchedIndex].psGpToZclCmdInfo[u8MatchedCmdIndex].u8EndpointId;
    /* if endpoint id is 0xFE in translation table then use endpoint id 0xFF */
    if(0xFE == psGpCustomDataStructure->psZgpsTranslationTableEntry[u8MatchedIndex].psGpToZclCmdInfo[u8MatchedCmdIndex].u8EndpointId)
    {
        u8DstEndpoint = 0xFF;
    }

    if(u16ClusterId == 0xFFFF)
    {
        return E_ZCL_ERR_CLUSTER_NOT_FOUND;
    }


    //case E_GP_IDENTIFY:
    if((psGpCustomDataStructure->psZgpsTranslationTableEntry[u8MatchedIndex].psGpToZclCmdInfo[u8MatchedCmdIndex].u8ZbCommandId == E_CLD_IDENTIFY_CMD_IDENTIFY)&&
            (u16ClusterId == GP_GENERAL_CLUSTER_ID_IDENTIFY))
    {
        tsCLD_Identify_IdentifyRequestPayload sCmdPyld;
        sCmdPyld.u16IdentifyTime = 0x003C;
        /* push the Identify request command back into the Zigbee Pro stack as a
         * unicast transmit with destination address as self address */
        return eCLD_IdentifyCommandIdentifyRequestSend(ZCL_GP_PROXY_ENDPOINT_ID,
                                                       u8DstEndpoint,
                                                       &sDestinationAddress,
                                                       &u8TransactionNum,
                                                       &sCmdPyld);
    }
    //case E_GP_OFF:
    //case E_GP_ON:
    //case E_GP_TOGGLE:
    //case E_GP_LEVEL_CONTROL_STOP:
    else if((((psGpCustomDataStructure->psZgpsTranslationTableEntry[u8MatchedIndex].psGpToZclCmdInfo[u8MatchedCmdIndex].u8ZbCommandId == E_CLD_ONOFF_CMD_OFF)||
            (psGpCustomDataStructure->psZgpsTranslationTableEntry[u8MatchedIndex].psGpToZclCmdInfo[u8MatchedCmdIndex].u8ZbCommandId == E_CLD_ONOFF_CMD_ON)||
            (psGpCustomDataStructure->psZgpsTranslationTableEntry[u8MatchedIndex].psGpToZclCmdInfo[u8MatchedCmdIndex].u8ZbCommandId == E_CLD_ONOFF_CMD_TOGGLE))&&
            (u16ClusterId == GP_GENERAL_CLUSTER_ID_ONOFF))||
            ((psGpCustomDataStructure->psZgpsTranslationTableEntry[u8MatchedIndex].psGpToZclCmdInfo[u8MatchedCmdIndex].u8ZbCommandId == E_CLD_LEVELCONTROL_CMD_STOP)&&
                            (u16ClusterId == GP_GENERAL_CLUSTER_ID_LEVEL_CONTROL)))
    {
        /* push the translated command back into the Zigbee Pro stack as a
         * unicast transmit with destination address as self address */
        eStatus = eZCL_CustomCommandSend(ZCL_GP_PROXY_ENDPOINT_ID,
                                      u8DstEndpoint,
                                      &sDestinationAddress,
                                      u16ClusterId,
                                      FALSE,
                                      psGpCustomDataStructure->psZgpsTranslationTableEntry[u8MatchedIndex].psGpToZclCmdInfo[u8MatchedCmdIndex].u8ZbCommandId,
                                      &u8TransactionNum,
                                      0,
                                      FALSE,
                                      0,
                                      0);
    }
     //break;
    else
    {
        switch(psGpCustomDataStructure->psZgpsTranslationTableEntry[u8MatchedIndex].psGpToZclCmdInfo[u8MatchedCmdIndex].eZgpdCommandId)
        {
        case E_GP_MOVE_DOWN_WITH_ON_OFF:

            sMoveCmdPayload.u8MoveMode = 1;

        case E_GP_MOVE_UP_WITH_ON_OFF:
            /* if rate field is present in GPD command then copy it in Move command payload
             * other wise take default values */
            if(u8GpdCommandPayloadLength == 1)
            {
                sMoveCmdPayload.u8Rate = (uint8)*pu8GpdCommandPayload;
            }
            /* push the Move command back into the Zigbee Pro stack as a
             * unicast transmit with destination address as self address */
            eStatus = eCLD_LevelControlCommandMoveCommandSend(
                                ZCL_GP_PROXY_ENDPOINT_ID,
                                u8DstEndpoint,
                                &sDestinationAddress,
                                &u8TransactionNum,
                                TRUE,
                                &sMoveCmdPayload);
            break;
        case E_GP_STEP_DOWN_WITH_ON_OFF:

            sStepCmdPayload.u8StepMode = 1;

        case E_GP_STEP_UP_WITH_ON_OFF:
            /* if optional fields are present in GPD command then copy in step command payload */
            if(u8GpdCommandPayloadLength != 0)
            {
                sStepCmdPayload.u8StepSize = (uint8)*pu8GpdCommandPayload++;
                /* if transition time is present in GPD command then  copy it in step command payload */
                if(u8GpdCommandPayloadLength == 3)
                {
                    //2 byte transition time field
                    sStepCmdPayload.u16TransitionTime = *pu8GpdCommandPayload++;
                    sStepCmdPayload.u16TransitionTime |= (*pu8GpdCommandPayload++) << 8;
                }
            }
            /* push the step command back into the Zigbee Pro stack as a
             * unicast transmit with destination address as self address */
            eStatus = eCLD_LevelControlCommandStepCommandSend(
                                ZCL_GP_PROXY_ENDPOINT_ID,
                                u8DstEndpoint,
                                &sDestinationAddress,
                                &u8TransactionNum,
                                TRUE,
                                &sStepCmdPayload);
            break;

        case E_GP_ATTRIBUTE_REPORTING:
        case E_GP_SENSOR_COMMAND:
            /* if payload length is not 0 of command payload */
            if(u8GpdCommandPayloadLength != 0)
            {
            	tsGP_ZgpsAttributeReportingCmdRcvd sZgpsAttributeReportingCmdRcvd;
                //2 byte transition time field
                u16ClusterId = *pu8GpdCommandPayload++;
                u16ClusterId |= (*pu8GpdCommandPayload++) << 8;
                if(u16ClusterId != GP_GENERAL_CLUSTER_ID_TEMP_MEASUREMENT)
                {
                    eStatus = E_ZCL_FAIL;
                }
                else
                {
                    tsZCL_EndPointDefinition        *psEndPointDefinition;
                    tsZCL_ClusterInstance           *psClusterInstance;
                    tsGP_GreenPowerCustomData       *psGpCustomDataStructure;
                    //find GP cluster
                    if((eStatus = eGP_FindGpCluster(
                             u8GpEndPointId,
                             TRUE,
                             &psEndPointDefinition,
                             &psClusterInstance,
                             &psGpCustomDataStructure)) != E_ZCL_SUCCESS)
                     {
                         return E_ZCL_FAIL;
                     }
                     else
                     {
                         // get EP mutex
                         #ifndef COOPERATIVE
                            eZCL_GetMutex(psEndPointDefinition);
                         #endif

                         /* Call end point callback event for application to store attribute data in flash */
                         /* Set Event Type */
                         psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_ZGPD_ATTR_REPORTING_COMMAND_RCVD;
                         sZgpsAttributeReportingCmdRcvd.u16ClusterID = u16ClusterId;
                         sZgpsAttributeReportingCmdRcvd.u8GpdCommandPayloadLength = u8GpdCommandPayloadLength;
                         sZgpsAttributeReportingCmdRcvd.pu8GpdCommandPayload = pu8GpdCommandPayload;
                         psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.uMessage.psZgpsAttrReportingCmdRcvd =
                        		 &sZgpsAttributeReportingCmdRcvd;
                         psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);
                         // release mutex
                         #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif

                     }
                }
            }
            else
            {
                eStatus = E_ZCL_FAIL;
            }
            break;

        default:
            eStatus = E_ZCL_FAIL;
        }
    }

    return eStatus;
}

/****************************************************************************
 **
 ** NAME:       u16GP_GetClusterId
 **
 ** DESCRIPTION:
 ** Return back cluster id based on GPD command id
 **
 ** PARAMETERS:                         Name                            Usage
    teGP_ZgpdCommandId           eZgpdCommandId                      Zgpd Command id
 ** RETURN:
 ** uint16
 **
 ****************************************************************************/
PUBLIC uint16 u16GP_GetClusterId(teGP_ZgpdCommandId   eZgpdCommandId)
{
    uint8 i = 0;
    /* search ZGP command cluster table for ZGPD command id */
    while(asZgpCommadClusterTable[i].eZgpdCommandId != E_GP_ZGPD_CMD_ID_ENUM_END)
    {
        /* if ZGPD command id is present then return linked cluster id */
        if(asZgpCommadClusterTable[i].eZgpdCommandId == eZgpdCommandId)
        {
            return(asZgpCommadClusterTable[i].u16ClusterId);
        }
        i++;
    }
    /* if ZGPD command id is not present in ZGP command cluster table return invalid cluster id */
    return 0xFFFF;
}
/****************************************************************************
 **
 ** NAME:       eGP_BufferLoopBackPacket
 **
 ** DESCRIPTION:
 ** buffer loopback packet if there is need to push same packet multiple times
 **
 ** PARAMETERS:                         Name                            Usage
 ** tsZCL_EndPointDefinition      *psEndPointDefinition          Endpoint definition
 ** tsGP_GreenPowerCustomData     *psGpCustomDataStructure       Custom data
 ** uint8                         u8TranslationIndex             translation table index
 ** uint8                         u8ApplicationId                Application ID
 ** tuGP_ZgpdDeviceAddr           *puZgpdAddress                 ZGP device address
 ** teGP_ZgpdCommandId            eZgpdCommandId                 command id
 ** uint8                         u8GpdCommandPayloadLength      GPD command length
 ** uint8                         *pu8GpdCommandPayload          GPD command payload
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PRIVATE teZCL_Status eGP_BufferLoopBackPacket(
                    tsZCL_EndPointDefinition               *psEndPointDefinition,
                    tsGP_GreenPowerCustomData              *psGpCustomDataStructure,
                    uint8                                  u8TranslationIndex,
                    uint8                                  u8ApplicationId,
                    tuGP_ZgpdDeviceAddr                    *puZgpdAddress,
                    teGP_ZgpdCommandId                     eZgpdCommandId,
                    uint8                                  u8GpdCommandPayloadLength,
                    uint8                                  *pu8GpdCommandPayload)
{

    tsGP_ZgpDataIndication                          sZgpDataIndication = {0};
     //uint8                                          au8Pdu[GP_MAX_ZB_CMD_PAYLOAD_LENGTH];
    /* Copy payload length */
    sZgpDataIndication.u8PDUSize = u8GpdCommandPayloadLength;

    /* Check Green Power Payload length */
    if(sZgpDataIndication.u8PDUSize > GP_MAX_ZB_CMD_PAYLOAD_LENGTH)
    {
        /* Inform application unsupported payload length as we are buffering packet for delayed transmission */
        psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_CMD_UNSUPPORTED_PAYLOAD_LENGTH;

        /* Give Application Callback  */
        psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);
        return E_ZCL_SUCCESS;
    }

    sZgpDataIndication.u8CommandId = eZgpdCommandId;
    sZgpDataIndication.u2ApplicationId = u8ApplicationId;
    sZgpDataIndication.uZgpdDeviceAddr = *puZgpdAddress;
    /* Copy Payload */
    //sZgpDataIndication.pu8Pdu = au8Pdu;
    sZgpDataIndication.pu8Pdu = pu8GpdCommandPayload;
    //memcpy(sZgpDataIndication.pu8Pdu,pu8GpdCommandPayload,u8GpdCommandPayloadLength);

    sZgpDataIndication.u8TranslationIndex = u8TranslationIndex;
    /* push this packet to stack after some delay */
    return eGp_BufferTransmissionPacket(
                        &sZgpDataIndication,
                        E_GP_LOOP_BACK,
                        psGpCustomDataStructure);
}

/****************************************************************************
 **
 ** NAME:       eGP_UpdateSinkTable
 **
 ** DESCRIPTION:
 ** Update sink table information for ZGPD
 **
 ** PARAMETERS:                         Name                            Usage
 ** ZPS_tsAfEvent                 *pZPSevent                     ZPS Event
 ** tsZCL_EndPointDefinition      *psEndPointDefinition          Endpoint definition
 ** tsGP_GreenPowerCustomData     *psGpCustomDataStructure       Custom data
 ** tsGP_ZgpsSinkTable            *psZgpsSinkTable               Pointer to sink table
 ** tsGP_GpToZclCommandInfo       *psGpToZclCommandInfo          Pointer to GpToZCL command Infor
 ** teZCL_Status                  eCommIndStatus                 Commission Indication status by App
 ** bool_t                        bIsSinkTableEntryPresent       Is ZGPD entry present in Sink Table
 ** bool_t                        bIsSeqNumCap                   Sequence Capability Info
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC teZCL_Status eGP_UpdateSinkTable(
                                        tsZCL_EndPointDefinition        *psEndPointDefinition,
                                        tsGP_GreenPowerCustomData       *psGpCustomDataStructure,
                                        tsGP_ZgpsSinkTable              *psZgpsSinkTable,
                                        tsGP_GpToZclCommandInfo         *psGpToZclCommandInfo,
                                        uint8                           u8AppId,
                                        tuGP_ZgpdDeviceAddr             uZgpdDeviceAddr,
                                        uint8                           u8SecLevel,
                                        uint8                           u8SecKeyType,
                                        uint8                           u8ZgpsCommunicationMode,
                                        uint32                          u32SecFrameCounter,
                                        teZCL_Status                    eCommIndStatus,
                                        bool_t                          bIsSeqNumCap,
                                        bool_t                          bIsRxOnCapability,
                                        bool_t                          bIsFixedLocation)
{
    teGP_GreenPowerStatus       eSinkStatus;
    tsZCL_Key                   sTempZgpdKey;
 //   teGP_GreenPowerSecKeyType   eTempKeyType;

    psZgpsSinkTable->b16Options |= u8AppId;
    psZgpsSinkTable->uZgpdDeviceAddr = uZgpdDeviceAddr;

    /* Set Communication Mode based on sink communication mode attribute value */
    /* If default communication mode is pre-commissioned,
       assummed that sink table is populated before device put in commission mode
       Group list would be populated by CT */
    psZgpsSinkTable->b16Options |= (u8ZgpsCommunicationMode << 3);

    /* Set Groupcast Radius */
    if( (u8ZgpsCommunicationMode == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_DGROUP_ID) ||
        (u8ZgpsCommunicationMode == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID) )
    {
        /* Set default groupcast radius */
        //psZgpsSinkTable->u8GroupCastRadius = GP_GROUPCAST_RADIUS;
    }



    /* set seq num capability in sink table from GP commission command */
    psZgpsSinkTable->b16Options |= (bIsSeqNumCap << 5);

    /* Set RxOnCap and Fixed Location fields */
    psZgpsSinkTable->b16Options |= (bIsRxOnCapability << 6);
    psZgpsSinkTable->b16Options |= (bIsFixedLocation << 7);

    /* Populate sink table entry */
    if(eCommIndStatus == E_ZCL_SUCCESS)
    {
        psZgpsSinkTable->eGreenPowerSinkTablePriority = E_GP_SINK_TABLE_P_1;
    }
    else
    {
        psZgpsSinkTable->eGreenPowerSinkTablePriority = E_GP_SINK_TABLE_P_2;
    }

  //  eTempKeyType = psZgpsSinkTable->b8SecOptions >> 2;
    /* check sec status of event indication */
    psZgpsSinkTable->b8SecOptions = u8SecLevel;

    /* Sec Level */
    if(u8SecLevel)
    {
        AESSW_Block_u                   uSecurityKey = {{0}};
#ifdef CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY
        AESSW_Block_u                   uInKey;
#endif
        uint64                          u64Address = 0;

        memcpy(sTempZgpdKey.au8Key, psZgpsSinkTable->sZgpdKey.au8Key, E_ZCL_KEY_128_SIZE);

        psZgpsSinkTable->b8SecOptions |= (u8SecKeyType << 0x02);
        psZgpsSinkTable->b16Options |= GP_SINK_TABLE_SECURITY_USE_MASK;

#ifdef GP_IEEE_ADDR_SUPPORT
        u64Address = psZgpsSinkTable->uZgpdDeviceAddr.u64ZgpdIEEEAddr;
#endif
        /* Copy Key */
        if((u8SecKeyType == E_GP_ZGPD_GROUP_KEY)||(u8SecKeyType == E_GP_DERIVED_INDIVIDUAL_ZGPD_KEY))
        {
#ifdef CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY
           // get EP mutex
            #ifndef COOPERATIVE
                eZCL_GetMutex(psEndPointDefinition);
            #endif

            /* Get Green Power communication Mode attribute value */
            eZCL_ReadLocalAttributeValue(
                     psEndPointDefinition->u8EndPointNumber,
                     GREENPOWER_CLUSTER_ID,
                     TRUE,
                     FALSE,
                     FALSE,
                     E_CLD_GP_ATTR_ZGP_SHARED_SECURITY_KEY,
                     (uint8*)&uSecurityKey);

            // release mutex
            #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif


            if(u8SecKeyType == E_GP_DERIVED_INDIVIDUAL_ZGPD_KEY)
            {
                uInKey = uSecurityKey;

                /* Get the derived individual key */
                ZPS_vZgpTransformKey(ZPS_E_ZGP_DERIVED_INDIVIDUAL_KEY,
                                   u8AppId,
                                   psZgpsSinkTable->uZgpdDeviceAddr.u32ZgpdSrcId,
                                   u64Address,
                                   &uInKey,
                                   &uSecurityKey);
            }
#else
            // fill in callback event structure
            eZCL_SetCustomCallBackEvent(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent,
                                          0, 0, psEndPointDefinition->u8EndPointNumber);
             /* Set Event Type */
            psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_SHARED_SECURITY_KEY_IS_NOT_ENABLED;
             /* Give a call back event to app */
            psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);
#endif
        }
        else if(u8SecKeyType == E_GP_ZIGBEE_NWK_KEY)
        {
            /* Get the current network key */
            ZPS_vZgpTransformKey(ZPS_E_ZGP_ZIGBEE_NWK_KEY,
                                 u8AppId,
                                 psZgpsSinkTable->uZgpdDeviceAddr.u32ZgpdSrcId,
                                 u64Address,
                                 NULL,
                                 &uSecurityKey);

        }
        else if(u8SecKeyType == E_GP_NWK_KEY_DERIVED_ZGPD_GROUP_KEY)
        {
            /* Get the current network key */
//            ZPS_vZgpTransformKey(ZPS_E_ZGP_ZIGBEE_NWK_KEY,
//                                 u8AppId,
//                                 psZgpsSinkTable->uZgpdDeviceAddr.u32ZgpdSrcId,
//                                 u64Address,
//                                 NULL,
//                                 &uInKey);
            /* Get the network key - derived GPD group key */
            ZPS_vZgpTransformKey(ZPS_E_ZGP_NWK_KEY_DERIVED_GRP_KEY,
                                 u8AppId,
                                 psZgpsSinkTable->uZgpdDeviceAddr.u32ZgpdSrcId,
                                 u64Address,
                                 NULL,
                                 &uSecurityKey);
        }
        if(u8SecKeyType != E_GP_OUT_OF_THE_BOX_ZGPD_KEY)
            memcpy(psZgpsSinkTable->sZgpdKey.au8Key, uSecurityKey.au8, E_ZCL_KEY_128_SIZE);
    }


    /* check translation table pointer which was passed by app */
    if(psGpToZclCommandInfo != NULL)
    {
        psZgpsSinkTable->eZgpdDeviceId = psGpToZclCommandInfo->eZgpdDeviceId;
    }

    /* Security Frame Counter */
    psZgpsSinkTable->u32ZgpdSecFrameCounter = u32SecFrameCounter;


    /* Add to Sink Table */
    eSinkStatus = eGP_AddSinkTableEntry(psEndPointDefinition->u8EndPointNumber,
                                        psZgpsSinkTable);

    /* check eStatus  and give call back accordingly */
    if(eSinkStatus == E_GP_SINK_TABLE_SUCCESS)
    {
        psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_SINK_TABLE_ENTRY_ADDED;
        psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.uMessage.psZgpsSinkTable = psZgpsSinkTable;
    }
    else
    {
        psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_SINK_TABLE_FULL;
    }

    /* Give Application Callback for sink table update */
    psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);
#if 0
    if((u8SecLevel)&&(eSinkStatus == E_GP_SINK_TABLE_SUCCESS))
    {
        tsGP_ZgpsSinkTable             sZgpsSinkTable;
        bGP_IsSinkTableEntryPresent(
                            psEndPointDefinition->u8EndPointNumber,
                            u8AppId,
                            &uZgpdDeviceAddr,
                            E_GP_SINK_TABLE_GET_ENTRY,
                            &sZgpsSinkTable,
                            u8ZgpsCommunicationMode);
        /* reset the security frame counter if key or key type is different */
        if(( memcmp(sZgpsSinkTable.sZgpdKey.au8Key, sTempZgpdKey.au8Key, E_ZCL_KEY_128_SIZE) != 0)||
           (eTempKeyType != (sZgpsSinkTable.b8SecOptions >> 2)))
        {
            sZgpsSinkTable.u32ZgpdSecFrameCounter = 0;
            bGP_IsSinkTableEntryPresent(
                                psEndPointDefinition->u8EndPointNumber,
                                u8AppId,
                                &uZgpdDeviceAddr,
                                E_GP_SINK_TABLE_SET_ENTRY,
                                &sZgpsSinkTable,
                                u8ZgpsCommunicationMode);
        }
    }
#endif
    return eSinkStatus;
}

/****************************************************************************
 **
 ** NAME:       eGP_UpdateApsGroupTableAndDeviceAnnounce
 **
 ** DESCRIPTION:
 ** Adding group Id to APS group table and making ZGPD device announce
 **
 ** PARAMETERS:                         Name                            Usage
 ** ZPS_tsAfEvent                 *pZPSevent                     ZPS Event
 ** tsZCL_EndPointDefinition      *psEndPointDefinition          Endpoint definition
 ** tsGP_GreenPowerCustomData     *psGpCustomDataStructure       Custom data
 ** tsGP_ZgpsSinkTable            *psZgpsSinkTable               Pointer to sink table
 ** tsGP_ZgpDataIndication        *psZgpDataIndication           GPDF Data Indication
 ** teZCL_Status                  eCommIndStatus                 Commission Indication status by App
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC teZCL_Status eGP_UpdateApsGroupTableAndDeviceAnnounce(
                            tsZCL_EndPointDefinition        *psEndPointDefinition,
                            tsGP_GreenPowerCustomData       *psGpCustomDataStructure,
                            tsGP_ZgpsSinkTable              *psZgpsSinkTable,
                            tsGP_ZgpDataIndication          *psZgpDataIndication,
                            teZCL_Status                    eCommIndStatus)
{
    teZCL_Status eStatus = E_ZCL_SUCCESS;

    /* For device doesn't have any payload */
    psZgpDataIndication->pu8Pdu = NULL;

    eGp_BufferTransmissionPacket(
                        psZgpDataIndication,
                        E_GP_DEVICE_ANNOUNCE,
                        psGpCustomDataStructure);

    /* Add GP endpoint to ZPS group tables */
    if(eCommIndStatus == E_ZCL_SUCCESS)
    {
        /* Add to the group only if communication mode is derived or assigned */
        if(((psZgpsSinkTable->b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3) == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_DGROUP_ID)
        {
            /* Add derived group Id */
            uint16  u16DerivedGroupId;
            u16DerivedGroupId = u16GP_DeriveAliasSrcAddr(
                    (uint8)psZgpDataIndication->u2ApplicationId,
                    psZgpDataIndication->uZgpdDeviceAddr);

            eStatus = ZPS_eAplZdoGroupEndpointAdd(u16DerivedGroupId, ZCL_GP_PROXY_ENDPOINT_ID);
            /* Check Status */
            if(eStatus != E_ZCL_SUCCESS)
            {
                psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_ADDING_GROUP_TABLE_FAIL;
                psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.uMessage.eAddGroupTableStatus = eStatus;
               /* Give Application Callback for sink table update */
                psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);
               // release mutex
                #ifndef COOPERATIVE
                    eZCL_ReleaseMutex(psEndPointDefinition);
                #endif

                return E_ZCL_SUCCESS;
            }
        }
        else if(((psZgpsSinkTable->b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3) == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID)
        {
            /* Find No. of pre-commissioned groups are presented in the list */
            uint8   u8Count;

            for(u8Count = 0; u8Count < psZgpsSinkTable->u8ZgpsGroupListEntries; u8Count++)
            {
                eStatus = ZPS_eAplZdoGroupEndpointAdd(psZgpsSinkTable->asZgpsGroupList[u8Count].u16SinkGroup, ZCL_GP_PROXY_ENDPOINT_ID);
                /* Check Status */
                 if(eStatus != E_ZCL_SUCCESS)
                 {
                     psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.eEventType = E_GP_ADDING_GROUP_TABLE_FAIL;
                     psGpCustomDataStructure->sGPCommon.sGreenPowerCallBackMessage.uMessage.eAddGroupTableStatus = eStatus;
                    /* Give Application Callback for sink table update */
                     psEndPointDefinition->pCallBackFunctions(&psGpCustomDataStructure->sGPCommon.sGPCustomCallBackEvent);
                    // release mutex
                    #ifndef COOPERATIVE
                        eZCL_ReleaseMutex(psEndPointDefinition);
                    #endif

                    return E_ZCL_SUCCESS;
                }
            }
        }
    }

    return eStatus;
}
#endif
/****************************************************************************
 **
 ** NAME:       u8GP_GetDataReqHandle
 **
 ** DESCRIPTION:
 ** Return back Data Req Handle
 **
 ** PARAMETERS:                         Name                            Usage

 ** RETURN:
 ** uint8
 **
 ****************************************************************************/
PUBLIC uint8 u8GP_GetDataReqHandle(tsGP_GreenPowerCustomData  *psGpCustomDataStructure)
{
    uint8 u8GPDataReqHandle;
    u8GPDataReqHandle = psGpCustomDataStructure->u8GPDataReqHandle++;

    if(psGpCustomDataStructure->u8GPDataReqHandle == 0)
    {
        psGpCustomDataStructure->u8GPDataReqHandle = 0x81;
    }

    return u8GPDataReqHandle;
}
#if 0
/****************************************************************************
 **
 ** NAME:       u8GP_GetDataReqHandle
 **
 ** DESCRIPTION:
 ** Return back Data Req Handle
 **
 ** PARAMETERS:                         Name                            Usage

 ** RETURN:
 ** uint8
 **
 ****************************************************************************/
PUBLIC teZCL_Status eGP_WriteAttributeDataReq(uint32 u32GPDSrcID, uint16 u16ClusterId, uint16 u16AttrId, uint8 u8AttrDataType, void *pvAttrValue)
{
    ZPS_tsZgpGreenPowerReq                      sZgpDataReq;
    PDUM_thAPduInstance                         hAPduInst;
    uint8                                       *pu8Start,u8RecordLength=0;
    ZPS_teStatus                                eZPSStatus;
    hAPduInst = hZCL_AllocateAPduInstance();
    /* check buffer size */
    if((hAPduInst == PDUM_INVALID_HANDLE)||(pvAttrValue == NULL))
    {
        // free buffer and return
        PDUM_eAPduFreeAPduInstance(hAPduInst);
        return E_ZCL_FAIL;
    }
    sZgpDataReq.bDataFrame = TRUE;

    pu8Start = (uint8 *)(PDUM_pvAPduInstanceGetPayload(hAPduInst));
    *pu8Start++ = 0;//options
    *pu8Start++ = (uint8)u16ClusterId;
    *pu8Start++ = (uint8)(u16ClusterId >> 8);
    if(eZCL_GetAttributeTypeSize(u8AttrDataType, &u8RecordLength)!= E_ZCL_SUCCESS)
    {
        // free buffer and return
        PDUM_eAPduFreeAPduInstance(hAPduInst);
        return E_ZCL_FAIL;
    }
    u8RecordLength += 3;
    *pu8Start++ = u8RecordLength;//length of record
    *pu8Start++ = (uint8)u16AttrId;
    *pu8Start++ = (uint8)(u16AttrId >> 8);
    *pu8Start++ = u8AttrDataType;//attr data type
    u16ZCL_WriteTypeNBO(pu8Start, u8AttrDataType, pvAttrValue);
    PDUM_eAPduInstanceSetPayloadSize(hAPduInst, 4+u8RecordLength);

    sZgpDataReq.u8TxOptions = 0x01;
    sZgpDataReq.u8ApplicationId = GP_APPL_ID_4_BYTE;
    //if(sZgpDataReq.u8ApplicationId == GP_APPL_ID_4_BYTE)
    {
        sZgpDataReq.uGpId.u32SrcId = u32GPDSrcID;
    }

    sZgpDataReq.u16TxQueueEntryLifetime = 30000; //30 sec
    //sZgpDataReq.u8Handle = u8GP_GetDataReqHandle(psGpCustomDataStructure);
    //sZgpDataReq.u8SeqNum = psZgpBufferedApduRecord->sBufferedApduInfo.u8SeqNum;
    sZgpDataReq.u16Panid = 0xFFFF;
    sZgpDataReq.u16DstAddr = 0xFFFF;

    eZPSStatus = zps_vDStub_DataReq(&sZgpDataReq, hAPduInst,TRUE,0xF1);
    DBG_vPrintf(TRUE, "zps_vDStub_DataReq:%d\r\n", eZPSStatus);
    // free buffer and return
    PDUM_eAPduFreeAPduInstance(hAPduInst);
    return eZPSStatus;
}
#endif
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

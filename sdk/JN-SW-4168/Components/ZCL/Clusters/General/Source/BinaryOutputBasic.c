/*****************************************************************************
 *
 * MODULE:             Binary Output Basic Cluster
 *
 * COMPONENT:          BinaryOutputBasic.c
 *
 * AUTHOR:             Shweta Chauhan
 *
 * DESCRIPTION:        Binary Inpunt Basic cluster definition
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/UnifiedZCL_ZLL102_HA122_Maintenance/Clusters/General/Source/BinaryOutputBasic.c $
 *
 * $Revision: 76101 $
 *
 * $LastChangedBy: nxp57621 $
 *
 * $LastChangedDate: 2016-01-18 08:35:53 +0000 (Mon, 18 Jan 2016) $
 *
 * $Id: BinaryOutputBasic.c 76101 2016-01-18 08:35:53Z nxp57621 $
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
 * Copyright NXP B.V. 2012. All rights reserved
 *
 ****************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#include <jendefs.h>
#include "zcl.h"
#include "zcl_customcommand.h"
#include "BinaryOutputBasic.h"
#include "zcl_options.h"


#ifdef CLD_BINARY_OUTPUT_BASIC

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#if defined(CLD_BINARY_OUTPUT_BASIC) && !defined(BINARY_OUTPUT_BASIC_SERVER) && !defined(BINARY_OUTPUT_BASIC_CLIENT)
#error You Must Have either BINARY_OUTPUT_BASIC_SERVER and/or BINARY_OUTPUT_BASIC_CLIENT defined in zcl_options.h
#endif
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
#ifdef BINARY_OUTPUT_BASIC_SERVER
    tsZCL_AttributeDefinition asCLD_BinaryOutputBasicClusterAttributeDefinitions [] = {

        /* ZigBee Cluster Library Version */
    #ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_ACTIVE_TEXT
        {E_CLD_BINARY_OUTPUT_BASIC_ATTR_ID_ACTIVE_TEXT,            (E_ZCL_AF_RD|E_ZCL_AF_WR),               E_ZCL_CSTRING,        (uint32)(&((tsCLD_BinaryOutputBasic*)(0))->sActiveText),          0},  /* Optional */
    #endif

    #ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_DESCRIPTION
        {E_CLD_BINARY_OUTPUT_BASIC_ATTR_ID_DESCRIPTION,            (E_ZCL_AF_RD|E_ZCL_AF_WR),               E_ZCL_CSTRING,        (uint32)(&((tsCLD_BinaryOutputBasic*)(0))->sDescription),       0},  /* Optional */
    #endif

    #ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_INACTIVE_TEXT
        {E_CLD_BINARY_OUTPUT_BASIC_ATTR_ID_INACTIVE_TEXT,          (E_ZCL_AF_RD|E_ZCL_AF_WR),               E_ZCL_CSTRING,        (uint32)(&((tsCLD_BinaryOutputBasic*)(0))->sInactiveText),       0},  /* Optional */
    #endif

    #ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_MINIMUM_OFF_TIME
        {E_CLD_BINARY_OUTPUT_BASIC_ATTR_ID_MINIMUM_OFF_TIME,       (E_ZCL_AF_RD|E_ZCL_AF_WR),               E_ZCL_UINT32,        (uint32)(&((tsCLD_BinaryOutputBasic*)(0))->u32MinimumOffTime),     0}, /* Optional */
    #endif  

    #ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_MINIMUM_ON_TIME
        {E_CLD_BINARY_OUTPUT_BASIC_ATTR_ID_MINIMUM_ON_TIME,        (E_ZCL_AF_RD|E_ZCL_AF_WR),               E_ZCL_UINT32,        (uint32)(&((tsCLD_BinaryOutputBasic*)(0))->u32MinimumOnTime),      0}, /* Optional */
    #endif    
    
        {E_CLD_BINARY_OUTPUT_BASIC_ATTR_ID_OUT_OF_SERVICE,         (E_ZCL_AF_RD|E_ZCL_AF_WR),               E_ZCL_BOOL,            (uint32)(&((tsCLD_BinaryOutputBasic*)(0))->bOutOfService),        0},  /* Mandatory */

    #ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_POLARITY
        {E_CLD_BINARY_OUTPUT_BASIC_ATTR_ID_POLARITY,               E_ZCL_AF_RD,                             E_ZCL_ENUM8,        (uint32)(&((tsCLD_BinaryOutputBasic*)(0))->u8Polarity),            0},  /* Optional */
    #endif        

        {E_CLD_BINARY_OUTPUT_BASIC_ATTR_ID_PRESENT_VALUE,          (E_ZCL_AF_RD|E_ZCL_AF_WR|E_ZCL_AF_RP),   E_ZCL_BOOL,         (uint32)(&((tsCLD_BinaryOutputBasic*)(0))->bPresentValue),         0},  /* Mandatory */

    #ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_RELIABILITY
        {E_CLD_BINARY_OUTPUT_BASIC_ATTR_ID_RELIABILITY,            (E_ZCL_AF_RD|E_ZCL_AF_WR),               E_ZCL_ENUM8,        (uint32)(&((tsCLD_BinaryOutputBasic*)(0))->u8Reliability),        0},  /* Optional */
    #endif        

    #ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_RELINQUISH_DEFAULT
        {E_CLD_BINARY_OUTPUT_BASIC_ATTR_ID_RELINQUISH_DEFAULT,     (E_ZCL_AF_RD|E_ZCL_AF_WR),               E_ZCL_BOOL,         (uint32)(&((tsCLD_BinaryOutputBasic*)(0))->bRelinquishDefault),        0},  /* Optional */
    #endif
    
        {E_CLD_BINARY_OUTPUT_BASIC_ATTR_ID_STATUS_FLAGS,           (E_ZCL_AF_RD|E_ZCL_AF_RP),               E_ZCL_BMAP8,        (uint32)(&((tsCLD_BinaryOutputBasic*)(0))->u8StatusFlags),        0},  /* Mandatory */

    #ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_APPLICATION_TYPE
        {E_CLD_BINARY_OUTPUT_BASIC_ATTR_ID_APPLICATION_TYPE,        E_ZCL_AF_RD,                            E_ZCL_UINT32,        (uint32)(&((tsCLD_BinaryOutputBasic*)(0))->u32ApplicationType),    0}, /* Optional */
    #endif    
    };

    tsZCL_ClusterDefinition sCLD_BinaryOutputBasic = {
            GENERAL_CLUSTER_ID_BINARY_OUTPUT_BASIC,
            FALSE,
            E_ZCL_SECURITY_NETWORK,
            (sizeof(asCLD_BinaryOutputBasicClusterAttributeDefinitions) / sizeof(tsZCL_AttributeDefinition)),
            (tsZCL_AttributeDefinition*)asCLD_BinaryOutputBasicClusterAttributeDefinitions,
            NULL
    };
    uint8 au8BinaryOutputBasicServerAttributeControlBits[(sizeof(asCLD_BinaryOutputBasicClusterAttributeDefinitions) / sizeof(tsZCL_AttributeDefinition))];
#else
    tsZCL_ClusterDefinition sCLD_BinaryOutputBasic = {
            GENERAL_CLUSTER_ID_BINARY_OUTPUT_BASIC,
            FALSE,
            E_ZCL_SECURITY_NETWORK,
            0,
            NULL,
            NULL
    };
#endif



/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

/****************************************************************************
 *
 * NAME:       eCLD_BinaryOutputBasicCreateBinaryOutputBasic
 *
 * DESCRIPTION:
 * Creates a binary output basic cluster
 *
 * PARAMETERS:  Name                         Usage
 *              psClusterInstance            Cluster structure
 *              bIsServer                    Server/Client Flag
 *              psClusterDefinition          Cluster Definitation
 *              pvEndPointSharedStructPtr    EndPoint Shared Structure Pointer
 *              pu8AttributeControlBits      Attribute Control Bits
 * RETURN:
 * teZCL_Status
 *
 ****************************************************************************/
PUBLIC  teZCL_Status eCLD_BinaryOutputBasicCreateBinaryOutputBasic(
                tsZCL_ClusterInstance              *psClusterInstance,
                bool_t                              bIsServer,
                tsZCL_ClusterDefinition            *psClusterDefinition,
                void                               *pvEndPointSharedStructPtr,
                uint8                              *pu8AttributeControlBits)
{


    #ifdef STRICT_PARAM_CHECK 
        /* Parameter check */
        if((psClusterInstance==NULL) ||
           (psClusterDefinition==NULL)  )
        {
            return E_ZCL_ERR_PARAMETER_NULL;
        }
    #endif
    

    /* Create an instance of a bianry input basic cluster */
    vZCL_InitializeClusterInstance(
       psClusterInstance, 
       bIsServer,
       psClusterDefinition,
       pvEndPointSharedStructPtr,
       pu8AttributeControlBits,
       NULL,
       NULL);
       
    #ifdef BINARY_OUTPUT_BASIC_SERVER
        /* Initialise attributes defaults */
        if(psClusterInstance->pvEndPointSharedStructPtr != NULL)
        {

    #ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_ACTIVE_TEXT
            ((tsCLD_BinaryOutputBasic*)pvEndPointSharedStructPtr)->sActiveText.u8MaxLength = sizeof(((tsCLD_BinaryOutputBasic*)pvEndPointSharedStructPtr)->au8ActiveText);
            ((tsCLD_BinaryOutputBasic*)pvEndPointSharedStructPtr)->sActiveText.u8Length = 0;
            ((tsCLD_BinaryOutputBasic*)pvEndPointSharedStructPtr)->sActiveText.pu8Data = ((tsCLD_BinaryOutputBasic*)pvEndPointSharedStructPtr)->au8ActiveText;
    #endif

    #ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_DESCRIPTION
            ((tsCLD_BinaryOutputBasic*)pvEndPointSharedStructPtr)->sDescription.u8MaxLength = sizeof(((tsCLD_BinaryOutputBasic*)pvEndPointSharedStructPtr)->au8Description);
            ((tsCLD_BinaryOutputBasic*)pvEndPointSharedStructPtr)->sDescription.u8Length = 0;
            ((tsCLD_BinaryOutputBasic*)pvEndPointSharedStructPtr)->sDescription.pu8Data = ((tsCLD_BinaryOutputBasic*)pvEndPointSharedStructPtr)->au8Description;
    #endif

    #ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_INACTIVE_TEXT
            ((tsCLD_BinaryOutputBasic*)pvEndPointSharedStructPtr)->sInactiveText.u8MaxLength = sizeof(((tsCLD_BinaryOutputBasic*)pvEndPointSharedStructPtr)->au8InactiveText);
            ((tsCLD_BinaryOutputBasic*)pvEndPointSharedStructPtr)->sInactiveText.u8Length = 0;
            ((tsCLD_BinaryOutputBasic*)pvEndPointSharedStructPtr)->sInactiveText.pu8Data = ((tsCLD_BinaryOutputBasic*)pvEndPointSharedStructPtr)->au8InactiveText;
    #endif
    
    #ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_MINIMUM_OFF_TIME
        ((tsCLD_BinaryOutputBasic*)pvEndPointSharedStructPtr)->u32MinimumOffTime = 0xFFFFFFFF;
    #endif
    
    #ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_MINIMUM_ON_TIME
        ((tsCLD_BinaryOutputBasic*)pvEndPointSharedStructPtr)->u32MinimumOnTime = 0xFFFFFFFF;
    #endif
            ((tsCLD_BinaryOutputBasic*)pvEndPointSharedStructPtr)->bOutOfService = FALSE;

    #ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_POLARITY
            ((tsCLD_BinaryOutputBasic*)pvEndPointSharedStructPtr)->u8Polarity = 0; //E_CLD_BINARY_OUTPUT_BASIC_POLARITY_NORMAL
    #endif
        
    #ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_RELIABILITY
            ((tsCLD_BinaryOutputBasic*)pvEndPointSharedStructPtr)->u8Reliability = 0; //E_CLD_BINARY_OUTPUT_BASIC_RELIABILITY_NO_FAULT_DETECTED
    #endif

            ((tsCLD_BinaryOutputBasic*)pvEndPointSharedStructPtr)->u8StatusFlags = 0;
        }
        #endif
    return E_ZCL_SUCCESS;

}

#ifdef BINARY_OUTPUT_BASIC_SERVER

/****************************************************************************
 **
 **  NAME:       eCLD_BinaryOutputBasicHandler
 **
 ** DESCRIPTION:
 ** Handles the dependency between Basic Binary Output attributes
 **
 ** PARAMETERS          
 ** Type                    Name                         Usage
 ** uint8                   u8SourceEndPointId           Source Endpoint ID
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
 
PUBLIC  teZCL_Status eCLD_BinaryOutputBasicHandler(
                                    uint8                       u8SourceEndPointId)
{

    teZCL_Status eStatus;
    tsZCL_EndPointDefinition *psEndPointDefinition;
    tsZCL_ClusterInstance *psClusterInstance;
    tsCLD_BinaryOutputBasic *psSharedStruct;
    void *psCustomDataStructure;
    
    /* Find pointers to cluster */
    eStatus = eZCL_FindCluster(GENERAL_CLUSTER_ID_BINARY_OUTPUT_BASIC, u8SourceEndPointId, TRUE, &psEndPointDefinition, &psClusterInstance, (void*)&psCustomDataStructure);
    if(eStatus != E_ZCL_SUCCESS)
    {
        return eStatus;
    }

    /* Point to shared struct */
    psSharedStruct = (tsCLD_BinaryOutputBasic *)psClusterInstance->pvEndPointSharedStructPtr;
    
    // get EP mutex
    #ifndef COOPERATIVE
        eZCL_GetMutex(psEndPointDefinition);
    #endif

    if(psSharedStruct->bOutOfService)
    {
        psSharedStruct->u8StatusFlags |= BINARY_OUTPUT_BASIC_STATUS_FLAGS_OUT_OF_SERVICE_MASK;
    }else{
        psSharedStruct->u8StatusFlags  &=  ~(BINARY_OUTPUT_BASIC_STATUS_FLAGS_OUT_OF_SERVICE_MASK);
    }
#ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_RELIABILITY
    if(psSharedStruct->u8Reliability != E_CLD_BINARY_OUTPUT_BASIC_RELIABILITY_NO_FAULT_DETECTED)
        psSharedStruct->u8StatusFlags  |= BINARY_OUTPUT_BASIC_STATUS_FLAGS_FAULT_MASK;
    else
        psSharedStruct->u8StatusFlags  &= ~(BINARY_OUTPUT_BASIC_STATUS_FLAGS_FAULT_MASK);
#endif    

    // release EP
    #ifndef COOPERATIVE
        eZCL_ReleaseMutex(psEndPointDefinition);
    #endif

    
    return E_ZCL_SUCCESS;
}
#endif

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

#endif
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/


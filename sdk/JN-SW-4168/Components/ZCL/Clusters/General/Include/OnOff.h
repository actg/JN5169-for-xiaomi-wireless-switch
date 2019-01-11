/*****************************************************************************
 *
 * MODULE:             On/Off Cluster
 *
 * COMPONENT:          OnOff.h
 *
 * AUTHOR:             Lee Mitchell
 *
 * DESCRIPTION:        Header for On/Off Cluster
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/UnifiedZCL_ZLL102_HA122_Maintenance/Clusters/General/Include/OnOff.h $
 *
 * $Revision: 87494 $
 *
 * $LastChangedBy: nxp29772 $
 *
 * $LastChangedDate: 2017-03-24 08:42:36 +0000 (Fri, 24 Mar 2017) $
 *
 * $Id: OnOff.h 87494 2017-03-24 08:42:36Z nxp29772 $
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

#ifndef ONOFF_H
#define ONOFF_H

#include <jendefs.h>
#include "zcl.h"
#include "zcl_options.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/* Cluster ID's */
#define GENERAL_CLUSTER_ID_ONOFF                        0x0006

/****************************************************************************/
/*             On/Off Control Cluster - ZLL Enhanced Attributes             */
/*                                                                          */
/* Add the following #define's to your zcl_options.h file to add optional   */
/* attributes to the level control cluster.                                 */
/****************************************************************************/
/* ON Configurable Time */
//#define CLD_ONOFF_ATTR_ID_ON_CONFIGURABLE_DURATION

/*ON duration Unit Of Measument */
//#define CLD_ONOFF_ATTR_ID_DURATION_UNIT_OF_MEASUREMENT

/*Max Duration */
//#define CLD_ONOFF_ATTR_ID_MAX_DURATION

/* global scene control attribute */
//#define CLD_ONOFF_ATTR_GLOBAL_SCENE_CONTROL

/* on time attribute */
//#define CLD_ONOFF_ATTR_ON_TIME

/* global scane control attribute */
//#define CLD_ONOFF_ATTR_OFF_WAIT_TIME



/* Bit definitions in On with Timed Off command On/Off field */
#define CLD_ONOFF_OWTO_BIT_ACCEPT_ONLY_WHEN_ON  (1 << 0)

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/* On/Off Command - Payload */
typedef enum 
{

    E_CLD_ONOFF_CMD_OFF                      = 0x00,     /* Mandatory */
    E_CLD_ONOFF_CMD_ON,                                  /* Mandatory */
    E_CLD_ONOFF_CMD_TOGGLE,                              /* Mandatory */

    E_CLD_ONOFF_CMD_OFF_EFFECT               = 0x40,
    E_CLD_ONOFF_CMD_ON_RECALL_GLOBAL_SCENE,
    E_CLD_ONOFF_CMD_ON_TIMED_OFF
} teCLD_OnOff_Command;


typedef enum 
{
    /* On/Off attribute set attribute ID's (3.8.2.2) */
    E_CLD_ONOFF_ATTR_ID_ONOFF                = 0x0000,    /* Mandatory */
    E_CLD_ONOFF_ATTR_ID_ON_CONFIGURABLE_DURATION,
    E_CLD_ONOFF_ATTR_ID_DURATION_UNIT_OF_MEASUREMENT,
    E_CLD_ONOFF_ATTR_ID_MAX_DURATION,
    E_CLD_ONOFF_ATTR_ID_GLOBAL_SCENE_CONTROL = 0x4000,    /* Optional */
    E_CLD_ONOFF_ATTR_ID_ON_TIME,                          /* Optional */
    E_CLD_ONOFF_ATTR_ID_OFF_WAIT_TIME,                    /* Optional */

} teCLD_OnOff_ClusterID;


/* On/Off Cluster */
typedef struct
{

    zbool                   bOnOff;
    
#ifdef CLD_ONOFF_ATTR_ID_ON_CONFIGURABLE_DURATION
    zuint16                 u16OnConfigurableDuration;
#endif    

#ifdef CLD_ONOFF_ATTR_ID_DURATION_UNIT_OF_MEASUREMENT
    zenum8                  eDurationUnitOfMeasurement;
#endif  

#ifdef CLD_ONOFF_ATTR_ID_MAX_DURATION
    zuint16                 u16MaxDuration;
#endif 

#ifdef CLD_ONOFF_ATTR_GLOBAL_SCENE_CONTROL
    zbool                   bGlobalSceneControl;
#endif
#ifdef CLD_ONOFF_ATTR_ON_TIME
    zuint16                 u16OnTime;
#endif
#ifdef CLD_ONOFF_ATTR_OFF_WAIT_TIME
    zuint16                 u16OffWaitTime;
#endif

} tsCLD_OnOff;


//#ifdef  CLD_ONOFF_SUPPORT_ZLL_ENHANCED_COMMANDS
/* off effect request command payload */
typedef struct
{
    zuint8                 u8EffectId;
    zuint8                 u8EffectVariant;
} tsCLD_OnOff_OffWithEffectRequestPayload;

typedef struct
{
    zuint8                 u8OnOff;
    zuint16                u16OnTime;
    zuint16                u16OffTime;
} tsCLD_OnOff_OnWithTimedOffRequestPayload;
//#endif

/* Custom data structure */
typedef struct
{
    uint8                   u8Dummy;
} tsCLD_OnOffCustomDataStructure;


/* Definition of On/Off Callback Event Structure */
typedef struct
{
    uint8                           u8CommandId;
    union
    {
        tsCLD_OnOff_OffWithEffectRequestPayload *psOffWithEffectRequestPayload;
    } uMessage;
} tsCLD_OnOffCallBackMessage;


/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC teZCL_Status eCLD_OnOffCreateOnOff(
                tsZCL_ClusterInstance              *psClusterInstance,
                bool_t                              bIsServer,
                tsZCL_ClusterDefinition            *psClusterDefinition,
                void                               *pvEndPointSharedStructPtr,
                uint8                              *pu8AttributeControlBits,
                tsCLD_OnOffCustomDataStructure     *psCustomDataStructure);

PUBLIC teZCL_Status eCLD_OnOffCommandSend(
                uint8           u8SourceEndPointId,
                uint8           u8DestinationEndPointId,
                tsZCL_Address   *psDestinationAddress,
                uint8           *pu8TransactionSequenceNumber,
                teCLD_OnOff_Command   eCommand);

#if (defined CLD_ONOFF_SUPPORT_ZLL_ENHANCED_COMMANDS) && (defined ONOFF_SERVER)
PUBLIC teZCL_Status eCLD_OnOffUpdate(uint8 u8SourceEndPointId);
#endif

#if (defined CLD_ONOFF_SUPPORT_ZLL_ENHANCED_COMMANDS)
PUBLIC teZCL_Status eCLD_OnOffCommandOffWithEffectSend(
                uint8           u8SourceEndPointId,
                uint8           u8DestinationEndPointId,
                tsZCL_Address   *psDestinationAddress,
                uint8           *pu8TransactionSequenceNumber,
                tsCLD_OnOff_OffWithEffectRequestPayload *psPayload);

PUBLIC teZCL_Status eCLD_OnOffCommandOnWithTimedOffSend(
                uint8           u8SourceEndPointId,
                uint8           u8DestinationEndPointId,
                tsZCL_Address   *psDestinationAddress,
                uint8           *pu8TransactionSequenceNumber,
                tsCLD_OnOff_OnWithTimedOffRequestPayload *psPayload);

#endif

/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/

extern tsZCL_ClusterDefinition sCLD_OnOff;

#if (defined CLD_ONOFF) && (defined ONOFF_SERVER)
    extern const tsZCL_AttributeDefinition asCLD_OnOffClusterAttributeDefinitions[];
    extern uint8 au8OnOffServerAttributeControlBits[];
#endif

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

#endif /* ONOFF_H */

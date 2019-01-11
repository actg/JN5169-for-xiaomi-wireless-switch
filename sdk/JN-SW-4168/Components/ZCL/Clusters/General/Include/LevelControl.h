/*****************************************************************************
 *
 * MODULE:             Level Control Cluster
 *
 * COMPONENT:          LevelControl.h.h
 *
 * AUTHOR:             Lee Mitchell
 *
 * DESCRIPTION:        Header for Level Control Cluster
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/UnifiedZCL_ZLL102_HA122_Maintenance/Clusters/General/Include/LevelControl.h $
 *
 * $Revision: 65827 $
 *
 * $LastChangedBy: nxp57621 $
 *
 * $LastChangedDate: 2014-11-20 11:34:13 +0000 (Thu, 20 Nov 2014) $
 *
 * $Id: LevelControl.h 65827 2014-11-20 11:34:13Z nxp57621 $
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

#ifndef LEVEL_CONTROL_H
#define LEVEL_CONTROL_H

#include <jendefs.h>
#include "dlist.h"
#include "zcl.h"
#include "zcl_customcommand.h"
#include "zcl_options.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/* Cluster ID's */
#define GENERAL_CLUSTER_ID_LEVEL_CONTROL            0x0008

/****************************************************************************/
/*             Level Control Cluster - Optional Attributes                  */
/*                                                                          */
/* Add the following #define's to your zcl_options.h file to add optional   */
/* attributes to the level control cluster.                                 */
/****************************************************************************/

/* Enable the optional Remaining Time attribute */
//#define CLD_LEVELCONTROL_ATTR_REMAINING_TIME

/* Enable the optional On/Off Transition Time attribute */
//#define CLD_LEVELCONTROL_ATTR_ON_OFF_TRANSITION_TIME

/* Enable the optional On Level attribute */
//#define CLD_LEVELCONTROL_ATTR_ON_LEVEL

/* Enable the optional On Transition Time attribute */
//#define CLD_LEVELCONTROL_ATTR_ON_TRANSITION_TIME

/* Enable the optional Off Transition Time attribute */
//#define CLD_LEVELCONTROL_ATTR_OFF_TRANSITION_TIME

/* Enable the optional Default Move Rate attribute */
//#define CLD_LEVELCONTROL_ATTR_DEFAULT_MOVE_RATE

#ifndef CLD_LEVELCONTROL_MIN_LEVEL
#define CLD_LEVELCONTROL_MIN_LEVEL                  (1)
#endif

#ifndef CLD_LEVELCONTROL_MAX_LEVEL
#define CLD_LEVELCONTROL_MAX_LEVEL                  (0xfe)
#endif

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/* Command codes */
typedef enum 
{
    E_CLD_LEVELCONTROL_CMD_MOVE_TO_LEVEL            = 0x00,    /* Mandatory */
    E_CLD_LEVELCONTROL_CMD_MOVE,                            /* Mandatory */
    E_CLD_LEVELCONTROL_CMD_STEP,                            /* Mandatory */
    E_CLD_LEVELCONTROL_CMD_STOP,                            /* Mandatory */
    E_CLD_LEVELCONTROL_CMD_MOVE_TO_LEVEL_WITH_ON_OFF,       /* Mandatory */
    E_CLD_LEVELCONTROL_CMD_MOVE_WITH_ON_OFF,                /* Mandatory */
    E_CLD_LEVELCONTROL_CMD_STEP_WITH_ON_OFF,                /* Mandatory */
    E_CLD_LEVELCONTROL_CMD_STOP_WITH_ON_OFF,                /* Mandatory */

    /* These are not actual commands, they are used as extra states in the level control update function */
    E_CLD_LEVELCONTROL_CMD_NONE
} teCLD_LevelControl_Command;


/* Attribute ID's */
typedef enum 
{
    /* LevelControl attribute set attribute ID's (3.10.2.2) */
    E_CLD_LEVELCONTROL_ATTR_ID_CURRENT_LEVEL            = 0x0000,  /* Mandatory */
    E_CLD_LEVELCONTROL_ATTR_ID_REMAINING_TIME,
    E_CLD_LEVELCONTROL_ATTR_ID_ON_OFF_TRANSITION_TIME   = 0x010,
    E_CLD_LEVELCONTROL_ATTR_ID_ON_LEVEL,
	E_CLD_LEVELCONTROL_ATTR_ID_ON_TRANSITION_TIME,
	E_CLD_LEVELCONTROL_ATTR_ID_OFF_TRANSITION_TIME,
	E_CLD_LEVELCONTROL_ATTR_ID_DEFAULT_MOVE_RATE,
    E_CLD_LEVELCONTROL_ATTR_ID_PHYSICAL_MIN_LEVEL,
    E_CLD_LEVELCONTROL_ATTR_ID_PHYSICAL_MAX_LEVEL,
    E_CLD_LEVELCONTROL_ATTR_ID_MIN_LEVEL,
    E_CLD_LEVELCONTROL_ATTR_ID_MAX_LEVEL
} teCLD_LevelControl_ClusterID;


/* Move Modes */
typedef enum 
{
    E_CLD_LEVELCONTROL_MOVE_MODE_UP = 0x0,
    E_CLD_LEVELCONTROL_MOVE_MODE_DOWN
} teCLD_LevelControl_MoveMode;


typedef enum 
{
    E_CLD_LEVELCONTROL_TRANSITION_MOVE_TO_LEVEL = 0,
    E_CLD_LEVELCONTROL_TRANSITION_MOVE,
    E_CLD_LEVELCONTROL_TRANSITION_STEP,
    E_CLD_LEVELCONTROL_TRANSITION_STOP,
    E_CLD_LEVELCONTROL_TRANSITION_ON,
    E_CLD_LEVELCONTROL_TRANSITION_OFF,
    E_CLD_LEVELCONTROL_TRANSITION_OFF_WITH_EFFECT_DIM_DOWN_FADE_OFF,
    E_CLD_LEVELCONTROL_TRANSITION_OFF_WITH_EFFECT_DIM_UP_FADE_OFF,
    E_CLD_LEVELCONTROL_TRANSITION_NONE,
} teCLD_LevelControl_Transition;

/* Level Control Cluster */
typedef struct
{
    zuint8                  u8CurrentLevel;

#ifdef CLD_LEVELCONTROL_ATTR_REMAINING_TIME
    zuint16                 u16RemainingTime;
#endif

#ifdef CLD_LEVELCONTROL_ATTR_ON_OFF_TRANSITION_TIME
    zuint16                 u16OnOffTransitionTime;
#endif

#ifdef CLD_LEVELCONTROL_ATTR_ON_LEVEL
    zuint8                  u8OnLevel;
#endif

#ifdef CLD_LEVELCONTROL_ATTR_ON_TRANSITION_TIME
    zuint16                 u16OnTransitionTime;
#endif

#ifdef CLD_LEVELCONTROL_ATTR_OFF_TRANSITION_TIME
    zuint16                 u16OffTransitionTime;
#endif

#ifdef CLD_LEVELCONTROL_ATTR_DEFAULT_MOVE_RATE
    zuint8                  u8DefaultMoveRate;
#endif

#ifdef CLD_LEVELCONTROL_PHYSICAL_MIN_LEVEL
    zuint8                  u8PhysicalMinLevel;
#endif

#ifdef CLD_LEVELCONTROL_PHYSICAL_MAX_LEVEL
    zuint8                  u8PhysicalMaxLevel;
#endif

#ifdef CLD_LEVELCONTROL_ATTR_MIN_LEVEL
    zuint8                  u8MinLevel;
#endif

#ifdef CLD_LEVELCONTROL_ATTR_MAX_LEVEL
    zuint8                  u8MaxLevel;
#endif

} tsCLD_LevelControl;


/* Move to level command payload */
typedef struct
{
    uint8                   u8Level;
    uint16                  u16TransitionTime;
} tsCLD_LevelControl_MoveToLevelCommandPayload;


/* Move command payload */
typedef struct
{
    uint8                   u8MoveMode;
    uint8                   u8Rate;
} tsCLD_LevelControl_MoveCommandPayload;


/* Step command payload */
typedef struct
{
    uint8                   u8StepMode;
    uint8                   u8StepSize;
    uint16                  u16TransitionTime;
} tsCLD_LevelControl_StepCommandPayload;


/* Definition of On-Off Call back Event Structure */
typedef struct
{
    uint8                                       u8CommandId;
    union
    {
        tsCLD_LevelControl_MoveToLevelCommandPayload    *psMoveToLevelCommandPayload;
        tsCLD_LevelControl_MoveCommandPayload           *psMoveCommandPayload;
        tsCLD_LevelControl_StepCommandPayload           *psStepCommandPayload;
    } uMessage;
} tsCLD_LevelControlCallBackMessage;


/* Transition related data */
typedef struct
{
    teCLD_LevelControl_Transition   eTransition;
    teCLD_LevelControl_MoveMode     eMode;
    bool                            bWithOnOff;
    int                             iCurrentLevel;
    int                             iTargetLevel;
    int                             iPreviousLevel;
    int                             iStepSize;
    uint32                          u32Time;
} tsCLD_LevelControl_Transition;


/* Custom data structure */
typedef struct
{
    tsCLD_LevelControl_Transition       sTransition;
    tsZCL_ReceiveEventAddress             sReceiveEventAddress;
    tsZCL_CallBackEvent                 sCustomCallBackEvent;
    tsCLD_LevelControlCallBackMessage   sCallBackMessage;
} tsCLD_LevelControlCustomDataStructure;


/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC teZCL_Status eCLD_LevelControlCreateLevelControl(
                    tsZCL_ClusterInstance              *psClusterInstance,
                    bool_t                              bIsServer,
                    tsZCL_ClusterDefinition            *psClusterDefinition,
                    void                               *pvEndPointSharedStructPtr,
                    uint8              *pu8AttributeControlBits,
                    tsCLD_LevelControlCustomDataStructure  *psCustomDataStructure);

PUBLIC teZCL_Status eCLD_LevelControlUpdate(
                    uint8                   u8SourceEndPointId);

PUBLIC teZCL_Status eCLD_LevelControlSetLevel(
                    uint8                   u8SourceEndPointId,
                    uint8                   u8Level,
                    uint16                  u16TransitionTime);

PUBLIC teZCL_Status eCLD_LevelControlStopTransition(
        uint8                   u8SourceEndPointId);

PUBLIC teZCL_Status eCLD_LevelControlGetLevel(
                    uint8                   u8SourceEndPointId,
                    uint8                   *pu8Level);

PUBLIC teZCL_Status eCLD_LevelControlClusterIsPresent(
                    uint8                   u8SourceEndPointId);

PUBLIC teZCL_Status eCLD_LevelControlCommandMoveToLevelCommandSend(
                    uint8                       u8SourceEndPointId,
                    uint8                       u8DestinationEndPointId,
                    tsZCL_Address               *psDestinationAddress,
                    uint8                       *pu8TransactionSequenceNumber,
                    bool_t                      bWithOnOff,
                    tsCLD_LevelControl_MoveToLevelCommandPayload *psPayload);

PUBLIC teZCL_Status eCLD_LevelControlCommandMoveCommandSend(
                    uint8                       u8SourceEndPointId,
                    uint8                       u8DestinationEndPointId,
                    tsZCL_Address               *psDestinationAddress,
                    uint8                       *pu8TransactionSequenceNumber,
                    bool_t                      bWithOnOff,
                    tsCLD_LevelControl_MoveCommandPayload *psPayload);

PUBLIC teZCL_Status eCLD_LevelControlCommandStepCommandSend(
                    uint8                       u8SourceEndPointId,
                    uint8                       u8DestinationEndPointId,
                    tsZCL_Address               *psDestinationAddress,
                    uint8                       *pu8TransactionSequenceNumber,
                    bool_t                      bWithOnOff,
                    tsCLD_LevelControl_StepCommandPayload *psPayload);

PUBLIC teZCL_Status eCLD_LevelControlCommandStopCommandSend(
                    uint8                       u8SourceEndPointId,
                    uint8                       u8DestinationEndPointId,
                    tsZCL_Address               *psDestinationAddress,
                    uint8                       *pu8TransactionSequenceNumber);

PUBLIC teZCL_Status eCLD_LevelControlCommandStopWithOnOffCommandSend(
                    uint8                       u8SourceEndPointId,
                    uint8                       u8DestinationEndPointId,
                    tsZCL_Address               *psDestinationAddress,
                    uint8                       *pu8TransactionSequenceNumber);
/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/

extern tsZCL_ClusterDefinition sCLD_LevelControl;

#if (defined CLD_LEVEL_CONTROL) && (defined LEVEL_CONTROL_SERVER)
    extern const tsZCL_AttributeDefinition asCLD_LevelControlClusterAttributeDefinitions[];
    extern uint8 au8LevelControlServerAttributeControlBits[];
#endif

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

#endif /* LEVEL_CONTROL_H */

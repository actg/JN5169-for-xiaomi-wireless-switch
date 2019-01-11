/*****************************************************************************
 *
 * MODULE:             Level Control Cluster
 *
 * COMPONENT:          LevelControl_internal.h
 *
 * AUTHOR:             Lee Mitchell
 *
 * DESCRIPTION:        The internal API for the Level Control Cluster
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/UnifiedZCL_ZLL102_HA122_Maintenance/Clusters/General/Source/LevelControl_internal.h $
 *
 * $Revision: 65575 $
 *
 * $LastChangedBy: nxp57621 $
 *
 * $LastChangedDate: 2014-11-14 11:35:30 +0000 (Fri, 14 Nov 2014) $
 *
 * $Id: LevelControl_internal.h 65575 2014-11-14 11:35:30Z nxp57621 $
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

#ifndef  LEVEL_CONTROL_INTERNAL_H_INCLUDED
#define  LEVEL_CONTROL_INTERNAL_H_INCLUDED

#if defined __cplusplus
extern "C" {
#endif

/****************************************************************************/
/***        Include Files                                                 ***/
/****************************************************************************/

#include "jendefs.h"

#include "zcl.h"
#include "LevelControl.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#define CLAMP(x, low, high)  (((x) > (high)) ? (high) : (((x) < (low)) ? (low) : (x)))

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/* OffWithEffect based on (EffectId | EffectVariant) (6.6.1.4.4)*/
typedef enum 
{
    CLD_ONOFF_OFF_WITH_EFFECT_FADE_OFF            = 0x0000,
    CLD_ONOFF_OFF_WITH_EFFECT_NO_FADE             = 0x0001,
    CLD_ONOFF_OFF_WITH_EFFECT_DIM_DOWN_FADE_OFF   = 0x0002,
    CLD_ONOFF_OFF_WITH_EFFECT_DIM_UP_FADE_OFF     = 0x0100,
    CLD_ONOFF_OFF_WITH_EFFECT_NONE                = 0xFFFF
} teCLD_OnOff_OffWithEffect;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC teZCL_Status eCLD_LevelControlCommandHandler(
                    ZPS_tsAfEvent               *pZPSevent,
                    tsZCL_EndPointDefinition    *psEndPointDefinition,
                    tsZCL_ClusterInstance       *psClusterInstance);

PUBLIC teZCL_Status eCLD_LevelControlCommandMoveToLevelCommandReceive(
                    ZPS_tsAfEvent               *pZPSevent,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_LevelControl_MoveToLevelCommandPayload *psPayload);

PUBLIC teZCL_Status eCLD_LevelControlCommandMoveCommandReceive(
                    ZPS_tsAfEvent               *pZPSevent,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_LevelControl_MoveCommandPayload *psPayload);

PUBLIC teZCL_Status eCLD_LevelControlCommandStepCommandReceive(
                    ZPS_tsAfEvent               *pZPSevent,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_LevelControl_StepCommandPayload *psPayload);

PUBLIC teZCL_Status eCLD_LevelControlCommandStopCommandReceive(
                    ZPS_tsAfEvent               *pZPSevent,
                    uint8                       *pu8TransactionSequenceNumber);

PUBLIC teZCL_Status eCLD_LevelControlSetOnOffState(
                    uint8                       u8SourceEndPointId,
                    bool                        bOn,
                    teCLD_OnOff_OffWithEffect   eCLD_OnOff_OffWithEffect);

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

#if defined __cplusplus
}
#endif

#endif  /* LEVEL_CONTROL_INTERNAL_H_INCLUDED */

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

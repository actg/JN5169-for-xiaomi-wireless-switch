/*****************************************************************************
 *
 * MODULE:             On/Off Cluster
 *
 * COMPONENT:          OnOff_internal.h
 *
 * AUTHOR:             Lee Mitchell
 *
 * DESCRIPTION:        The internal API for the On/Off Cluster
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/UnifiedZCL_ZLL102_HA122_Maintenance/Clusters/General/Source/OnOff_internal.h $
 *
 * $Revision: 65741 $
 *
 * $LastChangedBy: nxp57621 $
 *
 * $LastChangedDate: 2014-11-19 07:04:45 +0000 (Wed, 19 Nov 2014) $
 *
 * $Id: OnOff_internal.h 65741 2014-11-19 07:04:45Z nxp57621 $
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

#ifndef  ONOFF_INTERNAL_H_INCLUDED
#define  ONOFF_INTERNAL_H_INCLUDED

#if defined __cplusplus
extern "C" {
#endif

/****************************************************************************/
/***        Include Files                                                 ***/
/****************************************************************************/

#include "jendefs.h"

#include "zcl.h"
#include "OnOff.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC teZCL_Status eCLD_OnOffCommandHandler(
                    ZPS_tsAfEvent               *pZPSevent,
                    tsZCL_EndPointDefinition    *psEndPointDefinition,
                    tsZCL_ClusterInstance       *psClusterInstance);

PUBLIC teZCL_Status eCLD_OnOffCommandReceive(
                    ZPS_tsAfEvent               *pZPSevent,
                    uint8                       *pu8TransactionSequenceNumber);

PUBLIC teZCL_Status eCLD_OnOffSetState(uint8 u8SourceEndPointId, bool bOn);

PUBLIC teZCL_Status eCLD_OnOffGetState(uint8 u8SourceEndPointId, bool* pbOn);

PUBLIC teZCL_Status eCLD_OnOffClusterIsPresent(uint8 u8SourceEndPointId);

#if ((defined ONOFF_SERVER) && (defined CLD_ONOFF_ATTR_GLOBAL_SCENE_CONTROL))
PUBLIC teZCL_Status eCLD_OnOffSetGlobalSceneControl(uint8 u8SourceEndPointId, bool bGlobalSceneControl);
#endif

#ifdef  CLD_ONOFF_SUPPORT_ZLL_ENHANCED_COMMANDS
PUBLIC teZCL_Status eCLD_OnOffCommandOffWithEffectReceive(
                ZPS_tsAfEvent               *pZPSevent,
                uint8                       *pu8TransactionSequenceNumber,
                tsCLD_OnOff_OffWithEffectRequestPayload *psPayload);

PUBLIC teZCL_Status eCLD_OnOffCommandOnWithTimedOffReceive(
                ZPS_tsAfEvent               *pZPSevent,
                uint8                       *pu8TransactionSequenceNumber,
                tsCLD_OnOff_OnWithTimedOffRequestPayload *psPayload);
#endif

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

#if defined __cplusplus
}
#endif

#endif  /* ONOFF_INTERNAL_H_INCLUDED */

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

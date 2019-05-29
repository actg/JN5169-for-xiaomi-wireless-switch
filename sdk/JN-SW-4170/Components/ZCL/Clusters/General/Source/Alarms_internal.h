/*****************************************************************************
 *
 * MODULE:             Alarms Cluster
 *
 * COMPONENT:          Alarms_internal.h
 *
 * AUTHOR:             Lee Mitchell
 *
 * DESCRIPTION:        The internal API for the Alarms Cluster
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/Components/ZCL/Trunk/Clusters/General/Source/Alarms_internal.h $
 *
 * $Revision: 72260 $
 *
 * $LastChangedBy: nxp57621 $
 *
 * $LastChangedDate: 2015-08-26 09:12:34 +0200 (Wed, 26 Aug 2015) $
 *
 * $Id: Alarms_internal.h 72260 2015-08-26 07:12:34Z nxp57621 $
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

#ifndef  ALARMS_INTERNAL_H_INCLUDED
#define  ALARMS_INTERNAL_H_INCLUDED

#if defined __cplusplus
extern "C" {
#endif

/****************************************************************************/
/***        Include Files                                                 ***/
/****************************************************************************/

#include <jendefs.h>

#include "zcl.h"
#include "Alarms.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC teZCL_Status eCLD_AlarmsCommandHandler(
                    ZPS_tsAfEvent               *pZPSevent,
                    tsZCL_EndPointDefinition    *psEndPointDefinition,
                    tsZCL_ClusterInstance       *psClusterInstance);

#ifdef ALARMS_SERVER
PUBLIC teZCL_Status eCLD_AlarmsCommandResetAlarmCommandReceive(
                    ZPS_tsAfEvent               *pZPSevent,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_AlarmsResetAlarmCommandPayload *psPayload);

PUBLIC teZCL_Status eCLD_AlarmsCommandResetAllAlarmsCommandReceive(
                    ZPS_tsAfEvent               *pZPSevent,
                    uint8                       *pu8TransactionSequenceNumber);

PUBLIC teZCL_Status eCLD_AlarmsCommandGetAlarmCommandReceive(
                    ZPS_tsAfEvent               *pZPSevent,
                    uint8                       *pu8TransactionSequenceNumber);

PUBLIC teZCL_Status eCLD_AlarmsCommandResetAlarmLogCommandReceive(
                    ZPS_tsAfEvent               *pZPSevent,
                    uint8                       *pu8TransactionSequenceNumber);

PUBLIC teZCL_Status eCLD_AlarmsCommandAlarmCommandSend(
                    uint8                       u8SourceEndPointId,
                    uint8                       u8DestinationEndPointId,
                    tsZCL_Address               *psDestinationAddress,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_AlarmsAlarmCommandPayload *psPayload);
                    
PUBLIC teZCL_Status eCLD_AlarmsCommandGetAlarmResponseSend(
                    uint8                       u8SourceEndPointId,
                    uint8                       u8DestinationEndPointId,
                    tsZCL_Address               *psDestinationAddress,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_AlarmsGetAlarmResponsePayload *psPayload);
#endif
    
#ifdef ALARMS_CLIENT    
PUBLIC teZCL_Status eCLD_AlarmsCommandAlarmCommandReceive(
                    ZPS_tsAfEvent               *pZPSevent,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_AlarmsAlarmCommandPayload *psPayload);
                    
PUBLIC teZCL_Status eCLD_AlarmsCommandGetAlarmResponseReceive(
                    ZPS_tsAfEvent               *pZPSevent,
                    uint8                       *pu8TransactionSequenceNumber,
                    tsCLD_AlarmsGetAlarmResponsePayload *psPayload);
#endif
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

#if defined __cplusplus
}
#endif

#endif  /* ALARMS_INTERNAL_H_INCLUDED */

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

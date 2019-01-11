/*****************************************************************************
 *
 * MODULE:             Smart Energy
 *
 * COMPONENT:          zcl_heap.h
 *
 * AUTHOR:             we1
 *
 * DESCRIPTION:        Manages the heap used to allocate memory to components. Simple design:
 * doesn't allow the memory to be returned.
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/UnifiedZCL_ZLL102_HA122_Maintenance/Include/zcl_heap.h $
 *
 * $Revision: 81838 $
 *
 * $LastChangedBy: nxp46755 $
 *
 * $LastChangedDate: 2016-07-27 07:33:01 +0100 (Wed, 27 Jul 2016) $
 *
 * $Id: zcl_heap.h 81838 2016-07-27 06:33:01Z nxp46755 $
 *
 ****************************************************************************
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
#ifndef  ZCL_HEAP_H_INCLUDED
#define  ZCL_HEAP_H_INCLUDED

#if defined __cplusplus
extern "C" {
#endif

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include <jendefs.h>
#include "dlist.h"
#include "zcl.h"
#include "zcl_customcommand.h"

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/* ZCL_INTERNAL_TIMERS is 1 because the ZCL needs a timer of its own for reporting.
   u8NumberOfTimers in the heap size macro is the number of timers required outside of the ZCL.*/
#define ZCL_INTERNAL_TIMERS (1)

#ifndef ZCL_ATTRIBUTE_REPORT_STRING_MAXIMUM_SIZE
    #define ZCL_ATTRIBUTE_REPORT_STRING_MAXIMUM_SIZE        32
#endif    

typedef struct
{
    bool_t                    bRegistered;
    tsZCL_EndPointDefinition *psEndPointDefinition;
} tsZCL_EndPointRecord;

typedef struct {
    DNODE                       dllTimeNode;
    teZCL_TimerMode             eTimerMode;
    uint32                      u32UTCTime;
    tfpZCL_ZCLCallBackFunction  pfZCLCallBackFunction;
} tsZCL_TimerRecord;

typedef struct
{
    DNODE dllReportNode;
    tsZCL_EndPointDefinition    *psEndPointDefinition;
    tsZCL_ClusterInstance       *psClusterInstance;
    tsZCL_AttributeDefinition   *psAttributeDefinition;
    // tsZCL_ReceiveEventAddress    sReceiveEventAddress;  Now sending events bound
    tuZCL_AttributeStorage       uAttributeStorage;
    uint32                       u32LastFiredUTCTime;
    tsZCL_AttributeReportingConfigurationRecord sAttributeReportingConfigurationRecord;
} tsZCL_ReportRecord;

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
// ZCL_INTERNAL_TIMERS is 1 because the ZCL now needs a timer of its own for reporting.  u8NumberOfTimers in the heap size macro is the number of timers required outside of the ZCL.
#define ZCL_HEAP_SIZE(u8NumberOfEndpoints, u8NumberOfTimers, u8NumberOfReports , u8NumberOfStringReports) (ENDPOINT_SIZE_WORDS(u8NumberOfEndpoints) + TIMER_SIZE_WORDS((u8NumberOfTimers+ZCL_INTERNAL_TIMERS)) + REPORT_SIZE_WORDS(u8NumberOfReports) + STRING_REPORT_SIZE_WORDS(u8NumberOfStringReports))

#define ENDPOINT_SIZE(u8NumberOfEndpoints)                ((sizeof(tsZCL_EndPointRecord)+ 4) * u8NumberOfEndpoints)
#define ENDPOINT_SIZE_WORDS(u8NumberOfEndpoints)          ((ENDPOINT_SIZE(u8NumberOfEndpoints) + 4)/4)

#define TIMER_SIZE(u8NumberOfTimers)                      ((sizeof(tsZCL_TimerRecord)+ 4) * u8NumberOfTimers)
#define TIMER_SIZE_WORDS(u8NumberOfTimers)                ((TIMER_SIZE(u8NumberOfTimers) + 4)/4)

#define REPORT_SIZE(u8NumberOfReports)                    ((sizeof(tsZCL_ReportRecord)+ 4) * u8NumberOfReports)
#define REPORT_SIZE_WORDS(u8NumberOfReports)              ((REPORT_SIZE(u8NumberOfReports) + 4)/4)

#define STRING_REPORT_SIZE(u8NumberOfStringReports)       ((ZCL_ATTRIBUTE_REPORT_STRING_MAXIMUM_SIZE + 4) * u8NumberOfStringReports)
#define STRING_REPORT_SIZE_WORDS(u8NumberOfStringReports) ((STRING_REPORT_SIZE(u8NumberOfStringReports) + 4)/4)
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
/***        Imported Functions                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

#if defined __cplusplus
}
#endif

#endif  /* ZCL_HEAP_H_INCLUDED */

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

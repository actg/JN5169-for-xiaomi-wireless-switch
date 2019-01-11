/*****************************************************************************
 *
 * MODULE:             Fan Control Cluster
 *
 * COMPONENT:          FanControl.c
 *
 * AUTHOR:             Shweta Chauhan
 *
 * DESCRIPTION:        Fan Control cluster definition
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/HA1_x_1v0/ZCL/Clusters/General/Source/FanControl.c $
 *
 * $Revision: 53274 $
 *
 * $LastChangedBy: nxp57621 $
 *
 * $LastChangedDate: 2013-04-16 11:39:09 +0530 (Tue, 16 Apr 2013) $
 *
 * $Id: FanControl.c 53274 2013-04-16 06:09:09Z nxp57621 $
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
#include "zcl_options.h"
#include "FanControl.h"
#include "dbg.h"

#ifdef DEBUG_CLD_FAN_CONTROL
#define TRACE_FAN_CONTROL    TRUE
#else
#define TRACE_FAN_CONTROL    FALSE
#endif

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#if defined(CLD_FAN_CONTROL) && !defined(FAN_CONTROL_SERVER) && !defined(FAN_CONTROL_CLIENT)
#error You Must Have either FAN_CONTROL_SERVER and/or FAN_CONTROL_CLIENT defined in zcl_options.h
#endif

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
#ifdef CLD_FAN_CONTROL
/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
#if defined FAN_CONTROL_SERVER
    const tsZCL_AttributeDefinition asCLD_FanControlClusterAttributeDefinitions[] = {

        {E_CLD_FAN_CONTROL_ATTR_ID_FAN_MODE,                        (E_ZCL_AF_RD|E_ZCL_AF_WR),               E_ZCL_ENUM8,   (uint32)(&((tsCLD_FanControl*)(0))->eFanMode),0},    /* Mandatory */

        {E_CLD_FAN_CONTROL_ATTR_ID_FAN_MODE_SEQUENCE,               (E_ZCL_AF_RD|E_ZCL_AF_WR),               E_ZCL_ENUM8,   (uint32)(&((tsCLD_FanControl*)(0))->eFanModeSequence),0},    /* Mandatory */
        
    };

    tsZCL_ClusterDefinition sCLD_FanControl = {
            HVAC_CLUSTER_ID_FANCONTROL,
            FALSE,
            E_ZCL_SECURITY_NETWORK,
            (sizeof(asCLD_FanControlClusterAttributeDefinitions) / sizeof(tsZCL_AttributeDefinition)),
            (tsZCL_AttributeDefinition*)asCLD_FanControlClusterAttributeDefinitions,
            NULL
    };
	
    uint8 au8FanControlServerAttributeControlBits[(sizeof(asCLD_FanControlClusterAttributeDefinitions) / sizeof(tsZCL_AttributeDefinition))];	
#else
    tsZCL_ClusterDefinition sCLD_FanControl = {
            HVAC_CLUSTER_ID_FANCONTROL,
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
 **
 ** NAME:       eCLD_FanControlCreateFanControl
 **
 ** DESCRIPTION:
 ** Creates a Fan Control cluster
 **
 ** PARAMETERS:                 Name                                Usage
 ** tsZCL_ClusterInstance      *psClusterInstance                   Cluster structure
 ** bool_t                      bIsServer                           Server Client flag
 ** tsZCL_ClusterDefinition    *psClusterDefinition                 Cluster Definition
 ** void                       *pvEndPointSharedStructPtr           EndPoint Shared Structure
 ** uint8                      *pu8AttributeControlBits             Attribute Control Bits
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/
PUBLIC  teZCL_Status eCLD_FanControlCreateFanControl(
                tsZCL_ClusterInstance                   *psClusterInstance,
                bool_t                                  bIsServer,
                tsZCL_ClusterDefinition                 *psClusterDefinition,
                void                                    *pvEndPointSharedStructPtr,
                uint8                                   *pu8AttributeControlBits)
{

    #ifdef STRICT_PARAM_CHECK 
        /* Parameter check */
           if((psClusterInstance==NULL) ||
           (psClusterDefinition==NULL)  )
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
                       NULL);

    #if defined FAN_CONTROL_SERVER
        if(psClusterInstance->pvEndPointSharedStructPtr != NULL)
        {
            /* Set attribute default values */
            ((tsCLD_FanControl*)pvEndPointSharedStructPtr)->eFanMode = E_CLD_FANCONTROL_FAN_MODE_AUTO;
            ((tsCLD_FanControl*)pvEndPointSharedStructPtr)->eFanModeSequence = E_CLD_FANCONTROL_FAN_MODE_SEQUENCE_LMHA;
        }
    #endif
    return E_ZCL_SUCCESS;

}

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

#endif   /* #define CLD_FAN_CONTROL */
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/


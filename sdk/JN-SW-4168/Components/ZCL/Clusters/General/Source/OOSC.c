/*****************************************************************************
 *
 * MODULE:             On/Off Switch Configuration Cluster
 *
 * COMPONENT:          OOSC.c
 *
 * AUTHOR:             Lee Mitchell
 *
 * DESCRIPTION:        On/Off switch configuration cluster definition
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/UnifiedZCL_ZLL102_HA122_Maintenance/Clusters/General/Source/OOSC.c $
 *
 * $Revision: 66146 $
 *
 * $LastChangedBy: nxp58432 $
 *
 * $LastChangedDate: 2014-11-28 10:58:55 +0000 (Fri, 28 Nov 2014) $
 *
 * $Id: OOSC.c 66146 2014-11-28 10:58:55Z nxp58432 $
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
#include "OOSC.h"
#include "zcl_options.h"
#include "OOSC.h"


#ifdef CLD_OOSC

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

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
#ifdef OOSC_SERVER
    const tsZCL_AttributeDefinition asCLD_OOSCClusterAttributeDefinitions[] = {

        {E_CLD_OOSC_ATTR_ID_SWITCH_TYPE,    E_ZCL_AF_RD,                E_ZCL_ENUM8,    (uint32)(&((tsCLD_OOSC*)(0))->eSwitchType),0},    /* Mandatory */

        {E_CLD_OOSC_ATTR_ID_SWITCH_ACTIONS, (E_ZCL_AF_RD|E_ZCL_AF_WR),  E_ZCL_ENUM8,    (uint32)(&((tsCLD_OOSC*)(0))->eSwitchActions),0}, /* Mandatory */

    };
    tsZCL_ClusterDefinition sCLD_OOSC = {
            GENERAL_CLUSTER_ID_ONOFF_SWITCH_CONFIGURATION,
            FALSE,
            E_ZCL_SECURITY_NETWORK,
            (sizeof(asCLD_OOSCClusterAttributeDefinitions) / sizeof(tsZCL_AttributeDefinition)),
            (tsZCL_AttributeDefinition*)asCLD_OOSCClusterAttributeDefinitions,
            NULL
    };
    uint8 au8OOSCServerAttributeControlBits[(sizeof(asCLD_OOSCClusterAttributeDefinitions) / sizeof(tsZCL_AttributeDefinition))];

#else
    tsZCL_ClusterDefinition sCLD_OOSC = {
            GENERAL_CLUSTER_ID_ONOFF_SWITCH_CONFIGURATION,
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
 ** NAME:       eCLD_OOSCCreateOnOffSwitchConfig
 **
 ** DESCRIPTION:
 ** Creates an on/off cluster
 **
 ** PARAMETERS:                 Name                        Usage
 ** tsZCL_ClusterInstance    *psClusterInstance             Cluster structure
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/

PUBLIC  teZCL_Status eCLD_OOSCCreateOnOffSwitchConfig(
                tsZCL_ClusterInstance              *psClusterInstance,
                bool_t                              bIsServer,
                tsZCL_ClusterDefinition            *psClusterDefinition,
                void                               *pvEndPointSharedStructPtr,
                uint8                              *pu8AttributeControlBits)
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
                                   NULL);    
    #ifdef OOSC_SERVER
        if(pvEndPointSharedStructPtr != NULL)
        {
            /* Set attribute defaults */
            ((tsCLD_OOSC*)psClusterInstance->pvEndPointSharedStructPtr)->eSwitchActions = 0x00;
        }
    #endif
    //  register timer
    return E_ZCL_SUCCESS;

}

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

#endif
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/


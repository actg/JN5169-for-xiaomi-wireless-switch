/*****************************************************************************
 *
 * MODULE:             Fan Control Cluster
 *
 * COMPONENT:          FanControl.h
 *
 * AUTHOR:             Shweta Chauhan
 * DESCRIPTION:        Header for FanControl Cluster
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/HA1_x_1v0/ZCL/Clusters/General/Include/FanControl.h $
 *
 * $Revision: 53326 $
 *
 * $LastChangedBy: nxp57621 $
 *
 * $LastChangedDate: 2013-04-17 11:51:06 +0530 (Wed, 17 Apr 2013) $
 *
 * $Id: FanControl.h 53326 2013-04-17 06:21:06Z nxp57621 $
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

#ifndef FANCONTROL_H
#define FANCONTROL_H

#include <jendefs.h>
#include "zcl.h"
#include "zcl_options.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/* Cluster ID's */
#define HVAC_CLUSTER_ID_FANCONTROL                                     0x0202

/****************************************************************************/
/*             Fan_Control Control Cluster - Optional Attributes             */
/*                                                                          */
/* Add the following #define's to your zcl_options.h file to add optional   */
/* attributes to the Fan Control cluster.                                 */
/****************************************************************************/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
typedef enum 
{
    /* Fan Control attribute set attribute ID's (A1) */
    E_CLD_FAN_CONTROL_ATTR_ID_FAN_MODE                  = 0x0000,             /* 0.Mandatory */
    E_CLD_FAN_CONTROL_ATTR_ID_FAN_MODE_SEQUENCE,                              /* 1.Mandatory */
} teCLD_FanControl_Cluster_AttrID; 

/* Lock State */
typedef enum 
{
    E_CLD_FANCONTROL_FAN_MODE_OFF  = 0x00,
    E_CLD_FANCONTROL_FAN_MODE_LOW,
    E_CLD_FANCONTROL_FAN_MODE_MEDIUM,
	E_CLD_FANCONTROL_FAN_MODE_HIGH,
	E_CLD_FANCONTROL_FAN_MODE_ON,
	E_CLD_FANCONTROL_FAN_MODE_AUTO,
	E_CLD_FANCONTROL_FAN_MODE_SMART
} teCLD_FanControl_FanMode;

typedef enum 
{
    E_CLD_FANCONTROL_FAN_MODE_SEQUENCE_LMH  = 0x00,
    E_CLD_FANCONTROL_FAN_MODE_SEQUENCE_LH,
    E_CLD_FANCONTROL_FAN_MODE_SEQUENCE_LMHA,
	E_CLD_FANCONTROL_FAN_MODE_SEQUENCE_LHA,
	E_CLD_FANCONTROL_FAN_MODE_SEQUENCE_OA
} teCLD_FanControl_;


/* Fan Control Cluster */
typedef struct
{
 #ifdef FAN_CONTROL_SERVER   
    zenum8                   eFanMode;
    zenum8                   eFanModeSequence;
 #endif

} tsCLD_FanControl;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC teZCL_Status eCLD_FanControlCreateFanControl(
                tsZCL_ClusterInstance                  *psClusterInstance,
                bool_t                                 bIsServer,
                tsZCL_ClusterDefinition                *psClusterDefinition,
                void                                   *pvEndPointSharedStructPtr,
                uint8                                  *pu8AttributeControlBits);

/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/

extern tsZCL_ClusterDefinition sCLD_FanControl;
#if (defined CLD_FAN_CONTROL) && (defined FAN_CONTROL_SERVER)
    extern const tsZCL_AttributeDefinition asCLD_FanControlClusterAttributeDefinitions[];
    extern uint8 au8FanControlServerAttributeControlBits[];
#endif


/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

#endif /* FANCONTROL_H */

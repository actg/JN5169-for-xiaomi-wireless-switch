/*****************************************************************************
 *
 * MODULE:             Relative Humidity Measurement Cluster
 *
 * COMPONENT:          RelativeHumidityMeasurement.h
 *
 * AUTHOR:             Lee Mitchell
 *
 * DESCRIPTION:        Header for Relative Humidity Measurement Cluster
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/UnifiedZCL_ZLL102_HA122_Maintenance/Clusters/MeasurementAndSensing/Include/RelativeHumidityMeasurement.h $
 *
 * $Revision: 65938 $
 *
 * $LastChangedBy: nxp57621 $
 *
 * $LastChangedDate: 2014-11-24 06:39:16 +0000 (Mon, 24 Nov 2014) $
 *
 * $Id: RelativeHumidityMeasurement.h 65938 2014-11-24 06:39:16Z nxp57621 $
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

#ifndef RELATIVE_HUMIDITY_MEASUREMENT_H
#define RELATIVE_HUMIDITY_MEASUREMENT_H

#include <jendefs.h>
#include "zcl.h"
#include "zcl_options.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/*       Relative Humidity Measurement Cluster - Optional Attributes        */
/*                                                                          */
/* Add the following #define's to your zcl_options.h file to add optional   */
/* attributes to the relative humidity measurement cluster.                 */
/****************************************************************************/

/* Enable the optional Tolerance attribute */
//#define CLD_RHMEAS_ATTR_TOLERANCE

/* End of optional attributes */


/* Cluster ID's */
#define MEASUREMENT_AND_SENSING_CLUSTER_ID_RELATIVE_HUMIDITY_MEASUREMENT  0x0405


/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

typedef enum 
{
    /* Relative Humidity Measurement Information attribute set attribute ID's (4.7.2.2.1) */
    E_CLD_RHMEAS_ATTR_ID_MEASURED_VALUE          = 0x0000,  /* Mandatory */
    E_CLD_RHMEAS_ATTR_ID_MIN_MEASURED_VALUE,                /* Mandatory */
    E_CLD_RHMEAS_ATTR_ID_MAX_MEASURED_VALUE,                /* Mandatory */
    E_CLD_RHMEAS_ATTR_ID_TOLERANCE,
} teCLD_RHM_ClusterID;


/* Relative Humidity Measurement Cluster */
typedef struct
{
    zuint16                u16MeasuredValue;

    zuint16                u16MinMeasuredValue;

    zuint16                u16MaxMeasuredValue;

#ifdef CLD_RHMEAS_ATTR_TOLERANCE
    zuint16                u16Tolerance;
#endif

} tsCLD_RelativeHumidityMeasurement;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC teZCL_Status eCLD_RelativeHumidityMeasurementCreateRelativeHumidityMeasurement(
                tsZCL_ClusterInstance              *psClusterInstance,
                bool_t                              bIsServer,
                tsZCL_ClusterDefinition            *psClusterDefinition,
                void                               *pvEndPointSharedStructPtr,
                uint8              *pu8AttributeControlBits);

/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/
extern tsZCL_ClusterDefinition sCLD_RelativeHumidityMeasurement;

#ifdef RELATIVE_HUMIDITY_MEASUREMENT_SERVER
    extern uint8 au8RelativeHumidityMeasurementServerAttributeControlBits[];
    extern const tsZCL_AttributeDefinition asCLD_RelativeHumidityMeasurementClusterAttributeDefinitions[];
#endif
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

#endif /* RELATIVE_HUMIDITY_MEASUREMENT_H */

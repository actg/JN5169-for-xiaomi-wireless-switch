/*****************************************************************************
 *
 * MODULE:             Illuminance Measurement Cluster
 *
 * COMPONENT:          IlluminanceMeasurement.h
 *
 * AUTHOR:             Lee Mitchell
 *
 * DESCRIPTION:        Header for Illuminance Measurement Cluster
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/UnifiedZCL_ZLL102_HA122_Maintenance/Clusters/MeasurementAndSensing/Include/IlluminanceMeasurement.h $
 *
 * $Revision: 65827 $
 *
 * $LastChangedBy: nxp57621 $
 *
 * $LastChangedDate: 2014-11-20 11:34:13 +0000 (Thu, 20 Nov 2014) $
 *
 * $Id: IlluminanceMeasurement.h 65827 2014-11-20 11:34:13Z nxp57621 $
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

#ifndef ILLUMINANCE_MEASUREMENT_H
#define ILLUMINANCE_MEASUREMENT_H

#include <jendefs.h>
#include "zcl.h"
#include "zcl_options.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/*             Illuminance Measurement Cluster - Optional Attributes        */
/*                                                                          */
/* Add the following #define's to your zcl_options.h file to add optional   */
/* attributes to the illuminance measurement cluster.                       */
/****************************************************************************/

/* Enable the optional Tolerance attribute */
//#define CLD_ILLMEAS_ATTR_TOLERANCE

/* Enable the optional Light Sensor Type attribute */
//#define CLD_ILLMEAS_ATTR_LIGHT_SENSOR_TYPE

/* End of optional attributes */


/* Cluster ID's */
#define MEASUREMENT_AND_SENSING_CLUSTER_ID_ILLUMINANCE_MEASUREMENT  0x0400


/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

typedef enum 
{
    /* Illuminance Level Sensing Information attribute set attribute ID's (4.2.2.2.1) */
    E_CLD_ILLMEAS_ATTR_ID_MEASURED_VALUE          = 0x0000,  /* Mandatory */
    E_CLD_ILLMEAS_ATTR_ID_MIN_MEASURED_VALUE,                /* Mandatory */
    E_CLD_ILLMEAS_ATTR_ID_MAX_MEASURED_VALUE,                /* Mandatory */
    E_CLD_ILLMEAS_ATTR_ID_TOLERANCE,
    E_CLD_ILLMEAS_ATTR_ID_LIGHT_SENSOR_TYPE
} teCLD_IM_ClusterID;


/* Light sensor types */
typedef enum 
{
    E_CLD_ILLMEAS_LST_PHOTODIODE = 0,
    E_CLD_ILLMEAS_LST_CMOS
} teCLD_IMEAS_LightSensorType;


/* Illuminance Measurement Cluster */
typedef struct
{
    zuint16                u16MeasuredValue;

    zuint16                u16MinMeasuredValue;

    zuint16                u16MaxMeasuredValue;

#ifdef CLD_ILLMEAS_ATTR_TOLERANCE
    zuint16                u16Tolerance;
#endif

#ifdef CLD_ILLMEAS_ATTR_LIGHT_SENSOR_TYPE
    zenum8                  eLightSensorType;
#endif

} tsCLD_IlluminanceMeasurement;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC teZCL_Status eCLD_IlluminanceMeasurementCreateIlluminanceMeasurement(
                tsZCL_ClusterInstance              *psClusterInstance,
                bool_t                              bIsServer,
                tsZCL_ClusterDefinition            *psClusterDefinition,
                void                               *pvEndPointSharedStructPtr,
                uint8                              *pu8AttributeControlBits);

/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/

extern tsZCL_ClusterDefinition sCLD_IlluminanceMeasurement;
#if (defined CLD_ILLUMINANCE_MEASUREMENT) && (defined ILLUMINANCE_MEASUREMENT_SERVER)
    extern const tsZCL_AttributeDefinition asCLD_IlluminanceMeasurementClusterAttributeDefinitions[];
    extern uint8 au8IlluminanceMeasurementServerAttributeControlBits[];
#endif

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

#endif /* ILLUMINANCE_MEASUREMENT_H */

/*****************************************************************************
 *
 * MODULE:             Temperature Measurement Cluster
 *
 * COMPONENT:          TemperatureMeasurement.h
 *
 * AUTHOR:             Lee Mitchell
 *
 * DESCRIPTION:        Header for Temperature Measurement Cluster
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/UnifiedZCL_ZLL102_HA122_Maintenance/Clusters/MeasurementAndSensing/Include/TemperatureMeasurement.h $
 *
 * $Revision: 65965 $
 *
 * $LastChangedBy: nxp58432 $
 *
 * $LastChangedDate: 2014-11-25 05:39:23 +0000 (Tue, 25 Nov 2014) $
 *
 * $Id: TemperatureMeasurement.h 65965 2014-11-25 05:39:23Z nxp58432 $
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

#ifndef TEMPERATURE_MEASUREMENT_H
#define TEMPERATURE_MEASUREMENT_H

#include <jendefs.h>
#include "zcl.h"
#include "zcl_options.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/*       Temperature Measurement Cluster - Optional Attributes              */
/*                                                                          */
/* Add the following #define's to your zcl_options.h file to add optional   */
/* attributes to the temperature measurement cluster.                       */
/****************************************************************************/

/* Enable the optional Tolerance attribute */
//#define CLD_TEMPMEAS_ATTR_TOLERANCE

/* End of optional attributes */


/* Cluster ID's */
#define MEASUREMENT_AND_SENSING_CLUSTER_ID_TEMPERATURE_MEASUREMENT  0x0402


/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

typedef enum 
{
    /* Temperature Measurement Information attribute set attribute ID's (4.4.2.2.1) */
    E_CLD_TEMPMEAS_ATTR_ID_MEASURED_VALUE          = 0x0000,  /* Mandatory */
    E_CLD_TEMPMEAS_ATTR_ID_MIN_MEASURED_VALUE,                /* Mandatory */
    E_CLD_TEMPMEAS_ATTR_ID_MAX_MEASURED_VALUE,                /* Mandatory */
    E_CLD_TEMPMEAS_ATTR_ID_TOLERANCE,
} teCLD_TemperatureMeasurement_AttributeID;

/* Temperature Measurement Cluster */
typedef struct
{
    zint16                 i16MeasuredValue;

    zint16                 i16MinMeasuredValue;

    zint16                 i16MaxMeasuredValue;

#ifdef CLD_TEMPMEAS_ATTR_TOLERANCE
    zuint16                u16Tolerance;
#endif

} tsCLD_TemperatureMeasurement;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC teZCL_Status eCLD_TemperatureMeasurementCreateTemperatureMeasurement(
                tsZCL_ClusterInstance              *psClusterInstance,
                bool_t                              bIsServer,
                tsZCL_ClusterDefinition            *psClusterDefinition,
                void                               *pvEndPointSharedStructPtr,
                uint8              *pu8AttributeControlBits);

/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/

extern const tsZCL_AttributeDefinition asCLD_TemperatureMeasurementClusterAttributeDefinitions[];
extern tsZCL_ClusterDefinition sCLD_TemperatureMeasurement;
#ifdef TEMPERATURE_MEASUREMENT_SERVER

    extern uint8 au8TemperatureMeasurementServerAttributeControlBits[];
#endif

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

#endif /* TEMPERATURE_MEASUREMENT_H */

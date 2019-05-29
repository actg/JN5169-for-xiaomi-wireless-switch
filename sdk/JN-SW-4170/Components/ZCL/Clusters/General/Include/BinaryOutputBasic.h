/*****************************************************************************
 *
 * MODULE:             Binary Output Basic Cluster
 *
 * COMPONENT:          BinaryOutputBasic.h
 *
 * AUTHOR:             Shweta Chauhan
 *
 * DESCRIPTION:        Header for Binary Output Basic Cluster
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/HA1_x_1v0/ZCL/Clusters/General/Include/BinaryOutputBasic.h $
 *
 * $Revision: 52743 $
 *
 * $LastChangedBy: nxp57621 $
 *
 * $LastChangedDate: 2013-03-15 18:39:02 +0530 (Fri, 15 Mar 2013) $
 *
 * $Id: BinaryOutputBasic.h 52743 2013-03-15 13:09:02Z nxp57621 $
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

#ifndef BINARY_OUTPUT_BASIC_H
#define BINARY_OUTPUT_BASIC_H

#include <jendefs.h>
#include "zcl.h"
#include "zcl_options.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/*             Binary Output Basic Cluster - Optional Attributes                          */
/*                                                                          */
/* Add the following #define's to your zcl_options.h file to add optional   */
/* attributes to the binary input basic cluster.                                         */
/****************************************************************************/

/* Enable the optional Active Text attribute */
//#define   CLD_BINARY_OUTPUT_BASIC_ATTR_ACTIVE_TEXT

/* Enable the optional Description attribute*/
//#define   CLD_BINARY_OUTPUT_BASIC_ATTR_DESCRIPTION

/* Enable the optional Inactive text attribute */
//#define   CLD_BINARY_OUTPUT_BASIC_ATTR_INACTIVE_TEXT

/* Enable the optional Minimum Off Time attribute */
//#define   CLD_BINARY_OUTPUT_BASIC_ATTR_MINIMUM_OFF_TIME

/* Enable the optional Minimum On Time attribute */
//#define   CLD_BINARY_OUTPUT_BASIC_ATTR_MINIMUM_ON_TIME

/* Enable the optional Polarity attribute */
//#define   CLD_BINARY_OUTPUT_BASIC_ATTR_POLARITY

/* Enable the optional Relinquish Default attribute */
//#define   CLD_BINARY_OUTPUT_BASIC_ATTR_RELINQUISH_DEFAULT

/* Enable the optional Reliability attribute */
//#define   CLD_BINARY_OUTPUT_BASIC_ATTR_RELIABILITY

/* Enable the optional Application type attribute */
//#define   CLD_BINARY_OUTPUT_BASIC_ATTR_APPLICATION_TYPE

/* Enable the optional Attribute Reporting Status attribute */
//#define   CLD_BINARY_OUTPUT_BASIC_ATTR_ATTRIBUTE_REPORTING_STATUS

/* End of optional attributes */


/* Cluster ID's */
#define GENERAL_CLUSTER_ID_BINARY_OUTPUT_BASIC                            0x0010


/* 3.14.10.12 & 3.14.10.13 If either the ActiveText attribute or the InactiveText attribute are present, then both of them shall be
Present */
#if((defined CLD_BINARY_OUTPUT_BASIC_ATTR_ACTIVE_TEXT) || (defined CLD_BINARY_OUTPUT_BASIC_ATTR_INACTIVE_TEXT))
    #ifndef CLD_BINARY_OUTPUT_BASIC_ATTR_ACTIVE_TEXT
        #define CLD_BINARY_OUTPUT_BASIC_ATTR_ACTIVE_TEXT
    #endif
    #ifndef     CLD_BINARY_OUTPUT_BASIC_ATTR_INACTIVE_TEXT
        #define CLD_BINARY_OUTPUT_BASIC_ATTR_INACTIVE_TEXT
    #endif
#endif

#ifndef CLD_BINARY_OUTPUT_BASIC_CLUSTER_REVISION
    #define CLD_BINARY_OUTPUT_BASIC_CLUSTER_REVISION                         1
#endif 


/* Status Flags - bit definitions and bit masks */
#define BINARY_OUTPUT_BASIC_STATUS_FLAGS_IN_ALARM                              0
#define BINARY_OUTPUT_BASIC_STATUS_FLAGS_FAULT                                 1
#define BINARY_OUTPUT_BASIC_STATUS_FLAGS_OVERRIDDEN                            2
#define BINARY_OUTPUT_BASIC_STATUS_FLAGS_OUT_OF_SERVICE                        3

#define BINARY_OUTPUT_BASIC_STATUS_FLAGS_IN_ALARM_MASK                          (1 << BINARY_OUTPUT_BASIC_STATUS_FLAGS_IN_ALARM)
#define BINARY_OUTPUT_BASIC_STATUS_FLAGS_FAULT_MASK                             (1 << BINARY_OUTPUT_BASIC_STATUS_FLAGS_FAULT)
#define BINARY_OUTPUT_BASIC_STATUS_FLAGS_OVERRIDDEN_MASK                        (1 << BINARY_OUTPUT_BASIC_STATUS_FLAGS_OVERRIDDEN)
#define BINARY_OUTPUT_BASIC_STATUS_FLAGS_OUT_OF_SERVICE_MASK                    (1 << BINARY_OUTPUT_BASIC_STATUS_FLAGS_OUT_OF_SERVICE)

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/* Command codes */


typedef enum 
{
    /* Binary Output (Basic) Device Information attribute set attribute ID's (3.2.2.2.1) */
    E_CLD_BINARY_OUTPUT_BASIC_ATTR_ID_ACTIVE_TEXT                    =                0x0004, /* Optional */
    E_CLD_BINARY_OUTPUT_BASIC_ATTR_ID_DESCRIPTION                    =                0x001C, /*Optional */
    E_CLD_BINARY_OUTPUT_BASIC_ATTR_ID_INACTIVE_TEXT                  =                0x002E, /*Optional */
    E_CLD_BINARY_OUTPUT_BASIC_ATTR_ID_MINIMUM_OFF_TIME               =                0x0042, /*Optional */
    E_CLD_BINARY_OUTPUT_BASIC_ATTR_ID_MINIMUM_ON_TIME                =                0x0043, /*Optional */
    E_CLD_BINARY_OUTPUT_BASIC_ATTR_ID_OUT_OF_SERVICE                 =                0x0051, /*Mandatory */
    E_CLD_BINARY_OUTPUT_BASIC_ATTR_ID_POLARITY                       =                0x0054, /*Optional */
    E_CLD_BINARY_OUTPUT_BASIC_ATTR_ID_PRESENT_VALUE                  =                0x0055, /* Mandatory */
    E_CLD_BINARY_OUTPUT_BASIC_ATTR_ID_RELIABILITY                    =                0x0067, /*Optional */
    E_CLD_BINARY_OUTPUT_BASIC_ATTR_ID_RELINQUISH_DEFAULT             =                0x0068, /*Optional */
    E_CLD_BINARY_OUTPUT_BASIC_ATTR_ID_STATUS_FLAGS                   =                0x006F, /* Mandatory */
    E_CLD_BINARY_OUTPUT_BASIC_ATTR_ID_APPLICATION_TYPE               =                0x0100, /*Optional */
} teCLD_BinaryOutputBasicCluster_AttrID;



/* Polarity attribute */
typedef enum 
{ 
    E_CLD_BINARY_OUTPUT_BASIC_POLARITY_NORMAL                       =                0x0000,
    E_CLD_BINARY_OUTPUT_BASIC_POLARITY_REVERSE
}teCLD_BinaryOutputBasic_Polarity;


/* Reliability attribute */
typedef enum 
{ 
    E_CLD_BINARY_OUTPUT_BASIC_RELIABILITY_NO_FAULT_DETECTED         =                0x0000,
    E_CLD_BINARY_OUTPUT_BASIC_RELIABILITY_OVER_RANGE                =                0x0002,
    E_CLD_BINARY_OUTPUT_BASIC_RELIABILITY_UNDER_RANGE,
    E_CLD_BINARY_OUTPUT_BASIC_RELIABILITY_OPEN_LOOP,
    E_CLD_BINARY_OUTPUT_BASIC_RELIABILITY_SHORTED_LOOP,
    E_CLD_BINARY_OUTPUT_BASIC_RELIABILITY_UNRELIABLE_OTHER          =                0x0007,
    E_CLD_BINARY_OUTPUT_BASIC_RELIABILITY_PROCESS_ERROR,
    E_CLD_BINARY_OUTPUT_BASIC_RELIABILITY_CONFIGURATION_ERROR       =                0x000A 
 }teCLD_BinaryOutputBasic_Reliability;


/* Binary Output Basic Cluster */
#ifdef BINARY_OUTPUT_BASIC_SERVER
typedef struct
{
#ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_ACTIVE_TEXT
    tsZCL_CharacterString       sActiveText;
    uint8                       au8ActiveText[16];
#endif

#ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_DESCRIPTION                
    tsZCL_CharacterString       sDescription;
    uint8                       au8Description[16];
#endif

#ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_INACTIVE_TEXT
    tsZCL_CharacterString       sInactiveText;
    uint8                       au8InactiveText[16];
#endif

#ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_MINIMUM_OFF_TIME
    zuint32                     u32MinimumOffTime;
#endif

#ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_MINIMUM_ON_TIME
    zuint32                     u32MinimumOnTime;
#endif

    zbool                       bOutOfService;

#ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_POLARITY
    zenum8                      u8Polarity;
#endif

    zbool                       bPresentValue;

#ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_RELIABILITY
    zenum8                      u8Reliability;
#endif

#ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_RELINQUISH_DEFAULT
    zbool                       bRelinquishDefault;
#endif

    zbmap8                      u8StatusFlags;

#ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_APPLICATION_TYPE
    zuint32                     u32ApplicationType;
#endif

#ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_ATTRIBUTE_REPORTING_STATUS
    zenum8                      u8AttributeReportingStatus;
#endif

    zuint16                     u16ClusterRevision;
    
} tsCLD_BinaryOutputBasic;
#endif

#ifdef BINARY_OUTPUT_BASIC_CLIENT
typedef struct
{
    zuint16                     u16ClusterRevision;
} tsCLD_BinaryOutputBasicClient;
#endif
/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC teZCL_Status eCLD_BinaryOutputBasicCreateBinaryOutputBasic(
                tsZCL_ClusterInstance              *psClusterInstance,
                bool_t                              bIsServer,
                tsZCL_ClusterDefinition            *psClusterDefinition,
                void                               *pvEndPointSharedStructPtr,
                uint8                              *pu8AttributeControlBits);
                            
/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/
#ifdef BINARY_OUTPUT_BASIC_SERVER
    extern tsZCL_ClusterDefinition sCLD_BinaryOutputBasic;
    extern tsZCL_AttributeDefinition asCLD_BinaryOutputBasicClusterAttributeDefinitions[];
    extern uint8 au8BinaryOutputBasicAttributeControlBits[];
#endif
#ifdef BINARY_OUTPUT_BASIC_CLIENT
    extern tsZCL_ClusterDefinition sCLD_BinaryOutputBasicClient;
    extern tsZCL_AttributeDefinition asCLD_BinaryOutputBasicClientClusterAttributeDefinitions[];
    extern uint8 au8BinaryOutputBasicClientAttributeControlBits[];
#endif
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

#endif /* BASIC_H */

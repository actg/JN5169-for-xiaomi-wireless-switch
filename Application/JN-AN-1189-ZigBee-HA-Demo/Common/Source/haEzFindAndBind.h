/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          haEzFindAndBind.h
 *
 * DESCRIPTION:        HA EZ mode commissioning (Interface)
 *
 *****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products [NXP Microcontrollers such as JN5168, JN5164,
 * JN5161, JN5148, JN5142, JN5139].
 * You, and any third parties must reproduce the copyright and warranty notice
 * and any other legend of ownership on each copy or partial copy of the
 * software.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
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
 * Copyright NXP B.V. 2013. All rights reserved
 *
 ****************************************************************************/

#ifndef EZ_FIND_AND_BIND_H
#define EZ_FIND_AND_BIND_H

#if defined __cplusplus
extern "C" {
#endif


#include <jendefs.h>
#include "zcl.h"
#include "zcl_options.h"
#include "ha.h"
#include "zps_apl_aps.h"
#include "appZdpExtraction.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/* The time in minutes that a device will be in EZ Find and Bind state */
#ifndef EZ_MODE_TIME
#define EZ_MODE_TIME                            			 3
#endif

/* The time in seconds that a device will wait for identify
 * query response after broadcasting identify query request */
#ifndef EZ_RESPONSE_TIME
#define EZ_RESPONSE_TIME                            		10
#endif

/* maximum number of target devices that the device is going to bind.*/
#ifndef EZ_MAX_TARGET_DEVICES
#define EZ_MAX_TARGET_DEVICES                               10
#endif

#ifndef EZ_NUMBER_OF_ENDPOINTS
#define EZ_NUMBER_OF_ENDPOINTS								HA_NUMBER_OF_ENDPOINTS
#endif

#ifndef EZ_MAX_CLUSTER_EXCLUSION_SIZE
#define EZ_MAX_CLUSTER_EXCLUSION_SIZE					    5
#endif

#if !defined(EZ_MODE_INITIATOR) && !defined(EZ_MODE_TARGET)
#error " Either EZ_MODE_INITIATOR or EZ_MODE_TARGET should be defined "
#endif

#if (!defined(CLD_GROUPS) && (!defined (GROUPS_CLIENT ) ||!defined (GROUPS_SERVER) ) && defined (EZ_ENABLE_GROUP))
#error "EZ mode grouping requires Group Cluster. Please define CLD_GROUPS and GROUPS_CLIENT or GROUPS_SERVER"
#endif

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
/*EZ Find and Bind states */
typedef enum 
{
	E_EZ_FIND_AND_BIND_INITIAL_STATE,
	E_EZ_FIND_AND_BIND_INITIATOR_IN_PROGRESS,
	E_EZ_GROUPING_IN_PROGRESS_STATE,
	E_EZ_FIND_AND_BIND_TARGET_IN_PROGRESS
}teEZ_FindAndBindState;


/* EZ events */
typedef enum
{
	E_EZ_NONE,
	E_EZ_NO_DEVICE_IN_IDENTIFY_MODE,
	E_EZ_BIND_CREATED_FOR_TARGET,
	E_EZ_GROUP_CREATED_FOR_TARGET,
	E_EZ_BIND_FAILED,
	E_EZ_TIMEOUT
#ifdef EZ_CHECK_FOR_BINDING_GROUPING
	,
	E_EZ_CHECK_FOR_BIND_FOR_TARGET,
	E_EZ_CHECK_FOR_GROUP_FOR_TARGET
#endif
}teEZ_Events;

/* EZ modes */
typedef enum
{
	E_EZ_INITIATOR ,
	E_EZ_TARGET
}teEZ_Mode;

/* EZ status values */
typedef enum
{
	E_EZ_IDLE,
	E_EZ_FIND_AND_BIND_IN_PROGRESS,
	E_EZ_GROUPING_IN_PROGRESS,
	E_EZ_BUSY,
	E_EZ_ERROR
}teEZ_Status;

/* Status of the call for the exclusion list*/
typedef enum
{
	E_EZ_CLUSTER_EXCLUSION_SUCCESS,
	E_EZ_EXCLUSION_TABLE_FULL
}teEZ_ClusterExcludeStatus;

typedef struct
{
	uint8 u8DstEndpoint;
	uint16 u16NwkAddr;
	uint64 u64IeeeAddr;
}tsEZ_AddressDetails;

typedef struct
{
	uint8                          	u8Endpoint;
	teEZ_FindAndBindState          	eEZFindAndBindState;
	uint8							u8EZResponseWaitTime;
	uint16							u16EZTime;
	tsEZ_AddressDetails				aAddressDetails [EZ_MAX_TARGET_DEVICES ];
}tsEZ_Info;

typedef struct{
	uint16 u16ClusterId;
	bool_t bServer;
}tsClusterList;

typedef struct
{
	uint8               u8ExclusionClusterCount;
	uint16 				u16GroupID;
	tsClusterList       sClusterExclusionList[EZ_MAX_CLUSTER_EXCLUSION_SIZE];
	tsEZ_Info			sEZInfo[EZ_NUMBER_OF_ENDPOINTS];
}tsEZ_FindAndBind;


typedef struct{
	teEZ_Events eEventType;
	uint8 u8InitiatorEp;
	uint8 u8TargetEp;
	uint16 u16TargetAddress;
	union {
		uint16 u16ClusterId;
		uint16 u16GroupId;
	}uEvent;
#ifdef EZ_CHECK_FOR_BINDING_GROUPING
	ZPS_tsAfZdpEvent *psAfZdpEvent;
	bool bAllowBindOrGroup;
	bool bGroupCast;
#endif
}tsEZ_FindAndBindEvent;
/****************************************************************************/
/***        Exported Functions                                            ***/
PUBLIC teEZ_Status eEZ_FindAndBind(uint8 u8SourceEndpoint, teEZ_Mode eEZ_Mode);
PUBLIC void vEZ_Exit(uint8 u8SourceEndpoint);
PUBLIC void vEZ_FactoryReset(uint8 u8SourceEndpoint);


#ifdef EZ_ENABLE_GROUP
PUBLIC teEZ_Status eEZ_Group(uint8 u8SourceEndpoint, teEZ_Mode eEZ_Mode);
PUBLIC void vEZ_SetGroupId(uint16 u16GroupID);
PUBLIC uint16 u16EZ_GetGroupId(void);
#endif

PUBLIC void vEZ_EPCallBackHandler(tsZCL_CallBackEvent *pCallBackEvent);
PUBLIC teEZ_FindAndBindState eEZ_GetFindAndBindState(uint8 u8SourceEndpoint);
PUBLIC teEZ_ClusterExcludeStatus eEZ_ExcludeClusterFromEZBinding(uint16 u16ClusterID,bool_t bServer);
PUBLIC void vEZ_EZModeNWKFindAndBindHandler(ZPS_tsAfEvent *pZPSevent);

PUBLIC void vEZ_EZModeCb(tsEZ_FindAndBindEvent * psCallBackEvent);
/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

#if defined __cplusplus
}
#endif

#endif /* EZ_FIND_AND_BIND_H */

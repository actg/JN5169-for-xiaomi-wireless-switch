/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          haEzJoin.h
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

#ifndef EZ_JOIN_H
#define EZ_JOIN_H

#if defined __cplusplus
extern "C" {
#endif

#include <jendefs.h>
#include "zps_nwk_sap.h"
#include "zps_apl_af.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/*
 *
 * These may be overridden by adding #define's to zcl_options.h
 *
 */
/* The maximum number of network scan attempted by device in case of no networks found.*/
#ifndef MAX_DISCOVERY_ATTEMPT_PER_CHANNEL
#define MAX_DISCOVERY_ATTEMPT_PER_CHANNEL                   3
#endif

/* Max Descriptors per scan on a channel*/
#ifndef EZ_MAX_NETWORK_DESCRIPTOR
#define EZ_MAX_NETWORK_DESCRIPTOR					    	8
#endif

/* The time duration between intermediate scan attempts */
#ifndef DISCOVERY_TIMEOUT_IN_MS
#define DISCOVERY_TIMEOUT_IN_MS                           	1000
#endif

/* Joining Time out once attempted to join per attempt*/
#ifndef JOINING_TIMEOUT_IN_MS
#define JOINING_TIMEOUT_IN_MS								15000
#endif

/*Restarting the Scan Time from the previous scan */
#ifndef RESTART_TIME_IN_MS
#define RESTART_TIME_IN_MS									100
#endif

/* One minute in MS */
#ifndef BACKOFF_TIMEOUT_IN_MS
#define BACKOFF_TIMEOUT_IN_MS       						60000
#endif

/* Formation Time in MS*/
#ifndef	NWK_FORMATION_TIMEOUT_IN_MS
#define NWK_FORMATION_TIMEOUT_IN_MS							5000
#endif

/* Time for which the device will back off before the
 * next attaempt to join. As per HA spec it is 15 minutes */
#ifndef	BACKOFF_TIME_IN_MINUTES
#define BACKOFF_TIME_IN_MINUTES          					15
#endif

/*EZ Mode time in minutes = Permit Join Open Time */
#ifndef EZ_MODE_TIME
#define EZ_MODE_TIME                            			3
#endif

//#define SUPPORT_JOIN_ELSE_FORM
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
typedef enum 
{
 E_EZ_JOIN,
 E_EZ_REJOIN
}teEZ_JoinAction;
typedef enum 
{
	E_EZ_START,
	E_EZ_INPROGRESS,
	E_EZ_WAIT_FOR_SCAN,
	E_EZ_WAIT_DISCOVERY_TIMEOUT,
	E_EZ_JOINING_NETWORK,
	E_EZ_DEVICE_IN_NETWORK,
	E_EZ_NWK_FORMATION_TIMEOUT,
	E_EZ_BACKOFF,
	E_EZ_COMPLETED
}teEZ_State;

typedef enum
{
	E_EZ_JOIN_OR_FORM_BASED_ON_DEVICE_TYPE,
	E_EZ_JOIN_ELSE_FORM_IF_NO_NETWORK

}teEZ_SetUpPolicy;

typedef struct
{
	uint8              	u8EZSetUpState;
	uint8              	u8ScanAttempts;
	uint8 				u8ScanDurationInSec;
	uint8				u8IsPrimaryChannelsScanned;
	uint8 				u8SetUpTime;
	uint8				u8JoinIndex;
	uint8				u8DiscoveredNwkCount;
	#ifdef SUPPORT_JOIN_ELSE_FORM
	bool				bFormNwk;
	bool				bSetUpPolicy;
	#endif
	ZPS_tsNwkNetworkDescr asSavedNetworks[EZ_MAX_NETWORK_DESCRIPTOR];
}tsEZ_Join;

typedef enum 
{
	E_EZ_SCAN_ALL_CHANNEL_COMPLETED,
	E_EZ_SCAN_HALF_CHANNEL_COMPLETED
}eChannelsSelected;
/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
PUBLIC void vEZ_EZModeNWKJoinHandler(ZPS_tsAfEvent *pZPSevent,teEZ_JoinAction eJoinAction);
PUBLIC teEZ_State eEZ_GetJoinState(void);
PUBLIC ZPS_teStatus eEZ_UpdateEZState(teEZ_State eEZState);
PUBLIC void vEZ_SetDefaultAIBChMask(void);
PUBLIC void vEZ_RestoreDefaultAIBChMask(void);
PUBLIC void vEZ_ReJoin(void);

#ifdef SUPPORT_JOIN_ELSE_FORM
PUBLIC void vEZ_SetUpPolicy(teEZ_SetUpPolicy ePolicy);
PUBLIC void vEZ_FormNWK(void);
#endif
/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/
extern uint32 u32BackOffTime;
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

#if defined __cplusplus
}
#endif

#endif /* EZ_JOIN_H */

/*****************************************************************************
 *
 * MODULE:             JN-AN-1219
 *
 * COMPONENT:          app_events.h
 *
 * DESCRIPTION:        ZLO application generic event definitions
 *
 ****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products [NXP Microcontrollers such as JN5168, JN5179].
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
 * Copyright NXP B.V. 2016. All rights reserved
 *
 ***************************************************************************/

#ifndef APP_GENERIC_EVENTS_H_
#define APP_GENERIC_EVENTS_H_

#ifdef DimmerSwitch
    #include "zcl_options.h"
#endif
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
#ifdef ColorSceneController
#include "zll_commission.h"
#include "zll_utility.h"

#define TEN_HZ_TICK_TIME        ZPS_TSV_TIME_MSEC(100)


typedef enum
{
    APP_E_EVENT_NONE = 0,
    APP_E_EVENT_BUTTON_UP,
    APP_E_EVENT_BUTTON_DOWN,
    APP_E_EVENT_LEAVE_AND_RESET,
    APP_E_EVENT_TOUCH_LINK,
    APP_E_EVENT_EP_INFO_MSG,
    APP_E_EVENT_EP_LIST_MSG,
    APP_E_EVENT_GROUP_LIST_MSG,
    APP_E_EVENT_MAX
} APP_teEventType;

typedef struct
{
    uint8 u8Button;
#ifdef DR1199
    uint32 u32DIOState;
#endif
} APP_tsEventButton;

typedef struct
{
    uint8 u8Level;
} APP_tsEventLevel;

typedef struct
{
    uint16 u16SourceShortAddress;
    uint16 u16QueryTimeout;
} APP_tsEventHAQueryRsp;

/*
typedef struct
{
    uint16 u16NwkAddr;
    uint16 u16ProfileId;
    uint16 u16DeviceId;
    uint8  u8Endpoint;
    uint8 u8Version;
} APP_tsEventTouchLink;*/

#define APP_tsEventTouchLink tsCLD_ZllEndpointlistRecord

typedef struct {
    uint16 u16SrcAddr;
    tsCLD_ZllUtility_EndpointInformationCommandPayload sPayload;
} APP_tsEventEpInfoMsg;

typedef struct {
    uint8   u8SrcEp;
    uint16 u16SrcAddr;
    tsCLD_ZllUtility_GetEndpointListRspCommandPayload sPayload;
} APP_tsEventEpListMsg;

typedef struct {
    uint8   u8SrcEp;
    uint16 u16SrcAddr;
    tsCLD_ZllUtility_GetGroupIdRspCommandPayload sPayload;
} APP_tsEventGroupListMsg;

typedef struct
{
    APP_teEventType eType;
    union
    {
        APP_tsEventButton           sButton;
        APP_tsEventTouchLink        sTouchLink;
        APP_tsEventEpInfoMsg        sEpInfoMsg;
        APP_tsEventEpListMsg        sEpListMsg;
        APP_tsEventGroupListMsg     sGroupListMsg;
    }uEvent;
} APP_tsEvent;

typedef struct
{
    APP_teEventType eType;
    union
    {
        APP_tsEventButton                   sButton;
    }uEvent;
} APP_tsLightEvent;


#endif


#if defined( DimmerSwitch) || defined (EH_Switch)

typedef enum
{
    APP_E_EVENT_NONE = 0,
    APP_E_EVENT_BUTTON_UP,
    APP_E_EVENT_BUTTON_DOWN,
    APP_E_EVENT_BUTTON_ALL_UP,
    APP_E_EVENT_PGM_BUTTON_UP,
    APP_E_EVENT_PGM_BUTTON_DOWN,
    APP_E_EVENT_HA_IDENTIFY_QUERY_RESPONSE,
    APP_E_EVENT_LIGHT_ON,
    APP_E_EVENT_LIGHT_OFF,
    APP_E_EVENT_LEVEL_CHANGE,
    APP_E_EVENT_1HZ_TICK_TIMER_EXPIRED,
    APP_E_EVENT_10HZ_TICK_TIMER_EXPIRED,
    APP_E_EVENT_DATA_CONFIRM,
    APP_E_EVENT_DATA_CONFIRM_FAILED,
    APP_E_EVENT_TOUCH_LINK,
    APP_E_EVENT_EP_INFO_MSG,
    APP_E_EVENT_EP_LIST_MSG,
    APP_E_EVENT_GROUP_LIST_MSG,
    APP_E_EVENT_POR_IDENTIFY,
    APP_E_EVENT_GP_DECOMMISSION,
    APP_E_EVENT_POR_FACTORY_RESET,
    APP_E_EVENT_POR_PDM_RESET,
    APP_E_EVENT_MAX
} APP_teEventType;

typedef struct
{
    uint8 u8Button;
    uint32 u32DIOState;
} APP_tsEventButton;

typedef struct
{
    APP_teEventType eType;
    union
    {
        APP_tsEventButton                   sButton;
    }uEvent;
} APP_tsEvent;

typedef enum
{
    E_STARTUP,
    E_WAIT_STARTUP,
    E_REJOINING,
    E_RUNNING
} teNODE_STATES;

typedef struct
{
    teNODE_STATES   eNodeState;
    #ifdef CLD_OTA
        bool        bValid;
        uint64      u64IeeeAddrOfServer;
        uint16      u16NwkAddrOfServer;
        uint8       u8OTAserverEP;
    #endif
}tsDeviceDesc;
#endif

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
#ifdef ColorSceneController
PUBLIC bool bAddToEndpointTable(APP_tsEventTouchLink *psEndpointData);
#endif
/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#endif /*APP_GENERIC_EVENTS_H_*/

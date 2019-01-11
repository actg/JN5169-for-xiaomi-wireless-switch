/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          app_events.h
 *
 * DESCRIPTION:        Application Events
 *
 ****************************************************************************
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
 ***************************************************************************/

#ifndef APP_GENERIC_EVENTS_H_
#define APP_GENERIC_EVENTS_H_

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/


/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/


typedef enum
{
    APP_E_EVENT_NONE = 0,
    APP_E_EVENT_BUTTON_UP,
    APP_E_EVENT_BUTTON_DOWN,
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
    APP_E_EVENT_MAX,
    APP_E_EVENT_FAILED_DEBOUNCE,
    APP_E_EVENT_NO_BUTTON_CHANGE,
    APP_E_EVENT_PERIODIC_REPORT,
    APP_E_EVENT_SEND_REPORT,
    APP_E_EVENT_WAKE_TIMER,
    APP_E_EVENT_KEEPALIVE_START,
    APP_E_EVENT_KEEPALIVE_STOP
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
/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#endif /*APP_GENERIC_EVENTS_H_*/

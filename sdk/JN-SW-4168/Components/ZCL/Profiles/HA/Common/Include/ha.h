/*****************************************************************************
 *
 * MODULE:             Home Automation Profile
 *
 * COMPONENT:          ha.h
 *
 * AUTHOR:             Lee Mitchell
 *
 * DESCRIPTION:        Header for ZigBee Home Automation profile functions
 *
 * $HeadURL: $
 *
 * $Revision: $
 *
 * $LastChangedBy: $
 *
 * $LastChangedDate: $
 *
 * $Id: $
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

#ifndef HA_H
#define HA_H

#if defined __cplusplus
extern "C" {
#endif

#include <jendefs.h>
#include "zcl.h"
#include "zcl_options.h"
#include "Basic.h"
#include "LevelControl.h"
#include "Scenes.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/* Sets the number of endpoints that will be created by the ZCL library
 *
 * These may be overridden by adding #define's to zcl_options.h
 *
 */
#ifndef HA_NUMBER_OF_ENDPOINTS
#define HA_NUMBER_OF_ENDPOINTS                              1
#endif

/*
 * Add the following #define's to your zcl_options.h file to add optional
 * clusters.
 *
 * #define CLD_TIME
 *
 */

/* Home Automation Profile ID's */
#ifndef HA_PROFILE_ID
#define HA_PROFILE_ID                                       0x0104
#endif

#ifdef HA_SUPPORT_1V1

#define HA_MIN_GROUPS                                       8
#define HA_MIN_SCENES                                       16

#ifdef CLD_SCENES_MAX_NUMBER_OF_SCENES
#if (CLD_SCENES_MAX_NUMBER_OF_SCENES  <  HA_MIN_SCENES)
    #error Minimum number of scenes should be ateast 16
#endif
#endif

#ifdef CLD_GROUPS_MAX_NUMBER_OF_GROUPS
#if (CLD_GROUPS_MAX_NUMBER_OF_GROUPS  <  HA_MIN_GROUPS)
    #error Minimum number of groups should be ateast 8
#endif
#endif

#ifdef CLD_BAS_ATTR_PHYSICAL_ENVIRONMENT
/* Power source */
typedef enum 
{
    E_CLD_BAS_PE_ATRIUM                                            = 0x01,
    E_CLD_BAS_PE_BAR,
    E_CLD_BAS_PE_COURTYARD,
    E_CLD_BAS_PE_BATHROOM,
    E_CLD_BAS_PE_BEDROOM,
    E_CLD_BAS_PE_BILLIARD_ROOM,
    E_CLD_BAS_PE_UTILITY_ROOM,
    E_CLD_BAS_PE_CELLAR,
    E_CLD_BAS_PE_CLOSET,
    E_CLD_BAS_PE_THREATER,
    E_CLD_BAS_PE_OFFICE_0XB,
    E_CLD_BAS_PE_DECK,
    E_CLD_BAS_PE_DEN,
    E_CLD_BAS_PE_DINNING_ROOM,
    E_CLD_BAS_PE_ELECTRICAL_ROOM,
    E_CLD_BAS_PE_ELEVATOR,
    E_CLD_BAS_PE_ENTRY,
    E_CLD_BAS_PE_FAMILY_ROOM,
    E_CLD_BAS_PE_MAIN_FLOOR,
    E_CLD_BAS_PE_UPSTAIRS,
    E_CLD_BAS_PE_DOWNSTAIRS,
    E_CLD_BAS_PE_BASEMENT_LOWER_LEVEL,
    E_CLD_BAS_PE_GALLERY,
    E_CLD_BAS_PE_GAME_ROOM,
    E_CLD_BAS_PE_GARAGE,
    E_CLD_BAS_PE_GYM,
    E_CLD_BAS_PE_HALLWAY,
    E_CLD_BAS_PE_HOUSE,
    E_CLD_BAS_PE_KITCHEN,
    E_CLD_BAS_PE_LAUNDRY_ROOM,
    E_CLD_BAS_PE_LIBRARY,
    E_CLD_BAS_PE_MASTER_BEDROOM,
    E_CLD_BAS_PE_MUD_ROOM,
    E_CLD_BAS_PE_NURSERY,
    E_CLD_BAS_PE_PANTRY,
    E_CLD_BAS_PE_OFFICE_0X24,
    E_CLD_BAS_PE_OUTSIDE,
    E_CLD_BAS_PE_POOL,
    E_CLD_BAS_PE_PORCH,
    E_CLD_BAS_PE_SEWING_ROOM,
    E_CLD_BAS_PE_SITTING_ROOM,
    E_CLD_BAS_PE_STAIRWAY,
    E_CLD_BAS_PE_YARD,
    E_CLD_BAS_PE_ATTIC,
    E_CLD_BAS_PE_HOT_TUB,
    E_CLD_BAS_PE_LIVING_ROOM_0X2E,
    E_CLD_BAS_PE_SAUNA,
    E_CLD_BAS_PE_SHOP_WORKSHOP,
    E_CLD_BAS_PE_GUEST_BEDROOM,
    E_CLD_BAS_PE_GUEST_BATH,
    E_CLD_BAS_PE_POWDER_ROOM,
    E_CLD_BAS_PE_BACK_YARD,
    E_CLD_BAS_PE_FRONT_YARD,
    E_CLD_BAS_PE_PATIO,
    E_CLD_BAS_PE_DRIVEWAY,
    E_CLD_BAS_PE_SUN_ROOM,
    E_CLD_BAS_PE_LIVING_ROOM_0X39,
    E_CLD_BAS_PE_SPA,
    E_CLD_BAS_PE_WHIRLPOOL,
    E_CLD_BAS_PE_SHED,
    E_CLD_BAS_PE_EQUIPMENT_STORAGE,
    E_CLD_BAS_PE_HOBBY_CRAFT_ROOM,
    E_CLD_BAS_PE_FOUNTAIN,
    E_CLD_BAS_PE_POND,
    E_CLD_BAS_PE_RECEPTION_ROOM,
    E_CLD_BAS_PE_BREAKFAST_ROOM,
    E_CLD_BAS_PE_NOOK,
    E_CLD_BAS_PE_GARDEN,
    E_CLD_BAS_PE_PANIC_ROOM,
    E_CLD_BAS_PE_TERRACE,
    E_CLD_BAS_PE_ROOF
} teCLD_BAS_PhysicalEnvironment;
#endif
#endif
/*
On/Off Switch 0x0000
Level Control Switch 0x0001
On/Off Output 0x0002
Level Controllable Output 0x0003
Scene Selector 0x0004
Configuration Tool 0x0005
Remote Control 0x0006
Combined Interface 0x0007
Range Extender 0x0008
Mains Power Outlet 0x0009
Reserved 0x000A 0x00FF
Lighting
On/Off Light 0x0100
Dimmable Light 0x0101
Color Dimmable Light 0x0102
On/Off Light Switch 0x0103
Dimmer Switch 0x0104
Color Dimmer Switch 0x0105
Light Sensor 0x0106
Occupancy Sensor 0x0107
Reserved 0x0108 0x1FF
Closures
Shade 0x0200
Shade Controller 0x0201
Reserved 0x0202 0x2FF
*/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC teZCL_Status eHA_Initialise(tfpZCL_ZCLCallBackFunction cbCallBack,
                                   PDUM_thAPdu hAPdu);

PUBLIC teZCL_Status eHA_Update100mS(void);

/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

#if defined __cplusplus
}
#endif

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/
#endif /* HA_H */

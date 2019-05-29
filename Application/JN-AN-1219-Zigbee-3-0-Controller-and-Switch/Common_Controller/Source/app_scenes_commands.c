/*****************************************************************************
 *
 * MODULE:             JN-AN-1219
 *
 * COMPONENT:          
 *
 * DESCRIPTION:        
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

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#include <jendefs.h>
#include "dbg.h"
#include "zps_gen.h"
#include "pdum_gen.h"
#include "app_common.h"
#include "zlo_controller_node.h"
#include "app_menu_handler.h"
#include "app_general_commands.h"
#include "app_scenes_commands.h"

#ifdef DEBUG_APP
    #define TRACE_APP   TRUE
#else
    #define TRACE_APP   FALSE
#endif

#ifdef DEBUG_REMOTE_NODE
    #define TRACE_REMOTE_NODE   TRUE
#else
    #define TRACE_REMOTE_NODE   FALSE
#endif

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/



/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/



/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/


/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/



#ifdef CLD_SCENES
/****************************************************************************
 *
 * NAME: vAppAddScene
 *
 * DESCRIPTION:
 * send an add scene command to a light or lights,
 * this command includes all the scene data
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppAddScene(uint8 u8SceneId, uint16 u16GroupId, uint16 u16TransitionTime)
{
    uint8 u8Seq;
    tsZCL_Address sAddress;
    tsCLD_ScenesAddSceneRequestPayload sPayload;
    uint8 name[] = "";

    uint8 au8Extension[] = {0x06, 0x00, 0x01, 0x01,         /* On cluster */
                            0x08, 0x00, 0x01, 0xfe,         /* level cluster */
                            0x00, 0x03, 0x0b,               /* colour cluster */
                            0x00, 0x00, 0x00, 0x00,         /* BigX BigY */
                            0x00, 0xa0,                     /* enhanced Hue */
                            0xfe,                           /* saturation */
                            0x00,                           /* colour loop active */
                            0x00,                           /* colour loop direction */
                            0x00, 0x00};                    /* colour loop time */
    teZCL_Status eStatus;

    vSetAddress(&sAddress, FALSE);
    sPayload.u16GroupId = u16GroupId;
    sPayload.u8SceneId = u8SceneId;
    sPayload.u16TransitionTime = u16TransitionTime;
    sPayload.sSceneName.u8Length = 0;
    sPayload.sSceneName.u8MaxLength = 1;
    sPayload.sSceneName.pu8Data = name;
    sPayload.sExtensionField.pu8Data = au8Extension;
    sPayload.sExtensionField.u16Length = 22;

    eStatus = eCLD_ScenesCommandAddSceneRequestSend(
                        sDeviceTable.asDeviceRecords[0].u8Endpoint,
                        sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint,   // dst ep
                        &sAddress,
                        &u8Seq,
                        &sPayload);
    DBG_vPrintf(TRACE_APP, "\neCLD_ScenesCommandAddSceneRequestSend  eStatus = %d", eStatus);

}

/****************************************************************************
 *
 * NAME: vAppEnhancedAddScene
 *
 * DESCRIPTION: send an enhanced add scene command to a light or lights,
 * this command includes all the scene data
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppEnhancedAddScene( uint8 u8Scene, uint16 u16GroupId)
{
    tsCLD_ScenesEnhancedAddSceneRequestPayload sPayload;

    uint8 au8Extension[] = {0x06, 0x00, 0x01, 0x01,         /* On cluster */
                            0x08, 0x00, 0x01, 0xfe,         /* level cluster */
                            0x00, 0x03, 0x0b,               /* colour cluster */
                            0x00, 0x00, 0x00, 0x00,         /* BigX BigY */
                            0x00, 0xa0,                     /* enhanced Hue */
                            0xfe,                           /* saturation */
                            0x00,                           /* colour loop active */
                            0x00,                           /* colour loop direction */
                            0x00, 0x00};                    /* colour loop time */

    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE);

    DBG_vPrintf(TRACE_REMOTE_NODE, "\nAdd sc %d", u8Scene);

    switch (u8Scene)
    {
        case 0:
            break;
        case 1:
            au8Extension[7] = 127;
            au8Extension[11] = 0x47;    // Big X Blue
            au8Extension[12] = 0x21;
            au8Extension[13] = 0x33;    // Big Y Blue
            au8Extension[14] = 0x13;
            au8Extension[15] = 0;
            au8Extension[16] = 0;
            break;
        case 2:
            au8Extension[7] = 60;
            au8Extension[11] = 0xcf;    // Big X red
            au8Extension[12] = 0xb2;
            au8Extension[13] = 0xcc;    // Big Y red
            au8Extension[14] = 0x4c;
            au8Extension[15] = 0;
            au8Extension[16] = 0;
            break;
        default:
            return;
            break;
    }

    uint8 name[] = "";

    //sPayload.u16GroupId = sGroupTable.asGroupRecords[0].u16GroupId;
    sPayload.u16GroupId = u16GroupId;
    sPayload.u8SceneId = u8Scene;
    sPayload.u16TransitionTime100ms = 0x000a;
    sPayload.sSceneName.u8Length = 0;
    sPayload.sSceneName.u8MaxLength = 0;
    sPayload.sSceneName.pu8Data = name;


    sPayload.sExtensionField.pu8Data = au8Extension;
    sPayload.sExtensionField.u16Length = 22;

    eCLD_ScenesCommandEnhancedAddSceneRequestSend(
                        sDeviceTable.asDeviceRecords[0].u8Endpoint,
                        sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint,   // dst ep
                        &sAddress,
                        &u8Seq,
                        &sPayload );
}

/****************************************************************************
 *
 * NAME: vAppViewScene
 *
 * DESCRIPTION:send a view scene command to a light or lights,
 * this command includes all the scene data
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppViewScene(uint8 u8SceneId, uint16 u16GroupId)
{
    uint8 u8Seq;
    tsZCL_Address sAddress;
    tsCLD_ScenesViewSceneRequestPayload sPayload;

    vSetAddress(&sAddress, FALSE);
    sPayload.u16GroupId = u16GroupId;
    sPayload.u8SceneId = u8SceneId;

    eCLD_ScenesCommandViewSceneRequestSend(
                        sDeviceTable.asDeviceRecords[0].u8Endpoint,
                        sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint,   // dst ep
                        &sAddress,
                        &u8Seq,
                        &sPayload);
}

/****************************************************************************
 *
 * NAME: vAppEnhancedViewScene
 *
 * DESCRIPTION: send an enhanced view scene command to a light or lights
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppEnhancedViewScene(uint8 u8SceneId, uint16 u16GroupId)
{
    uint8 u8Seq;
    tsZCL_Address sAddress;
    tsCLD_ScenesEnhancedViewSceneRequestPayload sPayload;

    vSetAddress(&sAddress, FALSE);
    sPayload.u16GroupId = u16GroupId;
    sPayload.u8SceneId = u8SceneId;

    eCLD_ScenesCommandEnhancedViewSceneRequestSend(
                        sDeviceTable.asDeviceRecords[0].u8Endpoint,
                        sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint,   // dst ep
                        &sAddress,
                        &u8Seq,
                        &sPayload);
}

/****************************************************************************
 *
 * NAME: vAppRecallSceneById
 *
 * DESCRIPTION: send a recall scene command to a light or lights
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppRecallSceneById( uint8 u8SceneId, uint16 u16GroupId)
{

    tsCLD_ScenesRecallSceneRequestPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE);

    sPayload.u16GroupId = u16GroupId;
    sPayload.u8SceneId = u8SceneId;
    sPayload.u16TransitionTime = 0x0000;

    eCLD_ScenesCommandRecallSceneRequestSend(
                            sDeviceTable.asDeviceRecords[0].u8Endpoint,
                            sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint   /* don't care group addr */,
                            &sAddress,
                            &u8Seq,
                            &sPayload);

}

/****************************************************************************
 *
 * NAME: vAppRemoveSceneById
 *
 * DESCRIPTION: send a remove scene command to a light or lights
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppRemoveSceneById( uint8 u8SceneId, uint16 u16GroupId)
{

    tsCLD_ScenesRemoveSceneRequestPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE);

    sPayload.u16GroupId = u16GroupId;
    sPayload.u8SceneId = u8SceneId;

    eCLD_ScenesCommandRemoveSceneRequestSend(
                            sDeviceTable.asDeviceRecords[0].u8Endpoint,
                            sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint   /* don't care group addr */,
                            &sAddress,
                            &u8Seq,
                            &sPayload);

}

/****************************************************************************
 *
 * NAME: vAppRemoveAllScene
 *
 * DESCRIPTION:
 * send a remove all scenes command to a light or lights
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppRemoveAllScene(uint16 u16GroupId)
{

    tsCLD_ScenesRemoveAllScenesRequestPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE);

    sPayload.u16GroupId = u16GroupId;

    eCLD_ScenesCommandRemoveAllScenesRequestSend(
                            sDeviceTable.asDeviceRecords[0].u8Endpoint,
                            sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint   /* don't care group addr */,
                            &sAddress,
                            &u8Seq,
                            &sPayload);

}

/****************************************************************************
 *
 * NAME: vAppGetSceneMembership
 *
 * DESCRIPTION:sends a get scenes membership to a group of lights
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppGetSceneMembership(uint16 u16GroupId)
{

    tsCLD_ScenesGetSceneMembershipRequestPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE);

    sPayload.u16GroupId = u16GroupId;

    eCLD_ScenesCommandGetSceneMembershipRequestSend(
                            sDeviceTable.asDeviceRecords[0].u8Endpoint,
                            sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint   /* don't care group addr */,
                            &sAddress,
                            &u8Seq,
                            &sPayload);

}
/****************************************************************************
 *
 * NAME: vAppCopyScene
 *
 * DESCRIPTION: sends a copy scene scene command to a light or lights
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppCopyScene(uint8 u8Mode, uint8 u8FromSceneId, uint16 u16FromGroupId, uint8 u8ToSceneId, uint16 u16ToGroupId)
{

    tsCLD_ScenesCopySceneRequestPayload sPayload;
    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE);

    sPayload.u8Mode = u8Mode;
    sPayload.u16FromGroupId = u16FromGroupId;
    sPayload.u8FromSceneId = u8FromSceneId;
    sPayload.u16ToGroupId = u16ToGroupId;
    sPayload.u8ToSceneId = u8ToSceneId;

    eCLD_ScenesCommandCopySceneSceneRequestSend(
                            sDeviceTable.asDeviceRecords[0].u8Endpoint,
                            sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint   /* don't care group addr */,
                            &sAddress,
                            &u8Seq,
                            &sPayload);

}

/****************************************************************************
 *
 * NAME: vAppStoreSceneById
 *
 * DESCRIPTION: sends a store scene command to a light or lights
 * the actual scenwe data is the current state of the receiving light
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vAppStoreSceneById(uint8 u8SceneId, uint16 u16GroupId)
{
    tsCLD_ScenesStoreSceneRequestPayload sPayload;

    uint8 u8Seq;
    tsZCL_Address sAddress;

    vSetAddress(&sAddress, FALSE);

    sPayload.u16GroupId = u16GroupId;
    sPayload.u8SceneId = u8SceneId;


    eCLD_ScenesCommandStoreSceneRequestSend(
                            sDeviceTable.asDeviceRecords[0].u8Endpoint,
                            sEndpointTable.asEndpointRecords[sEndpointTable.u8CurrentLight].u8Endpoint,   // dst ep
                            &sAddress,
                            &u8Seq,
                            &sPayload);

}

#endif


/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

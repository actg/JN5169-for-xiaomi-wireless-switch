/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          app_scenes.h
 *
 * DESCRIPTION:        ZHA Demo : Stack <-> Outlet App Interaction (Interface)
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
 * Copyright NXP B.V. 2012. All rights reserved
 *
 ***************************************************************************/
#ifndef APP_SCENES_H_
#define APP_SCENES_H_

#include "zcl.h"
#include "app_scenes.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
typedef struct PACK
{
    DNODE   dllScenesNode;
    uint16  u16GroupId;
    uint8   u8SceneId;
    uint16  u16TransitionTime;
    uint16  u16SceneDataLength;
    uint8   au8SceneData[CLD_SCENES_MAX_SCENE_STORAGE_BYTES];
} tsAPP_ScenesCustomTableEntry;

/* Scenes data structure for PDM saving */
typedef struct PACK
{
    DLIST   lScenesAllocList;
    DLIST   lScenesDeAllocList;
    #if (defined CLD_SCENES) && (defined SCENES_SERVER)
        tsAPP_ScenesCustomTableEntry  asScenesCustomTableEntry[CLD_SCENES_MAX_NUMBER_OF_SCENES];
    #endif
} tsAPP_ScenesCustomData;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
PUBLIC void vLoadScenesNVM(void);
PUBLIC void vSaveScenesNVM(void);
#ifdef CLD_GROUPS
    PUBLIC void vRemoveAllGroupsAndScenes(void);
#endif

/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/

/****************************************************************************/

/****************************************************************************/
/****************************************************************************/

#endif //APP_SCENES_H_

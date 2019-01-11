/****************************************************************************
 *
 * MODULE              JN-AN-1171 ZigBee Light Link Application
 *
 * COMPONENT:          app_scenes.c
 *
 * DESCRIPTION         Application Scenes save and load functionality
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
#include <string.h>
#include "pdum_gen.h"
#include "pdm.h"
#include "dbg.h"
#include "zps_gen.h"
#include "PDM_IDs.h"
#include "zcl_options.h"
#include "zps_apl_af.h"

#include "app_common.h"

#include "Scenes.h"
#include "app_scenes.h"
#ifdef CLD_GROUPS
#include "Groups_internal.h"
#endif
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#define SCENES_SEARCH_GROUP_ID      (1 << 0)
#define SCENES_SEARCH_SCENE_ID      (1 << 1)


/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
typedef struct
{
    uint8   u8SearchOptions;
    uint16  u16GroupId;
    uint8   u8SceneId;
} tsSearchParameter;

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
#if (defined CLD_SCENES) && (defined SCENES_SERVER)
PRIVATE tsAPP_ScenesCustomData sScenesCustomData;
#endif


/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

#if (defined CLD_SCENES) && (defined SCENES_SERVER)
/****************************************************************************
 *
 * NAME: vSaveScenesNVM
 *
 * DESCRIPTION:
 * To save scenes data to EEPROM
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vSaveScenesNVM(void)
{
    uint8 i=0, j=0;
    tsCLD_ScenesTableEntry *psTableEntry;

    /* Before saving data again clear off the earlier entries and recopy all the scenes */
    memset(&sScenesCustomData,0,sizeof(tsAPP_ScenesCustomData));
    psTableEntry = (tsCLD_ScenesTableEntry*)psDLISTgetHead(&sLight.sScenesServerCustomDataStructure.lScenesAllocList);
    for(i = 0; i < iDLISTnumberOfNodes(&sLight.sScenesServerCustomDataStructure.lScenesAllocList); i++)
    {
            if(psTableEntry != NULL)
            {
                 sScenesCustomData.asScenesCustomTableEntry[j].bIsSceneValid = TRUE;
                  sScenesCustomData.asScenesCustomTableEntry[j].u16GroupId = psTableEntry->u16GroupId;
                  sScenesCustomData.asScenesCustomTableEntry[j].u8SceneId = psTableEntry->u8SceneId;
                 sScenesCustomData.asScenesCustomTableEntry[j].u16TransitionTime = psTableEntry->u16TransitionTime;
                 sScenesCustomData.asScenesCustomTableEntry[j].u16SceneDataLength = psTableEntry->u16SceneDataLength;
                 memcpy(sScenesCustomData.asScenesCustomTableEntry[j].au8SceneData,psTableEntry->au8SceneData,psTableEntry->u16SceneDataLength);
                  #ifdef CLD_SCENES_TABLE_SUPPORT_TRANSITION_TIME_IN_MS
                         sScenesCustomData.asScenesCustomTableEntry[j].u8TransitionTime100ms = psTableEntry->u8TransitionTime100ms;
                  #endif
                  j++;
            }
            psTableEntry = (tsCLD_ScenesTableEntry*)psDLISTgetNext((DNODE*)psTableEntry);
    }

    PDM_eSaveRecordData(PDM_ID_APP_SCENES_DATA,&sScenesCustomData,sizeof(tsAPP_ScenesCustomData));
}
#endif

#if (defined CLD_SCENES) && (defined SCENES_SERVER)
/****************************************************************************
 *
 * NAME: vLoadScenesNVM
 *
 * DESCRIPTION:
 * To load scenes data from EEPROM
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vLoadScenesNVM(void)
{
    uint8 i=0;
    uint16 u16ByteRead;

    PDM_eReadDataFromRecord(PDM_ID_APP_SCENES_DATA,
                            &sScenesCustomData,
                            sizeof(tsAPP_ScenesCustomData), &u16ByteRead);

    /* initialise lists */
    vDLISTinitialise(&sLight.sScenesServerCustomDataStructure.lScenesAllocList);
    vDLISTinitialise(&sLight.sScenesServerCustomDataStructure.lScenesDeAllocList);

    for(i=0; i<CLD_SCENES_MAX_NUMBER_OF_SCENES; i++)
    {
        /* Rebuild the scene list to avoid scene loss after re-flashing */
        if(sScenesCustomData.asScenesCustomTableEntry[i].bIsSceneValid == TRUE)
        {
             vDLISTaddToTail(&sLight.sScenesServerCustomDataStructure.lScenesAllocList,
                            (DNODE *)&sLight.sScenesServerCustomDataStructure.asScenesTableEntry[i]);
        }
        else
        {
             vDLISTaddToTail(&sLight.sScenesServerCustomDataStructure.lScenesDeAllocList,
                            (DNODE *)&sLight.sScenesServerCustomDataStructure.asScenesTableEntry[i]);
        }

        sLight.sScenesServerCustomDataStructure.asScenesTableEntry[i].u16GroupId = sScenesCustomData.asScenesCustomTableEntry[i].u16GroupId;
        sLight.sScenesServerCustomDataStructure.asScenesTableEntry[i].u8SceneId = sScenesCustomData.asScenesCustomTableEntry[i].u8SceneId;
        sLight.sScenesServerCustomDataStructure.asScenesTableEntry[i].u16TransitionTime = sScenesCustomData.asScenesCustomTableEntry[i].u16TransitionTime;
        sLight.sScenesServerCustomDataStructure.asScenesTableEntry[i].u16SceneDataLength = sScenesCustomData.asScenesCustomTableEntry[i].u16SceneDataLength;
        memcpy(sLight.sScenesServerCustomDataStructure.asScenesTableEntry[i].au8SceneData, sScenesCustomData.asScenesCustomTableEntry[i].au8SceneData,sScenesCustomData.asScenesCustomTableEntry[i].u16SceneDataLength);
            #ifdef CLD_SCENES_TABLE_SUPPORT_TRANSITION_TIME_IN_MS
                 sLight.sScenesServerCustomDataStructure.asScenesTableEntry[i].u8TransitionTime100ms = sScenesCustomData.asScenesCustomTableEntry[i].u8TransitionTime100ms;
            #endif
    }
}
#endif

#ifdef CLD_GROUPS
/****************************************************************************
 *
 * NAME: vRemoveAllGroupsAndScenes
 *
 * DESCRIPTION:
 * to remove all scenes and groups after a leave or factory reset
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vRemoveAllGroupsAndScenes(void)
{
    eCLD_GroupsRemoveAllGroups(&sLight.sEndPoint,
                               &sLight.sClusterInstance.sGroupsServer,
                               (uint64)0xffffffffffffffffLL);

}
#endif

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

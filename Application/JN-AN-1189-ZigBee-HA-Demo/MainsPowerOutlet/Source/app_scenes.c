/*****************************************************************************
 *
 * MODULE:             JN-AN-1189 ZHA Demo
 *
 * COMPONENT:          app_scenes.c
 *
 * DESCRIPTION:        ZHA Outlet Scenes - Implementation
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
/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include <jendefs.h>
#include <string.h>
#include "os.h"
#include "os_gen.h"
#include "pdum_gen.h"
#include "pdm.h"
#include "dbg.h"
#include "zps_gen.h"
#include "PDM_IDs.h"
#include "zcl_options.h"
#include "zps_apl_af.h"
#include "ha.h"
#include "app_common.h"
#include "app_events.h"
#include "app_scenes.h"
#include "App_MainsPowerOutlet.h"

#ifdef CLD_GROUPS
    #include "Groups_internal.h"
#endif

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifdef DEBUG_SCENE
    #define TRACE_SCENE   TRUE
#else
    #define TRACE_SCENE   FALSE
#endif

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
PRIVATE tsAPP_ScenesCustomData sScenesCustomData;
//PDM_tsRecordDescriptor sScenesDataPDDesc;
//PDM_tsRecordDescriptor sDevicePDDesc;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
/****************************************************************************
 *
 * NAME: vSaveScenesNVM
 *
 * DESCRIPTION:
 * to save scenes data to eeprom
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vSaveScenesNVM(void)
{
    uint8 i=0, j=0;

    DBG_vPrintf(TRACE_SCENE, "\nvSaveScenesNVM:");
    memcpy(&sScenesCustomData.lScenesAllocList, &sOutletDevice.sScenesServerCustomDataStructure.lScenesAllocList, sizeof(DLIST));
    memcpy(&sScenesCustomData.lScenesDeAllocList, &sOutletDevice.sScenesServerCustomDataStructure.lScenesDeAllocList, sizeof(DLIST));

    #if (defined CLD_SCENES) && (defined SCENES_SERVER)
    {
        for(i=0; i<CLD_SCENES_MAX_NUMBER_OF_SCENES; i++)
        {
            memcpy(&sScenesCustomData.asScenesCustomTableEntry[i].dllScenesNode,
                   &sOutletDevice.sScenesServerCustomDataStructure.asScenesTableEntry[i].dllScenesNode,
                    sizeof(DNODE));
            sScenesCustomData.asScenesCustomTableEntry[i].u16GroupId = sOutletDevice.sScenesServerCustomDataStructure.asScenesTableEntry[i].u16GroupId;
            sScenesCustomData.asScenesCustomTableEntry[i].u8SceneId = sOutletDevice.sScenesServerCustomDataStructure.asScenesTableEntry[i].u8SceneId;
            sScenesCustomData.asScenesCustomTableEntry[i].u16TransitionTime = sOutletDevice.sScenesServerCustomDataStructure.asScenesTableEntry[i].u16TransitionTime;
            sScenesCustomData.asScenesCustomTableEntry[i].u16SceneDataLength = sOutletDevice.sScenesServerCustomDataStructure.asScenesTableEntry[i].u16SceneDataLength;
            for(j=0; j<CLD_SCENES_MAX_SCENE_STORAGE_BYTES; j++)
            {
                sScenesCustomData.asScenesCustomTableEntry[i].au8SceneData[j] = sOutletDevice.sScenesServerCustomDataStructure.asScenesTableEntry[i].au8SceneData[j];
            }
        }
    }
    #endif

    PDM_eSaveRecordData(PDM_ID_APP_SCENES_DATA,&sScenesCustomData,sizeof(tsAPP_ScenesCustomData));
}

/****************************************************************************
 *
 * NAME: vLoadScenesNVM
 *
 * DESCRIPTION:
 * to recover scenes data to eeprom
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vLoadScenesNVM(void)
{
    PDM_teStatus eStatus;
    uint8 i=0,j=0;
    uint16 u16ByteRead;

    DBG_vPrintf(TRACE_SCENE, "\nvLoadScenesNVM:");

    PDM_eReadDataFromRecord(PDM_ID_APP_SCENES_DATA,
                            &sScenesCustomData,
                            sizeof(tsAPP_ScenesCustomData), &u16ByteRead);

    memcpy(&sOutletDevice.sScenesServerCustomDataStructure.lScenesAllocList, &sScenesCustomData.lScenesAllocList, sizeof(DLIST));
    memcpy(&sOutletDevice.sScenesServerCustomDataStructure.lScenesDeAllocList, &sScenesCustomData.lScenesDeAllocList, sizeof(DLIST));

    DBG_vPrintf(TRACE_SCENE, "\nAPP: PDM Load SCENES_DATA returned %d\n", eStatus);

    #if (defined CLD_SCENES) && (defined SCENES_SERVER)
    {
        for(i=0; i<CLD_SCENES_MAX_NUMBER_OF_SCENES; i++)
        {
            memcpy(&sOutletDevice.sScenesServerCustomDataStructure.asScenesTableEntry[i].dllScenesNode,
                   &sScenesCustomData.asScenesCustomTableEntry[i].dllScenesNode,
                    sizeof(DNODE));
            sOutletDevice.sScenesServerCustomDataStructure.asScenesTableEntry[i].u16GroupId = sScenesCustomData.asScenesCustomTableEntry[i].u16GroupId;
            sOutletDevice.sScenesServerCustomDataStructure.asScenesTableEntry[i].u8SceneId = sScenesCustomData.asScenesCustomTableEntry[i].u8SceneId;
            sOutletDevice.sScenesServerCustomDataStructure.asScenesTableEntry[i].u16TransitionTime = sScenesCustomData.asScenesCustomTableEntry[i].u16TransitionTime;
            sOutletDevice.sScenesServerCustomDataStructure.asScenesTableEntry[i].u16SceneDataLength = sScenesCustomData.asScenesCustomTableEntry[i].u16SceneDataLength;
            for(j=0; j<CLD_SCENES_MAX_SCENE_STORAGE_BYTES; j++)
            {
                sOutletDevice.sScenesServerCustomDataStructure.asScenesTableEntry[i].au8SceneData[j] = sScenesCustomData.asScenesCustomTableEntry[i].au8SceneData[j];
            }
        }
    }
    #endif
}

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
    eCLD_GroupsRemoveAllGroups(&sOutletDevice.sEndPoint,
                               &sOutletDevice.sClusterInstance.sGroupsServer,
                               (uint64)0xffffffffffffffffLL);

}
#endif

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

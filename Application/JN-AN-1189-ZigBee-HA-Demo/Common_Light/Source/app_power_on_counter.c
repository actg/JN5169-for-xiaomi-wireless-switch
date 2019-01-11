/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          app_power_on_counter.c
 *
 * DESCRIPTION:        ZHA Demo : Stack <-> Light-App Interaction (Implementation)
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
 * Copyright NXP B.V. 2014. All rights reserved
 *
 ***************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include <jendefs.h>
#include <string.h>
#include "dbg.h"
#include "os.h"
#include "os_gen.h"
#include "pdm.h"
#include "app_timer_driver.h"
#include "app_events.h"
#include "app_zbp_utilities.h"
#include "PDM_IDs.h"

#include "app_power_on_counter.h"
#include "zcl_common.h"
#include "app_light_effect.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifndef DEBUG_POWER_ON_COUNTER
    #define TRACE_POWER_ON_COUNTER   FALSE
#else
    #define TRACE_POWER_ON_COUNTER   TRUE
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
PRIVATE tsPowerOnCounts sPowerOnCounts;
PRIVATE bool_t bPreInitFunctionCalled;
/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
/****************************************************************************
 *
 * NAME: vManagePowerOnCountLoadRecord
 *
 * DESCRIPTION:
 * Loads record from PDM before the AfInit.
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vManagePowerOnCountLoadRecord(void)
{
    PDM_teStatus eStatus;
    uint16 u16ByteRead;
    eStatus = PDM_eReadDataFromRecord(PDM_ID_POWER_ON_COUNTER,
                                      &sPowerOnCounts,
                                      sizeof(tsPowerOnCounts),
                                      &u16ByteRead);


    DBG_vPrintf(TRACE_POWER_ON_COUNTER, "\nAPP: Status = %d, u8PowerOnCounter =%d\n", eStatus, sPowerOnCounts.u8PowerOnCounter);

}
/****************************************************************************
 *
 * NAME: vManagePowerOnCountInit
 *
 * DESCRIPTION:
 * Initialises the power on counters for triggering events on a sequence of
 * On/Off power cycle to the bulb
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vManagePowerOnCountInit(void)
{

    if (FALSE == bPreInitFunctionCalled)
    {
        OS_eStartSWTimer(APP_PowerOnCountTimer, APP_TIME_MS(POWER_ON_PRE_INIT_COUNTER_DB_IN_MSEC), NULL);
    }
    else
    {
        OS_eStopSWTimer(APP_PowerOnCountTimer);
        sPowerOnCounts.u8PowerOnCounter++;
        PDM_eSaveRecordData(PDM_ID_POWER_ON_COUNTER,
                            &sPowerOnCounts,
                            sizeof(tsPowerOnCounts));
        switch (sPowerOnCounts.u8PowerOnCounter)
        {
            #if ((CONFIG_FIND_BIND_POWER_CYCLES != 0) && (CONFIG_FIND_BIND_BLINK == TRUE))
            {
                case CONFIG_FIND_BIND_POWER_CYCLES:
                {
                    vStartEffect(0);
                }
                break;
            }
            #endif

            #if ((CONFIG_FACTORY_RESET_POWER_CYCLES != 0) && (CONFIG_FACTORY_RESET_BLINK == TRUE))
            {
                case CONFIG_FACTORY_RESET_POWER_CYCLES:
                {
                    vStartEffect(0);
                }
                break;
            }
            #endif

            #if ((CONFIG_FACTORY_NEW_POWER_CYCLES != 0) && (CONFIG_FACTORY_NEW_BLINK == TRUE))
            {
                case CONFIG_FACTORY_NEW_POWER_CYCLES:
                {
                    vStartEffect(0);
                }
                break;
            }
            #endif

            default :
                break;
        }
        OS_eStartSWTimer(APP_PowerOnCountTimer, APP_TIME_MS(POWER_ON_COUNTER_DB_IN_MSEC), NULL);
    }
}

/****************************************************************************
 *
 * NAME: APP_vManagePowerOnCount
 *
 * DESCRIPTION:
 * OS task for the power on counters for triggering events on a sequence of
 * On/Off power cycle to the bulb
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
OS_TASK(APP_vManagePowerOnCount)
{
    if (FALSE == bPreInitFunctionCalled)
    {
        /*Pre Init over */
        bPreInitFunctionCalled=TRUE;
        /*Second call to the init will start timer and increment the vales also*/
        vManagePowerOnCountInit();
    }
    else
    {
        APP_tsEvent sPowerOnEvent;
        OS_eStopSWTimer(APP_PowerOnCountTimer);
        switch (sPowerOnCounts.u8PowerOnCounter)
        {
            #if (CONFIG_FIND_BIND_POWER_CYCLES != 0)
            {
                case CONFIG_FIND_BIND_POWER_CYCLES:
                {
                    sPowerOnEvent.eType = APP_E_EVENT_POR_IDENTIFY;
                }
                break;
            }
            #endif

            #if (CONFIG_FACTORY_RESET_POWER_CYCLES != 0)
            {
                case CONFIG_FACTORY_RESET_POWER_CYCLES:
                {
                    sPowerOnEvent.eType = APP_E_EVENT_POR_FACTORY_RESET;
                }
                break;
            }
            #endif

            #if (CONFIG_FACTORY_NEW_POWER_CYCLES != 0)
            {
                case CONFIG_FACTORY_NEW_POWER_CYCLES:
                {
                    sPowerOnEvent.eType = APP_E_EVENT_POR_PDM_RESET;
                }
                break;
            }
            #endif

            #ifdef CLD_GREENPOWER
            {
                case 4:
                {
                    sPowerOnEvent.eType = APP_E_EVENT_GP_DECOMMISSION;
                }
                break;
            }
            #endif

            default:
            {
                sPowerOnEvent.eType = APP_E_EVENT_NONE;
            }
            break;
        }
        DBG_vPrintf(TRACE_POWER_ON_COUNTER,"\nPosting Msg = %d\n",sPowerOnEvent.eType);
        OS_ePostMessage(APP_msgPOREvents, &sPowerOnEvent);
        sPowerOnCounts.u8PowerOnCounter=0;
         PDM_eSaveRecordData(PDM_ID_POWER_ON_COUNTER,
                            &sPowerOnCounts,
                            sizeof(tsPowerOnCounts));
    }
}

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

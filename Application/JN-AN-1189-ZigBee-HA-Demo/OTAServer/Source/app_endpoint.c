/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          app_endpoint.c
 *
 * DESCRIPTION:        ZHA End Point event handler (Implementation)
 *
 *****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products [NXP Microcontrollers such as JN5148, JN5142,
 * JN5139]. You, and any third parties must reproduce the copyright and
 * warranty notice and any other legend of ownership on each copy or partial
 * copy of the software.
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

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#include <jendefs.h>
#include "dbg.h"
#include "os.h"
#include "os_gen.h"
#include "pdum_apl.h"
#include "pdum_gen.h"
#include "pwrm.h"
#include "pdm.h"
#include "zps_gen.h"
#include "zps_apl.h"
#include "zps_apl_af.h"
#include "zps_apl_aib.h"
#include "zps_apl_zdo.h"
#include "zps_apl_zdp.h"
#include "app_timer_driver.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#ifndef DEBUG_APP
    #define TRACE_APP FALSE
#else
    #define TRACE_APP TRUE
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

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

/****************************************************************************
 *
 * NAME: APP_taskEndpoint
 *
 * DESCRIPTION:
 * End Point event handling
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
OS_TASK(APP_taskMyEndPoint)
{
    ZPS_tsAfEvent sStackEvent;
    sStackEvent.eType = ZPS_EVENT_NONE;

    /* check if any messages to collect */
    if (OS_E_OK != OS_eCollectMessage(APP_msgMyEndPointEvents, &sStackEvent))
    {
        DBG_vPrintf(TRACE_APP, "APP: No event to process\n");
    }

    if (ZPS_EVENT_NONE != sStackEvent.eType)
    {
        switch (sStackEvent.eType)
        {
            case ZPS_EVENT_APS_DATA_INDICATION:
                DBG_vPrintf(TRACE_APP, "APP: APP_taskEndPoint: ZPS_EVENT_AF_DATA_INDICATION\n");

                /* Process incoming cluster messages for this endpoint... */
                DBG_vPrintf(TRACE_APP, "    Data Indication:\r\n");
                DBG_vPrintf(TRACE_APP, "        Profile :%x\r\n",sStackEvent.uEvent.sApsDataIndEvent.u16ProfileId);
                DBG_vPrintf(TRACE_APP, "        Cluster :%x\r\n",sStackEvent.uEvent.sApsDataIndEvent.u16ClusterId);
                DBG_vPrintf(TRACE_APP, "        EndPoint:%x\r\n",sStackEvent.uEvent.sApsDataIndEvent.u8DstEndpoint);

                /* free the application protocol data unit (APDU) once it has been dealt with */
                PDUM_eAPduFreeAPduInstance(sStackEvent.uEvent.sApsDataIndEvent.hAPduInst);

                break;

            case ZPS_EVENT_APS_DATA_CONFIRM:
                DBG_vPrintf(TRACE_APP, "APP: APP_taskEndPoint: ZPS_EVENT_APS_DATA_CONFIRM Status %d, Address 0x%04x\n",
                            sStackEvent.uEvent.sApsDataConfirmEvent.u8Status,
                            sStackEvent.uEvent.sApsDataConfirmEvent.uDstAddr.u16Addr);
                break;

            case ZPS_EVENT_APS_DATA_ACK:
                DBG_vPrintf(TRACE_APP, "APP: APP_taskEndPoint: ZPS_EVENT_APS_DATA_ACK Status %d, Address 0x%04x\n",
                            sStackEvent.uEvent.sApsDataAckEvent.u8Status,
                            sStackEvent.uEvent.sApsDataAckEvent.u16DstAddr);
                break;

            default:
                DBG_vPrintf(TRACE_APP, "APP: APP_taskEndPoint: unhandled event %d\n", sStackEvent.eType);
                break;
        }
    }

}

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/


/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          App_Coordinator.c
 *
 * DESCRIPTION:        ZBP-ZHA Coordinator (Implementation)
 *
 ****************************************************************************
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
 ***************************************************************************/

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
#include "app_coordinator.h"
#include "app_timer_driver.h"
#include "PDM_IDs.h"
#include "AgeChildren.h"
#include "app_common.h"
#include "haKeys.h"
#include <rnd_pub.h>

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#define USB_DONGLE

#ifndef DEBUG_APP
    #define TRACE_APP FALSE
#else
    #define TRACE_APP TRUE
#endif

#define DIO_8        (8)
#define APP_BUTTONS_DIO_MASK        ((1 << DIO_8))
#define PERMIT_JOIN_TIME_AFTER_STARTUP 180 /* Seconds    */

#ifndef USB_DONGLE
    #define LED_NWK_FORMED 0x00000004UL    /* using DIO2 */
    #define LED_PERMIT_JOIN 0x00000008UL   /* using DIO3 */
#else
    #define LED_NWK_FORMED (1<<16)         /* using DIO16 */
    #define LED_PERMIT_JOIN (1<<17)        /* using DIO17 */
#endif
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/

PRIVATE void vStartup(void);
PRIVATE void vWaitForNetworkFormation(ZPS_tsAfEvent sStackEvent);
PRIVATE void vHandleStackEvent(ZPS_tsAfEvent sStackEvent);
PRIVATE bool bCheckDIO8( void );
PRIVATE void vInitDR1174LED(void);
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

PUBLIC PDM_tsRecordDescriptor s_sDevicePDDesc;

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

PRIVATE teNODE_STATES s_eDeviceState;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

/****************************************************************************
 *
 * NAME: APP_vInitialiseCoordinator
 *
 * DESCRIPTION:
 * Initialises the Coordinator application
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_vInitialiseCoordinator(void)
{
     bool_t bDeleteRecords = FALSE;

    /* If required, at this point delete the network context from flash, perhaps upon some condition
     * For example, check if a button is being held down at reset, and if so request the Persistent
     * Data Manager to delete all its records:
     * e.g. bDeleteRecords = vCheckButtons();
     * Alternatively, always call PDM_vDelete() if context saving is not required.
     */

    bDeleteRecords = bCheckDIO8();

    if (bDeleteRecords)
    {
        DBG_vPrintf(TRACE_APP, "APP: Deleting all records from flash\n");
        PDM_vDeleteAllDataRecords();
    }

    /* Restore any application data previously saved to flash
     * All Application records must be loaded before the call to
     * ZPS_eAplAfInit
     */
        s_eDeviceState = E_STARTUP;
        uint16 u16ByteRead;
        PDM_eReadDataFromRecord(PDM_ID_APP_COORD,
                                    &s_eDeviceState,
                                    sizeof(s_eDeviceState),
                                &u16ByteRead);

    /* Initialise ZBPro stack */
    ZPS_vAplSecSetInitialSecurityState(ZPS_ZDO_PRECONFIGURED_LINK_KEY, (uint8 *)&s_au8LnkKeyArray, 0x00, ZPS_APS_GLOBAL_LINK_KEY);

    /* Initialise ZBPro stack */
    ZPS_eAplAfInit();

#ifdef PDM_EEPROM
        vDisplayPDMUsage();
#endif

    /* Initialise other software modules
     * HERE
     */

    /* Always initialise any peripherals used by the applicatio
     * HERE
     */
    vInitDR1174LED();

    /* If the device state has been restored from flash, re-start the stack
     * and set the application running again. Note that if there is more than 1 state
     * where the network has already joined, then the other states should also be included
     * in the test below
     * E.g. E_RUNNING_1, E_RUNNING_2......
     * if (E_RUNNING_1 == s_sDevice || E_RUNNING_2 == s_sDevice)
     */
    if (E_RUNNING == s_eDeviceState)
    {
        ZPS_teStatus eStatus = ZPS_eAplZdoStartStack();

        /* Store the NWK frame counter increment */
        ZPS_vSaveAllZpsRecords();

        DBG_vPrintf(TRACE_APP, "APP: Re-starting Stack....\r\n");
        if (ZPS_E_SUCCESS != eStatus)
        {
            DBG_vPrintf(TRACE_APP, "APP: ZPS_eZdoStartStack() failed error %d", eStatus);
        }
        /* turn on joining */
        ZPS_eAplZdoPermitJoining(PERMIT_JOIN_TIME_AFTER_STARTUP);

        /* Re-start any other application software modules
         * HERE
         */

        /*Start to blink LEDs to indicate formation the network*/
        OS_eStartSWTimer(APP_tmrLEDBlinkTimer,APP_TIME_MS(500),NULL);

    }
    else
        /* perform any actions require on initial start-up */
    {
        /* Return the device to the start-up start if it was reset during the network formation stage */
        s_eDeviceState = E_STARTUP;
    }

    /* Start Child Aging Code */
    OS_eStartSWTimer(APP_AgeOutChildrenTmr, APP_TIME_MS(APP_AGE_CHILDREN_START_TIME_IN_MS), NULL);
}

/****************************************************************************
 *
 * NAME: APP_taskCoordinator
 *
 * DESCRIPTION:
 * Main state machine
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
OS_TASK(APP_taskCoordinator)
{
    ZPS_tsAfEvent sStackEvent;
    sStackEvent.eType = ZPS_EVENT_NONE;

    /* check if any messages to collect */
    if (OS_E_OK == OS_eCollectMessage(APP_msgZpsEvents, &sStackEvent))
    {
        DBG_vPrintf(TRACE_APP, "APP: No event to process\n");

        /*Request response event ? - Call the child aging stuff */
        if((ZPS_EVENT_APS_DATA_INDICATION == sStackEvent.eType) &&
                (0 == sStackEvent.uEvent.sApsDataIndEvent.u8DstEndpoint))
        {
            /* check if the this is a response from my end device child, if so remove */
            vCheckIfMyChild(&sStackEvent);
        }
    }
    if (OS_eGetSWTimerStatus(App_tmr1sec) == OS_E_SWTIMER_EXPIRED)
    {
        OS_eContinueSWTimer (App_tmr1sec, APP_TIME_MS(1000), NULL);
    }

    switch (s_eDeviceState)
    {
        case E_STARTUP:
            vStartup();
            break;

        case E_NETWORK_FORMATION:
            vWaitForNetworkFormation(sStackEvent);
            break;

        case E_RUNNING:
            vHandleStackEvent(sStackEvent);
            break;

        default:
            break;
    }
}

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/
/****************************************************************************
 *
 * NAME: vInitDR1174LED
 *
 * DESCRIPTION:
 * Initialised DIO3 and DIO6 as output
 *
 *
 ****************************************************************************/
PRIVATE void vInitDR1174LED(void)
{

    /*Enable Pull Ups : Not really required for the outputs */
    vAHI_DioSetPullup(0,LED_NWK_FORMED);
    vAHI_DioSetPullup(0,LED_PERMIT_JOIN);

    /*Make the DIo as output*/
    vAHI_DioSetDirection(0,LED_NWK_FORMED);
    vAHI_DioSetDirection(0,LED_PERMIT_JOIN);
}
/****************************************************************************
 *
 * NAME: vStartup
 *
 * DESCRIPTION:
 * Initiates network formation
 *
 * RETURNS:
 * Sequence number
 *
 ****************************************************************************/
PRIVATE void vStartup(void)
{
    /* display the startup splash screen */
    DBG_vPrintf(TRACE_APP, "APP: Application startup\n");

    /* Stops Coordinator from sleeping ever - but does allow doze */
    PWRM_eStartActivity();

    ZPS_teStatus eStatus = ZPS_eAplZdoStartStack();
    if (ZPS_E_SUCCESS == eStatus)
    {
        s_eDeviceState = E_NETWORK_FORMATION;
    }
    else
    {
        DBG_vPrintf(TRACE_APP, "APP: ZPS_eZdoStartStack() failed error %d", eStatus);
    }
    OS_eStartSWTimer (App_tmr1sec, APP_TIME_MS(1000), NULL);
}

/****************************************************************************
 *
 * NAME: vWaitForNetworkFormation
 *
 * DESCRIPTION:
 * Handles stack events during network formation
 *
 * PARAMETERS: Name         RW  Usage
 *             sStackEvent  R   Contains details of the stack event
 *
 * RETURNS:
 * Sequence number
 *
 ****************************************************************************/
PRIVATE void vWaitForNetworkFormation(ZPS_tsAfEvent sStackEvent)
{
    /* wait for network stack to start up as a coordinator */
    if (ZPS_EVENT_NONE != sStackEvent.eType)
    {
        if (ZPS_EVENT_NWK_STARTED == sStackEvent.eType)
        {
            DBG_vPrintf(TRACE_APP, "APP: Network Started\r\n");

            /* turn on joining */
            ZPS_eAplZdoPermitJoining(PERMIT_JOIN_TIME_AFTER_STARTUP);

            OS_eStartSWTimer(APP_tmrLEDBlinkTimer,APP_TIME_MS(500),NULL);

            s_eDeviceState = E_RUNNING;
            /* Save the application state to flash. Note that all records may be saved at any time by the PDM:
             * if a module has called PDM_vSaveRecord(), but there is insufficient spare memory, an erase is performed
             * followed by a write of all records.
             */
            PDM_eSaveRecordData(PDM_ID_APP_COORD,
                                &s_eDeviceState,
                                sizeof(s_eDeviceState));
            ZPS_vSaveAllZpsRecords();
        }
    }
}
/****************************************************************************
 *
 * NAME: APP_taskBlinkLED
 *
 * DESCRIPTION:
 * LED blinking
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
OS_TASK(APP_taskBlinkLED)
{
    static bool bToggle=FALSE;
    /*Stop the timer and start it agian*/
    OS_eStopSWTimer(APP_tmrLEDBlinkTimer);
    OS_eStartSWTimer(APP_tmrLEDBlinkTimer,APP_TIME_MS(500),NULL);

    if(bToggle == TRUE)
    {
        bToggle=FALSE;
        /*SetLEDs ON*/
        vAHI_DioSetOutput(0,LED_NWK_FORMED);
        if(ZPS_bGetPermitJoiningStatus())
            vAHI_DioSetOutput(LED_PERMIT_JOIN,0);
    }
    else
    {
        bToggle=TRUE;

        /*Set LEDs OFF*/
        vAHI_DioSetOutput(LED_NWK_FORMED,0);
        vAHI_DioSetOutput(0,LED_PERMIT_JOIN);
    }
}


/****************************************************************************
 *
 * NAME: vHandleStackEvent
 *
 * DESCRIPTION:
 * Handles stack events after the Coordinator has started a network and is in
 * its running state
 *
 * PARAMETERS: Name         RW  Usage
 *             sStackEvent  R   Contains details of the stack event
 *
 * RETURNS:
 * Sequence number
 *
 ****************************************************************************/
PRIVATE void vHandleStackEvent(ZPS_tsAfEvent sStackEvent)
{
    if (ZPS_EVENT_NONE != sStackEvent.eType)
    {
        switch (sStackEvent.eType)
        {
             case ZPS_EVENT_APS_INTERPAN_DATA_INDICATION:
                  DBG_vPrintf(TRACE_APP, "APP: event  ZPS_EVENT_APS_INTERPAN_DATA_INDICATION\n");
                  PDUM_eAPduFreeAPduInstance(sStackEvent.uEvent.sApsInterPanDataIndEvent.hAPduInst);
                  break;

            case ZPS_EVENT_APS_DATA_INDICATION:
                DBG_vPrintf(TRACE_APP, "APP: vCheckStackEvent: ZPS_EVENT_AF_DATA_INDICATION\n");

                /* Process incoming cluster messages ... */
                DBG_vPrintf(TRACE_APP, "        Profile :%x\r\n",sStackEvent.uEvent.sApsDataIndEvent.u16ProfileId);
                DBG_vPrintf(TRACE_APP, "        Cluster :%x\r\n",sStackEvent.uEvent.sApsDataIndEvent.u16ClusterId);
                DBG_vPrintf(TRACE_APP, "        EndPoint:%x\r\n",sStackEvent.uEvent.sApsDataIndEvent.u8DstEndpoint);

                /* free the application protocol data unit (APDU) once it has been dealt with */
                PDUM_eAPduFreeAPduInstance(sStackEvent.uEvent.sApsDataIndEvent.hAPduInst);

                break;

            case ZPS_EVENT_APS_DATA_CONFIRM:
                DBG_vPrintf(TRACE_APP, "APP: vCheckStackEvent: ZPS_EVENT_APS_DATA_CONFIRM Status %d, Address 0x%04x\n",
                            sStackEvent.uEvent.sApsDataConfirmEvent.u8Status,
                            sStackEvent.uEvent.sApsDataConfirmEvent.uDstAddr.u16Addr);
                break;

            case ZPS_EVENT_APS_DATA_ACK:
                DBG_vPrintf(TRACE_APP, "APP: vCheckStackEvent: ZPS_EVENT_APS_DATA_ACK Status %d, Address 0x%04x\n",
                            sStackEvent.uEvent.sApsDataAckEvent.u8Status,
                            sStackEvent.uEvent.sApsDataAckEvent.u16DstAddr);
                break;

            case ZPS_EVENT_NWK_NEW_NODE_HAS_JOINED:
                DBG_vPrintf(TRACE_APP, "APP: vCheckStackEvent: vCheckStackEvent: ZPS_EVENT_NEW_NODE_HAS_JOINED, Nwk Addr=0x%04x\n",
                            sStackEvent.uEvent.sNwkJoinIndicationEvent.u16NwkAddr);
                vAgeChildren_ChildJoined(&sStackEvent);
                break;

            case ZPS_EVENT_NWK_LEAVE_INDICATION:
                DBG_vPrintf(TRACE_APP, "APP: vCheckStackEvent: ZPS_EVENT_LEAVE_INDICATION\n");
                break;

            case ZPS_EVENT_NWK_LEAVE_CONFIRM:
                DBG_vPrintf(TRACE_APP, "APP: vCheckStackEvent: ZPS_EVENT_LEAVE_CONFIRM\n");
                break;

            case ZPS_EVENT_NWK_STATUS_INDICATION:
                DBG_vPrintf(TRACE_APP, "APP: vCheckStackEvent: ZPS_EVENT_NWK_STATUS_INDICATION\n");
                break;

            case ZPS_EVENT_NWK_ROUTE_DISCOVERY_CONFIRM:
                DBG_vPrintf(TRACE_APP, "APP: vCheckStackEvent: ZPS_EVENT_ROUTE_DISCOVERY_CFM\n");
                break;

            case ZPS_EVENT_ERROR:
                           DBG_vPrintf(TRACE_APP, "APP: Monitor Sensors ZPS_EVENT_ERROR\n");
                           DBG_vPrintf(TRACE_APP, "    Error Code %d\n", sStackEvent.uEvent.sAfErrorEvent.eError);

                           if ( ZPS_ERROR_OS_MESSAGE_QUEUE_OVERRUN == sStackEvent.uEvent.sAfErrorEvent.eError)
                           {
                                   DBG_vPrintf(TRACE_APP, "    Queue handle %d\n",sStackEvent.uEvent.sAfErrorEvent.uErrorData.sAfErrorOsMessageOverrun.hMessage);
                           }
                           break;

            case ZPS_EVENT_NWK_POLL_CONFIRM:
                DBG_vPrintf(TRACE_APP, "APP: vCheckStackEvent: ZPS_EVENT_NEW_POLL_COMPLETE, status = %d\n",
                            sStackEvent.uEvent.sNwkPollConfirmEvent.u8Status );
                break;


            case ZPS_EVENT_NWK_JOINED_AS_ROUTER:
            case ZPS_EVENT_NWK_JOINED_AS_ENDDEVICE:
            case ZPS_EVENT_NWK_STARTED:
            case ZPS_EVENT_NWK_FAILED_TO_START:
            case ZPS_EVENT_NWK_FAILED_TO_JOIN:
            case ZPS_EVENT_NWK_DISCOVERY_COMPLETE:
                /*  Deliberate fall through */
            default:
                DBG_vPrintf(TRACE_APP, "APP: vCheckStackEvent: unhandled event %d\n", sStackEvent.eType);
                break;
        }
    }
}
/****************************************************************************
 *
 * NAME: bCheckDIO8
 *
 * DESCRIPTION:
 * Checks the DIO8 pin status
 *
 * PARAMETERS:
 *             void
 *
 * RETURNS:
 * Status of DIO press
 *
 ****************************************************************************/
PRIVATE bool bCheckDIO8( void )
{
    vAHI_DioSetDirection(APP_BUTTONS_DIO_MASK, 0);

    /* Turn on pull-ups for DIO lines with buttons connected */
    vAHI_DioSetPullup(APP_BUTTONS_DIO_MASK, 0);

    uint32 u32Buttons = u32AHI_DioReadInput() & APP_BUTTONS_DIO_MASK;
    if (u32Buttons != APP_BUTTONS_DIO_MASK)
    {
        return TRUE;
    }
    return FALSE;

}


/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

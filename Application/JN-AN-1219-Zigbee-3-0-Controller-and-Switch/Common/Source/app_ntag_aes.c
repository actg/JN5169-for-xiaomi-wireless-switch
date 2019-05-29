/*****************************************************************************
 *
 * MODULE:          JN-AN-1220 ZLO Sensor Demo
 *
 * COMPONENT:       app_ntag_aes.c
 *
 * DESCRIPTION:     ZLO Demo: Application layer for NTAG
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
 * Copyright NXP B.V. 2017. All rights reserved
 *
 ***************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include "dbg.h"
#include "ZTimer.h"
#include "pwrm.h"
#include "PDM.h"
#include "bdb_DeviceCommissioning.h"
#include "ntag.h"
#include "ntag_nwk.h"
#include "app_ntag_aes.h"
#include "app_main.h"
#include "app_buttons.h"
#include "PDM_IDs.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifdef DEBUG_APP_NTAG
    #define TRACE_APP_NTAG   TRUE
#else
    #define TRACE_APP_NTAG   FALSE
#endif
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
/* APP_NTAG States */
typedef enum
{
    E_APP_NTAG_STATE_NONE,              // 0
    E_APP_NTAG_STATE_ABSENT,            // 1
    E_APP_NTAG_STATE_PRESENT            // 2
} teAppNtagState;

/* APP_NTAG Modes */
typedef enum
{
    E_APP_NTAG_MODE_APP,                // 0
    E_APP_NTAG_MODE_NWK                 // 1
} teAppNtagMode;

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
PRIVATE void APP_vNtagPdmSave(tsNfcNwkNwk *psNtagNwk);

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
PRIVATE uint32                     u32AppNtagTicks;
PRIVATE uint32                     u32AppNtagMs;
PRIVATE teAppNtagState               eAppNtagState;
PRIVATE teAppNtagMode               eAppNtagMode;
PRIVATE uint8                       u8AppNtagNwkNscType;
PRIVATE tsNfcNwk                   sNfcNwk;
PRIVATE bool_t                       bNtagTimer;
PRIVATE tsNfcNwkNwk                sNtagNwkPdm;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
extern void APP_vFactoryResetRecords(void);

/****************************************************************************
 *
 * NAME: APP_vNtagPdmLoad
 *
 * DESCRIPTION:
 * Attempts to load PDM record and initiates OOBC if recovered
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC bool_t APP_bNtagPdmLoad(void)
{
    bool_t bReturn = FALSE;
    PDM_teStatus   ePdmStatus;
    uint16       u16PdmRead;

    /* Debug */
    DBG_vPrintf(TRACE_APP_NTAG, "\n%d: APP_vNtagPdmLoad()", u32AppNtagMs);
    /* Attempt to read data */
    ePdmStatus = PDM_eReadDataFromRecord(PDM_ID_APP_NTAG_NWK,
                                         &sNtagNwkPdm,
                                         sizeof(sNtagNwkPdm),
                                         &u16PdmRead);
    /* Debug */
    DBG_vPrintf(TRACE_APP_NTAG, "\n    PDM_eReadDataFromRecord(PDM_ID_APP_NTAG_NWK) = %d,%d", ePdmStatus, u16PdmRead);
    /* Recovered data ? */
    if (sizeof(sNtagNwkPdm) == u16PdmRead)
    {
        /* Got a valid channel ? */
        if (sNtagNwkPdm.u8Channel >= 11 && sNtagNwkPdm.u8Channel <= 26)
        {
            uint8 u8BdbOob;
            BDB_tsOobWriteDataToCommission sBdbOob;

            /* Populate BDB data */
            sBdbOob.u64PanId         = sNtagNwkPdm.u64ExtPanId;
            sBdbOob.u64TrustCenterAddress = sNtagNwkPdm.u64TrustCenterAddress;
            sBdbOob.pu8NwkKey        = sNtagNwkPdm.au8NetworkKey;
            sBdbOob.pu8InstallCode   = (uint8 *) NULL;
            sBdbOob.u16PanId         = sNtagNwkPdm.u16PanId;
            sBdbOob.u16ShortAddress  = 0xFFFF;
            sBdbOob.u8ActiveKeySqNum = sNtagNwkPdm.u8KeySeqNum;
            sBdbOob.u8DeviceType     = ZPS_eAplZdoGetDeviceType();
            sBdbOob.u8Channel        = sNtagNwkPdm.u8Channel;
            sBdbOob.u8NwkUpdateId    = 1;
            /* End device ? */
            if (sBdbOob.u8DeviceType == ZPS_ZDO_DEVICE_ENDDEVICE)
            {
                /* Use ED settings */
                sBdbOob.bRejoin          = TRUE;
                sBdbOob.u8RxOnWhenIdle   = FALSE;
            }
            /* Others ? */
            else
            {
                /* Use router settings */
                sBdbOob.bRejoin          = FALSE;
                sBdbOob.u8RxOnWhenIdle   = TRUE;
            }
            /* Commission device */
            u8BdbOob = BDB_u8OutOfBandCommissionStartDevice(&sBdbOob);
            /* Set on a network */
            sBDB.sAttrib.bbdbNodeIsOnANetwork = TRUE;
            /* Debug */
            DBG_vPrintf(TRACE_APP_NTAG, "\n    BDB_u8OutOfBandCommissionStartDevice() = %d", u8BdbOob);
            /* Clear record (can we delete it instead ?) */
            memset(&sNtagNwkPdm, 0, sizeof(sNtagNwkPdm));
            /* Save empty record */
            ePdmStatus = PDM_eSaveRecordData(PDM_ID_APP_NTAG_NWK,
                                             &sNtagNwkPdm,
                                             sizeof(sNtagNwkPdm));
            /* Debug */
            DBG_vPrintf(TRACE_APP_NTAG, "\n    PDM_eSaveRecordData(PDM_ID_APP_NTAG_NWK) = %d", ePdmStatus);
            /* Note we started the join process */
            bReturn = TRUE;
        }
    }

    return bReturn;
}

/****************************************************************************
 *
 * NAME: APP_vNtagStart
 *
 * DESCRIPTION:
 * Starts NTAG processing
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_vNtagStart(uint8 u8NscType)
{
    /* Debug */
    DBG_vPrintf(TRACE_APP_NTAG, "\n%d: APP_vNtagStart(x%02x)", u32AppNtagMs, u8NscType);
    /* Store the NSC device type */
    u8AppNtagNwkNscType = u8NscType;
    /* Initialise main NTAG state machine */
    NTAG_vInitialise(APP_NTAG_ADDRESS,
                     APP_NTAG_I2C_LOCATION,
                     APP_NTAG_I2C_FREQUENCY_HZ); /* Use SW3/DIO17 for NTAG FD pin */
    /* Set state and mode */
    eAppNtagState = E_APP_NTAG_STATE_NONE;
    eAppNtagMode  = E_APP_NTAG_MODE_APP;
    /* Register callback */
    NTAG_vRegCbEvent(APP_cbNtagEvent);
    /* Flag that the timer should run */
    bNtagTimer = TRUE;
    /* Start the timer */
    ZTIMER_eStart(u8TimerNtag, APP_NTAG_TICK_MS);
}

/****************************************************************************
 *
 * NAME: APP_vNtagStop
 *
 * DESCRIPTION:
 * Stops NTAG processing
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_vNtagStop(void)
{
    /* Debug */
    DBG_vPrintf(TRACE_APP_NTAG, "\n%d: APP_vNtagStop()", u32AppNtagMs);
    /* Flag that the timer shouldn't run */
    bNtagTimer = FALSE;
    /* De-register callback */
    NTAG_vRegCbEvent(NULL);
}

/****************************************************************************
 *
 * NAME: APP_cbNtagTimer
 *
 * DESCRIPTION:
 * Timer callback function
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_cbNtagTimer(void *pvParams)
{
    /* Restart the timer */
    if (bNtagTimer)
    {
        ZTIMER_eStart(u8TimerNtag, APP_NTAG_TICK_MS);
    }
    /* Debug */
    DBG_vPrintf(TRACE_APP_NTAG, ".");
    /* Increment tick counter and timer value */
    u32AppNtagTicks++;
    u32AppNtagMs += APP_NTAG_TICK_MS;
    /* Which mode are we in ? */
    switch (eAppNtagMode)
    {
        /* Network ? */
        case E_APP_NTAG_MODE_NWK:
        {
            teNtagNwkStatus eNtagNwkStatus;

            /* Maintain network NTAG state machine */
            eNtagNwkStatus = NTAG_NWK_eTick(APP_NTAG_TICK_MS);
            /* Network NTAG state machine finished ? */
            if (E_NTAG_NWK_ACTIVE != eNtagNwkStatus)
            {
                uint8 *pu8Data;
                uint8   u8Index;

                /* Debug */
                DBG_vPrintf(TRACE_APP_NTAG, "\n%d: APP_cbNtagTimer()", u32AppNtagMs);
                DBG_vPrintf(TRACE_APP_NTAG, ", NTAG_NWK_eTick() = %d", eNtagNwkStatus);
                DBG_vPrintf(TRACE_APP_NTAG, ", eAppNtagMode = APP");
                DBG_vPrintf(TRACE_APP_NTAG, "\n%d: NTAG_pu8Header()  =", u32AppNtagMs);
                pu8Data = NTAG_pu8Header();
#if TRACE_APP_NTAG
                for (u8Index = 0; u8Index < NFC_NWK_HEADER_SIZE; u8Index++)
                {
                    DBG_vPrintf(TRACE_APP_NTAG, " %02x", pu8Data[u8Index]);
                }
#endif

                /* Stop network processing */
                (void) NTAG_NWK_eStop();
                /* Go to application mode */
                eAppNtagMode = E_APP_NTAG_MODE_APP;
                /* Reclaim event callbacks */
                NTAG_vRegCbEvent(APP_cbNtagEvent);
                /* Success ? */
                if (E_NTAG_NWK_OK == eNtagNwkStatus)
                {
                    #if TRACE_APP_NTAG
                    {
                        uint32 u32Idx;

                        /* Debug */
                        DBG_vPrintf(TRACE_APP_NTAG, "\n    sNfcNwk.sNwk.u8NscType             = x%02x",     sNfcNwk.sNwk.u8NscType);
                        DBG_vPrintf(TRACE_APP_NTAG, "\n    sNfcNwk.sNwk.u8Command             = %d",        sNfcNwk.sNwk.u8Command);
                        DBG_vPrintf(TRACE_APP_NTAG, "\n    sNfcNwk.sNwk.u8Channel             = %d",        sNfcNwk.sNwk.u8Channel);
                        DBG_vPrintf(TRACE_APP_NTAG, "\n    sNfcNwk.sNwk.u16PanId              = x%04x",     sNfcNwk.sNwk.u16PanId);
                        DBG_vPrintf(TRACE_APP_NTAG, "\n    sNfcNwk.sNwk.u64ExtPanId           = %08x %08x", (uint32)(sNfcNwk.sNwk.u64ExtPanId           >> 32), (uint32)(sNfcNwk.sNwk.u64ExtPanId           & 0xffffffff));
                        DBG_vPrintf(TRACE_APP_NTAG, "\n    sNfcNwk.sNwk.u64TrustCenterAddress = %08x %08x", (uint32)(sNfcNwk.sNwk.u64TrustCenterAddress >> 32), (uint32)(sNfcNwk.sNwk.u64TrustCenterAddress & 0xffffffff));
                        DBG_vPrintf(TRACE_APP_NTAG, "\n    sNfcNwk.sNwk.au8NetworkKey         =");
                        for (u32Idx = 0; u32Idx < 16; u32Idx++) DBG_vPrintf(TRACE_APP_NTAG, " %02x", sNfcNwk.sNwk.au8NetworkKey[u32Idx]);
                        DBG_vPrintf(TRACE_APP_NTAG, "\n    sNfcNwk.sNwk.u8KeySeqNum           = %d",        sNfcNwk.sNwk.u8KeySeqNum);
                    }
                    #endif

                    /* Which command was passed back ? */
                    switch (sNfcNwk.sNwk.u8Command)
                    {
                        /* Return device to factory new */
                        case NFC_NWK_CMD_FACTORY_NEW:
                        {
                            /* Debug */
                            DBG_vPrintf(TRACE_APP_NTAG, "\n    ZPS_eAplZdoLeaveNetwork(0, F, F)");
                            /* Leave without rejoin request rejected (probably not in a network) ? */
                            /* Taken from app_router_node.c */
                            if (ZPS_E_SUCCESS !=  ZPS_eAplZdoLeaveNetwork(0, FALSE, FALSE))
                            {
                                /* Leave failed,so just reset everything */
                                APP_vFactoryResetRecords();
                                vAHI_SwReset();
                            }
                        }
                        break;

                        /* Join network ? */
                        case NFC_NWK_CMD_JOIN_NETWORK:
                        {
                            /* Save data to PDM */
                            APP_vNtagPdmSave(&sNfcNwk.sNwk);
                        }
                        break;

                        /* Secure join network with ECC encryption (not supported) */
                        case NFC_NWK_CMD_SECURE_JOIN_NETWORK:
                        {
                            /* Do nothing - not supported */
                            ;
                        }
                        break;

                        /* Leave network ? */
                        case NFC_NWK_CMD_LEAVE_NETWORK:
                        {
                            /* Debug */
                            DBG_vPrintf(TRACE_APP_NTAG, "\n    ZPS_eAplZdoLeaveNetwork(0, F, f)");
                            /* Leave with rejoin (delete children) */
                            ZPS_eAplZdoLeaveNetwork(0, FALSE, FALSE);
                        }
                        break;

                        /* Others ? */
                        default:
                        {
                            /* Do nothing */
                            ;
                        }
                        break;
                    }
                }
                /* Allow the timer to stop running */
                bNtagTimer = FALSE;
            }
        }
        break;

        /* Others (application mode) ? */
        default:
        {
            /* Maintain driver NTAG state machine */
            NTAG_vTick(APP_NTAG_TICK_MS);
        }
        break;
    }
}

/****************************************************************************
 *
 * NAME: APP_cbNtagEvent
 *
 * DESCRIPTION:
 * Called when a tag event takes place
 *
 * RETURNS:
 * None
 *
 ****************************************************************************/
PUBLIC  void        APP_cbNtagEvent(    /* Called when an event takes place */
        teNtagEvent eNtagEvent,         /* Event raised */
        uint32      u32Address,
        uint32      u32Length,
        uint8       *pu8Data)           /* Event data (NULL if no data) */
{
    /* Debug */
    DBG_vPrintf(TRACE_APP_NTAG, "\n%d: APP_cbNtagEvent(%d, %d, %d)", u32AppNtagMs, eNtagEvent, u32Address, u32Length);
    /* Which event ? */
    switch (eNtagEvent)
    {
        /* Absent ? */
        case E_NTAG_EVENT_ABSENT:
        {
            /* Not already absent ? */
            if (E_APP_NTAG_STATE_ABSENT != eAppNtagState)
            {
                /* Debug */
                DBG_vPrintf(TRACE_APP_NTAG, ", eAppNtagState = ABSENT");
                /* Go to absent state */
                eAppNtagState = E_APP_NTAG_STATE_ABSENT;
                /* Not in NWK mode ? */
                if (E_APP_NTAG_MODE_NWK != eAppNtagMode)
                {
                    /* Debug */
                    DBG_vPrintf(TRACE_APP_NTAG, ", eAppNtagMode = NWK");
                    /* Zero the NtagNwk data structure */
                    memset(&sNfcNwk, 0, sizeof(sNfcNwk));
                    /* Populate the device data in the NtagNwk structure */
                    sNfcNwk.sDev.u8NscType       = u8AppNtagNwkNscType;
                    sNfcNwk.sDev.u8Channel       = ZPS_u8AplZdoGetRadioChannel();           // NOT CURRENTLY USED
                    sNfcNwk.sDev.u16ShortAddress = ZPS_u16AplZdoGetNwkAddr();               // NOT CURRENTLY USED
                    sNfcNwk.sDev.u16PanId        = ZPS_u16AplZdoGetNetworkPanId();          // NOT CURRENTLY USED
                    sNfcNwk.sDev.u64ExtAddress   = ZPS_u64AplZdoGetIeeeAddr();
                    sNfcNwk.sDev.u64ExtPanId     = ZPS_u64AplZdoGetNetworkExtendedPanId();  // NOT CURRENTLY USED
                    /* Debug */
                    DBG_vPrintf(TRACE_APP_NTAG, "\n    sNfcNwk.sDev.u8NscType       = x%02x",     sNfcNwk.sDev.u8NscType);
                    DBG_vPrintf(TRACE_APP_NTAG, "\n    sNfcNwk.sDev.u64ExtAddress   = %08x %08x", (uint32)(sNfcNwk.sDev.u64ExtAddress >> 32), (uint32)(sNfcNwk.sDev.u64ExtAddress & 0xffffffff));
                    /* Go to network mode */
                    eAppNtagMode = E_APP_NTAG_MODE_NWK;
                    /* Start ntag network processing */
                    NTAG_NWK_eStart(&sNfcNwk);
                }
            }
        }
        break;

        /* Present ? */
        case E_NTAG_EVENT_PRESENT:
        {
            /* Not already present ? */
            if (E_APP_NTAG_STATE_PRESENT != eAppNtagState)
            {
                /* Debug */
                DBG_vPrintf(TRACE_APP_NTAG, ", eAppNtagState = PRESENT");
                /* Go to present state */
                eAppNtagState = E_APP_NTAG_STATE_PRESENT;
            }
        }
        break;

        /* Others ? */
        default:
        {
            /* Do nothing */
            ;
        }
        break;
    }
}

/****************************************************************************
 *
 * NAME: APP_vNtagPdmSave
 *
 * DESCRIPTION:
 * Saves PDM record and resets to force its load on startup
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void APP_vNtagPdmSave(tsNfcNwkNwk *psNtagNwk)
{
    PDM_teStatus   ePdmStatus;

    /* Debug */
    DBG_vPrintf(TRACE_APP_NTAG, "\n%d: APP_vNtagPdmSave()", u32AppNtagMs);
    /* Got a valid channel ? */
    if (psNtagNwk->u8Channel >= 11 && psNtagNwk->u8Channel <= 26)
    {
        /* Copy the data into our PDM structure */
        memcpy(&sNtagNwkPdm, psNtagNwk, sizeof(sNtagNwkPdm));
        /* Save record */
        ePdmStatus = PDM_eSaveRecordData(PDM_ID_APP_NTAG_NWK,
                                         &sNtagNwkPdm,
                                         sizeof(sNtagNwkPdm));
        /* Debug */
        DBG_vPrintf(TRACE_APP_NTAG, "\n    PDM_eSaveRecordData(PDM_ID_APP_NTAG_NWK) = %d", ePdmStatus);
        DBG_vPrintf(TRACE_APP_NTAG, "\n    vAHI_SwReset()");
        /* Reset */
        vAHI_SwReset();
    }
}

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

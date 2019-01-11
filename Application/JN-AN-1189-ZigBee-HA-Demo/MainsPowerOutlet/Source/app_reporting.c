/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          app_reporting.c
 *
 * DESCRIPTION:        ZHA Demo : Stack <-> Mains Power Outlet-App Interaction (Implementation)
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
#include "pdum_gen.h"
#include "pdm.h"
#include "pdum_gen.h"
#include "zps_gen.h"
#include "zps_apl.h"
#include "zps_apl_aib.h"
#include "zps_nwk_sap.h"
#include "app_common.h"
#include "PDM_IDs.h"
#include "zcl_options.h"
#include "app_zbp_utilities.h"
#include "zcl_common.h"
#include "app_reporting.h"

#ifdef CLD_GROUPS
#include "groups.h"
#include "Groups_internal.h"
#endif
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifndef DEBUG_REPORT
    #define TRACE_REPORT   FALSE
#else
    #define TRACE_REPORT   TRUE
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
/*Just Two reports for time being*/
PRIVATE tsReports asSavedReports[MAINS_POWER_OUTLET_NUMBER_OF_REPORTS];

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
/****************************************************************************
 *
 * NAME: eRestoreReports
 *
 * DESCRIPTION:
 * Loads the reporting information from the EEPROM/PDM
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC OS_teStatus eRestoreReports( void )
{
    /* Restore any report data that is previously saved to flash */
    uint16 u16ByteRead;
    PDM_teStatus eStatusReportReload = PDM_eReadDataFromRecord(PDM_ID_APP_REPORTS,
                                                              asSavedReports,
                                                              sizeof(asSavedReports),
                                                              &u16ByteRead);

    DBG_vPrintf(TRACE_REPORT,"eStatusReportReload=%d\n",eStatusReportReload);
    /* Restore any application data previously saved to flash */

    return  (eStatusReportReload);
}

/****************************************************************************
 *
 * NAME: vMakeSupportedAttributesReportable
 *
 * DESCRIPTION:
 * Makes the attributes reportable for On Off and Level control
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vMakeSupportedAttributesReportable(void)
{
    uint16 u16AttributeEnum;
    uint16 u16ClusterId;
    uint8 i;

    tsZCL_AttributeReportingConfigurationRecord *psAttributeReportingConfigurationRecord;

    DBG_vPrintf(TRACE_REPORT, "\n\r%s", __FUNCTION__);

    for(i = 0; i < MAINS_POWER_OUTLET_NUMBER_OF_REPORTS; i++)
    {
        teZCL_Status eStatus;

        u16AttributeEnum = asSavedReports[i].sAttributeReportingConfigurationRecord.u16AttributeEnum;
        u16ClusterId = asSavedReports[i].u16ClusterID;
        psAttributeReportingConfigurationRecord = &(asSavedReports[i].sAttributeReportingConfigurationRecord);
        eStatus = eZCL_SetReportableFlag(1, u16ClusterId, TRUE, FALSE, u16AttributeEnum);
        DBG_vPrintf(TRACE_REPORT, "\n\reZCL_SetReportableFlag: %x", eStatus);
        eStatus = eZCL_CreateLocalReport(1, u16ClusterId, 0, TRUE, psAttributeReportingConfigurationRecord);
        DBG_vPrintf(TRACE_REPORT, "\n\reZCL_CreateLocalReport: %x", eStatus);
    }
}

/****************************************************************************
 *
 * NAME: vLoadDefaultConfigForReportable
 *
 * DESCRIPTION:
 * Loads a default configuration
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vLoadDefaultConfigForReportable(void)
{
    uint8 u8Index;

    /* For OnOff attribute in ON Off Cluster */
    asSavedReports[0].u16ClusterID = GENERAL_CLUSTER_ID_ONOFF;
    asSavedReports[0].sAttributeReportingConfigurationRecord.eAttributeDataType = E_ZCL_BOOL;
    asSavedReports[0].sAttributeReportingConfigurationRecord.u16AttributeEnum = E_CLD_ONOFF_ATTR_ID_ONOFF;
    asSavedReports[0].sAttributeReportingConfigurationRecord.u16MaximumReportingInterval = HA_SYSTEM_MAX_REPORT_INTERVAL;
    asSavedReports[0].sAttributeReportingConfigurationRecord.u16MinimumReportingInterval = HA_SYSTEM_MIN_REPORT_INTERVAL;
    asSavedReports[0].sAttributeReportingConfigurationRecord.u16TimeoutPeriodField = 0;
    asSavedReports[0].sAttributeReportingConfigurationRecord.u8DirectionIsReceived = 0;
    asSavedReports[0].sAttributeReportingConfigurationRecord.uAttributeReportableChange.zuint8ReportableChange = 0;

    DBG_vPrintf(TRACE_REPORT,"\nLoaded Defaults Records \n");

    for(u8Index = 0; u8Index < MAINS_POWER_OUTLET_NUMBER_OF_REPORTS; u8Index++)
    {
        DBG_vPrintf(TRACE_REPORT,"\nCluster %d",asSavedReports[u8Index].u16ClusterID);
        DBG_vPrintf(TRACE_REPORT,"\nAtt Dta Type = %d",asSavedReports[u8Index].sAttributeReportingConfigurationRecord.eAttributeDataType);
        DBG_vPrintf(TRACE_REPORT,"\nAttr No = %d",asSavedReports[u8Index].sAttributeReportingConfigurationRecord.u16AttributeEnum);
        DBG_vPrintf(TRACE_REPORT,"\nMax = %d",asSavedReports[u8Index].sAttributeReportingConfigurationRecord.u16MaximumReportingInterval);
        DBG_vPrintf(TRACE_REPORT,"\nMin = %d",asSavedReports[u8Index].sAttributeReportingConfigurationRecord.u16MinimumReportingInterval);
        DBG_vPrintf(TRACE_REPORT,"\nTimeOut = %d",asSavedReports[u8Index].sAttributeReportingConfigurationRecord.u16TimeoutPeriodField);
        DBG_vPrintf(TRACE_REPORT,"\nDirection = %d",asSavedReports[u8Index].sAttributeReportingConfigurationRecord.u8DirectionIsReceived);
        DBG_vPrintf(TRACE_REPORT,"\nChange = %d\n",asSavedReports[u8Index].sAttributeReportingConfigurationRecord.uAttributeReportableChange.zuint8ReportableChange);
    }
    /*Save this Records*/
    PDM_eSaveRecordData(PDM_ID_APP_REPORTS,
                        asSavedReports,
                        sizeof(asSavedReports));
}


/****************************************************************************
 *
 * NAME: vSaveReportableRecord
 *
 * DESCRIPTION:
 * Loads a default configuration
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vSaveReportableRecord(uint8 u8Index,uint16 u16ClusterID, tsZCL_AttributeReportingConfigurationRecord* psAttributeReportingConfigurationRecord)
{
    asSavedReports[u8Index].u16ClusterID = u16ClusterID;
    memcpy(&(asSavedReports[u8Index].sAttributeReportingConfigurationRecord),psAttributeReportingConfigurationRecord,sizeof(tsZCL_AttributeReportingConfigurationRecord));

    DBG_vPrintf(TRACE_REPORT,"\nSaving Records \n");

    DBG_vPrintf(TRACE_REPORT,"\nCluster %d",asSavedReports[u8Index].u16ClusterID);
    DBG_vPrintf(TRACE_REPORT,"\nAtt Dta Type = %d",asSavedReports[u8Index].sAttributeReportingConfigurationRecord.eAttributeDataType);
    DBG_vPrintf(TRACE_REPORT,"\nAttr No = %d",asSavedReports[u8Index].sAttributeReportingConfigurationRecord.u16AttributeEnum);
    DBG_vPrintf(TRACE_REPORT,"\nMax = %d",asSavedReports[u8Index].sAttributeReportingConfigurationRecord.u16MaximumReportingInterval);
    DBG_vPrintf(TRACE_REPORT,"\nMin = %d",asSavedReports[u8Index].sAttributeReportingConfigurationRecord.u16MinimumReportingInterval);
    DBG_vPrintf(TRACE_REPORT,"\nTimeOut = %d",asSavedReports[u8Index].sAttributeReportingConfigurationRecord.u16TimeoutPeriodField);
    DBG_vPrintf(TRACE_REPORT,"\nDirection = %d",asSavedReports[u8Index].sAttributeReportingConfigurationRecord.u8DirectionIsReceived);
    DBG_vPrintf(TRACE_REPORT,"\nChange = %d\n\n",asSavedReports[u8Index].sAttributeReportingConfigurationRecord.uAttributeReportableChange.zuint8ReportableChange);

    /*Save this Records*/
    PDM_eSaveRecordData(PDM_ID_APP_REPORTS,
                        asSavedReports,
                        sizeof(asSavedReports));
}
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

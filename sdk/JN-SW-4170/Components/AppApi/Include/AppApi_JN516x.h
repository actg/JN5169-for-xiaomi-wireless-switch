/*****************************************************************************
 *
 * MODULE:             Application API header
 *
 * DESCRIPTION:        Select correct interface depending on chip / chip family
 *
 ****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products [NXP Microcontrollers such as JN5148, JN5142, JN5139].
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

/**
 * @defgroup g_app_sap Application MAC Service Access Point (SAP)
 */
#ifndef  APP_API_H_INCLUDED
#define  APP_API_H_INCLUDED

#if defined __cplusplus
extern "C" {
#endif

/****************************************************************************/
/***        Include Files                                                 ***/
/****************************************************************************/
#include <jendefs.h>
#include <mac_sap.h>
#include <mac_pib.h>

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#if (defined BUILD_FOR_ROM)
#error Bad build configuration
#endif

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
/**
 * @ingroup g_app_sap
 * @brief Get Buffer routine type
 *
 * Type of Get Buffer callback routine
 */
typedef MAC_DcfmIndHdr_s * (*PR_GET_BUFFER)(void *);

/**
 * @ingroup g_app_sap
 * @brief Post routine type
 *
 * Type of Post callback routine
 */
typedef void (*PR_POST_CALLBACK)(void *, MAC_DcfmIndHdr_s *);

/* Types for calls used to re-direct MAC request entry points */
typedef void (*PR_MLME_CALL)(void *, MAC_MlmeReqRsp_s *, MAC_MlmeSyncCfm_s *);
typedef void (*PR_MCPS_CALL)(void *, MAC_McpsReqRsp_s *, MAC_McpsSyncCfm_s *);

#ifdef JENNIC_CHIP_FAMILY_JN516x
/* High Power Module Enable */
#define APP_API_MODULE_STD 0
#define APP_API_MODULE_HPM05 1
#define APP_API_MODULE_HPM06 2
#endif

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
/* MAC is in RAM, link directly to internal functions */
#define pvAppApiGetMacHandle pvAppApiDefGetMacHandle
#define u32AppApiInit u32AppApiDefInit
#define vAppApiMlmeRequest vAppApiDefMlmeRequest
#define vAppApiMcpsRequest vAppApiDefMcpsRequest
#define eAppApiPlmeSet eAppApiDefPlmeSet
#define eAppApiPlmeGet eAppApiDefPlmeGet
#define pvAppApiGetMacAddrLocation pvAppApiDefGetMacAddrLocation
#define vAppApiSaveMacSettings vAppApiDefSaveMacSettings
#define vAppApiRestoreMacSettings vAppApiDefRestoreMacSettings

PUBLIC uint32
u32AppApiInit(PR_GET_BUFFER prMlmeGetBuffer,
              PR_POST_CALLBACK prMlmeCallback,
              void *pvMlmeParam,
              PR_GET_BUFFER prMcpsGetBuffer,
              PR_POST_CALLBACK prMcpsCallback,
              void *pvMcpsParam);

PUBLIC void *pvAppApiGetMacHandle(void);

/* MLME calls */
PUBLIC void
vAppApiMlmeRequest(MAC_MlmeReqRsp_s *psMlmeReqRsp,
                   MAC_MlmeSyncCfm_s *psMlmeSyncCfm);

PUBLIC void
vAppApiMcpsRequest(MAC_McpsReqRsp_s *psMcpsReqRsp,
                   MAC_McpsSyncCfm_s *psMcpsSyncCfm);

/* PLME calls */
PUBLIC PHY_Enum_e eAppApiPlmeSet(PHY_PibAttr_e ePhyPibAttribute,
                                 uint32 u32PhyPibValue);
PUBLIC PHY_Enum_e eAppApiPlmeGet(PHY_PibAttr_e ePhyPibAttribute,
                                 uint32 *pu32PhyPibValue);

PUBLIC void *pvAppApiGetMacAddrLocation(void);
PUBLIC void vAppApiSetMacAddrLocation(void *pvNewMacAddrLocation);
PUBLIC void  vAppApiSaveMacSettings(void);
PUBLIC void  vAppApiRestoreMacSettings(void);

PUBLIC void vAppApiSetMacEntryPoints(PR_MLME_CALL, PR_MCPS_CALL);
PUBLIC void vAppApiGetMacEntryPoints(PR_MLME_CALL *, PR_MCPS_CALL *);
PUBLIC void vAppApiRegisterTxStartCallback(void (*prvUserCallback)(uint8 u8Handle));
PUBLIC void vAppApiEnableBeaconResponse(bool_t bEnable);
PUBLIC void vAppApiNoCalibrationOnWarmStart(bool_t bNoCalibration);

PUBLIC void vAppApiSetSecurityMode(MAC_SecutityMode_e eSecurityMode);

PUBLIC void vMAC_RestoreSettings(void);
PUBLIC bool_t bAppApi_CurrentlyScanning(void);

PUBLIC void vAppApiSetHighPowerMode(uint8 u8ModuleID, bool_t bMode);

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

#if defined __cplusplus
}
#endif

#endif  /* APP_API_H_INCLUDED */

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/


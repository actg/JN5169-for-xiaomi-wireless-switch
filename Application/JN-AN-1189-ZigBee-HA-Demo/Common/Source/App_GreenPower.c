/*****************************************************************************
 *
 * MODULE:             JN-AN-1189 ZHA Demo
 *
 * COMPONENT:          App_GreenPower.c
 *
 * DESCRIPTION:        ZHA Application Green Power - Implementation
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
#include "App_GreenPower.h"
#include "ha.h"
#include "app_zcl_light_task.h"
#include "zps_apl_aib.h"
#include "app_common.h"
#ifdef CLD_GREENPOWER
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#ifdef DEBUG_APP_GP
    #define TRACE_APP_GP                       TRUE
#else
    #define TRACE_APP_GP                       FALSE
#endif

#define RESTORE_GP_DATA                      0xAB
#define FIRST_CMD_INDEX                        0x00

#define ANY_INDEX                             0xFF
#define GP_SINK_TABLE_COMM_MODE_MASK        0x0018
#define GP_APP_ID_MASK                         0x0007
#define GP_ON_PROXY_COMM_EXIT_CMD           0x04
#define GP_ON_WINDOW_EXPIRE_MASK            (0x01)            // On Commissioning Window expiration
#define GP_ON_PAIRING_SUCCESS_MASK           (0x02)            // On first Pairing success
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/


PRIVATE tsGP_TranslationTableEntry* psApp_GPGetTranslationTable(tuGP_ZgpdDeviceAddr *uSrcAddr);
void vAppAddTransTableEntries(uint8 u8TransEntries,
        tuGP_ZgpdDeviceAddr uRcvdGPDAddr,
         zbmap8   b8Options,
         tsGP_GpToZclCommandInfo *pCmdInfo);
teGP_GreenPowerStatus eApp_UpdateTranslationTable(tsGP_ZgpsTranslationTableUpdate *psUpdateCmd);
void vApp_UpdateTranslationTableOnPairingCfg(tsGP_ZgpsPairingConfigCmdRcvd *psPairingConfigCmdRcvd);
void vAppGPAddDevice(uint8 u8DeviceType,
        tuGP_ZgpdDeviceAddr uRcvdGPDAddr,
        zbmap8   b8Options,
        tsGP_ZgpCommissionIndication *psZgpCommissionIndication);


/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/


tsGPPDMData sGPPDMData;
extern uint8 s_au8LnkKeyArray[16];

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

tsGP_GreenPowerDevice               sDeviceInfo;

uint32 u32GPDSrcID;
bool bIsDeCommMode = FALSE;
/* Default Translation Table Entries in FLASH */


/* translation table entries for Level control device . The same is used for on/off device,Generic 1-state Switch, Advanced Generic 1-state Switch*/
tsGP_GpToZclCommandInfo asGpToZclLevelControlCmdInfo[] = {
    {E_GP_ZGP_LEVEL_CONTROL_SWITCH, E_GP_OFF, 0x00, 1, GP_GENERAL_CLUSTER_ID_ONOFF, 0x00, {0}}, /* On/Off Switch, GP Off Cmd Id, ZB Cmd Id, EP, Cluster ID, ZB Payload Length, NULL data */
    {E_GP_ZGP_LEVEL_CONTROL_SWITCH, E_GP_ON, 0x01, 1, GP_GENERAL_CLUSTER_ID_ONOFF, 0x00, {0}}, /* On/Off Switch, GP On Cmd Id, ZB Cmd Id, EP, Cluster ID, ZB Payload Length, NULL data */
    {E_GP_ZGP_LEVEL_CONTROL_SWITCH, E_GP_TOGGLE, 0x02, 1, GP_GENERAL_CLUSTER_ID_ONOFF, 0x00, {0}}, /* On/Off Switch, GP Toggle Cmd Id, ZB Cmd Id, EP, Cluster ID, ZB Payload Length, NULL data */
    {E_GP_ZGP_LEVEL_CONTROL_SWITCH, E_GP_LEVEL_CONTROL_STOP, E_CLD_LEVELCONTROL_CMD_STOP, 1, GP_GENERAL_CLUSTER_ID_LEVEL_CONTROL, 0x00, {0}}, /* Level control switch , Level control stop, ZB Cmd Id, EP, Cluster ID, ZB Payload Length, NULL data */
    {E_GP_ZGP_LEVEL_CONTROL_SWITCH, E_GP_MOVE_UP_WITH_ON_OFF, E_CLD_LEVELCONTROL_CMD_MOVE_WITH_ON_OFF, 1, GP_GENERAL_CLUSTER_ID_LEVEL_CONTROL, 0x02, {0,10}}, /* Level control switch,Move Up, ZB Cmd Id, EP, Cluster ID, ZB Payload Length, NULL data */
    {E_GP_ZGP_LEVEL_CONTROL_SWITCH, E_GP_MOVE_DOWN_WITH_ON_OFF, E_CLD_LEVELCONTROL_CMD_MOVE_WITH_ON_OFF, 1, GP_GENERAL_CLUSTER_ID_LEVEL_CONTROL, 0x02, {1,10}}, /* Level control switch, Move down, ZB Cmd Id, EP, Cluster ID, ZB Payload Length, NULL data */
};
/* translation table entries for number of paired endpoints 0x00 or 0xFD */
tsGP_GpToZclCommandInfo asGpToZclEp0xFDCmdInfo[] = {
    {0xFF, 0xFF, 0xFF, 0xFD, 0xFFFF, 0x00, {0}}, /* On/Off Switch, GP Off Cmd Id, ZB Cmd Id, EP, Cluster ID, ZB Payload Length, NULL data */
};

/* translation table entries for number of paired endpoints 0x00 or 0xFD */
tsGP_GpToZclCommandInfo asGpToZclTempSensorInforInfo[] = {
    {0x30, 0xAF, 0x0a, 0x01, 0x0402, 0xFF, {0}}
};


PDM_tsRecordDescriptor sGP_PDDesc;

bool bIsInCommissionMode = FALSE;
uint8 u8CommExitModeActual;
/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
void vApp_RegisterGPDevice(tfpZCL_ZCLCallBackFunction fptrEPCallBack)
{
    teZCL_Status eZCL_Status;
    teGP_ResetToDefaultConfig eResetToDefault = E_GP_DEFAULT_ATTRIBUTE_VALUE |E_GP_DEFAULT_SINK_TABLE_VALUE |E_GP_DEFAULT_PROXY_TABLE_VALUE;
#ifdef GP_COMBO_MIN_DEVICE
    /* Register GP End Point */
    eZCL_Status = eGP_RegisterComboMinimumEndPoint(
            GREENPOWER_END_POINT_ID,
            fptrEPCallBack,
            &sDeviceInfo,
            HA_PROFILE_ID,
            GP_NUMBER_OF_TRANSLATION_TABLE_ENTRIES,
            sGPPDMData.asTranslationTableEntry);

    /* Check GP end point registration status */
    if (eZCL_Status != E_ZCL_SUCCESS)
    {
            DBG_vPrintf(TRACE_APP_GP, "Error: eGP_RegisterComboMinimumEndPoint:%d\r\n", eZCL_Status);
    }

     if(RESTORE_GP_DATA == sGPPDMData.u8RestoreDefaults)
     {
        tsGP_PersistedData sGPData;


        DBG_vPrintf(TRACE_APP_GP, "sGPPDMData.u8RestoreDefaults = %d \n", sGPPDMData.u8RestoreDefaults);
        /* DO not reset sink table to default. Sink table is persisted */
        eResetToDefault = E_GP_DEFAULT_ATTRIBUTE_VALUE ;
        sGPData.pasZgpsSinkTable = (sDeviceInfo.sGreenPowerCustomDataStruct.asZgpsSinkTable);
        vGP_RestorePersistedData(&sGPData,eResetToDefault);

     }
     else
     {

        DBG_vPrintf(TRACE_APP_GP, "sGPPDMData.u8RestoreDefaults = %d should not be %d \n", sGPPDMData.u8RestoreDefaults, RESTORE_GP_DATA);
        vGP_RestorePersistedData(NULL,eResetToDefault);
        memset(&sGPPDMData.asGpToZclCmdInfoUpdate,0, sizeof(sGPPDMData.asGpToZclCmdInfoUpdate) );
     }
         sDeviceInfo.sServerGreenPowerCluster.b24ZgpsFeatures |=
             ( GP_FEATURE_ZGPD_SEC_LVL_0B01 | GP_FEATURE_ZGPD_SEC_LVL_0B10);
         sDeviceInfo.sServerGreenPowerCluster.b24ZgpsFeatures |= GP_FEATURE_CT_BASED_CMSNG;
         sDeviceInfo.sServerGreenPowerCluster.b8ZgpsSecLevel = GP_SECURITY_LEVEL;


     #ifdef GP_SECURITY
             sDeviceInfo.sServerGreenPowerCluster.b8ZgpSharedSecKeyType = GP_KEYTPE;
#ifdef CLD_GP_ATTR_ZGP_LINK_KEY
             memcpy(&(sDeviceInfo.sServerGreenPowerCluster.sZgpLinkKey),s_au8LnkKeyArray, 16 );
#endif
     #ifdef GPD_SEC_PRECONFIG_MODE
             uint8 key[] = GP_SHARED_KEY;
             memcpy(&sDeviceInfo.sServerGreenPowerCluster.sZgpSharedSecKey,key, 16 );
     #endif
     #endif

#endif


}
/****************************************************************************
 *
 * NAME: vAppGPEnterDeCommissioningMode
 *
 * DESCRIPTION:
 * Initiate  DeCommissioning Mode
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
void vAppGPEnterDeCommissioningMode(void)
{
#ifdef GP_COMBO_MIN_DEVICE
    {
        uint8 u8Status;
        tsZCL_Address                          sDestinationAddress;
        uint8 u8CommExitModeTemp = GP_ON_PROXY_COMM_EXIT_CMD | GP_ON_WINDOW_EXPIRE_MASK ;
        eZCL_ReadLocalAttributeValue(
                GREENPOWER_END_POINT_ID,
                GREENPOWER_CLUSTER_ID,
                TRUE,
                FALSE,
                FALSE,
                E_CLD_GP_ATTR_ZGPS_COMMISSIONING_EXIT_MODE,
                &u8CommExitModeActual);

        /* change to on exit command */
        u8Status =  eZCL_WriteLocalAttributeValue(
                        GREENPOWER_END_POINT_ID,
                        GREENPOWER_CLUSTER_ID,
                        TRUE,
                        FALSE,
                        FALSE,
                        E_CLD_GP_ATTR_ZGPS_COMMISSIONING_EXIT_MODE,
                        &u8CommExitModeTemp);

        sDestinationAddress.eAddressMode = E_ZCL_AM_BROADCAST;
        sDestinationAddress.uAddress.eBroadcastMode = ZPS_E_APL_AF_BROADCAST_RX_ON;

        u8Status = eGP_ProxyCommissioningMode(
                GREENPOWER_END_POINT_ID,
                        242,
                        sDestinationAddress,
                        E_GP_PROXY_COMMISSION_ENTER);
        DBG_vPrintf(TRACE_APP_GP, "eGP_ProxyCommissioningMode returned status 0x%x", u8Status);
        bIsDeCommMode = TRUE;

        #if (defined CLD_COLOUR_CONTROL) && !(defined ColorTempTunableWhiteLight)
            uint8 u8Red,u8Green,u8Blue;
            vApp_eCLD_ColourControl_GetRGB(&u8Red, &u8Green, &u8Blue);

            DBG_vPrintf(TRACE_APP_GP, "\nR %d G %d B %d L %d Hue %d Sat %d X %d Y %d On %d", u8Red, u8Green, u8Blue,
                    sLight.sLevelControlServerCluster.u8CurrentLevel,
                    sLight.sColourControlServerCluster.u8CurrentHue,
                    sLight.sColourControlServerCluster.u8CurrentSaturation,
                    sLight.sColourControlServerCluster.u16CurrentX,
                    sLight.sColourControlServerCluster.u16CurrentY,
                    sLight.sOnOffServerCluster.bOnOff);

        vRGBLight_SetLevels(!(sLight.sOnOffServerCluster.bOnOff),
                sLight.sLevelControlServerCluster.u8CurrentLevel,
                u8Red,
                u8Green,
                u8Blue);

        #elif (defined CLD_LEVEL_CONTROL) && !(defined ColorTempTunableWhiteLight)
           vWhiteLightSetLevels(!(sLight.sOnOffServerCluster.bOnOff), sLight.sLevelControlServerCluster.u8CurrentLevel);

        #elif (defined CLD_LEVEL_CONTROL) && (defined ColorTempTunableWhiteLight)
           vTunableWhiteLightSetLevels(!(sLight.sOnOffServerCluster.bOnOff), sLight.sLevelControlServerCluster.u8CurrentLevel,
                   sLight.sColourControlServerCluster.u16ColourTemperatureMired);
        #else
           /* Call on-off drivers here */
        #endif
    }

#endif
}
/****************************************************************************
 *
 * NAME: vAppGPEnterCommissioningMode
 *
 * DESCRIPTION:
 * Initiate  Commissioning Mode
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
void vAppGPEnterCommissioningMode(void)
{
#ifdef GP_COMBO_MIN_DEVICE
    {
        tsZCL_Address                          sDestinationAddress;
        sDestinationAddress.eAddressMode = E_ZCL_AM_BROADCAST;
        sDestinationAddress.uAddress.eBroadcastMode = ZPS_E_APL_AF_BROADCAST_RX_ON;

        uint8 u8Status = eGP_ProxyCommissioningMode(
                GREENPOWER_END_POINT_ID,
                        242,
                        sDestinationAddress,
                        E_GP_PROXY_COMMISSION_ENTER);
        DBG_vPrintf(TRACE_APP_GP, "eGP_ProxyCommissioningMode returned status 0x%x", u8Status);
        bIsInCommissionMode = TRUE;
    }

#endif
}
/****************************************************************************
 *
 * NAME: vLoadGPData
 *
 * DESCRIPTION:
 * Loads GP data from PDM
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
void vLoadGPData(void)
{
    uint16 u16ByteRead;
    PDM_eReadDataFromRecord(PDM_ID_APP_CLD_GP_TRANS_TABLE,
                                               &sGPPDMData,
                                               sizeof(tsGPPDMData),
                                               &u16ByteRead);
    PDM_eReadDataFromRecord(PDM_ID_APP_CLD_GP_SINK_TABLE,
                                                  &sDeviceInfo.sGreenPowerCustomDataStruct.asZgpsSinkTable,
                                                  sizeof(sDeviceInfo.sGreenPowerCustomDataStruct.asZgpsSinkTable),
                                                &u16ByteRead);
}
/****************************************************************************
 *
 * NAME: vHandleGreenPowerEvent
 *
 * DESCRIPTION:
 * GP Event Handler
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/


void vHandleGreenPowerEvent(tsGP_GreenPowerCallBackMessage *psGPMessage)
{
    DBG_vPrintf(TRACE_APP_GP, "Green Power Callback Message\n");
    uint8 i, u8Count;
    tsGP_TranslationTableEntry *psTranslationTableEntry = NULL;
    tsZCL_Address                          sDestinationAddress;
    switch(psGPMessage->eEventType)
    {
        case E_GP_COMMISSION_DATA_INDICATION:
        {

            tsGP_ZgpCommissionIndication *psZgpCommissionIndication;

            DBG_vPrintf(TRACE_APP_GP, "E_GP_COMMISSION_DATA_INDICATION \n");

            psZgpCommissionIndication = psGPMessage->uMessage.psZgpCommissionIndication;

            /* check type of indication */
            switch(psZgpCommissionIndication->eCmdType)
            {
                case E_GP_DATA_CMD_AUTO_COMM:
                {
                    /* Auto commissioning command, device type not known, set default   */
                    vAppGPAddDevice(E_GP_ZGP_LEVEL_CONTROL_SWITCH,
                            psZgpCommissionIndication->uCommands.sZgpDataCmd.uZgpdDeviceAddr,
                            psZgpCommissionIndication->uCommands.sZgpDataCmd.b8AppId,
                            psZgpCommissionIndication);

                    break;
                }
                case E_GP_COMM_NOTF_CMD:
                {
                    teGP_ZgpdDeviceId eZgpdDeviceId;
                    if(psZgpCommissionIndication->uCommands.sZgpCommissioningNotificationCmdPayload.eZgpdCmdId == E_GP_COMMISSIONING)
                    {
                        /* tunneled commissioning command , add device if device type is supported */
                       eZgpdDeviceId = psZgpCommissionIndication->uCommands.sZgpCommissioningNotificationCmdPayload.sZgpdCommandPayload.pu8Data[0];
                       vAppGPAddDevice(eZgpdDeviceId,
                               psZgpCommissionIndication->uCommands.sZgpCommissioningNotificationCmdPayload.uZgpdDeviceAddr,
                                (uint8)(psZgpCommissionIndication->uCommands.sZgpCommissioningNotificationCmdPayload.b16Options & 0x0007),
                                psZgpCommissionIndication);
                    }
                    else
                    {
                        /* Tunneled auto commissioning command, device type not known, set default   */
                        vAppGPAddDevice(E_GP_ZGP_LEVEL_CONTROL_SWITCH,
                                psZgpCommissionIndication->uCommands.sZgpCommissioningNotificationCmdPayload.uZgpdDeviceAddr,
                                (uint8)(psZgpCommissionIndication->uCommands.sZgpCommissioningNotificationCmdPayload.b16Options & 0x0007),
                                psZgpCommissionIndication);
                    }

                      break;
               }
               case E_GP_COMM_CMD:
               {
                   vAppGPAddDevice(psZgpCommissionIndication->uCommands.sZgpCommissionCmd.eZgpdDeviceId,
                           psZgpCommissionIndication->uCommands.sZgpCommissionCmd.uZgpdDeviceAddr,
                           psZgpCommissionIndication->uCommands.sZgpCommissionCmd.b8AppId,
                           psZgpCommissionIndication);
               }

                break;
            default:
                break;

            }
            break;
        }

        case E_GP_COMMISSION_MODE_ENTER:
        {
            DBG_vPrintf(TRACE_APP_GP, "E_GP_COMMISSION_MODE_ENTER \n");
            break;
        }

        case E_GP_COMMISSION_MODE_EXIT:
        {
            DBG_vPrintf(TRACE_APP_GP, "E_GP_COMMISSION_MODE_EXIT \n");
            if(bIsInCommissionMode)
            {
                sLight.sIdentifyServerCluster.u16IdentifyTime = 0;

                APP_vHandleIdentify(0);
                bIsInCommissionMode = FALSE;
            }
            else if (bIsDeCommMode)
            {

                bIsDeCommMode = FALSE;
                #if (defined CLD_COLOUR_CONTROL) && !(defined ColorTempTunableWhiteLight)
                    uint8 u8Red,u8Green,u8Blue;
                    vApp_eCLD_ColourControl_GetRGB(&u8Red, &u8Green, &u8Blue);

                    DBG_vPrintf(TRACE_APP_GP, "\nR %d G %d B %d L %d Hue %d Sat %d X %d Y %d On %d", u8Red, u8Green, u8Blue,
                            sLight.sLevelControlServerCluster.u8CurrentLevel,
                            sLight.sColourControlServerCluster.u8CurrentHue,
                            sLight.sColourControlServerCluster.u8CurrentSaturation,
                            sLight.sColourControlServerCluster.u16CurrentX,
                            sLight.sColourControlServerCluster.u16CurrentY,
                            sLight.sOnOffServerCluster.bOnOff);

                    vRGBLight_SetLevels((sLight.sOnOffServerCluster.bOnOff),
                            sLight.sLevelControlServerCluster.u8CurrentLevel,
                            u8Red,
                            u8Green,
                            u8Blue);
                #elif (defined CLD_LEVEL_CONTROL)&& !(defined ColorTempTunableWhiteLight)
                    vWhiteLightSetLevels(sLight.sOnOffServerCluster.bOnOff, sLight.sLevelControlServerCluster.u8CurrentLevel);

                #elif (defined CLD_LEVEL_CONTROL) && (defined ColorTempTunableWhiteLight)
                    vTunableWhiteLightSetLevels((sLight.sOnOffServerCluster.bOnOff), sLight.sLevelControlServerCluster.u8CurrentLevel,
                   sLight.sColourControlServerCluster.u16ColourTemperatureMired);
                #else
                    /* Call on-off drivers here */
                #endif
            }
                break;
        }

        case E_GP_CMD_UNSUPPORTED_PAYLOAD_LENGTH:
        {
            DBG_vPrintf(TRACE_APP_GP, "E_GP_CMD_UNSUPPORTED_PAYLOAD_LENGTH \n");
            break;
        }

        case E_GP_SINK_TABLE_ENTRY_ADDED:
        {
            tsGP_ZgpsSinkTable *psZgpsSinkTable;
            psZgpsSinkTable = psGPMessage->uMessage.psZgpsSinkTable;
            uint8 j = 0;
             if((((psZgpsSinkTable->b16Options & GP_SINK_TABLE_COMM_MODE_MASK) >> 3)
                     == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID) &&
                     bIsInCommissionMode)
             {
                 /* add group ids */
                ZPS_tsAplAib *tsAplAib  = ZPS_psAplAibGetAib();
                for(i = 0; ((psZgpsSinkTable->u8ZgpsGroupListEntries < GP_MAX_SINK_GROUP_LIST) &&
                        (i <  tsAplAib->psAplApsmeGroupTable->u32SizeOfGroupTable)); i++)
                {
                    for(j=0; j < sizeof(tsAplAib->psAplApsmeGroupTable->psAplApsmeGroupTableId[i].au8Endpoint); j++)
                    {
                        if((tsAplAib->psAplApsmeGroupTable->psAplApsmeGroupTableId[i].au8Endpoint[j]) == u8AppGetEPId())
                        {
                            psZgpsSinkTable->asZgpsGroupList[psZgpsSinkTable->u8ZgpsGroupListEntries].u16SinkGroup =
                                tsAplAib->psAplApsmeGroupTable->psAplApsmeGroupTableId[i].u16Groupid;
                            psZgpsSinkTable->asZgpsGroupList[psZgpsSinkTable->u8ZgpsGroupListEntries].u16Alias =
                                0xFFFF;

                            DBG_vPrintf(TRACE_APP_GP, "Adding group Id = 0x%8x in sink table = 0x%8x \n",
                                    tsAplAib->psAplApsmeGroupTable->psAplApsmeGroupTableId[i].u16Groupid ,
                                    psZgpsSinkTable->asZgpsGroupList[psZgpsSinkTable->u8ZgpsGroupListEntries].u16SinkGroup );
                            psZgpsSinkTable->u8ZgpsGroupListEntries++;
                            break;
                        }
                    }
                }
                bGP_IsSinkTableEntryPresent(GREENPOWER_END_POINT_ID,
                                    (psZgpsSinkTable->b16Options & GP_APP_ID_MASK) ,
                                    &(psZgpsSinkTable->uZgpdDeviceAddr),
                                    E_GP_SINK_TABLE_SET_ENTRY,
                                    psZgpsSinkTable,
                                    E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID);
             }
            DBG_vPrintf(TRACE_APP_GP, "E_GP_SINK_TABLE_ENTRY_ADDED \n");
            DBG_vPrintf(TRACE_APP_GP, "Sink Table Priority: 0x%02x\n", psZgpsSinkTable->eGreenPowerSinkTablePriority);
            DBG_vPrintf(TRACE_APP_GP, "Sink Table Options: 0x%04x\n", psZgpsSinkTable->b16Options);
            DBG_vPrintf(TRACE_APP_GP, "ZGPD Src Id: 0x%08x\n", psZgpsSinkTable->uZgpdDeviceAddr.u32ZgpdSrcId);
            DBG_vPrintf(TRACE_APP_GP, "GP Device Id: 0x%02x\n", psZgpsSinkTable->eZgpdDeviceId);
            DBG_vPrintf(TRACE_APP_GP, "Group Radius: 0x%02x\n", psZgpsSinkTable->u8GroupCastRadius);
            break;
        }

        case E_GP_SINK_TABLE_FULL:
        {
            DBG_vPrintf(TRACE_APP_GP, "E_GP_SINK_TABLE_FULL \n");
            break;
        }

        case E_GP_ZGPD_COMMAND_RCVD:
        {
            DBG_vPrintf(TRACE_APP_GP, "E_GP_ZGPD_COMMAND_RCVD \n");
            break;
        }

        case E_GP_ZGPD_CMD_RCVD_WO_TRANS_ENTRY:
        {
            DBG_vPrintf(TRACE_APP_GP, "E_GP_ZGPD_CMD_RCVD_WO_TRANS_ENTRY \n");
            break;
        }

        case E_GP_ADDING_GROUP_TABLE_FAIL:
        {
            DBG_vPrintf(TRACE_APP_GP, "E_GP_ADDING_GROUP_TABLE_FAIL \n");
            break;
        }
        case E_GP_SHARED_SECURITY_KEY_TYPE_IS_NOT_ENABLED:
        {
            DBG_vPrintf(TRACE_APP_GP, "E_GP_SHARED_SECURITY_KEY_TYPE_IS_NOT_ENABLED \n");
            break;
        }
        case E_GP_SHARED_SECURITY_KEY_IS_NOT_ENABLED:
        {
              DBG_vPrintf(TRACE_APP_GP, "E_GP_SHARED_SECURITY_KEY_IS_NOT_ENABLED \n");
              break;
        }
        case E_GP_RECEIVED_CHANNEL_REQUEST:
        {
            DBG_vPrintf(TRACE_APP_GP, "E_GP_RECEIVED_CHANNEL_REQUEST \n");
            break;
        }
        case E_GP_SUCCESS_CMD_RCVD:
        {
            DBG_vPrintf(TRACE_APP_GP, "E_GP_SUCCESS_CMD_RCVD \n");

            break;
        }
        case E_GP_PERSIST_ATTRIBUTE_DATA:
        {
            DBG_vPrintf(TRACE_APP_GP, "E_GP_PERSIST_ATTRIBUTE_DATA \n");
            sGPPDMData.u8RestoreDefaults = RESTORE_GP_DATA;

            PDM_eSaveRecordData(PDM_ID_APP_CLD_GP_TRANS_TABLE,
                                &sGPPDMData,
                                sizeof(tsGPPDMData));
            PDM_eSaveRecordData(PDM_ID_APP_CLD_GP_SINK_TABLE,
                                   &(sDeviceInfo.sGreenPowerCustomDataStruct.asZgpsSinkTable),
                                   sizeof(sDeviceInfo.sGreenPowerCustomDataStruct.asZgpsSinkTable));
            break;
        }
        case E_GP_TRANSLATION_TABLE_UPDATE:
            psGPMessage->uMessage.psTransationTableUpdate->eStatus =
            eApp_UpdateTranslationTable((psGPMessage->uMessage.psTransationTableUpdate));

            break;
        case E_GP_PAIRING_CONFIGURATION_CMD_RCVD:
            vApp_UpdateTranslationTableOnPairingCfg(psGPMessage->uMessage.psPairingConfigCmdRcvd);
            sGPPDMData.u8RestoreDefaults = RESTORE_GP_DATA;

            break;
        case E_GP_DECOMM_CMD_RCVD:
            DBG_vPrintf(TRACE_APP_GP, "E_GP_DECOMM_CMD_RCVD ,0x%08x\n",
                    psGPMessage->uMessage.psZgpDecommissionIndication->uZgpdDeviceAddr.u32ZgpdSrcId);
            for(u8Count = 0; u8Count < GP_NUMBER_OF_TRANSLATION_TABLE_ENTRIES; u8Count++)
            {
                psTranslationTableEntry =
                    psApp_GPGetTranslationTable(&(psGPMessage->uMessage.psZgpDecommissionIndication->uZgpdDeviceAddr));
                if(NULL != psTranslationTableEntry)
                {
                    memset(psTranslationTableEntry,0,sizeof(tsGP_TranslationTableEntry));
                }
            }
            sDestinationAddress.eAddressMode = E_ZCL_AM_BROADCAST;
                    sDestinationAddress.uAddress.eBroadcastMode = ZPS_E_APL_AF_BROADCAST_RX_ON;
            if(bIsDeCommMode)
            {

                 eGP_ProxyCommissioningMode(
                                GREENPOWER_END_POINT_ID,
                                242,
                                sDestinationAddress,
                                E_GP_PROXY_COMMISSION_EXIT);
                eZCL_WriteLocalAttributeValue(
                                GREENPOWER_END_POINT_ID,
                                GREENPOWER_CLUSTER_ID,
                                TRUE,
                                FALSE,
                                FALSE,
                                E_CLD_GP_ATTR_ZGPS_COMMISSIONING_EXIT_MODE,
                                &u8CommExitModeActual);
            }
            break;

        default:
        {
            DBG_vPrintf(TRACE_APP_GP, "Unknown event generated = %d\n", psGPMessage->eEventType);
            break;
        }
    }

}
/****************************************************************************
 *
 * NAME: vApp_UpdateTranslationTableOnpairingCfg
 *
 * DESCRIPTION:
 * GP translation table update when pairing configuration command is received
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/

void vApp_UpdateTranslationTableOnPairingCfg(tsGP_ZgpsPairingConfigCmdRcvd *psPairingConfigCmdRcvd)
{

    tsGP_TranslationTableEntry *psTranslationTableEntry = NULL;
    bool u8TransEntries = 0, u8Count;
    tsGP_GpToZclCommandInfo *pCmdInfo = NULL;
    uint8 i = 0, j=0;
    bool bAddTranslationTable = FALSE;

    switch(psPairingConfigCmdRcvd->eTranslationTableAction)
    {
        case E_GP_PAIRING_CONFIG_TRANSLATION_TABLE_ADD_ENTRY:
        {
            DBG_vPrintf(TRACE_APP_GP, "E_GP_PAIRING_CONFIG_EXTEND_SINK_TABLE_ENTRY  \n");
            if(psPairingConfigCmdRcvd->u8NumberOfPairedEndpoints == 0xFE)
            {
                if(psPairingConfigCmdRcvd->eCommunicationMode == E_GP_GROUP_FORWARD_ZGP_NOTIFICATION_TO_PRE_COMMISSION_GROUP_ID)
                {
                    /* check if any group added to application endpoint */
                    ZPS_tsAplAib * tsAplAib  = ZPS_psAplAibGetAib();
                    for(i = 0; ((i < psPairingConfigCmdRcvd->u8ZgpsGroupListEntries) &&
                                (bAddTranslationTable == FALSE)); i++)
                    {
                        for(j=0; j < tsAplAib->psAplApsmeGroupTable->u32SizeOfGroupTable;j++)
                        {
                            /*  If the group id a*/
                            if(tsAplAib->psAplApsmeGroupTable->psAplApsmeGroupTableId[j].u16Groupid ==
                                psPairingConfigCmdRcvd->asZgpsGroupList[i].u16SinkGroup)
                            {
                                bAddTranslationTable = TRUE;
                                break;
                            }
                        }

                    }
                    if(bAddTranslationTable == FALSE)
                    {
                        tuGP_ZgpdDeviceAddr uDummydeviceAddr = { 0 };
                        psTranslationTableEntry = psApp_GPGetTranslationTable(&uDummydeviceAddr);
                        if(NULL != psTranslationTableEntry)
                        {
                            psTranslationTableEntry->b8Options = psPairingConfigCmdRcvd->u8ApplicationId;
                            psTranslationTableEntry->uZgpdDeviceAddr = psPairingConfigCmdRcvd->uZgpdDeviceAddr;
                            psTranslationTableEntry->psGpToZclCmdInfo = &asGpToZclEp0xFDCmdInfo[FIRST_CMD_INDEX];
                        }
                    }
                }
                else
                {
                    bAddTranslationTable = TRUE;
                }
            }
            else if ((psPairingConfigCmdRcvd->u8NumberOfPairedEndpoints > 0 ) &&
                    (psPairingConfigCmdRcvd->u8NumberOfPairedEndpoints < 0xFD))
            {
                for(i = 0; (i < psPairingConfigCmdRcvd->u8NumberOfPairedEndpoints);i++)
                {
                    if(psPairingConfigCmdRcvd->au8PairedEndpointList[i] == u8AppGetEPId() )
                    {
                        bAddTranslationTable = TRUE;
                        break;
                    }
                }
            }
            else if ((psPairingConfigCmdRcvd->u8NumberOfPairedEndpoints == 0 ) ||
                     (psPairingConfigCmdRcvd->u8NumberOfPairedEndpoints == 0xFD))
            {
                tuGP_ZgpdDeviceAddr uDummydeviceAddr = { 0 };
                psTranslationTableEntry = psApp_GPGetTranslationTable(&uDummydeviceAddr);
                if(NULL != psTranslationTableEntry)
                {
                    psTranslationTableEntry->b8Options = psPairingConfigCmdRcvd->u8ApplicationId;
                    psTranslationTableEntry->uZgpdDeviceAddr = psPairingConfigCmdRcvd->uZgpdDeviceAddr;
                    psTranslationTableEntry->psGpToZclCmdInfo = &asGpToZclEp0xFDCmdInfo[FIRST_CMD_INDEX];
                }
            }

            if(bAddTranslationTable == FALSE)
            {
                return;
            }
             if(E_GP_ZGP_TEMP_SENSOR == psPairingConfigCmdRcvd->eZgpdDeviceId )
            {
                u8TransEntries = sizeof(asGpToZclTempSensorInforInfo)/sizeof(tsGP_GpToZclCommandInfo) ;
                pCmdInfo = &asGpToZclTempSensorInforInfo[FIRST_CMD_INDEX];
                DBG_vPrintf(TRACE_APP_GP, "E_GP_ZGP_TEMP_SENSOR vAppAddTransTableEntries  \n");
             }
            else
            {
                u8TransEntries = sizeof(asGpToZclLevelControlCmdInfo)/sizeof(tsGP_GpToZclCommandInfo) ;
                pCmdInfo = &asGpToZclLevelControlCmdInfo[FIRST_CMD_INDEX];
                DBG_vPrintf(TRACE_APP_GP, "E_GP_ZGP_LEVEL_CONTROL_SWITCH vAppAddTransTableEntries  \n");
            }



             vAppAddTransTableEntries(
                  u8TransEntries,
                  psPairingConfigCmdRcvd->uZgpdDeviceAddr,
                  psPairingConfigCmdRcvd->u8ApplicationId,
                  pCmdInfo);

             DBG_vPrintf(TRACE_APP_GP, "psPairingConfigCmdRcvd->eZgpdDeviceId = %d \n", psPairingConfigCmdRcvd->eZgpdDeviceId);

        }
        break;
    case E_GP_PAIRING_CONFIG_TRANSLATION_TABLE_REMOVE_ENTRY:

        DBG_vPrintf(TRACE_APP_GP, "E_GP_PAIRING_CONFIG_REMOVE_SINK_TABLE_ENTRY  \n");
        for(u8Count = 0; u8Count < GP_NUMBER_OF_TRANSLATION_TABLE_ENTRIES; u8Count++)
        {
            psTranslationTableEntry = psApp_GPGetTranslationTable(&psPairingConfigCmdRcvd->uZgpdDeviceAddr);
            if(NULL != psTranslationTableEntry)
            {
                memset(psTranslationTableEntry,0,sizeof(tsGP_TranslationTableEntry));
            }
        }
        break;
    default:
        DBG_vPrintf(TRACE_APP_GP, "vApp_UpdateTranslationTableOnPairingCfg default   \n");
        break;
    }

}

/****************************************************************************
 *
 * NAME: eApp_UpdateTranslationTable
 *
 * DESCRIPTION:
 * GP translation table update when translation table update command is received
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
teGP_GreenPowerStatus eApp_UpdateTranslationTable(tsGP_ZgpsTranslationTableUpdate *psUpdateCmd)
{
    uint8 i;
    teGP_GreenPowerStatus eStatus =E_GP_TRANSLATION_UPDATE_FAIL;
    tsGP_TranslationTableEntry *psTranslationTableEntry = NULL;
    /* uDummydeviceAddr will be used to get a unused/free entry from translation table */
    tuGP_ZgpdDeviceAddr uDummydeviceAddr = { 0 };
    switch(psUpdateCmd->eAction)
    {
    case E_GP_TRANSLATION_TABLE_ADD_ENTRY:
        if(psUpdateCmd->psTranslationUpdateEntry->u8Index == ANY_INDEX)
        {
            /* get free translation table entry(translation table entry with 0x0000 as src id)*/
            psTranslationTableEntry = psApp_GPGetTranslationTable(&uDummydeviceAddr);
        }
        else
        {
            if(psUpdateCmd->psTranslationUpdateEntry->u8Index < GP_NUMBER_OF_TRANSLATION_TABLE_ENTRIES)
            {
                psTranslationTableEntry =
                    &sGPPDMData.asTranslationTableEntry[psUpdateCmd->psTranslationUpdateEntry->u8Index];
                /* check if entry is empty*/
                if(psTranslationTableEntry->uZgpdDeviceAddr.u32ZgpdSrcId != 0)
                {
                    psTranslationTableEntry = NULL;
                }
            }

        }

        /*fall through */
    case E_GP_TRANSLATION_TABLE_REPLACE_ENTRY:
        if((psUpdateCmd->psTranslationUpdateEntry->u8Index < GP_NUMBER_OF_TRANSLATION_TABLE_ENTRIES) &&
                (E_GP_TRANSLATION_TABLE_REPLACE_ENTRY == psUpdateCmd->eAction))
        {
            psTranslationTableEntry = &sGPPDMData.asTranslationTableEntry[psUpdateCmd->psTranslationUpdateEntry->u8Index];
            for(i = 0 ; i < MAX_TRANSLATION_TABLE_UPDATE_ENTRIES; i++)
            {
                if(psTranslationTableEntry->psGpToZclCmdInfo == &sGPPDMData.asGpToZclCmdInfoUpdate[i])
                {
                    /* clear the entry, we are going to overwrite*/
                    memset(&sGPPDMData.asGpToZclCmdInfoUpdate[i],
                            0,
                            sizeof(tsGP_GpToZclCommandInfo));
                }
            }
        }
        if(psTranslationTableEntry != NULL)
        {
            DBG_vPrintf(TRACE_APP_GP, "E_GP_TRANSLATION_TABLE_ADD_ENTRY check\n");
            psTranslationTableEntry->psGpToZclCmdInfo = NULL;
            /* get a free entry to add command details*/
            for(i = 0 ; i < MAX_TRANSLATION_TABLE_UPDATE_ENTRIES; i++)
            {
                if(sGPPDMData.asGpToZclCmdInfoUpdate[i].u8EndpointId == 0x00)
                {
                    /* clear the entry, we are going to overwrite*/
                    psTranslationTableEntry->psGpToZclCmdInfo =
                        &sGPPDMData.asGpToZclCmdInfoUpdate[i];
                    break;
                }
            }
            if(psTranslationTableEntry->psGpToZclCmdInfo == NULL)
            {
                break;
            }
            if(psUpdateCmd->psTranslationUpdateEntry->u8EndpointId < 0xF0 )
            {
                if(psUpdateCmd->psTranslationUpdateEntry->u8EndpointId != u8AppGetEPId() )
                {
                    break;
                }
            }

            if(psUpdateCmd->psTranslationUpdateEntry->u8EndpointId == 0xFF)
            {
                psTranslationTableEntry->psGpToZclCmdInfo->u8EndpointId = 0xFF;
            }
            else
            {
                psTranslationTableEntry->psGpToZclCmdInfo->u8EndpointId =
                    u8AppGetEPId();
            }

            psTranslationTableEntry->b8Options =
                            psUpdateCmd->u8ApplicationId;
                        psTranslationTableEntry->uZgpdDeviceAddr =
                            psUpdateCmd->uZgpdDeviceAddr;

            psTranslationTableEntry->psGpToZclCmdInfo->eZgpdCommandId =
                psUpdateCmd->psTranslationUpdateEntry->eZgpdCommandId;

            psTranslationTableEntry->psGpToZclCmdInfo->u8ZbCommandId =
                psUpdateCmd->psTranslationUpdateEntry->u8ZbCommandId;




            psTranslationTableEntry->psGpToZclCmdInfo->u16ZbClusterId =
                psUpdateCmd->psTranslationUpdateEntry->u16ZbClusterId;

            psTranslationTableEntry->psGpToZclCmdInfo->u8ZbCmdLength =
                psUpdateCmd->psTranslationUpdateEntry->u8ZbCmdLength;

            memcpy(&psTranslationTableEntry->psGpToZclCmdInfo->au8ZbCmdPayload[0],
                    &psUpdateCmd->psTranslationUpdateEntry->au8ZbCmdPayload[0],
                    psTranslationTableEntry->psGpToZclCmdInfo->u8ZbCmdLength);

            eStatus =E_GP_TRANSLATION_UPDATE_SUCCESS;

        }
        break;
    case E_GP_TRANSLATION_TABLE_REMOVE_ENTRY:
        if(psUpdateCmd->psTranslationUpdateEntry->u8Index < GP_NUMBER_OF_TRANSLATION_TABLE_ENTRIES)
        {
            psTranslationTableEntry =
                &sGPPDMData.asTranslationTableEntry[psUpdateCmd->psTranslationUpdateEntry->u8Index];
            memset(psTranslationTableEntry,0,sizeof(tsGP_TranslationTableEntry));
            eStatus = E_GP_TRANSLATION_UPDATE_SUCCESS;
        }

        break;
    default:
        break;
    }
    return eStatus;
}
/****************************************************************************
 *
 * NAME: vAppAddTransTableEntries
 *
 * DESCRIPTION:
 * GP translation table addition during commissioning
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
void vAppAddTransTableEntries( uint8 u8TransEntries,
         tuGP_ZgpdDeviceAddr         uRcvdGPDAddr,
         zbmap8                      b8Options,
        tsGP_GpToZclCommandInfo      *pCmdInfo)
{

    uint8 u8Count = 0;
    tsGP_TranslationTableEntry *psTranslationTableEntry;
    /* uDummydeviceAddr will be used to get a unused/free entry from translation table */
    tuGP_ZgpdDeviceAddr uDummydeviceAddr = { 0 };

    if(u8TransEntries == 0)
    {
        return;
    }
    /* Check if previous entry with the same device exists, delete all such entries
     * if any  */
    for(u8Count = 0; u8Count < GP_NUMBER_OF_TRANSLATION_TABLE_ENTRIES; u8Count++)
    {
        psTranslationTableEntry =
            psApp_GPGetTranslationTable(&(uRcvdGPDAddr));
        if( psTranslationTableEntry == NULL )
        {

            break;
        }
        else
        {
            if(psTranslationTableEntry->psGpToZclCmdInfo->u8EndpointId != 0xFD)
            {

                /* clear entry */
                memset(&psTranslationTableEntry->uZgpdDeviceAddr, 0, sizeof(tuGP_ZgpdDeviceAddr));
                DBG_vPrintf(TRACE_APP_GP, "cleared translation table  \n");
            }

        }
    }
    u32GPDSrcID = uRcvdGPDAddr.u32ZgpdSrcId;
    /* Now add translation table entry for each command supported */

    DBG_vPrintf(TRACE_APP_GP, "adding commands \n");
    /* get free translation entry( entry with 0x00(uDummydeviceAddr) as src id )*/
    psTranslationTableEntry = psApp_GPGetTranslationTable(&uDummydeviceAddr);
    /* check pointer */
    if(psTranslationTableEntry != NULL)
    {
        psTranslationTableEntry->b8Options =
                b8Options;
        psTranslationTableEntry->uZgpdDeviceAddr =
                uRcvdGPDAddr;

        psTranslationTableEntry->psGpToZclCmdInfo = &(pCmdInfo[0]) ;
        psTranslationTableEntry->u8NoOfCmdInfo = u8TransEntries;
        DBG_vPrintf(TRACE_APP_GP, "ENTRY ADDED TO THE TABLE = 0x%x\n", psTranslationTableEntry->psGpToZclCmdInfo->eZgpdCommandId);
    }
}


/****************************************************************************
 *
 * NAME: psApp_GPGetTranslationTable
 *
 * DESCRIPTION:
 * Transition Table
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE tsGP_TranslationTableEntry* psApp_GPGetTranslationTable(tuGP_ZgpdDeviceAddr *uSrcAddr)
{
    uint8 u8Count;

    for(u8Count = 0; u8Count < GP_NUMBER_OF_TRANSLATION_TABLE_ENTRIES; u8Count++)
    {
        /* if ZGPD Src ID is zero then it is free entry */
        if(sGPPDMData.asTranslationTableEntry[u8Count].uZgpdDeviceAddr.u32ZgpdSrcId  == uSrcAddr->u32ZgpdSrcId)
        {
            DBG_vPrintf(TRACE_APP_GP, "psApp_GPGetTranslationTable Success\n");
            return &(sGPPDMData.asTranslationTableEntry[u8Count]);
        }
    }

    return NULL;
}
void vAppGPAddDevice(uint8                                 u8DeviceType,
                    tuGP_ZgpdDeviceAddr                 uRcvdGPDAddr,
                    zbmap8                               b8Options,
                    tsGP_ZgpCommissionIndication         *psZgpCommissionIndication)

{
     uint8 u8TransEntries = 0;
     tsGP_GpToZclCommandInfo *pCmdInfo = NULL;
    if(u8DeviceType == E_GP_ZGP_TEMP_SENSOR )
    {
        DBG_vPrintf(TRACE_APP_GP, "u8DeviceType == E_GP_ZGP_TEMP_SENSOR Success\n");
        /* Add sensor commands to translation table */
        u8TransEntries = sizeof(asGpToZclTempSensorInforInfo)/sizeof(tsGP_GpToZclCommandInfo) ;
        pCmdInfo = &asGpToZclTempSensorInforInfo[FIRST_CMD_INDEX];
    }
    else
    {
         /* Add Level control commands to translation table */
        DBG_vPrintf(TRACE_APP_GP, "u8DeviceType == E_GP_ZGP_LEVEL_CONTROL_SWITCH Success\n");
        u8TransEntries = sizeof(asGpToZclLevelControlCmdInfo)/sizeof(tsGP_GpToZclCommandInfo) ;
        pCmdInfo = &asGpToZclLevelControlCmdInfo[FIRST_CMD_INDEX];
    }

    if(pCmdInfo != NULL)
    {
        DBG_vPrintf(TRACE_APP_GP, "vAppAddTransTableEntries Success\n");
        vAppAddTransTableEntries(
                        u8TransEntries,
                        uRcvdGPDAddr,
                        b8Options,
                        pCmdInfo);
        psZgpCommissionIndication->psGpToZclCommandInfo = pCmdInfo;
    }
    else
    {
        DBG_vPrintf(TRACE_APP_GP, "Commissioning Failed \n");
        psZgpCommissionIndication->eStatus = E_ZCL_FAIL;
    }

}
#endif /* CLD_GREENPOWER */
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

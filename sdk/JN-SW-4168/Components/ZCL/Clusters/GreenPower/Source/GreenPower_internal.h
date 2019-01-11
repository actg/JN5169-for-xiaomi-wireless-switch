/*****************************************************************************
 *
 * MODULE:             Green Power Cluster
 *
 * COMPONENT:          GreenPower_internal.h
 *
 * AUTHOR:             Ramakrishna
 *
 * DESCRIPTION:        The Internal API for the Green Power Cluster
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/UnifiedZCL_ZLL102_HA122_Maintenance/Clusters/GreenPower/Source/GreenPower_internal.h $
 *
 * $Revision: 65741 $
 *
 * $LastChangedBy: nxp57621 $
 *
 * $LastChangedDate: 2014-11-19 07:04:45 +0000 (Wed, 19 Nov 2014) $
 *
 * $Id: GreenPower_internal.h 65741 2014-11-19 07:04:45Z nxp57621 $
 *
 *****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products  [NXP Microcontrollers such as JN5168, JN5164,
 * JN5161, JN5148, JN5142, JN5139].
 * You, and any third parties must reproduce the copyright and warranty notice
 * and any other legend of ownership on each  copy or partial copy of the software.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
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
 ****************************************************************************/

#ifndef  GP_INTERNAL_H_INCLUDED
#define  GP_INTERNAL_H_INCLUDED

#if defined __cplusplus
extern "C" {
#endif

/****************************************************************************/
/***        Include Files                                                 ***/
/****************************************************************************/

#include "jendefs.h"
#include "zcl.h"
#include "GreenPower.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
    /* GP Cluster Field MASKS */
#define GP_APPLICATION_ID_MASK                                          (0x0007)

#define GP_NOTIFICATION_APPOINT_TEMP_MASTER_MASK                        (0x0800)
#define GP_NOTIFICATION_SECURITY_LEVEL_MASK                             (0x00C0)
#define GP_NOTIFICATION_SECURITY_KEY_TYPE_MASK                          (0x0700)
#define GP_NOTIFICATION_ALSO_UNICAST_MASK                               (0x0008)
#define GP_NOTIFICATION_ALSO_DERIVED_GROUP_MASK                         (0x0010)
#define GP_NOTIFICATION_ALSO_COMMISSION_GROUP_MASK                      (0x0020)

#define GP_CMSNG_NOTIFICATION_APPOINT_TEMP_MASTER_MASK                  (0x0008)
#define GP_CMSNG_NOTIFICATION_SECURITY_LEVEL_MASK                       (0x0030)
#define GP_CMSNG_NOTIFICATION_SECURITY_KEY_TYPE_MASK                    (0x01C0)
#define GP_CMSNG_NOTIFICATION_SEC_PROCESS_FAIL_MASK                     (0x0200)

#define GP_PROXY_CMSNG_MODE_ACTION_FIELD_MASK                           (0x01)
#define GP_PROXY_CMSNG_MODE_EXIT_MODE_ON_WINDOW_EXPIRE_MASK             (0x02)
#define GP_PROXY_CMSNG_MODE_EXIT_MODE_ON_PAIRING_SUCCESS_MASK           (0x04)
#define GP_PROXY_CMSNG_MODE_EXIT_MODE_ON_PROXY_MODE_CMD_MASK            (0x08)
#define GP_PROXY_CMSNG_MODE_CHANNEL_PRESENT_MASK                        (0x10)

#define GP_PAIRING_ADD_SINK_MASK                                        (0x000008)
#define GP_PAIRING_REMOVE_GPD_MASK                                      (0x000010)
#define GP_PAIRING_COMM_MODE_MASK                                       (0x000060)
#define GP_PAIRING_GPD_FIXED_MASK                                       (0x000080)
#define GP_PAIRING_SEQ_NUM_CAP_MASK                                     (0x000100)
#define GP_PAIRING_SEC_LEVEL_MASK                                       (0x000600)
#define GP_PAIRING_SEC_KEY_TYPE_MASK                                    (0x003800)
#define GP_PAIRING_SECURITY_COUNTER_PRESENT_MASK                        (0x004000)
#define GP_PAIRING_SECURITY_KEY_PRESENT_MASK                            (0x008000)
#define GP_PAIRING_ASSIGNED_ALIAS_PRESENT_MASK                          (0x010000)
#define GP_PAIRING_FORWARDING_RADIUS_PRESENT_MASK                       (0x020000)


#define GP_ZGP_ACTIVE_FEATURES_ATTR_DEFAULT_VALUE                      (0x00FFFFFF)


/* Commissioning Exit mode */
#define GP_CMSNG_EXIT_MODE_ON_WINDOW_EXPIRE_MASK                        (0x01)            // On Commissioning Window expiration
#define GP_CMSNG_EXIT_MODE_ON_PAIRING_SUCCESS_MASK                      (0x02)            // On first Pairing success
#define GP_CMSNG_EXIT_MODE_ON_PROXY_MODE_MASK                           (0x04)            // On ZGP Proxy Commissioning Mode (exit)

/* sink table options field masks */
#define GP_SINK_TABLE_APP_ID_MASK                                       (0x0007)
#define GP_SINK_TABLE_COMM_MODE_MASK                                    (0x0018)
#define GP_SINK_TABLE_SEQ_NUM_CAP_MASK                                  (0x0020)
#define GP_SINK_TABLE_RX_ON_CAP_MASK                                    (0x0040)
#define GP_SINK_TABLE_FIXED_LOCATION_MASK                               (0x0080)
#define GP_SINK_TABLE_ASSIGNED_ADDR_MASK                                (0x0100)
#define GP_SINK_TABLE_SECURITY_USE_MASK                                 (0x0200)
#define GP_SECURITY_LEVEL_MASK                                          (0x03)
#define GP_SECURITY_KEY_TYPE_MASK                                       (0x1C)

/* proxy table options field masks */
#define GP_PROXY_TABLE_ENTRY_ACTIVE_MASK                                (0x0008)
#define GP_PROXY_TABLE_ENTRY_VALID_MASK                                 (0x0010)
#define GP_PROXY_TABLE_SEQ_NUM_CAP_MASK                                 (0x0020)
#define GP_PROXY_TABLE_UNICAST_GPS_MASK                                 (0x0040)
#define GP_PROXY_TABLE_DERIVED_GROUP_GPS_MASK                           (0x0080)
#define GP_PROXY_TABLE_COMMISSION_GROUP_GPS_MASK                        (0x0100)
#define GP_PROXY_TABLE_FIRST_TO_FWD_MASK                                (0x0200)
#define GP_PROXY_TABLE_IN_RANGE_MASK                                    (0x0400)
#define GP_PROXY_TABLE_GPD_FIXED_MASK                                   (0x0800)
#define GP_PROXY_TABLE_HAS_ALL_UNICAST_ROUTES_MASK                      (0x1000)
#define GP_PROXY_TABLE_ASSIGNED_ALIAS_MASK                              (0x2000)
#define GP_PROXY_TABLE_SECURITY_USE_MASK                                (0x4000)

/* GP Translation table update command options field mask */
#define GP_TRANS_UPDATE_ACTION_MASK                                     (0x0018)
#define GP_TRANS_UPDATE_NUM_OF_TRANSLATIONS_MASK                        (0x00E0)

/* GP Pairing search command options field mask */
#define GP_PAIRING_SEARCH_RQST_UNICAST_SINK_MASK                        (0x0008)
#define GP_PAIRING_SEARCH_RQST_DERIVED_GROUPCAST_SINK_MASK              (0x0010)
#define GP_PAIRING_SEARCH_RQST_COMMISSION_GROUPCAST_SINK_MASK           (0x0020)
#define GP_PAIRING_SEARCH_RQST_SECURITY_COUNTER_MASK                    (0x0040)
#define GP_PAIRING_SEARCH_RQST_SECURITY_KEY_MASK                        (0x0080)

/* GP Pairing Configuration command actions field mask */
#define GP_PAIRING_CONFIG_ACTION_MASK                                   (0x07)
#define GP_PAIRING_CONFIG_SEND_GP_PAIRING_MASK                          (0x08)

/* Commission Cmd Options Fields Mask */
#define GP_COMM_CMD_MAC_SEQ_NUM_CAP_MASK                                (0x01)
#define GP_COMM_CMD_RX_ON_CAP_MASK                                      (0x02)
#define GP_COMM_CMD_PANID_REQ_MASK                                      (0x10)
#define GP_COMM_CMD_ZGP_SEC_KEY_REQ_MASK                                (0x20)
#define GP_COMM_CMD_FIXED_LOCATION_MASK                                 (0x40)
#define GP_COMM_CMD_EXT_OPT_FIELD_MASK                                  (0x80)

/* Commission Cmd Extended Options Fields Mask */
#define GP_COMM_CMD_EXT_OPT_SEC_LEVEL_MASK                              (0x03)
#define GP_COMM_CMD_EXT_OPT_KEY_TYPE_MASK                               (0x1C)
#define GP_COMM_CMD_EXT_OPT_ZGPD_KEY_PRESENT_MASK                       (0x20)
#define GP_COMM_CMD_EXT_OPT_ZGPD_KEY_ENC_MASK                           (0x40)
#define GP_COMM_CMD_EXT_OPT_ZGPD_OUT_GOING_COUNTER_MASK                 (0x80)


#define GP_APPL_ID_4_BYTE                                               (0x00)
#define GP_APPL_ID_8_BYTE                                               (0x02)

#define GP_SINK_TABLE_MINIMUM_LENGTH                                     8
#define GP_PROXY_TABLE_MINIMUM_LENGTH                                    7
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

/* Server Transmission Cmd APIs */
PUBLIC teZCL_Status eGP_ProxyCommissioningModeSend(
                    uint8                                       u8SourceEndPointId,
                    uint8                                       u8DestinationEndPointId,
                    tsZCL_Address                               *psDestinationAddress,
                    uint8                                       *pu8TransactionSequenceNumber,
                    tsGP_ZgpProxyCommissioningModeCmdPayload    *psZgpProxyCommissioningModeCmdPayload);

/* Client Transmission Cmd APIs */
PUBLIC teZCL_Status eGP_ZgpNotificationSend(
                    uint8                                       u8SourceEndPointId,
                    uint8                                       u8DestinationEndPointId,
                    tsZCL_Address                               *psDestinationAddress,
                    uint8                                       *pu8TransactionSequenceNumber,
                    tsGP_ZgpNotificationCmdPayload              *psZgpNotificationPayload);

PUBLIC teZCL_Status eGP_ZgpCommissioningNotificationSend(
                    uint8                                       u8SourceEndPointId,
                    uint8                                       u8DestinationEndPointId,
                    tsZCL_Address                               *psDestinationAddress,
                    uint8                                       *pu8TransactionSequenceNumber,
                    tsGP_ZgpCommissioningNotificationCmdPayload *psZgpCmsngNotificationPayload);

/* Client Received Cmd APIs */
PUBLIC teZCL_Status eGP_ProxyCommissioningModeReceive(
                    ZPS_tsAfEvent                               *pZPSevent,
                    uint16                                      u16Offset,
                    tsGP_ZgpProxyCommissioningModeCmdPayload    *psZgpProxyCommissioningModeCmdPayload);

/* Server Received Cmd APIs */
PUBLIC teZCL_Status eGP_ZgpNotificationReceive(
                    ZPS_tsAfEvent                               *pZPSevent,
                    uint16                                      u16Offset,
                    tsGP_ZgpNotificationCmdPayload              *psZgpNotificationPayload);

PUBLIC teZCL_Status eGP_ZgpCommissioningNotificationReceive(
                    ZPS_tsAfEvent                               *pZPSevent,
uint16                                      u16Offset,
                    tsGP_ZgpCommissioningNotificationCmdPayload *psZgpCmsngNotificationPayload);

/* Green Power Command Handler APIs */
PUBLIC teZCL_Status eGP_HandleProxyCommissioningMode(
                    ZPS_tsAfEvent                               *pZPSevent,
                    tsZCL_EndPointDefinition                    *psEndPointDefinition,
                    tsZCL_ClusterInstance                       *psClusterInstance,
                    uint16                                      u16Offset);

PUBLIC teZCL_Status eGP_HandleZgpNotification(
                    ZPS_tsAfEvent                               *pZPSevent,
                    tsZCL_EndPointDefinition                    *psEndPointDefinition,
                    tsZCL_ClusterInstance                       *psClusterInstance,
                    uint16                                      u16Offset);

PUBLIC teZCL_Status eGP_HandleZgpCommissioningNotification(
                    ZPS_tsAfEvent                               *pZPSevent,
                    tsZCL_EndPointDefinition                    *psEndPointDefinition,
                    tsZCL_ClusterInstance                       *psClusterInstance,
                    uint16                                      u16Offset);

/* Green Power Cluster command Handler */
PUBLIC teZCL_Status eGP_GreenPowerCommandHandler(
                    ZPS_tsAfEvent                               *pZPSevent,
                    tsZCL_EndPointDefinition                    *psEndPointDefinition,
                    tsZCL_ClusterInstance                       *psClusterInstance);

/* Green Power Cluster Direct Command Handler */
PUBLIC teZCL_Status eGP_GreenPowerDirectCommandHandler(
                    ZPS_tsAfEvent                               *pZPSevent,
                    tsZCL_EndPointDefinition                    *psEndPointDefinition,
                    tsZCL_ClusterInstance                       *psClusterInstance);

PUBLIC uint16 u16GP_DeriveAliasSrcAddr(
                    uint8                                       u8ApplicationId,
                    tuGP_ZgpdDeviceAddr                         uZgpdID);

PUBLIC uint8 u8GP_DeriveAliasSeqNum(
                    uint8                                       u8GpdfSeqNum,
                    teGP_GreenPowerClusterCmdIds                eGpCmdId,
                    teGP_GreenPowerCommunicationMode            eCommunicationMode);

PUBLIC uint32 u32GP_CRC32(
                    uint8                                       *pu8Data,
                    uint32                                      u32Len);

PUBLIC bool_t bGP_IsDuplicatePkt(
                    uint8                                          u8SourceEndPointId,
                    bool                                           bIsServer,
                    uint8                                          u8ApplicationID,
                    tuGP_ZgpdDeviceAddr                            uZgpdDeviceAddr,
                    bool_t                                         bSecurityOptions,
                    uint32                                         u32SeqNoOrCounter,
                    uint8                                          u8CommandId,
                    uint8                                          u8PayloadLength,
                    uint8                                          *pu8Payload,
                    uint16                                         u16SourceAddress,
                    tsGP_GreenPowerCustomData                      *psGpCustomDataStructure);

PUBLIC bool_t bGP_IsFreshPkt(
                    uint8                                       u8EndPointId,
                    uint8                                       u8ApplicationId,
                    tuGP_ZgpdDeviceAddr                         *puZgpdAddress,
                    tsGP_GreenPowerCustomData                   *psGpCustomDataStructure,
#ifdef GP_PROXY_DEVICE
                    tsGP_ZgppProxyTable                         *psTableEntry,
#else
                    tsGP_ZgpsSinkTable                          *psTableEntry,
#endif
                    uint32                                      u32SeqNoOrCounter);

PUBLIC teZCL_Status eGP_GreenPowerAutoCommissionCmdHandler(
                    ZPS_tsAfEvent                               *pZPSevent,
                    tsZCL_EndPointDefinition                    *psEndPointDefinition,
                    tsZCL_ClusterInstance                       *psClusterInstance);

PUBLIC teZCL_Status eGP_GPDFHandler(
                    ZPS_tsAfEvent                               *pZPSevent,
                    tsZCL_EndPointDefinition                    *psEndPointDefinition,
                    tsGP_GreenPowerCustomData                   *psGpCustomDataStructure,
                    uint8                                       u8ApplicationId,
                    tuGP_ZgpdDeviceAddr                         *puZgpdAddress,
                    teGP_ZgpdCommandId                          eZgpdCommandId,
                    uint8                                       u8GpdCommandPayloadLength,
                    uint8                                       *pu8GpdCommandPayload);

PUBLIC teZCL_Status u16GP_APduInstanceReadWriteLongString(
                    uint8                                       u8EndPoint,
                    uint16                                      u16AttributeId,
                    bool_t                                      IsClientAttribute,
                    bool_t                                      bWriteAttributeValueIntoBuffer,
                    PDUM_thAPduInstance                         hAPduInst,
                    uint16                                      u16Pos,
                    uint16                                      *pu16NoOfBytes);

PUBLIC uint16 u16GP_ReadSinkTableString(
                    uint8                                       u8GreenPowerEndPointId,
                    uint8                                       *pu8Data,
                    uint16                                      u16StringSize);

PUBLIC uint16 u16GP_WriteSinkTableString(
                    uint8                                       u8GreenPowerEndPointId,
                    uint8                                       *pu8Data,
                    uint16                                      u16StringSize);

PUBLIC uint16 u16GP_GetStringSizeOfSinkTable(
                    uint8                                       u8GreenPowerEndPointId);

PUBLIC uint16 u16GP_ReadProxyTableString(
                    uint8                                       u8GreenPowerEndPointId,
                    uint8                                       *pu8Data,
                    uint16                                      u16StringSize);

PUBLIC uint16 u16GP_WriteProxyTableString(
                    uint8                                       u8GreenPowerEndPointId,
                    uint8                                       *pu8Data,
                    uint16                                      u16StringSize);

PUBLIC uint16 u16GP_GetStringSizeOfProxyTable(
                    uint8                                       u8GreenPowerEndPointId);

PUBLIC void vGp_TransmissionTimerCallback(
                    uint8                                       u8SrcEndPointId,
                    tsZCL_EndPointDefinition                    *psEndPointDefinition,
                    tsGP_GreenPowerCustomData                   *psGpCustomDataStructure);

PUBLIC teZCL_Status eGp_BufferTransmissionPacket(
                    tsGP_ZgpDataIndication                      *psZgpDataIndication,
                    teGP_GreenPowerBufferedCommands             eGreenPowerBufferedCommand,
                    tsGP_GreenPowerCustomData                   *psGreenPowerCustomData);

PUBLIC teZCL_Status eGP_ZgpPairingSend(
                    uint8                                  u8SourceEndPointId,
                    uint8                                  u8DestinationEndPointId,
                    tsZCL_Address                          *psDestinationAddress,
                    uint8                                  *pu8TransactionSequenceNumber,
                    tsGP_ZgpPairingCmdPayload              *psZgpPairingPayload);

PUBLIC teZCL_Status eGP_ZgpPairingReceive(
                    ZPS_tsAfEvent                          *pZPSevent,
                    uint16                                 u16Offset,
                    tsGP_ZgpPairingCmdPayload              *psZgpPairingPayload);


PUBLIC teZCL_Status eGP_ZgpPairingConfigReceive(
                    ZPS_tsAfEvent                          *pZPSevent,
                    uint16                                 u16Offset,
                    tsGP_ZgpPairingConfigCmdPayload        *psZgpPairingConfigPayload);

PUBLIC teZCL_Status eGP_ZgpPairingSearchSend(
                    uint8                                  u8SourceEndPointId,
                    uint8                                  u8DestinationEndPointId,
                    tsZCL_Address                          *psDestinationAddress,
                    uint8                                  *pu8TransactionSequenceNumber,
                    tsGP_ZgpPairingSearchCmdPayload        *psZgpPairingSearchPayload);

PUBLIC teZCL_Status eGP_ZgpPairingSearchReceive(
                    ZPS_tsAfEvent                          *pZPSevent,
                    uint16                                 u16Offset,
                    tsGP_ZgpPairingSearchCmdPayload        *psZgpPairingSearchPayload);



PUBLIC teZCL_Status eGP_ZgpTranslationTableRequestReceive(
                    ZPS_tsAfEvent                          *pZPSevent,
                    uint8                                  *pu8StartIndex);

PUBLIC teZCL_Status eGP_ZgpTranslationTableResponseSend(
                    uint8                                  u8SourceEndPointId,
                    uint8                                  u8DestinationEndPointId,
                    tsZCL_Address                          *psDestinationAddress,
                    uint8                                  *pu8TransactionSequenceNumber,
                    tsGP_ZgpTransTableResponseCmdPayload   *psZgpTransTableResponsePayload);

PUBLIC teZCL_Status eGP_ZgpTranslationTableResponseReceive(
                    ZPS_tsAfEvent                          *pZPSevent,
                    uint16                                 u16Offset,
                    tsGP_ZgpTransTableResponseCmdPayload   *psZgpTransTableResponsePayload);

PUBLIC teZCL_Status eGP_ZgpTranslationTableUpdateReceive(
                    ZPS_tsAfEvent                          *pZPSevent,
                    uint16                                 u16Offset,
                    tsGP_ZgpTranslationUpdateCmdPayload    *psZgpTransTableUpdatePayload);

PUBLIC teZCL_Status eGP_HandleZgpPairing(
                    ZPS_tsAfEvent                          *pZPSevent,
                    tsZCL_EndPointDefinition               *psEndPointDefinition,
                    tsZCL_ClusterInstance                  *psClusterInstance,
                    uint16                                 u16Offset);

PUBLIC teZCL_Status eGP_HandleZgpTranslationRequest(
                    ZPS_tsAfEvent                          *pZPSevent,
                    tsZCL_EndPointDefinition               *psEndPointDefinition,
                    tsZCL_ClusterInstance                  *psClusterInstance,
                    uint16                                 u16Offset);

PUBLIC teZCL_Status eGP_HandleZgpTranslationResponse(
                    ZPS_tsAfEvent                          *pZPSevent,
                    tsZCL_EndPointDefinition               *psEndPointDefinition,
                    tsZCL_ClusterInstance                  *psClusterInstance,
                    uint16                                 u16Offset);

PUBLIC teZCL_Status eGP_HandleZgpTranslationTableUpdate(
                    ZPS_tsAfEvent                          *pZPSevent,
                    tsZCL_EndPointDefinition               *psEndPointDefinition,
                    tsZCL_ClusterInstance                  *psClusterInstance,
                    uint16                                 u16Offset);

PUBLIC teZCL_Status eGP_HandleZgpPairingSearch(
                    ZPS_tsAfEvent                          *pZPSevent,
                    tsZCL_EndPointDefinition               *psEndPointDefinition,
                    tsZCL_ClusterInstance                  *psClusterInstance,
                    uint16                                 u16Offset);

PUBLIC teZCL_Status eGP_HandleZgpPairingConfig(
                    ZPS_tsAfEvent                          *pZPSevent,
                    tsZCL_EndPointDefinition               *psEndPointDefinition,
                    tsZCL_ClusterInstance                  *psClusterInstance,
                    uint16                                 u16Offset);


PUBLIC bool_t bGP_IsZgpdCommandSupported(
                    teGP_ZgpdCommandId                     eZgpdCommandId,
                    uint8                                  u8ZbCommandId,
                    uint16                                 u16ZbClusterId);

PUBLIC teZCL_Status eGP_GreenPowerChannelReqCmdHandler(
                    ZPS_tsAfEvent                               *pZPSevent,
                    tsZCL_EndPointDefinition                    *psEndPointDefinition,
                    tsZCL_ClusterInstance                       *psClusterInstance);

PUBLIC int8 i8GP_GetProxyDistance(uint8 u8LinkQuality);

PUBLIC uint8 u8GP_GetProxyDelay(uint8 u8LinkQuality);

PUBLIC teZCL_Status eGP_ZgpResponseSend(
                    uint8                                  u8SourceEndPointId,
                    uint8                                  u8DestinationEndPointId,
                    tsZCL_Address                          *psDestinationAddress,
                    uint8                                  *pu8TransactionSequenceNumber,
                    tsGP_ZgpResponseCmdPayload             *psZgpResponseCmdPayload);

PUBLIC teZCL_Status eGP_ZgpResponseReceive(
                    ZPS_tsAfEvent                          *pZPSevent,
                    uint16                                 u16Offset,
                    tsGP_ZgpResponseCmdPayload             *psZgpResponseCmdPayload);

PUBLIC teZCL_Status eGP_HandleZgpReponse(
                    ZPS_tsAfEvent                               *pZPSevent,
                    tsZCL_EndPointDefinition                    *psEndPointDefinition,
                    tsZCL_ClusterInstance                       *psClusterInstance,
                    uint16                                      u16Offset);

PUBLIC teZCL_Status eGP_GreenPowerCommissionCmdHandler(
                    ZPS_tsAfEvent                               *pZPSevent,
                    tsZCL_EndPointDefinition                    *psEndPointDefinition,
                    tsZCL_ClusterInstance                       *psClusterInstance);

PUBLIC teZCL_Status eGP_UpdateSinkTable(
                    tsZCL_EndPointDefinition                    *psEndPointDefinition,
                    tsGP_GreenPowerCustomData                   *psGpCustomDataStructure,
                    tsGP_ZgpsSinkTable                          *psZgpsSinkTable,
                    tsGP_GpToZclCommandInfo                     *psGpToZclCommandInfo,
                    uint8                                       u8AppId,
                    tuGP_ZgpdDeviceAddr                         uZgpdDeviceAddr,
                    uint8                                       u8SecLevel,
                    uint8                                       u8SecKeyType,
                    uint8                                       u8ZgpsCommunicationMode,
                    uint32                                      u32SecFrameCounter,
                    teZCL_Status                                eCommIndStatus,
                    bool_t                                      bIsSeqNumCap,
                    bool_t                                      bIsRxOnCapability,
                    bool_t                                      bIsFixedLocation);

PUBLIC teZCL_Status eGP_UpdateApsGroupTableAndDeviceAnnounce(
                    tsZCL_EndPointDefinition        *psEndPointDefinition,
                    tsGP_GreenPowerCustomData       *psGpCustomDataStructure,
                    tsGP_ZgpsSinkTable              *psZgpsSinkTable,
                    tsGP_ZgpDataIndication          *psZgpDataIndication,
                    teZCL_Status                    eCommIndStatus);

PUBLIC void vGP_RemoveGPEPFromGroup(tsGP_GreenPowerCustomData   *psGpCustomDataStructure,
                                    tsZCL_EndPointDefinition    *psEndPointDefinition,
                                    tsGP_ZgpsSinkTable          *psSinkTableEntry);

PUBLIC void vGP_AddGPEPToGroup(     tsGP_GreenPowerCustomData   *psGpCustomDataStructure,
                                    tsZCL_EndPointDefinition    *psEndPointDefinition,
                                    tsGP_ZgpsSinkTable          *psSinkTableEntry);

PUBLIC teZCL_Status eGP_GreenPowerSuccessCmdHandler(
                    ZPS_tsAfEvent                               *pZPSevent,
                    tsZCL_EndPointDefinition                    *psEndPointDefinition,
                    tsZCL_ClusterInstance                       *psClusterInstance);

PUBLIC teZCL_Status eGP_GreenPowerDeCommissionCmdHandler(
                    ZPS_tsAfEvent                               *pZPSevent,
                    tsZCL_EndPointDefinition                    *psEndPointDefinition,
                    tsZCL_ClusterInstance                       *psClusterInstance);

PUBLIC uint8 u8GP_GetDataReqHandle(
                    tsGP_GreenPowerCustomData                   *psGpCustomDataStructure);

PUBLIC teGP_GreenPowerStatus eGP_RemoveProxyTableEntry(
                    uint8                                  u8GreenPowerEndPointId,
                    tsGP_ZgppProxyTable                    *psProxyTableEntry);

PUBLIC uint16 u16GP_GetClusterId(teGP_ZgpdCommandId   eZgpdCommandId);
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

#if defined __cplusplus
}
#endif

#endif  /* GP_INTERNAL_H_INCLUDED */

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

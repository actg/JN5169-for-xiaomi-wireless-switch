/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          app_ota_client.c
 *
 * DESCRIPTION:        DK4 (DR1175/DR1199) OTA Client App (Implementation)
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
 * Copyright NXP B.V. 2013. All rights reserved
 *
 ***************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include <jendefs.h>

#include "dbg.h"
#include "pdm.h"
#include "PDM_IDs.h"

#include "os_gen.h"
#include "pdum_gen.h"

#ifdef CHECK_VBO_FOR_OTA_ACTIVITY
    /* On Chip Peripherals include */
    #include "AppHardwareApi.h"
#endif

#include "ota.h"
#include "ha.h"

#include "app_timer_driver.h"
#include "app_ota_client.h"

#if (defined DimmableLight) || (defined DimmableLightOpenHome) || (defined ColorDimmableLight) || (defined OTAColorDimmableLightWithOccupancy)
    #include "zha_light_node.h"
#endif

#ifdef DimmerSwitch
    #include "zha_switch_node.h"
#endif

#include "app_common.h"
#include "Utilities.h"
#include "rnd_pub.h"



#include "appZdpExtraction.h"
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#ifndef DEBUG_OTA_LNT
    #define TRACE_OTA_LNT               FALSE
#else
    #define TRACE_OTA_LNT               TRUE
#endif

#ifndef DEBUG_APP_OTA
    #define TRACE_APP_OTA               FALSE
#else
    #define TRACE_APP_OTA               TRUE
#endif
#ifndef DEBUG_OTA_CIR_LOOP
    #define TRACE_OTA_CIR_LOOP FALSE
#else
    #define TRACE_OTA_CIR_LOOP TRUE
#endif

#ifdef CHECK_VBO_FOR_OTA_ACTIVITY
    #define SYSCON_SYS_IM_ADDR  0x0200000cUL
    #define SYSCON_VBOCTRL_ADDR 0x02000044UL
#endif


#define OTA_CLIENT_EP 1
#define OTA_STARTUP_DELAY_IN_SEC 5

#define OTA_IDLE 0
#define OTA_FIND_SERVER 1
#define OTA_FIND_SERVER_WAIT 2
#define OTA_FIND_SERVER_ADDRESS 3
#define OTA_FIND_SERVER_ADDRESS_WAIT 4
#define OTA_QUERYIMAGE 5
#define OTA_DL_PROGRESS 6
#define OTA_QUERYIMAGE_WAIT 7
#define OTA_GET_IEEE_ADDRESS_OF_SERVER 8
#define OTA_RE_QUERYIMAGE 9

#define APP_IEEE_ADDR_RESPONSE 0x8001
#define APP_MATCH_DESCRIPTOR_RESPONSE 0x8006

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
typedef enum{
     QUERY_SENT,
     QUERY_RSP_RECEIVED_OK,
     QUERY_RSP_RECEIVED_ERR,
     QUERY_FINISHED
}teImageQueryStatus;

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
PRIVATE void vInitAndDisplayKeys(void);
PRIVATE bool_t bMatchRecieved(void);

tsCLD_AS_Ota_Persist test;

PRIVATE teZCL_Status eClientQueryNextImageRequest(
                    uint8 u8SourceEndpoint,
                    uint8 u8DestinationEndpoint,
                    uint16 u16DestinationAddress,
                    uint32 u32FileVersion,
                    uint16 u16HardwareVersion,
                    uint16 u16ImageType,
                    uint16 u16ManufacturerCode,
                    uint8 u8FieldControl);

PRIVATE ZPS_teStatus eSendOTAMatchDescriptor(uint16 u16ProfileId);
PRIVATE void vManagaeOTAState(void);
PRIVATE void vGetIEEEAddress(uint8 u8Index);
PRIVATE void vCheckForOTAMatch( ZPS_tsAfEvent  * psStackEvent);
PRIVATE void vCheckForOTAServerIeeeAddress( ZPS_tsAfEvent  * psStackEvent);
PRIVATE void vOTAPersist(void);
PRIVATE void vRestetOTADiscovery(void);
PRIVATE void vMonitorServerInDLProgress(void);

PRIVATE uint8 u8VerifyLinkKey(tsOTA_CallBackMessage *psCallBackMessage);

#ifdef CHECK_VBO_FOR_OTA_ACTIVITY
    PRIVATE void vOTAActivity(teOTAActivity eOTAActivity);
    PRIVATE void vSetNextBOEvent(teBrownOutTripVoltage eBOTripVoltage,uint32 u32Mask);
    PRIVATE teOTAActivity eGetOTAActivity(void);
#endif

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
tsOTA_PersistedData              sOTA_PersistedData;
PRIVATE tsOTA_PersistedData_App sOTA_PersistedData_App;


/* mac address */
PUBLIC  uint8 au8MacAddress[]  __attribute__ ((section (".ro_mac_address"))) = {
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

/* Pre-configured Link Key */
PUBLIC  uint8 s_au8LnkKeyArray[16] __attribute__ ((section (".ro_se_lnkKey"))) = {0x5a, 0x69, 0x67, 0x42, 0x65, 0x65, 0x41, 0x6c,
                                                                  0x6c, 0x69, 0x61, 0x6e, 0x63, 0x65, 0x30, 0x39};

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/
PRIVATE uint8 OTA_State=OTA_FIND_SERVER;
PRIVATE uint32 u32TimeOut=0;
PRIVATE tsDiscovedOTAServers sDiscovedOTAServers[MAX_SERVER_NODES];
PRIVATE uint32 u32OTAQueryTimeinSec= 0xFFFFFF;
PRIVATE uint8 u8Discovered;
PRIVATE bool_t bKeyVerified = FALSE;

PRIVATE uint8 au8MacAddressVolatile[8];

#ifdef CHECK_VBO_FOR_OTA_ACTIVITY
    PRIVATE teOTAActivity s_eOTAStartStop=APP_E_OTA_START;
#endif

PRIVATE uint8 u8NodeIndex;
PRIVATE uint8 u8EpIndex;
PRIVATE teImageQueryStatus eImageQueryStatus;

PRIVATE uint16 u16ExpectedManuf;
PRIVATE uint16 u16ExpectedFileType;
PRIVATE uint32 u32ExpectedVersion;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

/****************************************************************************
 *
 * NAME: vAppInitOTA
 *
 * DESCRIPTION:
 * Initialises application OTA client related data structures and calls
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/

PUBLIC void vAppInitOTA(void)
{
    tsNvmDefs sNvmDefs;
    teZCL_Status eZCL_Status;
    uint8 au8CAPublicKey[22];
    uint8 u8CurrentImageSector;

    DBG_vPrintf(TRACE_OTA_LNT, "**REBOOT**\n");

    vInitAndDisplayKeys();

#ifdef JENNIC_CHIP_FAMILY_JN516x
  #if JENNIC_CHIP==JN5168
            uint8 u8StartSector[1] = {0};
  #elif JENNIC_CHIP == JN5169
            uint8 u8StartSector[1] = {8};     
  #endif
#else
    #error "Define chip family"
#endif

    eZCL_Status = eOTA_UpdateClientAttributes(OTA_CLIENT_EP, 0); /* Initialise with the Ep = 1*/
    if (eZCL_Status != E_ZCL_SUCCESS)
    {
        DBG_vPrintf(TRACE_APP_OTA, "eOTA_UpdateClientAttributes returned error 0x%x", eZCL_Status);
    }

#if JENNIC_CHIP==JN5168
    sNvmDefs.u32SectorSize = 64*1024; /* Sector Size = 64K*/
    sNvmDefs.u8FlashDeviceType = E_FL_CHIP_AUTO;
#elif JENNIC_CHIP==JN5169
    sNvmDefs.u32SectorSize = 32*1024; /* Sector Size = 32K*/
    sNvmDefs.u8FlashDeviceType = E_FL_CHIP_INTERNAL;
#else
    error define the chip
#endif

    u8CurrentImageSector = u32REG_SysRead(REG_SYS_FLASH_REMAP) & 0xf;
    if (u8CurrentImageSector)
    {
        vREG_SysWrite(REG_SYS_FLASH_REMAP,  0xfedcba98);
#ifndef JN5168
        vREG_SysWrite(REG_SYS_FLASH_REMAP2, 0x76543210);
#endif
    }

    vOTA_FlashInit(NULL,&sNvmDefs);


#ifdef JENNIC_CHIP_FAMILY_JN516x
  #if JENNIC_CHIP==JN5168
        eZCL_Status = eOTA_AllocateEndpointOTASpace(
                OTA_CLIENT_EP,
                u8StartSector,
                OTA_MAX_IMAGES_PER_ENDPOINT,
                4,
                FALSE,
                au8CAPublicKey);
  #elif JENNIC_CHIP==JN5169
        eZCL_Status = eOTA_AllocateEndpointOTASpace(
                        OTA_CLIENT_EP,
                        u8StartSector,
                        OTA_MAX_IMAGES_PER_ENDPOINT,
                        8,                                 /* max sectors per image*/
                        FALSE,
                        au8CAPublicKey);

  #endif
#endif

    if (eZCL_Status != E_ZCL_SUCCESS)
    {
        DBG_vPrintf(TRACE_APP_OTA, "eAllocateEndpointOTASpace returned error 0x%x", eZCL_Status);
    }
    else
    {
        #if TRACE_APP_OTA
            tsOTA_ImageHeader          sOTAHeader;
            eOTA_GetCurrentOtaHeader(OTA_CLIENT_EP,FALSE,&sOTAHeader);
            DBG_vPrintf(TRACE_APP_OTA,"\n\nCurrent Image Details \n");
            DBG_vPrintf(TRACE_APP_OTA,"File ID = 0x%08x\n",sOTAHeader.u32FileIdentifier);
            DBG_vPrintf(TRACE_APP_OTA,"Header Ver ID = 0x%04x\n",sOTAHeader.u16HeaderVersion);
            DBG_vPrintf(TRACE_APP_OTA,"Header Length ID = 0x%04x\n",sOTAHeader.u16HeaderLength);
            DBG_vPrintf(TRACE_APP_OTA,"Header Control Filed = 0x%04x\n",sOTAHeader.u16HeaderControlField);
            DBG_vPrintf(TRACE_APP_OTA,"Manufac Code = 0x%04x\n",sOTAHeader.u16ManufacturerCode);
            DBG_vPrintf(TRACE_APP_OTA,"Image Type = 0x%04x\n",sOTAHeader.u16ImageType);
            DBG_vPrintf(TRACE_APP_OTA,"File Ver = 0x%08x\n",sOTAHeader.u32FileVersion);
            DBG_vPrintf(TRACE_APP_OTA,"Stack Ver = 0x%04x\n",sOTAHeader.u16StackVersion);
            DBG_vPrintf(TRACE_APP_OTA,"Image Len = 0x%08x\n\n\n",sOTAHeader.u32TotalImage);
        #endif

        eZCL_Status = eOTA_RestoreClientData(OTA_CLIENT_EP,&sOTA_PersistedData,TRUE);

        DBG_vPrintf(TRACE_APP_OTA,"OTA PDM Status = %d \n",eZCL_Status);

    }
#ifdef CHECK_VBO_FOR_OTA_ACTIVITY
    vInitVBOForOTA(APP_OTA_VBATT_LOW_THRES);
#endif

    DBG_vPrintf(TRACE_OTA_LNT, "**REBOOT**\n");
    u32OTAQueryTimeinSec = RND_u32GetRand(60, ((15*60)-10));
    DBG_vPrintf(TRACE_OTA_LNT, "Init OTA Tick to %d\n", u32OTAQueryTimeinSec);


}


#ifdef CHECK_VBO_FOR_OTA_ACTIVITY
/****************************************************************************
 *
 * NAME: vInitVBOForOTA
 *
 * DESCRIPTION:
 * Initializes the VBO for the trip
 *
 * PARAMETERS:
 * teBrownOutTripVoltage Brown out voltage enumeration values
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vInitVBOForOTA(teBrownOutTripVoltage eBOTripValue)
{
    /* WORKAROUND for [lpsw4269]Set trip voltage, enable SVM & disable reset on BO */
    *(uint32 *)SYSCON_VBOCTRL_ADDR = eBOTripValue |1;

    /* Enable Rising Event mask (VDD below BO trip voltage) */
    *(uint32 *)SYSCON_SYS_IM_ADDR |= E_AHI_SYSCTRL_VREM_MASK;


    if(bAHI_BrownOutStatus())
    {
        /* Depending on the voltage do a start or stop */
        DBG_vPrintf(TRACE_APP_OTA,"BrownOut at Init\n");
        vOTAActivity(APP_E_OTA_STOP);
    }
    else
    {
        vOTAActivity(APP_E_OTA_START);
        DBG_vPrintf(TRACE_APP_OTA,"Start at Init\n");
    }

}
/****************************************************************************
 *
 * NAME: vCbSystemControllerOTAVoltageCheck
 *
 * DESCRIPTION:
 * Checks the interrupt source and sets the next VBO trip voltage
 *
 * PARAMETERS:
 * u32DeviceId      The device that interrupted
 * u32ItemBitmap    The bit mask of the interrupt
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vCbSystemControllerOTAVoltageCheck(uint32 u32DeviceId, uint32 u32ItemBitmap)
{
    /* Disable both interrupts */
    *(uint32 *)SYSCON_SYS_IM_ADDR &= ~(E_AHI_SYSCTRL_VREM_MASK|E_AHI_SYSCTRL_VFEM_MASK);

    /* Validate interrupt source when brown out state entered */
    if (E_AHI_DEVICE_SYSCTRL == u32DeviceId)
    {
        /*Voltage is Low, hence setting voltage for the rising edge */
        if(E_AHI_SYSCTRL_VREM_MASK & u32ItemBitmap)
        {
            /*Stop OTA activity until next interrupt*/
            vSetNextBOEvent(APP_OTA_VBATT_HI_THRES,E_AHI_SYSCTRL_VFEM_MASK);
            /* OTA activity Stop */
            vOTAActivity(APP_E_OTA_STOP);
        }
        /* Voltage is reported high, hence set the falling edge  */
        else if (E_AHI_SYSCTRL_VFEM_MASK & u32ItemBitmap)
        {
            /*Start OTA activity until next interrupt*/
            vSetNextBOEvent(APP_OTA_VBATT_LOW_THRES,E_AHI_SYSCTRL_VREM_MASK);
            /* OTA activity Start/Stop */
            vOTAActivity(APP_E_OTA_START);
        }
    }
}
#endif
/****************************************************************************
 *
 * NAME: vLoadOTAPersistedData
 *
 * DESCRIPTION:
 * Loads back OTA persisted data from PDM in application at start up.
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vLoadOTAPersistedData(void)
{
    /*Restore OTA Persistent Data*/
    PDM_teStatus eStatusOTAReload;
    uint16 u16ByteRead=0;

    eStatusOTAReload = PDM_eReadDataFromRecord(PDM_ID_OTA_DATA,
                                                   &sOTA_PersistedData_App,
                                                   sizeof(tsOTA_PersistedData_App),
                                                   &u16ByteRead);

    memset(&sOTA_PersistedData,0,sizeof(tsOTA_PersistedData));
    sOTA_PersistedData.sAttributes.u64UgradeServerID = sOTA_PersistedData_App.sAttributes.u64UgradeServerID;
    sOTA_PersistedData.sAttributes.u32FileOffset = sOTA_PersistedData_App.sAttributes.u32FileOffset;
    sOTA_PersistedData.sAttributes.u32CurrentFileVersion = sOTA_PersistedData_App.sAttributes.u32CurrentFileVersion;
    sOTA_PersistedData.sAttributes.u16CurrentStackVersion = sOTA_PersistedData_App.sAttributes.u16CurrentStackVersion;
    sOTA_PersistedData.sAttributes.u32DownloadedFileVersion = sOTA_PersistedData_App.sAttributes.u32DownloadedFileVersion;
    sOTA_PersistedData.sAttributes.u16DownloadedStackVersion = sOTA_PersistedData_App.sAttributes.u16DownloadedStackVersion;
    sOTA_PersistedData.sAttributes.u8ImageUpgradeStatus = sOTA_PersistedData_App.sAttributes.u8ImageUpgradeStatus;
    sOTA_PersistedData.sAttributes.u16ManfId = sOTA_PersistedData_App.sAttributes.u16ManfId;
    sOTA_PersistedData.sAttributes.u16ImageType = sOTA_PersistedData_App.sAttributes.u16ImageType;
    sOTA_PersistedData.sAttributes.u16MinBlockRequestDelay = sOTA_PersistedData_App.sAttributes.u16MinBlockRequestDelay;

#ifndef OTA_APP_PDM_OPTIMISE
    sOTA_PersistedData.u32FunctionPointer         = sOTA_PersistedData_App.u32FunctionPointer;
#endif

    sOTA_PersistedData.u32RequestBlockRequestTime = sOTA_PersistedData_App.u32RequestBlockRequestTime;
    sOTA_PersistedData.u32CurrentFlashOffset      = sOTA_PersistedData_App.u32CurrentFlashOffset;
    sOTA_PersistedData.u32TagDataWritten         = sOTA_PersistedData_App.u32TagDataWritten;
    sOTA_PersistedData.u32Step                   = sOTA_PersistedData_App.u32Step;
    sOTA_PersistedData.u16ServerShortAddress     = sOTA_PersistedData_App.u16ServerShortAddress;
#ifndef OTA_APP_PDM_OPTIMISE
#ifdef OTA_CLD_ATTR_REQUEST_DELAY
    sOTA_PersistedData.bWaitForBlockReq          = sOTA_PersistedData_App.bWaitForBlockReq;
#endif
#endif

    memcpy(&(sOTA_PersistedData.u8ActiveTag),&(sOTA_PersistedData_App.u8ActiveTag),OTA_TAG_HEADER_SIZE);
    memcpy(&(sOTA_PersistedData.u8PassiveTag),&(sOTA_PersistedData_App.u8PassiveTag),OTA_TAG_HEADER_SIZE);
    memcpy(&(sOTA_PersistedData.au8Header),&(sOTA_PersistedData_App.au8Header),OTA_MAX_HEADER_SIZE);

#ifndef OTA_APP_PDM_OPTIMISE
    sOTA_PersistedData.u8Retry                   = sOTA_PersistedData_App.u8Retry;
#endif

    sOTA_PersistedData.u8RequestTransSeqNo       = sOTA_PersistedData_App.u8RequestTransSeqNo ;
    sOTA_PersistedData.u8DstEndpoint             = sOTA_PersistedData_App.u8DstEndpoint ;

#ifndef OTA_APP_PDM_OPTIMISE
    sOTA_PersistedData.bIsCoProcessorImage       = sOTA_PersistedData_App.bIsCoProcessorImage;
    sOTA_PersistedData.bIsSpecificFile           = sOTA_PersistedData_App.bIsSpecificFile;
#endif

    sOTA_PersistedData.bIsNullImage              = sOTA_PersistedData_App.bIsNullImage;

#ifndef OTA_APP_PDM_OPTIMISE
    sOTA_PersistedData.u8CoProcessorOTAHeaderIndex = sOTA_PersistedData_App.u8CoProcessorOTAHeaderIndex;
    sOTA_PersistedData.u32CoProcessorImageSize     = sOTA_PersistedData_App.u32CoProcessorImageSize;
    sOTA_PersistedData.u32SpecificFileSize         = sOTA_PersistedData_App.u32SpecificFileSize;

#ifdef OTA_INTERNAL_STORAGE
    sOTA_PersistedData.u8Buf[0]     = sOTA_PersistedData_App.u8Buf[0];
    sOTA_PersistedData.u8Buf[1]     = sOTA_PersistedData_App.u8Buf[1];
    sOTA_PersistedData.u8Buf[2]     = sOTA_PersistedData_App.u8Buf[2];
    sOTA_PersistedData.u8Buf[3]     = sOTA_PersistedData_App.u8Buf[3];
#endif
#endif

    DBG_vPrintf(TRACE_APP_OTA,"PDM read bytes = %d\n",u16ByteRead);
    DBG_vPrintf(TRACE_APP_OTA,"eStatusOTAReload=%d\n",eStatusOTAReload);

    if (eStatusOTAReload== PDM_E_STATUS_OK)
    {
        /*Make Block request time 1 as time cluster is not present*/
        if(sOTA_PersistedData.u32RequestBlockRequestTime != 0)
        {
            sOTA_PersistedData.u32RequestBlockRequestTime = 1;
        }
        /*Make retries 0*/
        sOTA_PersistedData.u8Retry = 0;

        if (sOTA_PersistedData.sAttributes.u8ImageUpgradeStatus == E_CLD_OTA_STATUS_NORMAL)
            OTA_State = OTA_FIND_SERVER;
        else
            OTA_State = OTA_DL_PROGRESS;
    }
}
/****************************************************************************
 *
 * NAME: vHandleZDPReqResForOTA
 *
 * DESCRIPTION:
 * Handles the stack event for OTA discovery. Called from the OS Task
 * upon a stack event.
 *
 * INPUT:
 * ZPS_tsAfEvent  * psStackEvent Pointer to stack event
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vHandleZDPReqResForOTA(ZPS_tsAfEvent  * psStackEvent)
{
    if(OTA_State == OTA_FIND_SERVER_WAIT)
    {
        vCheckForOTAMatch(psStackEvent);
    }
    if(OTA_State == OTA_GET_IEEE_ADDRESS_OF_SERVER)
    {
        vCheckForOTAServerIeeeAddress(psStackEvent);
    }
}
/****************************************************************************
 *
 * NAME: vRunAppOTAStateMachine
 *
 * DESCRIPTION:
 * Timely checks for the OTA upgrade when the device state is running.
 * This is called from a timer ticking at rate of 1sec
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vRunAppOTAStateMachine(void)
{
    #ifdef CHECK_VBO_FOR_OTA_ACTIVITY
    DBG_vPrintf(TRACE_APP_OTA,"OTA Activity = %d \n",eGetOTAActivity());
    if(APP_E_OTA_STOP != eGetOTAActivity())
    #endif
    {
        if( E_RUNNING == eGetNodeState())
        {
             /*Increment Second timer */
            u32OTAQueryTimeinSec++;
            vManagaeOTAState();
        }

    }
}

/****************************************************************************
 *
 * NAME: vHandleAppOtaClient
 *
 * DESCRIPTION:
 * Handles the OTA Cluster Client events.
 * This is called from the EndPoint call back in the application
 * when an OTA event occurs.
 *
 * INPUT:
 * tsOTA_CallBackMessage *psCallBackMessage Pointer to cluster callback message
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vHandleAppOtaClient(tsOTA_CallBackMessage *psCallBackMessage)
{
    tsZCL_Address sZCL_Address;
    if(psCallBackMessage->eEventId == E_CLD_OTA_COMMAND_QUERY_NEXT_IMAGE_RESPONSE )
    {
        DBG_vPrintf(TRACE_APP_OTA|TRACE_OTA_LNT,"\nQuery Next Image Response status %02x\n", psCallBackMessage->uMessage.sQueryImageResponsePayload.u8Status);
        if (psCallBackMessage->uMessage.sQueryImageResponsePayload.u8Status != E_ZCL_SUCCESS) 
        {
            DBG_vPrintf(TRACE_APP_OTA,"Query Status 0x%02x\n", psCallBackMessage->uMessage.sQueryImageResponsePayload.u8Status);

            
            eImageQueryStatus = QUERY_RSP_RECEIVED_ERR;
            DBG_vPrintf(TRACE_APP_OTA,"Should be in  In OTA_QUERYIMAGE_WAIT = %d - QUERY_RSP_RECEIVED_ERR\n ",OTA_State);
            
        } 
        else 
        {

            DBG_vPrintf(TRACE_APP_OTA,"QNI R Image Size 0x%08x\n", psCallBackMessage->uMessage.sQueryImageResponsePayload.u32ImageSize);
            DBG_vPrintf(TRACE_APP_OTA,"QNI R File Ver  0x%08x \n", psCallBackMessage->uMessage.sQueryImageResponsePayload.u32FileVersion);
            DBG_vPrintf(TRACE_APP_OTA,"QNI R Manufacture Code 0x%04x  \n", psCallBackMessage->uMessage.sQueryImageResponsePayload.u16ManufacturerCode);
            DBG_vPrintf(TRACE_APP_OTA,"QNI R Image Type 0x%04x\n\n\n", psCallBackMessage->uMessage.sQueryImageResponsePayload.u16ImageType);

            /* Save the credentials from the QNI response
             * These can be compared later once the image header is received
             * the app will be notified by a Verify Header event callback
             *
             */
            u16ExpectedManuf = psCallBackMessage->uMessage.sQueryImageResponsePayload.u16ManufacturerCode;
            u16ExpectedFileType = psCallBackMessage->uMessage.sQueryImageResponsePayload.u16ImageType;
            u32ExpectedVersion = psCallBackMessage->uMessage.sQueryImageResponsePayload.u32FileVersion;
        }
    }

    if(psCallBackMessage->eEventId == E_CLD_OTA_INTERNAL_COMMAND_VERIFY_IMAGE_VERSION )
    {
        DBG_vPrintf(TRACE_APP_OTA|TRACE_OTA_LNT,"\n\n\nVerify the version \n");
        DBG_vPrintf(TRACE_APP_OTA,"Current Ver = 0x%08x\n",psCallBackMessage->uMessage.sImageVersionVerify.u32CurrentImageVersion );
        DBG_vPrintf(TRACE_APP_OTA,"Notified Ver = 0x%08x\n",psCallBackMessage->uMessage.sImageVersionVerify.u32NotifiedImageVersion);


/* Enables the OTA to re install same image, if enabled the
 *  server must have a mechanism to prevent the device constantly downloading */
#ifndef OTA_ENABLE_IMAGE_RE_INSTALL
        if (psCallBackMessage->uMessage.sImageVersionVerify.u32CurrentImageVersion ==
            psCallBackMessage->uMessage.sImageVersionVerify.u32NotifiedImageVersion )
        {
            DBG_vPrintf(TRACE_APP_OTA|TRACE_OTA_LNT,"\n\n\nVerify restore ota discovery \n");
            psCallBackMessage->uMessage.sImageVersionVerify.eImageVersionVerifyStatus = E_ZCL_FAIL;
            u32TimeOut = 0;
            OTA_State = OTA_RE_QUERYIMAGE;

        }
        else

#endif
        {
            eImageQueryStatus = QUERY_RSP_RECEIVED_OK;
            bKeyVerified = FALSE;
            DBG_vPrintf(TRACE_APP_OTA,"Should be in In OTA_QUERYIMAGE_WAIT = %d - QUERY_RSP_RECEIVED_OK\n ",OTA_State);
        }
    }

#ifdef OTA_STRING_COMPARE
    if(psCallBackMessage->eEventId == E_CLD_OTA_INTERNAL_COMMAND_VERIFY_STRING )
    {
        int i=0;
        DBG_vPrintf(TRACE_APP_OTA,"Status = %d\n",psCallBackMessage->uMessage.sImageIdentification.eStatus);

        DBG_vPrintf(TRACE_APP_OTA,"Current Header String:\n");
        for(i=0;i<32;i++)
            DBG_vPrintf(TRACE_APP_OTA,"%02x ",*(psCallBackMessage->uMessage.sImageIdentification.pu8Current +i));

        DBG_vPrintf(TRACE_APP_OTA,"\nNotified Header String: \n");
        for(i=0;i<32;i++)
            DBG_vPrintf(TRACE_APP_OTA,"%02x ",*(psCallBackMessage->uMessage.sImageIdentification.puNotified +i));

           if(psCallBackMessage->uMessage.sImageIdentification.eStatus == E_ZCL_FAIL)
           {
                DBG_vPrintf(TRACE_APP_OTA, "Mismatch\n\n\n");
                OTA_State = OTA_FIND_SERVER;
                vRestetOTADiscovery();
                DBG_vPrintf(TRACE_OTA_LNT, "CLEAR OUT SERVER #2\n");
        }

    }
#endif


    if(psCallBackMessage->eEventId == E_CLD_OTA_COMMAND_UPGRADE_END_RESPONSE )
    {
        DBG_vPrintf(TRACE_APP_OTA|TRACE_OTA_LNT,"\n\n\nUpgrade End Response \n");
        DBG_vPrintf(TRACE_APP_OTA,"Upgrade Time : 0x%08x\n",psCallBackMessage->uMessage.sUpgradeResponsePayload.u32UpgradeTime);
        DBG_vPrintf(TRACE_APP_OTA,"Current Time : 0x%08x\n",psCallBackMessage->uMessage.sUpgradeResponsePayload.u32CurrentTime);
        DBG_vPrintf(TRACE_APP_OTA,"File Version : 0x%08x\n",psCallBackMessage->uMessage.sUpgradeResponsePayload.u32FileVersion);
        DBG_vPrintf(TRACE_APP_OTA,"Image Type   : 0x%04x\n",psCallBackMessage->uMessage.sUpgradeResponsePayload.u16ImageType);
        DBG_vPrintf(TRACE_APP_OTA,"Manufacturer : 0x%04x\n",psCallBackMessage->uMessage.sUpgradeResponsePayload.u16ManufacturerCode);

        if(0xFFFFFFFF != psCallBackMessage->uMessage.sUpgradeResponsePayload.u32UpgradeTime )
        {
            if(psCallBackMessage->uMessage.sUpgradeResponsePayload.u32UpgradeTime > psCallBackMessage->uMessage.sUpgradeResponsePayload.u32CurrentTime)
            {
                psCallBackMessage->uMessage.sUpgradeResponsePayload.u32UpgradeTime -= psCallBackMessage->uMessage.sUpgradeResponsePayload.u32CurrentTime;
            }
            else
            {
                /* If upgrade time is in past , upgrade in one second*/
                psCallBackMessage->uMessage.sUpgradeResponsePayload.u32UpgradeTime = 1;
            }
            psCallBackMessage->uMessage.sUpgradeResponsePayload.u32CurrentTime = 0;
        }
    }

    if(psCallBackMessage->eEventId == E_CLD_OTA_INTERNAL_COMMAND_SAVE_CONTEXT )
    {
        DBG_vPrintf(TRACE_APP_OTA|TRACE_OTA_LNT,"\nSave Context\n");
        vOTAPersist();
    }
    if(psCallBackMessage->eEventId == E_CLD_OTA_INTERNAL_COMMAND_SWITCH_TO_UPGRADE_DOWNGRADE )
    {
        DBG_vPrintf(TRACE_APP_OTA|TRACE_OTA_LNT,"\nSwitching to New Image\n");
    }
    if(psCallBackMessage->eEventId ==  E_CLD_OTA_INTERNAL_COMMAND_OTA_DL_ABORTED)
    {
        DBG_vPrintf(TRACE_APP_OTA|TRACE_OTA_LNT,"DL complete INvalid Image\n\n");
    }
    if(psCallBackMessage->eEventId ==  E_CLD_OTA_INTERNAL_COMMAND_RESET_TO_UPGRADE)
    {
        DBG_vPrintf(TRACE_APP_OTA|TRACE_OTA_LNT,"E_CLD_OTA_INTERNAL_COMMAND_RESET_TO_UPGRADE\n\n");
    }
    if(psCallBackMessage->eEventId ==  E_CLD_OTA_COMMAND_UPGRADE_END_RESPONSE)
    {
        DBG_vPrintf(TRACE_APP_OTA,"E_CLD_OTA_COMMAND_UPGRADE_END_RESPONSE\n\n");
    }
    if(psCallBackMessage->eEventId == E_CLD_OTA_COMMAND_BLOCK_RESPONSE)
    {
        DBG_vPrintf(TRACE_OTA_LNT,"Block Resp Status = %02x file offset %08x\n",
                psCallBackMessage->uMessage.sImageBlockResponsePayload.u8Status,
                psCallBackMessage->uMessage.sImageBlockResponsePayload.uMessage.sBlockPayloadSuccess.u32FileOffset);
        if(psCallBackMessage->uMessage.sImageBlockResponsePayload.u8Status == OTA_STATUS_SUCCESS)
        {
            psCallBackMessage->uMessage.sImageBlockResponsePayload.u8Status = u8VerifyLinkKey(psCallBackMessage);
            if(OTA_STATUS_ABORT == psCallBackMessage->uMessage.sImageBlockResponsePayload.u8Status)
            {
                /* Send an Abort from Application, the ZCL is not doing it.*/
                tsOTA_UpgradeEndRequestPayload sUpgradeEndRequestPayload;

                sUpgradeEndRequestPayload.u32FileVersion = psCallBackMessage->uMessage.sImageBlockResponsePayload.uMessage.sBlockPayloadSuccess.u32FileVersion;
                sUpgradeEndRequestPayload.u16ImageType = psCallBackMessage->uMessage.sImageBlockResponsePayload.uMessage.sBlockPayloadSuccess.u16ImageType;
                sUpgradeEndRequestPayload.u16ManufacturerCode = psCallBackMessage->uMessage.sImageBlockResponsePayload.uMessage.sBlockPayloadSuccess.u16ManufacturerCode;
                sUpgradeEndRequestPayload.u8Status = psCallBackMessage->uMessage.sImageBlockResponsePayload.u8Status;

                #if OTA_ACKS_ON == TRUE
                    sZCL_Address.eAddressMode = E_ZCL_AM_SHORT;
                #else
                    sZCL_Address.eAddressMode = E_ZCL_AM_SHORT_NO_ACK;
                #endif
                sZCL_Address.uAddress.u16DestinationAddress = psCallBackMessage->sPersistedData.u16ServerShortAddress;


                eOTA_ClientUpgradeEndRequest(
                         OTA_CLIENT_EP,
                         psCallBackMessage->sPersistedData.u8DstEndpoint,
                         &sZCL_Address,
                         &sUpgradeEndRequestPayload);
            }
        } 
        else 
        { 
            DBG_vPrintf(TRACE_OTA_LNT, "BLK RSP Error WAIT DATA ?\n"); 
        }
        #ifdef DEEP_SLEEP_ENABLE
            vLoadDeepSleepTimer(DEEP_SLEEP_TIME);
        #endif
    }
    if(psCallBackMessage->eEventId ==  E_CLD_OTA_INTERNAL_COMMAND_OTA_DL_ABORTED)
    {
        DBG_vPrintf(TRACE_APP_OTA|TRACE_OTA_LNT,"E_CLD_OTA_INTERNAL_COMMAND_OTA_DL_ABORTED\n\n");
    }
    u32TimeOut = 0;
}

/****************************************************************************
 *
 * NAME: vDumpFlashData
 *
 * DESCRIPTION:
 * Dumps the OTA downloaded data on debug terminal at a chunk of 16 bytes
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vDumpFlashData(uint32 u32FlashByteLocation, uint32 u32EndLocation)
{
    uint8 au8Data[16];

    for (;u32FlashByteLocation<=u32EndLocation;u32FlashByteLocation +=16 )
    {
        bAHI_FullFlashRead(u32FlashByteLocation,16,au8Data);

        uint8 u8Len;
        DBG_vPrintf(TRACE_APP_OTA,"0x%08x : ",u32FlashByteLocation);
        for (u8Len=0;u8Len<16;u8Len++)
        {
            DBG_vPrintf(TRACE_APP_OTA,"%02x ",au8Data[u8Len]);
        }
        DBG_vPrintf(TRACE_APP_OTA,"\n");

        volatile uint32 u32Delay=10000;
        for(u32Delay=10000;u32Delay>0;u32Delay--);

        vAHI_WatchdogRestart();
    }
}
/****************************************************************************
 *
 * NAME: vIncrementTimeOut
 *
 * DESCRIPTION:
 * Increment Timeout value by the u8TimeInSec to compensate for any sleep
 *
 * PARAMETERS:
 * uint8 u8TimeInSec Time in seconds to be incremented
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vIncrementTimeOut(uint8 u8TimeInSec)
{
    if(u32OTAQueryTimeinSec != 0)
    {
        u32OTAQueryTimeinSec += u8TimeInSec;
    }
    if(u32TimeOut != 0)
    {
        u32TimeOut += u8TimeInSec;
    }
}
/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/
#ifdef CHECK_VBO_FOR_OTA_ACTIVITY
/****************************************************************************
 *
 * NAME: vSetNextBOEvent
 *
 * DESCRIPTION:
 * Sets the voltage and rising/falling event to occur
 *
 * PARAMETERS:
 * eBOTripVoltage       Trip Voltage
 * u32Mask              Rising or falling mask
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vSetNextBOEvent(teBrownOutTripVoltage eBOTripVoltage,uint32 u32Mask)
{
    /* Set trip voltage to indicate start activity, enable SVM & disable reset on BO */
    *(uint32 *)SYSCON_VBOCTRL_ADDR =  eBOTripVoltage|1;

    /*Set the falling edge and reset the rising edge */
    *(uint32 *)SYSCON_SYS_IM_ADDR |= u32Mask;
}

/****************************************************************************
 *
 * NAME: vOTAActivity
 *
 * DESCRIPTION:
 * Manipulates the block request time to based on the voltage
 *
 * PARAMETERS:
 * teBrownOutTripVoltage Brown out voltage enumeration values
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vOTAActivity(teOTAActivity eOTAStartStop)
{
    s_eOTAStartStop = eOTAStartStop;
    tsOTA_PersistedData * psOTAPersistedData = psGetOTACallBackPersistdata();

    if(psOTAPersistedData->sAttributes.u8ImageUpgradeStatus != E_CLD_OTA_STATUS_NORMAL)
    {
        switch(eOTAStartStop)
        {
            case APP_E_OTA_STOP:
                vOTA_SetLowVoltageFlag(TRUE);
                DBG_vPrintf(TRACE_APP_OTA|TRACE_OTA_LNT,"Stopped OTA Block Request by Setting time to 0x%08x \n",psOTAPersistedData->u32RequestBlockRequestTime);
                break;
            case APP_E_OTA_START:
                vOTA_SetLowVoltageFlag(FALSE);
                DBG_vPrintf(TRACE_APP_OTA|TRACE_OTA_LNT,"Resumed OTA Block Request by Setting time to 0x%08x \n",psOTAPersistedData->u32RequestBlockRequestTime);
                break;
            default :
                break;
        }
    }
}
/****************************************************************************
 *
 * NAME: eGetOTAActivity
 *
 * DESCRIPTION:
 * Gets the activity of OTA
 *
 * PARAMETERS:
 * void
 *
 * RETURNS:
 * OTA to start or to stop
 *
 ****************************************************************************/
PRIVATE teOTAActivity eGetOTAActivity(void)
{
    return s_eOTAStartStop;
}
#endif
/****************************************************************************
 *
 * NAME: u8VerifyLinkKey
 *
 * DESCRIPTION:
 * Verifies link key once first 1K data is downloaded and saved in flash
 *
 * RETURNS:
 * staus of the verification
 *
 ****************************************************************************/
PRIVATE uint8 u8VerifyLinkKey(tsOTA_CallBackMessage *psCallBackMessage)
{



    /*Assumption : First 1 K downloaded and saved to external flash*/
    if(
            (bKeyVerified == FALSE) &&
            (psCallBackMessage->uMessage.sImageBlockResponsePayload.uMessage.sBlockPayloadSuccess.u32FileOffset > APP_OTA_OFFSET_WRITEN_BEFORE_LINKKEY_VERIFICATION )
       )
    {
        bKeyVerified = TRUE;

        volatile int i;
        uint8 au8DownloadedLnkKey[0x10];
        uint8 au8Key[0x10];

        uint32 u32LnkKeyLocation = (uint32)(&(_FlsLinkKey)) - (uint32)(&(_flash_start));
#ifdef OTA_INTERNAL_STORAGE
        u32LnkKeyLocation += psCallBackMessage->u8ImageStartSector[0] * sNvmDefsStruct.u32SectorSize;
#endif
        DBG_vPrintf(TRACE_APP_OTA,"Link Key Offset in External Flash = 0x%08x\n",u32LnkKeyLocation);
        bAHI_FullFlashRead(u32LnkKeyLocation,0x10,au8DownloadedLnkKey);

        /*Get a copy of the Lnk Key*/
        for(i=0;i<16;i++)
        {
            au8Key[i] = s_au8LnkKeyArray[i];
        }

#ifndef OTA_INTERNAL_STORAGE
        extern uint32 _enc_start;
        /* for internal storage of the image the key will never be encrypted
         * as the downloaded image is decrypted before placing it in the internal flash
         */
        uint32 u32CustomerSettings = *((uint32*)FL_INDEX_SECTOR_CUSTOMER_SETTINGS);
        bool_t bEncExternalFlash = (u32CustomerSettings & FL_INDEX_SECTOR_ENC_EXT_FLASH)?FALSE:TRUE;

        if(bEncExternalFlash)
        {
            uint8 au8Iv[0x10];
            uint8 au8DataOut[0x10];

            uint32 u32IVLocation = 0x10;
            tsReg128 sKey;

            /*Get the downloaded IV from Ext Flash */
            bAHI_FullFlashRead(u32IVLocation,0x10,au8Iv);
            DBG_vPrintf(TRACE_APP_OTA,"The Plain IV :\n");

            for (i=0;i<0x10;i++)
                DBG_vPrintf(TRACE_APP_OTA,"au8Iv[%d]: 0x%02x\n",i,au8Iv[i]);

            DBG_vPrintf(TRACE_APP_OTA,"The Enc Offset Address = 0x%08x\n",((uint32)(&(_enc_start))));
            uint32 u32LnkKeyFromEncStart=  ((uint32)(&(_FlsLinkKey)) -((uint32)(&(_enc_start))));
            DBG_vPrintf(TRACE_APP_OTA,"The The Total Bytes between Enc Offset and LnkKey = 0x%08x\n", u32LnkKeyFromEncStart );
            uint8 u8IVIncrement = (uint8)(u32LnkKeyFromEncStart>>4);
            DBG_vPrintf(TRACE_APP_OTA,"The IV should be increased by = 0x%08x\n", u8IVIncrement);

            /*Increase IV*/
            au8Iv[15] = au8Iv[15]+u8IVIncrement;

            /*Get the EFUSE keys*/
            uint32 *pu32KeyPtr = (uint32*)FL_INDEX_SECTOR_ENC_KEY_ADDRESS;

            sKey.u32register0 = *pu32KeyPtr;
            sKey.u32register1 = *(pu32KeyPtr+1);
            sKey.u32register2 = *(pu32KeyPtr+2);
            sKey.u32register3 = *(pu32KeyPtr+3);

            DBG_vPrintf(TRACE_APP_OTA,"The Key is :\n");
            DBG_vPrintf(TRACE_APP_OTA,"sKey.u32register0: 0x%08x\n",sKey.u32register0);
            DBG_vPrintf(TRACE_APP_OTA,"sKey.u32register1: 0x%08x\n",sKey.u32register1);
            DBG_vPrintf(TRACE_APP_OTA,"sKey.u32register2: 0x%08x\n",sKey.u32register2);
            DBG_vPrintf(TRACE_APP_OTA,"sKey.u32register3: 0x%08x\n",sKey.u32register3);

            /*Encrypt the IV*/
            vOTA_EncodeString(&sKey,au8Iv,au8DataOut);

            /* Encrypt the Internal Key */
            for(i=0;i<16;i++)
            {
                au8Key[i] = au8Key[i] ^ au8DataOut[i];
            }
        }
#endif

        /*Comparing the Keys*/
        for(i=0;i<0x10;i++)
        {
            DBG_vPrintf(TRACE_APP_OTA,"Internal Key[%d] = %02x Downloaded Key[%d] = 0x%02x \n",i,au8Key[i],i,au8DownloadedLnkKey[i]);

            /*Compare to see if they match else its an invalid image*/
            if(au8Key[i]!=au8DownloadedLnkKey[i])
            {
                DBG_vPrintf(TRACE_APP_OTA,"Key Mismatch, Abort DownLoad\n");
                bKeyVerified=FALSE;
                return OTA_STATUS_ABORT;
            }
        }

        #ifdef OTA_CLIENT_ABORT_TH
            /*First Link key check will fail  if the TH is defined to test Client initiated Aborts.*/
            volatile static bool_t bClientAbort = TRUE;

            if(TRUE == bClientAbort)
            {
                bClientAbort = FALSE;
                return OTA_STATUS_ABORT;
            }
        #endif
    }



    return OTA_STATUS_SUCCESS;
}


/****************************************************************************
 *
 * NAME: vInitAndDisplayKeys
 *
 * DESCRIPTION:
 * Initialize Keys and displays the content
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vInitAndDisplayKeys(void)
{

    #ifndef JENNIC_CHIP_FAMILY_JN514x
        uint8 u8Index;
        for(u8Index=0;u8Index<8;u8Index++)
            au8MacAddressVolatile[u8Index]=au8MacAddress[u8Index];
    #endif

    #if TRACE_APP_OTA==TRUE
        uint8 i;
        DBG_vPrintf(TRACE_APP_OTA, "MAC Address at address = %08x\n\n\n",au8MacAddress);
        for (i =0;i<8;i++)
        {
            DBG_vPrintf(TRACE_APP_OTA, "%02x ",au8MacAddress[i] );
        }

        DBG_vPrintf(TRACE_APP_OTA, "\n\n\n Link Key ");
        for (i =0;i<16;i++)
        {
            DBG_vPrintf(TRACE_APP_OTA, "%02x ",s_au8LnkKeyArray[i] );
        }
        DBG_vPrintf(TRACE_APP_OTA, "\n\n\n");
    #endif
}

/****************************************************************************
 *
 * NAME: vCheckForOTAMatch
 *
 * DESCRIPTION:
 * Checks for the OTA cluster match during OTA server discovery, if a match
 * found it will make an entry in the local discovery table.This table will be
 * used to query image requests by the client.
 *
 *
 * INPUT:
 *
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vCheckForOTAMatch( ZPS_tsAfEvent  * psStackEvent)
{
    ZPS_tsAfZdpEvent sAfZdpEvent;
    zps_bAplZdpUnpackResponse(psStackEvent, &sAfZdpEvent);

    if (APP_MATCH_DESCRIPTOR_RESPONSE == sAfZdpEvent.u16ClusterId)
    {
        DBG_vPrintf(TRACE_OTA_LNT, "MATCH RSP St %02x\n", sAfZdpEvent.uZdpData.sMatchDescRsp.u8Status);
        if(
                (!sAfZdpEvent.uZdpData.sMatchDescRsp.u8Status) &&
                (ZPS_u16AplZdoGetNwkAddr() != sAfZdpEvent.uZdpData.sMatchDescRsp.u16NwkAddrOfInterest ) &&
                (u8Discovered < MAX_SERVER_NODES )
           )
        {
            uint8 i;
            sDiscovedOTAServers[u8Discovered].u16NwkAddrOfServer= sAfZdpEvent.uZdpData.sMatchDescRsp.u16NwkAddrOfInterest;
            DBG_vPrintf(TRACE_APP_OTA,"\n\nNwk Address oF server = %04x\n",sDiscovedOTAServers[u8Discovered].u16NwkAddrOfServer);

            sDiscovedOTAServers[u8Discovered].u8MatchLength = sAfZdpEvent.uZdpData.sMatchDescRsp.u8MatchLength;
            DBG_vPrintf(TRACE_APP_OTA,"Number of OTA Server EPs = %d\n",sDiscovedOTAServers[u8Discovered].u8MatchLength);

            for( i=0; i<sDiscovedOTAServers[u8Discovered].u8MatchLength && i<MAX_SERVER_EPs ;i++)
            {
                sDiscovedOTAServers[u8Discovered].u8MatchList[i] = sAfZdpEvent.uLists.au8Data[i];
                DBG_vPrintf(TRACE_APP_OTA,"OTA Server EP# = %d\n",sDiscovedOTAServers[u8Discovered].u8MatchList[i]);
            }

            u8Discovered++;
        }
    }
}
/****************************************************************************
 *
 * NAME: vCheckForOTAServerIeeeAddress
 *
 * DESCRIPTION:
 * Handles IEEE address look up query query
 * Makes an entry in the application OTA discovery table. Later this is used
 * for by the OTA requests.
 *
 * This function is called from the application OTA handler with stack event
 * as input.
 *
 *
 * INPUT:
 * ZPS_tsAfEvent  * psStackEvent   Pointer to the stack event
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vCheckForOTAServerIeeeAddress( ZPS_tsAfEvent  * psStackEvent)
{
    ZPS_tsAfZdpEvent sAfZdpEvent;
    zps_bAplZdpUnpackResponse(psStackEvent, &sAfZdpEvent); 
    if (APP_IEEE_ADDR_RESPONSE == sAfZdpEvent.u16ClusterId)
    {
        DBG_vPrintf(TRACE_OTA_LNT, "IEE RSP St %02x\n", sAfZdpEvent.uZdpData.sIeeeAddrRsp.u8Status);
        if(!sAfZdpEvent.uZdpData.sIeeeAddrRsp.u8Status)
        {
            uint8 i;
            for( i=0; i<u8Discovered ;i++)
            {
                if( sDiscovedOTAServers[i].u16NwkAddrOfServer ==
                        sAfZdpEvent.uZdpData.sIeeeAddrRsp.u16NwkAddrRemoteDev)
                {
                    /*Make an entry in the OTA server tables*/
                    sDiscovedOTAServers[i].u64IeeeAddrOfServer = sAfZdpEvent.uZdpData.sIeeeAddrRsp.u64IeeeAddrRemoteDev;
                    DBG_vPrintf(TRACE_APP_OTA,"Entry Added NWK Addr 0x%04x IEEE Addr 0x%016x",
                            sDiscovedOTAServers[i].u16NwkAddrOfServer,sDiscovedOTAServers[i].u64IeeeAddrOfServer);
                    ZPS_eAplZdoAddAddrMapEntry( sDiscovedOTAServers[i].u16NwkAddrOfServer,sDiscovedOTAServers[i].u64IeeeAddrOfServer,FALSE);

                    sDiscovedOTAServers[i].bValid = TRUE;
                    DBG_vPrintf(TRACE_OTA_LNT, "SERVER DISCOVERED\n");
                }
            }
        }
    }
}
/****************************************************************************
 *
 * NAME: vGetIEEEAddress
 *
 * DESCRIPTION:
 * Finds an IEEE address on the local node by calling Stack API, if no entries
 * found it request the IEEE look up on air.
 *
 *
 * INPUT:
 * uint8 u8Index   Index to the discovery table point to the NWK address of
 *                 the discovered server
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vGetIEEEAddress(uint8 u8Index)
{
    /* Always query for address Over the air - Uncomment if required for local look up first*/
    #ifdef LOCAL_ADDRESS_LOOK_UP
    /* See if there is a local address map exists  */
    uint64 u64IeeeAdress = ZPS_u64AplZdoLookupIeeeAddr(sDiscovedOTAServers[u8Index].u16NwkAddrOfServer);
    if( u64IeeeAdress != 0x0000000000000000 || u64IeeeAdress != 0xFFFFFFFFFFFFFFFF )
    {
        /*Valid address found, setting up the OTA server address */
        sDiscovedOTAServers[u8Index].u64IeeeAddrOfServer = u64IeeeAdress;
    }
    else
    #endif
    {
        /* If there is no address map existing, then do a look up */
        PDUM_thAPduInstance hAPduInst;
        hAPduInst = PDUM_hAPduAllocateAPduInstance(apduZDP);

        if (hAPduInst == PDUM_INVALID_HANDLE)
        {
            DBG_vPrintf(TRACE_APP_OTA|TRACE_OTA_LNT, "IEEE Address Request - PDUM_INVALID_HANDLE\n");
        }
        else
        {
            ZPS_tuAddress uDstAddr;
            bool bExtAddr;
            uint8 u8SeqNumber;
            ZPS_teStatus eStatus;
            ZPS_tsAplZdpIeeeAddrReq sZdpIeeeAddrReq;

            uDstAddr.u16Addr = sDiscovedOTAServers[u8Index].u16NwkAddrOfServer;
            bExtAddr = FALSE;
            sZdpIeeeAddrReq.u16NwkAddrOfInterest=sDiscovedOTAServers[u8Index].u16NwkAddrOfServer;
            sZdpIeeeAddrReq.u8RequestType =0;
            sZdpIeeeAddrReq.u8StartIndex =0;
            DBG_vPrintf(TRACE_APP_OTA, "Send IEEE Address Request : 0x%04x\n", sZdpIeeeAddrReq.u16NwkAddrOfInterest);
            eStatus= ZPS_eAplZdpIeeeAddrRequest(
                                            hAPduInst,
                                            uDstAddr,
                                            bExtAddr,
                                            &u8SeqNumber,
                                            &sZdpIeeeAddrReq);
            if (eStatus)
            {
                PDUM_eAPduFreeAPduInstance(hAPduInst);
                DBG_vPrintf(TRACE_APP_OTA|TRACE_OTA_LNT, "Address Request failed: 0x%02x\n", eStatus);
            } 
            else 
            { 
                DBG_vPrintf(TRACE_OTA_LNT, "SENT IEEE REQ for %04x\n", sDiscovedOTAServers[u8Index].u16NwkAddrOfServer);
            }
        }
    }
}
/****************************************************************************
 *
 * NAME: bMatchRecieved
 *
 * DESCRIPTION:
 * Validation function for the match and sets the valid field true in the
 * discovery table if there is valid OTA Server found in the network
 *
 *
 * INPUT:
 *
 * RETURNS:
 * TRUE/FALSE
 *
 ****************************************************************************/
PRIVATE bool_t bMatchRecieved(void)
{
    uint8 i;

    for (i =0; i < u8Discovered;i++)
    {
        if(sDiscovedOTAServers[i].bValid)
            return TRUE;
    }
    return FALSE;
}
/****************************************************************************
 *
 * NAME: eClientQueryNextImageRequest
 *
 * DESCRIPTION:
 * Query nest image request application wrapper.
 *
 *
 * INPUT:
 *  uint8 u8SourceEndpoint
 *  uint8 u8DestinationEndpoint,
 *  uint16 u16DestinationAddress,
 *  uint32 u32FileVersion,
 *  uint16 u16HardwareVersion,
 *  uint16 u16ImageType,
 *  uint16 u16ManufacturerCode,
 *  uint8 u8FieldControl
 *
 * RETURNS:
 * ZCL status of the call
 *
 ****************************************************************************/
PRIVATE teZCL_Status eClientQueryNextImageRequest(
                    uint8 u8SourceEndpoint,
                    uint8 u8DestinationEndpoint,
                    uint16 u16DestinationAddress,
                    uint32 u32FileVersion,
                    uint16 u16HardwareVersion,
                    uint16 u16ImageType,
                    uint16 u16ManufacturerCode,
                    uint8 u8FieldControl)
{
    tsZCL_Address sAddress;
    sAddress.eAddressMode = E_ZCL_AM_SHORT_NO_ACK;
    sAddress.uAddress.u16DestinationAddress = u16DestinationAddress;

    tsOTA_QueryImageRequest sRequest;
    sRequest.u32CurrentFileVersion = u32FileVersion;
    sRequest.u16HardwareVersion = u16HardwareVersion;
    sRequest.u16ImageType = u16ImageType;
    sRequest.u16ManufacturerCode = u16ManufacturerCode;
    sRequest.u8FieldControl = u8FieldControl;

    DBG_vPrintf(TRACE_APP_OTA,"Sending Image Query to Address 0x%04x\n",sAddress.uAddress.u16DestinationAddress);
    teZCL_Status eStatus;
    eStatus = eOTA_ClientQueryNextImageRequest(
            u8SourceEndpoint,
            u8DestinationEndpoint,
            &sAddress,
            &sRequest);
    DBG_vPrintf(TRACE_APP_OTA|TRACE_OTA_LNT,"eOTA_ClientQueryNextImageRequest Status = %d \n\n",eStatus);
    return eStatus;
}
/****************************************************************************
 *
 * NAME: eSendOTAMatchDescriptor
 *
 * DESCRIPTION:
 * Sends the OTA match descriptor for OTA server discovery as a broadcast.
 *
 *
 * INPUT:
 *  uint16 u16ProfileId Profile Identifier
 *
 * RETURNS:
 * ZPS status of the call
 *
 ****************************************************************************/
PRIVATE ZPS_teStatus eSendOTAMatchDescriptor(uint16 u16ProfileId)
{
    uint16 au16InClusters[]={OTA_CLUSTER_ID};
    uint8 u8TransactionSequenceNumber;
    ZPS_tuAddress uDestinationAddress;
    ZPS_tsAplZdpMatchDescReq sMatch;

    sMatch.u16ProfileId = u16ProfileId;
    sMatch.u8NumInClusters=sizeof(au16InClusters)/sizeof(uint16);
    sMatch.pu16InClusterList=au16InClusters;
    sMatch.pu16OutClusterList=NULL;
    sMatch.u8NumOutClusters=0;
    sMatch.u16NwkAddrOfInterest=0xFFFD;

    uDestinationAddress.u16Addr = 0xFFFD;

    PDUM_thAPduInstance hAPduInst = PDUM_hAPduAllocateAPduInstance(apduZDP);

    if (hAPduInst == PDUM_INVALID_HANDLE)
    {
        DBG_vPrintf(TRACE_APP_OTA, "Allocate PDU ERR:\n");
        return (ZPS_teStatus)PDUM_E_INVALID_HANDLE;
    }

    ZPS_teStatus eStatus = ZPS_eAplZdpMatchDescRequest(
                            hAPduInst,
                            uDestinationAddress,
                            FALSE,
                            &u8TransactionSequenceNumber,
                            &sMatch);

    if (eStatus)
    {
        PDUM_eAPduFreeAPduInstance(hAPduInst);
        DBG_vPrintf(TRACE_APP_OTA|TRACE_OTA_LNT, "Match ERR: 0x%x", eStatus);
    } 
    else 
    { 
        DBG_vPrintf(TRACE_OTA_LNT, "SENT MATCH DESC\n");
    }

    return eStatus;
}
/****************************************************************************
 *
 * NAME: vManagaeOTAState
 *
 * DESCRIPTION:
 * Simple State Machine to move the OTA state from Discovery to Download.
 * It also implements a simple mechanism of time out.
 *
 * INPUT:
 * uint32 u32OTAQueryTime
 *
 * RETURNS:
 *
 *
 ****************************************************************************/
PRIVATE void vManagaeOTAState(void)
{
#if TRACE_OTA_LNT
    if ( (u32OTAQueryTimeinSec % 10) == 0) {
        DBG_vPrintf(TRACE_OTA_LNT, "OTA state %d tick %d\n", OTA_State, u32OTAQueryTimeinSec);
    }
#endif
    switch(OTA_State)
    {
        case OTA_FIND_SERVER:
        {
            DBG_vPrintf(TRACE_APP_OTA,"In OTA_FIND_SERVER\n ");

            if(u32OTAQueryTimeinSec > OTA_QUERY_TIME_IN_SEC )
            {
                u8NodeIndex=0;
                u8EpIndex=0;
                u32OTAQueryTimeinSec=0;
                ZPS_teStatus eStatus;
                eStatus = eSendOTAMatchDescriptor(HA_PROFILE_ID);
                if ( eStatus)
                {
                    u32TimeOut=0;
                    OTA_State = OTA_FIND_SERVER;
                    vRestetOTADiscovery();
                    DBG_vPrintf(TRACE_APP_OTA|TRACE_OTA_LNT, "Send Match Error 0x%02x\n",eStatus);
                    DBG_vPrintf(TRACE_OTA_LNT, "CLEAR OUT SERVER #3\n");
                }
                else
                {
                    /*Wait for the discovery to complete */
                    u32TimeOut=0;
                    OTA_State = OTA_FIND_SERVER_WAIT;
                }
            }
        }
        break;

        case OTA_FIND_SERVER_WAIT:
        {
            DBG_vPrintf(TRACE_APP_OTA,"In OTA_FIND_SERVER_WAIT\n ");
            u32TimeOut++;
            if(u32TimeOut > OTA_DISCOVERY_TIMEOUT_IN_SEC )
            {
                u32TimeOut=0;
                if( u8Discovered > u8NodeIndex )
                {
                    u8NodeIndex=0;
                    u8EpIndex=0;
                    
                    OTA_State = OTA_GET_IEEE_ADDRESS_OF_SERVER;
                }
                else
                {
                    OTA_State = OTA_FIND_SERVER;
                    vRestetOTADiscovery();
                    DBG_vPrintf(TRACE_OTA_LNT, "CLEAR OUT SERVER #4\n");
                }
            }
        }
        break;

        case OTA_GET_IEEE_ADDRESS_OF_SERVER:
        {
            DBG_vPrintf(TRACE_APP_OTA,"In OTA_GET_IEEE_ADDRESS_OF_SERVER\n ");
            u32TimeOut++;
            if(u32TimeOut > OTA_IEEE_ADDRESS_RESP_TIMEOUT_PER_REQUEST)
            {
                u32TimeOut=0;
                if(u8Discovered > u8NodeIndex)
                {
                    /* The following is un-condintional increment
                     * to make sure even if there is no response received it just comes out */
                    vGetIEEEAddress(u8NodeIndex);
                    u8NodeIndex++;
                }
                else if( bMatchRecieved() )
                {
                    u8NodeIndex=0;
                    u8EpIndex=0;
                    OTA_State = OTA_QUERYIMAGE;
                }
                else
                {
                    OTA_State = OTA_FIND_SERVER;
                    vRestetOTADiscovery();
                    DBG_vPrintf(TRACE_OTA_LNT, "CLEAR OUT SERVER #4.1\n");
                }
            }
        }
        break;
        case OTA_RE_QUERYIMAGE:
        {
            DBG_vPrintf(TRACE_APP_OTA,"In OTA_RE_QUERYIMAGE\n ");
            u32TimeOut++;
            if(u32TimeOut > OTA_OTA_RE_QUERYIMAGE_TIME)
            {
                u32TimeOut=0;
                u8NodeIndex=0;
                u8EpIndex=0;
                OTA_State = OTA_QUERYIMAGE;

            }
        }
        break;
        case OTA_QUERYIMAGE:
        {
            DBG_vPrintf(TRACE_APP_OTA,"In OTA_QUERYIMAGE\n ");
            for(; u8NodeIndex < u8Discovered;)
            {
                if(sDiscovedOTAServers[u8NodeIndex].bValid)
                {

                    tsOTA_ImageHeader          sOTAHeader;
                    eOTA_GetCurrentOtaHeader(OTA_CLIENT_EP,FALSE,&sOTAHeader);
                    DBG_vPrintf(TRACE_APP_OTA,"\n\nFile ID = 0x%08x\n",sOTAHeader.u32FileIdentifier);
                    DBG_vPrintf(TRACE_APP_OTA,"Header Ver ID = 0x%04x\n",sOTAHeader.u16HeaderVersion);
                    DBG_vPrintf(TRACE_APP_OTA,"Header Length ID = 0x%04x\n",sOTAHeader.u16HeaderLength);
                    DBG_vPrintf(TRACE_APP_OTA,"Header Control Filed = 0x%04x\n",sOTAHeader.u16HeaderControlField);
                    DBG_vPrintf(TRACE_APP_OTA,"Manufac Code = 0x%04x\n",sOTAHeader.u16ManufacturerCode);
                    DBG_vPrintf(TRACE_APP_OTA,"Image Type = 0x%04x\n",sOTAHeader.u16ImageType);
                    DBG_vPrintf(TRACE_APP_OTA,"File Ver = 0x%08x\n",sOTAHeader.u32FileVersion);
                    DBG_vPrintf(TRACE_APP_OTA,"Stack Ver = 0x%04x\n",sOTAHeader.u16StackVersion);
                    DBG_vPrintf(TRACE_APP_OTA,"Image Len = 0x%08x\n\n",sOTAHeader.u32TotalImage);

                    /*Set server address */
                    eOTA_SetServerAddress(
                                        OTA_CLIENT_EP,
                                        sDiscovedOTAServers[u8NodeIndex].u64IeeeAddrOfServer,
                                        sDiscovedOTAServers[u8NodeIndex].u16NwkAddrOfServer
                                        );

                    for (; u8EpIndex< sDiscovedOTAServers[u8NodeIndex].u8MatchLength;)
                    {
                        eClientQueryNextImageRequest(
                                OTA_CLIENT_EP,
                                sDiscovedOTAServers[u8NodeIndex].u8MatchList[u8EpIndex],
                                sDiscovedOTAServers[u8NodeIndex].u16NwkAddrOfServer,
                                sOTAHeader.u32FileVersion,
                                0,
                                sOTAHeader.u16ImageType,
                                sOTAHeader.u16ManufacturerCode,
                                0
                                );

                        u32TimeOut=0;
                        OTA_State = OTA_QUERYIMAGE_WAIT;

                        eImageQueryStatus=QUERY_SENT;
                        u8EpIndex++;
                        DBG_vPrintf(TRACE_APP_OTA,"In OTA_QUERYIMAGE - QUERY_SENT\n ");
                        return;
                    }
                    /*loop is over reset the index for the next node*/
                    u8EpIndex=0;
                }
                u8NodeIndex++;
            }
            DBG_vPrintf(TRACE_APP_OTA,"In OTA_QUERYIMAGE - QUERY_FINISHED\n ");
            eImageQueryStatus=QUERY_FINISHED;

            u32TimeOut=0;
            OTA_State = OTA_FIND_SERVER;
            vRestetOTADiscovery();
            DBG_vPrintf(TRACE_OTA_LNT, "CLEAR OUT SERVER #5\n");
        }
        break;
        case OTA_QUERYIMAGE_WAIT:
        {
            DBG_vPrintf(TRACE_APP_OTA|TRACE_OTA_LNT,"In OTA_QUERYIMAGE_WAIT\n ");
            u32TimeOut++;
             if(eImageQueryStatus == QUERY_RSP_RECEIVED_OK)
             {
                 u32TimeOut=0;
                 OTA_State = OTA_DL_PROGRESS;
             }
             else if ( (eImageQueryStatus == QUERY_RSP_RECEIVED_ERR) || ( u32TimeOut > OTA_QUERY_IMAGE_TIMEOUT_IN_SEC )  )
             {
                 u32TimeOut=0;
                 OTA_State = OTA_QUERYIMAGE;
             }
             else if(eImageQueryStatus == QUERY_FINISHED)
             {
                 u32TimeOut=0;
                 OTA_State = OTA_FIND_SERVER;
                 vRestetOTADiscovery();
                 DBG_vPrintf(TRACE_OTA_LNT, "CLEAR OUT SERVER #6\n");
             }
        }
        break;
        case OTA_DL_PROGRESS:
        {
            DBG_vPrintf(TRACE_APP_OTA,"In OTA_DL_PROGRESS\n ");
            vMonitorServerInDLProgress();
        }
        break;
        default :
            break;
    }
}
/****************************************************************************
 *
 * NAME: vMonitorServerInDLProgress
 *
 * DESCRIPTION:
 * Manages the DL progress state, mainly to get the state machine out of it
 *
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vMonitorServerInDLProgress(void)
{

    u32TimeOut++;
    tsOTA_PersistedData * psOTAPersistedData = psGetOTACallBackPersistdata();

    /*Monitor the download to initiate a route discovery when the retry has failed for predefined number of time times */
    DBG_vPrintf(TRACE_OTA_CIR_LOOP," The Retry = %d\n",psOTAPersistedData->u8Retry);

    if (psOTAPersistedData->u8Retry > APP_FORCE_ROUTE_DISCOVERY_COUNT)
    {
        ZPS_teStatus eStatus;
        DBG_vPrintf(TRACE_OTA_CIR_LOOP," The Server Address = %04x\n",psOTAPersistedData->u16ServerShortAddress);
        eStatus = ZPS_eAplZdoRouteRequest(psOTAPersistedData->u16ServerShortAddress,0);
           DBG_vPrintf(TRACE_OTA_CIR_LOOP," The ZPS_eAplZdoRouteRequest Status  = %d\n",eStatus);
    }


    DBG_vPrintf(TRACE_OTA_LNT, "Upgrade status=%d\n",psOTAPersistedData->sAttributes.u8ImageUpgradeStatus);
    if(    psOTAPersistedData->sAttributes.u8ImageUpgradeStatus == E_CLD_OTA_STATUS_NORMAL)
    {
        DBG_vPrintf(TRACE_OTA_LNT, "Upgrade status normal\n");
        u32TimeOut=0;
        OTA_State = OTA_FIND_SERVER;
        vRestetOTADiscovery();
        DBG_vPrintf(TRACE_OTA_LNT, "CLEAR OUT SERVER #7\n");
    }
}

/****************************************************************************
 *
 * NAME: vRestetOTADiscovery
 *
 * DESCRIPTION:
 * Resets OTA discovery so that a fresh discovery is possible
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vRestetOTADiscovery(void)
{
    DBG_vPrintf(TRACE_OTA_LNT, "%s\n", __FUNCTION__);
    memset(sDiscovedOTAServers,0,sizeof(sDiscovedOTAServers));
    u8Discovered=0;

}

/****************************************************************************
 *
 * NAME: vOTAPersist
 *
 * DESCRIPTION:
 * Persists OTA data when called by the OTA client ebvent, this is required to
 * restore the down load in case of power failure.
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/

PRIVATE void vOTAPersist(void)
{
    sOTA_PersistedData = sGetOTACallBackPersistdata();

    memset(&sOTA_PersistedData_App,0,sizeof(tsOTA_PersistedData_App));

    sOTA_PersistedData_App.sAttributes.u64UgradeServerID = sOTA_PersistedData.sAttributes.u64UgradeServerID;
    sOTA_PersistedData_App.sAttributes.u32FileOffset = sOTA_PersistedData.sAttributes.u32FileOffset;
    sOTA_PersistedData_App.sAttributes.u32CurrentFileVersion = sOTA_PersistedData.sAttributes.u32CurrentFileVersion;
    sOTA_PersistedData_App.sAttributes.u16CurrentStackVersion = sOTA_PersistedData.sAttributes.u16CurrentStackVersion;
    sOTA_PersistedData_App.sAttributes.u32DownloadedFileVersion = sOTA_PersistedData.sAttributes.u32DownloadedFileVersion;
    sOTA_PersistedData_App.sAttributes.u16DownloadedStackVersion = sOTA_PersistedData.sAttributes.u16DownloadedStackVersion;
    sOTA_PersistedData_App.sAttributes.u8ImageUpgradeStatus = sOTA_PersistedData.sAttributes.u8ImageUpgradeStatus;
    sOTA_PersistedData_App.sAttributes.u16ManfId = sOTA_PersistedData.sAttributes.u16ManfId;
    sOTA_PersistedData_App.sAttributes.u16ImageType = sOTA_PersistedData.sAttributes.u16ImageType;
    sOTA_PersistedData_App.sAttributes.u16MinBlockRequestDelay = sOTA_PersistedData.sAttributes.u16MinBlockRequestDelay;

#ifndef OTA_APP_PDM_OPTIMISE
    sOTA_PersistedData_App.u32FunctionPointer    = sOTA_PersistedData.u32FunctionPointer;
#endif

    sOTA_PersistedData_App.u32RequestBlockRequestTime  = sOTA_PersistedData.u32RequestBlockRequestTime;
    sOTA_PersistedData_App.u32CurrentFlashOffset       = sOTA_PersistedData.u32CurrentFlashOffset;
    sOTA_PersistedData_App.u32TagDataWritten           = sOTA_PersistedData.u32TagDataWritten;
    sOTA_PersistedData_App.u32Step                     = sOTA_PersistedData.u32Step ;
    sOTA_PersistedData_App.u16ServerShortAddress       = sOTA_PersistedData.u16ServerShortAddress;

#ifndef OTA_APP_PDM_OPTIMISE
#ifdef OTA_CLD_ATTR_REQUEST_DELAY
    sOTA_PersistedData_App.bWaitForBlockReq      = sOTA_PersistedData.bWaitForBlockReq;
#endif
#endif

    memcpy(&(sOTA_PersistedData_App.u8ActiveTag),&(sOTA_PersistedData.u8ActiveTag),OTA_TAG_HEADER_SIZE);
    memcpy(&(sOTA_PersistedData_App.u8PassiveTag),&(sOTA_PersistedData.u8PassiveTag),OTA_TAG_HEADER_SIZE);
    memcpy(&(sOTA_PersistedData_App.au8Header),&(sOTA_PersistedData.au8Header),OTA_MAX_HEADER_SIZE);

#ifndef OTA_APP_PDM_OPTIMISE
    sOTA_PersistedData_App.u8Retry               = sOTA_PersistedData.u8Retry;
#endif

    sOTA_PersistedData_App.u8RequestTransSeqNo   = sOTA_PersistedData.u8RequestTransSeqNo;
    sOTA_PersistedData_App.u8DstEndpoint         = sOTA_PersistedData.u8DstEndpoint ;

#ifndef OTA_APP_PDM_OPTIMISE
    sOTA_PersistedData_App.bIsCoProcessorImage   = sOTA_PersistedData.bIsCoProcessorImage;
    sOTA_PersistedData_App.bIsSpecificFile       = sOTA_PersistedData.bIsSpecificFile;
#endif

    sOTA_PersistedData_App.bIsNullImage          = sOTA_PersistedData.bIsNullImage;

#ifndef OTA_APP_PDM_OPTIMISE
    sOTA_PersistedData_App.u8CoProcessorOTAHeaderIndex = sOTA_PersistedData_App.u8CoProcessorOTAHeaderIndex;
    sOTA_PersistedData_App.u32CoProcessorImageSize     = sOTA_PersistedData_App.u32CoProcessorImageSize;
    sOTA_PersistedData_App.u32SpecificFileSize         = sOTA_PersistedData_App.u32SpecificFileSize;

#ifdef OTA_INTERNAL_STORAGE
    sOTA_PersistedData_App.u8Buf[0]   = sOTA_PersistedData.u8Buf[0];
    sOTA_PersistedData_App.u8Buf[1]   = sOTA_PersistedData.u8Buf[1];
    sOTA_PersistedData_App.u8Buf[2]   = sOTA_PersistedData.u8Buf[2];
    sOTA_PersistedData_App.u8Buf[3]   = sOTA_PersistedData.u8Buf[3];
#endif
#endif

    PDM_eSaveRecordData(PDM_ID_OTA_DATA,
                        &sOTA_PersistedData_App,
                        sizeof(tsOTA_PersistedData_App));

}
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

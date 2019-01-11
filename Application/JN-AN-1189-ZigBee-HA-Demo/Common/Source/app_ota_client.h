/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          app_ota_client.h
 *
 * DESCRIPTION:        DK4 (DR1175/DR1199) App OTA client (Implementation)
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

#ifndef APP_OTA_CLIENT_H
#define APP_OTA_CLIENT_H

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifdef OTA_DEMO_BUILD
    #define APP_FORCE_ROUTE_DISCOVERY_COUNT 2
    #define OTA_IEEE_ADDRESS_RESP_TIMEOUT_PER_REQUEST 5
    #define OTA_QUERY_TIME_IN_SEC 60/*once a day 24(H)*60(M)*60(S)= 86400*/ /*To find the server*/
    #define OTA_DISCOVERY_TIMEOUT_IN_SEC 15
    #define OTA_DL_IN_PROGRESS_TIME_IN_SEC 120
    #define RAND_TIMEOUT_MIN_IN_SEC 60
    #define RAND_TIMEOUT_MAX_IN_SEC 120
    #define OTA_QUERY_IMAGE_TIMEOUT_IN_SEC 5
    #define OTA_OTA_RE_QUERYIMAGE_TIME            60
    #define MAX_SERVER_EPs 2
    #define MAX_SERVER_NODES 2

#elif OTA_ICONTROL_BUILD
    #define APP_FORCE_ROUTE_DISCOVERY_COUNT 2
    #define RAND_TIMEOUT_MIN_IN_SEC 60                   // A random time lower value
    #define RAND_TIMEOUT_MAX_IN_SEC 120                   // A random time upper value

    #define OTA_IEEE_ADDRESS_RESP_TIMEOUT_PER_REQUEST 5
    #define OTA_QUERY_TIME_IN_SEC (60*60*24)             //+ RND_u32GetRand(RAND_TIMEOUT_MIN_IN_SEC,RAND_TIMEOUT_MAX_IN_SEC))  /*once a day 24(H)*60(M)*60(S)= 86400*/ /*To find the server*/
    #define OTA_DISCOVERY_TIMEOUT_IN_SEC 15           // Wait time for the Match descriptor BCAST to get an response , should be > BTR timeout for request + 1.6 sec for the response
    #define OTA_DL_IN_PROGRESS_TIME_IN_SEC (15*60)    //(24*60*60)  //Time in seconds - may be a day to allow to be in the download progress state else can assume that the server is lost and find the server again.
    #define OTA_QUERY_IMAGE_TIMEOUT_IN_SEC 15          // Wait for a query Image response there may be multiple servers hence wait for the max timeout before examining the servers
    #define OTA_OTA_RE_QUERYIMAGE_TIME        (15*60)   //ReQuery time
    #define MAX_SERVER_EPs 1
    #define MAX_SERVER_NODES 1
#else
    #define APP_FORCE_ROUTE_DISCOVERY_COUNT 2
    #define RAND_TIMEOUT_MIN_IN_SEC 60                   // A random time lower value
    #define RAND_TIMEOUT_MAX_IN_SEC 120                   // A random time upper value

    #define OTA_IEEE_ADDRESS_RESP_TIMEOUT_PER_REQUEST 5
    #define OTA_QUERY_TIME_IN_SEC (15*60)             //+ RND_u32GetRand(RAND_TIMEOUT_MIN_IN_SEC,RAND_TIMEOUT_MAX_IN_SEC))  /*once a day 24(H)*60(M)*60(S)= 86400*/ /*To find the server*/
    #define OTA_DISCOVERY_TIMEOUT_IN_SEC 15           // Wait time for the Match descriptor BCAST to get an response , should be > BTR timeout for request + 1.6 sec for the response
    #define OTA_DL_IN_PROGRESS_TIME_IN_SEC (15*60)    //(24*60*60)  //Time in seconds - may be a day to allow to be in the download progress state else can assume that the server is lost and find the server again.
    #define OTA_QUERY_IMAGE_TIMEOUT_IN_SEC 15          // Wait for a query Image response there may be multiple servers hence wait for the max timeout before examining the servers
    #define OTA_OTA_RE_QUERYIMAGE_TIME        (15*60)   //ReQuery time  
    #define MAX_SERVER_EPs 1
    #define MAX_SERVER_NODES 1
#endif

#define APP_OTA_OFFSET_WRITEN_BEFORE_LINKKEY_VERIFICATION 1100

#define APP_OTA_VBATT_LOW_THRES E_BO_TRIP_2V4
#define APP_OTA_VBATT_HI_THRES  E_BO_TRIP_2V7

#if JENNIC_CHIP==JN5168
    #define OTA_APP_PDM_OPTIMISE    TRUE
#endif

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
typedef struct {
    bool bValid;
    uint64 u64IeeeAddrOfServer;
    uint16 u16NwkAddrOfServer;
    uint8 u8MatchLength;
    uint8 u8MatchList[MAX_SERVER_EPs];
}tsDiscovedOTAServers;

typedef enum
{
    E_BO_TRIP_1V95 = 0,
    E_BO_TRIP_2V0  = 2,
    E_BO_TRIP_2V1  = 4,
    E_BO_TRIP_2V2  = 6,
    E_BO_TRIP_2V3  = 8,
    E_BO_TRIP_2V4  = 10,
    E_BO_TRIP_2V7  = 12,
    E_BO_TRIP_3V0  = 14
} teBrownOutTripVoltage;

typedef enum
{
    APP_E_OTA_STOP,
    APP_E_OTA_START
}teOTAActivity;

typedef struct
{
    tsCLD_AS_Ota_Persist sAttributes;
#ifndef OTA_APP_PDM_OPTIMISE
    uint32 u32FunctionPointer;
#endif
    uint32 u32RequestBlockRequestTime;
    uint32 u32CurrentFlashOffset;
    uint32 u32TagDataWritten;
    uint32 u32Step;
    uint16 u16ServerShortAddress;
#ifndef OTA_APP_PDM_OPTIMISE
#ifdef OTA_CLD_ATTR_REQUEST_DELAY
    bool_t bWaitForBlockReq;
#endif
#endif
    uint8 u8ActiveTag[OTA_TAG_HEADER_SIZE];
    uint8 u8PassiveTag[OTA_TAG_HEADER_SIZE];
    uint8 au8Header[OTA_MAX_HEADER_SIZE];
#ifndef OTA_APP_PDM_OPTIMISE
    uint8 u8Retry;
#endif
    uint8 u8RequestTransSeqNo;
    uint8 u8DstEndpoint;
#ifndef OTA_APP_PDM_OPTIMISE
    bool_t bIsCoProcessorImage;
    bool_t bIsSpecificFile;
#endif
    bool_t bIsNullImage;
#ifndef OTA_APP_PDM_OPTIMISE
    uint8  u8CoProcessorOTAHeaderIndex;

    uint32 u32CoProcessorImageSize;
    uint32 u32SpecificFileSize;

#ifdef OTA_INTERNAL_STORAGE
    uint8 u8Buf[4];
#endif
#endif

}tsOTA_PersistedData_App;


/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
PUBLIC void vAppInitOTA(void);
PUBLIC void vRunAppOTAStateMachine(void);
PUBLIC void vHandleZDPReqResForOTA(ZPS_tsAfEvent  *psStackEvent);
PUBLIC void vHandleAppOtaClient(tsOTA_CallBackMessage *psCallBackMessage);
PUBLIC void vLoadOTAPersistedData(void);
PUBLIC void vDumpFlashData(uint32 u32FlashByteLocation, uint32 u32EndLocation);
PUBLIC void vIncrementTimeOut(uint8 u8TimeInSec);
PUBLIC void vInitVBOForOTA(teBrownOutTripVoltage eBOTripValue);
/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/
PUBLIC  uint8 s_au8LnkKeyArray[16];
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#endif /*APP_OTA_CLIENT_H*/

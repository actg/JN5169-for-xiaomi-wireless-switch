/*****************************************************************************
 *
 * MODULE:             Smart Lighting Profile
 *
 * COMPONENT:          zsl.h
 *
 * AUTHOR:             rclay
 *
 * DESCRIPTION:        Header for ZigBee Smart lighting Profile functions
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/UnifiedZCL_ZLL102_HA122_Maintenance/Profiles/ZLL/Include/zll.h $
 *
 * $Revision: 55722 $
 *
 * $LastChangedBy: nxp46755 $
 *
 * $LastChangedDate: 2013-07-31 14:10:27 +0100 (Wed, 31 Jul 2013) $
 *
 * $Id: zll.h 55722 2013-07-31 13:10:27Z nxp46755 $
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

#ifndef ZLL_H
#define ZLL_H

#if defined __cplusplus
extern "C" {
#endif

#include <jendefs.h>
#include "zcl.h"
#include "zcl_options.h"


/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/* Sets the number of endpoints that will be created by the ZCL library
 *
 * These may be overridden by adding #define's to zcl_options.h
 *
 */
#ifndef ZLL_NUMBER_OF_ENDPOINTS
#define ZLL_NUMBER_OF_ENDPOINTS                              1
#endif

#ifndef ZLL_MANUFACTURER_CODE
#define ZLL_MANUFACTURER_CODE                                0x1234
#endif

/*
 * Add the following #define's to your zcl_options.h file to add optional
 * clusters.
 *
 * #define CLD_TIME
 *
 */

/* Smart Lighting Profile ID's */
#define ZLL_PROFILE_ID                  0xC05E
#ifndef HA_PROFILE_ID
#define HA_PROFILE_ID                   0x0104
#endif



#ifdef ZLL_PRIMARY
    #define ZLL_CHANNEL_MASK                ( (1<<11) | (1<<15) | (1<<20) | (1<<25) )
    #define ZLL_SECOND_CHANNEL_MASK         ( (1<<12) | (1<<13) | (1<<14) | (1<<16) | (1<<17) | \
                                          (1<<18) | (1<<19) | (1<<21) | (1<<22) | (1<<23) | \
                                          (1<<24) | (1<<26) )
    #define ZLL_SKIP_CH1    11
    #define ZLL_SKIP_CH2    15
    #define ZLL_SKIP_CH3    20
    #define ZLL_SKIP_CH4    25
#else
    #ifdef ZLL_PRIMARY_PLUS1
        #define ZLL_CHANNEL_MASK                ( (1<<12) | (1<<16) | (1<<21) | (1<<26) )
        #define ZLL_SECOND_CHANNEL_MASK         ( (1<<11) | (1<<13) | (1<<14) | (1<<15) | (1<<17) | \
                                          (1<<18) | (1<<19) | (1<<20) | (1<<22) | (1<<23) | \
                                          (1<<24) | (1<<25) )
        #define ZLL_SKIP_CH1    12
        #define ZLL_SKIP_CH2    16
        #define ZLL_SKIP_CH3    21
        #define ZLL_SKIP_CH4    26
    #else
        #ifdef ZLL_PRIMARY_PLUS2
            #define ZLL_CHANNEL_MASK                ( (1<<13) | (1<<17) | (1<<22) | (1<<19) )
            #define ZLL_SECOND_CHANNEL_MASK         ( (1<<11) | (1<<12) | (1<<14) | (1<<15) | (1<<16) | \
                                          (1<<18) | (1<<20) | (1<<21) | (1<<22) | (1<<24) | \
                                          (1<<25) | (1<<26) )
            #define ZLL_SKIP_CH1    13
            #define ZLL_SKIP_CH2    17
            #define ZLL_SKIP_CH3    19
            #define ZLL_SKIP_CH4    22
        #else
            #ifdef ZLL_PRIMARY_PLUS3
                #define ZLL_CHANNEL_MASK                ( (1<<14) | (1<<18) | (1<<23) | (1<<24) )
                #define ZLL_SECOND_CHANNEL_MASK         ( (1<<11) | (1<<12) | (1<<13) | (1<<15) | (1<<16) | \
                                          (1<<17) | (1<<19) | (1<<20) | (1<<21) | (1<<22) | \
                                          (1<<25) | (1<<26) )
                #define ZLL_SKIP_CH1    14
                #define ZLL_SKIP_CH2    18
                #define ZLL_SKIP_CH3    23
                #define ZLL_SKIP_CH4    24
            #endif
        #endif
    #endif
#endif




extern const uint8 au8ZLLChannelSet[];

/* ZLL device types  */
#define ON_OFF_LIGHT_DEVICE_ID             0x0000
#define ON_OFF_PLUG_DEVICE_ID              0x0010
#define DIMMABLE_LIGHT_DEVICE_ID           0x0100
#define DIMMABLE_PLUG_DEVICE_ID            0x0110
#define COLOUR_LIGHT_DEVICE_ID             0x0200
#define EXTENDED_COLOUR_LIGHT_DEVICE_ID     0x0210
#define COLOUR_TEMPERATURE_LIGHT_DEVICE_ID  0x0220

#define COLOUR_REMOTE_DEVICE_ID            0x0800
#define COLOUR_SCENE_REMOTE_DEVICE_ID      0x0810
#define NON_COLOUR_REMOTE_DEVICE_ID        0x0820
#define NON_COLOUR_SCENE_REMOTE_DEVICE_ID  0x0830
#define CONTROL_BRIDGE_DEVICE_ID           0x0840
#define ON_OFF_SENSOR_DEVICE_ID            0x0850

#define aplcInterPANTransIdLifetime        8            // Seconds
#define aplcMinStartupDelayTime            2            // Seconds
#define aplcRxWindowDuration               5            // Seconds
#define aplcScanTimeBaseDuration           250          // milli seconds
#define aplcMaxPermitJoinDuration          60           // seconds
#define aplcMaxParentLossRetryAttempts     10
#define aplcMaxPollInterval                1            // hours
#define aplcMinChildPersistenceTime        (4*aplcMaxPollInterval)

#define ZLL_SCAN_RX_TIME_MS                  aplcScanTimeBaseDuration
#define ZLL_INTERPAN_LIFE_TIME_SEC           aplcInterPANTransIdLifetime
#define ZLL_RX_WINDOW_TIME_SEC               aplcRxWindowDuration
#define ZLL_START_UP_TIME_SEC                aplcMinStartupDelayTime
#define ZLL_MAX_PERMIT_JOIN_TIME_SEC         aplcMaxPermitJoinDuration
#define ZLL_MAX_REJOIN_ATTEMPTS              aplcMaxParentLossRetryAttempts
#define ZLL_MAX_POLL_INTERVAL_HOURS          aplcMaxPollInterval
#define ZLL_CHILD_PERSIST_TIME_HOURS         aplcMinChildPersistenceTime



#define ZLL_SUCCESS     0
#define ZLL_ERROR       1

#define ZLL_MIN_ADDR     0x0001
#define ZLL_MAX_ADDR     0xfff7
#define ZLL_MIN_GROUP    0x0001
#define ZLL_MAX_GROUP    0xfeff

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
typedef struct
{
    uint64  u64IEEEAddr;
    uint16  u16ProfileId;
    uint16 u16DeviceId;
    uint8   u8Endpoint;
    uint8 u8Version;
    uint8 u8NumberGroupIds;
    uint8 u8Sort;
} tsCLD_ZllDeviceRecord;

typedef struct
{
    uint8   u8NumberDevices;
    tsCLD_ZllDeviceRecord asDeviceRecords[ZLL_NUMBER_DEVICES];
} tsCLD_ZllDeviceTable;




/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC teZCL_Status eZLL_Initialise(tfpZCL_ZCLCallBackFunction cbCallBack,
                                   PDUM_thAPdu hAPdu);

PUBLIC teZCL_Status eZLL_Update100mS(void);

/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

#if defined __cplusplus
}
#endif

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/
#endif /* ZLL_H */

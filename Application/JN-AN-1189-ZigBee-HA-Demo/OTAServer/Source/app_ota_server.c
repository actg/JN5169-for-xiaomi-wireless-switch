/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          app_ota_server.c
 *
 * DESCRIPTION:        DK4 USB Dongle OTA Server App (Implementation)
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

#include "ota.h"
#include "ha.h"

#include "app_timer_driver.h"
#include "app_ota_server.h"

#include "app_common.h"
#include "Utilities.h"
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifndef DEBUG_APP_OTA
    #define TRACE_APP_OTA               FALSE
#else
    #define TRACE_APP_OTA               TRUE
#endif

#define OTA_STARTUP_DELAY_IN_SEC 5
#define OTA_FIND_SERVER 1
#define OTA_FIND_SERVER_WAIT 2
#define OTA_FIND_SERVER_ADDRESS 3
#define OTA_FIND_SERVER_ADDRESS_WAIT 4
#define OTA_QUERYIMAGE 5
#define OTA_DL_PROGRESS 6

#define APP_IEEE_ADDR_RESPONSE 0x8001
#define APP_MATCH_DESCRIPTOR_RESPONSE 0x8006

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
PRIVATE void vInitAndDisplayKeys(void);
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

/* mac address */
PUBLIC    uint8 au8MacAddress[]  __attribute__ ((section (".ro_mac_address"))) = {
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

/* Pre-configured Link Key */
PUBLIC    uint8 s_au8LnkKeyArray[16] __attribute__ ((section (".ro_se_lnkKey"))) = {0x5a, 0x69, 0x67, 0x42, 0x65, 0x65, 0x41, 0x6c,
        0x6c, 0x69, 0x61, 0x6e, 0x63, 0x65, 0x30, 0x39};

volatile PRIVATE uint8 au8MacAddressVolatile[8];

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
        /*Set Up OTA server related stuff*/
    vInitAndDisplayKeys();

    tsNvmDefs sNvmDefs;
    teZCL_Status eZCL_Status;
    uint8 au8CAPublicKey[22];

    #if (OTA_MAX_IMAGES_PER_ENDPOINT == 3)
        uint8 u8StartSector[3] = {0,2,4};
    #else
        #ifdef JENNIC_CHIP_FAMILY_JN516x
            uint8 u8StartSector[1] = {0};
        #else
            uint8 u8StartSector[2] = {0,3};
        #endif
    #endif

    sNvmDefs.u32SectorSize = 64*1024;
    sNvmDefs.u8FlashDeviceType = E_FL_CHIP_AUTO;
    vOTA_FlashInit(NULL,&sNvmDefs);

    eZCL_Status = eOTA_NewImageLoaded(2,FALSE,NULL);
    DBG_vPrintf(TRACE_APP_OTA, "\neOTA_NewImageLoaded status = %d\n", eZCL_Status);

    eZCL_Status = eOTA_AllocateEndpointOTASpace(2, u8StartSector, OTA_MAX_IMAGES_PER_ENDPOINT, 4, TRUE,au8CAPublicKey);
    if (eZCL_Status != E_ZCL_SUCCESS)
    {
        DBG_vPrintf(TRACE_APP_OTA, "eAllocateEndpointOTASpace returned error 0x%x\n", eZCL_Status);
    }

    eZCL_Status = eOTA_SetServerAuthorisation(2, E_CLD_OTA_STATE_ALLOW_ALL,NULL, 0);
    if (eZCL_Status != E_ZCL_SUCCESS)
    {
        DBG_vPrintf(TRACE_APP_OTA, "eSetServerAuthorisation returned error 0x%x\n", eZCL_Status);
    }

    tsOTA_ImageNotifyCommand   sImageNotifyCommand;
    tsZCL_Address              sDestinationAddress;
    sDestinationAddress.eAddressMode = E_ZCL_AM_BROADCAST;
    sDestinationAddress.uAddress.u16DestinationAddress = 0xffff;
    sImageNotifyCommand.ePayloadType = E_CLD_OTA_QUERY_JITTER;
    sImageNotifyCommand.u8QueryJitter=100;
    eOTA_ServerImageNotify(2,0xff,&sDestinationAddress,&sImageNotifyCommand);
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
        /*ZPS_vSetOverrideLocalMacAddress((uint64 *)&au8MacAddress);*/
        volatile uint8 u8Index;
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
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

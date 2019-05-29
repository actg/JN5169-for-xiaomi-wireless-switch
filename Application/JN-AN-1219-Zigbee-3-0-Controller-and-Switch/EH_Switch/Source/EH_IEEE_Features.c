/*****************************************************************************
 *
 * MODULE:             JN-AN-1219
 *
 * COMPONENT:          EH_IEEE_Features.c
 *
 * AUTHOR:             Rajeena
 *
 * DESCRIPTION:        ZigBee EH Feature implementation
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
 * Copyright NXP B.V. 2016. All rights reserved
 *
 ***************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include "jendefs.h"
#include "AppHardwareApi.h"
#include "PeripheralRegs.h"
#include "string.h"
#include <dbg.h>
#include <dbg_uart.h>
#include "MMAC.h"
#include "EH_IEEE_802154_Switch.h"
#include "EH_Switch_Configurations.h"
#include "EH_IEEE_Features.h"
#include "EH_IEEE_Commands.h"
#include "AHI_EEPROM.h"
#include "aessw_ccm.h"
#include "AHI_AES.h"
#include "EH_Button.h"
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/** GPD fixed RX offset, constant by GP spec and non configurable */
#define GPD_RX_OFFSET                       (5000) /* in micro sec */

/** 2.4 GHZ minimum channel number */
#define MIN_CHANEL                          (11)

/** 2.4 GHZ maximum  channel number */
#define MAX_CHANEL                          (26)

/** The bit values/magic numbers  in received command */
#define PAN_ID_BIT_INDEX_COMM_REPY          (0x01)
#define SEC_KEY_BIT_INDEX_COMM_REPY         (0x02)
#define SEC_KEY_ENC_BIT_INDEX_COMM_REPY     (0x04)
#define SEC_KEY_TYPE_BITS_INDEX_COMM_REPY   (0x05)
#define SEC_KEY_TYPE_BITS_MASK_COMM_REPY    (0xE0)

/** Security key size */
#define KEY_SIZE                            (16)

/** byte value to confirm PDM validity*/
#define PDM_MAGIC_NO                        (0xA8)
#define GP_CHANNEL_CONFIG_CH_MASK           (0x0f)
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/


/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

/* Global non persistent data */
ts_GPDData sGPDData = { 0,0 };

/* Global  persistent data */
tGPD_PersistantData sGPDPersistentData;

/* channel list */
#ifdef GPD_SEND_CHANNEL_REQUEST
    #ifdef SECONDARY_CHANNELS
        const uint8 au8ChannelList[] ={ PRIMARY_CHANNELS,SECONDARY_CHANNELS };
    #else
        const uint8 au8ChannelList[] ={ PRIMARY_CHANNELS } ;
    #endif
#endif


/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
#ifdef GPD_SEND_CHANNEL_REQUEST
void vSendChannelRequestCmd(void);
#endif
void vSendGPDSuccessCmd(void);
void vSendCommissioningCmd(void);
bool bHandleCommissioningStateMachine(void);
void vHandleOperationalState(uint8 u8CmdId);

#ifdef GPD_WITH_SECURITY
bool bEncryptDecyptKey(uint8 u8CCMMode, uint8 *pu8Key);
#endif
/****************************************************************************/
/***        Public Functions                                              ***/
/****************************************************************************/

#ifndef LITTLE_ENDIAN_PROCESSOR
/****************************************************************************
 *
 * NAME: vMemRevCpy
 *
 * DESCRIPTION:
 * Copies from source memory to destination memory in reverse order
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
void vMemRevCpy(uint8 *pu8Dst, uint8 *pu8Src, uint8 u8Len)
{
    uint8 i;
    for(i=0;i<u8Len; i++ )
    {
        pu8Dst[u8Len -1- i] = pu8Src[i];
    }
}

#endif
/****************************************************************************
 *
 * NAME: HandleGPDStateMachine
 *
 * DESCRIPTION:
 * Handles GP Switch state machine
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
void HandleGPDStateMachine( uint8 u8CmdId)
{
#ifndef GPD_AUTOCOMMISSIOINING
    bool bRxEnable = FALSE;
#endif

    DBG_vPrintf(DBG_DEVICE_SWITCH, "\n HandleGPDStateMachine \n" );
#ifndef DK4
    vLoadPersistentData();
#endif
    /* sGPDPersistentData is updated with data required for operation */
#ifndef GPD_AUTOCOMMISSIOINING
    /* If commissioing is complete, send operational mode commands */
    if(sGPDPersistentData.b8CommissioiningStatusBits & COMM_COMP_SET_BIT)
#endif
    {
        vHandleOperationalState(u8CmdId);
    }
#ifndef GPD_AUTOCOMMISSIOINING
    else /* GPDPersistentData.b8CommissioiningStatusBits & COMM_COMP_SET_BIT */
    {

        bRxEnable = bHandleCommissioningStateMachine();
    }
#endif /* GPD_AUTOCOMMISSIOINING */

#if defined( GPD_RX_AFTER_TX) || defined(GPD_RX_ENABLE)
    if(bRxEnable == TRUE)
    {
        /* Enable Rx */

        vEnableRxAndReceive();

    }
#endif

}
/****************************************************************************
 *
 * NAME: vSendDecommissioingCmd
 *
 * DESCRIPTION:
 * Send de commissioning command
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
void vSendDecommissioingCmd(void)
{
#ifdef  GPD_WITH_SECURITY
    uint8 u8GPDEncryptedDataIndex = 0;
#endif
    /* Form MAC Header */

#ifdef GPD_WITH_SECURITY
    GPD_ConstructMACAndNetworkHeader(FALSE, TRUE, FALSE);
#else
    GPD_ConstructMACAndNetworkHeader(FALSE, FALSE, FALSE);
#endif
#ifdef  GPD_WITH_SECURITY

    /* Save index of NWK payload for security addition */
    u8GPDEncryptedDataIndex = sGPD_MACFrame.u8PayloadLength;
#endif
    /* Add  decommissioing command id */
    sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength] =
        E_GPD_DECOMMISSIOINING_CMD;
    sGPD_MACFrame.u8PayloadLength++;
#ifdef  GPD_WITH_SECURITY
    /* add security */
    bGPD_SecureFrame(u8GPDEncryptedDataIndex,XCV_REG_AES_SET_MODE_CCM,(sGPDPersistentData.U32FrameCounter - 1), &sGPD_MACFrame);
#endif
    sGPDPersistentData.b8CommissioiningStatusBits = 0;
    sGPDPersistentData.b8CommissioiningStatusBitsPrevious= 0;
    /* transmit frame */
    vSendMACFrame(TRUE);

}
/****************************************************************************
 *
 * NAME: vClearPersistentData
 *
 * DESCRIPTION:
 * Resets persistent data to defaults
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
void vClearPersistentData(bool bIsWriteToEEPROM)
{
#ifdef GPD_WITH_SECURITY
    uint8 au8GPDKey[16]  __attribute__ ((aligned (4))) = GPD_KEY;
#endif
    DBG_vPrintf(DBG_DEVICE_SWITCH, " \n  vClearPersistentData \n");

    /* reset persistent data */
    sGPDPersistentData.b8CommissioiningStatusBits = 0x00;
    sGPDPersistentData.u8Channel = GPD_DEFAULT_CHANNEL;
    sGPDPersistentData.U16Panid = GPD_DEFAULT_PANID;
    sGPDPersistentData.U8MACSeqNumber = 0;
    sGPDPersistentData.u8NoOfTransPerChannel = GPD_NO_OF_COMMANDS_IN_OPERATIONAL_CHANNEL;
    sGPDPersistentData.u8ChannelIndex = 0;
#ifdef GPD_WITH_SECURITY
    sGPDPersistentData.U8GPDSecKeyType = GPD_KEY_TYPE;
    memcpy((uint8 *)&sGPDPersistentData.sGPDSecKey, au8GPDKey,  sizeof(sGPDPersistentData.sGPDSecKey));
    sGPDPersistentData.U32FrameCounter = 1;
#endif
    sGPDPersistentData.b8CommissioiningStatusBitsPrevious = 0;
    sGPDPersistentData.u8PDMValid = PDM_MAGIC_NO;

#ifdef GPD_SUPPORT_PERSISTENT_DATA
    if(bIsWriteToEEPROM)
    {

        bAHI_WriteEEPROMBlock(EEPROM_START_SECTOR,
                    sizeof(tGPD_PersistantData),
                    (uint8 *)&sGPDPersistentData);
    }


#endif

}



/****************************************************************************/
/***        Local Functions                                              ***/
/****************************************************************************/
/****************************************************************************
 *
 * NAME: vLoadPersistentData
 *
 * DESCRIPTION:
 * Loads persistent data. If persisting data is not supported,
 * default values will be loaded
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
void vLoadPersistentData(void)
{
#ifdef GPD_SUPPORT_PERSISTENT_DATA
    /* Restore persistent Data */

    if(bAHI_ReadEEPROMBlock(EEPROM_START_SECTOR,
            sizeof(tGPD_PersistantData),
            (uint8 *)&sGPDPersistentData))
    {
        if(PDM_MAGIC_NO != sGPDPersistentData.u8PDMValid)
        {
            /* First time, PDM does not have default values. Initialize with default configuration*/
            DBG_vPrintf(DBG_DEVICE_SWITCH, " \n  Writing default values to persistent = %d\n",sGPDPersistentData.u8PDMValid);
            vClearPersistentData(FALSE);

        }
    }
#else /* GPD_SUPPORT_PERSISTENT_DATA */
    if(PDM_MAGIC_NO != sGPDPersistentData.u8PDMValid)
    {
        /* First time, PDM does not have default values. Initialize with default configuration*/
        DBG_vPrintf(DBG_DEVICE_SWITCH, " \n  Writing default values to persistent = %d\n",sGPDPersistentData.u8PDMValid);
        vClearPersistentData(FALSE);

    }

#endif /* GPD_SUPPORT_PERSISTENT_DATA */
}
/****************************************************************************
 *
 * NAME: vHandleOperationalState
 *
 * DESCRIPTION:
 * Send the appropriate commands in operational mode
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
void vHandleOperationalState(uint8 u8CmdId)
{


#ifndef DK4
    sGPDData.u8ButtonCount = u32REG_SysRead(REG_SYS_WK_T1);
#endif

    {
        DBG_vPrintf(DBG_DEVICE_SWITCH, "\n Sending operational command  \n" );
        /* send operational command here */
#if (GPD_TYPE == GP_LEVEL_CONTROL_SWITCH)
        if(u8CmdId)
        {
            /* specific command */
            GPD_SendSpecificCommand(u8CmdId);
            sGPDData.u8ButtonCount = 0x00;
        }
        else
#endif
        {
            /* default command */
            sGPDData.u8ButtonCount++;
            GPD_SendOperationalCommand();
        }
        /* required to update sequence number or frame control in persistent memory */
    }


}
/****************************************************************************
 *
 * NAME: bHandleCommissioningStateMachine
 *
 * DESCRIPTION:
 * Send the appropriate commands in commissioning mode
 *
 * RETURNS:
 * TRUE: Response to be received
 * FALSe: No response Expected
 *
 ****************************************************************************/
bool bHandleCommissioningStateMachine(void)
{
    bool bRxEnable = FALSE;
#if defined (GPD_RX_AFTER_TX) ||  defined (GPD_RX_ENABLE)
    /* Reset the button count for de commissioning / factory reset */
    sGPDData.u8ButtonCount = 0x00;

#ifdef GPD_SEND_CHANNEL_REQUEST
    if(sGPDPersistentData.b8CommissioiningStatusBits & CHANNEL_SET_BIT)
    {
#endif /* GPD_SEND_CHANNEL_REQUEST */
    /* channel is set , go for next commissioning command */

        if(sGPDPersistentData.b8CommissioiningStatusBits & COMM_REPLY_RCVD_BIT)
        {

            /* pan id is set , go for commissioning command */
#if (defined(GPD_WITH_SECURITY ) )
            if(sGPDPersistentData.b8CommissioiningStatusBits & SEC_MAT_SET_BIT)
            {
#endif /* ((GPD_SECURITY_LEVEL != GPD_NO_SECURITY ) )) */
            /* security materials are set , go for next packet */

                if(sGPDPersistentData.b8CommissioiningStatusBits & GPDF_SUCCESS_SET_BIT)
                {
                    /* Success GPDF is send , set commissioning complete bit  */
                    sGPDPersistentData.b8CommissioiningStatusBits =
                        sGPDPersistentData.b8CommissioiningStatusBits | COMM_COMP_SET_BIT;

                }
                else /* GPDF_SUCCESS_SET_BIT not set */
                {

                    /** Send GPDF Success command */
                    sGPDPersistentData.b8CommissioiningStatusBits =
                        sGPDPersistentData.b8CommissioiningStatusBits | GPDF_SUCCESS_SET_BIT;
                    sGPDPersistentData.b8CommissioiningStatusBits |=
                        sGPDPersistentData.b8CommissioiningStatusBits | COMM_COMP_SET_BIT;
                    vSendGPDSuccessCmd();
                }
    #if (defined(GPD_WITH_SECURITY ))
            }
            else /* SEC_MAT_SET_BIT not set */
            {
                vSendCommissioningCmd();
                bRxEnable = TRUE;

            }
#endif /* #if ((GPD_SECURITY_LEVEL != GPD_NO_SECURITY )  */


        }
        else /* COMM_REPLY_RCVD_BIT not set */
        {

            vSendCommissioningCmd();
            bRxEnable = TRUE;

        }

#ifdef GPD_SEND_CHANNEL_REQUEST
    }
    else /* CHANNEL_SET_BIT not set */
    {
        /* Send  channel request command  */

        vSendChannelRequestCmd();
        bRxEnable = TRUE;
    }
#endif /* GPD_SEND_CHANNEL_REQUEST */

#else  /*GPD_RX_AFTER_TX */

    vSendCommissioningCmd();
    sGPDPersistentData.b8CommissioiningStatusBits |=  COMM_COMP_SET_BIT;

#endif /*GPD_RX_AFTER_TX */
return bRxEnable;
}
/****************************************************************************
 *
 * NAME: vHandleRxMacFrame
 *
 * DESCRIPTION:
 * Handles received data
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
void vHandleRxMacFrame(void)
{
    ts_ReceivedPayload sReceivedData;
    bool bUpdatePersistence = FALSE;
    uint8 payloadIndex = 1;
#ifdef GPD_WITH_SECURITY
    bool_t bIsValidFrame = TRUE;
#endif

    /* Parse received frame */
    if(bGPD_ParseMACFrame(FALSE, &sReceivedData))
    {
        /* check protocol id and other bits */
        /* valid gpd frame, parse based on gpd command id */
        switch(sReceivedData.u8CmdId)
        {
            case E_GPD_COMM_REPLY_CMD:
                DBG_vPrintf(DBG_DEVICE_SWITCH, "\n vHandleRxMacFrame E_GPD_COMM_REPLY_CMD \n" );
                if(sReceivedData.u8CmdPayloadLen > 0)
                {
                    sGPDPersistentData.b8CommissioiningStatusBits =
                        sGPDPersistentData.b8CommissioiningStatusBits | COMM_REPLY_RCVD_BIT;
                    bUpdatePersistence = TRUE;
                    sGPDPersistentData.u8NoOfTransPerChannel = GPD_NO_OF_COMMANDS_IN_OPERATIONAL_CHANNEL;
                    /* check if pan id present */
                    if(sReceivedData.pu8CmdPayload[0] &PAN_ID_BIT_INDEX_COMM_REPY)
                    {
                        /* extract pan id and store it */

                        sGPDPersistentData.b8CommissioiningStatusBits =
                                sGPDPersistentData.b8CommissioiningStatusBits | COMM_REPLY_RCVD_BIT;
                        vMemRevCpy((uint8 *)&sGPDPersistentData.U16Panid, sReceivedData.pu8CmdPayload + payloadIndex,
                                sizeof(sGPDPersistentData.U16Panid));
                        payloadIndex += 2;

                        DBG_vPrintf(DBG_DEVICE_SWITCH, "\n PAN_ID_BIT_INDEX_COMM_REPY = 0x%4x \n", sGPDPersistentData.U16Panid );
                    }
    #ifdef GPD_WITH_SECURITY
                    if(sReceivedData.pu8CmdPayload[0] & SEC_KEY_BIT_INDEX_COMM_REPY)
                    {

                        if(sReceivedData.pu8CmdPayload[0] & SEC_KEY_ENC_BIT_INDEX_COMM_REPY)
                        {


                            bIsValidFrame = bEncryptDecyptKey(
                                    XCV_REG_AES_SET_MODE_CCM_D,
                                    (sReceivedData.pu8CmdPayload + payloadIndex));

                            DBG_vPrintf(DBG_DEVICE_SWITCH, "\n bIsValidFrame = %d  \n",bIsValidFrame );

                            if(bIsValidFrame)
                            {
                                /* security processing complete , store keys */
                                sGPDPersistentData.b8CommissioiningStatusBits =
                                sGPDPersistentData.b8CommissioiningStatusBits | SEC_MAT_SET_BIT;
                                sGPDPersistentData.U8GPDSecKeyType  =
                                (sReceivedData.pu8CmdPayload[0] & SEC_KEY_TYPE_BITS_MASK_COMM_REPY) >> SEC_KEY_TYPE_BITS_INDEX_COMM_REPY;
                                memcpy((uint8 *)&sGPDPersistentData.sGPDSecKey ,&sReceivedData.pu8CmdPayload[payloadIndex], KEY_SIZE);
                                payloadIndex += KEY_SIZE;


                                DBG_vPrintf(DBG_DEVICE_SWITCH, "\n Printing Key , key type = %d  \n",sGPDPersistentData.U8GPDSecKeyType );

                            }

                        }
                        else
                        {
                            sGPDPersistentData.b8CommissioiningStatusBits =
                            sGPDPersistentData.b8CommissioiningStatusBits | SEC_MAT_SET_BIT;
                            sGPDPersistentData.U8GPDSecKeyType  =
                            (sReceivedData.pu8CmdPayload[0]& SEC_KEY_TYPE_BITS_MASK_COMM_REPY) >> SEC_KEY_TYPE_BITS_INDEX_COMM_REPY;
                            memcpy((uint8 *)&sGPDPersistentData.sGPDSecKey ,&sReceivedData.pu8CmdPayload[payloadIndex], KEY_SIZE);
                            payloadIndex += KEY_SIZE;


                            DBG_vPrintf(DBG_DEVICE_SWITCH, "\n Printing Key send in clear , key type = %d  \n",sGPDPersistentData.U8GPDSecKeyType );

                        }
                    }
                    else
                    {
                        sGPDPersistentData.b8CommissioiningStatusBits =
                        sGPDPersistentData.b8CommissioiningStatusBits | SEC_MAT_SET_BIT;
                    }
#endif
                }
            break;
            case E_GPD_CHANNEL_CONFIG_CMD:
            {
                uint8 u8Channel;
                if(sReceivedData.u8CmdPayloadLen > 0)
                {
                    u8Channel   =sReceivedData.pu8CmdPayload[0] &  GP_CHANNEL_CONFIG_CH_MASK;
                    DBG_vPrintf(DBG_DEVICE_SWITCH, "\n E_GPD_CHANNEL_CONFIG_CMD =%d u8Channel = %d sReceivedData.pu8CmdPayload[0]  = %d\n",sGPDPersistentData.u8Channel ,u8Channel,
                            sReceivedData.pu8CmdPayload[0] );
                    if(((u8Channel + MIN_CHANEL) >= MIN_CHANEL) && ((u8Channel + MIN_CHANEL) <= MAX_CHANEL))
                    {
                        /* Extract and save channel */
                        sGPDPersistentData.b8CommissioiningStatusBits =
                            sGPDPersistentData.b8CommissioiningStatusBits | CHANNEL_SET_BIT;
                        sGPDPersistentData.u8Channel = u8Channel + MIN_CHANEL;
                        sGPDPersistentData.u8NoOfTransPerChannel = GPD_NO_OF_COMMANDS_IN_OPERATIONAL_CHANNEL;
                        bUpdatePersistence = TRUE;
                        DBG_vPrintf(DBG_DEVICE_SWITCH, "\n operational channel =%d  \n",sGPDPersistentData.u8Channel );

                    }
                }
            }
            break;
            default:
                DBG_vPrintf(DBG_DEVICE_SWITCH, "\nvHandleRxMacFrame, unknown command = 0x%x \n", sReceivedData.u8CmdId );
                break;

        }
    }
    else
    {
        DBG_vPrintf(DBG_DEVICE_SWITCH, "\nv HandleRxMacFrame,Parsing Failed  \n" );
    }
    if(bUpdatePersistence)
    {
         bAHI_WriteEEPROMBlock(EEPROM_START_SECTOR,
                sizeof(tGPD_PersistantData),
                (uint8 *)&sGPDPersistentData);
    }
}
/****************************************************************************
 *
 * NAME: bEncryptDecyptKey
 *
 * DESCRIPTION:
 * Encrypts/De crypt key with tc-lk
 *
 * RETURNS:
 * Returns whether encryption/de cryption is success
 *
 ****************************************************************************/
#ifdef GPD_WITH_SECURITY
bool bEncryptDecyptKey(uint8 u8CCMMode, uint8 *pu8Key)
{
    bool bEncrypt = FALSE;
    bool_t bIsValidFrame = TRUE;
    uint32 u32OutgoingCounter;
    uint8 const auTC_LK[]  __attribute__ ((aligned (4))) = { 0x5a, 0x69, 0x67, 0x42, 0x65, 0x65, 0x41, 0x6c,
            0x6c, 0x69, 0x61, 0x6e, 0x63, 0x65, 0x30, 0x39};

    tsReg128 sKey;

#ifndef  GPD_IEEE_ADDRESS_ENABLE
    uint32 u32SourceID =  GPD_SOURCE_ID;
#endif
    uint8 a[4];
    AESSW_Block_u aNonce;
    DBG_vPrintf(DBG_DEVICE_SWITCH, "\n bEncryptDecyptKey  \n" );
    memset((uint8 *)&aNonce, 0, sizeof(aNonce));
#ifndef  GPD_IEEE_ADDRESS_ENABLE
    if(XCV_REG_AES_SET_MODE_CCM_D == u8CCMMode)
    {
        vMemRevCpy(&aNonce.au8[5], (uint8 *)&u32SourceID, sizeof(u32SourceID));

        u32OutgoingCounter = sGPDPersistentData.U32FrameCounter - 1;

#ifndef GPD_SECURITY_LEVEL_FC_1LSB_MIC_2B_NO_ENC
        vMemRevCpy(&aNonce.au8[9], (uint8 *)&(u32OutgoingCounter),
                sizeof(sGPDPersistentData.U32FrameCounter));
#else
        aNonce.au8[9] = sGPD_MACReceivedFrame.u8SequenceNum + 1;
#endif
    }
    else
    {
        vMemRevCpy(&aNonce.au8[1], (uint8 *)&u32SourceID, sizeof(u32SourceID));
        vMemRevCpy(&aNonce.au8[5], (uint8 *)&u32SourceID, sizeof(u32SourceID));
        vMemRevCpy(&aNonce.au8[9], (uint8 *)&u32SourceID, sizeof(u32SourceID));
    }
#else
    memcpy(&aNonce.au8[1],(uint8 *)&(sGPD_MACReceivedFrame.uDestAddr.sExt),MAC_EXT_ADDR_LEN);
#endif


    /* security control */
    aNonce.au8[13] = SECURITY_LEVEL_5;

#ifdef  GPD_IEEE_ADDRESS_ENABLE
    vMemRevCpy(&a[0], (uint8 *)&(sGPD_MACReceivedFrame.uDestAddr.sExt.u32L),
            sizeof(sGPD_MACReceivedFrame.uDestAddr.sExt.u32L));

#else
    vMemRevCpy(&a[0], (uint8 *)&u32SourceID, sizeof(u32SourceID));
#endif
    vACI_CmdWaitBusy();
    memcpy((uint8 *)&sKey ,auTC_LK, sizeof(auTC_LK) );
#ifdef LITTLE_ENDIAN_PROCESSOR
    sKey.u32register0 = u32Reverse(sKey.u32register0);
    sKey.u32register1 = u32Reverse(sKey.u32register1);
    sKey.u32register2 = u32Reverse(sKey.u32register2);
    sKey.u32register3 = u32Reverse(sKey.u32register3);
#endif

    if (bACI_WriteKey((tsReg128 *)&sKey) == FALSE)
    {
        /* Failed, so give up */
        DBG_vPrintf(DBG_DEVICE_SWITCH, "\n bACI_WriteKey failed  \n" );
        return FALSE;
    }

    if(u8CCMMode == XCV_REG_AES_SET_MODE_CCM)
    {
        bEncrypt = TRUE;
    }

    vACI_OptimisedCcmStar(
            bEncrypt,           /*bEncrypt*/
            4,
            4 ,  /* Length of authentication data, in bytes */
            KEY_SIZE,
            &aNonce,
            a,
            pu8Key,
            (pu8Key + KEY_SIZE),
            &bIsValidFrame
        );

    return bIsValidFrame;

}
#endif



#ifdef GPD_SEND_CHANNEL_REQUEST

/****************************************************************************
 *
 * NAME: vSendChannelRequestCmd
 *
 * DESCRIPTION:
 * Send channel request command
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
void vSendChannelRequestCmd(void)
{
    uint8 i;

    /* -1 as array index starts from 0 */
    uint8 u8NextChannelIndex = sGPDPersistentData.u8ChannelIndex + GPD_NO_OF_CHANNEL_PER_COMM_ATTEMPT -1 ;
    uint8 u8SecondNextChannelIndex = sGPDPersistentData.u8ChannelIndex + 2 *GPD_NO_OF_CHANNEL_PER_COMM_ATTEMPT -1;

    /* Form MAC Header */

    //GPD_ConstructMACAndNetworkHeader(FALSE, FALSE, TRUE);
    GPD_ConstructMaintenaceFrame();
    /* Construct payload, command id first */
    sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength++] =
            E_GPD_CHANNEL_REQ_CMD;

    /* channel request should be transmitted in a channel for GPD_NO_OF_CHANNEL_REQ_PER_CHANNEL times*/
    sGPDPersistentData.u8NoOfTransPerChannel = GPD_NO_OF_REQ_BEFORE_RX;

    /* Switch will scan primary channels(11, 15, 20 and 25) first followed by secondary
     channel(12, 13, 14, 16, 17, 18, 19, 21, 22, 23, 24).On each channel GPD will repeat
     the channel request for GPD_NO_OF_CHANNEL_REQ_PER_CHANNEL.  For example if
     GPD_NO_OF_CHANNEL_PER_COMM_ATTEMPT is 3 and GPD_NO_OF_CHANNEL_REQ_PER_CHANNEL is 1,On
     first press, channel request command will be transmitted on channel 11, 15 and 20,
     GPD_NO_OF_CHANNEL_REQ_PER_CHANNEL times on each channel.  The next channel fields in the
     Channel Request command will be 20 and the second next channel field will be current
     channel 13. The switch will go for a delay of GPD_RX_OFFSET  after transmission on channel 20
     and then goes to Rx mode for GPD_RX_ENABLE_DURATION on channel 20.	On second press,
     channel request command will be transmitted on channel 25, 12 and 13.
      The next channel fields in the Channel Request command will be 13 and the
       second next channel field will be current channel 17 */


    /* Find next channel */
    if(u8NextChannelIndex  >= sizeof(au8ChannelList) )
    {
        /* the next channel index exceeds the channel array size. channel list
         * will be considered as a circular list in this case */
        u8NextChannelIndex = u8NextChannelIndex - sizeof(au8ChannelList);
        if(u8NextChannelIndex >= sizeof(au8ChannelList))
        {
            u8NextChannelIndex = 0;
        }
    }

    if(u8SecondNextChannelIndex >= sizeof(au8ChannelList))
    {
        /* the second next channel index exceeds the channel array size. channel list
         will be considered as a circular list in this case */
        u8SecondNextChannelIndex =  u8SecondNextChannelIndex - sizeof(au8ChannelList);
        if(u8SecondNextChannelIndex >= sizeof(au8ChannelList))
        {
            u8SecondNextChannelIndex = 0;
        }
    }

    /* Now we know next channel and second next channel. Put the same in frame */
    sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength] =
        au8ChannelList[u8NextChannelIndex] - MIN_CHANEL;
    sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength] |=
         (au8ChannelList[u8SecondNextChannelIndex] - MIN_CHANEL)<< 4;
    sGPD_MACFrame.u8PayloadLength++;
    /* secure frame if required */
    for(i=0; i< GPD_NO_OF_CHANNEL_PER_COMM_ATTEMPT; i++)
    {
        /* set the channel on which channel request to be transmitted */
        /* Reset the channel index if it exceeds channel size */
        if (sGPDPersistentData.u8ChannelIndex >= sizeof(au8ChannelList))
        {

            sGPDPersistentData.u8ChannelIndex = 0;
        }

        vSendMACFrame(FALSE);
        sGPDPersistentData.u8Channel  = au8ChannelList[u8NextChannelIndex];
        sGPDPersistentData.u8ChannelIndex++;
#ifdef GPD_SUPPORT_PERSISTENT_DATA
        bAHI_WriteEEPROMBlock(EEPROM_START_SECTOR,
                sizeof(tGPD_PersistantData),
                (uint8 *)&sGPDPersistentData);
#endif

    }
}
#endif

/****************************************************************************
 *
 * NAME: vSendCommissioningCmd
 *
 * DESCRIPTION:
 * Send commissioning command
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/

void vSendCommissioningCmd(void)
{

#ifdef GPD_WITH_SECURITY
#ifndef GPD_SECURITY_LEVEL_FC_1LSB_MIC_2B_NO_ENC
    uint32 u32OutgoingCouter = 0;
#endif

    //uint8 u8GPDEncryptedDataIndex;

#endif
    /* Form MAC Header */
    /*if((sGPDPersistentData.b8CommissioiningStatusBits == CHANNEL_SET_BIT) &&
    (sGPDPersistentData.b8CommissioiningStatusBitsPrevious & COMM_COMP_SET_BIT))
    {
        //send secured commissioning packets if previously commissioned
        GPD_ConstructMACAndNetworkHeader(FALSE, TRUE, TRUE);
    }
    else
    {
        GPD_ConstructMACAndNetworkHeader(FALSE, FALSE, TRUE);
    }*/
    GPD_ConstructMACAndNetworkHeader(FALSE, FALSE, TRUE);
    //u8GPDEncryptedDataIndex = sGPD_MACFrame.u8PayloadLength;


    /* Fill payload: command id */
    sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength++] =
        E_GPD_COMMISSIOING_CMD;

    /*  GPS- Device Id */
    sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength++] =
        GPD_TYPE;

    /* Options */
    sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength] = 0x00;
#ifdef GPD_SUPPORT_PERSISTENT_DATA
    /* MAC sequence number capability: Bit 0 */
    sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength] |= 0x01;
#endif
#ifdef GPD_RX_ENABLE
    /* Rx On Capability : Bit1*/
    sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength] |= 0x01 << 1;
#endif
#ifdef GPD_REQ_PANID
    /* Bit 2,3 reserved, Bit4 PANIdRequest */
    sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength] |= 0x01 << 4;
#endif
#ifdef GPD_FIXED
    /* Fixed location Bit6*/
    sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength] |= 0x01 << 6;
#endif
#ifdef  GPD_RX_AFTER_TX
    sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength] |= 0x01 << 5;
#endif
#ifdef GPD_WITH_SECURITY
    sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength++] |= 0x01 << 7;

    /* Extended Options field */
    /* Bits: 0-1 SecurityLevel capabilities */
    sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength] = GPD_SECURITY_LEVEL;

    /* Bits: 2-4 KeyType */
    sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength] |= sGPDPersistentData.U8GPDSecKeyType << 2;


    /* Bits: 5 GPD Key present */
    sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength] |= 1 << 5;



    /* Bits: 6 GPD Key encryption */
    sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength] |= 1 << 6;


    /* Bits: 7 GPD outgoing counter present */
    sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength] |= 1 << 7;

    sGPD_MACFrame.u8PayloadLength++;

    memcpy(&(sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength]),
                                (uint8 *)&(sGPDPersistentData.sGPDSecKey),
                                16);


    /* encrypt key with tc-lk */
    bEncryptDecyptKey(XCV_REG_AES_SET_MODE_CCM,
            &sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength]);
    sGPD_MACFrame.u8PayloadLength += 4;



    sGPD_MACFrame.u8PayloadLength += 16;

#ifndef GPD_SECURITY_LEVEL_FC_1LSB_MIC_2B_NO_ENC
    u32OutgoingCouter = sGPDPersistentData.U32FrameCounter - 1;
    vMemRevCpy(&sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength],
                        (uint8 *)&u32OutgoingCouter,
                        sizeof(sGPDPersistentData.U32FrameCounter));
#else
        vMemRevCpy(&sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength],
                        (uint8 *)&(sGPD_MACFrame.u8SequenceNum),
                        sizeof(sGPD_MACFrame.u8SequenceNum));
#endif
            sGPD_MACFrame.u8PayloadLength += sizeof(sGPDPersistentData.U32FrameCounter);

#else
    /* since array index starts from 0, increment length once */
    sGPD_MACFrame.u8PayloadLength++;
#endif
/*	if((sGPDPersistentData.b8CommissioiningStatusBits == CHANNEL_SET_BIT) &&
    (sGPDPersistentData.b8CommissioiningStatusBitsPrevious & COMM_COMP_SET_BIT))
    {

        bGPD_SecureFrame(u8GPDEncryptedDataIndex,
                XCV_REG_AES_SET_MODE_CCM,
                (sGPDPersistentData.U32FrameCounter - 1),
                &sGPD_MACFrame);
    }
    else
    {


    bGPD_SecureFrame(u8GPDEncryptedDataIndex,
            XCV_REG_AES_SET_MODE_CCM,
            (sGPDPersistentData.U32FrameCounter - 1),
            &sGPD_MACFrame);

    }*/

#ifdef GPD_RX_ENABLE
    sGPDPersistentData.u8NoOfTransPerChannel = GPD_NO_OF_REQ_BEFORE_RX;
#ifdef DK4
    /* write to eeprom on EEPROM to save sequence number */
    vSendMACFrame(TRUE);
#else
    vSendMACFrame(FALSE);
#endif
#else
    sGPDPersistentData.u8NoOfTransPerChannel =
        GPD_NO_OF_COMMANDS_IN_OPERATIONAL_CHANNEL;
    sGPDPersistentData.b8CommissioiningStatusBits |=
        sGPDPersistentData.b8CommissioiningStatusBits | COMM_COMP_SET_BIT;
    vSendMACFrame(TRUE);
#endif

}

/****************************************************************************
 *
 * NAME: vSendGPDSuccessCmd
 *
 * DESCRIPTION:
 * Send Success command
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
void vSendGPDSuccessCmd(void)
{
#ifdef  GPD_WITH_SECURITY
    uint8 u8GPDEncryptedDataIndex = 0;
#endif
    /* Form MAC Header */

#ifdef GPD_WITH_SECURITY
    GPD_ConstructMACAndNetworkHeader(FALSE, TRUE, FALSE);
#else
    GPD_ConstructMACAndNetworkHeader(FALSE, FALSE, FALSE);
#endif

#ifdef  GPD_WITH_SECURITY
    /* Save index of NWK payload for security addition */
    u8GPDEncryptedDataIndex = sGPD_MACFrame.u8PayloadLength;
#endif
    /* Add  GPD success  command id */
    sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength] =
        E_GPD_SUCCESS_CMD;
    sGPD_MACFrame.u8PayloadLength++;
#ifdef  GPD_WITH_SECURITY
    /* add security */
    bGPD_SecureFrame(u8GPDEncryptedDataIndex,
            XCV_REG_AES_SET_MODE_CCM,
            (sGPDPersistentData.U32FrameCounter - 1),
            &sGPD_MACFrame);
#endif
    /* transmit frame */
    vSendMACFrame(TRUE);

}

/****************************************************************************
 *
 * NAME: vSetModeToDeComm
 *
 * DESCRIPTION:
 * Set Decomissioning mode
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
void vSetModeToDeComm(void )
{
    sGPDPersistentData.b8CommissioiningStatusBits =
            sGPDPersistentData.b8CommissioiningStatusBits | GPD_DE_COMM_MODE_SET_BIT;

}


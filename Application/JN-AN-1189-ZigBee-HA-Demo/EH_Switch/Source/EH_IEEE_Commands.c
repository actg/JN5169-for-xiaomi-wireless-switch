
/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          EH_IEEE_Commands.c
 *
 * AUTHOR:             Rajeena
 *
 * DESCRIPTION:        ZigBee EH Commands implementation
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
#include "aessw_ccm.h"
#include "AHI_AES.h"


/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
/* Macros/Magic numbers for frame creation / processing */
#define SET_EXT_NWK_FRAME_CONTROL                         (0x8C)
#define FRAMETYPE_VERSION                                  (0x0C)

#define MAC_MIN_HEADER_NWK_FC_LEN                         (8)
#define NWK_FRAME_CONTROL_EXT_BIT                          (0x80)

/* Data, no security, no frame pending, No Ack, non intra pan */
#define MAC_FC_FIRST_BYTE                                 (0x01)
/*  destination short address  no source address */
#define MAC_FC_SECOND_BYTE                                 (0x08)

#define MAC_SEQ_NO_INDEX                                 (0x02)

#define MAX_PHY_DATA                                      (30)
#define SRC_ADDRESS_BIT_INDEX_MAC_HEADER                   (0x000C)
#define DST_ADDRESS_BIT_INDEX_MAC_HEADER                   (0x000C)
#define SHORT_ADDRESS_MODE                                 (0x08)
#define LONG_ADDRESS_MODE                                 (0x0C)
#define NO_ADDRESS                                         (0x00)


#define GP_APPID_FOR_IEEE                                (0x02)
#define GP_APP_ID_MASK                                   (0x07)
#define GPD_SEC_CONROL_RESERVED                            (0xC0)
/****************************************************************************/
/***        Type Definitions                                              ***/

/****************************************************************************/
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

/***  Global variable containing the data to be transmitted */
tsMacFrame sGPD_MACFrame;

/***  Global variable containing the data to be received  */
tsMacFrame sGPD_MACReceivedFrame;
/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/

/****************************************************************************/
/***        Public Functions                                              ***/
/****************************************************************************/

/****************************************************************************
 *
 * NAME: bGPD_ParseMACFrame
 *
 * DESCRIPTION:
 * Parses received MAC frame
 *
 * RETURNS:
 * TRUE: Parsing is successful
 * FALSE: Parsing is not successful
 *
 ****************************************************************************/
bool bGPD_ParseMACFrame(bool_t bIgnoreSecurity, ts_ReceivedPayload *psReceivedPayload)
{

    uint8 u8ReceivedSecurityLevel = 0x00;
    uint8 payloadLength = 0;
    uint32 u32RecvdGPDId = 0;
    uint8  u8AppID = 0;

    /* check if we received a GPD frame */
    if(sGPD_MACReceivedFrame.uPayload.au8Byte[payloadLength] & FRAMETYPE_VERSION)
    {
        /*valid GPD frame, process the packet received */

        /* check if frame is protected , check for extended frame control data */
        if(sGPD_MACReceivedFrame.uPayload.au8Byte[payloadLength++] & NWK_FRAME_CONTROL_EXT_BIT )
        {
            u8AppID = sGPD_MACReceivedFrame.uPayload.au8Byte[payloadLength] & GP_APP_ID_MASK;

            /* extended frame control is present , check if frame is security level is supported is same as GPD */
            u8ReceivedSecurityLevel = (sGPD_MACReceivedFrame.uPayload.au8Byte[payloadLength++]) >> 0x03 & 0x03;
            if((u8ReceivedSecurityLevel != GPD_SECURITY_LEVEL) && (bIgnoreSecurity))
            {
                DBG_vPrintf(DBG_DEVICE_SWITCH, "\n GPD_SECURITY_LEVEL mismatch u8ReceivedSecurityLevel=%d \n" ,u8ReceivedSecurityLevel);
                return FALSE;
            }

#ifdef GPD_IEEE_ADDRESS_ENABLE
            if( u8AppID != GP_APPID_FOR_IEEE)
            {
                return FALSE;
            }
#else

            if(u8AppID)
            {
                return FALSE;
            }
#endif

        }
        /* Extract GPD ID from the received packet */
        vMemRevCpy((uint8 *)&u32RecvdGPDId ,
                &sGPD_MACReceivedFrame.uPayload.au8Byte[payloadLength] ,
                sizeof(uint32));
        payloadLength += sizeof(uint32);
#ifndef GPD_IEEE_ADDRESS_ENABLE
        /* assert for GPD ID */
        if(GPD_SOURCE_ID != u32RecvdGPDId)
        {
            DBG_vPrintf(DBG_DEVICE_SWITCH, "\n GPD_SOURCE_ID mismatch, u32RecvdGPDId = %8lx, GPD_SOURCE_ID = %8lx  \n" ,u32RecvdGPDId,GPD_SOURCE_ID);
            return FALSE;
        }
#endif
#ifdef GPD_WITH_SECURITY

        /* Security Check - MAC sequence number should be LSB of frame counter  */
#ifdef GPD_SECURITY_LEVEL_FC_1LSB_MIC_2B_NO_ENC
        {
            if(u8ReceivedSecurityLevel)
            {

                psReceivedPayload->u32ReceivedFrameCounter = sGPD_MACReceivedFrame.uPayload.au8Byte[payloadLength++];

                /* sGPDData.u8MACSeqNo should contain LSB of FC, updated when packet is transmitted  */
                if(((uint8)psReceivedPayload->u32ReceivedFrameCounter < sGPDData.u8MACSeqNo)&&(bIgnoreSecurity))
                {
                    DBG_vPrintf(DBG_DEVICE_SWITCH, "\n u32RecvdFrameCounter mismatch \n" );
                    return FALSE;
                }
            }

        }
#else  /* GPD_SECURITY_LEVEL_FC_1LSB_MIC_2B_NO_ENC */
/* 4 byte Frame counter is present */

        if(u8ReceivedSecurityLevel)
        {
            psReceivedPayload->u32ReceivedFrameCounter = 0;
            psReceivedPayload->u32ReceivedFrameCounter = sGPD_MACReceivedFrame.uPayload.au8Byte[payloadLength + 3] << 24;
            psReceivedPayload->u32ReceivedFrameCounter |= sGPD_MACReceivedFrame.uPayload.au8Byte[payloadLength + 2] << 16;
            psReceivedPayload->u32ReceivedFrameCounter |= sGPD_MACReceivedFrame.uPayload.au8Byte[payloadLength + 1] << 8;
            psReceivedPayload->u32ReceivedFrameCounter |= sGPD_MACReceivedFrame.uPayload.au8Byte[payloadLength ] ;
            if(psReceivedPayload->u32ReceivedFrameCounter > (sGPDPersistentData.U32FrameCounter ))
            {
                DBG_vPrintf(DBG_DEVICE_SWITCH, "\n u32RecvdFrameCounter mismatch u32RecvdFrameCounter = 0x%32lx, self = 0x%32lx \n" ,
                        psReceivedPayload->u32ReceivedFrameCounter,sGPDPersistentData.U32FrameCounter);
                return FALSE;
            }
            payloadLength += 4;

        }
#ifdef GPD_SECURITY_LEVEL_FC_4B_MIC_4B_WITH_ENC
        /* decrypt frame */

        if(u8ReceivedSecurityLevel)
        {
            if(!(bGPD_SecureFrame(payloadLength,XCV_REG_AES_SET_MODE_CCM_D,(psReceivedPayload->u32ReceivedFrameCounter-1),&sGPD_MACReceivedFrame)))
            {
                DBG_vPrintf(DBG_DEVICE_SWITCH, "\n Decryption / MIC of frame failed\n" );
                return FALSE;

            }
        }

#endif  /* GPD_SECURITY_LEVEL_FC_4B_MIC_4B_WITH_ENC */
#endif  /* GPD_SECURITY_LEVEL_FC_1LSB_MIC_2B_NO_ENC */
#endif    /* GPD_WITH_SECURITY */
        DBG_vPrintf(DBG_DEVICE_SWITCH, "\n bGPD_SecureFrame returned true  ,payloadLength =%d\n" , payloadLength);
        /* Frame processing completed, update command Id and payload*/

        psReceivedPayload->u8CmdId = sGPD_MACReceivedFrame.uPayload.au8Byte[payloadLength++];



        psReceivedPayload->pu8CmdPayload = NULL;
        if(sGPD_MACReceivedFrame.u8PayloadLength >= payloadLength)
        {
            psReceivedPayload->pu8CmdPayload = &sGPD_MACReceivedFrame.uPayload.au8Byte[payloadLength];
            psReceivedPayload->u8CmdPayloadLen = sGPD_MACReceivedFrame.u8PayloadLength - payloadLength ;
        }


        return TRUE;

    }
    else
    {
        DBG_vPrintf(DBG_DEVICE_SWITCH, "\n Invalid GPD frame \n" );
        return FALSE;
    }
}

/****************************************************************************
 *
 * NAME: GPD_ConstructMACAndNetworkHeader
 *
 * DESCRIPTION:
 * Constructs MAC and network header
 *
 * RETURNS:
 * None
 *
 ****************************************************************************/
void GPD_ConstructMACAndNetworkHeader(bool_t bAutoCommissioning, bool_t bSecured, bool_t bRxAfterTx)
{
#ifndef GPD_IEEE_ADDRESS_ENABLE
    uint32 u32SourceID = GPD_SOURCE_ID;
#endif
    memset(&sGPD_MACFrame,0,sizeof(sGPD_MACFrame));
    /* Fill MAC header information  */
    sGPD_MACFrame.u16FCF = 0x801;  /* Frame control */
    sGPD_MACFrame.u16DestPAN = sGPDPersistentData.U16Panid;

     /* Broadcast Destination Short Address */
    sGPD_MACFrame.uDestAddr.u16Short = 0xffff;
#ifdef    GPD_IEEE_ADDRESS_ENABLE
    sGPD_MACFrame.u16FCF = 0xC841; /* Frame control */
    /* ... Check for MAC1 */
    sGPD_MACFrame.uSrcAddr.sExt.u32L = *(uint32 *)(MAC_ADDR1_BASE + 4);
    sGPD_MACFrame.uSrcAddr.sExt.u32H = *(uint32 *)(MAC_ADDR1_BASE);
    /* ...If MAC1 is blank, use MAC0 instead */
    if (   (sGPD_MACFrame.uSrcAddr.sExt.u32L == 0xffffffff)
        && (sGPD_MACFrame.uSrcAddr.sExt.u32H == 0xffffffff))
    {
        sGPD_MACFrame.uSrcAddr.sExt.u32L = *(uint32 *)(MAC_ADDR0_BASE + 4);
        sGPD_MACFrame.uSrcAddr.sExt.u32H = *(uint32 *)(MAC_ADDR0_BASE);
    }
#endif

    /* MAC payload */
    sGPD_MACFrame.u8PayloadLength = 0x00;
    /* GPD frame control */
#if (defined( GPD_RX_AFTER_TX )|| defined( GPD_RX_ENABLE )||  defined(GPD_WITH_SECURITY ) || defined(GPD_IEEE_ADDRESS_ENABLE))
    /* GPD frame control  with extended NWK frame control */
#ifndef GPD_AUTOCOMMISSIOINING
    sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength++] =
        SET_EXT_NWK_FRAME_CONTROL ;
#else
    sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength++] =
        SET_EXT_NWK_FRAME_CONTROL | (bAutoCommissioning << 6);
#endif
    #ifdef GPD_WITH_SECURITY
        /* Bit 3-4 represents security and bit5 represents Security key type */
    if(bSecured)
    {
        sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength] = GPD_SECURITY_LEVEL << 3 ;
        if((sGPDPersistentData.U8GPDSecKeyType ==  E_GPD_INDIVIDUAL_KEY )||
                (sGPDPersistentData.U8GPDSecKeyType ==  DERIVED_INDIVIDUAL_GPD_KEY))
        {
            sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength] |= 1 << 5 ;
        }

    }

    #endif /* GPD_WITH_SECURITY */

    #if defined( GPD_RX_AFTER_TX )|| defined(GPD_RX_ENABLE)
    if(bRxAfterTx)
    {
        sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength] |= 1 << 6 ;
    }
    #endif /* ( GPD_RX_AFTER_TX )|| defined(GPD_RX_ENABLE) */

#ifdef GPD_IEEE_ADDRESS_ENABLE
    sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength] |= GP_APPID_FOR_IEEE;
#endif
    sGPD_MACFrame.u8PayloadLength++;

#else /* ( GPD_RX_AFTER_TX )|| defined( GPD_RX_ENABLE )||  defined(GPD_WITH_SECURITY ) */
#ifdef GPD_AUTOCOMMISSIOINING
    /* Frame control : no security, non rx capable, no extended frame control  */
    sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength++] =
        FRAMETYPE_VERSION | (bAutoCommissioning << 6) ;
#else
    sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength++] =
        FRAMETYPE_VERSION  ;
#endif
#endif
#ifndef    GPD_IEEE_ADDRESS_ENABLE
    /* GPD SrcID field */
    vMemRevCpy(&sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength],(uint8 *)&u32SourceID,
            GPD_SOURCE_ID_SIZE);
    sGPD_MACFrame.u8PayloadLength += GPD_SOURCE_ID_SIZE;
#endif
    /*frame counter */

#ifdef  GPD_SECURITY_LEVEL_FC_1LSB_MIC_2B_NO_ENC

        /* If the SecurityLevel is set to GPD_FC_1LSB_MIC_2B_NO_ENC, the Security Frame counter
         * field is not present, the MAC sequence number field carries
         * the 1LSB of the frame counter */
        sGPD_MACFrame.u8SequenceNum =      (uint8 )sGPDPersistentData.U32FrameCounter++;
        DBG_vPrintf(DBG_DEVICE_SWITCH, "\n GPD_FC_1LSB_MIC_2B_NO_ENC  u8SequenceNum as FC \n" );

#else /* GPD_SECURITY_LEVEL_FC_1LSB_MIC_2B_NO_ENC */

#if defined(GPD_SECURITY_LEVEL_FC_4B_MIC_4B_WITH_ENC) || defined(GPD_SECURITY_LEVEL_FC_4B_MIC_4B_NO_ENC)
        /* the Security Frame counter field is present, has the length of 4B, and carries
         *  the full 4B security frame counter */
    if(bSecured)
    {

        vMemRevCpy(&sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength],
                    (uint8 *)&(sGPDPersistentData.U32FrameCounter),
                    sizeof(sGPDPersistentData.U32FrameCounter));
        sGPD_MACFrame.u8PayloadLength += sizeof(sGPDPersistentData.U32FrameCounter);

    }

#endif

#ifndef GPD_SUPPORT_PERSISTENT_DATA
        /* Sequence Number uses random number. Random number generator should be
           finished; wait to be sure */
        while ((u32REG_SysRead(REG_SYS_WK_ES) & REG_SYSCTRL_RNDES_MASK) == 0);
        sGPDData.u8MACSeqNo =  u16AHI_ReadRandomNumber() & 0xFF;
        sGPD_MACFrame.u8SequenceNum = sGPDData.u8MACSeqNo;
    #else
        /* use sequential sequence number */
#if (defined(GPD_SECURITY_LEVEL_FC_4B_MIC_4B_WITH_ENC) || defined(GPD_SECURITY_LEVEL_FC_4B_MIC_4B_NO_ENC))

        sGPD_MACFrame.u8SequenceNum = (uint8)sGPDPersistentData.U32FrameCounter++;

#else
        sGPD_MACFrame.u8SequenceNum = sGPDPersistentData.U8MACSeqNumber++;
#endif
        sGPDData.u8MACSeqNo = sGPD_MACFrame.u8SequenceNum;

    #endif /* GPD_SUPPORT_PERSISTENT_DATA */
#endif

}

/****************************************************************************
 *
 * NAME: GPD_SendSpecificCommand
 *
 * DESCRIPTION:
 * Sends command as given in u8CommandId
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
#if (GPD_TYPE == GP_LEVEL_CONTROL_SWITCH)
void GPD_SendSpecificCommand(uint8 u8CommandId)
{
#ifdef  GPD_WITH_SECURITY
    uint8 u8GPDEncryptedDataIndex = 0;
#endif
    /* Form MAC Header */
#ifdef GPD_WITH_SECURITY
    GPD_ConstructMACAndNetworkHeader(TRUE, TRUE, FALSE);
#else
    GPD_ConstructMACAndNetworkHeader(TRUE, FALSE, FALSE);
#endif
#ifdef  GPD_WITH_SECURITY
    u8GPDEncryptedDataIndex = sGPD_MACFrame.u8PayloadLength;
#endif
    sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength++] =
        u8CommandId;
    /* add payload for commands with payloads */
    switch(u8CommandId)
    {
    case E_GPD_MOVE_UP_CMD: /* fall through , payload same for move up and move down commands*/
    case E_GPD_MOVE_DOWN_CMD:
        sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength++] =
                MOVE_RATE;
        break;
    default:
        break;

    }
#ifdef  GPD_WITH_SECURITY
    /* encrypt payload */
    bGPD_SecureFrame(u8GPDEncryptedDataIndex, XCV_REG_AES_SET_MODE_CCM,(sGPDPersistentData.U32FrameCounter - 1),&sGPD_MACFrame);
#endif
    vSendMACFrame(TRUE);
}
#endif
/****************************************************************************
 *
 * NAME: GPD_SendOperationalCommand
 *
 * DESCRIPTION:
 * Sends on/off/toggle command based on configuration
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
void GPD_SendOperationalCommand(void)
{
#ifdef  GPD_WITH_SECURITY
    uint8 u8GPDEncryptedDataIndex = 0;
#endif
    /* Form MAC Header */
#ifdef GPD_WITH_SECURITY
    GPD_ConstructMACAndNetworkHeader(TRUE, TRUE, FALSE);
#else
    GPD_ConstructMACAndNetworkHeader(TRUE, FALSE, FALSE);
#endif
#ifdef  GPD_WITH_SECURITY
    /* Save the payload starting to add security */
    u8GPDEncryptedDataIndex = sGPD_MACFrame.u8PayloadLength;
#endif

#ifndef GPD_SEND_TOGGLE_CMD
#if(GPD_TYPE         ==    GP_ON_OFF_SWITCH)
    /* On/Off command supported , Send OFF command if previous command is ON, otherwise ON command  */
    if(sGPDPersistentData.b8CommissioiningStatusBits & GPD_PREVIOUS_ON_CMD_SET_BIT)
    {
        /* Send Off command */
        sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength++] =
            E_GPD_OFF_CMD;
        /* Update persistent data so that ON command is sent next time */
        sGPDPersistentData.b8CommissioiningStatusBits &= ~GPD_PREVIOUS_ON_CMD_SET_BIT;

    }
    else
#endif
    {
        /* Send ON command */
        sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength++] =
            E_GPD_ON_CMD;
        /* Update persistent data so that OFF command is sent next time */
        sGPDPersistentData.b8CommissioiningStatusBits |= GPD_PREVIOUS_ON_CMD_SET_BIT;

    }
#endif /* GPD_SEND_TOGGLE_CMD*/
#ifdef GPD_SEND_TOGGLE_CMD
    /* Send Toggle command */
    sGPD_MACFrame.uPayload.au8Byte[sGPD_MACFrame.u8PayloadLength++] =
        E_GPD_TOGGLE_CMD;

#endif /* GPD_SEND_TOGGLE_CMD */
#ifdef  GPD_WITH_SECURITY
    /* encrypt payload */
    bGPD_SecureFrame(u8GPDEncryptedDataIndex, XCV_REG_AES_SET_MODE_CCM,(sGPDPersistentData.U32FrameCounter - 1),&sGPD_MACFrame);
#endif
    /* Transmit command */
    vSendMACFrame(TRUE);
}
/****************************************************************************
 *
 * NAME: bGPD_SecureFrame
 *
 * DESCRIPTION:
 * Encrypts/Decrypts  frame that is to be send/received
 *
 * RETURNS:
 * TRUE if encryption/decrytion is successful
 * FALSE otherwise
 *
 ****************************************************************************/

bool bGPD_SecureFrame(
        uint8             u8GPDEncryptedDataIndex,
        uint8             u8AESmode ,
        uint32             u32FrameCounter,
        tsMacFrame         *psMACFrame)
{
#ifdef GPD_WITH_SECURITY
    AESSW_Block_u aNonce ;
    uint8 auEncryptedOutput[GPD_MAX_PAYLOAD];
    uint8 ua8CheckSum[4];
#ifndef  GPD_IEEE_ADDRESS_ENABLE
    uint32 u32SourceID =GPD_SOURCE_ID;
#endif
    uint8 aData[MAX_PHY_DATA];
    uint8 u8aLen = 0;
    bool_t        bValid;
    bool bEncrypt =  FALSE;
    /* Reset nonce */
    memset(&aNonce, 0, sizeof(aNonce));
    memset(&aData, 0, sizeof(aData));
    memset(&ua8CheckSum, 0, sizeof(ua8CheckSum));

    /* If security level is 1,Header = MAC sequence number || MAC addressing fields ||
     *  NWK Frame Control || Extended NWK  Frame Control || SrcID.
     * other wise Header = NWK Frame Control || Ext NWK Frame Control
     * || SrcID || Frame counter; */
#ifdef GPD_SECURITY_LEVEL_FC_1LSB_MIC_2B_NO_ENC


    /* construct auth data , start from MAC sequence number */
    aData[u8aLen++] =psMACFrame->u8SequenceNum;

    /* pan id */
    vMemRevCpy(&aData[u8aLen],(    uint8*)(&psMACFrame->u16DestPAN) ,
                sizeof(psMACFrame->u16DestPAN) );
    u8aLen += sizeof(psMACFrame->u16DestPAN);


    vMemRevCpy(&aData[u8aLen],(
                    uint8*)(&psMACFrame->uDestAddr.u16Short) ,
                    sizeof(psMACFrame->uDestAddr.u16Short) );
    u8aLen += sizeof(psMACFrame->uDestAddr.u16Short);


    /* Src address */
    if((psMACFrame->u16FCF & SRC_ADDRESS_BIT_INDEX_MAC_HEADER )== SHORT_ADDRESS_MODE)
    {

        vMemRevCpy(&aData[u8aLen],
                        (uint8*)(&psMACFrame->uSrcAddr.u16Short) ,
                        sizeof(psMACFrame->uSrcAddr.u16Short) );
        u8aLen += sizeof(psMACFrame->u16SrcPAN);

    }
    else if((psMACFrame->u16FCF & SRC_ADDRESS_BIT_INDEX_MAC_HEADER )== LONG_ADDRESS_MODE)
    {
        DBG_vPrintf(DBG_DEVICE_SWITCH, "\n Invalid  SRC_ADDRESS_BIT_INDEX_MAC_HEADER LONG_ADDRESS_MODE \n" );
        vMemRevCpy(&aData[u8aLen],(
                            uint8*)(&psMACFrame->uSrcAddr.sExt) ,
                            sizeof(MAC_ExtAddr_s) );
        u8aLen += sizeof(MAC_ExtAddr_s);

    }
    if( psMACFrame->u8PayloadLength < (MAX_PHY_DATA - u8aLen))
    {
        memcpy(&aData[u8aLen],&psMACFrame->uPayload.au8Byte[0],
                psMACFrame->u8PayloadLength );
        u8aLen +=  psMACFrame->u8PayloadLength;
    }
    else
    {
        return FALSE;
    }
    /* to make m of length 0 */
    u8GPDEncryptedDataIndex = psMACFrame->u8PayloadLength;

#endif
#ifdef  GPD_SECURITY_LEVEL_FC_4B_MIC_4B_NO_ENC

    /* copy payload */
    if( psMACFrame->u8PayloadLength < (MAX_PHY_DATA - u8aLen))
    {
        memcpy(&aData[u8aLen],&psMACFrame->uPayload.au8Byte[0],
                psMACFrame->u8PayloadLength );
        u8aLen +=  psMACFrame->u8PayloadLength;
    }
    else
    {
        return FALSE;
    }
    /* to make m of length 0 */
    u8GPDEncryptedDataIndex = psMACFrame->u8PayloadLength;

#endif
#ifdef GPD_SECURITY_LEVEL_FC_4B_MIC_4B_WITH_ENC
    if( psMACFrame->u8PayloadLength < (MAX_PHY_DATA - u8aLen))
        {
            memcpy(&aData[u8aLen],&psMACFrame->uPayload.au8Byte[0],
                     u8GPDEncryptedDataIndex);
            u8aLen +=  u8GPDEncryptedDataIndex;
        }
        else
        {
            return FALSE;
        }
#endif

    /* Construct Nonce., Nonce should be left shifted by 1 as expected by vACI_OptimisedCcmStar */
    /* First eight byte will be source id */
#ifndef  GPD_IEEE_ADDRESS_ENABLE
    if(XCV_REG_AES_SET_MODE_CCM == u8AESmode)
    {

        vMemRevCpy(&aNonce.au8[1],(uint8*)&u32SourceID,sizeof(u32SourceID));
    }
    vMemRevCpy(&aNonce.au8[5],(uint8*)&u32SourceID,sizeof(u32SourceID));
#else
    if(XCV_REG_AES_SET_MODE_CCM == u8AESmode)
    {
        if (((*(uint32 *)(MAC_ADDR1_BASE + 4)) == 0xffffffff)
                && ((*(uint32 *)(MAC_ADDR1_BASE + 4))== 0xffffffff))
        {
            memcpy(&(aNonce.au8[1]),(uint8 *)MAC_ADDR0_BASE,MAC_EXT_ADDR_LEN);
        }
        else
        {
            memcpy(&(aNonce.au8[1]),(uint8 *)MAC_ADDR1_BASE,MAC_EXT_ADDR_LEN);
        }
    }
    else
    {
        memcpy(&(aNonce.au8[1]),(uint8 *)&(psMACFrame->uDestAddr.sExt),MAC_EXT_ADDR_LEN);
    }

#endif
    /*next 4bytes of nonce is 4B frame counter for this GPD, part or whole of which is being transmitted in the GPDF */

#ifdef GPD_SECURITY_LEVEL_FC_1LSB_MIC_2B_NO_ENC
    /* If the SecurityLevel is set to GPD_FC_1LSB_MIC_2B_NO_ENC, the Security Frame counter
     * field is not present, the MAC sequence number field carries
     * the 1LSB of the frame counter */
    aNonce.au8[9] =psMACFrame->u8SequenceNum;

#else
    vMemRevCpy(&aNonce.au8[9],
            (uint8*)&(u32FrameCounter),
            sizeof(u32FrameCounter));
#endif
#ifdef  GPD_IEEE_ADDRESS_ENABLE
    if(XCV_REG_AES_SET_MODE_CCM == u8AESmode)
    {
        aNonce.au8[13] = SECURITY_LEVEL_5 ;
    }
    else
    {
        aNonce.au8[13] = SECURITY_LEVEL_5 | GPD_SEC_CONROL_RESERVED;
    }
#else

    /* security level will be always 5 in nonce */
    aNonce.au8[13] = SECURITY_LEVEL_5;
#endif
    if(XCV_REG_AES_SET_MODE_CCM == u8AESmode)
    {
        memcpy(auEncryptedOutput,&(psMACFrame->uPayload.au8Byte[u8GPDEncryptedDataIndex]),
                    (psMACFrame->u8PayloadLength -u8GPDEncryptedDataIndex ));
    }
    else
    {
        uint8 u8CheckSumStart = psMACFrame->u8PayloadLength - 0x04;

        memcpy(ua8CheckSum,&psMACFrame->uPayload.au8Byte[u8CheckSumStart],
                0x04 );
        psMACFrame->u8PayloadLength -= 0x04;

        memcpy(auEncryptedOutput,&psMACFrame->uPayload.au8Byte[u8GPDEncryptedDataIndex],
                            (psMACFrame->u8PayloadLength -u8GPDEncryptedDataIndex) );

    }


    /* Upload key */
    vACI_CmdWaitBusy();
    if (bACI_WriteKey((tsReg128 *)&sGPDPersistentData.sGPDSecKey) == FALSE)
    {
        /* Failed, so give up */
        DBG_vPrintf(DBG_DEVICE_SWITCH, "\n bACI_WriteKey failed  \n" );
        return FALSE;
    }


    if(u8AESmode == XCV_REG_AES_SET_MODE_CCM)
    {
        bEncrypt = TRUE;
    }

    vACI_OptimisedCcmStar(
            bEncrypt,           /*bEncrypt*/
                   4,                     /* 4B MIC is calculated (irrespective of gpdSecurityLevel). */
                   u8aLen,                 /* u8alength */
                   (psMACFrame->u8PayloadLength - u8GPDEncryptedDataIndex) ,/* u8alength */
                   &aNonce,             /* puNonce */
                   aData,                 /* pau8authenticationData*/
                   auEncryptedOutput,   /* output*/
                   ua8CheckSum,         /* pau8checksumData*/
                  &bValid                 /* pbChecksumVerify*/

            );
#ifdef GPD_SECURITY_LEVEL_FC_4B_MIC_4B_WITH_ENC
    /* copy the encrypted payload */
    memcpy(&psMACFrame->uPayload.au8Byte[u8GPDEncryptedDataIndex ],auEncryptedOutput, (psMACFrame->u8PayloadLength - u8GPDEncryptedDataIndex));


#endif /* GPD_SECURITY_LEVEL_FC_4B_MIC_4B_WITH_ENC */


    /* Add checksum for encryption, compare checksum for decryption  */
    if(XCV_REG_AES_SET_MODE_CCM == u8AESmode)
    {
        /* Now add MIC */
        #ifdef  GPD_SECURITY_LEVEL_FC_1LSB_MIC_2B_NO_ENC
            /* 2 bytes of MIC */
            memcpy(&psMACFrame->uPayload.au8Byte[psMACFrame->u8PayloadLength ],ua8CheckSum, 0x02);
            psMACFrame->u8PayloadLength += 0x02;
        #else /* GPD_SECURITY_LEVEL_FC_1LSB_MIC_2B_NO_ENC */

            /* 4 bytes of MIC */
            memcpy(&psMACFrame->uPayload.au8Byte[psMACFrame->u8PayloadLength ],ua8CheckSum, 0x04);
            psMACFrame->u8PayloadLength += 0x04;
        #endif

    }
    else
    {
        /* return check sum comparison flag*/
        DBG_vPrintf(DBG_DEVICE_SWITCH, "\n bValid== %d \n", bValid );
        return (bValid);

    }


#endif /* GPD_WITH_SECURITY */
    /* Security not supported, return success */
    return TRUE;

}


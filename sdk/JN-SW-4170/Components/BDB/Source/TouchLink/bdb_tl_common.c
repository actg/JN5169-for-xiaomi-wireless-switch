/*###############################################################################
#
# MODULE:      BDB
#
# COMPONENT:   bdb_tl_common.c
#
# AUTHOR:      
#
# DESCRIPTION: BDB Touchlink Common functionality
#              
#
# $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/Components/BDB/Trunk/Source/TouchLink/bdb_tl_common.c $
#
# $Revision: 86833 $
#
# $LastChangedBy: nxp29772 $
#
# $LastChangedDate: 2017-02-16 10:11:22 +0000 (Thu, 16 Feb 2017) $
#
# $Id: bdb_tl_common.c 86833 2017-02-16 10:11:22Z nxp29772 $
#
###############################################################################
#
# This software is owned by NXP B.V. and/or its supplier and is protected
# under applicable copyright laws. All rights are reserved. We grant You,
# and any third parties, a license to use this software solely and
# exclusively on NXP products [NXP Microcontrollers such as JN514x, JN516x, JN517x].
# You, and any third parties must reproduce the copyright and warranty notice 
# and any other legend of ownership on each  copy or partial copy of the software.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
# POSSIBILITY OF SUCH DAMAGE. 
# 
# Copyright NXP B.V. 2015-2016. All rights reserved
#
###############################################################################*/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include <jendefs.h>
#include "bdb_api.h"
#include "bdb_tl.h"
#include "zll_commission.h"
#include "dbg.h"
#include <rnd_pub.h>
#include <string.h>
#include <stdlib.h>

#include "portmacro.h"
#if (defined JENNIC_CHIP_FAMILY_JN518x)
#include "aessw_ccm.h"
#include "fsl_aes.h"
#endif
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#define ADJUST_POWER        TRUE
#define TL_SCAN_LQI_MIN    (100)

#ifndef DEBUG_JOIN
#define TRACE_JOIN            FALSE
#else
#define TRACE_JOIN            TRUE
#endif

#ifndef DEBUG_COMMISSION
#define TRACE_COMMISSION      FALSE
#else
#define TRACE_COMMISSION      TRUE
#endif

#ifndef DEBUG_TL_NEGATIVE
#define TRACE_TL_NEGATIVE       FALSE
#else
#define TRACE_TL_NEGATIVE       TRUE
#endif

#define BLOCK_TO_REG        TRUE
#define REG_TO_BLOCK	    FALSE

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
#if (defined JENNIC_CHIP_FAMILY_JN516x) || (defined JENNIC_CHIP_FAMILY_JN517x)
extern PUBLIC tsReg128 sTLMasterKey;
extern PUBLIC tsReg128 sTLCertKey;
#else
extern PUBLIC uint8 au8TLMasterKey[16];
extern PUBLIC uint8 au8TLCertKey[16];
#endif

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

/****************************************************************************
 *
 * NAME:
 *
 * DESCRIPTION:
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC uint8 BDB_u8TlGetRandomPrimary(void)
{
#ifndef FIXED_CHANNEL
    uint32 u32NoOfBits = 0;
        uint32 u32ChannelMask = BDBC_TL_PRIMARY_CHANNEL_SET;
        uint32 u32RandomBitNo, u32Channel;
        int i;

        for (i=0; i<27; i++)
        {
            if (u32ChannelMask & 0x01)
            {
                u32NoOfBits++;
            }
            u32ChannelMask >>= 1;
        }
        if (u32NoOfBits > 1)
        {
            u32RandomBitNo = RND_u32GetRand( 0, u32NoOfBits);
            u32RandomBitNo++;
        }
        else
        {
            u32RandomBitNo = 1;
        }

        u32NoOfBits = 0;
        u32Channel = 0;
        u32ChannelMask = BDBC_TL_PRIMARY_CHANNEL_SET;
        for (i=0; i<27 && u32NoOfBits != u32RandomBitNo; i++)
        {
            if (u32ChannelMask & 0x01)
            {
                u32NoOfBits++;
                u32Channel = i;
            }

            u32ChannelMask >>= 1;
        }
        DBG_vPrintf(TRACE_JOIN, "PickChannel %d\n", u32Channel);
        return (uint8)u32Channel;


#else
    return FIXED_CHANNEL;
#endif
}

/****************************************************************************
 *
 * NAME: BDB_u8TlNewUpdateID
 *
 * DESCRIPTION: determines which of 2 network update ids is
 * the freshest
 *
 *
 * RETURNS: the frestest nwk update id
 *
 *
 ****************************************************************************/
PUBLIC uint8 BDB_u8TlNewUpdateID(uint8 u8ID1, uint8 u8ID2 )
{
    if ( (abs(u8ID1-u8ID2)) > 200) {
        return MIN(u8ID1, u8ID2);
    }
    return MAX(u8ID1, u8ID2);
}

/****************************************************************************
 *
 * NAME: BDB_u8TlEncryptKey
 *
 * DESCRIPTION: encrypt the nwk key before transmitting it
 *
 *
 * RETURNS:
 *
 *
 ****************************************************************************/
PUBLIC uint8 BDB_u8TlEncryptKey( uint8* au8InData,
                                  uint8* au8OutData,
                                  uint32 u32TransId,
                                  uint32 u32ResponseId,
                                  uint8 u8KeyIndex)
{
    tsReg128 sExpanded;
    tsReg128 sTransportKey;
#if (JENNIC_CHIP_FAMILY == JN517x) && (defined LITTLE_ENDIAN_PROCESSOR)
    AESSW_Block_u sAesBlock;
#endif

    tsReg128 sDataIn,sDataOut;
#if (defined JENNIC_CHIP_FAMILY_JN516x) || (defined JENNIC_CHIP_FAMILY_JN517x)
    sExpanded.u32register0 = u32TransId;
    sExpanded.u32register1 = u32TransId;
    sExpanded.u32register2 = u32ResponseId;
    sExpanded.u32register3 = u32ResponseId;
#else
    sExpanded.u32register0 = u32Reverse(u32TransId);
	sExpanded.u32register1 = u32Reverse(u32TransId);
	sExpanded.u32register2 = u32Reverse(u32ResponseId);
	sExpanded.u32register3 = u32Reverse(u32ResponseId);
#endif

    switch (u8KeyIndex)
    {
        case TL_TEST_KEY_INDEX:
            sTransportKey.u32register0 = 0x50684c69;
            sTransportKey.u32register1 = u32TransId;
            sTransportKey.u32register2 = 0x434c534e;
            sTransportKey.u32register3 = u32ResponseId;
            break;
        case TL_MASTER_KEY_INDEX:
#if (defined JENNIC_CHIP_FAMILY_JN516x) || (defined JENNIC_CHIP_FAMILY_JN517x)
            bACI_ECBencodeStripe( &sTLMasterKey,
                                  TRUE,
                                  &sExpanded,
                                  &sTransportKey);
#else
            AES_SetKey(AES0, au8TLMasterKey, AESSW_BLK_SIZE);
            AES_EncryptEcb(AES0, (uint8*)&sExpanded, (uint8*)&sTransportKey, AESSW_BLK_SIZE);
#endif
            break;
        case TL_CERTIFICATION_KEY_INDEX:
#if (defined JENNIC_CHIP_FAMILY_JN516x) || (defined JENNIC_CHIP_FAMILY_JN517x)
            bACI_ECBencodeStripe( &sTLCertKey,
                                  TRUE,
                                  &sExpanded,
                                  &sTransportKey);
#else
            AES_SetKey(AES0, au8TLCertKey, AESSW_BLK_SIZE);
            AES_EncryptEcb(AES0, (uint8*)&sExpanded, (uint8*)&sTransportKey, AESSW_BLK_SIZE);
#endif
            break;

        default:
            return 3;
            break;
    }
#if (JENNIC_CHIP_FAMILY == JN517x) && (defined LITTLE_ENDIAN_PROCESSOR)
    memcpy( &sAesBlock.au8, au8InData, AES_BLOCK_SIZE);
    vSwipeEndian( &sAesBlock, &sDataIn, BLOCK_TO_REG);
#else
    memcpy(&sDataIn,au8InData,0x10);
#endif
 

    memcpy(&sDataOut,au8OutData,0x10);

#if (defined JENNIC_CHIP_FAMILY_JN516x) || (defined JENNIC_CHIP_FAMILY_JN517x)
    bACI_ECBencodeStripe(&sTransportKey,
                         TRUE,
                         &sDataIn,
                         &sDataOut);
#else
    AES_SetKey(AES0, (uint8*)&sTransportKey, AESSW_BLK_SIZE);
    AES_EncryptEcb(AES0, (uint8*)&sDataIn, (uint8*)&sDataOut, AESSW_BLK_SIZE);
#endif
#if ( JENNIC_CHIP_FAMILY == JN517x) && (defined LITTLE_ENDIAN_PROCESSOR)
    vSwipeEndian( &sAesBlock, &sDataOut, REG_TO_BLOCK);
    memcpy( au8OutData, &sAesBlock.au8, AES_BLOCK_SIZE);
#else
    memcpy(au8OutData,&sDataOut,0x10);

    
#endif


    return 0;

}

/****************************************************************************
 *
 * NAME: BDB_eTlDecryptKey
 *
 * DESCRIPTION: decrypt the received nwk key
 *
 *
 * RETURNS:
 *
 *
 ****************************************************************************/
PUBLIC uint8 BDB_eTlDecryptKey( uint8* au8InData,
                                  uint8* au8OutData,
                                  uint32 u32TransId,
                                  uint32 u32ResponseId,
                                  uint8 u8KeyIndex)
{
    tsReg128 sTransportKey;
    tsReg128 sExpanded;

#if (defined JENNIC_CHIP_FAMILY_JN516x) || (defined JENNIC_CHIP_FAMILY_JN517x)
    sExpanded.u32register0 = u32TransId;
    sExpanded.u32register1 = u32TransId;
    sExpanded.u32register2 = u32ResponseId;
    sExpanded.u32register3 = u32ResponseId;
#else
    sExpanded.u32register0 = u32Reverse(u32TransId);
	sExpanded.u32register1 = u32Reverse(u32TransId);
	sExpanded.u32register2 = u32Reverse(u32ResponseId);
	sExpanded.u32register3 = u32Reverse(u32ResponseId);
#endif

    switch (u8KeyIndex)
    {
        case TL_TEST_KEY_INDEX:
            sTransportKey.u32register0 = 0x50684c69;
            sTransportKey.u32register1 = u32TransId;
            sTransportKey.u32register2 = 0x434c534e;
            sTransportKey.u32register3 = u32ResponseId;
            break;
        case TL_MASTER_KEY_INDEX:
#if (defined JENNIC_CHIP_FAMILY_JN516x) || (defined JENNIC_CHIP_FAMILY_JN517x)
            bACI_ECBencodeStripe( &sTLMasterKey,
                                  TRUE,
                                  &sExpanded,
                                  &sTransportKey);
#else
            AES_SetKey(AES0, au8TLMasterKey, AESSW_BLK_SIZE);
        	AES_EncryptEcb(AES0, (uint8*)&sExpanded, (uint8*)&sTransportKey, AESSW_BLK_SIZE);
#endif
            break;
        case TL_CERTIFICATION_KEY_INDEX:
#if (defined JENNIC_CHIP_FAMILY_JN516x) || (defined JENNIC_CHIP_FAMILY_JN517x)
            bACI_ECBencodeStripe( &sTLCertKey,
                                  TRUE,
                                  &sExpanded,
                                  &sTransportKey);
#else
            AES_SetKey(AES0, au8TLCertKey, AESSW_BLK_SIZE);
        	AES_EncryptEcb(AES0, (uint8*)&sExpanded, (uint8*)&sTransportKey, AESSW_BLK_SIZE);
#endif
            break;

        default:
            DBG_vPrintf(TRACE_COMMISSION, "***Ooops***\n");
            return 3;
            break;
    }

#if ( defined LITTLE_ENDIAN_PROCESSOR) && (defined JENNIC_CHIP_FAMILY_JN517x)
    sTransportKey.u32register0 = u32Reverse(sTransportKey.u32register0);
    sTransportKey.u32register1 = u32Reverse(sTransportKey.u32register1);
    sTransportKey.u32register2 = u32Reverse(sTransportKey.u32register2);
    sTransportKey.u32register3 = u32Reverse(sTransportKey.u32register3);
#endif

#if (defined JENNIC_CHIP_FAMILY_JN516x) || (defined JENNIC_CHIP_FAMILY_JN517x)
    vECB_Decrypt( (uint8*)&sTransportKey,
                  au8InData,
                  au8OutData);
#else
    AES_SetKey(AES0, (uint8*)&sTransportKey, AESSW_BLK_SIZE);
    AES_DecryptEcb(AES0, (uint8*)au8InData, (uint8*)au8OutData, AESSW_BLK_SIZE);
#endif
#ifdef SHOW_KEY
    int i;
    for (i=0; i<16; i++) {
        DBG_vPrintf(TRACE_COMMISSION, "%02x ", au8OutData[i]);
    }
    DBG_vPrintf(TRACE_COMMISSION, "\r\n");
#endif

    return 0;
}

/****************************************************************************
 *
 * NAME: BDB_bTlIsKeySupported
 *
 * DESCRIPTION: tests if the given key index matches a supported key
 *
 *
 * RETURNS: True if Key index is supported
 *
 *
 ****************************************************************************/
PUBLIC bool BDB_bTlIsKeySupported(uint8 u8KeyIndex)
{
    uint16 u16KeyMask = (1<<u8KeyIndex);
    return (bool)(u16KeyMask & TL_SUPPORTED_KEYS);
}

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/


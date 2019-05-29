/*****************************************************************************
 *
 * MODULE: NTAG (NFC Tag Interface)
 *
 * COMPONENT: ntag.h
 *
 * $AUTHOR: Martin Looker$
 *
 * DESCRIPTION:
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_apps/Projects/Components/NTAG/Trunk/Include/ntag.h $
 *
 * $Revision: 17112 $
 *
 * $LastChangedBy: nxp29761 $
 *
 * $LastChangedDate: 2016-04-19 15:34:31 +0100 (Tue, 19 Apr 2016) $
 *
 * $Id: ntag.h 17112 2016-04-19 14:34:31Z nxp29761 $
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
 * Copyright NXP B.V. 2015. All rights reserved
 *
 ****************************************************************************
 * NFC Controller Interface Library (ntag.h)
 ****************************************************************************
 * Features:
 * - Provides an event driven driver for I2C NFC tags
 *   suitable for use with a RTOS.
 * - Tag header data access is read-only.
 * - Tag user data access is read/write.
 *
 * Limitations:
 * - Only processes NFC A Passive Poll Mode Type 2 tags.
 * - Does not process lock bytes, Lock Control TLVs or MemoryControl TLVs.
 ***************************************************************************/
#ifndef NTAG_H_
#define NTAG_H_

/****************************************************************************/
/***        Include Files                                                 ***/
/****************************************************************************/
#include <jendefs.h>

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
/* Functionality defines */
#if (JENNIC_CHIP_FAMILY == JN516x)
#define NTAG_GET_VERSION     TRUE
#else
#define NTAG_GET_VERSION     TRUE
#endif

/* Ntag defines */
#define NTAG_UNKNOWN         0
#define NTAG_NT3H1101        31101
#define NTAG_NT3H1201        31201
#define NTAG_NT3H2111        32111
#define NTAG_NT3H2211        32211

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
/* NTAG Events - Passed to application by library calling the registerd callback function */
typedef enum
{
    E_NTAG_EVENT_ABSENT,            /* Tag has been removed from reader */
    E_NTAG_EVENT_PRESENT,           /* Tag has been presented to reader */
    E_NTAG_EVENT_READ_FAIL,
    E_NTAG_EVENT_READ_OK,
    E_NTAG_EVENT_WRITE_FAIL,
    E_NTAG_EVENT_WRITE_OK,
    E_NTAG_EVENT_READ_REG_FAIL,
    E_NTAG_EVENT_READ_REG_OK,
    E_NTAG_EVENT_WRITE_REG_FAIL,
    E_NTAG_EVENT_WRITE_REG_OK
} teNtagEvent;

/* NTAG Event Callback function */
typedef void (*tprNtagCbEvent)(         /* Called when an event takes place */
        teNtagEvent eNtagEvent,         /* Event raised */
        uint32      u32Address,
        uint32      u32Length,
        uint8       *pu8Data);          /* Event data (NULL if no data) */

/****************************************************************************/
/***        Exported Functions (called by application)                    ***/
/****************************************************************************/
PUBLIC  void        NTAG_vInitialise(   /* Initialise NTAG library */
        uint8       u8Address,          /* Reader I2C address (0xFF for automatic detection of NPC100 or PN7120) */
        bool_t      bLocation,          /* Use alternative JN516x I2C pins */
        uint32      u32FrequencyHz,     /* Prescale value for I2C (63 recommended) */
        uint8       u8InputFd);         /* Input DIO for FD */

PUBLIC  void        NTAG_vRegCbEvent(   /* Register event callback function */
        tprNtagCbEvent prRegCbEvent);   /* Pointer to event callback function */

PUBLIC  void        NTAG_vTick(         /* Call regularly (5ms) to allow NTAG library processing */
        uint32      u32TickMs);         /* Time in ms since previous tick */

PUBLIC  bool_t      NTAG_bRead(         /* Call to read data */
        uint32      u32ReadAddress,     /* Byte address of read */
        uint32      u32ReadLength,      /* Number of bytes to read */
        uint8       *pu8ReadData);      /* Buffer to read data into */

#if NTAG_GET_VERSION
PUBLIC  bool_t      NTAG_bReadVersion(  /* Call to read version data */
        uint32      u32ReadLength,      /* Number of bytes to read */
        uint8       *pu8ReadData);      /* Buffer to read data into */
#endif

PUBLIC  bool_t      NTAG_bWrite(        /* Call to write data */
        uint32      u32WriteAddress,    /* Byte address of write */
        uint32      u32WriteLength,     /* Number of bytes to write */
        uint8       *pu8WriteData);     /* Buffer to write data from */

PUBLIC  bool_t      NTAG_bReadReg(      /* Call to read register */
        uint32      u32ReadAddress,     /* Byte address of read */
        uint32      u32ReadLength,      /* Number of bytes to read */
        uint8       *pu8ReadData);      /* Buffer to read data into (1 byte only) */

PUBLIC  bool_t      NTAG_bWriteReg(     /* Call to write register */
        uint32      u32WriteAddress,    /* Byte address of write */
        uint32      u32WriteLength,     /* Number of bytes to write */
        uint8       *pu8WriteData);     /* Buffer to write data from: [0] = RegMask, [1] = RegValue */

PUBLIC  uint32      NTAG_u32Ntag(void);    /* Returns NTAG type */
PUBLIC  uint32      NTAG_u32Config(void);  /* Returns NTAG config registers address */
PUBLIC  uint32      NTAG_u32Session(void); /* Returns NTAG session registers address */
PUBLIC  uint32      NTAG_u32Sram(void);    /* Returns NTAG SRAM address */
PUBLIC  uint8      *NTAG_pu8Header(void);  /* Returns NTAG header */
#if NTAG_GET_VERSION
PUBLIC  uint8      *NTAG_pu8Version(void); /* Returns NTAG version */
#endif

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

#endif /* NTAG_H_ */
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

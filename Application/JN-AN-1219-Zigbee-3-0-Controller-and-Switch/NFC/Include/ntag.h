/*****************************************************************************
 *
 * MODULE:      NFC
 *
 * COMPONENT:   ntag.h
 *
 * AUTHOR:      Martin Looker
 *
 * DESCRIPTION: NTAG driver for reading and writing data (interface)
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/Components/NFC/Tags/+v1000/Include/ntag.h $
 *
 * $Revision: 83835 $
 *
 * $LastChangedBy: nxp29761 $
 *
 * $LastChangedDate: 2016-10-04 22:29:56 +0800 (Tue, 04 Oct 2016) $
 *
 * $Id: ntag.h 83835 2016-10-04 14:29:56Z nxp29761 $
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
/*!
 * \file  ntag.h
 *
 * \brief NTAG driver for reading and writing data (interface)
 *
 * ntag.h contains low level APIs for reading and writing raw data to the NTAG.
 *
 * The typical set up sequence is as follows:
 *
 * \li NTAG_vInitialise() is called to initialise the hardware.
 * \li NTAG_vRegCbEvent() is called to register the event callback function in the
 * application the library should call to inform the application of NTAG events.
 * APP_NtagCbEvent() is used in these examples.
 * \li NTAG_vTick() should be called regularly (recommended every 5ms) to provide
 * processing time to the library.
 * \li APP_NtagCbEvent() will be called by the library to pass events to the
 * application layer. The E_NTAG_EVENT_ABSENT and E_NTAG_EVENT_PRESENT events will
 * be raised when the NTAG is removed from and placed into an NFC reader's field.
 *
 * A typical sequence to read data is shown below. It is recommended that data is read
 * when the NTAG is removed from a field (as the data in the NTAG may have been altered
 * whilst in the field) in response to the E_NTAG_EVENT_ABSENT event. When the callback
 * function is registered at initialisation the E_NTAG_EVENT_ABSENT will be raised if
 * the NTAG is not in field thus triggering a read of data that may have been changed
 * while the device was powered down.
 *
 * \li NTAG_vTick() is called by the application
 * \li APP_NtagCbEvent(E_NTAG_EVENT_ABSENT) is called in the application
 * \li NTAG_bRead() is called by the application, the byte address and length
 * of data to be read from the NTAG is provided along with a buffer to store the read
 * data in. This call will return TRUE if the request is accepted.
 * \li NTAG_vTick() continues to be called regularly by the application.
 * \li APP_NtagCbEvent(E_NTAG_EVENT_READ_OK) is called in the application if the read
 * is successful. The data read from the NTAG will be in the buffer provided by the call
 * to NTAG_bRead(), this data pointer is also provided as a parameter to APP_NtagCbEvent()
 * \li APP_NtagCbEvent(E_NTAG_EVENT_READ_FAIL) is called in the application if the read
 * is unsuccessful.
 *
 * A typical sequence to write data is shown below. It is recommended that data is written
 * when the NTAG is not in a field (as a reader may be writing whilst in
 * the field). Data may also be written following a successful read as shown below:
 *
 * \li NTAG_vTick() is called by the application
 * \li APP_NtagCbEvent(E_NTAG_EVENT_READ_OK) is called in the application following a
 * successful read.
 * \li NTAG_bWrite() is called by the application, the byte address and length
 * of data to be written to the NTAG is provided along with a buffer containing the data
 * to be written. This call will return TRUE if the request is accepted.
 * \li NTAG_vTick() continues to be called regularly by the application.
 * \li APP_NtagCbEvent(E_NTAG_EVENT_WRITE_OK) is called in the application if the write
 * is successful.
 * \li APP_NtagCbEvent(E_NTAG_EVENT_WRITE_FAIL) is called in the application if the write
 * is unsuccessful.
 *
 * The message sequence chart below shows a sequence of function calls for initialisation,
 * a data read and a data write:
 *
 * \msc
 * APP, NTAG;
 * APP=>NTAG [linecolor="black", textcolor="black", label="NTAG_vInitialise()"];
 * APP=>NTAG [linecolor="black", textcolor="black", label="NTAG_vRegCbEvent(APP_NtagCbEvent)"];
 * APP=>NTAG [linecolor="green", textcolor="green", label="NTAG_vTick()"];
 * APP<=NTAG [linecolor="red",   textcolor="red",   label="APP_NtagCbEvent(E_NTAG_EVENT_ABSENT)"];
 * APP=>NTAG [linecolor="blue",  textcolor="blue",  label="NTAG_bRead()"];
 * APP<<NTAG [linecolor="blue",  textcolor="blue",  label="NTAG_bRead() returns TRUE"];
 * APP>>NTAG [linecolor="red",   textcolor="red",   label="APP_NtagCbEvent() returns"];
 * APP<<NTAG [linecolor="green", textcolor="green", label="NTAG_vTick() returns"];
 * APP:>NTAG [linecolor="green", textcolor="green", label="Regular calls to NTAG_vTick()"];
 * ---       [linecolor="black", textcolor="black", label="until read successful"];
 * APP=>NTAG [linecolor="green", textcolor="green", label="NTAG_vTick()"];
 * APP<=NTAG [linecolor="red",   textcolor="red",   label="APP_NtagCbEvent(E_NTAG_EVENT_READ_OK)"];
 * APP=>NTAG [linecolor="blue",  textcolor="blue",  label="NTAG_bWrite()"];
 * APP<<NTAG [linecolor="blue",  textcolor="blue",  label="NTAG_bWrite() returns TRUE"];
 * APP>>NTAG [linecolor="red",   textcolor="red",   label="APP_NtagCbEvent() returns"];
 * APP<<NTAG [linecolor="green", textcolor="green", label="NTAG_vTick() returns"];
 * APP:>NTAG [linecolor="green", textcolor="green", label="Regular calls to NTAG_vTick()"];
 * ---       [linecolor="black", textcolor="black", label="until write successful"];
 * APP=>NTAG [linecolor="green", textcolor="green", label="NTAG_vTick()"];
 * APP<=NTAG [linecolor="red",   textcolor="red",   label="APP_NtagCbEvent(E_NTAG_EVENT_WRITE_OK)"];
 * APP>>NTAG [linecolor="red",   textcolor="red",   label="APP_NtagCbEvent() returns"];
 * APP<<NTAG [linecolor="green", textcolor="green", label="NTAG_vTick() returns"];
 * \endmsc
 *
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

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
/*! NTAG Events - Passed to application by library calling the registerd callback function */
typedef enum
{
    E_NTAG_EVENT_ABSENT,            /*!< Tag has been removed from reader */
    E_NTAG_EVENT_PRESENT,           /*!< Tag has been presented to reader */
    E_NTAG_EVENT_READ_FAIL,         /*!< Read request failed */
    E_NTAG_EVENT_READ_OK,           /*!< Read request succeeded */
    E_NTAG_EVENT_WRITE_FAIL,        /*!< Write request failed */
    E_NTAG_EVENT_WRITE_OK,          /*!< Write request succeeded */
    E_NTAG_EVENT_READ_REG_FAIL,     /*!< Read register request failed */
    E_NTAG_EVENT_READ_REG_OK,       /*!< Read register request succeeded */
    E_NTAG_EVENT_WRITE_REG_FAIL,    /*!< Write register request failed */
    E_NTAG_EVENT_WRITE_REG_OK       /*!< Write register request succeeded */
} teNtagEvent;

/*! NTAG Event Callback function */
typedef void (*tprNtagCbEvent)(         /* Called when an event takes place */
        teNtagEvent eNtagEvent,         /* Event raised */
        uint32      u32Address,
        uint32      u32Length,
        uint8       *pu8Data);          /* Event data (NULL if no data) */

/****************************************************************************/
/***        Exported Functions (called by application)                    ***/
/****************************************************************************/
/****************************************************************************
 *
 *  NAME:  NTAG_vInitialise
 */
/*! \brief Initialises NTAG data and hardware
 *
 ****************************************************************************/
PUBLIC void NTAG_vInitialise(
       uint8    u8Address,     /*!< Reader I2C address (0xFF for automatic detection) */
       bool_t    bLocation,    /*!< Use alternative I2C pins */
       uint32  u32FrequencyHz, /*!< Frequency in Hz */
       uint8    u8InputFd      /*!< Input DIO for field detect */
       );

/****************************************************************************
 *
 *  NAME:  NTAG_vRegCbEvent
 */
/*! \brief Registers callback for NTAG events
 *
 ****************************************************************************/
PUBLIC void NTAG_vRegCbEvent(
       tprNtagCbEvent prRegCbEvent /*!< Pointer to event callback function */
       );

/****************************************************************************
 *
 *  NAME:  NTAG_vTick
 */
/*! \brief Timer function to drive NTAG processing
 *
 * Should be called regularly, every 5ms is recommended.
 *
 ****************************************************************************/
PUBLIC void NTAG_vTick(
       uint32  u32TickMs /*!< Number of ms since previous call */
       );

/****************************************************************************
 *
 *  NAME:  NTAG_bRead
 */
/*! \brief Requests read of NTAG data
 *
 * If the request is successful the final outcome of the read request is
 * indicated by a call to the NTAG event callback function, along with the
 * data if successful.
 *
 * \retval TRUE  Request accepted
 * \retval FALSE Request failed
 *
 ****************************************************************************/
PUBLIC  bool_t NTAG_bRead(
        uint32    u32ReadAddress, /*!< Byte address of data to read */
        uint32    u32ReadLength,  /*!< Number of bytes to read */
        uint8    *pu8ReadData     /*!< Buffer to read data into */
        );

/****************************************************************************
 *
 *  NAME:  NTAG_bReadVersion
 */
/*! \brief Requests read of NTAG version data
 *
 * If the request is successful the final outcome of the read request is
 * indicated by a call to the NTAG event callback function, along with the
 * data if successful.
 *
 * The version information is always 8 bytes in size the buffer and length
 * needs to be set appropriately.
 *
 * \retval TRUE  Request accepted
 * \retval FALSE Request failed
 *
 ****************************************************************************/
PUBLIC  bool_t NTAG_bReadVersion(
        uint32    u32ReadLength, /*!< Number of bytes to read (minimum 8) */
        uint8    *pu8ReadData    /*!< Buffer to read data into */
        );

/****************************************************************************
 *
 *  NAME:  NTAG_bWrite
 */
/*! \brief Requests write of NTAG data
 *
 * If the request is successful the final outcome of the write request is
 * indicated by a call to the NTAG event callback function, along with the
 * data if successful.
 *
 * \retval TRUE  Request accepted
 * \retval FALSE Request failed
 *
 ****************************************************************************/
PUBLIC  bool_t NTAG_bWrite(
        uint32    u32WriteAddress,  /*!< Byte address of write */
        uint32    u32WriteLength,   /*!< Number of bytes to write */
        uint8    *pu8WriteData      /*!< Buffer to write data from */
        );

/****************************************************************************
 *
 *  NAME:  NTAG_bReadReg
 */
/*! \brief Requests read of NTAG register data
 *
 * If the request is successful the final outcome of the read request is
 * indicated by a call to the NTAG event callback function, along with the
 * data if successful.
 *
 * The register data is always 1 byte, the data length and buffer need to be
 * sized appropriately.
 *
 * \retval      TRUE  Request accepted
 * \retval      FALSE Request failed
 *
 ****************************************************************************/
PUBLIC  bool_t NTAG_bReadReg(
        uint32    u32ReadAddress, /*<! Byte address of read */
        uint32    u32ReadLength,  /*<! Number of bytes to read (minimum 1) */
        uint8    *pu8ReadData     /*<! Buffer to read data into */
        );

/****************************************************************************
 *
 *  NAME:  NTAG_bWriteReg
 */
/*! \brief Requests write of NTAG register data
 *
 * If the request is successful the final outcome of the write request is
 * indicated by a call to the NTAG event callback function, along with the
 * data if successful.
 *
 * The register data is always 2 bytes, the data length and buffer need to be
 * sized appropriately. The first byte specifies a mask of bits to be written
 * to the register, the second byte specifies the values to set the bits
 * specified by the mask.
 *
 * \retval TRUE  Request accepted
 * \retval FALSE Request failed
 *
 ****************************************************************************/
PUBLIC  bool_t NTAG_bWriteReg(
        uint32    u32WriteAddress, /*!< Byte address of write */
        uint32    u32WriteLength,  /*!< Number of bytes to write */
        uint8    *pu8WriteData     /*!< Buffer to write data from: [0] = RegMask, [1] = RegValue */
        );

/****************************************************************************
 *
 *  NAME:  NTAG_u32Ntag
 */
/*! \brief Returns the NTAG model
 *
 * The NTAG_bReadVersion() function must have been called previously in
 * order to detect the NTAG model.
 *
 * \retval NFC_NTAG_UNKNOWN  Unknown NTAG model
 * \retval NFC_NTAG_NT3H1101 NT3H1101 NTAG model
 * \retval NFC_NTAG_NT3H1201 NT3H1201 NTAG model
 * \retval NFC_NTAG_NT3H2111 NT3H2111 NTAG model
 * \retval NFC_NTAG_NT3H2211 NT3H2211 NTAG model
 *
 ****************************************************************************/
PUBLIC  uint32 NTAG_u32Ntag(void);

/****************************************************************************
 *
 *  NAME:  NTAG_u32Config
 */
/*! \brief Returns the byte address of the NTAG's configuration registers
 *
 * The NTAG_bReadVersion() function must have been called previously in
 * order to determine the address.
 *
 * \returns Byte address of configuration registers
 *
 ****************************************************************************/
PUBLIC  uint32 NTAG_u32Config(void);

/****************************************************************************
 *
 *  NAME:        NTAG_u32Session
 */
/*! \brief Returns the byte address of the NTAG's session registers
 *
 * The NTAG_bReadVersion() function must have been called previously in
 * order to determine the address.
 *
 * \returns Byte address of session registers
 *
 ****************************************************************************/
PUBLIC  uint32 NTAG_u32Session(void);

/****************************************************************************
 *
 *  NAME:        NTAG_u32Sram
 */
/*! \brief Returns the byte address of the NTAG's SRAM
 *
 * The NTAG_bReadVersion() function must have been called previously in
 * order to determine the address.
 *
 * \returns Byte address of SRAM
 *
 ****************************************************************************/
PUBLIC  uint32 NTAG_u32Sram(void);

/****************************************************************************
 *
 *  NAME:        NTAG_pu8Header
 */
/*! \brief Returns the 16 header bytes of the NTAG's memory
 *
 * The NTAG_bRead() function must have been called previously with a read of
 * these first 16 bytes from address 0.
 *
 * \returns Pointer to header data
 *
 ****************************************************************************/
PUBLIC  uint8 *NTAG_pu8Header(void);

/****************************************************************************
 *
 *  NAME:        NTAG_pu8Version
 */
/*! \brief Returns the 8 version information bytes for the NTAG
 *
 * The NTAG_bReadVersion() function must have been called previously.
 *
 * \returns Pointer to version data
 *
 ****************************************************************************/
PUBLIC  uint8 *NTAG_pu8Version(void);

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

#endif /* NTAG_H_ */
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

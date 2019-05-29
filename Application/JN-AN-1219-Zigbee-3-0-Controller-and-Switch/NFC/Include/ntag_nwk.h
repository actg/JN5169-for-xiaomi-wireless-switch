/*****************************************************************************
 *
 * MODULE:      NFC
 *
 * COMPONENT:   ntag_nwk.h
 *
 * AUTHOR:      Martin Looker
 *
 * DESCRIPTION: NTAG Network NDEF reading and writing (interface)
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/Components/NFC/Tags/+v1000/Include/ntag_nwk.h $
 *
 * $Revision: 83835 $
 *
 * $LastChangedBy: nxp29761 $
 *
 * $LastChangedDate: 2016-10-04 22:29:56 +0800 (Tue, 04 Oct 2016) $
 *
 * $Id: ntag_nwk.h 83835 2016-10-04 14:29:56Z nxp29761 $
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
 * \file  ntag_nwk.h
 *
 * \brief NTAG Network NDEF reading and writing (interface)
 *
 * ntag_nwk.h contains high level APIs for reading and writing a network NDEF to the NTAG
 * suitable for use in commissioning devices into an IEEE 802.15.4 network.
 *
 * The typical set up sequence is the same for the data APIs (described in ntag.h).
 *
 * A typical sequence to read data is shown below. It is recommended that data is read
 * when the NTAG is removed from a field (as the data in the NTAG may have been altered
 * whilst in the field) in response to the E_NTAG_EVENT_ABSENT event.
 *
 * \li NTAG_vTick() is called by the application
 * \li APP_NtagCbEvent(E_NTAG_EVENT_ABSENT) is called in the application
 * \li NTAG_NWK_eRead() is called by the application, handing control of the low-level
 * data APIs over to the NDEF data module. A pointer to be filled in with the address
 * of the read and a pointer to store the NDEF payload is provided. This function call
 * will return E_NTAG_NWK_READING if the request is successful.
 * \li NTAG_NWK_eTick() should then be called regularly by the application (replacing the
 * calls to NTAG_vTick()).
 * \li If NTAG_NWK_eTick() returns E_NTAG_NWK_READ_OK the read was successful.
 * The NDEF payload and the address of the read will have been placed into the pointers
 * provided in the NTAG_NWK_eRead() call.
 * \li If NTAG_NWK_eTick() returns E_NTAG_NWK_READ_FAIL the read was unsuccessful.
 * \li If the interaction with the NDEF data is finished NTAG_NWK_eStop() should be called
 * followed by a call to NTAG_vRegCbEvent() to reclaim the NTAG event callback, followed by
 * regular calls to NTAG_vTick().
 *
 * A typical sequence to write the NDEF payload data is shown below. It is recommended that data is written
 * when the NTAG is not in a field (as a reader may be writing whilst in
 * the field). Data may also be written following a successful read as shown below:
 *
 * \li NTAG_NWK_eTick() returns E_NTAG_NWK_READ_OK indicating a successful read.
 * \li The NDEF payload contents are updated for writing.
 * \li NTAG_NWK_eWrite() is called by the application, handing control of the low-level
 * data APIs over to the NDEF data module. A pointer with the address
 * of the write and a pointer to NDEF payload data to be written is provided. This function call
 * will return E_NTAG_NWK_WRITING if the request is successful.
 * \li NTAG_NWK_eTick() should then be called regularly by the application (continuing to replace the
 * calls to NTAG_vTick()).
 * \li If NTAG_NWK_eTick() returns E_NTAG_NWK_WRITE_OK the write was successful.
 * \li If NTAG_NWK_eTick() returns E_NTAG_NWK_WRITE_FAIL the write was unsuccessful.
 * \li If the interaction with the NDEF data is finished NTAG_NWK_eStop() should be called
 * followed by a call to NTAG_vRegCbEvent() to reclaim the NTAG event callback, followed by
 * regular calls to NTAG_vTick().
 *
 * The message sequence chart below shows a sequence of function calls for initialisation,
 * an NDEF read and an NDEF write:
 *
 * \msc
 * APP, NTAG, NTAG_NWK;
 * APP=>NTAG     [linecolor="black", textcolor="black", label="NTAG_vInitialise()"];
 * APP=>NTAG     [linecolor="black", textcolor="black", label="NTAG_vRegCbEvent(APP_NtagCbEvent)"];
 * APP=>NTAG     [linecolor="green", textcolor="green", label="NTAG_vTick()"];
 * APP<=NTAG     [linecolor="red",   textcolor="red",   label="APP_NtagCbEvent(E_NTAG_EVENT_ABSENT)"];
 * APP=>NTAG_NWK [linecolor="blue",  textcolor="blue",  label="NTAG_NWK_eRead()"];
 * APP<<NTAG_NWK [linecolor="blue",  textcolor="blue",  label="NTAG_NWK_eRead() returns E_NTAG_NWK_READING"];
 * APP>>NTAG     [linecolor="red",   textcolor="red",   label="APP_NtagCbEvent() returns"];
 * APP<<NTAG     [linecolor="green", textcolor="green", label="NTAG_vTick() returns"];
 * APP=>NTAG_NWK [linecolor="green", textcolor="green", label="NTAG_NWK_eTick()"];
 * APP<<NTAG_NWK [linecolor="green", textcolor="green", label="NTAG_NWK_eTick() returns E_NTAG_NWK_READING"];
 * APP:>NTAG_NWK [linecolor="green", textcolor="green", label="Regular calls to NTAG_NWK_eTick()"];
 * ---           [linecolor="black", textcolor="black", label="until read successful"];
 * APP=>NTAG_NWK [linecolor="green", textcolor="green", label="NTAG_NWK_eTick()"];
 * APP<<NTAG_NWK [linecolor="green", textcolor="green", label="NTAG_NWK_eTick() returns E_NTAG_NWK_READ_OK"];
 * APP=>NTAG_NWK [linecolor="blue",  textcolor="blue",  label="NTAG_NWK_eWrite()"];
 * APP<<NTAG_NWK [linecolor="blue",  textcolor="blue",  label="NTAG_NWK_eWrite() returns E_NTAG_NWK_WRITING"];
 * APP=>NTAG_NWK [linecolor="green", textcolor="green", label="NTAG_NWK_eTick()"];
 * APP<<NTAG_NWK [linecolor="green", textcolor="green", label="NTAG_NWK_eTick() returns E_NTAG_NWK_WRITING"];
 * APP:>NTAG_NWK [linecolor="green", textcolor="green", label="Regular calls to NTAG_NWK_eTick()"];
 * ---           [linecolor="black", textcolor="black", label="until write successful"];
 * APP=>NTAG_NWK [linecolor="green", textcolor="green", label="NTAG_NWK_eTick()"];
 * APP<<NTAG_NWK [linecolor="green", textcolor="green", label="NTAG_NWK_eTick() returns E_NTAG_NWK_WRITE_OK"];
 * APP=>NTAG_NWK [linecolor="blue",  textcolor="blue",  label="NTAG_NWK_eStop()"];
 * APP<<NTAG_NWK [linecolor="blue",  textcolor="blue",  label="NTAG_NWK_eStop() returns E_NTAG_NWK_IDLE"];
 * APP=>NTAG     [linecolor="black", textcolor="black", label="NTAG_vRegCbEvent(APP_NtagCbEvent)"];
 * APP=>NTAG     [linecolor="green", textcolor="green", label="NTAG_vTick()"];
 * APP<=NTAG     [linecolor="red",   textcolor="red",   label="APP_NtagCbEvent(E_NTAG_EVENT_ABSENT)"];
 * APP>>NTAG     [linecolor="red",   textcolor="red",   label="APP_NtagCbEvent() returns"];
 * APP<<NTAG     [linecolor="green", textcolor="green", label="NTAG_vTick() returns"];
 * APP:>NTAG     [linecolor="green", textcolor="green", label="Regular calls to NTAG_vTick()"];
 * \endmsc
 *
 ***************************************************************************/
#ifndef NTAG_NWK_H_
#define NTAG_NWK_H_

/****************************************************************************/
/***        Include Files                                                 ***/
/****************************************************************************/
#include <jendefs.h>
#include "nfc_nwk.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
/*! NTAG NWK status type */
typedef enum
{
    E_NTAG_NWK_IDLE,        /*!< NTAG NWK processing is idle */
    E_NTAG_NWK_READING,     /*!< NTAG NWK is reading data */
    E_NTAG_NWK_READ_FAIL,   /*!< NTAG NWK read has failed */
    E_NTAG_NWK_READ_OK,     /*!< NTAG NWK read was successful */
    E_NTAG_NWK_WRITING,     /*!< NTAG NWK is writing data */
    E_NTAG_NWK_WRITE_FAIL,  /*!< NTAG NWK write has failed */
    E_NTAG_NWK_WRITE_OK     /*!< NTAG NWK write was successful */
} teNtagNwkStatus;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
/****************************************************************************
 *
 *  NAME:  NTAG_NWK_eRead
 */
/*! \brief Requests read of NTAG NWK NDEF data
 *
 * If the request is successful the final outcome of the read request is
 * returned by NTAG_NWK_eTick() returning a status of E_NTAG_NWK_READ_OK.
 * The byte address the NTAG NWK NDEF was read from is placed in the
 * pu32ReadAddress pointer and the payload data in the psNfcNwkPayloadStart
 * pointer.
 *
 * When the request is accepted the NTAG event callback function, set by
 * NTAG_vRegCbEvent(), is overridden to allow the NTAG NWK code to process
 * NTAG events. When the request completes NTAG_NWK_eStop() should be called
 * to end the processing and the NTAG event callback function can be reclaimed
 * by the application.
 *
 * \retval E_NTAG_NWK_READING   Request accepted
 * \retval E_NTAG_NWK_READ_FAIL Request failed
 *
 ****************************************************************************/
PUBLIC teNtagNwkStatus NTAG_NWK_eRead(
    uint32          *pu32ReadAddress,         /*!< Pointer where byte address of NTAG NWK NDEF is placed if successful */
    tsNfcNwkPayload   *psNfcNwkPayloadStart   /*!< Pointer where NTAG NWK NDEF payload data is placed if successful */
    );

/****************************************************************************
 *
 *  NAME:  NTAG_NWK_eWrite
 */
/*! \brief Requests write of NTAG NWK NDEF data
 *
 * If the request is successful the final outcome of the write request is
 * returned by NTAG_NWK_eTick() returning a status of E_NTAG_NWK_WRITE_OK.
 * The byte address to write NTAG NWK NDEF should be in the
 * pu32ReadAddress pointer and the payload data in the psNfcNwkPayloadStart
 * pointer.
 *
 * When the request is accepted the NTAG event callback function, set by
 * NTAG_vRegCbEvent(), is overridden to allow the NTAG NWK code to process
 * NTAG events. When the request completes NTAG_NWK_eStop() should be called
 * to end the processing and the NTAG event callback function can be reclaimed
 * by the application.
 *
 * \retval E_NTAG_NWK_WRITING    Request accepted
 * \retval E_NTAG_NWK_WRITE_FAIL Request failed
 *
 ****************************************************************************/
PUBLIC teNtagNwkStatus NTAG_NWK_eWrite(
    uint32          *pu32WriteAddress,      /*!< Pointer to byte address to write data */
    tsNfcNwkPayload   *psNfcNwkPayloadStart /*!< Pointer to payload to write */
    );

/****************************************************************************
 *
 *  NAME:  NTAG_NWK_eStop
 */
/*! \brief Stops processing of NTAG NWK NDEF data
 *
 * This function should be called when the processing of the NTAG NWK NDEF
 * data is complete, the NTAG event callback function can be reclaimed by the
 * application after calling NTAG_NWK_eStop().
 *
 * \retval E_NTAG_NWK_IDLE NTAG_NWK NDEF processing is idle
 *
 ****************************************************************************/
PUBLIC teNtagNwkStatus NTAG_NWK_eStop(void);

/****************************************************************************
 *
 *  NAME:  NTAG_NWK_eStatus
 */
/*! \brief Returns the status of the NTAG NWK NDEF processing
 *
 * \returns Status of NTAG NWK NDEF processing
 *
 ****************************************************************************/
PUBLIC teNtagNwkStatus NTAG_NWK_eStatus(void);

/****************************************************************************
 *
 *  NAME:  NTAG_NWK_eTick
 */
/*! \brief Timer function to drive NTAG NWK NDEF processing
 *
 * Should be called regularly, every 5ms is recommended.
 *
 * \warning This function calls NTAG_bTick() internally, there is no need to
 * call NTAG_bTick() from the application when NTAG NWK NDEF processing is
 * taking place.
 *
 * \returns Status of NTAG NWK NDEF processing
 *
 ****************************************************************************/
PUBLIC teNtagNwkStatus NTAG_NWK_eTick(
       uint32                 u32TickMs /*!< Time in ms since previous call */
    );

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

#endif /* NTAG_NWK_H_ */
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

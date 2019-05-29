/*****************************************************************************
 *
 * MODULE:      NFC
 *
 * COMPONENT:   nci_nwk.h
 *
 * AUTHOR:      Martin Looker
 *
 * DESCRIPTION: NCI Network NDEF reading and writing (interface)
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/Components/NFC/Tags/+v1000/Include/nci_nwk.h $
 *
 * $Revision: 83835 $
 *
 * $LastChangedBy: nxp29761 $
 *
 * $LastChangedDate: 2016-10-04 22:29:56 +0800 (Tue, 04 Oct 2016) $
 *
 * $Id: nci_nwk.h 83835 2016-10-04 14:29:56Z nxp29761 $
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
 * \file   nci_nwk.h
 *
 * \brief NCI Network NDEF reading and writing (interface)
 *
 * nci_nwk.h contains high level APIs for reading and writing a network NDEF to the NTAGs
 * placed in the reader's field which is suitable for use in commissioning devices into
 * IEEE 802.15.4 based networks.
 *
 * The typical set up sequence is the same for the data APIs (described in nci.h).
 *
 * A typical sequence to read data is shown below. Data must be read
 * when the NTAG is placed into the field usually
 * in response to the E_NCI_EVENT_PRESENT event.
 *
 * \li NCI_vTick() is called by the application
 * \li APP_NciCbEvent(E_NCI_EVENT_PRESENT) is called in the application when an NTAG
 * is placed into the field.
 * \li NCI_NWK_eRead() is called by the application, handing control of the low-level
 * data APIs over to the NDEF data module. A pointer to be filled in with the address
 * of the read and a pointer to store the NDEF payload is provided. This function call
 * will return E_NCI_NWK_READING if the request is successful.
 * \li NCI_NWK_eTick() should then be called regularly by the application (replacing the
 * calls to NCI_vTick()).
 * \li If NCI_NWK_eTick() returns E_NCI_NWK_READ_OK the read was successful.
 * The NDEF payload and the address of the read will have been placed into the pointers
 * provided in the NCI_NWK_eRead() call.
 * \li If NCI_NWK_eTick() returns E_NCI_NWK_READ_FAIL the read was unsuccessful.
 * \li If the interaction with the NDEF data is finished NCI_NWK_eStop() should be called
 * followed by a call to NCI_vRegCbEvent() to reclaim the NCI event callback, followed by
 * regular calls to NCI_vTick(). NCI_NWK_eStop() includes a call to NCI_bEnd().
 *
 * A typical sequence to write the NDEF payload data is shown below. Data must be written
 * when the NTAG is in the field.
 * Data may be written following a successful read as shown below:
 *
 * \li NCI_NWK_eTick() returns E_NCI_NWK_READ_OK indicating a successful read.
 * \li The NDEF payload contents are updated for writing.
 * \li NCI_NWK_eWrite() is called by the application, handing control of the low-level
 * data APIs over to the NDEF data module. A pointer with the address
 * of the write and a pointer to NDEF payload data to be written is provided. This function call
 * will return E_NCI_NWK_WRITING if the request is successful.
 * \li NCI_NWK_eTick() should then be called regularly by the application (continuing to replace the
 * calls to NCI_vTick()).
 * \li If NCI_NWK_eTick() returns E_NCI_NWK_WRITE_OK the write was successful.
 * \li If NCI_NWK_eTick() returns E_NCI_NWK_WRITE_FAIL the write was unsuccessful.
 * \li If the interaction with the NDEF data is finished NCI_NWK_eStop() should be called
 * followed by a call to NCI_vRegCbEvent() to reclaim the NTAG event callback, followed by
 * regular calls to NCI_vTick(). NCI_NWK_eStop() includes a call to NCI_bEnd().
 *
 * The message sequence chart below shows a sequence of function calls for initialisation,
 * an NDEF read and an NDEF write:
 *
 * \msc
 * APP, NCI, NCI_NWK;
 * APP=>NCI     [linecolor="black", textcolor="black", label="NCI_vInitialise()"];
 * APP=>NCI     [linecolor="black", textcolor="black", label="NCI_vRegCbEvent(APP_NciCbEvent)"];
 * APP=>NCI     [linecolor="green", textcolor="green", label="NCI_vTick()"];
 * APP<=NCI     [linecolor="red",   textcolor="red",   label="APP_NciCbEvent(E_NCI_EVENT_ABSENT)"];
 * APP>>NCI     [linecolor="red",   textcolor="red",   label="APP_NciCbEvent() returns"];
 * APP<<NCI     [linecolor="green", textcolor="green", label="NCI_vTick() returns"];
 * APP:>NCI     [linecolor="green", textcolor="green", label="Regular calls to NCI_vTick()"];
 * ---          [linecolor="black", textcolor="black", label="until NTAG placed in field"];
 * APP=>NCI     [linecolor="green", textcolor="green", label="NCI_vTick()"];
 * APP<=NCI     [linecolor="red",   textcolor="red",   label="APP_NciCbEvent(E_NCI_EVENT_PRESENT)"];
 * APP=>NCI_NWK [linecolor="blue",  textcolor="blue",  label="NCI_NWK_eRead()"];
 * APP<<NCI_NWK [linecolor="blue",  textcolor="blue",  label="NCI_NWK_eRead() returns E_NCI_NWK_READING"];
 * APP>>NCI     [linecolor="red",   textcolor="red",   label="APP_NciCbEvent() returns"];
 * APP<<NCI     [linecolor="green", textcolor="green", label="NCI_vTick() returns"];
 * APP=>NCI_NWK [linecolor="green", textcolor="green", label="NCI_NWK_eTick()"];
 * APP<<NCI_NWK [linecolor="green", textcolor="green", label="NCI_NWK_eTick() returns E_NCI_NWK_READING"];
 * APP:>NCI_NWK [linecolor="green", textcolor="green", label="Regular calls to NCI_NWK_eTick()"];
 * ---          [linecolor="black", textcolor="black", label="until read successful"];
 * APP=>NCI_NWK [linecolor="green", textcolor="green", label="NCI_NWK_eTick()"];
 * APP<<NCI_NWK [linecolor="green", textcolor="green", label="NCI_NWK_eTick() returns E_NCI_NWK_READ_OK"];
 * APP=>NCI_NWK [linecolor="blue",  textcolor="blue",  label="NCI_NWK_eWrite()"];
 * APP<<NCI_NWK [linecolor="blue",  textcolor="blue",  label="NCI_NWK_eWrite() returns E_NCI_NWK_WRITING"];
 * APP=>NCI_NWK [linecolor="green", textcolor="green", label="NCI_NWK_eTick()"];
 * APP<<NCI_NWK [linecolor="green", textcolor="green", label="NCI_NWK_eTick() returns E_NCI_NWK_WRITING"];
 * APP:>NCI_NWK [linecolor="green", textcolor="green", label="Regular calls to NCI_NWK_eTick()"];
 * ---          [linecolor="black", textcolor="black", label="until write successful"];
 * APP=>NCI_NWK [linecolor="green", textcolor="green", label="NCI_NWK_eTick()"];
 * APP<<NCI_NWK [linecolor="green", textcolor="green", label="NCI_NWK_eTick() returns E_NCI_NWK_WRITE_OK"];
 * APP=>NCI_NWK [linecolor="blue",  textcolor="blue",  label="NCI_NWK_eStop()"];
 * APP<<NCI_NWK [linecolor="blue",  textcolor="blue",  label="NCI_NWK_eStop() returns E_NCI_NWK_IDLE"];
 * APP=>NCI     [linecolor="black", textcolor="black", label="NCI_vRegCbEvent(APP_NciCbEvent)"];
 * APP=>NCI     [linecolor="green", textcolor="green", label="NCI_vTick()"];
 * APP<=NCI     [linecolor="red",   textcolor="red",   label="APP_NciCbEvent(E_NCI_EVENT_PRESENT)"];
 * APP>>NCI     [linecolor="red",   textcolor="red",   label="APP_NciCbEvent() returns"];
 * APP<<NCI     [linecolor="green", textcolor="green", label="NCI_vTick() returns"];
 * APP:>NCI     [linecolor="green", textcolor="green", label="Regular calls to NCI_vTick()"];
 * ---          [linecolor="black", textcolor="black", label="until NTAG removed from field"];
 * APP=>NCI     [linecolor="green", textcolor="green", label="NCI_vTick()"];
 * APP<=NCI     [linecolor="red",   textcolor="red",   label="APP_NciCbEvent(E_NCI_EVENT_ABSENT)"];
 * APP>>NCI     [linecolor="red",   textcolor="red",   label="APP_NciCbEvent() returns"];
 * APP<<NCI     [linecolor="green", textcolor="green", label="NCI_vTick() returns"];
 * \endmsc
 *
 ***************************************************************************/
#ifndef NCI_NWK_H_
#define NCI_NWK_H_

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
/*! NCI NWK status type */
typedef enum
{
    E_NCI_NWK_IDLE,        /*!< NCI NWK processing is idle */
    E_NCI_NWK_READING,     /*!< NCI NWK is reading data */
    E_NCI_NWK_READ_FAIL,   /*!< NCI NWK read has failed */
    E_NCI_NWK_READ_OK,     /*!< NCI NWK read was successful */
    E_NCI_NWK_WRITING,     /*!< NCI NWK is writing data */
    E_NCI_NWK_WRITE_FAIL,  /*!< NCI NWK write has failed */
    E_NCI_NWK_WRITE_OK     /*!< NCI NWK write was successful */
} teNciNwkStatus;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
/****************************************************************************
 *
 *  NAME:  NCI_NWK_eRead
 */
/*! \brief Requests read of NWK NDEF data from an NTAG in the reader's field
 *
 * If the request is successful the final outcome of the read request is
 * returned by NCI_NWK_eTick() returning a status of E_NCI_NWK_READ_OK.
 * The byte address the NWK NDEF was read from is placed in the
 * pu32ReadAddress pointer and the payload data in the psNfcNwkPayloadStart
 * pointer.
 *
 * When the request is accepted the NCI event callback function, set by
 * NCI_vRegCbEvent(), is overridden to allow the NCI NWK code to process
 * NCI events. When the request completes NCI_NWK_eStop() should be called
 * to end the processing and the NTAG event callback function can be reclaimed
 * by the application.
 *
 * \retval E_NCI_NWK_READING   Request accepted
 * \retval E_NCI_NWK_READ_FAIL Request failed
 *
 ****************************************************************************/
PUBLIC teNciNwkStatus NCI_NWK_eRead(
    uint32          *pu32ReadAddress,         /*!< Pointer where byte address of NTAG NWK NDEF is placed if successful */
    tsNfcNwkPayload   *psNfcNwkPayloadStart   /*!< Pointer where NTAG NWK NDEF payload data is placed if successful */
    );

/****************************************************************************
 *
 *  NAME:  NCI_NWK_eWrite
 */
/*! \brief Requests write of NWK NDEF data to an NTAG in the reader's field
 *
 * If the request is successful the final outcome of the write request is
 * returned by NCI_NWK_eTick() returning a status of E_NCI_NWK_WRITE_OK.
 * The byte address to write the NWK NDEF record should be in the
 * pu32ReadAddress pointer and the payload data in the psNfcNwkPayloadStart
 * pointer.
 *
 * When the request is accepted the NCI event callback function, set by
 * NCI_vRegCbEvent(), is overridden to allow the NCI NWK code to process
 * NCI events. When the request completes NCI_NWK_eStop() should be called
 * to end the processing and the NCI event callback function can be reclaimed
 * by the application.
 *
 * \retval E_NCI_NWK_WRITING    Request accepted
 * \retval E_NCI_NWK_WRITE_FAIL Request failed
 *
 ****************************************************************************/
PUBLIC teNciNwkStatus NCI_NWK_eWrite(
    uint32          *pu32WriteAddress,      /*!< Pointer to byte address to write data */
    tsNfcNwkPayload   *psNfcNwkPayloadStart /*!< Pointer to payload to write */
    );

/****************************************************************************
 *
 *  NAME:  NCI_NWK_eStop
 */
/*! \brief Stops processing of NCI NWK NDEF data
 *
 * This function should be called when the processing of the NCI NWK NDEF
 * data is complete, the NCI event callback function can be reclaimed by the
 * application after calling NCI_NWK_eStop().
 *
 * \retval E_NCI_NWK_IDLE NCI_NWK NDEF processing is idle
 *
 ****************************************************************************/
PUBLIC teNciNwkStatus NCI_NWK_eStop(void);

/****************************************************************************
 *
 *  NAME:  NCI_NWK_eStatus
 */
/*! \brief Returns the status of the NCI NWK NDEF processing
 *
 * \returns Status of NCI NWK NDEF processing
 *
 ****************************************************************************/
PUBLIC teNciNwkStatus NCI_NWK_eStatus(void);

/****************************************************************************
 *
 *  NAME:  NCI_NWK_eTick
 */
/*! \brief Timer function to drive NCI NWK NDEF processing
 *
 * Should be called regularly, every 5ms is recommended.
 *
 * \warning This function calls NCI_bTick() internally, there is no need to
 * call NCI_bTick() from the application when NCI NWK NDEF processing is
 * taking place.
 *
 * \returns Status of NCI NWK NDEF processing
 *
 ****************************************************************************/
PUBLIC teNciNwkStatus NCI_NWK_eTick(
       uint32               u32TickMs /*!< Time in ms since previous call */
    );

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

#endif /* NCI_NWK_H_ */
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

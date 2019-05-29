/****************************************************************************
 *
 * MODULE:             ZCL Reporting
 *
 * COMPONENT:          $RCSfile $
 *
 * AUTHOR:             Wayne Ellis
 *
 * DESCRIPTION:        ZCL Reporting
 *
 * $HeadURL: $
 *
 * $Revision: $
 *
 * $LastChangedBy: $
 *
 * $LastChangedDate: $
 *
 * $Id: $
 *
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
 ****************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#include <jendefs.h>
#include <string.h>
#include <stdlib.h>

#include "zcl_common.h"

#include "zcl.h"
#include "zcl_customcommand.h"

#include "zcl_internal.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

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

/****************************************************************************/
/***        Public Functions                                              ***/
/****************************************************************************/

/****************************************************************************
 **
 ** NAME:       vZCL_SetPointerToStringStorage
 **
 ** DESCRIPTION:
 ** Set the string report pointer to right location and sets the maximum length
 **
 ** PARAMETERS:                 Name                            Usage
 ** teZCL_ZCLAttributeType      eAttributeDataType              Data Type
 ** tsZCL_ReportRecord          *psAttributeReportingRecord     Pointer to reporting record
 ** uint8                       *pu8PointerToStringStorage      Pointer to String Storage
 **
 ** RETURN:
 ** void
 **
 ****************************************************************************/

PUBLIC  void vZCL_SetPointerToStringStorage(
                     teZCL_ZCLAttributeType       eAttributeDataType,
                     tsZCL_ReportRecord           *psAttributeReportingRecord,
                     uint8                        *pu8PointerToStringStorage)
{
    // If strings are to be used then storage will need to be returned
    switch(eAttributeDataType)
    {
        case(E_ZCL_OSTRING):
            psAttributeReportingRecord->uAttributeStorage.sOctetString.u8MaxLength = ZCL_ATTRIBUTE_REPORT_STRING_MAXIMUM_SIZE;    
            psAttributeReportingRecord->uAttributeStorage.sOctetString.pu8Data = pu8PointerToStringStorage;
        break;

        case(E_ZCL_CSTRING):
            psAttributeReportingRecord->uAttributeStorage.sCharacterString.u8MaxLength = ZCL_ATTRIBUTE_REPORT_STRING_MAXIMUM_SIZE;          
            psAttributeReportingRecord->uAttributeStorage.sCharacterString.pu8Data = pu8PointerToStringStorage;
        break;

        case(E_ZCL_LOSTRING):
            psAttributeReportingRecord->uAttributeStorage.sLongOctetString.u16MaxLength = ZCL_ATTRIBUTE_REPORT_STRING_MAXIMUM_SIZE;          
            psAttributeReportingRecord->uAttributeStorage.sLongOctetString.pu8Data = pu8PointerToStringStorage;
        break;

        case(E_ZCL_LCSTRING):
            psAttributeReportingRecord->uAttributeStorage.sLongCharacterString.u16MaxLength = ZCL_ATTRIBUTE_REPORT_STRING_MAXIMUM_SIZE; 
            psAttributeReportingRecord->uAttributeStorage.sLongCharacterString.pu8Data = pu8PointerToStringStorage;
        break;       

        default:
            break;
    }
}
/****************************************************************************
 **
 ** NAME:       pu8ZCL_Getpu8PointerToStringStorage
 **
 ** DESCRIPTION:
 ** Get the pointer for the string report storage
 **
 ** PARAMETERS:                 Name                            Usage
 ** teZCL_ZCLAttributeType      eAttributeDataType              Data Type
 ** tsZCL_ReportRecord          *psAttributeReportingRecord     Pointer to reporting record
 **
 ** RETURN:
 ** uint8 *
 **
 ****************************************************************************/

PUBLIC  uint8* pu8ZCL_GetPointerToStringStorage(
                     teZCL_ZCLAttributeType       eAttributeDataType,
                     tsZCL_ReportRecord           *psAttributeReportingRecord)
{
    // If strings are to be used then storage will need to be returned
    switch(eAttributeDataType)
    {
        case(E_ZCL_OSTRING):
            return psAttributeReportingRecord->uAttributeStorage.sOctetString.pu8Data;
        break;

        case(E_ZCL_CSTRING):
            return psAttributeReportingRecord->uAttributeStorage.sCharacterString.pu8Data;
        break;

        case(E_ZCL_LOSTRING):
            return psAttributeReportingRecord->uAttributeStorage.sLongOctetString.pu8Data;
        break;

        case(E_ZCL_LCSTRING):
            return psAttributeReportingRecord->uAttributeStorage.sLongCharacterString.pu8Data;
        break;       

        default:
            break;
    }
    return NULL;
}

/****************************************************************************
 **
 ** NAME:       vZCL_AllocateSpaceForStringReports
 **
 ** DESCRIPTION:
 ** Allocates the space for the string attribute
 **
 ** PARAMETERS:                 Name                            Usage
 ** teZCL_ZCLAttributeType      eAttributeDataType              Data Type
 ** tsZCL_ReportRecord          *psAttributeReportingRecord     Pointer to reporting record
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/

PUBLIC void vZCL_AllocateSpaceForStringReports(
                     teZCL_ZCLAttributeType       eAttributeDataType,
                     tsZCL_ReportRecord           *psAttributeReportingRecord)
{
    // If strings are to be used then storage will need allocating and assigning to
    // psAttributeReportingRecord->uAttributeStorage.sLongCharacterString.pu8Data
    switch(eAttributeDataType)
    {
        case(E_ZCL_OSTRING):
            psAttributeReportingRecord->uAttributeStorage.sOctetString.u8MaxLength = ZCL_ATTRIBUTE_REPORT_STRING_MAXIMUM_SIZE;
            vZCL_HeapAlloc(psAttributeReportingRecord->uAttributeStorage.sOctetString.pu8Data, uint8, ZCL_ATTRIBUTE_REPORT_STRING_MAXIMUM_SIZE, TRUE, "String_Record");
        break;

        case(E_ZCL_CSTRING):
            psAttributeReportingRecord->uAttributeStorage.sCharacterString.u8MaxLength = ZCL_ATTRIBUTE_REPORT_STRING_MAXIMUM_SIZE;
            vZCL_HeapAlloc(psAttributeReportingRecord->uAttributeStorage.sCharacterString.pu8Data, uint8, ZCL_ATTRIBUTE_REPORT_STRING_MAXIMUM_SIZE, TRUE, "String_Record");
        break;

        case(E_ZCL_LOSTRING):
            psAttributeReportingRecord->uAttributeStorage.sLongOctetString.u16MaxLength = ZCL_ATTRIBUTE_REPORT_STRING_MAXIMUM_SIZE;
            vZCL_HeapAlloc(psAttributeReportingRecord->uAttributeStorage.sLongOctetString.pu8Data, uint8, ZCL_ATTRIBUTE_REPORT_STRING_MAXIMUM_SIZE, TRUE, "String_Record");
        break;

        case(E_ZCL_LCSTRING):
            psAttributeReportingRecord->uAttributeStorage.sLongCharacterString.u16MaxLength = ZCL_ATTRIBUTE_REPORT_STRING_MAXIMUM_SIZE;
            vZCL_HeapAlloc(psAttributeReportingRecord->uAttributeStorage.sLongCharacterString.pu8Data, uint8, ZCL_ATTRIBUTE_REPORT_STRING_MAXIMUM_SIZE, TRUE, "String_Record");
        break;       

        default:
               break;
    }
}
/****************************************************************************
 **
 ** NAME:       eZCL_CheckForStringAttributeChange
 **
 ** DESCRIPTION:
 **
 ** PARAMETERS:                 Name                            Usage
 ** void                        *pvStringToStore                String
 ** teZCL_ZCLAttributeType      eAttributeDataType              Type
 ** tsZCL_ReportRecord          *psAttributeReportingRecord     Report Record
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/

PUBLIC teZCL_Status eZCL_CheckForStringAttributeChange(
                     void                      *pvStringToStore,
                     teZCL_ZCLAttributeType     eAttributeDataType,
                     tsZCL_ReportRecord        *psAttributeReportingRecord)
{
    tsZCL_LongOctetString        *psLongOctetString;
    tsZCL_OctetString            *psOctetString;
    tsZCL_CharacterString        *psCharacterString;
    tsZCL_LongCharacterString    *psLongCharacterString;

    if((pvStringToStore == NULL) || (psAttributeReportingRecord == NULL))
    {
        return(E_ZCL_FAIL);
    }

    switch(eAttributeDataType)
    {
        case(E_ZCL_OSTRING):
        {
            psOctetString = (tsZCL_OctetString *)pvStringToStore;
            if(psAttributeReportingRecord->uAttributeStorage.sOctetString.u8Length != psOctetString->u8Length)
            {
                return(E_ZCL_SUCCESS);
            }

            if(!memcmp(psAttributeReportingRecord->uAttributeStorage.sOctetString.pu8Data, psOctetString->pu8Data, psAttributeReportingRecord->uAttributeStorage.sOctetString.u8Length))
            {
                return(E_ZCL_ERR_NO_REPORTABLE_CHANGE);
            }
            break;
        }

        case(E_ZCL_CSTRING):
        {
            psCharacterString = (tsZCL_CharacterString *)pvStringToStore;
            if(psAttributeReportingRecord->uAttributeStorage.sCharacterString.u8Length != psCharacterString->u8Length)
            {
                return(E_ZCL_SUCCESS);
            }

            if(!memcmp(psAttributeReportingRecord->uAttributeStorage.sCharacterString.pu8Data, psCharacterString->pu8Data, psAttributeReportingRecord->uAttributeStorage.sCharacterString.u8Length))
            {
                return(E_ZCL_ERR_NO_REPORTABLE_CHANGE);
            }
            break;
        }
        case(E_ZCL_LCSTRING):
        {
            psLongCharacterString = (tsZCL_LongCharacterString *)pvStringToStore;
            if(psAttributeReportingRecord->uAttributeStorage.sLongCharacterString.u16Length != psLongCharacterString->u16Length)
            {
                return(E_ZCL_SUCCESS);
            }

            if(!memcmp(psAttributeReportingRecord->uAttributeStorage.sLongCharacterString.pu8Data, psLongCharacterString->pu8Data, psAttributeReportingRecord->uAttributeStorage.sLongCharacterString.u16Length))
            {
                return(E_ZCL_ERR_NO_REPORTABLE_CHANGE);
            }
            break;
        }
        case(E_ZCL_LOSTRING):
        {
            psLongOctetString = (tsZCL_LongOctetString *)pvStringToStore;
            if(psAttributeReportingRecord->uAttributeStorage.sLongOctetString.u16Length != psLongOctetString->u16Length)
            {
                return(E_ZCL_SUCCESS);
            }

            if(!memcmp(psAttributeReportingRecord->uAttributeStorage.sLongOctetString.pu8Data, psLongOctetString->pu8Data, psAttributeReportingRecord->uAttributeStorage.sLongOctetString.u16MaxLength))
            {
                return(E_ZCL_ERR_NO_REPORTABLE_CHANGE);
            }
            break;
        }

        default:
        {
            return(E_ZCL_FAIL);
        }
    }

    return(E_ZCL_SUCCESS);
}

/****************************************************************************
 **
 ** NAME:       vZCL_CopyStringAttributeToPreviousValue
 **
 ** DESCRIPTION:
 **
 **
 ** PARAMETERS:                 Name                            Usage
 ** void                        *pvStringToStore                String
 ** teZCL_ZCLAttributeType      eAttributeDataType              Type
 ** tsZCL_ReportRecord          *psAttributeReportingRecord     Report Record
 **
 ** RETURN:
 ** teZCL_Status
 **
 ****************************************************************************/

PUBLIC teZCL_Status eZCL_CopyStringAttributeToPreviousValue(
                     void                      *pvStringToStore,
                     teZCL_ZCLAttributeType     eAttributeDataType,
                     tsZCL_ReportRecord        *psAttributeReportingRecord)
{
    tsZCL_LongOctetString        *psLongOctetString;
    tsZCL_OctetString            *psOctetString;
    tsZCL_CharacterString        *psCharacterString;
    tsZCL_LongCharacterString    *psLongCharacterString;

    if((pvStringToStore == NULL) || (psAttributeReportingRecord == NULL))
    {
        return(E_ZCL_FAIL);
    }

    switch(eAttributeDataType)
    {
        case(E_ZCL_OSTRING):
        {
            psOctetString = (tsZCL_OctetString *)pvStringToStore;
            psAttributeReportingRecord->uAttributeStorage.sOctetString.u8Length = psOctetString->u8Length;
            if (psOctetString->u8Length > psAttributeReportingRecord->uAttributeStorage.sOctetString.u8MaxLength)
            {
                psAttributeReportingRecord->uAttributeStorage.sOctetString.u8Length =
                psAttributeReportingRecord->uAttributeStorage.sOctetString.u8MaxLength;
            }
            memcpy(psAttributeReportingRecord->uAttributeStorage.sOctetString.pu8Data, psOctetString->pu8Data, psAttributeReportingRecord->uAttributeStorage.sOctetString.u8Length);
            break;
        }

        case(E_ZCL_CSTRING):
        {
            psCharacterString = (tsZCL_CharacterString *)pvStringToStore;
            psAttributeReportingRecord->uAttributeStorage.sCharacterString.u8Length = psCharacterString->u8Length;
            if (psCharacterString->u8Length > psAttributeReportingRecord->uAttributeStorage.sCharacterString.u8MaxLength)
            {
                psAttributeReportingRecord->uAttributeStorage.sCharacterString.u8Length =
                psAttributeReportingRecord->uAttributeStorage.sCharacterString.u8MaxLength;
            }
            memcpy(psAttributeReportingRecord->uAttributeStorage.sCharacterString.pu8Data, psCharacterString->pu8Data, psAttributeReportingRecord->uAttributeStorage.sCharacterString.u8Length);
            break;
        }
        case(E_ZCL_LCSTRING):
        {
            psLongCharacterString = (tsZCL_LongCharacterString *)pvStringToStore;
            psAttributeReportingRecord->uAttributeStorage.sLongCharacterString.u16Length = psLongCharacterString->u16Length;
            if (psLongCharacterString->u16Length > psAttributeReportingRecord->uAttributeStorage.sLongCharacterString.u16MaxLength)
            {
                psAttributeReportingRecord->uAttributeStorage.sLongCharacterString.u16Length =
                psAttributeReportingRecord->uAttributeStorage.sLongCharacterString.u16MaxLength;
            }
            memcpy(psAttributeReportingRecord->uAttributeStorage.sLongCharacterString.pu8Data, psLongCharacterString->pu8Data, psAttributeReportingRecord->uAttributeStorage.sLongCharacterString.u16Length);
            break;
        }
        case(E_ZCL_LOSTRING):
        {
            psLongOctetString = (tsZCL_LongOctetString *)pvStringToStore;
            psAttributeReportingRecord->uAttributeStorage.sLongOctetString.u16Length = psLongOctetString->u16Length;
            if (psLongOctetString->u16Length > psAttributeReportingRecord->uAttributeStorage.sLongOctetString.u16MaxLength)
            {
                psAttributeReportingRecord->uAttributeStorage.sLongOctetString.u16Length =
                psAttributeReportingRecord->uAttributeStorage.sLongOctetString.u16MaxLength;
            }
            memcpy(psAttributeReportingRecord->uAttributeStorage.sLongOctetString.pu8Data, psLongOctetString->pu8Data, psAttributeReportingRecord->uAttributeStorage.sLongOctetString.u16Length);
            break;
        }

        default:
        {
            return(E_ZCL_FAIL);
        }
    }

    return(E_ZCL_SUCCESS);
}

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/


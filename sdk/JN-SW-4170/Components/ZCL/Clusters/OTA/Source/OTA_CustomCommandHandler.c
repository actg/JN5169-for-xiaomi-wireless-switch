/*****************************************************************************
 *
 * MODULE:             Over The Air Upgrade
 *
 * COMPONENT:          ota_server.c
 *
 * AUTHOR:             Faisal Bhaiyat
 *
 * DESCRIPTION:        Over The Air Upgrade
 *
 * $HeadURL: http://svn/sware/Projects/SmartEnergy/Trunk/ZCL/Clusters/OTA/Source/ota_server.c $
 *
 * $Revision:  $
 *
 * $LastChangedBy: fbhai $
 *
 * $LastChangedDate: $
 *
 * $Id: ota_client.c  $
 *
 *****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products [NXP Microcontrollers such as JN5168, JN5164,
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

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#include <jendefs.h>
#include "zcl.h"
#include "zcl_options.h"
#include "OTA.h"
#include "OTA_private.h"

#include "dbg.h"
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
/***        Exported Functions                                            ***/
/****************************************************************************/
#ifdef CLD_OTA
/****************************************************************************
 **
 ** NAME:       eOtaCommandHandler
 **
 ** DESCRIPTION:
 ** OTA command handler
 **
 ** PARAMETERS:                    Name                           Usage
 ** ZPS_tsAfEvent               *pZPSevent                  ZPS event
 ** tsZCL_EndPointDefinition    *psEndPointDefinition       endpoint definition
 ** tsZCL_ClusterInstance       *psClusterInstance          cluster instance
 **
 ** RETURN:
 ** teZCL_Status
 ****************************************************************************/
PUBLIC  teZCL_Status eOtaCommandHandler(
                    ZPS_tsAfEvent               *pZPSevent,
                    tsZCL_EndPointDefinition    *psEndPointDefinition,
                    tsZCL_ClusterInstance       *psClusterInstance)
{
    tsZCL_HeaderParams sZCL_HeaderParams;
    uint16 u16HeaderSize;
    teZCL_Status eStatus;


    // further error checking can only be done once we have interrogated the ZCL payload
    u16HeaderSize =     u16ZCL_ReadCommandHeader(pZPSevent->uEvent.sApsDataIndEvent.hAPduInst,
                             &sZCL_HeaderParams);
// store the incoming event details which can be used to send events back to the application
    
    eZCL_SetReceiveEventAddressStructure(pZPSevent, &((tsOTA_Common *)psClusterInstance->pvEndPointCustomStructPtr)->sReceiveEventAddress);

    switch (psClusterInstance->bIsServer)
    {
#ifdef OTA_CLIENT
        case(FALSE):
        {
            if(pZPSevent->uEvent.sApsDataIndEvent.u8SrcAddrMode == ZPS_E_ADDR_MODE_IEEE)
            {
                /*If we receive requests from anywhere else apart from our server
                ignore */
                if(pZPSevent->uEvent.sApsDataIndEvent.uSrcAddress.u64Addr
                    != ((tsOTA_Common *)psClusterInstance->pvEndPointCustomStructPtr)->sOTACallBackMessage.sPersistedData.sAttributes.u64UgradeServerID )
                {
                    return(E_ZCL_ERR_EP_UNKNOWN);
                }
            }

            if(pZPSevent->uEvent.sApsDataIndEvent.u8SrcAddrMode == ZPS_E_ADDR_MODE_SHORT &&
                    (pZPSevent->uEvent.sApsDataIndEvent.uSrcAddress.u16Addr < 0xFFF8) &&
                    ((tsOTA_Common *)psClusterInstance->pvEndPointCustomStructPtr)->sOTACallBackMessage.sPersistedData.u16ServerShortAddress !=
                    pZPSevent->uEvent.sApsDataIndEvent.uSrcAddress.u16Addr)
            {
                return(E_ZCL_ERR_EP_UNKNOWN);
            }
            /* handle default response */
            if(sZCL_HeaderParams.u8CommandIdentifier == E_ZCL_DEFAULT_RESPONSE &&
                sZCL_HeaderParams.eFrameType == eFRAME_TYPE_COMMAND_ACTS_ACCROSS_ENTIRE_PROFILE)
            {
                vOtaReceivedDefaultResponse(pZPSevent, psEndPointDefinition, psClusterInstance);
                return E_ZCL_SUCCESS;
            }
            #ifdef OTA_UPGRADE_VOLTAGE_CHECK
            /* Check if Volatge was OK */
                if( bOta_LowVoltage )
                {
                    return E_ZCL_SUCCESS;
                }
            #endif
            switch(sZCL_HeaderParams.u8CommandIdentifier)
            {
                case E_CLD_OTA_COMMAND_IMAGE_NOTIFY:
                     eStatus = eOtaReceivedImageNotify(pZPSevent, psEndPointDefinition, psClusterInstance, u16HeaderSize);
                break;

                case E_CLD_OTA_COMMAND_QUERY_NEXT_IMAGE_RESPONSE:
                     eStatus = eOtaReceivedQueryNextImageResponse(pZPSevent, psEndPointDefinition, psClusterInstance, u16HeaderSize);
                break;

                case E_CLD_OTA_COMMAND_BLOCK_RESPONSE:
                     eStatus = eOtaReceivedBlockResponse(pZPSevent, psEndPointDefinition, psClusterInstance, u16HeaderSize);
                break;

                case E_CLD_OTA_COMMAND_UPGRADE_END_RESPONSE:
                     eStatus = eOtaReceivedUpgradeEndResponse(pZPSevent, psEndPointDefinition, psClusterInstance, u16HeaderSize);
                break;

                case E_CLD_OTA_COMMAND_QUERY_SPECIFIC_FILE_RESPONSE:
                    eStatus = eOtaQuerySpecificFileResponse(pZPSevent, psEndPointDefinition, psClusterInstance, u16HeaderSize);
                break;

                default:
                    eStatus = E_ZCL_FAIL;
                break;
            }
        }
        break;
#endif
#ifdef OTA_SERVER
        case(TRUE):
        {
            switch(sZCL_HeaderParams.u8CommandIdentifier)
            {
                case E_CLD_OTA_COMMAND_QUERY_NEXT_IMAGE_REQUEST:
                    eStatus = eOtaReceivedQueryNextImage(pZPSevent, psEndPointDefinition, psClusterInstance, u16HeaderSize);
                break;

                case E_CLD_OTA_COMMAND_BLOCK_REQUEST:
                    eStatus = eOtaReceivedBlockRequest(pZPSevent, psEndPointDefinition, psClusterInstance, u16HeaderSize);
                break;

                case E_CLD_OTA_COMMAND_UPGRADE_END_REQUEST:
                    eStatus = eOtaReceivedUpgradeEndRequest(pZPSevent, psEndPointDefinition, psClusterInstance, u16HeaderSize);
                break;

                case E_CLD_OTA_COMMAND_PAGE_REQUEST:
                    eStatus = eOtaReceivedPageRequest(pZPSevent, psEndPointDefinition, psClusterInstance, u16HeaderSize);
                break;

                case E_CLD_OTA_COMMAND_QUERY_SPECIFIC_FILE_REQUEST:
                    eStatus = eOtaReceivedQuerySpecificFileRequest(pZPSevent, psEndPointDefinition, psClusterInstance, u16HeaderSize);
                break;

                default:

                   return(E_ZCL_FAIL);
                break;

            }
        }
        break;
#endif
        default:
            eStatus = E_ZCL_FAIL;
            break;

    }
    return eStatus;
}
#endif
/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

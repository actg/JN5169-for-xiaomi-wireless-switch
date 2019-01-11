/*****************************************************************************
 *
 * MODULE:             Smart Energy Profile
 *
 * COMPONENT:          se.c
 *
 * AUTHOR:             Lee Mitchell
 *
 * DESCRIPTION:        ZigBee Smart Energy profile functions
 *
 * $HeadURL: http://svn/sware/Projects/SmartEnergy/Trunk/ZCL/Profiles/SE/Source/se.c $
 *
 * $Revision: 16810 $
 *
 * $LastChangedBy: we1 $
 *
 * $LastChangedDate: 2009-07-23 12:18:09 +0100 (Thu, 23 Jul 2009) $
 *
 * $Id: se.c 16810 2009-07-23 11:18:09Z we1 $
 *
 *****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products [NXP Microcontrollers such as JN5148, JN5142, JN5139].
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
#include "zps_apl.h"
#include "zcl_heap.h"
#include "zcl.h"
#include "zcl_options.h"
#include "ha.h"
#include "Basic.h"
#include "Identify.h"
#include "Scenes.h"
#include "LevelControl.h"
#include "ColourControl.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#if (defined CLD_IDENTIFY) && (defined IDENTIFY_SERVER)
#define HA_NUMBER_OF_IDENTIFY_TIMERS                    (1)
#else
#define HA_NUMBER_OF_IDENTIFY_TIMERS                    (0)
#endif

#ifdef CLD_OTA
#define HA_NUMBER_OF_OTA_TIMERS    (1)
#else
#define HA_NUMBER_OF_OTA_TIMERS    (0)
#endif

#ifdef CLD_TEMPERATURE_MEASUREMENT
#define HA_NUMBER_OF_TEMPERATURE_MEASUREMENT_REPORTS    (1)
#else
#define HA_NUMBER_OF_TEMPERATURE_MEASUREMENT_REPORTS    (0)
#endif

#define HA_NUMBER_OF_TIMERS     (HA_NUMBER_OF_ZCL_APPLICATION_TIMERS) + \
								(HA_NUMBER_OF_IDENTIFY_TIMERS)        +\
								(HA_NUMBER_OF_OTA_TIMERS)

#ifdef ZCL_ATTRIBUTE_REPORTING_SERVER_SUPPORTED
    /*If Number of reports not defined by app define it to 10*/
    #ifndef HA_NUMBER_OF_REPORTS
        #define HA_NUMBER_OF_REPORTS            (10)
    #endif

    #ifndef HA_NUMBER_OF_STRING_REPORTS
        #define HA_NUMBER_OF_STRING_REPORTS     (0)
    #endif
    
    /*If System Min time is not defined by app define it to 1*/
    #ifndef HA_SYSTEM_MIN_REPORT_INTERVAL
        #define HA_SYSTEM_MIN_REPORT_INTERVAL   (0x0001)
    #endif
    
    /*If system max time  not defined by app define it to 60 secs*/
    #ifndef HA_SYSTEM_MAX_REPORT_INTERVAL
        #define HA_SYSTEM_MAX_REPORT_INTERVAL   (0x003c)
    #endif
#else
    #ifndef HA_NUMBER_OF_REPORTS
        #define HA_NUMBER_OF_REPORTS            (0)
    #endif
    #ifndef HA_NUMBER_OF_STRING_REPORTS
        #define HA_NUMBER_OF_STRING_REPORTS     (0)
    #endif   
    #ifndef HA_SYSTEM_MIN_REPORT_INTERVAL
        #define HA_SYSTEM_MIN_REPORT_INTERVAL   (0)
    #endif
    #ifndef HA_SYSTEM_MAX_REPORT_INTERVAL    
        #define HA_SYSTEM_MAX_REPORT_INTERVAL   (0)
    #endif
#endif


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

PRIVATE uint32 u32ZCL_Heap[ZCL_HEAP_SIZE(HA_NUMBER_OF_ENDPOINTS, HA_NUMBER_OF_TIMERS, HA_NUMBER_OF_REPORTS, HA_NUMBER_OF_STRING_REPORTS)];

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

/****************************************************************************
 *
 * NAME: eHA_Initialise
 *
 * DESCRIPTION:
 * Registers timer servers with the ZCL layer
 *
 * PARAMETERS:  Name                            Usage
 *              cbCallBack                      Pointer to general callback
 *              hAPdu                           pointer to pool of APDU's
 *
 * RETURNS:
 * teZCL_Status
 *
 ****************************************************************************/
PUBLIC teZCL_Status eHA_Initialise(tfpZCL_ZCLCallBackFunction cbCallBack,
                                   PDUM_thAPdu hAPdu)
{
    teZCL_Status eStatus;
    tsZCL_Config sConfig;

    sConfig.u8NumberOfEndpoints = HA_NUMBER_OF_ENDPOINTS;
    sConfig.u8NumberOfTimers = HA_NUMBER_OF_TIMERS;
    sConfig.u8NumberOfReports = HA_NUMBER_OF_REPORTS;
    sConfig.u16SystemMinimumReportingInterval = HA_SYSTEM_MIN_REPORT_INTERVAL;
    sConfig.u16SystemMaximumReportingInterval = HA_SYSTEM_MAX_REPORT_INTERVAL;
    sConfig.pfZCLcallBackFunction = cbCallBack;
    sConfig.hAPdu = hAPdu;
    sConfig.u32ZCL_HeapSizeInWords = sizeof(u32ZCL_Heap) / sizeof(uint32);
    sConfig.pu32ZCL_Heap = &u32ZCL_Heap[0];


    eStatus = eZCL_CreateZCL(&sConfig);
    return eStatus;
}


/****************************************************************************
 *
 * NAME: eHA_Update100mS
 *
 * DESCRIPTION:
 * Should be called by an application timer 10 times per second
 *
 * PARAMETERS:  Name                            Usage
 *
 * RETURNS:
 * teZCL_Status
 *
 ****************************************************************************/
PUBLIC teZCL_Status eHA_Update100mS(void)
{
    #if ((defined LEVEL_CONTROL_SERVER) || (defined SCENES_SERVER) || \
         (defined COLOUR_CONTROL_SERVER) )
        uint8 u8NumEndpoints;
        int i;
    
        u8NumEndpoints = u8ZCL_GetNumberOfEndpointsRegistered();
        
        /* Update clusters on each end point if any */
        for(i = 0; i < u8NumEndpoints; i++)
        {

        #if (defined LEVEL_CONTROL_SERVER)
            eCLD_LevelControlUpdate(u8ZCL_GetEPIdFromIndex(i));
        #endif

        #if (defined SCENES_SERVER)
            eCLD_ScenesUpdate(u8ZCL_GetEPIdFromIndex(i));
        #endif

        #if (defined COLOUR_CONTROL_SERVER)
            eCLD_ColourControlUpdate(u8ZCL_GetEPIdFromIndex(i));
        #endif
        }

    #endif
    return E_ZCL_SUCCESS;

}


/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/


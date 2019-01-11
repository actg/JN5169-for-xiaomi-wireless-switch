/*****************************************************************************
 *
 * MODULE:             Green Power Profile
 *
 * COMPONENT:          gp.h
 *
 * AUTHOR:             Ramakrishna
 *
 * DESCRIPTION:        The API for the Green Power End Point Registration
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/UnifiedZCL_ZLL102_HA122_Maintenance/Profiles/GP/Include/gp.h $
 *
 * $Revision: 57055 $
 *
 * $LastChangedBy: nxp47667 $
 *
 * $LastChangedDate: 2013-10-11 08:51:09 +0100 (Fri, 11 Oct 2013) $
 *
 * $Id: gp.h 57055 2013-10-11 07:51:09Z nxp47667 $
 *
 *****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products  [NXP Microcontrollers such as JN5168, JN5164,
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

#ifndef COMBOMIN_H
#define COMBOMIN_H

#if defined __cplusplus
extern "C" {
#endif

#include <jendefs.h>
#include "zcl.h"
#include "zcl_options.h"
#include "GreenPower.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#ifndef GP_MANUFACTURER_CODE
#define GP_MANUFACTURER_CODE                                        (0)
#endif

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

    /* Holds cluster instances */
typedef struct
{
    tsZCL_ClusterInstance                  sGreenPowerServer;
    tsZCL_ClusterInstance                  sGreenPowerClient;
} tsGP_GreenPowerClusterInstances;


/* Holds everything required to create an instance of an Green Power device */
typedef struct
{
    tsZCL_EndPointDefinition               sEndPoint;

    /* Cluster instances */
    tsGP_GreenPowerClusterInstances        sClusterInstance;

    /* Holds the attributes for the Green Power cluster server */
    tsCLD_GreenPower                       sServerGreenPowerCluster;

   /* Holds the attributes for the Green Power cluster Client */
    tsCLD_GreenPower                       sClientGreenPowerCluster;

    /*Event Address, Custom call back event, Custom call back message*/
    tsGP_GreenPowerCustomData              sGreenPowerCustomDataStruct;
} tsGP_GreenPowerDevice;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
PUBLIC teZCL_Status eGP_RegisterComboMinimumEndPoint(
                        uint8                               u8EndPointIdentifier,
                        tfpZCL_ZCLCallBackFunction          cbCallBack,
                        tsGP_GreenPowerDevice               *psDeviceInfo,
                        uint16                              u16ProfileId,
                        uint8                               u8NoOfTranslationTableEntries,
                        tsGP_TranslationTableEntry          *psTranslationTableEntry);

PUBLIC teZCL_Status eGP_RegisterProxyEndPoint(
                        uint8                               u8EndPointIdentifier,
                        tfpZCL_ZCLCallBackFunction          cbCallBack,
                        tsGP_GreenPowerDevice               *psDeviceInfo);
/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/
extern const tsZCL_AttributeDefinition  asCLD_GreenPowerClusterAttributeDefinitions[];
extern tsZCL_ClusterDefinition          sCLD_GreenPower;
extern uint8                            au8ServerGreenPowerClusterAttributeControlBits[];
extern uint8                            au8ClientGreenPowerClusterAttributeControlBits[];

/****************************************************************************/
#if defined __cplusplus
}
#endif

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

#endif /* COMBOMIN_H */

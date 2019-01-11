/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          PDM_IDs.h
 *
 * DESCRIPTION:        Persistant Data Manager Id's
 *
 *****************************************************************************
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
 * Copyright NXP B.V. 2013. All rights reserved
 *
 ****************************************************************************/

#ifndef  PDMIDS_H_INCLUDED
#define  PDMIDS_H_INCLUDED

#if defined __cplusplus
extern "C" {
#endif


/****************************************************************************/
/***        Include Files                                                 ***/
/****************************************************************************/

#include <jendefs.h>

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#ifdef PDM_USER_SUPPLIED_ID

#define PDM_ID_APP_REMOTE_CONTROL        0x1
#define PDM_ID_APP_LIGHT_TABLE		     0x2
#define PDM_ID_APP_COORD 			     0x3
#define PDM_ID_APP_REMOTE_DEVICE_TABLE   0x4
#define PDM_ID_APP_APP_ROUTER            0x5
#define PDM_ID_APP_SCENES_CL             0x7
#define PDM_ID_APP_SCENES_ATTB           0x8
#define PDM_ID_APP_SCENES_DATA           0x9
#define PDM_ID_POWER_ON_COUNTER          0xa
#define PDM_ID_APP_REPORTS               0xb
#define PDM_ID_OTA_DATA                  0xc
#define PDM_ID_APP_CLD_GP_TRANS_TABLE    0xd
#define PDM_ID_APP_CLD_GP_SINK_TABLE     0xe
#if (CONFIG_RESTORE_DIM_LEVEL == TRUE)
#define PDM_ID_APP_LIGHT_LEVEL           0xf
#endif
#define PDM_ID_DEVICE_SWITCH_GROUPID		 0x10
#else

#define PDM_ID_APP_REMOTE_CONTROL   "REMOTE_CONTROL"
#define PDM_ID_APP_LIGHT_TABLE		"LIGHT_TABLE"
#define PDM_ID_APP_COORD 			"APP_COORD"
#define PDM_ID_APP_APP_ROUTER       "APP_ROUTER"
#define PDM_ID_APP_SCENES_CL        "SCENES_CL"
#define PDM_ID_APP_SCENES_ATTB      "SCENES_ATTB"
#define PDM_ID_APP_SCENES_DATA      "SCENES_DATA"

#endif


/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

#if defined __cplusplus
}
#endif

#endif /* PDMIDS_H_INCLUDED */

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

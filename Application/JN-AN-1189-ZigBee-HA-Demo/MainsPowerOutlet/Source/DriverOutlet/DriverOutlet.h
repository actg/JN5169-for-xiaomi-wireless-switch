/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          DriverOutlet.h
 *
 * DESCRIPTION:        ZHA Demo Driver Main Power Outlet - Interface
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
 ***************************************************************************/
#ifndef  DRIVEROUTLET_H_INCLUDED
#define  DRIVEROUTLET_H_INCLUDED

#if defined __cplusplus
extern "C" {
#endif

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
/* SDK includes */
#include <jendefs.h>

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#define DRIVEROUTLET_ON_OFF_BUTTON_ID    0

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Public Function Prototypes                                    ***/
/****************************************************************************/
/* Mandatory Interface functions */
PUBLIC void     DriverOutlet_vInit(void);
PUBLIC void     DriverOutlet_vOutputOn(void);
PUBLIC void     DriverOutlet_vOutputOff(void);
PUBLIC void     DriverOutlet_vSetOutputOnOff(bool_t bOn);
PUBLIC bool_t    DriverOutlet_bIsOutputOn(void);
PUBLIC void     DriverOutlet_vStatusLedOn(void);
PUBLIC void     DriverOutlet_vStatusLedOff(void);
PUBLIC bool_t    DriverOutlet_bIsStatusLedOn(void);
PUBLIC void        DriverOutlet_vSetStatusLedOnOff(bool_t bOn);
PUBLIC bool_t   DriverOutlet_bIsButtonDown(void);

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

#if defined __cplusplus
}
#endif

#endif  /* DRIVEROUTLET_H_INCLUDED */
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

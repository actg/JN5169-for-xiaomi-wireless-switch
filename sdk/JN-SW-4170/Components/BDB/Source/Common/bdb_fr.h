/*###############################################################################
#
# MODULE:      BDB
#
# COMPONENT:   bdb_failure_recovery.h
#
# AUTHOR:
#
# DESCRIPTION: BDB failure recovery API
#
#
# $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/Components/BDB/Trunk/Source/Common/bdb_fr.h $
#
# $Revision: 74707 $
#
# $LastChangedBy: nxp46755 $
#
# $LastChangedDate: 2015-11-30 13:46:12 +0000 (Mon, 30 Nov 2015) $
#
# $Id: bdb_fr.h 74707 2015-11-30 13:46:12Z nxp46755 $
#
###############################################################################
#
# This software is owned by NXP B.V. and/or its supplier and is protected
# under applicable copyright laws. All rights are reserved. We grant You,
# and any third parties, a license to use this software solely and
# exclusively on NXP products [NXP Microcontrollers such as JN514x, JN516x, JN517x].
# You, and any third parties must reproduce the copyright and warranty notice
# and any other legend of ownership on each  copy or partial copy of the software.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
# Copyright NXP B.V. 2015-2016. All rights reserved
#
###############################################################################*/

#ifndef BDB_FR_INCLUDED
#define BDB_FR_INCLUDED

#if defined __cplusplus
extern "C" {
#endif

/****************************************************************************/
/***        Include Files                                                 ***/
/****************************************************************************/
#include "bdb_api.h"
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
typedef enum
{
    E_FR_IDLE,
    E_FR_RECOVERY,
    E_FR_GIVE_UP
}teFR_State;


/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
PUBLIC void BDB_vFrStateMachine(BDB_tsZpsAfEvent *psZpsAfEvent);

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
extern teFR_State eFR_State;

#if defined __cplusplus
}
#endif

#endif  /* BDB_FR_INCLUDED */

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/







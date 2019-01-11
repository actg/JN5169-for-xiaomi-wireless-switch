/****************************************************************************
 *
 * MODULE:             JN-AN-1189 ZHA Demo
 *
 * COMPONENT:          app_exceptions.c
 *
 * DESCRIPTION:        Exception routines
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
 * Copyright NXP B.V. 2014. All rights reserved
 *
 ***************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include <jendefs.h>
#include "pwrm.h"
#include "pdm.h"
#include "dbg_uart.h"
#include "pdum_gen.h"
#include "os_gen.h"
#include "zps_gen.h"
#include "zps_apl.h"
#include "appapi.h"



/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#define HALT_ON_EXCEPTION      FALSE

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
#ifndef DEBUG_EXCEPTION
    #define TRACE_EXCEPTION FALSE
#else
    #define TRACE_EXCEPTION TRUE
#endif
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

/****************************************************************************
 *
 * NAME: vUnclaimedInterrupt
 *
 * DESCRIPTION:
 * Catches any unexpected interrupts
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vUnclaimedInterrupt(void)
{
    DBG_vPrintf(TRACE_EXCEPTION, "Unclaimed interrupt\n");
    DBG_vDumpStack();
    #if HALT_ON_EXCEPTION
        while (1);
    #else
        vAHI_SwReset();
    #endif
}
/****************************************************************************
 *
 * NAME: APP_isrStackOverflowException
 *
 * DESCRIPTION:
 * Stack Over Flow ISR
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
OS_ISR(APP_isrStackOverflowException)
{
    DBG_vPrintf(TRACE_EXCEPTION, "Stack overflowed\n");
    DBG_vDumpStack();
    #if HALT_ON_EXCEPTION
        while (1);
    #else
        vAHI_SwReset();
    #endif
}
/****************************************************************************
 *
 * NAME: APP_isrUnimplementedModuleException
 *
 * DESCRIPTION:
 * Unimplemented Module exception ISR
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
OS_ISR(APP_isrUnimplementedModuleException)
{
    DBG_vPrintf(TRACE_EXCEPTION, "Unimplemented module exception\n");
    DBG_vDumpStack();
    #if HALT_ON_EXCEPTION
        while (1);
    #else
        vAHI_SwReset();
    #endif
}
/****************************************************************************
 *
 * NAME: APP_isrBusErrorException
 *
 * DESCRIPTION:
 * Bus Error ISR
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
OS_ISR(APP_isrBusErrorException)
{
    DBG_vPrintf(TRACE_EXCEPTION, "Bus error\n");
    DBG_vDumpStack();
    #if HALT_ON_EXCEPTION
        while(1);
    #else
        vAHI_SwReset();
    #endif
}
/****************************************************************************
 *
 * NAME: APP_isrAlignmentException
 *
 * DESCRIPTION:
 * Alignment exception ISR
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
OS_ISR(APP_isrAlignmentException)
{
    DBG_vPrintf(TRACE_EXCEPTION, "Alignment exception\n");
    DBG_vDumpStack();
    #if HALT_ON_EXCEPTION
        while(1);
    #else
        vAHI_SwReset();
    #endif
}
/****************************************************************************
 *
 * NAME: APP_isrIllegalInstruction
 *
 * DESCRIPTION:
 * Illegal Instruction ISR
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
OS_ISR(APP_isrIllegalInstruction)
{
    DBG_vPrintf(TRACE_EXCEPTION, "Illegal instruction\n");
    DBG_vDumpStack();
    #if HALT_ON_EXCEPTION
        while(1);
    #else
        vAHI_SwReset();
    #endif
}

/****************************************************************************
 *
 * NAME: vOSError
 *
 * DESCRIPTION:
 * Catches any unexpected OS errors
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void vOSError(OS_teStatus eStatus, void *hObject)
{
    OS_thTask hTask;

    /* ignore queue underruns */
    if ((OS_E_QUEUE_EMPTY == eStatus) ||
        (( eStatus >= OS_E_SWTIMER_STOPPED) && ( eStatus <= OS_E_SWTIMER_RUNNING)) )
    {
        return;
    }

    DBG_vPrintf(TRACE_EXCEPTION, "OS Error %d, offending object handle = 0x%08x\n", eStatus, hObject);

    /* NB the task may have been pre-empted by an ISR which may be at fault */
    OS_eGetCurrentTask(&hTask);
    DBG_vPrintf(TRACE_EXCEPTION, "Currently active task handle = 0x%08x\n", hTask);
#ifdef OS_STRICT_CHECKS
    DBG_vPrintf(TRACE_EXCEPTION, "Currently active ISR fn address = 0x%08x\n", OS_prGetActiveISR());
#endif

#if HALT_ON_EXCEPTION
    if ( (eStatus < OS_E_SWTIMER_STOPPED) || (eStatus > OS_E_SWTIMER_RUNNING) ) {
    	DBG_vPrintf(TRUE, "OS Error: %d\n", eStatus);
    }
#endif
}

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

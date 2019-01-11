/*****************************************************************************
 *
 * MODULE:             Operating System
 *
 * DESCRIPTION:        Provide basic operating system functionality for managing
 *                     tasks, interrupts, etc.
 *
 ****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products [NXP Microcontrollers such as JN5148, JN5142, JN5139]. 
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
 * Copyright NXP B.V. 2012. All rights reserved
 *
 ***************************************************************************/

#ifndef OS_H_
#define OS_H_

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#define OS_TASK(a)        void os_v##a(void) /* [I SP001271_fr 1006,1007] */
#define OS_ISR(a)         void os_v##a(void) /* [I SP001271_fr 1050] */
#define OS_SWTIMER_CALLBACK(a, b) void os_v##a(void *b)
#define OS_HWCOUNTER_ENABLE_CALLBACK(a) void os_v##a(void)
#define OS_HWCOUNTER_DISABLE_CALLBACK(a) void os_v##a(void)
#define OS_HWCOUNTER_SET_CALLBACK(a, b) bool os_b##a(uint32 b)
#define OS_HWCOUNTER_GET_CALLBACK(a) uint32 os_u32##a(void)

/*
 *  For use when compiling libraries etc that need to reference handle instances
 * when os_gen.h is not available
 */
#define OS_EXTERN_TASK(_name_)          extern struct _os_tsTask os_Task_##_name_
#define OS_EXTERN_MUTEX(_name_)         extern struct _os_tsMutex os_Mutex_##_name_
#define OS_EXTERN_MESSAGE(_name_)       extern struct _os_tsMessage os_Message_##_name_
#define OS_EXTERN_HWCOUNTER(_name_)     extern struct _os_tsHWCounter os_HWCounter_##_name_
#define OS_EXTERN_SWTIMER(_name_)       extern struct _os_tsSWTimer os_SWTimer_##_name_

#define OS_TASK_HANDLE(_name_)          ((OS_thTask)&os_Task_##_name_)
#define OS_MUTEX_HANDLE(_name_)         ((OS_thMutex)&os_Mutex_##_name_)
#define OS_MESSAGE_HANDLE(_name_)       ((OS_thMessage)&os_Message_##_name_)
#define OS_HWCOUNTER_HANDLE(_name_)     ((OS_thHWCounter)&os_HWCounter_##_name_)
#define OS_SWTIMER_HANDLE(_name_)       ((OS_thSWTimer)&os_SWTimer_##_name_)

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

typedef enum {
    OS_E_OK                              = 0,
    OS_E_BADTASK                         = 1,
    OS_E_BADMUTEX                        = 2,
    OS_E_BADMESSAGE                      = 3,
    OS_E_BADVALUE                        = 4,
    OS_E_OVERACTIVATION                  = 5,
    OS_E_QUEUE_EMPTY                     = 6,
    OS_E_QUEUE_FULL                      = 7,
    OS_E_UNQUEUED                        = 8,
    OS_E_OSINTOVERFLOW                   = 9,
    OS_E_OSINTUNDERFLOW                  = 10,
    OS_E_BADSWTIMER                      = 11,
    OS_E_BADHWCOUNTER                    = 12,
    OS_E_SWTIMER_STOPPED                 = 13,
    OS_E_SWTIMER_EXPIRED                 = 14,
    OS_E_SWTIMER_RUNNING                 = 15,
    OS_E_HWCOUNTERIDLE                   = 16,
    OS_E_NOTHINGTOEXPIRE                 = 17,
    OS_E_PRIORITY_ERROR                  = 18,
    OS_E_BAD_NESTING                     = 19,
    OS_E_TICKS_TOO_BIG                   = 20,
    OS_E_CURRENT_TASK_NOT_A_MUTEX_MEMBER = 21,
    OS_E_TASK_NOT_A_MESSAGE_POSTER       = 22,
    OS_E_TASK_NOT_A_MESSAGE_COLLECTOR    = 23
} OS_teStatus;

struct _os_tsTask;
struct _os_tsMutex;
struct _os_tsMessage;
struct _os_tsHWCounter;
struct _os_tsSWTimer;

typedef struct _os_tsTask      * OS_thTask;
typedef struct _os_tsMutex     * OS_thMutex;
typedef struct _os_tsMessage   * OS_thMessage;
typedef struct _os_tsHWCounter * OS_thHWCounter;
typedef struct _os_tsSWTimer   * OS_thSWTimer;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC void OS_vRestart(void);
PUBLIC OS_teStatus OS_eActivateTask(OS_thTask hTask); /* [I SP001271_fr 1008] */
PUBLIC OS_teStatus OS_eGetCurrentTask(OS_thTask *phTask); /* [I SP001271_fr 2016] */
PUBLIC OS_teStatus OS_eEnterCriticalSection(OS_thMutex hMutex); /* [I SP001271_fr 2050] */
PUBLIC OS_teStatus OS_eExitCriticalSection(OS_thMutex hMutex); /* [I SP001271_fr 2055] */
PUBLIC OS_teStatus OS_ePostMessage(OS_thMessage hMessage, void *pvData);
PUBLIC OS_teStatus OS_eCollectMessage(OS_thMessage hMessage, void *pvData); /* [I SP001271_fr 2034] */
PUBLIC OS_teStatus OS_eGetMessageStatus(OS_thMessage hMessage); /* [I SP001271_fr 2044] */
PUBLIC OS_teStatus OS_eSuspendOSInterrupts(void); /* [I SP001271_fr 2061] */
PUBLIC OS_teStatus OS_eResumeOSInterrupts(void); /* [I SP001271_fr 2068] */
PUBLIC OS_teStatus OS_eDisableAllInterrupts(void); /* [I SP001271_fr 2073] */
PUBLIC OS_teStatus OS_eEnableAllInterrupts(void); /* [I SP001271_fr 2076] */
PUBLIC OS_teStatus OS_eStartSWTimer(OS_thSWTimer hSWTimer, uint32 u32Ticks, void *pvData); /* [I SP001271_fr 2090] */
PUBLIC OS_teStatus OS_eContinueSWTimer(OS_thSWTimer hSWTimer, uint32 u32Ticks, void *pvData); /* [I SP001271_fr 2104] */
PUBLIC OS_teStatus OS_eStopSWTimer(OS_thSWTimer hSWTimer); /* [I SP001271_fr 2117] */
PUBLIC OS_teStatus OS_eGetSWTimerStatus(OS_thSWTimer hSWTimer); /* [I SP001271_fr 2129] */
PUBLIC OS_teStatus OS_eExpireSWTimers(OS_thHWCounter hHWCounter); /* [I SP001271_fr 2079] */

/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/

#endif /*OS_H_*/

/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

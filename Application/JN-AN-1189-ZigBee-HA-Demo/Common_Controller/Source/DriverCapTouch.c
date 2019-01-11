/****************************************************************************
 *
 * MODULE              JN-AN-1170 DR1159 Capacitive Touch Remote
 *
 * DESCRIPTION         Capacitance Touch Driver - Implementation
 *
 ****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products [NXP Microcontrollers such as JN5168, JN5164].
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
 ****************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include <jendefs.h>
#include <AppHardwareApi.h>
#include <string.h>
#include "DriverCapTouch.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#define MICRO_DISABLE_AND_SAVE_INTERRUPTS(u32Store);                        \
    {                                                                       \
        asm volatile ("b.mfspr %0, r0, 17;" :"=r"(u32Store) : );            \
        asm volatile ("b.di;" : : );                                        \
    }

#define MICRO_RESTORE_INTERRUPTS(u32Store);                                 \
        asm volatile ("b.mtspr r0, %0, 17;" : :"r"(u32Store));

/* If defined, algorithm debug test is output to serial port */

/* For timing analysis. Toggles a dio during algorithm execution         */
/* For each pin in use the DIO goes low at the start of the charge cycle */
/* cycle and high at the end of the discharge cycle                      */
/*                                                                       */
/* __________   __   __   __   ________   waveform for 4 DIO Usage       */
/*           |_|  |_|  |_|  |_|                                          */

//#define TOUCH_DEBUG_DIO

#ifdef TOUCH_DEBUG_DIO
#define TOUCH_DEBUG_DIO_MASK 0x00000008
#else
#define TOUCH_DEBUG_DIO_MASK 0
#endif /* TOUCH_DEBUG_DIO */

/* Mask of the DIO pins used for buttons by the touch module                */
/* For DR1159 (4v0/4v1/4v2) we use DIO10-DIO19 (10 off)                     */
/* for DR1159 (5v0/5v1/5v2/5v2) we use DI02-3, DIO4-5, DIO8-19              */
/*                                                                          */
/* @Note!                                                                   */
/* The Released Cap Touch Reference Design currently uses 5V2 when used     */
/* with JN514x modules, and will 5V4 for JN5168 (allowing same keymap       */
/* Using 5V2 with JN5168  we lose 2 pads "?" &  ">"  [NXP INTERNAL ONLY]    */

#define TOUCH_DIO_MASK_BUTTONS (0x000fff3c)
#define TOUCH_SENSOR_COUNT 16


/* Mask of the DIO pins used by the touch module */
#define TOUCH_DIO_MASK (TOUCH_DIO_MASK_BUTTONS  & ~TOUCH_DEBUG_DIO_MASK)

/* The timer resource used by the touch module */
#define TOUCH_TIMER E_AHI_TIMER_0

/* Number of samples to wait before considering that the capacitance has settled */
#define TOUCH_BASE_CAPACITANCE_MEASURE_SAMPLES 20

/* number of button samples we acquire before drifting the background      */
/* towards the new  value. Implements a 'slow' tracking algorithm          */
#define TOUCH_BASE_CAPACITANCE_DECIMATION_FACTOR 10

/* Count Delta by which base capacitance must increase above to register a  */
/* touch and decrease below to register a release (difference = hysteresis  */

#define TOUCH_PRESSED_THRESHOLD      100
#define TOUCH_RELEASED_THRESHOLD     15

#define CE_PROBE_PRESS_COUNT_DELTA   100

#define TOUCH_BLANKING_TIME_MS       100
#define TOUCH_MS_PER_TICK            10


/* filter parameters */
#define GAIN                 2.400388646e+03
#define SCALING_FACTOR_BITS  8
#define SCALING_FACTOR       256
#define NZEROS               4
#define NPOLES               4

#define FIR_B1  ( (int32)(-0.4382651423  * SCALING_FACTOR) )
#define FIR_B2  ( (int32)( 2.1121553551  * SCALING_FACTOR) )
#define FIR_B3  ( (int32)(-3.8611943490  * SCALING_FACTOR) )
#define FIR_B4  ( (int32)( 3.1806385489  * SCALING_FACTOR) )

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

typedef struct
{
    uint32 *pu32BaseCapacitance;
    uint32 u32NewMeasurement;
} tsTouchSliderElement;

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/

static uint32 u32TouchReadRaw(uint32 u32InputMask, uint32 u32OutputMask);
static uint32 u32TouchReadCapacitance(uint32 u32Button, uint32 u32Mask, bool bSmooth);
static void vTouchUpdateBaseCapacitance(uint32 u32Button, uint32 u32NewMeasurement);
static void vTouchButton(tsTouchSliderElement* psElement, uint8 u8Button);

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
uint32 u32GoodSelectKeyPress = 0;
/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

static uint32 u32BaseMeasureSamples = 0;
static uint32 au32BaseCapacitances[TOUCH_SENSOR_COUNT];

/****************************************************************************/
/***        Local Constants                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Functions                                      ***/
/****************************************************************************/

static void vTouchInitHardware(void)
{

    /* Set up timer with 0 prescaling, no interrupts */
    vAHI_TimerEnable(TOUCH_TIMER, 0, FALSE, FALSE, FALSE);

    /* Reclaim the GPIO */
    vAHI_TimerDIOControl(TOUCH_TIMER, FALSE);

    /* Start timer */
    vAHI_TimerStartRepeat(TOUCH_TIMER, 65535, 65535);

    /* Set all pins as outputs */
    vAHI_DioSetDirection(0, TOUCH_DIO_MASK | TOUCH_DEBUG_DIO_MASK);

    /* Set all pins low */
    vAHI_DioSetOutput(0, TOUCH_DIO_MASK);

    /* Disable the pullups */
    vAHI_DioSetPullup(0, TOUCH_DIO_MASK);
}

teTouchStatus eTouchInit(void)
{
    volatile uint32 i, j;

    vTouchInitHardware();

    u32BaseMeasureSamples = TOUCH_BASE_CAPACITANCE_MEASURE_SAMPLES;

    for (i = 0; i < 32000; i++);

        for (i = 1, j = 0; i != 0; i <<= 1)
        {
            if (i & TOUCH_DIO_MASK)
            {
            au32BaseCapacitances[j] = u32TouchReadCapacitance(j, i, FALSE);
                j++;
            }
        }


    return TOUCH_STATUS_OK;
}

teTouchStatus eTouchSleep(void)
{
    /* About to sleep - remember that we'll need to sample enough times after wakeup */
    u32BaseMeasureSamples = TOUCH_BASE_CAPACITANCE_MEASURE_SAMPLES;

    /* Set all pins low */
    vAHI_DioSetOutput(0, TOUCH_DIO_MASK);
    return TOUCH_STATUS_OK;
}

teTouchStatus eTouchWake(void)
{

    u32BaseMeasureSamples = 0;

    /* Ensure our DIO config is still there.. */

    vTouchInitHardware();

    return TOUCH_STATUS_OK;
}

teTouchStatus eTouchProcess(void)
{

    uint32 i, j;
    uint32 u32MeasuredCapacitance;

    /* Read all of the capacitances first - important to do this relatively quickly
     * So that we get a jipshot in time of the slider
     */

    for (i = 1, j = 0; i != 0; i <<= 1)
    {
        if (i & TOUCH_DIO_MASK)
        {
            u32MeasuredCapacitance = u32TouchReadCapacitance(j, i, TRUE);
            vTouchUpdateBaseCapacitance(j, u32MeasuredCapacitance);
        }

        if (i & TOUCH_DIO_MASK_BUTTONS)
        {
            tsTouchSliderElement sButton;
            sButton.u32NewMeasurement = u32MeasuredCapacitance;
            sButton.pu32BaseCapacitance = &au32BaseCapacitances[j];
            vTouchButton(&sButton,(uint8) j);
            j++;
        }
    }

    if (u32BaseMeasureSamples)
    {
        /* Decrement the number of samples to wait before generating output */
        u32BaseMeasureSamples--;
        return TOUCH_STATUS_DONT_SLEEP;
    }

    return TOUCH_STATUS_OK;
}

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/


/** Function to read the raw capacitance present on a pin.
 *  The DIO lines are all set high in \ref Touch_init().
 *  Here we set the pin to an input an measure how long it statys high.
 *  \param u32Mask   GPIO mask of the pin to measure.
 *  \return a number of counts that will change dependant upon capacitance
 */
static uint32 u32TouchReadRaw(uint32 u32InputMask, uint32 u32OutputMask)
{
    uint16  u16TimerCountAfter;
    uint16  u16TimerCountBefore;
    uint32  u32DecayTime;
    uint32  u32RiseTime;
    uint32  u32InterruptsSave;

    /* Make the pin we're interested in an input */
    vAHI_DioSetDirection(u32InputMask, 0);

    /* First measure the rise time */

    /* Disable interrupts to make sure nothing puts us off.. */
    MICRO_DISABLE_AND_SAVE_INTERRUPTS(u32InterruptsSave);

    u16TimerCountBefore = u16AHI_TimerReadCount(TOUCH_TIMER);


#ifdef TOUCH_DEBUG_DIO
    vAHI_DioSetOutput(0, TOUCH_DEBUG_DIO_MASK);
#endif /* TOUCH_DEBUG_DIO */

    /* Corresponding pin high */
    vAHI_DioSetOutput(u32OutputMask, 0);

    /* Now we wait for the charge on the pin to rise ..... */
    while ((u32AHI_DioReadInput() & u32InputMask) == 0);
    u16TimerCountAfter = u16AHI_TimerReadCount(TOUCH_TIMER);

#ifdef TOUCH_DEBUG_DIO
    vAHI_DioSetOutput(TOUCH_DEBUG_DIO_MASK, 0);
#endif /* TOUCH_DEBUG_DIO */

    /* Now we can put interrupts back */
    MICRO_RESTORE_INTERRUPTS(u32InterruptsSave);

    /* Now, to process the time into a measurement */
    if (u16TimerCountAfter > u16TimerCountBefore)
    {
        /* Normal case, the timer has not wrapped */
        u32RiseTime = u16TimerCountAfter - u16TimerCountBefore;
    }
    else
    {
        u32RiseTime = ((uint32)u16TimerCountAfter + 65536) - u16TimerCountBefore;
    }

    /* Now, measure the fall time */

    /* Disable interrupts to make sure nothing puts us off.. */
    MICRO_DISABLE_AND_SAVE_INTERRUPTS(u32InterruptsSave);

    u16TimerCountBefore = u16AHI_TimerReadCount(TOUCH_TIMER);


#ifdef TOUCH_DEBUG_DIO
    vAHI_DioSetOutput(0, TOUCH_DEBUG_DIO_MASK);
#endif /* TOUCH_DEBUG_DIO */

    /* Corresponding pin low */
    vAHI_DioSetOutput(0, u32OutputMask);

    /* Now we wait for the charge on the pin to fall again ..... */
    while (u32AHI_DioReadInput() & u32InputMask);
    u16TimerCountAfter = u16AHI_TimerReadCount(TOUCH_TIMER);

#ifdef TOUCH_DEBUG_DIO
    vAHI_DioSetOutput(TOUCH_DEBUG_DIO_MASK, 0);
#endif /* TOUCH_DEBUG_DIO */

    /* Now we can put interrupts back */
    MICRO_RESTORE_INTERRUPTS(u32InterruptsSave);

    /* Now, to process the time into a measurement */
    if (u16TimerCountAfter > u16TimerCountBefore)
    {
        /* Normal case, the timer has not wrapped */
        u32DecayTime = u16TimerCountAfter - u16TimerCountBefore;
    }
    else
    {
        u32DecayTime = ((uint32)u16TimerCountAfter + 65536) - u16TimerCountBefore;
    }

    /* Now put the pin back to an output and drive lo*/
    vAHI_DioSetDirection(0, u32InputMask);
    vAHI_DioSetOutput(0, u32InputMask);

    return  (u32RiseTime + u32DecayTime);
}

/** Function to read the capacitance present on a pin.
 *  This function implements the smooting of the raw input data.
 *  It may be rolling average of low-pass filter.
 *  \param u32Button Button number (0-(TOUCH_SENSOR_COUNT-1))
 *  \param u32Mask   GPIO mask of the pin to measure.
 *  \param bSmooth   TRUE to apply smoothing function to raw data
 *  \return a number of counts that will change dependant upon capacitance
 */
static uint32 u32TouchReadCapacitance(uint32 u32Button, uint32 u32Mask, bool bSmooth)
{
    uint32 u32Raw,u32Smooth;

    static int32 xv[TOUCH_SENSOR_COUNT][NZEROS+1], yv[TOUCH_SENSOR_COUNT][NPOLES+1];

    u32Raw = u32TouchReadRaw(u32Mask, (u32Button & 1) ? u32Mask >> 1 : u32Mask << 1);

    xv[u32Button][0] = xv[u32Button][1];
    xv[u32Button][1] = xv[u32Button][2];
    xv[u32Button][2] = xv[u32Button][3];
    xv[u32Button][3] = xv[u32Button][4];
    xv[u32Button][4] = (int32)u32Raw;
    yv[u32Button][0] = yv[u32Button][1];
    yv[u32Button][1] = yv[u32Button][2];
    yv[u32Button][2] = yv[u32Button][3];
    yv[u32Button][3] = yv[u32Button][4];

    yv[u32Button][4] = (xv[u32Button][0] + xv[u32Button][4]) +
                       (4 * (xv[u32Button][1] + xv[u32Button][3])) +
                       (6 *  xv[u32Button][2]);

    yv[u32Button][4] += (((FIR_B1 * yv[u32Button][0]) +
                          (FIR_B2 * yv[u32Button][1]) +
                          (FIR_B3 * yv[u32Button][2]) +
                          (FIR_B4 * yv[u32Button][3])) >> 8);

    u32Smooth = yv[u32Button][4] >> 11;

    return (bSmooth) ? u32Smooth : u32Raw;
}

/** Function to update the base capacitance of a pin with a new value.
 *  This function implements a smoothing algorithm for the base capacitance.
 *  \param u32Button   Button number (0-(TOUCH_SENSOR_COUNT-1))
 *  \param u32NewMeasurement New base capacitance measurement
 */
static void vTouchUpdateBaseCapacitance(uint32 u32Button, uint32 u32NewMeasurement)
{
    static uint32 u32UpdateCount = 0;

    if (u32Button == 0)
    {
        u32UpdateCount++;
    }

    if (u32UpdateCount <= TOUCH_BASE_CAPACITANCE_DECIMATION_FACTOR)
    {
        return;
    }

    if (u32NewMeasurement > au32BaseCapacitances[u32Button])
    {
        au32BaseCapacitances[u32Button]++;
    }
    else if (u32NewMeasurement !=  au32BaseCapacitances[u32Button])
    {
        au32BaseCapacitances[u32Button]--;
        au32BaseCapacitances[u32Button] = ((3*au32BaseCapacitances[u32Button]) + u32NewMeasurement) >> 2;
    }

    if (u32Button == (TOUCH_SENSOR_COUNT-1))
    {
        u32UpdateCount = 0;
    }
}

/** Function to determine if a button is pressed from the new measured sample
 *  and the known base capacitance for that pin.
 *  \param psElement   Pointer to new and base values for the pin.
 *  \return TRUE if button is pressed
 */
static void vTouchButton(tsTouchSliderElement* psElement, uint8 u8Button)
{
    int32 i32MeasuredCap;
    int32 i32BaseCap;
    int32 i32TripHi;
    int32 i32TripLo;

    static uint32 u32BlankingTimer = 0;

    static uint32 u32ButtonState =0; /* for tracking the states of all the buttons */

    i32BaseCap = (int32)*(psElement->pu32BaseCapacitance);

    i32MeasuredCap = ((int32)psElement->u32NewMeasurement);

    i32TripHi = i32BaseCap + TOUCH_PRESSED_THRESHOLD;
    i32TripLo = i32BaseCap + TOUCH_RELEASED_THRESHOLD;

    /* Check if application provides call-back function before attempting to use it */
    if (vCbTouchEventButton)
    {
        /* comparator with spatial and temporal hysteresis */
        if (u32BlankingTimer ==0)
        {
            if ( (i32MeasuredCap > i32TripHi) && (u32ButtonState==0))
            {
                vCbTouchEventButton(TOUCH_BUTTON_EVENT_PRESSED, u8Button);
                u32ButtonState |= (1<<u8Button);
                u32BlankingTimer = (TOUCH_BLANKING_TIME_MS * TOUCH_SENSOR_COUNT)/TOUCH_MS_PER_TICK;
            }

            if ((i32MeasuredCap < i32TripLo) && ( (u32ButtonState & (1<<u8Button)) !=0) )
            {
                vCbTouchEventButton(TOUCH_BUTTON_EVENT_RELEASED, u8Button);
                u32ButtonState &= ~(1 << u8Button);
                if (u32ButtonState == 0)
                {
                    vCbTouchEventButton(TOUCH_BUTTON_EVENT_ALL_RELEASED, 0);
                }
                u32BlankingTimer = (TOUCH_BLANKING_TIME_MS * TOUCH_SENSOR_COUNT)/TOUCH_MS_PER_TICK;
             }
        }
       else
        {
            u32BlankingTimer--;
        }
    }

    if (u8Button == 15)
    {
        if (i32MeasuredCap > i32TripHi)
        {
            i32MeasuredCap -= i32BaseCap;
            u32GoodSelectKeyPress = (i32MeasuredCap > CE_PROBE_PRESS_COUNT_DELTA) ? 1UL : 0UL;
        }
    }

}

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

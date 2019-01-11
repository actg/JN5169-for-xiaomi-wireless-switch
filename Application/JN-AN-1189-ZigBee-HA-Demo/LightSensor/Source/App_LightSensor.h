/*****************************************************************************
 *
 * MODULE:             JN-AN-1189
 *
 * COMPONENT:          App_LightSensor.h
 *
 * DESCRIPTION:        ZHA Demo Light Sensor -Implementation
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
 * Copyright NXP B.V. 2012. All rights reserved
 *
 ***************************************************************************/

#ifndef APP_OCCUPANCY_SENSOR_H
#define APP_OCCUPANCY_SENSOR_H

#include "light_sensor.h"
#include "zcl_options.h"

/****************************************************************************/
/***        Macro Definition                                              ***/
/****************************************************************************/
#define LIGHT_SENSOR_MINIMUM_MEASURED_VALUE                            0x0001
#define LIGHT_SENSOR_MAXIMUM_MEASURED_VALUE                            0xFAF
#define LIGHT_SENSOR_MINIMUM_REPORTABLE_CHANGE                         0x01
#define LIGHT_SENSOR_SAMPLING_TIME_IN_SECONDS                          5
#define APP_TICKS_PER_SECOND    32000
#define APP_JOINING_BLINK_TIME            (APP_TIME_MS(1000))
#define APP_FIND_AND_BIND_BLINK_TIME     (APP_TIME_MS(500))
#define APP_KEEP_AWAKE_TIME                (APP_TIME_MS(250))

/* Only one reportable attribute : MeasuredValue */
#define LIGHT_SENSOR_NUMBER_OF_REPORTS                                 1
#define LED_LEVEL                                                      20
#define LED_MAX_LEVEL                                                  255
#define LED_MIN_LEVEL                                                  0

#define FAILED_POLL_COUNT                                3
#define FAILED_REJOIN_COUNT                                3
/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/
extern tsHA_LightSensorDevice sSensor;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

void vAPP_ZCL_DeviceSpecific_Init(void);
teZCL_Status eApp_HA_RegisterEndpoint(tfpZCL_ZCLCallBackFunction fptr);
PUBLIC void vAPP_ZCL_DeviceSpecific_UpdateIdentify(void);
PUBLIC void vAPP_ZCL_DeviceSpecific_SetIdentifyTime(uint16 u16Time);
PUBLIC void vAPP_ZCL_DeviceSpecific_IdentifyOff(void);
PUBLIC void vAPP_LightSensorSample(void);

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

#endif /* APP_OCCUPANCY_SENSOR_H */

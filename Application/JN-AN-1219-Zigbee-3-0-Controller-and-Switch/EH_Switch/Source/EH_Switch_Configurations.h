/*****************************************************************************
 *
 * MODULE:             JN-AN-1219
 *
 * COMPONENT:          EH_Switch_Configurations.h
 *
 * AUTHOR:             Rajeena
 *
 * DESCRIPTION:        ZigBee EH switch application
 *
 ****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products [NXP Microcontrollers such as JN5168, JN5179].
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
 * Copyright NXP B.V. 2016. All rights reserved
 *
 ***************************************************************************/

#ifndef EH_SWITCH_CONFIGURATIONS_H_
#define EH_SWITCH_CONFIGURATIONS_H_


#include "EH_IEEE_802154_Switch.h"




/****************************************************************************/
/***       Common Configuration                                           ***/
/****************************************************************************/
/** This macro should contain default operating channel of device. may override during commissioning */
#define GPD_DEFAULT_CHANNEL                             (11)
#define GPD_FIXED
#ifdef LITTLE_ENDIAN_PROCESSOR
#define vMemRevCpy  memcpy
#endif
/** The number of commands send in a channel */
#define GPD_NO_OF_COMMANDS_IN_OPERATIONAL_CHANNEL       (3)

/** If data need to be stored in persistent memory, the below macro need to be configured */
#define GPD_SUPPORT_PERSISTENT_DATA


 /* 4 byte GPD source address  */
#define GPD_SOURCE_ID                                   (0x87654321UL)


/** If data need to be secured, the below macro need to be configured */
#define GPD_WITH_SECURITY


/** This macro should contain initial pan id of device, pan id may override during commissioning*/
#define GPD_DEFAULT_PANID                               (0xFFFF)

#define GPD_MAX_PAYLOAD                                 (40)
#ifdef  GPD_WITH_SECURITY
        /** The security level supported on switch   */
        #define                                         GPD_SECURITY_LEVEL_FC_4B_MIC_4B_WITH_ENC
#ifdef DK4
        /** This macro defines the key type  */
        #define GPD_KEY_TYPE                            (E_GPD_INDIVIDUAL_KEY)
#else
        #define GPD_KEY_TYPE                            (E_GPD_GROUP_KEY)
#endif
        /** This macro defines the pre configured key  */
        #define GPD_KEY   { 0xC0 , 0xC1 , 0xC2 , 0xC3 , 0xC4 , 0xC5 , 0xC6 , 0xC7 , 0xC8 , 0xC9 , 0xCA , 0xCB , 0xCC , 0xCD , 0xCE , 0xCF };


#endif

/****************************************************************************/
/***       Configuration for DK4 switch( Rx capable,
* secured( key received from bulb), level control switch)                ***/
/****************************************************************************/
#ifdef DK4

     #define GPD_TYPE                                   (GP_LEVEL_CONTROL_SWITCH)

    /** This macro should be defined if channel request need to be send in commissioning mode */
     #define GPD_SEND_CHANNEL_REQUEST
    /** The number of channels, the channel request will be transmitted,
     * on a single button press */
    #define GPD_NO_OF_CHANNEL_PER_COMM_ATTEMPT          (1)


    #ifdef GPD_SEND_CHANNEL_REQUEST
        #define PRIMARY_CHANNELS                    11,15,20,25
            /* Note that enabling secondary channels will increase commissioning time.*/
        #define SECONDARY_CHANNELS                  12,13,14,16,17,18,19,21,22,23,24
    #endif


    /** This macro should be enabled on a device that is capable of receiving */
    #define GPD_RX_ENABLE
     /** This macro should be enabled on a device that is capable of receiving GPDF after
      * transmission  */
    #define GPD_RX_AFTER_TX

    /** The number of commands send on a channel before commissioning. The Rx capable device
     * will go to RX mode after transmitting GPD_NO_OF_REQ_BEFORE_RX packets */
    #define GPD_NO_OF_REQ_BEFORE_RX                     (1)

    /** This macro should be defined if pan id to be requested during commissioning on a
      Rx capable device. If this macro is not defined, pan Id GPD_DEFAULT_PANID will be used.*/
    #define GPD_REQ_PANID

    #ifdef GPD_RX_AFTER_TX
        /** The time duration in seconds for which receiver will be enabled for reception after
         * transmission. The minimum duration should be 0.576 ms */
        #define  GPD_RX_AFTER_TX_DURATION               (20UL)

    #endif

    #define MOVE_RATE                                   (65)


#endif

/****************************************************************************/
/***       Configuration for Energy Harvesting switch    ( Non Rx capable,
 * secured( with pre configured key)  on/off switch                    )                            ***/
/****************************************************************************/
    #ifndef DK4

        #define GPD_AUTOCOMMISSIOINING
        #ifdef DR1216
            #define GPD_TYPE                                    (GP_LEVEL_CONTROL_SWITCH)
            #define MOVE_RATE                                   (65)
        #else
            #define GPD_TYPE                                    (GP_ON_OFF_SWITCH)
        #endif

        /** This macro defines the key type  */


        /** This macro defines the pre configured key  */
        #define GPD_OOB_KEY   { 0xC0 , 0xC1 , 0xC2 , 0xC3 , 0xC4 , 0xC5 , 0xC6 , 0xC7 , 0xC8 , 0xC9 , 0xCA , 0xCB , 0xCC , 0xCD , 0xCE , 0xCF };
        /* Use Toggle command instead of ON/OFF command */
        /* #define GPD_SEND_TOGGLE_CMD */
    #endif

#endif /* EH_SWITCH_CONFIGURATIONS_H_ */
 /****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/


###########################################################################
#  Module Name:        Low level interrupt handler for JN5168 FreeRTOS port
#
#  Created By:         Ian Morris
#
#  Original Release:   January 21, 2010
#
#  Module Description: Handles interrupts required by FreeRTOS to switch
#                      tasks, automatically using the tick timer or
#                      manually using a system call.
#
###########################################################################

.globl  PIC_ChannelPriorities
    .section .text,"ax"
    .align 4
    .type   PIC_ChannelPriorities, @object
    .size   PIC_ChannelPriorities, 16
PIC_ChannelPriorities:
#ifdef DK2
    .byte 14                # pwm1 priority
#else
    .byte 0                # pwm1 priority
#endif
    .byte 0                 # pwm2 priority
    .byte 1                 # system controller priority
    .byte 7                 # MAC priority
    .byte 0                 # AES priority
    .byte 0                 # PHY priority
#ifdef DR1199
    .byte 5                 # uart0 priority
#else
    .byte 0                 # uart0 priority
#endif
    .byte 0                 # uart1 priority
    .byte 0                 # timer0 priority
    .byte 0                 # spi slave priority
    .byte 0                 # i2c maste/slave priority
    .byte 0                 # spi master priority
    .byte 0                 # pwm4 priority
    .byte 0                 # analog peripherals priority
    .byte 0                 # pwm3 priority
    .byte 15                # tick timer priority


.globl  PIC_SwVectTable
    .section .text,"ax"
    .extern zps_isrMAC
    .extern vISR_KeyScan
    .extern vISR_SystemController
    .extern ISR_vTickTimer
    .align 4
    .type   PIC_SwVectTable, @object
    .size   PIC_SwVectTable, 64
PIC_SwVectTable:
    .word vUnclaimedInterrupt               # 0
    .word vISR_SystemController             # 1
    .word vUnclaimedInterrupt               # 2
    .word vUnclaimedInterrupt               # 3
    .word vUnclaimedInterrupt               # 4
#ifdef DR1199
    .word APP_isrUart                       # 5
#else
    .word vUnclaimedInterrupt               # 5
#endif
    .word vUnclaimedInterrupt               # 6
    .word zps_isrMAC                        # 7
    .word vUnclaimedInterrupt               # 8
    .word vUnclaimedInterrupt               # 9
    .word vUnclaimedInterrupt               # 10
    .word vUnclaimedInterrupt               # 11
    .word vUnclaimedInterrupt               # 12
    .word vUnclaimedInterrupt               # 13
#ifdef DK2
    .word vISR_KeyScan                      # 14
#else
    .word vUnclaimedInterrupt               # 14
#endif
    .word ISR_vTickTimer                    # 15


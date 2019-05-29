###############################################################################
#
# MODULE:   Makefile
#
# DESCRIPTION: Makefile for the ZLL Controller (e.g., Remote) devices
# 
 ############################################################################
#
# This software is owned by NXP B.V. and/or its supplier and is protected
# under applicable copyright laws. All rights are reserved. We grant You,
# and any third parties, a license to use this software solely and
# exclusively on NXP products [NXP Microcontrollers such as JN5168, JN5179].
# You, and any third parties must reproduce the copyright and warranty notice
# and any other legend of ownership on each copy or partial copy of the
# software.
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
# Copyright NXP B.V. 2016. All rights reserved
#
###############################################################################

REMOTE ?= ColorSceneController

# Application target name
TARGET = $(REMOTE)
PDM_BUILD_TYPE ?=_EEPROM

###############################################################################
#User definable make parameters that may be overwritten from the command line

# Default target device is the JN5168

JENNIC_CHIP_FAMILY ?= JN517x
JENNIC_CHIP ?= JN5179

ifeq ($(JENNIC_CHIP_FAMILY), JN517x)
JENNIC_SDK              = JN-SW-4270
ZNCLKCMD                = AppBuildZBPro.ld
ENDIAN                  = LITTLE_ENDIAN_PROCESSOR
else 
ifeq ($(JENNIC_CHIP_FAMILY), JN516x)
JENNIC_SDK              = JN-SW-4170
ZNCLKCMD                = AppBuildZBPro.ld
ENDIAN 	                = BIG_ENDIAN
endif
endif


STACK_SIZE = 5000
MINIMUM_HEAP_SIZE = 2000
###############################################################################
# Default DK2 development kit target hardware
DR ?= DK2
ifeq ($(DR), DR1199)
JENNIC_PCB ?= DEVKIT4
CFLAGS  += -DBUTTON_MAP_DR1199
# dont sleep if using the serial interface
#CFLAGS += -DSLEEP_ENABLE
endif

ifeq ($(DR), DR1159)
# Remote control hardware
JENNIC_PCB ?= DEVKIT2
CFLAGS += -DSLEEP_ENABLE
endif

CFLAGS  += -D$(DR)

###############################################################################
# Network settings

# Optional network.mk for channel
sinclude ../../../network.mk

# Channel (0 for default channels)
SINGLE_CHANNEL ?= 0
CFLAGS         += -DSINGLE_CHANNEL=$(SINGLE_CHANNEL)

###############################################################################
# Select the network stack (e.g. MAC, ZBPro, ZCL)

JENNIC_STACK ?= ZCL
JENNIC_MAC ?= MiniMacShim

###############################################################################
# ZBPro Stack specific options
ZBPRO_DEVICE_TYPE ?= ZED
#PDM_BUILD_TYPE ?= _EXTERNAL_FLASH
PDM_BUILD_TYPE ?=_EEPROM
APP_CLUSTER_LIGHTING_SRC ?= 1
APP_CLUSTER_COMMISSIONING_SRC ?= 1

# BDB features � Enable as required
BDB_SUPPORT_TOUCHLINK_INITIATOR_END_DEVICE ?= 1
#BDB_SUPPORT_TOUCHLINK_INITIATOR_ROUTER ?= 1
#BDB_SUPPORT_TOUCHLINK_TARGET ?= 1
BDB_SUPPORT_NWK_STEERING ?= 1
#BDB_SUPPORT_NWK_FORMATION ?= 1
BDB_SUPPORT_FIND_AND_BIND_INITIATOR ?= 1
#BDB_SUPPORT_FIND_AND_BIND_TARGET ?= 1

ifeq ($(JENNIC_CHIP_FAMILY),JN517x)
INTERRUPT_HANDLER_BBC = zps_isrMAC
LDFLAGS += -Wl,-u$(INTERRUPT_HANDLER_BBC) -Wl,-defsym,vAHI_IntHandlerBbc_select=$(INTERRUPT_HANDLER_BBC)
endif


###############################################################################
# Debug options define DEBUG either HW or SW
#DEBUG ?=SW
#DEBUG ?=HW
#
# Define which UART to use for HW debug
DEBUG_PORT ?= UART1
#  DEBUG_MODE  ?=  SWD    # For ARM core

###############################################################################
# Define TRACE to use with DBG module
TRACE ?=1
ifeq ($(TRACE), 1)
CFLAGS  += -DDBG_ENABLE
endif


#Set defalt to sleep unless overridden from build configs
INHIBIT_DEEP_SLEEP ?= FALSE
CFLAGS += -DNEVER_DEEP_SLEEP=$(INHIBIT_DEEP_SLEEP)




CFLAGS += -D$(TARGET)



CFLAGS += -DDEBUG_APP
#CFLAGS += -DDEBUG_ZCL
#CFLAGS += -DDEBUG_CLD_ONOFF
#CFLAGS += -DDEBUG_CAPTOUCH
#CFLAGS += -DDEBUG_APP_BUTTON
#CFLAGS += -DDEBUG_ZTIMER
#CFLAGS += -DDEBUG_APP_BUTTON

CFLAGS += -DDEBUG_START_UP
#CFLAGS += -DDEBUG_REMOTE_NODE
#CFLAGS += -DDEBUG_REMOTE_TASK
#CFLAGS += -DDEBUG_SCAN
#CFLAGS += -DDEBUG_JOIN
#CFLAGS += -DDEBUG_COMMISSION
#CFLAGS += -DDEBUG_CLASSIC_JOIN
#CFLAGS += -DDEBUG_SCAN_REQ   
#CFLAGS += -DDEBUG_TL_NEGATIVE
#CFLAGS += -DDEBUG_LIGHT_AGE

#CFLAGS += -DDEBUG_REJOIN
#CFLAGS += -DDEBUG_SLEEP

#CFLAGS  += -DSTRICT_PARAM_CHECK

###############################################################################
# Path definitions

# Use if application directory contains multiple targets
SDK_BASE_DIR        = $(abspath ../../../../sdk/$(JENNIC_SDK))
APP_BASE            = $(abspath ../..)
APP_BLD_DIR         = $(APP_BASE)/Common_Controller/Build
APP_SRC_DIR         = $(APP_BASE)/Common_Controller/Source
DEV_BLD_DIR         = $(APP_BASE)/$(TARGET)/Build
DEV_SRC_DIR         = $(APP_BASE)/$(TARGET)/Source
HW_SRC_DIR			= $(COMPONENTS_BASE_DIR)/HardwareAPI/Source

#Generic Low Battery Indicator module (SVN external)
APP_LBI_SRC_DIR  = $(APP_BASE)/Common_Controller/Source/LBI

APP_COMMON_SRC_DIR  = $(APP_BASE)/Common/Source

###############################################################################
# Application Source files

# Note: Path to source file is found using vpath below, so only .c filename is required

ifeq ($(JENNIC_CHIP_FAMILY), JN517x)
APPSRC = port_JN517x.c
endif
ifeq ($(JENNIC_CHIP_FAMILY), JN516x)
APPSRC = irq_JN516x.S
APPSRC += portasm_JN516x.S
APPSRC += port_JN516x.c
endif

APPSRC += app_main.c
APPSRC += pdum_gen.c
APPSRC += pdum_apdu.S
APPSRC += zps_gen.c
APPSRC += app_led_control.c
APPSRC += app_start_controller.c
ifeq ($(JENNIC_CHIP_FAMILY), JN517x)
APPSRC += AHI_ModuleConfiguration.c 
endif

APPSRC += App_$(TARGET).c
APPSRC += zlo_controller_node.c
APPSRC += app_zcl_controller_task.c


ifeq ($(DR), DR1199)
APPSRC += uart.c
APPSRC += app_serial_interface.c
APPSRC += app_buttons.c
APPSRC += app_menu_handler_DR1199.c
endif

ifeq ($(DR), DR1159)
APPSRC += app_menu_handler_DR1159.c
APPSRC += app_captouch_buttons.c
APPSRC += DriverCapTouch.c
APPSRC += low_bat_indicator.c
endif

APPSRC += app_on_off_commands.c
APPSRC += app_level_commands.c
APPSRC += app_colour_commands.c
APPSRC += app_scenes_commands.c
APPSRC += app_group_commands.c
APPSRC += app_identify_commands.c
APPSRC += app_general_commands.c

APP_ZPSCFG = app.zpscfg

# Construct binary hardware list

TARGET_HARDWARE:=_$(JENNIC_CHIP)_$(DR)

ifneq ($(SINGLE_CHANNEL), 0)
TARGET_HARDWARE:=$(TARGET_HARDWARE)_CH$(SINGLE_CHANNEL)
endif

OPTIONAL_STACK_FEATURES = $(shell $(ZPSCONFIG) -n $(TARGET) -f $(APP_COMMON_SRC_DIR)/$(APP_ZPSCFG) -y )

###############################################################################
# Standard Application header search paths

INCFLAGS += -I$(APP_SRC_DIR)
INCFLAGS += -I$(APP_SRC_DIR)/..
INCFLAGS += -I$(DEV_SRC_DIR)
INCFLAGS += -I$(APP_COMMON_SRC_DIR)


# Application specific include files
INCFLAGS += -I$(COMPONENTS_BASE_DIR)/ZigbeeCommon/Include
INCFLAGS += -I$(COMPONENTS_BASE_DIR)/ZCL/Include
INCFLAGS += -I$(COMPONENTS_BASE_DIR)/ZCIF/Include
INCFLAGS += -I$(COMPONENTS_BASE_DIR)/HardwareAPI/Include

INCFLAGS += -I$(APP_LBI_SRC_DIR)


###############################################################################
# Application libraries
# Specify additional Component libraries

#APPLIBS +=

###############################################################################

# You should not need to edit below this line

###############################################################################
###############################################################################
# Configure for the selected chip or chip family

include $(SDK_BASE_DIR)/Chip/Common/Build/config.mk
include $(SDK_BASE_DIR)/Platform/Common/Build/config.mk
include $(SDK_BASE_DIR)/Stack/Common/Build/config.mk
include $(SDK_BASE_DIR)/Components/BDB/Build/config.mk

###############################################################################

TEMP = $(APPSRC:.c=.o)
APPOBJS_TMP = $(TEMP:.S=.o)
APPOBJS := $(addprefix $(DEV_BLD_DIR)/,$(APPOBJS_TMP))

###############################################################################
# Application dynamic dependencies

APPDEPS_TMP = $(APPOBJS_TMP:.o=.d)
APPDEPS := $(addprefix $(DEV_BLD_DIR)/,$(APPDEPS_TMP))

###############################################################################
# Linker

# Add application libraries before chip specific libraries to linker so
# symbols are resolved correctly (i.e. ordering is significant for GCC)

APPLDLIBS := $(foreach lib,$(APPLIBS),$(if $(wildcard $(addprefix $(COMPONENTS_BASE_DIR)/Library/lib,$(addsuffix _$(JENNIC_CHIP).a,$(lib)))),$(addsuffix _$(JENNIC_CHIP),$(lib)),$(addsuffix _$(JENNIC_CHIP_FAMILY),$(lib))))
LDLIBS := $(APPLDLIBS) $(LDLIBS)
LDLIBS += JPT_$(JENNIC_CHIP)

###############################################################################
# Dependency rules

.PHONY: all clean
# Path to directories containing application source
vpath % $(APP_SRC_DIR):$(APP_COMMON_SRC_DIR):$(ZCL_SRC_DIRS):$(ZCL_SRC):$(UTIL_SRC_DIR):$(BDB_SRC_DIR):$(DEV_SRC_DIR):$(APP_LBI_SRC_DIR):$(HW_SRC_DIR)


all: $(DEV_BLD_DIR)/$(TARGET)$(TARGET_HARDWARE).bin

-include $(APPDEPS)
$(DEV_BLD_DIR)/%.d:
	rm -f $*.o

ifeq ($(JENNIC_CHIP_FAMILY),JN517x)
$(DEV_SRC_DIR)/pdum_gen.c $(DEV_SRC_DIR)/pdum_gen.h: $(APP_COMMON_SRC_DIR)/$(APP_ZPSCFG) $(PDUMCONFIG)
	$(info Configuring the PDUM ...)
	$(PDUMCONFIG) -z $(TARGET)  -e $(ENDIAN) -f $< -o $(DEV_SRC_DIR)
	@echo


$(DEV_SRC_DIR)/zps_gen.c $(DEV_SRC_DIR)/zps_gen.h: $(APP_COMMON_SRC_DIR)/$(APP_ZPSCFG) $(ZPSCONFIG)
	$(info Configuring the Zigbee Protocol Stack ...)
	$(ZPSCONFIG) -n $(TARGET) -t $(JENNIC_CHIP) -l $(ZPS_NWK_LIB) -a $(ZPS_APL_LIB) -c $(TOOL_COMMON_BASE_DIR)/$(TOOLCHAIN_PATH)  -e $(ENDIAN) -f $< -o $(DEV_SRC_DIR)
	@echo
$(DEV_BLD_DIR)/pdum_gen.o: CFLAGS += -fno-lto
$(DEV_BLD_DIR)/zps_gen.o: CFLAGS += -fno-lto
endif	

ifeq ($(JENNIC_CHIP_FAMILY),JN516x)
$(DEV_SRC_DIR)/pdum_gen.c $(DEV_SRC_DIR)/pdum_gen.h: $(APP_COMMON_SRC_DIR)/$(APP_ZPSCFG) $(PDUMCONFIG)
	$(info Configuring the PDUM ...)
	$(PDUMCONFIG) -z $(TARGET)  -f $< -o $(DEV_SRC_DIR)
	@echo


$(DEV_SRC_DIR)/zps_gen.c $(DEV_SRC_DIR)/zps_gen.h: $(APP_COMMON_SRC_DIR)/$(APP_ZPSCFG) $(ZPSCONFIG)
	$(info Configuring the Zigbee Protocol Stack ...)
	$(ZPSCONFIG) -n $(TARGET) -t $(JENNIC_CHIP) -l $(ZPS_NWK_LIB) -a $(ZPS_APL_LIB) -c $(TOOL_COMMON_BASE_DIR)/$(TOOLCHAIN_PATH) -f $< -o $(DEV_SRC_DIR)
	@echo
$(DEV_BLD_DIR)/pdum_gen.o: CFLAGS += -fno-lto
$(DEV_BLD_DIR)/zps_gen.o: CFLAGS += -fno-lto
endif


$(DEV_BLD_DIR)/%.o: %.S
	$(info Assembling $< ...)
	$(CC) -c -o $(subst Source,Build,$@) $(CFLAGS) $(INCFLAGS) $< -MD -MF $(DEV_BLD_DIR)/$*.d -MP
	@echo

$(DEV_BLD_DIR)/%.o: %.c
	$(info Compiling $< ...)
	$(CC) -c -o $(subst Source,Build,$@) $(CFLAGS) $(INCFLAGS) $< -MD -MF $(DEV_BLD_DIR)/$*.d -MP
	@echo

$(DEV_BLD_DIR)/$(TARGET)$(TARGET_HARDWARE).elf: $(APPOBJS) $(addsuffix.a,$(addprefix $(COMPONENTS_BASE_DIR)/Library/lib,$(APPLDLIBS))) 
	$(info Linking $@ ...)
	$(CC) -Wl,--gc-sections -Wl,-u_AppColdStart -Wl,-u_AppWarmStart $(LDFLAGS) -L $(SDK_BASE_DIR)/Stack/ZCL/Build/ -T$(ZNCLKCMD)  -o $@ -Wl,--start-group $(APPOBJS) $(addprefix -l,$(LDLIBS)) -lm -Wl,--end-group -Wl,-Map,$(DEV_BLD_DIR)/$(TARGET)$(TARGET_HARDWARE).map 
	$(SIZE) $@
	date +%c >> $(APP_BASE)/Doc/size.txt
	$(SIZE) $@ >> $(APP_BASE)/Doc/size.txt
	
ifeq ($(JENNIC_CHIP_FAMILY),JN517x)
$(DEV_BLD_DIR)/$(TARGET)$(TARGET_HARDWARE).bin: $(DEV_BLD_DIR)/$(TARGET)$(TARGET_HARDWARE).elf 
	$(info Generating binary ...)
	$(OBJCOPY) -S -O binary $< $@
else
$(DEV_BLD_DIR)/$(TARGET)$(TARGET_HARDWARE).bin: $(DEV_BLD_DIR)/$(TARGET)$(TARGET_HARDWARE).elf 
	$(info Generating binary ...)
	$(OBJCOPY) -j .version -j .bir -j .flashheader -j .vsr_table -j .vsr_handlers -j .rodata -j .text -j .data -j .bss -j .heap -j .stack -S -O binary $< $@
endif

###############################################################################

clean:
	rm -f $(APPOBJS) $(APPDEPS) $(DEV_BLD_DIR)/$(TARGET)$(TARGET_HARDWARE).bin $(DEV_BLD_DIR)/$(TARGET)$(TARGET_HARDWARE).elf $(DEV_BLD_DIR)/$(TARGET)$(TARGET_HARDWARE).map
	rm -f $(DEV_SRC_DIR)/pdum_gen.* $(DEV_SRC_DIR)/zps_gen*.*

###############################################################################

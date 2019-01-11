###############################################################################
#
# MODULE:   Makefile
#
# DESCRIPTION: Makefile for the ZHA Occupancy Sensor device
# 
 ############################################################################
#
# This software is owned by NXP B.V. and/or its supplier and is protected
# under applicable copyright laws. All rights are reserved. We grant You,
# and any third parties, a license to use this software solely and
# exclusively on NXP products [NXP Microcontrollers such as  JN5168, JN5164,
# JN5161, JN5148, JN5142, JN5139]. 
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
# Copyright NXP B.V. 2012. All rights reserved
#
############################################################################

SENSOR ?= OccupancySensor
CHANNEL ?= 0

# Application target name
TARGET = $(SENSOR)
PDM_BUILD_TYPE ?=_EEPROM
JENNIC_SDK ?= JN-SW-4168
###############################################################################
#User definable make parameters that may be overwritten from the command line

# Default target device is the JN5168

JENNIC_CHIP ?= JN5168

JENNIC_CHIP_FAMILY ?= JN516x

##############################################################################
# Stack size and Heap can be configured below

STACK_SIZE ?= 6000
MINIMUM_HEAP_SIZE ?= 2000

###############################################################################


###############################################################################
# Default DK4 development kit target hardware
JENNIC_PCB ?= DEVKIT4

DR ?= DR1199

KEEPALIVETIME ?= 6

ifeq ($(KEEPALIVETIME),0) 
#no need to do anything as the sleep will not be defined
else 
ifeq ($(KEEPALIVETIME),255)
CFLAGS += -DSLEEP_ENABLE
else
CFLAGS += -DSLEEP_ENABLE
endif
endif
CFLAGS += -D$(DR)
CFLAGS += -D$(SENSOR)

CFLAGS  += -DBUTTON_MAP_$(DR)

# Switch is an Initiator,
CFLAGS  += -DEZ_MODE_INITIATOR
#CFLAGS  += -DEZ_ENABLE_GROUP

###############################################################################
# Select the network stack (e.g. MAC, ZBPro, SE, HA)
JENNIC_STACK ?= ZLLHA
JENNIC_MAC ?= MiniMacShim
APP_CLUSTER_HA_LIGHTING_SRC ?=1
###############################################################################
# End device or router / coord (e.g. ZCR, ZED)
ZBPRO_DEVICE_TYPE ?= ZED

###############################################################################
# Debug options define DEBUG either HW or SW
#DEBUG ?=SW
#DEBUG ?=HW
#
# Define which UART to use for HW debug
DEBUG_PORT ?= UART0

###############################################################################
# Define TRACE to use with DBG module
TRACE ?=1
ifeq ($(TRACE), 1)
CFLAGS  += -DDBG_ENABLE
endif

APP_CLUSTER_LIGHTING_SRC ?=1
APP_CLUSTERS_MEASUREMENT_AND_SENSING ?=1
#APP_CLUSTERS_OTA_SRC ?=1
#APP_CLUSTERS_ENERGY_AT_HOME_SRC ?=1
#APP_CLUSTERS_GREENPOWER_SRC ?=1
#APP_CLUSTERS_HVAC_SRC ?=1
#APP_CLUSTERS_SMART_ENERGY_SRC ?=1
#APP_CLUSTERS_IAS_SRC ?=1


CFLAGS += -D$(TARGET)

##############################################################################
# For 4x use string based PDM id's for newer families use 16 bit id numbers
ifneq ($(JENNIC_CHIP_FAMILY), JN514x)
CFLAGS   += -DPDM_USER_SUPPLIED_ID
endif

###############################################################################

CFLAGS += -DNXP_HARDWARE
#CFLAGS += -DDEBUG_EZMODE
CFLAGS += -DDEBUG_ZCL
CFLAGS += -DDEBUG_CLD_ONOFF
CFLAGS += -DDEBUG_APP_BUTTON
CFLAGS += -DDEBUG_START_UP
CFLAGS += -DDEBUG_SENSOR_NODE
CFLAGS += -DDEBUG_SENSOR_TASK
CFLAGS += -DDEBUG_SCAN
CFLAGS += -DDEBUG_JOIN
CFLAGS += -DDEBUG_COMMISSION
CFLAGS += -DDEBUG_SENSOR_STATE
CFLAGS += -DDEBUG_SLEEP_HANDLER
CFLAGS += -DDEBUG_OCCUPANCY_SENSOR
CFLAGS += -DDEBUG_POLL_HANDLER
CFLAGS += -DDEBUG_PROCESS_BUTTONS
CFLAGS += -DDEBUG_ZCL_PROCESSING
CFLAGS += -DDEBUG_REPORT
CFLAGS += -DDEBUG_NWK_EVENT_HANDLER
CFLAGS += -DDEBUG_PIR_EVENTS

###############################################################################
# PIR Sensor Flags
# Specify additional Component libraries
#PIR_SENSOR_TYPE	    = PIR_TYPE_OPEN_COLLECTOR
PIR_SENSOR_TYPE	= PIR_TYPE_PWM

CFLAGS += -D$(PIR_SENSOR_TYPE)

###############################################################################

###############################################################################
# Path definitions

# Use if application directory contains multiple targets
SDK_BASE_DIR        = $(abspath ../../../../sdk/$(JENNIC_SDK))
APP_BASE            = $(abspath ../..)
APP_BLD_DIR         = $(APP_BASE)/$(TARGET)/Build
APP_SRC_DIR         = $(APP_BASE)/$(TARGET)/Source
APP_PIR_DIR         = $(APP_SRC_DIR)/PIR

APP_COMMON_SRC_DIR  = $(APP_BASE)/Common/Source
UTIL_SRC_DIR        = $(COMPONENTS_BASE_DIR)/Utilities/Source


###############################################################################
# Application Source files

# Note: Path to source file is found using vpath below, so only .c filename is required
APPSRC  = os_gen.c
APPSRC += os_irq.S
APPSRC += os_irq_alignment.S
APPSRC += os_irq_buserror.S
APPSRC += os_irq_illegalinstruction.S
APPSRC += os_irq_stackoverflowexception.S
APPSRC += os_irq_unimplementedmodule.S
APPSRC += pdum_gen.c
APPSRC += pdum_apdu.S
APPSRC += zps_gen.c
APPSRC += app_exceptions.c
APPSRC += app_pdm.c

APPSRC += app_reporting.c

APPSRC += app_timer_driver.c
APPSRC += app_start_sensor.c

APPSRC += app_zbp_utilities.c


APPSRC += App_$(TARGET).c
APPSRC += zha_sensor_node.c

APPSRC += app_zcl_sensor_task.c
APPSRC += app_occupancy_buttons.c
APPSRC += app_sensor_state_machine.c
APPSRC += appZpsBeaconHandler.c
APPSRC += app_sleep_handler.c
APPSRC += app_nwk_event_handler.c
APPSRC += app_event_handler.c
#APPSRC += app_PIR_events.c

ifeq ($(PIR_SENSOR_TYPE), PIR_TYPE_OPEN_COLLECTOR)
APPSRC += app_PIR_OpenCollector_events.c
else
ifeq ($(PIR_SENSOR_TYPE), PIR_TYPE_PWM)
APPSRC += app_PIR_pwm_events.c
endif
endif

APPSRC += app_zcl_tick_handler.c
APPSRC += app_blink_led.c

APPSRC += haEzJoin.c
APPSRC += haEzFindAndBind.c
APPSRC += haKeys.c

APPSRC += appZdpExtraction.c
APP_ZPSCFG = app.zpscfg

BIN_SUFFIX=_$(DR)

###############################################################################
# Standard Application header search paths

INCFLAGS += -I$(APP_SRC_DIR)
INCFLAGS += -I$(APP_SRC_DIR)/..
INCFLAGS += -I$(APP_COMMON_SRC_DIR)

INCFLAGS += -I$(APP_PIR_DIR)

# Application specific include files
INCFLAGS += -I$(COMPONENTS_BASE_DIR)/Utilities/Include
INCFLAGS += -I$(COMPONENTS_BASE_DIR)/ZCL/Include

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
include $(SDK_BASE_DIR)/Platform/Common/Build/Config.mk
include $(SDK_BASE_DIR)/Stack/Common/Build/config.mk

###############################################################################

TEMP = $(APPSRC:.c=.o)
APPOBJS_TMP = $(TEMP:.S=.o)
APPOBJS := $(addprefix $(APP_BLD_DIR)/,$(APPOBJS_TMP))

###############################################################################
# Application dynamic dependencies

APPDEPS_TMP = $(APPOBJS_TMP:.o=.d)
APPDEPS := $(addprefix $(APP_BLD_DIR)/,$(APPDEPS_TMP))

###############################################################################
# Linker

# Add application libraries before chip specific libraries to linker so
# symbols are resolved correctly (i.e. ordering is significant for GCC)

APPLDLIBS := $(foreach lib,$(APPLIBS),$(if $(wildcard $(addprefix $(COMPONENTS_BASE_DIR)/Library/lib,$(addsuffix _$(JENNIC_CHIP).a,$(lib)))),$(addsuffix _$(JENNIC_CHIP),$(lib)),$(addsuffix _$(JENNIC_CHIP_FAMILY),$(lib))))
LDLIBS := $(APPLDLIBS) $(LDLIBS)
###############################################################################
# Dependency rules

.PHONY: all clean
# Path to directories containing application source
vpath % $(APP_SRC_DIR):$(APP_COMMON_SRC_DIR):$(APP_PIR_DIR):$(HA_SRC_DIRS):$(ZCL_SRC):$(UTIL_SRC_DIR)


all: $(APP_BLD_DIR)/$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).bin

-include $(APPDEPS)
#$(APP_BLD_DIR)/%.d:
#	rm -f $*.o

$(APP_SRC_DIR)/os_gen.c $(APP_SRC_DIR)/os_gen.h $(APP_SRC_DIR)/os_irq.S $(APP_SRC_DIR)/os_irq_alignment.S $(APP_SRC_DIR)/os_irq_buserror.S $(APP_SRC_DIR)/os_irq_illegalinstruction.S $(APP_SRC_DIR)/os_irq_stackoverflowexception.S $(APP_SRC_DIR)/os_irq_unimplementedmodule.S: $(APP_SRC_DIR)/App_ZHA_$(SENSOR)_$(JENNIC_CHIP_FAMILY).oscfgdiag $(OSCONFIG)
	$(info Configuring the OS ...)
	$(OSCONFIG) -f $< -o $(APP_SRC_DIR) -v $(JENNIC_CHIP)
	@echo

$(APP_SRC_DIR)/pdum_gen.c $(APP_SRC_DIR)/pdum_gen.h: $(APP_COMMON_SRC_DIR)/$(APP_ZPSCFG) $(PDUMCONFIG)
	$(info Configuring the PDUM ...)
	$(PDUMCONFIG) -z $(TARGET) -f $< -o $(APP_SRC_DIR)
	@echo

$(APP_SRC_DIR)/zps_gen.c $(APP_SRC_DIR)/zps_gen.h: $(APP_COMMON_SRC_DIR)/$(APP_ZPSCFG) $(ZPSCONFIG)
	$(info Configuring the Zigbee Protocol Stack ...)
	$(ZPSCONFIG) -n $(TARGET) -t $(JENNIC_CHIP) -l $(ZPS_NWK_LIB) -a $(ZPS_APL_LIB) -c $(TOOL_COMMON_BASE_DIR)/$(TOOLCHAIN_PATH) -f $< -o $(APP_SRC_DIR)
	@echo

$(APP_BLD_DIR)/%.o: %.S
	$(info Assembling $< ...)
	$(CC) -c -o $(subst Source,Build,$@) $(CFLAGS) $(INCFLAGS) $< -MD -MF $(APP_BLD_DIR)/$*.d -MP
	@echo

$(APP_BLD_DIR)/%.o: %.c
	$(info Compiling $< ...)
	$(CC) -c -o $(subst Source,Build,$@) $(CFLAGS) $(INCFLAGS) $< -MD -MF $(APP_BLD_DIR)/$*.d -MP
	@echo

$(APP_BLD_DIR)/$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).elf: $(APPOBJS) $(addsuffix.a,$(addprefix $(COMPONENTS_BASE_DIR)/Library/lib,$(APPLDLIBS))) 
	$(info Linking $@ ...)

	$(CC) -Wl,--gc-sections -Wl,-u_AppColdStart -Wl,-u_AppWarmStart $(LDFLAGS) -TAppBuildZLLHA_$(JENNIC_CHIP).ld -o $@ -Wl,--start-group $(APPOBJS) $(addprefix -l,$(LDLIBS)) -lm -Wl,--end-group -Wl,-Map,$(APP_BLD_DIR)/$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).map 
	$(SIZE) $@ 
	
$(APP_BLD_DIR)/$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).bin: $(APP_BLD_DIR)/$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).elf 
	$(info Generating binary ...)
	$(OBJCOPY) -j .version -j .bir -j .flashheader -j .vsr_table -j .vsr_handlers  -j .rodata -j .text -j .data -j .bss -j .heap -j .stack -S -O binary $< $@

###############################################################################

clean:
	rm -f $(APPOBJS) $(APPDEPS) $(APP_BLD_DIR)/$(TARGET)_$(JENNIC_CHIP)*.bin $(APP_BLD_DIR)/$(TARGET)_$(JENNIC_CHIP)*.elf $(APP_BLD_DIR)/$(TARGET)_$(JENNIC_CHIP)*.map
	rm -f $(APP_SRC_DIR)/os_gen.c $(APP_SRC_DIR)/os_gen.h $(APP_SRC_DIR)/os_irq*.S $(APP_SRC_DIR)/pdum_gen.* $(APP_SRC_DIR)/zps_gen*.*

###############################################################################

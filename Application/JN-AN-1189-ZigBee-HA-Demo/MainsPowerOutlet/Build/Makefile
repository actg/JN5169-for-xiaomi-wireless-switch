###############################################################################
#
# MODULE:   Makefile
#
# DESCRIPTION: Makefile for the ZHA Mains Power Outlet device
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

#Default HW is DR1199 expansion board DK4
TARGET = MainsPowerOutlet
#DR    ?= DR1199

# Pull in the manufacturer specific configuration options
include $(abspath ../..)/$(TARGET)/Build/manu_config.mk

# Application target name
PDM_BUILD_TYPE ?=_EEPROM
JENNIC_SDK ?= JN-SW-4168

###############################################################################
#User definable make parameters that may be overwritten from the command line

# Default target device is the JN5168

JENNIC_CHIP ?= JN5169

JENNIC_CHIP_FAMILY ?=JN516x 

##############################################################################
# Stack size and Heap can be configured below

STACK_SIZE ?= 6000
MINIMUM_HEAP_SIZE ?= 2000

###############################################################################
# Default DK4 development kit target hardware
JENNIC_PCB ?= DEVKIT4

# Tell device drivers they must be RTOS compatible
CFLAGS += -DRTOS

# Tell the codebase the target platform and the light type
CFLAGS += -D$(TARGET)
CFLAGS += -D$(DR)

#for access to low-level interrupt routines required by DR1223, DR1192 and DR1221

CFLAGS += -DEMBEDDED
CFLAGS += -DUSER_VSR_HANDLER
  
# Light Is an EZ mode Target
CFLAGS += -DEZ_MODE_TARGET

###############################################################################
# Select the network stack (e.g. MAC, ZBPro, SE, HA)
JENNIC_STACK ?= ZLLHA
JENNIC_MAC ?= MiniMacShim

###############################################################################
# End device or router / coord
ZBPRO_DEVICE_TYPE ?= ZCR

###############################################################################
# Debug options define DEBUG either HW or SW
#DEBUG ?=SW
#DEBUG ?=HW
#
# Define which UART to use for HW debug
DEBUG_PORT ?= UART1

###############################################################################
# Define TRACE to use with DBG module
TRACE ?=1
ifeq ($(TRACE), 1)
CFLAGS  += -DDBG_ENABLE
endif

ifeq ($(OTA),1)
CFLAGS  += -DBUILD_OTA
CFLAGS += -DCLD_OTA_MANF_ID_VALUE=$(MANUFACTURER_CODE)

OTA_ENCRYPTED ?= 0
ifeq ($(OTA_ENCRYPTED),1)
CFLAGS  += -DOTA_ENCRYPTED
endif

APP_CLUSTERS_OTA_SRC ?=1
endif

###############################################################################
# Define GP Support to use 
GP_SUPPORT ?=0
ifeq ($(GP_SUPPORT), 1)
CFLAGS  += -DCLD_GREENPOWER
APP_CLUSTERS_GREENPOWER_SRC ?=1
endif
APP_CLUSTER_HA_LIGHTING_SRC ?= 1
APP_CLUSTER_LIGHTING_SRC ?=1
#APP_CLUSTERS_MEASUREMENT_AND_SENSING ?=1
#APP_CLUSTERS_ENERGY_AT_HOME_SRC ?=1
#APP_CLUSTERS_HVAC_SRC ?=1
APP_CLUSTERS_SMART_ENERGY_SRC ?=1
#APP_CLUSTERS_IAS_SRC ?=1


CFLAGS += -D$(TARGET)

##############################################################################
# For 4x use string based PDM id's for newer families use 16 bit id numbers
ifneq ($(JENNIC_CHIP_FAMILY), JN514x)
CFLAGS   += -DPDM_USER_SUPPLIED_ID
endif

###############################################################################

#CFLAGS += -DDEBUG_PATH
#CFLAGS += -DNXP_HARDWARE
#CFLAGS += -DDEBUG_EZMODE
#CFLAGS += -DDEBUG_ZCL
#CFLAGS += -DDEBUG_APP
#CFLAGS += -DTRACE_ZCL
#CFLAGS += -DDEBUG_START_UP
#CFLAGS += -DDEBUG_LIGHT_NODE
#CFLAGS += -DDEBUG_LIGHT_TASK
#CFLAGS += -DDEBUG_JOIN
#CFLAGS += -DDEBUG_COMMISSION
#CFLAGS += -DDEBUG_TEMPERATURE
#CFLAGS += -DDEBUG_CLD_IDENTIFY 
#CFLAGS += -DDEBUG_CLD_LEVEL_CONTROL
#CFLAGS += -DDEBUG_CLD_ONOFF
#CFLAGS += -DDEBUG_LAMP
#CFLAGS += -DDEBUG_CLD_SCENES
#CFLAGS += -DDEBUG_CLD_COLOUR_CONTROL
#CFLAGS += -DDEBUG_CLD_COLOUR_CONTROL_UPDATES
#CFLAGS += -DDEBUG_CLD_COLOUR_CONTROL_CONVERSIONS
#CFLAGS += -DDEBUG_CLD_GROUPS
#CFLAGS += -DTRACE_GP_DEBUG
#CFLAGS += -DTRACE_OTA_DEBUG
#CFLAGS += -DDEBUG_APP_GP
#CFLAGS += -DDEBUG_APP_OTA
CFLAGS += -DDEBUG_EXCEPTION
#CFLAGS += -DOTA_DEMO_BUILD=TRUE
###############################################################################
# Path definitions

# Use if application directory contains multiple targets
SDK_BASE_DIR        = $(abspath ../../../../sdk/$(JENNIC_SDK))
APP_BASE            = $(abspath ../..)
APP_BLD_DIR         = $(APP_BASE)/$(TARGET)/Build
APP_SRC_DIR         = $(APP_BASE)/$(TARGET)/Source
DEV_BLD_DIR         = $(APP_BASE)/$(TARGET)/Build
DEV_SRC_DIR         = $(APP_BASE)/$(TARGET)/Source


APP_COMMON_SRC_DIR  = $(APP_BASE)/Common/Source
APP_DRIVER_SRC_DIR  = $(APP_BASE)/$(TARGET)/Source/DriverOutlet

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
#APPSRC += app_mutex.c
APPSRC += app_reporting.c
APPSRC += AgeChildren.c
APPSRC += app_timer_driver.c
APPSRC += app_start_outlet.c
APPSRC += app_zbp_utilities.c
#APPSRC += zps_apl_zdo_mgmt_bind_server.c
#APPSRC += app_management_bind.c
APPSRC += app_scenes.c
APPSRC += App_$(TARGET).c
APPSRC += zha_outlet_node.c
APPSRC += app_zcl_outlet_task.c
APPSRC += haEzFindAndBind.c
APPSRC += haEzJoin.c
APPSRC += app_status_led.c

APPSRC += app_power_on_counter.c

APPSRC += appZdpExtraction.c
APPSRC += appZpsBeaconHandler.c

#Pull in the platform depandant driver files
APPSRC += DriverOutlet_$(DR).c

ifeq ($(ENCRYPT_DEV),1)
CFLAGS += -DENCRYPT_DEV
APPSRC += app_encrypt.c
endif

ifeq ($(OTA),1)
APPSRC += app_ota_client.c
else
APPSRC += haKeys.c
endif

ifeq ($(GP_SUPPORT), 1)
APP_ZPSCFG = app_GP.zpscfg
else
APP_ZPSCFG = app.zpscfg
endif

#BIN_SUFFIX=_$(DR)
BIN_SUFFIX := $(BIN_SUFFIX)_$(MODEL_ID)

ifeq ($(GP_SUPPORT), 1)
BIN_SUFFIX := $(BIN_SUFFIX)_GP
endif

ifeq ($(OTA),1)
BIN_SUFFIX := $(BIN_SUFFIX)_OTA
endif

###############################################################################
# Standard Application header search paths

INCFLAGS += -I$(APP_SRC_DIR)
INCFLAGS += -I$(APP_SRC_DIR)/..
INCFLAGS += -I$(DEV_SRC_DIR)
INCFLAGS += -I$(APP_COMMON_SRC_DIR)
INCFLAGS += -I$(APP_DRIVER_SRC_DIR)

# Application specific include files
INCFLAGS += -I$(COMPONENTS_BASE_DIR)/Utilities/Include

INCFLAGS += -I$(COMPONENTS_BASE_DIR)/ZCL/Include
INCFLAGS += -I$(COMPONENTS_BASE_DIR)/Xcv/Include/

INCFLAGS += -I$(COMPONENTS_BASE_DIR)/Recal/Include/
INCFLAGS += -I$(COMPONENTS_BASE_DIR)/MicroSpecific/Include 
LDLIBS += Recal_$(JENNIC_CHIP_FAMILY)


###############################################################################
# Application libraries
# Specify additional Component libraries

#APPLIBS +=

###############################################################################

# You should not need to edit below this line

###############################################################################
OPTIONAL_STACK_FEATURES = $(shell $(ZPSCONFIG) -n $(TARGET) -f $(APP_COMMON_SRC_DIR)/$(APP_ZPSCFG) -y )

###############################################################################
# Configure for the selected chip or chip family

include $(SDK_BASE_DIR)/Chip/Common/Build/config.mk
include $(SDK_BASE_DIR)/Platform/Common/Build/Config.mk
include $(SDK_BASE_DIR)/Stack/Common/Build/config.mk

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
###############################################################################
# Dependency rules

.PHONY: all clean
# Path to directories containing application source
vpath % $(APP_SRC_DIR):$(APP_COMMON_SRC_DIR):$(HA_SRC_DIRS):$(ZCL_SRC):$(UTIL_SRC_DIR):$(DEV_SRC_DIR):$(APP_DRIVER_SRC_DIR)

ifeq ($(OTA),1)
APP_SW_VERSION_UPGRADE_IMAGE ?= 20
all: Client.bin	
else
all: $(DEV_BLD_DIR)/$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).bin
endif
-include $(APPDEPS)
#$(DEV_BLD_DIR)/%.d:
#	rm -f $*.o


OS_SHEET_SUFFIX ?= _mono
ifeq ($(TYPE),RGB)
OS_SHEET_SUFFIX := _rgb
endif

$(DEV_SRC_DIR)/os_gen.c $(DEV_SRC_DIR)/os_gen.h $(DEV_SRC_DIR)/os_irq.S $(DEV_SRC_DIR)/os_irq_alignment.S $(DEV_SRC_DIR)/os_irq_buserror.S $(DEV_SRC_DIR)/os_irq_illegalinstruction.S $(DEV_SRC_DIR)/os_irq_stackoverflowexception.S $(DEV_SRC_DIR)/os_irq_unimplementedmodule.S: $(APP_SRC_DIR)/App_ZHA_$(TARGET)_$(JENNIC_CHIP_FAMILY).oscfgdiag $(OSCONFIG)
	$(info Configuring the OS ...)
	$(OSCONFIG) -f $< -o $(DEV_SRC_DIR) -v $(JENNIC_CHIP)
	@echo

$(DEV_SRC_DIR)/pdum_gen.c $(DEV_SRC_DIR)/pdum_gen.h: $(APP_COMMON_SRC_DIR)/$(APP_ZPSCFG) $(PDUMCONFIG)
	$(info Configuring the PDUM ...)
	$(PDUMCONFIG) -z $(TARGET) -f $< -o $(DEV_SRC_DIR)
	@echo

$(DEV_SRC_DIR)/zps_gen.c $(DEV_SRC_DIR)/zps_gen.h: $(APP_COMMON_SRC_DIR)/$(APP_ZPSCFG) $(ZPSCONFIG)
	$(info Configuring the Zigbee Protocol Stack ...)
	$(ZPSCONFIG) -n $(TARGET) -t $(JENNIC_CHIP) -l $(ZPS_NWK_LIB) -a $(ZPS_APL_LIB) -c $(TOOL_COMMON_BASE_DIR)/$(TOOLCHAIN_PATH) -f $< -o $(DEV_SRC_DIR)
	@echo

$(DEV_BLD_DIR)/%.o: %.S
	$(info Assembling $< ...)
	$(CC) -c -o $(subst Source,Build,$@) $(CFLAGS) $(INCFLAGS) $< -MD -MF $(DEV_BLD_DIR)/$*.d -MP
	@echo

$(DEV_BLD_DIR)/%.o: %.c
	$(info Compiling $< ...)
	$(CC) -c -o $(subst Source,Build,$@) $(CFLAGS) $(INCFLAGS) $< -MD -MF $(DEV_BLD_DIR)/$*.d -MP
	@echo

$(DEV_BLD_DIR)/$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).elf: $(APPOBJS) $(addsuffix.a,$(addprefix $(COMPONENTS_BASE_DIR)/Library/lib,$(APPLDLIBS))) 
	$(info Linking $@ ...)

	$(CC) -Wl,--gc-sections -Wl,-u_AppColdStart -Wl,-u_AppWarmStart $(LDFLAGS) -TAppBuildZLLHA_$(JENNIC_CHIP).ld -o $@ -Wl,--start-group $(APPOBJS) $(addprefix -l,$(LDLIBS)) -lm -Wl,--end-group -Wl,-Map,$(DEV_BLD_DIR)/$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).map 
	$(SIZE) $@ 
	
$(DEV_BLD_DIR)/$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).bin: $(DEV_BLD_DIR)/$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).elf 
	$(info Generating binary ...)
	$(OBJCOPY) -j .version -j .bir -j .flashheader -j .vsr_table -j .vsr_handlers  -j .rodata -j .text -j .data -j .bss -j .heap -j .stack -S -O binary $< $@
ifeq ($(OTA),1)	
Client.bin:$(DEV_BLD_DIR)/$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).bin

ifeq ($(OTA_ENCRYPTED),0)
    ############################################## Create Client and OTA images - Unencrypted ##################################
	cp -f $(DEV_BLD_DIR)/$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).bin $(DEV_BLD_DIR)/OTABuild/$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).bin
	cd $(DEV_BLD_DIR)/OTABuild;\
	$(DEV_BLD_DIR)/OTABuild/LightCreatOtaClient.bat $(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX) $(MANUFACTURER_CODE) $(APP_SW_VERSION) $(JENNIC_CHIP)

    ##########################Create Client and OTA images with a different version to test - Unencrypted #########################	
	cp -f $(DEV_BLD_DIR)/$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).bin $(DEV_BLD_DIR)/OTABuild/$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).bin
	cd $(DEV_BLD_DIR)/OTABuild;\
	$(DEV_BLD_DIR)/OTABuild/LightCreatOtaClient.bat $(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX) $(MANUFACTURER_CODE) $(APP_SW_VERSION_UPGRADE_IMAGE) $(JENNIC_CHIP)
else
    ############################################## Create Client and OTA images - Enncrypted ##################################
	cp -f $(DEV_BLD_DIR)/$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).bin $(DEV_BLD_DIR)/OTABuild/$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).bin
	cd $(DEV_BLD_DIR)/OTABuild;\
	$(DEV_BLD_DIR)/OTABuild/LightCreatOtaEncClient.bat $(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX) $(MANUFACTURER_CODE) $(APP_SW_VERSION) $(JENNIC_CHIP)

    ##########################Create Client and OTA images with a different version to test - Enncrypted #########################	
	cp -f $(DEV_BLD_DIR)/$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).bin $(DEV_BLD_DIR)/OTABuild/$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).bin
	cd $(DEV_BLD_DIR)/OTABuild;\
	$(DEV_BLD_DIR)/OTABuild/LightCreatOtaEncClient.bat $(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX) $(MANUFACTURER_CODE) $(APP_SW_VERSION_UPGRADE_IMAGE) $(JENNIC_CHIP)
endif	
	
	rm -f $(DEV_BLD_DIR)/$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).bin
endif	

###############################################################################

clean:
	rm -f $(APPOBJS) $(APPDEPS) $(DEV_BLD_DIR)/$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).bin $(DEV_BLD_DIR)/$(TARGET)_$(JENNIC_CHIP)*.elf $(DEV_BLD_DIR)/$(TARGET)_$(JENNIC_CHIP)*.map
	rm -f $(DEV_SRC_DIR)/os_gen.c $(DEV_SRC_DIR)/os_gen.h $(DEV_SRC_DIR)/os_irq*.S $(DEV_SRC_DIR)/pdum_gen.* $(DEV_SRC_DIR)/zps_gen*.*

###############################################################################

###############################################################################
#
# MODULE:   Makefile
#
# DESCRIPTION: Makefile for the ZHA Switch devices
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
# Copyright NXP B.V. 2017. All rights reserved
#
############################################################################

SWITCH ?= DimmerSwitch
DR    ?= DR1199
TYPE  ?= EXP_BOARD
REV   ?= r1v2

# Pull in the manufacturer specific configuration options
include $(abspath ../..)/$(SWITCH)/Build/manu_config.mk

# Application target name
TARGET = $(SWITCH)
PDM_BUILD_TYPE ?=_EEPROM
STACK_SIZE = 5000
MINIMUM_HEAP_SIZE = 2000
###############################################################################
#User definable make parameters that may be overwritten from the command line

# Default target device is the JN5179
JENNIC_CHIP ?= JN5179
JENNIC_PCB  ?= DEVKIT5

JENNIC_CHIP_FAMILY ?= JN517x

ifeq ($(JENNIC_CHIP_FAMILY),JN517x)
    ifeq ($(OTA),1)
    	ZNCLKCMD         = AppBuildZBProOta.ld
        JET_VERSION      = 5
    else
    	ZNCLKCMD         = AppBuildZBPro.ld
    endif
	JENNIC_SDK           = JN-SW-4270
	JENNIC_PCB           = DEVKIT5
	ENDIAN               = LITTLE_ENDIAN_PROCESSOR
	DISABLE_LTO          = 1
endif

ifeq ($(JENNIC_CHIP_FAMILY),JN516x)
    JENNIC_SDK           = JN-SW-4170
    JENNIC_PCB           = DEVKIT4
    ZNCLKCMD             = AppBuildZBPro.ld
    ENDIAN 	             = BIG_ENDIAN
    DISABLE_LTO          = 1
    ifeq ($(OTA),1)
    	JET_VERSION      = 4
    endif
endif 

ifeq ($(JENNIC_CHIP_FAMILY),JN517x)
INTERRUPT_HANDLER_BBC = zps_isrMAC
LDFLAGS += -Wl,-u$(INTERRUPT_HANDLER_BBC) -Wl,-defsym,vAHI_IntHandlerBbc_select=$(INTERRUPT_HANDLER_BBC)
endif

###############################################################################
# Network settings

# Optional network.mk for channel
sinclude ../../../network.mk

# Channel (0 for default channels)
SINGLE_CHANNEL ?= 0
CFLAGS         += -DSINGLE_CHANNEL=$(SINGLE_CHANNEL)

###############################################################################
# Sleep Configuration
ifeq ($(OTA),1)
KEEPALIVETIME ?= 20
CFLAGS += -DKEEP_ALIVETIME=$(KEEPALIVETIME)
else
KEEPALIVETIME ?= 6
CFLAGS += -DKEEP_ALIVETIME=$(KEEPALIVETIME)
endif
CFLAGS += -DSLEEP_ENABLE
CFLAGS += -DDEEP_SLEEP_ENABLE

CFLAGS += -D$(DR)
CFLAGS += -D$(SWITCH)

CFLAGS  += -DBUTTON_MAP_$(DR)

CFLAGS += -DSLEEPY_ZED

# Switch is an Initiator,
CFLAGS  += -DEZ_MODE_INITIATOR
CFLAGS  += -DEZ_ENABLE_GROUP

# NFC NTAG ICODE (new) functionality
APP_NTAG_ICODE ?= 1
ifeq ($(APP_NTAG_ICODE), 1)
CFLAGS  += -DAPP_NTAG_ICODE
endif

# NFC NTAG AES (old) functionality
APP_NTAG_AES ?= 0
ifeq ($(APP_NTAG_AES), 1)
CFLAGS  += -DAPP_NTAG_AES
endif

###############################################################################
# Select the network stack (e.g. MAC, ZBPro, SE, HA)
JENNIC_STACK ?= ZCL
JENNIC_MAC ?= MiniMacShim

###############################################################################
# End device or router / coord (e.g. ZCR, ZED)
ZBPRO_DEVICE_TYPE ?= ZED

###############################################################################
# BDB specific options
#BDB_SUPPORT_TOUCHLINK_INITIATOR ?= 1
#BDB_SUPPORT_TOUCHLINK_TARGET ?= 1
BDB_SUPPORT_NWK_STEERING ?= 1
#BDB_SUPPORT_NWK_FORMATION ?= 1
BDB_SUPPORT_FIND_AND_BIND_INITIATOR ?= 1
#BDB_SUPPORT_FIND_AND_BIND_TARGET ?= 1
ifeq ($(APP_NTAG_ICODE), 1)
BDB_SUPPORT_OOBC ?= 1
endif
ifeq ($(APP_NTAG_AES), 1)
BDB_SUPPORT_OOBC ?= 1
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
CFLAGS += -DDBG_ENABLE
#CFLAGS += -DDEBUG_921600

# Enable any debug output here:
#CFLAGS += -DNXP_HARDWARE
CFLAGS += -DDEBUG_APP_BUTTON
CFLAGS += -DDEBUG_APP
CFLAGS += -DDEBUG_START_UP
CFLAGS += -DDEBUG_SWITCH_STATE
#CFLAGS += -DDEBUG_ZCL
CFLAGS += -DDEBUG_SWITCH_TASK
CFLAGS += -DDEBUG_SWITCH_NODE
#CFLAGS += -DDEBUG_CLD_BASIC
#CFLAGS += -DDEBUG_APP_OTA
#CFLAGS += -DDEBUG_APP_NTAG
#CFLAGS += -DDEBUG_APP_ICODE
#CFLAGS += -DDEBUG_BDB
endif

ifeq ($(OTA),1)
CFLAGS  += -DBUILD_OTA
CFLAGS  += -DCHECK_VBO_FOR_OTA_ACTIVITY
CFLAGS  += -DOTA_DEMO_BUILD

OTA_ENCRYPTED ?= 0
ifeq ($(OTA_ENCRYPTED),0)
OTA_STRING = $(DR)r1v2--$(JENNIC_CHIP)00000000000000
else
OTA_STRING = $(DR)r1v2--$(JENNIC_CHIP)--ENCRYPTED000
CFLAGS  += -DOTA_ENCRYPTED
endif

OTA_INTERNAL_STORAGE ?= 1
ifeq ($(OTA_INTERNAL_STORAGE),1)
CFLAGS  += -DOTA_INTERNAL_STORAGE
ifeq ($(OTA_ENCRYPTED),1)
CFLAGS += -DINTERNAL_ENCRYPTED
endif
endif

APP_CLUSTERS_OTA_SRC ?=1
endif

APP_CLUSTER_LIGHTING_SRC ?=1
#APP_CLUSTERS_MEASUREMENT_AND_SENSING ?=1
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
# Path definitions

# Use if application directory contains multiple targets
SDK_BASE_DIR        = $(abspath ../../../../sdk/$(JENNIC_SDK))
APP_BASE            = $(abspath ../..)
APP_BLD_DIR         = $(APP_BASE)/Common_Switch/Build
APP_SRC_DIR         = $(APP_BASE)/Common_Switch/Source
DEV_BLD_DIR         = $(APP_BASE)/$(TARGET)/Build
DEV_SRC_DIR         = $(APP_BASE)/$(TARGET)/Source
APP_COMMON_SRC_DIR  = $(APP_BASE)/Common/Source
UTIL_SRC_DIR        = $(COMPONENTS_BASE_DIR)/ZigbeeCommon/Source
HW_SRC_DIR			= $(COMPONENTS_BASE_DIR)/HardwareAPI/Source

###############################################################################
# Application Source files

# Note: Path to source file is found using vpath below, so only .c filename is required
ifeq ($(JENNIC_CHIP_FAMILY),JN516x)
APPSRC = irq_$(JENNIC_CHIP_FAMILY).S
APPSRC += portasm_JN516x.S
APPSRC += port_JN516x.c
endif
ifeq ($(JENNIC_CHIP_FAMILY),JN517x)
APPSRC += port_JN517x.c
endif
APPSRC += pdum_gen.c
APPSRC += pdum_apdu.S
APPSRC += zps_gen.c
APPSRC += app_pdm.c
APPSRC += app_main.c
APPSRC += app_start_switch.c
ifeq ($(JENNIC_CHIP_FAMILY), JN517x)
APPSRC += AHI_ModuleConfiguration.c 
endif

APPSRC += App_$(TARGET).c
APPSRC += app_zlo_switch_node.c
APPSRC += app_zcl_switch_task.c
APPSRC += app_buttons.c
APPSRC += app_switch_state_machine.c
APPSRC += app_pdm_convert.c

ifeq ($(APP_NTAG_ICODE),1)
APPSRC += app_ntag_icode.c
#APPSRC += app_icode.c
endif
ifeq ($(APP_NTAG_AES),1)
APPSRC += app_ntag_aes.c
endif

#APPSRC += app_mutex.c
ifeq ($(OTA),1)
APPSRC += app_ota_client.c
endif

APP_ZPSCFG = app.zpscfg

# Construct binary features list 

ifeq ($(APP_NTAG_ICODE),1)
TARGET_FEATURES:=$(TARGET_FEATURES)_NtagIcode
endif

ifeq ($(APP_NTAG_AES),1)
TARGET_FEATURES:=$(TARGET_FEATURES)_NtagAes
endif

ifeq ($(OTA),1)
TARGET_FEATURES:=$(TARGET_FEATURES)_Ota
ifeq ($(OTA_ENCRYPTED),1)
TARGET_FEATURES:=$(TARGET_FEATURES)Enc
endif
endif

# Construct binary hardware list

TARGET_HARDWARE:=_$(JENNIC_CHIP)_$(DR)

ifneq ($(SINGLE_CHANNEL), 0)
TARGET_HARDWARE:=$(TARGET_HARDWARE)_CH$(SINGLE_CHANNEL)
endif

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
INCFLAGS += -I$(COMPONENTS_BASE_DIR)/Xcv/Include/
INCFLAGS += -I$(COMPONENTS_BASE_DIR)/Recal/Include/
INCFLAGS += -I$(COMPONENTS_BASE_DIR)/MicroSpecific/Include 
INCFLAGS += -I$(COMPONENTS_BASE_DIR)/HardwareAPI/Include

###############################################################################
# NTAG ICODE library
ifeq ($(APP_NTAG_ICODE),1)
# NTAG library folder
APP_NTAG_LIB_DIR  = $(APP_BASE)/NFC
# NTAG library
LDLIBS           += NTAG_$(JENNIC_CHIP_FAMILY)
# NTAG library path
LDFLAGS          += -L$(APP_NTAG_LIB_DIR)/Library
# NTAG include path
INCFLAGS         += -I$(APP_NTAG_LIB_DIR)/Include
endif

###############################################################################
# NTAG AES library
ifeq ($(APP_NTAG_AES),1)
# NTAG library folder
APP_NTAG_LIB_DIR  = $(APP_BASE)/NTAG
# NTAG library
LDLIBS           += NTAG_$(JENNIC_CHIP_FAMILY)
# NTAG library path
LDFLAGS          += -L$(APP_NTAG_LIB_DIR)/Library
# NTAG include path
INCFLAGS         += -I$(APP_NTAG_LIB_DIR)/Include
endif

###############################################################################
# Application libraries
# Specify additional Component libraries

#APPLIBS +=

LDLIBS += Recal_$(JENNIC_CHIP_FAMILY)
LDLIBS += JPT_$(JENNIC_CHIP)

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
###############################################################################
# Dependency rules

.PHONY: all clean
# Path to directories containing application source
vpath % $(APP_SRC_DIR):$(APP_COMMON_SRC_DIR):$(ZCL_SRC_DIRS):$(ZCL_SRC):$(BDB_SRC_DIR):$(UTIL_SRC_DIR):$(DEV_SRC_DIR):$(HW_SRC_DIR)

ifeq ($(OTA),1)
APP_SW_VERSION_UPGRADE_IMAGE ?= 2
all: Client.bin	
else
all: $(DEV_BLD_DIR)/$(TARGET)$(TARGET_FEATURES)$(TARGET_HARDWARE).bin
endif

-include $(APPDEPS)
$(DEV_BLD_DIR)/%.d:
	rm -f $*.o

ifeq ($(JENNIC_CHIP_FAMILY),JN517x)
$(DEV_SRC_DIR)/pdum_gen.c $(DEV_SRC_DIR)/pdum_gen.h: $(APP_COMMON_SRC_DIR)/$(APP_ZPSCFG) $(PDUMCONFIG)
	$(info Configuring the PDUM ...)
	$(PDUMCONFIG) -z $(TARGET) -e $(ENDIAN) -f $< -o $(DEV_SRC_DIR)
	@echo

$(DEV_SRC_DIR)/zps_gen.c $(DEV_SRC_DIR)/zps_gen.h: $(APP_COMMON_SRC_DIR)/$(APP_ZPSCFG) $(ZPSCONFIG)
	$(info Configuring the Zigbee Protocol Stack ...)
	$(ZPSCONFIG) -n $(TARGET) -t $(JENNIC_CHIP) -l $(ZPS_NWK_LIB) -a $(ZPS_APL_LIB) -c $(TOOL_COMMON_BASE_DIR)/$(TOOLCHAIN_PATH) -e $(ENDIAN) -f $< -o $(DEV_SRC_DIR)
	@echo
	

    pdum_gen.o zps_gen.o: CFLAGS += -fno-lto
    CFLAGS += -fno-lto
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

endif

$(DEV_BLD_DIR)/%.o: %.S
	$(info Assembling $< ...)
	$(CC) -c -o $(subst Source,Build,$@) $(CFLAGS) $(INCFLAGS) $< -MD -MF $(DEV_BLD_DIR)/$*.d -MP
	@echo

$(DEV_BLD_DIR)/%.o: %.c
	$(info Compiling $< ...)
	$(CC) -c -o $(subst Source,Build,$@) $(CFLAGS) $(INCFLAGS) $< -MD -MF $(DEV_BLD_DIR)/$*.d -MP
	@echo

$(DEV_BLD_DIR)/$(TARGET)$(TARGET_FEATURES)$(TARGET_HARDWARE).elf: $(APPOBJS) $(addsuffix.a,$(addprefix $(COMPONENTS_BASE_DIR)/Library/lib,$(APPLDLIBS))) 
	$(info Linking $@ ...)
	$(CC) -Wl,--gc-sections -Wl,-u_AppColdStart -Wl,-u_AppWarmStart $(LDFLAGS) -T$(ZNCLKCMD) -L $(SDK_BASE_DIR)/Stack/ZCL/Build/ -o $@ -Wl,--start-group $(APPOBJS) $(addprefix -l,$(LDLIBS)) -lm -Wl,--end-group -Wl,-Map,$(DEV_BLD_DIR)/$(TARGET)$(TARGET_FEATURES)$(TARGET_HARDWARE).map
	$(SIZE) $@
	date +%c >> $(APP_BASE)/Doc/size.txt
	$(SIZE) $@ >> $(APP_BASE)/Doc/size.txt

ifeq ($(JENNIC_CHIP_FAMILY),JN517x)
$(DEV_BLD_DIR)/$(TARGET)$(TARGET_FEATURES)$(TARGET_HARDWARE).bin: $(DEV_BLD_DIR)/$(TARGET)$(TARGET_FEATURES)$(TARGET_HARDWARE).elf 
	$(info Generating binary ...)
	$(OBJCOPY) -S -O binary $< $@
else
$(DEV_BLD_DIR)/$(TARGET)$(TARGET_FEATURES)$(TARGET_HARDWARE).bin: $(DEV_BLD_DIR)/$(TARGET)$(TARGET_FEATURES)$(TARGET_HARDWARE).elf 
	$(info Generating binary ...)
	$(OBJCOPY) -j .version -j .bir -j .flashheader -j .vsr_table -j .vsr_handlers  -j .rodata -j .text -j .data -j .bss -j .heap -j .stack -S -O binary $< $@
endif

ifeq ($(OTA),1)
Client.bin:$(DEV_BLD_DIR)/$(TARGET)$(TARGET_FEATURES)$(TARGET_HARDWARE).bin
ifeq ($(OTA_ENCRYPTED),0)
    ############################################## Create Client and OTA images - Unencrypted ##################################
	cp -f $(DEV_BLD_DIR)/$(TARGET)$(TARGET_FEATURES)$(TARGET_HARDWARE).bin $(DEV_BLD_DIR)/OTABuild/$(TARGET)$(TARGET_FEATURES)$(TARGET_HARDWARE).bin
ifeq ($(OS),Windows_NT)	
	cd $(DEV_BLD_DIR)/OTABuild;\
	$(DEV_BLD_DIR)/OTABuild/SwitchCreatOtaClient.bat $(TARGET)$(TARGET_FEATURES)$(TARGET_HARDWARE) $(MANUFACTURER_CODE) $(APP_SW_VERSION) $(OTA_STRING) $(JENNIC_SDK) $(JET_VERSION) $(JENNIC_CHIP_FAMILY)
else
	cd $(DEV_BLD_DIR)/OTABuild;\
	/bin/bash $(DEV_BLD_DIR)/OTABuild/SwitchCreatOtaClient.sh $(TARGET)$(TARGET_FEATURES)$(TARGET_HARDWARE) $(MANUFACTURER_CODE) $(APP_SW_VERSION) $(OTA_STRING) $(JENNIC_SDK) $(JET_VERSION) $(JENNIC_CHIP_FAMILY)
endif
    ##########################Create Client and OTA images with a different version to test - Unencrypted #########################
	cp -f $(DEV_BLD_DIR)/$(TARGET)$(TARGET_FEATURES)$(TARGET_HARDWARE).bin $(DEV_BLD_DIR)/OTABuild/$(TARGET)$(TARGET_FEATURES)$(TARGET_HARDWARE).bin
ifeq ($(OS),Windows_NT)		
	cd $(DEV_BLD_DIR)/OTABuild;\
	$(DEV_BLD_DIR)/OTABuild/SwitchCreatOtaClient.bat $(TARGET)$(TARGET_FEATURES)$(TARGET_HARDWARE) $(MANUFACTURER_CODE) $(APP_SW_VERSION_UPGRADE_IMAGE) $(OTA_STRING) $(JENNIC_SDK) $(JET_VERSION) $(JENNIC_CHIP_FAMILY)
else
	cd $(DEV_BLD_DIR)/OTABuild;\
	/bin/bash $(DEV_BLD_DIR)/OTABuild/SwitchCreatOtaClient.sh $(TARGET)$(TARGET_FEATURES)$(TARGET_HARDWARE) $(MANUFACTURER_CODE) $(APP_SW_VERSION_UPGRADE_IMAGE) $(OTA_STRING) $(JENNIC_SDK) $(JET_VERSION) $(JENNIC_CHIP_FAMILY)
endif

else
    ############################################## Create Client and OTA images - Enncrypted ##################################
	cp -f $(DEV_BLD_DIR)/$(TARGET)$(TARGET_FEATURES)$(TARGET_HARDWARE).bin $(DEV_BLD_DIR)/OTABuild/$(TARGET)$(TARGET_FEATURES)$(TARGET_HARDWARE).bin
ifeq ($(OS),Windows_NT)	
	cd $(DEV_BLD_DIR)/OTABuild;\
	$(DEV_BLD_DIR)/OTABuild/SwitchCreatOtaEncClient.bat $(TARGET)$(TARGET_FEATURES)$(TARGET_HARDWARE) $(MANUFACTURER_CODE) $(APP_SW_VERSION) $(OTA_STRING) $(JENNIC_SDK) $(JET_VERSION) $(JENNIC_CHIP_FAMILY)
else
	cd $(DEV_BLD_DIR)/OTABuild;\
	/bin/bash $(DEV_BLD_DIR)/OTABuild/SwitchCreatOtaEncClient.sh $(TARGET)$(TARGET_FEATURES)$(TARGET_HARDWARE) $(MANUFACTURER_CODE) $(APP_SW_VERSION) $(OTA_STRING) $(JENNIC_SDK) $(JET_VERSION) $(JENNIC_CHIP_FAMILY)
endif
    ##########################Create Client and OTA images with a different version to test - Enncrypted #########################	
	cp -f $(DEV_BLD_DIR)/$(TARGET)$(TARGET_FEATURES)$(TARGET_HARDWARE).bin $(DEV_BLD_DIR)/OTABuild/$(TARGET)$(TARGET_FEATURES)$(TARGET_HARDWARE).bin
ifeq ($(OS),Windows_NT)	
	cd $(DEV_BLD_DIR)/OTABuild;\
	$(DEV_BLD_DIR)/OTABuild/SwitchCreatOtaEncClient.bat $(TARGET)$(TARGET_FEATURES)$(TARGET_HARDWARE) $(MANUFACTURER_CODE) $(APP_SW_VERSION_UPGRADE_IMAGE) $(OTA_STRING) $(JENNIC_SDK) $(JET_VERSION) $(JENNIC_CHIP_FAMILY)
else
	cd $(DEV_BLD_DIR)/OTABuild;\
	/bin/bash $(DEV_BLD_DIR)/OTABuild/SwitchCreatOtaEncClient.sh $(TARGET)$(TARGET_FEATURES)$(TARGET_HARDWARE) $(MANUFACTURER_CODE) $(APP_SW_VERSION_UPGRADE_IMAGE) $(OTA_STRING) $(JENNIC_SDK) $(JET_VERSION) $(JENNIC_CHIP_FAMILY)
endif
endif
	
	rm -f $(DEV_BLD_DIR)/$(TARGET)$(TARGET_FEATURES)$(TARGET_HARDWARE).bin
endif	

###############################################################################

clean:
	rm -f $(APPOBJS) $(APPDEPS) $(DEV_BLD_DIR)/$(TARGET)$(TARGET_FEATURES)$(TARGET_HARDWARE).bin $(DEV_BLD_DIR)/$(TARGET)$(TARGET_FEATURES)$(TARGET_HARDWARE).elf $(DEV_BLD_DIR)/$(TARGET)$(TARGET_FEATURES)$(TARGET_HARDWARE).map
	rm -f $(DEV_SRC_DIR)/pdum_gen.* $(DEV_SRC_DIR)/zps_gen*.* $(DEV_SRC_DIR)/pdum_apdu.*

###############################################################################

###############################################################################
#
# MODULE:      Makefile
#
# DESCRIPTION: Makefile for the ZHA OTAServer
# 
###############################################################################
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
# Copyright NXP B.V. 2013. All rights reserved
#
############################################################################

# Application target name
TARGET = OTAServer
PDM_BUILD_TYPE ?= _EEPROM
JENNIC_SDK ?= JN-SW-4168

###############################################################################
#User definable make parameters that may be overwritten from the command line

# Default target device is the JN5168

JENNIC_CHIP ?= JN5169

JENNIC_CHIP_FAMILY ?=JN516x 

###############################################################################
# Default DK4 development kit target hardware
JENNIC_PCB ?= DEVKIT4

###############################################################################
# Select the network stack (e.g. MAC, ZBPro, SE, HA)
JENNIC_STACK ?= ZLLHA
JENNIC_MAC ?= MiniMacShim

###############################################################################
# End device or router / coord
ZBPRO_DEVICE_TYPE ?= ZCR
MANUFACTURER_CODE ?= 0x1037
APP_SW_VERSION ?= 1
ifeq ($(JENNIC_CHIP), JN5169)
IMAGE_TYPE ?= 5169
else
IMAGE_TYPE ?= 5168
endif
###############################################################################
# Debug options - define DEBUG to enable
# DEBUG ?=HW
#
# Define which UART to use for SW/HW debug
DEBUG_PORT ?= UART0

###############################################################################
# By default TRACE and OVERLAYS have been turned off
# Set them to 1 to enable TRACE and overlays.
TRACE ?=1

ifeq ($(TRACE), 1)
CFLAGS  += -DDBG_ENABLE

# Enable any debug output here:
#CFLAGS  += -DDEBUG_APP
endif

CFLAGS += -DOTA_DEMO_BUILD=TRUE

APP_CLUSTER_HA_LIGHTING_SRC ?=1
#APP_CLUSTER_LIGHTING_SRC ?=1
#APP_CLUSTERS_MEASUREMENT_AND_SENSING ?=1
APP_CLUSTERS_OTA_SRC ?=1
#APP_CLUSTERS_ENERGY_AT_HOME_SRC ?=1
#APP_CLUSTERS_GREENPOWER_SRC ?=1
#APP_CLUSTERS_HVAC_SRC ?=1
#APP_CLUSTERS_SMART_ENERGY_SRC ?=1
#APP_CLUSTERS_IAS_SRC ?=1


# Add the EZ mode defines for a light,
# These flags compile the EZ mode module into. 

###############################################################################
# Path definitions

# Use if application directory contains multiple targets
SDK_BASE_DIR        = $(abspath ../../../../sdk/$(JENNIC_SDK))
APP_BASE            = $(abspath ../..)
APP_BLD_DIR	    = $(APP_BASE)/$(TARGET)/Build
APP_SRC_DIR 	    = $(APP_BASE)/$(TARGET)/Source
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
APPSRC += zps_gen.c
APPSRC += pdum_apdu.S
APPSRC += app_timer_driver.c
APPSRC += app_exceptions.c
APPSRC += app_ota_server.c
APPSRC += app_start_upgrade_server.c
APPSRC += app_zcl_server_node_task.c
APPSRC += zha_upgrade_server_node.c
APPSRC += app_endpoint.c
APPSRC += app_pdm.c
APPSRC += AgeChildren.c
APPSRC += haEzJoin.c
APPSRC += app_zbp_utilities.c

APPSRC += appZdpExtraction.c
APPSRC += appZpsBeaconHandler.c

APP_ZPSCFG = app.zpscfg
ZBPRO_OVERLAYS = $(shell $(OSCONFIG) -f "$(shell cygpath -w "$(APP_SRC_DIR)/App_$(TARGET)_$(JENNIC_CHIP_FAMILY).oscfgdiag")" -y )

###############################################################################
# Standard Application header search paths

INCFLAGS += -I$(APP_SRC_DIR)
INCFLAGS += -I$(APP_SRC_DIR)/..
INCFLAGS += -I$(APP_COMMON_SRC_DIR)

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
vpath % $(APP_SRC_DIR):$(APP_COMMON_SRC_DIR):$(UTIL_SRC_DIR):$(HA_SRC_DIRS):$(ZCL_SRC)


#all: $(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).bin
all: Server.bin
-include $(APPDEPS)
#%.d:
#	rm -f $*.o

$(APP_SRC_DIR)/os_gen.c $(APP_SRC_DIR)/os_gen.h $(APP_SRC_DIR)/os_irq.S $(APP_SRC_DIR)/os_irq_alignment.S $(APP_SRC_DIR)/os_irq_buserror.S $(APP_SRC_DIR)/os_irq_illegalinstruction.S $(APP_SRC_DIR)/os_irq_stackoverflowexception.S $(APP_SRC_DIR)/os_irq_unimplementedmodule.S: $(APP_SRC_DIR)/App_$(TARGET)_$(JENNIC_CHIP_FAMILY).oscfgdiag $(OSCONFIG) 
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
	$(CC) -c -o $(subst Source,Build,$@) $(CFLAGS) $(INCFLAGS) $< -MD -MF $*.d -MP
	@echo

$(APP_BLD_DIR)/%.o: %.c
	$(info Compiling $< ...)
	$(CC) -c -o $(subst Source,Build,$@) $(CFLAGS) $(INCFLAGS) $< -MD -MF $*.d -MP
	@echo

$(APP_BLD_DIR)/$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).elf: $(APPOBJS) $(addsuffix.a,$(addprefix $(COMPONENTS_BASE_DIR)/Library/lib,$(APPLDLIBS))) 
	$(info Linking $@ ...)
	$(CC) -Wl,--gc-sections -Wl,-u_AppColdStart -Wl,-u_AppWarmStart $(LDFLAGS) -TAppBuildZLLHA_$(JENNIC_CHIP).ld -o $@ -Wl,--start-group $(APPOBJS) $(addprefix -l,$(LDLIBS)) -Wl,--end-group -Wl,-Map,$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).map
	$(SIZE) $@ 
	
$(APP_BLD_DIR)/$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).bin: $(APP_BLD_DIR)/$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).elf 
	$(info Generating binary ...)
	$(OBJCOPY) -j .version -j .bir -j .flashheader -j .vsr_table -j .vsr_handlers -j .ro_mac_address -j .ro_ota_header -j .ro_se_lnkKey -j .ro_se_cert -j .ro_se_pvKey -j .ro_se_customData -j .rodata -j .text -j .data -j .bss -j .heap -j .stack -S -O binary $< $@

Server.bin:$(APP_BLD_DIR)/$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).bin
	cp -f $(APP_BLD_DIR)/$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).bin $(APP_BLD_DIR)/OTABuild/$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).bin
	cd $(APP_BLD_DIR)/OTABuild;\
	$(APP_BLD_DIR)/OTABuild/CreatOtaServer.bat $(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX) $(MANUFACTURER_CODE) $(APP_SW_VERSION) $(IMAGE_TYPE) $(JENNIC_CHIP)
	
###############################################################################

clean:
	rm -f $(APPOBJS) $(APPDEPS) $(TARGET)_$(JENNIC_CHIP)*.bin $(TARGET)_$(JENNIC_CHIP)*.elf $(TARGET)_$(JENNIC_CHIP)*.map
	rm -f $(APP_SRC_DIR)/os_gen.c $(APP_SRC_DIR)/os_gen.h $(APP_SRC_DIR)/os_irq*.S $(APP_SRC_DIR)/pdum_gen.* $(APP_SRC_DIR)/zps_gen*.*

###############################################################################

###############################################################################
#
# MODULE:      Makefile
#
# DESCRIPTION: Makefile for the ZHA Coordinator
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

TARGET = Coordinator

###############################################################################
#User definable make parameters that may be overwritten from the command line

# Default target device is the JN5168

JENNIC_CHIP ?= JN5168
JENNIC_CHIP_FAMILY ?=JN516x 

###############################################################################
# Default DK4 development kit target hardware

JENNIC_PCB ?= DEVKIT4

###############################################################################
# Select the network stack (e.g. MAC, ZBPro)

JENNIC_STACK ?= ZBPro
JENNIC_MAC ?= MiniMacShim

###############################################################################
# ZBPro Stack specific options
ZBPRO_DEVICE_TYPE = ZCR
#PDM_BUILD_TYPE ?= _EXTERNAL_FLASH
PDM_BUILD_TYPE ?=_EEPROM
JENNIC_SDK ?= JN-SW-4168

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
endif

# Enable any debug output here:
CFLAGS  += -DDEBUG_APP



###############################################################################
# Path definitions

# Use if application directory contains multiple targets
SDK_BASE_DIR   	 	= $(abspath ../../../../sdk/$(JENNIC_SDK))
APP_BASE           	= $(abspath ../..)
APP_BLD_DIR			= $(APP_BASE)/$(TARGET)/Build
APP_SRC_DIR 	   	= $(APP_BASE)/$(TARGET)/Source
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
APPSRC += app_zbp_utilities.c
APPSRC += app_exceptions.c
APPSRC += app_pdm.c
APPSRC += app_timer_driver.c
APPSRC += app_start.c
APPSRC += App_Coordinator.c
APPSRC += app_endpoint.c
APPSRC += AgeChildren.c
APPSRC += haKeys.c
APPSRC += appZpsBeaconHandler.c
APPSRC += appZdpExtraction.c
APP_ZPSCFG = app.zpscfg
ZBPRO_OVERLAYS = $(shell $(OSCONFIG) -f "$(shell cygpath -w "$(APP_SRC_DIR)/App_$(TARGET)_$(JENNIC_CHIP_FAMILY).oscfgdiag")" -y )

###############################################################################
# Standard Application header search paths

INCFLAGS += -I$(APP_SRC_DIR)
INCFLAGS += -I$(APP_SRC_DIR)/..
INCFLAGS += -I$(APP_COMMON_SRC_DIR)

# Application specific include files
INCFLAGS += -I$(COMPONENTS_BASE_DIR)/JennicLogo/Include
INCFLAGS += -I$(COMPONENTS_BASE_DIR)/Utilities/Include
INCFLAGS += -I$(COMPONENTS_BASE_DIR)/NXPLogo/Include
INCFLAGS += -I$(COMPONENTS_BASE_DIR)/Xcv/Include/

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
APPOBJS = $(TEMP:.S=.o)

###############################################################################
# Application dynamic dependencies

APPDEPS = $(APPOBJS:.o=.d)

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
vpath % $(APP_SRC_DIR):$(APP_COMMON_SRC_DIR):$(UTIL_SRC_DIR)


all: $(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).bin

-include $(APPDEPS)
%.d:
	rm -f $*.o

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

%.o: %.S
	$(info Assembling $< ...)
	$(CC) -c -o $(subst Source,Build,$@) $(CFLAGS) $(INCFLAGS) $< -MD -MF $*.d -MP
	@echo

%.o: %.c 
	$(info Compiling $< ...)
	$(CC) -c -o $(subst Source,Build,$@) $(CFLAGS) $(INCFLAGS) $< -MD -MF $*.d -MP
	@echo

$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).elf: $(APPOBJS) $(addsuffix.a,$(addprefix $(COMPONENTS_BASE_DIR)/Library/lib,$(APPLDLIBS))) 
	$(info Linking $@ ...)
#	$(CC) -Wl,--unique -Wl,-r -Wl,-u_AppColdStart -Wl,-u_AppWarmStart $(LDFLAGS) -TAppBuildZBPro_$(JENNIC_CHIP).ld -o $@ -Wl,--start-group $(APPOBJS) $(addprefix -l,$(LDLIBS)) -Wl,--end-group -Wl,-Map,$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).map
	$(CC) -Wl,--gc-sections -Wl,-u_AppColdStart -Wl,-u_AppWarmStart $(LDFLAGS) -TAppBuildZBPro.ld -o $@ -Wl,--start-group $(APPOBJS) $(addprefix -l,$(LDLIBS)) -Wl,--end-group -Wl,-Map,$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).map 
	 
	$(SIZE) $@ 


$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).bin: $(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).elf 
	$(info Generating binary ...)
	$(OBJCOPY) -j .version -j .bir -j .flashheader -j .vsr_table -j .vsr_handlers  -j .rodata -j .text -j .data -j .bss -j .heap -j .stack -S -O binary $< $@

	
###############################################################################

clean:
	rm -f $(APPOBJS) $(APPDEPS) $(TARGET)_$(JENNIC_CHIP)*.bin $(TARGET)_$(JENNIC_CHIP)*.elf $(TARGET)_$(JENNIC_CHIP)*.map
	rm -f $(APP_SRC_DIR)/os_gen.c $(APP_SRC_DIR)/os_gen.h $(APP_SRC_DIR)/os_irq*.S $(APP_SRC_DIR)/pdum_gen.* $(APP_SRC_DIR)/zps_gen*.*

###############################################################################

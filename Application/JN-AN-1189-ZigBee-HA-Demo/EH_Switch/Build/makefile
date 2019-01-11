###############################################################################
#
# MODULE:   Makefile
#
# DESCRIPTION: Controller_EH_Switch
# 
############################################################################
# This software is owned by NXP B.V. and/or its supplier and is protected
# under applicable copyright laws. All rights are reserved. We grant You,
# and any third parties, a license to use this software solely and
# exclusively on NXP products [NXP Microcontrollers such as JN5148, JN5142, JN5139].
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
#############################################################################
#
# Application target name

TARGET = EH_Switch
PDM_BUILD_TYPE ?=_EEPROM
JENNIC_SDK ?= JN-SW-4168

###############################################################################
#User definable make parameters that may be overwritten from the command line

# Default target device is the JN5168

JENNIC_CHIP ?= JN5168

JENNIC_CHIP_FAMILY ?=JN516x 

###############################################################################
# Default DK4 development kit target hardware
JENNIC_PCB ?= DEVKIT4

SWITCH_TYPE_DK4 ?=1
SWITCH_TYPE_EnOcean=0

ifeq ($(SWITCH_TYPE_DK4), 1)	
CFLAGS += -DDK4
BIN_SUFFIX=_DR1199
else
CFLAGS += -DEH_SWITCH
BIN_SUFFIX=
endif


ifeq ($(SWITCH_TYPE_DR1216), 1)	
CFLAGS += -DDR1216
BIN_SUFFIX=_DR1216
endif

###############################################################################
# Select the network stack (e.g. MAC, ZBPro)

JENNIC_STACK ?= MAC
JENNIC_MAC = MiniMac

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
CFLAGS += -DDBG_ENABLE
#CFLAGS += -DDBG_DEVICE_SWITCH
endif

###############################################################################
# Path definitions

# Use if application directory contains multiple targets
#SDK_BASE_DIR   	 	= $(abspath ../../../..)
#APP_BASE            	 	= $(abspath ../..)
#APP_BLD_DIR			= $(APP_BASE)/$(TARGET)/Build
#APP_SRC_DIR 	        	= $(APP_BASE)/$(TARGET)/Source


# Use if application directory contains single target
SDK_BASE_DIR         	= $(abspath ../../../../sdk/$(JENNIC_SDK))
APP_BASE            	= $(abspath ..)
APP_BLD_DIR          	= $(APP_BASE)/Build
APP_SRC_DIR          	= $(APP_BASE)/Source
APP_COMMON_SRC_DIR      = $(APP_BASE)../../Common/Source
MMAC_DIR      			= $(APP_BASE)../../Components/MMAC/Include
LIB_DIR            		= $(APP_BASE)/../Components/Library
#AES_DIR                 =  $(APP_BASE)../../Components/Aes/Include
#AES_AHI_INC      = $(COMPONENT_BASE_DIR)/AES/Include
#AES_INC          = $(COMPONENT_BASE_DIR)/AES_SW/Include
###############################################################################
# Application Source files

# Note: Path to source file is found using vpath below, so only .c filename is required
APPSRC  += EH_IEEE_802154_Switch.c
APPSRC  += EH_IEEE_Features.c
APPSRC  += EH_IEEE_Commands.c
APPSRC  += AHI_EEPROM.c
APPSRC  += EH_Timer.c
APPSRC  += EH_Button.c

###############################################################################
# Standard Application header search paths

INCFLAGS += -I$(APP_SRC_DIR)
INCFLAGS += -I$(APP_SRC_DIR)/..
INCFLAGS += -I$(APP_COMMON_SRC_DIR)
INCFLAGS += -I$(MMAC_DIR)
#INCFLAGS += -I$(AES_DIR)
# Application specific include files
INCFLAGS += -I$(SDK_BASE_DIR)/Components/DBG/Include
INCFLAGS += -I$(SDK_BASE_DIR)/Components/AppApi/Include
INCFLAGS += -I$(SDK_BASE_DIR)/Components/AppQueueApi/Include
INCFLAGS += -I$(COMPONENTS_BASE_DIR)/PDM/Include
INCFLAGS += -I$(COMPONENTS_BASE_DIR)/AES_SW/Include
#CFLAGS += -DTAG_BUILD_MAINS
#CFLAGS += -DTAG_BUILD_MAINS_BUTTON
CFLAGS += -DTAG_BUILD_RANDOM
#CFLAGS += -DTAG_BUILD_FRAM
#CFLAGS += -DTAG_BUILD_ONE_BYTE_FCF
#CFLAGS += -DTAG_BUILD_COMMISSIONING
#CFLAGS += -DTAG_BUILD_COMM_OPTIONS_RXCAPABLE
#CFLAGS += -DTAG_BUILD_RXAFTERTX
#CFLAGS += -DTAG_BUILD_SECURITY
#CFLAGS += -DEMBEDDED
#CFLAGS += -DUSER_VSR_HANDLER
#INCFLAGS += -I$(AES_INC)
#INCFLAGS += -I$(AES_AHI_INC)
###############################################################################
# Application libraries
# Specify additional Component libraries
APPLIBS +=OS

#APPLIBS += MMAC
#APPLIBS += AES_SW
APPLIBS +=PDM$(PDM_BUILD_TYPE)
#APPLIBS +=PDUM
#APPLIBS +=PDM$(PDM_BUILD_TYPE)
#APPLIBS += MAC # Including MAC only for optimised CCM* code
LDFLAGS += -L$(LIB_DIR)
LDFLAGS += -L$(APP_SRC_DIR)
###############################################################################

# You should not need to edit below this line

###############################################################################
###############################################################################
# Configure for the selected chip or chip family

include $(SDK_BASE_DIR)/Chip/Common/Build/config.mk
include $(SDK_BASE_DIR)/Platform/Common/Build/Config.mk
include $(SDK_BASE_DIR)/Stack/Common/Build/config.mk

###############################################################################


# LINKCMD = AppBuild_SchTag.ld

#APPLIBS += HardwareApi
#APPLIBS += Boot
#APPLIBS += Aes
#APPLIBS += PDM_EEPROM
#APPLIBS += MMAC
APPLIBS += DBG
#LDLIBS =

TEMP = $(APPSRC:.c=.o)
APPOBJS = $(TEMP:.S=.o)

###############################################################################
# Application dynamic dependencies

APPDEPS = $(APPOBJS:.o=.d)

###############################################################################
# Linker

# Add application libraries before chip specific libraries to linker so
# symbols are resolved correctly (i.e. ordering is significant for GCC)


LDLIBS := $(addsuffix _$(JENNIC_CHIP_FAMILY),$(APPLIBS)) $(LDLIBS)
LDLIBS := $(filter-out PDM_EEPROM_$(JENNIC_CHIP_FAMILY)_NO_RTOS,$(LDLIBS))

###############################################################################
# Dependency rules


.PHONY: all clean
# Path to directories containing application source 
vpath % $(APP_SRC_DIR):$(APP_COMMON_SRC_DIR):$(MMAC_DIR)


all: $(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).bin

-include $(APPDEPS)
%.d:
	rm -f $*.o

%.o: %.S
	$(info Assembling $< ...)
	$(CC) -c -o $(subst Source,Build,$@) $(CFLAGS) $(INCFLAGS) $< -MD -MF $*.d -MP
	@echo

%.o: %.c 
	$(info Compiling $< ...)
	$(CC) -c -o $(subst Source,Build,$@) $(CFLAGS) $(INCFLAGS) $< -MD -MF $*.d -MP
	@echo

#$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).elf: $(APPOBJS) $(addsuffix _$(JENNIC_CHIP_FAMILY).a,$(addprefix $(COMPONENTS_BASE_DIR)/Library/lib,$(APPLIBS)))
$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).elf: $(APPOBJS)
	$(info Linking $@ ...)
	$(CC) -Wl,--gc-sections -Wl,-u_AppColdStart -Wl,-u_AppWarmStart $(LDFLAGS) -T$(LINKCMD) -o $@ $(APPOBJS) $(addprefix -l,$(LDLIBS)) -Wl,-Map,$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).map 
	$(SIZE) $@ 
	@echo

$(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).bin: $(TARGET)_$(JENNIC_CHIP)$(BIN_SUFFIX).elf 
	$(info Generating binary ...)
	$(OBJCOPY) -S -O binary $< $@
	
###############################################################################

clean:
	rm -f $(APPOBJS) $(APPDEPS) $(TARGET)_$(JENNIC_CHIP)*.bin $(TARGET)_$(JENNIC_CHIP)*.elf $(TARGET)_$(JENNIC_CHIP)*.map

###############################################################################

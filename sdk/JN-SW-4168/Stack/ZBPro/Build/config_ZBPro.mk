###############################################################################
#
# MODULE:   Config.mk
#
# DESCRIPTION: ZBPro stack configuration. Defines tool, library and
#              header file details for building an app using the ZBPro stack 
# 
###############################################################################
# 
# This software is owned by Jennic and/or its supplier and is protected
# under applicable copyright laws. All rights are reserved. We grant You,
# and any third parties, a license to use this software solely and
# exclusively on Jennic products. You, and any third parties must reproduce
# the copyright and warranty notice and any other legend of ownership on each
# copy or partial copy of the software.
# 
# THIS SOFTWARE IS PROVIDED "AS IS". JENNIC MAKES NO WARRANTIES, WHETHER
# EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE,
# ACCURACY OR LACK OF NEGLIGENCE. JENNIC SHALL NOT, IN ANY CIRCUMSTANCES,
# BE LIABLE FOR ANY DAMAGES, INCLUDING, BUT NOT LIMITED TO, SPECIAL,
# INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON WHATSOEVER.
# 
# Copyright Jennic Ltd 2009. All rights reserved
# 
###############################################################################
#
# $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/Stack/Modules/ZBPro/Branches/ZBProv1.1/Build/config_ZBPro.mk $
# $Revision: 81665 $
# $LastChangedBy: nxp29741 $
# $LastChangedDate: 2016-07-19 12:06:50 +0100 (Tue, 19 Jul 2016) $
# $Id: config_ZBPro.mk 81665 2016-07-19 11:06:50Z nxp29741 $
#
###############################################################################

###############################################################################
# Tools

OSCONFIG = $(TOOL_BASE_DIR)/OSConfig/bin/OSConfig.exe
PDUMCONFIG = $(TOOL_BASE_DIR)/PDUMConfig/bin/PDUMConfig.exe
ZPSCONFIG = $(TOOL_BASE_DIR)/ZPSConfig/bin/ZPSConfig.exe
STACK_SIZE ?= 5000
MINIMUM_HEAP_SIZE ?= 2000
###############################################################################
# ROM based software components

INCFLAGS += -I$(COMPONENTS_BASE_DIR)/MAC/Include
INCFLAGS += -I$(COMPONENTS_BASE_DIR)/MicroSpecific/Include
INCFLAGS += -I$(COMPONENTS_BASE_DIR)/MiniMAC/Include
INCFLAGS += -I$(COMPONENTS_BASE_DIR)/MMAC/Include
INCFLAGS += -I$(COMPONENTS_BASE_DIR)/TimerServer/Include
ifeq ($(JENNIC_CHIP_FAMILY), JN516x)
INCFLAGS += -I$(COMPONENTS_BASE_DIR)/Random/Include
ifeq ($(JENNIC_MAC), MAC)
$(info JENNIC_MAC is MAC )
APPLIBS +=ZPSMAC
CFLAGS  += -DREDUCED_ZIGBEE_MAC_BUILD
REDUCED_MAC_LIB_SUFFIX = ZIGBEE_
else
$(info JENNIC_MAC is Mini MAC shim )
JENNIC_MAC = MiniMacShim
APPLIBS +=ZPSMAC_Mini
endif
endif

###############################################################################
# RAM based software components


ifneq ($(JENNIC_CHIP_FAMILY),JN514x)
CFLAGS += -DPDM_USER_SUPPLIED_ID
ifeq ($(PDM_BUILD_TYPE),_EEPROM)
CFLAGS += -DPDM$(PDM_BUILD_TYPE)
else
ifeq ($(PDM_BUILD_TYPE),_EXTERNAL_FLASH)
CFLAGS += -DPDM$(PDM_BUILD_TYPE)
else
ifeq ($(PDM_BUILD_TYPE),_NONE)
CFLAGS += -DPDM$(PDM_BUILD_TYPE)
else
$(error PDM_BUILD_TYPE must be defined please define PDM_BUILD_TYPE=_EEPROM or PDM_BUILD_TYPE=_EXTERNAL_FLASH)
endif
endif
endif
endif

# NB Order is significant for GNU linker
APPLIBS +=OS
APPLIBS +=PWRM
APPLIBS +=ZPSTSV
APPLIBS +=AES_SW
APPLIBS +=PDUM
APPLIBS +=ZPSAPL
ifeq ($(JENNIC_CHIP_FAMILY), JN516x)
APPLIBS +=Random
endif

INCFLAGS += $(addsuffix /Include,$(addprefix -I$(COMPONENTS_BASE_DIR)/,$(APPLIBS)))
INCFLAGS += -I$(COMPONENTS_BASE_DIR)/PDM/Include

ifneq ($(PDM_BUILD_TYPE),_NONE)
APPLIBS +=PDM$(PDM_BUILD_TYPE)
endif

ifeq ($(TRACE), 1)
CFLAGS  += -DDBG_ENABLE
$(info Building trace version ...)
APPLIBS +=DBG
else
INCFLAGS += -I$(COMPONENTS_BASE_DIR)/DBG/Include
endif

ifeq ($(OPTIONAL_STACK_FEATURES),1)
ifneq ($(ZBPRO_DEVICE_TYPE), ZED)
APPLIBS += ZPSZLL
else
APPLIBS += ZPSZLL_ZED
endif
endif

ifeq ($(OPTIONAL_STACK_FEATURES),2)
ifneq ($(ZBPRO_DEVICE_TYPE), ZED)
APPLIBS += ZPSGP
else
APPLIBS += ZPSGP_ZED
endif
endif

ifeq ($(OPTIONAL_STACK_FEATURES),3)
ifneq ($(ZBPRO_DEVICE_TYPE), ZED)
APPLIBS += ZPSGP
APPLIBS += ZPSZLL
else
APPLIBS += ZPSGP_ZED
APPLIBS += ZPSZLL_ZED
endif
endif

###############################################################################
# Paths to network and application layer libs for stack config tools

INCFLAGS += -I$(COMPONENTS_BASE_DIR)/ZPSMAC/Include
INCFLAGS += -I$(COMPONENTS_BASE_DIR)/ZPSNWK/Include

ifeq ($(ZBPRO_DEVICE_TYPE), ZCR)
APPLIBS +=ZPSNWK
else
ifeq ($(ZBPRO_DEVICE_TYPE), ZED)
APPLIBS +=ZPSNWK_ZED
else
$(error ZBPRO_DEVICE_TYPE must be set to either ZCR or ZED)
endif
endif

ifeq ($(ZBPRO_DEVICE_TYPE), ZCR)
ZPS_NWK_LIB = $(COMPONENTS_BASE_DIR)/Library/libZPSNWK_$(JENNIC_CHIP_FAMILY).a
endif
ifeq ($(ZBPRO_DEVICE_TYPE), ZED)
ZPS_NWK_LIB = $(COMPONENTS_BASE_DIR)/Library/libZPSNWK_ZED_$(JENNIC_CHIP_FAMILY).a
endif


ZPS_APL_LIB = $(COMPONENTS_BASE_DIR)/Library/libZPSAPL_$(JENNIC_CHIP_FAMILY).a

LDFLAGS += -Wl,--gc-sections

###############################################################################

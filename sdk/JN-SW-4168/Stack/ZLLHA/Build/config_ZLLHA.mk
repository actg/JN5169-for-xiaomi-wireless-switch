###############################################################################
#
# MODULE:   Config_HA.mk
#
# DESCRIPTION: unified Profile make requirements
# 
###############################################################################
#
# $HeadURL:  $
# $Revision: $
# $LastChangedBy: $
# $LastChangedDate: $
# $Id: $
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

###############################################################################

# Get ZigBee stack makefile requirements
include $(STACK_BASE_DIR)/ZBPro/Build/config_ZBPro.mk

###############################################################################

ZCL_BASE         = $(COMPONENTS_BASE_DIR)/ZCL
ZCL_SRC          = $(ZCL_BASE)/Source
CLUSTERS_BASE    = $(ZCL_BASE)/Clusters
PROFILES_BASE    = $(ZCL_BASE)/Profiles
#Always include General for basic, so no compile time option
CLUSTERS_GENERAL_SRC                    = $(CLUSTERS_BASE)/General/Source


ifeq ($(APP_CLUSTER_HA_LIGHTING_SRC), 1)
CLUSTER_LIGHTING_SRC                    = $(CLUSTERS_BASE)/Lighting/Source
PROFILES_LIGHTING_SRC                   = $(PROFILES_BASE)/HA/Lighting/Source
endif



ifeq ($(APP_CLUSTERS_MEASUREMENT_AND_SENSING), 1)
CLUSTERS_MEASUREMENT_AND_SENSING_SRC    = $(CLUSTERS_BASE)/MeasurementAndSensing/Source
endif


ifeq ($(APP_CLUSTER_ZLL_SRC), 1)
CLUSTERS_ZLL_SRC			= $(CLUSTERS_BASE)/LightLink/Source
PROFILES_ZLL_BASE_SRC 		        = $(PROFILES_BASE)/ZLL/Source
CLUSTER_LIGHTING_SRC                    = $(CLUSTERS_BASE)/Lighting/Source
endif

ifeq ($(APP_CLUSTERS_ENERGY_AT_HOME_SRC), 1)
CLUSTERS_ENERGY_AT_HOME_SRC             = $(CLUSTERS_BASE)/EnergyAtHome/Source 
PROFILES_ENERGY_AT_HOME_SRC             = $(PROFILES_BASE)/HA/EnergyAtHome/Source  
endif

ifeq ($(APP_CLUSTERS_GREENPOWER_SRC), 1)
CLUSTERS_GREENPOWER_SRC                 = $(CLUSTERS_BASE)/GreenPower/Source
PROFILES_GP_SRC                         = $(PROFILES_BASE)/GP/Source
endif

ifeq ($(APP_CLUSTERS_OTA_SRC), 1)
CLUSTERS_OTA_SRC                        = $(CLUSTERS_BASE)/OTA/Source
endif

ifeq ($(APP_CLUSTERS_HVAC_SRC), 1)
CLUSTERS_HVAC_SRC                       = $(CLUSTERS_BASE)/HVAC/Source
PROFILES_HVAC_SRC                       = $(PROFILES_BASE)/HA/HVAC/Source
endif

ifeq ($(APP_CLUSTERS_SMART_ENERGY_SRC), 1)
CLUSTERS_SMART_ENERGY_SRC               = $(CLUSTERS_BASE)/SmartEnergy/Source
endif

ifeq ($(APP_CLUSTERS_IAS_SRC), 1)
CLUSTERS_IAS_SRC                        = $(CLUSTERS_BASE)/IAS/Source
PROFILES_IAS_SRC                        = $(PROFILES_BASE)/HA/IAS/Source
endif


CLUSTERS_SRC_DIRS                       = $(CLUSTERS_GENERAL_SRC):$(CLUSTERS_MEASUREMENT_AND_SENSING_SRC):$(CLUSTER_LIGHTING_SRC):$(CLUSTERS_ENERGY_AT_HOME_SRC):$(CLUSTERS_GREENPOWER_SRC):$(CLUSTERS_OTA_SRC):$(CLUSTERS_HVAC_SRC):$(CLUSTERS_SMART_ENERGY_SRC):$(CLUSTERS_IAS_SRC)
PROFILES_COMMON_SRC                     = $(PROFILES_BASE)/HA/Common/Source
PROFILES_GENERIC_SRC                    = $(PROFILES_BASE)/HA/Generic/Source
PROFILES_HOMEAUTOMATION_SRC             = $(PROFILES_COMMON_SRC):$(PROFILES_LIGHTING_SRC):$(PROFILES_GENERIC_SRC):$(PROFILES_GP_SRC):$(PROFILES_ENERGY_AT_HOME_SRC):$(PROFILES_HVAC_SRC):$(PROFILES_IAS_SRC)
HA_SRC_DIRS                             = $(CLUSTERS_SRC_DIRS):$(PROFILES_HOMEAUTOMATION_SRC):$(ZCL_SRC)
CLUSTERS_ZLL_SPEC_DIRS                  = $(CLUSTERS_GENERAL_SRC):$(CLUSTERS_MEASUREMENT_AND_SENSING_SRC):$(CLUSTER_LIGHTING_SRC):$(CLUSTERS_ENERGY_AT_HOME_SRC):$(CLUSTERS_GREENPOWER_SRC):$(CLUSTERS_OTA_SRC):$(CLUSTERS_HVAC_SRC):$(CLUSTERS_SMART_ENERGY_SRC)
ZLL_SRC_DIRS                            = $(CLUSTERS_ZLL_SPEC_DIRS):$(CLUSTERS_ZLL_SRC):$(ZCL_SRC):$(PROFILES_ZLL_BASE_SRC):$(CLUSTER_LIGHTING_SRC)

###############################################################################


ifeq ($(GP_SUPPORT), 1)
GPSRC:=$(shell cd $(CLUSTERS_GREENPOWER_SRC); ls *.c)
APPSRC += $(GPSRC)
APPSRC += gp.c
endif


# Clusters
# All General cluster files
GENSRCS:=$(shell cd $(CLUSTERS_GENERAL_SRC); ls *.c)
APPSRC += $(GENSRCS)


ifeq ($(APP_CLUSTERS_MEASUREMENT_AND_SENSING), 1)
# All measurement and sensing cluster files
MSSRCS:=$(shell cd $(CLUSTERS_MEASUREMENT_AND_SENSING_SRC); ls *.c)
APPSRC += $(MSSRCS)
endif

ifeq ($(APP_CLUSTER_HA_LIGHTING_SRC), 1)
# All Lighting cluster files
LSRCS:=$(shell cd $(CLUSTER_LIGHTING_SRC); ls *.c)
APPSRC += $(LSRCS)
LIGHTING_SRCS:=$(shell cd $(PROFILES_LIGHTING_SRC); ls *.c)
APPSRC += $(LIGHTING_SRCS)
endif



ifeq ($(APP_CLUSTER_ZLL_SRC), 1)
# All ZLL cluster files
ZLLCSRCS:=$(shell cd $(CLUSTERS_ZLL_SRC); ls *.c)
APPSRC += $(ZLLCSRCS)
ZLLSRCS:=$(shell cd $(PROFILES_ZLL_BASE_SRC); ls *.c)
APPSRC += $(ZLLSRCS)
LIGHTING_SRCS:=$(shell cd $(CLUSTER_LIGHTING_SRC); ls *.c)
APPSRC += $(LIGHTING_SRCS)
else
# Profiles
# All common files
COMMON_SRCS:=$(shell cd $(PROFILES_COMMON_SRC); ls *.c)
APPSRC += $(COMMON_SRCS)
# All Generic devices
GENERIC_SRCS:=$(shell cd $(PROFILES_GENERIC_SRC); ls *.c)
APPSRC += $(GENERIC_SRCS)
endif


ifeq ($(APP_CLUSTERS_ENERGY_AT_HOME_SRC), 1)
# All EnergyAtHome cluster files
EAHSRCS:=$(shell cd $(CLUSTERS_ENERGY_AT_HOME_SRC); ls *.c)
APPSRC += $(EAHSRCS)
ENERGY_AT_HOME_SRC :=$(shell cd $(PROFILES_ENERGY_AT_HOME_SRC); ls *.c)
APPSRC += $(ENERGY_AT_HOME_SRC)
endif

ifeq ($(APP_CLUSTERS_HVAC_SRC), 1)
# All HVAC cluster files
HVACSRCS:=$(shell cd $(CLUSTERS_HVAC_SRC); ls *.c)
APPSRC += $(HVACSRCS)
HVAC_HOME_SRC :=$(shell cd $(PROFILES_HVAC_SRC); ls *.c)
APPSRC += $(HVAC_HOME_SRC)
endif

ifeq ($(APP_CLUSTERS_SMART_ENERGY_SRC), 1)
# Selected Smart Energy cluster files
SESRCS:=$(shell cd $(CLUSTERS_SMART_ENERGY_SRC); ls *.c)
APPSRC += $(SESRCS)
endif

ifeq ($(APP_CLUSTERS_IAS_SRC), 1)
# All IAS cluster files
IASSRCS:=$(shell cd $(CLUSTERS_IAS_SRC); ls *.c)
APPSRC += $(IASSRCS)
IAS_HOME_SRC :=$(shell cd $(PROFILES_IAS_SRC); ls *.c)
APPSRC += $(IAS_HOME_SRC)
endif


# All EnergyAtHome devices


# All HVAC devices


# All IAS devices


# ZCL now built from source
ZCLSRCS:= $(shell cd $(ZCL_SRC); ls *.c)
APPSRC += $(ZCLSRCS)

# OTA files 

ifeq ($(APP_CLUSTERS_OTA_SRC), 1)
OTASRCS:= $(shell cd $(CLUSTERS_OTA_SRC); ls *.c)
APPSRC += $(OTASRCS)
endif


###############################################################################

# Includes
INCFLAGS += -I$(ZCL_SRC)

INCFLAGS += -I$(ZCL_BASE)/Include

INCFLAGS += -I$(CLUSTERS_BASE)/General/Include
INCFLAGS += -I$(CLUSTERS_BASE)/General/Source
INCFLAGS += -I$(CLUSTERS_BASE)/Lighting/Include
INCFLAGS += -I$(CLUSTERS_BASE)/MeasurementAndSensing/Include
INCFLAGS += -I$(CLUSTERS_BASE)/EnergyAtHome/Include
INCFLAGS += -I$(CLUSTERS_BASE)/SE/Include
INCFLAGS += -I$(CLUSTERS_BASE)/GreenPower/Include
INCFLAGS += -I$(CLUSTERS_BASE)/HVAC/Include
INCFLAGS += -I$(CLUSTERS_BASE)/OTA/Include
INCFLAGS += -I$(CLUSTERS_BASE)/SmartEnergy/Include
INCFLAGS += -I$(CLUSTERS_BASE)/IAS/Include
INCFLAGS += -I$(PROFILES_BASE)/HA/Common/Include
INCFLAGS += -I$(PROFILES_BASE)/HA/Generic/Include
ifeq ($(APP_CLUSTER_HA_LIGHTING_SRC), 1)
INCFLAGS += -I$(PROFILES_BASE)/HA/Lighting/Include
endif
ifeq ($(APP_CLUSTERS_ENERGY_AT_HOME_SRC), 1)
INCFLAGS += -I$(PROFILES_BASE)/HA/EnergyAtHome/Include
endif
ifeq ($(APP_CLUSTERS_HVAC_SRC), 1)
INCFLAGS += -I$(PROFILES_BASE)/HA/HVAC/Include
endif
ifeq ($(APP_CLUSTERS_IAS_SRC), 1)
INCFLAGS += -I$(PROFILES_BASE)/HA/IAS/Include
endif
ifeq ($(APP_CLUSTER_ZLL_SRC), 1)
INCFLAGS += -I$(CLUSTERS_BASE)/LightLink/Include
INCFLAGS += -I$(PROFILES_BASE)/ZLL/Include
endif
INCFLAGS += -I$(PROFILES_BASE)/GP/Include


###############################################################################

CFLAGS += -DZPS_APL_OPT_SINGLE_INSTANCE
CFLAGS += -DOTA_NO_CERTIFICATE
###############################################################################

LDFLAGS += -L$(ZCL_BASE)/Build
CFLAGS += -DPLME_SAP
LDFLAGS += -L$(STACK_BASE_DIR)/ZBPro/Build
LDFLAGS += -L$(STACK_BASE_DIR)/ZLLHA/Build

###############################################################################




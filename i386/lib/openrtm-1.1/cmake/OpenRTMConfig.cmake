# -*- cmake -*-
#
# @file OpenRTMConfig.cmake
# @brief cmake-config file for OpenRTM-aist
# @author Noriaki Ando
# @date 2013年 8月19日 月曜日 22時33分25秒 JST
#
# This file is used for cmake config-mode.
# The following variables are defined.
#
# Basic compiler/linker options
# - OPENRTM_CFLAGS: cflags 
# - OPENRTM_INCLUDE_DIRS: include directories
# - OPENRTM_LDFLAGS: linker options
# - OPENRTM_LIBRARY_DIRS: library directories
# - OPENRTM_LIBRARIES: libraries
# - OPENRTM_LIB_DIR: OpenRTM's lib directory
#
# OpenRTM-aist specific directory
# - COIL_INCLUDE_DIR: coil include dir
# - OPENRTM_INCLUDE_DIR: OpenRTM's include directory
# - OPENRTM_LIB_DIR: OpenRTM's lib directory
# - OPENRTM_DATA_DIR: OpenRTM's shared directory
#
# OpenRTM-aist version
# - OPENRTM_VERSION: x.y.z version
# - OPENRTM_VERSION_MAJOR: major version number
# - OPENRTM_VERSION_MINOR: minor version number
# - OPENRTM_VERSION_PATCH: revision number
# - OPENRTM_SHORT_VERSION: short version number 1.1.0->110
#
# OpenRTM-aist's CORBA related settings
# - OPENRTM_ORB: CORBA implementation
# - OPENRTM_IDL_WRAPPER: rtm-skelwrapper command
# - OPENRTM_IDL_WRAPPER_FLAGS: rtm-skelwrapper flag
# - OPENRTM_IDLC: IDL command
# - OPENRTM_IDLFLAGS: IDL optins

message(STATUS "OpenRTMConfig.cmake found.")
message(STATUS "Configrued by configuration mode.")


# Basic compiler/linker options
set(OPENRTM_CFLAGS  -Wall -fPIC  -O2)
set(OPENRTM_INCLUDE_DIRS /opt/universal/i386/include /opt/universal/i386/include/coil-1.1 /opt/universal/i386/include/openrtm-1.1 /opt/universal/i386/include/openrtm-1.1/rtm/idl)
set(OPENRTM_LDFLAGS  --export-dynamic)
set(OPENRTM_LIBRARY_DIRS /opt/universal/i386/lib)
set(OPENRTM_LIBRARIES omniORB4 omnithread omniDynamic4 RTC coil)
set(OPENRTM_LIB_DIR /opt/universal/i386/lib/openrtm-1.1)
set(OPENRTM_DIR /opt/universal/i386)

# OpenRTM-aist specific directory
set(COIL_INCLUDE_DIR /opt/universal/i386/include/coil-1.1)
set(OPENRTM_INCLUDE_DIR /opt/universal/i386/include/openrtm-1.1)
set(OPENRTM_LIB_DIR /opt/universal/i386/lib/openrtm-1.1)
set(OPENRTM_DATA_DIR /opt/universal/i386/share/openrtm-1.1)

# OpenRTM-aist version
set(OPENRTM_VERSION 1.1.0)
set(OPENRTM_VERSION_MAJOR 1)
set(OPENRTM_VERSION_MINOR 1)
set(OPENRTM_VERSION_PATCH 0)
set(OPENRTM_SHORT_VERSION 110)

# OpenRTM-aist's CORBA related settings
set(OPENRTM_ORB omniORB)
set(OPENRTM_IDL_WRAPPER rtm-skelwrapper)
set(OPENRTM_IDL_WRAPPER_FLAGS --include-dir= --skel-suffix=Skel --stub-suffix=Stub)
set(OPENRTM_IDLC /usr/local/bin/omniidl)
set(OPENRTM_IDLFLAGS -bcxx -Wba -nf)

include(FindPkgConfig)
#
# Getting omniORB settings
#
pkg_check_modules(OMNIORB REQUIRED omniORB4)
if(NOT OMNIORB_DIR)
  if(OMNIORB_FOUND)
    set(OMNIORB_DIR )
  endif()
  set(OMNIORB_DIR  CACHE PATH omniORB root directory)
endif()

message(STATUS "OpenRTM-aist configuration done")
# end of OpenRTMConfig.cmake

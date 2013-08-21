// -*- C++ -*-
/*!
 *
 * THIS FILE IS GENERATED AUTOMATICALLY!! DO NOT EDIT!!
 *
 * @file  OpenRTMSkel.cpp 
 * @brief OpenRTM server skeleton wrapper code
 * @date  Mon Aug 19 22:24:45 2013 
 *
 */

#include "rtm/idl/OpenRTMSkel.h"

#if   defined ORB_IS_TAO
#include "rtm/idl/OpenRTMC.cpp"
#include "rtm/idl/OpenRTMS.cpp"
#elif defined ORB_IS_OE
#include "rtm/idl/OpenRTM.cxx"
#include "rtm/idl/OpenRTM_s.cxx"
#elif defined ORB_IS_OMNIORB
#ifdef WIN32
#pragma warning( disable : 4267 )
#pragma warning( disable : 4290 )
#pragma warning( disable : 4311 )
#pragma warning( disable : 4312 )
#endif // WIN32
#include "rtm/idl/OpenRTMSK.cc"
#include "rtm/idl/OpenRTMDynSK.cc"
#ifdef WIN32
#pragma warning( default : 4267 )
#pragma warning( default : 4290 )
#pragma warning( default : 4311 )
#pragma warning( default : 4312 )
#endif // WIN32
#elif defined ORB_IS_MICO
#include "rtm/idl/OpenRTM.cc"
#include "rtm/idl/OpenRTM_skel.cc"
#elif defined ORB_IS_ORBIT2
#include "rtm/idl/OpenRTM-cpp-skels.cc"
#include "rtm/idl/OpenRTM-cpp-stubs.cc"
#elif defined ORB_IS_RTORB
#include "rtm/idl/OpenRTM-common.c"
#include "rtm/idl/OpenRTM-stubs.c"
#include "rtm/idl/OpenRTM-skels.c"
#include "rtm/idl/OpenRTM-skelimpl.c"
#else
#error "NO ORB defined"
#endif

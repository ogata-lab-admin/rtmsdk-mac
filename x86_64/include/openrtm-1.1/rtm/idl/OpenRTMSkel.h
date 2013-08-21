// -*- C++ -*-
/*!
 *
 * THIS FILE IS GENERATED AUTOMATICALLY!! DO NOT EDIT!!
 *
 * @file  OpenRTMSkel.h 
 * @brief OpenRTM server skeleton wrapper code
 * @date  Mon Aug 19 21:58:42 2013
 *
 */

#ifndef __OPENRTMSKEL_H__
#define __OPENRTMSKEL_H__

#include <rtm/config_rtc.h>
#undef PACKAGE_BUGREPORT
#undef PACKAGE_NAME
#undef PACKAGE_STRING
#undef PACKAGE_TARNAME
#undef PACKAGE_VERSION

#if   defined ORB_IS_TAO
#include "rtm/idl/OpenRTMC.h"
#include "rtm/idl/OpenRTMS.h"
#elif defined ORB_IS_OE
#include "rtm/idl/OpenRTM_s.h"
#include "rtm/idl/OpenRTM.h"
#elif defined ORB_IS_OMNIORB
#ifdef WIN32
#pragma warning( disable : 4267 )
#pragma warning( disable : 4290 )
#pragma warning( disable : 4311 )
#pragma warning( disable : 4312 )
#endif // WIN32
#include "rtm/idl/OpenRTM.hh"
#ifdef WIN32
#pragma warning( default : 4267 )
#pragma warning( default : 4290 )
#pragma warning( default : 4311 )
#pragma warning( default : 4312 )
#endif // WIN32
#elif defined ORB_IS_MICO
#include "rtm/idl/OpenRTM.h"
#elif defined ORB_IS_ORBIT2
#include "rtm/idl/OpenRTM-cpp-stubs.h"
#include "rtm/idl/OpenRTM-cpp-skels.h"
#elif defined ORB_IS_RTORB
#include "rtm/idl/OpenRTM.h"
#else
#error "NO ORB defined"
#endif

#endif // end of __OPENRTMSKEL_H__

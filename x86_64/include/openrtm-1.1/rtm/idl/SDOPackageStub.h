// -*- C++ -*-
/*!
 *
 * THIS FILE IS GENERATED AUTOMATICALLY!! DO NOT EDIT!!
 *
 * @file  SDOPackageStub.h 
 * @brief SDOPackage server skeleton wrapper code
 * @date  Mon Aug 19 21:58:41 2013
 *
 */

#ifndef __SDOPACKAGESTUB_H__
#define __SDOPACKAGESTUB_H__

#include <rtm/config_rtc.h>
#undef PACKAGE_BUGREPORT
#undef PACKAGE_NAME
#undef PACKAGE_STRING
#undef PACKAGE_TARNAME
#undef PACKAGE_VERSION

#if   defined ORB_IS_TAO
#include "rtm/idl/SDOPackageC.h"
#elif defined ORB_IS_OE
#include "rtm/idl/SDOPackage.h"
#elif defined ORB_IS_OMNIORB
#ifdef WIN32
#pragma warning( disable : 4267 )
#pragma warning( disable : 4290 )
#pragma warning( disable : 4311 )
#pragma warning( disable : 4312 )
#endif // WIN32
#include "rtm/idl/SDOPackage.hh"
#ifdef WIN32
#pragma warning( default : 4267 )
#pragma warning( default : 4290 )
#pragma warning( default : 4311 )
#pragma warning( default : 4312 )
#endif // WIN32
#elif defined ORB_IS_MICO
#include "rtm/idl/SDOPackage.h"
#elif defined ORB_IS_ORBIT2
#include "rtm/idl/SDOPackage-cpp-stubs.h"
#elif defined ORB_IS_RTORB
#include "rtm/idl/SDOPackage.h"
#else
#error "NO ORB defined"
#endif

#endif // end of __SDOPACKAGESTUB_H__

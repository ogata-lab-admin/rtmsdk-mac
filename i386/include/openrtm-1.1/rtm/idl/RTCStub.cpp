// -*- C++ -*-
/*!
 *
 * THIS FILE IS GENERATED AUTOMATICALLY!! DO NOT EDIT!!
 *
 * @file  RTCStub.cpp 
 * @brief RTC server skeleton wrapper code
 * @date  Mon Aug 19 22:24:45 2013 
 *
 */

#include "rtm/idl/RTCStub.h"

#if   defined ORB_IS_TAO
#include "rtm/idl/RTCC.cpp"
#elif defined ORB_IS_OE
#include "rtm/idl/RTC.cxx"
#elif defined ORB_IS_OMNIORB
#ifdef WIN32
#pragma warning( disable : 4267 )
#pragma warning( disable : 4290 )
#pragma warning( disable : 4311 )
#pragma warning( disable : 4312 )
#endif // WIN32
#include "rtm/idl/RTCSK.cc"
#include "rtm/idl/RTCDynSK.cc"
#ifdef WIN32
#pragma warning( default : 4267 )
#pragma warning( default : 4290 )
#pragma warning( default : 4311 )
#pragma warning( default : 4312 )
#endif // WIN32
#elif defined ORB_IS_MICO
#include "rtm/idl/RTC.cc"
#elif defined ORB_IS_ORBIT2
#include "rtm/idl/RTC-cpp-stubs.cc"
#elif defined ORB_IS_RTORB
#include "rtm/idl/RTC-stubs.c"
#else
#error "NO ORB defined"
#endif

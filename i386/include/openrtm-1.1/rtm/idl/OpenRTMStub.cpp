// -*- C++ -*-
/*!
 *
 * THIS FILE IS GENERATED AUTOMATICALLY!! DO NOT EDIT!!
 *
 * @file  OpenRTMStub.cpp 
 * @brief OpenRTM server skeleton wrapper code
 * @date  Mon Aug 19 22:24:45 2013 
 *
 */

#include "rtm/idl/OpenRTMStub.h"

#if   defined ORB_IS_TAO
#include "rtm/idl/OpenRTMC.cpp"
#elif defined ORB_IS_OE
#include "rtm/idl/OpenRTM.cxx"
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
#elif defined ORB_IS_ORBIT2
#include "rtm/idl/OpenRTM-cpp-stubs.cc"
#elif defined ORB_IS_RTORB
#include "rtm/idl/OpenRTM-stubs.c"
#else
#error "NO ORB defined"
#endif

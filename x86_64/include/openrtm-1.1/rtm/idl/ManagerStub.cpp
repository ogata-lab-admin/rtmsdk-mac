// -*- C++ -*-
/*!
 *
 * THIS FILE IS GENERATED AUTOMATICALLY!! DO NOT EDIT!!
 *
 * @file  ManagerStub.cpp 
 * @brief Manager server skeleton wrapper code
 * @date  Mon Aug 19 21:58:42 2013 
 *
 */

#include "rtm/idl/ManagerStub.h"

#if   defined ORB_IS_TAO
#include "rtm/idl/ManagerC.cpp"
#elif defined ORB_IS_OE
#include "rtm/idl/Manager.cxx"
#elif defined ORB_IS_OMNIORB
#ifdef WIN32
#pragma warning( disable : 4267 )
#pragma warning( disable : 4290 )
#pragma warning( disable : 4311 )
#pragma warning( disable : 4312 )
#endif // WIN32
#include "rtm/idl/ManagerSK.cc"
#include "rtm/idl/ManagerDynSK.cc"
#ifdef WIN32
#pragma warning( default : 4267 )
#pragma warning( default : 4290 )
#pragma warning( default : 4311 )
#pragma warning( default : 4312 )
#endif // WIN32
#elif defined ORB_IS_MICO
#include "rtm/idl/Manager.cc"
#elif defined ORB_IS_ORBIT2
#include "rtm/idl/Manager-cpp-stubs.cc"
#elif defined ORB_IS_RTORB
#include "rtm/idl/Manager-stubs.c"
#else
#error "NO ORB defined"
#endif

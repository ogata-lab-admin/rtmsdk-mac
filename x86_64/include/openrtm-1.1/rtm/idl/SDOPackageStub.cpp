// -*- C++ -*-
/*!
 *
 * THIS FILE IS GENERATED AUTOMATICALLY!! DO NOT EDIT!!
 *
 * @file  SDOPackageStub.cpp 
 * @brief SDOPackage server skeleton wrapper code
 * @date  Mon Aug 19 21:58:41 2013 
 *
 */

#include "rtm/idl/SDOPackageStub.h"

#if   defined ORB_IS_TAO
#include "rtm/idl/SDOPackageC.cpp"
#elif defined ORB_IS_OE
#include "rtm/idl/SDOPackage.cxx"
#elif defined ORB_IS_OMNIORB
#ifdef WIN32
#pragma warning( disable : 4267 )
#pragma warning( disable : 4290 )
#pragma warning( disable : 4311 )
#pragma warning( disable : 4312 )
#endif // WIN32
#include "rtm/idl/SDOPackageSK.cc"
#include "rtm/idl/SDOPackageDynSK.cc"
#ifdef WIN32
#pragma warning( default : 4267 )
#pragma warning( default : 4290 )
#pragma warning( default : 4311 )
#pragma warning( default : 4312 )
#endif // WIN32
#elif defined ORB_IS_MICO
#include "rtm/idl/SDOPackage.cc"
#elif defined ORB_IS_ORBIT2
#include "rtm/idl/SDOPackage-cpp-stubs.cc"
#elif defined ORB_IS_RTORB
#include "rtm/idl/SDOPackage-stubs.c"
#else
#error "NO ORB defined"
#endif

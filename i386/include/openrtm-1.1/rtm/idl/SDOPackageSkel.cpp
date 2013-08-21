// -*- C++ -*-
/*!
 *
 * THIS FILE IS GENERATED AUTOMATICALLY!! DO NOT EDIT!!
 *
 * @file  SDOPackageSkel.cpp 
 * @brief SDOPackage server skeleton wrapper code
 * @date  Mon Aug 19 22:24:45 2013 
 *
 */

#include "rtm/idl/SDOPackageSkel.h"

#if   defined ORB_IS_TAO
#include "rtm/idl/SDOPackageC.cpp"
#include "rtm/idl/SDOPackageS.cpp"
#elif defined ORB_IS_OE
#include "rtm/idl/SDOPackage.cxx"
#include "rtm/idl/SDOPackage_s.cxx"
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
#include "rtm/idl/SDOPackage_skel.cc"
#elif defined ORB_IS_ORBIT2
#include "rtm/idl/SDOPackage-cpp-skels.cc"
#include "rtm/idl/SDOPackage-cpp-stubs.cc"
#elif defined ORB_IS_RTORB
#include "rtm/idl/SDOPackage-common.c"
#include "rtm/idl/SDOPackage-stubs.c"
#include "rtm/idl/SDOPackage-skels.c"
#include "rtm/idl/SDOPackage-skelimpl.c"
#else
#error "NO ORB defined"
#endif

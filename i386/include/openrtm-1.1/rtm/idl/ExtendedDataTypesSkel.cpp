// -*- C++ -*-
/*!
 *
 * THIS FILE IS GENERATED AUTOMATICALLY!! DO NOT EDIT!!
 *
 * @file  ExtendedDataTypesSkel.cpp 
 * @brief ExtendedDataTypes server skeleton wrapper code
 * @date  Mon Aug 19 22:24:46 2013 
 *
 */

#include "rtm/idl/ExtendedDataTypesSkel.h"

#if   defined ORB_IS_TAO
#include "rtm/idl/ExtendedDataTypesC.cpp"
#include "rtm/idl/ExtendedDataTypesS.cpp"
#elif defined ORB_IS_OE
#include "rtm/idl/ExtendedDataTypes.cxx"
#include "rtm/idl/ExtendedDataTypes_s.cxx"
#elif defined ORB_IS_OMNIORB
#ifdef WIN32
#pragma warning( disable : 4267 )
#pragma warning( disable : 4290 )
#pragma warning( disable : 4311 )
#pragma warning( disable : 4312 )
#endif // WIN32
#include "rtm/idl/ExtendedDataTypesSK.cc"
#include "rtm/idl/ExtendedDataTypesDynSK.cc"
#ifdef WIN32
#pragma warning( default : 4267 )
#pragma warning( default : 4290 )
#pragma warning( default : 4311 )
#pragma warning( default : 4312 )
#endif // WIN32
#elif defined ORB_IS_MICO
#include "rtm/idl/ExtendedDataTypes.cc"
#include "rtm/idl/ExtendedDataTypes_skel.cc"
#elif defined ORB_IS_ORBIT2
#include "rtm/idl/ExtendedDataTypes-cpp-skels.cc"
#include "rtm/idl/ExtendedDataTypes-cpp-stubs.cc"
#elif defined ORB_IS_RTORB
#include "rtm/idl/ExtendedDataTypes-common.c"
#include "rtm/idl/ExtendedDataTypes-stubs.c"
#include "rtm/idl/ExtendedDataTypes-skels.c"
#include "rtm/idl/ExtendedDataTypes-skelimpl.c"
#else
#error "NO ORB defined"
#endif

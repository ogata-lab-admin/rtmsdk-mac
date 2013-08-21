// -*- C++ -*-
/*!
 *
 * THIS FILE IS GENERATED AUTOMATICALLY!! DO NOT EDIT!!
 *
 * @file  InterfaceDataTypesSkel.cpp 
 * @brief InterfaceDataTypes server skeleton wrapper code
 * @date  Mon Aug 19 22:24:46 2013 
 *
 */

#include "rtm/idl/InterfaceDataTypesSkel.h"

#if   defined ORB_IS_TAO
#include "rtm/idl/InterfaceDataTypesC.cpp"
#include "rtm/idl/InterfaceDataTypesS.cpp"
#elif defined ORB_IS_OE
#include "rtm/idl/InterfaceDataTypes.cxx"
#include "rtm/idl/InterfaceDataTypes_s.cxx"
#elif defined ORB_IS_OMNIORB
#ifdef WIN32
#pragma warning( disable : 4267 )
#pragma warning( disable : 4290 )
#pragma warning( disable : 4311 )
#pragma warning( disable : 4312 )
#endif // WIN32
#include "rtm/idl/InterfaceDataTypesSK.cc"
#include "rtm/idl/InterfaceDataTypesDynSK.cc"
#ifdef WIN32
#pragma warning( default : 4267 )
#pragma warning( default : 4290 )
#pragma warning( default : 4311 )
#pragma warning( default : 4312 )
#endif // WIN32
#elif defined ORB_IS_MICO
#include "rtm/idl/InterfaceDataTypes.cc"
#include "rtm/idl/InterfaceDataTypes_skel.cc"
#elif defined ORB_IS_ORBIT2
#include "rtm/idl/InterfaceDataTypes-cpp-skels.cc"
#include "rtm/idl/InterfaceDataTypes-cpp-stubs.cc"
#elif defined ORB_IS_RTORB
#include "rtm/idl/InterfaceDataTypes-common.c"
#include "rtm/idl/InterfaceDataTypes-stubs.c"
#include "rtm/idl/InterfaceDataTypes-skels.c"
#include "rtm/idl/InterfaceDataTypes-skelimpl.c"
#else
#error "NO ORB defined"
#endif

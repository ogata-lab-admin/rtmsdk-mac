// -*- C++ -*-
/*!
 *
 * THIS FILE IS GENERATED AUTOMATICALLY!! DO NOT EDIT!!
 *
 * @file  BasicDataTypeSkel.cpp 
 * @brief BasicDataType server skeleton wrapper code
 * @date  Mon Aug 19 21:58:42 2013 
 *
 */

#include "rtm/idl/BasicDataTypeSkel.h"

#if   defined ORB_IS_TAO
#include "rtm/idl/BasicDataTypeC.cpp"
#include "rtm/idl/BasicDataTypeS.cpp"
#elif defined ORB_IS_OE
#include "rtm/idl/BasicDataType.cxx"
#include "rtm/idl/BasicDataType_s.cxx"
#elif defined ORB_IS_OMNIORB
#ifdef WIN32
#pragma warning( disable : 4267 )
#pragma warning( disable : 4290 )
#pragma warning( disable : 4311 )
#pragma warning( disable : 4312 )
#endif // WIN32
#include "rtm/idl/BasicDataTypeSK.cc"
#include "rtm/idl/BasicDataTypeDynSK.cc"
#ifdef WIN32
#pragma warning( default : 4267 )
#pragma warning( default : 4290 )
#pragma warning( default : 4311 )
#pragma warning( default : 4312 )
#endif // WIN32
#elif defined ORB_IS_MICO
#include "rtm/idl/BasicDataType.cc"
#include "rtm/idl/BasicDataType_skel.cc"
#elif defined ORB_IS_ORBIT2
#include "rtm/idl/BasicDataType-cpp-skels.cc"
#include "rtm/idl/BasicDataType-cpp-stubs.cc"
#elif defined ORB_IS_RTORB
#include "rtm/idl/BasicDataType-common.c"
#include "rtm/idl/BasicDataType-stubs.c"
#include "rtm/idl/BasicDataType-skels.c"
#include "rtm/idl/BasicDataType-skelimpl.c"
#else
#error "NO ORB defined"
#endif

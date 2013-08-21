// -*- C++ -*-
/*!
 * @file ExecutionContextProfile.h
 * @brief ExecutionContextProfile class
 * @date $Date$
 * @author Noriaki Ando <n-ando@aist.go.jp>
 *
 * Copyright (C) 2011
 *     Noriaki Ando
 *     Intelligent Systems Research Institute,
 *     National Institute of
 *         Advanced Industrial Science and Technology (AIST), Japan
 *     All rights reserved.
 *
 * $Id$
 *
 */

#ifndef RTC_EXECUTIONCONTEXTPROFILE_H
#define RTC_EXECUTIONCONTEXTPROFILE_H

#include <coil/Mutex.h>
#include <coil/Guard.h>
#include <coil/Properties.h>
#include <coil/TimeValue.h>

#include <rtm/idl/RTCStub.h>
#include <rtm/SystemLogger.h>

#ifdef WIN32
#pragma warning( disable : 4290 )
#endif

namespace RTC_impl
{
  /*!
   * @if jp
   * @class ExecutionContextProfile
   * @brief ExecutionContextProfile ���饹
   *
   * Periodic Sampled Data Processing(�����¹���)ExecutionContext���饹��
   *
   * @since 0.4.0
   *
   * @else
   * @class ExecutionContextProfile
   * @brief ExecutionContextProfile class
   *
   * Periodic Sampled Data Processing (for the execution cycles)
   * ExecutionContext class
   *
   * @since 0.4.0
   *
   * @endif
   */
  class ExecutionContextProfile
  {
    typedef coil::Guard<coil::Mutex> Guard;
  public:
    /*!
     * @if jp
     * @brief �ǥե���ȥ��󥹥ȥ饯��
     *
     * �ǥե���ȥ��󥹥ȥ饯��
     * �ץ�ե�����˰ʲ��ι��ܤ����ꤹ�롣
     *  - kind : PERIODIC
     *  - rate : 0.0
     *
     * @else
     * @brief Default Constructor
     *
     * Default Constructor
     * Set the following items to profile.
     *  - kind : PERIODIC
     *  - rate : 0.0
     *
     * @endif
     */
    ExecutionContextProfile(RTC::ExecutionKind kind = RTC::PERIODIC);

    /*!
     * @if jp
     * @brief �ǥ��ȥ饯��
     *
     * �ǥ��ȥ饯��
     *
     * @else
     * @brief Destructor
     *
     * Destructor
     *
     * @endif
     */
    virtual ~ExecutionContextProfile(void);

    /*!
     * @if jp
     * @brief CORBA ���֥������Ȼ��ȤΥ��å�
     *
     * ExecutioncontextService �� CORBA ���֥������Ȼ��Ȥ򥻥åȤ��롣
     * ���åȤ����ȡ�����ޤǥ��åȤ���Ƥ������֥������Ȼ��Ȥ�
     * release����롣���åȤ��륪�֥������Ȼ��Ȥ�ͭ���ʻ��ȤǤʤ����
     * �ʤ�ʤ���
     *
     * @param ec_ptr ExecutionContextService��CORBA���֥������Ȼ���
     *
     * @else
     * @brief Setting a CORBA object reference
     *
     * This operation sets a object reference to
     * ExecutionContextService.  After setting a new object reference,
     * old reference is released.  The object reference have to be
     * valid reference.
     *
     * @param ec_ptr A CORBA object reference of ExecutionContextService
     *
     * @endif
     */
    void setObjRef(RTC::ExecutionContextService_ptr ec_ptr);

    /*!
     * @if jp
     * @brief CORBA ���֥������Ȼ��Ȥμ���
     *
     * �ܥ��֥������Ȥ� ExecutioncontextService �Ȥ��Ƥ� CORBA ���֥���
     * ���Ȼ��Ȥ�������롣
     *
     * @return CORBA ���֥������Ȼ���
     *
     * @else
     * @brief Get the reference to the CORBA object
     *
     * Get the reference to the CORBA object as
     * ExecutioncontextService of this object.
     *
     * @return The reference to CORBA object
     *
     * @endif
     */
    RTC::ExecutionContextService_ptr getObjRef(void) const;

    /*!
     * @if jp
     * @brief ExecutionContext �μ¹Լ���(Hz)�����ꤹ��
     *
     * Active ���֤ˤ�RT����ݡ��ͥ�Ȥ��¹Ԥ�������(ñ��:Hz)�����ꤹ
     * �롣�¹Լ������ѹ��ϡ�DataFlowComponentAction ��
     * on_rate_changed �ˤ�äƳ�RT����ݡ��ͥ�Ȥ���ã����롣
     *
     * @param rate ��������(ñ��:Hz)
     *
     * @return ReturnCode_t ���Υ꥿���󥳡���
     *         RTC_OK: ���ｪλ
     *         BAD_PARAMETER: �����ͤ������
     *
     * @else
     *
     * @brief Set execution rate(Hz) of ExecutionContext
     *
     * This operation shall set the rate (in hertz) at which this
     * context��s Active participating RTCs are being called.  If the
     * execution kind of the context is PERIODIC, a rate change shall
     * result in the invocation of on_rate_changed on any RTCs
     * realizing DataFlowComponentAction that are registered with any
     * RTCs participating in the context.
     *
     * @param rate Execution cycle(Unit:Hz)
     *
     * @return The return code of ReturnCode_t type
     *         RTC_OK: Succeed
     *         BAD_PARAMETER: Invalid value. The value might be negative.
     *
     * @endif
     */
    RTC::ReturnCode_t setRate(double rate);
    RTC::ReturnCode_t setPeriod(double period);
    RTC::ReturnCode_t setPeriod(coil::TimeValue period);

    /*!
     * @if jp
     * @brief ExecutionContext �μ¹Լ���(Hz)���������
     *
     * Active ���֤ˤ�RT����ݡ��ͥ�Ȥ��¹Ԥ�������(ñ��:Hz)�������
     * �롣
     *
     * @return ��������(ñ��:Hz)
     *
     * @else
     *
     * @brief Get execution rate(Hz) of ExecutionContext
     *
     * This operation shall return the rate (in hertz) at which its
     * Active participating RTCs are being invoked.
     *
     * @return Execution cycle(Unit:Hz)
     *
     * @endif
     */
    double getRate(void) const;
    coil::TimeValue getPeriod(void) const;

    /*!
     * @if jp
     * @brief ExecutionKind ��ʸ���󲽤���
     *
     * RTC::ExecutionKind ���������Ƥ��� PERIODIC, EVENT_DRIVEN,
     * OTHER ��ʸ���󲽤��롣
     *
     * @param kind ExecutionKind
     * @return ʸ���󲽤��줿ExecutionKind
     *
     * @else
     *
     * @brief Converting ExecutionKind enum to string 
     *
     * This function converts enumeration (PERIODIC, EVENT_DRIVEN,
     * OTHER) defined in RTC::ExecutionKind to string.
     *
     * @param kind ExecutionKind
     * @return String of ExecutionKind
     *
     * @endif
     */
    const char* getKindString(RTC::ExecutionKind kind) const;
    const char* getKindString() const
    {
      return getKindString(m_profile.kind);
    }

    /*!
     * @if jp
     * @brief ExecutionKind �����ꤹ��
     *
     * ���� ExecutionContext �� ExecutionKind �����ꤹ��
     *
     * @param kind ExecutionKind
     *
     * @else
     *
     * @brief Set the ExecutionKind
     *
     * This operation sets the kind of the execution context.
     *
     * @param kind ExecutionKind
     *
     * @endif
     */
    RTC::ReturnCode_t setKind(RTC::ExecutionKind kind);

    /*!
     * @if jp
     * @brief ExecutionKind ���������
     *
     * �� ExecutionContext �� ExecutionKind ���������
     *
     * @return ExecutionKind
     *
     * @else
     *
     * @brief Get the ExecutionKind
     *
     * This operation shall report the execution kind of the execution
     * context.
     *
     * @return ExecutionKind
     *
     * @endif
     */
    RTC::ExecutionKind getKind(void) const;

    /*!
     * @if jp
     * @brief Owner����ݡ��ͥ�Ȥ򥻥åȤ��롣
     *
     * ����EC��Owner�Ȥʤ�RTC�򥻥åȤ��롣
     *
     * @param comp Owner�Ȥʤ�RT����ݡ��ͥ��
     * @return ReturnCode_t ���Υ꥿���󥳡���
     * @else
     * @brief Setting owner component of the execution context
     *
     * This function sets an RT-Component to be owner of the execution context.
     *
     * @param comp an owner RT-Component of this execution context
     * @return The return code of ReturnCode_t type
     * @endif
     */
    RTC::ReturnCode_t setOwner(RTC::LightweightRTObject_ptr comp);

    /*!
     * @if jp
     * @brief Owner����ݡ��ͥ�Ȥλ��Ȥ��������
     *
     * ����EC��Owner�Ǥ���RTC�λ��Ȥ�������롣
     *
     * @return OwnerRT����ݡ��ͥ�Ȥλ���
     * @else
     * @brief Getting a reference of the owner component
     *
     * This function returns a reference of the owner RT-Component of
     * this execution context
     *
     * @return a reference of the owner RT-Component
     * @endif
     */
    const RTC::RTObject_ptr getOwner() const;

    /*!
     * @if jp
     * @brief RT����ݡ��ͥ�Ȥ��ɲä���
     *
     * ���ꤷ��RT����ݡ��ͥ�Ȥ򻲲üԥꥹ�Ȥ��ɲä��롣�ɲä��줿RT��
     * ��ݡ��ͥ�Ȥ� attach_context ���ƤФ졢Inactive ���֤����ܤ��롣
     * ���ꤵ�줿RT����ݡ��ͥ�Ȥ�null�ξ��ϡ�BAD_PARAMETER ���֤���
     * �롣���ꤵ�줿RT����ݡ��ͥ�Ȥ� DataFlowComponent �ʳ��ξ��ϡ�
     * BAD_PARAMETER ���֤���롣
     *
     * @param comp �ɲ��о�RT����ݡ��ͥ��
     *
     * @return ReturnCode_t ���Υ꥿���󥳡���
     *
     * @else
     *
     * @brief Add an RT-component
     *
     * The operation causes the given RTC to begin participating in
     * the execution context.  The newly added RTC will receive a call
     * to LightweightRTComponent::attach_context and then enter the
     * Inactive state.  BAD_PARAMETER will be invoked, if the given
     * RT-Component is null or if the given RT-Component is other than
     * DataFlowComponent.
     *
     * @param comp The target RT-Component for add
     *
     * @return The return code of ReturnCode_t type
     *
     * @endif
     */
    RTC::ReturnCode_t addComponent(RTC::LightweightRTObject_ptr comp);

    /*!
     * @if jp
     * @brief RT����ݡ��ͥ�Ȥ򻲲üԥꥹ�Ȥ���������
     *
     * ���ꤷ��RT����ݡ��ͥ�Ȥ򻲲üԥꥹ�Ȥ��������롣������줿
     * RT����ݡ��ͥ�Ȥ� detach_context ���ƤФ�롣���ꤵ�줿RT����ݡ�
     * �ͥ�Ȥ����üԥꥹ�Ȥ���Ͽ����Ƥ��ʤ����ϡ�BAD_PARAMETER ����
     * ����롣
     *
     * @param comp ����о�RT����ݡ��ͥ��
     *
     * @return ReturnCode_t ���Υ꥿���󥳡���
     *
     * @else
     *
     * @brief Remove the RT-Component from participant list
     *
     * This operation causes a participant RTC to stop participating in the
     * execution context.
     * The removed RTC will receive a call to
     * LightweightRTComponent::detach_context.
     * BAD_PARAMETER will be returned, if the given RT-Component is not
     * participating in the participant list.
     *
     * @param comp The target RT-Component for delete
     *
     * @return The return code of ReturnCode_t type
     *
     * @endif
     */
    RTC::ReturnCode_t removeComponent(RTC::LightweightRTObject_ptr comp);

    /*!
     * @if jp
     * @brief RT����ݡ��ͥ�Ȥλ��üԥꥹ�Ȥ��������
     *
     * ������Ͽ����Ƥ��뻲�ü�RTC�Υꥹ�Ȥ�������롣���δؿ��ϥ���ݡ�
     * �ͥ�ȥꥹ�ȤΥ����ѿ��ؤλ��Ȥ��֤��Τǡ��ꥹ�Ȼ�������
     * ExecutionContextProfile::lock() �ǥ�å������ꥹ�Ȼ��Ѹ��
     * ExecutionContextProfile::unlock() �ǥ�å��������ʤ���Фʤ��
     * ����
     *
     * @return ���ü�RTC�Υꥹ��
     *
     * @else
     *
     * @brief Getting participant RTC list
     *
     * This function returns a list of participant RTC of the
     * execution context.  Since the function returns a reference to
     * the member variable of component list, user have to lock by
     * ExecutionContextProfile::lock() before using the list, and user
     * also have to release the unlock by
     * ExecutionContextProfile::unlock().
     *
     * @return Participants RTC list
     *
     * @endif
     */
    const RTC::RTCList& getComponentList() const;

    /*!
     * @if jp
     * @brief Properties�򥻥åȤ���
     *
     * ExecutionContextProfile::properties �򥻥åȤ��롣
     *
     * @param props ExecutionContextProfile::properties �˥��åȤ����
     *              ��ѥƥ���
     *
     * @else
     * @brief Setting Properties
     *
     * This function sets ExecutionContextProfile::properties by
     * coil::Properties.
     *
     * @param props Properties to be set to
     *              ExecutionContextProfile::properties.
     *
     * @endif
     */
    void setProperties(coil::Properties& props);

    /*!
     * @if jp
     * @brief Properties���������
     *
     * ExecutionContextProfile::properties ��������롣
     *
     * @return coil::Properties���Ѵ����줿
     *              ExecutionContextProfile::properties
     *
     * @else
     * @brief Setting Properties
     *
     * This function sets ExecutionContextProfile::properties by
     * coil::Properties.
     *
     * @param props Properties to be set to ExecutionContextProfile::properties.
     *
     * @endif
     */
    const coil::Properties getProperties() const;

    /*!
     * @if jp
     * @brief Profile���������
     *
     * RTC::ExecutionContextProfile ��������롣��������
     * ExecutionContextProfile �ν�ͭ���ϸƤӽФ�¦�ˤ��롣�������줿��
     * �֥������Ȥ����פˤʤä���硢�ƤӽФ�¦������������Ǥ���餦��
     *
     * @return RTC::ExecutionContextProfile
     *
     * @else
     * @brief Getting Profile
     *
     * This function gets RTC::ExecutionContextProfile.  The ownership
     * of the obtained ExecutionContextProfile is given to caller. The
     * caller should release obtained object when it is unneccessary
     * anymore.
     *
     * @return RTC::ExecutionContextProfile
     *
     * @endif
     */
    RTC::ExecutionContextProfile* getProfile(void);

    /*!
     * @if jp
     * @brief Profile���������
     *
     * RTC::ExecutionContextProfile ��������롣
     *
     * @return RTC::ExecutionContextProfile
     *
     * @else
     * @brief Getting Profile
     *
     * This function gets RTC::ExecutionContextProfile.
     *
     * @return RTC::ExecutionContextProfile
     *
     * @endif
     */
    const RTC::ExecutionContextProfile& getProfile(void) const;

    /*!
     * @if jp
     * @brief ExecutionContextProfile���å�����
     *
     * ���Υ��֥������Ȥ��������� RTC::ExecutionContextProfile ���å����롣
     * ��å������פˤʤä��ݤˤ�unlock()�ǥ�å��������ʤ���Фʤ�ʤ���
     *
     * @else
     * @brief Getting a lock of RTC::ExecutionContextProfile
     *
     * This function locks  RTC::ExecutionContextProfile in the object.
     * The lock should be released when the lock is unneccessary.
     *
     * @endif
     */
    void lock() const;

    /*!
     * @if jp
     * @brief ExecutionContextProfile�򥢥��å�����
     *
     * ���Υ��֥������Ȥ��������� RTC::ExecutionContextProfile �򥢥���
     * �����롣
     *
     * @else
     * @brief Release a lock of the RTC::ExecutionContextProfile
     *
     * This function release the lock of RTC::ExecutionContextProfile
     * in the object.
     *
     * @endif
     */
    void unlock() const;

  private:
    /*!
     * @if jp
     * @brief Logger
     * @else
     * @brief Logger
     * @endif
     */
    mutable RTC::Logger rtclog;
    /*!
     * @if jp
     * @brief ECProfile
     * @else
     * @brief ECProfile
     * @endif
     */
    RTC::ExecutionContextProfile m_profile;

    /*!
     * @if jp
     * @brief mutex of ExecutionContextProfile
     * @else
     * @brief mutex ExecutionContextProfile
     * @endif
     */
    mutable coil::Mutex m_profileMutex;

    /*!
     * @if jp
     * @brief ExecutionContext �μ¹Լ���
     * @else
     * @brief Execution cycle of ExecutionContext
     * @endif
     */
    coil::TimeValue m_period;

    /*!
     * @if jp
     * @brief ExecutionContextService ���֥������Ȥؤλ���
     * @else
     * @brief Reference to ExecutionContextService object
     * @endif
     */
    RTC::ExecutionContextService_var m_ref;

    class find_participant
    {
      RTC::RTObject_var m_comp;
    public:      
      find_participant(RTC::RTObject_ptr comp)
        : m_comp(RTC::RTObject::_duplicate(comp)) {}
      bool operator()(RTC::RTObject_ptr comp)
      {
        return m_comp->_is_equivalent(comp);
      }
    };
  }; // class ExecutionContextProfile
}; // namespace RTC

#ifdef WIN32
#pragma warning( default : 4290 )
#endif

#endif // RTC_EXECUTIONCONTEXTPROFILE_H

// -*- C++ -*-
/*!
 * @file ExecutionContextBase.h
 * @brief ExecutionContext base class
 * @date $Date: 2008-01-14 07:48:55 $
 * @author Noriaki Ando <n-ando@aist.go.jp>
 *
 * Copyright (C) 2007, 2011-2012
 *     Intelligent Systems Research Institute,
 *     National Institute of
 *         Advanced Industrial Science and Technology (AIST), Japan
 *     All rights reserved.
 *
 * $Id: ExecutionContextBase.h 2307 2012-02-05 21:29:15Z n-ando $
 *
 */

#ifndef RTC_EXECUTIONCONTEXTBASE_H
#define RTC_EXECUTIONCONTEXTBASE_H

#include <coil/Factory.h>

#include <rtm/idl/RTCSkel.h>
#include <rtm/idl/OpenRTMSkel.h>
#include <rtm/Factory.h>
#include <rtm/ExecutionContextProfile.h>
#include <rtm/ExecutionContextWorker.h>

#ifdef WIN32
#pragma warning( disable : 4290 )
#endif

#define DEFAULT_EXECUTION_RATE 1000

namespace coil
{
  class Properties;
}

namespace RTC
{
  /*!
   * @if jp
   * @class ExecutionContextBase
   * @brief ExecutionContext�Ѵ��쥯�饹
   *
   * EC�μ������饹�Ǥϡ����δ��쥯�饹��Ѿ���������EC��CORBA���ڥ졼
   * ������������ʤ���Фʤ�ʤ�������ˡ��ºݤ˥��å����ư���뤿
   * �ᡢ���Ĥ�����«��§��ExecutionContextBase�δؿ���ƤӽФ�ɬ�פ���
   * �롣EC��CORBA���ڥ졼�����ϰʲ��Τ�Τ����ꡢ���줾��
   * ExecutionContextBase�Υ��дؿ����б����Ƥ��롣
   *
   * - is_running(): ExecutionContextBase::isRunning()
   * - start(): ExecutionContextBase::start()
   * - stop(): ExecutionContextBase::stop()
   *
   * - get_rate(): ExecutionContextBase::gatRate()
   * - set_rate(): ExecutioinContextBase::setRate()
   *
   * - add_component(): ExecutionContextBase::addComponent()
   * - remove_component(): ExecutionContextBase::removeComponent()
   *
   * - activate_component(): ExecutionContextBase::activateComponent()
   * - deactivate_component(): ExecutionContextBase::deactivateComponent()
   * - reset_component(): ExecutionContextBase::resetComponent()
   *
   * - get_component_state(): ExecutionContextBase::getComponentState()
   * - get_kind(): ExecutionContextBase::getKind()
   * - get_profile(): ExecutionContextBase::getProfile()
   *
   * @par �¹Ծ��֤˴ط�����ؿ��ȼ�����ˡ
   * - is_running(): ExecutionContextBase::isRunning()
   * - start(): ExecutionContextBase::start()
   * - stop(): ExecutionContextBase::stop()
   *
   * �¹Ծ��֤˴ط�����ؿ��ϡ�is_running(), start(), stop() ��3�Ĥ���
   * �롣ExecutionContextBase�Ǥ�ñ��� running/stopped �Υե饰�����
   * �Ƥ��ꡢstart/stop�ǥե饰��ON/OFF�ڤ��ؤ���is_running()�Ǿ����ɤ�
   * �Ф���ԤäƤ��롣�̾EC�μ������饹�Ǥϡ�protected �ʲ��ۥ��
   * �дؿ� onStarting(), onStarted(), onStopping(), onStopped() �ؿ���
   * �������������ǡ�CORBA���ڥ졼������ʲ��Τ褦�˼�������ɬ�פ����롣
   *
   * is_running() ��CORBA���ڥ졼�����Ǥϡ�ñ���
   * ExecutionContextBase �� isRunning() ��ƤӽФ������Ǥ��롣���δؿ�
   * �˴�Ϣ���� protected ���۴ؿ���onIsRunning() ���Ѱդ���Ƥ��뤬��
   * �̾��ä˼�������ɬ�פϤʤ��������ơ����ߤ� running/stopped ���֤�
   * �񤭴����������ˤ��δؿ������Ѥ��뤳�Ȥ��Ǥ��뤬�侩�Ϥ���ʤ���
   *
   * <pre>
   * public:
   *  CORBA::Boolean is_runing()
   *  {
   *    return ExecutionContextBase::isRunning();
   *  }
   * protected:
   *  CORBA::Boolean onIsRunning(CORBA::Boolean running)
   *  {
   *    return running;
   *  }
   * </pre>
   *
   * start(), stop() CORBA���ڥ졼�����Ǥϡ��̾�
   * ExecutionContextBase �� start(), stop() �ؿ���ƤӽФ��褦�������롣
   * ���δؿ��˴�Ϣ���� protected ���۴ؿ��ϡ�start() ����� stop() ��
   * �Ĥ��Ƥ��줾��2�ĤŤĤ� onStarting(), onStarted(), �����
   * onStopping(), onStopped() �ؿ������롣EC�μ������饹�ˤ����Ƥϡ���
   * �줾��ʲ��Τ褦�˼������롣
   *
   * <pre>
   *  RTC::ReturnCode_t start()
   *  {
   *    return ExecutionContextBase::start();
   *  }
   *  RTC::ReturnCode_t stop()
   *  {
   *    return ExecutionContextBase::stop();
   *  }
   * protected:
   *  RTC::ReturnCode_t onStarting()
   *  {
   *    RTC::ReturnCode_t ret = // ����åɤ򳫻Ϥ�������ʤ�
   *    return ret;
   *  }
   *  RTC::ReturnCode_t onStarted()
   *  {
   *    RTC::ReturnCode_t ret = // ����åɤ򳫻Ϥ�������ʤ�
   *    return ret;
   *  }
   *  RTC::ReturnCode_t onStopping()
   *  {
   *    // ����åɤ���ߤ�������ʤ�
   *    return retcode;
   *  }
   *  RTC::ReturnCode_t onStopped()
   *  {
   *    // ����åɤ���ߤ�������ʤ�
   *    return retcode;
   *  }
   * </pre>
   *
   * @par �¹Լ����˴ؤ���ؿ��ȼ�����ˡ
   * - get_rate(): ExecutionContextBase::gatRate()
   * - set_rate(): ExecutioinContextBase::setRate()
   *
   * �¹Լ����˴ؤ���ؿ��� set_rate(), get_rate() ��2���ब���롣����
   * ����¹ԥ���ƥ����Ȥ��⤷ set_rate() �ˤ����ꤵ�����������Ѥ���
   * ��硢�ƥ�ץ졼�ȴؿ� onSetRate() �򥪡��С��饤�ɤ��������롣
   * onSetRate() �ϰ����� double ���μ������ꡢ�����ͤ��������ͤǤ���
   * ���Ȥ��ݾڤ���Ƥ��롣onSetRate() ��RTC::RTC_OK �ʳ����ͤ��֤�����
   * �硢EC��Profile�μ��������ꤵ���������ͤ��ݻ����뤳�Ȥ��ݾڤ���
   * �롣
   *
   * set_rate() Ʊ�� get_rate() �ƤӽФ�����onGetRate() ���ƤӽФ����
   * ����������̾索���С��饤�����ɬ�פϤʤ�����������get_rate() ��
   * �֤��ͤ��ѹ���������硢onGetRate() �򥪡��С��饤�ɤ��뤳�ȤǤ���
   * �ͤ�񤭴����뤳�Ȥ��Ǥ��롣������������Ͽ侩����ʤ���
   *
   * <pre>
   * public:
   *  RTC::ReturnCode_t set_rate(double rate)
   *  {
   *    return setRate(rate);
   *  }
   *  double get_rate(void) const
   *  {
   *    return getRate();
   *  }
   * protected:
   *  virtual RTC::ReturnCode_t onSetRate(double rate)
   *  {
   *    RTC::ReturnCode_t ret = // ���������ꤹ�벿�餫�ν���
   *    if (ret != RTC::RTC_OK)
   *      {
   *        RTC_ERROR(("Error message"));
   *      }
   *    return ret;
   *  }
   *  virtual double onGetRate(rate)
   *  {
   *    // get_rate() ���֤��ͤ�ù����������
   *    // �̾�Ϥ��δؿ����������ɬ�פϤʤ���
   *    return rate;
   *  }
   * </pre>
   *
   * @par ����ݡ��ͥ�Ȥ��ɲäȺ���˴ؤ���ؿ�
   * - add_component(): ExecutionContextBase::addComponent()
   * - remove_component(): ExecutionContextBase::removeComponent()
   *
   * ����ݡ��ͥ�Ȥ��ɲäȺ���˴ؤ���ؿ��ϡ�add_component(),
   * remove_component() ������ब���롣�¹ԥ���ƥ����Ȥμ������饹��
   * �����Ƥϡ�ExecutionContextBase �Τ��줾�� addComponent(),
   * removeComponent() ��ƤӽФ����Ǽ�����Ԥ��������δؿ��˴�Ϣ����
   * protected ���۴ؿ��� onAddingComponent(), onAddedComponent(),
   * onRemovingComponent(), onRemovedComponent() ��4���ढ�롣��������
   * �����β��۴ؿ����̾索���С��饤�ɤ���ɬ�פϤʤ������ѤϿ侩����
   * �ʤ���
   *
   * <pre>
   * public:
   *  RTC::ReturnCode_t add_component(RTC::LightweightRTObject_ptr comp)
   *  {
   *    return ExecutionContextBase::addComponent(comp);
   *  }
   *  RTC::ReturnCode_t remove_component(RTC::LightweightRTObject_ptr comp)
   *  {
   *    return ExecutionContextBase::removeComponent(comp);
   *  }
   * protected:
   *  virtual RTC::ReturnCode_t
   *  onAddingComponent(RTC::LightweightRTObject rtobj)
   *  {
   *     // ����ݡ��ͥ���ɲû��˼¹Ԥ����������򵭽�
   *     // RTC::RTC_OK �ʳ����֤�����硢����ݡ��ͥ�Ȥ��ɲäϹԤ��ʤ���
   *     return RTC::RTC_OK;
   *  }
   *  virtual RTC::ReturnCode_t
   *  onAddedComponent(RTC::LightweightRTObject rtobj)
   *  {
   *     // ����ݡ��ͥ���ɲû��˼¹Ԥ����������򵭽�
   *     // RTC::RTC_OK �ʳ����֤�����硢removeComponent() ���ƤӽФ��졢
   *     // �ɲä��줿����ݡ��ͥ�Ȥ��������롣
   *     return RTC::RTC_OK;
   *  }
   *  virtual RTC::ReturnCode_t
   *  onRemovingComponent(RTC::LightweightRTObject rtobj)
   *  {
   *     // ����ݡ��ͥ�Ⱥ�����˼¹Ԥ����������򵭽�
   *     // RTC::RTC_OK �ʳ����֤�����硢����ݡ��ͥ�Ȥκ���ϹԤ��ʤ���
   *     return RTC::RTC_OK;
   *  }
   *  virtual RTC::ReturnCode_t
   *  onRemovedComponent(RTC::LightweightRTObject rtobj)
   *  {
   *     // ����ݡ��ͥ���ɲû��˼¹Ԥ����������򵭽�
   *     // RTC::RTC_OK �ʳ����֤�����硢addComponent() ���ƤӽФ��졢
   *     // ������줿����ݡ��ͥ�Ȥ��Ƥ��ɲä���롣
   *     return RTC::RTC_OK;
   *  }
   * </pre>
   *
   * @par ����ݡ��ͥ�ȤΥ����ƥ��ֲ����˴ؤ���ؿ�
   * - activate_component(): ExecutionContextBase::activateComponent()
   * - deactivate_component(): ExecutionContextBase::deactivateComponent()
   * - reset_component(): ExecutionContextBase::resetComponent()
   *
   * ����ݡ��ͥ�ȤΥ����ƥ��ֲ����˴ؤ���ؿ��ϡ�
   * activate_component(), deactivate_component(), reset_component() ��
   * �����ब���롣�¹ԥ���ƥ����Ȥμ������饹�ˤ����Ƥϡ�
   * ExecutionContextBase �Τ��줾�� activateComponent(),
   * deactivateComponent(), resetComponent() ��ƤӽФ����Ǽ�����Ԥ���
   * �����δؿ��˴�Ϣ���� protected ���۴ؿ���
   * onActivatingComponent(), onAtivatingComponent(),
   * onActivatedComponent(), onDeactivatingComponent(),
   * onDeactivatedComponent(), onResettingComponent(),
   * onResetComponent() ��6���ढ�롣�������������β��۴ؿ����̾索��
   * �С��饤�ɤ���ɬ�פϤʤ������ѤϿ侩����ʤ���
   *
   * <pre>
   * public:
   *  RTC::ReturnCode_t add_component(RTC::LightweightRTObject_ptr comp)
   *  {
   *    return ExecutionContextBase::addComponent(comp);
   *  }
   *  RTC::ReturnCode_t remove_component(RTC::LightweightRTObject_ptr comp)
   *  {
   *    return ExecutionContextBase::removeComponent(comp);
   *  }
   * protected:
   *  virtual RTC::ReturnCode_t
   *  onAddingComponent(RTC::LightweightRTObject rtobj)
   *  {
   *    // ����ݡ��ͥ���ɲû��˼¹Ԥ����������򵭽�
   *    // RTC::RTC_OK �ʳ����֤�����硢����ݡ��ͥ�Ȥ��ɲäϹԤ��ʤ���
   *    return RTC::RTC_OK;
   *  }
   *  virtual RTC::ReturnCode_t
   *  onAddedComponent(RTC::LightweightRTObject rtobj)
   *  {
   *    // ����ݡ��ͥ���ɲû��˼¹Ԥ����������򵭽�
   *    // RTC::RTC_OK �ʳ����֤�����硢removeComponent() ���ƤӽФ��졢
   *    // �ɲä��줿����ݡ��ͥ�Ȥ��������롣
   *    return RTC::RTC_OK;
   *  }
   *  virtual RTC::ReturnCode_t
   *  onRemovingComponent(RTC::LightweightRTObject rtobj)
   *  {
   *    // ����ݡ��ͥ�Ⱥ�����˼¹Ԥ����������򵭽�
   *    // RTC::RTC_OK �ʳ����֤�����硢����ݡ��ͥ�Ȥκ���ϹԤ��ʤ���
   *    return RTC::RTC_OK;
   *  }
   *  virtual RTC::ReturnCode_t
   *  onRemovedComponent(RTC::LightweightRTObject rtobj)
   *  {
   *    // ����ݡ��ͥ���ɲû��˼¹Ԥ����������򵭽�
   *    // RTC::RTC_OK �ʳ����֤�����硢addComponent() ���ƤӽФ��졢
   *    // ������줿����ݡ��ͥ�Ȥ��Ƥ��ɲä���롣
   *    return RTC::RTC_OK;
   *  }
   * </pre>
   *
   * @par �¹ԥ���ƥ����Ȥξ�������˴ؤ���ؿ�
   * - get_component_state(): ExecutionContextBase::getComponentState()
   * - get_kind(): ExecutionContextBase::getKind()
   * - get_profile(): ExecutionContextBase::getProfile()
   *
   * �¹ԥ���ƥ����Ȥξ�������˴ؤ���ؿ��ϡ�get_component_state(),
   * get_kind(), get_profile() ��3���ब���롣�¹ԥ���ƥ����Ȥμ�����
   * �饹�ˤ����Ƥϡ�ExecutionContextBase �Τ��줾��
   * getComponentState(), getKind(), getProfile() ��ƤӽФ����Ǽ�����
   * �Ԥ��������δؿ��˴�Ϣ���� protected ���۴ؿ���
   * onGetComponentState(), onGetKind(), onGetProfile() ��3���ढ�롣��
   * ���β��۴ؿ����̾索���С��饤�ɤ���ɬ�פϤʤ������ѤϿ侩�����
   * �������������֤�������ѹ����������ϡ������δؿ���Ŭ�ڤ˼�����
   * �뤳�Ȥǡ��ƤӽФ�¦���֤��ͤ��񤭤��뤳�Ȥ��Ǥ��롣
   *
   * <pre>
   * public:
   *  LifeCycleState get_component_state(RTC::LightweightRTObject_ptr comp)
   *  {
   *    return getComponentState(comp);
   *  }
   *  ExecutionKind PeriodicExecutionContext::get_kind()
   *  {
   *    return getKind();
   *  }
   *  ExecutionContextProfile* get_profile()
   *  {
   *    return getProfile();
   *  }
   *
   * protected:
   *  virtual LifeCycleState onGetComponentState(LifeCycleState state)
   *  { // �֤�state��񤭴����������Ϥ��δؿ����������
   *    return state;
   *  }
   *  virtual ExecutionKind onGetKind(ExecutionKind kind)
   *  { // �֤�kind��񤭴����������Ϥ��δؿ����������
   *    return kind;
   *  }
   *  virtual ExecutionContextProfile*
   *  onGetProfile(ExecutionContextProfile*& profile)
   *  { // �֤�profile��񤭴����������Ϥ��δؿ����������
   *    return profile;
   *  }
   * </pre>
   *
   * ExecutionContext�δ��쥯�饹��
   *
   * @since 0.4.0
   *
   * @else
   * @class ExecutionContextBase
   * @brief A base class for ExecutionContext
   *
   * A base class of ExecutionContext.
   *
   * @since 0.4.0
   *
   * @endif
   */
  class ExecutionContextBase
  {
  public:
    /*!
     * @if jp
     * @brief ���ۥǥ��ȥ饯��
     *
     * ���ۥǥ��ȥ饯��
     *
     * @else
     * @brief Virtual Destructor
     *
     * Virtual Destructor
     *
     * @endif
     */
    ExecutionContextBase(const char* name);

    /*!
     * @if jp
     * @brief ���ۥǥ��ȥ饯��
     *
     * ���ۥǥ��ȥ饯��
     *
     * @else
     * @brief Virtual Destructor
     *
     * Virtual Destructor
     *
     * @endif
     */
    virtual ~ExecutionContextBase(void);

    /*!
     * @if jp
     * @brief ExecutionContext�ν�����ʤ��
     *
     * ExecutionContext�ν����򣱼���ʬ�ʤ�롣
     *
     * @else
     * @brief Proceed with tick of ExecutionContext
     *
     * Proceed with tick of ExecutionContext for one period.
     *
     * @endif
     */
    virtual void init(coil::Properties& props);

    /*!
     * @if jp
     * @brief ����ݡ��ͥ�Ȥ�Х���ɤ��롣
     *
     * ����ݡ��ͥ�Ȥ�Х���ɤ��롣
     *
     * @else
     * @brief Bind the component.
     *
     * Bind the component.
     *
     * @endif
     */
    virtual RTC::ReturnCode_t bindComponent(RTC::RTObject_impl* rtc);

    //============================================================
    // implementation functions for EC's CORBA operation
    //============================================================
    /*!
     * @if jp
     * @brief ExecutionContext �¹Ծ��ֳ�ǧ�ؿ�
     *
     * �������� ExecutionContext �� Runnning ���֤ξ��� true ���֤���
     * �֤��ͤϡ�start() �ؿ����ƤФ줿���Ȥ�Running���֤Ȥʤ�
     * true ��stop() �ؿ����ƤФ줿���Ȥ�Stopped���֤Ȥʤ�false���֤���
     *
     * @return ư����� (Running����:true��Stopped����: false)
     *
     * @else
     *
     * @brief Check for ExecutionContext running state
     *
     * This operation shall return true if the context is in the
     * Running state.  After calling the start() of this class, this
     * function returns true, after calling to stop function of it,
     * this function returns false.
     *
     * @return Working status (Running:true��Stopped:false)
     *
     * @endif
     */
    CORBA::Boolean isRunning();

    /*!
     * @if jp
     * @brief ExecutionContext �μ¹Ԥ򳫻�
     *
     * ExecutionContext �μ¹Ծ��֤� Runnning �Ȥ��뤿��Υꥯ�����Ȥ�
     * ȯ�Ԥ��롣ExecutionContext �ξ��֤����ܤ����
     * ComponentAction::on_startup ���ƤӽФ���롣���ä��Ƥ���RT����ݡ�
     * �ͥ�Ȥ�������������ޤ� ExecutionContext �򳫻Ϥ��뤳�ȤϤǤ�
     * �ʤ���ExecutionContext ��ʣ���󳫻�/��ߤ򷫤��֤����Ȥ��Ǥ��롣
     *
     * @return ReturnCode_t ���Υ꥿���󥳡���
     *
     * @else
     *
     * @brief Start the ExecutionContext
     *
     * Request that the context enter the Running state.  Once the
     * state transition occurs, the ComponentAction::on_startup
     * operation will be invoked.  An execution context may not be
     * started until the RT-Components that participate in it have
     * been initialized.  An execution context may be started and
     * stopped multiple times.
     *
     * @return The return code of ReturnCode_t type
     *
     * @endif
     */
    RTC::ReturnCode_t start(void);

    /*!
     * @if jp
     * @brief ExecutionContext �μ¹Ԥ����
     *
     * ExecutionContext �ξ��֤� Stopped �Ȥ��뤿��Υꥯ�����Ȥ�ȯ�Ԥ�
     * �롣���ܤ�ȯ���������ϡ�ComponentAction::on_shutdown ���Ƥӽ�
     * ����롣���ä��Ƥ���RT����ݡ��ͥ�Ȥ���λ��������
     * ExecutionContext ����ߤ���ɬ�פ����롣ExecutionContext ��ʣ����
     * ����/��ߤ򷫤��֤����Ȥ��Ǥ��롣
     *
     * @return ReturnCode_t ���Υ꥿���󥳡���
     *
     * @else
     *
     * @brief Stop the ExecutionContext
     *
     * Request that the context enter the Stopped state.  Once the
     * transition occurs, the ComponentAction::on_shutdown operation
     * will be invoked.  An execution context must be stopped before
     * the RT components that participate in it are finalized.  An
     * execution context may be started and stopped multiple times.
     *
     * @return The return code of ReturnCode_t type
     *
     * @endif
     */
    virtual RTC::ReturnCode_t stop(void);

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
     * @brief RT����ݡ��ͥ�Ȥ򥢥��ƥ��ֲ�����
     *
     * Inactive ���֤ˤ���RT����ݡ��ͥ�Ȥ�Active �����ܤ����������ƥ�
     * �ֲ����롣�������ƤФ줿��̡�on_activate ���ƤӽФ���롣��
     * �ꤷ��RT����ݡ��ͥ�Ȥ����üԥꥹ�Ȥ˴ޤޤ�ʤ����ϡ�
     * BAD_PARAMETER ���֤���롣���ꤷ��RT����ݡ��ͥ�Ȥξ��֤�
     * Inactive �ʳ��ξ��ϡ�PRECONDITION_NOT_MET ���֤���롣
     *
     * @param comp �����ƥ��ֲ��о�RT����ݡ��ͥ��
     *
     * @return ReturnCode_t ���Υ꥿���󥳡���
     *
     * @else
     *
     * @brief Activate an RT-component
     *
     * The given participant RTC is Inactive and is therefore not
     * being invoked according to the execution context��s execution
     * kind. This operation shall cause the RTC to transition to the
     * Active state such that it may subsequently be invoked in this
     * execution context.  The callback on_activate shall be called as
     * a result of calling this operation. This operation shall not
     * return until the callback has returned, and shall result in an
     * error if the callback does.
     *
     * @param comp The target RT-Component for activation
     *
     * @return The return code of ReturnCode_t type
     *
     * @endif
     */
    RTC::ReturnCode_t activateComponent(RTC::LightweightRTObject_ptr comp);

    /*!
     * @if jp
     * @brief RT����ݡ��ͥ�Ȥ��󥢥��ƥ��ֲ�����
     *
     * Inactive ���֤ˤ���RT����ݡ��ͥ�Ȥ��󥢥��ƥ��ֲ�����Inactive
     * �����ܤ����롣�������ƤФ줿��̡�on_deactivate ���ƤӽФ���
     * �롣���ꤷ��RT����ݡ��ͥ�Ȥ����üԥꥹ�Ȥ˴ޤޤ�ʤ����ϡ�
     * BAD_PARAMETER ���֤���롣���ꤷ��RT����ݡ��ͥ�Ȥξ��֤�
     * Active �ʳ��ξ��ϡ�PRECONDITION_NOT_MET ���֤���롣
     *
     *
     *


     * |


     
     * @param comp �󥢥��ƥ��ֲ��о�RT����ݡ��ͥ��
     *
     * @return ReturnCode_t ���Υ꥿���󥳡���
     *
     * @else
     *
     * @brief Deactivate an RT-component
     *
     * The given RTC is Active in the execution context. Cause it to
     * transition to the Inactive state such that it will not be
     * subsequently invoked from the context unless and until it is
     * activated again.  The callback on_deactivate shall be called as
     * a result of calling this operation. This operation shall not
     * return until the callback has returned, and shall result in an
     * error if the callback does.
     *
     * @param comp The target RT-Component for deactivate
     *
     * @return The return code of ReturnCode_t type
     *
     * @endif
     */
    RTC::ReturnCode_t deactivateComponent(RTC::LightweightRTObject_ptr comp);

    /*!
     * @if jp
     * @brief RT����ݡ��ͥ�Ȥ�ꥻ�åȤ���
     *
     * Error ���֤�RT����ݡ��ͥ�Ȥ��������ߤ롣�������ƤФ줿��
     * �̡�on_reset ���ƤӽФ���롣���ꤷ��RT����ݡ��ͥ�Ȥ����üԥ�
     * ���Ȥ˴ޤޤ�ʤ����ϡ�BAD_PARAMETER ���֤���롣���ꤷ��RT����
     * �ݡ��ͥ�Ȥξ��֤� Error �ʳ��ξ��ϡ�PRECONDITION_NOT_MET ����
     * ����롣
     *
     * @param comp �ꥻ�å��о�RT����ݡ��ͥ��
     *
     * @return ReturnCode_t ���Υ꥿���󥳡���
     *
     * @else
     *
     * @brief Reset the RT-component
     *
     * Attempt to recover the RTC when it is in Error.  The
     * ComponentAction::on_reset callback shall be invoked. This
     * operation shall not return until the callback has returned, and
     * shall result in an error if the callback does. If possible, the
     * RTC developer should implement that callback such that the RTC
     * may be returned to a valid state.
     *
     * @param comp The target RT-Component for reset
     *
     * @return The return code of ReturnCode_t type
     *
     * @endif
     */
    RTC::ReturnCode_t resetComponent(RTC::LightweightRTObject_ptr comp);

    /*!
     * @if jp
     * @brief RT����ݡ��ͥ�Ȥξ��֤��������
     *
     * ���ꤷ��RT����ݡ��ͥ�Ȥξ���(LifeCycleState)��������롣���ꤷ
     * ��RT����ݡ��ͥ�Ȥ����üԥꥹ�Ȥ˴ޤޤ�ʤ����ϡ�
     * UNKNOWN_STATE ���֤���롣
     *
     * @param comp ���ּ����о�RT����ݡ��ͥ��
     *
     * @return ���ߤξ���(LifeCycleState)
     *
     * @else
     *
     * @brief Get RT-component's state
     *
     * This operation shall report the LifeCycleState of the given
     * participant RTC.  UNKNOWN_STATE will be returned, if the given
     * RT-Component is not inclued in the participant list.
     *
     * @param comp The target RT-Component to get the state
     *
     * @return The current state of the target RT-Component(LifeCycleState)
     *
     * @endif
     */
    RTC::LifeCycleState getComponentState(RTC::LightweightRTObject_ptr comp);
    const char* getStateString(RTC::LifeCycleState state);
    
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

    //============================================================
    // Delegated functions to ExecutionContextProfile
    //============================================================
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
     * @brief RT����ݡ��ͥ�Ȥλ��üԥꥹ�Ȥ��������
     *
     * ������Ͽ����Ƥ��뻲�ü�RTC�Υꥹ�Ȥ�������롣
     *
     * @return ���ü�RTC�Υꥹ��
     *
     * @else
     *
     * @brief Getting participant RTC list
     *
     * This function returns a list of participant RTC of the execution context.
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
    // end of delegated functions to ExecutionContextProfile
    //============================================================

    //============================================================
    // Delegated functions to ExecutionContextWorker
    //============================================================
    bool isAllCurrentState(RTC::LifeCycleState state)
    {
      return m_worker.isAllCurrentState(state);
    };
    bool isAllNextState(RTC::LifeCycleState state)
    {
      return m_worker.isAllNextState(state);
    };
    bool isOneOfCurrentState(RTC::LifeCycleState state)
    {
      return m_worker.isOneOfCurrentState(state);
    };
    bool isOneOfNextState(RTC::LifeCycleState state)
    {
      return m_worker.isOneOfNextState(state);
    };
    
    void invokeWorker()       { m_worker.invokeWorker(); }
    void invokeWorkerPreDo()  { m_worker.invokeWorkerPreDo(); }
    void invokeWorkerDo()     { m_worker.invokeWorkerDo(); }
    void invokeWorkerPostDo() { m_worker.invokeWorkerPostDo(); }


  protected:
    // template virtual functions related to start/stop
    virtual bool onIsRunning(bool running) { return running; }
    virtual RTC::ReturnCode_t onStarting() { return RTC::RTC_OK; }
    virtual RTC::ReturnCode_t onStarted() { return RTC::RTC_OK; }
    virtual RTC::ReturnCode_t onStopping() { return RTC::RTC_OK; }
    virtual RTC::ReturnCode_t onStopped() { return RTC::RTC_OK; }

    // template virtual functions getting/setting execution rate
    virtual double onGetRate(double rate) const { return rate; }
    virtual double onSettingRate(double rate) { return rate; }
    virtual RTC::ReturnCode_t onSetRate(double rate) { return RTC::RTC_OK; }

    // template virtual functions adding/removing component
    virtual RTC::ReturnCode_t
    onAddingComponent(RTC::LightweightRTObject_ptr rtobj)
    {
      return RTC::RTC_OK;
    }
    virtual RTC::ReturnCode_t
    onAddedComponent(RTC::LightweightRTObject_ptr rtobj)
    {
      return RTC::RTC_OK;
    }
    virtual RTC::ReturnCode_t
    onRemovingComponent(RTC::LightweightRTObject_ptr rtobj)
    {
      return RTC::RTC_OK;
    }
    virtual RTC::ReturnCode_t
    onRemovedComponent(RTC::LightweightRTObject_ptr rtobj)
    {
      return RTC::RTC_OK;
    }

    // template virtual functions related to activation/deactivation/reset
    virtual RTC::ReturnCode_t
    onActivating(RTC::LightweightRTObject_ptr comp)
    {
      return RTC::RTC_OK;
    }
    virtual RTC::ReturnCode_t
    onWaitingActivated(RTC_impl::RTObjectStateMachine* comp, long int count)
    {
      return RTC::RTC_OK;
    }
    virtual RTC::ReturnCode_t
    onActivated(RTC_impl::RTObjectStateMachine* comp,
                                     long int count)
    {
      return RTC::RTC_OK;
    }
    virtual RTC::ReturnCode_t
    onDeactivating(RTC::LightweightRTObject_ptr comp)
    {
      return RTC::RTC_OK;
    }
    virtual RTC::ReturnCode_t
    onWaitingDeactivated(RTC_impl::RTObjectStateMachine* comp, long int count)
    {
      return RTC::RTC_OK;
    }
    virtual RTC::ReturnCode_t
    onDeactivated(RTC_impl::RTObjectStateMachine* comp, long int count)
    {
      return RTC::RTC_OK;
    }
    virtual RTC::ReturnCode_t onResetting(RTC::LightweightRTObject_ptr comp)
    {
      return RTC::RTC_OK;
    }
    virtual RTC::ReturnCode_t
    onWaitingReset(RTC_impl::RTObjectStateMachine* comp, long int count)
    {
      return RTC::RTC_OK;
    }
    virtual RTC::ReturnCode_t
    onReset(RTC_impl::RTObjectStateMachine* comp, long int count)
    {
      return RTC::RTC_OK;
    }

    virtual RTC::LifeCycleState
    onGetComponentState(RTC::LifeCycleState state)
    {
      return state;
    }
    virtual RTC::ExecutionKind
    onGetKind(RTC::ExecutionKind kind) const
    {
      return kind;
    }
    virtual RTC::ExecutionContextProfile*
    onGetProfile(RTC::ExecutionContextProfile*& profile)
    {
      return profile;
    }

  private:
    /*!
     * @if jp
     * @brief Properties����¹ԥ���ƥ����Ȥ򥻥åȤ���
     * @else
     * @brief Setting execution rate from given properties.
     * @endif
     */
    bool setExecutionRate(coil::Properties& props);
    /*!
     * @if jp
     * @brief Properties����������ܥ⡼�ɤ򥻥åȤ���
     * @else
     * @brief Setting state transition mode from given properties.
     * @endif
     */
    bool setTransitionMode(coil::Properties& props,
                           const char* key, bool& flag);
    /*!
     * @if jp
     * @brief Properties�����������Timeout�򥻥åȤ���
     * @else
     * @brief Setting state transition timeout from given properties.
     * @endif
     */
    bool setTimeout(coil::Properties& props, const char* key,
                    coil::TimeValue& timevalue);

    RTC::ReturnCode_t waitForActivated(RTC_impl::RTObjectStateMachine* rtobj);
    RTC::ReturnCode_t waitForDeactivated(RTC_impl::RTObjectStateMachine* rtobj);
    RTC::ReturnCode_t waitForReset(RTC_impl::RTObjectStateMachine* rtobj);
    
  protected:
    mutable RTC::Logger rtclog;

    RTC_impl::ExecutionContextWorker m_worker;
    RTC_impl::ExecutionContextProfile m_profile;

    coil::TimeValue m_activationTimeout;
    coil::TimeValue m_deactivationTimeout;
    coil::TimeValue m_resetTimeout;

    bool m_syncActivation;
    bool m_syncDeactivation;
    bool m_syncReset;
  };  // class ExecutionContextBase

  typedef coil::GlobalFactory<ExecutionContextBase> ExecutionContextFactory;

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
  EXTERN template class DLL_PLUGIN coil::GlobalFactory<ExecutionContextBase>;
#endif
};  // namespace RTC

#ifdef WIN32
#pragma warning( default : 4290 )
#endif

#endif // RTC_EXECUTIONCONTEXTBASE_H

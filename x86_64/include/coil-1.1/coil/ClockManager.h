// -*- C++ -*-
/*!
 * @file ClockManager.h
 * @brief Global clock management class
 * @date $Date$
 * @author Noriaki Ando <n-ando@aist.go.jp>
 *
 * Copyright (C) 2012
 *     Noriaki Ando
 *     Intelligent Systems Research Institute,
 *     National Institute of
 *         Advanced Industrial Science and Technology (AIST), Japan
 *     All rights reserved.
 *
 * $Id$
 *
 */

#ifndef COIL_CLOCKMANAGER_H
#define COIL_CLOCKMANAGER_H

#include <string>
#include <coil/Singleton.h>
#include <coil/TimeValue.h>
#include <coil/Mutex.h>

namespace coil
{
  /*!
   * @if jp
   * @class �������ꡦ�������֥������ȤΥ��󥿡��ե�����
   *
   * ���Υ��饹�� ClockManager �ˤ�äƴ�������륯��å����֥������Ȥ�
   * ����Υ��󥿡��ե������Ǥ��롣ClockManager ��ʣ���Υ���å����֥���
   * ���Ȥ��������ɬ�פ˱�����Ŭ�ڤʥ���å����֥������Ȥ� IClock ����
   * �����ե��������ĥ��֥������ȤȤ����֤�������å����֥������Ȥ�ñ
   * �˥����ƥ������֤���Τ䡢�ȼ��������������ĥ���å����֥�����
   * �������ͤ����롣
   *
   * @else
   * @brief An interface to set and get time
   *
   * This class is a interface for clock objects managed by
   * ClockManager. ClockManager manages one or more clocks, and it
   * returns appropriate clock objects according to demands. The clock
   * object might be clock which just returns system time, or a clock
   * which returns individual logical time.
   *
   * @endif
   */
  class IClock
  {
  public:
    virtual ~IClock() {}
    /*!
     * @if jp
     * @brief ������������
     * @return ���ߤλ���
     * @else
     * @brief Getting time
     * @return Current time
     * @endif
     */
    virtual coil::TimeValue gettime() const = 0;
    /*!
     * @if jp
     * @brief ��������ꤹ��
     * @param clocktime ���ߤλ���
     * @else
     * @brief Setting time
     * @param clocktime Current time
     * @endif
     */
    virtual bool settime(coil::TimeValue clocktime) = 0;
  };

  /*!
   * @if jp
   * @class �����ƥ����򰷤�����å����֥�������
   *
   * ���Υ��饹�ϥ����ƥ९��å�������ޤ��ϼ������륯�饹�Ǥ��롣
   *
   * @else
   * @brief clock object to handle system clock
   *
   * This class sets and gets system clock.
   *
   * @endif
   */
  class SystemClock
    : public IClock
  {
  public:
    virtual ~SystemClock();
    virtual coil::TimeValue gettime() const;
    virtual bool settime(coil::TimeValue clocktime);
  };

  /*!
   * @if jp
   * @class �������֤򰷤�����å����֥�������
   *
   * ���Υ��饹���������֤�����ޤ��ϼ������륯�饹�Ǥ��롣
   * ñ��� settime() �ˤ�ä����ꤵ�줿����� gettime() �ˤ�äƼ������뤹��
   *
   * @else
   * @brief Clock object to handle logical clock
   *
   * This class sets and gets system clock.
   * It just sets time by settime() and gets time by gettime().
   *
   * @endif
   */
  class LogicalClock
    : public IClock
  {
  public:
    LogicalClock();
    virtual ~LogicalClock();
    virtual coil::TimeValue gettime() const;
    virtual bool settime(coil::TimeValue clocktime);
  private:
    coil::TimeValue m_currentTime;
    mutable coil::Mutex m_currentTimeMutex;
  };

  /*!
   * @if jp
   * @class Ĵ���Ѥ߻���򰷤�����å����֥�������
   *
   * settime() �ƤӽФ����˸��߻���Ȥκ��򥪥ե��åȤȤ����ݻ�����
   * gettime() �ˤ�äƥ��ե��å�Ĵ���Ѥߤλ�����֤���
   *
   * @else
   * @brief Clock object to handle adjusted clock
   *
   * This class stores a offset time with current system clock when
   * settime(), and gettime() returns adjusted clock by the offset.
   *
   * @endif
   */
  class AdjustedClock
    : public IClock
  {
  public:
    AdjustedClock();
    virtual ~AdjustedClock();
    virtual coil::TimeValue gettime() const;
    virtual bool settime(coil::TimeValue clocktime);
  private:
    coil::TimeValue m_offset;
    mutable coil::Mutex m_offsetMutex;
  };

  /*!
   * @if jp
   * @class �����Х�ʥ���å��������饹��
   *
   * ���Υ��饹�ϥ����Х�˥���å����֥������Ȥ��󶡤��륷�󥰥�ȥ�
   * ���饹�Ǥ��롣getClocK(����å�̾) �ˤ�� IClock ���Υ���å�����
   * �������Ȥ��֤������Ѳ�ǽ�ʥ���å��� "system", "logical" �����
   * "adjusted" �Σ�����Ǥ��롣
   *
   * @else
   * @brief A global clock management class
   *
   * This class is a singleton class that provides clock objects
   * globally. It provides a IClock object by getClock(<clock
   * type>). As clock types, "system", "logical" and "adjusted" are
   * available.
   *
   * @endif
   */
  class ClockManager
    : public coil::Singleton<ClockManager>
  {
  public:
    IClock& getClock(std::string clocktype);
  private:
    SystemClock   m_systemClock;
    LogicalClock  m_logicalClock;
    AdjustedClock m_adjustedClock;
  };
}; // namespace coil
#endif // COIL_CLOCKMANAGER_H

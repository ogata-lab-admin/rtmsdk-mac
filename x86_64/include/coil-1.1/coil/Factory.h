// -*- C++ -*-
/*!
 * @file Factory.h
 * @brief generic Factory template class
 * @date $Date$
 * @author Noriaki Ando <n-ando@aist.go.jp>
 *
 * Copyright (C) 2009, 2012
 *     Noriaki Ando
 *     Task-intelligence Research Group,
 *     Intelligent Systems Research Institute,
 *     National Institute of
 *         Advanced Industrial Science and Technology (AIST), Japan
 *     All rights reserved.
 *
 * $Id$
 *
 */

#ifndef COIL_FACTORY_H
#define COIL_FACTORY_H

#include <assert.h>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <coil/Singleton.h>

// for Windows DLL export
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#   ifdef LIBRARY_EXPORTS
#      define EXTERN
#      define DLL_PLUGIN __declspec(dllexport)
#   else
#      define EXTERN extern
#      define DLL_PLUGIN __declspec(dllimport)
#   endif
#else 
#   define DLL_PLUGIN
#   define EXTERN
#endif /* Windows */


namespace coil
{
  /*!
   * @if jp
   *
   * @brief Creator �ƥ�ץ졼��
   *
   * @else
   *
   * @brief Creator template
   *
   * @endif
   */
  template <class AbstractClass, class ConcreteClass>
  AbstractClass* Creator()
  {
    return new ConcreteClass();
  }

  /*!
   * @if jp
   *
   * @brief Destructor �ƥ�ץ졼��
   *
   * @else
   *
   * @brief Destructor template
   *
   * @endif
   */
  template <class AbstractClass, class ConcreteClass>
  void Destructor(AbstractClass*& obj)
  {
    if (obj == 0) { return; }
    ConcreteClass* tmp = dynamic_cast<ConcreteClass*>(obj);
    if (tmp == 0) { return; }
    delete obj;
    obj = 0;
  }

  /*!
   * @if jp
   *
   * @class Factory
   * @brief Factory �ƥ�ץ졼�ȥ��饹
   *
   * @else
   *
   * @class Factory
   * @brief Factory template class
   *
   * @endif
   */
  template <
    class AbstractClass,
    typename Identifier = std::string,
    typename Compare = std::less<Identifier>,
    typename Creator = AbstractClass* (*)(),
    typename Destructor = void (*)(AbstractClass*&)
    >
  class Factory
  {
    class FactoryEntry;
  public:

    typedef std::map<Identifier, FactoryEntry> FactoryMap;
    typedef typename FactoryMap::iterator      FactoryMapIt;
    typedef std::map<AbstractClass*, FactoryEntry> ObjectMap;
    typedef typename ObjectMap::iterator           ObjectMapIt;
    
    enum ReturnCode
      {
        FACTORY_OK,
        FACTORY_ERROR,
        ALREADY_EXISTS,
        NOT_FOUND,
        INVALID_ARG,
        UNKNOWN_ERROR
      };

    /*!
     * @if jp
     *
     * @brief �ե����ȥ꡼̵ͭ�����å�
     *
     * ����ID�Υե����ȥ꡼̵ͭ���֤���
     *
     * @param id �ե����ȥ꡼ID
     *
     * @return true: ͭ��, false: ̵��
     *
     * @else
     *
     * @brief Factory presence check
     *
     * Return a factory having ID or not.
     *
     * @param id Factory ID.
     *
     * @return true: found, false: not found
     *
     * @endif
     */
    bool hasFactory(const Identifier& id)
    {
      if (m_creators.count(id) == 0) { return false; }
      return true;
    }

    /*!
     * @if jp
     *
     * @brief �ե����ȥ꡼ID�ꥹ�ȼ���
     *
     * �ե����ȥ꡼ID�ꥹ�Ȥ��֤���
     *
     * @return ID �ꥹ��
     *
     * @else
     *
     * @brief Get factory ID list
     *
     * Return a list of factory ID.
     *
     * @return ID list
     *
     * @endif
     */
    std::vector<Identifier> getIdentifiers()
    {
      std::vector<Identifier> idlist;
      idlist.reserve(m_creators.size());

      FactoryMapIt it(m_creators.begin());
      FactoryMapIt it_end(m_creators.end());

      while (it != it_end)
        {
          idlist.push_back(it->first);
          ++it;
        }
      return idlist;
    }

    /*!
     * @if jp
     *
     * @brief �ե����ȥ꡼��Ͽ
     *
     * �ե����ȥ꡼����Ͽ���롣
     *
     * @param id �ե����ȥ꡼ID
     * @param creator ���ꥨ�����ѥե��󥯥�
     * @param destructor �ǥ��ȥ饯���ѥե��󥯥�
     *
     * @return FACTORY_OK: ���ｪλ
     *         ALREADY_EXISTS: ��Ͽ�Ѥ�
     *         INVALID_ARG: creator �� destructor ���������ͤ�ޤ�
     *
     * @else
     *
     * @brief Add factory
     *
     * Add a factory.
     *
     * @param id Factory ID.
     * @param creator Functor for creator.
     * @param destructor Functor for destructor.
     *
     * @return FACTORY_OK: Successful
     *         ALREADY_EXISTS: already exists.
     *         INVALID_ARG: creator or destructor with invalid values.
     *
     * @endif
     */
    ReturnCode addFactory(const Identifier& id,
                          Creator creator,
                          Destructor destructor)
    {
      if (creator == 0 || destructor == 0) { return INVALID_ARG; }
      if (m_creators.count(id) != 0) { return ALREADY_EXISTS; }
      FactoryEntry f(id, creator, destructor);
      m_creators[id] = f;
      return FACTORY_OK;
    }

    /*!
     * @if jp
     *
     * @brief �ե����ȥ꡼���
     *
     * �ե����ȥ꡼�������롣
     *
     * @param id �ե����ȥ꡼ID
     *
     * @return FACTORY_OK: ���ｪλ
     *         NOT_FOUND: ID̤��Ͽ
     *
     * @else
     *
     * @brief Remove factory
     *
     * Remove a factory.
     *
     * @param id Factory ID.
     *
     * @return FACTORY_OK: Successful
     *         NOT_FOUND: ID not found
     *
     * @endif
     */
    ReturnCode removeFactory(const Identifier& id)
    {
      if (m_creators.count(id) == 0) { return NOT_FOUND; }
      m_creators.erase(id);
      return FACTORY_OK;
    }

    /*!
     * @if jp
     *
     * @brief �ե����ȥ꡼���֥�����������
     *
     * �ե����ȥ꡼���֥������Ȥ��������롣
     *
     * @param id �ե����ȥ꡼ID
     *
     * @return AbstractClass �Υݥ���
     *
     * @else
     *
     * @brief Create factory object
     *
     * Create a factory object.
     *
     * @param id Factory ID.
     *
     * @return Pointer of AbstractClass
     *
     * @endif
     */
    AbstractClass* createObject(const Identifier& id)
    {
      if (m_creators.count(id) == 0) { return 0; }
      AbstractClass* obj = m_creators[id].creator_();
      assert(m_objects.count(obj) == 0);
      m_objects[obj] = m_creators[id];
      return obj;
    }

    /*!
     * @if jp
     *
     * @brief �ե����ȥ꡼���֥������Ⱥ��
     *
     * �ե����ȥ꡼���֥������Ȥ������롣
     *
     * @param id �ե����ȥ꡼ID
     * @param obj �ե����ȥ꡼���֥�������
     *
     * @else
     *
     * @brief Delete factory object
     *
     * Delete a factory object.
     *
     * @param id Factory ID.
     * @param obj Factory object.
     *
     * @endif
     */
    ReturnCode deleteObject(const Identifier& id, AbstractClass*& obj)
    {
      if (m_creators.count(id) == 0)
        {
          return deleteObject(obj);
        }
      m_creators[id].destructor_(obj);
      m_objects.erase(obj);
      return FACTORY_OK;
    }

    /*!
     * @if jp
     *
     * @brief �ե����ȥ꡼���֥������Ⱥ��
     *
     * �ե����ȥ꡼���֥������Ȥ������롣
     *
     * @param obj �ե����ȥ꡼���֥�������
     *
     * @else
     *
     * @brief Delete factory object
     *
     * Delete a factory object.
     *
     * @param obj Factory object.
     *
     * @endif
     */
    ReturnCode deleteObject(AbstractClass*& obj)
    {
      if (m_objects.count(obj) == 0) { return NOT_FOUND; }
      AbstractClass* tmp(obj);
      m_objects[obj].destructor_(obj);
      m_objects.erase(tmp);
      return FACTORY_OK;
    }

    /*!
     * @if jp
     *
     * @brief �����Ѥߥ��֥������ȥꥹ�Ȥμ���
     *
     * ���Υե����ȥ���������줿���֥������ȤΥꥹ�Ȥ�������롣
     *
     * @return �����Ѥߥ��֥������ȥꥹ��
     *
     * @else
     *
     * @brief Getting created objects
     *
     * This operation returns a list of created objects by the factory.
     *
     * @return created object list
     *
     * @endif
     */
    std::vector<AbstractClass*> createdObjects()
    {
      std::vector<AbstractClass*> objects;
      for (ObjectMapIt it(m_objects.begin()); it != m_objects.end(); ++it)
        {
          objects.push_back(it->first);
        }
      return objects;
    }

    /*!
     * @if jp
     *
     * @brief ���֥������Ȥ����Υե����ȥ������ʪ���ɤ���Ĵ�٤�
     *
     * @param obj �оݥ��֥�������
     * @return true: ���Υե����ȥ������ʪ
     *         false: ���Υե����ȥ������ʪ�ǤϤʤ�
     *
     * @else
     *
     * @brief Whether a object is a product of this factory
     *
     * @param obj A target object
     * @return true: The object is a product of the factory
     *         false: The object is not a product of the factory
     *
     * @return created object list
     *
     * @endif
     */
    bool isProducerOf(AbstractClass* obj)
    {
      return m_objects.count(obj) != 0;
    }

    /*!
     * @if jp
     *
     * @brief ���֥������Ȥ��饯�饹���̻�(ID)���������
     *
     * �������֥������ȤΥ��饹���̻�(ID)��������롣
     *
     * @param obj [in] ���饹���̻�(ID)��������������֥�������
     * @param id [out] ���饹���̻�(ID)
     * @return �꥿���󥳡��� NOT_FOUND: ���̻Ҥ�¸�ߤ��ʤ�
     *                        FACTORY_OK: ���ｪλ
     * @else
     *
     * @brief Getting class identifier (ID) from a object
     *
     * This operation returns a class identifier (ID) from a object.
     *
     * @param obj [in] An object to investigate its class ID.
     * @param id [out] Class identifier (ID)
     * @return Return code NOT_FOUND: ID not found
     *                        FACTORY_OK: normal return
     * @endif
     */
    ReturnCode objectToIdentifier(AbstractClass* obj, Identifier& id)
    {
      if (m_objects.count(obj) == 0) { return NOT_FOUND; }
      id = m_objects[obj].id_;
      return FACTORY_OK;
    }

    /*!
     * @if jp
     *
     * @brief ���֥������ȤΥ��󥹥ȥ饯�����������
     *
     * ���Υե����ȥ���������줿���֥������ȤΥ��󥹥ȥ饯����������롣
     * obj �Ϥ��Υե����ȥ���������줿��ΤǤʤ���Фʤ�ʤ���ͽ��
     * isProducerOf() �ؿ����������֥������Ȥ����Υե����ȥ������ʪ��
     * ���뤫�ɤ���������å����ʤ���Фʤ�ʤ���
     *
     * @return ���֥������ȤΥǥ��ȥ饯��
     *
     * @else
     *
     * @brief Getting destructor of the object
     *
     * This operation returns a constructor of the object created by
     * the factory.  obj must be a product of the factory.  User must
     * check if the object is a product of the factory by using
     * isProducerOf()-function, before using this function.
     *
     * @return destructor of the object
     *
     * @endif
     */
    Creator objectToCreator(AbstractClass* obj)
    {
      return m_objects[obj].creator_;
    }

    /*!
     * @if jp
     *
     * @brief ���֥������ȤΥǥ��ȥ饯�����������
     *
     * ���Υե����ȥ���������줿���֥������ȤΥǥ��ȥ饯����������롣
     * obj �Ϥ��Υե����ȥ���������줿��ΤǤʤ���Фʤ�ʤ���ͽ��
     * isProducerOf() �ؿ����������֥������Ȥ����Υե����ȥ������ʪ��
     * ���뤫�ɤ���������å����ʤ���Фʤ�ʤ���
     *
     * @return ���֥������ȤΥǥ��ȥ饯��
     *
     * @else
     *
     * @brief Getting destructor of the object
     *
     * This operation returns a destructor of the object created by
     * the factory.  obj must be a product of the factory.  User must
     * check if the object is a product of the factory by using
     * isProducerOf()-function, before using this function.
     *
     * @return destructor of the object
     *
     * @endif
     */
    Destructor objectToDestructor(AbstractClass* obj)
    {
      return m_objects[obj].destructor_;
    }

  private:

    /*!
     * @if jp
     *
     * @class FactoryEntry
     * @brief FactoryEntry ���饹
     *
     * @else
     *
     * @class FactoryEntry
     * @brief FactoryEntry class
     *
     * @endif
     */
    class FactoryEntry
    {
    public:
      explicit FactoryEntry()
      {
      }

      /*!
       * @if jp
       *
       * @brief ���󥹥ȥ饯��
       *
       * ���󥹥ȥ饯����
       *
       * @param creator ���ꥨ�����ѥե��󥯥�
       * @param destructor �ǥ��ȥ饯���ѥե��󥯥�
       *
       * @else
       *
       * @brief Constructor
       *
       * Constructor
       *
       * @param creator Functor for creator.
       * @param destructor Functor for destructor.
       *
       * @endif
       */
      FactoryEntry(Identifier id, Creator creator, Destructor destructor)
        : id_(id), creator_(creator), destructor_(destructor)
      {
      }
      std::string id_;
      Creator creator_;
      Destructor destructor_;
    };
    FactoryMap m_creators;
    ObjectMap  m_objects;
  };



  /*!
   * @if jp
   *
   * @class GlobalFactory
   * @brief GlobalFactory �ƥ�ץ졼�ȥ��饹
   *
   * @else
   *
   * @class GlobalFactory
   * @brief GlobalFactory template class
   *
   * @endif
   */
  template <
    class AbstractClass,
    typename Identifier = std::string,
    typename Compare = std::less<Identifier>,
    typename Creator = AbstractClass* (*)(),
    typename Destructor = void (*)(AbstractClass*&)
    >
  class GlobalFactory
    : public Factory<AbstractClass, Identifier, Compare, Creator, Destructor>,
      public coil::Singleton<GlobalFactory<AbstractClass,
                                           Identifier,
                                           Compare,
                                           Creator,
                                           Destructor> >
  {
  public:

  private:
    /*!
     * @if jp
     *
     * @brief ���󥹥ȥ饯��
     *
     * ���󥹥ȥ饯����
     *
     * @else
     *
     * @brief Constructor
     *
     * Constructor
     *
     * @endif
     */
    GlobalFactory(){}

    /*!
     * @if jp
     *
     * @brief �ǥ��ȥ饯��
     *
     * �ǥ��ȥ饯����
     *
     * @else
     *
     * @brief Destructor
     *
     * Destructor
     *
     * @endif
     */
    ~GlobalFactory(){}

    friend class Singleton<GlobalFactory>;
  };

}; // namespace coil
#endif // COIL_FACTORY_H
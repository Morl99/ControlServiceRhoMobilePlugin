#pragma once

#include "IControlService.h"
#include "logging/RhoLog.h"
#include "common/StringConverter.h"
#include "common/ExtManager.h"


namespace rho {

using namespace rho::apiGenerator;

// hash keys used in properties and parameters 

class CControlServiceFactoryBase : public CModuleFactoryBase<IControlService, IControlServiceSingleton, IControlServiceFactory>
{
protected:
    static rho::common::CAutoPtr<CControlServiceFactoryBase> m_pInstance;
    HashtablePtr<rho::String,IControlService*> m_hashModules;

public:

    static void setInstance(CControlServiceFactoryBase* pInstance){ m_pInstance = pInstance; }
    static CControlServiceFactoryBase* getInstance(){ return m_pInstance; }

    static IControlServiceSingleton* getControlServiceSingletonS(){ return getInstance()->getModuleSingleton(); }

    virtual IControlService* getModuleByID(const rho::String& strID)
    {
        if ( !m_hashModules.containsKey(strID) )
        {
            IControlService* pObj = createModuleByID(strID);
            m_hashModules.put(strID, pObj );

            return pObj;
        }

        return m_hashModules[strID];
    }

    virtual IControlService* createModuleByID(const rho::String& strID){ return (IControlService*)0; };
    virtual void deleteModuleByID(const rho::String& strID)
    {
        m_hashModules.remove(strID);
    }

};

class CControlServiceSingletonBase : public CModuleSingletonBase< IControlServiceSingleton >, public rho::common::IRhoExtension
{
protected:
    DEFINE_LOGCLASS;


    rho::String m_strDefaultID;




public:
    virtual rho::LogCategory getModuleLogCategory(){ return getLogCategory(); }

    CControlServiceSingletonBase();
    ~CControlServiceSingletonBase();




    virtual void setDefaultID(const rho::String& strDefaultID){ m_strDefaultID = strDefaultID; }
    virtual rho::String getDefaultID()
    { 
        if ( m_strDefaultID.length() == 0 )
            setDefaultID(getInitialDefaultID());
        return m_strDefaultID; 
    }

};

class CControlServiceBase: public IControlService
{
protected:
    DEFINE_LOGCLASS;


public:


    CControlServiceBase();



    static CControlServiceBase* getInstance(){ return static_cast< CControlServiceBase* >(CControlServiceFactoryBase::getInstance()->getModuleByID(CControlServiceFactoryBase::getControlServiceSingletonS()->getDefaultID())); }
 

};

extern "C" void Init_ControlService_API();


}

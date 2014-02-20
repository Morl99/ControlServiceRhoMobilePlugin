#pragma once

#include "../../../../shared/generated/cpp/ControlServiceBase.h"
#include "ControlServiceRuntime.h"


namespace rho {
class CControlServiceFactory: public CControlServiceFactoryBase
{
private:
    static rhoruntime::IControlServiceFactoryImpl^ _impl;
public:
    static void setImpl(rhoruntime::IControlServiceFactoryImpl^ impl) { _impl = impl; }
    ~CControlServiceFactory(){}
    virtual IControlServiceSingleton* createModuleSingleton();
    virtual IControlService* createModuleByID(const rho::String& strID);
};

}

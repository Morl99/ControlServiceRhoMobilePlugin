#pragma once

#include "common/RhoStd.h"
#include "api_generator/MethodResult.h"
#include "api_generator/BaseClasses.h"


namespace rho {
///////////////////////////////////////////////////////////
struct IControlService
{
//constants


//methods
    virtual ~IControlService(){}

    virtual void startService( const rho::String& testDescription, rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void stopService(rho::apiGenerator::CMethodResult& oResult) = 0;

};

struct IControlServiceSingleton
{
//constants


    virtual ~IControlServiceSingleton(){}

//methods


    virtual rho::String getDefaultID() = 0;
    virtual rho::String getInitialDefaultID() = 0;
    virtual void setDefaultID(const rho::String& strID) = 0;

    virtual void addCommandToQueue(rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor) = 0;
    virtual void callCommandInThread(rho::common::IRhoRunnable* pFunctor) = 0;
};

struct IControlServiceFactory
{
    virtual ~IControlServiceFactory(){}

    virtual IControlServiceSingleton* getModuleSingleton() = 0;


    virtual IControlService* getModuleByID(const rho::String& strID) = 0;

};


}

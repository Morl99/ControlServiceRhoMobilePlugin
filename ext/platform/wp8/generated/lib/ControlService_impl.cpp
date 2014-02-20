#include "common/RhodesApp.h"
#include "../../wp8/rhoruntime/common/RhoConvertWP8.h"
//#include "../../../../shared/generated/cpp/ControlServiceBase.h"
#include "ControlServiceFactory.h"
#include "api_generator/wp8/MethodResultImpl.h"

using namespace rho::apiGenerator;
using namespace rhoruntime;

namespace rho {

class CControlServiceImpl: public CControlServiceBase
{
private:
    IControlServiceImpl^ _runtime;
public:
    CControlServiceImpl(const rho::String& strID, IControlServiceImpl^ runtime): CControlServiceBase(), _runtime(runtime) {}

    virtual void startService(const rho::String& testDescription, CMethodResult& oResult)
    {
        Platform::String^ _testDescription = rho::common::convertStringToWP8(testDescription);
        try {
            _runtime->startService(_testDescription, ref new CMethodResultImpl((int64)&oResult));
        } catch (Platform::Exception^ e) {
            LOG(ERROR) + rho::common::convertStringAFromWP8(e->ToString());
        }
    }

    virtual void stopService(CMethodResult& oResult)
    {
        try {
            _runtime->stopService(ref new CMethodResultImpl((int64)&oResult));
        } catch (Platform::Exception^ e) {
            LOG(ERROR) + rho::common::convertStringAFromWP8(e->ToString());
        }
    }
};

class CControlServiceSingleton: public CControlServiceSingletonBase
{
private:
    IControlServiceSingletonImpl^ _runtime;
public:
    CControlServiceSingleton(IControlServiceSingletonImpl^ runtime): CControlServiceSingletonBase(), _runtime(runtime) {}
    ~CControlServiceSingleton(){}


    virtual rho::String getDefaultID(){return "1";} // TODO: implement getDefaultID
    virtual rho::String getInitialDefaultID(){return "1";} // TODO: implement getInitialDefaultID
    virtual void setDefaultID(const rho::String& strID){} // TODO: implement setDefaultID
    virtual void addCommandToQueue(rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor){} // TODO: implement addCommandToQueue
    virtual void callCommandInThread(rho::common::IRhoRunnable* pFunctor){} // TODO: implement callCommandInThread
};

IControlServiceFactoryImpl^ CControlServiceFactory::_impl;

IControlService* CControlServiceFactory::createModuleByID(const rho::String& strID)
{
    return new CControlServiceImpl(strID, _impl->getImpl());
}

IControlServiceSingleton* CControlServiceFactory::createModuleSingleton()
{
    return new CControlServiceSingleton(_impl->getSingletonImpl());
}

}

extern "C" void Init_ControlService_extension()
{
    rho::CControlServiceFactory::setInstance( new rho::CControlServiceFactory() );
    rho::Init_ControlService_API();

    RHODESAPP().getExtManager().requireRubyFile("RhoControlServiceApi");
}

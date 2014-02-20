#include "../../../shared/generated/cpp/ControlServiceBase.h"

namespace rho {

using namespace apiGenerator;

class CControlServiceImpl: public CControlServiceBase
{
public:
    CControlServiceImpl(const rho::String& strID): CControlServiceBase()
    {
    }

    virtual void getPlatformName(rho::apiGenerator::CMethodResult& oResult) {
         oResult.set("WM");
    }

    virtual void calcSumm( int a,  int b, rho::apiGenerator::CMethodResult& oResult) {
         oResult.set(a+b);
    }
    
    virtual void joinStrings( const rho::String& a,  const rho::String& b, rho::apiGenerator::CMethodResult& oResult) {
         oResult.set(a+b);
    }

};

class CControlServiceSingleton: public CControlServiceSingletonBase
{
    ~CControlServiceSingleton(){}
    virtual rho::String getInitialDefaultID();
    virtual void enumerate(CMethodResult& oResult);
};

class CControlServiceFactory: public CControlServiceFactoryBase
{
    ~CControlServiceFactory(){}
    virtual IControlServiceSingleton* createModuleSingleton();
    virtual IControlService* createModuleByID(const rho::String& strID);
};

extern "C" void Init_ControlService_extension()
{
    CControlServiceFactory::setInstance( new CControlServiceFactory() );
    Init_ControlService_API();
}

IControlService* CControlServiceFactory::createModuleByID(const rho::String& strID)
{
    return new CControlServiceImpl(strID);
}

IControlServiceSingleton* CControlServiceFactory::createModuleSingleton()
{
    return new CControlServiceSingleton();
}

void CControlServiceSingleton::enumerate(CMethodResult& oResult)
{
    rho::Vector<rho::String> arIDs;
    arIDs.addElement("SC1");
    arIDs.addElement("SC2");

    oResult.set(arIDs);
}

rho::String CControlServiceSingleton::getInitialDefaultID()
{
    CMethodResult oRes;
    enumerate(oRes);

    rho::Vector<rho::String>& arIDs = oRes.getStringArray();
        
    return arIDs[0];
}

}
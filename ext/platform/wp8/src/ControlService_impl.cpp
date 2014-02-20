#include "../../../shared/generated/cpp/controlServiceBase.h"

namespace rho {

using namespace apiGenerator;

class CcontrolServiceImpl: public CcontrolServiceBase
{
public:
    CcontrolServiceImpl(const rho::String& strID): CcontrolServiceBase()
    {
    }

    virtual void enable( const rho::Hashtable<rho::String, rho::String>& propertyMap, CMethodResult& oResult){}
    virtual void start(CMethodResult& oResult){}
    virtual void stop(CMethodResult& oResult){}
    virtual void disable(CMethodResult& oResult){}
    virtual void take( const rho::Hashtable<rho::String, rho::String>& propertyMap, CMethodResult& oResult){}

};

class CcontrolServiceSingleton: public CcontrolServiceSingletonBase
{
    ~CcontrolServiceSingleton(){}
    virtual rho::String getInitialDefaultID();
    virtual void enumerate(CMethodResult& oResult);
};

class CcontrolServiceFactory: public CcontrolServiceFactoryBase
{
    ~CcontrolServiceFactory(){}
    virtual IcontrolServiceSingleton* createModuleSingleton();
    virtual IcontrolService* createModuleByID(const rho::String& strID);
};

extern "C" void Init_controlService_extension()
{
    CcontrolServiceFactory::setInstance( new CcontrolServiceFactory() );
    Init_controlService_API();
}

IcontrolService* CcontrolServiceFactory::createModuleByID(const rho::String& strID)
{
    return new CcontrolServiceImpl(strID);
}

IcontrolServiceSingleton* CcontrolServiceFactory::createModuleSingleton()
{
    return new CcontrolServiceSingleton();
}

void CcontrolServiceSingleton::enumerate(CMethodResult& oResult)
{
    rho::Vector<rho::String> arIDs;
    arIDs.addElement("SC1");
    arIDs.addElement("SC2");

    oResult.set(arIDs);
}

rho::String CcontrolServiceSingleton::getInitialDefaultID()
{
    CMethodResult oRes;
    enumerate(oRes);

    rho::Vector<rho::String>& arIDs = oRes.getStringArray();
        
    return arIDs[0];
}

}
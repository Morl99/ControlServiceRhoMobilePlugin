

#include "ControlServiceBase.h"
#include "api_generator/js_helpers.h"

#include "logging/RhoLog.h"
#undef DEFAULT_LOGCATEGORY
#define DEFAULT_LOGCATEGORY "ControlService"

#include "common/StringConverter.h"

extern "C" void rho_wm_impl_performOnUiThread(rho::common::IRhoRunnable* pTask);

using namespace rho;
using namespace rho::json;
using namespace rho::common;
using namespace rho::apiGenerator;


rho::String js_ControlService_startService(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    RAWTRACE3("startService(strObjID = %s, strCallbackID = %s, strJsVmID = %s)", strObjID.c_str(), strCallbackID.c_str(), strJsVmID.c_str());

    rho::apiGenerator::CMethodResult oRes;



    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    int argc = argv.getSize();

    rho::IControlService* pObj = rho::CControlServiceFactoryBase::getInstance()->getModuleByID(strObjID);



    
    if ( argc == 0 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toJSON();
    }
    


    rho::String arg0 = "";
    if ( argc > 0 )
    {
        if ( argv[0].isString() )
        {
            arg0 = argv[0].getString();
        }
        else if (!argv[0].isNull())
        {
            oRes.setArgError( "Type error: argument " "0" " should be " "string" );
            return oRes.toJSON();
        }
    }





















    if ( oRes.hasCallback() )
    {
        pFunctor = rho_makeInstanceClassFunctor2( pObj, &rho::IControlService::startService, arg0,  oRes );
        rho::CControlServiceFactoryBase::getControlServiceSingletonS()->addCommandToQueue( pFunctor );
    }
    else 
    {

        pObj->startService( arg0,  oRes );
    }

    return oRes.toJSON();

}

rho::String js_ControlService_stopService(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    RAWTRACE3("stopService(strObjID = %s, strCallbackID = %s, strJsVmID = %s)", strObjID.c_str(), strCallbackID.c_str(), strJsVmID.c_str());

    rho::apiGenerator::CMethodResult oRes;



    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    int argc = argv.getSize();

    rho::IControlService* pObj = rho::CControlServiceFactoryBase::getInstance()->getModuleByID(strObjID);







    if ( oRes.hasCallback() )
    {
        pFunctor = rho_makeInstanceClassFunctor1( pObj, &rho::IControlService::stopService,  oRes );
        rho::CControlServiceFactoryBase::getControlServiceSingletonS()->addCommandToQueue( pFunctor );
    }
    else 
    {

        pObj->stopService(  oRes );
    }

    return oRes.toJSON();

}



rho::String js_s_ControlService_getDefaultID(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    rho::apiGenerator::CMethodResult oRes;
    rho::String strDefaultID = rho::CControlServiceFactoryBase::getControlServiceSingletonS()->getDefaultID();
    oRes.set(strDefaultID);

    return oRes.toJSON();
}

rho::String js_s_ControlService_getDefault(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    rho::apiGenerator::CMethodResult oRes;
    rho::String strDefaultID = rho::CControlServiceFactoryBase::getControlServiceSingletonS()->getDefaultID();
    oRes.set(strDefaultID);
    oRes.setJSObjectClassPath("Rho.ControlService");

    return oRes.toJSON();
}

rho::String js_s_ControlService_setDefaultID(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    rho::apiGenerator::CMethodResult oRes;
    rho::CControlServiceFactoryBase::getControlServiceSingletonS()->setDefaultID(strObjID);

    return oRes.toJSON();
}



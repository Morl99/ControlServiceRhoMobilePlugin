#include "ControlService.h"

#include "MethodResultJni.h"

#include "api_generator/MethodResult.h"
#include "api_generator/MethodResultConvertor.h"
#include "api_generator/JSONResultConvertor.h"

#include "rhodes/JNIRhoJS.h"

#include "logging/RhoLog.h"
#undef DEFAULT_LOGCATEGORY
#define DEFAULT_LOGCATEGORY "ControlServiceJS"

typedef rho::CControlServiceProxy<ArgumentsAdapter<rho::json::CJSONArray> > ObjectProxy;

using namespace rho::apiGenerator;

rho::String js_s_ControlService_getDefaultID(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    RAWTRACE(__FUNCTION__);
    
    rho::apiGenerator::CMethodResult result(false);
    result.set(ObjectProxy::getDefaultID());
    return CMethodResultConvertor().toJSON(result);
}

rho::String js_s_ControlService_getDefault(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    RAWTRACE(__FUNCTION__);
    
    rho::apiGenerator::CMethodResult result(false);
    result.setJSObjectClassPath("Rho.ControlService");
    result.set(ObjectProxy::getDefaultID());
    return CMethodResultConvertor().toJSON(result);
}

rho::String js_s_ControlService_setDefaultID(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    RAWTRACE(__FUNCTION__);

    rho::apiGenerator::CMethodResult result(false);
    ObjectProxy::setDefaultID(strObjID);
    return CMethodResultConvertor().toJSON(result);
} 


rho::String js_ControlService_startService(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result(false);
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return CMethodResultConvertor().toJSON(result);
    }

    ObjectProxy controlservice(strObjID);

    int argc = argv.getSize();
    if((argc < 1) || (argc > 1))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return CMethodResultConvertor().toJSON(result);
    }
    
    if(strCallbackID.length() != 0)
    {
        result.setCallBack(strCallbackID, strCallbackParam);
    }

    controlservice.startService(argumentsAdapter(argv), result); 
    rho::String res = CMethodResultConvertor().toJSON(result);
    RAWTRACE(res.c_str());
    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_ControlService_stopService(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result(false);
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return CMethodResultConvertor().toJSON(result);
    }

    ObjectProxy controlservice(strObjID);

    int argc = argv.getSize();
    if((argc < 0) || (argc > 0))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return CMethodResultConvertor().toJSON(result);
    }
    
    if(strCallbackID.length() != 0)
    {
        result.setCallBack(strCallbackID, strCallbackParam);
    }

    controlservice.stopService(argumentsAdapter(argv), result); 
    rho::String res = CMethodResultConvertor().toJSON(result);
    RAWTRACE(res.c_str());
    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}

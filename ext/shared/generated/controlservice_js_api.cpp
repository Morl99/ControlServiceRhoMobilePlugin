#include "api_generator/js_helpers.h"

#include "logging/RhoLog.h"
#undef DEFAULT_LOGCATEGORY
#define DEFAULT_LOGCATEGORY "ControlService"


rho::String js_ControlService_startService(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);
rho::String js_s_ControlService_def_startService(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);

rho::String js_ControlService_stopService(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);
rho::String js_s_ControlService_def_stopService(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);



rho::String js_s_ControlService_getDefaultID(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);
rho::String js_s_ControlService_getDefault(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);
rho::String js_s_ControlService_setDefaultID(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);



extern "C" void Init_JSAPI_ControlService(void)
{

    rho::apiGenerator::js_define_instance_method("Rho:ControlService:startService", js_ControlService_startService);
    //  should define static method !     rho::apiGenerator::js_define_static_method("Rho:ControlService:def_startService", js_s_ControlService_def_startService);;

    rho::apiGenerator::js_define_instance_method("Rho:ControlService:stopService", js_ControlService_stopService);
    //  should define static method !     rho::apiGenerator::js_define_static_method("Rho:ControlService:def_stopService", js_s_ControlService_def_stopService);;


    rho::apiGenerator::js_define_static_method("Rho:ControlService:getDefaultID", js_s_ControlService_getDefaultID);
    rho::apiGenerator::js_define_static_method("Rho:ControlService:getDefault", js_s_ControlService_getDefault);
    rho::apiGenerator::js_define_static_method("Rho:ControlService:setDefaultID", js_s_ControlService_setDefaultID);

}


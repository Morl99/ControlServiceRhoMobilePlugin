#include "common/app_build_capabilities.h"

extern "C" void Init_RubyAPI_ControlService();
extern "C" void Init_JSAPI_ControlService();

extern "C" int  rho_ruby_is_started();

extern "C" void Init_ControlService_API()
{
    if (rho_ruby_is_started())
    {
    	Init_RubyAPI_ControlService();
    }

#ifndef RHO_NO_JS_API
    Init_JSAPI_ControlService();
#endif
}

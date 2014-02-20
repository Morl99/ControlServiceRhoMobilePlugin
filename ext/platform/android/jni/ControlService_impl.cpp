#include "rhodes.h"
#include "ControlService.h"

#include "logging/RhoLog.h"
#undef DEFAULT_LOGCATEGORY
#define DEFAULT_LOGCATEGORY "ControlService_impl"

#define CONTROLSERVICE_FACTORY_CLASS "com.rho.controlservice.ControlServiceFactory"

extern "C" void Init_ControlService_API(void);

extern "C" void Init_ControlService(void)
{
    RAWTRACE(__FUNCTION__);

    JNIEnv *env = jnienv();
    if(env)
    {
        jclass cls = rho_find_class(env, CONTROLSERVICE_FACTORY_CLASS);
        if(!cls)
        {
            RAWLOG_ERROR1("Failed to find java class: %s", CONTROLSERVICE_FACTORY_CLASS);
            return;
        }
        jmethodID midFactory = env->GetMethodID(cls, "<init>", "()V");
        if(!midFactory)
        {
            RAWLOG_ERROR1("Failed to get constructor for java class %s", CONTROLSERVICE_FACTORY_CLASS);
            return;
        }
        jobject jFactory = env->NewObject(cls, midFactory);
        if(env->IsSameObject(jFactory, NULL))
        {
            RAWLOG_ERROR1("Failed to create %s instance", CONTROLSERVICE_FACTORY_CLASS);
            return;
        }
        
        RAWTRACE("Initializing Java factory");

        rho::CControlServiceBase::setJavaFactory(env, jFactory);

        RAWTRACE("Deleting JNI reference");

        env->DeleteLocalRef(jFactory);

        RAWTRACE("Initializing API");

        Init_ControlService_API();

        RAWTRACE("Init_ControlService succeeded");
    }
    else
    {
        RAWLOG_ERROR("Failed to initialize ControlService API: jnienv() is failed");
    }

}

extern "C" void Init_ControlService_extension() {
    Init_ControlService();
}

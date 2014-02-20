#pragma once

#include "common/RhoStd.h"
#include "logging/RhoLog.h"
#include "rhodes/JNIRhodes.h"
#include "MethodExecutorJni.h"
#include "MethodResultJni.h"


namespace rho {

using rho::apiGenerator::MethodResultJni;
using rho::apiGenerator::MethodExecutorJni;

class CControlServiceBase : public MethodExecutorJni
{
protected:
    DEFINE_LOGCLASS;

    static const char* const FACTORY_SINGLETON_CLASS;
    static jclass s_clsFactorySingleton;
    static jmethodID s_midFactorySetInstance;
    static jmethodID s_midFactoryGetInstance;

    //IControlServiceFactory staff
    static const char* const IFACTORY_CLASS;
    static jclass s_clsIFactory;
    static jmethodID s_midGetApiSingleton;
    static jmethodID s_midGetApiObject;

    //ControlServiceSingletonBase staff
    static const char* const SINGLETON_BASE_CLASS;
    static jclass s_clsSingletonBase;

    //ControlServiceBase staff
    static const char* const OBJECT_BASE_CLASS;
    static jclass s_clsObjectBase;

    //Method tasks

    static const char* const STARTSERVICE_TASK_CLASS;
    static jclass s_clsstartServiceTask;
    static jmethodID s_midstartServiceTask;
    static const char* const STOPSERVICE_TASK_CLASS;
    static jclass s_clsstopServiceTask;
    static jmethodID s_midstopServiceTask;

    //IRhoApiDefaultId staff
    static const char* const IDEFAULTID_CLASS;
    static jclass s_clsIDefaultId;
    static jmethodID s_midGetDefaultID;
    static jmethodID s_midSetDefaultID;

    static JNIEnv* jniInit(JNIEnv* env);
    static JNIEnv* jniInit();

    static jobject getFactory(JNIEnv* env);
    static jobject getSingleton(JNIEnv* env);

    rho::String m_id;
    jobject getObject(JNIEnv* env);
public:
    static void setJavaFactory(JNIEnv* env, jobject jFactory);

    static rho::String getDefaultID();
    static void setDefaultID(const rho::String& id); 

    CControlServiceBase(const rho::String& id)
        : MethodExecutorJni(), m_id(id)
        {}
    virtual ~CControlServiceBase() {}
};

template <typename T>
class CControlServiceProxy : public CControlServiceBase
{
public:
    CControlServiceProxy(const rho::String& id)
        : CControlServiceBase(id)
        {}
    virtual ~CControlServiceProxy() {}

    void startService(const T& argsAdapter, MethodResultJni& result)
    {
        LOG(TRACE) + "startService";

        JNIEnv *env = jniInit();
        if (!env) {
            LOG(FATAL) + "JNI initialization failed";
            return;
        }

        jhobject jhObject = 
            getObject(env); 

        if(argsAdapter.size() <= 0)
        {
            LOG(ERROR) + "Wrong number of arguments: 'testDescription' must be set ^^^";
            result.setArgError("Wrong number of arguments: 'testDescription' must be set");
            return;
        }
        jholder< jstring > jhtestDescription = 
            rho_cast< jstring >(env, argsAdapter[0]);

        jhobject jhTask = env->NewObject(s_clsstartServiceTask, s_midstartServiceTask,
                    jhObject.get(), 
                    jhtestDescription.get(),
                    static_cast<jobject>(result));

        run(env, jhTask.get(), result, false, false);
        if(env->ExceptionCheck() == JNI_TRUE)
        {
            rho::String message = rho::common::clearException(env);
            LOG(ERROR) + message;
            result.setError(message);
        }
    }

    void stopService(const T& argsAdapter, MethodResultJni& result)
    {
        LOG(TRACE) + "stopService";

        JNIEnv *env = jniInit();
        if (!env) {
            LOG(FATAL) + "JNI initialization failed";
            return;
        }

        jhobject jhObject = 
            getObject(env); 

        jhobject jhTask = env->NewObject(s_clsstopServiceTask, s_midstopServiceTask,
                    jhObject.get(), 
                    static_cast<jobject>(result));

        run(env, jhTask.get(), result, false, false);
        if(env->ExceptionCheck() == JNI_TRUE)
        {
            rho::String message = rho::common::clearException(env);
            LOG(ERROR) + message;
            result.setError(message);
        }
    }


};


}

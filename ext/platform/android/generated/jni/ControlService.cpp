#include "ControlService.h"


namespace rho {

IMPLEMENT_LOGCLASS(CControlServiceBase, "ControlServiceJNI");

//ControlServiceFactorySingleton staff
const char* const CControlServiceBase::FACTORY_SINGLETON_CLASS = "com.rho.controlservice.ControlServiceFactorySingleton";
jclass CControlServiceBase::s_clsFactorySingleton = 0;
jmethodID CControlServiceBase::s_midFactorySetInstance;
jmethodID CControlServiceBase::s_midFactoryGetInstance;

//ControlServiceFactory staff
const char* const CControlServiceBase::IFACTORY_CLASS = "com.rho.controlservice.IControlServiceFactory";
jclass CControlServiceBase::s_clsIFactory = 0;
jmethodID CControlServiceBase::s_midGetApiSingleton;
jmethodID CControlServiceBase::s_midGetApiObject;

//ControlServiceSingletonBase staff
const char* const CControlServiceBase::SINGLETON_BASE_CLASS = "com.rho.controlservice.ControlServiceSingletonBase";
jclass CControlServiceBase::s_clsSingletonBase = 0;

//ControlServiceBase staff
const char* const CControlServiceBase::OBJECT_BASE_CLASS = "com.rho.controlservice.ControlServiceBase";
jclass CControlServiceBase::s_clsObjectBase = 0;


//IRhoApiDefaultId staff
const char* const CControlServiceBase::IDEFAULTID_CLASS = "com.rhomobile.rhodes.api.IRhoApiDefaultId";
jclass CControlServiceBase::s_clsIDefaultId = 0;
jmethodID CControlServiceBase::s_midGetDefaultID;
jmethodID CControlServiceBase::s_midSetDefaultID;


//Method tasks

const char* const CControlServiceBase::STARTSERVICE_TASK_CLASS = 
        "com.rho.controlservice.ControlServiceBase$startServiceTask";

jclass CControlServiceBase::s_clsstartServiceTask = 0;
jmethodID CControlServiceBase::s_midstartServiceTask;

const char* const CControlServiceBase::STOPSERVICE_TASK_CLASS = 
        "com.rho.controlservice.ControlServiceBase$stopServiceTask";

jclass CControlServiceBase::s_clsstopServiceTask = 0;
jmethodID CControlServiceBase::s_midstopServiceTask;


//----------------------------------------------------------------------------------------------------------------------

JNIEnv* CControlServiceBase::jniInit()
{
    JNIEnv *env = jnienv();
    if(!env)
    {
        LOG(FATAL) + "JNI init failed: JNIEnv is null";
        return 0;
    }
    return jniInit(env);
}
//----------------------------------------------------------------------------------------------------------------------

JNIEnv* CControlServiceBase::jniInit(JNIEnv* env)
{
    static bool initialized = false;
    env = MethodExecutorJni::jniInit(env);
    if (!env) {
        LOG(FATAL) + "JNI init failed";
        return 0;
    }

    if(!initialized)
    {
        //init ControlServiceFactorySingleton JNI
        s_clsFactorySingleton = loadClass(env, FACTORY_SINGLETON_CLASS);
        if (!s_clsFactorySingleton) return 0;

        s_midFactorySetInstance = env->GetStaticMethodID(s_clsFactorySingleton, "setInstance", "(Lcom/rho/controlservice/IControlServiceFactory;)V");
        if(!s_midFactorySetInstance)
        {
            LOG(FATAL) + "Failed to get method 'setInstance' for java class " + FACTORY_SINGLETON_CLASS;
            return NULL;
        }
        s_midFactoryGetInstance = env->GetStaticMethodID(s_clsFactorySingleton, "getInstance", "()Lcom/rho/controlservice/IControlServiceFactory;");
        if(!s_midFactoryGetInstance)
        {
            LOG(FATAL) + "Failed to get method 'getInstance' for java class " + FACTORY_SINGLETON_CLASS;
            return NULL;
        }

        //init IControlServiceFactory JNI
        s_clsIFactory = loadClass(env, IFACTORY_CLASS);
        if (!s_clsIFactory) return 0;
        s_midGetApiSingleton = env->GetMethodID(s_clsIFactory, "getApiSingleton", "()Lcom/rho/controlservice/IControlServiceSingleton;");
        if(!s_midGetApiSingleton)
        {
            LOG(FATAL) + "Failed to get method 'getApiSingleton' for java class " + IFACTORY_CLASS;
            return NULL;
        }
        s_midGetApiObject = env->GetMethodID(s_clsIFactory, "getApiObject", "(Ljava/lang/String;)Lcom/rho/controlservice/IControlService;");
        if(!s_midGetApiObject)
        {
            LOG(FATAL) + "Failed to get method 'getApiObject' for java class " + IFACTORY_CLASS;
            return NULL;
        }

        s_clsSingletonBase = loadClass(env, SINGLETON_BASE_CLASS);
        if (!s_clsSingletonBase) return 0;
        s_clsObjectBase = loadClass(env, OBJECT_BASE_CLASS);
        if (!s_clsObjectBase) return 0;



        s_clsstartServiceTask = loadClass(env, STARTSERVICE_TASK_CLASS);
        if (!s_clsstartServiceTask) return 0;
        s_midstartServiceTask = env->GetMethodID(s_clsstartServiceTask, "<init>",
                        "(Lcom/rho/controlservice/IControlService;Ljava/lang/String;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midstartServiceTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + STARTSERVICE_TASK_CLASS;
            return NULL;
        }

        s_clsstopServiceTask = loadClass(env, STOPSERVICE_TASK_CLASS);
        if (!s_clsstopServiceTask) return 0;
        s_midstopServiceTask = env->GetMethodID(s_clsstopServiceTask, "<init>",
                        "(Lcom/rho/controlservice/IControlService;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midstopServiceTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + STOPSERVICE_TASK_CLASS;
            return NULL;
        }


        s_clsIDefaultId = loadClass(env, IDEFAULTID_CLASS);
        if (!s_clsIDefaultId) return 0;
        s_midGetDefaultID = env->GetMethodID(s_clsIDefaultId, "getDefaultID", "()Ljava/lang/String;");
        if(!s_midGetDefaultID)
        {
            LOG(FATAL) + "Failed to get method 'getDefaultID' for java class " + IDEFAULTID_CLASS;
            return NULL;
        }
        s_midSetDefaultID = env->GetMethodID(s_clsIDefaultId, "setDefaultID", "(Ljava/lang/String;)V");
        if(!s_midSetDefaultID)
        {
            LOG(FATAL) + "Failed to get method 'setDefaultID' for java class " + IDEFAULTID_CLASS;
            return NULL;
        }


        initialized = true;
        LOG(TRACE) + "CControlService JNI init succeeded";
    }
    return env;
}
//----------------------------------------------------------------------------------------------------------------------

void CControlServiceBase::setJavaFactory(JNIEnv* env, jobject jFactory)
{
    LOG(TRACE) + "setJavaFactory";

    env = jniInit(env);
    if (!env) {
        LOG(FATAL) + "JNI initialization failed";
        return;
    }

    env->CallStaticVoidMethod(s_clsFactorySingleton, s_midFactorySetInstance, jFactory);

    LOG(TRACE) + "setJavaFactory succeeded";
}
//----------------------------------------------------------------------------------------------------------------------

rho::String CControlServiceBase::getDefaultID()
{
    LOG(TRACE) + "getDefaultID";

    JNIEnv *env = jniInit();
    if (!env) {
        LOG(FATAL) + "JNI initialization failed";
        return rho::String();
    }

    jhobject jhSingleton = getSingleton(env);
    jhstring res = static_cast<jstring>(env->CallObjectMethod(jhSingleton.get(), s_midGetDefaultID));
    return rho_cast<rho::String>(env, res);
}
//----------------------------------------------------------------------------------------------------------------------

void CControlServiceBase::setDefaultID(const rho::String& id)
{
    LOG(TRACE) + "setDefaultID: " + id;

    JNIEnv *env = jniInit();
    if (!env) {
        LOG(FATAL) + "JNI initialization failed";
        return;
    }

    jhobject instance = getSingleton(env);
    jhstring jhId = rho_cast<jstring>(env, id);
    env->CallVoidMethod(instance.get(), s_midSetDefaultID, jhId.get());
}
//----------------------------------------------------------------------------------------------------------------------

jobject CControlServiceBase::getFactory(JNIEnv* env)
{
    jobject res = env->CallStaticObjectMethod(s_clsFactorySingleton, s_midFactoryGetInstance);
    return res;
}
//----------------------------------------------------------------------------------------------------------------------

jobject CControlServiceBase::getSingleton(JNIEnv* env)
{
    jhobject jhFactory = getFactory(env);
    jobject res = env->CallObjectMethod(jhFactory.get(), s_midGetApiSingleton);
    return res;
}
//----------------------------------------------------------------------------------------------------------------------

jobject CControlServiceBase::getObject(JNIEnv* env)
{
    jhstring jhId = rho_cast<jstring>(env, m_id);
    jhobject jhFactory = getFactory(env);
    jobject res = env->CallObjectMethod(jhFactory.get(), s_midGetApiObject, jhId.get());
    return res;
}
//----------------------------------------------------------------------------------------------------------------------


}

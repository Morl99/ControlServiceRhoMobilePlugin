
#include "ControlServiceBase.h"

#include "logging/RhoLog.h"
#undef DEFAULT_LOGCATEGORY
#define DEFAULT_LOGCATEGORY "ControlService"

#include "ruby/ext/rho/rhoruby.h"
#include "common/StringConverter.h"
#include "common/AutoPointer.h"

using namespace rho;
using namespace rho::common;
using namespace rho::apiGenerator;

extern "C"
{
void rho_wm_impl_performOnUiThread(rho::common::IRhoRunnable* pTask);
VALUE getRuby_ControlService_Module();


VALUE rb_ControlService_s_default(VALUE klass)
{
    rho::String strDefaultID = rho::CControlServiceFactoryBase::getControlServiceSingletonS()->getDefaultID();

    return rho_ruby_create_object_with_id( klass, strDefaultID.c_str() );
}

VALUE rb_ControlService_s_setDefault(VALUE klass, VALUE valObj)
{
    const char* szID = rho_ruby_get_object_id( valObj );
    rho::CControlServiceFactoryBase::getControlServiceSingletonS()->setDefaultID(szID);

    return rho_ruby_get_NIL();
}


static void string_iter(const char* szVal, void* par)
{
    rho::Vector<rho::String>& ar = *((rho::Vector<rho::String>*)(par));
    ar.addElement( szVal );
}

static void getStringArrayFromValue(VALUE val, rho::Vector<rho::String>& res)
{
    rho_ruby_enum_strary_json(val, string_iter, &res);
}

static void hash_eachstr(const char* szName, const char* szVal, void* par)
{
    rho::Hashtable<rho::String, rho::String>& hash = *((rho::Hashtable<rho::String, rho::String>*)(par));
    hash.put( szName, szVal );
}

static void getStringHashFromValue(VALUE val, rho::Hashtable<rho::String, rho::String>& res)
{
    rho_ruby_enum_strhash_json(val, hash_eachstr, &res);
}


static VALUE _api_generator_ControlService_startService(int argc, VALUE *argv, rho::IControlService* pObj)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    nCallbackArg = 1;
    if ( argc == 0 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toRuby();
    }
    rho::String arg0 = "";
    if ( argc > 0 )
    {
        if ( rho_ruby_is_string(argv[0]) )
        {
            arg0 = getStringFromValue(argv[0]);
        }
        else if (!rho_ruby_is_NIL(argv[0]))
        {
            oRes.setArgError("Type error: argument " "0" " should be " "string" );
            return oRes.toRuby();
        }
    }

    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toRuby();
    }
    if ( bUseCallback )
    {
        pFunctor = rho_makeInstanceClassFunctor2( pObj, &rho::IControlService::startService, arg0,  oRes );
        rho::CControlServiceFactoryBase::getControlServiceSingletonS()->addCommandToQueue( pFunctor );
    }
    else 
    {

        pObj->startService( arg0,  oRes );
    }
    
    return oRes.toRuby();
}



VALUE rb_ControlService_startService(int argc, VALUE *argv, VALUE obj)
{
    const char* szID = rho_ruby_get_object_id( obj );
    if (!szID)
        rho_ruby_raise_runtime("Object was deleted.");

    VALUE res = 0;
    rho::IControlService* pObj =  rho::CControlServiceFactoryBase::getInstance()->getModuleByID(szID);

    res = _api_generator_ControlService_startService(argc, argv, pObj);

    return res;
}



VALUE rb_s_ControlService_def_startService(int argc, VALUE *argv)
{
    rho::String strDefaultID = rho::CControlServiceFactoryBase::getControlServiceSingletonS()->getDefaultID();
    rho::IControlService* pObj = rho::CControlServiceFactoryBase::getInstance()->getModuleByID(strDefaultID);

    return _api_generator_ControlService_startService(argc, argv, pObj);
}


static VALUE _api_generator_ControlService_stopService(int argc, VALUE *argv, rho::IControlService* pObj)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(0) );
        return oRes.toRuby();
    }
    if ( bUseCallback )
    {
        pFunctor = rho_makeInstanceClassFunctor1( pObj, &rho::IControlService::stopService,  oRes );
        rho::CControlServiceFactoryBase::getControlServiceSingletonS()->addCommandToQueue( pFunctor );
    }
    else 
    {

        pObj->stopService(  oRes );
    }
    
    return oRes.toRuby();
}



VALUE rb_ControlService_stopService(int argc, VALUE *argv, VALUE obj)
{
    const char* szID = rho_ruby_get_object_id( obj );
    if (!szID)
        rho_ruby_raise_runtime("Object was deleted.");

    VALUE res = 0;
    rho::IControlService* pObj =  rho::CControlServiceFactoryBase::getInstance()->getModuleByID(szID);

    res = _api_generator_ControlService_stopService(argc, argv, pObj);

    return res;
}



VALUE rb_s_ControlService_def_stopService(int argc, VALUE *argv)
{
    rho::String strDefaultID = rho::CControlServiceFactoryBase::getControlServiceSingletonS()->getDefaultID();
    rho::IControlService* pObj = rho::CControlServiceFactoryBase::getInstance()->getModuleByID(strDefaultID);

    return _api_generator_ControlService_stopService(argc, argv, pObj);
}



}
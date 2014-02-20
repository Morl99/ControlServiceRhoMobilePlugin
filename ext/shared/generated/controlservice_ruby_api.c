#include "ruby.h"

static VALUE rb_api_mParent;
static VALUE rb_api_mControlService;

VALUE rb_ControlService_startService(int argc, VALUE *argv, VALUE obj);
VALUE rb_s_ControlService_def_startService(int argc, VALUE *argv);
VALUE rb_ControlService_stopService(int argc, VALUE *argv, VALUE obj);
VALUE rb_s_ControlService_def_stopService(int argc, VALUE *argv);



VALUE rb_ControlService_s_default(VALUE klass);
VALUE rb_ControlService_s_setDefault(VALUE klass, VALUE obj);


VALUE getRuby_ControlService_Module(){ return rb_api_mControlService; }



static void _free_class_object(void *p)
{
    ruby_xfree(p);
}

static VALUE _allocate_class_object(VALUE klass)
{
    VALUE valObj = 0;
    char ** ppString = NULL;
    void* pData = ALLOC(void*);
    memset( pData, 0, sizeof(pData) );
    
	valObj = Data_Wrap_Struct(klass, 0, _free_class_object, pData);

    Data_Get_Struct(valObj, char *, ppString);
    *ppString = xmalloc(10);
    sprintf(*ppString, "%X", valObj);

    return valObj;
}

void Init_RubyAPI_ControlService(void)
{

    VALUE tmpParent = Qnil;
    rb_api_mParent = rb_define_module("Rho");
    

	rb_api_mControlService = rb_define_class_under(rb_api_mParent, "ControlService", rb_cObject);

	rb_define_alloc_func(rb_api_mControlService, _allocate_class_object);
    //Constructor should be not available in case of static members
    //rb_undef_alloc_func(rb_api_mControlService);

    rb_define_method(rb_api_mControlService, "startService", rb_ControlService_startService, -1);
    rb_define_singleton_method(rb_api_mControlService, "startService", rb_s_ControlService_def_startService, -1);
    rb_define_method(rb_api_mControlService, "stopService", rb_ControlService_stopService, -1);
    rb_define_singleton_method(rb_api_mControlService, "stopService", rb_s_ControlService_def_stopService, -1);



    rb_define_singleton_method(rb_api_mControlService, "getDefault", rb_ControlService_s_default, 0);
    rb_define_singleton_method(rb_api_mControlService, "setDefault", rb_ControlService_s_setDefault, 1);






}


#import "IControlService.h"
//#import "api_generator/common/ruby_helpers.h"

#import "ruby/ext/rho/rhoruby.h"
#import "api_generator/iphone/CMethodResult.h"
#import "api_generator/iphone/CRubyConverter.h"

extern VALUE getRuby_ControlService_Module();



@interface ControlService_RubyValueFactory : NSObject<IMethodResult_RubyObjectFactory> {
}

- (VALUE) makeRubyValue:(NSObject*)obj;
+ (ControlService_RubyValueFactory*) getSharedInstance;

@end

static ControlService_RubyValueFactory* our_ControlService_RubyValueFactory = nil;

@implementation ControlService_RubyValueFactory

- (VALUE) makeRubyValue:(NSObject*)obj {
    VALUE v = rho_ruby_get_NIL();
    if ([obj isKindOfClass:[NSString class]]) {
        // single objects id
        NSString* strRes = (NSString*)obj;
        v = rho_ruby_create_object_with_id( getRuby_ControlService_Module(), [strRes UTF8String] );
    }
    else if ([obj isKindOfClass:[NSArray class]]) {
        // list of IDs
        v = rho_ruby_create_array();
        NSArray* arrRes = (NSArray*)obj;
        int i;
        for (i = 0; i < [arrRes count]; i++) {
            NSString* strItem = (NSString*)[arrRes objectAtIndex:i];
            VALUE vItem = rho_ruby_create_object_with_id( getRuby_ControlService_Module(), [strItem UTF8String] );
            rho_ruby_add_to_array(v, vItem);
        }
    }
    return v;
}

+ (ControlService_RubyValueFactory*) getSharedInstance {
    if (our_ControlService_RubyValueFactory == nil) {
        our_ControlService_RubyValueFactory = [[ControlService_RubyValueFactory alloc] init];
    }
    return our_ControlService_RubyValueFactory;
}

@end


id<IControlService> ControlService_makeInstanceByRubyObject(VALUE obj) {
    const char* szID = rho_ruby_get_object_id( obj );
    id<IControlServiceFactory> factory = [ControlServiceFactorySingleton getControlServiceFactoryInstance];
    return [factory getControlServiceByID:[NSString stringWithUTF8String:szID]];
}









@interface rb_ControlService_startService_caller_params : NSObject

@property (nonatomic, copy) NSArray* params;
@property (assign) id<IControlService> item;
@property (assign) CMethodResult* methodResult;

-(void)dealloc;

+(rb_ControlService_startService_caller_params*) makeParams:(NSArray*)_params _item:(id<IControlService>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_ControlService_startService_caller_params

@synthesize params,item,methodResult;

-(void)dealloc {
    [params release];
    [super dealloc];
}

+(rb_ControlService_startService_caller_params*) makeParams:(NSArray*)_params _item:(id<IControlService>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_ControlService_startService_caller_params* par = [[rb_ControlService_startService_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return [par retain];
}

@end


@interface rb_ControlService_startService_caller : NSObject {

}
+(rb_ControlService_startService_caller*) getSharedInstance;
+(void) startService:(rb_ControlService_startService_caller_params*)caller_params;
+(void) startService_in_thread:(rb_ControlService_startService_caller_params*)caller_params;
+(void) startService_in_UI_thread:(rb_ControlService_startService_caller_params*)caller_params;

@end

static rb_ControlService_startService_caller* our_ControlService_startService_caller = nil;

@implementation rb_ControlService_startService_caller

+(rb_ControlService_startService_caller*) getSharedInstance {
    if (our_ControlService_startService_caller == nil) {
        our_ControlService_startService_caller = [[rb_ControlService_startService_caller alloc] init];
    }
    return our_ControlService_startService_caller;
}

-(void) command_startService:(rb_ControlService_startService_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IControlService> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem startService:(NSString*)[params objectAtIndex:0] methodResult:methodResult ];
    [caller_params release];
}

+(void) startService:(rb_ControlService_startService_caller_params*)caller_params {
    [[rb_ControlService_startService_caller getSharedInstance] command_startService:caller_params];
}

+(void) startService_in_thread:(rb_ControlService_startService_caller_params*)caller_params {
    [[rb_ControlService_startService_caller getSharedInstance] performSelectorInBackground:@selector(command_startService:) withObject:caller_params];
}

+(void) startService_in_UI_thread:(rb_ControlService_startService_caller_params*)caller_params {
    [[rb_ControlService_startService_caller getSharedInstance] performSelectorOnMainThread:@selector(command_startService:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_ControlService_startService_Obj(int argc, VALUE *argv, id<IControlService>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[1+1];
    NSString* callbackURL = nil;
    unsigned long callbackMethod = 0;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;

    [methodResult setMethodSignature:@"ControlService::startService"];

    
    BOOL is_factory_param[] = { NO, NO };

    int i;

    // init
    for (i = 0; i < (1); i++) {
        params[i] = [NSNull null];
    }

    

    // enumerate params
    for (int i = 0; i < (1); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = ControlService_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(1)];
    for (i = 0 ; i < (1); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (1+1)) {
        VALUE callback = argv[1];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
        else if (rho_ruby_is_proc(callback) || rho_ruby_is_method(callback)) {
            callbackMethod = callback;
        }
    }
    // check callback param
    if (argc >= (1+2)) {
        VALUE callback_param = argv[1+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if ((callbackURL != nil) || (callbackMethod != 0)) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        if (callbackURL != nil)
            [methodResult setRubyCallback:callbackURL];
        if (callbackMethod != 0)
            [methodResult setRubyCallbackMethod:callbackMethod];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_ControlService_startService_caller startService_in_thread:[rb_ControlService_startService_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_ControlService_startService_caller startService:[rb_ControlService_startService_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (callbackMethod == 0) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_ControlService_startService(int argc, VALUE *argv, VALUE obj) {

    id<IControlService> item = ControlService_makeInstanceByRubyObject(obj);
    return rb_ControlService_startService_Obj(argc, argv, item);

}

VALUE rb_s_ControlService_def_startService(int argc, VALUE *argv) {
    id<IControlServiceFactory> factory = [ControlServiceFactorySingleton getControlServiceFactoryInstance];
    id<IControlServiceSingleton> singleton = [factory getControlServiceSingleton];

    NSString* defID = [singleton getDefaultID];

    id<IControlService> item = [factory getControlServiceByID:defID];
    return rb_ControlService_startService_Obj(argc, argv, item);
}







@interface rb_ControlService_stopService_caller_params : NSObject

@property (nonatomic, copy) NSArray* params;
@property (assign) id<IControlService> item;
@property (assign) CMethodResult* methodResult;

-(void)dealloc;

+(rb_ControlService_stopService_caller_params*) makeParams:(NSArray*)_params _item:(id<IControlService>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_ControlService_stopService_caller_params

@synthesize params,item,methodResult;

-(void)dealloc {
    [params release];
    [super dealloc];
}

+(rb_ControlService_stopService_caller_params*) makeParams:(NSArray*)_params _item:(id<IControlService>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_ControlService_stopService_caller_params* par = [[rb_ControlService_stopService_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return [par retain];
}

@end


@interface rb_ControlService_stopService_caller : NSObject {

}
+(rb_ControlService_stopService_caller*) getSharedInstance;
+(void) stopService:(rb_ControlService_stopService_caller_params*)caller_params;
+(void) stopService_in_thread:(rb_ControlService_stopService_caller_params*)caller_params;
+(void) stopService_in_UI_thread:(rb_ControlService_stopService_caller_params*)caller_params;

@end

static rb_ControlService_stopService_caller* our_ControlService_stopService_caller = nil;

@implementation rb_ControlService_stopService_caller

+(rb_ControlService_stopService_caller*) getSharedInstance {
    if (our_ControlService_stopService_caller == nil) {
        our_ControlService_stopService_caller = [[rb_ControlService_stopService_caller alloc] init];
    }
    return our_ControlService_stopService_caller;
}

-(void) command_stopService:(rb_ControlService_stopService_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IControlService> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem stopService:methodResult ];
    [caller_params release];
}

+(void) stopService:(rb_ControlService_stopService_caller_params*)caller_params {
    [[rb_ControlService_stopService_caller getSharedInstance] command_stopService:caller_params];
}

+(void) stopService_in_thread:(rb_ControlService_stopService_caller_params*)caller_params {
    [[rb_ControlService_stopService_caller getSharedInstance] performSelectorInBackground:@selector(command_stopService:) withObject:caller_params];
}

+(void) stopService_in_UI_thread:(rb_ControlService_stopService_caller_params*)caller_params {
    [[rb_ControlService_stopService_caller getSharedInstance] performSelectorOnMainThread:@selector(command_stopService:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_ControlService_stopService_Obj(int argc, VALUE *argv, id<IControlService>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[0+1];
    NSString* callbackURL = nil;
    unsigned long callbackMethod = 0;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;

    [methodResult setMethodSignature:@"ControlService::stopService"];

    
    BOOL is_factory_param[] = { NO };

    int i;

    // init
    for (i = 0; i < (0); i++) {
        params[i] = [NSNull null];
    }

    

    // enumerate params
    for (int i = 0; i < (0); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = ControlService_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(0)];
    for (i = 0 ; i < (0); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (0+1)) {
        VALUE callback = argv[0];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
        else if (rho_ruby_is_proc(callback) || rho_ruby_is_method(callback)) {
            callbackMethod = callback;
        }
    }
    // check callback param
    if (argc >= (0+2)) {
        VALUE callback_param = argv[0+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if ((callbackURL != nil) || (callbackMethod != 0)) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        if (callbackURL != nil)
            [methodResult setRubyCallback:callbackURL];
        if (callbackMethod != 0)
            [methodResult setRubyCallbackMethod:callbackMethod];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_ControlService_stopService_caller stopService_in_thread:[rb_ControlService_stopService_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_ControlService_stopService_caller stopService:[rb_ControlService_stopService_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (callbackMethod == 0) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_ControlService_stopService(int argc, VALUE *argv, VALUE obj) {

    id<IControlService> item = ControlService_makeInstanceByRubyObject(obj);
    return rb_ControlService_stopService_Obj(argc, argv, item);

}

VALUE rb_s_ControlService_def_stopService(int argc, VALUE *argv) {
    id<IControlServiceFactory> factory = [ControlServiceFactorySingleton getControlServiceFactoryInstance];
    id<IControlServiceSingleton> singleton = [factory getControlServiceSingleton];

    NSString* defID = [singleton getDefaultID];

    id<IControlService> item = [factory getControlServiceByID:defID];
    return rb_ControlService_stopService_Obj(argc, argv, item);
}







VALUE rb_ControlService_s_default(VALUE klass)
{
    id<IControlServiceFactory> factory = [ControlServiceFactorySingleton getControlServiceFactoryInstance];
    id<IControlServiceSingleton> singleton = [factory getControlServiceSingleton];

    NSString* defID = [singleton getDefaultID];

    return rho_ruby_create_object_with_id( klass, [defID UTF8String] );
}

VALUE rb_ControlService_s_setDefault(VALUE klass, VALUE valObj)
{
    const char* szID = rho_ruby_get_object_id( valObj );
    id<IControlServiceFactory> factory = [ControlServiceFactorySingleton getControlServiceFactoryInstance];
    id<IControlServiceSingleton> singleton = [factory getControlServiceSingleton];

    [singleton setDefaultID:[NSString stringWithUTF8String:szID]];

    return rho_ruby_get_NIL();
}




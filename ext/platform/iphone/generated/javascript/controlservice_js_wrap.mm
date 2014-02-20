#import "IControlService.h"
//#import "api_generator/common/ruby_helpers.h"

#include "api_generator/js_helpers.h"

#import "api_generator/iphone/CMethodResult.h"
#import "api_generator/iphone/CJSConverter.h"

extern VALUE getRuby_ControlService_Module();



id<IControlService> ControlService_makeInstanceByJSObject(rho::String sid) {
    const char* szID = sid.c_str();
    id<IControlServiceFactory> factory = [ControlServiceFactorySingleton getControlServiceFactoryInstance];
    return [factory getControlServiceByID:[NSString stringWithUTF8String:szID]];
}









@interface ControlService_startService_caller_params : NSObject

@property (nonatomic, copy) NSArray* params;
@property (assign) id<IControlService> item;
@property (assign) CMethodResult* methodResult;

-(void)dealloc;

+(ControlService_startService_caller_params*) makeParams:(NSArray*)_params _item:(id<IControlService>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation ControlService_startService_caller_params

@synthesize params,item,methodResult;

-(void)dealloc {
    [params release];
    [super dealloc];
}

+(ControlService_startService_caller_params*) makeParams:(NSArray*)_params _item:(id<IControlService>)_item _methodResult:(CMethodResult*)_methodResult {
    ControlService_startService_caller_params* par = [[ControlService_startService_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return [par retain];
}

@end


@interface ControlService_startService_caller : NSObject {

}
+(ControlService_startService_caller*) getSharedInstance;
+(void) startService:(ControlService_startService_caller_params*)caller_params;
+(void) startService_in_thread:(ControlService_startService_caller_params*)caller_params;
+(void) startService_in_UI_thread:(ControlService_startService_caller_params*)caller_params;

@end

static ControlService_startService_caller* our_ControlService_startService_caller = nil;

@implementation ControlService_startService_caller

+(ControlService_startService_caller*) getSharedInstance {
    if (our_ControlService_startService_caller == nil) {
        our_ControlService_startService_caller = [[ControlService_startService_caller alloc] init];
    }
    return our_ControlService_startService_caller;
}

-(void) command_startService:(ControlService_startService_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IControlService> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem startService:(NSString*)[params objectAtIndex:0] methodResult:methodResult ];
    [caller_params release];
}


+(void) startService:(ControlService_startService_caller_params*)caller_params {
    [[ControlService_startService_caller getSharedInstance] command_startService:caller_params];
}

+(void) startService_in_thread:(ControlService_startService_caller_params*)caller_params {
    [[ControlService_startService_caller getSharedInstance] performSelectorInBackground:@selector(command_startService:) withObject:caller_params];
}

+(void) startService_in_UI_thread:(ControlService_startService_caller_params*)caller_params {
    [[ControlService_startService_caller getSharedInstance] performSelectorOnMainThread:@selector(command_startService:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_ControlService_startService_Obj(rho::json::CJSONArray& argv, id<IControlService>objItem, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[1+1];
    BOOL method_return_result = YES;
    BOOL method_receive_callback = NO;
    int argc = argv.getSize();


    [methodResult setMethodSignature:@"ControlService::startService"];

    
    static RHO_API_PARAM rho_api_params[] = { {RHO_API_STRING, 0, "testDescription", 0, 0 } };

    
    BOOL is_factory_param[] = { NO, NO };

    int i;

    // init
    for (i = 0; i < (1); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    

    // enumerate params
    for (int i = 0; i < (1); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = ControlService_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
            // TODO: Handle CMethodResultError
            if (params[i] == nil) {
                NSLog(@"ControlService::startService parameter %d is nil!", i);
                rho::String resValue = rho::String("\"result\":null,\"error\":\"Method parameter is nil!\"");
                return resValue;
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(1)];
    for (i = 0 ; i < (1); i++) {
        [params_array addObject:params[i]];
    }

    
        if (strCallbackID.size() > 0) {
            method_receive_callback = YES;
        }
    

    

    if (method_receive_callback) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:[NSString stringWithUTF8String:strCallbackID.c_str()] webViewUID:[NSString stringWithUTF8String:strJsVmID.c_str()]];
        [methodResult setCallbackParam:[NSString stringWithUTF8String:strCallbackParam.c_str()]];
        
        [ControlService_startService_caller startService_in_thread:[ControlService_startService_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [ControlService_startService_caller startService:[ControlService_startService_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = rho::String("\"result\":null");
    if ((!method_receive_callback) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    return resValue;
}


rho::String js_ControlService_startService(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam) {

    id<IControlService> item = ControlService_makeInstanceByJSObject(strObjID);
    return js_ControlService_startService_Obj(argv, item, strCallbackID, strJsVmID, strCallbackParam);

}

rho::String js_s_ControlService_def_startService(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam) {
    id<IControlServiceFactory> factory = [ControlServiceFactorySingleton getControlServiceFactoryInstance];
    id<IControlServiceSingleton> singleton = [factory getControlServiceSingleton];

    NSString* defID = [singleton getDefaultID];

    id<IControlService> item = [factory getControlServiceByID:defID];
    return js_ControlService_startService_Obj(argv, item, strCallbackID, strJsVmID, strCallbackParam);
}







@interface ControlService_stopService_caller_params : NSObject

@property (nonatomic, copy) NSArray* params;
@property (assign) id<IControlService> item;
@property (assign) CMethodResult* methodResult;

-(void)dealloc;

+(ControlService_stopService_caller_params*) makeParams:(NSArray*)_params _item:(id<IControlService>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation ControlService_stopService_caller_params

@synthesize params,item,methodResult;

-(void)dealloc {
    [params release];
    [super dealloc];
}

+(ControlService_stopService_caller_params*) makeParams:(NSArray*)_params _item:(id<IControlService>)_item _methodResult:(CMethodResult*)_methodResult {
    ControlService_stopService_caller_params* par = [[ControlService_stopService_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return [par retain];
}

@end


@interface ControlService_stopService_caller : NSObject {

}
+(ControlService_stopService_caller*) getSharedInstance;
+(void) stopService:(ControlService_stopService_caller_params*)caller_params;
+(void) stopService_in_thread:(ControlService_stopService_caller_params*)caller_params;
+(void) stopService_in_UI_thread:(ControlService_stopService_caller_params*)caller_params;

@end

static ControlService_stopService_caller* our_ControlService_stopService_caller = nil;

@implementation ControlService_stopService_caller

+(ControlService_stopService_caller*) getSharedInstance {
    if (our_ControlService_stopService_caller == nil) {
        our_ControlService_stopService_caller = [[ControlService_stopService_caller alloc] init];
    }
    return our_ControlService_stopService_caller;
}

-(void) command_stopService:(ControlService_stopService_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IControlService> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem stopService:methodResult ];
    [caller_params release];
}


+(void) stopService:(ControlService_stopService_caller_params*)caller_params {
    [[ControlService_stopService_caller getSharedInstance] command_stopService:caller_params];
}

+(void) stopService_in_thread:(ControlService_stopService_caller_params*)caller_params {
    [[ControlService_stopService_caller getSharedInstance] performSelectorInBackground:@selector(command_stopService:) withObject:caller_params];
}

+(void) stopService_in_UI_thread:(ControlService_stopService_caller_params*)caller_params {
    [[ControlService_stopService_caller getSharedInstance] performSelectorOnMainThread:@selector(command_stopService:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_ControlService_stopService_Obj(rho::json::CJSONArray& argv, id<IControlService>objItem, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[0+1];
    BOOL method_return_result = YES;
    BOOL method_receive_callback = NO;
    int argc = argv.getSize();


    [methodResult setMethodSignature:@"ControlService::stopService"];

    
    static RHO_API_PARAM rho_api_params[] = {  };

    
    BOOL is_factory_param[] = { NO };

    int i;

    // init
    for (i = 0; i < (0); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    

    // enumerate params
    for (int i = 0; i < (0); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = ControlService_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
            // TODO: Handle CMethodResultError
            if (params[i] == nil) {
                NSLog(@"ControlService::stopService parameter %d is nil!", i);
                rho::String resValue = rho::String("\"result\":null,\"error\":\"Method parameter is nil!\"");
                return resValue;
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(0)];
    for (i = 0 ; i < (0); i++) {
        [params_array addObject:params[i]];
    }

    
        if (strCallbackID.size() > 0) {
            method_receive_callback = YES;
        }
    

    

    if (method_receive_callback) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:[NSString stringWithUTF8String:strCallbackID.c_str()] webViewUID:[NSString stringWithUTF8String:strJsVmID.c_str()]];
        [methodResult setCallbackParam:[NSString stringWithUTF8String:strCallbackParam.c_str()]];
        
        [ControlService_stopService_caller stopService_in_thread:[ControlService_stopService_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [ControlService_stopService_caller stopService:[ControlService_stopService_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = rho::String("\"result\":null");
    if ((!method_receive_callback) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    return resValue;
}


rho::String js_ControlService_stopService(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam) {

    id<IControlService> item = ControlService_makeInstanceByJSObject(strObjID);
    return js_ControlService_stopService_Obj(argv, item, strCallbackID, strJsVmID, strCallbackParam);

}

rho::String js_s_ControlService_def_stopService(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam) {
    id<IControlServiceFactory> factory = [ControlServiceFactorySingleton getControlServiceFactoryInstance];
    id<IControlServiceSingleton> singleton = [factory getControlServiceSingleton];

    NSString* defID = [singleton getDefaultID];

    id<IControlService> item = [factory getControlServiceByID:defID];
    return js_ControlService_stopService_Obj(argv, item, strCallbackID, strJsVmID, strCallbackParam);
}







rho::String js_s_ControlService_getDefaultID(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    id<IControlServiceFactory> factory = [ControlServiceFactorySingleton getControlServiceFactoryInstance];
    id<IControlServiceSingleton> singleton = [factory getControlServiceSingleton];

    NSString* defID = [singleton getDefaultID];

    rho::String res =  [[CJSConverter convertToJS:defID level:0] UTF8String];

    return res;
}

rho::String js_s_ControlService_getDefault(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    id<IControlServiceFactory> factory = [ControlServiceFactorySingleton getControlServiceFactoryInstance];
    id<IControlServiceSingleton> singleton = [factory getControlServiceSingleton];

    NSString* defID = [singleton getDefaultID];

    rho::String res =  [[CJSConverter convertToJS:[CRhoAPIClassInstance rubyClassByName:@"Rho.ControlService" instanceID:defID] level:0] UTF8String];

    return res;
}

rho::String js_s_ControlService_setDefaultID(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    id<IControlServiceFactory> factory = [ControlServiceFactorySingleton getControlServiceFactoryInstance];
    id<IControlServiceSingleton> singleton = [factory getControlServiceSingleton];

    [singleton setDefaultID:[NSString stringWithUTF8String:(strObjID.c_str())]];

    [[CJSConverter convertToJS:nil level:0] UTF8String];
}




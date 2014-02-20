
#import <Foundation/Foundation.h>

#import "api_generator/iphone/IMethodResult.h"


// hash keys used in properties and parameters


@protocol IControlService <NSObject>


-(void) startService:(NSString*)testDescription methodResult:(id<IMethodResult>)methodResult;

-(void) stopService:(id<IMethodResult>)methodResult;


// NOTE: if you want to hold methodResult(for example periodically call callbacks) you should release it manually when you stop using it!
@end


@protocol IControlServiceSingleton <NSObject>


-(NSString*) getDefaultID;
-(void) setDefaultID:(NSString*)defaultID;
-(NSString*)getInitialDefaultID;
    



@end


@protocol IControlServiceFactory <NSObject>
-(id<IControlServiceSingleton>) getControlServiceSingleton;
-(id<IControlService>) getControlServiceByID:(NSString*)ID;
-(void) destroyObjectByID:(NSString*)ID;
@end


@interface ControlServiceFactorySingleton : NSObject {
}
+(id<IControlServiceFactory>) getControlServiceFactoryInstance;
@end



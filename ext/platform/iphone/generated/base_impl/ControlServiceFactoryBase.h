
#import "IControlService.h"

@interface ControlServiceFactoryBase : NSObject<IControlServiceFactory> {
    NSMutableDictionary* mControlServiceInstances;
    id<IControlServiceSingleton> mControlServiceSingleton;
}

-(id)init;

-(id<IControlServiceSingleton>) getControlServiceSingleton;
-(id<IControlService>) getControlServiceByID:(NSString*)ID;

-(void) destroyObjectByID:(NSString*)ID;

-(id<IControlService>)createControlServiceByID:(NSString*)ID;

-(void)dealloc;

@end
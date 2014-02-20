
#import "ControlServiceFactoryBase.h"
#import "ControlService.h"
#import "ControlServiceSingleton.h"



@implementation ControlServiceFactoryBase

-(id)init {
    self = [super init];
    mControlServiceInstances = [[NSMutableDictionary dictionaryWithCapacity:4] retain];
    mControlServiceSingleton = nil;
    return self;
}

-(id<IControlService>) getControlServiceByID:(NSString*)ID {
    ControlService* obj = (ControlService*)[mControlServiceInstances objectForKey:ID];
    if (obj == nil) {
        obj = [self createControlServiceByID:ID];
        [mControlServiceInstances setObject:obj forKey:ID];
    }
    return obj;
}

-(void) destroyObjectByID:(NSString*)ID {
    ControlService* obj = [mControlServiceInstances objectForKey:ID];
    if (obj != nil) {
        [mControlServiceInstances removeObjectForKey:ID];
    }
}


-(id<IControlService>)createControlServiceByID:(NSString*)ID {
    ControlService* obj = [[ControlService alloc] init];

    return obj;
}


-(id<IControlServiceSingleton>) getControlServiceSingleton {
    if (mControlServiceSingleton == nil) {
        mControlServiceSingleton = [[ControlServiceSingleton alloc] init];
    }
    return mControlServiceSingleton;
}

-(void)dealloc {
    [mControlServiceInstances release];
    [super dealloc];
}


@end
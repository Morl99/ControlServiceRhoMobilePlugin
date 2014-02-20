
#import "IControlService.h"
#import "ControlServiceFactoryBase.h"

static ControlServiceFactoryBase* ourControlServiceFactory = nil;

@implementation ControlServiceFactorySingleton

+(id<IControlServiceFactory>) getControlServiceFactoryInstance {
    if (ourControlServiceFactory == nil) {
        ourControlServiceFactory = [[ControlServiceFactoryBase alloc] init];
    }
    return ourControlServiceFactory;
}

@end
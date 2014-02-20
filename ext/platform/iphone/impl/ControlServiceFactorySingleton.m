
#import "IcontrolService.h"
#import "controlServiceFactoryBase.h"

static controlServiceFactoryBase* ourcontrolServiceFactory = nil;

@implementation controlServiceFactorySingleton

+(id<IcontrolServiceFactory>) getcontrolServiceFactoryInstance {
    if (ourcontrolServiceFactory == nil) {
        ourcontrolServiceFactory = [[controlServiceFactoryBase alloc] init];
    }
    return ourcontrolServiceFactory;
}

@end
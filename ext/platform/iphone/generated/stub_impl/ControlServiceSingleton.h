
#import "IControlService.h"
#import "ControlServiceSingletonBase.h"

@interface ControlServiceSingleton : ControlServiceSingletonBase<IControlServiceSingleton> {
}


-(NSString*)getInitialDefaultID;






@end
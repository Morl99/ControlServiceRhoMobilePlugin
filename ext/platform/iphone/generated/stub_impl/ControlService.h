
#import "IControlService.h"
#import "ControlServiceBase.h"

@interface ControlService : ControlServiceBase<IControlService> {
}

-(void) startService:(NSString*)testDescription methodResult:(id<IMethodResult>)methodResult;
-(void) stopService:(id<IMethodResult>)methodResult;



@end
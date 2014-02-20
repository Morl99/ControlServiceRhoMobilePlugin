
#import "IcontrolService.h"
#import "controlServiceBase.h"

@interface controlService : controlServiceBase<IcontrolService> {
}

-(void) getPlatformName:(id<IMethodResult>)methodResult;
-(void) calcSumm:(int)a b:(int)b methodResult:(id<IMethodResult>)methodResult;
-(void) joinStrings:(NSString*)a b:(NSString*)b methodResult:(id<IMethodResult>)methodResult;



@end

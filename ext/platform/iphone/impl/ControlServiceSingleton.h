
#import "IcontrolService.h"
#import "controlServiceSingletonBase.h"

@interface controlServiceSingleton : controlServiceSingletonBase<IcontrolServiceSingleton> {
}


-(NSString*)getInitialDefaultID;


-(void) enumerate:(id<IMethodResult>)methodResult;




@end
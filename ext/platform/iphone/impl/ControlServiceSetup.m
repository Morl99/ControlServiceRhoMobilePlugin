#import <Foundation/Foundation.h>
#include "common/app_build_capabilities.h"

extern void Init_controlService_API();

void Init_controlService_extension()
{
    Init_controlService_API();
}
// ControlServiceRuntime.cpp
#include "ControlServiceRuntime.h"
#include "ControlServiceFactory.h"

using namespace Platform;
using namespace rho::apiGenerator;

using namespace rho;

namespace rhoruntime
{

ControlServiceRuntimeComponent::ControlServiceRuntimeComponent(IControlServiceImpl^ impl):
    _impl(impl)
{
    // TODO: implement runtime component constructor
}

ControlServiceSingletonComponent::ControlServiceSingletonComponent(IControlServiceSingletonImpl^ impl):
    _impl(impl)
{
    // TODO: implement singleton component constructor
}

void ControlServiceRuntimeComponent::startService(Platform::String^ testDescription, IMethodResult^ oResult)
{
    _impl->startService(testDescription, oResult);
}

void ControlServiceRuntimeComponent::stopService(IMethodResult^ oResult)
{
    _impl->stopService(oResult);
}

void ControlServiceFactoryComponent::setImpl(IControlServiceFactoryImpl^ impl)
{
    CControlServiceFactory::setImpl(impl);
}

}
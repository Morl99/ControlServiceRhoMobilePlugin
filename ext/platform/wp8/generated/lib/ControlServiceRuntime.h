#pragma once

#include "../../../../shared/generated/cpp/IControlService.h"
#include "api_generator/wp8/IMethodResult.h"

namespace rhoruntime
{
    public interface class IControlServiceImpl
    {
    public:
        void startService(Platform::String^ testDescription, IMethodResult^ oResult);
        void stopService(IMethodResult^ oResult);
    };

    public interface class IControlServiceSingletonImpl
    {
    };
    public interface class IControlServiceFactoryImpl
    {
    public:
        IControlServiceImpl^ getImpl();
        IControlServiceSingletonImpl^ getSingletonImpl();
    };

    public ref class ControlServiceRuntimeComponent sealed: public IControlServiceImpl
    {
    public:
        ControlServiceRuntimeComponent(IControlServiceImpl^ impl);
        virtual void startService(Platform::String^ testDescription, IMethodResult^ oResult);
        virtual void stopService(IMethodResult^ oResult);
    private:
        IControlServiceImpl^ _impl;
    };

    public ref class ControlServiceSingletonComponent sealed: public IControlServiceSingletonImpl
    {
    public:
        ControlServiceSingletonComponent(IControlServiceSingletonImpl^ impl);
    private:
        IControlServiceSingletonImpl^ _impl;
    };

    public ref class ControlServiceFactoryComponent sealed
    {
    public:
        static void setImpl(IControlServiceFactoryImpl^ impl);
    };
}

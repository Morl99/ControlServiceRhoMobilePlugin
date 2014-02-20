using System;
using System.Collections.Generic;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Shapes;
using rhoruntime;

namespace rho {

namespace ControlServiceImpl
{
    public class ControlService : IControlServiceImpl
    {
        public ControlService()
        {
            ControlServiceRuntimeComponent _runtime = new ControlServiceRuntimeComponent(this);
        }

        public void startService(string testDescription, IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public void stopService(IMethodResult oResult)
        {
            // implement this method in C# here
        }
    }

    public class ControlServiceSingleton : IControlServiceSingletonImpl
    {
        public ControlServiceSingleton()
        {
            ControlServiceSingletonComponent _runtime = new ControlServiceSingletonComponent(this);
        }
    }

    public class ControlServiceFactory : IControlServiceFactoryImpl
    {
        public IControlServiceImpl getImpl() {
            return new ControlService();
        }
        public IControlServiceSingletonImpl getSingletonImpl() {
            return new ControlServiceSingleton();
        }
    }
}

}

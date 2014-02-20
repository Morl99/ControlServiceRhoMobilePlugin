package com.rho.controlservice;

import com.rhomobile.rhodes.api.IRhoApiFactory;
import com.rhomobile.rhodes.api.IRhoApiSingletonFactory;

public interface IControlServiceFactory
    extends IRhoApiFactory<IControlService>,
            IRhoApiSingletonFactory<IControlServiceSingleton> {

    @Override
    IControlServiceSingleton getApiSingleton();

    @Override
    IControlService getApiObject(String id);

}

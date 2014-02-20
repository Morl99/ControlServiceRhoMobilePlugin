package com.rho.controlservice;

import com.rhomobile.rhodes.api.RhoApiFactory;

public class ControlServiceFactory
        extends RhoApiFactory< ControlService, ControlServiceSingleton>
        implements IControlServiceFactory {

    @Override
    protected ControlServiceSingleton createSingleton() {
        return new ControlServiceSingleton(this);
    }

    @Override
    protected ControlService createApiObject(String id) {
        return new ControlService(id);
    }
}

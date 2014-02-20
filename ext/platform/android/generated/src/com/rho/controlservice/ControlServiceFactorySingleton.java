package com.rho.controlservice;

public class ControlServiceFactorySingleton {
    private static IControlServiceFactory mFactory;
    public static void setInstance(IControlServiceFactory factory) {
        mFactory = factory;
    }
    public static IControlServiceFactory getInstance() {
        return mFactory;
    }
}

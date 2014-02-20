package com.rho.controlservice;

import java.util.List;
import java.util.Map;

import com.rhomobile.rhodes.api.IMethodResult;

import com.rhomobile.rhodes.api.RhoApiDefaultId;

public abstract class ControlServiceSingletonBase 
    extends RhoApiDefaultId<IControlService, IControlServiceFactory>  {

    public ControlServiceSingletonBase(IControlServiceFactory factory) {
        super(factory);
    } 

    
}

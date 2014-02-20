package com.rho.controlservice;

import java.util.LinkedList;
import java.util.List;

import com.rhomobile.rhodes.api.IMethodResult;

class ControlServiceSingleton extends ControlServiceSingletonBase implements IControlServiceSingleton {
    public ControlServiceSingleton(ControlServiceFactory factory) {
        super(factory);
    }

    List<Object> getIDs() {
        List<Object> ids = new LinkedList<Object>();
        ids.add("SCN1");
        ids.add("SCN2");
        return ids;
    }
    
    @Override
    protected String getInitialDefaultID() {
        return (String)(getIDs().get(0));
    }

}
package com.rho.controlservice;



import java.util.Map;
import java.util.List;

import com.rhomobile.rhodes.api.IMethodResult;
import com.rhomobile.rhodes.api.IRhoApiObject;


public interface IControlService extends IRhoApiObject {

    void startService(String testDescription, IMethodResult result);
    void stopService(IMethodResult result);
};

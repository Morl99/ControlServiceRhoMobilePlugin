package com.rho.controlservice;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import com.rhomobile.rhodes.api.IMethodResult;
import com.rhomobile.rhodes.api.RhoApiObject;


public class ControlServiceBase extends RhoApiObject {

    public ControlServiceBase(String id) {
        super(id);

    }


    public static class startServiceTask implements Runnable {
        private IControlService mApiObject; 
        private String testDescription;
        private IMethodResult mResult;

        public startServiceTask(IControlService obj, 
                String testDescription, 
                IMethodResult result) {
            this.mApiObject = obj; 
            this.testDescription = testDescription;
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiObject.startService(
                testDescription, mResult);
        }
    }


    public static class stopServiceTask implements Runnable {
        private IControlService mApiObject; 
        private IMethodResult mResult;

        public stopServiceTask(IControlService obj, 
                IMethodResult result) {
            this.mApiObject = obj; 
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiObject.stopService(mResult);
        }
    }

}

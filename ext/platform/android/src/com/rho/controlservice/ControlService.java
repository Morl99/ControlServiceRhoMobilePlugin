package com.rho.controlservice;

import java.util.Map;
import android.content.Intent;
import com.rhomobile.rhodes.RhodesActivity;

import com.rhomobile.rhodes.api.IMethodResult;
import com.rhomobile.rhodes.api.MethodResult;

public class ControlService extends ControlServiceBase implements IControlService {
	 private static final String POWER_TUTOR_SERVICE = "edu.umich.PowerTutor.service.UMLoggerService";
	 private Intent serviceIntent = null;
    public ControlService(String id) {
    	super(id);
    	serviceIntent = new Intent();
        serviceIntent.setAction(POWER_TUTOR_SERVICE);
    }


    @Override
    public void startService(String testDescription, IMethodResult result) {
    	RhodesActivity ra = RhodesActivity.safeGetInstance();
    	serviceIntent.putExtra("testDescription", "RhoMobile_" + testDescription);
        ra.startService(serviceIntent);
    }
    
    @Override
    public void stopService(IMethodResult result) {
    	RhodesActivity ra = RhodesActivity.safeGetInstance();
    	ra.stopService(serviceIntent);
    }


 


}
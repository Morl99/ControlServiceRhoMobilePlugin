
(function ($, rho, rhoUtil) {
    'use strict';

    var moduleNS = 'Rho.ControlService';
    var apiReq = rhoUtil.apiReqFor(moduleNS);
    var currentDefaultID = null;

    // === ControlService class definition ===

    function ControlService() {
        var id = null;
        this.getId = function () {return id;};

        if (1 == arguments.length && arguments[0][rhoUtil.rhoIdParam()]) {
            if (moduleNS != arguments[0][rhoUtil.rhoClassParam()]) {
                throw "Wrong class instantiation!";
            }
            id = arguments[0][rhoUtil.rhoIdParam()];
        } else {
            id = rhoUtil.nextId();
            // constructor methods are following:
            
        }
    };

    ControlService.getId = function() { return currentDefaultID; }

    // === ControlService instance properties ===

    rhoUtil.createPropsProxy(ControlService.prototype, [
    ], apiReq, function(){ return this.getId(); });

    // === ControlService instance methods ===

    rhoUtil.createMethodsProxy(ControlService.prototype, [
    
          // function(/* const rho::String& */ testDescription, /* optional function */ oResult)
          { methodName: 'startService', nativeName: 'startService', valueCallbackIndex: 1 }
    
          // function(/* optional function */ oResult)
        , { methodName: 'stopService', nativeName: 'stopService', valueCallbackIndex: 0 }
    
    ], apiReq, function(){ return this.getId(); });

    // === ControlService constants ===

    



    // === ControlService static properties ===

    rhoUtil.createPropsProxy(ControlService, [
    ], apiReq);

    // === ControlService static methods ===

    rhoUtil.createMethodsProxy(ControlService, [
    
    ], apiReq);

    // === ControlService default instance support ===
    

        rhoUtil.createPropsProxy(ControlService, [
            { propName: 'defaultInstance:getDefault:setDefault', propAccess: 'rw', customSet: function(obj) { if(!obj || 'function' != typeof obj.getId){ throw 'Default object should provide getId method!' }; currentDefaultID = obj.getId(); } }
          , { propName: 'defaultID:getDefaultID:setDefaultID', propAccess: 'rw', customSet: function(id) { currentDefaultID = id; } }
        ], apiReq);

        ControlService.getId = function() {
            if (null == currentDefaultID) {
                currentDefaultID = ControlService.getDefaultID();
            }
            return currentDefaultID;
        }

        // === ControlService default instance properties ===

        rhoUtil.createPropsProxy(ControlService, [
        ], apiReq, function(){ return this.getId(); });

        // === ControlService default instance methods ===

        rhoUtil.createMethodsProxy(ControlService, [
        
              // function(/* const rho::String& */ testDescription, /* optional function */ oResult)
              { methodName: 'startService', nativeName: 'startService', valueCallbackIndex: 1 }
        
              // function(/* optional function */ oResult)
            , { methodName: 'stopService', nativeName: 'stopService', valueCallbackIndex: 0 }
        
        ], apiReq, function(){ return this.getId(); });

    

    rhoUtil.namespace(moduleNS, ControlService);

    



})(Rho.jQuery, Rho, Rho.util);

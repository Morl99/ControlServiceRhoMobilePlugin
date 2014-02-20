#include "ControlServiceBase.h"
#include "common/RhodesApp.h"


namespace rho {

IMPLEMENT_LOGCLASS(CControlServiceSingletonBase, "ControlService");
IMPLEMENT_LOGCLASS(CControlServiceBase, "ControlService");

rho::common::CAutoPtr< CControlServiceFactoryBase> CControlServiceFactoryBase::m_pInstance;



///////////////////////////////////////
//string constants definiton 

////////////////////////////////////////////////

CControlServiceBase::CControlServiceBase()
{

}
CControlServiceSingletonBase::CControlServiceSingletonBase()
{
    RHODESAPP().getExtManager().registerExtension( "ControlService", this );
}

CControlServiceSingletonBase::~CControlServiceSingletonBase()
{
    CControlServiceFactoryBase::setInstance(0);
}


}

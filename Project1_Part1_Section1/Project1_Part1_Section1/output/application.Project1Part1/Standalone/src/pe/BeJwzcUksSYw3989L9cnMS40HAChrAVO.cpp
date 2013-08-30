// eJxjdCwtyWdkNGJ0SSxJZPTPS_1XJzEsFADoSAX1


#include "BeJwzcUksSYw3989L9cnMS40HAChrAVO.h"
#include <dst-config.h>
#include <SPL/Runtime/Utility/BackoffSpinner.h>


using namespace SPL;

extern int PE_Version;

#define MYPE BeJwzcUksSYw3989L9cnMS40HAChrAVO



MYPE::MYPE(bool isStandalone/*=false*/) 
    : SPL::PE(isStandalone, NULL)
{
   PE_Version = 3100;
   BackoffSpinner::setYieldBehaviour(BackoffSpinner::Auto);
}



MAKE_PE(SPL::MYPE);


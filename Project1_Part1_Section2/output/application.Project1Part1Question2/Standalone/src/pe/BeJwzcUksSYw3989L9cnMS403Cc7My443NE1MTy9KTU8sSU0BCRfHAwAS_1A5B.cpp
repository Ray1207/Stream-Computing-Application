// eJxjdCwtyWdkNGF0SSxJZPTPS_1XJzEtlDM7My2ZMTE8vSk1PLElNAYkVAwAEzw2U


#include "BeJwzcUksSYw3989L9cnMS403Cc7My443NE1MTy9KTU8sSU0BCRfHAwAS_1A5B.h"
#include <dst-config.h>
#include <SPL/Runtime/Utility/BackoffSpinner.h>


using namespace SPL;

extern int PE_Version;

#define MYPE BeJwzcUksSYw3989L9cnMS403Cc7My443NE1MTy9KTU8sSU0BCRfHAwAS_1A5B



MYPE::MYPE(bool isStandalone/*=false*/) 
    : SPL::PE(isStandalone, NULL)
{
   PE_Version = 3100;
   BackoffSpinner::setYieldBehaviour(BackoffSpinner::Auto);
}



MAKE_PE(SPL::MYPE);


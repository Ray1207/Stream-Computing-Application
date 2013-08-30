// eJxjdCwtyWdkNGV0SSxJZPTPS_1XJzEtlDM7MywYThoyJ6elFqemJJakpIJliAFRQA9c


#include "BeJwzcUksSYw3989L9cnMS403Cc7My443BZGG8YamienpRanpiSWpKSDZ4ngAerYQCb.h"
#include <dst-config.h>
#include <SPL/Runtime/Utility/BackoffSpinner.h>


using namespace SPL;

extern int PE_Version;

#define MYPE BeJwzcUksSYw3989L9cnMS403Cc7My443BZGG8YamienpRanpiSWpKSDZ4ngAerYQCb



MYPE::MYPE(bool isStandalone/*=false*/) 
    : SPL::PE(isStandalone, NULL)
{
   PE_Version = 3100;
   BackoffSpinner::setYieldBehaviour(BackoffSpinner::Auto);
}



MAKE_PE(SPL::MYPE);


// eJxjdCwtyWdkNGZ0zi_1NK0ktYnRJLElk9M9L9cnMSwUAeR0IDX


#include "BeJwzd84vzStJLYo3cUksSYw3989L9cnMS40HAGyUAjE.h"
#include <dst-config.h>
#include <SPL/Runtime/Utility/BackoffSpinner.h>


using namespace SPL;

extern int PE_Version;

#define MYPE BeJwzd84vzStJLYo3cUksSYw3989L9cnMS40HAGyUAjE



MYPE::MYPE(bool isStandalone/*=false*/) 
    : SPL::PE(isStandalone, NULL)
{
   PE_Version = 3100;
   BackoffSpinner::setYieldBehaviour(BackoffSpinner::Auto);
}



MAKE_PE(SPL::MYPE);


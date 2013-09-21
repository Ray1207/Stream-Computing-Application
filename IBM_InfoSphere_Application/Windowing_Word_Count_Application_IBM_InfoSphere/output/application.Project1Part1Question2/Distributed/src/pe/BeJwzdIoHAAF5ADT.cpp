// eJxjdCwtyWdkNGR0AgAMqwIR


#include "BeJwzdIoHAAF5ADT.h"
#include <dst-config.h>
#include <SPL/Runtime/Utility/BackoffSpinner.h>


using namespace SPL;

extern int PE_Version;

#define MYPE BeJwzdIoHAAF5ADT



MYPE::MYPE(bool isStandalone/*=false*/) 
    : SPL::PE(isStandalone, NULL)
{
   PE_Version = 3100;
   BackoffSpinner::setYieldBehaviour(BackoffSpinner::Auto);
}



MAKE_PE(SPL::MYPE);


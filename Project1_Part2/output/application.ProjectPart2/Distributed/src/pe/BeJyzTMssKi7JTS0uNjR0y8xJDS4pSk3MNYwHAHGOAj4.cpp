// eJxjdCwtyWdkNGRMyywqLslNLS62snLLzEkNLilKTcw1BACWpQpA


#include "BeJyzTMssKi7JTS0uNjR0y8xJDS4pSk3MNYwHAHGOAj4.h"
#include <dst-config.h>
#include <SPL/Runtime/Utility/BackoffSpinner.h>


using namespace SPL;

extern int PE_Version;

#define MYPE BeJyzTMssKi7JTS0uNjR0y8xJDS4pSk3MNYwHAHGOAj4



MYPE::MYPE(bool isStandalone/*=false*/) 
    : SPL::PE(isStandalone, NULL)
{
   PE_Version = 3100;
   BackoffSpinner::setYieldBehaviour(BackoffSpinner::Auto);
}



MAKE_PE(SPL::MYPE);


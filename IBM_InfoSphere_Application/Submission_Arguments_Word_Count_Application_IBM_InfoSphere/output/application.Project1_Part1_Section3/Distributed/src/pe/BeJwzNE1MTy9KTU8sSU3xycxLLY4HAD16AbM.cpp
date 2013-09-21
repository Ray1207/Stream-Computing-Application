// eJxjdCwtyWdkNGRMTE8vSk1PLElN8cnMSy0GAFXHAfV


#include "BeJwzNE1MTy9KTU8sSU3xycxLLY4HAD16AbM.h"
#include <dst-config.h>
#include <SPL/Runtime/Utility/BackoffSpinner.h>


using namespace SPL;

extern int PE_Version;

#define MYPE BeJwzNE1MTy9KTU8sSU3xycxLLY4HAD16AbM



MYPE::MYPE(bool isStandalone/*=false*/) 
    : SPL::PE(isStandalone, NULL)
{
   PE_Version = 3100;
   BackoffSpinner::setYieldBehaviour(BackoffSpinner::Auto);
}



MAKE_PE(SPL::MYPE);


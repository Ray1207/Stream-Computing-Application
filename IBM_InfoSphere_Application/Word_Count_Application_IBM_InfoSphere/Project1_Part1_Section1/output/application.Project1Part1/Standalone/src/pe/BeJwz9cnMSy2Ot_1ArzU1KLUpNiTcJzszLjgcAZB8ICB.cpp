// eJxjdCwtyWdkNGb0ycxLLWb0K81NSi1KTWEMzszLBgBwkAiV


#include "BeJwz9cnMSy2Ot_1ArzU1KLUpNiTcJzszLjgcAZB8ICB.h"
#include <dst-config.h>
#include <SPL/Runtime/Utility/BackoffSpinner.h>


using namespace SPL;

extern int PE_Version;

#define MYPE BeJwz9cnMSy2Ot_1ArzU1KLUpNiTcJzszLjgcAZB8ICB



MYPE::MYPE(bool isStandalone/*=false*/) 
    : SPL::PE(isStandalone, NULL)
{
   PE_Version = 3100;
   BackoffSpinner::setYieldBehaviour(BackoffSpinner::Auto);
}



MAKE_PE(SPL::MYPE);


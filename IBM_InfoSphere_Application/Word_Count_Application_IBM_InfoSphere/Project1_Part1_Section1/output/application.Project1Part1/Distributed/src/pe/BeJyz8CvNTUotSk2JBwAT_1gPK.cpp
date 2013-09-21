// eJxjdCwtyWdkNGT0K81NSi1KTQEAJ0UFAB


#include "BeJyz8CvNTUotSk2JBwAT_1gPK.h"
#include <dst-config.h>
#include <SPL/Runtime/Utility/BackoffSpinner.h>


using namespace SPL;

extern int PE_Version;

#define MYPE BeJyz8CvNTUotSk2JBwAT_1gPK



MYPE::MYPE(bool isStandalone/*=false*/) 
    : SPL::PE(isStandalone, NULL)
{
   PE_Version = 3100;
   BackoffSpinner::setYieldBehaviour(BackoffSpinner::Auto);
}



MAKE_PE(SPL::MYPE);


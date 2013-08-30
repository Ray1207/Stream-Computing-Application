// eJxjdCwtyWdkNGT0ys_1Mc8vMSQ0uKUpNzAUATC0HBL


#include "BeJwzNPHKz8xzy8xJDS4pSk3MjQcANK4GBB.h"
#include <dst-config.h>
#include <SPL/Runtime/Utility/BackoffSpinner.h>


using namespace SPL;

extern int PE_Version;

#define MYPE BeJwzNPHKz8xzy8xJDS4pSk3MjQcANK4GBB



MYPE::MYPE(bool isStandalone/*=false*/) 
    : SPL::PE(isStandalone, NULL)
{
   PE_Version = 3100;
   BackoffSpinner::setYieldBehaviour(BackoffSpinner::Auto);
}



MAKE_PE(SPL::MYPE);


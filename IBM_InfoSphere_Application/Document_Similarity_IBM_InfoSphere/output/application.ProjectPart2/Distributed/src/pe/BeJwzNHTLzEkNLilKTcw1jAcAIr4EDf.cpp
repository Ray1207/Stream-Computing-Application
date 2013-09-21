// eJxjdCwtyWdkNGR0y8xJDS4pSk3MNQQAN4gFDs


#include "BeJwzNHTLzEkNLilKTcw1jAcAIr4EDf.h"
#include <dst-config.h>
#include <SPL/Runtime/Utility/BackoffSpinner.h>


using namespace SPL;

extern int PE_Version;

#define MYPE BeJwzNHTLzEkNLilKTcw1jAcAIr4EDf



MYPE::MYPE(bool isStandalone/*=false*/) 
    : SPL::PE(isStandalone, NULL)
{
   PE_Version = 3100;
   BackoffSpinner::setYieldBehaviour(BackoffSpinner::Auto);
}



MAKE_PE(SPL::MYPE);


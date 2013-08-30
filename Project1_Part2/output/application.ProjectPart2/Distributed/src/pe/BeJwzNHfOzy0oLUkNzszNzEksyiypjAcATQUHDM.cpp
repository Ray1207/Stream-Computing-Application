// eJxjdCwtyWdkNGR0zs8tKC1JDc7MzcxJLMosqQQAZv4IDT


#include "BeJwzNHfOzy0oLUkNzszNzEksyiypjAcATQUHDM.h"
#include <dst-config.h>
#include <SPL/Runtime/Utility/BackoffSpinner.h>


using namespace SPL;

extern int PE_Version;

#define MYPE BeJwzNHfOzy0oLUkNzszNzEksyiypjAcATQUHDM



MYPE::MYPE(bool isStandalone/*=false*/) 
    : SPL::PE(isStandalone, NULL)
{
   PE_Version = 3100;
   BackoffSpinner::setYieldBehaviour(BackoffSpinner::Auto);
}



MAKE_PE(SPL::MYPE);


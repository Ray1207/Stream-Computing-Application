// eJxjdCwtyWdkNGN0zs8tKC1JDc7MzcxJLMosqWR0y8xJDS4pSk3MNWT0ys_1MQ_1AZ_1fNSfTLzUhmDM_1OyGRPT04tS0xNLUlNAYsUAfE8cC7


#include "BeJwzNHfOzy0oLUkNzszNzEksyiypjDc0dMvMSQ0uKUpNzDWMNzTxys_1MQ4jEm_1vnpfpk5qXGmwRn5mXHG5ompqcXpaYnlqSmgISL4wEhxR8d.h"
#include <dst-config.h>
#include <SPL/Runtime/Utility/BackoffSpinner.h>


using namespace SPL;

extern int PE_Version;

#define MYPE BeJwzNHfOzy0oLUkNzszNzEksyiypjDc0dMvMSQ0uKUpNzDWMNzTxys_1MQ4jEm_1vnpfpk5qXGmwRn5mXHG5ompqcXpaYnlqSmgISL4wEhxR8d



MYPE::MYPE(bool isStandalone/*=false*/) 
    : SPL::PE(isStandalone, NULL)
{
   PE_Version = 3100;
   BackoffSpinner::setYieldBehaviour(BackoffSpinner::Auto);
}



MAKE_PE(SPL::MYPE);


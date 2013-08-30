// eJxjdCwtyWdkNGV0TE8vSk1PLEkNzszNzEksyiypZHTOzy0oRRFxy8xJDS4pSk3MNWT0ys_1MS01BiDAGZ_0ZlAwBdwByA


#include "BeJwztHRMTy9KTU8sSQ3OzM3MSSzKLKmMNzR3zs8tKEUVM3TLzEkNLilKTcw1jDc088rPzEtNQYjFmwRn5mXHAwDcLh5U.h"
#include <dst-config.h>
#include <SPL/Runtime/Utility/BackoffSpinner.h>


using namespace SPL;

extern int PE_Version;

#define MYPE BeJwztHRMTy9KTU8sSQ3OzM3MSSzKLKmMNzR3zs8tKEUVM3TLzEkNLilKTcw1jDc088rPzEtNQYjFmwRn5mXHAwDcLh5U



MYPE::MYPE(bool isStandalone/*=false*/) 
    : SPL::PE(isStandalone, NULL)
{
   PE_Version = 3100;
   BackoffSpinner::setYieldBehaviour(BackoffSpinner::Auto);
}



MAKE_PE(SPL::MYPE);


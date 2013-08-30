// eJxjdCwtyWdkNGN0TE8vSk1PLEkNzszNzEksyiypZHTOzy0oRRFxSSxJZHTLzEkNLilKTcw1ZPTKz8xLTUGIMAZn5mUDAOaDB38


#include "BeJwztHRMTy9KTU8sSQ3OzM3MSSzKLKmMNzR3zs8tKEURM3FJLEmMNzR0y8xJDS4pSk3MNYw3NPPKz8xLTUGIxZsEZ_0ZlxwMAlFcgBh.h"
#include <dst-config.h>
#include <SPL/Runtime/Utility/BackoffSpinner.h>


using namespace SPL;

extern int PE_Version;

#define MYPE BeJwztHRMTy9KTU8sSQ3OzM3MSSzKLKmMNzR3zs8tKEURM3FJLEmMNzR0y8xJDS4pSk3MNYw3NPPKz8xLTUGIxZsEZ_0ZlxwMAlFcgBh



MYPE::MYPE(bool isStandalone/*=false*/) 
    : SPL::PE(isStandalone, NULL)
{
   PE_Version = 3100;
   BackoffSpinner::setYieldBehaviour(BackoffSpinner::Auto);
}



MAKE_PE(SPL::MYPE);


// eJxNyDEKgDAMBVD_0kZycRXAQ0aEnCBhKsGkkpoO3FyfdHg9DCwN6jKZnC06iUsglbkxSOIUzaff3aq5UMJvUb7FVXqQyktQDlLNzpuD9vesBv08jBD


#include "BeJxNyDEKgDAMAMA3BZQ_0QHAQ0aEPCAFDCTapxDj4e3HS8Q7S0PS4grOoVHKJGwFGqZzDmRQQ0k9Lc6WK0E1N7HtMq_1EsxthlsR2hp1KcCwVvb5_14ANT2CZq.h"
#include <dst-config.h>
#include <SPL/Runtime/Utility/BackoffSpinner.h>


using namespace SPL;

extern int PE_Version;

#define MYPE BeJxNyDEKgDAMAMA3BZQ_0QHAQ0aEPCAFDCTapxDj4e3HS8Q7S0PS4grOoVHKJGwFGqZzDmRQQ0k9Lc6WK0E1N7HtMq_1EsxthlsR2hp1KcCwVvb5_14ANT2CZq



MYPE::MYPE(bool isStandalone/*=false*/) 
    : SPL::PE(isStandalone, NULL)
{
   PE_Version = 3100;
   BackoffSpinner::setYieldBehaviour(BackoffSpinner::Auto);
}



MAKE_PE(SPL::MYPE);


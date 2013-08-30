#include "SPL/Runtime/Function/SPLFunctions.h"
#include "./accumulateValues.h"
namespace application { 
void accumulateValues (SPL::BeJwrMc40zcnMSy3ONC3PL0oBUskZiUXFAGflAjd& x, const SPL::BeJwrMc40zcnMSy3ONC3PL0oBUskZiUXFAGflAjd& y)
{
    x.get_lines() += y.get_lines();
    x.get_words() += y.get_words();
    x.get_chars() += y.get_chars();
}
} 

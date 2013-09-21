#include "SPL/Runtime/Function/SPLFunctions.h"
#include "./init.h"
namespace application { 
SPL::boolean init (SPL::float64& AggregatedSimilarityScore)
{
    AggregatedSimilarityScore = SPL::float64(0.0);
    return false;
}
} 

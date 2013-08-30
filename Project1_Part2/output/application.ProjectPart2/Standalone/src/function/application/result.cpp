#include "SPL/Runtime/Function/SPLFunctions.h"
#include "./result.h"
namespace application { 
SPL::float64 result (SPL::float64& AggregatedSimilarityScore)
{
    return (AggregatedSimilarityScore / SPL::float64(100.0));
}
} 

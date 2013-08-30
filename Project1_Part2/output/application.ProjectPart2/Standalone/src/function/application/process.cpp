#include "SPL/Runtime/Function/SPLFunctions.h"
#include "./process.h"
namespace application { 
SPL::boolean process (SPL::float64& AggregatedSimilarityScore, const SPL::float64& Similarity)
{
    AggregatedSimilarityScore = (AggregatedSimilarityScore + Similarity);
    return false;
}
} 

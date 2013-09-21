#include "SPL/Runtime/Function/SPLFunctions.h"
#include "./ComputeSimilarityScore.h"
#include "../../function/application/FrequencyList.h"
namespace application { 
SPL::float64 ComputeSimilarityScore (const SPL::rstring& text1, const SPL::rstring& text2)
{
    const SPL::map<SPL::rstring, SPL::int32 > id$wordsStat1 = ::application::FrequencyList(text1);
    const SPL::map<SPL::rstring, SPL::int32 > id$wordsStat2 = ::application::FrequencyList(text2);
    SPL::float64 id$quadraticSum1 = SPL::float64(0.0);
    SPL::float64 id$quadraticSum2 = SPL::float64(0.0);
    SPL::float64 id$gScore = SPL::float64(0.0);
    {
        for (SPL::map<SPL::rstring, SPL::int32 >::const_iterator it$word1 = id$wordsStat1.begin(); it$word1 != id$wordsStat1.end(); it$word1++) {
            const SPL::rstring& id$word1 = it$word1->first;
            {
                const SPL::float64 id$Frequency1 = ::SPL::spl_cast<SPL::float64, SPL::int32 >::cast(id$wordsStat1.at(id$word1));
                const SPL::float64 id$quatraticValue = ::SPL::Functions::Math::pow(id$Frequency1, SPL::float64(2.0));
                id$quadraticSum1 = (id$quadraticSum1 + id$quatraticValue);
            }
        }
    }
    {
        for (SPL::map<SPL::rstring, SPL::int32 >::const_iterator it$word2 = id$wordsStat2.begin(); it$word2 != id$wordsStat2.end(); it$word2++) {
            const SPL::rstring& id$word2 = it$word2->first;
            {
                const SPL::float64 id$Frequency2 = ::SPL::spl_cast<SPL::float64, SPL::int32 >::cast(id$wordsStat2.at(id$word2));
                const SPL::float64 id$quatraticValue = ::SPL::Functions::Math::pow(id$Frequency2, SPL::float64(2.0));
                id$quadraticSum2 = (id$quadraticSum2 + id$quatraticValue);
            }
        }
    }
    {
        for (SPL::map<SPL::rstring, SPL::int32 >::const_iterator it$word1 = id$wordsStat1.begin(); it$word1 != id$wordsStat1.end(); it$word1++) {
            const SPL::rstring& id$word1 = it$word1->first;
            {
                if (::SPL::Functions::Collections::has(id$wordsStat2, id$word1)) 
                    {
                        const SPL::float64 id$g = ::SPL::spl_cast<SPL::float64, SPL::int32 >::cast(SPL::int32(id$wordsStat1.at(id$word1) * id$wordsStat2.at(id$word1)));
                        id$gScore = (id$gScore + id$g);
                    }
            }
        }
    }
    const SPL::float64 id$finalSim = (id$gScore / (::SPL::Functions::Math::pow(id$quadraticSum1, SPL::float64(0.5)) * ::SPL::Functions::Math::pow(id$quadraticSum2, SPL::float64(0.5))));
    return id$finalSim;
}
} 

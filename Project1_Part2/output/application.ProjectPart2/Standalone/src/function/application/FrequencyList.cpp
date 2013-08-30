#include "SPL/Runtime/Function/SPLFunctions.h"
#include "./FrequencyList.h"
namespace application { 
static inline SPL::map<SPL::rstring, SPL::int32 >& _litValue0() {
    static SPL::map<SPL::rstring, SPL::int32 > dummy;
    return dummy;
}

SPL::map<SPL::rstring, SPL::int32 > FrequencyList (const SPL::rstring& text)
{
    const SPL::list<SPL::rstring > id$words = ::SPL::Functions::String::tokenize(text, SPL::rstring(" \t\r"), (SPL::boolean)false);
    SPL::map<SPL::rstring, SPL::int32 > id$FrequentList = _litValue0();
    {
        for (SPL::list<SPL::rstring >::const_iterator it$word = id$words.begin(); it$word != id$words.end(); it$word++) {
            const SPL::rstring& id$word = *it$word;
            {
                if ((((id$word != SPL::rstring(" ")) && (id$word != SPL::rstring("\r"))) && (id$word != SPL::rstring("\t")))) 
                    {
                        if (::SPL::Functions::Collections::has(id$FrequentList, id$word)) 
                            {
                                const SPL::int32 id$frequency = id$FrequentList.at(id$word);
                                id$FrequentList[id$word] = SPL::int32(id$frequency + SPL::int32(1));
                            }
                        else
                            {
                                id$FrequentList[id$word] = SPL::int32(1);
                            }
                    }
            }
        }
    }
    return id$FrequentList;
}
} 

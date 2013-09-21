#include "SPL/Runtime/Function/SPLFunctions.h"
#include "./countWords.h"
namespace application { 
SPL::int32 countWords (const SPL::rstring& line)
{
    const SPL::list<SPL::rstring > id$words = ::SPL::Functions::String::tokenize(line, SPL::rstring(" \t"), (SPL::boolean)false);
    SPL::int32 id$count = SPL::int32(0);
    {
        for (SPL::list<SPL::rstring >::const_iterator it$word = id$words.begin(); it$word != id$words.end(); it$word++) {
            const SPL::rstring& id$word = *it$word;
            {
                if ((((id$word != SPL::rstring(" ")) && (id$word != SPL::rstring("\r"))) && (id$word != SPL::rstring("\t")))) 
                    {
                        id$count++;
                    }
            }
        }
    }
    return id$count;
}
} 

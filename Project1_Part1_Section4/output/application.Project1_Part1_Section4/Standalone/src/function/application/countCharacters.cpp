#include "SPL/Runtime/Function/SPLFunctions.h"
#include "./countCharacters.h"
namespace application { 
SPL::int32 countCharacters (const SPL::rstring& line)
{
    return ::SPL::Functions::String::length(line);
}
} 

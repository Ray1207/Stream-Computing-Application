// t1F20AggregatedSimilarity


#include "BeJwrMXQzMnBMTy9KTU8sSU0JzszNzEksyiypBABwrglg.h"
#include <sstream>

#define SELF BeJwrMXQzMnBMTy9KTU8sSU0JzszNzEksyiypBABwrglg

using namespace SPL;

std::auto_ptr<TupleMappings> SELF::mappings_(SELF::initMappings());

static void addMapping(TupleMappings & tm, TypeOffset & offset,
                       std::string const & name, uint32_t index)
{
    tm.nameToIndex_.insert(std::make_pair(name, index)); 
    tm.indexToName_.push_back(name);
    tm.indexToTypeOffset_.push_back(offset);    
}

static Tuple * initer() { return new SELF(); }

TupleMappings* SELF::initMappings()
{
    instantiators_.insert(std::make_pair("tuple<float64 AggregatedSimilarity>",&initer));
    TupleMappings * tm = new TupleMappings();
#define MY_OFFSETOF(member, base) \
    ((uintptr_t)&reinterpret_cast<Self*>(base)->member) - (uintptr_t)base
   
    // initialize the mappings 
    
    {
        std::string s("AggregatedSimilarity");
        TypeOffset t(MY_OFFSETOF(AggregatedSimilarity_, tm), 
                     Meta::Type::typeOf<SPL::float64 >(), 
                     &typeid(SPL::float64));
        addMapping(*tm, t, s, 0);
    }
    
    return tm;
}

void SELF::deserialize(std::istream & istr, bool withSuffix)
{
   std::string s;
   char c;

   istr >> c; if (!istr) { return; }
   if (c != '{') { istr.setstate(std::ios_base::failbit); return; }
   
   if (!readAttributeIdentifier(istr, s)) { return; }
   if (s != "AggregatedSimilarity") { istr.setstate(std::ios_base::failbit); return; }
   istr >> c; if (!istr) { return; }
   if (c != '=') { istr.setstate(std::ios_base::failbit); return; }
   if (withSuffix)
     SPL::deserializeWithSuffix(istr, AggregatedSimilarity_);
   else
     istr >> AggregatedSimilarity_;
   if (!istr) { return; }  
   istr >> c; if (!istr) { return; }
   
   if (c != '}') { istr.setstate(std::ios_base::failbit); return; }
}

void SELF::deserializeWithNanAndInfs(std::istream & istr, bool withSuffix)
{
   std::string s;
   char c;

   istr >> c; if (!istr) { return; }
   if (c != '{') { istr.setstate(std::ios_base::failbit); return; }
   
   if (!readAttributeIdentifier(istr, s)) { return; }
   if (s != "AggregatedSimilarity") { istr.setstate(std::ios_base::failbit); return; }
   istr >> c; if (!istr) { return; }
   if (c != '=') { istr.setstate(std::ios_base::failbit); return; }
   SPL::deserializeWithNanAndInfs(istr, AggregatedSimilarity_, withSuffix);
   if (!istr) { return; }  
   istr >> c; if (!istr) { return; }
   
   if (c != '}') { istr.setstate(std::ios_base::failbit); return; }
}

void SELF::serialize(std::ostream & ostr) const
{
    ostr << '{'
         << "AggregatedSimilarity=" << get_AggregatedSimilarity()  
         << '}';
}

void SELF::serializeWithPrecision(std::ostream & ostr) const
{
    ostr << '{';
    SPL::serializeWithPrecision(ostr << "AggregatedSimilarity=", get_AggregatedSimilarity()) ;
    ostr << '}';
}

SELF& SELF::clear()
{
    get_AggregatedSimilarity() = 0;

    return *this;
}

void SELF::normalizeBoundedSetsAndMaps()
{
    SPL::normalizeBoundedSetsAndMaps(*this);
}



// eJylU91P2zAQl1_17V0SIh0SDfDQ8TB5Maqt1AiUlU9YJ8VJZjtuaOrZlO6CA9r_1PcdOCqj4AuyjR_0Xz3u4_1fRUsWNoYyaloIJ402ogaxe1JwEobRsuHYUMEjJCWjGG11jJu6YciQP4g1RIfrE_0dsWkmiMbl5Ujm_0iJ8xz8s2vZ1N0iKLxXiuN_1d0fjcd_1Vyy0UN1GNSq2bVIZyNVPP94vMkWSTXLcnmb_1b6Oq_1wxL7_02YzyabMhKDbvQBGhjCzjVTQ3KIoPwvXkBuAC23dN4G6a0UZSvgLMlR2zDI7b0oylBtBY1iSwGQbVGVU15VG4PpWkqKqInoTZaIkyiQokHgk1SIGWSX3a83cyHUYUMAlxwYrlJ7EulUPsu3l0JBcqxC_0EbQu3hgFF_1P9wzr08UfBsAuvR8f5fwA4T5sluj8yTwrq68T8RDOKUcsRypDVFB4A08Ky_1u2wmEDnPa76qGcL5baWlJM6WjLuO_0k95bS7bASJvLt_1SebauzMenQ_0w5h5_1A6i3BFzIJRbudji_1jiufXolP_0EtNxXHeQOM_1kU5qvpAB6vkbLwFvN4J_1u8cWBJ7gb6d2B_1f3cNHCBwFfa6g_0v1_0B_1Mi1nZ


#include "./Counter.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>


#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR Counter_Base
#define MY_OPERATOR Counter$OP



static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("Counter",&initer));
    return true;
}

template<class T> static void initRTC (SPL::Operator& o, T& v, const char * n) {
    SPL::ValueHandle vh = v;
    o.getContext().getRuntimeConstantValue(vh, n);
}

MY_BASE_OPERATOR::MY_BASE_OPERATOR()
 : Operator() {
    PE & pe = PE::instance();
    uint32_t index = getIndex();
    initRTC(*this, lit$0, "lit$0");
    initRTC(*this, lit$1, "lit$1");
    initRTC(*this, lit$2, "lit$2");
    initRTC(*this, lit$3, "lit$3");
    state$sum = lit$3;
    (void) getParameters(); // ensure thread safety by initializing here
}
MY_BASE_OPERATOR::~MY_BASE_OPERATOR()
{
    for (ParameterMapType::const_iterator it = paramValues_.begin(); it != paramValues_.end(); it++) {
        const ParameterValueListType& pvl = it->second;
        for (ParameterValueListType::const_iterator it2 = pvl.begin(); it2 != pvl.end(); it2++) {
            delete *it2;
        }
    }
}

void MY_BASE_OPERATOR::tupleLogic(Tuple const & tuple, uint32_t port) {
    IPort0Type const & iport$0 = static_cast<IPort0Type const  &>(tuple);
    AutoPortMutex $apm($svMutex, *this);
    
::application::accumulateValues(state$sum, iport$0);

}


void MY_BASE_OPERATOR::processRaw(Tuple const & tuple, uint32_t port) {
    tupleLogic (tuple, port);
    static_cast<MY_OPERATOR_SCOPE::MY_OPERATOR*>(this)->MY_OPERATOR::process(tuple, port);
}


void MY_BASE_OPERATOR::punctLogic(Punctuation const & punct, uint32_t port) {
    AutoPortMutex $apm($svMutex, *this);
    
if ((SPL::BeJyrNIo3NArPzEvJL_1dNLMpOLTI0dMvMS8yBcACkegr2(punct-1) == SPL::BeJyrNIo3NArPzEvJL_1dNLMpOLTI0dMvMS8yBcACkegr2::FinalMarker)) 
    {
        ::SPL::Functions::Utility::printStringLn((((((::SPL::spl_cast<SPL::rstring, SPL::int32 >::cast(state$sum.get_lines()) + lit$2) + ::SPL::spl_cast<SPL::rstring, SPL::int32 >::cast(state$sum.get_words())) + lit$1) + ::SPL::spl_cast<SPL::rstring, SPL::int32 >::cast(SPL::int32(state$sum.get_chars() + state$sum.get_lines()))) + lit$0));
    }

}

void MY_BASE_OPERATOR::processRaw(Punctuation const & punct, uint32_t port) {
    punctLogic (punct, port);
    
    process(punct, port);
}






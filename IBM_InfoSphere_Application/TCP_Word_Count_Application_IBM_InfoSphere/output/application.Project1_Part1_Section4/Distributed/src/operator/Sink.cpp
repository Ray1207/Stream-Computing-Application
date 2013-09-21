// eJytUW1rwjAQJl_19FUX2wTJp68uHkYmgggOpLxjFsS8S0kyjbVKSdFrH_1vvS_0LIhYwxZQsLdcXfP89ypNPYyzWKmcwh7mdIiAYG9dVD2PF_1nKfW7dLCTQ7TbHzazUU72YUiaQUge3tCqj_1JpMpiSxWKKeT_0dbeMdWgw64z3p1HveunzdxBQeCB_0ivDEe9RqTMBDdudq_0sPlzv_1P0Gnc2UVEUgAYwlO4CgCYhhFJpyfgK2Fjth1j9Kgb8tUiob1yKE4WjhHEfHR2ks4gJfyfkVqWYUH8ixYYSXVtOsDQ_1MjYTvOlHWGPABaeGTc08lgp5YXTrRAAD0k73veSYA6Ht1s_04BVUQzs_07SI0SjayekFfsOWWrNF4SrHTru_0aqYz1T06g7bQiLhMqJsreieimpymLTEFdc68eMU1VxXefesRMsjH8FMBOOCoAzQu0mhK_1Qr2BkjaUBMwh_10XzhFLjuY_0mjBMyCL7lAZ2lMW0catqJ6tK2gk23x2iD4BHinAvf


#include "./Sink.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>


#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR Sink_Base
#define MY_OPERATOR Sink$OP



static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("Sink",&initer));
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
    
{
    ::SPL::Functions::Utility::printStringLn((((((::SPL::spl_cast<SPL::rstring, SPL::int32 >::cast(iport$0.get_resultSta().get_lines()) + lit$2) + ::SPL::spl_cast<SPL::rstring, SPL::int32 >::cast(iport$0.get_resultSta().get_words())) + lit$1) + ::SPL::spl_cast<SPL::rstring, SPL::int32 >::cast(SPL::int32(iport$0.get_resultSta().get_chars() + iport$0.get_resultSta().get_lines()))) + lit$0));
}

}


void MY_BASE_OPERATOR::processRaw(Tuple const & tuple, uint32_t port) {
    tupleLogic (tuple, port);
    static_cast<MY_OPERATOR_SCOPE::MY_OPERATOR*>(this)->MY_OPERATOR::process(tuple, port);
}


void MY_BASE_OPERATOR::punctLogic(Punctuation const & punct, uint32_t port) {
}

void MY_BASE_OPERATOR::processRaw(Punctuation const & punct, uint32_t port) {
    punctLogic (punct, port);
    
    process(punct, port);
}






// eJytUd9rwjAQJq_1_0FUX2YJm0te5hZCKo4ECqE6M49iIhzTTaJiVJp3Xsf18af2zIGEN2IXB33Hffd3cqS7xcs4TpAsJerrRIQWBfCKqe5_0sio36XDrZyiLa7_1Xo6KsguishdEJH7N7Tso2KSDiZkPp9g3s_0mm2SL5oPO0450wp63ql42McA94UNUNJ9GveY4CkR3pjYvbPbc7zy_0Jp11XIIC0ARG0k0A0DiCUCotGV8Cm2v8kAsvcsBfiZT6JqQ4VThOGffRIUA6j5nwt0JuVIYJ9cdSrCnRYyx16MdYY8AFp0ZCw3yWCXmWce0aAAPSrvS94hiD0Hbr55xoJriCcHY6QGbka2SHiHjN2rFaZcmCYKVb3wetOzYymGbotCEsC2pHyd6S6oWkKk9MQ1xzbZwwTlXNdZ1bx66tdP6VwKw1LglODI2rGL5Sv5KRFZaGzDD8ZeazpsB1HyofFWAOfK4FOs8S2jrIsIj6wbcDHX3L1wbBJxRAAfo


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






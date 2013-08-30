// eJyVkF1PwjAUhnNu_0RUL4YIFsw4wRosxYUYvEAxmkHhHmq2OytYu7VnIZvjv1iKIiRdyetXz8Z7zvKbMgwpFLrCm9L4yqAoI3etDOwgI1iUnEZ9s9ez1pZnJaLaob54Wy2sTL8NJY5rn5mFjalGX0Tja6izPgnXbzhpkyDuJqiRCPJ9SKiQOBwBDsKs64T6nDWohM3C5_1h_05wa9ZIGtVcGIbOCsMSwshSbz_1xFilQpGt0htTsoSTuVbvPMH_0as40DkjKkIFUkjuwEESp9PGMs_1BAgHb_0fLQ8G5Q6icdKJiiUNJQuD26WlgNjRzOVXRuO0usdZkyZrxJm8PaU_08L7IfbuKP1q6J6Y6ftWwFno_10_1pLLjjxm9_1fN8fOcyTC3q9UWvXAmvjOMs0z2whjUUhcqYtNrzliuHVJYSfsP7ADE


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
    state$count = lit$2;
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
    ::SPL::Functions::Utility::printStringLn((((lit$1 + ::SPL::spl_cast<SPL::rstring, SPL::int32 >::cast(state$count)) + lit$0) + ::SPL::spl_cast<SPL::rstring, SPL::BeJwrMXQzMnBMTy9KTU8sSU0JzszNzEksyiypBABwrglg >::cast(iport$0)));
    state$count++;
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






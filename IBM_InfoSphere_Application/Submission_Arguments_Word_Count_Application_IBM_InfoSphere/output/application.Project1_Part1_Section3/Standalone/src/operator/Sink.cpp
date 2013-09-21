// eJytUd9rwjAQJq_1_0FUX2YJm01e5hZCKo4ECqK0Zx7EVCmmm0TUqSTuvY_174Yf2zIGEOWkHB33N33fXcqT71Cs5TpEsJeobTIQGBvE1Q9z9dlTv0uHWzkEG22u9VkVJJtFJG7ICL3b2jRR_0U4G4zJbDbGvJ9P1ukGzQadpy3pNHvesnrZxBTuCB_0iMnwa9cI4CkR3qtYvbPrc7zy_0pp1Vsi8KQAgMpZsAoDiCUCotGV8AG2v8EGtexIC_1FBn1jUtxpnCSMe6jg4N0kTDhb4RcqxwT6sdSrCjRjXmMpfmRsZngoZ9gjQEXnBo2DfNYLuSZ0bUTAQxIO933imMOhLZbv_0AWVEE4Pe0iN0o0snoiXrPnmK3ydE6w0q3vmuuO9UxN2HTaEO4TakfK3oLquaSqSE1DXHOtnzJOVc11nVvHTnBv_1CuAmXCyBzghNK5C_0Ar9CkaWWBowg_1AXzWdOges_0VD4qwCz4nAt0kae0daBhK_0oH2wo62havDYJPdoALDe


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






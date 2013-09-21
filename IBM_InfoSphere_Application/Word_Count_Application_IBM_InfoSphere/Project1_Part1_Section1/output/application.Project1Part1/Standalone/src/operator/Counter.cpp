// eJylU01P4zAQla_19FRHikGjZOGk4IC_0s1FYUgZISKXS14lJZjtuaJrZlO6Cw2v_0_0jpsWVPUA7ESxxpOZNx9vomUVNoZVzLQITRptRA0i9yTgJAzhsuHEMMEhlrJiBG91Qpq6qbChv3DVUB2uT5yzaSWFY3r3ojJyHr0SnhVtcj_0bJHkaifFcbx7Z_1Pd0dLOsRk_1lYVCrZrcimY1U_1nr9fJcu4nKWZvI_0fbiNyuw5Ky7aMRlNNnSlhl1oDLSxBZzqpgZFniL00bwAnAPb7mm0DVPaKMZXwNniI7bhEVvy2ZQArkVNocWguNa4rBmHxfZSmKZkAr4ItdESEwpzJZ4oMfEix8qeBXUExLDEBgMuOLXkxPZlUqh9Gx8uhQHl6EXoHaP2ckCpv5_1umdcnCn4MAFt6vr9L_0AnGfNnt0fc48K6uvC_1EIzRlHFcZVhuqgsAbeFb_0uLMThBzmtF9WjdB8t9PSsmYKx13KfSe9t5bVgmBtLt_1ze7atzsYkQ_08nQp3D2yzCFTWLinE7H1vEN8_1tR6f8J6Qlv_0wgd5jxlzDfTAfwZI2VhbeYxzvZ540CS3I30L8D_0_1_07z8ABAldhrzu4Xo_1_0AeyrFoT


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






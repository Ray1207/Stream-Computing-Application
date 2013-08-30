// eJydUE9rwjAUJ9d9CpEdFKSpdYeRiVCFDqQ6ZxTHLhLSTKNpEpJ0tX76pVXH2GUwQuC9l7zfP6tFUDguuKsQmhTWqRyEzYlAOwigqzSDYzYtzQyXp_1NhNa_1oKU3pQ5jSx0_08S3C1zKdLutksiUz06ihKvJnGLycaR5Ng3_14N4hfPVM5wNXiZTwaLNFTjtT2_08_1VbEj9_1iPiQ1Us1P4B7lTNonWEktyTLuYT40mBXZFzBUpmj1YQyuDDqwKjrL4hx_1deCWceVjGBGHAFSSebh_0v5yrYy7DwFepAj91xTgwDQCEWpwkkLSms4itL4FqQ2XzovlcpfKzvWj1WJLiXXDpjO2ee61foj5O5zWCKEao3O1EuyY2xpmC_0HpSKfb7T7dAe_11ewRcoQUbejmDqCW4ZLZ3qX142a2me2LsCIRfaeitAS


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
    
::SPL::Functions::Utility::printStringLn(::SPL::spl_cast<SPL::rstring, SPL::BeJwrMc40zcnMSy3ONC3PL0oBUskZiUXFAGflAjd >::cast(iport$0.get_resultSta()));

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






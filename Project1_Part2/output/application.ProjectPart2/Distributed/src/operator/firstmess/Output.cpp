// eJx9UF1rgzAUJa_1_0ilD6YGEYdW_0WPbjal3VjZdLnkulFs5lEkitWSv_17oh0_0jHb5IMnNuYdzjm2boEPRCBySZNNZ1JKE04zJIgiYWzi0wJ7hpTdveR_1vDhJ36TbNPqoszYN6cRs2FModhzR7326yaIRFxCJHWOIJSb5_1TZI7lMQhnZxleEV1QuFjTAhhtZbALBrg0vJSCsXy6yPHrhSa9dp825YXwPZGf0GBe24wZiVHTpRW4DxFbotWm5n9jl4iiZlCOHvUjVl4UAEeEU7or_0gT_1WWaio1Q4K_1WE7zU9Ez_1s0gRZOsIZt41td2nFEj98eeBTv5Xa3qhfS0a8N3du3jXZJwR41IQqprs6Jt2_1kQ62onIKHzuDV3zDxlcJrI


#include "./Output.h"
using namespace SPL::_Operator::firstmess;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator::firstmess
#define MY_BASE_OPERATOR Output_Base
#define MY_OPERATOR Output$OP



static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("firstmess::Output",&initer));
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
    state$txt = SPL::BeJwrMSw2KUmtKAEADRgDAS().clear();
    (void) getParameters(); // ensure thread safety by initializing here
    $oportBitset = OPortBitsetType(std::string("01"));
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

void MY_BASE_OPERATOR::tupleLogic(Tuple & tuple, uint32_t port) {
    IPort0Type & iport$0 = static_cast<IPort0Type  &>(tuple);
    AutoPortMutex $apm($svMutex, *this);
    
{
    state$txt.get_text() = iport$0.get_line();
    do { SPL::BeJwrMSw2KUmtKAEADRgDAS temp = state$txt; submit (temp, lit$0); } while(0);
}

}


void MY_BASE_OPERATOR::processRaw(Tuple & tuple, uint32_t port) {
    tupleLogic (tuple, port);
    static_cast<MY_OPERATOR_SCOPE::MY_OPERATOR*>(this)->MY_OPERATOR::process(tuple, port);
}


void MY_BASE_OPERATOR::punctLogic(Punctuation const & punct, uint32_t port) {
}

void MY_BASE_OPERATOR::processRaw(Punctuation const & punct, uint32_t port) {
    punctLogic (punct, port);
    
    if (punct == Punctuation::FinalMarker) {
        process(punct, port);
        bool forward = false;
        {
            AutoPortMutex $apm($fpMutex, *this);
            $oportBitset.reset(port);
            if ($oportBitset.none()) {
                $oportBitset.set(1);
                forward=true;
            }
        }
        if(forward)
            submit(punct, 0);
        return;
    }
    
    process(punct, port);
}






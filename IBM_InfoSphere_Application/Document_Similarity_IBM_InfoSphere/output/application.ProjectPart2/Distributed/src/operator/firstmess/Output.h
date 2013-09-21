// eJx9UF1rgzAUJa_1_0ilD6YGEYdW_0WPbjal3VjZdLnkulFs5lEkitWSv_17oh0_0jHb5IMnNuYdzjm2boEPRCBySZNNZ1JKE04zJIgiYWzi0wJ7hpTdveR_1vDhJ36TbNPqoszYN6cRs2FModhzR7326yaIRFxCJHWOIJSb5_1TZI7lMQhnZxleEV1QuFjTAhhtZbALBrg0vJSCsXy6yPHrhSa9dp825YXwPZGf0GBe24wZiVHTpRW4DxFbotWm5n9jl4iiZlCOHvUjVl4UAEeEU7or_0gT_1WWaio1Q4K_1WE7zU9Ez_1s0gRZOsIZt41td2nFEj98eeBTv5Xa3qhfS0a8N3du3jXZJwR41IQqprs6Jt2_1kQ62onIKHzuDV3zDxlcJrI


#ifndef SPL_OPER_INSTANCE_FIRSTMESS_OUTPUT_H_
#define SPL_OPER_INSTANCE_FIRSTMESS_OUTPUT_H_

#include <SPL/Runtime/Serialization/NetworkByteBuffer.h>
#include <SPL/Runtime/Operator/Operator.h>
#include <SPL/Runtime/Operator/ParameterValue.h>
#include <SPL/Runtime/Operator/OperatorContext.h>
#include <SPL/Runtime/Operator/Port/AutoPortMutex.h>
#include <SPL/Runtime/ProcessingElement/PE.h>
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Utility/CV.h>
using namespace UTILS_NAMESPACE;

#include "../../type/BeJwrMSw2KUmtKAEADRgDAS.h"
#include "../../type/BeJwrMSw2ycnMSwUADOECD1.h"

#include <bitset>

#define MY_OPERATOR Output$OP
#define MY_BASE_OPERATOR Output_Base
#define MY_OPERATOR_SCOPE SPL::_Operator::firstmess

namespace SPL {
namespace _Operator {
namespace firstmess {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSw2ycnMSwUADOECD1 IPort0Type;
    typedef SPL::BeJwrMSw2KUmtKAEADRgDAS OPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    inline void tupleLogic(Tuple & tuple, uint32_t port);
    void processRaw(Tuple & tuple, uint32_t port);
    
    inline void punctLogic(Punctuation const & punct, uint32_t port);
    void processRaw(Punctuation const & punct, uint32_t port);
    
    inline void submit(Tuple & tuple, uint32_t port)
    {
        Operator::submit(tuple, port);
    }
    inline void submit(Punctuation const & punct, uint32_t port)
    {
        Operator::submit(punct, port);
    }
    
    
    
    SPL::uint32 lit$0;
    
    SPL::BeJwrMSw2KUmtKAEADRgDAS state$txt;
    
protected:
    Mutex $svMutex;
    typedef std::bitset<2> OPortBitsetType;
    OPortBitsetType $oportBitset;
    Mutex $fpMutex;
    void checkpointStateVariables(NetworkByteBuffer & opstate) const {
        opstate << state$txt;
    }
    void restoreStateVariables(NetworkByteBuffer & opstate) {
        opstate >> state$txt;
    }
private:
    static bool globalInit_;
    static bool globalIniter();
    ParameterMapType paramValues_;
    ParameterMapType& getParameters() { return paramValues_;}
    void addParameterValue(std::string const & param, ConstValueHandle const& value)
    {
        ParameterMapType::iterator it = paramValues_.find(param);
        if (it == paramValues_.end())
            it = paramValues_.insert (std::make_pair (param, ParameterValueListType())).first;
        it->second.push_back(&ParameterValue::create(value));
    }
    void addParameterValue(std::string const & param)
    {
        ParameterMapType::iterator it = paramValues_.find(param);
        if (it == paramValues_.end())
            it = paramValues_.insert (std::make_pair (param, ParameterValueListType())).first;
        it->second.push_back(&ParameterValue::create());
    }
};


class MY_OPERATOR : public MY_BASE_OPERATOR 
{
public:
   MY_OPERATOR() {}
   
       void getCheckpoint(NetworkByteBuffer & opstate) { checkpointStateVariables(opstate); }
       void restoreCheckpoint(NetworkByteBuffer & opstate) { restoreStateVariables(opstate); }
   
   
}; 

} // namespace firstmess
} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_FIRSTMESS_OUTPUT_H_


// eJylU01P4zAQla_19FRHikGjZOGk4IC_0s1FYUgZISKXS14lJZjtuaJrZlO6Cw2v_0_0jpsWVPUA7ESxxpOZNx9vomUVNoZVzLQITRptRA0i9yTgJAzhsuHEMMEhlrJiBG91Qpq6qbChv3DVUB2uT5yzaSWFY3r3ojJyHr0SnhVtcj_0bJHkaifFcbx7Z_1Pd0dLOsRk_1lYVCrZrcimY1U_1nr9fJcu4nKWZvI_0fbiNyuw5Ky7aMRlNNnSlhl1oDLSxBZzqpgZFniL00bwAnAPb7mm0DVPaKMZXwNniI7bhEVvy2ZQArkVNocWguNa4rBmHxfZSmKZkAr4ItdESEwpzJZ4oMfEix8qeBXUExLDEBgMuOLXkxPZlUqh9Gx8uhQHl6EXoHaP2ckCpv5_1umdcnCn4MAFt6vr9L_0AnGfNnt0fc48K6uvC_1EIzRlHFcZVhuqgsAbeFb_0uLMThBzmtF9WjdB8t9PSsmYKx13KfSe9t5bVgmBtLt_1ze7atzsYkQ_08nQp3D2yzCFTWLinE7H1vEN8_1tR6f8J6Qlv_0wgd5jxlzDfTAfwZI2VhbeYxzvZ540CS3I30L8D_0_1_07z8ABAldhrzu4Xo_1_0AeyrFoT


#ifndef SPL_OPER_INSTANCE_COUNTER_H_
#define SPL_OPER_INSTANCE_COUNTER_H_

#include <SPL/Runtime/Serialization/NetworkByteBuffer.h>
#include <SPL/Runtime/Operator/Operator.h>
#include <SPL/Runtime/Operator/ParameterValue.h>
#include <SPL/Runtime/Operator/OperatorContext.h>
#include <SPL/Runtime/Operator/Port/AutoPortMutex.h>
#include <SPL/Runtime/ProcessingElement/PE.h>
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Utility/CV.h>
using namespace UTILS_NAMESPACE;

#include "../function/application/accumulateValues.h"
#include "../type/BeJwrMc40zcnMSy3ONC3PL0oBUskZiUXFAGflAjd.h"
#include "../type/BeJyrNIo3NArPzEvJL_1dNLMpOLTI0dMvMS8yBcACkegr2.h"


#define MY_OPERATOR Counter$OP
#define MY_BASE_OPERATOR Counter_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMc40zcnMSy3ONC3PL0oBUskZiUXFAGflAjd IPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    inline void tupleLogic(Tuple const & tuple, uint32_t port);
    void processRaw(Tuple const & tuple, uint32_t port);
    
    inline void punctLogic(Punctuation const & punct, uint32_t port);
    void processRaw(Punctuation const & punct, uint32_t port);
    
    
    
    SPL::rstring lit$0;
    SPL::rstring lit$1;
    SPL::rstring lit$2;
    SPL::BeJwrMc40zcnMSy3ONC3PL0oBUskZiUXFAGflAjd lit$3;
    
    SPL::BeJwrMc40zcnMSy3ONC3PL0oBUskZiUXFAGflAjd state$sum;
    
protected:
    Mutex $svMutex;
    void checkpointStateVariables(NetworkByteBuffer & opstate) const {
        opstate << state$sum;
    }
    void restoreStateVariables(NetworkByteBuffer & opstate) {
        opstate >> state$sum;
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

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_COUNTER_H_


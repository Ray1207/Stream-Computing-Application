// eJydUE9rwjAUJ9d9CpEdFKSpdYeRiVCFDqQ6ZxTHLhLSTKNpEpJ0tX76pVXH2GUwQuC9l7zfP6tFUDguuKsQmhTWqRyEzYlAOwigqzSDYzYtzQyXp_1NhNa_1oKU3pQ5jSx0_08S3C1zKdLutksiUz06ihKvJnGLycaR5Ng3_14N4hfPVM5wNXiZTwaLNFTjtT2_08_1VbEj9_1iPiQ1Us1P4B7lTNonWEktyTLuYT40mBXZFzBUpmj1YQyuDDqwKjrL4hx_1deCWceVjGBGHAFSSebh_0v5yrYy7DwFepAj91xTgwDQCEWpwkkLSms4itL4FqQ2XzovlcpfKzvWj1WJLiXXDpjO2ee61foj5O5zWCKEao3O1EuyY2xpmC_0HpSKfb7T7dAe_11ewRcoQUbejmDqCW4ZLZ3qX142a2me2LsCIRfaeitAS


#ifndef SPL_OPER_INSTANCE_SINK_H_
#define SPL_OPER_INSTANCE_SINK_H_

#include <SPL/Runtime/Serialization/NetworkByteBuffer.h>
#include <SPL/Runtime/Operator/Operator.h>
#include <SPL/Runtime/Operator/ParameterValue.h>
#include <SPL/Runtime/Operator/OperatorContext.h>
#include <SPL/Runtime/Operator/Port/AutoPortMutex.h>
#include <SPL/Runtime/ProcessingElement/PE.h>
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Utility/CV.h>
using namespace UTILS_NAMESPACE;

#include "../type/BeJwrMSwxzjTNycxLLc40Lc8vSgFSyRmJRcWWRanFpTklwSWJAOxcA2C.h"
#include "../type/BeJwrMc40zcnMSy3ONC3PL0oBUskZiUXFAGflAjd.h"


#define MY_OPERATOR Sink$OP
#define MY_BASE_OPERATOR Sink_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSwxzjTNycxLLc40Lc8vSgFSyRmJRcWWRanFpTklwSWJAOxcA2C IPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    inline void tupleLogic(Tuple const & tuple, uint32_t port);
    void processRaw(Tuple const & tuple, uint32_t port);
    
    inline void punctLogic(Punctuation const & punct, uint32_t port);
    void processRaw(Punctuation const & punct, uint32_t port);
    
    
    
    
    
protected:
    Mutex $svMutex;
    void checkpointStateVariables(NetworkByteBuffer & opstate) const {
    }
    void restoreStateVariables(NetworkByteBuffer & opstate) {
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
   
   
}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_SINK_H_


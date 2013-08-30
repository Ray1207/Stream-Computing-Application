// eJyVkk1rwzAMhtFfKTu0l9hJevKtH_0tgdGtGCBu7DOO4rdvEDrZC6H79nGRrC8soQwdj_0_1UrPZJdVQRWFhyV0bxgbFVrgcYC7WIKoyAg2_1bM3xNeVYUSnZYIU2tc7LnlAqV1wX50Q_1tqbH6W4amSZC4fG_1uUNtFJaL9ks_0XmfrEMBzRiSj9bzSnePC_1iZE3NPHPHd5W9rWYP22J2yNtHFEIoFN5RSJM1Y0pjHAEA2ZtSEodW8tLxvFSapP0mxTpXhjTGHl3FhSSJNQcpMEy4xfCllq4tPyI5Rw7aaNmloKAqY89p_1qAABX0XoavKv7W_0BKV3nYP57XCbEUpvGXdmDnq60McV7A9_10_1Z6WEKBsavZMHYZzvibK9hJ_1GizjCcTEH7E_17K6_1IkhPw_1_1BVy4MUh


#ifndef SPL_OPER_INSTANCE_ONELINE_H_
#define SPL_OPER_INSTANCE_ONELINE_H_

#include <SPL/Runtime/Operator/Operator.h>
#include <SPL/Runtime/Operator/ParameterValue.h>
#include <SPL/Runtime/Operator/OperatorContext.h>
#include <SPL/Runtime/Operator/Port/AutoPortMutex.h>
#include <SPL/Runtime/ProcessingElement/PE.h>
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Utility/CV.h>
using namespace UTILS_NAMESPACE;

#include "../function/application/countCharacters.h"
#include "../function/application/countWords.h"
#include "../type/BeJwrMSw2ycnMSwUADOECD1.h"
#include "../type/BeJwrMc40zcnMSy3ONC3PL0oBUskZiUXFAGflAjd.h"

#include <bitset>

#define MY_OPERATOR OneLine$OP
#define MY_BASE_OPERATOR OneLine_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSw2ycnMSwUADOECD1 IPort0Type;
    typedef SPL::BeJwrMc40zcnMSy3ONC3PL0oBUskZiUXFAGflAjd OPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    inline void tupleLogic(Tuple const & tuple, uint32_t port);
    void processRaw(Tuple const & tuple, uint32_t port);
    
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
    
    
    
    SPL::int32 lit$0;
    
    
protected:
    Mutex $svMutex;
    typedef std::bitset<2> OPortBitsetType;
    OPortBitsetType $oportBitset;
    Mutex $fpMutex;
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
  
   void process(Tuple const & tuple, uint32_t port);
   void process(Punctuation const & punct, uint32_t port);
   
}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_ONELINE_H_


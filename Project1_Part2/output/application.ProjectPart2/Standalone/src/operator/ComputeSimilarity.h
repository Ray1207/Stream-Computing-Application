// eJx9UF1PwjAUzf0nhvgAiVm3YXjoG_1JhIkwxDVGfSDPKKFt3m_04ShF9vtykxiqbpwzk9PffcU9kicKqQpLGUBefTfZkSOgib04dOELBNzfl3Jq0tdNpo2QiN3ZMS2uhCOk1HkaJTwbbTfKGjVexOPRxcIjCeLw3NxveT5eRtmGT5dJxf0L0_0nx5Hu6dT0k_0EOM3ms3wyHOnB8GVZi_0s0wLZoFKvIKWkquTa6ZKIFgvZrjeyALq_0sTBVbONyplKLVQjqK2VqShBJL5W0if7VFR9chiMWc839ygoa2C4AYSL1TBM7P12XWoPiMalP8bfr3UmC8cwTVuT_1YFChpcOvJqLX4IkLg_1Fv1nF_1uvvu5VJApWjVZu72bq59k3O31fNgPuxShB7


#ifndef SPL_OPER_INSTANCE_COMPUTESIMILARITY_H_
#define SPL_OPER_INSTANCE_COMPUTESIMILARITY_H_

#include <SPL/Runtime/Operator/Operator.h>
#include <SPL/Runtime/Operator/ParameterValue.h>
#include <SPL/Runtime/Operator/OperatorContext.h>
#include <SPL/Runtime/Operator/Port/AutoPortMutex.h>
#include <SPL/Runtime/ProcessingElement/PE.h>
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Utility/CV.h>
using namespace UTILS_NAMESPACE;

#include "../function/application/ComputeSimilarityScore.h"
#include "../type/BeJwrMSo2LUmtKDGEUEYAMgkFDk.h"
#include "../type/BeJwrMXQzNCjOzM3MSSzKLKkEACi6AWU.h"

#include <bitset>

#define MY_OPERATOR ComputeSimilarity$OP
#define MY_BASE_OPERATOR ComputeSimilarity_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSo2LUmtKDGEUEYAMgkFDk IPort0Type;
    typedef SPL::BeJwrMXQzNCjOzM3MSSzKLKkEACi6AWU OPort0Type;
    
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
#endif // SPL_OPER_INSTANCE_COMPUTESIMILARITY_H_


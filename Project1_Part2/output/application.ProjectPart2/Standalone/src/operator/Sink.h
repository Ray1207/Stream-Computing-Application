// eJyVkF1PwjAUhnNu_0RUL4YIFsw4wRosxYUYvEAxmkHhHmq2OytYu7VnIZvjv1iKIiRdyetXz8Z7zvKbMgwpFLrCm9L4yqAoI3etDOwgI1iUnEZ9s9ez1pZnJaLaob54Wy2sTL8NJY5rn5mFjalGX0Tja6izPgnXbzhpkyDuJqiRCPJ9SKiQOBwBDsKs64T6nDWohM3C5_1h_05wa9ZIGtVcGIbOCsMSwshSbz_1xFilQpGt0htTsoSTuVbvPMH_0as40DkjKkIFUkjuwEESp9PGMs_1BAgHb_0fLQ8G5Q6icdKJiiUNJQuD26WlgNjRzOVXRuO0usdZkyZrxJm8PaU_08L7IfbuKP1q6J6Y6ftWwFno_10_1pLLjjxm9_1fN8fOcyTC3q9UWvXAmvjOMs0z2whjUUhcqYtNrzliuHVJYSfsP7ADE


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

#include "../type/BeJwrMXQzMnBMTy9KTU8sSU0JzszNzEksyiypBABwrglg.h"


#define MY_OPERATOR Sink$OP
#define MY_BASE_OPERATOR Sink_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMXQzMnBMTy9KTU8sSU0JzszNzEksyiypBABwrglg IPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    inline void tupleLogic(Tuple const & tuple, uint32_t port);
    void processRaw(Tuple const & tuple, uint32_t port);
    
    inline void punctLogic(Punctuation const & punct, uint32_t port);
    void processRaw(Punctuation const & punct, uint32_t port);
    
    
    
    SPL::rstring lit$0;
    SPL::rstring lit$1;
    SPL::int32 lit$2;
    
    SPL::int32 state$count;
    
protected:
    Mutex $svMutex;
    void checkpointStateVariables(NetworkByteBuffer & opstate) const {
        opstate << state$count;
    }
    void restoreStateVariables(NetworkByteBuffer & opstate) {
        opstate >> state$count;
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
#endif // SPL_OPER_INSTANCE_SINK_H_


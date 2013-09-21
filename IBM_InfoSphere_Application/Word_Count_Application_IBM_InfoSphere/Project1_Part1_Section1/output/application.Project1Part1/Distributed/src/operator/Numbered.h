// eJyNUMFKw0AQZa5_0RSk9tFSy2QiKqwjtQcW2IbD14iWsyZKuTXbj7sSavzdt2lixiCx7eG9m3rx5rsw9K3OBymiRM3Zf6QSNBX_13Auh7HsG6lGQqnzZ2wd8DvriKZr4OZ_1W6CpfLTZ18zq_15R7h8NjjJppcvWfHorfq_1JuvjyYfJ1I_1phMd020rBoUA5UMCjOWNK40UADZsrHPg_1OCArU0ji0EpROJEWShPeAo5VqgzZGLt2pUgkiax5kwnSSFikJBUoQBstm7No81VpbKf_0t0VQ0Aaydzke35xt7SVGo9TowDZ_0lM52uuaE7v9Cg6JZE5xSpa3agejMe5nE_0NA_1HMFcaRlWxau0ULWBdbN77ANjO_0zKPE6Ew9uj6nnvO_0reHWPb_0nB_186i57Qtpa6td


#ifndef SPL_OPER_INSTANCE_NUMBERED_H_
#define SPL_OPER_INSTANCE_NUMBERED_H_

#include <SPL/Runtime/Operator/Operator.h>
#include <SPL/Runtime/Operator/ParameterValue.h>
#include <SPL/Runtime/Operator/OperatorContext.h>
#include <SPL/Runtime/Operator/Port/AutoPortMutex.h>
#include <SPL/Runtime/ProcessingElement/PE.h>
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Utility/CV.h>
using namespace UTILS_NAMESPACE;

#include "../type/BeJwrMSq2SM7PK0nNKykuNTTwycxL9SvNTUotAgB6ZgmH.h"
#include "../type/BeJwrMSy2SM7PK0nNKykGAB0_1AS_1.h"

#include <bitset>

#define MY_OPERATOR Numbered$OP
#define MY_BASE_OPERATOR Numbered_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSy2SM7PK0nNKykGAB0_1AS_1 IPort0Type;
    typedef SPL::BeJwrMSq2SM7PK0nNKykuNTTwycxL9SvNTUotAgB6ZgmH OPort0Type;
    
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
    
    SPL::int32 state$i;
    
protected:
    Mutex $svMutex;
    typedef std::bitset<2> OPortBitsetType;
    OPortBitsetType $oportBitset;
    Mutex $fpMutex;
    void checkpointStateVariables(NetworkByteBuffer & opstate) const {
        opstate << state$i;
    }
    void restoreStateVariables(NetworkByteBuffer & opstate) {
        opstate >> state$i;
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
   
       void getCheckpoint(NetworkByteBuffer & opstate) { checkpointStateVariables(opstate); }
       void restoreCheckpoint(NetworkByteBuffer & opstate) { restoreStateVariables(opstate); }
   
}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_NUMBERED_H_


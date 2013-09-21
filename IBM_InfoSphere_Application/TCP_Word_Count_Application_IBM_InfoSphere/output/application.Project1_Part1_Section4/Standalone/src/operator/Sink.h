// eJytUW1rwjAQJl_19FUX2wTJp68uHkYmgggOpLxjFsS8S0kyjbVKSdFrH_1vvS_0LIhYwxZQsLdcXfP89ypNPYyzWKmcwh7mdIiAYG9dVD2PF_1nKfW7dLCTQ7TbHzazUU72YUiaQUge3tCqj_1JpMpiSxWKKeT_0dbeMdWgw64z3p1HveunzdxBQeCB_0ivDEe9RqTMBDdudq_0sPlzv_1P0Gnc2UVEUgAYwlO4CgCYhhFJpyfgK2Fjth1j9Kgb8tUiob1yKE4WjhHEfHR2ks4gJfyfkVqWYUH8ixYYSXVtOsDQ_1MjYTvOlHWGPABaeGTc08lgp5YXTrRAAD0k73veSYA6Ht1s_04BVUQzs_07SI0SjayekFfsOWWrNF4SrHTru_0aqYz1T06g7bQiLhMqJsreieimpymLTEFdc68eMU1VxXefesRMsjH8FMBOOCoAzQu0mhK_1Qr2BkjaUBMwh_10XzhFLjuY_0mjBMyCL7lAZ2lMW0catqJ6tK2gk23x2iD4BHinAvf


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
    
    
    
    SPL::rstring lit$0;
    SPL::rstring lit$1;
    SPL::rstring lit$2;
    
    
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


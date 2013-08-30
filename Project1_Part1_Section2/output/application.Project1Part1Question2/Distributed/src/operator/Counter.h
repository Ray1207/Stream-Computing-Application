// eJylU91P2zAQl1_17V0SIh0SDfDQ8TB5Maqt1AiUlU9YJ8VJZjtuaOrZlO6CA9r_1PcdOCqj4AuyjR_0Xz3u4_1fRUsWNoYyaloIJ402ogaxe1JwEobRsuHYUMEjJCWjGG11jJu6YciQP4g1RIfrE_0dsWkmiMbl5Ujm_0iJ8xz8s2vZ1N0iKLxXiuN_1d0fjcd_1Vyy0UN1GNSq2bVIZyNVPP94vMkWSTXLcnmb_1b6Oq_1wxL7_02YzyabMhKDbvQBGhjCzjVTQ3KIoPwvXkBuAC23dN4G6a0UZSvgLMlR2zDI7b0oylBtBY1iSwGQbVGVU15VG4PpWkqKqInoTZaIkyiQokHgk1SIGWSX3a83cyHUYUMAlxwYrlJ7EulUPsu3l0JBcqxC_0EbQu3hgFF_1P9wzr08UfBsAuvR8f5fwA4T5sluj8yTwrq68T8RDOKUcsRypDVFB4A08Ky_1u2wmEDnPa76qGcL5baWlJM6WjLuO_0k95bS7bASJvLt_1SebauzMenQ_0w5h5_1A6i3BFzIJRbudji_1jiufXolP_0EtNxXHeQOM_1kU5qvpAB6vkbLwFvN4J_1u8cWBJ7gb6d2B_1f3cNHCBwFfa6g_0v1_0B_1Mi1nZ


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


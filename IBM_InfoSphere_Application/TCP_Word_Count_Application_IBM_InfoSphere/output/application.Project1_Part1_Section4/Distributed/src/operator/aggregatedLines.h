// eJyVU_09r6jAU5f4nMvZhgphWN3iEMegEH0i3idnwsS8jL81qNE1Ckk7dX_1_1S1Dlhbz_0ktNy055yee3LjjOxbLqkXWlGJcVaWlpfUc0jidQEn_1T56rhVrEIgaIwWLaCSU8P3FyecAYzXjzn2JsdzVci_1jt4ajaz5Z2xuy3rwu72_03bJPn7DzJ2a8XUo7JdlZNZmw_0n1E1NvcruSbzSXa3Ydlg9B_0RQHxl6oZsh3e3o_0E0T_1T1g1s9ioc_14_0z3s8yWRUNKwfnQ8amrKyDTHOOfkgEGIIU_1TVqadd4KVUJ8lx4rBWihK46CBqeVo0UlFCLtgvi6EBqttV05QxlHU6uXnPn0aUpteBIegz1HBfUUlFbN7qXhFkbbvb0fWxFgG37CdK08pJEslB8OgibGcemMfGLU_0cv3j73OYQidK4wbwFnMpxtnCWAYolHcQasW_0inearag9q1unOuPzo_0fCKhCJym0M0ZCNL42kl_1Gv3Sik15bRye7Ojq5gnRUO6_0rYDla_0Ku15FQFZxgfzG_1Tu_1Bn_0_1npfoPeHYl3Qq_0z26PukZv0Qbrt8sBKiPEfDQZADR




#ifndef SPL_OPER_INSTANCE_AGGREGATEDLINES_H_
#define SPL_OPER_INSTANCE_AGGREGATEDLINES_H_

#include <SPL/Runtime/Common/Metric.h>
#include <SPL/Runtime/Operator/Operator.h>
#include <SPL/Runtime/Operator/ParameterValue.h>
#include <SPL/Runtime/Operator/OperatorContext.h>
#include <SPL/Runtime/Operator/Port/AutoPortMutex.h>
#include <SPL/Runtime/ProcessingElement/PE.h>
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Window/Window.h>
#include <SPL/Runtime/Utility/CV.h>
using namespace UTILS_NAMESPACE;

#include "../function/application/init.h"
#include "../function/application/process.h"
#include "../function/application/result.h"
#include "../type/BeJwrMSwxzjTNycxLLc40Lc8vSgFSyRmJRcWWRanFpTklwSWJAOxcA2C.h"
#include "../type/BeJwrMc40zcnMSy3ONC3PL0oBUskZiUXFAGflAjd.h"

#include <bitset>

#define MY_OPERATOR aggregatedLines$OP
#define MY_BASE_OPERATOR aggregatedLines_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMc40zcnMSy3ONC3PL0oBUskZiUXFAGflAjd IPort0Type;
    typedef SPL::BeJwrMSwxzjTNycxLLc40Lc8vSgFSyRmJRcWWRanFpTklwSWJAOxcA2C OPort0Type;
    
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
    
    
    
    SPL::rstring lit$0;
    SPL::BeJwrMc40zcnMSy3ONC3PL0oBUskZiUXFAGflAjd lit$1;
    
    SPL::BeJwrMc40zcnMSy3ONC3PL0oBUskZiUXFAGflAjd state$sum;
    
protected:
    Mutex $svMutex;
    typedef std::bitset<2> OPortBitsetType;
    OPortBitsetType $oportBitset;
    Mutex $fpMutex;
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
 
class MY_OPERATOR : public MY_BASE_OPERATOR, 
                    public ::SPL::WindowEvent<SPL::BeJwrMc40zcnMSy3ONC3PL0oBUskZiUXFAGflAjd>
{
public:
    typedef int32_t GroupByType; 
    typedef int32_t PartitionByType; 
    typedef ::SPL::TumblingWindow<IPort0Type> WindowType;
    typedef ::SPL::WindowEvent<IPort0Type> WindowEventType;
    MY_OPERATOR();
    ~MY_OPERATOR();
    void process(Tuple const & tuple, uint32_t port); 


    void beforeWindowFlushEvent(WindowEventType::WindowType & window, 
                                WindowEventType::PartitionType const & partition);



    struct Tumbling$aggregatedLines;

private:
    WindowType _window;
    Mutex    _mutex;

    Metric& _partitionCount;
}; 
 
} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_AGGREGATEDLINES_H_


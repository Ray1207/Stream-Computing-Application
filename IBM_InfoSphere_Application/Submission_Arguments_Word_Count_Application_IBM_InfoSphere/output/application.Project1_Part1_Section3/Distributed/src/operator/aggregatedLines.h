// eJyVkm9LwzAQxrlvIuILB7K0q4IUEepgwqg6lo2JbySm2ZYtTUKSus1Pb5rOOfDvCC2X9p7L77mc1aJtmCCOK0lEmmazmWEz4hhEYV3AcbuNppWkdQYiWgtOQzbikrv2_1PjnBG0UZdb_0mmOYrcSujNtohm5Yf2Xu8Gr9thjdb_0g6z_0l5lNPLVzzr4c2w7A_1pZDIksqdHS7HCk372sKZZp_1tNES98o_1IOb5KH_024yyCN1M7bLJz5_07GW3U5EtiloUg3Xe8YmtSsCDPE3_1KwbogODuJGpkXLqkA_0FLfGghQHNVMmSdYaS0pCi5RLjZYFcVXKGVMkurCWVoYNSCURc_1D4jxb8xCWxNUEEdAKlnfXewfrpXZwf0bhYOp9RFVlXQQ7zmLt2brBZD4nWQWmn_0erviI6ZyYj7jmUF85Dr9dKD1XDM28YG_1UVVqwq3DKUSA5a_0JAso0DyTXE3co6VXrkgPCilGBEerI03ZvF2iZ3p7tZaP2RvR3vT8HZ0bbjrQNb_1qV043IPxbfxHRWzC9y




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
    
    
    
    SPL::int32 lit$0;
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


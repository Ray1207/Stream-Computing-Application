// eJyVkm9rwjAQxrlvMoYvJgzT6AajjEEnOJBuc8bh2LssjRpNk5CkU_1fpl7bqhP1TQuDS3HP9PZdzRrYsl9QLraiM42Q6tXxKPYeoWpdw2mqhSaFYmYGoMVKwKhsJJXxrdvp7grGacef_0zLHcFXJXxq8NR7e8v7T3ZLn6mI8e1myVpuwiStnVO5n2yHqY94dsPB5S1TOjhVyScT95XLGk3f2hSBB_0MHVP1p3Hh25nkEb69tktXsXzSy_05m8hknpUiDM4Hxw1X5EAGaRwfKgZogxS_0EdUyoXynDdUXfGwhQDOdc_0S85TR3NMuFQqQ_0EF9kQqOltgtnKONoYPWcM48H1Hr8VHBXdrKNMuopKK3Kp8NhC6Ptju1gEgG21EdMF8oD3jOGN17LBdAJJ8Ud1HcBLtvGbEbtNi459HeO4x8X8sCFoR4XEoz6wkh_0Xf3lpCI5r_0OKZBNXJDeAu4XzOg_1IFcKb1pJTFcjieG8US5vCn_01GoflP9ma6vwTnJ5uON49s_0bfStcs9lNDGTw43C82




#ifndef SPL_OPER_INSTANCE_B_H_
#define SPL_OPER_INSTANCE_B_H_

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

#define MY_OPERATOR B$OP
#define MY_BASE_OPERATOR B_Base
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



    struct Tumbling$B;

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
#endif // SPL_OPER_INSTANCE_B_H_


// eJylUctugzAQ1P5K1EN7wQ964pYWWilNVCTEoafIAou4gI3MRjR_1X8dJIypIeqh8sHd2xzNj910TWNkIVEaLJopWRmmgfnFYBAHBQyfJk1wNdpMZvs5bfItfkzz5WG6q_0iWug91iMjfwQ6Hdli_1j9_0Q5ZscZCo_1QKLyjkKXrKFIaQw4eYROET5DwFwJkZ1pJerRStL0oW6VJdioy3JfKkMHYuu9EIUlqzacskG1TYZGTUqAAbbT0ASmoztiLqSv2QYF1o4wWZq8R2MgKO2dy3WtN5prgz07UOs9KV648CbP_1CfNbwuG8MAUzk3nua6F18hxQfiEbXXD2_1ANc3jCoJG6PYvcPnsP_15rARx2f5BtobL7C



#ifndef SPL_OPER_INSTANCE_JOINFILESTREAM1_H_
#define SPL_OPER_INSTANCE_JOINFILESTREAM1_H_

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

#include "../type/BeJwrMSo2LUmtKDGEUEYAMgkFDk.h"
#include "../type/BeJwrMSw2ycnMSwUADOECD1.h"

#include <bitset>

#define MY_OPERATOR JoinFileStream1$OP
#define MY_BASE_OPERATOR JoinFileStream1_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSw2ycnMSwUADOECD1 IPort0Type;
    typedef SPL::BeJwrMSw2ycnMSwUADOECD1 IPort1Type;
    typedef SPL::BeJwrMSo2LUmtKDGEUEYAMgkFDk OPort0Type;
    
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
    SPL::int32 lit$1;
    SPL::int32 lit$2;
    SPL::int32 lit$3;
    
    
protected:
    Mutex $svMutex;
    typedef std::bitset<3> OPortBitsetType;
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
    typedef int32_t PartitionByLHSType; 
    typedef ::SPL::SlidingWindow<IPort0Type*> WindowLHSType;
    typedef ::SPL::WindowEvent<IPort0Type*> WindowEventLHSType;

    class WindowLHSHandler : public WindowEventLHSType {
    public:
      WindowLHSHandler(MY_OPERATOR & op) : op_(op) {}
      void beforeTupleEvictionEvent (WindowType & window, TupleType & tuple,
                                     PartitionType const & partition)
        { op_.evictLHS (*tuple);}
      
    private:
      MY_OPERATOR & op_;
    };

    typedef int32_t PartitionByRHSType; 
    typedef ::SPL::SlidingWindow<IPort1Type*> WindowRHSType;
    typedef ::SPL::WindowEvent<IPort1Type*> WindowEventRHSType;

    class WindowRHSHandler : public WindowEventRHSType {
    public:
      WindowRHSHandler(MY_OPERATOR & op) : op_(op) {}
      void beforeTupleEvictionEvent (WindowType & window, TupleType & tuple,
                                     PartitionType const & partition)
        { op_.evictRHS (*tuple);}
      
    private:
      MY_OPERATOR & op_;
    };

    

    MY_OPERATOR();
    ~MY_OPERATOR();
  
    virtual void process(Tuple const & tuple, uint32_t port);

    virtual void prepareToShutdown() {}

private:
    void evictLHS (Tuple& tuple);
    void evictRHS (Tuple& tuple);
    void cleanLHS (Tuple& tuple);
    void cleanRHS (Tuple& tuple);
    WindowLHSType    _windowLHS;
    WindowLHSHandler _winLHSHandler;
    WindowRHSType    _windowRHS;
    WindowRHSHandler _winRHSHandler;
    Mutex            _mutex;
    
    
        
    
    bool _emptyCountLHS;
    bool _emptyCountRHS;
    Metric& _lhsPartitionCount;
    Metric& _rhsPartitionCount;
}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_JOINFILESTREAM1_H_


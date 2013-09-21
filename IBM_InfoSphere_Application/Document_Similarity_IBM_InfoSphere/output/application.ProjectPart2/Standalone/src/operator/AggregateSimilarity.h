// eJyNUsFugkAQzfxJ03jQpGFBW9NyE_0NFxdqgaW9miyuuLrtkd4iBry_0gVVu1NGQPzLyZee_1NmERYmgmKXEkqXLcXRZpFFBnY1fcE95ZFVqkMSwShSSJ4WKEJlxyt9f1tQKJVyIz5E6OZScWxDWYJIx4b7rT_18Zb70vNn2ctoNn82wdwe5iaf5IOtyXiWeD1vpyMRXa_0c9Devud_1xgyAfjUfbQa_1Pu733eQl2wGAhr3EUugx4zAXVHLMgVJpBMB277kooit1HgA4Ijg17H_0USO22oIs5FpP2rEshaxYwY1IzGhi5jLkmw_1wkwXXJFdkpvTUJDRqZabViIzmJKNbbJkiIFqWS5Bad4PFH6SKJOJXDQZZ0dqlQiOGc8nYOYInsrWY6D0qWjK_1CtqEypq0z_0symIC1oOXPP9NKGfGlRxYXrV_11Mpwagsxrru2dGUhDk2a_1bYqulxuM66Ng93B_1OtiOHi5Eqz1fq574sB_09OupVm4_0gVNQyfD




#ifndef SPL_OPER_INSTANCE_AGGREGATESIMILARITY_H_
#define SPL_OPER_INSTANCE_AGGREGATESIMILARITY_H_

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
#include "../type/BeJwrMXQzMnBMTy9KTU8sSU0JzszNzEksyiypBABwrglg.h"
#include "../type/BeJwrMXQzNCjOzM3MSSzKLKkEACi6AWU.h"

#include <bitset>

#define MY_OPERATOR AggregateSimilarity$OP
#define MY_BASE_OPERATOR AggregateSimilarity_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMXQzNCjOzM3MSSzKLKkEACi6AWU IPort0Type;
    typedef SPL::BeJwrMXQzMnBMTy9KTU8sSU0JzszNzEksyiypBABwrglg OPort0Type;
    
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
    SPL::float64 lit$2;
    
    SPL::float64 state$AggregatedSimilarityScore;
    
protected:
    Mutex $svMutex;
    typedef std::bitset<2> OPortBitsetType;
    OPortBitsetType $oportBitset;
    Mutex $fpMutex;
    void checkpointStateVariables(NetworkByteBuffer & opstate) const {
        opstate << state$AggregatedSimilarityScore;
    }
    void restoreStateVariables(NetworkByteBuffer & opstate) {
        opstate >> state$AggregatedSimilarityScore;
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
                    public ::SPL::WindowEvent<SPL::BeJwrMXQzNCjOzM3MSSzKLKkEACi6AWU*>
{
public:
    typedef int32_t GroupByType; 
    typedef int32_t PartitionByType; 
    typedef ::SPL::SlidingWindow<IPort0Type*> WindowType;
    typedef ::SPL::WindowEvent<IPort0Type*> WindowEventType;
    MY_OPERATOR();
    ~MY_OPERATOR();
    void process(Tuple const & tuple, uint32_t port); 



    void onWindowInitialFullEvent(WindowEventType::WindowType & window, 
                                  WindowEventType::PartitionType const & partition);


    void onWindowTriggerEvent(WindowEventType::WindowType & window, 
                              WindowEventType::PartitionType const & partition);

    void beforeTupleEvictionEvent(WindowEventType::WindowType & window, 
                                  WindowEventType::TupleType & tuple, 
                                  WindowEventType::PartitionType const & partition);



private:
    WindowType _window;
    Mutex    _mutex;

    std::tr1::unordered_set<WindowEventType::PartitionType> _windowFull;

    Metric& _partitionCount;
}; 
 
} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_AGGREGATESIMILARITY_H_


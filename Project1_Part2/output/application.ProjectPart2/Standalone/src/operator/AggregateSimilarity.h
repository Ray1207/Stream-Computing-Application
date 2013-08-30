// eJyNUt9PwjAQzv0nxvAAiVk3UKJ72wgvwBAziL6ROsoodO3S3kK2v94NcKCiM5c_0tPnuvh89kwpLM0GRK0mF63pxrFlMkYF9qAe4tSyyzmRUIQhNU8GjA5pwydHa3P4OSLWKmDF_1YjQzmajHYJ4y4rPRXgdvL0Ug_1WCeP43ni0cTLuxRYYppMdyZnOep7_1l7HYv4eud0sH0ugl4QhsV4Mt4NvQHve6_0LCuyAwdJeqza6CnnCBdUc8zBSmkE4m7juWiiK_1XuALgiOLfv4yiX2unB4cb7hgGxUwohBzWhi6CrhkoTHS4jZiiuyV3pnUhoxMtNqyyJ0ljOqsUtWFClIJavMnfLwVOmasskTcNBVnx2pTCI4Fzqdk_1SqoDJeG4VP2RWdukr3n_1AhKbkduBblmWGQGVQJ9I7z35USjMqS1nUv9qCSzLHd8DWdhhmnhWsac3dzStiKGS7PqbQ7na_0f_0oPguK2NMstUPwCd8xuc




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
    SPL::float64 lit$1;
    
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
                    public ::SPL::WindowEvent<SPL::BeJwrMXQzNCjOzM3MSSzKLKkEACi6AWU>
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



    struct Tumbling$AggregateSimilarity;

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
#endif // SPL_OPER_INSTANCE_AGGREGATESIMILARITY_H_


// eJx1UMFqwzAMRb9Sdo6droyRW5cssKxdA87OxUuU1VtiG8UhZF8_1LaWFHoZB1rMlvac3_0C7SjfYBKUly06FyI9UIcjlrWEWRCLNH8YTFRHs1refa8vW_0zQ7PaRZHp9VNzUxvL_1K_0MptxPz_141yw_1zMP0U9VUVI_0ba297jKcidX_1NEmLoTLiToMpdktAQyNhPABAn16NgiLofdNMbK9QZqDA2xonJ0ffgdY2iJPeFdYiPpSaOinPjbCwaHTRYZ5EXaR31OjBZxo_15GUhm5s90HILrd4Y90B20bAKX3ai5SNwGxh9jwJwQF_0kSnHd0lf_0PS9ADLUOY7TJTyl_0dL3kg



#ifndef SPL_OPER_INSTANCE_DATA_H_
#define SPL_OPER_INSTANCE_DATA_H_

namespace streams_boost { namespace iostreams { class file_descriptor_source; } }
#include <SPL/Runtime/Common/Metric.h>
#include <streams_boost/filesystem/path.hpp>
#include <SPL/Runtime/Operator/Operator.h>
#include <SPL/Runtime/Operator/ParameterValue.h>
#include <SPL/Runtime/Operator/OperatorContext.h>
#include <SPL/Runtime/Operator/Port/AutoPortMutex.h>
#include <SPL/Runtime/ProcessingElement/PE.h>
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Utility/CV.h>
using namespace UTILS_NAMESPACE;

#include "../type/BeJwrMSw2ycnMSwUADOECD1.h"
#include "../type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.h"


#define MY_OPERATOR Data$OP
#define MY_BASE_OPERATOR Data_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSw2ycnMSwUADOECD1 OPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    
    inline void submit(Tuple & tuple, uint32_t port)
    {
        Operator::submit(tuple, port);
    }
    inline void submit(Punctuation const & punct, uint32_t port)
    {
        Operator::submit(punct, port);
    }
    
    
    
    SPL::rstring lit$0;
    
    
protected:
    Mutex $svMutex;
    SPL::rstring param$format$0;
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
    MY_OPERATOR();
    
    
        virtual void process(uint32_t index);
        virtual void allPortsReady();
    

    virtual void prepareToShutdown();

private:
    void initialize();
    inline void punctAndStatus(const std::string& pathName);
    void processOneFile (const std::string& pathName);
    

    int32_t _fd;
    uint64_t _tupleNumber;
    
    
    
    
    
    
    Metric& _numFilesOpenedMetric;
    Metric& _numInvalidTuples;
}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_DATA_H_



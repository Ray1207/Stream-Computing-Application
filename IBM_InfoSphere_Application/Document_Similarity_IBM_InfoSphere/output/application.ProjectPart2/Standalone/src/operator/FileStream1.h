// eJx1kN1ugkAQhTOvYnrNLmKaxjsL2lRUSMFrs4WxbvlZMgwSfPoumjY1abMXm5N8c86caZvSUblqGGk_0T_104MR1lCPL6PJg4juChQfGM6562ST8dstp_0_00UQLf3AdU6TO2ag3av0Uj3rtsNjEwaraGj7S5rROn2a_1cweD26_19s1fw8YL5YzDouVtcY6G_1WUX9stFFPcv_1m7kJbhQan6QkMSb_0bzTNXtTABAnU6FomVBVrcorXYvkJhLucm1Eb6hoG5WhiMl8YsbuIVbEU5ErVlCbGm1dMiXagMRkBfLbKCS0SGck8LuWTbXR9lCqhMYQj_0CvHb73WjCTfu8YV4QIR0OVGtHAxqxuQlrSxt07jsUkmNH4u9w_1N4cK6JpmPcg21vUHSPkFw66QDq



#ifndef SPL_OPER_INSTANCE_FILESTREAM1_H_
#define SPL_OPER_INSTANCE_FILESTREAM1_H_

#include <SPL/Toolkit/TCPServer.h>
#include <SPL/Runtime/Common/Metric.h>
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
#include "../type/BeJyrNIo3K04tKkstMkvOyUzNKwEAOPwGCN.h"


#define MY_OPERATOR FileStream1$OP
#define MY_BASE_OPERATOR FileStream1_Base
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
    
    
    
    SPL::uint32 lit$0;
    
    
protected:
    Mutex $svMutex;
    SPL::rstring param$role$0;
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
   int _fd;
   SPL::TCPServer *_connector;
   uint64_t _tupleNumber;
   
   
   Metric& _numInvalidTuples;
   Metric& _numReconnects;
   Metric& _numConnections;
   Metric& _numWireFormatHandshakesFailed;
}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_FILESTREAM1_H_



// eJx1kV9vgjAUxXO_1itkzLUqWhTcHukxUyMBn08F1dvwpuS0j_0OlX3FyicWnS9jS_1e8_1JrW4rRxSiNUi_0nwVJqjrKEfh5zWDiOMwMLbJnXPW0SfvpkDf22M3DeBGErnOcXDEDbV_15LJNetxke2yhcxoPuT1lOq_0zJ_06s97N1_0Fah7xWoWcc9EpTab8isedqdt1C_1mcdK_1BNuR5zCFSpoHDmmy9n3ShmTzAec39_0YN2FHVyKxEUWtR1LJh6Y9ITVdIxXpFpW5Fjiwh9Ym5cfeJILun9i5V47FCGAGNahA8IFUhWBOVl2jeRsEhryQ2BoJOG1WvpR2jqEAUBaHWcBPI_1U0_0N1a_1dwaXhAitInOfdG_1Ig6JajGxoQy1_1BLekDXftzy3DQY2dL4P65_1_0gBjq72R4Xc86_1AekeKqe



#ifndef SPL_OPER_INSTANCE_DATA_H_
#define SPL_OPER_INSTANCE_DATA_H_

#include <SPL/Toolkit/TCPClient.h>
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
    SPL::rstring lit$1;
    
    
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
   SPL::TCPClient *_connector;
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
#endif // SPL_OPER_INSTANCE_DATA_H_



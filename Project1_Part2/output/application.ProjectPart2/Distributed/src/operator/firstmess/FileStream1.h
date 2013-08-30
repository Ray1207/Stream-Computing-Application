// eJx1UGFLwzAQ5f7K8HOT1SHSb7O1YN1cofWzxPbqok0TLiml_1nrPjg0URg7Cu9y791686yPVKheQkiTXPVZ2pAZBLieGVRQJrjA7FA9YTLSvpnhuBr5et9nhMc3W0XH1f2ymlyd5W_0vNuJ_1v3HOWH2Y_1fdcNFfX95kLv3tZTkdpfvoQ19DrcSKjKXZKQD6SHDwAQR2tQMERlvGqNHkR1AlUYW23FZOnLO9WgKMl_0YhNKRSEWrQoKBjsgZ_0gsGRVYIeNmfgKS5fgxHX2wZqc5vuqh4_1w89sfC2dc2MH4fA_0aEuPiVYJ2li_0crvwMGaFnCauedUv4A2Nd2BC



#ifndef SPL_OPER_INSTANCE_FIRSTMESS_FILESTREAM1_H_
#define SPL_OPER_INSTANCE_FIRSTMESS_FILESTREAM1_H_

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

#include "../../type/BeJwrMSw2ycnMSwUADOECD1.h"
#include "../../type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.h"


#define MY_OPERATOR FileStream1$OP
#define MY_BASE_OPERATOR FileStream1_Base
#define MY_OPERATOR_SCOPE SPL::_Operator::firstmess

namespace SPL {
namespace _Operator {
namespace firstmess {

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

} // namespace firstmess
} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_FIRSTMESS_FILESTREAM1_H_



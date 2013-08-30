// eJydkEFrwzAMhdFfKTtsFzv2sbd2SQdbywIhh52KSUTqJY6DopLl389JtlFYYDB8MBL63ntS3zXiyraxPG63e0NkkSCan4aNEJLHDuUenwc6ZV4fc8cv8VOSJ2_07U1Uf4lpcNr_1mBj0WbfjyXfyaPMZqmpkUQV68Q9kzoXG9KZ1tZbYUGV9L6_0Xgqe47U6BMyb9jweqcGmItS8MGWt_1iHCwC23niuwiy9Bhyr9uChWUXAAWNDSwFa9tWoVx49W8_0Ar_0SYO1A4IKKBsYPVjcCX9bfjZ_0NRIV8nszuH2ZG_182oG2a6jfoEydKNCE



#ifndef SPL_OPER_INSTANCE_JOINEDFILESTREAM_H_
#define SPL_OPER_INSTANCE_JOINEDFILESTREAM_H_

#include <deque>
#include <SPL/Runtime/Operator/Operator.h>
#include <SPL/Runtime/Operator/ParameterValue.h>
#include <SPL/Runtime/Operator/OperatorContext.h>
#include <SPL/Runtime/Operator/Port/AutoPortMutex.h>
#include <SPL/Runtime/ProcessingElement/PE.h>
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Utility/CV.h>
using namespace UTILS_NAMESPACE;

#include "../type/BeJwrMSo2LUmtKDGEUEYAMgkFDk.h"
#include "../type/BeJwrMSw2ycnMSwUADOECD1.h"

#include <bitset>

#define MY_OPERATOR JoinedFileStream$OP
#define MY_BASE_OPERATOR JoinedFileStream_Base
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
    typedef int32_t PartitionByType; 

    typedef std::deque<const Tuple*> DequeType;
    struct OneQueueSet 
    {
        OneQueueSet () : _nonEmptyQueues(0)
             {}
        DequeType _tuples[2];
        uint32_t _nonEmptyQueues;
        
    };

    

    MY_OPERATOR();
    ~MY_OPERATOR();
  
    virtual void process(Tuple const & tuple, uint32_t port);

    

private:
    Mutex _mutex;
    
        OneQueueSet Tuples;
    
}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_JOINEDFILESTREAM_H_


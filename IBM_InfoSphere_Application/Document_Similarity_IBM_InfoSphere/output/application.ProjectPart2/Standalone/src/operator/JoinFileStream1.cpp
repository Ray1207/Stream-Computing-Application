// eJylUctugzAQ1P5K1EN7wQ964pYWWilNVCTEoafIAou4gI3MRjR_1X8dJIypIeqh8sHd2xzNj910TWNkIVEaLJopWRmmgfnFYBAHBQyfJk1wNdpMZvs5bfItfkzz5WG6q_0iWug91iMjfwQ6Hdli_1j9_0Q5ZscZCo_1QKLyjkKXrKFIaQw4eYROET5DwFwJkZ1pJerRStL0oW6VJdioy3JfKkMHYuu9EIUlqzacskG1TYZGTUqAAbbT0ASmoztiLqSv2QYF1o4wWZq8R2MgKO2dy3WtN5prgz07UOs9KV648CbP_1CfNbwuG8MAUzk3nua6F18hxQfiEbXXD2_1ANc3jCoJG6PYvcPnsP_15rARx2f5BtobL7C




#include "./JoinFileStream1.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR JoinFileStream1_Base
#define MY_OPERATOR JoinFileStream1$OP


#include <SPL/Runtime/Operator/OperatorMetrics.h>
#include <SPL/Runtime/Utility/LogTraceMessage.h>

MY_OPERATOR_SCOPE::MY_OPERATOR::MY_OPERATOR()
: MY_BASE_OPERATOR(),
  _windowLHS(*this, 0, ::SPL::CountWindowPolicy(lit$0), ::SPL::CountWindowPolicy(lit$1)),
  _winLHSHandler (*this),
  _windowRHS(*this, 1, ::SPL::CountWindowPolicy(lit$2), ::SPL::CountWindowPolicy(lit$3)),
  _winRHSHandler (*this),
  _lhsPartitionCount(getContext().getMetrics().getCustomMetricByName("nCurrentPartitionsLHS")),
  _rhsPartitionCount(getContext().getMetrics().getCustomMetricByName("nCurrentPartitionsRHS"))
{

    if (lit$1 != 1)
        SPLTRACEMSG(L_ERROR, SPL_APPLICATION_RUNTIME_INVALID_COUNT_BASED_TRIGGER_SIZE(lit$1), SPL_OPER_DBG);
    if (lit$3 != 1)
        SPLTRACEMSG(L_ERROR, SPL_APPLICATION_RUNTIME_INVALID_COUNT_BASED_TRIGGER_SIZE(lit$3), SPL_OPER_DBG);
    _windowLHS.registerBeforeTupleEvictionHandler(&_winLHSHandler);
    _windowRHS.registerBeforeTupleEvictionHandler(&_winRHSHandler);
    
    
    
        
    
    
    
    _emptyCountLHS = (lit$0==0) && (_windowLHS.getEvictionPolicy().getType()==WindowPolicy::Count);
    _emptyCountRHS = (lit$2==0) && (_windowRHS.getEvictionPolicy().getType()==WindowPolicy::Count);
    _lhsPartitionCount.setValueNoLock(0);
    _rhsPartitionCount.setValueNoLock(0);
}

MY_OPERATOR_SCOPE::MY_OPERATOR::~MY_OPERATOR()
{
    // Delete any remaining tuples in the windows
    _windowLHS.deleteWindowObjects();
    _windowRHS.deleteWindowObjects();
}





void MY_OPERATOR_SCOPE::MY_OPERATOR::cleanLHS (Tuple& tuple)
{
    
    _lhsPartitionCount.setValueNoLock (_windowLHS.getWindowStorage().size());
    delete &tuple;
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::evictLHS (Tuple& tuple)
{
    
    cleanLHS (tuple);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::cleanRHS (Tuple& tuple)
{
    
    _rhsPartitionCount.setValueNoLock (_windowRHS.getWindowStorage().size());
    delete &tuple;
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::evictRHS (Tuple& tuple)
{
    
    cleanRHS (tuple);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple const & tuple, uint32_t port) {
    AutoPortMutex apm(_mutex, *this);
    bool match = false;
    if (port == 0) { // LHS
        const IPort0Type& iport$0 = static_cast<const IPort0Type&>(tuple);
        
        
        if (!_emptyCountRHS) {
            AutoWindowDataAcquirer<IPort1Type*,PartitionByRHSType> awda(_windowRHS);
            
                const WindowRHSType::StorageType& map = awda.getWindowStorage();
                WindowRHSType::StorageType::const_iterator it;
                for (it = map.begin(); it != map.end(); it++) {
                    const WindowRHSType::DataType& data = it->second;
                    WindowRHSType::DataType::const_iterator it2;
                    for (it2 = data.begin(); it2 != data.end(); it2++) {
                        const IPort1Type& iport$1 =
                            static_cast<const IPort1Type&>(**it2);
                        if (true) {
                            match = true;
                            
                            OPort0Type otuple (iport$0.get_line(), iport$1.get_line());
                            submit (otuple, 0);
                        }
                    }
                }
            
            _rhsPartitionCount.setValueNoLock (_windowRHS.getWindowStorage().size());
        }
        if (!_emptyCountLHS) {
            IPort0Type *newTuple = new IPort0Type(tuple);
            
            
            _windowLHS.insert (newTuple);
            _lhsPartitionCount.setValueNoLock (_windowLHS.getWindowStorage().size());
        } else {
                        
        }
    } else { // RHS
        const IPort1Type& iport$1 = static_cast<const IPort1Type&>(tuple);
        
        
        if (!_emptyCountLHS) {
            AutoWindowDataAcquirer<IPort0Type*,PartitionByLHSType> awda(_windowLHS);
            
                const WindowLHSType::StorageType& map = awda.getWindowStorage();
                WindowLHSType::StorageType::const_iterator it;
                for (it = map.begin(); it != map.end(); it++) {
                    const WindowLHSType::DataType& data = it->second;
                    WindowLHSType::DataType::const_iterator it2;
                    for (it2 = data.begin(); it2 != data.end(); it2++) {
                        const IPort0Type& iport$0 = static_cast<const IPort0Type&>(**it2);
                        if (true) {
                            match = true;
                            
                            OPort0Type otuple (iport$0.get_line(), iport$1.get_line());
                            submit (otuple, 0);
                        }
                    }
                }
            
        }
        if (!_emptyCountRHS) {
            IPort1Type *newTuple = new IPort1Type(tuple);
            
            
            _windowRHS.insert (newTuple);
        } else {
                 
        }
    }
    if (match)
        submit(Punctuation::WindowMarker, 0);
}

static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("JoinFileStream1",&initer));
    return true;
}

template<class T> static void initRTC (SPL::Operator& o, T& v, const char * n) {
    SPL::ValueHandle vh = v;
    o.getContext().getRuntimeConstantValue(vh, n);
}

MY_BASE_OPERATOR::MY_BASE_OPERATOR()
 : Operator() {
    PE & pe = PE::instance();
    uint32_t index = getIndex();
    initRTC(*this, lit$0, "lit$0");
    initRTC(*this, lit$1, "lit$1");
    initRTC(*this, lit$2, "lit$2");
    initRTC(*this, lit$3, "lit$3");
    (void) getParameters(); // ensure thread safety by initializing here
    $oportBitset = OPortBitsetType(std::string("011"));
}
MY_BASE_OPERATOR::~MY_BASE_OPERATOR()
{
    for (ParameterMapType::const_iterator it = paramValues_.begin(); it != paramValues_.end(); it++) {
        const ParameterValueListType& pvl = it->second;
        for (ParameterValueListType::const_iterator it2 = pvl.begin(); it2 != pvl.end(); it2++) {
            delete *it2;
        }
    }
}

void MY_BASE_OPERATOR::tupleLogic(Tuple const & tuple, uint32_t port) {
    switch(port) {
    }
}


void MY_BASE_OPERATOR::processRaw(Tuple const & tuple, uint32_t port) {
    tupleLogic (tuple, port);
    static_cast<MY_OPERATOR_SCOPE::MY_OPERATOR*>(this)->MY_OPERATOR::process(tuple, port);
}


void MY_BASE_OPERATOR::punctLogic(Punctuation const & punct, uint32_t port) {
}

void MY_BASE_OPERATOR::processRaw(Punctuation const & punct, uint32_t port) {
    punctLogic (punct, port);
    
    if (punct == Punctuation::FinalMarker) {
        process(punct, port);
        bool forward = false;
        {
            AutoPortMutex $apm($fpMutex, *this);
            $oportBitset.reset(port);
            if ($oportBitset.none()) {
                $oportBitset.set(2);
                forward=true;
            }
        }
        if(forward)
            submit(punct, 0);
        return;
    }
    
    process(punct, port);
}





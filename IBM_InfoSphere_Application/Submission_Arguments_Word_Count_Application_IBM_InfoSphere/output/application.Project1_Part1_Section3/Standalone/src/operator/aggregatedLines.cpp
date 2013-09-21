// eJyVU2Fr2zAU5P2TUPqhgRDZ8QZDlIIbyCC4bYhaMvqlaLLqKJElIclL0l9fWU7TQLutwdg82Xfne6cnZ_0TQckm90IpKjPOqsryinkMSr_09wNhyi50axFoGoMVKwiEZCCT9cnv0dYKxm3Ll_1Yix3jTzI_0J3h6JpPN_1aGbLYvq_1vbHdsWBfuWFOzHH1JNyG5eT_0dssZhTNTH3a7khi2l_0t2X5aPyJSCC_0MHVDdtnd7TibFYm_0fnDrR_1Hwa5L_1fJb5qmxJKTgfOj53TQ1kVmD8VTLACKTw50lHs85boSqI79JTpQAtdc1R0OC0drSshUKkWxDflEKjjbZrZyjjaGb1ijOfPs2oDU_1CY7AZKqmnoLRqdy8NtzDaHux92YoA2_1ITphvlIY1koXw2CpoYx6Uz8olR5y_1fPw56xyH0rjBuARcxn36cJYAsRKO4g04t9FO_01WxJ7VvdOtcfnZ8_0EVCHTlLoZoyEaHxjJL_0Mf_0lFJ4Oujk72dXRyBem4cV7XwXK08FtryakKzjA_0mt_02d_0EvDvPT_1w96fyTeCYPefo_16J27SB_0muyyMrIcZXCvRADQ




#include "./aggregatedLines.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR aggregatedLines_Base
#define MY_OPERATOR aggregatedLines$OP


#include <SPL/Toolkit/TumblingAggregate.h>
#include <SPL/Runtime/Window/TumblingWindowSummarizer.h>

#include <SPL/Runtime/Operator/OperatorMetrics.h>

#define MY$OP MY_OPERATOR_SCOPE::MY_OPERATOR
struct MY_OPERATOR::Tumbling$aggregatedLines :
	public  SPL::TumblingWindowSummarizer<MY$OP::IPort0Type,MY$OP::PartitionByType>{
    MY$OP& _oper;
    uint64_t _count;
    Tumbling$aggregatedLines (SPL::Operator& oper)
    : _oper(static_cast<MY$OP&>(oper)) {
	_count = 0;
	::application::init(_oper.state$sum);
    }
    void onTupleInsertionEvent(MY$OP::IPort0Type const& tuple) {
	_count++;
	MY$OP::IPort0Type const & iport$0 = static_cast<MY$OP::IPort0Type const>(tuple);
	::application::process(_oper.state$sum, iport$0);
    }
};


MY_OPERATOR_SCOPE::MY_OPERATOR::MY_OPERATOR()
  : MY_BASE_OPERATOR(), _window(*this, 0, ::SPL::CountWindowPolicy(::SPL::spl_cast<SPL::int32, SPL::rstring >::cast(lit$0))),
  _partitionCount(getContext().getMetrics().getCustomMetricByName("nCurrentPartitions"))
{

    _window.registerBeforeWindowFlushHandler(this);
    
        _window.registerWindowSummarizer<MY_OPERATOR::Tumbling$aggregatedLines>();
    
    


    _partitionCount.setValueNoLock(0);
}

MY_OPERATOR_SCOPE::MY_OPERATOR::~MY_OPERATOR()
{
    // Delete any remaining tuples in the window
    _window.deleteWindowObjects();
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple const & tuple, uint32_t port) 
{
    AutoPortMutex apm(_mutex, *this);
    IPort0Type const & iport$0 = static_cast<IPort0Type const&>(tuple);   

    
        _window.insert(iport$0);
    

    _partitionCount.setValueNoLock (_window.getWindowStorage().size());
}



void MY_OPERATOR_SCOPE::MY_OPERATOR::beforeWindowFlushEvent(
        WindowEventType::WindowType & window, 
        WindowEventType::PartitionType const & partition) 
{
    
        WindowType& twindow = static_cast<WindowType&>(window);
        MY_OPERATOR::Tumbling$aggregatedLines& summarizer =
            *static_cast<MY_OPERATOR::Tumbling$aggregatedLines*>(twindow.getSummarizer(partition));
    



    
        if (summarizer._count == 0) {
    
            submit(Punctuation::WindowMarker, 0);
            return;
        }



    
    

        // Populate the tuple
        
        
        SPL::BeJwrMSwxzjTNycxLLc40Lc8vSgFSyRmJRcWWRanFpTklwSWJAOxcA2C otuple(::application::result(state$sum));
        submit (otuple, 0);



    submit(Punctuation::WindowMarker, 0);
}





static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("aggregatedLines",&initer));
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
    state$sum = lit$1;
    (void) getParameters(); // ensure thread safety by initializing here
    $oportBitset = OPortBitsetType(std::string("01"));
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
                $oportBitset.set(1);
                forward=true;
            }
        }
        if(forward)
            submit(punct, 0);
        return;
    }
    
    process(punct, port);
}






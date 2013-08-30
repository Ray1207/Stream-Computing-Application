// eJyVkm9rwjAQxrlvMoYvJgzT6AajjEEnOJBuc8bh2LssjRpNk5CkU_1fpl7bqhP1TQuDS3HP9PZdzRrYsl9QLraiM42Q6tXxKPYeoWpdw2mqhSaFYmYGoMVKwKhsJJXxrdvp7grGacef_0zLHcFXJXxq8NR7e8v7T3ZLn6mI8e1myVpuwiStnVO5n2yHqY94dsPB5S1TOjhVyScT95XLGk3f2hSBB_0MHVP1p3Hh25nkEb69tktXsXzSy_05m8hknpUiDM4Hxw1X5EAGaRwfKgZogxS_0EdUyoXynDdUXfGwhQDOdc_0S85TR3NMuFQqQ_0EF9kQqOltgtnKONoYPWcM48H1Hr8VHBXdrKNMuopKK3Kp8NhC6Ptju1gEgG21EdMF8oD3jOGN17LBdAJJ8Ud1HcBLtvGbEbtNi459HeO4x8X8sCFoR4XEoz6wkh_0Xf3lpCI5r_0OKZBNXJDeAu4XzOg_1IFcKb1pJTFcjieG8US5vCn_01GoflP9ma6vwTnJ5uON49s_0bfStcs9lNDGTw43C82




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
  : MY_BASE_OPERATOR(), _window(*this, 0, ::SPL::CountWindowPolicy(lit$0)),
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






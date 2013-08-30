// eJyNUt9PwjAQzv0nxvAAiVk3UKJ72wgvwBAziL6ROsoodO3S3kK2v94NcKCiM5c_0tPnuvh89kwpLM0GRK0mF63pxrFlMkYF9qAe4tSyyzmRUIQhNU8GjA5pwydHa3P4OSLWKmDF_1YjQzmajHYJ4y4rPRXgdvL0Ug_1WCeP43ni0cTLuxRYYppMdyZnOep7_1l7HYv4eud0sH0ugl4QhsV4Mt4NvQHve6_0LCuyAwdJeqza6CnnCBdUc8zBSmkE4m7juWiiK_1XuALgiOLfv4yiX2unB4cb7hgGxUwohBzWhi6CrhkoTHS4jZiiuyV3pnUhoxMtNqyyJ0ljOqsUtWFClIJavMnfLwVOmasskTcNBVnx2pTCI4Fzqdk_1SqoDJeG4VP2RWdukr3n_1AhKbkduBblmWGQGVQJ9I7z35USjMqS1nUv9qCSzLHd8DWdhhmnhWsac3dzStiKGS7PqbQ7na_0f_0oPguK2NMstUPwCd8xuc




#include "./AggregateSimilarity.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR AggregateSimilarity_Base
#define MY_OPERATOR AggregateSimilarity$OP


#include <SPL/Toolkit/TumblingAggregate.h>
#include <SPL/Runtime/Window/TumblingWindowSummarizer.h>

#include <SPL/Runtime/Operator/OperatorMetrics.h>

#define MY$OP MY_OPERATOR_SCOPE::MY_OPERATOR
struct MY_OPERATOR::Tumbling$AggregateSimilarity :
	public  SPL::TumblingWindowSummarizer<MY$OP::IPort0Type,MY$OP::PartitionByType>{
    MY$OP& _oper;
    uint64_t _count;
    Tumbling$AggregateSimilarity (SPL::Operator& oper)
    : _oper(static_cast<MY$OP&>(oper)) {
	_count = 0;
	::application::init(_oper.state$AggregatedSimilarityScore);
    }
    void onTupleInsertionEvent(MY$OP::IPort0Type const& tuple) {
	_count++;
	MY$OP::IPort0Type const & iport$0 = static_cast<MY$OP::IPort0Type const>(tuple);
	::application::process(_oper.state$AggregatedSimilarityScore, iport$0.get_similarity());
    }
};


MY_OPERATOR_SCOPE::MY_OPERATOR::MY_OPERATOR()
  : MY_BASE_OPERATOR(), _window(*this, 0, ::SPL::CountWindowPolicy(lit$0)),
  _partitionCount(getContext().getMetrics().getCustomMetricByName("nCurrentPartitions"))
{

    _window.registerBeforeWindowFlushHandler(this);
    
        _window.registerWindowSummarizer<MY_OPERATOR::Tumbling$AggregateSimilarity>();
    
    


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
        MY_OPERATOR::Tumbling$AggregateSimilarity& summarizer =
            *static_cast<MY_OPERATOR::Tumbling$AggregateSimilarity*>(twindow.getSummarizer(partition));
    



    
        if (summarizer._count == 0) {
    
            submit(Punctuation::WindowMarker, 0);
            return;
        }



    
    

        // Populate the tuple
        
        
        SPL::BeJwrMXQzMnBMTy9KTU8sSU0JzszNzEksyiypBABwrglg otuple(::application::result(state$AggregatedSimilarityScore));
        submit (otuple, 0);



    submit(Punctuation::WindowMarker, 0);
}





static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("AggregateSimilarity",&initer));
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
    state$AggregatedSimilarityScore = lit$1;
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






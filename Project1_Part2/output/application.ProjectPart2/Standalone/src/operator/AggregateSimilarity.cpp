// eJyNUsFugkAQzfxJ03jQpGFBW9NyE_0NFxdqgaW9miyuuLrtkd4iBry_0gVVu1NGQPzLyZee_1NmERYmgmKXEkqXLcXRZpFFBnY1fcE95ZFVqkMSwShSSJ4WKEJlxyt9f1tQKJVyIz5E6OZScWxDWYJIx4b7rT_18Zb70vNn2ctoNn82wdwe5iaf5IOtyXiWeD1vpyMRXa_0c9Devud_1xgyAfjUfbQa_1Pu733eQl2wGAhr3EUugx4zAXVHLMgVJpBMB277kooit1HgA4Ijg17H_0USO22oIs5FpP2rEshaxYwY1IzGhi5jLkmw_1wkwXXJFdkpvTUJDRqZabViIzmJKNbbJkiIFqWS5Bad4PFH6SKJOJXDQZZ0dqlQiOGc8nYOYInsrWY6D0qWjK_1CtqEypq0z_0symIC1oOXPP9NKGfGlRxYXrV_11Mpwagsxrru2dGUhDk2a_1bYqulxuM66Ng93B_1OtiOHi5Eqz1fq574sB_09OupVm4_0gVNQyfD




#include "./AggregateSimilarity.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR AggregateSimilarity_Base
#define MY_OPERATOR AggregateSimilarity$OP


#include <SPL/Toolkit/Aggregate.h>

#include <SPL/Runtime/Operator/OperatorMetrics.h>



MY_OPERATOR_SCOPE::MY_OPERATOR::MY_OPERATOR()
  : MY_BASE_OPERATOR(), _window(*this, 0, ::SPL::CountWindowPolicy(lit$0), ::SPL::CountWindowPolicy(lit$1)),
  _partitionCount(getContext().getMetrics().getCustomMetricByName("nCurrentPartitions"))
{

    _window.registerOnWindowTriggerHandler(this);
    
        _window.registerOnWindowInitialFullHandler(this);
    
    _window.registerBeforeTupleEvictionHandler(this);


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

    
        _window.insert(new IPort0Type(iport$0));
    

    _partitionCount.setValueNoLock (_window.getWindowStorage().size());
}



void MY_OPERATOR_SCOPE::MY_OPERATOR::onWindowTriggerEvent(
        WindowEventType::WindowType & window, 
        WindowEventType::PartitionType const & partition) 
{
    


    if (_windowFull.find(partition) == _windowFull.end())
        return;


    
        WindowType::DataType & data = window.getWindowData(partition);
        if (data.size() == 0) {
    
            submit(Punctuation::WindowMarker, 0);
            return;
        }



    
                ::application::init(state$AggregatedSimilarityScore);
                
        
    
    
        WindowType::DataType::const_iterator it;
        for (it = data.begin(); it != data.end(); it++) {
            IPort0Type const & iport$0 = **it;
            
                    ::application::process(state$AggregatedSimilarityScore, iport$0.get_similarity());
                    
          }
    

        // Populate the tuple
        
            IPort0Type const & iport$0 = **data.rbegin();
        
        
        SPL::BeJwrMXQzMnBMTy9KTU8sSU0JzszNzEksyiypBABwrglg otuple(::application::result(state$AggregatedSimilarityScore));
        submit (otuple, 0);



    submit(Punctuation::WindowMarker, 0);
}




    
    void MY_OPERATOR_SCOPE::MY_OPERATOR::onWindowInitialFullEvent(WindowEventType::WindowType & window, 
                                               WindowEventType::PartitionType const & partition) 
    {
        _windowFull.insert (partition);
    }
    

void MY_OPERATOR_SCOPE::MY_OPERATOR::beforeTupleEvictionEvent(WindowEventType::WindowType & window, 
                                           WindowEventType::TupleType & tuple, 
                                           WindowEventType::PartitionType const & partition)
{
    delete tuple;
    _partitionCount.setValueNoLock (_window.getWindowStorage().size());
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
    initRTC(*this, lit$2, "lit$2");
    state$AggregatedSimilarityScore = lit$2;
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






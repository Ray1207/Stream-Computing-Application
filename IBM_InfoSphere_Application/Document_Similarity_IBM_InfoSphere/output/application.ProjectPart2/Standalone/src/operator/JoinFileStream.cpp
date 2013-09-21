// eJydkEFrwzAMhdFfKTtsFzv2sbd2SQdbywIhh52KSUTqJY6DopLl389JtlFYYDB8MBL63ntS3zXiyraxPG63e0NkkSCan4aNEJLHDuUenwc6ZV4fc8cv8VOSJ2_07U1Uf4lpcNr_1mBj0WbfjyXfyaPMZqmpkUQV68Q9kzoXG9KZ1tZbYUGV9L6_0Xgqe47U6BMyb9jweqcGmItS8MGWt_1iHCwC23niuwiy9Bhyr9uChWUXAAWNDSwFa9tWoVx49W8_0Ar_0SYO1A4IKKBsYPVjcCX9bfjZ_0NRIV8nszuH2ZG_182oG2a6jfoEydKNCE




#include "./JoinFileStream.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR JoinFileStream_Base
#define MY_OPERATOR JoinFileStream$OP


MY_OPERATOR_SCOPE::MY_OPERATOR::MY_OPERATOR()
: MY_BASE_OPERATOR()
{
    
}



MY_OPERATOR_SCOPE::MY_OPERATOR::~MY_OPERATOR()
{
    // Delete any remaining tuples in the windows
    
        for (uint32_t i = 0; i < 2; i++) {
            DequeType& d = Tuples._tuples[i];
            for (DequeType::iterator it = d.begin(); it != d.end(); it++)
                delete *it;
        }
    
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple const & tuple, uint32_t port)
{
    const Tuple *inputTuples[2];
    {
        AutoMutex am(_mutex);
        
        if (Tuples._tuples[port].empty())
            Tuples._nonEmptyQueues++;
        Tuples._tuples[port].push_back (tuple.clone());
        if (Tuples._nonEmptyQueues != 2)
            return;

        
        for (uint32_t i = 0; i < 2; i++) { // clean up
            DequeType& d = Tuples._tuples[i];
            inputTuples[i] = d.front();
            
            d.pop_front();
            if (d.empty())
                Tuples._nonEmptyQueues--;
        }
        
        
    }

    // Now we can submit the output tuple and delete the input tuples
    
        const IPort0Type& iport$0 =
            static_cast<const IPort0Type&>(*inputTuples[0]);
    
        const IPort1Type& iport$1 =
            static_cast<const IPort1Type&>(*inputTuples[1]);
    

    OPort0Type otuple (iport$0.get_line(), iport$1.get_line());
    submit (otuple, 0);

    // Now delete the saved input tuples
    for (uint32_t i = 0; i < 2; i++)
        delete inputTuples[i];
}

static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("JoinFileStream",&initer));
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





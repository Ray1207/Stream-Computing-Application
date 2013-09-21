// eJyVUtFqwyAU5f5K2UP7Ek3TJ9_1adB2Mbg2EsLGXIsY2tokGNYTs62fM1haWUcYFRT333Hvu0dRloHlJrVCSloRsGsms0oB9LGASBOjQ37l3ROu6FMxjEVONtHFBNWWWaxMUkzvYN6XzC8x2NUcr_1tzql7Sdd0y6LVuud4_1xOhzBsAX_07DFdtHuNo2SL1Soz5w_0RvW_0WT4dyecr7JAwhlMI_0YEiTLSFC2mgOAKhQFUfGak4rQ_1NKSJQOh9Q2uVCoVfpsaso4SrQ6cWbDfUK1W1PutUQop5aCVJL7GhhErfSlzh8yQMAwRvBtuVztehDy6BnUb4b7IqFylJEnMzDIC13cqP0ZQNsPexyCgZAbcwi5ujP91hUcud33VaazGTDn8b_0orp9ijM_0J_1wIML8Vd


#include "./OneLine.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR OneLine_Base
#define MY_OPERATOR OneLine$OP




void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple const & tuple, uint32_t port) 
{
   IPort0Type const & iport$0 = static_cast<IPort0Type const&>(tuple);
   if (! (1) ) 
       return;
   { OPort0Type otuple(lit$0, ::application::countWords(iport$0.get_line()), ::application::countCharacters(iport$0.get_line())); submit (otuple, 0);
 }
   
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Punctuation const & punct, uint32_t port) 
{
   forwardWindowPunctuation(punct);
}

static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("OneLine",&initer));
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






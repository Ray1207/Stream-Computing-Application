// eJyVj01Lw0AQhpmrv6IUDwlINomguIpgBRGbhkDSi5eyJku6Nvvh7qwx_1966jXiWOb3M8w7PODMkHsUgcKL00TvUEtIwGSyThOBkOFnxl9Fu6o_083lxX61SV6_0ngy6YZp_1aruKk_1y2ar8aFfXb328jnZL0MfyF5LThxazqRjnRSK1KdQo_0_0EJqO2B2dYy0ll9TtvMauYxYx0DBkorXiwSEEYbfE8hboqKP2XCwiwQYbSUH7yqkWhlaN0_0_1u0sULhUUyovlDRDDoz7Frm8C4k68L6YhGSP_1KX_0eKe0h8imu2SnuOuEIqXXr5xG8VxfHsGkEOrFXKFDuYr8AfB6RSk3_11pH9l


#include "./Sink.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>


#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR Sink_Base
#define MY_OPERATOR Sink$OP



static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("Sink",&initer));
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
    IPort0Type const & iport$0 = static_cast<IPort0Type const  &>(tuple);
    AutoPortMutex $apm($svMutex, *this);
    
::SPL::Functions::Utility::printStringLn(::SPL::spl_cast<SPL::rstring, SPL::uint32 >::cast(iport$0.get_LineNumber()));

}


void MY_BASE_OPERATOR::processRaw(Tuple const & tuple, uint32_t port) {
    tupleLogic (tuple, port);
    static_cast<MY_OPERATOR_SCOPE::MY_OPERATOR*>(this)->MY_OPERATOR::process(tuple, port);
}


void MY_BASE_OPERATOR::punctLogic(Punctuation const & punct, uint32_t port) {
}

void MY_BASE_OPERATOR::processRaw(Punctuation const & punct, uint32_t port) {
    punctLogic (punct, port);
    
    process(punct, port);
}






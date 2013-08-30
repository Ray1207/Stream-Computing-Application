// eJx1UF1rg0AQZP9K6LN3RinFt1ST0phEqeY5XHXTXP042Tsj5tf3TGhpoGXh9gZmZ3ZWd7UjStEZpCDIwzRTPRUI_1FoezByHmbFD9ozrgbbZMB_0L1rb9IkqWYeQ6p9kdZ6TdK_1dy6ffb8bGLo1Uy6uGSF7TOn_1yf2ePBHdah_0mtYeTH3TVxps63Oybi_17OJhuUjS4SXcTXwOLtTSPHDI0k0Q9LI13hwA2Ek1yLQhFI0WZSNblt1AZvpSKjYoqnQnCmQpqU8sjHtIBdk3s3_0pWp_0VwghoVYs2N6karVOmigrN2wQ4aKQzEoS9NqrZSHsxUUOnyEzEX8t8L7gwhuR7b3BFiHBU1IiJGlmb1Q1wy7R294pTQg5qEv5O_0c_1xoQG6ulkNstFl_0wGcfwFly5RR




#include "./Data.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>


#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR Data_Base
#define MY_OPERATOR Data$OP


#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fstream>


#include <streams_boost/iostreams/stream.hpp>
#include <streams_boost/iostreams/filtering_streambuf.hpp>
#include <streams_boost/iostreams/device/file_descriptor.hpp>

#include <SPL/Runtime/Common/ApplicationRuntimeMessage.h>
#include <SPL/Toolkit/IOHelper.h>
#include <SPL/Toolkit/RuntimeException.h>
#include <SPL/Runtime/Operator/OperatorMetrics.h>

using namespace std;
using namespace streams_boost::iostreams;


// defines for error checking conditions
#define CHECK_FAIL      \
    if (failedRead)                                   \
        _numInvalidTuples.incrementValueNoLock()

    #define DO_ERROR(msg)                             \
        do { _numInvalidTuples.incrementValueNoLock();   \
          const FormattableMessage& $msg = msg;       \
          SPLTRACEMSG (L_ERROR, $msg, SPL_OPER_DBG);  \
          THROW (SPLRuntimeFileSourceOperator, $msg);} while (0)
    #define DO_ERROR_FILESOURCE(msg) DO_ERROR(msg)
    #define CHECK_ERROR(msg)                          \
        if (fs.fail() && !getPE().getShutdownRequested()) \
            DO_ERROR(msg)


MY_OPERATOR_SCOPE::MY_OPERATOR::MY_OPERATOR()
    : MY_BASE_OPERATOR(), _fd(0), _connector(0),
        _tupleNumber(0), 
        
        
        
        
        _numInvalidTuples( getContext().getMetrics().getCustomMetricByName("nInvalidTuples")),
        _numReconnects(getContext().getMetrics().getCustomMetricByName("nReconnections")),
        _numConnections(getContext().getMetrics().getCustomMetricByName("nConnections")),
        _numWireFormatHandshakesFailed(getContext().getMetrics().getCustomMetricByName("nConfirmWireFormatFailures"))
{
    _numInvalidTuples.setValueNoLock(0);
    _numReconnects.setValueNoLock(0);
    _numConnections.setValueNoLock(0);
    _numWireFormatHandshakesFailed.setValueNoLock(0);
}


void MY_OPERATOR_SCOPE::MY_OPERATOR::allPortsReady()
{
    createThreads (1);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::prepareToShutdown()
{
    if (_fd) {
        shutdown (_fd, SHUT_RDWR); // try to clean things up nicely
        _fd = 0;
    }
    if (_connector)
        _connector->terminate();
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(uint32_t) 
{
    SPLAPPTRC(L_DEBUG, "TCPSource startup...", SPL_OPER_DBG);
    SPL::BeJwrMSw2ycnMSwUADOECD1 tuple$;
    
    
    try {
        SPL::TCPServer conn (getPE());
        
        
            
            
            
                conn.setup (lit$0);
            
        

        _fd = conn.fileDescriptor();
        SPLAPPTRC(L_DEBUG, "TCPSource connected.  File descriptor = " << _fd, SPL_OPER_DBG);
        _numConnections.setValueNoLock(1);
        _connector = &conn;

        
            while (!getPE().getShutdownRequested()) {
        
                // We might have failed due to handshake failure
                if (conn.connected()) {
                    _tupleNumber = 0; 
                    file_descriptor_source fd_src (_fd, false);
                    filtering_streambuf<input> filt_str;
                    
                    filt_str.push (fd_src);
                    
                        istream fs (&filt_str);
                    
                    fs.imbue(locale::classic());





bool failedRead = false;
while(!getPE().getShutdownRequested() && !fs.eof()) {
    _tupleNumber++;
    if (SPL::safePeek(fs) == EOF) break;
    bool doSubmit = true;
    try {
        
            SPL::rstring& t = tuple$.get_line();
            std::getline (fs, t, '\n');
            
            if (fs.fail() || (fs.eof() && t.empty())) break;
        



    } catch (const std::exception& e) {
        DO_ERROR(SPL_APPLICATION_RUNTIME_EXCEPTION(e.what()));
        _numInvalidTuples.incrementValueNoLock();
        doSubmit = false;
    } catch (...) {
        DO_ERROR(SPL_APPLICATION_RUNTIME_UNKNOWN_EXCEPTION);
        _numInvalidTuples.incrementValueNoLock();
        doSubmit = false;
    }
    if (doSubmit)
        submit (tuple$, 0);
}

                    
                        submit (Punctuation::WindowMarker, 0);
                    
                }
                _numConnections.setValueNoLock(0);

                
        
                _fd = conn.reconnect();
                _numConnections.setValueNoLock(1);
                _numReconnects.incrementValueNoLock();
            }
        
        conn.terminate();
    } catch (...) {
        // If we get here, we had an exception, and the throw will destruct conn.
        // Ensure that we don't try to do it twice.
        _fd = 0; // no longer using this
        _connector = 0;
        throw;
    }
    _fd = 0; // no longer using this
    _connector = 0;
    
    SPLAPPTRC(L_DEBUG, "TCPSource exiting...", SPL_OPER_DBG);
}

static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("Data",&initer));
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
    param$role$0 = "server";
    addParameterValue ("role", SPL::ConstValueHandle(param$role$0));
    addParameterValue ("port", SPL::ConstValueHandle(lit$0));
    param$format$0 = "line";
    addParameterValue ("format", SPL::ConstValueHandle(param$format$0));
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





// eJx1kV9vgjAUxXO_1itkzLUqWhTcHukxUyMBn08F1dvwpuS0j_0OlX3FyicWnS9jS_1e8_1JrW4rRxSiNUi_0nwVJqjrKEfh5zWDiOMwMLbJnXPW0SfvpkDf22M3DeBGErnOcXDEDbV_15LJNetxke2yhcxoPuT1lOq_0zJ_06s97N1_0Fah7xWoWcc9EpTab8isedqdt1C_1mcdK_1BNuR5zCFSpoHDmmy9n3ShmTzAec39_0YN2FHVyKxEUWtR1LJh6Y9ITVdIxXpFpW5Fjiwh9Ym5cfeJILun9i5VM2WFMAIa1SB4QKpCsCYqL9G8jYJDXklsDASdNqpeSztGUYEoCkKt4SaQ_05t8bqx_07wwuCRFaReY_06d6QB0W1GNnQhlr_0CG5JG_07an1uGgxo7Xwb1z_19BDXR2sz0u5px_1A_0cwKqc




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
        SPL::TCPClient conn (getPE());
        
        
            
                conn.setup (lit$0,lit$1);
            
        

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
    initRTC(*this, lit$1, "lit$1");
    param$role$0 = "client";
    addParameterValue ("role", SPL::ConstValueHandle(param$role$0));
    addParameterValue ("address", SPL::ConstValueHandle(lit$0));
    addParameterValue ("port", SPL::ConstValueHandle(lit$1));
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






#include "SimulatorToForwardTargetSensor.hh"

#include "SimulationParams.hh"
#include "umlrtinsignal.hh"
#include "umlrtobjectclass.hh"
#include "umlrtoutsignal.hh"
#include "umlrtsignalregistry.hh"
struct UMLRTCommsPort;

static UMLRTObject_field fields_sendReadForwardTargetSensor[] = 
{
    {
        "sensedForwardTargetSensor",
        &UMLRTType_int,
        0,
        1,
        0
    }
};

static UMLRTObject payload_sendReadForwardTargetSensor = 
{
    sizeof( int ),
    1,
    fields_sendReadForwardTargetSensor
};

static UMLRTObject_field fields_createForwardTargetSensor[] = 
{
    {
        "simulatorParams",
        &UMLRTType_SimulationParams,
        0,
        1,
        0
    }
};

static UMLRTObject payload_createForwardTargetSensor = 
{
    sizeof( SimulationParams ),
    1,
    fields_createForwardTargetSensor
};

static UMLRTObject_field fields_readForwardTargetSensor[] = 
{
    #ifdef NEED_NON_FLEXIBLE_ARRAY
    {
        0,
        0,
        0,
        0,
        0
    }
    #endif
};

static UMLRTObject payload_readForwardTargetSensor = 
{
    0,
    #ifdef NEED_NON_FLEXIBLE_ARRAY
    1
    #else
    0
    #endif
    ,
    fields_readForwardTargetSensor
};

SimulatorToForwardTargetSensor::Base::Base( const UMLRTCommsPort * & srcPort )
: UMLRTProtocol( srcPort )
{
    UMLRTSignalRegistry & signalRegistry = UMLRTSignalRegistry::getRegistry();
    signalRegistry.registerInSignal( "SimulatorToForwardTargetSensor", "sendReadForwardTargetSensor", signal_sendReadForwardTargetSensor, &payload_sendReadForwardTargetSensor );
    signalRegistry.registerOutSignal( "SimulatorToForwardTargetSensor", "createForwardTargetSensor", signal_createForwardTargetSensor, &payload_createForwardTargetSensor );
    signalRegistry.registerOutSignal( "SimulatorToForwardTargetSensor", "readForwardTargetSensor", signal_readForwardTargetSensor, &payload_readForwardTargetSensor );
}

UMLRTInSignal SimulatorToForwardTargetSensor::Base::sendReadForwardTargetSensor() const
{
    UMLRTInSignal signal;
    signal.initialize( "sendReadForwardTargetSensor", signal_sendReadForwardTargetSensor, srcPort, &payload_sendReadForwardTargetSensor );
    return signal;
}

UMLRTOutSignal SimulatorToForwardTargetSensor::Base::createForwardTargetSensor( const SimulationParams & simulatorParams ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "createForwardTargetSensor", signal_createForwardTargetSensor, srcPort, &payload_createForwardTargetSensor, &simulatorParams );
    return signal;
}

UMLRTOutSignal SimulatorToForwardTargetSensor::Base::readForwardTargetSensor() const
{
    UMLRTOutSignal signal;
    signal.initialize( "readForwardTargetSensor", signal_readForwardTargetSensor, srcPort, &payload_readForwardTargetSensor );
    return signal;
}

SimulatorToForwardTargetSensor::Conj::Conj( const UMLRTCommsPort * & srcPort )
: UMLRTProtocol( srcPort )
{
    UMLRTSignalRegistry & signalRegistry = UMLRTSignalRegistry::getRegistry();
    signalRegistry.registerOutSignal( "SimulatorToForwardTargetSensor", "sendReadForwardTargetSensor", signal_sendReadForwardTargetSensor, &payload_sendReadForwardTargetSensor );
    signalRegistry.registerInSignal( "SimulatorToForwardTargetSensor", "createForwardTargetSensor", signal_createForwardTargetSensor, &payload_createForwardTargetSensor );
    signalRegistry.registerInSignal( "SimulatorToForwardTargetSensor", "readForwardTargetSensor", signal_readForwardTargetSensor, &payload_readForwardTargetSensor );
}

UMLRTOutSignal SimulatorToForwardTargetSensor::Conj::sendReadForwardTargetSensor( int sensedForwardTargetSensor ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "sendReadForwardTargetSensor", signal_sendReadForwardTargetSensor, srcPort, &payload_sendReadForwardTargetSensor, &sensedForwardTargetSensor );
    return signal;
}

UMLRTInSignal SimulatorToForwardTargetSensor::Conj::createForwardTargetSensor() const
{
    UMLRTInSignal signal;
    signal.initialize( "createForwardTargetSensor", signal_createForwardTargetSensor, srcPort, &payload_createForwardTargetSensor );
    return signal;
}

UMLRTInSignal SimulatorToForwardTargetSensor::Conj::readForwardTargetSensor() const
{
    UMLRTInSignal signal;
    signal.initialize( "readForwardTargetSensor", signal_readForwardTargetSensor, srcPort, &payload_readForwardTargetSensor );
    return signal;
}



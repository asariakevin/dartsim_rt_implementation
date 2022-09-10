
#include "AdapterInterfaceToSimulatorProtocol.hh"

#include "SimulationParams.hh"
#include "SimulationResults.hh"
#include "TacticList.hh"
#include "TeamState.hh"
#include "umlrtobjectclass.hh"
#include "umlrtsignalregistry.hh"
#include <cstddef>
#include "umlrtinsignal.hh"
#include "umlrtoutsignal.hh"
struct UMLRTCommsPort;

static UMLRTObject_field fields_sendIsFinished[] = 
{
    {
        "finished",
        &UMLRTType_int,
        0,
        1,
        0
    }
};

static UMLRTObject payload_sendIsFinished = 
{
    sizeof( int ),
    1,
    fields_sendIsFinished
};

static UMLRTObject_field fields_sendParameters[] = 
{
    {
        "simulationParams",
        &UMLRTType_SimulationParams,
        0,
        1,
        0
    }
};

static UMLRTObject payload_sendParameters = 
{
    sizeof( SimulationParams ),
    1,
    fields_sendParameters
};

static UMLRTObject_field fields_sendReadForwardTargetSensor[] = 
{
    {
        "readings",
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

static UMLRTObject_field fields_sendReadForwardTargetSensorForObservation[] = 
{
    {
        "readings",
        &UMLRTType_int,
        0,
        1,
        0
    }
};

static UMLRTObject payload_sendReadForwardTargetSensorForObservation = 
{
    sizeof( int ),
    1,
    fields_sendReadForwardTargetSensorForObservation
};

static UMLRTObject_field fields_sendReadForwardThreatSensor[] = 
{
    {
        "readings",
        &UMLRTType_int,
        0,
        1,
        0
    }
};

static UMLRTObject payload_sendReadForwardThreatSensor = 
{
    sizeof( int ),
    1,
    fields_sendReadForwardThreatSensor
};

static UMLRTObject_field fields_sendReadForwardThreatSensorForObservation[] = 
{
    {
        "readings",
        &UMLRTType_int,
        0,
        1,
        0
    }
};

static UMLRTObject payload_sendReadForwardThreatSensorForObservation = 
{
    sizeof( int ),
    1,
    fields_sendReadForwardThreatSensorForObservation
};

static UMLRTObject_field fields_sendResults[] = 
{
    {
        "simulationResults",
        &UMLRTType_SimulationResults,
        0,
        1,
        0
    }
};

static UMLRTObject payload_sendResults = 
{
    sizeof( SimulationResults ),
    1,
    fields_sendResults
};

static UMLRTObject_field fields_sendScreenOutput[] = 
{
    {
        "screenOutput",
        &UMLRTType_int,
        0,
        1,
        0
    }
};

static UMLRTObject payload_sendScreenOutput = 
{
    sizeof( int ),
    1,
    fields_sendScreenOutput
};

static UMLRTObject_field fields_sendState[] = 
{
    {
        "teamState",
        &UMLRTType_TeamState,
        0,
        1,
        0
    }
};

static UMLRTObject payload_sendState = 
{
    sizeof( TeamState ),
    1,
    fields_sendState
};

static UMLRTObject_field fields_sendStep[] = 
{
    {
        "detection",
        &UMLRTType_int,
        0,
        1,
        0
    }
};

static UMLRTObject payload_sendStep = 
{
    sizeof( int ),
    1,
    fields_sendStep
};

static UMLRTObject_field fields_createSimulator[] = 
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

static UMLRTObject payload_createSimulator = 
{
    0,
    #ifdef NEED_NON_FLEXIBLE_ARRAY
    1
    #else
    0
    #endif
    ,
    fields_createSimulator
};

static UMLRTObject_field fields_getParameters[] = 
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

static UMLRTObject payload_getParameters = 
{
    0,
    #ifdef NEED_NON_FLEXIBLE_ARRAY
    1
    #else
    0
    #endif
    ,
    fields_getParameters
};

static UMLRTObject_field fields_getResults[] = 
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

static UMLRTObject payload_getResults = 
{
    0,
    #ifdef NEED_NON_FLEXIBLE_ARRAY
    1
    #else
    0
    #endif
    ,
    fields_getResults
};

static UMLRTObject_field fields_getScreenOutput[] = 
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

static UMLRTObject payload_getScreenOutput = 
{
    0,
    #ifdef NEED_NON_FLEXIBLE_ARRAY
    1
    #else
    0
    #endif
    ,
    fields_getScreenOutput
};

static UMLRTObject_field fields_getState[] = 
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

static UMLRTObject payload_getState = 
{
    0,
    #ifdef NEED_NON_FLEXIBLE_ARRAY
    1
    #else
    0
    #endif
    ,
    fields_getState
};

static UMLRTObject_field fields_isFinished[] = 
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

static UMLRTObject payload_isFinished = 
{
    0,
    #ifdef NEED_NON_FLEXIBLE_ARRAY
    1
    #else
    0
    #endif
    ,
    fields_isFinished
};

static UMLRTObject_field fields_readForwardTargetSensor[] = 
{
    {
        "cells",
        &UMLRTType_int,
        0,
        1,
        0
    }
};

static UMLRTObject payload_readForwardTargetSensor = 
{
    sizeof( int ),
    1,
    fields_readForwardTargetSensor
};

struct params_readForwardTargetSensorForObservation
{
    int cells;
    int numOfObservations;
};

static UMLRTObject_field fields_readForwardTargetSensorForObservation[] = 
{
    {
        "cells",
        &UMLRTType_int,
        offsetof( params_readForwardTargetSensorForObservation, cells ),
        1,
        0
    },
    {
        "numOfObservations",
        &UMLRTType_int,
        offsetof( params_readForwardTargetSensorForObservation, numOfObservations ),
        1,
        0
    }
};

static UMLRTObject payload_readForwardTargetSensorForObservation = 
{
    sizeof( params_readForwardTargetSensorForObservation ),
    2,
    fields_readForwardTargetSensorForObservation
};

static UMLRTObject_field fields_readForwardThreatSensor[] = 
{
    {
        "cells",
        &UMLRTType_int,
        0,
        1,
        0
    }
};

static UMLRTObject payload_readForwardThreatSensor = 
{
    sizeof( int ),
    1,
    fields_readForwardThreatSensor
};

struct params_readForwardThreatSensorForObservation
{
    int cells;
    int numOfObservations;
};

static UMLRTObject_field fields_readForwardThreatSensorForObservation[] = 
{
    {
        "cells",
        &UMLRTType_int,
        offsetof( params_readForwardThreatSensorForObservation, cells ),
        1,
        0
    },
    {
        "numOfObservations",
        &UMLRTType_int,
        offsetof( params_readForwardThreatSensorForObservation, numOfObservations ),
        1,
        0
    }
};

static UMLRTObject payload_readForwardThreatSensorForObservation = 
{
    sizeof( params_readForwardThreatSensorForObservation ),
    2,
    fields_readForwardThreatSensorForObservation
};

struct params_step
{
    TacticList tactics;
    double decisionTimeMsec;
};

static UMLRTObject_field fields_step[] = 
{
    {
        "tactics",
        &UMLRTType_TacticList,
        offsetof( params_step, tactics ),
        1,
        0
    },
    {
        "decisionTimeMsec",
        &UMLRTType_double,
        offsetof( params_step, decisionTimeMsec ),
        1,
        0
    }
};

static UMLRTObject payload_step = 
{
    sizeof( params_step ),
    2,
    fields_step
};

AdapterInterfaceToSimulatorProtocol::Base::Base( const UMLRTCommsPort * & srcPort )
: UMLRTProtocol( srcPort )
{
    UMLRTSignalRegistry & signalRegistry = UMLRTSignalRegistry::getRegistry();
    signalRegistry.registerInSignal( "AdapterInterfaceToSimulatorProtocol", "sendIsFinished", signal_sendIsFinished, &payload_sendIsFinished );
    signalRegistry.registerInSignal( "AdapterInterfaceToSimulatorProtocol", "sendParameters", signal_sendParameters, &payload_sendParameters );
    signalRegistry.registerInSignal( "AdapterInterfaceToSimulatorProtocol", "sendReadForwardTargetSensor", signal_sendReadForwardTargetSensor, &payload_sendReadForwardTargetSensor );
    signalRegistry.registerInSignal( "AdapterInterfaceToSimulatorProtocol", "sendReadForwardTargetSensorForObservation", signal_sendReadForwardTargetSensorForObservation, &payload_sendReadForwardTargetSensorForObservation );
    signalRegistry.registerInSignal( "AdapterInterfaceToSimulatorProtocol", "sendReadForwardThreatSensor", signal_sendReadForwardThreatSensor, &payload_sendReadForwardThreatSensor );
    signalRegistry.registerInSignal( "AdapterInterfaceToSimulatorProtocol", "sendReadForwardThreatSensorForObservation", signal_sendReadForwardThreatSensorForObservation, &payload_sendReadForwardThreatSensorForObservation );
    signalRegistry.registerInSignal( "AdapterInterfaceToSimulatorProtocol", "sendResults", signal_sendResults, &payload_sendResults );
    signalRegistry.registerInSignal( "AdapterInterfaceToSimulatorProtocol", "sendScreenOutput", signal_sendScreenOutput, &payload_sendScreenOutput );
    signalRegistry.registerInSignal( "AdapterInterfaceToSimulatorProtocol", "sendState", signal_sendState, &payload_sendState );
    signalRegistry.registerInSignal( "AdapterInterfaceToSimulatorProtocol", "sendStep", signal_sendStep, &payload_sendStep );
    signalRegistry.registerOutSignal( "AdapterInterfaceToSimulatorProtocol", "createSimulator", signal_createSimulator, &payload_createSimulator );
    signalRegistry.registerOutSignal( "AdapterInterfaceToSimulatorProtocol", "getParameters", signal_getParameters, &payload_getParameters );
    signalRegistry.registerOutSignal( "AdapterInterfaceToSimulatorProtocol", "getResults", signal_getResults, &payload_getResults );
    signalRegistry.registerOutSignal( "AdapterInterfaceToSimulatorProtocol", "getScreenOutput", signal_getScreenOutput, &payload_getScreenOutput );
    signalRegistry.registerOutSignal( "AdapterInterfaceToSimulatorProtocol", "getState", signal_getState, &payload_getState );
    signalRegistry.registerOutSignal( "AdapterInterfaceToSimulatorProtocol", "isFinished", signal_isFinished, &payload_isFinished );
    signalRegistry.registerOutSignal( "AdapterInterfaceToSimulatorProtocol", "readForwardTargetSensor", signal_readForwardTargetSensor, &payload_readForwardTargetSensor );
    signalRegistry.registerOutSignal( "AdapterInterfaceToSimulatorProtocol", "readForwardTargetSensorForObservation", signal_readForwardTargetSensorForObservation, &payload_readForwardTargetSensorForObservation );
    signalRegistry.registerOutSignal( "AdapterInterfaceToSimulatorProtocol", "readForwardThreatSensor", signal_readForwardThreatSensor, &payload_readForwardThreatSensor );
    signalRegistry.registerOutSignal( "AdapterInterfaceToSimulatorProtocol", "readForwardThreatSensorForObservation", signal_readForwardThreatSensorForObservation, &payload_readForwardThreatSensorForObservation );
    signalRegistry.registerOutSignal( "AdapterInterfaceToSimulatorProtocol", "step", signal_step, &payload_step );
}

UMLRTInSignal AdapterInterfaceToSimulatorProtocol::Base::sendIsFinished() const
{
    UMLRTInSignal signal;
    signal.initialize( "sendIsFinished", signal_sendIsFinished, srcPort, &payload_sendIsFinished );
    return signal;
}

UMLRTInSignal AdapterInterfaceToSimulatorProtocol::Base::sendParameters() const
{
    UMLRTInSignal signal;
    signal.initialize( "sendParameters", signal_sendParameters, srcPort, &payload_sendParameters );
    return signal;
}

UMLRTInSignal AdapterInterfaceToSimulatorProtocol::Base::sendReadForwardTargetSensor() const
{
    UMLRTInSignal signal;
    signal.initialize( "sendReadForwardTargetSensor", signal_sendReadForwardTargetSensor, srcPort, &payload_sendReadForwardTargetSensor );
    return signal;
}

UMLRTInSignal AdapterInterfaceToSimulatorProtocol::Base::sendReadForwardTargetSensorForObservation() const
{
    UMLRTInSignal signal;
    signal.initialize( "sendReadForwardTargetSensorForObservation", signal_sendReadForwardTargetSensorForObservation, srcPort, &payload_sendReadForwardTargetSensorForObservation );
    return signal;
}

UMLRTInSignal AdapterInterfaceToSimulatorProtocol::Base::sendReadForwardThreatSensor() const
{
    UMLRTInSignal signal;
    signal.initialize( "sendReadForwardThreatSensor", signal_sendReadForwardThreatSensor, srcPort, &payload_sendReadForwardThreatSensor );
    return signal;
}

UMLRTInSignal AdapterInterfaceToSimulatorProtocol::Base::sendReadForwardThreatSensorForObservation() const
{
    UMLRTInSignal signal;
    signal.initialize( "sendReadForwardThreatSensorForObservation", signal_sendReadForwardThreatSensorForObservation, srcPort, &payload_sendReadForwardThreatSensorForObservation );
    return signal;
}

UMLRTInSignal AdapterInterfaceToSimulatorProtocol::Base::sendResults() const
{
    UMLRTInSignal signal;
    signal.initialize( "sendResults", signal_sendResults, srcPort, &payload_sendResults );
    return signal;
}

UMLRTInSignal AdapterInterfaceToSimulatorProtocol::Base::sendScreenOutput() const
{
    UMLRTInSignal signal;
    signal.initialize( "sendScreenOutput", signal_sendScreenOutput, srcPort, &payload_sendScreenOutput );
    return signal;
}

UMLRTInSignal AdapterInterfaceToSimulatorProtocol::Base::sendState() const
{
    UMLRTInSignal signal;
    signal.initialize( "sendState", signal_sendState, srcPort, &payload_sendState );
    return signal;
}

UMLRTInSignal AdapterInterfaceToSimulatorProtocol::Base::sendStep() const
{
    UMLRTInSignal signal;
    signal.initialize( "sendStep", signal_sendStep, srcPort, &payload_sendStep );
    return signal;
}

UMLRTOutSignal AdapterInterfaceToSimulatorProtocol::Base::createSimulator() const
{
    UMLRTOutSignal signal;
    signal.initialize( "createSimulator", signal_createSimulator, srcPort, &payload_createSimulator );
    return signal;
}

UMLRTOutSignal AdapterInterfaceToSimulatorProtocol::Base::getParameters() const
{
    UMLRTOutSignal signal;
    signal.initialize( "getParameters", signal_getParameters, srcPort, &payload_getParameters );
    return signal;
}

UMLRTOutSignal AdapterInterfaceToSimulatorProtocol::Base::getResults() const
{
    UMLRTOutSignal signal;
    signal.initialize( "getResults", signal_getResults, srcPort, &payload_getResults );
    return signal;
}

UMLRTOutSignal AdapterInterfaceToSimulatorProtocol::Base::getScreenOutput() const
{
    UMLRTOutSignal signal;
    signal.initialize( "getScreenOutput", signal_getScreenOutput, srcPort, &payload_getScreenOutput );
    return signal;
}

UMLRTOutSignal AdapterInterfaceToSimulatorProtocol::Base::getState() const
{
    UMLRTOutSignal signal;
    signal.initialize( "getState", signal_getState, srcPort, &payload_getState );
    return signal;
}

UMLRTOutSignal AdapterInterfaceToSimulatorProtocol::Base::isFinished() const
{
    UMLRTOutSignal signal;
    signal.initialize( "isFinished", signal_isFinished, srcPort, &payload_isFinished );
    return signal;
}

UMLRTOutSignal AdapterInterfaceToSimulatorProtocol::Base::readForwardTargetSensor( int cells ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "readForwardTargetSensor", signal_readForwardTargetSensor, srcPort, &payload_readForwardTargetSensor, &cells );
    return signal;
}

UMLRTOutSignal AdapterInterfaceToSimulatorProtocol::Base::readForwardTargetSensorForObservation( int cells, int numOfObservations ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "readForwardTargetSensorForObservation", signal_readForwardTargetSensorForObservation, srcPort, &payload_readForwardTargetSensorForObservation, &cells, &numOfObservations );
    return signal;
}

UMLRTOutSignal AdapterInterfaceToSimulatorProtocol::Base::readForwardThreatSensor( int cells ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "readForwardThreatSensor", signal_readForwardThreatSensor, srcPort, &payload_readForwardThreatSensor, &cells );
    return signal;
}

UMLRTOutSignal AdapterInterfaceToSimulatorProtocol::Base::readForwardThreatSensorForObservation( int cells, int numOfObservations ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "readForwardThreatSensorForObservation", signal_readForwardThreatSensorForObservation, srcPort, &payload_readForwardThreatSensorForObservation, &cells, &numOfObservations );
    return signal;
}

UMLRTOutSignal AdapterInterfaceToSimulatorProtocol::Base::step( const TacticList & tactics, double decisionTimeMsec ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "step", signal_step, srcPort, &payload_step, &tactics, &decisionTimeMsec );
    return signal;
}

AdapterInterfaceToSimulatorProtocol::Conj::Conj( const UMLRTCommsPort * & srcPort )
: UMLRTProtocol( srcPort )
{
    UMLRTSignalRegistry & signalRegistry = UMLRTSignalRegistry::getRegistry();
    signalRegistry.registerOutSignal( "AdapterInterfaceToSimulatorProtocol", "sendIsFinished", signal_sendIsFinished, &payload_sendIsFinished );
    signalRegistry.registerOutSignal( "AdapterInterfaceToSimulatorProtocol", "sendParameters", signal_sendParameters, &payload_sendParameters );
    signalRegistry.registerOutSignal( "AdapterInterfaceToSimulatorProtocol", "sendReadForwardTargetSensor", signal_sendReadForwardTargetSensor, &payload_sendReadForwardTargetSensor );
    signalRegistry.registerOutSignal( "AdapterInterfaceToSimulatorProtocol", "sendReadForwardTargetSensorForObservation", signal_sendReadForwardTargetSensorForObservation, &payload_sendReadForwardTargetSensorForObservation );
    signalRegistry.registerOutSignal( "AdapterInterfaceToSimulatorProtocol", "sendReadForwardThreatSensor", signal_sendReadForwardThreatSensor, &payload_sendReadForwardThreatSensor );
    signalRegistry.registerOutSignal( "AdapterInterfaceToSimulatorProtocol", "sendReadForwardThreatSensorForObservation", signal_sendReadForwardThreatSensorForObservation, &payload_sendReadForwardThreatSensorForObservation );
    signalRegistry.registerOutSignal( "AdapterInterfaceToSimulatorProtocol", "sendResults", signal_sendResults, &payload_sendResults );
    signalRegistry.registerOutSignal( "AdapterInterfaceToSimulatorProtocol", "sendScreenOutput", signal_sendScreenOutput, &payload_sendScreenOutput );
    signalRegistry.registerOutSignal( "AdapterInterfaceToSimulatorProtocol", "sendState", signal_sendState, &payload_sendState );
    signalRegistry.registerOutSignal( "AdapterInterfaceToSimulatorProtocol", "sendStep", signal_sendStep, &payload_sendStep );
    signalRegistry.registerInSignal( "AdapterInterfaceToSimulatorProtocol", "createSimulator", signal_createSimulator, &payload_createSimulator );
    signalRegistry.registerInSignal( "AdapterInterfaceToSimulatorProtocol", "getParameters", signal_getParameters, &payload_getParameters );
    signalRegistry.registerInSignal( "AdapterInterfaceToSimulatorProtocol", "getResults", signal_getResults, &payload_getResults );
    signalRegistry.registerInSignal( "AdapterInterfaceToSimulatorProtocol", "getScreenOutput", signal_getScreenOutput, &payload_getScreenOutput );
    signalRegistry.registerInSignal( "AdapterInterfaceToSimulatorProtocol", "getState", signal_getState, &payload_getState );
    signalRegistry.registerInSignal( "AdapterInterfaceToSimulatorProtocol", "isFinished", signal_isFinished, &payload_isFinished );
    signalRegistry.registerInSignal( "AdapterInterfaceToSimulatorProtocol", "readForwardTargetSensor", signal_readForwardTargetSensor, &payload_readForwardTargetSensor );
    signalRegistry.registerInSignal( "AdapterInterfaceToSimulatorProtocol", "readForwardTargetSensorForObservation", signal_readForwardTargetSensorForObservation, &payload_readForwardTargetSensorForObservation );
    signalRegistry.registerInSignal( "AdapterInterfaceToSimulatorProtocol", "readForwardThreatSensor", signal_readForwardThreatSensor, &payload_readForwardThreatSensor );
    signalRegistry.registerInSignal( "AdapterInterfaceToSimulatorProtocol", "readForwardThreatSensorForObservation", signal_readForwardThreatSensorForObservation, &payload_readForwardThreatSensorForObservation );
    signalRegistry.registerInSignal( "AdapterInterfaceToSimulatorProtocol", "step", signal_step, &payload_step );
}

UMLRTOutSignal AdapterInterfaceToSimulatorProtocol::Conj::sendIsFinished( int finished ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "sendIsFinished", signal_sendIsFinished, srcPort, &payload_sendIsFinished, &finished );
    return signal;
}

UMLRTOutSignal AdapterInterfaceToSimulatorProtocol::Conj::sendParameters( const SimulationParams & simulationParams ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "sendParameters", signal_sendParameters, srcPort, &payload_sendParameters, &simulationParams );
    return signal;
}

UMLRTOutSignal AdapterInterfaceToSimulatorProtocol::Conj::sendReadForwardTargetSensor( int readings ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "sendReadForwardTargetSensor", signal_sendReadForwardTargetSensor, srcPort, &payload_sendReadForwardTargetSensor, &readings );
    return signal;
}

UMLRTOutSignal AdapterInterfaceToSimulatorProtocol::Conj::sendReadForwardTargetSensorForObservation( int readings ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "sendReadForwardTargetSensorForObservation", signal_sendReadForwardTargetSensorForObservation, srcPort, &payload_sendReadForwardTargetSensorForObservation, &readings );
    return signal;
}

UMLRTOutSignal AdapterInterfaceToSimulatorProtocol::Conj::sendReadForwardThreatSensor( int readings ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "sendReadForwardThreatSensor", signal_sendReadForwardThreatSensor, srcPort, &payload_sendReadForwardThreatSensor, &readings );
    return signal;
}

UMLRTOutSignal AdapterInterfaceToSimulatorProtocol::Conj::sendReadForwardThreatSensorForObservation( int readings ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "sendReadForwardThreatSensorForObservation", signal_sendReadForwardThreatSensorForObservation, srcPort, &payload_sendReadForwardThreatSensorForObservation, &readings );
    return signal;
}

UMLRTOutSignal AdapterInterfaceToSimulatorProtocol::Conj::sendResults( const SimulationResults & simulationResults ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "sendResults", signal_sendResults, srcPort, &payload_sendResults, &simulationResults );
    return signal;
}

UMLRTOutSignal AdapterInterfaceToSimulatorProtocol::Conj::sendScreenOutput( int screenOutput ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "sendScreenOutput", signal_sendScreenOutput, srcPort, &payload_sendScreenOutput, &screenOutput );
    return signal;
}

UMLRTOutSignal AdapterInterfaceToSimulatorProtocol::Conj::sendState( const TeamState & teamState ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "sendState", signal_sendState, srcPort, &payload_sendState, &teamState );
    return signal;
}

UMLRTOutSignal AdapterInterfaceToSimulatorProtocol::Conj::sendStep( int detection ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "sendStep", signal_sendStep, srcPort, &payload_sendStep, &detection );
    return signal;
}

UMLRTInSignal AdapterInterfaceToSimulatorProtocol::Conj::createSimulator() const
{
    UMLRTInSignal signal;
    signal.initialize( "createSimulator", signal_createSimulator, srcPort, &payload_createSimulator );
    return signal;
}

UMLRTInSignal AdapterInterfaceToSimulatorProtocol::Conj::getParameters() const
{
    UMLRTInSignal signal;
    signal.initialize( "getParameters", signal_getParameters, srcPort, &payload_getParameters );
    return signal;
}

UMLRTInSignal AdapterInterfaceToSimulatorProtocol::Conj::getResults() const
{
    UMLRTInSignal signal;
    signal.initialize( "getResults", signal_getResults, srcPort, &payload_getResults );
    return signal;
}

UMLRTInSignal AdapterInterfaceToSimulatorProtocol::Conj::getScreenOutput() const
{
    UMLRTInSignal signal;
    signal.initialize( "getScreenOutput", signal_getScreenOutput, srcPort, &payload_getScreenOutput );
    return signal;
}

UMLRTInSignal AdapterInterfaceToSimulatorProtocol::Conj::getState() const
{
    UMLRTInSignal signal;
    signal.initialize( "getState", signal_getState, srcPort, &payload_getState );
    return signal;
}

UMLRTInSignal AdapterInterfaceToSimulatorProtocol::Conj::isFinished() const
{
    UMLRTInSignal signal;
    signal.initialize( "isFinished", signal_isFinished, srcPort, &payload_isFinished );
    return signal;
}

UMLRTInSignal AdapterInterfaceToSimulatorProtocol::Conj::readForwardTargetSensor() const
{
    UMLRTInSignal signal;
    signal.initialize( "readForwardTargetSensor", signal_readForwardTargetSensor, srcPort, &payload_readForwardTargetSensor );
    return signal;
}

UMLRTInSignal AdapterInterfaceToSimulatorProtocol::Conj::readForwardTargetSensorForObservation() const
{
    UMLRTInSignal signal;
    signal.initialize( "readForwardTargetSensorForObservation", signal_readForwardTargetSensorForObservation, srcPort, &payload_readForwardTargetSensorForObservation );
    return signal;
}

UMLRTInSignal AdapterInterfaceToSimulatorProtocol::Conj::readForwardThreatSensor() const
{
    UMLRTInSignal signal;
    signal.initialize( "readForwardThreatSensor", signal_readForwardThreatSensor, srcPort, &payload_readForwardThreatSensor );
    return signal;
}

UMLRTInSignal AdapterInterfaceToSimulatorProtocol::Conj::readForwardThreatSensorForObservation() const
{
    UMLRTInSignal signal;
    signal.initialize( "readForwardThreatSensorForObservation", signal_readForwardThreatSensorForObservation, srcPort, &payload_readForwardThreatSensorForObservation );
    return signal;
}

UMLRTInSignal AdapterInterfaceToSimulatorProtocol::Conj::step() const
{
    UMLRTInSignal signal;
    signal.initialize( "step", signal_step, srcPort, &payload_step );
    return signal;
}



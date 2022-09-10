
#ifndef ADAPTERINTERFACETOSIMULATORPROTOCOL_HH
#define ADAPTERINTERFACETOSIMULATORPROTOCOL_HH

#include "SimulationParams.hh"
#include "SimulationResults.hh"
#include "TacticList.hh"
#include "TeamState.hh"
#include "umlrtinsignal.hh"
#include "umlrtoutsignal.hh"
#include "umlrtprotocol.hh"
#include "umlrtsignal.hh"
struct UMLRTCommsPort;

namespace AdapterInterfaceToSimulatorProtocol
{
    class Base : public UMLRTProtocol
    {
    public:
        Base( const UMLRTCommsPort * & srcPort );
        UMLRTInSignal sendIsFinished() const;
        UMLRTInSignal sendParameters() const;
        UMLRTInSignal sendReadForwardTargetSensor() const;
        UMLRTInSignal sendReadForwardTargetSensorForObservation() const;
        UMLRTInSignal sendReadForwardThreatSensor() const;
        UMLRTInSignal sendReadForwardThreatSensorForObservation() const;
        UMLRTInSignal sendResults() const;
        UMLRTInSignal sendScreenOutput() const;
        UMLRTInSignal sendState() const;
        UMLRTInSignal sendStep() const;
        UMLRTOutSignal createSimulator() const;
        UMLRTOutSignal getParameters() const;
        UMLRTOutSignal getResults() const;
        UMLRTOutSignal getScreenOutput() const;
        UMLRTOutSignal getState() const;
        UMLRTOutSignal isFinished() const;
        UMLRTOutSignal readForwardTargetSensor( int cells ) const;
        UMLRTOutSignal readForwardTargetSensorForObservation( int cells, int numOfObservations ) const;
        UMLRTOutSignal readForwardThreatSensor( int cells ) const;
        UMLRTOutSignal readForwardThreatSensorForObservation( int cells, int numOfObservations ) const;
        UMLRTOutSignal step( const TacticList & tactics, double decisionTimeMsec ) const;
    };
    enum SignalId
    {
        signal_sendIsFinished = UMLRTSignal::FIRST_PROTOCOL_SIGNAL_ID,
        signal_sendParameters,
        signal_sendReadForwardTargetSensor,
        signal_sendReadForwardTargetSensorForObservation,
        signal_sendReadForwardThreatSensor,
        signal_sendReadForwardThreatSensorForObservation,
        signal_sendResults,
        signal_sendScreenOutput,
        signal_sendState,
        signal_sendStep,
        signal_createSimulator,
        signal_getParameters,
        signal_getResults,
        signal_getScreenOutput,
        signal_getState,
        signal_isFinished,
        signal_readForwardTargetSensor,
        signal_readForwardTargetSensorForObservation,
        signal_readForwardThreatSensor,
        signal_readForwardThreatSensorForObservation,
        signal_step
    };
    class Conj : public UMLRTProtocol
    {
    public:
        Conj( const UMLRTCommsPort * & srcPort );
        UMLRTOutSignal sendIsFinished( int finished ) const;
        UMLRTOutSignal sendParameters( const SimulationParams & simulationParams ) const;
        UMLRTOutSignal sendReadForwardTargetSensor( int readings ) const;
        UMLRTOutSignal sendReadForwardTargetSensorForObservation( int readings ) const;
        UMLRTOutSignal sendReadForwardThreatSensor( int readings ) const;
        UMLRTOutSignal sendReadForwardThreatSensorForObservation( int readings ) const;
        UMLRTOutSignal sendResults( const SimulationResults & simulationResults ) const;
        UMLRTOutSignal sendScreenOutput( int screenOutput ) const;
        UMLRTOutSignal sendState( const TeamState & teamState ) const;
        UMLRTOutSignal sendStep( int detection ) const;
        UMLRTInSignal createSimulator() const;
        UMLRTInSignal getParameters() const;
        UMLRTInSignal getResults() const;
        UMLRTInSignal getScreenOutput() const;
        UMLRTInSignal getState() const;
        UMLRTInSignal isFinished() const;
        UMLRTInSignal readForwardTargetSensor() const;
        UMLRTInSignal readForwardTargetSensorForObservation() const;
        UMLRTInSignal readForwardThreatSensor() const;
        UMLRTInSignal readForwardThreatSensorForObservation() const;
        UMLRTInSignal step() const;
    };
};

#endif


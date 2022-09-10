
#ifndef SIMULATORTOFORWARDTARGETSENSOR_HH
#define SIMULATORTOFORWARDTARGETSENSOR_HH

#include "SimulationParams.hh"
#include "umlrtinsignal.hh"
#include "umlrtoutsignal.hh"
#include "umlrtprotocol.hh"
#include "umlrtsignal.hh"
struct UMLRTCommsPort;

namespace SimulatorToForwardTargetSensor
{
    class Base : public UMLRTProtocol
    {
    public:
        Base( const UMLRTCommsPort * & srcPort );
        UMLRTInSignal sendReadForwardTargetSensor() const;
        UMLRTOutSignal createForwardTargetSensor( const SimulationParams & simulatorParams ) const;
        UMLRTOutSignal readForwardTargetSensor() const;
    };
    enum SignalId
    {
        signal_sendReadForwardTargetSensor = UMLRTSignal::FIRST_PROTOCOL_SIGNAL_ID,
        signal_createForwardTargetSensor,
        signal_readForwardTargetSensor
    };
    class Conj : public UMLRTProtocol
    {
    public:
        Conj( const UMLRTCommsPort * & srcPort );
        UMLRTOutSignal sendReadForwardTargetSensor( int sensedForwardTargetSensor ) const;
        UMLRTInSignal createForwardTargetSensor() const;
        UMLRTInSignal readForwardTargetSensor() const;
    };
};

#endif


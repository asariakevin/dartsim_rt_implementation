
#ifndef FORWARDTARGETSENSOR_HH
#define FORWARDTARGETSENSOR_HH

#include "SimulatorToForwardTargetSensor.hh"
#include "umlrtcapsule.hh"
#include "umlrtcapsuleclass.hh"
#include "umlrtlogprotocol.hh"
#include "umlrtmessage.hh"
struct UMLRTCommsPort;
struct UMLRTSlot;

class Capsule_ForwardTargetSensor : public UMLRTCapsule
{
public:
    Capsule_ForwardTargetSensor( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat );
protected:
    UMLRTLogProtocol_baserole log;
    SimulatorToForwardTargetSensor::Conj simulatorPort;
public:
    enum BorderPortId
    {
        borderport_simulatorPort,
        borderport_log
    };
    enum PartId
    {
    };
    enum PortId
    {
        port_log,
        port_simulatorPort
    };
    virtual void bindPort( bool isBorder, int portId, int index );
    virtual void unbindPort( bool isBorder, int portId, int index );
    virtual void inject( const UMLRTMessage & message );
    virtual void initialize( const UMLRTMessage & message );
    const char * getCurrentStateString() const;
private:
    enum State
    {
        runningForwardTargetSensor,
        waitingStateForwardTargetSensor,
        SPECIAL_INTERNAL_STATE_TOP,
        SPECIAL_INTERNAL_STATE_UNVISITED
    };
    const char * stateNames[4];
    State currentState;
    void update_state( State newState );
    void transitionaction_____TtLQDwTY( const UMLRTMessage * msg );
    void transitionaction_____mVydoKme( const UMLRTMessage * msg );
    void actionchain_____TtLQDwTY( const UMLRTMessage * msg );
    void actionchain_____mVydoKme( const UMLRTMessage * msg );
    State state_____runningForwardTargetSensor( const UMLRTMessage * msg );
    State state_____waitingStateForwardTargetSensor( const UMLRTMessage * msg );
};
extern const UMLRTCapsuleClass ForwardTargetSensor;

#endif


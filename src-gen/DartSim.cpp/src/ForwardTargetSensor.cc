
#include "ForwardTargetSensor.hh"

#include "SimulatorToForwardTargetSensor.hh"
#include "umlrtcommsportrole.hh"
#include "umlrtmessage.hh"
#include "umlrtslot.hh"
#include <cstddef>
#include "SimulationParams.hh"
#include "umlrtcapsuleclass.hh"
class UMLRTRtsInterface;
struct UMLRTCommsPort;

Capsule_ForwardTargetSensor::Capsule_ForwardTargetSensor( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat )
: UMLRTCapsule( NULL, cd, st, border, internal, isStat )
, simulatorPort( borderPorts[borderport_simulatorPort] )
, currentState( SPECIAL_INTERNAL_STATE_UNVISITED )
{
    stateNames[runningForwardTargetSensor] = "runningForwardTargetSensor";
    stateNames[waitingStateForwardTargetSensor] = "waitingStateForwardTargetSensor";
    stateNames[SPECIAL_INTERNAL_STATE_TOP] = "<top>";
    stateNames[SPECIAL_INTERNAL_STATE_UNVISITED] = "<uninitialized>";
}






void Capsule_ForwardTargetSensor::bindPort( bool isBorder, int portId, int index )
{
}

void Capsule_ForwardTargetSensor::unbindPort( bool isBorder, int portId, int index )
{
}

void Capsule_ForwardTargetSensor::inject( const UMLRTMessage & message )
{
    msg = &message;
    switch( currentState )
    {
    case waitingStateForwardTargetSensor:
        currentState = state_____waitingStateForwardTargetSensor( &message );
        break;
    case runningForwardTargetSensor:
        currentState = state_____runningForwardTargetSensor( &message );
        break;
    default:
        break;
    }
}

void Capsule_ForwardTargetSensor::initialize( const UMLRTMessage & message )
{
    msg = &message;
    actionchain_____TtLQDwTY( &message );
    currentState = waitingStateForwardTargetSensor;
}

const char * Capsule_ForwardTargetSensor::getCurrentStateString() const
{
    return stateNames[currentState];
}




void Capsule_ForwardTargetSensor::update_state( Capsule_ForwardTargetSensor::State newState )
{
    currentState = newState;
}

void Capsule_ForwardTargetSensor::transitionaction_____TtLQDwTY( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN file:/tmp/ca.jahed.rtpoet.papyrusrt/uml/DartSim.uml DartSim::ForwardTargetSensor transition initialStateForwardTargetSensor,waitingStateForwardTargetSensor */
    log.log("[ForwardTargetSensor] from initial state to waiting state");

    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_ForwardTargetSensor::transitionaction_____mVydoKme( const UMLRTMessage * msg )
{
    #define simulatorParams ( *(const SimulationParams * )msg->getParam( 0 ) )
    #define rtdata ( (const SimulationParams * )msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN file:/tmp/ca.jahed.rtpoet.papyrusrt/uml/DartSim.uml DartSim::ForwardTargetSensor transition waitingStateForwardTargetSensor,runningForwardTargetSensor,createForwardTargetSensor:simulatorPort */
    log.log("[ForwardTargetSensor] from waiting state to running state");

    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef simulatorParams
}

void Capsule_ForwardTargetSensor::actionchain_____TtLQDwTY( const UMLRTMessage * msg )
{
    transitionaction_____TtLQDwTY( msg );
    update_state( waitingStateForwardTargetSensor );
}

void Capsule_ForwardTargetSensor::actionchain_____mVydoKme( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    transitionaction_____mVydoKme( msg );
    update_state( runningForwardTargetSensor );
}

Capsule_ForwardTargetSensor::State Capsule_ForwardTargetSensor::state_____runningForwardTargetSensor( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    default:
        this->unexpectedMessage();
        break;
    }
    return currentState;
}

Capsule_ForwardTargetSensor::State Capsule_ForwardTargetSensor::state_____waitingStateForwardTargetSensor( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_simulatorPort:
        switch( msg->getSignalId() )
        {
        case SimulatorToForwardTargetSensor::signal_createForwardTargetSensor:
            actionchain_____mVydoKme( msg );
            return runningForwardTargetSensor;
        default:
            this->unexpectedMessage();
            break;
        }
        return currentState;
    default:
        this->unexpectedMessage();
        break;
    }
    return currentState;
}


static const UMLRTCommsPortRole portroles_border[] = 
{
    {
        Capsule_ForwardTargetSensor::port_simulatorPort,
        "SimulatorToForwardTargetSensor",
        "simulatorPort",
        "",
        1,
        true,
        true,
        false,
        false,
        false,
        false,
        false
    },
    {
        Capsule_ForwardTargetSensor::port_log,
        "Log",
        "log",
        "",
        0,
        false,
        false,
        false,
        false,
        false,
        false,
        false
    }
};

static void instantiate_ForwardTargetSensor( const UMLRTRtsInterface * rts, UMLRTSlot * slot, const UMLRTCommsPort * * borderPorts )
{
    slot->capsule = new Capsule_ForwardTargetSensor( &ForwardTargetSensor, slot, borderPorts, NULL, false );
}

const UMLRTCapsuleClass ForwardTargetSensor = 
{
    "ForwardTargetSensor",
    NULL,
    instantiate_ForwardTargetSensor,
    0,
    NULL,
    2,
    portroles_border,
    0,
    NULL
};


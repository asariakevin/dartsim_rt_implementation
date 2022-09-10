
#include "AdapterInterface.hh"

#include "umlrtcommsportrole.hh"
#include "umlrtmessage.hh"
#include "umlrtslot.hh"
#include <cstddef>
#include "umlrtcapsuleclass.hh"
class UMLRTRtsInterface;
struct UMLRTCommsPort;

Capsule_AdapterInterface::Capsule_AdapterInterface( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat )
: UMLRTCapsule( NULL, cd, st, border, internal, isStat )
, currentState( SPECIAL_INTERNAL_STATE_UNVISITED )
, adapterManager( borderPorts[borderport_adapterManager] )
{
    stateNames[running] = "running";
    stateNames[SPECIAL_INTERNAL_STATE_TOP] = "<top>";
    stateNames[SPECIAL_INTERNAL_STATE_UNVISITED] = "<uninitialized>";
}

void Capsule_AdapterInterface::inject( const UMLRTMessage & message )
{
    msg = &message;
    switch( currentState )
    {
    case running:
        currentState = state_____running( &message );
        break;
    default:
        break;
    }
}

void Capsule_AdapterInterface::initialize( const UMLRTMessage & message )
{
    msg = &message;
    actionchain_____fIMHhqnT( &message );
    currentState = running;
}

const char * Capsule_AdapterInterface::getCurrentStateString() const
{
    return stateNames[currentState];
}




void Capsule_AdapterInterface::update_state( Capsule_AdapterInterface::State newState )
{
    currentState = newState;
}

void Capsule_AdapterInterface::transitionaction_____fIMHhqnT( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN file:/tmp/ca.jahed.rtpoet.papyrusrt/uml/DartSim.uml DartSim::AdapterInterface transition initialStateAdapterInterfaceCapsule,running */
    log.log("[AdapterInterface] from initial state to running state");

    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_AdapterInterface::actionchain_____fIMHhqnT( const UMLRTMessage * msg )
{
    transitionaction_____fIMHhqnT( msg );
    update_state( running );
}

Capsule_AdapterInterface::State Capsule_AdapterInterface::state_____running( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    default:
        this->unexpectedMessage();
        break;
    }
    return currentState;
}






void Capsule_AdapterInterface::bindPort( bool isBorder, int portId, int index )
{
}

void Capsule_AdapterInterface::unbindPort( bool isBorder, int portId, int index )
{
}


static const UMLRTCommsPortRole portroles_border[] = 
{
    {
        Capsule_AdapterInterface::port_adapterManager,
        "AdapterInterfaceToSimulatorProtocol",
        "adapterManager",
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
        Capsule_AdapterInterface::port_log,
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

static void instantiate_AdapterInterface( const UMLRTRtsInterface * rts, UMLRTSlot * slot, const UMLRTCommsPort * * borderPorts )
{
    slot->capsule = new Capsule_AdapterInterface( &AdapterInterface, slot, borderPorts, NULL, false );
}

const UMLRTCapsuleClass AdapterInterface = 
{
    "AdapterInterface",
    NULL,
    instantiate_AdapterInterface,
    0,
    NULL,
    2,
    portroles_border,
    0,
    NULL
};


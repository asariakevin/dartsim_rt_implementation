
#include "Top.hh"

#include "AdapterInterface.hh"
#include "ForwardTargetSensor.hh"
#include "umlrtcapsuleclass.hh"
#include "umlrtcapsulepart.hh"
#include "umlrtslot.hh"
#include <cstddef>
#include "umlrtcapsulerole.hh"
#include "umlrtframeservice.hh"
class UMLRTRtsInterface;
struct UMLRTCommsPort;

Capsule_Top::Capsule_Top( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat )
: UMLRTCapsule( NULL, cd, st, border, internal, isStat )
, adapterInterface( &slot->parts[part_adapterInterface] )
, forwardTargetSensor( &slot->parts[part_forwardTargetSensor] )
{
}




void Capsule_Top::bindPort( bool isBorder, int portId, int index )
{
}

void Capsule_Top::unbindPort( bool isBorder, int portId, int index )
{
}

void Capsule_Top::initialize( const UMLRTMessage & msg )
{
}

void Capsule_Top::inject( const UMLRTMessage & msg )
{
}


static const UMLRTCapsuleRole roles[] = 
{
    {
        "adapterInterface",
        &AdapterInterface,
        1,
        1,
        false,
        false
    },
    {
        "forwardTargetSensor",
        &ForwardTargetSensor,
        1,
        1,
        false,
        false
    }
};

static void instantiate_Top( const UMLRTRtsInterface * rts, UMLRTSlot * slot, const UMLRTCommsPort * * borderPorts )
{
    AdapterInterface.instantiate( NULL, slot->parts[Capsule_Top::part_adapterInterface].slots[0], UMLRTFrameService::createBorderPorts( slot->parts[Capsule_Top::part_adapterInterface].slots[0], AdapterInterface.numPortRolesBorder ) );
    ForwardTargetSensor.instantiate( NULL, slot->parts[Capsule_Top::part_forwardTargetSensor].slots[0], UMLRTFrameService::createBorderPorts( slot->parts[Capsule_Top::part_forwardTargetSensor].slots[0], ForwardTargetSensor.numPortRolesBorder ) );
    slot->capsule = new Capsule_Top( &Top, slot, borderPorts, NULL, false );
}

const UMLRTCapsuleClass Top = 
{
    "Top",
    NULL,
    instantiate_Top,
    2,
    roles,
    0,
    NULL,
    0,
    NULL
};


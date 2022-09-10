
#include "TeamState.hh"

#include "umlrtobjectclass.hh"
#include "umlrtobjectclassgeneric.hh"
#include <cstddef>

const UMLRTObject_field TeamState::fields[] = 
{
    {
        "position",
        &UMLRTType_Coordinate,
        offsetof( TeamState, position ),
        1,
        0
    },
    {
        "directionX",
        &UMLRTType_int,
        offsetof( TeamState, directionX ),
        1,
        0
    },
    {
        "directionY",
        &UMLRTType_int,
        offsetof( TeamState, directionY ),
        1,
        0
    },
    {
        "config",
        &UMLRTType_TeamConfiguration,
        offsetof( TeamState, config ),
        1,
        0
    }
};






const UMLRTObject_class UMLRTType_TeamState = 
{
    UMLRTObjectInitialize<TeamState>,
    UMLRTObjectCopy<TeamState>,
    UMLRTObject_decode,
    UMLRTObject_encode,
    UMLRTObjectDestroy<TeamState>,
    UMLRTObject_fprintf,
    "TeamState",
    NULL,
    {
        sizeof( TeamState ),
        4,
        TeamState::fields
    },
    UMLRTOBJECTCLASS_DEFAULT_VERSION,
    UMLRTOBJECTCLASS_DEFAULT_BACKWARDS
};


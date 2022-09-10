
#include "Formation.hh"

#include "umlrtobjectclass.hh"
#include "umlrtobjectclassgeneric.hh"
#include <cstddef>

const UMLRTObject_field Formation::fields[] = 
{
    {
        "LOOSE",
        &UMLRTType_int,
        offsetof( Formation, LOOSE ),
        1,
        0
    },
    {
        "TIGHT",
        &UMLRTType_int,
        offsetof( Formation, TIGHT ),
        1,
        0
    }
};




const UMLRTObject_class UMLRTType_Formation = 
{
    UMLRTObjectInitialize<Formation>,
    UMLRTObjectCopy<Formation>,
    UMLRTObject_decode,
    UMLRTObject_encode,
    UMLRTObjectDestroy<Formation>,
    UMLRTObject_fprintf,
    "Formation",
    NULL,
    {
        sizeof( Formation ),
        2,
        Formation::fields
    },
    UMLRTOBJECTCLASS_DEFAULT_VERSION,
    UMLRTOBJECTCLASS_DEFAULT_BACKWARDS
};


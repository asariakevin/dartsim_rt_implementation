
#include "Coordinate.hh"

#include "umlrtobjectclass.hh"
#include "umlrtobjectclassgeneric.hh"
#include <cstddef>

const UMLRTObject_field Coordinate::fields[] = 
{
    {
        "x",
        &UMLRTType_int,
        offsetof( Coordinate, x ),
        1,
        0
    },
    {
        "y",
        &UMLRTType_int,
        offsetof( Coordinate, y ),
        1,
        0
    }
};




const UMLRTObject_class UMLRTType_Coordinate = 
{
    UMLRTObjectInitialize<Coordinate>,
    UMLRTObjectCopy<Coordinate>,
    UMLRTObject_decode,
    UMLRTObject_encode,
    UMLRTObjectDestroy<Coordinate>,
    UMLRTObject_fprintf,
    "Coordinate",
    NULL,
    {
        sizeof( Coordinate ),
        2,
        Coordinate::fields
    },
    UMLRTOBJECTCLASS_DEFAULT_VERSION,
    UMLRTOBJECTCLASS_DEFAULT_BACKWARDS
};


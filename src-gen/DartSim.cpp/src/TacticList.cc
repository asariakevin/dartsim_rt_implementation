
#include "TacticList.hh"

#include "umlrtobjectclass.hh"
#include "umlrtobjectclassgeneric.hh"
#include <cstddef>

const UMLRTObject_field TacticList::fields[] = 
{
};



const UMLRTObject_class UMLRTType_TacticList = 
{
    UMLRTObjectInitialize<TacticList>,
    UMLRTObjectCopy<TacticList>,
    UMLRTObject_decode,
    UMLRTObject_encode,
    UMLRTObjectDestroy<TacticList>,
    UMLRTObject_fprintf,
    "TacticList",
    NULL,
    {
        sizeof( TacticList ),
        0,
        TacticList::fields
    },
    UMLRTOBJECTCLASS_DEFAULT_VERSION,
    UMLRTOBJECTCLASS_DEFAULT_BACKWARDS
};


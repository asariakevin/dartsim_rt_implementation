
#include "TeamConfiguration.hh"

#include "umlrtobjectclass.hh"
#include "umlrtobjectclassgeneric.hh"
#include <cstddef>

const UMLRTObject_field TeamConfiguration::fields[] = 
{
    {
        "formation",
        &UMLRTType_Formation,
        offsetof( TeamConfiguration, formation ),
        1,
        0
    }
};









const UMLRTObject_class UMLRTType_TeamConfiguration = 
{
    UMLRTObjectInitialize<TeamConfiguration>,
    UMLRTObjectCopy<TeamConfiguration>,
    UMLRTObject_decode,
    UMLRTObject_encode,
    UMLRTObjectDestroy<TeamConfiguration>,
    UMLRTObject_fprintf,
    "TeamConfiguration",
    NULL,
    {
        sizeof( TeamConfiguration ),
        1,
        TeamConfiguration::fields
    },
    UMLRTOBJECTCLASS_DEFAULT_VERSION,
    UMLRTOBJECTCLASS_DEFAULT_BACKWARDS
};


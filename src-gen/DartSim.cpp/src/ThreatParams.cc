
#include "ThreatParams.hh"

#include "umlrtobjectclass.hh"
#include "umlrtobjectclassgeneric.hh"
#include <cstddef>

const UMLRTObject_field ThreatParams::fields[] = 
{
};
ThreatParams::ThreatParams()
{
    destructionFormationFactor = ( 1.5 );
    threatRange = ( 3 );
}





const UMLRTObject_class UMLRTType_ThreatParams = 
{
    UMLRTObjectInitialize<ThreatParams>,
    UMLRTObjectCopy<ThreatParams>,
    UMLRTObject_decode,
    UMLRTObject_encode,
    UMLRTObjectDestroy<ThreatParams>,
    UMLRTObject_fprintf,
    "ThreatParams",
    NULL,
    {
        sizeof( ThreatParams ),
        0,
        ThreatParams::fields
    },
    UMLRTOBJECTCLASS_DEFAULT_VERSION,
    UMLRTOBJECTCLASS_DEFAULT_BACKWARDS
};


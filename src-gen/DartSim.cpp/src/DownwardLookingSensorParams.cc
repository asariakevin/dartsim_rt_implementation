
#include "DownwardLookingSensorParams.hh"

#include "umlrtobjectclass.hh"
#include "umlrtobjectclassgeneric.hh"
#include <cstddef>

const UMLRTObject_field DownwardLookingSensorParams::fields[] = 
{
};
DownwardLookingSensorParams::DownwardLookingSensorParams()
{
    targetDetectionFormationFactor = ( 1.2 );
    targetSensorRange = ( 4 );
}





const UMLRTObject_class UMLRTType_DownwardLookingSensorParams = 
{
    UMLRTObjectInitialize<DownwardLookingSensorParams>,
    UMLRTObjectCopy<DownwardLookingSensorParams>,
    UMLRTObject_decode,
    UMLRTObject_encode,
    UMLRTObjectDestroy<DownwardLookingSensorParams>,
    UMLRTObject_fprintf,
    "DownwardLookingSensorParams",
    NULL,
    {
        sizeof( DownwardLookingSensorParams ),
        0,
        DownwardLookingSensorParams::fields
    },
    UMLRTOBJECTCLASS_DEFAULT_VERSION,
    UMLRTOBJECTCLASS_DEFAULT_BACKWARDS
};


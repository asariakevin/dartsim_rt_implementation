
#include "LongRangeSensorParams.hh"

#include "umlrtobjectclass.hh"
#include "umlrtobjectclassgeneric.hh"
#include <cstddef>

const UMLRTObject_field LongRangeSensorParams::fields[] = 
{
};
LongRangeSensorParams::LongRangeSensorParams()
{
    threatSensorFPR = ( 0.1 );
    threatSensorFNR = ( 0.15 );
    targetSensorFPR = ( 0.1 );
    targetSensorFNR = ( 0.15 );
}







const UMLRTObject_class UMLRTType_LongRangeSensorParams = 
{
    UMLRTObjectInitialize<LongRangeSensorParams>,
    UMLRTObjectCopy<LongRangeSensorParams>,
    UMLRTObject_decode,
    UMLRTObject_encode,
    UMLRTObjectDestroy<LongRangeSensorParams>,
    UMLRTObject_fprintf,
    "LongRangeSensorParams",
    NULL,
    {
        sizeof( LongRangeSensorParams ),
        0,
        LongRangeSensorParams::fields
    },
    UMLRTOBJECTCLASS_DEFAULT_VERSION,
    UMLRTOBJECTCLASS_DEFAULT_BACKWARDS
};


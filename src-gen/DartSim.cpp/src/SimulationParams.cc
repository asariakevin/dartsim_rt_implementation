
#include "SimulationParams.hh"

#include "umlrtobjectclass.hh"
#include "umlrtobjectclassgeneric.hh"
#include <cstddef>

const UMLRTObject_field SimulationParams::fields[] = 
{
};
SimulationParams::SimulationParams()
{
    mapSize = ( 40 );
    squareMap = ( false );
    altitudeLevels = ( 4 );
    changeAltitudeLatencyPeriods = ( 1 );
    optimalityTest = ( false );
}











const UMLRTObject_class UMLRTType_SimulationParams = 
{
    UMLRTObjectInitialize<SimulationParams>,
    UMLRTObjectCopy<SimulationParams>,
    UMLRTObject_decode,
    UMLRTObject_encode,
    UMLRTObjectDestroy<SimulationParams>,
    UMLRTObject_fprintf,
    "SimulationParams",
    NULL,
    {
        sizeof( SimulationParams ),
        0,
        SimulationParams::fields
    },
    UMLRTOBJECTCLASS_DEFAULT_VERSION,
    UMLRTOBJECTCLASS_DEFAULT_BACKWARDS
};


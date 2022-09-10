
#include "SimulationResults.hh"

#include "umlrtobjectclass.hh"
#include "umlrtobjectclassgeneric.hh"
#include <cstddef>

const UMLRTObject_field SimulationResults::fields[] = 
{
    {
        "whereDestroyed",
        &UMLRTType_Coordinate,
        offsetof( SimulationResults, whereDestroyed ),
        1,
        0
    }
};








const UMLRTObject_class UMLRTType_SimulationResults = 
{
    UMLRTObjectInitialize<SimulationResults>,
    UMLRTObjectCopy<SimulationResults>,
    UMLRTObject_decode,
    UMLRTObject_encode,
    UMLRTObjectDestroy<SimulationResults>,
    UMLRTObject_fprintf,
    "SimulationResults",
    NULL,
    {
        sizeof( SimulationResults ),
        1,
        SimulationResults::fields
    },
    UMLRTOBJECTCLASS_DEFAULT_VERSION,
    UMLRTOBJECTCLASS_DEFAULT_BACKWARDS
};


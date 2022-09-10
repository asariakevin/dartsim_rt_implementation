
#include "Sensor.hh"

#include "umlrtobjectclass.hh"
#include "umlrtobjectclassgeneric.hh"
#include <cstddef>

const UMLRTObject_field Sensor::fields[] = 
{
};




int Sensor::Sensor( double falsePositiveRate, double falseNegativeRate )
{
    /* UMLRTGEN-USERREGION-BEGIN file:/tmp/ca.jahed.rtpoet.papyrusrt/uml/DartSim.uml DartSim::Sensor operation Sensor */
    fpr(falsePositiveRate);
    fnr(falseNegativeRate);
    randomGenerator.seed(RandomSeed::getNextSeed());
    /* UMLRTGEN-USERREGION-END */
}

int Sensor::sense( bool truth )
{
    /* UMLRTGEN-USERREGION-BEGIN file:/tmp/ca.jahed.rtpoet.papyrusrt/uml/DartSim.uml DartSim::Sensor operation sense */
    bool result = truth;
    double random = uniform(randomGenerator);
    if (truth && random <= fnr) {
    result = false;
    } else if (!truth && random <= fpr) {
    result = true;
    }
    return result;
    /* UMLRTGEN-USERREGION-END */
}



const UMLRTObject_class UMLRTType_Sensor = 
{
    UMLRTObjectInitialize<Sensor>,
    UMLRTObjectCopy<Sensor>,
    UMLRTObject_decode,
    UMLRTObject_encode,
    UMLRTObjectDestroy<Sensor>,
    UMLRTObject_fprintf,
    "Sensor",
    NULL,
    {
        sizeof( Sensor ),
        0,
        Sensor::fields
    },
    UMLRTOBJECTCLASS_DEFAULT_VERSION,
    UMLRTOBJECTCLASS_DEFAULT_BACKWARDS
};


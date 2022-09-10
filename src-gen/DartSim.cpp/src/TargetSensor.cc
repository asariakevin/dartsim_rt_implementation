
#include "TargetSensor.hh"

#include "umlrtobjectclass.hh"
#include "umlrtobjectclassgeneric.hh"
#include <cstddef>

const UMLRTObject_field TargetSensor::fields[] = 
{
};




int TargetSensor::TargetSensor( double range, double detectionFormationFactor )
{
    /* UMLRTGEN-USERREGION-BEGIN file:/tmp/ca.jahed.rtpoet.papyrusrt/uml/DartSim.uml DartSim::TargetSensor operation TargetSensor */
    range(range);
    detectionFormationFactor(detectionFormationFactor);
    randomGenerator(RandomSeed::getNextSeed());
    /* UMLRTGEN-USERREGION-END */
}

int TargetSensor::sense( TeamConfiguration config, bool targetPresent )
{
    /* UMLRTGEN-USERREGION-BEGIN file:/tmp/ca.jahed.rtpoet.papyrusrt/uml/DartSim.uml DartSim::TargetSensor operation sense */
    bool detected = false;
    if (targetPresent) {
    double probOfDetection = getProbabilityOfDetection(config);
    double random = uniform(randomGenerator);
    detected = (random <= probOfDetection);
    }
    return detected;
    /* UMLRTGEN-USERREGION-END */
}

int TargetSensor::getProbabilityOfDetection( TeamConfiguration config )
{
    /* UMLRTGEN-USERREGION-BEGIN file:/tmp/ca.jahed.rtpoet.papyrusrt/uml/DartSim.uml DartSim::TargetSensor operation getProbabilityOfDetection */
    double probOfDetection =
    ((config.formation == TeamConfiguration::Formation::LOOSE) ? 1.0 : 1 / detectionFormationFactor)
    * max(0.0, range - config.altitudeLevel) / range;
    // ECM reduces the prob of detection
    if (config.ecm) {
    probOfDetection *= 0.25;
    }
    return probOfDetection;
    /* UMLRTGEN-USERREGION-END */
}



const UMLRTObject_class UMLRTType_TargetSensor = 
{
    UMLRTObjectInitialize<TargetSensor>,
    UMLRTObjectCopy<TargetSensor>,
    UMLRTObject_decode,
    UMLRTObject_encode,
    UMLRTObjectDestroy<TargetSensor>,
    UMLRTObject_fprintf,
    "TargetSensor",
    NULL,
    {
        sizeof( TargetSensor ),
        0,
        TargetSensor::fields
    },
    UMLRTOBJECTCLASS_DEFAULT_VERSION,
    UMLRTOBJECTCLASS_DEFAULT_BACKWARDS
};


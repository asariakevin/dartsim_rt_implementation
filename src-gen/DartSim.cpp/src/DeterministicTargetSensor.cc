
#include "DeterministicTargetSensor.hh"

#include "umlrtobjectclass.hh"
#include "umlrtobjectclassgeneric.hh"
#include <cstddef>

const UMLRTObject_field DeterministicTargetSensor::fields[] = 
{
};




int DeterministicTargetSensor::DeterministicTargetSensor( double range, double detectionFormationFactor )
{
    /* UMLRTGEN-USERREGION-BEGIN file:/tmp/ca.jahed.rtpoet.papyrusrt/uml/DartSim.uml DartSim::DeterministicTargetSensor operation DeterministicTargetSensor */
    range(range);
    detectionFormationFactor(detectionFormationFactor);
    randomGenerator(RandomSeed::getNextSeed());
    /* UMLRTGEN-USERREGION-END */
}

int DeterministicTargetSensor::sense( TeamConfiguration config, bool targetPresent )
{
    /* UMLRTGEN-USERREGION-BEGIN file:/tmp/ca.jahed.rtpoet.papyrusrt/uml/DartSim.uml DartSim::DeterministicTargetSensor operation sense */
    bool detected = false;
    if (targetPresent) {
    double probOfDetection = getProbabilityOfDetection(config);
    double random = uniform(randomGenerator);
    detected = (random <= probOfDetection);
    }
    return detected;
    /* UMLRTGEN-USERREGION-END */
}

int DeterministicTargetSensor::getProbabilityOfDetection( TeamConfiguration config )
{
    /* UMLRTGEN-USERREGION-BEGIN file:/tmp/ca.jahed.rtpoet.papyrusrt/uml/DartSim.uml DartSim::DeterministicTargetSensor operation getProbabilityOfDetection */
    double effectiveRange = range;
    if (config.formation == TeamConfiguration::Formation::TIGHT) {
    effectiveRange = range / detectionFormationFactor;
    }
    // ECM reduces the range of detection
    if (config.ecm) {
    effectiveRange *= 0.75;
    }
    double probOfDetection = ((effectiveRange - config.altitudeLevel) > 0.0) ? 1.0 : 0.0;
    return probOfDetection;
    /* UMLRTGEN-USERREGION-END */
}



const UMLRTObject_class UMLRTType_DeterministicTargetSensor = 
{
    UMLRTObjectInitialize<DeterministicTargetSensor>,
    UMLRTObjectCopy<DeterministicTargetSensor>,
    UMLRTObject_decode,
    UMLRTObject_encode,
    UMLRTObjectDestroy<DeterministicTargetSensor>,
    UMLRTObject_fprintf,
    "DeterministicTargetSensor",
    NULL,
    {
        sizeof( DeterministicTargetSensor ),
        0,
        DeterministicTargetSensor::fields
    },
    UMLRTOBJECTCLASS_DEFAULT_VERSION,
    UMLRTOBJECTCLASS_DEFAULT_BACKWARDS
};


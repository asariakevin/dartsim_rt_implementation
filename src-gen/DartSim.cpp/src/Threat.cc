
#include "Threat.hh"

#include "umlrtobjectclass.hh"
#include "umlrtobjectclassgeneric.hh"
#include <cstddef>

const UMLRTObject_field Threat::fields[] = 
{
    {
        "range",
        &UMLRTType_double,
        offsetof( Threat, range ),
        1,
        0
    },
    {
        "destructionFormationFactor",
        &UMLRTType_double,
        offsetof( Threat, destructionFormationFactor ),
        1,
        0
    }
};




int Threat::Threat( double range, double destructionFormationFactor )
{
    /* UMLRTGEN-USERREGION-BEGIN file:/tmp/ca.jahed.rtpoet.papyrusrt/uml/DartSim.uml DartSim::Threat operation Threat */
    range(range);
    destructionFormationFactor(destructionFormationFactor);
    randomGenerator(RandomSeed::getNextSeed());
    /* UMLRTGEN-USERREGION-END */
}

int Threat::isDestroyed( RealEnvironment threatEnv, TeamConfiguration config, Coordinate location )
{
    /* UMLRTGEN-USERREGION-BEGIN file:/tmp/ca.jahed.rtpoet.papyrusrt/uml/DartSim.uml DartSim::Threat operation isDestroyed */
    bool destroyed = false;
    bool threat = threatEnv.isObjectAt(location);
    if (threat) {
    double probOfDestruction = getProbabilityOfDestruction(config);
    double random = uniform(randomGenerator);
    destroyed = (random <= probOfDestruction);
    }
    return destroyed;
    /* UMLRTGEN-USERREGION-END */
}

int Threat::getProbabilityOfDestruction( TeamConfiguration config )
{
    /* UMLRTGEN-USERREGION-BEGIN file:/tmp/ca.jahed.rtpoet.papyrusrt/uml/DartSim.uml DartSim::Threat operation getProbabilityOfDestruction */
    double probOfDestruction =
    ((config.formation == TeamConfiguration::Formation::LOOSE) ? 1.0 : (1.0 / destructionFormationFactor))
    * max(0.0, range - config.altitudeLevel) / range;
    // ECM reduces the prob of destruction
    if (config.ecm) {
    probOfDestruction *= 0.25;
    }
    return probOfDestruction;
    /* UMLRTGEN-USERREGION-END */
}



const UMLRTObject_class UMLRTType_Threat = 
{
    UMLRTObjectInitialize<Threat>,
    UMLRTObjectCopy<Threat>,
    UMLRTObject_decode,
    UMLRTObject_encode,
    UMLRTObjectDestroy<Threat>,
    UMLRTObject_fprintf,
    "Threat",
    NULL,
    {
        sizeof( Threat ),
        2,
        Threat::fields
    },
    UMLRTOBJECTCLASS_DEFAULT_VERSION,
    UMLRTOBJECTCLASS_DEFAULT_BACKWARDS
};


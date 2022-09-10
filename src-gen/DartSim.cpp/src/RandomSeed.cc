
#include "RandomSeed.hh"

#include "umlrtobjectclass.hh"
#include "umlrtobjectclassgeneric.hh"
#include <cstddef>

const UMLRTObject_field RandomSeed::fields[] = 
{
};



int RandomSeed::RandomSeed()
{
    /* UMLRTGEN-USERREGION-BEGIN file:/tmp/ca.jahed.rtpoet.papyrusrt/uml/DartSim.uml DartSim::RandomSeed operation RandomSeed */
    randomGenerator(std::random_device()())
    /* UMLRTGEN-USERREGION-END */
}

int RandomSeed::getInstance()
{
    /* UMLRTGEN-USERREGION-BEGIN file:/tmp/ca.jahed.rtpoet.papyrusrt/uml/DartSim.uml DartSim::RandomSeed operation getInstance */
    if (instance.get() == nullptr) {
    instance.reset(new RandomSeed);
    }
    return *instance;
    /* UMLRTGEN-USERREGION-END */
}

int RandomSeed::getNextSeed()
{
    /* UMLRTGEN-USERREGION-BEGIN file:/tmp/ca.jahed.rtpoet.papyrusrt/uml/DartSim.uml DartSim::RandomSeed operation getNextSeed */
    return getInstance().getSeed();
    /* UMLRTGEN-USERREGION-END */
}

int RandomSeed::seed( int seed )
{
    /* UMLRTGEN-USERREGION-BEGIN file:/tmp/ca.jahed.rtpoet.papyrusrt/uml/DartSim.uml DartSim::RandomSeed operation seed */
    getInstance().randomGenerator.seed(seed);
    /* UMLRTGEN-USERREGION-END */
}

int RandomSeed::getSeed()
{
    /* UMLRTGEN-USERREGION-BEGIN file:/tmp/ca.jahed.rtpoet.papyrusrt/uml/DartSim.uml DartSim::RandomSeed operation getSeed */
    return uniform(randomGenerator);
    /* UMLRTGEN-USERREGION-END */
}



const UMLRTObject_class UMLRTType_RandomSeed = 
{
    UMLRTObjectInitialize<RandomSeed>,
    UMLRTObjectCopy<RandomSeed>,
    UMLRTObject_decode,
    UMLRTObject_encode,
    UMLRTObjectDestroy<RandomSeed>,
    UMLRTObject_fprintf,
    "RandomSeed",
    NULL,
    {
        sizeof( RandomSeed ),
        0,
        RandomSeed::fields
    },
    UMLRTOBJECTCLASS_DEFAULT_VERSION,
    UMLRTOBJECTCLASS_DEFAULT_BACKWARDS
};


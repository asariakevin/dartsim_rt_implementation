
#include "RealEnvironment.hh"

#include "umlrtobjectclass.hh"
#include "umlrtobjectclassgeneric.hh"
#include <cstddef>

const UMLRTObject_field RealEnvironment::fields[] = 
{
    {
        "size",
        &UMLRTType_Coordinate,
        offsetof( RealEnvironment, size ),
        1,
        0
    }
};


int RealEnvironment::populate( Coordinate size, unsigned numOfObjects )
{
    /* UMLRTGEN-USERREGION-BEGIN file:/tmp/ca.jahed.rtpoet.papyrusrt/uml/DartSim.uml DartSim::RealEnvironment operation populate */
    this->size = size;
    envMap.clear();
    std::default_random_engine gen(RandomSeed::getNextSeed());
    std::uniform_int_distribution<> unifX(0, size.x - 1);
    std::uniform_int_distribution<> unifY(0, size.y - 1);
    while (numOfObjects > 0) {
    unsigned x = unifX(gen);
    unsigned y = unifY(gen);
    while (envMap[Coordinate(x,y)]) {
    x = unifX(gen);
    y = unifY(gen);
    }
    envMap[Coordinate(x,y)] = true;
    numOfObjects--;
    }
    /* UMLRTGEN-USERREGION-END */
}

int RealEnvironment::getSize()
{
    /* UMLRTGEN-USERREGION-BEGIN file:/tmp/ca.jahed.rtpoet.papyrusrt/uml/DartSim.uml DartSim::RealEnvironment operation getSize */
    return size;
    /* UMLRTGEN-USERREGION-END */
}

int RealEnvironment::isObjectAt( Coordinate location )
{
    /* UMLRTGEN-USERREGION-BEGIN file:/tmp/ca.jahed.rtpoet.papyrusrt/uml/DartSim.uml DartSim::RealEnvironment operation isObjectAt */
    bool isThere = false;
    const auto it = envMap.find(location);
    if (it != envMap.end()) {
    isThere = it->second;
    }
    return isThere;
    /* UMLRTGEN-USERREGION-END */
}

int RealEnvironment::setAt( Coordinate location, bool objectPresent )
{
    /* UMLRTGEN-USERREGION-BEGIN file:/tmp/ca.jahed.rtpoet.papyrusrt/uml/DartSim.uml DartSim::RealEnvironment operation setAt */
    envMap[location] = objectPresent;
    /* UMLRTGEN-USERREGION-END */
}



const UMLRTObject_class UMLRTType_RealEnvironment = 
{
    UMLRTObjectInitialize<RealEnvironment>,
    UMLRTObjectCopy<RealEnvironment>,
    UMLRTObject_decode,
    UMLRTObject_encode,
    UMLRTObjectDestroy<RealEnvironment>,
    UMLRTObject_fprintf,
    "RealEnvironment",
    NULL,
    {
        sizeof( RealEnvironment ),
        1,
        RealEnvironment::fields
    },
    UMLRTOBJECTCLASS_DEFAULT_VERSION,
    UMLRTOBJECTCLASS_DEFAULT_BACKWARDS
};


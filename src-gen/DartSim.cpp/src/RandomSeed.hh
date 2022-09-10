
#ifndef RANDOMSEED_HH
#define RANDOMSEED_HH

#include "umlrtobjectclass.hh"

class RandomSeed
{
protected:
    std::unique_ptr<RandomSeed> instance;
    std::uniform_int_distribution<> uniform;
    std::default_random_engine randomGenerator;
public:
    int RandomSeed();
    int getInstance();
    int getNextSeed();
    int seed( int seed );
    int getSeed();
    static const UMLRTObject_field fields[];
};
extern const UMLRTObject_class UMLRTType_RandomSeed;

#endif


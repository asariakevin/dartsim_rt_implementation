
#ifndef THREAT_HH
#define THREAT_HH

#include "TeamConfiguration.hh"
#include "umlrtobjectclass.hh"

class Threat
{
protected:
    double range;
    double destructionFormationFactor;
    std::uniform_real_distribution<> uniform;
    std::default_random_engine randomGenerator;
public:
    int Threat( double range, double destructionFormationFactor );
    int isDestroyed( RealEnvironment threatEnv, TeamConfiguration config, Coordinate location );
    int getProbabilityOfDestruction( TeamConfiguration config );
    static const UMLRTObject_field fields[];
};
extern const UMLRTObject_class UMLRTType_Threat;

#endif


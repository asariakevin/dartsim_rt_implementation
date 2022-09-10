
#ifndef DETERMINISTICTARGETSENSOR_HH
#define DETERMINISTICTARGETSENSOR_HH

#include "TeamConfiguration.hh"
#include "umlrtobjectclass.hh"

class DeterministicTargetSensor
{
protected:
    double range;
    double detectionFormationFactor;
    std::uniform_real_distribution<> uniform;
    std::default_random_engine randomGenerator;
public:
    int DeterministicTargetSensor( double range, double detectionFormationFactor );
    int sense( TeamConfiguration config, bool targetPresent );
    int getProbabilityOfDetection( TeamConfiguration config );
    static const UMLRTObject_field fields[];
};
extern const UMLRTObject_class UMLRTType_DeterministicTargetSensor;

#endif


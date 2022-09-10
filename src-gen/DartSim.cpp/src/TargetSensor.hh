
#ifndef TARGETSENSOR_HH
#define TARGETSENSOR_HH

#include "TeamConfiguration.hh"
#include "umlrtobjectclass.hh"

class TargetSensor
{
protected:
    double range;
    double detectionFormationFactor;
    std::uniform_real_distribution<> uniform;
    std::default_random_engine randomGenerator;
public:
    int TargetSensor( double range, double detectionFormationFactor );
    int sense( TeamConfiguration config, bool targetPresent );
    int getProbabilityOfDetection( TeamConfiguration config );
    static const UMLRTObject_field fields[];
};
extern const UMLRTObject_class UMLRTType_TargetSensor;

#endif


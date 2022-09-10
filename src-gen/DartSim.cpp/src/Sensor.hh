
#ifndef SENSOR_HH
#define SENSOR_HH

#include "umlrtobjectclass.hh"

class Sensor
{
protected:
    double fpr;
    double fnr;
    std::uniform_real_distribution uniform;
    std::default_random_engine randomGenerator;
public:
    int Sensor( double falsePositiveRate, double falseNegativeRate );
    int sense( bool truth );
    static const UMLRTObject_field fields[];
};
extern const UMLRTObject_class UMLRTType_Sensor;

#endif


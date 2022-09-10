
#ifndef LONGRANGESENSORPARAMS_HH
#define LONGRANGESENSORPARAMS_HH

#include "umlrtobjectclass.hh"

class LongRangeSensorParams
{
public:
    LongRangeSensorParams();
    double threatSensorFPR;
    double threatSensorFNR;
    double targetSensorFPR;
    double targetSensorFNR;
    static const UMLRTObject_field fields[];
};
extern const UMLRTObject_class UMLRTType_LongRangeSensorParams;

#endif


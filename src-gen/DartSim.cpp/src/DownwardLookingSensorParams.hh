
#ifndef DOWNWARDLOOKINGSENSORPARAMS_HH
#define DOWNWARDLOOKINGSENSORPARAMS_HH

#include "umlrtobjectclass.hh"

class DownwardLookingSensorParams
{
public:
    DownwardLookingSensorParams();
    double targetDetectionFormationFactor;
    unsigned targetSensorRange;
    static const UMLRTObject_field fields[];
};
extern const UMLRTObject_class UMLRTType_DownwardLookingSensorParams;

#endif


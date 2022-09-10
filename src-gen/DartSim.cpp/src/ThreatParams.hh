
#ifndef THREATPARAMS_HH
#define THREATPARAMS_HH

#include "umlrtobjectclass.hh"

class ThreatParams
{
public:
    ThreatParams();
    double destructionFormationFactor;
    unsigned threatRange;
    static const UMLRTObject_field fields[];
};
extern const UMLRTObject_class UMLRTType_ThreatParams;

#endif


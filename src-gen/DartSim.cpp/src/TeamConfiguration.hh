
#ifndef TEAMCONFIGURATION_HH
#define TEAMCONFIGURATION_HH

#include "Formation.hh"
#include "umlrtobjectclass.hh"

class TeamConfiguration
{
public:
    unsigned altitudeLevel;
    Formation formation;
    bool ecm;
    unsigned ttcIncAlt;
    unsigned ttcDecAlt;
    unsigned ttcIncAlt2;
    unsigned ttcDecAlt2;
    static const UMLRTObject_field fields[];
};
extern const UMLRTObject_class UMLRTType_TeamConfiguration;

#endif


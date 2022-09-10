
#ifndef TEAMSTATE_HH
#define TEAMSTATE_HH

#include "Coordinate.hh"
#include "TeamConfiguration.hh"
#include "umlrtobjectclass.hh"

class TeamState
{
public:
    Coordinate position;
    int directionX;
    int directionY;
    TeamConfiguration config;
    static const UMLRTObject_field fields[];
};
extern const UMLRTObject_class UMLRTType_TeamState;

#endif



#ifndef SIMULATIONRESULTS_HH
#define SIMULATIONRESULTS_HH

#include "Coordinate.hh"
#include "umlrtobjectclass.hh"

class SimulationResults
{
public:
    bool destroyed;
    Coordinate whereDestroyed;
    unsigned targetsDetected;
    bool missionSuccess;
    double decisionTimeAvg;
    double decisionTimeVar;
    static const UMLRTObject_field fields[];
};
extern const UMLRTObject_class UMLRTType_SimulationResults;

#endif


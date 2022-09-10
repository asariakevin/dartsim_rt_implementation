
#ifndef SIMULATIONPARAMS_HH
#define SIMULATIONPARAMS_HH

#include "umlrtobjectclass.hh"

class SimulationParams
{
public:
    SimulationParams();
    unsigned mapSize;
    bool squareMap;
    unsigned altitudeLevels;
    unsigned changeAltitudeLatencyPeriods;
    bool optimalityTest;
    LongRangeSensorParams longRangeSensor;
    DownwardLookingSensorParams downwardLookingSensor;
    ThreatParams threat;
    static const UMLRTObject_field fields[];
};
extern const UMLRTObject_class UMLRTType_SimulationParams;

#endif


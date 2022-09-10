
#ifndef REALENVIRONMENT_HH
#define REALENVIRONMENT_HH

#include "Coordinate.hh"
#include "umlrtobjectclass.hh"

class RealEnvironment
{
protected:
    Coordinate size;
    std::map<Coordinate, bool> envMap;
public:
    int populate( Coordinate size, unsigned numOfObjects );
    int getSize();
    int isObjectAt( Coordinate location );
    int setAt( Coordinate location, bool objectPresent );
    static const UMLRTObject_field fields[];
};
extern const UMLRTObject_class UMLRTType_RealEnvironment;

#endif


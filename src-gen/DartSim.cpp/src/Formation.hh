
#ifndef FORMATION_HH
#define FORMATION_HH

#include "umlrtobjectclass.hh"

class Formation
{
public:
    int LOOSE;
    int TIGHT;
    static const UMLRTObject_field fields[];
};
extern const UMLRTObject_class UMLRTType_Formation;

#endif


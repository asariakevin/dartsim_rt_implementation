
#ifndef TACTICLIST_HH
#define TACTICLIST_HH

#include "umlrtobjectclass.hh"

class TacticList
{
public:
    std::set<std::string> tacticList;
    static const UMLRTObject_field fields[];
};
extern const UMLRTObject_class UMLRTType_TacticList;

#endif


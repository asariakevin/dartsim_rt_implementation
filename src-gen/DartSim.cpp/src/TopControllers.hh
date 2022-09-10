
#ifndef TOPCONTROLLERS_HH
#define TOPCONTROLLERS_HH

class UMLRTController;
struct UMLRTCommsPort;
struct UMLRTSlot;

enum CapsuleInstanceId
{
    InstId_Top,
    InstId_Top_adapterInterface,
    InstId_Top_forwardTargetSensor
};
extern UMLRTController * DefaultController;
extern UMLRTCommsPort borderports_Top_adapterInterface[];
extern UMLRTCommsPort borderports_Top_forwardTargetSensor[];
extern UMLRTSlot Top_slots[];

#endif


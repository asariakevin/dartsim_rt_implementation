
#include "TopControllers.hh"

#include "AdapterInterface.hh"
#include "ForwardTargetSensor.hh"
#include "Top.hh"
#include "umlrtcapsuleclass.hh"
#include "umlrtcapsulepart.hh"
#include "umlrtcommsport.hh"
#include "umlrtcommsportfarend.hh"
#include "umlrtcontroller.hh"
#include "umlrtslot.hh"
#include <cstddef>


static UMLRTController DefaultController_( "DefaultController" );

UMLRTController * DefaultController = &DefaultController_;

static Capsule_Top top( &Top, &Top_slots[InstId_Top], NULL, NULL, true );

static UMLRTSlot * slots_Top[] = 
{
    &Top_slots[InstId_Top_adapterInterface],
    &Top_slots[InstId_Top_forwardTargetSensor]
};

static UMLRTCapsulePart parts_Top[] = 
{
    {
        &Top,
        Capsule_Top::part_adapterInterface,
        1,
        &slots_Top[0]
    },
    {
        &Top,
        Capsule_Top::part_forwardTargetSensor,
        1,
        &slots_Top[1]
    }
};

static UMLRTCommsPortFarEnd borderfarEndList_Top_adapterInterface[] = 
{
    {
        0,
        NULL
    },
    {
        0,
        NULL
    }
};

UMLRTCommsPort borderports_Top_adapterInterface[] = 
{
    {
        &AdapterInterface,
        Capsule_AdapterInterface::borderport_adapterManager,
        &Top_slots[InstId_Top_adapterInterface],
        1,
        borderfarEndList_Top_adapterInterface,
        NULL,
        NULL,
        "",
        true,
        true,
        true,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false
    },
    {
        &AdapterInterface,
        Capsule_AdapterInterface::borderport_log,
        &Top_slots[InstId_Top_adapterInterface],
        1,
        &borderfarEndList_Top_adapterInterface[1],
        NULL,
        NULL,
        "",
        true,
        true,
        true,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false
    }
};

static const UMLRTCommsPort * borderports_Top_adapterInterface_ptrs[] = 
{
    &borderports_Top_adapterInterface[0],
    &borderports_Top_adapterInterface[1]
};

static Capsule_AdapterInterface top_adapterInterface( &AdapterInterface, &Top_slots[InstId_Top_adapterInterface], borderports_Top_adapterInterface_ptrs, NULL, true );

static UMLRTCommsPortFarEnd borderfarEndList_Top_forwardTargetSensor[] = 
{
    {
        0,
        NULL
    },
    {
        0,
        NULL
    }
};

UMLRTCommsPort borderports_Top_forwardTargetSensor[] = 
{
    {
        &ForwardTargetSensor,
        Capsule_ForwardTargetSensor::borderport_simulatorPort,
        &Top_slots[InstId_Top_forwardTargetSensor],
        1,
        &borderfarEndList_Top_forwardTargetSensor[1],
        NULL,
        NULL,
        "",
        true,
        true,
        true,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false
    },
    {
        &ForwardTargetSensor,
        Capsule_ForwardTargetSensor::borderport_log,
        &Top_slots[InstId_Top_forwardTargetSensor],
        1,
        borderfarEndList_Top_forwardTargetSensor,
        NULL,
        NULL,
        "",
        true,
        true,
        true,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false
    }
};

static const UMLRTCommsPort * borderports_Top_forwardTargetSensor_ptrs[] = 
{
    &borderports_Top_forwardTargetSensor[0],
    &borderports_Top_forwardTargetSensor[1]
};

static Capsule_ForwardTargetSensor top_forwardTargetSensor( &ForwardTargetSensor, &Top_slots[InstId_Top_forwardTargetSensor], borderports_Top_forwardTargetSensor_ptrs, NULL, true );

UMLRTSlot Top_slots[] = 
{
    {
        "Top",
        0,
        &Top,
        NULL,
        0,
        &top,
        &DefaultController_,
        2,
        parts_Top,
        0,
        NULL,
        NULL,
        true,
        false
    },
    {
        "Top.adapterInterface",
        0,
        &AdapterInterface,
        &Top,
        Capsule_Top::part_adapterInterface,
        &top_adapterInterface,
        &DefaultController_,
        0,
        NULL,
        2,
        borderports_Top_adapterInterface,
        NULL,
        true,
        false
    },
    {
        "Top.forwardTargetSensor",
        0,
        &ForwardTargetSensor,
        &Top,
        Capsule_Top::part_forwardTargetSensor,
        &top_forwardTargetSensor,
        &DefaultController_,
        0,
        NULL,
        2,
        borderports_Top_forwardTargetSensor,
        NULL,
        true,
        false
    }
};


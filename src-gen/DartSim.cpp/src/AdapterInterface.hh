
#ifndef ADAPTERINTERFACE_HH
#define ADAPTERINTERFACE_HH

#include "AdapterInterfaceToSimulatorProtocol.hh"
#include "umlrtcapsule.hh"
#include "umlrtcapsuleclass.hh"
#include "umlrtlogprotocol.hh"
#include "umlrtmessage.hh"
struct UMLRTCommsPort;
struct UMLRTSlot;

class Capsule_AdapterInterface : public UMLRTCapsule
{
public:
    Capsule_AdapterInterface( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat );
    virtual void inject( const UMLRTMessage & message );
    virtual void initialize( const UMLRTMessage & message );
    const char * getCurrentStateString() const;
private:
    enum State
    {
        running,
        SPECIAL_INTERNAL_STATE_TOP,
        SPECIAL_INTERNAL_STATE_UNVISITED
    };
    const char * stateNames[3];
    State currentState;
    void update_state( State newState );
    void transitionaction_____fIMHhqnT( const UMLRTMessage * msg );
    void actionchain_____fIMHhqnT( const UMLRTMessage * msg );
    State state_____running( const UMLRTMessage * msg );
protected:
    AdapterInterfaceToSimulatorProtocol::Conj adapterManager;
public:
    enum BorderPortId
    {
        borderport_adapterManager,
        borderport_log
    };
protected:
    UMLRTLogProtocol_baserole log;
public:
    enum PartId
    {
    };
    enum PortId
    {
        port_adapterManager,
        port_log
    };
    virtual void bindPort( bool isBorder, int portId, int index );
    virtual void unbindPort( bool isBorder, int portId, int index );
};
extern const UMLRTCapsuleClass AdapterInterface;

#endif


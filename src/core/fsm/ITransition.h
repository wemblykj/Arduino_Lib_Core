#ifndef _CORE_FSM_ITRANSITION_h
#define _CORE_FSM_ITRANSITION_h

namespace Core {

namespace Event {
  class IEvent;
}

namespace FSM {

class IState;

template<class T_StateImpl = IState>
class ITransition {
public:

  virtual void Transition(
    T_StateImpl* fromState, 
    T_StateImpl* toState, 
    const Core::Event::IEvent& event); 
};

} // namespace FSM
} // namespace Core

#endif // _CORE_FSM_ITRANSITION_h

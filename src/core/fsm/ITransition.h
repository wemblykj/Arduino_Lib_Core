#ifndef CORE_FSM_ITRANSITION_h
#define CORE_FSM_ITRANSITION_h

#include "core/fsm/Event.h"

namespace Core {
namespace FSM {

class IState;

template<class T_StateImpl = IState>
class ITransition {
public:

  virtual void Transition(T_StateImpl* fromState, T_StateImpl* toState, Event event); 
};

} // namespace FSM
} // namespace Core

#endif // CORE_FSM_ITRANSITION_h

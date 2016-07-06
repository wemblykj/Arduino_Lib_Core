#ifndef CORE_FSM_IFINITESTATEMACHINE_h
#define CORE_FSM_IFINITESTATEMACHINE_h

#include "FSMEvent.h"

namespace Core {
namespace FSM {

class IState;
class ITransition;

class IFiniteStateMachine
{
public:

  void AddState(IState* state); 
  void RemoveState(IState* state); 

  void AddTransition(IState* fromState, FSMEvent event, IState* toState); 
  void AddTransition(IState* fromState, FSMEvent event, IState* toState, ITransition* transition); 

  void RemoveTransition(IState* fromState, FSMEvent event); 
  void RemoveTransitions(IState* fromState, IState* toState); 
  void RemoveTransitions(IState* state); 

  void Event(FSMEvent event);
};

} // namespace FSM
} // namespace Core

#endif // CORE_FSM_IFINITESTATEMACHINE_h

#ifndef CORE_FSM_IFSM_h
#define CORE_FSM_IFSM_h

#include "FSMEvent.h"

namespace Core {
namespace FSM {

class IState;
class ITransition;

template<class T_StateImpl = IState>
class IFSM {
public:

  T_StateImpl* GetCurrentState();

  bool AddState(T_StateImpl* state); 
  bool RemoveState(T_StateImpl* state); 

  void AddTransition(T_StateImpl* fromState, FSMEvent event, T_StateImpl* toState); 
  void AddTransition(T_StateImpl* fromState, FSMEvent event, T_StateImpl* toState, ITransition* transition); 

  void RemoveTransition(T_StateImpl* fromState, FSMEvent event); 
  void RemoveTransitions(T_StateImpl* fromState, T_StateImpl* toState); 
  void RemoveTransitions(T_StateImpl* state); 

  void Event(FSMEvent event);
};

} // namespace FSM
} // namespace Core

#endif // CORE_FSM_IFSM_h

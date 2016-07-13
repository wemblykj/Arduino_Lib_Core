#ifndef CORE_FSM_IFSM_h
#define CORE_FSM_IFSM_h

#include "ITransition.h"
#include "Event.h"

namespace Core {
namespace FSM {

class IState;

template<class T_StateImpl = IState>
class IFSM {
public:
  virtual T_StateImpl* GetCurrentState() = 0;

  virtual bool AddState(T_StateImpl* state) = 0; 
  virtual bool RemoveState(T_StateImpl* state) = 0; 

  virtual bool AddTransition(T_StateImpl* fromState, Event event, T_StateImpl* toState) = 0;
  virtual bool AddTransition(T_StateImpl* fromState, Event event, T_StateImpl* toState, ITransition<T_StateImpl>* transition) = 0;

  virtual bool RemoveTransition(T_StateImpl* fromState, Event event) = 0;
  virtual bool RemoveTransitions(T_StateImpl* fromState, T_StateImpl* toState) = 0;
  virtual bool RemoveTransitions(T_StateImpl* fromState) = 0;

  virtual bool Event(Event event) = 0;
};

} // namespace FSM
} // namespace Core

#endif // CORE_FSM_IFSM_h

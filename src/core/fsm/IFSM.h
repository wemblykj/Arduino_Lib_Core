#ifndef _CORE_FSM_IFSM_h
#define _CORE_FSM_IFSM_h

#include "core/fsm/ITransition.h"
#include "core/event/IEventClassifier.h"
#include "core/event/IEventListener.h"

namespace Core {

namespace FSM {

class IState;

template<class T_StateImpl = IState>
class IFSM : virtual public Core::Event::IEventListener {
public:
  virtual T_StateImpl* GetCurrentState() = 0;

  virtual bool AddState(T_StateImpl* state) = 0; 
  virtual bool RemoveState(T_StateImpl* state) = 0; 

  virtual bool AddTransition(T_StateImpl* fromState, Core::Event::IEventClassifier& eventClassifier, T_StateImpl* toState) = 0;
  virtual bool AddTransition(T_StateImpl* fromState, Core::Event::IEventClassifier& eventClassifier, T_StateImpl* toState, ITransition<T_StateImpl>* transition) = 0;

  virtual bool RemoveTransition(T_StateImpl* fromState, Core::Event::IEventClassifier& eventClassifier) = 0;
  virtual bool RemoveTransitions(T_StateImpl* fromState, T_StateImpl* toState) = 0;
  virtual bool RemoveTransitions(T_StateImpl* fromState) = 0;
};

} // namespace FSM
} // namespace Core

#endif // _CORE_FSM_IFSM_h

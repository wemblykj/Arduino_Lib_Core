#ifndef _CORE_FSM_DEFAULT_STATE_h
#define _CORE_FSM_DEFAULT_STATE_h

#include "core/fsm/IState.h"

namespace Core {
namespace FSM {
namespace Default {

template<class T_StateImpl = IState>
class State : public T_StateImpl, virtual public IState {
public:
  void Enter() override {
    OnEnter();
  }
  
  void Exit() override {
    OnExit();
  }

  virtual void OnEnter() {}
  virtual void OnExit() {}
};

} // namespace Default
} // namespace FSM
} // namespace Core

#endif _CORE_FSM_DEFAULT_STATE_h

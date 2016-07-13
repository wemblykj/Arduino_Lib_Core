#ifndef CORE_FSM_DEFAULT_STATE_h
#define CORE_FSM_DEFAULT_STATE_h

#include "core/fsm/IState.h"

namespace Core {
namespace FSM {
namespace Default {

class State : public IState {
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

#endif CORE_FSM_DEFAULT_STATE_h

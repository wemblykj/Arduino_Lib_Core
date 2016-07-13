#ifndef CORE_FSM_TIMEOUTSTATE_h
#define CORE_FSM_TIMEOUTSTATE_h

#include "core/fsm/IUpdatableState.h"
#include "core/fsm/Event.h"

namespace Core {
namespace FSM {
namespace Default {

class TimeoutState : public State, public IUpdatableState {
protected:
  time_t mRemaining;
public:
  void Enter() override {
    Reset();
    State::Enter();    
  }
  
  void Exit() override {
  }

  void Update(time_t deltaTime) override {
    if (deltaTime > mRemaining) {
      mRemaining = 0;
      OnTimeout();
    } else {
      OnUpdate(deltaTime);
      mRemaining -= deltaTime;
    } 
  }

  time_t Remaining() { return mRemaining; }
  virtual void Reset() = 0;

  virtual void OnTimeout() {}

  virtual void OnUpdate(time_t deltaTime) {}
};

} // namespace Default
} // namespace FSM
} // namespace Core

#endif CORE_FSM_DEFAULT_TIMEOUTSTATE_h

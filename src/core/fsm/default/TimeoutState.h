#ifndef _CORE_FSM_DEFAULT_TIMEOUTSTATE_h
#define _CORE_FSM_DEFAULT_TIMEOUTSTATE_h

#include "core/IUpdatable.h"

namespace Core {
namespace FSM {
namespace Default {

class IState;

template<class T_StateImpl = IState>
class TimeoutState : public State<T_StateImpl>, virtual public IUpdatable {
protected:
  time_t mRemaining;

public:
  void Enter() override {
    Reset();
    State<T_StateImpl>::Enter();    
  }
  
  void Exit() override {
    State<T_StateImpl>::Exit();
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

#endif _CORE_FSM_DEFAULT_TIMEOUTSTATE_h

#ifndef CORE_FSM_DEFAULT_VARIABLETIMEOUTSTATE_h
#define CORE_FSM_DEFAULT_VARIABLETIMEOUTSTATE_h

#include "core/fsm/default/TimeoutState.h"

namespace Core {
namespace FSM {
namespace Default {

class VariableTimeoutState : public TimeoutState {
private:
  time_t mTimeoutPeriod;
public:
  VariableTimeoutState(time_t timeoutPeriod) {
    mTimeoutPeriod = timeoutPeriod;
  }

  void Reset() {
    mRemaining = mTimeoutPeriod;
  }
};

} // namespace Default
} // namespace FSM
} // namespace Core

#endif CORE_FSM_DEFAULT_VARIABLETIMEOUTSTATE_h

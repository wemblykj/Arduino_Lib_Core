#ifndef _CORE_FSM_DEFAULT_VARIABLETIMEOUTSTATE_h
#define _CORE_FSM_DEFAULT_VARIABLETIMEOUTSTATE_h

#include "core/fsm/default/TimeoutState.h"

namespace Core {
namespace FSM {
namespace Default {

class IState;

template<class T_StateImpl = IState>
class VariableTimeoutState : public TimeoutState<T_StateImpl> {
private:
  time_t mTimeoutPeriod;
public:
  VariableTimeoutState(time_t timeoutPeriod) {
    mTimeoutPeriod = timeoutPeriod;
  }

  void Reset() {
    TimeoutState<T_StateImpl>::mRemaining = mTimeoutPeriod;
  }
};

} // namespace Default
} // namespace FSM
} // namespace Core

#endif _CORE_FSM_DEFAULT_VARIABLETIMEOUTSTATE_h

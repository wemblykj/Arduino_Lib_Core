#ifndef _CORE_FSM_DEFAULT_FIXEDTIMEOUTSTATE_h
#define _CORE_FSM_DEFAULT_FIXEDTIMEOUTSTATE_h

#include "core/fsm/default/TimeoutState.h"

namespace Core {
namespace FSM {
namespace Default {

template<
  int T_TimeoutPeriod,
  class T_StateImpl = IState
>
class FixedTimeoutState : public TimeoutState<T_StateImpl> {
public:
  void Reset() override {
    TimeoutState<T_StateImpl>::mRemaining = T_TimeoutPeriod;
  }
};

} // namespace Default
} // namespace FSM
} // namespace Core

#endif _CORE_FSM_DEFAULT_FIXEDTIMEOUTSTATE_h

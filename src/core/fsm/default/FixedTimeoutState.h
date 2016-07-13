#ifndef CORE_FSM_DEFAULT_FIXEDTIMEOUTSTATE_h
#define CORE_FSM_DEFAULT_FIXEDTIMEOUTSTATE_h

#include "core/fsm/default/TimeoutState.h"

namespace Core {
namespace FSM {
namespace Default {

template<int T_TimeoutPeriod>
class FixedTimeoutState : public TimeoutState {
public:
  void Reset() {
    mRemaining = T_TimeoutPeriod;
  }
};

} // namespace Default
} // namespace FSM
} // namespace Core

#endif CORE_FSM_DEFAULT_FIXEDTIMEOUTSTATE_h

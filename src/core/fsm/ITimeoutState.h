#ifndef CORE_FSM_ITIMEOUTSTATE_h
#define CORE_FSM_ITIMEOUTSTATE_h

#include "core/Types.h"
#include "core/fsm/IUpdatableState.h"

namespace Core {
namespace FSM {

class ITimeoutState : public IUpdatableState {
public:
  virtual void Reset() = 0;
  virtual time_t Remaining() = 0;
};

} // namespace FSM
} // namespace Core

#endif CORE_FSM_ITIMEOUTSTATE_h

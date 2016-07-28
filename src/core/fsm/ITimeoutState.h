#ifndef _CORE_FSM_ITIMEOUTSTATE_h
#define _CORE_FSM_ITIMEOUTSTATE_h

#include "core/Types.h"
#include "core/IUpdatable.h"
#include "core/fsm/IState.h"

namespace Core {
namespace FSM {

class ITimeoutState : virtual public IState, virtual public IUpdatable {
public:
  virtual void Reset() = 0;
  virtual time_t Remaining() = 0;
};

} // namespace FSM
} // namespace Core

#endif _CORE_FSM_ITIMEOUTSTATE_h

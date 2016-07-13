#ifndef CORE_FSM_IUPDATABLESTATE_h
#define CORE_FSM_IUPDATABLESTATE_h

#include "core/Types.h"
#include "core/fsm/IState.h"

namespace Core {
namespace FSM {

class IUpdatableState : public IState {
public:
  virtual void Update(time_t deltaTime) = 0;
};

} // namespace FSM
} // namespace Core

#endif CORE_FSM_IUPDATABLESTATE_h

#ifndef CORE_FSM_ISTATE_h
#define CORE_FSM_ISTATE_h

#include "FSMEvent.h"

namespace Core {
namespace FSM {

class IState
{
public:

  void Enter(FSMEvent event); 
  void Exit(); 
};

} // namespace FSM
} // namespace Core

#endif // CORE_FSM_ISTATE_h

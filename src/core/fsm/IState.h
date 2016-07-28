#ifndef _CORE_FSM_ISTATE_h
#define _CORE_FSM_ISTATE_h

namespace Core {
namespace FSM {

class IState
{
public:
  // Called on entering the state from another state
  virtual void Enter() = 0; 
  virtual void Exit() = 0; 
};

} // namespace FSM
} // namespace Core

#endif // _CORE_FSM_ISTATE_h

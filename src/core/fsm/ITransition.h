#ifndef CORE_FSM_ITRANSITION_h
#define CORE_FSM_ITRANSITION_h

#include "FSMEvent.h"

namespace Core {
namespace FSM {

class IState;

class ITransition
{
public:

  void Transition(IState* fromState, IState* toState, FSMEvent event); 
};

} // namespace FSM
} // namespace Core

#endif // CORE_FSM_ITRANSITION_h

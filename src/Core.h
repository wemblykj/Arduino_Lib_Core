/* Simple forward and bidirectional linked list implementations
 * Paul Wightmore 2015
 */
#ifndef _CORE_CORE_h
#define _CORE_CORE_h

#include "core/LinkedList.h"
#include "impl/fsm/FSM.h"

namespace Core {

template<
  int T_StateCount, 
  int T_TransitionCount,
  class T_StateImpl = FSM::IState>
FSM::IFSM<T_StateImpl>* CreateFSM() {
  return new FSM::FSM<T_StateCount, T_TransitionCount, T_StateImpl>();
}

} // namespace Core

#endif // _CORE_CORE_h

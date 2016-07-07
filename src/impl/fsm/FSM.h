#ifndef CORE_FSM_FSM_h
#define CORE_FSM_FSM_h

#include "core/fsm/IFSM.h"

#include <string.h>

namespace Core {
namespace FSM {

template<
  int T_StateCount, 
  int T_TransitionCount,
  class T_StateImpl = IState>
class FSM : public IFSM<T_StateImpl> {

private:
  struct TransitionEntry {
    T_StateImpl* fromState;
    FSMEvent event;
    T_StateImpl* toState;
    ITransition* transition;
  }; 

  T_StateImpl* m_States[T_StateCount];
  TransitionEntry* m_Transitions[T_TransitionCount];
  T_StateImpl* m_currentState;

public:

  FSM() {
    memset(m_States, 0, sizeof(T_StateImpl*)*T_StateCount);
    memset(m_Transitions, 0, sizeof(T_StateImpl*)*T_TransitionCount);
    m_currentState = nullptr;
  }

  bool AddState(T_StateImpl* state) {
    for(int i = 0; i < T_StateCount; ++i) {
      if (m_States[i] == nullptr) {
        m_States[i] = state;
        return true;
      }
    }

    return false;
  }

  bool RemoveState(T_StateImpl* state) {
    for(int i = 0; i < T_StateCount; ++i) {
      if (m_States[i] == state) {
        if (m_currentState == state) {
          m_currentState = nullptr;
          Event(state, FSM::Removed);
        }

        RemoveTransitions(state);

        m_States[i] = nullptr;
	return true;
      }
    }

    return false;
  }

  bool AddTransition(T_StateImpl* fromState, FSMEvent event, T_StateImpl* toState) {
    return AddTransition(fromState, event, toState, nullptr);
  }

  bool AddTransition(T_StateImpl* fromState, FSMEvent event, T_StateImpl* toState, ITransition* transition) {
    for(int i = 0; i < T_TransitionCount; ++i) {
      auto transitionEntry = m_Transitions[i];
      if (transitionEntry == nullptr) {
        transitionEntry = new TransitionEntry();
        transitionEntry.fromState = fromState;
        transitionEntry.event = event;
        transitionEntry.toState = toState;
        transitionEntry.transition = transition;

        return true;
      } 
    }

    return false;
  }

  bool RemoveTransition(T_StateImpl* fromState, FSMEvent event) {
    for(int i = 0; i < T_TransitionCount; ++i) {
      auto transitionEntry = m_Transitions[i];
      if (transitionEntry != nullptr 
       && transitionEntry.fromState == fromState
       && transitionEntry.event == event) {
        delete(transitionEntry);
        m_Transitions[i] = nullptr; 
        return true;
      }
    }

    return false;
  }

  void RemoveTransitions(T_StateImpl* fromState, T_StateImpl* toState) {
    for(int i = 0; i < T_TransitionCount; ++i) {
      auto transitionEntry = m_Transitions[i];
      if (transitionEntry != nullptr
       && transitionEntry.fromState == fromState
       && transitionEntry.toState == toState) {
        delete(transitionEntry);
        m_Transitions[i] = nullptr; 
      }
    }
  }

  bool RemoveTransitions(T_StateImpl* fromState) {
    bool result = false;
    for(int i = 0; i < T_TransitionCount; ++i) {
      auto transitionEntry = m_Transitions[i];
      if (transitionEntry != nullptr && transitionEntry.fromState == fromState) {
        delete(transitionEntry);
        m_Transitions[i] = nullptr; 
        result = true;
      }
    }

    return result;
  }

  void Event(FSMEvent event) {
    for(int i = 0; i < T_TransitionCount; ++i) {
      auto transitionEntry = m_Transitions[i];
      if (transitionEntry != nullptr 
       && transitionEntry.event == event
       && transitionEntry.fromState == m_currentState) {
        auto fromState = transitionEntry.fromState;
        auto toState = transitionEntry.toState;

	if (fromState != nullptr) {
          fromState.Exit();
        }

        auto transition = transitionEntry.transition;
        if (transition != nullptr) {
          transition.Transition(fromState, toState, event); 
        }

        if (toState != nullptr) {
          toState.Entry();
        }

        m_currentState = toState;
      }
    }
  }
};

} // namespace FSM
} // namespace Core

#endif CORE_FSM_FSM_h

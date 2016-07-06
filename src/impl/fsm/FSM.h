#ifndef CORE_FSM_FSM_h
#define CORE_FSM_FSM_h

#include "core/fsm/IFiniteStateMachine.h"

#include <std>
#include <exception>

namespace Core {
namespace FSM {

template<int T_StateCount, T_TransitionCount>
class FSM : IFiniteStateMachine {

private:
  struct TransitionEntry {
    IState* fromState;
    FSMEvent event;
    IState* toState;
    ITransition* transition;
  } 

  IState* m_States[T_StateCount];
  TransitionEntry* m_Transitions[T_TransitionCount];
  IState* m_currentState;

public:

  void FSM() {
    memset(m_States, 0, sizeof(IState*)*T_StateCount);
    memset(m_Transitions, 0, sizeof(TransitionIState*)*T_TransitionCount);
    m_currentState = nullptr;
  }

  void AddState(IState* state) {
    for(int i = 0; i < T_StateCount; ++i) {
      if (m_States[i] == nullptr) {
        m_States[i] = state;
        return;
      }
    }

    throw Exception("The number of fixed states has been exceeded!"); 
  }

  void RemoveState(IState* state) {
    for(int i = 0; i < T_StateCount; ++i) {
      if (m_States[i] == state) {
        if (m_currentState == state) {
          m_currentState = nullptr;
          Event(state, Removed);
        }

        RemoveTransitions(state);

        m_States[i] = nullptr;
	break;
      }
    }
  }

  void AddTransition(IState* fromState, FSMEvent event, IState* toState) {
    AddTransition(fromState, event, toState, nullptr);
  }

  void AddTransition(IState* fromState, FSMEvent event, IState* toState, ITransition* transition) {
    for(int i = 0; i < T_TransitionCount; ++i) {
      auto transitionEntry = m_Transitions[i];
      if (transitionEntry == nullptr) {
        transitionEntry = new TransitionEntry();
        transitionEntry.fromState = fromState;
        transitionEntry.event = ievent;
        transitionEntry.toState = toState;
        transitionEntry.transition = transition;

        return;
      } 
    }

    throw Exception("The number of fixed states has been exceeded!"); 
  }

  void RemoveTransition(IState* fromState, FSMEvent event) {
    for(int i = 0; i < T_TransitionCount; ++i) {
      auto transitionEntry = m_Transitions[i];
      if (transitionEntry != nullptr 
       && transitionEntry.fromState == fromState
       && transitionEntry.event == event) {
        delete(transitionEntry);
        m_Transitions[i] = nullptr; 
        break;
      }
    }
  }

  void RemoveTransitions(IState* fromState, IState* toState) {
    for(int i = 0; i < T_TransitionCount; ++i) {
      auto transitionEntry = m_Transitions[i];
      if (transitionEntry != null 
       && transitionEntry.fromState == fromState
       && transitionEntry.toState == toState) {
        delete(transitionEntry);
        m_Transitions[i] = nullptr; 
      }
    }
  }

  void RemoveTransitions(IState* fromState) {
    for(int i = 0; i < T_TransitionCount; ++i) {
      auto transitionEntry = m_Transitions[i];
      if (transitionEntry != null && transitionEntry.fromState == fromState) {
        delete(transitionEntry);
        m_Transitions[i] = nullptr; 
      }
    }
  }

  void Event(FSMEvent event) {
    for(int i = 0; i < T_TransitionCount; ++i) {
      auto transitionEntry = m_Transitions[i];
      if (transitionEntry != null 
       && transitionEntry.event == event
       && transitionEntry.fromState == m_currentState) {
        auto fromState = transition.fromState;
        auto toState = transition.toState;

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
}

} // namespace FSM
} // namespace Core

#endif CORE_FSM_FSM_h

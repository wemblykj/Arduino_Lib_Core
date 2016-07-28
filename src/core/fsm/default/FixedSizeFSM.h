#ifndef _CORE_FSM_DEFAULT_FSM_h
#define _CORE_FSM_DEFAULT_FSM_h

#include "core/fsm/IFSM.h"
#include "core/fsm/ITransition.h"
#include "core/event/IEventClassifier.h"

#include <string.h>

namespace Core {
namespace FSM {
namespace Default {

template<
  int T_StateCount, 
  int T_TransitionCount,
  class T_StateImpl = IState>
class FixedSizeFSM : public IFSM<T_StateImpl> {

private:
  struct TransitionEntry {
    TransitionEntry(const Core::Event::IEventClassifier& ec) {
      eventClassifier = ec;
    }

    const Core::Event::IEventClassifier& eventClassifier;
    T_StateImpl* fromState;
    T_StateImpl* toState;
    ITransition<T_StateImpl>* transition;
  }; 

  T_StateImpl* m_States[T_StateCount];
  TransitionEntry* m_Transitions[T_TransitionCount];
  T_StateImpl* m_currentState;

public:

  FixedSizeFSM() {
    memset(m_States, 0, sizeof(T_StateImpl*)*T_StateCount);
    memset(m_Transitions, 0, sizeof(T_StateImpl*)*T_TransitionCount);
    m_currentState = nullptr;
  }

  T_StateImpl* GetCurrentState() {
    return m_currentState;
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
        }

        RemoveTransitions(state);

        m_States[i] = nullptr;
	return true;
      }
    }

    return false;
  }

  bool AddTransition(
	T_StateImpl* fromState, 
	const Core::Event::IEventClassifier& eventClassifier, 
	T_StateImpl* toState) {
    return AddTransition(fromState, eventClassifier, toState, nullptr);
  }

  bool AddTransition(
	T_StateImpl* fromState, 
	const Core::Event::IEventClassifier& eventClassifier, 
	T_StateImpl* toState, 
	ITransition<T_StateImpl>* transition) {
    for(int i = 0; i < T_TransitionCount; ++i) {
      if (m_Transitions[i] == nullptr) {
        auto transitionEntry = new TransitionEntry(eventClassifier);
        transitionEntry->fromState = fromState;
        transitionEntry->toState = toState;
        transitionEntry->transition = transition;

        m_Transitions[i] = transitionEntry;

        return true;
      } 
    }

    return false;
  }

  bool RemoveTransition(
	T_StateImpl* fromState, 
	const Core::Event::IEventClassifier& event) {
    for(int i = 0; i < T_TransitionCount; ++i) {
      const auto transitionEntry = m_Transitions[i];
      if (transitionEntry != nullptr) {
        if (transitionEntry->fromState == fromState
         && transitionEntry->eventClassifier.IsMember(event)) {
          delete(transitionEntry);
          m_Transitions[i] = nullptr; 
          return true;
        }
      }
    }

    return false;
  }

  bool RemoveTransitions(T_StateImpl* fromState, T_StateImpl* toState) {
    bool result = false;
    for(int i = 0; i < T_TransitionCount; ++i) {
      const auto transitionEntry = m_Transitions[i];
      if (transitionEntry != nullptr
       && transitionEntry->fromState == fromState
       && transitionEntry->toState == toState) {
        delete(transitionEntry);
        m_Transitions[i] = nullptr; 
        result = true;
      }
    }

    return result;
  }

  bool RemoveTransitions(T_StateImpl* fromState) {
    bool result = false;
    for(int i = 0; i < T_TransitionCount; ++i) {
      const auto transitionEntry = m_Transitions[i];
     if (transitionEntry != nullptr
       && transitionEntry->fromState == fromState ) {
        delete(transitionEntry);
        m_Transitions[i] = nullptr; 
        result = true;
      }
    }

    return result;
  }

  bool Event(Core::Event::IEvent& event) {
    for(int i = 0; i < T_TransitionCount; ++i) {
      const auto transitionEntry = m_Transitions[i];
      if (transitionEntry == nullptr)
        continue;
 
      if (transitionEntry->eventClassifier.IsMember(event)) 
        continue;

      const auto fromState = transitionEntry->fromState;
      const auto toState = transitionEntry->toState;

      if (fromState != m_currentState)
        continue;

      if (toState == m_currentState) {
        // already there
        return true;
      }

      if (fromState != nullptr) {
        fromState->Exit();
      }

      const auto transition = transitionEntry->transition;
      if (transition != nullptr) {
        transition->Transition(fromState, toState, event); 
      }

      if (toState != nullptr) {
        toState->Enter();
      }

      m_currentState = toState;
    }

    return true;
  }
};

} // namespace Default
} // namespace FSM
} // namespace Core

#endif _CORE_FSM_DEFAULT_FSM_h

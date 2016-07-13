#ifndef CORE_FSM_EVENT_h
#define CORE_FSM_EVENT_h

namespace Core {
namespace FSM {

enum Event {
  //
  // Core Events
  //

  // Request to move to the next state
  // If no state transition is defined go to the next defined state 
  Next = 0,

  // Move to the previous state
  // If no state transition is definedgo to the previously defined state
  Previous = 1,

  // Exit the current state
  // Default behavour is to switch to a null state 
  Exit = 2,

  // Start of user-defined events
  User = 100
};

} // namespace FSM
} // namespace Core

#endif // CORE_FSM_EVENT_h

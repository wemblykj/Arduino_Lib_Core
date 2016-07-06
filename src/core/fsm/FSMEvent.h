#ifndef CORE_FSM_FSMEVENT_h
#define CORE_FSM_FSMEVENT_h

namespace Core {
namespace FSM {

enum FSMEvent {
  Enter = 0,
  Pause = 1,
  Next = 2,
  Previous = 3,
  Reset = 4,
  Exit = 5,
  User = 100
};

} // namespace FSM
} // namespace Core

#endif // CORE_FSM_FSMEVENT_h

#ifndef CORE_EVENT_IEVENT_h
#define CORE_EVENT_IEVENT_h

#include "core/io/EventType.h"

namespace Core {
namespace Event {

class IEvent {
  virtual EventType EventType() = 0;
};

} // namespace Event
} // namespace Core

#endif // CORE_EVENT_IEVENT_h

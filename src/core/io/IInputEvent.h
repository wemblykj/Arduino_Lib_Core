#ifndef CORE_IO_IINPUTEVENT_h
#define CORE_IO_IINPUTEVENT_h

#include "core/event/IEvent.h"
#include "core/io/InputAction.h"

namespace Core {
namespace Io {

class IInputEvent : public Event::IEvent {
  virtual InputType InputType() = 0;
};

} // namespace Io
} // namespace Core

#endif // CORE_IO_INPUTEVENT_h

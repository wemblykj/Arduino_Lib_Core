#ifndef CORE_IO_IBUTTONHANDLER_h
#define CORE_IO_IBUTTONHANDLER_h

#include "core/event/IEventSource.h"

namespace Core {
namespace Io {

class IButton;

class IButtonHandler : public Event::IEventSource {
  virtual void AddButton(IButton* button) = 0;
};

} // namespace Io
} // namespace Core

#endif // CORE_IO_IBUTTONHANDLER_h

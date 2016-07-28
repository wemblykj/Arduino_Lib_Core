#ifndef CORE_IO_IBUTTON_h
#define CORE_IO_IBUTTON_h

#include "core/event/IEventSource.h"

namespace Core {
namespace Io {

class IButton : public Event::IEventSource {
public:
  virtual bool IsPressed() = 0;
};

} // namespace Io
} // namespace Core

#endif // CORE_IO_IBUTTON_h

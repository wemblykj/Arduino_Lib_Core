#ifndef CORE_IO_ILOGICINPUT_h
#define CORE_IO_ILOGICINPUT_h

#include "core/event/IEventSource.h"
#include "core/io/LogicState.h"

namespace Core {
namespace Io {

class ILogicInput : virtual public Event::IEventSource {
public:
  virtual LogicState State() = 0;
  virtual bool IsHigh() = 0;
  virtual bool IsLow() = 0;
};

} // namespace Io
} // namespace Core

#endif // CORE_IO_ILOGICINPUT_h

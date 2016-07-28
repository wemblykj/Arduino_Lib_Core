#ifndef CORE_IO_ILOGICOUTPUT_h
#define CORE_IO_ILOGICOUTPUT_h

#include "core/event/IEventListener.h"
#include "core/io/LogicState.h"

namespace Core {
namespace Io {

class ILogicOutput : virtual public Event::IEventListener {
public:
  virtual void State(LogicState state) = 0;
  virtual void SetHigh() = 0;
  virtual void SetLow() = 0;
};

} // namespace Io
} // namespace Core

#endif // CORE_IO_ILOGICOUTPUT_h

#ifndef CORE_IO_LOGICEVENT_h
#define CORE_IO_LOGICEVENT_h

#include "core/io/IInputEvent.h"

namespace Core {
namespace Io {

class LogicEvent() : public IInputEvent {
public:
  LogicAction LogicAction() {};
};

} // namespace Io
} // namespace Core

#endif // CORE_IO_LOGICEVENT_h

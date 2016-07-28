#ifndef CORE_IO_INPUTEVENT_h
#define CORE_IO_INPUTEVENT_h

#include "core/io/IInputEvent.h"
#include "core/io/InputAction.h"

namespace Core {
namespace Io {

class InputEvent() : public IInputEvent {
public:
  InputAction InputAction() override {};
};

} // namespace Io
} // namespace Core

#endif // CORE_IO_INPUTEVENT_h

#ifndef CORE_IO_IBUTTONEVENT_h
#define CORE_IO_IBUTTONEVENT_h

#include "core/io/IInputEvent.h"
#include "core/io/ButtonAction.h"

namespace Core {
namespace Io {

class IButton;

class IButtonEvent() : public IInputEvent {
public:
  virtual IButton* Button() = 0;
  virtual ButtonAction ButtonAction() = 0;
};

} // namespace Io
} // namespace Core

#endif // CORE_IO_IBUTTONEVENT_h

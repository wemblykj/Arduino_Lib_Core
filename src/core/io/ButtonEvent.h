#ifndef CORE_IO_BUTTONEVENT_h
#define CORE_IO_BUTTONEVENT_h

#include "core/io/IButtonEvent.h"
#include "core/io/IButton.h"

namespace Core {
namespace Io {

//class IButton;

class ButtonEvent() : public IButtonEvent {
private:
  const IButton& mButton;
  ButtonAction mAction;

public:
  ButtonEvent(const IButton& button, ButtonAction action)
    : mButton(button)
    , mAction(action) {
  }

  const IButton& Button() { return mButton; }
  ButtonAction ButtonAction() { return mAction; }
};

} // namespace Io
} // namespace Core

#endif // CORE_IO_BUTTONEVENT_h

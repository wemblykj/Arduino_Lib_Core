#ifndef CORE_IO_LOGICBUTTONADAPTOR_h
#define CORE_IO_LOGICBUTTONADAPTOR_h

#include "core/io/IButton.h"
#include "core/io/LogicAction.h"
#include "core/event/IEventListener.h"
#include "core/event/FixedEventListener.h"

namespace Core {
namespace Io {

class IButton;

template<class T_ListenerImpl, int E_PressedState = Rising, int E_ReleasedState = Falling>
class LogicButtonAdaptor() : public T_ListenerImpl, virtual public IButton, virtual public Event::IEventListener  {
private:
  const ILogicInput& mInput;
  static LogicEventClassifier sEventClassifier();
  ButtonEvent mButtonPressedEvent;
  ButtonEvent mButtonReleasedEvent;

public:
  LogicButton(const ILogicInput& input) 
    : mInput(input)
    , mButtonPressedEvent(this, Pressed),
    , mButtonReleaseEvent(this, Released) {
    mInput.AddListener(this);
  }

  bool OnEvent(const IEvent& event) {
    if (sEventClassifier.IsMember(event)) {
      auto logicEvent = static_cast<ILogicEvent>(event);
      switch(logicEvent.LogicAction) {
        case E_PressedState:
          PushEvent(mButtonPressedEvent);
          break;

        case E_ReleasedState:
          PushEvent(mButtonReleaseEvent);
          break;
      }
    }
  }
};

} // namespace Io
} // namespace Core

#endif // CORE_IO_LOGICBUTTONADAPTOR_h

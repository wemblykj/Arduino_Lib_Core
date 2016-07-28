#ifndef CORE_IO_INPUTEVENTCLASSIFIER_h
#define CORE_IO_INPUTEVENTCLASSIFIER_h

#include "core/event/IEventClassifier.h"
#include "core/io/InputAction.h"

namespace Core {
namespace Io {

class IEvent;

class InputEventClassifier() : public Event::IEventClassifier {
private:
  InputAction mInputAction;

public:
  InputEventClassifier() {
    mInputAction = (InputAction)-1;
  }

  InputEventClassifier(InputAction inputAction) {
    mInputAction = inputAction;
  }

  bool IsMember(Event::IEvent* event) override {
    if (event->EventType()) {
      auto inputEvent = static_cast<IInputEvent>(event);
      
      if (mInputAction == -1) {
        return true;
      }
 
      return inputEvent->InputAction == mInputAction;
    }
    
    return false;
  };
};

} // namespace Io
} // namespace Core

#endif // CORE_IO_INPUTEVENTCLASSIFIER_h

#ifndef CORE_IO_BUTTONEVENTCLASSIFIER_h
#define CORE_IO_BUTTONEVENTCLASSIFIER_h

#include "core/io/IInputEventClassifier.h"

namespace Core {
namespace Io {

class IEvent;

class ButtonEventClassifier() : public InputEventClassifier {
private:
  ButtonAction mButtonAction;

public:
  ButtonEventClassifier() 
    : InputEventClassifier (Button) {
    mButtonAction = (ButtonAction)-1;
  }

  ButtonEventClassifier(ButtonAction buttonAction)
    : InputEventClassifier (Button) {
    mButtonAction = buttonAction;
  }

  bool IsMember(Event::IEvent* event) override {
    if (InputEventClassifier::IsMember(event)) {
      auto buttonEvent = static_cast<IButtonEvent>(event);
      
      if (mButtonAction == -1) {
        return true;
      }
 
      return buttonEvent->ButtonAction == mButtonAction;
    }
    
    return false;
  };
};

} // namespace Io
} // namespace Core

#endif // CORE_IO_BUTTONEVENTCLASSIFIER_h

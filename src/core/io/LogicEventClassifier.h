#ifndef CORE_IO_LOGICEVENTCLASSIFIER_h
#define CORE_IO_LOGICEVENTCLASSIFIER_h

#include "core/io/InputEventClassifier.h"
#include "core/io/LogicAction.h"

namespace Core {
namespace Io {

class IEvent;

class LogicEventClassifier() : public InputEventClassifier {
private:
  LogicAction mLogicAction;

public:
  LogicEventClassifier() 
    : InputEventClassifier(Logic) {
    mLogicAction = (LogicAction)-1;
  }

  LogicEventClassifier(LogicAction logicAction)
    : InputEventClassifier(Logic) {
    mLogicAction = logicAction;
  }

  bool IsMember(Event::IEvent* event) override {
    if (InputEventClassifier::IsMember(event)) {
      auto logicEvent = static_cast<ILogicEvent>(event);
      
      if (mLogicAction == -1) {
        return true;
      }
 
      return logicEvent->LogicAction == mLogicAction;
    }
    
    return false;
  };
};

} // namespace Io
} // namespace Core

#endif // CORE_IO_LOGICEVENTCLASSIFIER_h

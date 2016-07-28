#ifndef CORE_EVENT_IEVENTCLASSIFIER_h
#define CORE_EVENT_IEVENTCLASSIFIER_h

namespace Core {
namespace Event {

class IEvent;

class IEventClassifier {
public:
  virtual bool IsMember(const IEvent& event) = 0;
};

} // namespace Event
} // namespace Core

#endif // CORE_EVENT_IEVENTCLASSIFIER_h

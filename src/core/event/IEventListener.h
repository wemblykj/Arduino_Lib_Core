#ifndef CORE_EVENT_IEVENTLISTENER_h
#define CORE_EVENT_IEVENTLISTENER_h

namespace Core {
namespace Event {

class IEvent;

class IEventListener {
public:
  virtual bool OnEvent(IEvent& event) = 0;
};

} // namespace Event
} // namespace Core

#endif // CORE_EVENT_IEVENTLISTENER_h

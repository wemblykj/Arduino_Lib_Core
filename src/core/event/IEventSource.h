#ifndef CORE_EVENT_IEVENTSOURCE_h
#define CORE_EVENT_IEVENTSOURCE_h

namespace Core {
namespace Event {

class IEventListener;

class IEventSource {
  virtual bool AddListener(IEventListener* listener) = 0;
};

} // namespace Event
} // namespace Core

#endif // CORE_EVENT_IEVENTSOURCE_h

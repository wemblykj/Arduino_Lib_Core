#ifndef CORE_EVENT_FIXEDSIZEEVENTSOURCE_h
#define CORE_EVENT_FIXEDSIZEEVENTSOURCE_h

#include "core/event/IEventSource.h"
#include "core/event/IEventListener.h"

namespace Core {
namespace Event {

class IEvent;

template<int T_ListenerCount>
class FixedSizeEventSource : public IEventSource {
private:
  IEventListener* mListener[T_ListenerCount];
public:
  FixedSizeEventSource() {
    memset(mListeners, 0, sizeof(IEventListener*)*T_ListenerCount);
  }

  bool AddListener(IEventListener* listener) override {
    for(int i = 0; i < T_ListenerCount; ++i) {
      if (mListeners[i] == nullptr) {
        mListener[i] = listener;
        return true;
      }
    }
    
    return false;
  }

  bool PushEvent(IEvent& event) {
    bool result = false;
    for(int i = 0; i < T_ListenerCount; ++i) {
      if (mListeners[i] != nullptr) {
        result |= mListeners[i]->OnEvent(event)
      }
    }

    return result;
  }
};

} // namespace Event
} // namespace Core

#endif // CORE_EVENT_FIXEDSIZEEVENTSOURCE_h

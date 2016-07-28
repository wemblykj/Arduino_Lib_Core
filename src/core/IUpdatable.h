#ifndef CORE_IUPDATABLE_h
#define CORE_IUPDATABLE_h

#include "core/Types.h"

namespace Core {

class IUpdatable {
public:
  virtual void Update(time_t deltaTime) = 0;
};

} // namespace Core

#endif CORE_IUPDATABLE_h

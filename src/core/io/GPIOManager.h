#ifndef CORE_IO_GPIOMANAGER_h
#define CORE_IO_GPIOMANAGER_h

#include "core/IUpdatable.h"

namespace Core {
namespace Io {

class IButton;

template<int T_GPIOCount>
class GPIOManager() : public IUpdatable {
public:
  IGPIO* GetGPIO(int pin);
  ILogicInput* GetInput(int pin);
  ILogicOutput* GetOutput(int pin);

  void Update(time_t deltaTime) override {
  }
};

} // namespace Io
} // namespace Core

#endif // CORE_IO_GPIOMANAGER_h

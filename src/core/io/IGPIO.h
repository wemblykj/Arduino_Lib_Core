#ifndef CORE_IO_IGPIO_h
#define CORE_IO_IGPIO_h

#include "core/io/IGPInput.h"
#include "core/io/IGPOutput.h"
#include "core/io/GPIODirection.h"

namespace Core {
namespace Io {

class IGPIO : virtual public ILogicInput, virtual public ILogicOutput {
public:
  virtual int Pin() = 0;
  virtual void Direction(GPIODirection direction) = 0;
  virtual GPIODirection Direction() = 0;
};

} // namespace Io
} // namespace Core

#endif // CORE_IO_IGPIO_h

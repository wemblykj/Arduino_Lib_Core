#ifndef CORE_IO_IBUTTONMULTIPLEXER_h
#define CORE_IO_IBUTTONMULTIPLEXER_h

#include "core/io/IButton.h"

namespace Core {
namespace Io {


class IButtonMultiplexer : public IButton {
  virtual void AddButton(IButton* button) = 0;
};

} // namespace Io
} // namespace Core

#endif // CORE_IO_IBUTTONMULTIPLEXER_h

#ifndef CORE_IO_BUTTONMULTIPLEXER_h
#define CORE_IO_BUTTONMULTIPLEXER_h

#include "core/io/IButtonMultiplexer.h"

namespace Core {
namespace Io {

class IButton;

class ButtonMultiplexer() : public IButtonMultiplexer {
public:
  void AddButton(IButton* button) override {
  }
};

} // namespace Io
} // namespace Core

#endif // CORE_IO_BUTTONMULTIPLEXER_h

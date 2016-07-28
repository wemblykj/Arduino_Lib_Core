#ifndef CORE_IO_BUTTONACTION_h
#define CORE_IO_BUTTONACTION_h

namespace Core {
namespace Io {

enum ButtonAction {
  Pressed,
  Released,
  SingleClick,
  DoubleClick,
  ShortPress,
  LongPress
};

} // namespace Io
} // namespace Core

#endif // CORE_IO_BUTTONACTION_h

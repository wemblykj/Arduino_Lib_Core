#ifndef _CORE_COLLECTION_IENUMERATOR_h
#define _CORE_COLLECTION_IENUMERATOR_h

namespace Core {
namespace Colleciton {

template<typename T_Payload>
class IEnumerable {
public:
  virtual IForwardIterator<T_Payload> First() = 0;
};

} // namespace Colleciton
} // namespace Core 

#endif // _CORE_COLLECTION_IENUMERATOR_h

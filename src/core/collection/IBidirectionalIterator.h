#ifndef _CORE_COLLECTION_IBIDIRECTIONALITERATOR_h
#define _CORE_COLLECTION_IBIDIRECTIONALITERATOR_h

#include "core/collection/IForwardIterator.h"

namespace Core {
namespace Collection {

template<typename T_Payload>
class IBidirectionalIterator : virtual public IForwardIterator<T_Payload> {
public:
  virtual bool HasPrevious() = 0;
  virtual T_Payload Previous() = 0;
};

} // namespace Collection
} // namespace Core 

#endif // _CORE_COLLECTION_IBIDIRECTIONALITERATOR_h

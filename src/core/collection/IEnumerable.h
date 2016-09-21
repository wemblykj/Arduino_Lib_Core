#ifndef _CORE_COLLECTION_IENUMERATOR_h
#define _CORE_COLLECTION_IENUMERATOR_h

#include "core/collection/IForwardIterator.h"

namespace Core {
namespace Collection {

template<typename T_Payload, template <typename> class T_Iterator>
class IEnumerable {
public:
  typedef T_Iterator<T_Payload> Iterator;

  virtual Iterator First() const = 0;
  //virtual Iterator begin() const = 0;
  //virtual Iterator end() const = 0;
};

} // namespace Collection
} // namespace Core 

#endif // _CORE_COLLECTION_IENUMERATOR_h

#ifndef _CORE_COLLECTION_ICOLLECTION_h
#define _CORE_COLLECTION_ICOLLECTION_h

#include "core/collection/IEnumerable.h"
#include "core/collection/IForwardIterator.h"

namespace Core {
namespace Colleciton {

template<
  typename T_Payload,
  class T_Iterator = IForwardIterator
>
class ICollection : IEnumerable<T_Payload> {
protected:
  typedef T_Iterator<T_Payload> Iterator;

public:
  virtual int Count() = 0;
  virtual int Clear() = 0;
  virtual Iterator Add(T_Payload payload) = 0;
  virtual Iterator Remove(Iterator iterator) = 0;
  virtual Iterator Find(T_Payload payload) = 0;
  virtual bool Contains(T_Payload payload) = 0;
};

} // namespace Colleciton
} // namespace Core 

#endif // _CORE_COLLECTION_ICOLLECTION_h

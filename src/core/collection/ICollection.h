#ifndef _CORE_COLLECTION_ICOLLECTION_h
#define _CORE_COLLECTION_ICOLLECTION_h

#include "core/collection/IEnumerable.h"
#include "core/collection/IForwardIterator.h"

namespace Core {
namespace Collection {

template<
  typename T_Payload,
  template <typename> class T_Iterator
>
class ICollection : public IEnumerable<T_Payload, T_Iterator> {
  
public:
  typedef typename IEnumerable<T_Payload, T_Iterator>::Iterator Iterator;

  virtual int Count() const = 0;
  virtual void Clear() = 0;
  virtual Iterator Add(T_Payload payload) = 0;
  virtual Iterator Remove(const Iterator& iterator) = 0;
  virtual Iterator Find(const T_Payload payload) const = 0;
  virtual bool Contains(const T_Payload payload) const = 0;
};

} // namespace Collection
} // namespace Core 

#endif // _CORE_COLLECTION_ICOLLECTION_h

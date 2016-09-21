#ifndef CORE_COLLECTION_ARRAYITERATOR_h
#define CORE_COLLECTION_ARRAYITERATOR_h

#include "core/collection/IBidirectionalIterator.h"

namespace Core {
namespace Collection {

template<typename T_Payload>
class ArrayIterator : public IBidirectionalIterator<T_Payload> {
public:
  class Delegate {
  public:
	virtual T_Payload Get(int index) const = 0;
	virtual int Count() const = 0;
  };

private:

  const Delegate* mDelegate;
  int mIndex;
  
public:

  ArrayIterator(const Delegate* delegate, int index)
    : mDelegate(delegate)
    , mIndex(index) {
  }

  bool operator!= (const ArrayIterator& other) const {
	  return mIndex != other.mIndex;
  }
  
  const ArrayIterator& operator++ () {
	  ++mIndex;
	  return *this;
  }
  
  T_Payload operator* () const {
	  return mDelegate->Get(mIndex);
  }
  
  bool HasNext() {
    return mIndex < mDelegate->Count();
  }    

  T_Payload Next() {
    return mDelegate->Get(mIndex++); 
  }

  bool HasPrevious() {
    return mIndex > 0;
  }    

  T_Payload Previous() {
    return mDelegate->Get(--mIndex);
  }

  int Index() const {
    return mIndex;
  }
};

} // namespace Collection
} // namespace Core

#endif // CORE_COLLECTION_ARRAYITERATOR_h

#ifndef CORE_COLLECTION_FIXEDARRAY_h
#define CORE_COLLECTION_FIXEDARRAY_h

#include "core/collection/ICollection.h"
#include "core/collection/ArrayIterator.h"

namespace Core {
namespace Collection {

template<
  typename T_Payload, 
  int T_Size
>
class FixedArray : public ICollection<
  T_Payload, 
  IBidirectionalIterator 
{
  T_Payload mItems[T_Size];
  int mCount;

public:

  FixedArray() {
    Clear();
  }

  Iterator First() {
    return ArrayIterator<FixedArray>(*this, 0);
  }
 
  int Count() {
    return mCount;
  }

  void Clear() {
    memset(mItems, 0, sizeof(T_Payload)*T_Size);
    mCount = 0;
  }

  Iterator Add(T_Payload payload) {
    if (mCount == T_Size)
      return ArrayIterator(mItems, mCount);
    
    mArray[mCount] = payload;    
    return ArrayIterator(mItems, mCount++);
  }

  Iterator Remove(const Iterator& iterator) {
    const int index = static_cast<ArrayIterator>iterator.Index();

    --mCount;

    if (index < mCount) {
      while(index < mCount) {
        mArray[index] = mArray[++index];
      }

      return iterator; 
    }
    
    return ArrayIterator(mItems, mCount);
  }

  Iterator Find(T_Payload payload) {
    for(int i = 0; i < mCount; ++i) {
      if (mArray[i] == payload) {
        return ArrayIterator(mItems, i);
      }
    }

    return ArrayIterator(mItems, mCount);
  }
};

} // namespace Colleciton
} // namespace Core

#endif CORE_COLLECTION_FIXEDARRAY_h

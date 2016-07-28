#ifndef CORE_COLLECTION_DYNAMICARRAY_h
#define CORE_COLLECTION_DYNAMICARRAY_h

#include "core/collection/ICollection.h"
#include "core/collection/ArrayIterator.h"

namespace Core {
namespace Collection {

template<
  typename T_Payload, 
>
class DynamicArray : public ICollection<
  T_Payload, 
  IBidirectionalIterator<T_Payload>> 
{
  typedef IBidirectionalIterator<T_Payload> Iterator;

  T_Payload *mItems[];
  int mSize;
  int mCount;

public:
  DynamicArray(int size)
    : mSize(size)
    , mItems(new T_Payload[size]) {
    Clear();
  }

  ~DynamicArray() {
    Clear();
    delete[] mItems;
  }

  Resize(int size) {
    auto items = new T_Payload[size];
    int count = (mCount < size) ? mCount : size;
    memcpy(items, mItems, sizeof(T_Payload) * count);
    mCount = count;
    mSize = size;
    mItems = items;
  }

  // ICollection

  int Count() {
    return mCount;
  }

  void Clear() {
    memset(mItems, 0, sizeof(T_Payload)*T_Size);
    mCount = 0;
  }

  Iterator Add(T_Payload payload) {
    if (mCount == mSize) {
      // TODO: Work out growth algorithm (10%?)
      Resize(mCount+1);
    }
 
    mArray[mCount++] = payload;    
    return ArrayIterator(mItems, i);
  }

  Iterator Remove(const Iterator& iterator) {
    const int index = static_cast<ArrayIterator>iterator.Index();

    --mCount;

    if (index < mCount) {
      while(index < mCount) {
        mArray[index] = mArray[++index];
      }

      // TODO: Should we resize on reducing count by 10%

      return iterator; 
    }
    
    return ArrayIterator::Null();
  }

  Iterator Find(T_Payload payload) {
    for(int i = 0; i < mCount; ++i) {
      if (mItems[i] == payload) {
        return ArrayIterator(mItems, i);
      }
    }

    return ArrayIterator::Null();
  }

  // IEnumerator

  Iterator First() {
    return Iterator(mItems);
  }
 
};

} // namespace Colleciton
} // namespace Core

#endif CORE_COLLECTION_FIXEDARRAY_h

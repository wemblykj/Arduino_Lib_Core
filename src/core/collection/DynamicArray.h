#ifndef CORE_COLLECTION_DYNAMICARRAY_h
#define CORE_COLLECTION_DYNAMICARRAY_h

#include "core/collection/ICollection.h"
#include "core/collection/ArrayIterator.h"

namespace Core {
namespace Collection {

template<
  typename T_Payload,
  int T_InitialCapacity,
  int T_CapacityIncrement 
>
class DynamicArray : public ICollection<T_Payload, ArrayIterator>, public ArrayIterator<T_Payload>::Delegate 
{
  T_Payload *mItems;
  int mCapacity;
  int mCount;
  
public:

  typedef typename ICollection<T_Payload, ArrayIterator>::Iterator Iterator;

  DynamicArray()
    : mItems(new T_Payload[T_InitialCapacity])
	, mCapacity(T_InitialCapacity)
	, mCount(0) {
    Clear();
  }

  ~DynamicArray() {
    Clear();
    delete[] mItems;
  }

  void Resize(int capacity) {
    auto items = new T_Payload[capacity];
    int count = (mCount < capacity) ? mCount : capacity;
    memcpy(items, mItems, sizeof(T_Payload) * count);
    if (capacity > count) {
        memset(&items[count], 0, sizeof(T_Payload)*(capacity-count));
	}
    mCount = count;
    mCapacity = capacity;
	delete[] mItems;
    mItems = items;
  }

  // ICollection

  Iterator begin() const {
	return ArrayIterator<T_Payload>(this, 0);
  }

  Iterator end() const {
	return ArrayIterator<T_Payload>(this, mCount);
  }

  Iterator First() const override {
	return ArrayIterator<T_Payload>(this, 0);
  }

  int Count() const override {
	  return mCount;
  }

  void Clear() override {
	if (mCapacity != T_InitialCapacity) {
		delete[] mItems;
		mItems = new T_Payload[T_InitialCapacity];
		mCapacity = T_InitialCapacity;
	}
	  
    memset(mItems, 0, sizeof(T_Payload)*T_InitialCapacity);
    mCount = 0;
  }

  Iterator Add(T_Payload payload) override {
    if (mCount == mCapacity) {
      // TODO: Work out growth algorithm (10%?)
      Resize(mCapacity + T_CapacityIncrement);
    }
 
    mItems[mCount] = payload;    
    return ArrayIterator<T_Payload>(this, mCount++);
  }

  Iterator Remove(const Iterator& iterator) override {
    int index = iterator.Index();

    --mCount;

    if (index < mCount) {
      while(index < mCount) {
        mItems[index] = mItems[index];
		++index;
      }

      // TODO: Should we resize on reducing count by 10%

      return iterator; 
    }
    
    return ArrayIterator<T_Payload>(this, mCount);
  }

  Iterator Find(const T_Payload payload) const override {
    for(int i = 0; i < mCount; ++i) {
      if (mItems[i] == payload) {
        return ArrayIterator<T_Payload>(this, i);
      }
    }

    return ArrayIterator<T_Payload>(this, mCount);
  }

  bool Contains(const T_Payload payload) const override {
	for(int i = 0; i < mCount; ++i) {
		if (mItems[i] == payload) {
			return true;
		}
	}
	
	return false;
  }

  // ArrayIterator::Delegate

  T_Payload Get(int index) const override {
	return mItems[index];
  }
  
  // DynamicArray
  
  int GetCapacity() const {
	  return mCapacity;
  }
};

} // namespace Collection
} // namespace Core

#endif // CORE_COLLECTION_DYNAMICARRAY_h

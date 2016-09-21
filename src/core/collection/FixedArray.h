#ifndef CORE_COLLECTION_FIXEDARRAY_h
#define CORE_COLLECTION_FIXEDARRAY_h

//#include "core/collection/IBidirectionalIterator.h"
#include "core/collection/ICollection.h"
#include "core/collection/ArrayIterator.h"

#include <string.h>

namespace Core {
namespace Collection {

template<typename T_Payload, int T_Size>
class FixedArray : public ICollection<T_Payload, ArrayIterator>, public ArrayIterator<T_Payload>::Delegate
{
  T_Payload mItems[T_Size];
  int mCount;
  
public:

  typedef typename ICollection<T_Payload, ArrayIterator>::Iterator Iterator;

  FixedArray() {
    Clear();
  }

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
    memset(mItems, 0, sizeof(T_Payload)*T_Size);
    mCount = 0;
  }

  Iterator Add(T_Payload payload) override {
    if (mCount == T_Size)
      return ArrayIterator<T_Payload>(this, mCount);
    
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

      return ArrayIterator<T_Payload>(this, index);
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
};

template<typename T_Payload, int T_Size> typename FixedArray<T_Payload, T_Size>::Iterator begin(FixedArray<T_Payload, T_Size>& buf) {
	return {};//{ buf..data, buf.beginPosition };
}

template<typename T_Payload, int T_Size> typename FixedArray<T_Payload, T_Size>::Iterator end(FixedArray<T_Payload, T_Size>& buf) {
	return {}; // buf.data, buf.endPosition };
}

} // namespace Collection
} // namespace Core

namespace std
{
	template<typename T_Payload, int T_Size> typename Core::Collection::FixedArray<T_Payload, T_Size>::Iterator begin(Core::Collection::FixedArray<T_Payload, T_Size>& buf) {
		return {};//{ buf..data, buf.beginPosition };
	}

	template<typename T_Payload, int T_Size> typename Core::Collection::FixedArray<T_Payload, T_Size>::Iterator end(Core::Collection::FixedArray<T_Payload, T_Size>& buf) {
		return {}; // buf.data, buf.endPosition };
	}
}
#endif // CORE_COLLECTION_FIXEDARRAY_h

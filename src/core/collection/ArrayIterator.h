#ifndef CORE_COLLECTION_ARRAYITERATOR_h
#define CORE_COLLECTION_ARRAYITERATOR_h

namespace Core {
namespace Collection {

template<typename T_Payload>
class ArrayIterator : public IBidirectionalIterator<T_Payload> {
  T_Payload mArray[];
  int mCount;
  int mIndex;
  
public:
  ArrayIterator(T_Payload array[], int count, int start)
    : mArray(array)
    , mCount(count)
    , mIndex(start) {
  }
  
  bool HasNext() {
    return mIndex < mCount;
  }    

  T_Payload Next() {
    return mArray[mIndex++]; 
  }

  bool HasPrevious() {
    return mIndex > 0;
  }    

  T_Payload Previous() {
    return mArray[--mIndex]; 
  }

  int Index() {
    return mIndex;
  }
};

} // namespace Colleciton
} // namespace Core

#endif CORE_COLLECTION_ARRAYITERATOR_h

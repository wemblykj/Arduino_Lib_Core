#ifndef _CORE_COLLECTION_IFORWARDITERATOR_h
#define _CORE_COLLECTION_IFORWARDITERATOR_h

namespace Core {
namespace Collection {

template<typename T_Payload>
class IForwardIterator {
public:
  virtual bool HasNext() = 0;
  virtual T_Payload Next() = 0;
};

} // namespace Collection
} // namespace Core 

#endif // _CORE_COLLECTION_IFORWARDITERATOR_h

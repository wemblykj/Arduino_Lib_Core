/* Simple forward and bidirectional linked list implementations
 * Paul Wightmore 2015
 */
#ifndef _CORE_COLLECTION_LINKEDLIST_h
#define _CORE_COLLECTION_LINKEDLIST_h

#include <stdlib.h>

namespace Core {
namespace Collection {

template<
    typename T_Payload, 
    template <typename> class LinkingPolicy
  >
class LinkedList : public LinkingPolicy<T_Payload> {
public:
  typedef typename LinkingPolicy<T_Payload>::node_t node_t;
  
  LinkedList()
    : mHead(nullptr)
    , mTail(nullptr)
  {}
  
  node_t* head() { return mHead; }
  const node_t* head() const { return mHead; }
  node_t* tail() { return mTail; }
  const node_t* tail() const { return mTail; }
  
  T_Payload pop() {
    if (!mHead)
      return nullptr;
    
    return LinkingPolicy<T_Payload>::pop();
  }
  
  void push(T_Payload p) { 
    if (!mHead)
      mTail = mHead = LinkingPolicy<T_Payload>::createNode(p);
    else
      mHead = LinkingPolicy<T_Payload>::insertNodeBefore(p, mHead);
  }
  
  size_t size() const {
    size_t count = 0;
    auto n = mHead;
    while(n) {
      ++count;
      n = n->next;
    }
    
    return count;
  }
  
  void push_back(T_Payload p) {
    if (!mHead)
      mTail = mHead = LinkingPolicy<T_Payload>::createNode(p);
    else {
      mTail->next = LinkingPolicy<T_Payload>::insertNodeAfter(p, mTail);
      mTail = mTail->next;
    }
  }
  
  bool remove(T_Payload p) {
    if (!mHead)
      return false;
    
    if (mHead->payload == p) {
      mHead = LinkingPolicy<T_Payload>::removeNode(mHead);
      if (mTail->payload == p) 
        mTail = mHead;
      return true;
    } else {
      auto n = mHead;
      while(n->next) {
        if (n->next->payload == p) {
          n->next = LinkingPolicy<T_Payload>::removeNode(n->next);
          if (n->next == nullptr)
            mTail = n;
          return true;
        }
        n = n->next;
      }
    }
    return false;
  }
  
protected:
  node_t* mHead;
  node_t* mTail;
};

template<typename T_Payload>
struct ForwardPolicy {
  struct ForwardNode {
      ForwardNode(T_Payload _payload, struct ForwardNode* _next = nullptr)
        : payload(_payload)
        , next(_next)
      {}
      
	  // TODO: Improve accessing the payload
      //T_Payload* operator->() const { return &payload; }
	  T_Payload payload;
      struct ForwardNode* next;
  };
  
  typedef ForwardNode node_t;
  
  node_t* createNode(T_Payload p) {
    return new ForwardNode(p);
  }
  
  void deleteNode(node_t* n) {
    delete n;
  }
  
  node_t* insertNodeBefore(T_Payload p, node_t* before) {
    return new ForwardNode(p, before);
  }
  
  node_t* insertNodeAfter(T_Payload p, node_t* after) {
    return new ForwardNode(p, after->next);
  }
  
  node_t* removeNode(node_t* n) {
    auto next = n->next;
    deleteNode(n);
    return next;
  }
};

template<typename T_Payload>
struct BidirectionalPolicy {
  struct BidirectionalNode {
      BidirectionalNode(T_Payload _payload, struct BidirectionalNode* _prev = nullptr, struct BidirectionalNode* _next = nullptr)
        : payload(_payload)
        , prev(_prev)
        , next(_next)
      {}
      
      T_Payload* operator->() const { return &payload; }
      struct BidirectionalNode* prev;
      struct BidirectionalNode* next;
      T_Payload payload;
  };
  
  typedef BidirectionalNode node_t;
  
  node_t* createNode(T_Payload p) {
    return new BidirectionalNode(p);
  }
  
  void deleteNode(node_t* n) {
    delete n;
  }
  
  node_t* insertNodeBefore(T_Payload p, node_t* before) {
    return new BidirectionalNode(p, before->prev, before);
  }
  
  node_t* insertNodeAfter(T_Payload p, node_t* after) {
    return new BidirectionalNode(p, after, after->next);
  }
  
  node_t* removeNode(node_t* n) {
    n->next->prev = n->prev;
    auto next = n->next;
    deleteNode(n);
    return next;
  } 
};

template<typename T_Payload>
class ForwardLinkedList : public LinkedList<T_Payload, ForwardPolicy> {};

template<typename T_Payload>
class BidirectionalLinkedList : public LinkedList<T_Payload, BidirectionalPolicy> {};

} // namespace Collection
} // namespace Core

#endif // _CORE_COLLECTION_LINKEDLIST_h

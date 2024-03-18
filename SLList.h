#ifndef __SLLIST_H__
#define __SLLIST_H__
#include <iostream>

namespace ds {

template <typename ItemType> class Node {
public:
  ItemType item;
  Node *next;

  Node(ItemType i, Node *n = nullptr) {
    this->item = i;
    this->next = n;
  }
};

/** Singly linked list. */
template <typename ItemType> class SLList {
  friend class TestDriver<ItemType>; // for autograding only; please ignore

private:
  /** Pointer pointing to the sentinel node. */
  Node<ItemType> *sentinel;

  /** Stores the current size of the list. */
  int count;

public:
  /** Construct a new SLList object. */
  SLList() {
    this->sentinel = new Node<ItemType>(ItemType(), nullptr);
    this->count = 0;
  }


  /** Destroy the SLList object. */
  ~SLList() {
    count = 0;
    while (sentinel != nullptr) {
      Node<ItemType> *curr = sentinel;
      sentinel = sentinel->next;
      delete curr;
    }
  }

  /** Add x at the beginning of the list. */
  void addFirst(ItemType x) {
    count += 1;
    sentinel->next = new Node<ItemType>(x, sentinel->next);
  }

  /** Return the first element. */
  ItemType &getFirst() const { return sentinel->next->item; }

  /** Return the number of elements in list. */
  int size() const { return count; }

  /** Append the list with x. */
  void addLast(ItemType x) {
    count += 1;
    Node<ItemType> *p = sentinel;
    while (p->next != nullptr) {
      p = p->next;
    }
    p->next = new Node<ItemType>(x, nullptr);
  }


  inline SLList(const SLList<ItemType> &other);
  inline ItemType &get(int i) const;
  inline void insertAt (ItemType x, int pos);
  inline ItemType removeFirst();
  inline ItemType removeLast();
  inline void Display();
};

/**
 * Copy-construct a new SLList<ItemType>::SLList object
 *
 * @param other some list
 */
template <typename ItemType>
SLList<ItemType>::SLList(const SLList<ItemType> &other) {
    this->sentinel = new Node<ItemType>(ItemType(), nullptr);
    this->count = 0;

    Node<ItemType> *otherPtr = other.sentinel -> next; //starts otherPtr at first item in original list
    Node<ItemType> *lastNode = this->sentinel;
    while(otherPtr != nullptr)
    {
      Node<ItemType> *newNode = new Node<ItemType>(otherPtr->item, nullptr);
      lastNode->next = newNode;
      lastNode = newNode;
      otherPtr = otherPtr->next;
      this->count++;
    }
}

/**
 *  Return the i-th item in list. Index starts from 0.
 *  For simplicity, assume the item always exists.
 *
 * @param i index of item
 * @return ItemType& the i-th item
 */
template <typename ItemType> ItemType &SLList<ItemType>::get(int i) const 
{
  Node<ItemType> *p = sentinel->next; //creates a new pointer p of Node type, and has it start at first official node in list
  
    int j = 0;
    while (j < i && p!= nullptr) //iterates through entire list until 1-desired index is reached
    {
      p = p -> next; 
      j++;
    }

    return p->item; //returns value stored in list at desired index
  }


/**
 *  Add a new Itemtype of value x into the list at the i-th item in list. Index starts from 0.
 *  For simplicity, assume the list containts at least i number of items.
 * @param x new item to into the list 
 * @param i index for the new item
 */
template <typename ItemType> void SLList<ItemType>::insertAt(ItemType x, int i) 
{
  Node<ItemType> *newptr = new Node<ItemType> (x, nullptr);
  Node<ItemType> *p = sentinel;
  int j = 0;
    while (j < i && p-> next!= nullptr) //iterates through entire list until 1-desired index is reached
    {
      p = p -> next; 
      j++;
    }
  newptr -> next = p->next;
  p -> next = newptr;
  count++;

  if(i==0){
    sentinel->next = newptr;
  }
}

/**
 * Remove and return the first item of the list.
 * For example, list [1,2,3] becomes [2,3] and 1 is returned.
 *
 * @return ItemType the first item in the original list before removing
 */
template <typename ItemType> ItemType SLList<ItemType>::removeFirst() {
  
  if(sentinel->next == nullptr)
  {
    std::cout<<"Empty List!";
  }

  ItemType storedFirst = sentinel -> next -> item;
  Node<ItemType> *tempFirst = sentinel -> next;
  sentinel -> next = sentinel -> next -> next;
  delete tempFirst;
  count--;
  return storedFirst; 
  
}

/**
 * Remove and return the last item of the list.
 * For example, list [1,2,3] becomes [1,2] and 3 is returned.
 *
 * @return ItemType the last item in the original list before removing
 */
template <typename ItemType> ItemType SLList<ItemType>::removeLast() {

  if(sentinel->next == nullptr)
  {
    std::cout<<"Empty List!";
  }

  Node<ItemType> *tempLast = sentinel;
  while((tempLast->next->next) != nullptr)
  {
    tempLast = tempLast-> next;
  }

  ItemType a = tempLast->next-> item; 
  delete tempLast->next;
  tempLast->next = nullptr; //updates the second to last node's next pointer to null, making it the new last node
  count--;
  return a;
}

template <typename ItemType> void SLList<ItemType>::Display() {
    //make p points to current node's next 
    Node<ItemType> *p = this->sentinel -> next; 

    while (p != nullptr) {
    	//display the node p points to
    	std::cout <<" IntList Node at address:"<< p<<std::endl;
    	std::cout <<" ---first----------rest------"<<std::endl;
    	std::cout <<" ! "<<(*p).item <<"\t\t"<<p->next<<"|"<<std::endl;
    	std::cout <<" ---------------------------"<<std::endl;
        std::cout <<std::endl;
     
 
	//move p to points to next node 
        p = p->next; 
    }
  }

}
 // namespace ds

#endif // __SLLIST_H__

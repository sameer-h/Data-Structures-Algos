// header file for the templated DLList

/* Sameer Hussain - CSCE 221 - PA 2*/

#ifndef TEMPLATEDDLLIST_H
#define TEMPLATEDDLLIST_H

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class DLList; // class declaration

// doubly linked list node
template <typename T>
struct DLListNode {
  T obj;
  DLListNode<T> *prev, *next;
  // constructor
  DLListNode<T>(T e=T(), DLListNode *p=nullptr, DLListNode *n=nullptr): obj(e), prev(p), next(n) {}
};

// doubly linked list class
template <typename T>
class DLList {
private:
  DLListNode<T> header, trailer;
public:
  DLList(): header(T()), trailer(T()) {header.next = &trailer; trailer.prev = &header; } // default constructor
  DLList(const DLList<T>& dll); // copy constructor
  DLList(DLList<T>&& dll); // move constructor
  ~DLList(); // destructor
  DLList<T>& operator=(const DLList<T>& dll); // copy assignment operator
  DLList<T>& operator=(DLList<T>&& dll); // move assignment operator
  // return the pointer to the first node
  DLListNode<T> *first_node() const { return header.next; } 
  // return the pointer to the trailer
  const DLListNode<T> *after_last_node() const { return &trailer; }
  // return if the list is empty
  bool is_empty() const { return header.next == &trailer; }
  T first() const; // return the first object
  T last() const; // return the last object
  void insert_first(T obj); // insert to the first node
  T remove_first(); // remove the first node
  void insert_last(T obj); // insert to the last node
  T remove_last(); // remove the last node
  void insert_after(DLListNode<T> &p, T obj);
  void insert_before(DLListNode<T> &p, T obj);
  T remove_after(DLListNode<T> &p);
  T remove_before(DLListNode<T> &p);
};

template<typename T>
DLList<T>::DLList(DLList<T> && dll) // move constructor
{
    if (dll.is_empty()){
        header.next = &trailer;
        trailer.prev = &header;
        return;
    }

    header.next = dll.header.next;

    trailer.prev = dll.trailer.prev;


    dll.header.next->prev = &header;
    trailer.prev->next = &trailer;

    dll.header.next = &dll.trailer;
    dll.trailer.prev = &dll.header;
    

}

template<typename T>
DLList<T>::~DLList() // destructor
{
    DLListNode<T> * pvnode = header.next;
    DLListNode<T> * node = header.next;

    while(node != &trailer) {

        pvnode = node;
        node = node->next;
        delete pvnode;
    }

    header.next = &trailer;
    trailer.prev = &header;
}

/*
template<typename T>
bool DLList<T>::is_empty() const
{
    return header.next == &trailer; 
}
*/
/*
template<typename T>
DLListNode<T> *DLList<T>::first_node() const {
    return header.next;
}
*/
/*
template<typename T>
const DLListNode<T> *DLList<T>::after_last_node() const {
     return &trailer; 
    }
*/

// insert an object to the last node
template<typename T>
void DLList<T>::insert_last(T obj)
{ 
    DLListNode<T> * newNode = new DLListNode<T>(obj, trailer.prev, &trailer);

    trailer.prev->next = newNode;

    trailer.prev = newNode;
}

template<typename T>
DLList<T>::DLList(const DLList<T>& dll)
{
    header.next = &trailer;

    trailer.prev = &header;

    if(!dll.is_empty()) {
        DLListNode<T>* node;
        node = dll.first_node();

        while (node != dll.after_last_node()){
            this->insert_last(node->obj);
            node = node->next;
        }
    }
}

template<typename T>
DLList<T>& DLList<T>::operator=(const DLList<T>& dll) // copy assignment operator
{

  DLListNode<T>* nde = first_node();

  while (nde != after_last_node()) {

    DLListNode<T>* mve = nde;
    nde = nde->next;
    delete mve;
    
  }

  header.next = &trailer;
  trailer.prev = &header;

  nde = dll.first_node();

  while (nde != dll.after_last_node()) {

    insert_last(nde->obj);
    nde = nde->next;

  }

  return *this;
}

// move assignment operator
template<typename T>
DLList<T>& DLList<T>::operator=(DLList<T>&& dll)
{

  DLListNode<T>* nde = first_node();

  while (nde != after_last_node()) {

    DLListNode<T>* move = nde;

    nde = nde->next;

    delete move;

  }

  header.next = dll.header.next;
  trailer.prev = dll.trailer.prev;

  header.next->prev = &header;
  trailer.prev->next = &trailer;

  dll.header.next = &dll.trailer;
  dll.trailer.prev = &dll.header;

  return *this;
}

// return the first object
template<typename T>
T DLList<T>::first() const
{
    if(is_empty()){
        throw runtime_error ("Empty List"); // throwing a runtime error
    }
    return header.next->obj;
}

// return the last object
template<typename T>
T DLList<T>::last() const
{
    if(is_empty()){
       throw runtime_error ("Empty List"); // throwing a runtime error
    }
    return trailer.prev->obj;
}

// insert to the first node
template<typename T>
void DLList<T>::insert_first(T obj)
{
    DLListNode<T> * newNode = new DLListNode<T>(obj, &header, header.next);

    header.next->prev = newNode;

    header.next = newNode;
}

// remove the first node
template<typename T>
T DLList<T>::remove_first()
{
    if(is_empty()){
        throw runtime_error ("Empty List"); // throwing a runtime error
    }

    DLListNode<T> * node = header.next;

    node->next->prev = &header;

    header.next = node->next;

    T obj = node->obj;

    delete node;
    return obj;
}

// remove the last node
template<typename T>
T DLList<T>::remove_last()
{
    if(is_empty()){
      throw runtime_error ("Empty List"); // throwing a runtime error
    }
    DLListNode<T> * n = trailer.prev;

    n->prev->next = &trailer;

    trailer.prev = n->prev;
    
    T obj = n->obj;
    delete n;
    return obj;
}

template<typename T>
void DLList<T>::insert_after(DLListNode<T> &p, T obj)
{
    if(is_empty())
        throw runtime_error ("Empty List");
    DLListNode<T> * newNode = new DLListNode<T>(obj,&p,p.next);

    p.next->prev = newNode;
    p.next = newNode;

}

template<typename T>
void DLList<T>::insert_before(DLListNode<T> &p, T obj)
{
    if(is_empty()){
        throw runtime_error ("Empty List"); // throwing a runtime error
    }
    if(&p == &header){
        throw runtime_error("Cannot insert before header"); // runtime
    }
    DLListNode<T> * newNode = new DLListNode<T>(obj,p.prev,&p);
    p.prev->next = newNode;
    p.prev= newNode;
}

template<typename T>
T DLList<T>::remove_after(DLListNode<T> &p)
{
    if(is_empty())
        throw runtime_error ("Empty List");
    
    if(&p == &trailer || &p == trailer.prev){
      throw runtime_error("Can't remove trailer");
    }
    
    if (header.next == trailer.prev) {

        DLListNode<T>* nde = trailer.prev;

        nde->prev->next = &trailer;

        trailer.prev = nde->prev;

        T value = nde->obj;

        delete nde;

        nde = nullptr;

        header.next = &trailer;

        trailer.prev = &header;

        return value;
  }

  DLListNode<T>* nde = p.next;

  p.next = nde->next;

  nde->next->prev = &p;

  T value = nde->obj;

  delete nde;

  return value;
}

template<typename T>
T DLList<T>::remove_before(DLListNode<T> &p)
{
    if(is_empty()){
        throw runtime_error ("Empty List");
    }

    if(&p == &header || &p == header.next){
      throw runtime_error("Can't remove before header");
    }


    if (header.next == trailer.prev) {

        DLListNode<T>* nde = trailer.prev;

        nde->prev->next = &trailer;

        trailer.prev = nde->prev;

        T value = nde->obj;

        delete nde;

        nde = nullptr;

        header.next = &trailer;

        trailer.prev = &header;

        return value;
    }

    DLListNode<T>* nde = p.prev;

    p.prev = nde->prev;

    nde->prev->next = &p;

    T value = nde->obj;

    delete nde;

    return value;
}


template<typename T>
ostream& operator<<(ostream& out, const DLList<T>& dll)
{

    DLListNode<T> * nde = dll.first_node();
    if (!dll.is_empty()) {

        while(nde != dll.after_last_node()) {

            cout << nde->obj << ", ";

            nde = nde->next;
        }
    }
    cout << endl;
    return out;
}


#endif

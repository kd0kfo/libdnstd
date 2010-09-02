#include "DNode.h"

template <class T> DNode<T>::DNode()
{
  stuff = 0;
  prev = 0;
  next = 0;
}


template <class T> DNode<T>::DNode(const T& item)
{
  stuff = new T(item);
  prev = next = 0;
}
template <class T> DNode<T>::~DNode()
{
  delete stuff;stuff = 0;
}

template <class T>  DNode<T> * DNode<T>::setNext(DNode<T> * newNext)
{
  DNode<T> * temp = next;
  next = newNext;
  return temp;
}

template <class T>  DNode<T> * DNode<T>::setPrev(DNode<T> * newPrev)
{
  DNode<T> * temp = prev;
  prev = newPrev;
  return temp;
}

template <class T> void DNode<T>::setItem(const T& newItem)
{
  if(stuff == 0 )
    stuff = new T;
  *stuff = newItem;
}


#include "DList.h"

template <class T> DList<T>::DList()
{
  curr = tail = head = 0;
}

template <class T> DList<T>::~DList()
  {
    DNode<T>* tmp = head;
    curr = head;
    
    while(curr != 0)
      {
	curr = tmp->getNext();
	delete tmp;
	tmp = curr;
      }
    head = curr = tail = 0;
  }

  template <class T> void DList<T>::add(DNode<T> * newNode)
  {
    if(tail != 0)
      {
	newNode->setPrev(tail);
	tail->setNext(newNode);
	tail = newNode;
      }
    else
      {
	head = curr = tail = newNode;
      }
  }

template <class T> DNode<T> * const  DList<T>::forward()
  {
    curr = curr->getNext();
    return curr;
  }

template <class T> DNode<T> * const DList<T>::backward()
  {
    curr = curr->getPrev();
  }

  template <class T> void DList<T>::deleteNode(DNode<T> * deleteMe)
  {
    DNode<T> * temp;
    if(deleteMe == head)
      {
	temp = head;
	head = temp->getNext();
	delete temp;
	head->setPrev(0);
      }
    else if(deleteMe == tail)
      {
	temp = tail;
	tail = temp->getPrev();
	delete temp;
	tail->setNext(0);
      }
    else
      {
	if(isInList(deleteMe))
	  {
	    temp = deleteMe->getPrev();
	    temp->setNext(deleteMe->getNext());
	    delete deleteMe;
	  }
	else
	  throw DavidException("That node is not on the list",DavidException::DLIST_ERROR_CODE);
      }
    curr = head;
  }

  template <class T> bool DList<T>::isInList(DNode<T> * checkThis)
  {
    DNode<T> * temp = head;
    while(temp != 0)
      {
	if(temp == checkThis)
	  return true;
	
	temp = temp->getNext();
      }
    return false;
  }

template <class T> DNode<T> * DList<T>::setCurr(DNode<T> * newCurr)
{
  DNode<T> * temp = head;
  bool containsIt = false;
  while(temp != 0)
    {
      if(temp == newCurr)
	containsIt = true;
      temp = temp->getNext();
    }
  if(containsIt)
    {
      temp = curr;
      curr = newCurr;
    }
  else
    temp = 0;

  return temp;
}

template <class T> int DList<T>::size() const
{
  int returnMe = 0;
  
  DNode<T> * countUs = head;
  while(countUs != 0)
    {
      returnMe++;
      countUs = countUs->getNext();
    }
  countUs = 0;
  return returnMe;
}

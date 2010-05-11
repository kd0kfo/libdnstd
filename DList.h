#ifndef DLIST_CPP
#define DLIST_CPP

#include "DNode.h"
#include "DavidException.h"

/**
 * My Linked List Class
 *
 * Uses DNode
 *
 * (c) David Coss 2010
 */
template <class T> class DList{

 public:
  /**
   * Creates an empty list
   */
  DList();
  ~DList();

  /**
   * Adds a node to the end of the list
   */
  void add(DNode<T> * newValue);
  
  /**
   * Points the current list node back to the beginning. This is used to restart iteration through the list
   */
  void reset(){curr = head;}
  
  /**
   * Moves one node forward in the list. Returns a pointer to that node.
   */
  DNode<T> * const forward();
  /**
   * Moves one node backwards in the list. Returns a pointer to that node.
   */
  DNode<T> * const backward();

  /**
   * Returns a pointer to the current node.
   */
  DNode<T> * const getCurr() const {return curr;}

  /**
   * Determines which node is the current node in the list and returns a pointer to the previously current node. 
   * If the node is not actually in the list, the current node is unchanged and 0 is returned.
   */
  DNode<T> * setCurr(DNode<T> * newCurr);

  /**
   * Removes a node from the list
   */
  void deleteNode(DNode<T> * deleteMe);

  /**
   * Indicates whether or not the node is contained in the list, without changing the list.
   */
  bool isInList(DNode<T> * checkThis);
  
  /**
   * Gives the number of nodes in the list.
   */
  int size() const;

 private:
  DNode<T> * head;
  DNode<T> * tail;
  DNode<T> * curr;

};


#endif


#ifndef DNODE_CPP
#define DNODE_CPP

/**
 * Node to be used with DList
 * Copyright 2010 David Coss
 */
template <class T> class DNode{

 public:
  /**
   * Empty Constructor. Item pointer equals zero, as do next and previous node pointers
   */
  DNode();

  /**
   * Creates a node containing an object equal to the provided object.
   */
  DNode(const T&);
  ~DNode();
  
  /**
   * Removes the previous node.
   */
  void detachPrev(){prev = 0;}

  /**
   * Removes the next node
   */
  void detachNext(){next = 0;}

  /**
   * Returns a pointer to the next node
   */
  DNode * getNext(){return next;}

  /**
   * Returns a pointer to the previous node
   */
  DNode * getPrev(){return prev;}
  
  /**
   * Sets the next node. A pointer to the pre-existing node is returned.
   */
  DNode * setNext(DNode * newNext);

  /** 
   * Sets the previous node. A pointer to the pre-existing node is returned.
   */
  DNode * setPrev(DNode * newPrev);
  
  /**
   * Returns a constant pointer to the item contained in the node.
   */
  const T * const getItem() const {return stuff;}

  /**
   * Returns a new object equal to the item contained in the node.
   */
  T getItemCopy(){return *stuff;}
  
  /**
   * Sets the value of the item contained in the node.
   */
  void setItem(const T&);

 private:
  T * stuff;
  DNode * prev;
  DNode * next;


};

#endif


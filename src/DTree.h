#ifndef DTREE_CPP
#define DTREE_CPP

#include "DArray.h"
#include "DString.h"

/**
 * Binary Tree used with LinAl
 * Trees contain an item and up to two branches
 *
 * Copyright 2010 David Coss
 */
template<class T> class DTree
{
 public:
  /**
   * Default constructor. Empty Tree.
   */
  DTree();

  /**
   * Copy constructor.
   */
  DTree(const DTree&);

  /**
   * Creates a tree whose object is provided. There are no branches.
   */
  DTree(const T&);

  /**
   * Creates a tree whose object is provided. Pointers to the
   * branches are given
   */
  DTree(const T&, DTree *, DTree *);

  /**
   * Destructor.Objects and branches are deleted.
   */
  ~DTree();

  static DString getVersion(){return DString("1.0");}

  DTree & operator=(const DTree&);

  /**
   * Tests for equality in the object and the branches.
   */
  bool operator==(const DTree&) const;
  bool operator!=(const DTree& tree) const{ return !(*this == tree);}

  /**
   * Returns the DTree's object.
   */
  T const * const getItem() const{ return item; }

  /**
   * Indicates existance of a Left Tree Node
   */
  bool hasLeft() const { return leftNode != 0;}

  /**
   * Retrieves Left tree node
   * @return DTree
   */
  DTree getLeft() const{ return *leftNode; }

  /**
   * Indicates existance of a Left Tree Node
   */
  bool hasRight()const { return rightNode != 0;}


  /**
   * Retrieves Left tree node
   * @return DTree
   */
  DTree getRight()const { return *rightNode; }

  /**
   * Sets the item of the tree
   */
  void setItem(T * o){ item = o;}

  /**
   * Attaches a tree (via pointer) to the left branch
   */
  void setLeft(DTree * tree){ leftNode = tree; }

  /**
   * Attaches a tree (via pointer) to the right branch
   */
  void setRight(DTree * tree){ rightNode = tree; }

  /**
   * Indicates where or not the tree contains an item (regardless of branch count)
   */
  bool isEmpty() const { return item == 0; }
  
  /**
   * Returns a DArray<T> of all of the branches of the tree.
   */
  utils::DArray<T> decompose() const;

  /**
   * Indicates whether there is a branch, regardless of which one it is.
   */
  bool hasChildren() const{return leftNode != 0 && rightNode != 0;}

 private:
  T * item;
  DTree * leftNode;
  DTree * rightNode;
};

#endif


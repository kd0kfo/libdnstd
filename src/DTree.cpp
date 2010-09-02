#include "DTree.h"

template <class T> DTree<T>::~DTree()
	{
		delete item;
		item = 0;
		delete leftNode;
		item = 0;
		delete rightNode;
		item = 0;
	}

template <class T> DTree<T>::DTree(const DTree<T>& copy)
	{
		if(copy.item != 0)
		{
			item = new T;
			*item = *(copy.item);
		}
		else
		{
			item = 0;
		}
		
		if(copy.leftNode == 0)
		{
			leftNode = 0;
		}
		else
		{
		  leftNode = new DTree<T>;
			*leftNode = *(copy.leftNode);
		}
		
		if(copy.rightNode == 0)
		{
			rightNode = 0;
		}
		else
		{
		  rightNode = new DTree<T>();
		  *rightNode = *(copy.rightNode);
		}
	}
		

template<class T> DTree<T>::DTree() 
{
  item = 0;
  leftNode = 0;
  rightNode = 0;
}

template<class T> DTree<T>::DTree(const T& o)
{
  item = new T;
  *item = o;
  leftNode = 0;
  rightNode = 0;
}

template<class T> DTree<T>::DTree(const T& o, DTree<T> * leftTree , DTree<T> * rightTree)
{
  item = new T;
  if(leftTree != 0)
    {
      leftNode = new DTree<T>;
      *leftNode = *leftTree;
    }
  else
	leftNode = 0;
  if(rightTree != 0)
    {
      rightNode = new DTree();
      *rightNode = *rightTree;
    }
  else
    rightNode = 0;
  *item = *o;
  
}

template<class T>	DTree<T> & DTree<T>::operator=(const DTree<T>& copy)
{
  if(this == &copy)
    return *this;
  delete item;
		delete leftNode;
		delete rightNode;
		if(copy.item != 0)
		  {
		    item = new T;
		    *item = *(copy.item);
		  }
		else
		  {
		    item = 0;
		  }
		
		if(copy.leftNode == 0)
		  {
		    leftNode = 0;
		}
		else
		  {
		    leftNode = new DTree<T>;
		    *leftNode = *(copy.leftNode);
		  }
		
		if(copy.rightNode == 0)
		  {
		    rightNode = 0;
		  }
		else
		  {
		    rightNode = new DTree<T>;
		    *rightNode = *(copy.rightNode);
		  }
		return *this;
}

template<class T> bool DTree<T>::operator==(const DTree<T>& tree) const
{
  return (item == tree.item) && (tree.rightNode == rightNode) && (leftNode == tree.leftNode);
}

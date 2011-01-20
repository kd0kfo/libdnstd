#include "DStack.h"

namespace utils{


template <class T> DavidException DStack<T>::EMPTY_STACK = DavidException("The stack is empty","DStack Empty",DavidException::DSTACK_ERROR_CODE);

	template <class T> DStack<T>::DStack()
	{
		itsSize = 0;
		pType = 0;
	}

	template <class T> DStack<T>::DStack(const DStack &rhs)
	{
	  itsSize = rhs.getSize();
	  pType = new T[itsSize];
	  for(ushort i = 0;i<itsSize;i++)
	    pType[i] = rhs[i];
	}

	template <class T>
		DStack<T>::~DStack()
	{
		delete [] pType;
		pType = 0;
	}


  template <class T> bool DStack<T>::operator==(const DStack<T>& rhs) const
  {
    if(rhs.getSize() != this->getSize())
      return false;

    for(int i = 0;i<itsSize;i++)
      if(pType[i] != rhs.pType[i])
	return false;

    return true;
    
  }

	template <class T>
	DStack<T>&	DStack<T>::operator=(const DStack& rhs)
	{
		if(this == &rhs)
			return *this;
		if(pType != 0)
			delete [] pType;
		itsSize = rhs.getSize();
		pType = new T[itsSize];
		for(ushort i =0;i<itsSize;i++)
			pType[i] = rhs[i];
		return *this;
	}

	template <class T>
		bool DStack<T>::isEmpty()
	{ 
		return (pType == 0) || (itsSize <= 0);
	}

  template <class T> bool DStack<T>::empty(){return isEmpty();}

	template <class T>
		T& DStack<T>::peek()
	{
		if(isEmpty())
			throw DStack::EMPTY_STACK;
		return pType[itsSize-1];
	}

	template <class T>
		void DStack<T>::push(const T& t)
	{
		if(pType == 0)
		{
			pType = new T[1];
			pType[0] = t;
			itsSize = 1;
			return;
		}
		T * temp = new T[itsSize + 1];
		for(ushort i = 0;i<itsSize;i++)
			temp[i] = pType[i];
		temp[itsSize++] = t;
		delete [] pType;
		pType = new T[itsSize];
		for(ushort i = 0;i<itsSize;i++)
			pType[i] = temp[i];
		delete [] temp;
		temp = 0;
	}

  template <class T> T& DStack<T>::pop()
	{
		if(isEmpty())
		  throw DStack::EMPTY_STACK;
		return pType[--itsSize];
	}

  template <class T> DStack<T> DStack<T>::operator+(const DStack<T>& rhs) const
  {
    DStack<T> returnMe;
    
    for(int i = rhs.itsSize - 1;i >= 0;i++)
      returnMe.push(rhs[i]);
    
    for(int i = itsSize - 1;i >= 0;i++)
      returnMe.push(pType[i]);
 
    return returnMe;

  }

  template <class T> DStack<T> DStack<T>::operator+=(const DStack<T>& rhs)
  {

    DStack<T> returnMe;

    for(int i = rhs.itsSize - 1;i >= 0;i++)
      returnMe.push(rhs[i]);
    
    for(int i = itsSize - 1;i >= 0;i++)
      returnMe.push(pType[i]);    

    *this = returnMe;

    return returnMe;
    
  }


  template <class T> DStack<T> parseDString(const DString& rhs)
  {
    return DStack<T>(T(rhs));
  }

}

#include "Double.h"
template class utils::DStack<Double>;

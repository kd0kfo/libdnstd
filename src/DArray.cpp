#include "DArray.h"

namespace utils{
	template <class T> DArray<T>::DArray(ushort len)
	{
		itsArray = new T[len];
		itsSize = len;

	}

	template <class T> DArray<T>::DArray()
	{
		itsSize = 0;
		itsArray = new T[0];
	}

	template <class T> DArray<T>::DArray(ushort size, const T * beans)
	{
		itsSize = size;
		itsArray = new T[itsSize];
		for(ushort i = 0;i<itsSize;i++)
			itsArray[i] = beans[i];
	}

  template <class T> DArray<T>::DArray(std::vector<T> vec)
  {
    itsSize = vec.size();
    itsArray = new T[itsSize];
    for(int i = 0;i<itsSize;i++)
      itsArray[i] = vec[i];
  }
	
	template <class T> DArray<T>::DArray(const DArray& arr)
	{
		itsSize = arr.itsSize;
		itsArray = new T[itsSize];
		for(int i = 0;i<itsSize;i++)
			itsArray[i] = arr.itsArray[i];
	}

	template <class T> DArray<T>::~DArray()
	{
		if(itsArray != 0)
		{
			delete [] itsArray;
			itsArray = 0;
		}

		itsSize = 0;

	}

	template <class T> 
		T & DArray<T>::operator[](unsigned short offset)
	{
		if(offset > itsSize)
			throw DavidException("Array out of bounds error",DavidException::DARRAY_ERROR_CODE);
		else
			return itsArray[offset];
	}

  template <class T> T DArray<T>::get(unsigned short offset) const
  {
    if(offset > itsSize)
      throw DavidException("Array out of bounds error",DavidException::DARRAY_ERROR_CODE);
    else
      return itsArray[offset];
  }

	template <class T> 
		T & DArray<T>::get(unsigned short offset)
	{
	  if(offset > itsSize)
	    throw DavidException("Array out of bounds error",DavidException::DARRAY_ERROR_CODE);
	  else
	    return itsArray[offset];
	}
  
	template <class T> 
		T DArray<T>::operator[](unsigned short offset) const
	{
		if(offset > itsSize)
			throw DavidException("Array out of bounds error",DavidException::DARRAY_ERROR_CODE);
		else
			return itsArray[offset];
	}
			

	template <class T> 
		DArray<T> DArray<T>::operator+(const DArray& arrayTwo) const
	{
		ushort newSize = itsSize + arrayTwo.size();
		DArray<T> newArray(newSize);
		int i = 0;
		for(i = 0;i<itsSize;i++)
			newArray[i] = itsArray[i];
		for(int j = 0;j<arrayTwo.size();j++,i++)
			newArray[i] = arrayTwo[j];
		return newArray;
	}

	template <class T> 
		void DArray<T>::operator+=(const DArray& arrayTwo)
	{
		ushort newSize = itsSize + arrayTwo.size();
		DArray<T> newArray(newSize);
		int i = 0;
		for(i = 0;i<itsSize;i++)
			newArray[i] = itsArray[i];
		for(int j = 0;j<arrayTwo.size();j++,i++)
			newArray[i] = arrayTwo[j];
		*this = newArray;
	}
		

	template <class T> 
		DArray<T>& DArray<T>::operator=(const DArray & arrayTwo)
	{
		if(this == &arrayTwo)
			return *this;
		delete [] itsArray;
		itsSize = arrayTwo.size();
		itsArray = new T[itsSize];
		for(int i = 0;i<itsSize;i++)
			itsArray[i] = arrayTwo[i];
		return *this;
	}


	template <class T> 
	bool DArray<T>::operator==(const DArray& arrayTwo) const
	{
		return (itsArray == arrayTwo.getArray());
	}

	template <class T> 
		void DArray<T>::put(const T& bean)
	{
		ushort newSize = itsSize + 1;
		T * newArray = new T[newSize];
		ushort i = 0;
		for(i = 0;i<itsSize;i++)
			newArray[i] = itsArray[i];
		newArray[newSize-1] = bean;
		delete [] itsArray;
		itsArray = new T[newSize];
		for(i=0;i<newSize;i++)
			itsArray[i] = newArray[i];
		delete [] newArray;
		newArray = 0;
		itsSize = newSize;
		
	}

  template <class T>
  bool DArray<T>::contains(const T& t) const
  {
    for(int i = 0;i<this->size();i++)
      {
	if(itsArray[i] == t)
	  {
	    return true;
	  }
      }
    return false;
  }

  template <class T>
  T *  DArray<T>::getArray() const
  {
    T * returnArray = new T[this->size()];
    for(int i = 0;i<this->size();i++)
      returnArray[i] = itsArray[i];
    
    return returnArray;
  }
}			


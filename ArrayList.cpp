#include "ArrayList.h"

namespace utils{

	template <class T>ArrayList<T>::ArrayList(ushort len)
	{
		itsArray = new DArray<T>(len);
		itsSize = len;

	}

	template <class T>ArrayList<T>::ArrayList()
	{
		itsSize = 0;
		itsArray = new DArray<T>;
	}

	template <class T>ArrayList<T>::ArrayList(const T * beans)
	{
		itsSize = sizeof(beans);
		itsArray = new DArray<T>;
		for(ushort i = 0;i<itsSize;i++)
			itsArray->put(beans[i]);
	}

	template <class T> ArrayList<T>::ArrayList(const ArrayList<T>& newArr)
	{
		this->itsSize = newArr.itsSize;
		itsArray = new DArray<T>;
		for(int i = 0;i<itsSize;i++)
			itsArray->put(newArr.get(i));
	}


	template <class T>ArrayList<T>::~ArrayList()
	{
		if(itsArray != 0)
		{
			delete itsArray;
			itsArray = 0;
		}
		itsSize = 0;

	}

	template <class T> 
		T & ArrayList<T>::operator[](unsigned short offset)
	{
		if(offset > itsSize)
			throw DavidException("Array out of bounds error",DavidException::DARRAY_ERROR_CODE);
		else
			return itsArray[offset];
	}

	template <class T>
		T & ArrayList<T>::get(unsigned short offset) const
	{
		if(offset > itsSize)
			throw DavidException("Array out of bounds error",DavidException::ARRAYLIST_ERROR_CODE);
		else
			return itsArray->get(offset);
	}
	
	template <class T>
		T ArrayList<T>::operator[](unsigned short offset) const
	{
		if(offset > itsSize)
			throw DavidException("Array out of bounds error",DavidException::DARRAY_ERROR_CODE);
		else
			return itsArray->get(offset);
	}
			

	template <class T> 
		ArrayList<T> ArrayList<T>::operator+(const ArrayList& arrayTwo)	
	{
		ushort newSize = itsSize + arrayTwo.size();
		ArrayList<T> newArray;
		int i = 0;
		for(i = 0;i<itsSize;i++)
			newArray.put(this->get(i));
		for(int j = 0;j<arrayTwo.size();j++,i++)
			newArray.put(arrayTwo.get(j));
		return newArray;
	}

	template <class T>
		void ArrayList<T>::operator+=(const ArrayList& arrayTwo)
	{
		ushort newSize = itsSize + arrayTwo.size();
		ArrayList<T> newArray(newSize);
		int i = 0;
		for(i = 0;i<itsSize;i++)
			newArray[i] = itsArray[i];
		for(int j = 0;j<arrayTwo.size();j++,i++)
			newArray[i] = arrayTwo[j];
		*this = newArray;
	}
		

	template <class T>
		ArrayList<T> & ArrayList<T>::operator=(const ArrayList<T> & arrayTwo)
	{
		if(this == &arrayTwo)
			return *this;
		delete itsArray;
		itsSize = arrayTwo.size();
		itsArray = new DArray<T>;
		for(int i = 0;i<itsSize;i++)
			itsArray->put(arrayTwo.get(i));
		return *this;
	}


	template <class T>
		int ArrayList<T>::operator==(const ArrayList& arrayTwo)
	{
		return (itsArray == arrayTwo.getArray());
	}

	template <class T>
		void ArrayList<T>::put( const T& bean)
	{
		ushort newSize = itsSize + 1;
		DArray<T> * newArray = new DArray<T>;
		ushort i = 0;
		for(i = 0;i<itsSize;i++)
			newArray->put(itsArray->get(i));
		newArray->put(bean);
		*itsArray = *newArray;
		itsSize = newSize;
	}

	template <class T> 
		DArray<T> * ArrayList<T>::joinArrays(T * a,T * b)
	{
		int aSize = sizeof(*a);
		int bSize = sizeof(*b);
		int newSize = aSize+bSize;
		DArray<T> * newArray = new DArray<T>;
		int i = 0;
		for(i;i<sizeof(a);i++)
			newArray->put(a[i]);
		for(i;i<newSize;i++)
			newArray->put(b[i-sizeof(a)]);
		return newArray;
	}

}



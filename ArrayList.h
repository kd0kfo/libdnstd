#ifndef ARRAYLIST_CPP
#define ARRAYLIST_CPP

#include "DArray.h"


namespace utils{

	template <class T>
	class ArrayList
	{

		public:
			ArrayList();
			ArrayList(const T *);
			ArrayList(const ArrayList&);

			~ArrayList();
			
			T & get(ushort i) const ;
			void put(const T&);
			void add(const T& t){put(t);}
			T & operator[](unsigned short offset);
			T operator[](unsigned short offset) const;
			ArrayList operator+(const ArrayList&);
			void operator+=(const ArrayList&);
			ArrayList & operator=(const ArrayList<T>&);
			int operator==(const ArrayList&);
			
			unsigned short size() const { return itsSize; }
			unsigned short length() const{ return size();}
			DArray<T> getArray() const { return *itsArray; }
			static DArray<T> * joinArrays(T *,T *);
			
		private:

			unsigned short itsSize;
			DArray<T> * itsArray;
			
			ArrayList(ushort);
		
	};
}

#endif




#ifndef DARRAY_CPP
#define DARRAY_CPP

#include <vector>

#include "DavidException.h"

/**
 * Documentation coming soon (after upgrade)
 */
namespace utils{

	template <class T> 
	class DArray
	{

		public:
			DArray();
			DArray(ushort size, const T *);
			DArray(std::vector<T> vec);
			DArray(const DArray&);
			~DArray();
			
			T & get(ushort i);
			T get(ushort i) const;
			void put(const T&);
			T & operator[](unsigned short offset);
			T operator[](unsigned short offset) const;
			DArray operator+(const DArray&) const;
			void operator+=(const DArray&);
			DArray& operator=(const DArray&);
			bool operator==(const DArray&) const;
			bool operator!=(const DArray& rhs)const{return !(*this == rhs);}
		       
			
			unsigned short size() const { return itsSize; }
			unsigned short length() const{ return size();}
	                bool contains(const T&) const;
			
			/**
			 * Returns the array of object.
			 * Note: you don't get the actual array, just a copy.
			 */
	                T * getArray() const;
			
		private:

			unsigned short itsSize;
			T * itsArray;
			
			DArray(ushort);
		
	};

}


#endif

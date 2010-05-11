#ifndef BINARY_CPP
#define BINARY_CPP

#include "DString.h"
#include "Double.h"


namespace math{

class Binary
{
public:
	Binary();
	Binary(const Binary&);
	Binary(int);
	Binary(const DString&);
	~Binary();
	
	Binary operator =(const Binary& B);
	Binary operator +(const Binary& B);
	Binary operator -(const Binary& B);
	bool operator ==(const Binary& B);
	Binary operator ~();
	Binary operator ^(const Binary& B);
	Binary operator &(const Binary& B);
	Binary operator|(const Binary& B);
	Binary operator!(){return ~(*this);}

	Binary nand(const Binary& B);
	Binary nor(const Binary& B);

	static Binary toBinary(int);
	int getInt() const {return *i;}
	DString toDString() const;
	int mostSigBit(){return this->toDString().length();}
	int setBitSize(int newSize){int temp = bitSize; bitSize = newSize; return temp;}
	int getBitSize() const {return bitSize;}
	
private:
	int * i;
	DString * bString;
	int bitSize;

};
}

#endif

#include "Binary.h"

namespace math{


Binary::Binary()
{
	i = new int;
	*i = 0;
	bString = new DString("0");
	bitSize = 0;
}

Binary::~Binary()
{
	if(i != 0)
	{
		delete i;
		i = 0;
	}
	if(bString != 0)
	{
		delete bString;
		bString = 0;
	}
}

Binary::Binary(const Binary& B)
{
	i = new int;
	*i = B.getInt();
	bString = new DString;
	*bString = B.toDString();
	bitSize = B.getBitSize();
}

Binary::Binary(const DString& bean)
{
	i = new int;
	*i = 0;
	for(int j = 0;j<bean.length();j++)
	{
		if(bean[j] != '0' && bean[j] != '1')
			throw DavidException(DString(bean)+DString(" is an improperly formed Binary."),DavidException::FORMAT_ERROR_CODE);
		*i += (bean[j] == '1') ? (int)Double::exponent(2,bean.length()-1-j) : 0;
	}
	bString = new DString(bean);
	bitSize = bString->length();

}

Binary Binary::operator=(const Binary& B)
{
	if(i != 0)
	{
		delete i;
		i = 0;
	}
	if(bString != 0)
	{
		delete bString;
		bString = 0;
	}
	i = new int;
	bString = new DString;
	*i = B.getInt();
	*bString = B.toDString();
	bitSize = B.getBitSize();

	return *this;
}

Binary::Binary(int newI)
{
	i = new int;
	bString = new DString;
	*i = newI;
	bitSize = 0;
	*bString = toBinary(*i).toDString();
	bitSize = bString->length();
}

Binary Binary::toBinary(int i)
{
	Binary b;
	if(i == 0)
		return b;
	if(i < -1)
	  throw DavidException("Number must be a positive integer","Format Error", DavidException::FORMAT_ERROR_CODE);
	*(b.i) = i;
	*(b.bString) = "";
	while(i > 0)
	{
		int modI = i % 2;
		*(b.bString) = (modI) ? DString("1")+b.toDString() : DString("0")+b.toDString();
		i = i / 2;
	}
	b.setBitSize(b.bString->length());
	return b;
}

bool Binary::operator ==(const Binary& B)
{
	if(this == &B)
		return true;
	if(*i == *(B.i) && *bString == *(B.bString))
		return true;
	else
		throw "Invalid Binary number";
}

Binary Binary::operator +(const Binary& B)
{
	Binary sum(*i+B.getInt());
	if(B.getBitSize() > sum.bitSize)
		sum.setBitSize(B.getBitSize());
	return sum;
}


Binary Binary::operator -(const Binary& B)
{
	Binary diff(*i-*(B.i));
	if(B.getBitSize() > diff.bitSize)
		diff.setBitSize(B.getBitSize());
	return diff;
}

Binary Binary::operator ~()
{
	DString bean;
	for(int j = 0;j<bString->length();j++)
	{
		if(bString->charAt(j) == '1')
		{
			bean = DString("0")+bean;
		}
		else if(bString->charAt(j) == '0')
		{
			bean = DString("1")+bean;
		}
		else
		{
			throw "Invalid Binary Number";
		}
	}
	if(bitSize > bString->length())
	{
		for(int j = bString->length();j<bitSize;j++)
			bean = DString("1")+bean;
	}
	Binary b;
	for(int j = 0;j<bean.length();j++)
	{
		*(b.i) += (bean[j] == '1') ? (int) Double::exponent(2,j) : 0;
	}
	*(b.bString) = bean;
	b.setBitSize(this->bitSize);
 	return b;
}

Binary Binary::operator ^(const Binary& B)
{
	int tempInt = *i & B.getInt();
	Binary _xor(tempInt);
	if(B.getBitSize() > _xor.bitSize)
		_xor.setBitSize(B.getBitSize());
	return _xor;
}

Binary Binary::operator &(const Binary& B)
{
	Binary _and(*i & B.getInt());
	if(B.getBitSize() > _and.bitSize)
		_and.setBitSize(B.getBitSize());
	return _and;
}

Binary Binary::operator |(const Binary& B)
{
	Binary _or(*i | B.getInt());
	if(B.getBitSize() > _or.bitSize)
		_or.setBitSize(B.getBitSize());
	return _or;
}

Binary Binary::nand(const Binary& B)
{
	return ~(Binary(*this & B));
}

Binary Binary::nor(const Binary& B)
{
	return ~(Binary(!(*i & B.getInt())));
}
		
DString Binary::toDString() const
{
	if(bString->length() == bitSize)
		return *bString;
	DString bean = *bString;
	for(int j = bean.length();j<bitSize;j++)
		bean = DString("0")+bean;
	return bean;
}

}//end of namespace decl.
	

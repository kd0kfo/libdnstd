/**
 * 
 * This file is part of libdnstd, a C++ utility library
 * This may be downloaded at http://libdnstd.davecoss.com
 * 
 * Copyright 2007, 2010 David Coss, PhD
 *
 * libdnstd is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * libdnstd is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with libdnstd.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "Binary.h"
#include "Double.h"

namespace math{


  Binary::Binary()
  {
    i = 0;
    bString = "0";
    bitSize = 0;
  }

  Binary::Binary(const Binary& B)
  {
    i = B.i;
    bString = B.bString;
    bitSize = B.bitSize;
  }

  Binary::Binary(const std::string& bean)
  {
    i = 0;
    for(int j = 0,size=bean.size();j<size;j++)
      {
	if(bean[j] != '0' && bean[j] != '1')
	  throw DavidException(bean+" is an improperly formed Binary.",DavidException::FORMAT_ERROR_CODE);
	i += (bean[j] == '1') ? (Binary::value_type)Double::exponent(2,bean.length()-1-j) : 0;
      }
    bString = bean;
    bitSize = bString.size();
  }

  Binary Binary::operator=(const Binary& B)
  {
    i = B.i;
    bString = B.bString;
    bitSize = B.bitSize;
    return *this;
  }

  Binary::Binary(Binary::value_type newI)
  {
    i = newI;
    bString = toBinary(i).str();
    bitSize = bString.size();
  }

  Binary Binary::toBinary(Binary::value_type i)
  {
    Binary b;
    if(i == 0)
      return b;
    b.i = i;
    b.bString = "";
    while(i > 0)
      {
	int modI = i % 2;
	b.bString = (modI) ? "1"+b.str() :"0"+b.str();
	i >>= 1;
      }
    b.setBitSize(b.bString.size());
    return b;
  }

  bool Binary::operator ==(const Binary& B)
  {
    if(this == &B)
      return true;
    return i == B.i;
  }

  Binary Binary::operator +(const Binary& B)
  {
    Binary sum(i+B.getInt());
    if(B.getBitSize() > sum.bitSize)
      sum.setBitSize(B.getBitSize());
    return sum;
  }


  Binary Binary::operator -(const Binary& B)
  {
    Binary diff(i-B.i);
    if(B.getBitSize() > diff.bitSize)
      diff.setBitSize(B.getBitSize());
    return diff;
  }

  Binary Binary::operator ~()
  {
    std::string bean;
    size_t size = bString.size();
    for(size_t j = 0;j<size;j++)
      {
	if(bString[j] == '1')
	  bean = "0"+bean;
	else if(bString[j] == '0')
	  bean = "1"+bean;
	else
	  throw "Invalid Binary Number";
      }
    if(bitSize > size)
      {
	for(size_t j = size;j<bitSize;j++)
	  bean = "1"+bean;
      }
    Binary b;
    for(int j = 0,size= bean.size();j<size;j++)
      {
	b.i += (bean[j] == '1') ? (Binary::value_type) Double::exponent(2,j) : 0;
      }
    b.bString = bean;
    b.bitSize = this->bitSize;
    return b;
  }

  Binary Binary::operator ^(const Binary& B)
  {
    Binary::value_type tempInt = i & B.i;
    Binary _xor(tempInt);
    if(B.bitSize > _xor.bitSize)
      _xor.bitSize = B.getBitSize();
    return _xor;
  }

  Binary Binary::operator &(const Binary& B)
  {
    Binary _and(i & B.getInt());
    if(B.getBitSize() > _and.bitSize)
      _and.setBitSize(B.getBitSize());
    return _and;
  }

  Binary Binary::operator |(const Binary& B)
  {
    Binary _or(i | B.getInt());
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
    return ~(Binary(!(i & B.i)));
  }
		
  std::string Binary::str() const
  {
    if(bString.size() == bitSize)
      return bString;
    std::string bean = bString;
    for(size_t j = bean.size();j<bitSize;j++)
      bean = "0"+bean;
    return bean;
  }

}//end of namespace math
	

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
#include "StringTokenizer.h"

utils::StringTokenizer::StringTokenizer(const std::string& string)
{
  StringTokenizer temp(string," ",false);
  *this = temp;
}

utils::StringTokenizer::StringTokenizer(const std::string& newString, const char * newDelim)
{
  StringTokenizer temp(newString,newDelim,false);
  *this = temp;
}

utils::StringTokenizer::StringTokenizer(const std::string& newString, const char * newDelim, bool keepDelim)
{
		
  delim = newDelim;
  string = newString;
  this->keepDelim = keepDelim;
  index =  0;
}

utils::StringTokenizer::StringTokenizer(const StringTokenizer& rhs)
{
  delim = rhs.getDelim();
  index = rhs.index;
  keepDelim = rhs.keepDelim;
  string = rhs.string;
}

utils::StringTokenizer utils::StringTokenizer::operator=(const StringTokenizer& rhs)
{
  if(this == &rhs)
    return *this;
  delim = rhs.getDelim();
  index = rhs.index;
  keepDelim = rhs.keepDelim;
  string = rhs.string;
  return *this;
}

std::string utils::StringTokenizer::nextToken(bool keepD)
{
  if(index >= this->string.size())
    throw DavidException("No more tokens in string tokenizer",DavidException::STRING_TOKENIZER_ERROR_CODE);

  size_t nextDelim = this->string.find_first_of(delim,index);
  std::string returnMe;
  if(nextDelim == std::string::npos )
    {
      returnMe = this->string.substr(index);
      index = this->string.size();
      return returnMe;
    }

  if(nextDelim == index)
    {
      if(keepD)
	{
	  return this->string.substr(index++,1);
	}
      else
	{
	  index++;
	  if(index == this->string.size())
	    return "";
	  return nextToken(keepD);
	}
    }
          
  returnMe = this->string.substr(index,nextDelim-index);
  index = nextDelim;
  return returnMe;
}
	
bool utils::StringTokenizer::hasMoreTokens()
{
  return index < this->string.size();
}

std::string utils::StringTokenizer::peek()
{
  std::string bean = nextToken(this->keepDelim);
  index -= bean.size();
  
  return bean;
}





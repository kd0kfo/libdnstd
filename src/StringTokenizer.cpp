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





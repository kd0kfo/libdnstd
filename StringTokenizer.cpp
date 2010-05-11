#include "StringTokenizer.h"

utils::StringTokenizer::~StringTokenizer()
	{
		delete delim;
		delim = 0;
		delete string;
		string = 0;
		delete tokens;
		tokens = 0;
	}

utils::StringTokenizer::StringTokenizer(const DString& string)
	{
		StringTokenizer * temp = new StringTokenizer(string," ",false);
		*this = *temp;
		delete temp;
		temp = 0;
	}

utils::StringTokenizer::StringTokenizer(const DString& newString, const char * newDelim)
	{
		StringTokenizer temp(newString,newDelim,false);
		*this = temp;
	}

utils::StringTokenizer::StringTokenizer(const DString& newString, const char * newDelim, bool keepDelim)
	{
		
		string = new DString("");
		delim = new DString("");
		*delim = DString(newDelim);
		*string = newString;
		this->keepDelim = keepDelim;
		tokens = new DArray<DString>();
		DString * tempString = 0;
		for(ushort i=0;i<string->length();i++)
		{
			if(delim->contains(newString[i]))
			{
				if(tempString != 0)
					tokens->put(*tempString);
				delete tempString;
				tempString = 0;
				if(keepDelim)
				{
					DString tempBean((char) newString[i]);
					tokens->put(tempBean);
				}

			}
			else
			{
				if(tempString == 0)
					tempString = new DString("");
				*tempString += newString.charAt(i);
			}
		}
		if(tempString != 0)
			tokens->put(*tempString);
		index = 0;
		delete tempString;
		tempString = 0;
	}

utils::StringTokenizer::StringTokenizer(const StringTokenizer& rhs)
	{
		this->delim = new DString();
		*delim = rhs.getDelim();
		this->index = rhs.index;
		this->keepDelim = rhs.keepDelim;
		this->string = new DString(*(rhs.string));
		this->tokens = new DArray<DString>;
		*tokens = *(rhs.tokens);
	}

utils::StringTokenizer utils::StringTokenizer::operator=(const StringTokenizer& rhs)
	{
		if(this == &rhs)
			return *this;
		this->delim = new DString();
		*delim = rhs.getDelim();
		this->index = rhs.index;
		this->keepDelim = rhs.keepDelim;
		this->string = new DString(*(rhs.string));
		this->tokens = new DArray<DString>;
		*tokens = *(rhs.tokens);
		return *this;
	}

DString utils::StringTokenizer::nextToken(bool keepD)
	{
		if(index >= tokens->length())
		{
			throw DavidException("Number of Tokens exceded",DavidException::STRING_TOKENIZER_ERROR_CODE);
		}
		if(keepD)
		{
			return tokens->get(index++);
		}
		else
		{
			if(delim->contains(tokens->get(index+1).charAt(0)))
			{
				index++;
				return nextToken(keepD);
			}
			return tokens->get(index++);
		}

	}
	
bool utils::StringTokenizer::hasMoreTokens()
	{
		bool bln = index < tokens->length();
		return bln;
	}

DString utils::StringTokenizer::peek()
	{
		DString bean = nextToken(this->keepDelim);
		this->index -= 1;
		return bean;
	}





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
#ifndef STRINGTOKENIZER_CPP
#define STRINGTOKENIZER_CPP

#include <string>

#include "DavidException.h"

namespace utils{

  /**
   * String Tokenizer
   * Copyright David Coss 2010
   * Copying and distributing are permitted under the terms of the GNU Public License version 3(see COPYING or http://www.gnu.org/licenses/gpl.txt).
   */
  class StringTokenizer
  {
  public:
    /**
     * Constructor which will take a string and tokenize it with 
     * one space character, " ", as the delimiter, which will not 
     * be included as a token.
     *
     * @param std::string string to tokenize
     */
    StringTokenizer(const std::string& string);

    /**
     * Constructor with given string to tokenize, based on the 
     * given delimiter. The delimiter will or will not be included
     * as a token based on the provided boolean flag.
     *
     * @param std::string string to tokenize
     * @param char* character to use as a delimiter
     * @param bool flag to indicate including the delimiter
     */
    StringTokenizer(const std::string& string, const char * delimiter, bool keepDelim);

    /**
     * Main Constructor, where delimiter is not included.
     *
     * @param std::string string to tokenize
     * @param char* character to use as a delimiter
     * @see StringTokenizer(const std::string& string, const char * delimiter, bool keepDelim)
     */
    StringTokenizer(const std::string& string, const char * delimiter);

    /**
     * Copy Constructor
     */
    StringTokenizer(const StringTokenizer&);

    /**
     * Destructor. The internal tokenized string and array of 
     * tokens are cleared from memory.
     */
    virtual ~StringTokenizer(){}

    /**
     * Returns the current index, zero index.
     *
     * @return int
     */
    const int getIndex() const{ return index;}
    
    StringTokenizer operator=(const StringTokenizer& rhs);			

    /**
     * Returns the next token as a std::string. Exception is
     * thrown if there is no next token.
     *
     * @return std::string next token
     * @throws DavidException
     */
    std::string nextToken(){return nextToken(keepDelim);}

    /**
     * Returns the next token, with an option to include
     * the delimiter. Exception is thrown if there is no
     * next token.
     *
     * @param bool keep the delimiter
     * @return std::string next token
     * @throws DavidException
     */
    std::string nextToken(bool keepDelim);

    /**
     * Gives the next token without advancing the next
     * token index. Exception is thrown if there is no
     * next token.
     *
     * @return std::string
     * @throws DavidException
     */
    std::string peek();

    /**
     * Indicates whether or not there are more tokens.
     *
     * @return bool
     */
    bool hasMoreTokens();

    /**
     * Returns the delimiter used by the string tokenizer
     *
     * @return std::string
     */
    std::string getDelim() const{return delim;}

  private:
    std::string delim;
    std::string string;
    bool keepDelim;
    size_t index;

  };
}


#endif


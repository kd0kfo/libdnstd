#ifndef STRINGTOKENIZER_CPP
#define STRINGTOKENIZER_CPP

#include "DArray.cpp"
template class utils::DArray<DString>;

namespace utils{

  /**
   * String Tokenizer
   * Copyright 2010 David Coss
   */
  class StringTokenizer
  {
  public:
    /**
     * Constructor which will take a string and tokenize it with 
     * one space character, " ", as the delimiter, which will not 
     * be included as a token.
     *
     * @param DString string to tokenize
     */
    StringTokenizer(const DString&);

    /**
     * Constructor with given string to tokenize, based on the 
     * given delimiter. The delimiter will or will not be included
     * as a token based on the provided boolean flag.
     *
     * @param DString string to tokenize
     * @param char* character to use as a delimiter
     * @param bool flag to indicate including the delimiter
     */
    StringTokenizer(const DString& string, const char * delimiter, bool keepDelim);

    /**
     * Main Constructor, where delimiter is not included.
     *
     * @param DString string to tokenize
     * @param char* character to use as a delimiter
     * @see StringTokenizer(const DString& string, const char * delimiter, bool keepDelim)
     */
    StringTokenizer(const DString& string, const char * delimiter);

    /**
     * Copy Constructor
     */
    StringTokenizer(const StringTokenizer&);

    /**
     * Destructor. The internal tokenized string and array of 
     * tokens are cleared from memory.
     */
    ~StringTokenizer();

    /**
     * Returns the current index, zero index.
     *
     * @return int
     */
    const int getIndex() const{ return index;}
    
    StringTokenizer operator=(const StringTokenizer& rhs);			

    /**
     * Returns the next token as a DString. Exception is
     * thrown if there is no next token.
     *
     * @return DString next token
     * @throws DavidException
     */
    DString nextToken(){return nextToken(true);}

    /**
     * Returns the next token, with an option to include
     * the delimiter. Exception is thrown if there is no
     * next token.
     *
     * @param bool keep the delimiter
     * @return DString next token
     * @throws DavidException
     */
    DString nextToken(bool keepDelim);

    /**
     * Gives the next token without advancing the next
     * token index. Exception is thrown if there is no
     * next token.
     *
     * @return DString
     * @throws DavidException
     */
    DString peek();

    /**
     * Indicates whether or not there are more tokens.
     *
     * @return bool
     */
    bool hasMoreTokens();

    /**
     * Returns the delimiter used by the string tokenizer
     *
     * @return DString
     */
    DString getDelim() const{return *delim;}

  private:
    DString * delim;
    DString * string;
    DArray<DString> * tokens;
    bool keepDelim;
    ushort index;

  };
}


#endif


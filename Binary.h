#ifndef BINARY_CPP
#define BINARY_CPP

#include "DString.h"
#include "Double.h"


namespace math{

  /**
   * Binary Number Object
   * Copyright David Coss 2010
   * Copying and distributing are permitted under the terms of the GNU Public License version 3 (see COPYING or http://www.gnu.org/licenses/gpl.txt).
   */
  class Binary
  {
  public:
  
    /**
     * Default Constructor.
     * Value equals zero.
     */ 
    Binary();

    /**
     * Copy constructory
     */
    Binary(const Binary&);

    /**
     * Creates binary number based on a positive integer.
     * This cannot handle negative numbers, for which a DavidException is thrown.
     */
    Binary(int);
    
    /**
     * Creates a binary number from a DString. 
     * If the string contains any character other than
     * a "1" or "0", a DavidException is thrown.
     */
    Binary(const DString&);

    ~Binary();
	
    Binary operator =(const Binary& B);
    Binary operator +(const Binary& B);
    Binary operator -(const Binary& B);
    bool operator ==(const Binary& B);

    /**
     * Returns the complement of the binary number.
     */
    Binary operator ~();

    /**
     * Returns the "exclusive or" of the the binary number.
     */
    Binary operator ^(const Binary& B);

    /**
     * Returns the "and" of the binary number.
     */
    Binary operator &(const Binary& B);
    
    /**
     * Returns the "or" of the binary number.
     */
    Binary operator|(const Binary& B);

    /**
     * Returns the compliment using operator~()
     */
    Binary operator!(){return ~(*this);}
    
    /**
     * Performs a "Not And" with the provided binary number
     */
    Binary nand(const Binary& B);

    /**
     * Performs a "Not Or" with the provided binary number
     */
    Binary nor(const Binary& B);

    static Binary toBinary(int);
    
    /**
     * Gives the *positive) integer value of the binary number.
     */
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

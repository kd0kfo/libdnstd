#ifndef BINARY_CPP
#define BINARY_CPP

#include "Double.h"

namespace math{

  /**
   * Binary Number Object
   * Copyright David Coss 2010
   * Copying and distributing are permitted under the terms of the GNU Public License version 3 (see COPYING or http://www.gnu.org/licenses/gpl.txt).
   */
  class Binary
  {
  private:
    typedef unsigned int value_type;
    value_type i;
    size_t bitSize;
    std::string bString;
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
    Binary(value_type);
    
    /**
     * Creates a binary number from a DString. 
     * If the string contains any character other than
     * a "1" or "0", a DavidException is thrown.
     */
    Binary(const std::string&);

    virtual ~Binary();
	
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

    static Binary toBinary(value_type);
    
    /**
     * Gives the integer value of the binary number.
     */
    const value_type& getInt() const {return i;}

    std::string str() const;
    value_type mostSigBit(){return (value_type)ceil(log(this->i)/log(2.0));}
    void setBitSize(value_type newSize){bitSize = newSize;}
    size_t getBitSize() const {return bitSize;}
	
  };
}

#endif

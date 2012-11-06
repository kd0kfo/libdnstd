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
#ifndef COMPLEX_CPP
#define COMPLEX_CPP

#include <string>
#include "Double.h"

namespace math
{

  /**
   * Complex Number Object
   * Copyright David Coss 2010
   * Copying and distributing are permitted under the terms of the GNU Public License version 3 (see COPYING or http://www.gnu.org/licenses/gpl.txt).
   */
  class Complex
  {

  public:
    /**
     * Main Constructor.
     * Creates a Complex Number(doubles).
     * @param Real Real Part
     * @param Imaginary Imaginary Part
     */
    Complex(const double Real, const double Imaginary);

    /**
     * Destructor.
     */	
    virtual ~Complex(){}
	
    /**
     * Default Constructor.
     * Creates a Complex Object equal to 0.0+0.0*i
     */
    Complex();

    /**
     * Turns a double into a complex number
     * Real part is Double's 0th component
     * Imaginary part is Double's 1st component
     */
    Complex(const Double& rhs);

    /**
     * Copy Constructor.
     * Copies another Complex
     * @param rhs Constant Complex Reference
     */
    Complex(const Complex & rhs);

    /**
     * Turns a double into a Complex number with 
     * Imaginary part equal to zero
     */
    Complex(const double& d);

    /**
     * Produces a DString from the Complex number.
     * @return Complex number as a DString
     */
    std::string str() const;

    std::string str(std::ostringstream&) const;

    Complex & operator=(const Complex&);
    Complex & operator=(const Double&);
    bool operator==(const Complex&) const;
    bool operator==(const Double&) const;
    bool operator==(const double&) const;
    Complex operator+(const Complex&)const;
    void operator+=(const Complex&);
    Complex operator-(const Complex&)const;
    void operator-=(const Complex&);
    Complex operator*(const Complex&)const;///<Performs the Complex Modulus Squared
    void operator*=(const Complex&);

    double getRealPart() const{return Re;}
    double real()const{return Re;}
    double getImaginaryPart() const{return Im;}
    double imag()const{return Im;}

    /**
     * Gives the Complex Conjugate.
     * Gives the Complex Conjugate of the Object.
     * @return A Complex Conjugate of the original Complex Object.
     */
    Complex getConjugate() const;

    /**
     * Parses a DString.
     * Takes a DString and turns it into a Complex Number
     * @param bean A DString Number.
     * @return A Complex Number.
     * @throws DavidException If the string is not a number, an exception is thrown
     */
    static Complex parseString(const std::string & bean);
    friend std::ostream& operator<<(std::ostream&, const Complex&);
    bool operator>(const Complex&) const;
    bool operator<(const Complex&) const;

    /**
     * Casting Overload
     * Casts the complex as a Double with 0th value equal to the real part and the 1st value equal to the imaginary part
     *
     * @return Double
     */
    operator Double() const {return Double(Re,Im,0.0);}
	
    /**
     * Provides a function to obtain a double
     */
    Double toDouble() const;


    /**
     * Returns the Modulus of the complex number.
     * @returns modulus of the complex number.
     */
    double modulus() const;
	
    /**
     * Returns the phase angle of the complex number
     * based on atan2(Imaginary,Real);
     */
    double phaseAngle() const;

    /**
     * Returns the Value of the complex number.
     * Note the parameter is redundant. It's used to uniformity with other objects.
     * @returns Complex number
     */
    Complex getValue(int i){return *this;}
	
    /**
     * Sets the value of the object to the new value.
     * Like getValue the int index value is redunant.
     * @param value new Complex Value
     */
    void setValue(int i, Complex value);
    
    /**
     * Sets the value of the object to the new value.
     * Unlike the (int, Complex) form of this function,
     * the index is used. Here, the index denotes Real Part
     * of index = 0 and Imaginary part if index = 1.
     * 
     * @param value new Complex Value
     */
    void setValue(int i, double value);

  private:
    double Re;
    double Im;

  };


}
double abs(const math::Complex& c);
double arg(const math::Complex& c);



#endif


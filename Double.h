#ifndef DOUBLE_CPP
#define DOUBLE_CPP

#include <sstream>
#include <iostream>
#include <math.h>

#ifndef atof
#include <cstdlib>
#endif

#include "DavidException.h"

#ifdef __DEBUG__
#define DEBUG_PRINT(x) std::cout << x << std::endl; 
#else 
#define DEBUG_PRINT
#endif


/**
 * My own Double class wrapper.
 * 
 * Contains 3 doubles, as needed by various cosmological applications.
 * This class is capable of parsing a string (and/or DString).
 * Copyright 2010 David Coss
 */
class Double
	{
		public:
			/**
			 * Main constructor.
			 * By default the double values are zero.
			 */
			Double(){mydoubleValue = mydoubleValue2 = mydoubleValue3 = 0;}

			/**
			 * Creates a Double from a const char* string.
			 * Note: if the string is not a valid real number, a DavidException is thrown.
			 * @param _string String given
			 * @see Double(const DString& newString)
			 * @throws DavidException.
			 */
			Double(const char * _string);

			/**
			 * Creates a Double from a DString.
			 * Note: if the string is not a valid real number, a DavidException is thrown.
			 * @param newString String given
			 * @see Double(const char * _string)
			 * @throws DavidException.
			 */
			Double(const DString& newString);

			/**
			 * Main constructor.
			 * Creates a Double wrapper for the supplied double.
			 * @param newDouble.
			 */
			Double(const double newDouble);

			/**
			 * Triplet Double Constructor.
			 * This constructor creates a Double wrapper that can hold three doubles.
			 * This is not used often, but it makes Double compatable with Triplet templates.
			 * @see Triplet
			 */
			Double(const double, const double, const double);

			/**
			 * Int to Double constructor.
			 * This constructor casts the provided int as a double and stores it.
			 * @param i int given to become a Double.
			 */
			Double(const int i){mydoubleValue = (double) i;mydoubleValue2 = 0; mydoubleValue3 = 0;}

			/**
			 * Copy Constructor
			 */
			Double(const Double&);

			/**
			 * Adds Double components. Each element is treated as linearly independent.
			 */
			Double operator+(const Double&);
			
			/**
			 * The provided double is added to the first element in the Double class
			 */
			Double operator+(const double&);
			
			/**
			 * @see operator+(const Double&)
			 */
			void operator+=(const Double&);
			void operator+=(const double);
			
			/**
			 * Subtracts the Double classes
			 * @see operator+(const Double&)
			 */
			Double operator-(const Double&);

			/**
			 * Subtracts the provided double from the first double element
			 */
			Double operator-(const double&);
			void operator-=(const Double&);
			void operator-=(const double);
			bool operator!=(const Double& rhs) const {return mydoubleValue != rhs.doubleValue() || mydoubleValue2 != rhs.getValue(1) || mydoubleValue3 !=  rhs.getValue(2);}
			bool operator!=(const double rhs) const { return mydoubleValue != rhs;}
			
			/**
			 * Multiplies Double elements as a vector inner (dot) product
			 */
			void operator*=(const Double&);
			void operator*=(const double);
			Double & operator=(const Double&);
			Double & operator=(const double&);
			bool operator==(const Double&) const;
			bool operator==(const double) const ;
			bool operator<=(const double f)const{return mydoubleValue <= f;}
			bool operator<=(const int f)const{return mydoubleValue <= f;}
			bool operator<=(const Double& f)const{return mydoubleValue <= f.doubleValue();}
			bool operator>=(const double f)const{return mydoubleValue >= f;}
			bool operator>=(const int f)const{return mydoubleValue >= f;}
			bool operator>=(const Double& f)const{return mydoubleValue >= f.doubleValue();}
			bool operator<(const Double& f) const{return (mydoubleValue < f.doubleValue());}
			bool operator<(const double f) const{return (mydoubleValue < f);}
			bool operator>(const Double& f) const{return (mydoubleValue > f.doubleValue());}
			bool operator>(const double f) const{return (mydoubleValue > f);}
			operator DString() const{return toDString();}

			/**
			 * Multiplication is performed where each of the 3 components are linearly independent and multiplication is done as an inner product.
			 * 
			 */
			Double operator*(const Double& f);
			
			/**
			 * @see Double operator*(const Double& f);
			 */
			Double operator*(const double f);

			/**
			 * @see Double operator*(const Double& f);
			 */
			Double operator/(const double f);
			
			friend std::ostream& operator<<( std::ostream&, const Double&);

			

			/**
			 * Gives the double value of the Double.
			 * @return double.
			 */
			double doubleValue() const { return mydoubleValue; }

			/**
			 * Gives the value of i to the provided power.
			 * @param i base.
			 * @param power
			 * @return double
			 */
			static double exponent(double i,int power);

			/**
			 * Determines if the string is a double
			 * @returns bool
			 * @see isDouble(DString&)
			 */
			static bool isDouble(const char *);
			
			/**
			 * Determines if the string is a double
			 * @returns bool
			 * @see isDouble(const char *)
			 */
			static bool isDouble(const DString&);

			/**
			 * Gives a DString representation of the Double (first value).
			 * @return DString.
			 */
			DString toDString() const;

			/**
			 * Like toDString(), but provides use of an optional, external stream
			 * for conversion. The string version of the Double is left in the stream.
			 */
			DString toDString(std::ostringstream& ss) const;

			/**
			 * Gives the ASCII value of the provided character.
			 * @param ch
			 * @return int
			 */
			static int getIntVal(char ch);

			/**
			 * Gives the sign of the provided double
			 * Note: sign(0) = 0;
			 *
			 * @param double d
			 * @return int +-1 or 0
			 */
			static int sign(const double d);
			static int sgn(const double d){return sign(d);}

			int sign()const{return sign(mydoubleValue);}
			int sgn()const{return sign();}

			/**
			 * Gives the integer part of the real value in the double.
			 * To be used in lieu of (int) casting.
			 *
			 */
			int intValue() const;

			/**
			 * Gives the n-th root of the provided base.
			 * @param base.
			 * @param n
			 * @return double.
			 */
			static double parseRoot(double base ,double n);

			/**
			 * Casts the double as an int
			 * @return int
			 */
			int toInt();

			/**
			 * DEPRECATED (too slow): Converts the provided Hexadecimal DString to a number.
			 * Note: If the string is not a valid hexadecimal number, a DavidException is thrown.
			 * @return int
			 * @see DavidException
			 * @see intToHex(const int)
			 */
			static int hexToInt(DString&);

			/**
			 * DEPRECATED(too slow): Converts an integer to a hexadecimal number.
			 * @return DString.
			 */
			static DString intToHex(const int);

			/**
			 * Changes the string to the provied base.
			 */
			static int stringToNBase(DString number, int base);
			
			/**
			 * DOES NOT WORK!!! REMOVE ME!!!
			 * Changes a number of a given base to a DString
			 */
			static DString& nBaseToString(int number);

			/**
			 * Parses a DString to a double
			 * Note: if the string is not a valid, real number, a DavidException is thrown.
			 * @param newString String to be converted to a Double.
			 * @return Double.
			 * @throws DavidException.
			 */
			static Double parseDString(const DString & newString);

			/**
			 * Gives the modulus(absolute value) of the Double.
			 * @return double.
			 */
			double modulus() const;

			/**
			 * Gives the inty-th value of the Double wrapper.
			 * Note: USUALLY the double only contains one value, so "0" would be used.
			 * However, if the double is used to hold 3 doubles, then use either 0, 1, or 2.
			 * An index greater than 2 or less than 0 will cause a DavidException to be thrown.
			 * @param inty zero index.
			 * @return double
			 * @see setValue(int inty, double value)
			 * @throws DavidException.
			 */
			double getValue(int inty) const;

			/**
			 * Sets the inty-th value of the Double wrapper.
			 * Note: USUALLY the double only contains one value, so "0" would be used.
			 * However, if the double is used to hold 3 doubles, then use either 0, 1, or 2.
			 * An index greater than 2 or less than 0 will cause a DavidException to be thrown.
			 * @param inty zero index.
			 * @param value new double value for the inty-th index.
			 * @return double
			 * @see getValue(int inty)
			 * @throws DavidException.
			 */
			void setValue(int inty, double value);

			/**
			 * Calculates the exponential function
			 */
			static double e(const double& x){return exp(x);}

		private:
			double mydoubleValue;
			double mydoubleValue2;
			double mydoubleValue3;
	};


/**
 * Constants
 */
const double D_PI = 4*atan(1.0);
const double D_E = exp(1.0);

/**
 * Functions
 */
static double max(const double& a, const double& b)
{
  if(a > b)
    return a;
  
  return b;
}

static double min(const double&a, const double& b)
{
  if(a < b)
    return a;
  
  return b;
}

#endif

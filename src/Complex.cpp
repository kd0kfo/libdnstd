#include "Complex.h"

namespace math{

Complex::Complex(const double Real, const double Imaginary)
{
	Re = Real;
	Im = Imaginary;
}

  Complex::Complex(const Complex & rhs)
  {
    Re = rhs.getRealPart();
    Im = rhs.getImaginaryPart();
  }

  Complex::Complex(const Double& rhs)
  {
    Re = rhs.getValue(0);
    Im = rhs.getValue(1);
  }

  Complex::Complex(const double& d)
  {
    Re = d;
    Im = 0;
  }

Complex::Complex()
{
	Re = 0;
	Im = 0;
}

std::string Complex::str() const
{
	std::ostringstream ss;
	return str(ss);
}

std::string Complex::str(std::ostringstream& stream) const
{
	//Add all stuff to stream and then extract a DString from the stream.

	if(Re == 0 && Im == 0)
		return "0";

	if(Re != 0)
		stream << Re;
	
	if(Re != 0 && Im != 0)
	{
		if(Im > 0)
			stream << "+";
	}
	
	if(Im != 0)
		stream << Im << "i";
	
	return stream.str();
	
}

Complex& Complex::operator=(const Complex& rhs)
{
	if(this == &rhs)
		return *this;
	Re = rhs.getRealPart();
	Im = rhs.getImaginaryPart();

	return *this;
}

  Complex & Complex::operator=(const Double& rhs)
  {

    Re = rhs.getValue(0);
    Im = rhs.getValue(1);
	return *this;
  }

  bool Complex::operator==(const Complex& rhs) const
  {
    if(this == &rhs)
      return true;

    return (Re == rhs.getRealPart()) && (Im == rhs.getImaginaryPart());
  }

  bool Complex::operator==(const Double& rhs) const
  {
    if(rhs.getValue(3) != 0.0)
      return false;
    
    return (Re == rhs.getValue(0)) && (Im == rhs.getValue(1));
  }

  bool Complex::operator==(const double& rhs) const
  {
    if(Im == 0)
      return false;

    return Re == rhs;
  }

Complex Complex::getConjugate() const
{

	return Complex(Re,-1*Im);

}


Complex Complex::parseString(const std::string & string)
{
  double Re, Im;
  Re = Im = 0;
  int middleOpLoc = -1;
  int iLoc = -1;
  for(int i = 0,size = string.size();i< size;i++)
    {
      if(string[i] == 'i' || string[i] == 'I')
	iLoc = i;
      if(string[i] == '+' || string[i] == '-')
	middleOpLoc = i;
      if(string[i] == 'e' || string[i] == 'E')
	i++;
    }

  if(iLoc == -1)
    {
      Re = Double(string).doubleValue();
      return Complex(Re,0.0);
    }

  if(middleOpLoc < 0)
    {
      Im = Double(string.substr(0,iLoc)).doubleValue();
      return Complex(0.0,Im);
    }

  if(string[0] == '-')
    Re = Double(string.substr(1,middleOpLoc-1)).doubleValue();
  else
    Re = Double(string.substr(0,middleOpLoc)).doubleValue();

  std::string imaginaryPart = string.substr(middleOpLoc+1,iLoc-middleOpLoc-1);
  if(imaginaryPart.size() == 0)
	  Im = 1;
  else
	Im = Double(imaginaryPart).doubleValue();

  if(string[0] == '-')
    Re *= -1;
  if(string[middleOpLoc] == '-')
    Im *= -1;

  return Complex(Re,Im);
  
}

 std::ostream& operator<<(std::ostream& theStream, const Complex& cNumber)
{

  theStream << cNumber.str();
	return theStream;

}

bool Complex::operator<(const Complex& rhs) const
{
  return modulus() < rhs.modulus();
}

bool Complex::operator>(const Complex& rhs) const
{
  return modulus() > rhs.modulus();
}

double Complex::modulus() const
{
  double modSquared = Re*Re+Im*Im;
  return sqrt(modSquared);
}

double Complex::phaseAngle() const
{
  return atan2(Im,Re);
}

void Complex::setValue(int i, Complex value)
{
  Re = value.getRealPart();
  Im = value.getImaginaryPart();
}


Complex Complex::operator+(const Complex& rhs)const
{
  return Complex(Re+rhs.getRealPart(),Im+rhs.getImaginaryPart());
}

void Complex::operator+=(const Complex& rhs)
{
  Re += rhs.getRealPart();
  Im += rhs.getImaginaryPart();
}
Complex Complex::operator-(const Complex& rhs)const
{
   return Complex(Re-rhs.getRealPart(),Im-rhs.getImaginaryPart());
}

void Complex::operator-=(const Complex& rhs)
{
   Re += rhs.getRealPart();
   Im += rhs.getImaginaryPart();
}

Complex Complex::operator*(const Complex& rhs)const
{
  
  double real = Re*rhs.getRealPart()-Im*rhs.getImaginaryPart();
  double imaginary = Re*rhs.getImaginaryPart() + Im*rhs.getRealPart();

  return Complex(real,imaginary);
}

void Complex::operator*=(const Complex& rhs)
{
  Re = Re * rhs.getRealPart() - Im * rhs.getImaginaryPart();
  Im = Re * rhs.getImaginaryPart() + Im * rhs.getRealPart();
}

Double Complex::toDouble() const
{
	Double temp(Re,Im,0.0);
	return temp;
}

}//end math

double abs(const math::Complex& c){return c.modulus();}
double arg(const math::Complex& c){return c.phaseAngle();}



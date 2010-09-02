#include "Double.h"

Double::Double(const char * bean)
{
  mydoubleValue2 = 0.0;
  mydoubleValue3 = 0.0;  
  try{
    mydoubleValue = atof(bean);
    if(mydoubleValue == 0 && strchr(bean,"0") != 0)
      throw DavidException(strcat(bean," is not a valid number."),DavidException::FORMAT_ERROR_CODE);
  }
  catch(...)
    {
      throw DavidException(strcat(bean," is not a valid number."),DavidException::FORMAT_ERROR_CODE);
    }
}

Double::Double(const Double& f)
{
  mydoubleValue = f.getValue(0);
  mydoubleValue2 = f.getValue(1);
  mydoubleValue3 = f.getValue(2);
}

Double::Double(const DString& _string)
{
  
  mydoubleValue2 = 0.0;
  mydoubleValue3 = 0.0;
  try{
    mydoubleValue = atof(_string.getString().c_str());
    if(mydoubleValue == 0 && !_string.contains('0'))
      throw DavidException(_string + " is not a valid number.",DavidException::FORMAT_ERROR_CODE);
  }
  catch(...)
    {
      throw DavidException(_string + " is not a valid number.",DavidException::FORMAT_ERROR_CODE);
    }

}

Double::Double(const double i)
{
  mydoubleValue = i;
  mydoubleValue2 = 0.0;
  mydoubleValue3 = 0.0;
}

Double::Double(const double i, const double i2, const double i3)
{
  	mydoubleValue = i;
	mydoubleValue2 = i2;
	mydoubleValue3 = i3;
}

bool Double::isDouble(const char * bean)
{
  DString str(bean);
  return isDouble(str);
}

bool Double::isDouble(const DString& bean)
{
  try
    {
      double d =  Double(bean).doubleValue();
      return d >= 0 || d <= 0;
    }
  catch(DavidException de)
    {
      if(de.getCode() == DavidException::FORMAT_ERROR_CODE)
	return false;
      else
	throw de;
    }
}
			
double Double::exponent(double i, int power)
{
  
  return pow(i,(double) power);
  if(power == 0)
    {
      return 1;
    }
  if(power > 0)
    {
      return i*exponent(i,power-1);
    }
  if(power < 0)
    return exponent(i,power+1)/i;
  throw DavidException("Number must be a positive integer","Format Error", DavidException::FORMAT_ERROR_CODE);
}


Double Double::operator+(const Double& j)
{
  Double returnMe;
  for(int i = 0;i<3;i++)
    returnMe.setValue(i,getValue(i)+j.getValue(i));
  return returnMe;
}

Double Double::operator+(const double& j)
{
  Double returnMe(getValue(0),getValue(1),getValue(2));
  returnMe.setValue(0,mydoubleValue + j);
  return returnMe;
}

	void Double::operator+=(const Double& j)
	{
		for(int i = 0;i<3;i++)
			setValue(i,getValue(i)+j.getValue(i));
	}

	void Double::operator+=(const double j)
	{
		setValue(0,mydoubleValue + j);
	}

Double Double::operator-(const Double& j)
{
  Double returnMe;
  for(int i = 0;i<3;i++)
    returnMe.setValue(i,getValue(i)-j.getValue(i));
  return returnMe;
}

Double Double::operator-(const double& j)
{
  Double returnMe(getValue(0),getValue(1),getValue(2));
  returnMe.setValue(0,mydoubleValue - j);
  return returnMe;
}

	void Double::operator-=(const Double& j)
	{
		for(int i = 0;i<3;i++)
			setValue(i,getValue(i)-j.getValue(i));
	}

	void Double::operator-=(const double j)
	{
		setValue(0,mydoubleValue - j);
	}


	Double & Double::operator=(const Double& j)
	{
		if(mydoubleValue == j.doubleValue() && mydoubleValue2 == j.getValue(1) && mydoubleValue3 == j.getValue(2))
			return *this;
		mydoubleValue = j.doubleValue();
		mydoubleValue2 = j.getValue(1);
		mydoubleValue3 = j.getValue(2);
		return *this;
		
	}

	Double & Double::operator=(const double& d)
	{
	  mydoubleValue = d;
	  mydoubleValue2 = 0;
	  mydoubleValue3 = 0;
	  return *this;
		
	}

	bool Double::operator==(const Double& j) const
	{
	  for(int i = 0;i<3;i++)
	    if(getValue(i) != j.getValue(i))
	      return false;
	  
	  return true;

	}

	bool Double::operator==(const double j) const
	{
	  return mydoubleValue == j;
	}

	std::ostream& operator<<( std::ostream& theStream, const Double& j)
	{
		theStream << j.toDString();
		return theStream;
	}
	void Double::operator*=(const Double& i)
	{
	  for(int j = 0;j<3;j++)
	    setValue(j,getValue(j)*i.getValue(j));
	  
	}
	void Double::operator*=(const double i)
	{
	  for(int j = 0;j<3;j++)
	    setValue(j,getValue(j)*i);
	}

int Double::intValue() const
{
  double returnMe = 0;
  modf(mydoubleValue,&returnMe);
  return (int) returnMe;
}

DString Double::toDString() const
{
	std::ostringstream ss;
	DString temp = toDString(ss);
	return temp;
}

DString Double::toDString(std::ostringstream& ss) const
{
	ss << mydoubleValue;
	DString temp(ss.str());
    return temp;
}

	int Double::getIntVal(char ch)
	{
		switch(ch)
		{
			case '1':
				return 1;
			case '2':
				return 2;
			case '3':
				return 3;
			case '4':
				return 4;
			case '5':
				return 5;
			case '6':
				return 6;
			case '7':
				return 7;
			case '8':
				return 8;
			case '9':
				return 9;
			case '0':
				return 0;
			default:
			  throw DavidException(DString((char) ch)+DString(" is not an integer."),DavidException::FORMAT_ERROR_CODE);
		}

	}

double Double::parseRoot(double x, double root)
{
  
  if(root == 2)
    return sqrt(x);
  
  const int ITERATIONS = 100000;
  if(x<0)
    throw DavidException("Result of this root is an imaginary number.",DavidException::IMAGINARY_NUMBER_ERROR_CODE);
  double num = x; //Number to take square root of
  double r = 1; //Any number actually works for r
  for (int i = 0; i < ITERATIONS; i++) 
    {
      r = ((num / r)+r)/root;
    }
  return r;
}

int Double::toInt()
{
  try
    {
      return intValue();
    }
  catch(...)
    {
      throw DavidException("This double is not an integer",DavidException::FORMAT_ERROR_CODE);
    }
}

	int Double::hexToInt(DString& hex)
	{
		int returnMe = 0;
		if(hex.contains('.'))
			throw DavidException(hex+DString(" is not a valid hexadecimal number"),DavidException::FORMAT_ERROR_CODE);
		for(ushort i = 0;i<hex.length();i++)
		{
			try
			{
				DEBUG_PRINT("hexToInt");
				DEBUG_PRINT(hex[i]);
				Double f((DString) hex[i]);
				returnMe += (int) f.doubleValue()*Double::exponent(16,hex.length()-i-1);
			}
			catch(DavidException de)
			{
				DEBUG_PRINT("hexToInt in catch");
				double f = 0;
				if(hex[i] == 'A' || hex[i] == 'a')
					f = 10;
				else if(hex[i] == 'B' || hex[i] == 'b')
					f = 11;
				else if(hex[i] == 'C' || hex[i] == 'c')
					f = 12;
				else if(hex[i] == 'D' || hex[i] == 'd')
					f = 13;
				else if(hex[i] == 'e' || hex[i] == 'E')
					f = 14;
				else if(hex[i] == 'f' || hex[i] == 'F')
					f = 15;
				else
					throw DavidException(DString((char) hex[i])+"is not a valid hexadecimal digit",DavidException::FORMAT_ERROR_CODE);
				DEBUG_PRINT("adding the number");
				DEBUG_PRINT(f);
				returnMe += (int) f*Double::exponent(16,hex.length()-i-1);

			}
		}
		return returnMe;
	}/**/

	DString Double::intToHex(const int arg)
	{
		if(arg < 0)
			throw DavidException("Argument must be non-negative",DavidException::INVALID_ARGUMENT_ERROR_CODE);
		if(arg == 0)
			return DString("0");

		DString returnMe = "";
		int i = arg;

		while(i > 0)
		{
			int mod = i % 16;
			
			switch(mod)
			{
			case(0):case(1):case(2):case(3):case(4):case(5):case(6):case(7):case(8):case(9):
				returnMe = Double(mod).toDString()+returnMe;
				break;
			case(10):
				returnMe = DString("A")+returnMe;
				break;
			case(11):
				returnMe = DString("B")+returnMe;
				break;
			case(12):
				returnMe = DString("C")+returnMe;
				break;
			case(13):
				returnMe = DString("D")+returnMe;
				break;
			case(14):
				returnMe = DString("E")+returnMe;
				break;
			case(15):
				returnMe = DString("F")+returnMe;
				break;

			}
			i = (int) (i / 16);

		}

		return returnMe;
	}


Double Double::parseDString(const DString & string)
{
  return Double(string);
}

double Double::modulus() const
{
  double returnMe = mydoubleValue*mydoubleValue+mydoubleValue2*mydoubleValue2+mydoubleValue3*mydoubleValue3;
  return sqrt(returnMe);
}

double Double::getValue(int inty) const
{
  
  if(inty > 2 || inty < 0)
    throw DavidException(DString("Not valid index: ")+Double((double) inty).toDString());

    switch(inty)
    {
    case 0:
      return mydoubleValue;
      break;
    case 1:
      return mydoubleValue2;
      break;
    case 2:
      return mydoubleValue3;
      break;
    default:
      throw DavidException(DString("Not valid index: ")+Double((double) inty).toDString());
      break;
    }
}

void Double::setValue(int inty, double value)
{

  if(inty > 2 || inty < 0)
    throw DavidException(DString("Not valid index: ")+Double((double) inty).toDString());

  switch(inty)
    {
    case 0:
      mydoubleValue = value;
      break;
    case 1:
      mydoubleValue2 = value;
      break;
    case 2:
      mydoubleValue3 = value;
      break;
    default:
      throw DavidException(DString("Not valid index: ")+Double((double) inty).toDString());
      break;
    }

}

int Double::stringToNBase(DString number, int base)
{
  int i;
  int binary;

  DString& stringBuffer = number;
  i = binary = 0;

  while(stringBuffer[i])
    {
      stringBuffer[i] -= 48;
      if(stringBuffer[i] > 16)
	stringBuffer[i] -= 7;
      if(stringBuffer[i] >= base)
	stringBuffer[i] -= 32;
      if(stringBuffer[i] >= base || stringBuffer[i] < 0)
	break;
      binary *= base;
      binary += stringBuffer[i];
      i++;
    }

  return binary;
}


Double Double::operator*(const Double& f)
{
  Double returnMe(*this);
  for(int i = 0;i<3;i++)
    returnMe.setValue(i,returnMe.getValue(i)*f.getValue(i));
  
  return returnMe;
}

Double Double::operator*(const double f)
{
  Double returnMe(*this);
  for(int i = 0;i<3;i++)
    returnMe.setValue(i,returnMe.getValue(i)*f);
  
  return returnMe;
}

Double Double::operator/(const double f)
{
  Double returnMe(*this);
  for(int i = 0;i<3;i++)
    returnMe.setValue(i,returnMe.getValue(i)/f);
  
  return returnMe;
}

int Double::sign(double d)
{
  if(d == 0)
    return 0;

  if(d > 0)
    return 1;
  else
    return -1;
}

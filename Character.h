#ifndef CHARACTER_CPP
#define CHARACTER_CPP

#include "DString.h"

class Character
{
	public:
		Character(){myChar = ' ';}
		Character(const char ch){myChar = ch;}
		Character(const Character& Ch){myChar = Ch.myChar;}

		const char getChar() const{return myChar;}
		DString toDString(){char * bean = new char[2]; bean[0] = myChar;bean[1] = '\0';return DString(bean);}
		void stdOut(){ std::cout << myChar << std::endl; }
		const int getIntValue() const{ return (int) myChar;}
		const char charValue() const{return getChar();}
		Character& operator=(const Character&);
		bool operator==(const Character& rhs){return myChar == rhs.myChar;}

	private:
		char myChar;

};

#endif

#include "Character.h"

Character& Character::operator=(const Character& Ch)
{
	myChar = Ch.getChar();
	return *this;
}

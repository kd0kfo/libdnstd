#ifndef DSTACK_CPP
#define DSTACK_CPP

#include <fstream>

#include "DavidException.h"

/**
 * My custom Stack Template
 *
 * (c) David Coss 2010
 */
namespace utils
{
  template <class T>
    class DStack
    {
    public:
	 
      /**
       * Default constructor. Empty Stack.
       */
      DStack();

      /**
       * Copy constructor.
       */
      DStack(const DStack &rhs);

      /**
       * Destructor.
       */
      ~DStack();

      DStack& operator=(const DStack&);
      bool operator==(const DStack&) const;

      /**
       * Returns the number of objects in the stack.
       *
       * @returns int usigned
       */
      ushort getSize()const { return itsSize;}

      /**
       * Gives the next object without popping the stack.
       * Exception is thrown if there is no next object.
       *
       * @throws DavidException
       */
      T& peek();

      /**
       * Adds another object to the top of the stack.
       */
      void push(const T&);

      /**
       * Returns the object on top of the stack.
       * Exception is thrown if there is no next object.
       *
       * @throws DavidException
       */
      T& pop();

      /**
       * Determines if the stack is empty
       */
      bool isEmpty();

      /** 
       * Same as isEmpty()
       *
       * @see isEmpty()
       */
      bool empty();

      /**
       * Adds to stacks together.
       * Note: stack addition is communitive.
       * The lhs is the top.
       * For example:
       * new = left+right;
       * new.pop() will equal left.pop()
       */
      DStack operator+(const DStack&) const;
      DStack operator+=(const DStack&);
			 
			 
      /**
       * Takes a DString and puts into the template object's
       * constructor.
       * Therefore (obviously) the template object must have a T(DString&) constructor
       */
      static DStack parseDString(const DString&);

      static DavidException EMPTY_STACK;

    private:
      T *pType;
      ushort itsSize;
      T& operator[](int offSet) const{return pType[offSet];}
			
    };
}

#endif

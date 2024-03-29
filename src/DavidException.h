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
#ifndef DAVIDEXCEPTION_CPP
#define DAVIDEXCEPTION_CPP

#include <stdexcept>
#include <iostream>
#include <sstream>

/**
 * Exception Object.
 * This is my customized Exception Object. I use it anytime there is an exception needing to be thrown. A few error codes for things I have written are provided.
 * Copyright David Coss 2010
 * Copying and distributing are permitted under the terms of the GNU Public License version 3(see COPYING or http://www.gnu.org/licenses/gpl.txt).
 */
class DavidException : public std::runtime_error
{
 public:
  enum{SUCCESS = 0,
       UNKNOWN_ERROR,
       IMAGINARY_NUMBER_ERROR_CODE,///<Incorrect Imaginary Number Format
       DEFAULT_ERROR_CODE,///<Default error code
       HASHMAP_ERROR_CODE,///<HashMap Error code
       LinAl_ERROR_CODE,///<LinAl Error Code
       DARRAY_ERROR_CODE,///<DArray Error Code
       STRING_TOKENIZER_ERROR_CODE,///<String Tokenizer Error
       MATRIX_ERROR_CODE,
       LTREE_ERROR_CODE,///<LinAl Error Code
       DSTACK_ERROR_CODE,
       FORMAT_ERROR_CODE,
       ARRAYLIST_ERROR_CODE,
       ALPARS_ERROR_CODE,///<LinAl Error Code
       INVALID_ARGUMENT_ERROR_CODE,
       IO_ERROR_CODE,///< Input and/or Output error
       PLANE_OUT_OF_BOUNDS_ERROR_CODE,///<Plane Out of Bounds element requested
       DATA_FORMAT_ERROR,
       NETWORK_ERROR_CODE,
       NULL_POINTER,
       MPI_ERROR_CODE,
       INVALID_XML_REQUEST,
       BAD_XML_TAG,
       ALLOC_ERROR,
       NUMBER_OF_EXCEPTIONS
  };
  /**
   * Main Constructor.
   * This is the default constructor.
   */
 DavidException() : runtime_error("Unknown Error"),errorCode(UNKNOWN_ERROR){}
 DavidException(const std::string& error_msg) : runtime_error(error_msg),errorCode(UNKNOWN_ERROR){}
 DavidException(const std::string& error_msg, const int& error_code) : runtime_error(error_msg),errorCode(error_code){}

 DavidException(const std::string& error_msg, const std::string& deprecated, const int& error_code) : runtime_error(error_msg),errorCode(error_code){}
		
 DavidException(const std::ostringstream& stream, const int& error_code = UNKNOWN_ERROR) : runtime_error(stream.str()), errorCode(error_code){}
  /**
   * Gets the error message.
   * @return DString Error message.
   */
  std::string getMessage() const{return what();}

  /** 
   * Gets the Error type.
   * @return DString Error type
   */
  std::string getType() const{return what();}

  /**
   * Gets the Cause of the Error.
   * @return DString Error Cause
   */
  std::string getCause() const{return what();}

  /**
   * Gets the Error code(int).
   * @return int Error code
   * @see ErrorCodes
   */
  int getCode() const{ return errorCode; }

  /**
   * Sends the result of getMessage() to Standard Output.
   * @see getMessage()
   */
  void stdOut(){std::cout << what() << std::endl;}

  /**
   * Sends the result of getMessage() to Standard Error.
   * @see getMessage()
   */
  void stdErr(){std::cerr << what() << std::endl;}

 private:
  int errorCode;
};

#endif

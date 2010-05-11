#ifndef DAVIDEXCEPTION_CPP
#define DAVIDEXCEPTION_CPP

#ifndef DSTRING_CPP
#include "DString.h"
#endif

/**
 * Exception Object.
 * This is my customized Exception Object. I use it anytime there is an exception needing to be thrown.
 * Created By David Coss, 2007
 */
class DavidException
{
 public:
  /**
   * Main Constructor.
   * This is the default constructor.
   */
     DavidException();
     
     /**
      * Cause and Error message Constructor.
      * This constructor sets the cause and error message.
      * @param theCause The cause of the exception.
      * @param theError The Error message.
      */
		DavidException(const DString& theCause, const DString& theErrorType);
		
		/**
		 * Cause Constructor.
		 * This Constructor sets the Cause only.
		 * @param theCause Cause of the Exception.
		 */
		DavidException(const DString& theCause);
		
		/**
		 * Cause and Error message constructor. 
		 * Same as DString, DString Constructor
		 * @see DavidException(const DString& theCause, const DString& theErrorType)
		 */
		DavidException(const char *,const char *);

		/**
		 * Cause constructor. 
		 * Same as DString Constructor
		 * @see DavidException(const DString& theCause)
		 */
		DavidException(const char*);

		/**
		 * Error Code Constructor
		 * @param errorCode ErrorCode
		 * @see ErrorCodes Below
		 */
		DavidException(int errorCode);
		DavidException(const DString& theCause, const DString& theErrorType, int errorCode);
		DavidException(const DString& theCause,int errorCode);
		DavidException(const char *,const char *, int errorCode);
		DavidException(const char*, int errorCode);
		DavidException(const DavidException&);
		~DavidException();

		static const int IMAGINARY_NUMBER_ERROR_CODE = -1;///<Incorrect Imaginary Number Format
		static const int DEFAULT_ERROR_CODE = -2;///<Default error code
		static const int HASHMAP_ERROR_CODE = 1;///<HashMap Error code
		static const int LinAl_ERROR_CODE = 2;///<LinAl Error Code
		static const int DARRAY_ERROR_CODE = 3;///<DArray Error Code
		static const int STRING_TOKENIZER_ERROR_CODE = 4;///<String Tokenizer Error
		static const int MATRIX_ERROR_CODE = 5;
		static const int LTREE_ERROR_CODE = 6;///<LinAl Error Code
		static const int DSTACK_ERROR_CODE = 7;
		static const int FORMAT_ERROR_CODE = 8;
		static const int ARRAYLIST_ERROR_CODE = 9;
		static const int ALPARS_ERROR_CODE = 10;///<LinAl Error Code
		static const int DHashMap_ERROR_CODE = 11;
		static const int INVALID_ARGUMENT_ERROR_CODE = 12;
		static const int IO_ERROR_CODE = 13;///< Input and/or Output error
		static const int PLANE_OUT_OF_BOUNDS_ERROR_CODE = 14;///<Plane Out of Bounds element requested
		static const int DLIST_ERROR_CODE = 15;///<Invalid DList Request
		
		/**
		 * Gets the error message.
		 * @return DString Error message.
		 */
		DString getMessage() const;

		/** 
		 * Gets the Error type.
		 * @return DString Error type
		 */
		DString getType() const{return errorType;}

		/**
		 * Gets the Cause of the Error.
		 * @return DString Error Cause
		 */
		DString getCause() const{return cause;}

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
		void stdOut(){DString bean = getMessage(); std::cout << bean << std::endl;}

		/**
		 * Sends the result of getMessage() to Standard Error.
		 * @see getMessage()
		 */
		void stdErr(){DString bean = getMessage(); std::cerr << bean << std::endl;}

	private:
		DString cause;
		DString errorType;
		int errorCode;
}
;

#endif

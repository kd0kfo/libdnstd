#include "DavidException.h"

DavidException::DavidException()
{
	cause = DString("Unknown Error");
	errorType = DString("Unknown Error");
	errorCode = this->DEFAULT_ERROR_CODE;
}

DavidException::DavidException(int errorCode)
{
	cause = DString("Unknown Error");
	errorType = DString("Unknown Error");
	this->errorCode = errorCode;
}


DavidException::DavidException(const DString& theCause, const DString& theErrorType)
{
	cause = theCause;
	errorType = theErrorType;
	errorCode = this->DEFAULT_ERROR_CODE;
}

DavidException::DavidException(const DString& theCause, const DString& theErrorType, int errorCode)
{
	cause = theCause;
	errorType = theErrorType;
	this->errorCode = errorCode;
}

DavidException::DavidException(const char * theCause, const char * theErrorType)
{
	cause = DString(theCause);
	errorType = DString(theErrorType);
	errorCode = this->DEFAULT_ERROR_CODE;
}

DavidException::DavidException(const char * theCause, const char * theErrorType, int errorCode)
{
	cause = DString(theCause);
	errorType = DString(theErrorType);
	this->errorCode = errorCode;
}

DavidException::DavidException(const DString& theCause)
{
	cause = theCause;
	errorType = DString("General Error");
	errorCode = this->DEFAULT_ERROR_CODE;
}

DavidException::DavidException(const DString& theCause, int errorCode)
{
	cause = theCause;
	errorType = DString("General Error");
	this->errorCode = errorCode;
}

DavidException::DavidException(const char * theCause)
{
	cause = DString(theCause);
	errorType = DString("General Error");
	errorCode = this->DEFAULT_ERROR_CODE;
}

DavidException::DavidException(const char * theCause, int errorCode)
{
	cause = DString(theCause);
	errorType = DString("General Error");
	this->errorCode = errorCode;
}

DString DavidException::getMessage() const
{
  return errorType + DString(": ") + cause;
}

DavidException::DavidException(const DavidException& de)
{
  cause = de.getCause();
  errorType = de.getType();
  errorCode = de.getCode();
}

DavidException::~DavidException()
{
}



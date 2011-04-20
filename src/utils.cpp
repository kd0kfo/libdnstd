#include "utils.h"

std::string utils::lower_case(std::string str)
{
  for(size_t i =0, size = str.size();i<size;i++)
    if(str[i] >= 'A' && str[i] <= 'Z')
      str[i] += 0x20;
  return str;
}

std::string utils::upper_case(std::string str)
{
  for(size_t i =0, size = str.size();i<size;i++)
    if(str[i] >= 'a' && str[i] <= 'a')
      str[i] -= 0x20;
  return str;
}

std::string utils::get_hostname() throw (DavidException)
{
  char hostname[HOST_NAME_MAX];
  
  int retval = gethostname(hostname,HOST_NAME_MAX);
  if(retval)
    {
      std::ostringstream error;
      error << "utils:get_hostname: Could not get hostname."
	    << "Reason: " << strerror(errno);
      throw DavidException(error,DavidException::NETWORK_ERROR_CODE);
    }

  return hostname;
}

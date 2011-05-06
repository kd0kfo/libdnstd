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
#include "utils.h"
#include <unistd.h>
#include <limits.h>
#include <cstring>
#include <errno.h>

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

std::string utils::trimString(const std::string& theString)
{
    std::string bean = theString;
    size_t lastpos = bean.find_last_not_of(" \t");
    size_t firstpos = bean.find_first_not_of(" \t");
    if(firstpos == bean.npos || lastpos == bean.npos)
    {
        bean = "";
    }
    else
        bean = bean.substr(firstpos,lastpos - firstpos + 1);

    return bean;
}


std::string utils::getNextLine(std::iostream& file) throw (DavidException)
{
    if(!file.good())
      throw DavidException("Could not read from file",DavidException::IO_ERROR_CODE);

    std::string returnMe;
    getline(file,returnMe);
    return returnMe;
}



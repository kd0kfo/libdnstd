#ifndef UTILS_H
#define UTILS_H 1

#include <string>
#include <unistd.h>
#include <limits.h>
#include <cstring>
#include <errno.h>
#include "DavidException.h"

namespace utils{
  std::string get_hostname() throw (DavidException);
  std::string lower_case(std::string);
  std::string upper_case(std::string);
  std::string trimString(const std::string& bean);
  std::string getNextLine(std::iostream& file) throw (DavidException);
}
#endif

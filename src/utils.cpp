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

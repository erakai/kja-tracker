#include <chrono>
#include <string>

#ifndef URL_H
#define URL_H

namespace jobs
{

class URL
{
  public:
    URL(std::string address) : address(address) {}
  
    std::string address;
    std::chrono::time_point<std::chrono::system_clock> date_accessed;

};

}

#endif
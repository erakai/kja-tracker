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
    URL(std::string address, 
        std::chrono::time_point<std::chrono::system_clock> date_accessed) : 
          address(address), date_accessed(date_accessed) {}
  
    std::string address;
    std::chrono::time_point<std::chrono::system_clock> date_accessed;

};

}

#endif
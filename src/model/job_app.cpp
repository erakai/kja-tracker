#include "model/job_app.hpp"

#include <iostream>

namespace jobs
{

std::string status_to_string(AppStatus status)
{
  for (auto &i : status_map) {
    if (i.second == status) {
      return i.first;
    }
  }
  return "";
}
  
void JobApp::update_status(const AppStatus new_status)
{
  status_hist.push_back(new_status);
}

AppStatus& JobApp::status()
{
  return status_hist.back();
}

std::ostream& operator<<(std::ostream& os, const JobApp& ja)
{
  os << ja.url.address << std::endl;
  return os;
}

}
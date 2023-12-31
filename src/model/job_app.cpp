#include "model/job_app.hpp"

#include <iostream>

namespace jobs
{
  
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
  os << "Application: " << ja.url.address << std::endl;
  return os;
}


}
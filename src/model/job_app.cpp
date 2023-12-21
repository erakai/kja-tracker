#include "job_app.hpp"

#include <iostream>

namespace jobs
{

JobApp::JobApp(URL url) : url(url)
{

}

void JobApp::print()
{
  std::cout << "Application: " << url.address << std::endl;
}


}
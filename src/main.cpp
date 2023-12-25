#include "model/job_app.hpp"

#include <iostream>

int main()
{
  std::cout << "============= RUNNING KJA TRACKER ============\n";

  jobs::URL url("google.com");
  jobs::JobApp app(url);

  std::cout << app;

  return 0;
}
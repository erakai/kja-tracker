#include "../db/app_store.hpp"
#include "../model/job_app.hpp"

#include <iostream>

#ifndef CLI_RUNNER_HPP
#define CLI_RUNNER_HPP

class CLIRunner
{
  public:
    void run();

  private:
    jobs::AppStore store;  

};


#endif
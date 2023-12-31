#include "../db/basic_app_store.hpp"
#include "../model/job_app.hpp"

#include <iostream>

#ifndef CLI_RUNNER_HPP
#define CLI_RUNNER_HPP

class CLIRunner
{
  public:
    void run();

  private:
    jobs::BasicAppStore store;  

    const char *help_message = 
      "Possible commands (case sensitive):\n"
      "\t- help: View this message\n"
      "\t- add: Add a new application\n"
      "\t- view: View all added applications\n"
      "\t- update: Update an existing application's status\n"
      "\t- quit: Quit\n"
      "";
    
    void help()
    {
      std::cout << help_message;
    }

    std::string prompt()
    {
      std::cout << "> ";
      std::string input;
      std::cin >> input;

      return input;
    }

    void add_job();
    void view_jobs();
    void update_job_status();

};


#endif
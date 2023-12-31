#include "interface/cli_runner.hpp"

void CLIRunner::run()
{
  std::cout << "Initializing store... Initialized!\n";
  help();

  while (true)
  {
    std::string input = prompt();

    if (!input.compare("help"))
    {
      help();
    }
    else if (!input.compare("quit"))
    {
      break;
    }
    else if (!input.compare("add"))
    {
      add_job();
    }
    else if (!input.compare("view"))
    {
      view_jobs();
    }
    else if (!input.compare("update"))
    {
      update_job_status();
    }
    else
    {
      std::cout << "Command not recognized.\n";
    }

  }
}

void CLIRunner::add_job()
{
  std::cout << "What's the URL of the job listing?\n";
  std::string url = prompt();

  std::cout << "Have you (applied), were you (referred), or were you (contacted)?\n";
  std::string status = prompt();
  if (jobs::status_map.find(status) == jobs::status_map.end())
  {
    std::cout << "Invalid.\n";
    return;
  }

  jobs::URL job_url(url);
  std::shared_ptr<jobs::JobApp> job_ptr(new jobs::JobApp(job_url));
  job_ptr->update_status(jobs::status_map[status]);

  store.store_app(job_ptr);

  std::cout << "Application tracked!\n";
}

void CLIRunner::view_jobs()
{
  std::cout << "STATUS - URL\n";

  std::vector<std::shared_ptr<jobs::JobApp>> jobs = store.get_apps();
  for (auto j: jobs)
  {
    std::cout << " " << jobs::status_to_string(j->status()) << " - " << *j;
  }
}

void CLIRunner::update_job_status()
{
  std::cout << "updating\n";
}
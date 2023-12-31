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
    std::cout << "Invalid status.\n";
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
  std::cout << "ID - STATUS - URL\n";

  std::map<uint64_t, std::shared_ptr<jobs::JobApp>> jobs = store.get_apps();
  for (auto j: jobs)
  {
    std::cout << " " << j.first << " - " << jobs::status_to_string(j.second->status()) << " - " << *(j.second);
  }
}

void CLIRunner::update_job_status()
{
  std::cout << "What is the ID of the application you would like to update?\n";

  std::string id_str = prompt();
  uint64_t id = std::stoi(id_str);

  if (store.get_app(id) == nullptr)
  {
    std::cout << "Invalid ID.\n";
    return;
  }

  std::cout << "What status would you like to update it with?\n";
  std::cout << "\t - (oa)\n";
  std::cout << "\t - (first round)\n";
  std::cout << "\t - (second round)\n";
  std::cout << "\t - (third round)\n";
  std::cout << "\t - (accepted)\n";
  std::cout << "\t - (rejected)\n";
  std::cout << "\t - (ghosted)\n";

  std::string str_status = prompt();
  if (jobs::status_map.find(str_status) == jobs::status_map.end())
  {
    std::cout << "Invalid status.\n";
    return;
  }
  jobs::AppStatus status = jobs::status_map[str_status];

  store.get_app(id)->update_status(status);
  std::cout << "Updated!\n";
}
#include "../model/job_app.hpp"

#include <map>

#ifndef APP_STORE_HPP
#define APP_STORE_HPP

namespace jobs
{

class BasicAppStore
{
  public:
    BasicAppStore();
    ~BasicAppStore();

    void store_app(JobApp *app);
    void update_app(const uint64_t id, JobApp *app);
    void remove_app(const uint64_t id);
    JobApp* get_app(const uint64_t id);
    std::vector<JobApp*> get_apps();

  private:
    void load_apps();
    void save_apps();

    uint64_t gen_key()
    {
      return apps.size() + 1;
    }

    std::map<uint64_t, JobApp*> apps;

};

}

#endif
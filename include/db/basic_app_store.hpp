#include "model/job_app.hpp"
#include "db/app_store.hpp"

#include <map>

#ifndef BASIC_APP_STORE_HPP
#define BASIC_APP_STORE_HPP

namespace jobs
{

class BasicAppStore: public AppStore
{
  public:
    BasicAppStore() = default;
    ~BasicAppStore() = default; 

    uint64_t store_app(std::shared_ptr<JobApp> app) override;
    void update_app(const uint64_t id, std::shared_ptr<JobApp> app) override;
    void remove_app(const uint64_t id) override;
    std::shared_ptr<JobApp> get_app(const uint64_t id) override;
    std::map<uint64_t, std::shared_ptr<JobApp>> get_apps() override;

  protected:
    void load_apps() override {};
    void save_apps() override {};

    uint64_t gen_key() override
    {
      return apps.size() + 1;
    }

    std::map<uint64_t, std::shared_ptr<JobApp>> apps;
};

}

#endif
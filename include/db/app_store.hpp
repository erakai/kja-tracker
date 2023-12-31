#include "model/job_app.hpp"

#include <memory>

#ifndef APP_STORE_HPP
#define APP_STORE_HPP

namespace jobs
{

class AppStore
{
  public:
    virtual uint64_t store_app(std::shared_ptr<JobApp> app) = 0;
    virtual void update_app(const uint64_t id, std::shared_ptr<JobApp> app) = 0;
    virtual void remove_app(const uint64_t id) = 0;
    virtual std::shared_ptr<JobApp> get_app(const uint64_t id) = 0;
    virtual std::vector<std::shared_ptr<JobApp>> get_apps() = 0;

  protected:
    virtual void load_apps() = 0;
    virtual void save_apps() = 0;
    virtual uint64_t gen_key() = 0;

};

}

#endif
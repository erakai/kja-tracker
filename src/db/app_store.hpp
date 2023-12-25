#include "../model/job_app.hpp"

#ifndef APP_STORE_HPP
#define APP_STORE_HPP

namespace jobs
{

struct App
{
  uint64_t id;
  JobApp app;
};

class AppStore
{
  public:
    AppStore()
    {
      // load
    }

    ~AppStore()
    {
      // save
    }

    void store_app(const App *app);
    void update_app(uint64_t id, const JobApp *app);
    void remove_app(uint64_t id);
    std::vector<App*> get_apps();

  private:
    std::vector<App*> apps;

};

}

#endif
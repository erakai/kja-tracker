#include "app_store.hpp"

using namespace jobs;

void AppStore::load_apps()
{
  // TODO: Loading apps
}

void AppStore::save_apps()
{
  // TODO: Saving apps
}

void AppStore::store_app(JobApp *app)
{
  uint64_t id = gen_key();
  apps[id] = app;
}

void AppStore::update_app(const uint64_t id, JobApp *app)
{
  apps[id] = app;
}

void AppStore::remove_app(const uint64_t id)
{
  apps.erase(id);
}

JobApp* AppStore::get_app(const uint64_t id)
{
  return apps[id];
}

std::vector<JobApp*> AppStore::get_apps()
{
  std::vector<JobApp*> v;
  for (auto it = apps.begin(); it != apps.end(); it++)
  {
    v.push_back(it->second);
  }

  return v;
}

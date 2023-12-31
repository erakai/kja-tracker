#include "db/basic_app_store.hpp"

using namespace jobs;

BasicAppStore::BasicAppStore()
{
  load_apps();
}

BasicAppStore::~BasicAppStore()
{
  save_apps();
}

void BasicAppStore::load_apps()
{
  // TODO: Loading apps
}

void BasicAppStore::save_apps()
{
  // TODO: Saving apps
}

void BasicAppStore::store_app(JobApp *app)
{
  uint64_t id = gen_key();
  apps[id] = app;
}

void BasicAppStore::update_app(const uint64_t id, JobApp *app)
{
  apps[id] = app;
}

void BasicAppStore::remove_app(const uint64_t id)
{
  apps.erase(id);
}

JobApp* BasicAppStore::get_app(const uint64_t id)
{
  return apps[id];
}

std::vector<JobApp*> BasicAppStore::get_apps()
{
  std::vector<JobApp*> v;
  for (auto it = apps.begin(); it != apps.end(); it++)
  {
    v.push_back(it->second);
  }

  return v;
}

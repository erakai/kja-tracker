#include "db/basic_app_store.hpp"

using namespace jobs;

uint64_t BasicAppStore::store_app(std::shared_ptr<JobApp> app)
{
  uint64_t id = gen_key();
  apps[id] = app;
  return id;
}

void BasicAppStore::update_app(const uint64_t id, std::shared_ptr<JobApp> app)
{
  apps[id] = app;
}

void BasicAppStore::remove_app(const uint64_t id)
{
  apps.erase(id);
}

std::shared_ptr<JobApp> BasicAppStore::get_app(const uint64_t id)
{
  if (apps.find(id) == apps.end())
  {
    return nullptr;
  }

  return apps[id];
}

std::map<uint64_t, std::shared_ptr<JobApp>> BasicAppStore::get_apps()
{
  return apps;
}

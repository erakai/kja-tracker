#include "url.hpp"

#include <vector>
#include <map>

#ifndef JOB_APP_H
#define JOB_APP_H

namespace jobs
{

enum AppStatus
{
  APPLIED, REFERRED, CONTACTED,
  OA,
  FIRST_ROUND, SECOND_ROUND, THIRD_ROUND,
  ACCEPTED, REJECTED, GHOSTED
};

static std::map<std::string, AppStatus> status_map = {
  {"applied", APPLIED},
  {"referred", REFERRED},
  {"contacted", CONTACTED},
  {"oa", OA},
  {"first round", FIRST_ROUND},
  {"second round", SECOND_ROUND},
  {"third_round", THIRD_ROUND},
  {"accepted", ACCEPTED},
  {"rejected", REJECTED},
  {"ghosted", GHOSTED}
};

std::string status_to_string(AppStatus status);


class JobApp
{
  public:
    JobApp(URL url) : url(url) {};

    void update_status(AppStatus new_status);
    AppStatus& status();

    friend std::ostream& operator<<(std::ostream& os, const JobApp& ja);

    std::string notes;

  private:
    URL url;
    std::vector<AppStatus> status_hist;

};

}

#endif
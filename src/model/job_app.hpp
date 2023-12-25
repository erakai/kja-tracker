#include "url.hpp"

#include <vector>

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


class JobApp
{
  public:
    JobApp(URL url);

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
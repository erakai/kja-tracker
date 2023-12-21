#include "url.hpp"

#ifndef JOB_APP_H
#define JOB_APP_H

namespace jobs
{

class JobApp
{
public:
  JobApp(URL url);

  void print();

private:
  URL url;

};

}

#endif
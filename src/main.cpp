#include "interface/cli_runner.hpp"

#include <iostream>

int main()
{
  std::cout << "============= RUNNING KJA TRACKER =============\n";

  CLIRunner runner;
  runner.run();

  return 0;
}

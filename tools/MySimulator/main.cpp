#include "MySimulator/MySimulator.h"

#include <sparta/app/CommandLineSimulator.hpp>

int main(int argc, char **argv) {
  sparta::app::DefaultValues DEFAULTS;

  sparta::app::CommandLineSimulator cls("", DEFAULTS);

  if (int err = 0; !cls.parse(argc, argv, err))
    return err;

  try {
    sparta::Scheduler scheduler;
    MySimulator sim(scheduler, true);

    cls.populateSimulation(&sim);
    cls.runSimulator(&sim);
    cls.postProcess(&sim);

  } catch (...) {
    throw;
  }

  return 0;
}
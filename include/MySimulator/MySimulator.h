#ifndef MYSIMULATOR_MYSIMULATOR_H
#define MYSIMULATOR_MYSIMULATOR_H

#include <sparta/app/Simulation.hpp>

class MySimulator : public sparta::app::Simulation {
public:
  MySimulator(sparta::Scheduler &scheduler, bool noisy);

  virtual ~MySimulator();

private:
  void buildTree_() override;

  void configureTree_() override;

  void bindTree_() override;

  const bool noisy = false;
};

#endif // MYSIMULATOR_MYSIMULATOR_H

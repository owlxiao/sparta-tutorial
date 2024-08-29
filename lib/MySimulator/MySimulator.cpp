#include "MySimulator/MySimulator.h"

MySimulator::MySimulator(sparta::Scheduler &scheduler, bool noisy)
    : sparta::app::Simulation("sparta_mysimulator", &scheduler), noisy(noisy) {
  // Using the macro SPARTA_EXPECT_FALSE will tell the compiler that
  // most of the time, this if statement is falses -- it's an
  // optimization.  There is also a SPARTA_EXPECT_TRUE
  if (SPARTA_EXPECT_FALSE(noisy)) {
    std::cout << "NOISE: " << __PRETTY_FUNCTION__ << ": Constructing"
              << std::endl;
  }
}

MySimulator::~MySimulator() {}

void MySimulator::buildTree_() {}

void MySimulator::configureTree_() {}

void MySimulator::bindTree_() {}
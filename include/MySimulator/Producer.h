#ifndef SIMULATOR_PRODUCER_H
#define SIMULATOR_PRODUCER_H

#include <sparta/simulation/ParameterSet.hpp>
#include <sparta/simulation/Unit.hpp>

class Producer : public sparta::Unit {
public:
  static const char *name;

  class ParameterSet : public sparta::ParameterSet {
  public:
    ParameterSet(sparta::TreeNode *n) : sparta::ParameterSet(n) {}
  };

  Producer(sparta::TreeNode *node, const ParameterSet *p);
};

#endif // SIMULATOR_PRODUCER_H

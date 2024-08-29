#ifndef MYSIMULATOR_CONSUMER_H
#define MYSIMULATOR_CONSUMER_H

#include <sparta/simulation/ParameterSet.hpp>
#include <sparta/simulation/Unit.hpp>

class Consumer : public sparta::Unit {
public:
  static const char *name;

  class ParameterSet : public sparta::ParameterSet {
  public:
    ParameterSet(sparta::TreeNode *n) : sparta::ParameterSet(n) {}
  };

  Consumer(sparta::TreeNode *node, const Consumer::ParameterSet *p);
};

#endif // MYSIMULATOR_CONSUMER_H

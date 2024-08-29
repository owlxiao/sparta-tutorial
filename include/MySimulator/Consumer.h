#ifndef MYSIMULATOR_CONSUMER_H
#define MYSIMULATOR_CONSUMER_H

#include <sparta/ports/DataPort.hpp>
#include <sparta/ports/SignalPort.hpp>
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

private:
  sparta::SignalOutPort ProducerOutPort{&unit_port_set_, "producer_go_port"};
  sparta::DataInPort<uint32_t> ConsumerInPort{&unit_port_set_,
                                              "consumer_in_port"};
};

#endif // MYSIMULATOR_CONSUMER_H

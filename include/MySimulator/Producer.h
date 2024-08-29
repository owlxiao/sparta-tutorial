#ifndef SIMULATOR_PRODUCER_H
#define SIMULATOR_PRODUCER_H

#include <sparta/ports/DataPort.hpp>
#include <sparta/ports/SignalPort.hpp>
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

private:
  sparta::SignalInPort ProducerGoPort{&unit_port_set_, "producer_go_port"};
  sparta::DataOutPort<uint32_t> ProducerOutPort{&unit_port_set_,
                                                "producer_out_port"};
};

#endif // SIMULATOR_PRODUCER_H

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
  // Consumer's receiving callback
  void receiveData(const uint32_t &dat);
  sparta::utils::ValidValue<uint32_t> ArrivedData;

  // 0 cycle delay on scheduling
  sparta::UniqueEvent<> EvDataArrived{
      &unit_event_set_, "EvDataArrived",
      CREATE_SPARTA_HANDLER(Consumer, dataArrived), 0};

  // Operate on incoming data
  void dataArrived();

  // Startup handler
  void signalNextProducer();

  sparta::SignalOutPort ProducerGoPort{&unit_port_set_, "producer_go_port"};
  sparta::DataInPort<uint32_t> ConsumerInPort{&unit_port_set_,
                                              "consumer_in_port", 1};

};

#endif // MYSIMULATOR_CONSUMER_H

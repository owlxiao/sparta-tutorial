#include "MySimulator/Consumer.h"

const char *Consumer::name = "consumer";

Consumer::Consumer(sparta::TreeNode *node, const Consumer::ParameterSet *p)
    : sparta::Unit(node, name) {
  (void)p;

  // Register callback to receive data on the InPort
  ConsumerInPort.registerConsumerHandler(
      CREATE_SPARTA_HANDLER_WITH_DATA(Consumer, receiveData, uint32_t));

  // Get the ball rolling
  sparta::StartupEvent(node,
                       CREATE_SPARTA_HANDLER(Consumer, signalNextProducer));
}

void Consumer::receiveData(const uint32_t &dat) {
  sparta_assert(ArrivedData.isValid() == false,
                "Somehow, data wasn't cleared in this consumer: " << getName());
  ArrivedData = dat;

  // Schedule a consumption this cycle
  EvDataArrived.schedule();

  // Signal the next producer
  signalNextProducer();
}

void Consumer::dataArrived() {
  std::cout << std::format("\tGot data `{}` on cycle: {}\n",
                           ArrivedData.getValue(), getClock()->currentCycle());
  ArrivedData.clearValid();
}

void Consumer::signalNextProducer() { ProducerGoPort.send(); }
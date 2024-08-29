#include "MySimulator/Producer.h"

#include <format>

const char *Producer::name = "producer";

Producer::Producer(sparta::TreeNode *node, const Producer::ParameterSet *p)
    : sparta::Unit(node, name) {
  (void)p;

  ProducerGoPort.registerConsumerHandler(
      CREATE_SPARTA_HANDLER(Producer, produceData));
}

void Producer::produceData() {
  std::cout << std::format("Producer: {} @ {} Sending {}\n", getName(),
                           getContainer()->getLocation(), CurrentCount);

  ProducerOutPort.send(CurrentCount);
  ++CurrentCount;
}
#include "MySimulator/Producer.h"

const char *Producer::name = "producer";

Producer::Producer(sparta::TreeNode *node, const Producer::ParameterSet *p)
    : sparta::Unit(node, name) {
  (void)p;
}
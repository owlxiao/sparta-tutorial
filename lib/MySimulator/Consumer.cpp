#include "MySimulator/Consumer.h"

const char *Consumer::name = "consumer";

Consumer::Consumer(sparta::TreeNode *node, const Consumer::ParameterSet *p)
    : sparta::Unit(node, name) {
  (void)p;
}
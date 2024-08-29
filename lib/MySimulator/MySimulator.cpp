#include "MySimulator/MySimulator.h"
#include "MySimulator/Consumer.h"
#include "MySimulator/Producer.h"

MySimulator::MySimulator(sparta::Scheduler &scheduler, bool noisy)
    : sparta::app::Simulation("sparta_mysimulator", &scheduler), noisy(noisy) {
  // Using the macro SPARTA_EXPECT_FALSE will tell the compiler that
  // most of the time, this if statement is falses -- it's an
  // optimization.  There is also a SPARTA_EXPECT_TRUE
  if (SPARTA_EXPECT_FALSE(noisy)) {
    std::cout << "NOISE: " << __PRETTY_FUNCTION__ << ": Constructing"
              << std::endl;
  }

  getResourceSet()
      ->addResourceFactory<
          sparta::ResourceFactory<Producer, Producer::ParameterSet>>();
  getResourceSet()
      ->addResourceFactory<
          sparta::ResourceFactory<Consumer, Consumer::ParameterSet>>();
}

MySimulator::~MySimulator() {
  if (SPARTA_EXPECT_FALSE(noisy)) {
    std::cout << __PRETTY_FUNCTION__ << ": Tearing down" << std::endl;
  }
  getRoot()->enterTeardown(); // Allow deletion of nodes without error now
}

void MySimulator::buildTree_() {
  if (SPARTA_EXPECT_FALSE(noisy)) {
    std::cout << "NOISE: " << __PRETTY_FUNCTION__
              << ": Building the ResourceTreeNodes -- not instantiated yet"
              << std::endl;
  }

  // Create consumer
  auto *ret = new sparta::ResourceTreeNode(
      getRoot(), "consumer", sparta::TreeNode::GROUP_NAME_NONE,
      sparta::TreeNode::GROUP_IDX_NONE, "Consumer Object",
      getResourceSet()->getResourceFactory(Consumer::name));
  to_delete_.emplace_back(ret);

  // Create producer
  ret = new sparta::ResourceTreeNode(
      getRoot(), "producer", sparta::TreeNode::GROUP_NAME_NONE,
      sparta::TreeNode::GROUP_IDX_NONE, "Producer Object",
      getResourceSet()->getResourceFactory(Producer::name));
  to_delete_.emplace_back(ret);
}

void MySimulator::configureTree_() {
  if (SPARTA_EXPECT_FALSE(noisy)) {
    std::cout << "NOISE: " << __PRETTY_FUNCTION__
              << ": Configuring the parameters in the ResourceTreeNodes, "
              << "but not the simulated objects are still not instantiated yet!"
              << std::endl;
  }
}

void MySimulator::bindTree_() {
  if (SPARTA_EXPECT_FALSE(noisy)) {
    std::cout << "NOISE: " << __PRETTY_FUNCTION__
              << ": The simulated objects are instantiated.  Can be bound now."
              << std::endl;
  }

  auto *RootNode = getRoot();
  sparta_assert(RootNode != nullptr);

  // Bind the producer to the consumer
  sparta::bind(
      RootNode->getChildAs<sparta::Port>("producer.ports.producer_out_port"),
      RootNode->getChildAs<sparta::Port>("consumer.ports.consumer_in_port"));

  sparta::bind(
      RootNode->getChildAs<sparta::Port>("producer.ports.producer_go_port"),
      RootNode->getChildAs<sparta::Port>("consumer.ports.producer_go_port"));
}
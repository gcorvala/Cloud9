#include <gtest/gtest.h>

#include <libcloud/Kdtree/Kdtree.h>

class KdtreeTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
  }

  Kdtree tree1;
};

TEST_F (KdtreeTest, ConstructorWorks) {
}

int
main (int argc, char **argv) {
  ::testing::InitGoogleTest (&argc, argv);
  return RUN_ALL_TESTS ();
}
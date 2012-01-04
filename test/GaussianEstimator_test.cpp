#include <gtest/gtest.h>

#include <libcloud/2D/GaussianEstimator.h>
#include <libcloud/2D/Matrix.h>

class GaussianEstimatorTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
  }

  GaussianEstimator estimator;
};

TEST_F (GaussianEstimatorTest, GetFilterWorks) {
  Matrix<double> filter;

  filter = estimator.getFilter ();

  ASSERT_DOUBLE_EQ (15./115, filter(2, 2));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest (&argc, argv);
  return RUN_ALL_TESTS ();
}
#include <gtest/gtest.h>

#include <libcloud/2D/FourierEstimator.h>

class FourierEstimatorTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    m1.resize (5, 5);
    m1 (0, 0) = 1;
    m1 (0, 1) = 2;
    m1 (0, 2) = 3;
    m1 (0, 3) = 4;
    m1 (0, 4) = 5;
    m1 (1, 0) = 6;
    m1 (1, 1) = 7;
    m1 (1, 2) = 8;
    m1 (1, 3) = 9;
    m1 (1, 4) = 10;
    m1 (2, 0) = 11;
    m1 (2, 1) = 12;
    m1 (2, 2) = 13;
    m1 (2, 3) = 14;
    m1 (2, 4) = 15;
    m1 (3, 0) = 16;
    m1 (3, 1) = 17;
    m1 (3, 2) = 18;
    m1 (3, 3) = 19;
    m1 (3, 4) = 20;
    m1 (4, 0) = 21;
    m1 (4, 1) = 22;
    m1 (4, 2) = 23;
    m1 (4, 3) = 24;
    m1 (4, 4) = 25;
  }

  Matrix<double> m1;
  FourierEstimator estimator;
};

TEST_F (FourierEstimatorTest, Works) {
  Matrix<std::complex<double> > result;

  estimator.compute (m1, result);

  ASSERT_NEAR (325, real (result (0, 0)), 1e-4);
  ASSERT_NEAR (0, imag (result (0, 0)), 1e-4);

  ASSERT_NEAR (-12.5, real (result (0, 1)), 1e-4);
  ASSERT_NEAR (17.2048, imag (result (0, 1)), 1e-4);

  ASSERT_NEAR (-12.5, real (result (0, 2)), 1e-4);
  ASSERT_NEAR (4.0615, imag (result (0, 2)), 1e-4);

  ASSERT_NEAR (-12.5, real (result (0, 3)), 1e-4);
  ASSERT_NEAR (-4.0615, imag (result (0, 3)), 1e-4);

  ASSERT_NEAR (-12.5, real (result (0, 4)), 1e-4);
  ASSERT_NEAR (-17.2048, imag (result (0, 4)), 1e-4);

  ASSERT_NEAR (-62.5, real (result (1, 0)), 1e-4);
  ASSERT_NEAR (86.0239, imag (result (1, 0)), 1e-4);

  ASSERT_NEAR (0, real (result (1, 1)), 1e-4);
  ASSERT_NEAR (0, imag (result (1, 1)), 1e-4);

  ASSERT_NEAR (0, real (result (1, 2)), 1e-4);
  ASSERT_NEAR (0, imag (result (1, 2)), 1e-4);

  ASSERT_NEAR (0, real (result (1, 3)), 1e-4);
  ASSERT_NEAR (0, imag (result (1, 3)), 1e-4);

  ASSERT_NEAR (0, real (result (1, 4)), 1e-4);
  ASSERT_NEAR (0, imag (result (1, 4)), 1e-4);

  ASSERT_NEAR (-62.5, real (result (2, 0)), 1e-4);
  ASSERT_NEAR (20.3075, imag (result (2, 0)), 1e-4);

  ASSERT_NEAR (0, real (result (2, 1)), 1e-4);
  ASSERT_NEAR (0, imag (result (2, 1)), 1e-4);

  ASSERT_NEAR (0, real (result (2, 2)), 1e-4);
  ASSERT_NEAR (0, imag (result (2, 2)), 1e-4);

  ASSERT_NEAR (0, real (result (2, 3)), 1e-4);
  ASSERT_NEAR (0, imag (result (2, 3)), 1e-4);

  ASSERT_NEAR (0, real (result (2, 4)), 1e-4);
  ASSERT_NEAR (0, imag (result (2, 4)), 1e-4);

  ASSERT_NEAR (-62.5, real (result (3, 0)), 1e-4);
  ASSERT_NEAR (-20.3075, imag (result (3, 0)), 1e-4);

  ASSERT_NEAR (0, real (result (3, 1)), 1e-4);
  ASSERT_NEAR (0, imag (result (3, 1)), 1e-4);

  ASSERT_NEAR (0, real (result (3, 2)), 1e-4);
  ASSERT_NEAR (0, imag (result (3, 2)), 1e-4);

  ASSERT_NEAR (0, real (result (3, 3)), 1e-4);
  ASSERT_NEAR (0, imag (result (3, 3)), 1e-4);

  ASSERT_NEAR (0, real (result (3, 4)), 1e-4);
  ASSERT_NEAR (0, imag (result (3, 4)), 1e-4);

  ASSERT_NEAR (-62.5, real (result (4, 0)), 1e-4);
  ASSERT_NEAR (-86.0239, imag (result (4, 0)), 1e-4);

  ASSERT_NEAR (0, real (result (4, 1)), 1e-4);
  ASSERT_NEAR (0, imag (result (4, 1)), 1e-4);

  ASSERT_NEAR (0, real (result (4, 2)), 1e-4);
  ASSERT_NEAR (0, imag (result (4, 2)), 1e-4);

  ASSERT_NEAR (0, real (result (4, 3)), 1e-4);
  ASSERT_NEAR (0, imag (result (4, 3)), 1e-4);

  ASSERT_NEAR (0, real (result (4, 4)), 1e-4);
  ASSERT_NEAR (0, imag (result (4, 4)), 1e-4);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest (&argc, argv);
  return RUN_ALL_TESTS ();
}
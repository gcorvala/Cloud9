#include <gtest/gtest.h>

#include <libcloud/Templates/PointCloudT.h>
#include <libcloud/Templates/Hough2D.h>
#include <libcloud/Templates/Point2D.h>

class Hough2DTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    cloud.clear ();
    cloud.push_back (Point2D <Float32> (0, 10));
    cloud.push_back (Point2D <Float32> (1, 10));
    cloud.push_back (Point2D <Float32> (2, 10));
    cloud.push_back (Point2D <Float32> (3, 10));
    cloud.push_back (Point2D <Float32> (4, 10));
    cloud.push_back (Point2D <Float32> (5, 34));
    cloud.push_back (Point2D <Float32> (6, 10));
    cloud.push_back (Point2D <Float32> (7, 10));
    cloud.push_back (Point2D <Float32> (8, 10));
    cloud.push_back (Point2D <Float32> (9, 10));
    cloud.push_back (Point2D <Float32> (10, 10));

    hough.setNTheta (7);
    hough.setNRho (27);
  }

  PointCloudT < Point2D <Float32> > cloud;
  Hough2D <Float32> hough;
};

TEST_F (Hough2DTest, RhoStepsWorks) {
  Matrix <UInt32> output;
  std::vector <Float64> rho_steps;
  std::vector <Float64> theta_steps;
  hough.compute (cloud, output, rho_steps, theta_steps);

  ASSERT_EQ (27, rho_steps.size ());
  for (UInt32 i = 0; i < 2*27; i += 2) {
    SInt32 rho = i-26;
    ASSERT_EQ (rho, rho_steps[i/2]);
  }
}

TEST_F (Hough2DTest, ThetaStepsWorks) {
  Matrix <UInt32> output;
  std::vector <Float64> rho_steps;
  std::vector <Float64> theta_steps;
  hough.compute (cloud, output, rho_steps, theta_steps);
  UInt32 n_theta = hough.getNTheta ();

  ASSERT_EQ (7, theta_steps.size ());
  for (UInt32 i = 0; i < n_theta; ++i) {
    ASSERT_EQ (M_PI/(n_theta-1)*i, theta_steps[i]);
  }
}

TEST_F (Hough2DTest, ComputeWorks) {
  Matrix <UInt32> output;
  std::vector <Float64> rho_steps;
  std::vector <Float64> theta_steps;
  hough.compute (cloud, output, rho_steps, theta_steps);
  UInt32 max, rho, theta;

  max = output.max (theta, rho);

  ASSERT_EQ (M_PI/2, theta_steps[theta]);
  ASSERT_EQ (10, rho_steps[rho]);
}

int
main (int argc, char **argv)
{
  ::testing::InitGoogleTest (&argc, argv);
  return RUN_ALL_TESTS ();
}
#include <gtest/gtest.h>

#include <libcloud/Common/Plane.h>
#include <math.h>

class PlaneTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    p1 = Plane ();
    p2 = Plane (Point (1, 0, 0), Point (0, 1, 0), Point (0, 0, 1));
    p3 = Plane (1, 2, 3, 4);
    p4 = Plane (1, 2, 3);
  }

  Plane p1;
  Plane p2;
  Plane p3;
  Plane p4;
  Plane p5;
};

TEST_F (PlaneTest, GetNormalWorks) {
  ASSERT_EQ (Vector (1, 0, 0).normalized (), p1.getNormal ());
  ASSERT_EQ (Vector (1, 1, 1).normalized (), p2.getNormal ());
  ASSERT_EQ (Vector (1, 2, 3).normalized (), p3.getNormal ());
}

TEST_F (PlaneTest, GetRhoWorks) {
  ASSERT_EQ (0, p1.getRho ());
  ASSERT_EQ (1./sqrt (3), p2.getRho ());
  ASSERT_EQ (4./sqrt (14), p3.getRho ());
  ASSERT_DOUBLE_EQ (1, p4.getRho ());
}

TEST_F (PlaneTest, GetThetaWorks) {
  ASSERT_EQ (0, p1.getTheta ());
  ASSERT_EQ (M_PI/4, p2.getTheta ());
  ASSERT_EQ (atan (2), p3.getTheta ());
  ASSERT_EQ (2, p4.getTheta ());
}

TEST_F (PlaneTest, GetPhiWorks) {
  ASSERT_EQ (M_PI/2, p1.getPhi ());
  ASSERT_DOUBLE_EQ (M_PI/2-acos (sqrt (2./3.)), p2.getPhi ());
  ASSERT_EQ (atan2 (hypot (1, 2), 3), p3.getPhi ());
  ASSERT_EQ (3, p4.getPhi ());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest (&argc, argv);
  return RUN_ALL_TESTS ();
}
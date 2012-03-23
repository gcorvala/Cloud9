#include <gtest/gtest.h>

#include <libcloud/2D/Line.h>
#include <math.h>

class LineTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    l1 = Line (0, 0);
    l2 = Line (1, M_PI/4);
    l3 = Line (2, M_PI/2);
    l4 = Line (3, 3*M_PI/4);
    l5 = Line (4, M_PI);
  }

  Line l1;
  Line l2;
  Line l3;
  Line l4;
  Line l5;
};

TEST_F (LineTest, GetRhoWorks) {
  ASSERT_EQ (0, l1.getRho ());
  ASSERT_EQ (1, l2.getRho ());
  ASSERT_EQ (2, l3.getRho ());
  ASSERT_EQ (3, l4.getRho ());
  ASSERT_EQ (4, l5.getRho ());
}

TEST_F (LineTest, GetThetaWorks) {
  ASSERT_EQ (0, l1.getTheta ());
  ASSERT_EQ (M_PI/4, l2.getTheta ());
  ASSERT_EQ (M_PI/2, l3.getTheta ());
  ASSERT_EQ (3*M_PI/4, l4.getTheta ());
  ASSERT_EQ (M_PI, l5.getTheta ());
}

TEST_F (LineTest, GetSlopeWorks) {
  ASSERT_TRUE (isinf (l1.getSlope ()));
  ASSERT_DOUBLE_EQ (-1, l2.getSlope ());
  EXPECT_NEAR (0, l3.getSlope (), 1e-10);
  ASSERT_DOUBLE_EQ (1, l4.getSlope ());
  ASSERT_LT (1e10, l5.getSlope ());
}

TEST_F (LineTest, GetXInterceptWorks) {
  ASSERT_EQ (0, l1.getXIntercept ());
  ASSERT_DOUBLE_EQ (sqrt (2), l2.getXIntercept ());
  ASSERT_LT (1e10, l3.getXIntercept ());
  ASSERT_EQ (-3*sqrt (2), l4.getXIntercept ());
  ASSERT_EQ (-4, l5.getXIntercept ());
}

TEST_F (LineTest, GetYInterceptWorks) {
  ASSERT_TRUE (isnan (l1.getYIntercept ()));
  ASSERT_EQ (sqrt (2), l2.getYIntercept ());
  ASSERT_EQ (2, l3.getYIntercept ());
  ASSERT_DOUBLE_EQ (3*sqrt (2), l4.getYIntercept ());
  ASSERT_LT (1e10, l5.getYIntercept ());
}

TEST_F (LineTest, GetPerpendicularWorks) {
  l1 = Line (1, 0, 0);
  ASSERT_EQ (Line (0, 1, 0), l1.getPerpendicular (Point (0, 0)));
  ASSERT_EQ (Line (0, 1, -2), l1.getPerpendicular (Point (2, 2)));
  l1 = Line (1, 2 , 3);
  ASSERT_EQ (Line (-2, 1, 2), l1.getPerpendicular (Point (2, 2)));
}

TEST_F (LineTest, GetIntersectionWorks) {
  l1 = Line (1, 0, 0);
  l2 = Line (0, 1, 0);
  ASSERT_EQ (Point (0, 0), l1.getIntersection (l2));
  l1 = Line (0, -1, 2);
  l2 = Line (-2, 1, 2);
  ASSERT_EQ (Point (2, 2), l1.getIntersection (l2));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest (&argc, argv);
  return RUN_ALL_TESTS ();
}
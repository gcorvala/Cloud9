#include <gtest/gtest.h>

#include <libcloud/Common/Point.h>
#include <math.h>

class PointTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    p1 = Point ();
    p2 = Point (0, 0, 0);
    p3 = Point (-1, 0, 1);
  }

  Point p1;
  Point p2;
  Point p3;
};

TEST_F (PointTest, ConstructorWorks) {
  ASSERT_EQ (0, p1.x);
  ASSERT_EQ (0, p1.y);
  ASSERT_EQ (0, p1.z);
  ASSERT_EQ (0, p2.x);
  ASSERT_EQ (0, p2.y);
  ASSERT_EQ (0, p2.z);
  ASSERT_EQ (-1, p3.x);
  ASSERT_EQ (0, p3.y);
  ASSERT_EQ (1, p3.z);
}

TEST_F (PointTest, EqualityWorks) {
  ASSERT_TRUE (p1 == p2);
  ASSERT_TRUE (p2 == p1);
  ASSERT_TRUE (p1 == p1);
  ASSERT_TRUE (p1 != p3);
  ASSERT_TRUE (p3 != p1);
  ASSERT_FALSE (p1 != p2);
  ASSERT_FALSE (p2 != p1);
  ASSERT_FALSE (p3 != p3);
}

TEST_F (PointTest, DistanceToPointWorks) {
  ASSERT_EQ (0, p1.distanceTo (p1));
  ASSERT_EQ (0, p1.distanceTo (p2));
  ASSERT_EQ (0, p2.distanceTo (p1));
  ASSERT_EQ (sqrt (2), p1.distanceTo (p3));
  ASSERT_EQ (sqrt (2), p3.distanceTo (p1));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest (&argc, argv);
  return RUN_ALL_TESTS ();
}
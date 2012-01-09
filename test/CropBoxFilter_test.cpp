#include <gtest/gtest.h>

#include <libcloud/Filters/CropBoxFilter.h>
#include <libcloud/Common/PointCloud.h>

class CropBoxFilterTest : public ::testing::Test {
 protected:
  CropBoxFilterTest ()
    :f1(Point (0, 0, 0), Point (1, 1, 1))
    ,f2(Point (0, 0, 0), Point (2, 2, 2))
    ,f3(Point (0, 0, 0), Point (1, 2, 1))
  {
  }

  virtual void SetUp() {
    cloud.push_back (Point (0, 0, 0));
    cloud.push_back (Point (1, 0, 0));
    cloud.push_back (Point (0, 1, 0));
    cloud.push_back (Point (0, 0, 1));
    cloud.push_back (Point (1, 1, 1));
    cloud.push_back (Point (2, 0, 0));
    cloud.push_back (Point (0, 2, 0));
    cloud.push_back (Point (0, 0, 2));
  }

  PointCloud cloud;
  CropBoxFilter f1;
  CropBoxFilter f2;
  CropBoxFilter f3;
};

TEST_F (CropBoxFilterTest, F1Works) {
  f1.run (cloud);
  ASSERT_EQ (5, cloud.size ());
  ASSERT_EQ (Point (0, 0, 0), cloud[0]);
  ASSERT_EQ (Point (1, 0, 0), cloud[1]);
  ASSERT_EQ (Point (0, 1, 0), cloud[2]);
  ASSERT_EQ (Point (0, 0, 1), cloud[3]);
  ASSERT_EQ (Point (1, 1, 1), cloud[4]);
}

TEST_F (CropBoxFilterTest, F2Works) {
  unsigned int s = cloud.size ();
  f2.run (cloud);
  ASSERT_EQ (s, cloud.size ());
  ASSERT_EQ (Point (0, 0, 0), cloud[0]);
  ASSERT_EQ (Point (1, 0, 0), cloud[1]);
  ASSERT_EQ (Point (0, 1, 0), cloud[2]);
  ASSERT_EQ (Point (0, 0, 1), cloud[3]);
  ASSERT_EQ (Point (1, 1, 1), cloud[4]);
  ASSERT_EQ (Point (2, 0, 0), cloud[5]);
  ASSERT_EQ (Point (0, 2, 0), cloud[6]);
  ASSERT_EQ (Point (0, 0, 2), cloud[7]);
}

TEST_F (CropBoxFilterTest, F3Works) {
  f3.run (cloud);
  ASSERT_EQ (6, cloud.size ());
  ASSERT_EQ (Point (0, 0, 0), cloud[0]);
  ASSERT_EQ (Point (1, 0, 0), cloud[1]);
  ASSERT_EQ (Point (0, 1, 0), cloud[2]);
  ASSERT_EQ (Point (0, 0, 1), cloud[3]);
  ASSERT_EQ (Point (1, 1, 1), cloud[4]);
  ASSERT_EQ (Point (0, 2, 0), cloud[5]);
}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest (&argc, argv);
  return RUN_ALL_TESTS ();
}
#include <gtest/gtest.h>

#include <libcloud/Templates/LinearSearchT.h>
#include <libcloud/Templates/PointCloudT.h>
#include <libcloud/Templates/Point2D.h>

class SearchTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    cloud.clear ();
    cloud.push_back (Point2D <Float32> (0, 0));
    cloud.push_back (Point2D <Float32> (1, 1));
    cloud.push_back (Point2D <Float32> (2, 2));
    cloud.push_back (Point2D <Float32> (3, 3));
    cloud.push_back (Point2D <Float32> (4, 4));
    cloud.push_back (Point2D <Float32> (5, 5));
    linear.setInputCloud (cloud);
  }

  LinearSearchT < Point2D <Float32> > linear;
  PointCloudT < Point2D <Float32> > cloud;
};

TEST_F (SearchTest, NearestKSearchWorks) {
  PointIndices indices;
  std::vector <Float64> distances;
  UInt32 n;

  n = linear.nearestKSearch (Point2D <Float32> (2.6, 2.6), 4, indices, distances);

  ASSERT_EQ (4, n);
  ASSERT_EQ (n, indices.size ());
  ASSERT_EQ (n, distances.size ());
  ASSERT_EQ (Point2D <Float32> (3, 3), cloud[indices[0]]);
  ASSERT_EQ (Point2D <Float32> (2, 2), cloud[indices[1]]);
  ASSERT_EQ (Point2D <Float32> (4, 4), cloud[indices[2]]);
  ASSERT_EQ (Point2D <Float32> (1, 1), cloud[indices[3]]);
  // FIXME : test distances
}

TEST_F (SearchTest, RadiusSearchWorks) {
  PointIndices indices;
  std::vector <Float64> distances;
  UInt32 n;

  n = linear.radiusSearch (Point2D <Float32> (2.6, 2.6), 2, indices, distances);

  ASSERT_EQ (3, n);
  ASSERT_EQ (n, indices.size ());
  ASSERT_EQ (n, distances.size ());
  ASSERT_EQ (Point2D <Float32> (3, 3), cloud[indices[0]]);
  ASSERT_EQ (Point2D <Float32> (2, 2), cloud[indices[1]]);
  ASSERT_EQ (Point2D <Float32> (4, 4), cloud[indices[2]]);
  // FIXME : test distances
}

int
main (int argc, char **argv)
{
  ::testing::InitGoogleTest (&argc, argv);
  return RUN_ALL_TESTS ();
}
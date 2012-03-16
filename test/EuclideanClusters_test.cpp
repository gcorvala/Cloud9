#include <gtest/gtest.h>

#include <libcloud/Templates/LinearSearchT.h>
#include <libcloud/Templates/PointCloudT.h>
#include <libcloud/Templates/ExtractEuclideanClusters.h>
#include <libcloud/Templates/Point2D.h>

class EuclideanClustersTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    cloud.clear ();
    cloud.push_back (Point2D <Float32> (0, 0));
    cloud.push_back (Point2D <Float32> (1, 1));
    cloud.push_back (Point2D <Float32> (2, 2));
    cloud.push_back (Point2D <Float32> (3, 3));
    cloud.push_back (Point2D <Float32> (4, 4));
    cloud.push_back (Point2D <Float32> (5, 5));
    cloud.push_back (Point2D <Float32> (10, 0));
    cloud.push_back (Point2D <Float32> (11, 1));
    cloud.push_back (Point2D <Float32> (12, 2));
    cloud.push_back (Point2D <Float32> (13, 3));
    cloud.push_back (Point2D <Float32> (14, 4));
    cloud.push_back (Point2D <Float32> (15, 5));
    linear.setInputCloud (cloud);
    euclidean_clusters.setSearchMethod (linear);
  }

  ExtractEuclideanClusters < Point2D <Float32> > euclidean_clusters;
  LinearSearchT < Point2D <Float32> > linear;
  PointCloudT < Point2D <Float32> > cloud;
};

TEST_F (EuclideanClustersTest, Works) {
  std::vector <PointCloudT <Point2D <Float32> > > clusters;
  euclidean_clusters.compute (cloud, clusters);

  for (UInt32 i = 0; i < clusters.size (); ++i) {
    std::cout << "cluster " << i << std::endl;
    for (UInt32 j = 0; j < clusters[i].size (); ++j) {
      std::cout << "p " << clusters[i][j].x << " " << clusters[i][j].y << std::endl;
    }
  }
}

int
main (int argc, char **argv)
{
  ::testing::InitGoogleTest (&argc, argv);
  return RUN_ALL_TESTS ();
}
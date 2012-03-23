#include <gtest/gtest.h>

#include <libcloud/Templates/PointCloudT.h>
#include <libcloud/Templates/LineProjector.h>
#include <libcloud/Templates/Point2D.h>
#include <libcloud/2D/Line.h>

class LineProjectorTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    cloud.clear ();
    result.clear ();
    cloud.push_back (Point2D <Float32> (0, 0));
    cloud.push_back (Point2D <Float32> (1, 0));
    cloud.push_back (Point2D <Float32> (2, 0));
    cloud.push_back (Point2D <Float32> (3, 0));
    cloud.push_back (Point2D <Float32> (4, 0));
  }

  PointCloudT < Point2D <Float32> > cloud;
  PointCloudT < Point2D <Float32> > result;
  LineProjector <Float32> projector;
};

TEST_F (LineProjectorTest, Compute0Works) {
  Line line (1, 0, 0);

  projector.setLine (line);
  projector.compute (cloud, result);

  ASSERT_EQ (5, result.size ());

  ASSERT_EQ (Point2D <Float32> (0, 0), result[0]);
  ASSERT_EQ (Point2D <Float32> (0, 0), result[1]);
  ASSERT_EQ (Point2D <Float32> (0, 0), result[2]);
  ASSERT_EQ (Point2D <Float32> (0, 0), result[3]);
  ASSERT_EQ (Point2D <Float32> (0, 0), result[4]);
}

TEST_F (LineProjectorTest, Compute45Works) {
  Line line (1, -1, 0);

  projector.setLine (line);
  projector.compute (cloud, result);

  PointCloudT < Point2D <Float32> >::const_iterator it;
  for (it = result.begin (); it != result.end (); ++it) {
    std::cout << "p: " << it->x << " " << it->y << std::endl;
  }

  ASSERT_EQ (5, result.size ());

  ASSERT_EQ (Point2D <Float32> (0, 0), result[0]);
  ASSERT_EQ (Point2D <Float32> (0.5, 0.5), result[1]);
  ASSERT_EQ (Point2D <Float32> (1, 1), result[2]);
  ASSERT_EQ (Point2D <Float32> (1.5, 1.5), result[3]);
  ASSERT_EQ (Point2D <Float32> (2, 2), result[4]);
}

TEST_F (LineProjectorTest, Compute90Works) {
  Line line (0, 1, 0);

  projector.setLine (line);
  projector.compute (cloud, result);

  PointCloudT < Point2D <Float32> >::const_iterator it;
  for (it = result.begin (); it != result.end (); ++it) {
    std::cout << "p: " << it->x << " " << it->y << std::endl;
  }

  ASSERT_EQ (5, result.size ());

  ASSERT_EQ (Point2D <Float32> (0, 0), result[0]);
  ASSERT_EQ (Point2D <Float32> (1, 0), result[1]);
  ASSERT_EQ (Point2D <Float32> (2, 0), result[2]);
  ASSERT_EQ (Point2D <Float32> (3, 0), result[3]);
  ASSERT_EQ (Point2D <Float32> (4, 0), result[4]);
}

TEST_F (LineProjectorTest, Compute135Works) {
  Line line (-1, -1, 0);

  projector.setLine (line);
  projector.compute (cloud, result);

  PointCloudT < Point2D <Float32> >::const_iterator it;
  for (it = result.begin (); it != result.end (); ++it) {
    std::cout << "p: " << it->x << " " << it->y << std::endl;
  }

  ASSERT_EQ (5, result.size ());

  ASSERT_EQ (Point2D <Float32> (0, 0), result[0]);
  ASSERT_EQ (Point2D <Float32> (0.5, 0.5), result[1]);
  ASSERT_EQ (Point2D <Float32> (1, 1), result[2]);
  ASSERT_EQ (Point2D <Float32> (1.5, 1.5), result[3]);
  ASSERT_EQ (Point2D <Float32> (2, 2), result[4]);
}
int
main (int argc, char **argv)
{
  ::testing::InitGoogleTest (&argc, argv);
  return RUN_ALL_TESTS ();
}
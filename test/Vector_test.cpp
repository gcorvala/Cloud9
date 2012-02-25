#include <gtest/gtest.h>

#include <libcloud/Common/Vector.h>

class VectorTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    v1 = Vector ();
    v2 = Vector (0, 0, 0);
    v3 = Vector (-1, 0, 1);
    v4 = Vector (Point (1, 2, 3));
    v5 = Vector (Point (-1, -2, -3), Point (4, 5, 6));
  }

  Vector v1;
  Vector v2;
  Vector v3;
  Vector v4;
  Vector v5;
};

TEST_F (VectorTest, ConstructorWorks) {
  ASSERT_EQ (0, v1.x);
  ASSERT_EQ (0, v1.y);
  ASSERT_EQ (0, v1.z);
  ASSERT_EQ (0, v2.x);
  ASSERT_EQ (0, v2.y);
  ASSERT_EQ (0, v2.z);
  ASSERT_EQ (-1, v3.x);
  ASSERT_EQ (0, v3.y);
  ASSERT_EQ (1, v3.z);
  ASSERT_EQ (1, v4.x);
  ASSERT_EQ (2, v4.y);
  ASSERT_EQ (3, v4.z);
  ASSERT_EQ (-5, v5.x);
  ASSERT_EQ (-7, v5.y);
  ASSERT_EQ (-9, v5.z);
}

TEST_F (VectorTest, EqualityWorks) {
  ASSERT_TRUE (v1 == v2);
  ASSERT_TRUE (v2 == v1);
  ASSERT_TRUE (v1 == v1);
  ASSERT_TRUE (v1 != v3);
  ASSERT_TRUE (v3 != v1);
  ASSERT_FALSE (v1 != v2);
  ASSERT_FALSE (v2 != v1);
  ASSERT_FALSE (v3 != v3);
}

TEST_F (VectorTest, AdditionWorks) {
  Vector r (-2, 0, 2);
  ASSERT_EQ (v1, v1+v2);
  ASSERT_EQ (v3, v1+v3);
  ASSERT_EQ (r, v3+v3);
  v1 += v2;
  ASSERT_EQ (v2, v1);
  v1 += v3;
  ASSERT_EQ (v3, v1);
  v2 += v3;
  ASSERT_EQ (v3, v2);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest (&argc, argv);
  return RUN_ALL_TESTS ();
}
#include <gtest/gtest.h>

#include <libcloud/Common/Vector.h>

class VectorTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    v1 = Vector ();
    v2 = Vector (0, 0, 0);
    v3 = Vector (-1, 0, 1);
  }

  Vector v1;
  Vector v2;
  Vector v3;
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
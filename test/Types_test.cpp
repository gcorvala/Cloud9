#include <gtest/gtest.h>

#include <libcloud/Common/Types.h>
#include <limits>

class TypesTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
  }
};

TEST_F (TypesTest, SInt8Works) {
  ASSERT_EQ (-128, std::numeric_limits<SInt8>::min ());
  ASSERT_EQ (127, std::numeric_limits<SInt8>::max ());
  ASSERT_EQ (1, sizeof (SInt8));
}

TEST_F (TypesTest, SInt16Works) {
  ASSERT_EQ (-32768, std::numeric_limits<SInt16>::min ());
  ASSERT_EQ (32767, std::numeric_limits<SInt16>::max ());
  ASSERT_EQ (2, sizeof (SInt16));
}

TEST_F (TypesTest, SInt32Works) {
  ASSERT_EQ (0x80000000, std::numeric_limits<SInt32>::min ());
  ASSERT_EQ (0x7FFFFFFF, std::numeric_limits<SInt32>::max ());
  ASSERT_EQ (4, sizeof (SInt32));
}

TEST_F (TypesTest, SInt64Works) {
  ASSERT_EQ (0x8000000000000000LL, std::numeric_limits<SInt64>::min ());
  ASSERT_EQ (0x7FFFFFFFFFFFFFFFLL, std::numeric_limits<SInt64>::max ());
  ASSERT_EQ (8, sizeof (SInt64));
}

TEST_F (TypesTest, UInt8Works) {
  ASSERT_EQ (0, std::numeric_limits<UInt8>::min ());
  ASSERT_EQ (255, std::numeric_limits<UInt8>::max ());
  ASSERT_EQ (1, sizeof (UInt8));
}

TEST_F (TypesTest, UInt16Works) {
  ASSERT_EQ (0, std::numeric_limits<UInt16>::min ());
  ASSERT_EQ (65535, std::numeric_limits<UInt16>::max ());
  ASSERT_EQ (2, sizeof (UInt16));
}

TEST_F (TypesTest, UInt32Works) {
  ASSERT_EQ (0, std::numeric_limits<UInt32>::min ());
  ASSERT_EQ (0xFFFFFFFF, std::numeric_limits<UInt32>::max ());
  ASSERT_EQ (4, sizeof (UInt32));
}

TEST_F (TypesTest, UInt64Works) {
  ASSERT_EQ (0, std::numeric_limits<UInt64>::min ());
  ASSERT_EQ (0xFFFFFFFFFFFFFFFFLL, std::numeric_limits<UInt64>::max ());
  ASSERT_EQ (8, sizeof (UInt64));
}

int main (int argc, char **argv) {
  ::testing::InitGoogleTest (&argc, argv);
  return RUN_ALL_TESTS ();
}
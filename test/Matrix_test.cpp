#include <gtest/gtest.h>

#include <libcloud/2D/Matrix.h>

class MatrixTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    m1 = Matrix<UInt32> (2,3);
    m2 = Matrix<UInt32> (3,3);
    m2(0, 0) = 1; m2(0, 1) = 2; m2(0, 2) = 3;
    m2(1, 0) = 4; m2(1, 1) = 5; m2(1, 2) = 6;
    m2(2, 0) = 7; m2(2, 1) = 8; m2(2, 2) = 9;
  }

  Matrix<UInt32> m1;
  Matrix<UInt32> m2;
  Matrix<UInt32> m3;
};

TEST_F (MatrixTest, ConstructorWorks) {
  ASSERT_EQ (2, m1.getRows ());
  ASSERT_EQ (3, m1.getCols ());
  ASSERT_EQ (3, m2.getRows ());
  ASSERT_EQ (3, m2.getCols ());
  ASSERT_EQ (0, m3.getRows ());
  ASSERT_EQ (0, m3.getCols ());
}

TEST_F (MatrixTest, InitWorks) {
  for (UInt32 i = 0; i < m1.getRows (); ++i) {
    for (UInt32 j = 0; j < m1.getCols (); ++j) {
      ASSERT_EQ (0, m1(i,j));
    }
  }
}

TEST_F (MatrixTest, AccessorsWork) {
  for (UInt32 i = 0; i < m1.getRows (); ++i) {
    for (UInt32 j = 0; j < m1.getCols (); ++j) {
      m1(i,j) = i+j;
      ASSERT_EQ (i+j, m1(i,j));
    }
  }
}

TEST_F (MatrixTest, GetDataWorks) {
  // FIXME
}

TEST_F (MatrixTest, FillWorks) {
  m1.fill (1);
  for (UInt32 i = 0; i < m1.getRows (); ++i) {
    for (UInt32 j = 0; j < m1.getCols (); ++j) {
      ASSERT_EQ (1, m1(i,j));
    }
  }
  m2.fill (2);
  for (UInt32 i = 0; i < m2.getRows (); ++i) {
    for (UInt32 j = 0; j < m2.getCols (); ++j) {
      ASSERT_EQ (2, m2(i,j));
    }
  }
  m3.fill (3);
  for (UInt32 i = 0; i < m3.getRows (); ++i) {
    for (UInt32 j = 0; j < m3.getCols (); ++j) {
      ASSERT_EQ (3, m3(i,j));
    }
  }
}

TEST_F (MatrixTest, IteratorsWork) {
  Matrix<UInt32>::iterator it;
  Matrix<UInt32>::const_iterator c_it;
  const Matrix<UInt32>& m = m1;

  for (it = m1.begin (); it != m1.end (); ++it) {
    *it = std::distance (m1.begin (), it);
  }

  for (c_it = m.begin (); c_it != m.end (); ++c_it) {
    ASSERT_EQ (std::distance (m.begin (), c_it), *c_it);
  }
}

TEST_F (MatrixTest, ResizeWorks) {
  m1.resize (10, 20);
  ASSERT_EQ (10, m1.getRows ());
  ASSERT_EQ (20, m1.getCols ());
}

TEST_F (MatrixTest, GetSubMatrixWorks) {
  Matrix<UInt32> s = m2.getSubMatrix (1, 1, 2, 2);
  ASSERT_EQ (2, s.getRows ());
  ASSERT_EQ (2, s.getCols ());
  ASSERT_EQ (5, s(0,0));
  ASSERT_EQ (6, s(0,1));
  ASSERT_EQ (8, s(1,0));
  ASSERT_EQ (9, s(1,1));
}

TEST_F (MatrixTest, OperatorsWork) {
  Matrix<SInt8> s;
  s = m2;
}

TEST_F (MatrixTest, ConvolveWorks) {
  Matrix<UInt32> result;

  m2.convolve (m2, result);

  ASSERT_EQ (26, result(0,0));
  ASSERT_EQ (56, result(0,1));
  ASSERT_EQ (54, result(0,2));
  ASSERT_EQ (84, result(1,0));
  ASSERT_EQ (165, result(1,1));
  ASSERT_EQ (144, result(1,2));
  ASSERT_EQ (134, result(2,0));
  ASSERT_EQ (236, result(2,1));
  ASSERT_EQ (186, result(2,2));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest (&argc, argv);
  return RUN_ALL_TESTS ();
}
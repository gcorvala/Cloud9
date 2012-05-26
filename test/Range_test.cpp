#include <gtest/gtest.h>

#include <libcloud2/Common/Range.h>

class RangeTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    r1 = new Range (0, 1, 10);
    r2 = new Range (0, 10, 10);
    r3 = new Range (-10, 5, 3);
    r4 = new Range (-1, 1, 20);
  }

  Range::ptr r1;
  Range::ptr r2;
  Range::ptr r3;
  Range::ptr r4;
};

TEST_F (RangeTest, ConstructorWorks) {
  ASSERT_EQ (0, r1->getMin ());
  ASSERT_EQ (0, r2->getMin ());
  ASSERT_EQ (-10, r3->getMin ());
  ASSERT_EQ (-1, r4->getMin ());
  ASSERT_EQ (1, r1->getMax ());
  ASSERT_EQ (10, r2->getMax ());
  ASSERT_EQ (5, r3->getMax ());
  ASSERT_EQ (1, r4->getMax ());
  ASSERT_EQ (10, r1->getSteps ());
  ASSERT_EQ (10, r2->getSteps ());
  ASSERT_EQ (3, r3->getSteps ());
  ASSERT_EQ (20, r4->getSteps ());
}

TEST_F (RangeTest, stepGetterWorks) {
  ASSERT_EQ (0.1f, r1->getStep ());
  ASSERT_EQ (1, r2->getStep ());
  ASSERT_EQ (5, r3->getStep ());
  ASSERT_EQ (0.1f, r4->getStep ());
}

TEST_F (RangeTest, minSetterWorks) {
  r1->setMin (-10);
  ASSERT_EQ (-10, r1->getMin ());
}

TEST_F (RangeTest, maxSetterWorks) {
  r1->setMax (-10);
  ASSERT_EQ (-10, r1->getMax ());
}

TEST_F (RangeTest, stepsSetterWorks) {
  r1->setSteps (20);
  ASSERT_EQ (20, r1->getSteps ());
}

TEST_F (RangeTest, valueIndexGetterWorks) {
  ASSERT_EQ (0, r1->getValueIndex (0));
  ASSERT_EQ (0, r1->getValueIndex (0.05));
  ASSERT_EQ (1, r1->getValueIndex (0.1));
  ASSERT_EQ (1, r1->getValueIndex (0.15));
  ASSERT_EQ (2, r1->getValueIndex (0.2));
  ASSERT_EQ (2, r1->getValueIndex (0.25));
  ASSERT_EQ (3, r1->getValueIndex (0.3));
  ASSERT_EQ (3, r1->getValueIndex (0.35));
  ASSERT_EQ (4, r1->getValueIndex (0.4));
  ASSERT_EQ (4, r1->getValueIndex (0.45));
  ASSERT_EQ (5, r1->getValueIndex (0.5));
  ASSERT_EQ (5, r1->getValueIndex (0.55));
  ASSERT_EQ (6, r1->getValueIndex (0.6));
  ASSERT_EQ (6, r1->getValueIndex (0.65));
  ASSERT_EQ (7, r1->getValueIndex (0.7));
  ASSERT_EQ (7, r1->getValueIndex (0.75));
  ASSERT_EQ (8, r1->getValueIndex (0.8));
  ASSERT_EQ (8, r1->getValueIndex (0.85));
  ASSERT_EQ (9, r1->getValueIndex (0.9));
  ASSERT_EQ (9, r1->getValueIndex (0.95));
  ASSERT_EQ (9, r1->getValueIndex (0.99999));
}

int
main (int argc, char** argv) {
  ::testing::InitGoogleTest (&argc, argv);
  return RUN_ALL_TESTS ();
}
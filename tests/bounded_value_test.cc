#include <stdexcept>

#include "gtest/gtest.h"
#include "bounded_value.h"

class BoundedValueTest : public ::testing::Test {
  public:
    BoundedValue<short> bv;
};

TEST_F(BoundedValueTest, BadConstruction) {
  EXPECT_THROW(BoundedValue<short>(0, -1, 3), std::invalid_argument);
}

TEST_F(BoundedValueTest, Assignment) {
  bv = BoundedValue<short>(0, 1, 10);
  EXPECT_EQ(bv.min(), 0);
  EXPECT_EQ(bv.value(), 1);
  EXPECT_EQ(bv.max(), 10);
  // Note: Trying to assign a bounded value of different type will cause a
  // compile-time error
}

TEST_F(BoundedValueTest, IsMin) {
  bv = BoundedValue<short>(0, 0, 10);
  EXPECT_TRUE(bv.isMin());
}

TEST_F(BoundedValueTest, IsMax) {
  bv = BoundedValue<short>(0, 10, 10);
  EXPECT_TRUE(bv.isMax());
}

TEST_F(BoundedValueTest, SetValueInBounds) {
  bv = BoundedValue<short>(0, 0, 10);
  for (short i = 0; i < 11; ++i) {
    EXPECT_EQ(bv.value(i), 0);
    EXPECT_EQ(bv.value(), i);
  }
}

TEST_F(BoundedValueTest, SetValueBelowMin) {
  bv = BoundedValue<short>(0, 0, 10);
  EXPECT_EQ(bv.value(-2), -2);
  EXPECT_EQ(bv.value(), 0);
}

TEST_F(BoundedValueTest, SetValueAboveMax) {
  bv = BoundedValue<short>(0, 0, 10);
  EXPECT_EQ(bv.value(13), 3);
  EXPECT_EQ(bv.value(), 10); 
}
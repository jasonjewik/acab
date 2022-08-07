#include <vector>

#include "gtest/gtest.h"
#include "bounded_value.h"
#include "pet_builder.h"

class PetBuilderTest : public ::testing::Test {
  public:
    PetBuilder pb;
};

TEST_F(PetBuilderTest, NullPtrExpected_1) {
  EXPECT_EQ(pb.build(), nullptr); 
}

TEST_F(PetBuilderTest, NullPtrExpected_2) {
  pb.setAbility(0)
    .setHealth(BoundedValue<short>(1, 1, 50));
  EXPECT_EQ(pb.build(), nullptr);
}

TEST_F(PetBuilderTest, NonNullExpected) {
  std::vector<BoundedValue<short>> expThresholds;
  expThresholds.push_back(BoundedValue<short>(0, 0, 2));
  pb.setAbility(0)
    .setHealth(BoundedValue<short>(1, 1, 50))
    .setAttack(BoundedValue<short>(1, 1, 50))
    .setExpLvl(0, 0, expThresholds)
    .setStatus(0);
  EXPECT_NE(pb.build(), nullptr);
}
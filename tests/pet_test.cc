#include <vector>

#include "gtest/gtest.h"
#include "bounded_value.h"
#include "pet.h"

TEST(PetTest, TestCreate) {
  BoundedValue<short> health(1, 1, 50);
  BoundedValue<short> attack(1, 1, 50);
  short level = 0;
  short exp = 0;
  
  std::vector<BoundedValue<short>> expThresholds;
  expThresholds.push_back(BoundedValue<short>(0, 0, 2));
  expThresholds.push_back(BoundedValue<short>(0, 0, 3));

  Pet p(health, attack, level, exp, expThresholds);

  EXPECT_EQ(p.getHealth(), health.value());
  EXPECT_EQ(p.getAttack(), attack.value());
  EXPECT_EQ(p.getLevel(), level);
  EXPECT_EQ(p.getExp(), exp);
}

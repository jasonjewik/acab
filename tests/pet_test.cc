#include <vector>

#include "gtest/gtest.h"
#include "bounded_value.h"
#include "pet.h"
#include "pet_builder.h"

class PetTest : public ::testing::Test {
  public:
    BoundedValue<short> health;
    BoundedValue<short> attack;
    short level;
    short exp;
    std::vector<BoundedValue<short>> expThresholds;
    PetBuilder pb;
    Pet* p;

  protected:
    void SetUp() override {
      health = BoundedValue<short>(1, 1, 50);
      attack = BoundedValue<short>(1, 1, 50);
      level = 0;
      exp = 0;
      expThresholds.push_back(BoundedValue<short>(0, 0, 2));
      expThresholds.push_back(BoundedValue<short>(0, 0, 3));
      pb.setHealth(health)
        .setAttack(attack)
        .setExpLvl(level, exp, expThresholds);
      p = pb.build();
    }

    void TearDown() override {
      delete p;
    }
};

TEST_F(PetTest, Getters) {
  EXPECT_EQ(p->getHealth(), health.value());
  EXPECT_EQ(p->getAttack(), attack.value());
  EXPECT_EQ(p->getLevel(), level);
  EXPECT_EQ(p->getExp(), exp);
}

TEST_F(PetTest, SetHealth) {
  HealthStatus status;
  short oldHealth = p->getHealth();

  status = p->setHealth(health.min());
  EXPECT_EQ(status, alive);
  EXPECT_EQ(p->getHealth(), health.min());  

  status = p->setHealth(health.min() - 2);
  EXPECT_EQ(status, fainted);
  EXPECT_EQ(p->getHealth(), health.min());

  status = p->setHealth(health.max());
  EXPECT_EQ(status, alive);
  EXPECT_EQ(p->getHealth(), health.max());

  status = p->setHealth(health.max() + 2);
  EXPECT_EQ(status, alive);
  EXPECT_EQ(p->getHealth(), health.max());

  status = p->setHealth(oldHealth);
  EXPECT_EQ(status, alive);
  EXPECT_EQ(p->getHealth(), oldHealth);
}

TEST_F(PetTest, SetAttack) {
  short oldAttack = p->getAttack();

  p->setAttack(attack.min());
  EXPECT_EQ(p->getAttack(), attack.min());

  p->setAttack(attack.min() - 3);
  EXPECT_EQ(p->getAttack(), attack.min());

  p->setAttack(attack.max());
  EXPECT_EQ(p->getAttack(), attack.max());

  p->setAttack(attack.max() + 3);
  EXPECT_EQ(p->getAttack(), attack.max());

  p->setAttack(oldAttack);
  EXPECT_EQ(p->getAttack(), oldAttack);
}

TEST_F(PetTest, IncrementExp_NoLevelUp) {
  short oldExp = p->getExp();
  short oldLevel = p->getLevel();

  p->incrementExp();
  EXPECT_EQ(p->getExp(), oldExp + 1);
  EXPECT_EQ(p->getLevel(), oldLevel);
}

TEST_F(PetTest, IncrementExp_LevelUpUntilMax) {
  short oldLevel, expNeeded;
  short maxLevel = expThresholds.size();
  oldLevel = p->getLevel();

  while (oldLevel < maxLevel) {
    for (expNeeded = 0; expNeeded < expThresholds[oldLevel].max(); ++expNeeded)
      EXPECT_TRUE(p->incrementExp());
    EXPECT_EQ(p->getExp(), 0);
    EXPECT_EQ(p->getLevel(), oldLevel + 1);
    oldLevel = p->getLevel();
  }
}

TEST_F(PetTest, IncrementExp_LevelUpPastMax) {
  short oldLevel, expNeeded;
  short maxLevel = expThresholds.size();
  oldLevel = p->getLevel();

  while (oldLevel < maxLevel) {
    for (expNeeded = 0; expNeeded < expThresholds[oldLevel].max(); ++expNeeded)
      p->incrementExp();
    oldLevel = p->getLevel();
  }
  EXPECT_EQ(p->getLevel(), maxLevel);
  EXPECT_EQ(p->getExp(), 0);

  EXPECT_FALSE(p->incrementExp());
  EXPECT_EQ(p->getLevel(), maxLevel);
  EXPECT_EQ(p->getExp(), 0);
}
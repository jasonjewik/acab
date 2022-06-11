#include "pet.h"

Pet::Pet(BoundedValue<short> health_, BoundedValue<short> attack_, short level_,
         short exp_, std::vector<BoundedValue<short>>& expThresholds_) {
  health = health_;
  attack = attack_;
  expThresholds = expThresholds_;

  level = BoundedValue<short>(0, level_, expThresholds_.size() - 1);
  exp = BoundedValue<short>(
    expThresholds_[level.value()].min(), 
    exp_,
    expThresholds_[level.value()].max()
  );
};

HealthStatus Pet::setHealth(short health_) {
  short difference = health.value(health_);
  if (difference < 0)
    return fainted;
  return alive;
};

void Pet::setAttack(short attack_) {
  attack.value(attack_);
};

bool Pet::incrementExp() {
  short difference = exp.value(exp.value() + 1);
  if (difference > 0) {
    while (difference > 0) {
      exp = expThresholds[level.value()];
      difference = exp.value(difference);
    }
    return true;
  } else if (exp.isMax() && levelUp()) {
    exp = expThresholds[level.value()];
    return true;
  }
  return false;
};

bool Pet::levelUp() {
  if (level.isMax())
    return false;
  else
    level.value(level.value() + 1);
  return true;
};
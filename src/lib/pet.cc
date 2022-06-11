#include "pet.h"

Pet::Pet(BoundedValue<short> health_, BoundedValue<short> attack_, short level_,
         short exp_, std::vector<BoundedValue<short>>& expThresholds_) {
  health = health_;
  attack = attack_;
  expThresholds = expThresholds_;

  level = BoundedValue<short>(0, level_, expThresholds_.size());
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
  if (level.isMax()) {
    exp.value(0);
    return false;
  }

  exp.value(exp.value() + 1);
  if (!exp.isMax())
    return true;

  level.value(level.value() + 1);
  if (!level.isMax())
    exp = expThresholds[level.value()];
  exp.value(0);
  return true;
};